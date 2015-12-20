/// \file pi_ade7880_drv.h
/// \brief \e Purpose: \n Middleware driver for RasPi SPI with ADE7880 header file
/***********************************************************************************************************************
 * DISCLAIMER
 *
 * Copyright (C) 2014
 ***********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name	   : pi_ade7880_drv.h
 * Version      : 1.0
 * H/W Platform : ADE7880
 * Description  : header file for ADE7880 driver.
 ***********************************************************************************************************************/
/***********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 * 		  						This file is a serves to hook the ADE7880 driver methods to the RX63N
 *         : 10.09.2014 1.00     First Release
 *         : 20.09.2014 1.10		Added definitions for the pin ports to set the power mode
 ***********************************************************************************************************************/

#ifndef PI_ADE7880_DRV_HEADER_FILE
#define PI_ADE7880_DRV_HEADER_FILE

/***********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/

/***************************************************
 * TODO: DONE!  check all #include linkage !!!!
 *****************************************************/

/***********************************************************************************************************************
 General Definitions
 **********************************************************************************************************************/
//#define	TYPE(_cc)  			(((_cc >= '1' )) ? ((uint8_t)) : ((uint16_t)))
//#define DSP_START	  		0xFF

#define REG_LENGTH(_x)          (sizeof(_x))

/***********************************************************************************************************************//**
 * \defgroup pi_ade_drv PI ADE7880 Middware driver
 * \ingroup ade_driver
 * @{
 *
 * \defgroup pi_ade_pin  I/O management
 * \ingroup pi_ade_drv
 * @{
 * \brief ADE7880 General Configuration file ade7880_configuration.h
 *
 *  Definitions for the different pins acting as GPIO
 *  The PIN addresses are set according to the hardware configuration. Refer to the ADE7880 I/O with the bcm2835 macros
 **********************************************************************************************************************/
#define PIN_PM0 				RPI_GPIO_P1_11					//!< ADE pin PM0 --> RASPI_PIN1-11 (BCM GPIO pin number 17 V1 & V2)
#define PIN_PM1 				RPI_GPIO_P1_12					//!< ADE pin PM1 --> RASPI_PIN1-12 (BCM GPIO pin number 18 V1 & V2)
#define PIN_RESET				RPI_GPIO_P1_15					//!< ADE pin RESET --> RASPI_PIN1-15 (BCM GPIO pin number 22 V1 & V2)
#define PIN_IRQ0				RPI_GPIO_P1_16					//!< ADE pin /IRQ0 --> RASPI_PIN1-16 (BCM GPIO pin number 22 V1 & V2)
#define PIN_IRQ1	    		RPI_GPIO_P1_18					//!< ADE pin /IRQ1 --> RASPI_PIN1-18 (BCM GPIO pin number 24 V1 & V2)
#define PIN_CS					RPI_GPIO_P1_24					//!< ADE pin CS uses RASPI CS0
//#define PIN_HREADY 		PORT5.PODR.BIT.B5				// CF2/HREADY --> RENESAS PMOD_PIN7 (P55)
//#define PIN_HREADY_PDR	PORT5.PDR.BIT.B5				// CF2/HREADY PORT DIRECTION

#define INPUT_PIN				BCM2835_GPIO_FSEL_INPT				//!< Defines the pin direction as input
#define OUTPUT_PIN				BCM2835_GPIO_FSEL_OUTP				//!< Defines the pin direction as input
#define PIN_PDR(_pin, _dir)		(bcm2835_gpio_fsel(_pin,  _dir))	//!< SET PIN PORT DIRECTION IN RASPI I/O call as PIN_PDR(PIN_RESET, OUTPUT_PIN)#define PIN_LEVEL_HIGH(_pin) 	(bcm2835_gpio_set(_pin))			//!< SET PIN LEVEL AS PIN HIGH OR 1#define PIN_LEVEL_LOW(_pin)		(bcm2835_gpio_clr(_pin))			//!< SET PIN LEVEL AS PIN LOW OR 0

