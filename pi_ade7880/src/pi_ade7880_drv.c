/// \file pi_ade7880_drv.c
/// \brief \e Purpose: \n Middleware driver for RasPi SPI with ADE7880
/******************************************************************************
 * File Name     : pi_ade7880_drv.c
 * Version       : 1.0
 * Device(s)     : ADE7880
 * Tool-Chain    : GNU x86 64  ARM (RasPi) Renesas RX Standard Toolchain 1.0.0
 * OS            : None
 * H/W Platform  : Raspberry Pi
 * Description   : This provides with access to the ADE7880 from the board in operation.
 *******************************************************************************/
/*******************************************************************************
 * History : DD.MM.YYYY     	Version     Description
 *         : 22.09.2014     	1.00        First release
 *         : 03.10.2014		1.10		Added error return to R_ADE_Initialize, R_ADE_Power_mode, R_ADE_Comm_initialize
 *******************************************************************************/

/*******************************************************************************
 Includes   <System Includes> , "Project Includes"
 *******************************************************************************/
/***********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include "./ade7880/ade7880_configuration.h"
#include "./ade7880/ade7880_registers.h"
#include "./ade7880/ade7880_spi_protocol.h"
#include "./ade7880/ade7880_srv_cmd_handler.h"
#include "../pi_ade7880_config.h"
#include "pi_ade7880_drv.h"
#include "../../pi_spi_bcm2835/pi_spi_bcm2835.h"



/*******************************************************************************
 * Prototypes for local functions
 *******************************************************************************/

/******************************************************************************
 * Function name: PI_ADE_ADE7880_driverCallbacks
 * Description  : Initializes the hardware SPI channel and power mode pin outputs
 * Arguments    :
 * Return Value :
 ******************************************************************************/
void PI_ADE_ADE7880_driverCallbacks(void)
{
	/*   */
	ADE_SPI_WRITE_callback_set(&PI_ADE_SPI_Write);
	ADE_SPI_READ_callback_set(&PI_ADE_SPI_Read);
	ADE_COMM_INIT_callback_set(&PI_ADE_Comm_initialize);
	ADE_POWER_MODE_callback_set(&PI_ADE_Power_mode);
	ADE_SPI_COMMLOCK_callback_set(&PI_ADE_SPI_commLock);
}
/* End of PI_ADE_ADE7880_driverCallbacks() */

/******************************************************************************
 * Function name: PI_ADE_power_up_proocedure
 * Description  : ADE power up procedure step by step
 * Arguments    : none
 * Return value : 0
 ******************************************************************************/
int8_t PI_ADE_power_up_procedure(void)
{
	/**************************************
	 * TODO check IRQ1, why RSTDONE blocks communications?
	 */

	int8_t err = 0;

	// Force a hardware reset to start up from the beginning. Set RESET pin to low state
	PI_ADE_HW_reset();

	/* Wait at least 26ms for ADE7880 to enter in PSM3 mode and set PSM0
	 If power supply was off, this period is much longer since the internal VDD monitor
	 has to detect a power crossing up a threshold of 2V (DS p.23 1st paragraph) 		*/
	usleep(100000);

	/* Set the power mode as normal mode */
	// RasPi can set ADE7880 by PI_ADE_Power_mode(Power mode)
	PIN_LEVEL_HIGH(PIN_PM0);
	PIN_LEVEL_LOW(PIN_PM1);

	/* Wait until RSTDONE /IRQ1 is triggered, about 40ms */
	//while ( !callback_IRQ1() );
	usleep(100000);

	/* µProcessor can make now the choice between I2C or SPI Protocol done by ADE_command_handler(ADE7880_SPI_COMM_LOCK, NO_ARGS)*/
	// toggle the SSL pin 3 times
	/*
	 // Clear RSTDONE IRQ1 bit
	 STATUS1_reg_u STATUS1_reg;
	 R_ADE_Comm_initialize(SPI);
	 while ( !(STATUS1_reg.REG_ALL = ADE_SPI_read( CHIP_ADDRESS1,
	 STATUS1,
	 REG_LENGTH(STATUS1_reg.REG_ALL))) )
	 {
	 printf("RSTDONE status = %d \n", STATUS1_reg.bits.RSTDONE);
	 delay_msec(100);
	 R_ADE_Comm_initialize(SPI);
	 }
	 printf("RSTDONE change status = %d \n", STATUS1_reg.bits.RSTDONE);

	 STATUS1_reg.REG_ALL = STATUS1_DEFAULT;
	 STATUS1_reg.bits.RSTDONE = 1;
	 R_ADE_Comm_initialize(SPI);
	 err = ADE_SPI_write(CHIP_ADDRESS1, STATUS1,
	 STATUS1_reg.REG_ALL,
	 REG_LENGTH(STATUS1_reg.REG_ALL));
	 */



	return err;

} /* End of R_ADE_power_up_proocedure() */


