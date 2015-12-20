/// \file ade7880_srv_cmd_handler.h
/// \brief definitions and enumerations for different configurations and measurements

/***********************************************************************************************************************
* DISCLAIMER
*
* Copyright (C) 2014
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name	   : ade7880_srv_cmd_handler.h
* Version      : 1.0
* H/W Platform : ADE7880
* Description  : header file for ADE7880 driver command handler.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
* 		  						Includes common definitions and macros
*         : 20.09.2014 1.00     First Release
*         : 23.09.2014 1.10     Definitions for config and measurement commands changed to enum list
***********************************************************************************************************************/

#ifndef __SRV_CMD_HANDLER_H
#define __SRV_CMD_HANDLER_H

/***********************************************************************************************************************
* Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/


/***********************************************************************************************************************
* Definitions for Configuration commands
**********************************************************************************************************************/
#define NO_ARGS				0
#define DEFAULT_ARGS		NO_ARGS
#define TO_INT8_T(_x)		(_x & 0x000000FF)
#define TO_INT16_T(_x)		(_x & 0x0000FFFF)



/* internal use config commands  */
typedef enum{
	ADE7880_SET_SPI_COMM,
	ADE7880_SPI_COMM_LOCK,
	ADE7880_RESET,
	POWER_MODE,
	VLEVEL_CMD,
	COMPMODE_CMD,
	VNOM_CMD,
	THRESHOLD,
	DSP_RUN,
	DSP_STOP,
	GAIN_INIT,
	QUICK_SETUP_AS_ENERGY_METER,
	HARMONICS_INIT,
	INTEGRATOR_INIT,
	RAM_PROTECTION,
	WRITE_REGISTER
}config_cmd_et;

/***********************************************************************************************************************
* Definitions for Measurement Commands
**********************************************************************************************************************/
/* internal use measurement read commands list */
typedef enum{
	PHASE_VRMS,
	PHASE_IRMS,
	PHASE_ACTIVE_WH,
	PHASE_ACTIVE_POWER,
	IHARMONIC_RMS,
	VHARMONIC_RMS,
	IHARMONIC_HD,
	VHARMONIC_HD,
	REGISTER
}measurement_cmd_et;

/***********************************************************************************************************************
* Definitions for Measurement Channels
**********************************************************************************************************************/
/* internal use measurement read commands list */
typedef enum{
	PHASE_A = 0,
	PHASE_B = 1,
	PHASE_C = 2,
	NEUTRAL_LINE = 3,
	ISUM_HD,
	HX_CH,
	HY_CH,
	HZ_CH,
	INRMS
}measurement_ch_et;
#include <unistd.h>		/* Symbolic Constants */

/***********************************************************************************************************************
* Public Functions
***********************************************************************************************************************/
error_list_et			ADE_command_handler			(uint32_t pid, uint32_t cmd,uint8_t arg,...);
error_list_et 			ADE_measure					(uint32_t pid, uint8_t cmd,uint8_t channel,uint16_t samples, float *result);
void 			ADE_COMM_INIT_callback_set			(int8_t(*func)(uint8_t mode, uint32_t pid));
void 			ADE_POWER_MODE_callback_set			(int8_t(*func)(uint8_t mode));
void 			ADE_SPI_COMMLOCK_callback_set		(int8_t(*func)(uint32_t pid));

#endif /* SRV_CMD_HANDLER_H_HEADER_FILE */
