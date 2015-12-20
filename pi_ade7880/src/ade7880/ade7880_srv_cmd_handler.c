/// \file ade7880_srv_cmd_handler.c
/// \brief Provides the two most important public functions to configure and measure using ADE7880

/******************************************************************************
* File Name     : ade7880_srv_cmd_handler.c
* Version       : 2.20
* Device(s)     : RX63N
* Tool-Chain    : Tested with GCC under Linux x86/64 and RasPi and Renesas RX Standard Toolchain 2.02.00
* OS            : None
* H/W Platform  : ADE7880
* Description   :
*******************************************************************************/
/*******************************************************************************
* History : DD.MM.YYYY     	Version     Description
*         : 21.09.2014     	1.00        First release
*         : 26.09.2014		2.00		Added command handdler
*         : 03.10.2014		2.10		Added: 	RAM protection to command handler
*         										cmd_rd_REG functions for simple register reading
*		  : 07.10.2014		2.20		Added:	COMMON_MEASUREMENTS_INIT to command handler
*		  										write to register from command handler
*		  : 03.02.2015		2.21		Includes with full path for GCC
*
*******************************************************************************/

/*******************************************************************************
Includes   <System Includes> , "Project Includes"
*******************************************************************************/

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>


#include "ade7880_configuration.h"
#include "ade7880_registers.h"
#include "ade7880_spi_protocol.h"
#include "ade7880_srv_cmd_handler.h"
#include "../../pi_ade7880_config.h"
#include "preamble.h"



#ifdef DEBUG_ADE
extern uint8_t debug_print;
#endif

/*******************************************************************************
Local function prototypes
*******************************************************************************/
error_list_et 			cmd_ADE7880_SET_SPI_COMM	(uint32_t pid);
error_list_et 			cmd_ADE7880_SPI_COMM_LOCK	(uint32_t pid);
error_list_et 			cmd_POWER_MODE				(uint8_t mode);
error_list_et 			cmd_DSP_RUN					(uint8_t, uint32_t pid);
error_list_et 			cmd_GAIN_INIT				(uint8_t pga1, uint8_t pga2, uint8_t pga3, uint32_t pid);
error_list_et			cmd_QUICK_SETUP_AS_ENERGY_METER(uint32_t pid);
error_list_et 			cmd_HARMONICS_DEF_INIT		(uint8_t phase, uint32_t pid);
error_list_et 			cmd_RAM_PROTECTION			(uint8_t cmd, uint32_t pid);
error_list_et	 		cmd_rd_REG					(uint16_t REG_addr, uint8_t REG_len, int32_t *pRead, uint32_t pid);
error_list_et	 		cmd_rd_32B_REG				(uint16_t REG_addr, int32_t *pRead, uint32_t pid);
error_list_et	 		cmd_rd_16B_REG				(uint16_t REG_addr, int32_t *pRead, uint32_t pid);
error_list_et 			cmd_rd_8B_REG				(uint16_t REG_addr, int32_t *pRead, uint32_t pid);
error_list_et			cmd_wr_32B_REG				(uint16_t REG_addr, uint32_t REG_val, uint32_t pid);
error_list_et 			cmd_wr_16B_REG				(uint16_t REG_addr, uint16_t REG_val, uint32_t pid);
error_list_et 			cmd_wr_8B_REG				(uint16_t REG_addr, uint8_t REG_val, uint32_t pid);
error_list_et 			meas_PHASE_VRMS 			(uint8_t channel, uint16_t samples, float *result, uint32_t pid);
error_list_et 			meas_PHASE_IRMS 			(uint8_t channel, uint16_t samples, float *result, uint32_t pid);
error_list_et 			meas_PHASE_ACTIVE_WH 		(uint8_t channel, float *result, uint32_t pid);
error_list_et 			meas_TOTAL_ACTIVE_WH 		(uint8_t channel, float *result, uint32_t pid);
error_list_et 			meas_PHASE_ACTIVE_POWER 	(uint8_t channel, float *result, uint32_t pid);
error_list_et 			meas_IHARMONIC_RMS 			(uint8_t channel, float *result, uint32_t pid);
error_list_et 			meas_IHARMONIC_HD			(uint8_t channel, uint16_t samples, float *result, uint32_t pid);
error_list_et 			meas_VHARMONIC_RMS 			(uint8_t channel, float *result, uint32_t pid);
error_list_et 			meas_VHARMONIC_HD			(uint8_t channel, uint16_t samples, float *result, uint32_t pid);
error_list_et 			meas_REGISTER 				(uint8_t channel, uint16_t samples, float *result, uint32_t pid);
error_list_et 			wait_new_conversion			(uint32_t pid);
#if INTEGRATOR
error_list_et 			cmd_INTEGRATOR_DEF_INIT 	(uint32_t pid);
#endif
int8_t 			(*ADE_COMM_INITIALIZE)		(uint8_t mode, uint32_t pid) = 0;
int8_t 			(*ADE_POWER_MODE)			(uint8_t mode) = 0;
int8_t 			(*ADE_SPI_COMMLOCK)			(uint32_t pid) = 0;

void ADE_COMM_INIT_callback_set(int8_t(*func)(uint8_t mode, uint32_t pid))
{
	ADE_COMM_INITIALIZE = func;
}

void ADE_SPI_COMMLOCK_callback_set(int8_t(*func)(uint32_t pid))
{
	ADE_SPI_COMMLOCK = func;
}

void ADE_POWER_MODE_callback_set(int8_t(*func)(uint8_t mode))
{
	ADE_POWER_MODE = func;
}

