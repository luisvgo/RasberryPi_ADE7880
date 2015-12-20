/*
 * pi_avr_spi.c
 *
 *  Created on: Mar 11, 2015
 *      Author: oops
 */


#include <stdint.h>
#include <stdbool.h>	/* boolean values */

#include "pi_avr_spi.h"
#include "../pi_spi_bcm2835/pi_spi_bcm2835.h"

//for reading values from the Universal Board
int8_t PI_AVR_SPI_read(uint8_t *data, uint8_t usBytes, uint32_t pid) //pointer, number of bytes
{
	bool locked = false;
	while ( false == ( locked = PI_SPI_Lock (pid)))
	{
	}

	if (locked)
	{
		if(pid != PI_SPI_last_caller_pid())
		{
			PI_SPI_SetClockSpeed(ATMEGA_SPI_CLOCKSPEED, pid);
			PI_SPI_Channel_Select(ATMEGA_SPI_CHANNEL, pid);
		}

		PI_SPI_Read(data, usBytes, pid);

		PI_SPI_Unlock(pid);
	}

	else
	{
		return -1;
	}

return 0;
}//PI_ATMEGA_SPI_READ