/******************************************************************************
 * Function name: PI_ADE_HW_reset
 * Description  : Produces an active low signal to the ADE7880 reset pin
 * Arguments    : none
 * Return Value : 0
 ******************************************************************************/
int8_t PI_ADE_HW_reset(void)
{
	/* Force a hardware reset to start up from the beginning. Set RESET pin to low state */
	PIN_LEVEL_LOW(PIN_RESET);

	/* hold the Reset pin low at least 10µs and return to an inactive state high */
	usleep(10000);
	PIN_LEVEL_HIGH(PIN_RESET);

	return 0;
} /* End of PI_ADE_HW_reset() */

/******************************************************************************
 * Function name: PI_ADE_InitializeHardware_SPI
 * Description  : Initializes the hardware SPI channel and power mode pin outputs
 * Arguments    :
 * Return Value :
 ******************************************************************************/
void PI_ADE_InitializeHardware_SPI(uint8_t bitOrder, uint8_t dataMode,
		uint16_t clockDivider, uint8_t polarity, uint8_t chipSelect)
{
	/* Open the Hardware channel in  µC */
	PI_SPI_Init(bitOrder, dataMode, clockDivider, polarity, chipSelect);

}
/* End of PI_ADE_InitializeHardware_SPI() */

/***********************************************************************************************************************
 * Function Name: PI_ADE_Power_mode
 * Description  : Sets the RX63N defined pins PM0 and PM1 of ADE7880 to the required starting power mode, usually PM0
 * Arguments    : mode -
 *                    The required Power Mode PSM0, PSM1, PSM2 or PSM3.
 * Return Value : 0-
 *					Power mode set
 *				 any
 *					The given power mode does not exist.
 ***********************************************************************************************************************/
int8_t PI_ADE_Power_mode(uint8_t mode)
{
	int8_t err = 0;

	switch (mode)
	{
	case PSM0:
		// Normal Power Mode
		PIN_LEVEL_HIGH(PIN_PM0);
		PIN_LEVEL_LOW(PIN_PM1);
		break;
	case PSM1:
		// Reduced Power Mode
		PIN_LEVEL_LOW(PIN_PM0);
		PIN_LEVEL_LOW(PIN_PM1);
		break;
	case PSM2:
		// Low Power Mode
		PIN_LEVEL_LOW(PIN_PM0);
		PIN_LEVEL_HIGH(PIN_PM1);
		break;
	case PSM3:
	{
		// Sleep Mode
		PIN_LEVEL_HIGH(PIN_PM0);
		PIN_LEVEL_HIGH(PIN_PM1);
	}
		break;
	default:
		err = ADE_ERROR_POWER_MODE;
		break;
	}

	return err;
}/* End of function PI_ADE_Power_mode() */

/***********************************************************************************************************************
 * Function Name: PI_ADE_Comm_initialize
 * Description  : Sets the ADE7880 communication protocol to the selected mode. So far only SPI is set.
 * 				  Set mode to SPI by toggling the CS pin 3 times. This does not lock the channel.
 * 				  If channel is unlocked, CS has to be toggled before every transmission
 * Arguments    : mode -
 *                    The selected protocol.
 * Return Value : 0-
 *					Set
 *				 -1
 *					The given protocol does not exist.
 ***********************************************************************************************************************/
