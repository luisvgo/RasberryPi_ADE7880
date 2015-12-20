/// \file ade7880_configuration.h
/// \brief contains ADE7880 configuration definitions
/// @author: Luis Alvarez
/// @version v 1.10
/***********************************************************************************************************************//**
 * \defgroup ADE7880_config ADE7880 Configuration file
 * \ingroup ade_driver
 * @{
 * \brief ADE7880 General Configuration file ade7880_configuration.h
 *
 * This file provides different definitions to serve as ADE7880 general standard configuration values for its
 * two main different working modes, as an energy meter or as a harmonics meter.
 *
 * To understand what these values refer to, one should cross-check them with the datasheet. Any change here will directly
 * affect to any ADE7880 measurement, for that reason is highly recommended to read the document before manipulating the
 * values here.
 *
 * The values here are standard to measure currents with a C.T. and one may use them as they are but, to a proper accuracy
 * and performance, the device should be calibrated as mentioned in the datasheet.
 *

 *
 */

#ifndef __ADE7880_CONFIGURATION_H
#define __ADE7880_CONFIGURATION_H


/// Set ADE7880 driver Debug mode
#ifdef DEBUG_ADE
#undef DEBUG_ADE
#endif

//#define DEBUG_ADE					0

///Chip address defines the id address given to the ADE. No use with SPI (7 MSBits of the transmission's buffer 1st byte i.e. 11111110).
///Last bit (LSB) cannot be used here since serves to differentiate a read or write operation
#define CHIP_ADDRESS1 			    0x00

/// \brief WRITE_TRANSFER_CHECK: Registers Write checking
/// Enables an extra function, when writing to a register that will check 3 different parameters to ensure that
/// a writing command to a register was successful.
///	This will allow to trace writes in case of error. Drawback, slows significantly the final overall system speed
#define WRITE_TRANSFER_CHECK	0


#define TRANSFORMER_RATIO       	20.56621005

/// Number of samples per measure. Each sample is a reading
#define NUMBER_OF_SAMPLES			1
/** @defgroup GAINS Global Input Gains
 * @{
 * Global Gains (Table 43 Gain Register, pag 96 DataSheet
 * \code
 * // GAIN Common multipliers defines defined in ade7880_registers.h
 * #define 	GAIN_1     		00
 * #define 	GAIN_2     		01
 * #define 	GAIN_4     		02
 * #define 	GAIN_8     		03
 * #define 	GAIN_16    		04
 * \endcode
 */
/// Select a multiplier for Phases Current input gain, default gain multiplier 1 = GAIN_1
#define PHASE_CURRENTS_GAIN			GAIN_1
/// Select a multiplier for neutral Current input gain, default gain multiplier 1 = GAIN_1
#define NEUTRAL_CURRENTS_GAIN		GAIN_1
/// Select a multiplier for Phases Voltage input gain, default gain multiplier 1 = GAIN_1
#define PHASE_VOLTAGES_GAIN			GAIN_1
///@}
/**
 * \defgroup ade_driver_energy	ADE Energy Calculations and Configuration
 * @{
 * \par ADE7880 QUICK SETUP AS ENERGY METER
 *
 * An energy meter is usually characterized by the nominal
 * current In, nominal voltage Vn, nominal frequency fn, and the meter constant MC.
 *
 * To quickly set up the ADE7880, execute the following steps:
 *
 * 1.
 * Select the PGA gains in the phase currents, voltages and neutral current channels: Bits[2:0](PGA1), Bits[5:3](PGA2) and Bits[8:6](PGA3) in the Gain register.
 *
 * 2.
 * If Rogowski coils are used, enable the digital integrators in the phase
 * and neutral currents: Bit 0 (INTEN) set to 1 in the CONFIG register.
 * Initialize the DICOEFF register to 0xFF8000 before setting the INTEN bit in the CONFIG register.
 *
 * 3.
 * If fn is between 55 Hz and 66 Hz, set Bit 14 (SELFREQ) in the COMPMODE register.
 *
 * 4.
 * Initialize all the other data memory RAM registers. Write
 * the last register in the queue three times to ensure that its
 * value is written into the RAM.
 *
 * 5.
 * Initialize the WTHR, VARTHR, VATHR, VLEVEL and
 * VNOM registers based on DataSheet Equation 26, Equation 37,
 * Equation 44, Equation 22, and Equation 42, respectively.
 *
 * 6.
 * Initialize CF1DEN, CF2DEN, and CF3DEN based on DataSheet
 * Equation 49.
 *
 * 7.
 * Enable the data memory RAM protection by writing 0xAD
 * to an internal 8-bit register located at Address 0xE7FE
 * followed by a write of 0x80 to an internal 8-bit register
 * located at Address 0xE7E3.
 *
 * 8.
 * Read back all data memory RAM registers to ensure that
 * they initialized with the desired values. If one or more
 * registers did not initialize correctly, disable the protection by
 * writing 0xAD to an internal 8-bit register at Address 0xE7FE,
 * followed by a write of 0x00 to an internal 8-bit register
 * located at Address 0xE7E3. Reinitialize the registers,and
 * write the last register in the queue three times. Enable the write
 * protection by writing 0xAD to an internal 8-bit register
 * located at Address 0xE7FE, followed by a write of 0x80 to
 * an internal 8-bit register located at Address 0xE7E3.
 *
 * 9.
 * Start the DSP by setting Run = 1.
 *
 * 10.
 * Read the energy registers xWATTHR, xVAHR, xFWATTHR,
 * and xFVARHR to erase their content and start energy
 * accumulation from a known state.
 *
 * 11.
 * Enable the CF1, CF2, and CF3 frequency converter outputs
 * by clearing bits 9, 10, and 11 (CF1DIS, CF2DIS, and
 * CF3DIS) to 0 in the CFMODE register. For a quick setup of the
 * ADE7880 harmonic calculations, see the Recommended Approach
 * to Managing Harmonic Calculations section.
 *
 * (1) One may first follow the procedure to power up the ADE7880 and turn on communications protocol
 */

