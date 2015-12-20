/// \file ade7880_driver.h
/// \brief \e Purpose: \n Headers for accessing the driver

/******************************************************************************
* File Name     : ade7880_driver.h
* Version       : 1.0
* Device(s)     : ADE7880 driver for Renesas & raspy
* Tool-Chain    : Tested with GCC x86 64 and Renesas RX Standard Toolchain 2.02.00
* OS            : None
* H/W Platform  : ADE7880
* Description   :
*******************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
* 		  						Includes common definitions and macros
***********************************************************************************************************************/
/***************************************************************************************************//**
 *
 *  \defgroup ade_driver ADE7880 Driver
 *  \par A summary of the ADE7880 properties
 *
 * - 7 inputs for phase and neutral:
 * - 4 pairs of full differential Vin (input in pairs, max. input ±0.5V) for current channels
 * - 3 more input pairs for voltage channels
 *
 * - ADC:
 *
 * -# 7 E-A (sigma-delta) ADCs ±0.5V signal full scale
 * -# ADCMAX = 5,928,256, the ADC output when the input is at full scale.
 * -# Work according power mode
 * -# Sampling clock = CLKIN/16 = 1024MHz.
 * -# The ADC outputs are signed twos complement 24-bit data-words and are available at a rate of 8 kSPS.
 * -# E-A ADC have a LPF at their final stage to anti-aliasing. Are -20dB/decay so pay attention when
 * -# using Rogowsky sensor, this is +20dB/decay and they neutralize each other.
 * -# When using a di/dt sensor, there are independent built-in integrators that can be activated
 * -# independently for each channel. They have a -20dB/dec so they offset the 20dB/dec again.
 * -# Cascade another RC filter to get -40dB/dec to solve these issues.
 * -# The ADC output is between -5,326,737 (0xAEB86F) and +5,326,737 (0x514791). Note that these are nominal
 *  values and every ADE7880 varies around these values.
 * -# The registers are 24bits and they can be accessed as 32 bits with 24 bits right padded of info,
 *  4 more bits padded as bit 23 (it is a sign bit) and 4 more padded as bit 23 in some registers or 0 in
 *  some other.
 * -# The ADE7880 can be configured to output a signal when the calculations are ready to read.
 *
 * - Communication:
 * -# Serial interfaces I2C, SPI or HSDC. For harmonics reading, HSDC in burst mode reading is recommended.
 * Working modes of interest:
 * -# As Energy meter, where all Fundamental, Apparent, Reactive or accumulated instantaneous or RMS phase
 * powers and their components are calculated and many different properties of the signal can be computed.
 * -# As a Harmonics meter, contains a harmonic engine that analyses one phase at a time. Harmonic information
 * is computed with a no attenuation pass band of 2.8 kHz (corresponding to a -3 dB bandwidth of 3.3 kHz)
 * and it is specified for line frequencies between 45 Hz and 66 Hz. Neutral current can also be analysed
 * simultaneously with the sum of the phase currents. Figure 82 at p.58 of the Data-Sheet presents a
 * synthesized diagram of the harmonic engine, its settings and its output registers.
 *
 *
 /// @{
 * \brief An ADE7880 Energy Meter middware driver for Raspberry Pi SPI
 *
 * \par Driver implementation
 *
 * HAL, Driver and Middware C code
 *
 * This ADE7880 will be used as a slave of a Raspberry Pi to measure the produced energy.
 * For that reason a HAL, a driver and middware were implemented to operate
 * with it.
 *
 * Following the same structure as all along the code, folders starting by 'pi_*' are specific RaspPi
 * drivers to operate the peripheral indicated by the tail name.
 * As in this case 'pi_ade7880' indicates that is the driver that provides control
 * and a set of functions and callbacks to drive the ADE7880 IC.
 *
 * Inside this folder, one may find subfolders named by the peripheral's name,
 * 'ade7880', indicating that this is an external peripheral with its independent HAL and
 * driver. Files starting by the peripheral name 'ade7880_*' are specific HAL and driver code,
 * build to be independent to the µC and portable C code, such in away that only a set of files in the parent
 * folder are required as middware to allow other systems specific code interact with the driver.
 * Files starting by 'pi_*' followed by the peripheral's name, as 'pi_ade7880*' belong to the middware
 * that provides access to and from the Raspberry Pi with the ADE7880 IC.
 * \code
 * /pi_ade7880						Folder containig middware, driver and HAL
 * 	|_pi_ade7880_config.h			RasPi SPI to ADE Hook configuration file
 * 	|_/src
 * 		|_ade_driver.h				Provides access to the driver from outside world
 * 		|_ /ade7880					Driver and HAL
 * 			|_ade7880_registers	§	HAL definitions
 * 			|_ade7880_configuration Speciphic ADE IC configuration definitions
 * 			|_ade_spi_protocol		Builds the Tx Rv buffer and callbacks to pi_ade middware
 * 			|_ade_src_cmd_handler	Provides two main public functions to interact with the IC
 * 		|_pi_ade7880_drv			Middware driver to allow ADE driver access RasPi SPI driver
 * 		|_pi_ade_gpio				Middware driver to allow ADE driver access the GPIO pins
 * \endcode
 * To implement this driver and have access to the public functions, one should include the file
 * "ade7880_driver.h" into the files requiring it.
 *
 * \par Middware driver
 * files starting by 'pi_ade7880*' provide the hook code in that way that the ADE driver can call the
 * functions in here not having to know how to access the SPI driver.
 * The functions in here allow to connect the ADE pins to RasPi GPIO providing direct hardware access
 * to manipulate the pins state, as i.e. to modify the working mode and a set of functions to allow
 * SPI reads and writes from/to the ADE
 *
 * This middware is µController or processor dependent in a way that specificµControllerand hardware
 * access like I/O addresses are hanled here so they are hidden to the ADE7880 driver.
 *
 *
 * \par ADE7880 Driver
 * files here build the transmission buffer and read back the incoming SPI information. Provide
 * two main methods to handle the most important operations, 'ADE_command_handler()' and 'ADE_measure()'
 * understanding these two, one can operate the energy meter to configure and obtain measurements.
 *
 ***************************************************************************************************/
/*******************************************************************************
*
* History : DD.MM.YYYY     	Version     Description
*         : 24.01.2015     	1.00        First release
*******************************************************************************/

/*******************************************************************************
Includes   <System Includes> , "Project Includes"
*******************************************************************************/
#ifndef __ADE7880_DRIVER_H
#define __ADE7880_DRIVER_H

/***************************************************************************
 * SECTION:  SPECIFIC ADE CONSTANTS
 ***************************************************************************/



//#include "bcm2835.h"

#include "./ade7880/ade7880_registers.h"
#include "./ade7880/ade7880_configuration.h"

#include "./ade7880/ade7880_srv_cmd_handler.h"
#include "./pi_ade7880_drv.h"


//R_ADE_SPI_WRITE_CALLBACK

/// @}



#endif /* (____ADE7880_DRIVER_H ) */