/**@}*/



/**
* \defgroup pi_ade_measures  Data structure
* \ingroup pi_ade_drv
* @{
* @brief Structure definitions for measured data
*/
/// \brief phase_data_t
/// Gives access to the measured data Structure when PHASES are read: Holds the measurement when the ENERGY METER measures phase registers are requested
typedef struct
{
	float IRMS;
	float VRMS;
	float WH;
	float POWER;

} phase_data_t;


/// \brief neutral_data
/// Gives access to the measured data Structure when NEUTRAL line are read: Holds the measurement when the HARMONICS Output registers of neutral current are requested
typedef struct
{
	float IN_IRMS;							// Neutral current RMS value
	float INSTANT_IN;						// Instantaneous Neutral current
	// Neutral current Harmonics RMS values
	float IN_HXIRMS;
	float IN_HYIRMS;
	float IN_HZIRMS;
	// Neutral current Harmonic distortion
	float IN_HXIHD;
	float IN_HYIHD;
	float IN_HZIHD;
	// ISUM RMS values
	float ISUM_HXVRMS;
	float ISUM_HYVRMS;
	float ISUM_HZVRMS;
	// ISUM Harmonics distortion
	float ISUM_HXVHD;
	float ISUM_HYVHD;
	float ISUM_HZVHD;
} neutral_data_t;


/// \brief measured_data_t
/// measured data Structure
typedef struct
{
	phase_data_t phase_a;
	phase_data_t phase_b;
	phase_data_t phase_c;
	neutral_data_t neutral_line;
} measured_data_t;

/**@}*/

/***************************************************************************************************************//**
* \defgroup pi_ade_public  Public Functions
* \ingroup pi_ade_drv
* @{
*
* One can use the functions in this middware to call ADE7880 SPI operations. All the operations can be handled with
* call to its functions, but it is easier to use the public functions offered by the ADE7880 driver itself instead
*/

/** @brief Send callback functions to the driver
 *
 * This function must always be called before using the driver to allow the ADE7880 driver a way to the middware.
 * It keeps the portability of the driver by hiding the middware to the driver.
 * One must always send the address of  of the next functions fn(&nameOfFunction):
 * - The function that writes to the SPI bus. This function will always have to be implemented such that it receives a
 * pointer to the buffer and the number of transmission's total bytes.
 * - The function that reads from the SPI. Same parameters as before, in this case the pointer will hold the buffer with
 * the received information.
 * - The function that sets the power mode, with the power mode as parameter
 * - The function that sets the communications mode, with the mode as parameter (only SPI implemented)
 */
void PI_ADE_ADE7880_driverCallbacks(void);

/** @brief ADE power up procedure step by step
 *
 * @return 0 ADE_NO_ERROR - Operation completed.\n
 */
int8_t PI_ADE_power_up_procedure(void);

/** @brief Initializes the hardware SPI channel and power mode pin outputs
 *
 * @param bitOrder MSB or LSB first \ref bcm2835SPIBitOrder
 * @param dataMode check devices' datasheet to choose the appropriate CHPA and CPOL \ref bcm2835SPIMode
 * @param clockDivider Selects the transmission speed \ref bcm2835SPIClockDivider
 * @param polarity Selects the CS polarity when enabled, Usually is low. \ref HIGH or \ref LOW
 * @param chipSelect Selects the active channel CS0, CS1 or CS2 after finishing the configuration \ref bcm2835SPIChipSelect
 */
void PI_ADE_InitializeHardware_SPI(uint8_t bitOrder, uint8_t dataMode,
		uint16_t clockDivider, uint8_t polarity, uint8_t chipSelect);

/** @brief Produces an active low signal to the ADE7880 reset pin
 *
 * @return always 0
 */
int8_t PI_ADE_HW_reset(void);

/** @brief Sets up extra pins as GPIO for other purposes, i,e, Power Mode */
void PI_ADE_GPIO_pin_initialize(void);

