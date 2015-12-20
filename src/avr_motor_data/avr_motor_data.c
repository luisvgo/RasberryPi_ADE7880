/*
 * avr_motor_data.c
 *
 *  Created on: March 11, 2015
 *      Author: Luis and Juhanni
 */


#include "../main.h"
#include "../../pi_avr_spi/avr_sensors.h"

#define 	AVR_TASK_PID		0x0A0EB333

extern sem_t 	g_DataUpdt_Lock_mutex;
extern uint8_t 	g_key;

void* reading_motor_avr(void *arg)
{
	/*********************************************************************************
	 * TODO: this code has not been tested properly. AVR implementation finished in the last minute
	 * for that reason range output of the values has to be adjusted
	 * for the same reason Convert_to_real is not correctly implemented
	 * finally TEST it! but AVR implementation has proven inefficient and quite buggy
	 */
	int8_t err = 0;
	uint8_t ii = 0;
	float result = 0.0;		// thread return value
	uint8_t mosi[3];
	tx_MC_data_u avr_data;
	mc_data_st avr_mc_data;
	MC_real_values_st avr_real;

	avr_measurement avr_meas[13] =  {
									{ MC_TORQUE_HIGH_ADDR, 0 },
									{ MC_SUCTION_TEMP_HIGH_ADDR, 0 },
									{ MC_COOLANT_GOING_TEMP_HIGH_ADDR, 0 },
									{ MC_COOLANT_RETURN_TEMP_HIGH_ADDR, 0 },
									{ MC_ENGINE_BLOCK_TEMP_HIGH_ADDR, 0 },
									{ MC_EXHAUST_TEMP_HIGH_ADDR, 0 },
									{ MC_OIL_TEMP_HIGH_ADDR, 0 },
									{ MC_CRANKSHAFT_RPM_HIGH_ADDR, 0 },
									{ MC_FUEL_GOING_HIGH_ADDR, 0 },
									{ MC_FUEL_RETURN_HIGH_ADDR, 0 },
									{ MC_SUCTION_FLOW_HIGH_ADDR, 0 },
									{ MC_AVR_BIN_INPUT_1, 0 }
									};

	printf("reading_motor() running \r\n");

	server_data_st *pAvr  = (server_data_st *)arg;


	/*  Initialize the bcm2835 library for GPIO acces */
	if (!PI_BCM_CheckInitialized())
	{
		PI_BCM_Init();
	}

	/* Open Raspberry hardware SPI channel to communicate with ADE7880 */
	if (!PI_SPI_CheckInitialized())
	{
		PI_SPI_Init(BCM2835_SPI_BIT_ORDER_MSBFIRST, BCM2835_SPI_MODE3,
				ATMEGA_SPI_CLOCKSPEED, LOW, ATMEGA_SPI_CHANNEL);
	}


	while(g_key != 'a')
	{

#ifdef DEBUG
		printf("Start next reading from motor sensors\r\n");
#endif
		/* Proceed to read from AVR */
		for(ii = 0; ii < 12; ii++)
		{
			mosi[0] = avr_meas[ii].int_addr;
			mosi[1] = 0;
			mosi[2] = 0;

			if ((err = PI_AVR_SPI_read(mosi, 3, AVR_TASK_PID)) != 0)
			{
				printf("\nCMD ERROR in reading_motor(): returned err: %d\r\n", err);
				usleep(20000);
				continue;
			}

#ifdef DEBUG
			printf("read sensor %d: %d\n", ii, avr_meas[ii].int_addr, mosi[2] << 8 | mosi[1]);
#endif
			avr_meas[ii].value = mosi[2] << 8 | mosi[1];
			usleep(5000);
		}

		avr_data.value.torque = avr_meas[0].value;
		avr_data.value.suction_temp = avr_meas[1].value;
		avr_data.value.coolant_in_temp = avr_meas[2].value;
		avr_data.value.coolant_return_temp = avr_meas[3].value;
		avr_data.value.block_temp = avr_meas[4].value;
		avr_data.value.exhaust_temp = avr_meas[5].value;
		avr_data.value.oil_temp = avr_meas[6].value;
		avr_data.value.crankShaft_rpm = avr_meas[7].value;
		avr_data.value.fuel_in = avr_meas[8].value;
		avr_data.value.fuel_return = avr_meas[9].value;
		avr_data.value.suction_flow = avr_meas[10].value;
		avr_data.value.bin_input.bin_all = avr_meas[10].value;

		/******************************************************************
		 * The ADC are 10, check that the values are in range
		 */
		if(avr_data.value.torque < MAX_16BIT_VALUE)
		{// If it is proceed to record value and timestamp
			//Convert to real values
			convert_to_real(MC_TORQUE_LOW_ADDR,  &avr_data,  &avr_real);
			avr_mc_data.torque.value = avr_real.torque;
			avr_mc_data.torque.timestamp = Hal_getTimeInMs();
		}
		else
		{// If not, keep previous value and timestamp
			avr_mc_data.torque.value = pAvr->motor.torque.value;
			avr_mc_data.torque.timestamp = pAvr->motor.torque.timestamp;
		}

		// Repeat the process for all the readings
		if(avr_data.value.suction_temp < MAX_16BIT_VALUE)
		{
			convert_to_real(MC_SUCTION_TEMP_LOW_ADDR,  &avr_data,  &avr_real);
			avr_mc_data.suction_temp.value = avr_real.suction_temp;
			avr_mc_data.suction_temp.timestamp = Hal_getTimeInMs();
		}
		else
		{
			avr_mc_data.suction_temp.value = pAvr->motor.suction_temp.value;
			avr_mc_data.suction_temp.timestamp = pAvr->motor.suction_temp.timestamp;
		}

		if(avr_data.value.coolant_in_temp < MAX_16BIT_VALUE)
		{
			convert_to_real(MC_COOLANT_GOING_TEMP_LOW_ADDR,  &avr_data,  &avr_real);
			avr_mc_data.coolant_in_temp.value = avr_real.coolant_in_temp;
			avr_mc_data.coolant_in_temp.timestamp = Hal_getTimeInMs();
		}
		else
		{
			avr_mc_data.coolant_in_temp.value = pAvr->motor.coolant_in_temp.value;
			avr_mc_data.coolant_in_temp.timestamp = pAvr->motor.coolant_in_temp.timestamp;
		}

		if(avr_data.value.coolant_return_temp < MAX_16BIT_VALUE)
		{
			convert_to_real(MC_COOLANT_RETURN_TEMP_LOW_ADDR,  &avr_data,  &avr_real);
			avr_mc_data.coolant_return_temp.value = avr_real.coolant_return_temp;
			avr_mc_data.coolant_return_temp.timestamp = Hal_getTimeInMs();
		}
		else
		{
			avr_mc_data.coolant_return_temp.value = pAvr->motor.coolant_return_temp.value;
			avr_mc_data.coolant_return_temp.timestamp = pAvr->motor.coolant_return_temp.timestamp;
		}

		if(avr_data.value.block_temp < MAX_16BIT_VALUE)
		{
			convert_to_real(MC_ENGINE_BLOCK_TEMP_LOW_ADDR,  &avr_data,  &avr_real);
			avr_mc_data.block_temp.value = avr_real.block_temp;
			avr_mc_data.block_temp.timestamp = Hal_getTimeInMs();
		}
		else
		{
			avr_mc_data.block_temp.value = pAvr->motor.block_temp.value;
			avr_mc_data.block_temp.timestamp = pAvr->motor.block_temp.timestamp;
		}

		if(avr_data.value.exhaust_temp < MAX_16BIT_VALUE)
		{
			convert_to_real(MC_EXHAUST_TEMP_LOW_ADDR,  &avr_data,  &avr_real);
			avr_mc_data.exhaust_temp.value = avr_real.exhaust_temp;
			avr_mc_data.exhaust_temp.timestamp = Hal_getTimeInMs();
		}
		else
		{
			avr_mc_data.exhaust_temp.value = pAvr->motor.exhaust_temp.value;
			avr_mc_data.exhaust_temp.timestamp = pAvr->motor.exhaust_temp.timestamp;
		}

		if(avr_data.value.oil_temp < MAX_16BIT_VALUE)
		{
			convert_to_real(MC_OIL_TEMP_LOW_ADDR,  &avr_data,  &avr_real);
			avr_mc_data.oil_temp.value = avr_real.oil_temp;
			avr_mc_data.oil_temp.timestamp = Hal_getTimeInMs();
		}
		else
		{
			avr_mc_data.oil_temp.value = pAvr->motor.oil_temp.value;
			avr_mc_data.oil_temp.timestamp = pAvr->motor.oil_temp.timestamp;
		}


		if(avr_data.value.crankShaft_rpm < 300000)
		{
			convert_to_real(MC_CRANKSHAFT_RPM_LOW_ADDR,  &avr_data,  &avr_real);
			avr_mc_data.crankShaft_rpm.value = avr_real.crankShaft_rpm;
			avr_mc_data.crankShaft_rpm.timestamp = Hal_getTimeInMs();
		}
		else
		{
			avr_mc_data.crankShaft_rpm.value = pAvr->motor.crankShaft_rpm.value;
			avr_mc_data.crankShaft_rpm.timestamp = pAvr->motor.crankShaft_rpm.timestamp;
		}

		if(avr_data.value.fuel_in < 1700000)
		{
			convert_to_real(MC_FUEL_GOING_LOW_ADDR,  &avr_data,  &avr_real);
			avr_mc_data.fuel_in.value = avr_real.fuel_in;
			avr_mc_data.fuel_in.timestamp = Hal_getTimeInMs();
		}
		else
		{
			avr_mc_data.fuel_in.value = pAvr->motor.fuel_in.value;
			avr_mc_data.fuel_in.timestamp = pAvr->motor.fuel_in.timestamp;
		}

		if(avr_data.value.fuel_return < 1700000)
		{
			convert_to_real(MC_FUEL_RETURN_LOW_ADDR,  &avr_data,  &avr_real);
			avr_mc_data.fuel_return.value = avr_real.fuel_return;
			avr_mc_data.fuel_return.timestamp = Hal_getTimeInMs();
		}
		else
		{
			avr_mc_data.fuel_return.value = pAvr->motor.fuel_return.value;
			avr_mc_data.fuel_return.timestamp = pAvr->motor.fuel_return.timestamp;
		}

		if(avr_data.value.suction_flow < 1700000)
		{
			convert_to_real(MC_SUCTION_FLOW_LOW_ADDR,  &avr_data,  &avr_real);
			avr_mc_data.suction_flow.value = avr_real.suction_flow;
			avr_mc_data.suction_flow.timestamp = Hal_getTimeInMs();
		}
		else
		{
			avr_mc_data.suction_flow.value = pAvr->motor.suction_flow.value;
			avr_mc_data.suction_flow.timestamp = pAvr->motor.suction_flow.timestamp;
		}

		if(avr_data.value.bin_input.bin_all < 256)
		{
			convert_to_real(MC_AVR_BIN_INPUT_1,  &avr_data,  &avr_real);
			avr_mc_data.bin_input.value.bin_all = avr_real.bin_input.bin_all;
			avr_mc_data.bin_input.timestamp = Hal_getTimeInMs();
		}
		else
		{
			avr_mc_data.bin_input.value.bin_all = pAvr->motor.bin_input.value.bin_all;
			avr_mc_data.bin_input.timestamp = pAvr->motor.bin_input.timestamp;
		}

		sem_wait(&g_DataUpdt_Lock_mutex);

			pAvr->motor = avr_mc_data;

		sem_post(&g_DataUpdt_Lock_mutex);

		/* Transmit the values */
		transmit_measures(MOTOR_SENSORS_REAL, (void *)&avr_real);
		transmit_measures(MOTOR_SENSORS_INT, (void *)&avr_data.value);


		g_key = getkey();
		if(g_key == 'm'){
			printf("\n'm' KEY PRESSED\nExiting motor routine... \r\n");
			pthread_exit(&result);
		}
		usleep(20000);

	}

	return NULL;
}


