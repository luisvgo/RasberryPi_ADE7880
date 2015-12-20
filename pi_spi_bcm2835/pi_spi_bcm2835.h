/// \file pi_spi_bcm2835.h
/// \brief \e Purpose: \n Middleware driver for SPI with bcm2835 header file
/*
 * pi_spi_bcm2835.h
 *
 *  Created on: Jan 24, 2015
 *      Author: Luis
 */

/***********************************************************************************************************************
* File Name     : pi_spi_bcm2835.h
* Version       : 1.0
* Description   : Configures the SPI driver
************************************************************************************************************************
* History : DD.MM.YYYY Version Description
*         : 24.01.2015 1.00    First Release
***********************************************************************************************************************/

/**************************************************************************************************//**
 *  \defgroup pi_spi SPI Middleware driver
 *
 /// @{
 * \brief C Middleware driver for Raspberry Pi with Broadcom BCM 2835
 *
 * SPI library and Middleware driver, Allows access to the BCM2835 SPI library and fulfills the requirements to work in standalone or
 * Operating systems. It is reentrant and non blocking. valid for systems with multiple SPI module and channels.
 *
 * This is a middleware driver for accessing the SPI by means of the BCM2835 library. It is written in C and It provides
 * access control to the driver when GPIO and other IO functions of the Broadcom BCM 2835 are needed, communications from and
 *  to another device through the GPIO pins using different protocols, although SPI is the only one implemented so far.
 *
 * It provides functions for reading, writing and setting the SPI communications with channel control, channel select control, application control
 * and lock mechanism
 *
 * It is C compatible, and installs  and executes on
 * any Linux-based distro (but clearly is no use except on Raspberry Pi or another board with
 * BCM 2835 at this moment).
 *
 * Device configuration : This module contains functions that are prepared and used to configure the
 * Raspberry pi GPIO (Broadcom BCM 2835) in SPI mode, As well as reading and writing to SPI channels with traffic control,
 * Serial Port selection (i.e. SPI port activation) and application access control
 *
 * Notice: This uses the open source library bcm2835 copyrighted (C) 2011-2013 by Mike McCauley. The Raspberry Pi consists of a Broadcom BCM2835 system on a chip (SoC) which allows access
 * to GPIO pins and other peripherals such as SPI interface. Thereby, for easy implementation, the C
 * library provided for this chip is used as external library in this software application. Therefore,
 * it’s necessary to recall that [-l bcm2835] option is used when compiling the software directly without
 * the use of makefile command. The library and information’s such as how to install the library on a
 * given machine can be downloaded from:
 * http://www.airspayce.com/mikem/bcm2835/bcm2835-1.36.tar.gz .
 * Also, details about the provided functions with this library can be obtained from
 * http://www.airspayce.com/mikem/bcm2835/
 * Based on data in http://elinux.org/RPi_Low-level_peripherals and
 * http://www.raspberrypi.org/wp-content/uploads/2012/02/BCM2835-ARM-Peripherals.pdf
 * and http://www.scribd.com/doc/101830961/GPIO-Pads-Control2
 *
 *@par USE GUIDELINES
 * Use as follows:
 * \arg 1. Implement the \ref pi_spi_bcm2835 middleware driver with \ref bcm2835 library by including \ref pi_spi_bcm2835.h
 * in the source file where the code requires SPI access
 * \arg 2. Initialize the library if it wasn't initialized before
 * \code
 * 	//  Initialize the bcm2835 library for GPIO access
 *	if (!PI_BCM_CheckInitialized())
 *	{
 *		PI_BCM_Init();
 *	}
 * \endcode
 * \arg 3. Open Raspberry hardware SPI channel to communicate with ADE7880 if the SPI pins are not active.
 * One can always call each function independently
 * \code
 * 	// Open Raspberry hardware SPI channel to communicate with ADE7880
 *	if (!PI_SPI_CheckInitialized())
 *	{
 *		PI_SPI_Init(BCM2835_SPI_BIT_ORDER_MSBFIRST, BCM2835_SPI_MODE3,
 *				BCM2835_SPI_CLOCK_DIVIDER_512, LOW, BCM2835_SPI_CS0);
 *	}
 * \endcode
 * \arg 4. Lock the access to the SPI to the calling application. \n Call \ref PI_SPI_Lock (APP_PID) and check its return
 * \arg 5. If lock is attained select the CS channel and any other required modification to SPI configuration here, like clock speed.
 * \n Use \ref PI_SPI_Select (REQUIRED_SPI_CHANNEL, APP_PID)
 *
 * \arg 6. Proceed with the SPI communication by calling one of the three provided functions, \ref PI_SPI_SendReceive, \ref PI_SPI_Write or \ref PI_SPI_Read
 * \arg 7. At last, proceed to unlock the SPI, \ref PI_SPI_Unlock (APP_PID)\n
 * follow the next example for steps 4, 5, 6 and 7.
 * \code
 *  //Example of steps 4, 5, 6 and 7
 * int8_t PI_ADE_SPI_Write(uint8_t *data, uint8_t usBytes)
 * {
 * 	bool locked = false;
 *
 * 	// Attempt to lock the SPI peripheral.
 * 	while ( false == (locked = PI_SPI_Lock( ADE_SPI_PID)))
 * 	{
 * 		//Wait until lock is given up or 'count' cycles. At this point another task must unlock the RSPI peripheral before we can
 * 		//lock it here. This means this other task must unlock from an ISR or from another RTOS task.
 * 		//usleep(ADE_LOCK_DELAY_MICROS); // No need for this but one can handle in here what ever the task does while waiting
 * 	}
 *
 * 	if (locked)
 * 	{
 * 		// The lock has been obtained. Check last access and set the proper clock speed and assert the Channel Select if proceed
 * 		if(ADE_SPI_PID != PI_SPI_last_caller_pid())
 * 		{
 * 			PI_SPI_SetClockSpeed(ADE_SPI_CLOCK_SPEED, ADE_SPI_PID);
 * 			PI_SPI_Channel_Select( ADE_SPI_CHANNEL, ADE_SPI_PID);
 * 		}
 *
 * 		// Send the data.
 * 		//    R_RSPI_Write(ADE_RSPI_CHANNEL, (const uint8_t *)&data, (reg_len+WR_MSG_OVERHEAD), ADE_RSPI_PID);
 * 		PI_SPI_Write(data, (usBytes), ADE_SPI_PID);
 *
 * 		// Release the lock.
 * 		PI_SPI_Unlock( ADE_SPI_PID);
 *
 * 	}
 * 	else
 * 	{
 * 		return -1;
 * 	}
 *
 * 	return 0;
 *
 * }// End of function PI_ADE_SPI_Write()
 * \endcode
 */

