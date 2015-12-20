/*
 * energyMeter.h
 *
 *  Created on: Feb 13, 2015
 *      Author: Luis
 */

#ifndef ENERGYMETER_H_
#define ENERGYMETER_H_

/// The Process ID to use when locking the RasPi SPI peripheral by call from Eneregy meter application.
#define ENERGY_APP_PID          	(0x5950474C)





void* reading_energy(void *arg);


#endif /* ENERGYMETER_H_ */
