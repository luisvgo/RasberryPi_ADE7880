/// \file pi_spi_bcm2835.c
/// \brief \e Purpose: \n Middleware driver for RasPi with bcm2835 for SPI set up and traffic control
/**
 * pi_spi_bcm2835.c
 *
 *  Created on: Jan 24, 2015
 *      Author: Luis
 */

/***********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/
/* Fixed width integers */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <semaphore.h>  /* Semaphore */
#include "pi_spi_bcm2835.h"


/**
 *Private global variables and functions
 */

uint8_t g_selected_channel = -1;

/* These variables are only needed if locking is enabled in pi_spi_config.h */
#if defined(SPI_REQUIRE_LOCK)

/* Holds the process currently using the SPI peripheral */
static uint32_t g_spi_locked_id = NO_DEVICE_SELECTED;
/* Holds the last process using the SPI peripheral */
static uint32_t g_spi_last_caller_pid = NO_DEVICE_SELECTED;

/* Used for atomic accesses */
static int g_atomic_semaphore = 0;
extern  sem_t g_SPI_Lock_mutex;

#endif
/* This variable determines whether the peripheral has already been initialized. */
static bool bcm_initialized = false;
/* This variable determines whether the peripheral has already been initialized in SPI mode. */
static bool spi_initialized = false;

/***********************************************************************************************************************
 * Function Name: PI_BCM_Init()
 * Description  : Enable bcm library channel
 * Arguments    :
 * Return Value : true -
 *                    SPI is initialized.
 ***********************************************************************************************************************/
void PI_BCM_Init(void)
{
	bcm2835_init();
	bcm_initialized = true;
}

/***********************************************************************************************************************
 * Function Name: PI_BCM_Close()
 * Description  : Closes bcm library channel
 * Arguments    :
 * Return Value :
 ***********************************************************************************************************************/
void PI_BCM_Close(void)
{
	bcm2835_close();
	bcm_initialized = false;
}

/***********************************************************************************************************************
 * Function Name: PI_BCM_Close()
 * Description  : Enable bcm library channel
 * Arguments    :
 * Return Value : true -
 *                    SPI is initialized.
 ***********************************************************************************************************************/
bool PI_BCM_CheckInitialized(void)
{
	return bcm_initialized;
}
/***********************************************************************************************************************
 * Function Name: PI_SPI_Init()
 * Description  : Enable SPI channel
 * Arguments    : uint8_t bitOrder,
				  uint8_t dataMode,
				  uint16_t clockDivider,
				  uint8_t polarity
 * Return Value :
 ***********************************************************************************************************************/
void PI_SPI_Init(uint8_t bitOrder,
				 uint8_t dataMode,
				 uint16_t clockDivider,
				 uint8_t polarity,
				 uint8_t chipSelect)
{
	bcm2835_spi_begin();
	bcm2835_spi_setBitOrder(bitOrder);
	bcm2835_spi_setDataMode(dataMode); 			// Data propagation edge
												// but we will make sure that the mode is right by trial and error
	bcm2835_spi_setClockDivider(clockDivider); // 512 = 2.048us = 488.28125kHz Check higher later
	bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS0, polarity); // SS/HSA chip pin of ade7880 should be low for communication
	bcm2835_spi_setChipSelectPolarity(BCM2835_SPI_CS1, polarity); // SS chip pin of ATMEGA32 should be low for communication
	bcm2835_spi_chipSelect(chipSelect);

	g_selected_channel = chipSelect;

	/// Keeps track of SPI pins initialization to avoid recalling it
	spi_initialized = true;
}

/***********************************************************************************************************************
 * Function Name: PI_SPI_Close()
 * Description  : Disable device SPI channel
 * Arguments    :
 * Return Value : false -
 *                    SPI not closed, perhaps not initialized.
 ***********************************************************************************************************************/
void PI_SPI_Close(void)
{
	bcm2835_spi_end();
	spi_initialized = false;

}

/***********************************************************************************************************************
 * Function Name: PI_SPI_CheckInitialized()
 * Description  : Enable device chip select on SPI channel
 * Arguments    :
 * Return Value : true -
 *                    SPI is initialized.
 *                false -
 *                    SPI not initialized.
 ***********************************************************************************************************************/
bool PI_SPI_CheckInitialized(void)
{
	return spi_initialized;
}

/***********************************************************************************************************************
 * Function Name: PI_SPI_SetClockSpeed()
 * Description  : Set Clock speed for transmission rate
 * Arguments    : uint16_t clockDivider, uint32_t pid
 * Return Value :
 ***********************************************************************************************************************/
bool PI_SPI_SetClockSpeed(uint16_t clockDivider, uint32_t pid)
{
#if defined(SPI_REQUIRE_LOCK)
	/* Verify that this task has the lock */
	if (false == PI_SPI_CheckLock(pid))
	{
		/* This task does not have the SPI lock and therefore cannot perform this operation. */
		return false;
	}
#endif
	bcm2835_spi_setClockDivider(clockDivider);

	return true;
}