/*! ******************************************************************************************************************
 * \brief  M16C_SPI_convert_to_real
 *
 *******************************************************************************************************************/

uint32_t g_crankShaft_rpm_avr[SAMPLES_NUM] = {0};
uint32_t g_fuel_in_avr[SAMPLES_NUM] = {0};
uint32_t g_fuel_return_avr[SAMPLES_NUM] = {0};
uint32_t g_suction_flow_avr[SAMPLES_NUM] = {0};

int8_t convert_to_real_avr(uint8_t sensor, tx_MC_data_u *data, MC_real_values_st *real)
{
	int8_t 		ret = 0;

	switch(sensor){

		case MC_AVR_REGISTERS_ALL:
			// After a transmission is complete cmd_addr holds the cmd sent at the beggining of the transmission
			real->cmd_addr = data->value.cmd_addr;
			// Convert 10 bit ADC values
			real->suction_temp = (10.0/ADC_MAX_VALUE) * (float)(data->value.suction_temp);
			real->coolant_in_temp = (150.0/ADC_MAX_VALUE) * (float)(data->value.coolant_in_temp);
			real->coolant_return_temp = (150.0/ADC_MAX_VALUE) * (float)(data->value.coolant_return_temp);
			real->block_temp = (150.0/ADC_MAX_VALUE) * (float)(data->value.block_temp);
			real->exhaust_temp = (150.0/ADC_MAX_VALUE) * (float)(data->value.exhaust_temp);
			real->oil_temp = (150.0/ADC_MAX_VALUE) * (float)(data->value.oil_temp);
			// Convert Pulse period measurements and take the average of the previous readings
			real->crankShaft_rpm = RPM((float)pulse_avg(data->value.crankShaft_rpm, g_crankShaft_rpm_avr));  // 1 RPM = 60Hz * 4 PPRev measured using 24Mz clock

			real->fuel_in = FLOW_LITRES_MIN( pulse_avg(data->value.fuel_in, g_fuel_in_avr));
			real->fuel_return = FLOW_LITRES_MIN( pulse_avg(data->value.fuel_return, g_fuel_return_avr));
			real->suction_flow = FLOW_LITRES_MIN( pulse_avg(data->value.suction_flow, g_suction_flow_avr));

			real->bin_input.bin_all = data->value.bin_input.bin_all;
		break;

		case MC_TORQUE_LOW_ADDR:
			real->torque = (10.0/ADC_MAX_VALUE) * (float)data->value.torque;
		break;
		case MC_SUCTION_TEMP_LOW_ADDR:
			real->suction_temp = (10.0/ADC_MAX_VALUE) * (float)(data->value.suction_temp);
		break;
		case MC_COOLANT_GOING_TEMP_LOW_ADDR:
			real->coolant_in_temp = (150.0/ADC_MAX_VALUE) * (float)(data->value.coolant_in_temp);
		break;
		case MC_COOLANT_RETURN_TEMP_LOW_ADDR:
			real->coolant_return_temp = (150.0/ADC_MAX_VALUE) * (float)(data->value.coolant_return_temp);
		break;
		case MC_ENGINE_BLOCK_TEMP_LOW_ADDR:
			real->block_temp = (150.0/ADC_MAX_VALUE) * (float)(data->value.block_temp);
		break;
		case MC_EXHAUST_TEMP_LOW_ADDR:
			real->exhaust_temp = (150.0/ADC_MAX_VALUE) * (float)(data->value.exhaust_temp);
		break;
		case MC_OIL_TEMP_LOW_ADDR:
			real->oil_temp = (150.0/ADC_MAX_VALUE) * (float)(data->value.oil_temp);
		break;
		case MC_CRANKSHAFT_RPM_LOW_ADDR:
			real->crankShaft_rpm = RPM((float)pulse_avg((float)data->value.crankShaft_rpm, g_crankShaft_rpm_avr));
		break;
		case MC_FUEL_GOING_LOW_ADDR:
			real->fuel_in = FLOW_LITRES_MIN( pulse_avg(data->value.fuel_in, g_fuel_in_avr));
		break;

		case MC_FUEL_RETURN_LOW_ADDR:
			real->fuel_return = FLOW_LITRES_MIN( pulse_avg(data->value.fuel_return, g_fuel_return_avr));
		break;
		case MC_SUCTION_FLOW_LOW_ADDR:
			real->suction_flow = FLOW_LITRES_MIN( pulse_avg(data->value.suction_flow, g_suction_flow_avr));
		break;
		case MC_AVR_BIN_INPUT_1:
			real->bin_input.bin_all = data->value.bin_input.bin_all;
		break;
		default:
			printf("Error in convert to real, parameter not found\r\n");
		break;

	}


	/* Return error */
	return ret;

}

uint32_t avr_pulse_avg(uint32_t lastPulse, uint32_t *pulseArray)
{
	int32_t g_sum = 0;
	uint8_t i = 0;

	for(i = 0; i< SAMPLES_NUM; i++)
	{
		if(i==0)
		{
			pulseArray[i] = lastPulse;
		}

		g_sum = g_sum + pulseArray[i];
	}

	g_sum = g_sum / SAMPLES_NUM;

	for(i=SAMPLES_NUM-1; i>0; i--)
	{
		pulseArray[i] = pulseArray[i-1];
	}

	return g_sum;
}


/*******************************************************************************************************************
 * END of M16C_SPI_convert_to_real()
 ******************************************************************************************************************/