/** @brief Calibration macros
 * These macros are only modified whenever a new calibration is performed and the values have
 * changed. A calibration should be performed whenever the EM is replaced for a new unit
 * acording to its respective datasheet.
 */

/** for mean absolute value (mav) pag 41*/
#define VLSB_CONST	  				211184.71337579617834394904458599
#define ILSB_CONST	  				353022.88732394
#define WHLSB_CONST	  				(67.28)*2.275
#define WATTLSB_CONST 				8505.0
/// enable disable Apparent Power Calculation Using VNOM register value
#define _VNOMAEN	  				0


/***********************************************************************************************************************
* Definitions for threshold registers
***********************************************************************************************************************/
//!Threshold registers
#define WTHR_DEFAULT         		0x03 		//>!Threshold used in phase total fundamental active power data path.
#define VARTHR_DEFAULT				0x03 		//Threshold used in phase total/ fundamental reactive power data path.
#define VATHR_DEFAULT				0x03 		//Threshold used in phase apparent power data path.
#define VLEVEL_DEFAULT				0x38000	    	//use Equation 26, Equation 37, Equation 44, Equation 22, and Equation 42
										//in the datasheet to determine this values
/// @}


/**
 *  \defgroup ade_driver_harmonics	ADE Harmonics Calculation and Configuration
 *  @{
 *  \par Harmonics Calculation extract from DataSheet p.57).
 *
 *  band-pass up to 2.8KHz with no attenuation (Bandwidth (-3dB) 3.3KHz)
 *  Maximum Harmonic index Nh = 2800/f(50Hz.) = 56
 *  Maximun harmonic indexes that can be read is 3 HX, HY and HZ (i.e. HX=3rd harmonic, HY=5th and HZ=7th).
 *  Table of output registers for Harmonic calculations in p.58 of DataSheet.
 *   Two main working modes, Phases A, B and C can be monitored or neutral line current.
 *  When a phase is monitored, fundamental + 3 selected harmonics indexes are analysed simultaneously.
 *   When neutral is monitored and the sum of the phase currents, only related Harmonics RMS registers are
 *   updated (pag. 63)
 *   When Neutral line currents are of the interest:
 *   When analysing neutral line, neutral current can be simultaneously analysed with the sum of the three
 *   phase currents.
 *   The update rate of the registers can be controlled. For that, one of the phases has to be connected
 *   and monitored to serve as a time base line.
 *   When reading neutral currents, In 3-phase systems, the neutral current is equal to the algebraic sum
 *   of the phase currents:
 *  	IN(t) = IA(t) + IB(t) + IC(t)
 *   If there is a mismatch between these two quantities, then a tamper situation may have occurred in the
 *   system. This sum can be read by ISUM register. The ADE7880 computes the difference between the absolute
 *   values of ISUM and the neutral current from the INWV register, take its absolute value and compare it
 *   against the ISUMLVL threshold. (D-S p.36)
 *

 *
 * \par Recommended approach for managing Harmonic Calculations (p.64)
 *
 * The recommended approach to managing the ADER7880 harmonic calculations is the following:
 *
 * 1.
 * Set up Bit 2 (CF2DIS) in the CONFIG register. Set CF2DIS bit to 1 to use the CF2/HREADY pin to signal
 * when the harmonic calculations have settled and are updated. The high to low transition of HREADY
 * signal indicates when to read the harmonic registers. Use the burst reading mode to read the harmonic
 * registers as it is the most efficient way to read them.
 *
 * This is done in the following way (1):
 *   		-Set bit 2 of 'CONFIG' register, address 0xE618, as 1 so CONFIG = 0x0006 (CONFIG register is 16bits)
 *   		-Write the register at least twice (in case you write the register individually, if sequentially,
 *  		 write twice only the last).
 *  		-Read the last written register to check that it was a successful write.
 *
 * 2.
 * Choose the harmonics to be monitored by setting HX, HY and HZ:
 *  		-write 'HX' 0xEA08 (8bits) with the desired harmonic index (i.e. 1 for Fundamental)
 *  		-write 'HY' 0xEA09 (8bits) as i.e. 5 to measure the 5th harmonic
 *  		-write 'HZ' 0xEA0A (8bits) as 7, 7th harmonic
 *
 * 3.
 * Select all the HCONFIG register bits.
 *
 * 4.
 * Write 'HCONFIG' 0xE900 (16bit), i.e. with update rate of 1ms (HCONFIG = 0x0047)
 *
 * 5.
 * Initialize the gain registers used in the calculations. Leave the offset registers to 0.
 *
 * 6.
 * Write 'GAIN' 0xE60F 16bits register as 0.
 *
 * 7.
 * If Rogowski coils are used, enable the digital integrators in the phase
 * and neutral currents: Bit 0 (INTEN) set to 1 in the CONFIG register.
 * Initialize the DICOEFF register to 0xFF8000 before setting the INTEN bit in the CONFIG register.
 *
 * 8.
 * Start the DSP by setting Run = 1.
 *
 * 9.
 * Read the registers in which the harmonic information is stored using the burst or regular reading
 * mode at high to low transitions of CF2/HREADY pin.
 *
 * 10.
 * CF2/HREADY pin can be programmed as an interrupt (read DataSheet Configuring Harmonic Calculations
 * Update rate p.63-64)and its value is stored and can be read in 'STATUS0' register 0xE502 32bits
 *
 * 11.
 * For neutral line monitoring read to 'HXIRMS' 0xE889 (32bits), 'HYIRMS' 0xE891 (32bits) and 'HZIRMS'
 * 0xE899 (32bits) (before proceeding with a reading one must follow the procedure to initialize and
 * turn on the ADE7880 DSP)
 *
 * (1) One may first follow the procedure to power up the ADE7880 and turn on communications protocol
 *
 *  \par Configuration of working mode: Energy Meter or Harmonics Meter
 *
 *  The first step that should be taken is to configure the desired working mode of the EM chip.
 *  By default the EM will work as an ENERGY METER.
 *  Opening the file "definitions.h" one can select to operate as a Harmonics meter by uncommenting
 *  the following line of the named file:
 *  \code
 *  #define		HARMONICS_MODE		1		// For measuring Harmonics registers activation
 *  \endcode
 *  the system will be configured as a Neutral Line HARMONICS Meter
 *
 *  \par Harmonics Configuration Values
 *
 *  Harmonic indexes:
 *  In the same file, indexes for harmonics can be found as follows:
 *  \code
 *  //harmonics indexes' macros
 *  #define HX_VAL				0x01
 *  #define	HY_VAL				0x05
 *  #define HZ_VAL				0x07
 *  \endcode
 *  Selecting the desired harmonics at each index is done here. One should pay attention that
 *  EM Absolute Maximum Number of Harmonics is 63 but the maximum number of harmonic is
 *  (2800 / Fundamental line frequency). This is due to its properties in which its Total Active
 *  Energy Measurement Bandwidth (-3 dB) is 3.3KHz. Read the EM data-sheet for more information.
 *
 *  Harmonics macros:
 *  \code
 *  //! Harmonics macros
 *  #define SELECTED_LINE 			NEUTRAL_LINE	(1)
 *  #define NUMBER_OF_SAMPLES		1				(2)
 *  #define CONFIG_CF2DIS_BIT		0				(3)
 *  #define HCONFIG_HRCFG_BIT		1				(4)
 *  #define HCONFIG_HSTIME_BITS		0b00			(5)
 *  #define HCONFIG_HRATE_BITS		0b000			(6)
 *  #define HCONFIG_ACTPHSEL_BITS	0b00			(7)
 *  \endcode
 *  (1) Select phase or neutral line to monitor. Options: NEUTRAL_LINE, PHASE_A, PHASE_B or PHASE_C.
 *
 *  (2) Number of samples per reading: From one single reading to as many as desired and the average
 *  	of the total readings is calculated in the following way:
 *  	(sum up all the readings) / (number of readings)
 *
 *  (3) Set CF2DIS bit in CONFIG to 1 to use CF2/HREADY pin to wait for a new calculation
 *  	value is completed and its register has settle for HRCFG & HSTIME. (*)
 *
 *  (4) Set HRCFG bit in HCONFIG (*): 0(Default) = waits HSTIME to settle and triggers HREADY
 * 									: 1 = Triggers HREADY immediately
 *
 *  (5) Set HSTIME bits in HCONFIG (*)	: (Default) 01 = 750ms of settle time
 * 									: 500ms (00)
 * 									: 1 sec (10)
 * 									: 1250 ms (11).
 *
 *  (6) Set HRATE bits in HCONFIG (*):(Default) 000 = the update rate of the harmonic registers. 000 = 8kHz
 *
 *  (7) Set ACTPHSEL bits in HCONFIG (*): (Default = 00 phase A) To select the phase voltage used as
 * 			time base for harmonic calculations. The selected phase has to be connected to its input pins.
 *
 *  (*) Read EM data-sheet for more information.
 *
 *  Integrator:
 *  In case of using a di/dt current sensor, the EM has its own integrator which can be activated by the next macro
 *  \code
 *  // di/dt current sensor and digital integrator
 *  // #define INTEGRATOR						(8)
 *  #ifdef	INTEGRATOR
 *  #define PI_INTEGRATOR			DISABLE		(9)
 *  #define NI_INTEGRATOR			ENABLE		(10)
 *  #endif
 *  \endcode
 *
 *  (8) #ifdef	INTEGRATOR enables (uncomment) or disables (comment) on-chip digital integrator for neutral
 *  current path as desired, whenever a di/dt curent sensor is being used
 *  When INTEGRATOR is enabled:
 *
 *  (9) Enable or disable on-chip digital integrator for Phase Current paths
 *
 *  (10) Enable or disable on-chip digital integrator for Neutral Current path
 *
 */