#ifndef PI_SPI_BCM2835_H_
#define PI_SPI_BCM2835_H_


#include <bcm2835.h>

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/// \brief device_selected
/// Enumeration for chips selects (CS channel)associated with RasPi SPI
typedef enum {
    NO_DEVICE_SELECTED =4,
	CHANNEL0_SELECTED = 0,
	CHANNEL1_SELECTED = 1,
	CHANNEL2_SELECTED = 2,
	CHANNEL3_SELECTED = 3
} device_selected_t;



/***********************************************************************************************************************
Configuration Options
***********************************************************************************************************************/
/** @brief Lock SPI channel required.
 *
 * When uncommented, obtaining a lock on the SPI peripheral using the PI_SPI_Lock() function will
 * be required. After obtaining the lock the user will have to pass the tasks PID to all other RSPI functions. If this
 * is commented out then locking will not be enabled and the user can pass any value they want for 'pid' because the
 * functions will ignore the lock.
 * */
#define SPI_REQUIRE_LOCK


/** @brief Checks if the bcm2835 library is initialized.
 * Calling this function before calling \ref PI_BCM_Init() avoids unnecessary reinitializations.
 *
 * @return bcm_initialized flag to check initialization status
 */
bool 	PI_BCM_CheckInitialized(void);

/** @brief Enable bcm library use.
 *
 * this calls bcm2835_init  and initializes it enabling the use of the GPIO.\n
 * Sets the flag bcm_initialized as true.\n
 */
void 	PI_BCM_Init			(void);

/** @brief Close bcm library use.
 *
 * this calls the bcm2835_close disabling any further use of it.\n
 * Sets the flag bcm_initialized as false.\n
 */
void 	PI_BCM_Close		(void);

/** @brief Checks if SPI pins have been initialized in this mode before.
 *
 * Calling this function and reding its return before calling \ref PI_SPI_Init avoids unnecessary reinitializations.
 *
 * @return spi_initialized flag to check initialization status
 */
bool 	PI_SPI_CheckInitialized(void);

/** @brief Starts the use of the required GPIO pins as SPI .
 *
 * Initializes the use of the SPI pins in this mode with the given parameters.\n
 * Parameters are set here in this function to avoid duplicity but. in the case of several channel in use, one should
 * pay special care of each channel settings and avoid mismatches
 * The SPI will be configured following the parameters. Parameters can be easily understood and obtained from bcm2835.h while
 * searching by each parameter's name.\n
 * The flag spi_initialized is asserted as true.\n
 * @param bitOrder \ref bcm2835SPIBitOrder MSB or LSB first
 * @param dataMode \ref bcm2835SPIMode CHPA and CPOL, check devices' datasheet to choose the appropriate
 * @param clockDivider \ref bcm2835SPIClockDivider Selects the transmission speed
 * @param polarity \ref HIGH or \ref LOW. Selects the CS polarity when enabled, Usually is low.
 * @param chipSelect \ref bcm2835SPIChipSelect. Selects the active channel CS0, CS1 or CS2 after finishing the configuration
 */
void	PI_SPI_Init			(uint8_t bitOrder, uint8_t dataMode, uint16_t clockDivider, uint8_t polarity, uint8_t chipSelect);

/** @brief Close SPI pins use and free them for another use.
 *
 * this calls \ref bcm2835_spi_end disabling any further use of it.\n
 * Sets the flag spi_initialized as false.\n
 */
void 	PI_SPI_Close		(void);

