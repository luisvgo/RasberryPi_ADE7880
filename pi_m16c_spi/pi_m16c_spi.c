/*
 * pi_m16c_spi.c
 *
 *  Created on: Feb 18, 2015
 *      Author: oops
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include "../pi_spi_bcm2835/pi_spi_bcm2835.h"
#include "pi_m16c_spi.h"
#include "definitions.h"



/***********************************************************************************************************************
 * Function Name: PI_M16C_SPI_Write
 * Description  : sends data out of the Raspi SPI. This also takes care of locking the SPI peripheral.
 * Arguments    : data-
 *                    Pointer to the tx data buffer.
 *                usBytes-
 *                	The length of the register that has to be written
 * Return Value : none
 ***********************************************************************************************************************/
int8_t PI_M16C_SPI_Write(uint8_t *data, uint8_t usBytes, uint32_t pid)
{
	bool locked = false;

	/* Attempt to lock the SPI peripheral. */
	while ( false == (locked = PI_SPI_Lock( pid)))
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
			PI_SPI_Channel_Select( M16C_SPI_CHANNEL, pid);
			PI_SPI_SetClockSpeed(M16C_SPI_CLOCK_SPEED, pid);
		}

		/* Send the data. */
		//    R_RSPI_Write(ADE_RSPI_CHANNEL, (const uint8_t *)&data, (reg_len+WR_MSG_OVERHEAD), ADE_RSPI_PID);
		PI_SPI_Write(data, (usBytes), pid);

		/* Release the lock. */
		PI_SPI_Unlock(pid);

	}
	else
	{
		return -1;
	}

	return 0;

}/* End of function PI_ADE_SPI_Write() */

/***********************************************************************************************************************
 * Function Name: M16C_SPI_read
 * Description  : reads data from the m16c. This also takes care of locking the
 * SPI peripheral.
 * Arguments    : data-
 *                    Pointer to the tx data buffer.
 *                usBytes-
 *                	The length of the register that has to be read
 * Return Value : none
 ***********************************************************************************************************************/
int8_t PI_M16C_SPI_Read(uint8_t *data, uint8_t usBytes, uint32_t pid)
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
			PI_SPI_Channel_Select( M16C_SPI_CHANNEL, pid);
			PI_SPI_SetClockSpeed(M16C_SPI_CLOCK_SPEED, pid);
		}

		/* Send the data. */
		PI_SPI_Read(data, usBytes, pid);

		/* Release the lock. */
		PI_SPI_Unlock(pid);

	}
	else
	{
		return -1;
	}

	return 0;
}/* End of function M16C_SPI_read() */