/***********************************************************************************************************************
* Function Name: configure_cmd
* Description  : runs the selected command
* Arguments    :
* Return Value : err
*/
error_list_et ADE_command_handler(uint32_t pid, uint32_t cmd, uint8_t arg, ...) {
	/******************//**
	 * TODO:  	Add return to all cases to check errors
	 * 			Check the given arguments in all cases
	 * 			Another argument for all cases should be chip address
	 */
	error_list_et err 	= ADE_NO_ERROR;
	va_list va;
	va_start(va, arg);

	switch (cmd) {

		/***********************************
		* Select SPI protocol (This does not lock it)
		*/
		case ADE7880_SET_SPI_COMM:
		{
			err = cmd_ADE7880_SET_SPI_COMM(pid);
		}break;
		/***********************************
		* Select SPI protocol and Lock it
		*/
		case ADE7880_SPI_COMM_LOCK:

		{
			err = cmd_ADE7880_SPI_COMM_LOCK(pid);
		}break;

		case DSP_RUN:
		{
			if (arg != 1) 	{ return ADE_ERROR_WRONG_ARGUMENT_NUM; }
			err = cmd_DSP_RUN(TO_INT8_T( TO_INT8_T( va_arg(va, uint32_t))), pid );
		}break;

		/***********************************
		 * Set a Software reset
		 */
		case ADE7880_RESET:
		{
		}
		break;
		/***********************************
		 * Set the DEFAULT GAINS
		 */
		case GAIN_INIT:
		{
			if (arg == DEFAULT_ARGS) {
				err = cmd_GAIN_INIT(PHASE_CURRENTS_GAIN, NEUTRAL_CURRENTS_GAIN, PHASE_VOLTAGES_GAIN, pid);
			}else if (arg == 3){
				err = cmd_GAIN_INIT( TO_INT8_T(va_arg(va, int32_t)), TO_INT8_T(va_arg(va, int32_t)), TO_INT8_T(va_arg(va, int32_t)), pid );
			}else
				err = ADE_ERROR_WRONG_ARGUMENT_NUM;
		}
		break;

		/***********************************
		 * Configure the working Power Mode
		 */
		case POWER_MODE:
		{
			if (arg != 1) 	{	return ADE_ERROR_WRONG_ARGUMENT_NUM; }

			err = cmd_POWER_MODE(va_arg(va, int32_t));
		}
		break;

		/***********************************
		 * Configure VLEVEL
		 */
		case VLEVEL_CMD:
		{
			if (arg != 1) 	{	return ADE_ERROR_WRONG_ARGUMENT_NUM; }

			err = cmd_wr_32B_REG(VLEVEL, va_arg(va, uint32_t), pid);
		}
		break;

		/*********************************
		 * Configure COMPMODE
		 */
		case COMPMODE_CMD:
		{
			if (arg != 1)	{ return ADE_ERROR_WRONG_ARGUMENT_NUM; }

			err = cmd_wr_16B_REG( COMPMODE, TO_INT16_T( va_arg(va, int32_t)), pid );
		}
		break;

		/*********************************
		 * Configure VNOM_CMD
		 */
		case VNOM_CMD:
		{
			if (arg != 1)	{ return ADE_ERROR_WRONG_ARGUMENT_NUM; }

			err = cmd_wr_32B_REG(VNOM, va_arg(va, uint32_t), pid);
		}
		break;

		/*********************************
		 * Configure THRESHOLD LEVELS
		 */
		case THRESHOLD:
		{
			if (arg == DEFAULT_ARGS) {
				err |= cmd_wr_8B_REG(WTHR, WTHR_DEFAULT, pid);
				err |= cmd_wr_8B_REG(VARTHR, VARTHR_DEFAULT, pid);
				err |= cmd_wr_8B_REG(VATHR, VATHR_DEFAULT, pid);
			}else if(arg == 3){
				err |= cmd_wr_8B_REG(WTHR, va_arg(va, int), pid);
				err |= cmd_wr_8B_REG(VARTHR, va_arg(va, int), pid);
				err |= cmd_wr_8B_REG(VATHR, va_arg(va, int), pid);
			}else{
				err = ADE_ERROR_WRONG_ARGUMENT_NUM;
			}
		}
		break;
	
		/*********************************
		 * Enables/Disable data memory protection
		 */
		case RAM_PROTECTION:
		{
			if (arg != 1) 	{ return ADE_ERROR_WRONG_ARGUMENT_NUM; }

			err = cmd_RAM_PROTECTION(va_arg(va, int), pid);
		}
		break;

		/*********************************
		 * Follow recommended approach for Measuring Currents and Volatges
		 */
		case QUICK_SETUP_AS_ENERGY_METER:
		{
			err = cmd_QUICK_SETUP_AS_ENERGY_METER(pid);
		}
		break;

		/*********************************
		 * Follow recommended approach for managing harmonics calculations over the neutral
		 */
		case HARMONICS_INIT:
		{
			if (arg != 1)  	{ return ADE_ERROR_WRONG_ARGUMENT_NUM; }
			err = cmd_HARMONICS_DEF_INIT(va_arg(va, int), pid);
		}
		break;

		/*********************************
		 * INTEGRATOR default configuration check configuration.h
		 */
	#if INTEGRATOR
		case INTEGRATOR_INIT:
		{
			err = cmd_INTEGRATOR_DEF_INIT();
		}
		break;
	#endif
		/*********************************
		 * WRITE_REG default command for writing to any register
		 *  Arguments -> 1.- register address. 2.- register value. 3.- register size in bytes)
		 */
		case WRITE_REGISTER:
		{
			uint16_t 	REG_address;
			uint32_t	REG_value;
			uint8_t		REG_size;

			if (arg != 3)  	{ return ADE_ERROR_WRONG_ARGUMENT_NUM; }

			REG_address		= va_arg(va, int32_t);
			REG_value		= va_arg(va, int32_t);
			REG_size		= va_arg(va, int32_t);

			switch(REG_size){
				case 1:
					err = cmd_wr_8B_REG(REG_address, REG_value, pid);
				break;
				case 2:
					err = cmd_wr_16B_REG(REG_address, REG_value, pid);
				break;
				case 4:
					err = cmd_wr_32B_REG(REG_address, REG_value, pid);
				break;
				default:
					err = ADE_ERROR_REG_LENGTH;
				break;

			}
		}
		break;

		/*********************************
		 * ERROR if any of the previous conditions is NOT met
		 */
		default: {
			err = ADE_ERROR_WRONG_CMD_ARG;
		}
		break;
	}

	va_end(va);

	return err;
} /* End of config_cmd */

