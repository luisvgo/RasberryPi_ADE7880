/*
 * transmission.c
 *
 *  Created on: Feb 13, 2015
 *      Author: oops
 */
/* Ade drv for knowing harmonic indexes*/

#include <stdio.h>
#include <string.h>

#include <stdint.h>
#include <stdbool.h>
#include <semaphore.h>
#include "../../pi_ade7880/src/ade7880/ade7880_configuration.h"
#include "../../pi_ade7880/src/pi_ade7880_drv.h"
#include "../../pi_m16c_spi/m16c_spi.h"
#include "transmission.h"
#include "../main.h"

//#include "../pi_ade7880/src/ade7880_driver.h"

extern sem_t 	g_DataUpdt_Lock_mutex;

/******************************************************************************
 * Function name: void transmit_measures(void)
 * Description  : To print measures to stdout
 * Arguments    : none
 * Return value : none
 ******************************************************************************/
#define USE_DEBUG_CONSOLE
void transmit_measures(uint8_t caller, void *data)
{

	//if (caller == MOTOR_SENSORS)
	sem_wait(&g_DataUpdt_Lock_mutex);

	switch (caller){
		case ENERGY_MEAS:
			print_energy_meas(data);
			break;
		case HARMONICS_MEAS:
			print_harmonic_meas(data);
			break;
		case MOTOR_SENSORS_REAL:
			print_motor_sensors(data);
			break;
		case MOTOR_SENSORS_INT:
			print_motor_sensors_int(data);
			break;
		default:
			break;
	}
	sem_post(&g_DataUpdt_Lock_mutex);
}


void print_harmonic_meas(void *pData)
{
	//measured_data_t *data = (measured_data_t *)pData;

#ifdef SEND_CONSOLE
	uint8_t result_string[20];
	printf("\r\n------------------------------------------------------------------------------------------------------------------- \r\n");
	printf("| cnt |	N I RMS	|	HX IRMS	|	HY IRMS	|	HZ IRMS	|	Ph_A IRMS |	Ph_B IRMS |	Ph_C IRMS | \r\n");
	printf("------------------------------------------------------------------------------------------------------------------- \r\n");

	/* count */
	sprintf(result_string, "| %2u |",i+1);
	printf(result_string);
	/* IN_IRMS */
	//sprintf(result_string, "	%1.5f |", g_data[i].neutral_line.IN_IRMS);
	sprintf(result_string, "	%f |", data->neutral_line.IN_IRMS);
	printf(result_string);
	/* IN_HXIRMS */
	sprintf(result_string, "	%1.5f |", data->neutral_line.IN_HXIRMS);
	printf(result_string);
	/* IN_HYIRMS */
	sprintf(result_string, "	%1.5f |", data->neutral_line.IN_HYIRMS);
	printf(result_string);
	/* IN_HZIRMS */
	sprintf(result_string, "	%1.5f |", data->neutral_line.IN_HZIRMS);
	printf(result_string);
	/* Ph_A IRMS */
	sprintf(result_string, "	%1.5f   |", data->phase_a.IRMS);
	printf(result_string);
	/* Ph_B IRMS */
	sprintf(result_string, "	%1.5f   |", data->phase_b.IRMS);
	printf(result_string);
	/* Ph_C IRMS */
	sprintf(result_string, "	%1.5f   |\r\n", data->phase_c.IRMS);
	printf(result_string);


	printf("------------------------------------------------------------------------------------------------------------------- \r\n");

#endif

#ifdef	USE_DEBUG_CONSOLE1
	/* Show the result in stdout */

	printf("\nCount = -------------%d", 1);
	printf("\n---------------------NEUTRAL RMS CURRENT (NIRMS) : %f\n",
			data->neutral_line.IN_IRMS);
	printf("\n---------------------HARMONIC N.%d OF NEUTRAL RMS CURRENT: %f\n",
			HX_VAL, data->neutral_line.IN_HXIRMS);
	printf("\n---------------------HARMONIC N.%d OF NEUTRAL RMS CURRENT: %f\n",
			HY_VAL, data->neutral_line.IN_HYIRMS);
	printf("\n---------------------HARMONIC N.%d OF NEUTRAL RMS CURRENT: %f\n",
			HZ_VAL, data->neutral_line.IN_HZIRMS);

#endif
} /* End of function print_harmonic_meas() */


