/*
 * transmission.h
 *
 *  Created on: Feb 13, 2015
 *      Author: oops
 */

#ifndef TRANSMISSION_H_
#define TRANSMISSION_H_

#define TIMESTAMP_NULL 0

enum{
	ENERGY_MEAS,
	HARMONICS_MEAS,
	MOTOR_SENSORS_REAL,
	MOTOR_SENSORS_INT
};



void 	transmit_measures	(uint8_t caller, void *data);

void print_energy_meas(void *data);
void print_harmonic_meas(void *data);
void print_motor_sensors(void *pData);
void print_motor_sensors_int(void *pData);

#endif /* TRANSMISSION_H_ */