/** @brief Set SPI Clock speed.
 *
 * this calls \ref bcm2835_spi_setClockDivider setting the new transmission speed.\n
 *
 * @param clockDivider \ref bcm2835SPIClockDivider Selects the transmission speed
 * @param pid Unique application ID. Any int random but unique number
 * @return true if speed is selected properly,\n false if lock success NOT
 */
bool PI_SPI_SetClockSpeed(uint16_t clockDivider, uint32_t pid);

/** @brief Set SPI Mode
 *
 * this calls \ref bcm2835_spi_setDataMode setting the new CPOL and CPHA values.\n
 *
 * @param dataMode \ref bcm2835SPIMode CHPA and CPOL, check devices' datasheet to choose the appropriate
 * @param pid Unique application ID. Any int random but unique number
 * @return true if speed is selected properly,\n false if lock success NOT
 */
bool PI_SPI_DataPropagationMode(uint16_t dataMode, uint32_t pid);

/** @brief Set SPI bit order
 *
 * this calls \ref bcm2835_spi_setBitOrder setting the new bit order for network transmission.\n
 *
 * @param bitOrder \ref bcm2835SPIBitOrder MSB or LSB first
 * @param pid Unique application ID. Any int random but unique number
 * @return true if mode is selected properly,\n false if lock success NOT
 */
bool PI_SPI_SetBitOrder(uint16_t bitOrder, uint32_t pid);

/** @brief get last operation's caller
 */
uint32_t PI_SPI_last_caller_pid(void);

/** @brief Enable device chip select on SPI channel
 *
 * Selects and activates a given CS channel to enable communications to the device attached to it.
 * If \ref SPI_REQUIRE_LOCK is active, this also checks if a lock to the SPI
 * driver was attained by an application PID, a unique number that identifies the caller, avoiding possible collisions,
 * Used to make sure tasks don't step on each other.. This is done by calling \ref PI_SPI_CheckLock(),
 * if g_spi_locked_id matches means the application has gotten the lock.
 * Before calling this function, one must call \ref PI_SPI_Lock() to get the lock
 *
 * @param chip_select  the CS channel (\ref bcm2835SPIChipSelect)
 * @param pid Unique application ID. Any int random but unique number
 * @return true if channel is selected properly,\n false if not locked succesfuly
 */
bool 	PI_SPI_Channel_Select		(uint16_t chip_select, uint32_t pid);

/** @brief Performs SPI transfers. Can read and write at the same time.
 *
 * @param pSrc  pointer to data buffer with data to be transmitted. If NULL, const 0xFF as source.
 * @param pDest pointer to location to put the received data (can be same as pSrc if desired). If NULL, receive data discarded.
 * @param usBytes number of bytes to be sent/received. Clock and CS are active for this number of bytes
 * @param pid Unique task ID. Used to make sure tasks don't step on each other.
 * @return true - Operation completed.\n
 *         false - This task did lock the SPI fist.
 *
 */
bool	PI_SPI_SendReceive	(uint8_t *pSrc, uint8_t *pDest, uint16_t usBytes, uint32_t pid);

/** @brief Reads data using SPI
 *
 * @param pDest Pointer to location to put the received data.
 *                    Returned value will be incremented by number of bytes received.
 * @param usBytes number of bytes of the transaction
 * @param pid Unique task ID. Used to make sure tasks don't step on each other.
 * @return true - Operation completed.\n
 *         false - This task did lock the SPI fist.
 */
bool 	PI_SPI_Read			(uint8_t *pDest, uint16_t usBytes, uint32_t pid);

/**
 * @brief Write to a SPI device
 *
 * @param pSrc Pointer to data buffer with data to be transmitted.
 *                    Returned value will be incremented by number of attempted writes.
 * @param usBytes Number of bytes of the transaction
 * @param pid Unique task ID. Used to make sure tasks don't step on each other.
 * @return true - Operation completed.\n
 *         false - This task did lock the SPI fist.
 */
bool 	PI_SPI_Write		(uint8_t *pSrc, uint16_t usBytes, uint32_t pid);


#if defined(SPI_REQUIRE_LOCK)

	/**
	 * @brief Get lock on SPI access.
	 *
	 * @param pid Unique program ID to attempt to lock RSPI with
	 * @return true - lock acquired \n
	 *         false - lock not acquired
	 */
	bool 	PI_SPI_Lock			(uint32_t pid);

	/**
	 * @brief Release SPI lock so another task can use it.
	 *
	 * @param pid Unique program ID to attempt to lock RSPI with
	 * @return true - lock was relinquished
	 *         false - lock was not previously given to this ID
	 */
	bool 	PI_SPI_Unlock		(uint32_t pid);

	/**
	 * @brief Checks to see if PID matches the one that took the lock
	 *
	 * @param pid Process ID to check against.
	 * @return true - This task has the lock
	 *         false - This task does not have the lock
	 */
	bool 	PI_SPI_CheckLock	(uint32_t pid);

	/**
	 * @brief Checks the active CS channel
	 *
	 * @param none.
	 * @return CS asctive SPI channel
	 */
	uint8_t PI_SPI_Channel_Select_Check();

#endif
/// @}
#endif /* PI_SPI_BCM2835_H_ */
