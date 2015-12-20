/************************
 * main.h
 *
 *  Created on: Feb 18, 2015
 *  author: Luis Alvarez
 */

/*!
 * \mainpage Motor Control Unit operated from IEC61850 testing lab
 *
 * This code is part of an Embedded Systems Project developed by a team of Finnish and international VAMK's students
 *
 * \warning
 * RASPBERRRY PI IS POWERED UP BY THE "ENERGY METER" BOARD ATTACHED TO IT. THIS BOARD HAS TWO INDEPENDENT POWER SOURCES, ONE TO DRIVE
 * THE ADE7880 ANOTHER TO DRIVE THE RASPI, DO NOT CONNECT THE POWER CORD TO THE RASPI, IT GETS THE POWER FROM THIS BOARD.
 * \warning
 * RISK OF SHOCK. AVOID MANIPULATING THIS BOARD WHEN CONNECTED, SINCE THE ADE7880 AND THE POWER GRID (ENERGY SOURCE UNDER MEASUREMENT,
 * THE ELECTRIC MOTOR IN THISCASE) SHARE THE NEUTRAL, TOUCHING PARTS OF THIS BOARD CAN DERIVE THE CURRENT FROM THE GRID'S NEUTRAL LINE
 * TO GROUND THROUGH YOUR BODY PRODUCING A SHOCK . FOR THIS REASON ONE SHOUD KEEP THIS BOX CLOSED AND ISOLATED.

 * \par Scope of the project
 *
 * Target:
 *
 * Mechanical department has a gasoline powered generator in Technobothnia. This system needs a system so it can be operated remotely
 * from DEMVE - laboratory with ABB MicroSCADA like system (made in programming project). DEMVE  laboratory is a IEC61850 - standard
 * testing laboratory.
 * Electrical deparment has a Vacon Drive for Solar batteries. We need to collect information and control the operation of the solar
 * charger.
 * System developed in this project has to create a HW and SW for communicating with IEC61850 standard.
 *
 * With this system operator has to be able to
 * - read motor status
 * - read generated power
 * - read load current
 * - read generator voltages
 * - change the status of motor (on / off)
 *
 * System will automatically send events of
 * - error conditions
 * - changes of status of motor
 *
 * Used devices and libraries:
 *  Raspberry Pi
 *  Renesas M16C62P
 *  Atmega32
 *  bcm2835
 *  libIEC61850
 *
 * \par Description of the code
 *
 * This code was written to control the motor and the energy produced by the electric motor attached to it. A brief description,
 * the software basically connects a Raspberry Pi to three external devices, an ADE7880 that measures the produced energy, an Atmega32 µController
 * that reads the motor sensors and to DEMVE  laboratory to update the information.
 * To achieve this, SPI and TCP/IP are in use, the first to connect to ADE7880 and Atmega32 from the RasPi and the second to connect to DEMVE lab
 * by means of IEC61850 protocol.
 *
 * Each part can be easily find in the code by the name of the folder. 'pi_ade7880' contains the middware driver for RasPi and, inside it, 'ade7880'
 * the SPI driver for the ADE7880 energy meter. The middware driver is built to interact with the ADE7880 driver without affecting the driver
 * structure, in a way that provides the driver with callbacks to SPI driver and GPIO access. This is needed because the ADE7880 was built trying
 * to achieve a fully portable code, independent of the hardware (it's already been tested in RasPi, so should work on any Linux environment,
 * and Renesas µController). The ADE7880 driver provides access to the IC hardware by its own HAL and offering a set of public functions to control
 * and read the measured values.
 * The folder 'pi_m16c_spi' offers a set of functions and the required header file mapping the addresses that hold the motor sensor information
 * in the RENESAS M16C62P.
 * The folder 'pi_avr_spi' offers a set of functions and the required header file mapping the addresses that hold the motor sensor information
 * in the Atmega32.
 * The folder 'pi_spi_bcm2835' contains the code built for controlling the access to the RasPi bcm gpio library. This driver offeres a non blocking access'
 * and is reentrant. Since two different modules require it,
 * and both working at very different speeds, the traffic requires to be handled. This is done by driver semaphores and application caller control.
 * The previous applications do not call directly the SPI bus, but using the methods provided by this middware instead.
 * The folder 'libIEC61850_server' contains the code of the public libIEC61850 library which we use to build the proper data structure and to transmit
 * it to the network and read by DEMVE
 *
 * The application runs in different threads, each one for its purpose, energy measurements, motor sensor readings and motor control (libIEC61850). and they can be
 * located into the 'src' folder and easily identifiable.
 *
 * To a better understanding of each of them, read the different modules of this documentation.
 *
 * This code requires the designed "ENERGY METER" board attached to the RasPi. HoldiNg the ADE7880 IC, external connectors for its required inputs
 * and SPI inputs coming from the M16C62P or Atmega32. It provides isolation to the circuitry, protecting it from the energy meter ground, since this
 * device uses a common ground for voltage measurements from the power grid.
 *
 *
 * Despite the initial specification mentions a change of start/stop status, due to safety restrictions in the labs, this part
 * is not covered here and as we could not interact in any way with the motor, a black box simulating all the incoming signals from the motor
 * is made for testing purposes.
 * The specifications doesn't mention the temperature sensors range so a default of 0 to 150C is established
 *
 * \author Luis Alvarez
 */