void print_energy_meas(void *pData)
{

	em_data_t *data = (em_data_t *)pData;


	char result_string[20];
	printf("\r\n------------------------------------------------------------------------------------------------------------------- \r\n");
	printf("| cnt |	PA VRMS	|	PB VRMS	|	PC VRMS	|	HZ IRMS	|	Ph_A IRMS |	Ph_B IRMS |	Ph_C IRMS | \r\n");
	printf("------------------------------------------------------------------------------------------------------------------- \r\n");

	/* count */
	sprintf(result_string, "| %2u |",1);
	printf(result_string);
	/* IN_IRMS */
	//sprintf(result_string, "	%1.5f |", g_data[i].neutral_line.IN_IRMS);
	sprintf(result_string, "	%f |", data->phase_a.VRMS.value);
	printf(result_string);
	/* IN_HXIRMS */
	sprintf(result_string, "	%1.5f |", data->phase_b.VRMS.value);
	printf(result_string);
	/* IN_HYIRMS */
	sprintf(result_string, "	%1.5f |", data->phase_c.VRMS.value);
	printf(result_string);
	/* IN_HZIRMS */
	sprintf(result_string, "	%1.5f |", data->neutral_line.IN_HZIRMS.value);
	printf(result_string);
	/* Ph_A IRMS */
	sprintf(result_string, "	%1.5f   |", data->phase_a.IRMS.value);
	printf(result_string);
	/* Ph_B IRMS */
	sprintf(result_string, "	%1.5f   |", data->phase_b.IRMS.value);
	printf(result_string);
	/* Ph_C IRMS */
	sprintf(result_string, "	%1.5f   |\r\n", data->phase_c.IRMS.value);
	printf(result_string);


	printf("------------------------------------------------------------------------------------------------------------------- \r\n");



#ifdef	USE_DEBUG_CONSOLE1
	/* Show the result in stdout */

	printf("\nCount = -------------%d", 1);
	printf("\n---------------------Phase A RMS CURRENT : %f\r\n",	data->phase_a.IRMS);
	printf("\n---------------------Phase B RMS CURRENT : %f\r\n",	data->phase_b.IRMS);
	printf("\n---------------------Phase C RMS CURRENT : %f\r\n",	data->phase_c.IRMS);
	printf("\n---------------------Phase A RMS VOLTAGE : %f\r\n",	data->phase_a.VRMS);
	printf("\n---------------------Phase B RMS VOLTAGE : %f\r\n",	data->phase_b.VRMS);
	printf("\n---------------------Phase C RMS VOLTAGE : %f\r\n",	data->phase_c.VRMS);
	printf("\n---------------------Phase A ACTIVE POWER : %f\r\n",	data->phase_a.POWER);
	printf("\n---------------------Phase B ACTIVE POWER : %f\r\n",	data->phase_b.POWER);
	printf("\n---------------------Phase C ACTIVE POWER : %f\r\n",	data->phase_c.POWER);
	printf("\n---------------------Phase A WATT HOUR : %f\r\n",	data->phase_a.WH);
	printf("\n---------------------Phase B WATT HOUR : %f\r\n",	data->phase_b.WH);
	printf("\n---------------------Phase C WATT HOUR : %f\r\n",	data->phase_c.WH);



#endif
} /* End of function print_harmonic_meas() */