int8_t PI_ADE_Comm_initialize(uint8_t mode, uint32_t pid)
{
	int8_t err = 0;
	switch (mode)
	{
	case SPI: /* SPI protocol */
	{
		uint8_t i = 0;

		for (i = 0; i < 3; i++)
		{
			ADE_SPI_write(DUMMY, 0x00, REG_LENGTH(uint8_t), pid);
		}
		/* Write Bit 1 (I2C_LOCK) of the CONFIG2 to lock SPI, NOT DONE HERE */

		break;
	}
	case I2C: /* I2C Protocol */
	{
		/* NOT IMPLEMENTED */
		err = ADE_ERROR_COMM_MODE;
		break;
	}
	case HSDC: /* High Speed Data Capture */
	{
		/* NOT IMPLEMENTED	*/
		err = ADE_ERROR_COMM_MODE;
		break;
	}
	default:
		err = ADE_ERROR_COMM_MODE;
		break;
	}
	//one may check the state of the pin's here to verify their status

	return err;
}
/* End of function ade_communication_mode() */

/******************************************************************************
 * Function name: PI_ADE_SPI_commLock
 * Description  : After toggling CS x3 times
 *				 Any write to CONFIG2 will lock the SPI port until device restart or hardware reset
 * Arguments    : none
 * Return value : error
 ******************************************************************************/
int8_t PI_ADE_SPI_commLock(uint32_t pid)
{
	uint8_t err = 0;
	CONFIG2_reg_u CONFIG2_reg;

	// Toggle CS pin high to low 3 times
	PI_ADE_Comm_initialize(SPI, pid);

	//After toggling CS x3 times
	// Any write to CONFIG2 will lock the SPI port until device restart or hardware reset
	//CONFIG2_reg.REG_ALL = 0xAA;
	CONFIG2_reg.REG_ALL = 0x00;
	//if((err = ADE_SPI_read(CONFIG2, REG_LENGTH(CONFIG2_reg.REG_ALL), &result)) != ADE_NO_ERROR)  { return err; };
	//CONFIG2_reg.REG_ALL = (uint8_t)result;

	//Any write to CONFIG2 will lock the spi port untill device restart or hardware reset
	CONFIG2_reg.bits.I2C_LOCK = 1;
	err = ADE_SPI_write(CONFIG2,
						CONFIG2_reg.REG_ALL,
						REG_LENGTH(CONFIG2_reg.REG_ALL),
						pid);

	return err;
}

/***********************************************************************************************************************
 * Function Name: PI_ADE_SPI_Write
 * Description  : sends data out of the Raspi SPI. This also takes care of locking the SPI peripheral.
 * Arguments    : data-
 *                    Pointer to the tx data buffer.
 *                usBytes-
 *                	The length of the register that has to be written
 * Return Value : none
 ***********************************************************************************************************************/
int8_t PI_ADE_SPI_Write(uint8_t *data, uint8_t usBytes, uint32_t pid)
{
	bool locked = false;

	/* Attempt to lock the SPI peripheral. */
	while ( false == (locked = PI_SPI_Lock(pid)))
	{
		/* Wait until lock is given up or 'count' cycles. At this point another task must unlock the RSPI peripheral before we can
		 lock it here. This means this other task must unlock from an ISR or from another RTOS task. */
		//usleep(ADE_LOCK_DELAY_MICROS);
	}

	if (locked)
	{
		/* The lock has been obtained. Check last access and
		 * Set the proper clock speed and assert the Channel Select
		 * if proceed  */
		if(pid != PI_SPI_last_caller_pid())
		{
			PI_SPI_SetClockSpeed(ADE_SPI_CLOCK_SPEED, pid);
			PI_SPI_Channel_Select( ADE_SPI_CHANNEL, pid);
		}

		/* Send the data. */
		//    R_RSPI_Write(ADE_RSPI_CHANNEL, (const uint8_t *)&data, (reg_len+WR_MSG_OVERHEAD), ADE_RSPI_PID);
		PI_SPI_Write(data, (usBytes), pid);

		/* Release the lock. */
		PI_SPI_Unlock( pid);

	}
	else
	{
		return -1;
	}

	return 0;

}/* End of function PI_ADE_SPI_Write() */