#ifndef MAIN_H_
#define MAIN_H_

/* Common libraries for 'src' files */


#include <stdlib.h>     /* General Utilities */
#include <stdint.h>
#include <stdio.h>		/* Input/Output */
#include <string.h>		/* String handling */
#include <unistd.h>		/* Symbolic Constants */
#include <stdbool.h>	/* boolean values */
#include <pthread.h>	/* POSIX Threads */
#include <semaphore.h>  /* Semaphore */



#include "../libIEC61850_server/include/iec61850_wrapper.h"
#include "../libIEC61850_server/static_model.h"
#include "../pi_ade7880/src/ade7880_driver.h"
#include "../pi_m16c_spi/m16c_spi.h"
#include "./m16c_motor_data/m16c_motor_data.h"
#include "../pi_avr_spi/pi_avr_spi.h"
#include "../pi_spi_bcm2835/pi_spi_bcm2835.h"
#include "./motor_control/motor_control_srvc.h"
#include "./energy_data/energy_meter.h"

#include "./avr_motor_data/avr_motor_data.h"

#include "./motor_control/transmission.h"


/// The Process ID to use when locking the RasPi SPI peripheral by call from Harmonics meter application.
#define MAIN_APP_PID          	(0xA3D463E1)

//Define which threads to create
#define RUN_IEC_SERVER 		1
#define READ_FROM_ADE7880	1
#define READ_FROM_M16C		1
#define READ_FROM_AVR		0

/* ENERGY MEASUREMENT ATTRIBUTES: REAL DATA*/
// Individual data
typedef struct
{
	float value;			// Measured Data
	uint64_t timestamp;		// Time stamp
}em_tval_st;


//Phase related data storage
typedef struct
{
	em_tval_st IRMS; 	// Current RMS
	em_tval_st VRMS;	// Voltage RMS
	em_tval_st WH;		// Watts hour
	em_tval_st POWER;	// instantaneous power in Watts
} em_phase_t;


// Neutral line related data storage
typedef struct
{
	em_tval_st IN_IRMS;							// Neutral current RMS value
	em_tval_st INSTANT_IN;						// Instantaneous Neutral current
	// Neutral current Harmonics RMS values
	em_tval_st IN_HXIRMS;
	em_tval_st IN_HYIRMS;
	em_tval_st IN_HZIRMS;
	// Neutral current Harmonic distortion
	em_tval_st IN_HXIHD;
	em_tval_st IN_HYIHD;
	em_tval_st IN_HZIHD;
	// ISUM RMS values
	em_tval_st ISUM_HXVRMS;
	em_tval_st ISUM_HYVRMS;
	em_tval_st ISUM_HZVRMS;
	// ISUM Harmonics distortion
	em_tval_st ISUM_HXVHD;
	em_tval_st ISUM_HYVHD;
	em_tval_st ISUM_HZVHD;
} em_neutral_t;


// Global container
typedef struct
{
	em_phase_t phase_a;
	em_phase_t phase_b;
	em_phase_t phase_c;
	em_neutral_t neutral_line;
} em_data_t;


/* MOTOR MEASUREMENT ATTRIBUTES: REAL DATA*/
typedef union
{
	uint16_t  bin_all;
	struct
	{
		uint16_t oil_pressure_OK	:1;
		uint16_t emergency_stop		:1;
		uint16_t min_fuel_lvl		:1;
		uint16_t annealing_ON		:1;
		uint16_t battery_charging	:1;
		uint16_t motor_on			:1;
		uint16_t motor_off			:1;
		uint16_t reserved			:9; // These bits are always 0
	}bit_s;
}mc_bin__ut;

typedef struct
{
	mc_bin__ut value;
	uint64_t timestamp;
}mc_bval_st;

typedef struct
{
	float value;
	uint64_t timestamp;

}mc_tval_st;

typedef struct
{
	uint8_t			command;
	uint8_t 		cmd_addr;
	mc_tval_st		torque;
	mc_tval_st 		suction_temp;
	mc_tval_st		coolant_in_temp;
	mc_tval_st		coolant_return_temp;
	mc_tval_st		block_temp;
	mc_tval_st		exhaust_temp;
	mc_tval_st		oil_temp;
	mc_tval_st  	crankShaft_rpm;
	mc_tval_st  	fuel_in;
	mc_tval_st  	fuel_return;
	mc_tval_st  	suction_flow;
	mc_bval_st   	bin_input;
} mc_data_st;


/* COMPLETE DATA */

typedef struct
{
	em_data_t 	energy;
	mc_data_st  motor;
} server_data_st;



int 	getkey				(void);

#endif /* MAIN_H_ */
