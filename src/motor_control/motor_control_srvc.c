/*
 * motor_control_srvc.c
 *
 *  Created on: Feb 18, 2015
 *      Author: Luis
 */


#include "../main.h"
#include <signal.h>
#include "../../libIEC61850_server/include/iec61850_wrapper.h"
#include "../../libIEC61850_server/static_model.h"

#define SERVER_ON		1
#define SERVER_OFF		0

extern sem_t 	g_DataUpdt_Lock_mutex;
extern uint8_t g_key;

server_data_st *g_pData;

void server_readData(IedServer server)
{
	// Readings from server
}

void server_writeData(IedServer server)
{
	fprintf(stderr, "Inside server write \r\n");
	//write to server
	sem_wait(&g_DataUpdt_Lock_mutex);

	//Output Power
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDGenerator_MMXU1_TotW_mag_f,
										g_pData->energy.phase_a.POWER.value);

	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDGenerator_MMXU1_TotW_t,
										g_pData->energy.phase_a.POWER.timestamp);

	//Phase to Phase Voltage
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDGenerator_MMXU1_PPV_phsAB_cVal_mag_f,
										g_pData->energy.phase_a.VRMS.value);

	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDGenerator_MMXU1_PPV_phsAB_t,
										g_pData->energy.phase_a.VRMS.timestamp);

	//Phase current
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDGenerator_MMXU1_A_phsA_cVal_mag_f,
										g_pData->energy.phase_a.IRMS.value);

	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDGenerator_MMXU1_PPV_phsAB_t,
										g_pData->energy.phase_a.IRMS.timestamp);

	//Output energy
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDGenerator_MMXU2_TotW_mag_f,
										g_pData->energy.phase_a.WH.value);

	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDGenerator_MMXU2_TotW_t,
										g_pData->energy.phase_a.WH.timestamp);

	//Crankshaft's torque
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_YLTC1_Torq_mag_f,
										g_pData->motor.torque.value);
	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDMotorIO_YLTC1_Torq_t,
										g_pData->motor.torque.timestamp);

	//Suction channel temperature
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_SIML1_TMP_mag_f,
										g_pData->motor.suction_temp.value);

	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDMotorIO_SIML1_TMP_t,
										g_pData->motor.suction_temp.timestamp);

	//Coolant/going temperature
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_SIML2_TMP_mag_f,
										g_pData->motor.coolant_in_temp.value);

	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDMotorIO_SIML2_TMP_t,
										g_pData->motor.coolant_in_temp.timestamp);

	//Coolant/return temperature
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_SIML3_TMP_mag_f,
										g_pData->motor.coolant_return_temp.value);

	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDMotorIO_SIML3_TMP_t,
										g_pData->motor.coolant_return_temp.timestamp);

	//Engine block temperature
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_SIML4_TMP_mag_f,
										g_pData->motor.block_temp.value);

	IedServer_updateUTCTimeAttributeValue(server,
											IEDMODEL_LDMotorIO_SIML4_TMP_t,
											g_pData->motor.block_temp.timestamp);

	//exhaust channel temperature
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_SIML5_TMP_mag_f,
										g_pData->motor.exhaust_temp.value);

	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDMotorIO_SIML5_TMP_t,
										g_pData->motor.exhaust_temp.timestamp);

	//lubricant (oil) temperature
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_SIML6_TMP_mag_f,
										g_pData->motor.oil_temp.value);

	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDMotorIO_SIML6_TMP_t,
										g_pData->motor.oil_temp.timestamp);
/*
	//minimum level of fuel tank
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_SIMG1_InsLevMin_stVal,
										g_pData->motor.bin_input.value.bit_s.min_fuel_lvl);
*/
	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDMotorIO_SIMG1_InsLevMin_t,
										g_pData->motor.bin_input.timestamp);
/*
	//motor start
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_LPHD1_PwrUp_stVal,
										g_pData->motor.bin_input.value.bit_s.motor_on);
*/
	IedServer_updateUTCTimeAttributeValue(server,
										 IEDMODEL_LDMotorIO_LPHD1_PwrDn_t,
										 g_pData->motor.bin_input.timestamp);
/*
	//motor stop
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_LPHD1_PwrDn_stVal,
										g_pData->motor.bin_input.value.bit_s.motor_off);
*/
	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDMotorIO_LPHD1_PwrDn_t,
										g_pData->motor.bin_input.timestamp);
/*
	//12v charge ok
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_GGIO1_Alm1_stVal,
										g_pData->motor.bin_input.value.bit_s.battery_charging);
*/
	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDMotorIO_GGIO2_Alm1_t,
										g_pData->motor.bin_input.timestamp);
/*
	//oilpressure ok
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_GGIO2_Alm1_stVal,
										g_pData->motor.bin_input.value.bit_s.oil_pressure_OK);
*/
	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDMotorIO_GGIO2_Alm1_t,
										g_pData->motor.bin_input.timestamp);
/*
	//emergency stop
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_GGIO3_Alm1_stVal,
										g_pData->motor.bin_input.value.bit_s.emergency_stop);
*/
	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDMotorIO_GGIO3_Alm1_t,
										g_pData->motor.bin_input.timestamp);
/*
	//turn on annealing
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_GGIO4_Alm1_stVal,
										g_pData->motor.bin_input.value.bit_s.annealing_ON);
*/
	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDMotorIO_GGIO4_Alm1_t,
										g_pData->motor.bin_input.timestamp);

	//crankshaft RPM
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_TRTN1_RotSpdSv_instMag_f,
										g_pData->motor.crankShaft_rpm.value);

	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDMotorIO_TRTN1_RotSpdSv_t,
										g_pData->motor.crankShaft_rpm.timestamp);

	//Fuel/going flow
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_TFLW1_FlwSv_instMag_f,
										g_pData->motor.fuel_in.value);

	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDMotorIO_TFLW1_FlwSv_t,
										g_pData->motor.fuel_in.timestamp);

	//Fuel/return flow
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_TFLW2_FlwSv_instMag_f,
										g_pData->motor.fuel_return.value);

	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDMotorIO_TFLW2_FlwSv_t,
										g_pData->motor.fuel_return.timestamp);

	//Suction channel flow
	IedServer_updateFloatAttributeValue(server,
										IEDMODEL_LDMotorIO_TFLW3_FlwSv_instMag_f,
										g_pData->motor.suction_flow.value);

	IedServer_updateUTCTimeAttributeValue(server,
										IEDMODEL_LDMotorIO_TFLW3_FlwSv_t,
										g_pData->motor.suction_flow.timestamp);


	sem_post(&g_DataUpdt_Lock_mutex);

}

void* motor_control_srvc(void *arg)
{
	float result = 0.0;		// thread return value
	int run = 1;

	g_pData  = (server_data_st *)arg;

	printf("motor_control_srvc() running \r\n");


	initIECServer(&server_readData, &server_writeData, run);


	while(1)
	{

		/* Transmit the values */
		//transmit_measures(MOTOR_SENSORS, (void *)&real);
		/* END: store the values protecting with a semaphore*/


		g_key = getkey();
		if(g_key == 's'){
			printf("\n's' KEY PRESSED\nExiting server routine... \r\n");
			pthread_exit(&result);
		}
		usleep(1000000);

	}

	return NULL;
}