/** @brief Sets the RX63N defined pins PM0 and PM1 of ADE7880 to the required starting power mode, usually PM0
 *
 * @param mode Selected power mode
 * @return 	No error or  \n
 * 			Wrong Power Mode selected
 */
int8_t PI_ADE_Power_mode(uint8_t mode);

/** @brief Sets the ADE7880 communication protocol to the selected mode. SPI is set but not locked.
 *
 * Set mode to SPI by toggling the CS pin 3 times. This does not lock the channel.
 * If channel is unlocked, CS has to be toggled before every transmission
 * @param mode Communication Protocol. *Only SPI is implemented so far
 * @return If error, error code
 */
int8_t PI_ADE_Comm_initialize(uint8_t mode, uint32_t pid);

/** @brief Lock SPI as communications protocol
 *
 * After toggling CS x3 times any write to CONFIG2 will lock the SPI port until
 * device restart or hardware reset
 * @return If error, error code
 */
int8_t PI_ADE_SPI_commLock(uint32_t pid);

/** @brief sends data out of the RasPi SPI. This also takes care of locking the SPI peripheral.
 *
 * Operation:
 * \arg 1. Lock the access to the SPI to the calling application. \n Call \ref PI_SPI_Lock (APP_PID) and check its return
 * \arg 2. If lock is attained select the CS channel. \n Use \ref PI_SPI_Select (REQUIRED_SPI_CHANNEL, APP_PID);
 * \arg 3. Proceed with the SPI communication by calling the provided function \ref PI_SPI_Write()
 * \arg 4. At last, proceed to unlock the SPI, \ref PI_SPI_Unlock (APP_PID)\n
 * @param data  Pointer to the tx data buffer.
 * @param usBytes The total length of the transmission
 * @return Error if any
 */
int8_t PI_ADE_SPI_Write(uint8_t *data, uint8_t usBytes, uint32_t pid);

/** @brief reads data from the ADE7880. This also takes care of locking the
 *
 * Operates as \ref PI_ADE_SPI_commLock() but calling \ref PI_SPI_Read() instead
 * @param data  Pointer to the tx data buffer.
 * @param usBytes The total length of the transmission
 * @return error if any
 */
int8_t PI_ADE_SPI_Read(uint8_t *data, uint8_t usBytes, uint32_t pid);

/** @brief sends data out and/or receives from the SPI. This also takes care of locking
 *
 * This function is called by \ref ADE_SPI_TransferNB() where the returned data will be
 * stored in the same pointer location as the source pointer by the SPI peripheral.
 *
 * Operates as \ref PI_ADE_SPI_TransferNB() but uses the pointer given as parameter to call PI_ADE_SPI_TransferNB
 * using the same pointer twice, one for tx and another for rv.
 * @param data  Pointer to the tx data buffer.
 * @param usBytes The total length of the transmission
 * @return error if any
 */
int8_t PI_ADE_SPI_TransferN(uint8_t *data, uint32_t usBytes, uint32_t pid);

/** @brief sends data out and/or receives from the SPI. This also takes care of locking
 *
 * This function is called by \ref ADE_SPI_TransferNB() where the returned data will be
 * stored in the same pointer location as the source pointer by the SPI peripheral.
 *
 * Operates as \ref PI_ADE_SPI_TransferNB() but uses the pointer given as parameter to call PI_ADE_SPI_TransferNB
 * using the same pointer twice, one for tx and another for rv.
 * @param pScr Pointer to source outgoing tx data buffer.
 * @param pDest Pointer to destination of the incoming tx data buffer.
 * @param usBytes The total length of the transmission in bytes
 * @return error if any
 */
int8_t PI_ADE_SPI_TransferNB(uint8_t *pScr, uint8_t *pDest, uint32_t usBytes, uint32_t pid);

/** @} */
/** @} */

//bool callback_IRQ0(void);
//bool callback_IRQ1(void);
//bool callback_HREADY(void);
uint16_t htons(uint16_t val);
uint32_t htonl(uint32_t val);


#endif /* PI_ADE7880_DRV_HEADER_FILE */