///harmonic index X macro
#define HX_VAL						3
///harmonic index Y macro
#define	HY_VAL						5
///harmonic index Z macro
#define HZ_VAL						7


///harmonics macros for a default configuration

/// Select phase or neutral line to monitor
#define SELECTED_LINE 				NEUTRAL_LINE
/// Set CF2DIS bit in CONFIG to 1 to use HREADY pin
#define CONFIG_CF2DIS_BIT			1
/// Set HRCFG bit in HCONFIG : 0(Default) = waits HSTIME to settle and triggers HREADY : 1 = Triggers HREADY immediately
#define HCONFIG_HRCFG_BIT			0
/// Set HSTIME bits in HCONFIG 	: (Default) 01 = 750ms of settle time : 500ms (00) : 1 sec (10) and 1250 ms (11).
#define HCONFIG_HSTIME_BITS			1
/// Set HRATE bits in HCONFIG 	:(Default) 000 = These bits manage the update rate of the harmonic registers. 000 = 8kHz
#define HCONFIG_HRATE_BITS			0
/// Set ACTPHSEL bits in HCONFIG : (Default = 00 phase A) These bits select the phase voltage used as time base for harmonic calculations.
#define HCONFIG_ACTPHSEL_BITS		0
/// harmonics special 3.21 registers output (2^21) correction factor
#define REG_321_CORRECTION	 			2097152.0