/***********************************************************************************************************************
* Function Name: measure
* Description  : measure commands
* Arguments    : cmd-
* Return Value : err
*/

error_list_et ADE_measure(uint32_t pid, uint8_t cmd, uint8_t phase, uint16_t samples, float *result) {

	error_list_et err = ADE_NO_ERROR;

	switch (cmd) {
		case PHASE_VRMS:
		{
			err =	meas_PHASE_VRMS(phase, samples, result, pid);
		} break;

		case PHASE_IRMS:
		{
			err =	meas_PHASE_IRMS(phase, samples, result, pid);
		} break;

		case PHASE_ACTIVE_WH:/*considers also harmoics , trouble? then we change it to fundamental*/
		{
			err =	meas_PHASE_ACTIVE_WH(phase, result, pid);
		} break;

		case PHASE_ACTIVE_POWER:
		{
			err =	meas_PHASE_ACTIVE_POWER(phase, result, pid);
		} break;

		case IHARMONIC_RMS: /* RMS Current or RMS Volt  of a harmonic*/
		{
			err =	meas_IHARMONIC_RMS(phase, result, pid);
		} break;

		case VHARMONIC_RMS: /* RMS Current or RMS Volt  of a harmonic*/
		{
			err =	meas_VHARMONIC_RMS(phase, result, pid);
		} break;

		case IHARMONIC_HD:
		{
			err =	meas_IHARMONIC_HD(phase, samples, result, pid);
		} break;

		case VHARMONIC_HD:
		{
			err =	meas_VHARMONIC_HD(phase, samples, result, pid);
		} break;

		case REGISTER:
		{	/* To measure the content of any register */
			err =	meas_REGISTER(phase, samples, result, pid);		//	There is no error detection therefore the given register (channel) should be right
		} break;

		default: {
			err = ADE_ERROR_WRONG_MEAS_ARG;
		} break;
	}

	return err;
}/* End of function ade_communication_mode() */



/***********************************************************************************************************************
* Function Name: cmd_ADE7880_SET_SPI_COMM
* Description  : Sets SPI as communications protocol but locks it not!
* Arguments    : none
* Return Value : none
*/
error_list_et cmd_ADE7880_SET_SPI_COMM(uint32_t pid)
{
	return ADE_COMM_INITIALIZE(SPI, pid);
}/* End of function cmd_ADE7880_SET_SPI_COMM() */



/***********************************************************************************************************************
 * Function Name: cmd_ADE7880_SPI_COMM_LOCK
 * Description  : Sets SPI as communications protocol and locks it
 * Arguments    : none
 * Return Value : none
 */
error_list_et cmd_ADE7880_SPI_COMM_LOCK(uint32_t pid)
{
	return ADE_SPI_COMMLOCK(pid);
}/* End of function cmd_ADE7880_SPI_COMM_LOCK() */


/***********************************************************************************************************************
* Function Name: cmd_DSP_RUN
* Description  : Turn ON the DSP
* Arguments    : none
* Return Value : none
*/
error_list_et cmd_DSP_RUN(uint8_t prt_arg, uint32_t pid)
{
	uint8_t ii;
	error_list_et err = ADE_NO_ERROR;

	for (ii = 0; ii < 3; ii++) {
		if (prt_arg == ENABLE) {
			if ( (err = ADE_SPI_write(RUN, 0x0001, REG_LENGTH(uint16_t), pid) )  !=  ADE_NO_ERROR) {
				return err;
			}
		} else {
			if ((err = ADE_SPI_write(RUN, 0x0000, REG_LENGTH(uint16_t), pid))
					!= ADE_NO_ERROR) {
				return err;
			}
		}
	}
	return err;
}/* End of function cmd_DSP_RUN() */


/***********************************************************************************************************************
* Function Name: cmd_GAIN_INIT
* Description  : Set the values for the global gain registers
* Arguments    : pga1- gain multiplier
* 				 pga2- gain multiplier
* 				 pga3- gain multiplier
* Return Value : err
*/
error_list_et cmd_GAIN_INIT(uint8_t pga1, uint8_t pga2, uint8_t pga3, uint32_t pid)
{
	GAIN_reg_u GAIN_reg;
	GAIN_reg.REG_ALL = 0;

	GAIN_reg.bits.PGA1 = (pga_et)pga1;
	GAIN_reg.bits.PGA2 = (pga_et)pga2;
	GAIN_reg.bits.PGA3 = (pga_et)pga3;

	return (ADE_SPI_write(GAIN, GAIN_reg.REG_ALL,
			REG_LENGTH(GAIN_reg.REG_ALL),
			pid));
}/* End of function cmd_GAIN_INIT() */


/***********************************************************************************************************************
* Function Name: cmd_POWER_MODE
* Description  : Set the working power mode
* Arguments    : mode- r
* Return Value : err
*/
error_list_et cmd_POWER_MODE	(uint8_t mode)
{
	return(ADE_POWER_MODE(mode));

}/* End of function cmd_POWER_MODE() */