/***********************************************************************************************************************
 * Function Name: PI_SPI_DataPropagationMode()
 * Description  : Set SPI mode CPOL CPHA
 * Arguments    : uint16_t mode, uint32_t pid
 * Return Value :
 ***********************************************************************************************************************/
bool PI_SPI_DataPropagationMode(uint16_t dataMode, uint32_t pid)
{
#if defined(SPI_REQUIRE_LOCK)
	/* Verify that this task has the lock */
	if (false == PI_SPI_CheckLock(pid))
	{
		/* This task does not have the SPI lock and therefore cannot perform this operation. */
		return false;
	}
#endif
	bcm2835_spi_setDataMode(dataMode);

	return true;
}

/***********************************************************************************************************************
 * Function Name: PI_SPI_SetBitOrder()
 * Description  : Set bit order MSB or LSB first
 * Arguments    : uint16_t clockDivider, uint32_t pid
 * Return Value :
 ***********************************************************************************************************************/
bool PI_SPI_SetBitOrder(uint16_t bitOrder, uint32_t pid)
{
#if defined(SPI_REQUIRE_LOCK)
	/* Verify that this task has the lock */
	if (false == PI_SPI_CheckLock(pid))
	{
		/* This task does not have the SPI lock and therefore cannot perform this operation. */
		return false;
	}
#endif
	bcm2835_spi_setBitOrder(bitOrder);

	return true;
}

/***********************************************************************************************************************
 * Function Name: PI_SPI_Channel_Select
 * Description  : Enable device chip select on SPI channel
 * Arguments    : chip_select -
 *                    Which device to enable (choose from device_selected_t enum)
 *                pid -
 *                    Unique task ID. Used to make sure tasks don't step on each other.
 * Return Value : true -
 *                    Operation completed.
 *                false -
 *                    This task did lock the SPI fist.
 ***********************************************************************************************************************/
bool PI_SPI_Channel_Select(uint16_t chip_select, uint32_t pid)
{
#if defined(SPI_REQUIRE_LOCK)
	/* Verify that this task has the lock */
	if (false == PI_SPI_CheckLock(pid))
	{
		/* This task does not have the SPI lock and therefore cannot perform this operation. */
		return false;
	}

#endif

	switch (chip_select)
	{
	case CHANNEL0_SELECTED: /* Enable CS0 */
		bcm2835_spi_chipSelect(BCM2835_SPI_CS0);
		g_selected_channel = BCM2835_SPI_CS0;
		break;

	case CHANNEL1_SELECTED: /* Enable CS1 */
		bcm2835_spi_chipSelect(BCM2835_SPI_CS1);
		g_selected_channel = BCM2835_SPI_CS1;
		break;

	default:
		break;
	}

	return true;
}

/***********************************************************************************************************************
 * Function Name: PI_SPI_Channel_Select_Check()
 * Description  : returns the active CS channel
 * Arguments    :
 * Return Value : last caller pid
 ***********************************************************************************************************************/
uint8_t PI_SPI_Channel_Select_Check()
{
	return g_selected_channel;
}
/***********************************************************************************************************************
 * Function Name: PI_SPI_last_caller_pid()
 * Description  : returns the caller's pid for the last operation
 * Arguments    :
 * Return Value : last caller pid
 ***********************************************************************************************************************/
uint32_t PI_SPI_last_caller_pid(void)
{
	return g_spi_last_caller_pid;
}

/***********************************************************************************************************************
 * Function Name: PI_SPI_SendReceive
 * Description  : Performs SPI transfers. Can read and write at the same time.
 * Arguments    : pSrc -
 *                    pointer to data buffer with data to be transmitted.
 *                    If NULL, const 0xFF as source.
 *                pDest -
 *                    pointer to location to put the received data (can be same as pSrc if desired).
 *                    If NULL, receive data discarded.
 *                usBytes -
 *                    number of bytes to be sent/received
 *                pid -
 *                    Unique task ID. Used to make sure tasks don't step on each other.
 * Return Value : true -
 *                    Operation completed.
 *                false -
 *                    This task did lock the RSPI fist.
 ***********************************************************************************************************************/
bool PI_SPI_SendReceive(uint8_t *pSrc, uint8_t *pDest, uint16_t usBytes,
		uint32_t pid)
{

#if defined(SPI_REQUIRE_LOCK)
	/* Verify that this task has the lock */
	if (false == PI_SPI_CheckLock(pid))
	{
		/* This task does not have the RSPI lock and therefore cannot perform this operation. */
		return false;
	}
#endif

	bcm2835_spi_transfernb(pSrc, pDest, usBytes);
	g_spi_last_caller_pid = pid;

	return true;
}