/// Enable Internal Integrator to use with di/dt current sensor
#define INTEGRATOR					DISABLE
// Enable (uncomment) or disable (comment) on-chip digital integrator for neutral current path
//if	INTEGRATOR defined ENABLE the selected phase or neutral line integrator
#if INTEGRATOR
	/// Enable or disable on-chip digital integrator for Phase Current paths
	#define PI_INTEGRATOR				DISABLE
	/// Enable or disable on-chip digital integrator for Neutral Current path
	#define NI_INTEGRATOR				ENABLE
#endif
/// @}


/**
 *  \defgroup ade_driver_endianness	ADE7880 Network Communications Endianness
 *  @{
 */
#ifndef 	LITTLE_ENDIAN
#define 	LITTLE_ENDIAN				0
#endif
#ifndef		BIG_ENDIAN
#define 	BIG_ENDIAN					1
#endif
/// Define the system's endianness according to the system
#ifndef 	BYTE_ORDER
#define 	BYTE_ORDER					LITTLE_ENDIAN
#endif

/// Convert 16-bit quantity from host byte order to network byte order.
/// This macro is primarily used for converting constants from host
/// byte order to network byte order. For converting variables to
/// network byte order, use the htons() function instead.
#ifndef HTONS
// BYTE_ORDER == BIG_ENDIAN
#   if BYTE_ORDER == BIG_ENDIAN
#      define HTONS(n) (n)
// BYTE_ORDER == LITTLE_ENDIAN
#   else
#      define HTONS(n) (uint16_t)((((uint16_t) (n) & 0xff00) >> 8) \
								| (((uint16_t) (n) & 0x00ff) << 8))
