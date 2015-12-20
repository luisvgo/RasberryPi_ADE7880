/*
 * pi_m16c_spi.h
 *
 *  Created on: Feb 18, 2015
 *      Author: oops
 */

#ifndef PI_M16C_SPI_H_
#define PI_M16C_SPI_H_

int8_t PI_M16C_SPI_Read(uint8_t *data, uint8_t usBytes, uint32_t pid);
int8_t PI_M16C_SPI_Write(uint8_t *data, uint8_t usBytes, uint32_t pid);

#endif /* PI_M16C_SPI_H_ */