/***********************************************************************************************************************
 * Function Name: ADE_SPI_read
 * Description  : reads data from the ADE7880. This also takes care of locking the
 RSPI peripheral.
 * Arguments    : data-
 *                    Pointer to the tx data buffer.
 *                usBytes-
 *                	The length of the register that has to be read
 * Return Value : none
 ***********************************************************************************************************************/
int8_t PI_ADE_SPI_Read(uint8_t *data, uint8_t usBytes, uint32_t pid)
{
	bool locked = false;
	/* Attempt to lock the SPI peripheral. */
	while ( false == (locked = PI_SPI_Lock(pid)))
	{
		/* Wait until lock is given up or 'count' cycles. At this point another task must unlock the RSPI peripheral before we can
		 lock it here. This means this other task must unlock from an ISR or from another RTOS task. */
		//usleep(ADE_LOCK_DELAY_MICROS);
	}

	if (locked)
	{
		/* The lock has been obtained. Check last access and set the proper clock speed and assert the Channel Select
		 * if proceed  */
		if(pid != PI_SPI_last_caller_pid())
		{
			PI_SPI_SetClockSpeed(ADE_SPI_CLOCK_SPEED, pid);
			PI_SPI_Channel_Select( ADE_SPI_CHANNEL, pid);
		}
		/* Send the data. */
		PI_SPI_Read(data, usBytes, pid);

		/* Release the lock. */
		PI_SPI_Unlock( pid);

	}
	else
	{
		return -1;
	}

	return 0;
}/* End of function ADE_SPI_read() */

/***********************************************************************************************************************
 * Function Name: ADE_SPI_TransferN
 * Description  : sends data out of the RSPI. This also takes care of locking the This function is ADE_SPI_TransferNB()
 *				where the returned data will be stored in the same pointer location as the source pointer
 *					RSPI peripheral.
 * Arguments    : data-
 *                    Pointer to the tx data buffer.
 *                usBytes-
 *                	The length of the payload that has to be transfered
 * Return Value : none
 ***********************************************************************************************************************/
int8_t PI_ADE_SPI_TransferN(uint8_t *data, uint32_t usBytes, uint32_t pid)
{
	/* Call . */
	PI_ADE_SPI_TransferNB(data, data, usBytes, pid);

	return 0;
}/* End of function ADE_TransferN() */

/***********************************************************************************************************************
 * Function Name: ADE_SPI_TransferNB
 * Description  : sends data out of the RSPI. This also takes care of locking the
 RSPI peripheral.
 * Arguments    : pScr-
 *                    Pointer to source outgoing tx data buffer.
 *                pDest-
 *                    Pointer to destination incoming tx data buffer.
 *                usBytes-
 *                	The length of the register that has to be read
 *
 * Return Value : none
 ***********************************************************************************************************************/
int8_t PI_ADE_SPI_TransferNB(uint8_t *pScr, uint8_t *pDest, uint32_t usBytes, uint32_t pid)
{
	bool locked = false;
	/* Attempt to lock the RSPI peripheral. */
	while ( false == (locked = PI_SPI_Lock( pid)))
	{
		usleep(ADE_LOCK_DELAY_MICROS);
	}

	if (locked)
	{
		if(pid != PI_SPI_last_caller_pid())
		{
			PI_SPI_SetClockSpeed(ADE_SPI_CLOCK_SPEED, pid);
			PI_SPI_Channel_Select( ADE_SPI_CHANNEL, pid);
		}

		/* Send the data. */
		PI_SPI_SendReceive(pScr, pDest, usBytes, pid);

		/* Release the lock. */
		PI_SPI_Unlock(pid);

	}
	else

		return -1;

	return 0;

}/* End of function ADE_SPI_TransferNB() */

/*******************************************************************************
 * Outline 		: htons & htonl
 * Module        : SPI ADEdrv, MCU/Board Level HAL
 * Description   : Bit order arrangement, call their respective macros
 * Argument 	 	: val-
 * 					The given variable value to organize
 * Return value  : The organized value if needed
 *******************************************************************************/
uint16_t htons(uint16_t val)
{
	return HTONS(val);
}
uint32_t htonl(uint32_t val)
{
	return HTONL(val);
}

/******************************************************************************/



/*******************************************************************************
 * End of function htons & htonl
 *******************************************************************************/