/***********************************************************************************************************************
* Function Name: cmd_DEFAULT_MEAS_INIT
* Description  : Basic initialization for measuring energy values, currents and voltages.
* Arguments    : none
* Return Value : err
*/
error_list_et cmd_QUICK_SETUP_AS_ENERGY_METER		(uint32_t pid)
{
	uint16_t cc			= 0;
	error_list_et err	= ADE_NO_ERROR;


	/* Recommended approach for energy calculations steps */
	/* Set gain registers */
	if((err = ADE_command_handler(pid, GAIN_INIT, DEFAULT_ARGS)) != ADE_NO_ERROR)		{ return err;}
	if((err = ADE_command_handler(pid, THRESHOLD, DEFAULT_ARGS)) != ADE_NO_ERROR)		{ return err;}
	if((err = ADE_command_handler(pid, WRITE_REGISTER, 3, CONFIG3, CONFIG3_DEFAULT, sizeof(uint8_t))) != ADE_NO_ERROR)	{return err;}

#if _VNOMAEN

	COMPMODE_reg_u COMPMODE_reg;
	COMPMODE_reg.REG_ALL 			= 0x0001;
	COMPMODE_reg.bits.VNOMAEN    	= 0;
	COMPMODE_reg.bits.VNOMBEN    	= 0;
	COMPMODE_reg.bits.VNOMCEN    	= 0;

	if((err = ADE_command_handler(pid, COMPMODE, 1, compmode_reg.reg_all)) != ADE_NO_ERROR)		{ return err;}

#endif

	while(++cc<3)
	{
		err = ADE_command_handler(pid, VLEVEL_CMD, 1, VLEVEL_DEFAULT);
	}
	if(err != ADE_NO_ERROR)		{ return err;}

	cc = 0;
	while( ((err = ADE_command_handler(pid, RAM_PROTECTION,1,ENABLE)) != ADE_NO_ERROR) 	&& 	(cc++ < 3));
	if(err != ADE_NO_ERROR)	{ return err;}

	return err;
}


/***********************************************************************************************************************
* Function Name: cmd_HARMONICS_DEF_INIT
* Description  : Initialize Harmonics measurement with default values defined in config.h
* Arguments    : phase- selects the phase A, B, C or Neutral line
* Return Value : err
*/
error_list_et cmd_HARMONICS_DEF_INIT		(uint8_t phase, uint32_t pid)
{
	error_list_et err = ADE_NO_ERROR;

	CONFIG_reg_u CONFIG_reg;			// To store COFIG register bits values
	HCONFIG_reg_u HCONFIG_reg;			// To store HCONFIG register bits values

	CONFIG_reg.REG_ALL = CONFIG_DEFAULT;// Initialize CONFIG to its default values
	CONFIG_reg.bits.CF2DIS = CONFIG_CF2DIS_BIT;	// Set CF2DIS bit in CONFIG check "includes.h" harmonics macros

	HCONFIG_reg.REG_ALL = HCONFIG_DEFAULT;// Initialize HCONFIG to its default values
	HCONFIG_reg.bits.HRCFG = HCONFIG_HRCFG_BIT;	//  check "includes.h" harmonics macros
	HCONFIG_reg.bits.HPHASE = phase;
	HCONFIG_reg.bits.HSTIME = HCONFIG_HSTIME_BITS;// check "includes.h" harmonics macros
	HCONFIG_reg.bits.HRATE = HCONFIG_HRATE_BITS;// check "includes.h" harmonics macros
	HCONFIG_reg.bits.ACTPHSEL = HCONFIG_ACTPHSEL_BITS;// check "includes.h" harmonics macros

	// Write GAIN register for neutral line
	// TODO: GAIN registers are initialized to their default values during system initialization.
	//     Set here only N line gain register to fulfill the harmonics initialization procedure

	// Write CONFIG register
	if ((err 	= cmd_wr_16B_REG(CONFIG, CONFIG_reg.REG_ALL, pid)) 	!= ADE_NO_ERROR )		{
#ifdef DEBUG_ADE
		printf("error in cmd_HARMONICS_DEF_INIT -->  cmd_wr_16B_REG(CONFIG, CONFIG_reg.REG_ALL) returned error\r\n");
#endif
		return err;
	}
	// Write HCONFIG register
	if ((err 	= cmd_wr_16B_REG(HCONFIG, HCONFIG_reg.REG_ALL, pid)) 	!= ADE_NO_ERROR )		{
#ifdef DEBUG_ADE
		printf("error in cmd_HARMONICS_DEF_INIT -->  cmd_wr_16B_REG(HCONFIG, HCONFIG_reg.REG_ALL) returned error\r\n");
#endif
		return err;
	}
	// Write Harmonics indexes values, check 'includes.h' macros values for HX, HY and HZ
	if ((err 	= cmd_wr_8B_REG(HX, HX_VAL, pid)) 	!= ADE_NO_ERROR )	{
#ifdef DEBUG_ADE
		printf("error in cmd_HARMONICS_DEF_INIT -->  (err 	= cmd_wr_8B_REG(HX, HX_VAL)) 	!= 0  returned error\r\n");
#endif
		return err; }
	if ((err 	= cmd_wr_8B_REG(HY, HY_VAL, pid)) 	!= ADE_NO_ERROR )	{
#ifdef DEBUG_ADE
		printf("error in cmd_HARMONICS_DEF_INIT -->  (err 	= cmd_wr_8B_REG(HY, HY_VAL)) 	!= 0  returned error\r\n");
#endif
		return err; }
	if ((err 	= cmd_wr_8B_REG(HZ, HZ_VAL, pid)) 	!= ADE_NO_ERROR )	{
#ifdef DEBUG_ADE
		printf("error in cmd_HARMONICS_DEF_INIT -->  (err 	= cmd_wr_8B_REG(HZ, HZ_VAL)) 	!= 0  returned error\r\n");
#endif
		return err; }

	return err;
} /* End of cmd_HARMONICS_DEF_INIT() */