void print_motor_sensors(void *pData)
{
	MC_real_values_st *data = (MC_real_values_st *)pData;

	char 	result_string[20];

#ifdef	USE_DEBUG_CONSOLE

	/* Show the result in stdout */
#ifdef DEBUG
	printf("\r\n---------------------Command sent : %x\r\n",	data->cmd_addr);
#endif
	printf("----------------------------------------------------------------------------------- \r\n");
	printf("| Torque | air tmp | coolant in t | coolant out t | m blk t | Exhaust g t | oil t |\r\n");
	printf("----------------------------------------------------------------------------------- \r\n");
	//sprintf(result_string, "	%1.5f |", g_data[i].neutral_line.IN_IRMS);
	sprintf(result_string, "|  %2.3f |", data->torque);
	printf(result_string);
	//printf("\n---------------------Torque : %f\r\n",	data->torque);
	sprintf(result_string, "    %3.2f |", data->suction_temp);
	printf(result_string);
	//printf("\n---------------------Suction Air temperature : %f\r\n",	data->suction_temp);
	sprintf(result_string, "	%3.2f	  |", data->coolant_in_temp);
	printf(result_string);
	//printf("\n---------------------Coolant temperature : %f\r\n",	data->coolant_in_temp);
	sprintf(result_string, "	%3.2f	  |", data->coolant_return_temp);
	printf(result_string);
	//printf("\n---------------------Returning Coolant Temperature : %f\r\n",	data->coolant_return_temp);
	sprintf(result_string, "   %3.2f  |", data->block_temp);
	printf(result_string);
	//printf("\n---------------------Motor Block Temperature : %f\r\n",	data->block_temp);
	sprintf(result_string, "	  %3.2f	  |", data->exhaust_temp);
	printf(result_string);
	//printf("\n---------------------Exhaust gasses Temperature : %f\r\n",	data->exhaust_temp);
	sprintf(result_string, "  %3.2f |", data->oil_temp);
	printf(result_string);
	//printf("\n---------------------Oil Temperrature : %f\r\n",	data->oil_temp);

	printf("\r\n");
	printf("--------------------------------------------------------------------------------------------------------- \r\n");
	printf("|  RPMs	| fuel in | fuel return | suct flow | Oil press OK | Fuel lvl Min | EMERGENCY STP | smokes out  |\r\n");
	printf("--------------------------------------------------------------------------------------------------------- \r\n");

	sprintf(result_string, "| %5.2f |", data->crankShaft_rpm);
	printf(result_string);
	//printf("\n---------------------CrankShaft_rpm : %f\r\n",	data->crankShaft_rpm);
	sprintf(result_string, "  %2.3f  |", data->fuel_in);
	printf(result_string);
	//printf("\n---------------------Fuel Flow intake : %f\r\n",	data->fuel_in);
	sprintf(result_string, "	%2.3f   |", data->fuel_return);
	printf(result_string);
	//printf("\n---------------------Fuel Flow return : %f\r\n",	data->fuel_return);
	sprintf(result_string, "   %2.3f   |", data->suction_flow);
	printf(result_string);
	//printf("\n---------------------Suction Channel flow : %f\r\n",	data->suction_flow);
	sprintf(result_string, "	   %u	   |", data->bin_input.bit_s.oil_pressure_OK);
	printf(result_string);
	//printf("\n---------------------Oil Prssure OK : %d\r\n",	data->bin_input.bit_s.oil_pressure_OK);
	sprintf(result_string, "	   %u	  |", data->bin_input.bit_s.min_fuel_lvl);
	printf(result_string);
	//printf("\n---------------------Fuel min. level : %d\r\n",	data->bin_input.bit_s.min_fuel_lvl);
	sprintf(result_string, "	   %u	  |", data->bin_input.bit_s.emergency_stop);
	printf(result_string);
	//printf("\n---------------------Emergency sotp : %d\r\n",	data->bin_input.bit_s.emergency_stop);
	sprintf(result_string, "	%u	|", data->bin_input.bit_s.annealing_ON);
	printf(result_string);
	//printf("\n---------------------annealing_ON : %d\r\n",	data->bin_input.bit_s.annealing_ON);
	printf("\r\n");

	printf("--------------------------------------------------------------------------------------------------------- \r\n");

#endif

}


void print_motor_sensors_int(void *pData)
{
	MC_data_st *data = (MC_data_st *)pData;

#ifdef	USE_DEBUG_CONSOLE
	/* Show the result in stdout */

	printf("\nCount = -------------%d", 1);

	printf("\n---------------------Command sent : %x\r\n",	data->cmd_addr);
	printf("\n---------------------Torque : %u\r\n",	data->torque);
	printf("\n---------------------Suction Air temperature : %u\r\n",	data->suction_temp);
	printf("\n---------------------Coolant temperature : %u\r\n",	data->coolant_in_temp);
	printf("\n---------------------Returning Coolant Temperature : %u\r\n",	data->coolant_return_temp);
	printf("\n---------------------Motor Block Temperature : %u\r\n",	data->block_temp);
	printf("\n---------------------Exhaust gasses Temperature : %u\r\n",	data->exhaust_temp);
	printf("\n---------------------Oil Temperrature : %u\r\n",	data->oil_temp);
	printf("\n---------------------CrankShaft_rpm : %u\r\n",	data->crankShaft_rpm);
	printf("\n---------------------Fuel Flow intake : %u\r\n",	data->fuel_in);
	printf("\n---------------------Fuel Flow return : %u\r\n",	data->fuel_return);
	printf("\n---------------------Suction Channel flow : %u\r\n",	data->suction_flow);
	printf("\n---------------------Oil Prssure OK : %d\r\n",	data->bin_input.bit_s.oil_pressure_OK);
	printf("\n---------------------Fuel min. level : %d\r\n",	data->bin_input.bit_s.min_fuel_lvl);
	printf("\n---------------------Emergency sotp : %d\r\n",	data->bin_input.bit_s.emergency_stop);
	printf("\n---------------------annealing_ON : %d\r\n",	data->bin_input.bit_s.annealing_ON);


#endif

}