/***********************************************************************************************************************
 * Function Name: PI_SPI_Read
 * Description  : Reads data using SPI
 * Arguments    : pDest -
 *                    Pointer to location to put the received data.
 *                    Returned value will be incremented by number of bytes received.
 *                usBytes -
 *                    number of bytes to be received
 *                pid -
 *                    Unique task ID. Used to make sure tasks don't step on each other.
 * Return Value : true -
 *                    Operation completed.
 *                false -
 *                    This task did lock the SPI fist.
 ***********************************************************************************************************************/
bool PI_SPI_Read(uint8_t *pDest, uint16_t usBytes, uint32_t pid)
{
#if defined(SPI_REQUIRE_LOCK)
	/* Verify that this task has the lock */
	if (false == PI_SPI_CheckLock(pid))
	{
		/* This task does not have the RSPI lock and therefore cannot perform this operation. */
		return false;
	}
#endif

	bcm2835_spi_transfern(pDest, usBytes);
	g_spi_last_caller_pid = pid;

	return true;
}

/***********************************************************************************************************************
 * Function Name: PI_SPI_Write
 * Description  : Write to a SPI device
 * Arguments    : pSrc -
 *                    Pointer to data buffer with data to be transmitted.
 *                    Returned value will be incremented by number of attempted writes.
 *                usBytes -
 *                    Number of bytes to be sent
 *                pid -
 *                    Unique task ID. Used to make sure tasks don't step on each other.
 * Return Value : true -
 *                    Operation completed.
 *                false -
 *                    This task did lock the RSPI fist.
 ***********************************************************************************************************************/
bool PI_SPI_Write(uint8_t *pSrc, uint16_t usBytes, uint32_t pid)
{
#if defined(SPI_REQUIRE_LOCK)
	/* Verify that this task has the lock */
	if (false == PI_SPI_CheckLock(pid))
	{
		/* This task does not have the RSPI lock and therefore cannot perform this operation. */
		return false;
	}
#endif

	bcm2835_spi_writenb(pSrc, usBytes);
	g_spi_last_caller_pid = pid;

	return true;
}

/* These functions are only needed if locking is enabled in
 pi_spi_bcm2835.h */
#if defined(SPI_REQUIRE_LOCK)

/***********************************************************************************************************************
 * Function Name: PI_SPI_Lock
 * Description  : Get lock on SPI access.
 * Arguments    : channel -
 *                    Which channel to use
 *                pid -
 *                    Unique program ID to attempt to lock RSPI with
 * Return Value : true -
 *                    lock acquired
 *                false -
 *                    lock not acquired
 ***********************************************************************************************************************/
bool PI_SPI_Lock(uint32_t pid)
{
	/******************************************
	 * TODO: Make the semaphore atomic, find the swap fn.
	 */
	/* Return variable */
	bool ret = true;

	/* Variable used in trying to grab semaphore. Using the __sync_bool_compare_and_swap instruction makes this atomic */
	int semaphore = 1;

	/* Try to grab semaphore to change state */
	sem_wait(&g_SPI_Lock_mutex);
	semaphore = g_atomic_semaphore;
	sem_post(&g_SPI_Lock_mutex);


	/* Check to see if semaphore was successfully taken */
	if (semaphore == 0)
	{
		/* Only give lock if no program has the lock already */
		if (g_spi_locked_id == NO_DEVICE_SELECTED)
		{
			/* Lock has been obtained */
			g_spi_locked_id = pid;
		}
		else
		{
			/* Lock has already been taken */
			ret = false;
		}

		/* Release semaphore */
		g_atomic_semaphore = 0;
	}
	else
	{
		/* Semaphore was not taken. Another task is in this function and has taken the semaphore already.
		 Try again later. */
		ret = false;
	}

	return ret;
}

/***********************************************************************************************************************
 * Function Name: PI_SPI_Unlock
 * Description  : Release SPI lock so another task can use it
 * Arguments    :pid -
 *                    Unique program ID to attempt to unlock RSPI with
 * Return Value : true -
 *                    lock was relinquished
 *                false -
 *                    lock was not given to this ID previously
 ***********************************************************************************************************************/
bool PI_SPI_Unlock(uint32_t pid)
{
	bool ret = true;

	/* Can only release lock if this program previously acquired it */
	if (g_spi_locked_id == pid)
	{
		/* Lock given back successfully */
		g_spi_locked_id = NO_DEVICE_SELECTED;
	}
	else
	{
		/* This program did not have this lock */
		ret = false;
	}

	return ret;
}

/***********************************************************************************************************************
 * Function Name: PI_SPI_CheckLock
 * Description  : Checks to see if PID matches the one that took the lock
 * Arguments    : pid -
 *                    Process ID to check against.
 * Return Value : true -
 *                    This task has the lock
 *                false -
 *                    This task does not have the lock
 ***********************************************************************************************************************/
bool PI_SPI_CheckLock(uint32_t pid)
{
	/* Check to see if this task has the lock */
	if (g_spi_locked_id != pid)
	{
		/* This task does not have the lock */
		return false;
	}
	else
	{
		/* This task has the lock */
		return true;
	}
}

#endif /* RSPI_REQUIRE_LOCK */