#if INTEGATOR
/***********************************************************************************************************************
* Function Name: cmd_INTEGRATOR_DEF_INIT
* Description  : Initialize Harmonics measurement with default values defined in config.h
* Arguments    : phase- selects the phase A, B, C or Neutral line
* Return Value : err
*/
error_list_et cmd_INTEGRATOR_DEF_INIT (uint32_t pid)
{
	/********************
		 * TODO:  Check the registers content!!! they have to be correct
		 */
	error_list_et err = ADE_NO_ERROR;
	CONFIG_reg_u CONFIG_REG;
	CONFIG3_reg_u CONFIG3_REG;
	CONFIG_REG.REG_ALL = CONFIG_DEFAULT;
	CONFIG_REG.bits.INTEN = 1;
	CONFIG3_REG.REG_ALL = CONFIG3_DEFAULT;
	CONFIG3_REG.bits.ININTEN = 1;

	//if Neutral Current path Integrator is active. Check "includes.h" Integrator macros
	if(NI_INTEGRATOR) {
		if ((err = cmd_wr_32B_REG(DICOEFF, DICOEFF_DEFAULT, pid)) 	!= ADE_NO_ERROR )		{ return err; }
		if ((err = cmd_wr_32B_REG(CONFIG3, CONFIG3_REG.REG_ALL, pid)) 	!= ADE_NO_ERROR )	{ return err; }
	}
	//if Phase Currents paths Integrator is active. Check "includes.h" Integrator macros
	if(PI_INTEGRATOR) {
		if ((err = cmd_wr_32B_REG(DICOEFF, DICOEFF_DEFAULT, pid)) 	!= ADE_NO_ERROR )		{ return err; }
		if ((err = cmd_wr_32B_REG(CONFIG, CONFIG_REG.REG_ALL, pid)) 	!= ADE_NO_ERROR )		{ return err; }
	}

	return err;
} /* End of cmd_INTEGRATOR_DEF_INIT() */
#endif

/***********************************************************************************************************************
* Function Name: cmd_SET_RAM_PROTECTION
* Description  : Enables or disables the RAM protection
* Arguments    :
* Return Value :
*/
error_list_et cmd_RAM_PROTECTION(uint8_t cmd, uint32_t pid)
{
	/*****************************************************
	 * DIGITAL SIGNAL PROCESSOR procedure DataSheet pag 38
	 */

	error_list_et 						err 				= ADE_NO_ERROR;
	tx_packed_buff_st			tx_buffer1;
	tx_packed_buff_st			tx_buffer2;
	uint8_t 					value;
	ade7880_tx_struct_ut		tx_struct_1st_msg;
	ade7880_tx_struct_ut 		tx_struct_2nd_msg;

	if(cmd == ENABLE) value = 0x80;
	else value = 0x00;

	/* Set the structure members content and establish byte order according to endianness*/
	tx_struct_1st_msg.msg_fields.address_byte.address_all 	= 0x00;
	tx_struct_1st_msg.msg_fields.target_register 			= htons(0xE7FE);
	tx_struct_1st_msg.msg_fields.value.reg8					= 0xAD;

	tx_struct_2nd_msg.msg_fields.address_byte.address_all 	= 0x00;
	tx_struct_2nd_msg.msg_fields.target_register 			= htons(0xE7E3);
	tx_struct_2nd_msg.msg_fields.value.reg8					= value;

	/* Build the buffer 1 for network transmission */
	ADE_set_tx_buffer(&tx_buffer1, &tx_struct_1st_msg);

	/* Build the buffer 2 for network transmission */
	ADE_set_tx_buffer(&tx_buffer2, &tx_struct_2nd_msg);

#ifdef DEBUG_ADE
	if(debug_print&0x01) {
		printf("\nMSG SENT: WR\n");
		printf("       Chip Address %02X\n", tx_struct_1st_msg.msg_fields.address_byte.address_all);
		printf("       1st Target Register %04X\n",
				ntohs(tx_struct_1st_msg.msg_fields.target_register));
		printf("       Value sent 1st  %1X\n",
				ntohl(tx_struct_1st_msg.msg_fields.value.reg8));

		printf("       2nd Target Register %04X\n",
				ntohs(tx_struct_2nd_msg.msg_fields.target_register));
		printf("       Value sent  %01X\n",
				ntohl(tx_struct_2nd_msg.msg_fields.value.reg8));
	}
#endif

	/* To enable or disable the write protection write 0xAD to 8-bit register Address 0xE7FE */
	cmd_wr_8B_REG(	tx_struct_1st_msg.msg_fields.target_register,
					tx_struct_1st_msg.msg_fields.value.reg8,
					pid);
/*	// Confirm the write operation
	if((err = ADE_SPI_wr_tx_check(tx_struct_1st_msg.msg_fields.target_register,
								 tx_struct_1st_msg.msg_fields.value.reg8,
				 	 	 	 	 REG_LENGTH(tx_struct_1st_msg.msg_fields.value.reg8),
				 	 	 	 	 pid))
			!= ADE_NO_ERROR)	{ return err; }
*/
	/* followed by a write of 0x80 (EN) or 0x00 (DIS) to an internal 8-bit register located at Address 0xE7E3 */
	cmd_wr_8B_REG(	tx_struct_2nd_msg.msg_fields.target_register,
					tx_struct_2nd_msg.msg_fields.value.reg8,
					pid);
/*	// Confirm the write operation
	if((err = ADE_SPI_wr_tx_check(tx_struct_2nd_msg.msg_fields.target_register,
								 tx_struct_2nd_msg.msg_fields.value.reg8,
				 	 	 	 	 REG_LENGTH(tx_struct_2nd_msg.msg_fields.value.reg8),
				 	 	 	 	 pid))
			!= ADE_NO_ERROR)	{ return err; }
*/
	return err;

}/* End of cmd_SET_RAM_PROTECTION() */