#   endif
#else
#error "HTONS already defined!"
#endif /* HTONS */


/// Convert 16-bit quantity from host byte order to network byte order.
/// This function is primarily used for converting variables from host
/// byte order to network byte order. For converting constants to
/// network byte order, use the HTONS() macro instead.
#ifndef htons
uint16_t htons(uint16_t val);
#endif /* htons */
#ifndef ntohs
#define ntohs htons
#endif


/// Convert 32-bit quantity from host byte order to network byte order.
/// This macro is primarily used for converting constants from host
/// byte order to network byte order. For converting variables to
/// network byte order, use the htons() function instead.
#ifndef HTONL
/* BYTE_ORDER == BIG_ENDIAN */
#   if BYTE_ORDER == BIG_ENDIAN
#      define HTONL(n) (n)
/* BYTE_ORDER == LITTLE_ENDIAN */
#   else
#      define HTONL(n) (uint32_t)((((uint32_t) (n) & 0xff000000) >> 24) \
								| (((uint32_t) (n) & 0x00ff0000) >> 8)  \
								| (((uint32_t) (n) & 0x0000ff00) << 8)  \
								| (((uint32_t) (n) & 0x000000ff) << 24))
#   endif
#else
#error "HTONL already defined!"
#endif /* HTONL */


/// Convert 32-bit quantity from host byte order to network byte order.
/// This function is primarily used for converting variables from host
/// byte order to network byte order. For converting constants to
/// network byte order, use the HTONS() macro instead.
#ifndef htonl
uint32_t htonl(uint32_t val);
#endif /* htonl */
#ifndef ntohl
#define ntohl htonl
#endif

/**@}*/


/**
 * \brief power_mode
 * Enumeration for the different selectable Power Mode options
 */
typedef enum{
	PSM0,//!< PSM0
	PSM1,//!< PSM1
	PSM2,//!< PSM2
	PSM3 //!< PSM3
}power_mode_et;



/**
 * \brief Communications protocol mode
 * Enumeration for the different selectable communications mode options
 */
typedef enum{
	SPI,
	I2C,
	HSDC
}comm_mode_et;


/** \brief Error list
 * \defgroup errors
 * @{
 * Most of the driver functions have a return, this will always be the error, a 0 means no error
 */
typedef enum{
	ADE_NO_ERROR = 0,					//!< No error
	ADE_ERROR_REG_LENGTH ,				//!< The given register length is wrong
	ADE_ERROR_REG_WRITE,				//!< Error when writing to a register
	ADE_ERROR_REG_READ,					//!< Error when reading a register
	ADE_ERROR_SPI_LOCK_NOT_GRANTED,		//!< SPI channel could not be locked
	ADE_ERROR_COMM_MODE,				//!< Given communications mode is not in the list \ref comm_mode_et
	ADE_ERROR_POWER_MODE,				//!< Given power mode is not in the list \ref power_mode_et
	ADE_ERROR_WRONG_ARGUMENT_NUM,		//!< When calling ADE_command_handler() wrong number of arguments
	ADE_ERROR_WRONG_CMD_ARG,			//!< When calling ADE_command_handler() wrong command argument
	ADE_ERROR_WRONG_MEAS_ARG,			//!< When calling ADE_measure() wrong command argument
	ADE_ERROR_LAST_OP_WR,				//!< When transmission check is enabled, error in last operation, Op not a write op
	ADE_ERROR_LAST_TARGET_REG,			//!< When transmission check is enabled, error in last write operation, last target register does not match with ADE7880 records
	ADE_ERROR_LAST_REG_VALUE,			//!< When transmission check is enabled, error in last write operation, last register's content obtained does not match with ADE7880 records
	ADE_ERROR_RAM_PROTECTION_NOT_DISABLED,	//!< RAM protection could not be dissabled
	ADE_ERROR_CONVERSION_WAIT_TIME_EXCEED	//!< in wait_new_conversion(), too long waitng time
}error_list_et;

/**@}*/

#endif		// __ADE7880_CONFIGURATION_H

/// @}
