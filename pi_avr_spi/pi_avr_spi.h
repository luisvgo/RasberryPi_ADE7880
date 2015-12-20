/*
 * pi_avr_spi.h
 *
 *  Created on: Mar 11, 2015
 *      Author: oops
 */

#ifndef PI_AVR_SPI_H_
#define PI_AVR_SPI_H_

#define ATMEGA_SPI_CLOCKSPEED 0 // 3Mbps
#define ATMEGA_SPI_CHANNEL (CHANNEL1_SELECTED)


int8_t PI_AVR_SPI_read(uint8_t *data, uint8_t usBytes, uint32_t pid);

#endif /* PI_AVR_SPI_H_ */