/***********************************************************************************************************************
* Function Name: cmd_rd_REG
* Description  : Read any register content, outputs a int32_t which must be casted from the function call
* Arguments    : REG_addr-	Register address
* 				 REG_val-	Register length
* Return Value : Register content as 32b, must be casted from function call to the appropriate value according register
*/
error_list_et cmd_rd_REG(uint16_t REG_addr, uint8_t REG_len, int32_t *pRead, uint32_t pid)
{
	error_list_et err = ADE_NO_ERROR;

	err = ADE_SPI_read(REG_addr, REG_len, pRead, pid);

	return err;
}/* End of function cmd_32B_REG() */


/***********************************************************************************************************************
* Function Name: cmd_rd_32B_REG
* Description  : Read 32Bit registers content
* Arguments    : REG_addr-	Register address
* 				 REG_val-	Register value
* Return Value : Register content value
*/
error_list_et cmd_rd_32B_REG(uint16_t REG_addr, int32_t *pRead, uint32_t pid)
{
	error_list_et err = ADE_NO_ERROR;

	err = ADE_SPI_read(REG_addr, REG_LENGTH(uint32_t), pRead, pid);
	return err;
}/* End of function cmd_32B_REG() */


/***********************************************************************************************************************
* Function Name: cmd_rd_16B_REG
* Description  : Set 16Bit registers content
* Arguments    : REG_addr-	Register address
* 				 REG_val	Register value
* Return Value : Register content value
*/
error_list_et cmd_rd_16B_REG(uint16_t REG_addr, int32_t *pRead, uint32_t pid)
{
	error_list_et err = ADE_NO_ERROR;

	err = ADE_SPI_read(REG_addr, REG_LENGTH(uint16_t), pRead, pid);
	return err;
}/* End of function cmd_16B_REG() */


/***********************************************************************************************************************
* Function Name: cmd_rd_8B_REG
* Description  : Set 8Bit registers content
* Arguments    : REG_addr-	Register address
* 				 REG_val	Register value
* Return Value : Register content value
*/
error_list_et cmd_rd_8B_REG(uint16_t REG_addr, int32_t *pRead, uint32_t pid)
{
	error_list_et err = ADE_NO_ERROR;

	err = ADE_SPI_read(REG_addr, REG_LENGTH(uint8_t), pRead, pid);
	return err;
}/* End of function cmd_8B_REG() */


/***********************************************************************************************************************
* Function Name: cmd_wr_32B_REG
* Description  : Set 32Bit registers content
* Arguments    : REG_addr-	Register address
* 				 REG_val	Register value
* Return Value : err
*/
error_list_et cmd_wr_32B_REG(uint16_t REG_addr, uint32_t REG_val, uint32_t pid)
{
	return (ADE_SPI_write(REG_addr, REG_val, REG_LENGTH(uint32_t), pid));
}/* End of function cmd_32B_REG() */


/***********************************************************************************************************************
* Function Name: cmd_wr_16B_REG
* Description  : Set 16Bit registers content
* Arguments    : REG_addr-	Register address
* 				 REG_val	Register value
* Return Value : err
*/
error_list_et cmd_wr_16B_REG(uint16_t REG_addr, uint16_t REG_val, uint32_t pid)
{
		return(ADE_SPI_write(REG_addr, REG_val,	REG_LENGTH(uint16_t), pid));
}/* End of function cmd_16B_REG() */


/***********************************************************************************************************************
* Function Name: cmd_wr_8B_REG
* Description  : Set 8Bit registers content
* Arguments    : REG_addr-	Register address
* 				 REG_val	Register value
* Return Value : err
*/
#include <unistd.h>
error_list_et cmd_wr_8B_REG(uint16_t REG_addr, uint8_t REG_val, uint32_t pid)
{
	return(ADE_SPI_write(REG_addr, REG_val,	REG_LENGTH(uint8_t), pid));
}/* End of function cmd_8B_REG() */


/***********************************************************************************************************************
* Function Name: meas_PHASE_VRMS
* Description  :
* Arguments    :
* Return Value :
*/
error_list_et meas_PHASE_VRMS 	(uint8_t channel, uint16_t samples, float *measured_val, uint32_t pid)
{
	error_list_et err = ADE_NO_ERROR;
	int32_t measured_temp = 0;
	int32_t measured_total = 0;
	uint16_t ii;
	uint16_t target_reg = 	(channel == PHASE_A) ? AVRMS :
							(channel == PHASE_B) ? BVRMS :
							(channel == PHASE_C) ? CVRMS :
							 0;

	if (target_reg == 0) { return ADE_ERROR_REG_LENGTH; }

	for (ii = 0; ii < samples; ii++)
	{
		if ((err = wait_new_conversion(pid)) != ADE_NO_ERROR) { return err; }
		err |= ADE_SPI_read( target_reg, REG_LENGTH( uint32_t ), &measured_temp, pid);
		measured_total += (measured_temp & 0xFFFFFF)  * TRANSFORMER_RATIO;
	}

	*measured_val = (float)measured_total / (float)samples / VLSB_CONST;

	return err;
}/* End of meas_PHASE_VRMS() */


/***********************************************************************************************************************
* Function Name: meas_PHASE_IRMS
* Description  :
* Arguments    :
* Return Value :
*/
error_list_et meas_PHASE_IRMS 	(uint8_t channel, uint16_t samples, float *measured_val, uint32_t pid)
{
	error_list_et err = ADE_NO_ERROR;
	int32_t measured_temp = 0;
	int32_t measured_total = 0;
	uint16_t ii;
	uint16_t target_reg = 	(channel == PHASE_A) ? AIRMS :
							(channel == PHASE_B) ? BIRMS :
							(channel == PHASE_C) ? CIRMS :
							(channel == NEUTRAL_LINE) 	 ? NIRMS :	// Instantaneous RMS Current on Neutral line
							(channel == ISUM) 	? ISUM :
							 0;

	if (target_reg == 0) { return ADE_ERROR_REG_LENGTH; }

	for (ii = 0; ii < samples; ii++) {
		if ((err = wait_new_conversion(pid)) != ADE_NO_ERROR) { return err; }
		err |= ( ADE_SPI_read( target_reg,	REG_LENGTH(uint32_t), &measured_temp,pid) );
		measured_total += measured_temp;
	}

	*measured_val = (float)measured_total / (float)samples / ILSB_CONST;
	return err;
}/* End of meas_PHASE_IRMS() */


/***********************************************************************************************************************
* Function Name: meas_PHASE_ACTIVE_WH
* Description  :
* Arguments    :
* Return Value :
*/
error_list_et meas_PHASE_ACTIVE_WH (uint8_t channel, float *measured_val, uint32_t pid)
{
	error_list_et err = ADE_NO_ERROR;
	int32_t measured_temp = 0;
	uint16_t target_reg = 	(channel == PHASE_A) ? AWATTHR :
							(channel == PHASE_B) ? BWATTHR :
							(channel == PHASE_C) ? CWATTHR :
							 0;
	if (target_reg == 0) { return ADE_ERROR_REG_LENGTH; }

	err = ADE_SPI_read( target_reg, REG_LENGTH(uint32_t), &measured_temp, pid);
	*measured_val = (float)measured_temp / WHLSB_CONST;

	return  err;
}/* End of meas_PHASE_ACTIVE_WH() */


/***********************************************************************************************************************
* Function Name: meas_TOTAL_ACTIVE_WH
* Description  :
* Arguments    :
* Return Value :
*/
error_list_et meas_TOTAL_ACTIVE_WH (uint8_t channel, float *measured_val, uint32_t pid)
{
	error_list_et err = ADE_NO_ERROR;
	float measured_temp = 0;

	err = ADE_measure(pid, PHASE_ACTIVE_WH, PHASE_A, 1, &measured_temp);
	*measured_val = measured_temp;
	err = ADE_measure(pid, PHASE_ACTIVE_WH, PHASE_B, 1, &measured_temp);
	*measured_val += measured_temp;
	err = ADE_measure(pid, PHASE_ACTIVE_WH, PHASE_C, 1, &measured_temp);
	*measured_val += measured_temp;

	return err;
}/* End of meas_TOTAL_ACTIVE_WH() */



/***********************************************************************************************************************
* Function Name: meas_PHASE_ACTIVE_POWER
* Description  :
* Arguments    :
* Return Value :
*/
error_list_et meas_PHASE_ACTIVE_POWER (uint8_t channel, float *measured_val, uint32_t pid)
{
	error_list_et err = ADE_NO_ERROR;
	int32_t measured_temp;
	uint16_t target_reg = 	(channel == PHASE_A) ? AWATT :
							(channel == PHASE_B) ? BWATT :
							(channel == PHASE_C) ? CWATT :
							 0;
	if (target_reg == 0) { return ADE_ERROR_REG_LENGTH; }

	err = ADE_SPI_read( target_reg, REG_LENGTH(uint32_t), &measured_temp, pid);

	*measured_val = (float)measured_temp / WATTLSB_CONST;

	return err;
}/* End of meas_PHASE_ACTIVE_POWER() */


/***********************************************************************************************************************
* Function Name: meas_IHARMONIC_RMS
* Description  :
* Arguments    :
* Return Value :
*/
error_list_et meas_IHARMONIC_RMS (uint8_t channel, float *measured_val, uint32_t pid)
{
	error_list_et err = ADE_NO_ERROR;
	int32_t measured_temp;
	uint16_t target_reg = 	(channel == HX_CH) ? HXIRMS :  	// RMS Current of HX harmonic on Phase or Neutral line
							(channel == HY_CH) ? HYIRMS :		// RMS Current of HY harmonic on Phase or Neutral line
							(channel == HZ_CH) ? HZIRMS :		// RMS Current of HZ harmonic on Phase or Neutral line
							 0;
	if (target_reg == 0) { return ADE_ERROR_REG_LENGTH; }

	err = ADE_SPI_read( target_reg, REG_LENGTH(uint32_t), &measured_temp, pid);

	*measured_val = (float)(measured_temp & 0xFFFFFF) / REG_321_CORRECTION;

	return err;
} /* End of meas_IHARMONIC_RMS() */


/***********************************************************************************************************************
* Function Name: meas_VHARMONIC_RMS
* Description  :
* Arguments    :
* Return Value :
*/
error_list_et meas_VHARMONIC_RMS (uint8_t channel, float *measured_val, uint32_t pid)
{
	error_list_et err = ADE_NO_ERROR;
	int32_t measured_temp;
	uint16_t target_reg = 	(channel == HX_CH) ? HXVRMS :  	// RMS V of HX harmonic on Phase or Neutral line
							(channel == HY_CH) ? HYVRMS :		// RMS V of HY harmonic on Phase or Neutral line
							(channel == HZ_CH) ? HZVRMS :		// RMS V of HZ harmonic on Phase or Neutral line
							 0;
	if (target_reg == 0) { return ADE_ERROR_REG_LENGTH; }

	err = ADE_SPI_read( target_reg, REG_LENGTH(uint32_t), &measured_temp, pid);

	*measured_val = (float)(measured_temp & 0xFFFFFF) / REG_321_CORRECTION;

	return err;
} /* End of meas_VHARMONIC_RMS() */


/***********************************************************************************************************************
* Function Name: meas_IHARMONIC_HD
* Description  : NEUTRAL CURRENT HARMONICS DISTORTION
* Arguments    :
* Return Value :
*/
error_list_et meas_IHARMONIC_HD(uint8_t channel, uint16_t samples, float *measured_val, uint32_t pid)
{
	error_list_et err = ADE_NO_ERROR;
	int32_t measured_temp;
	int32_t measured_total;
	uint16_t ii;
	uint16_t target_reg = 	(channel == HX_CH) ? HXIHD :
							(channel == HY_CH) ? HYIHD :
							(channel == HZ_CH) ? HZIHD :
							 0;

	if (target_reg == 0) { return ADE_ERROR_REG_LENGTH; }

	for (ii = 0; ii < samples; ii++) {
		if ((err = wait_new_conversion(pid)) != ADE_NO_ERROR) { return err; }
		err |= ADE_SPI_read( target_reg, REG_LENGTH(uint32_t), &measured_temp, pid);
		measured_total += measured_temp & 0xFFFFFF;
	}

	*measured_val = ((float)measured_total) / (float)samples / REG_321_CORRECTION;

	return err;
} /* End of meas_IHARMONIC_HD() */


/***********************************************************************************************************************
* Function Name: meas_VHARMONIC_HD
* Description  : NEUTRAL CURRENT HARMONICS DISTORTION
* Arguments    :
* Return Value :
*/
error_list_et meas_VHARMONIC_HD(uint8_t channel, uint16_t samples, float *measured_val, uint32_t pid)
{
	int32_t measured_temp = 0.0;
	int32_t measured_total = 0.0;
	error_list_et err = ADE_NO_ERROR;
	uint16_t ii;
	uint16_t target_reg = 	(channel == HX_CH) ? HXVHD :
							(channel == HY_CH) ? HYVHD :
							(channel == HZ_CH) ? HZVHD :
							 0;

	if (target_reg == 0) { return ADE_ERROR_REG_LENGTH; }

	for (ii = 0; ii < samples; ii++)
	{
		if ((err = wait_new_conversion(pid)) != ADE_NO_ERROR) { return err; }
		err |= ADE_SPI_read( target_reg, REG_LENGTH(uint32_t), &measured_temp, pid) ;
		measured_total += measured_temp & 0xFFFFFF;
	}

	*measured_val = (float)measured_total / (float)samples / REG_321_CORRECTION;

	return err;
} /* End of meas_VHARMONIC_HD() */


/***********************************************************************************************************************
* Function Name: meas_REGISTER
* Description  : To measure the value of any register
* Arguments    :
* Return Value :
*/
error_list_et meas_REGISTER (uint8_t channel, uint16_t samples, float *measured_val, uint32_t pid)
{
	int32_t measured_temp = 0.0;
	int32_t measured_total = 0.0;
	error_list_et err = ADE_NO_ERROR;
	uint16_t ii;

	for (ii = 0; ii < samples; ii++) {
		if ((err = wait_new_conversion(pid)) != ADE_NO_ERROR) { return err; }
		err |= ADE_SPI_read(channel, REG_LENGTH(uint32_t), &measured_temp, pid);
		measured_total += measured_temp & 0xFFFFFF;
	}
	*measured_val = (float)measured_total / (float)samples;

	return err;
} /* End of meas_IHARMONIC_RMS() */




/***********************************************************************************************************************
* Function Name: wait_new_conversion
* Description  :
* Arguments    :
* Return Value :
*/
error_list_et wait_new_conversion(uint32_t pid)
{
	error_list_et err = ADE_NO_ERROR;
	int8_t cc = 0;
	int32_t result = 0;
	STATUS0_reg_u STATUS0_REG;

	if((err = ADE_SPI_read(STATUS0,REG_LENGTH(uint32_t), &result, pid)) != ADE_NO_ERROR)  { return err; }

	STATUS0_REG.REG_ALL = result;

	if(STATUS0_REG.bits.DREADY==1)
	{
		result=0;
		cc = 0;

		while(((err = ADE_command_handler(RAM_PROTECTION,1,DISABLE)) != ADE_NO_ERROR) || (cc++ < 3));

		if(err != ADE_NO_ERROR) 	return ADE_ERROR_RAM_PROTECTION_NOT_DISABLED;

		//put back the value to clear status flags
		STATUS0_REG.bits.DREADY = 0;

		if( (ADE_SPI_write(STATUS0,STATUS0_REG.REG_ALL,REG_LENGTH(uint32_t), pid) ) != ADE_NO_ERROR)
		{
			return ADE_ERROR_REG_WRITE;
		}

		if( (err = ADE_SPI_read(STATUS0,REG_LENGTH(uint32_t), &result, pid)) != ADE_NO_ERROR)  return err;
		STATUS0_REG.REG_ALL = result;

		cc = 0;
		while(((err = ADE_command_handler(RAM_PROTECTION,1,ENABLE)) != ADE_NO_ERROR) || (cc++ < 3));

		if(err != 0)
		{
			#ifdef DEBUG_ADE
				printf("\nERROR: in wait_new_conversion() Couldn't set RAM protection to ENABLE, return -1\n");
			#endif
			return err;
		}
		
		//wait till conversion is done
		result = 0;
		cc = 0;
		
		while( (STATUS0_REG.bits.DREADY==0) && cc++ < 10)
		{
			if((err = ADE_SPI_read(STATUS0,REG_LENGTH(uint32_t), &result, pid)) != ADE_NO_ERROR) return err;
			STATUS0_REG.REG_ALL = result;
		}
		
		if (STATUS0_REG.bits.DREADY == 0)
		{
			return ADE_ERROR_CONVERSION_WAIT_TIME_EXCEED;
		}
		
	}
	
	return 0;
} /* End of function wait_new_conversion() */


