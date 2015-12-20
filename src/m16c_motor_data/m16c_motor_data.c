/*
 * m16_motor_data.c
 *
 *  Created on: Feb 18, 2015
 *      Author: Luis and Juhanni
 */


#include "../main.h"
#include "../../pi_m16c_spi/sensors.h"

#define 	MOTOR_TASK_PID		0x4A9EBC88

extern sem_t 	g_DataUpdt_Lock_mutex;
extern uint8_t g_key;

void* reading_motor(void *arg)
{
	tx_MC_data_u data;
	MC_real_values_st real;
	int8_t err = 0;
	float result = 0.0;		// thread return value

	printf("reading_motor() running \r\n");

	server_data_st *pData  = (server_data_st *)arg;
	mc_data_st mc_data;

	/*  Initialize the bcm2835 library for GPIO acces */
	if (!PI_BCM_CheckInitialized())
	{
		PI_BCM_Init();
	}

	/* Open Raspberry hardware SPI channel to communicate with ADE7880 */
	if (!PI_SPI_CheckInitialized())
	{
		PI_SPI_Init(BCM2835_SPI_BIT_ORDER_MSBFIRST, BCM2835_SPI_MODE3,
				M16C_SPI_CLOCK_SPEED, LOW, M16C_SPI_CHANNEL);
	}


	while(g_key != 'm')
	{
#ifdef DEBUG
		printf("Start next reading from motor sensors\r\n");
#endif
		/* Proceed to read from M16C */
		if ((err = M16C_SPI_read_all(&data, MOTOR_TASK_PID)) != 0)
		{
			printf("\nCMD ERROR in reading_motor(): returned err: %d\r\n", err);
			usleep(10000);
			continue;
		}


		
		// Check transmission errors, the initial sent command can be read back in cmd_addr value, if it does not match, there is an error
		// Moreover, regarding the buffer content, ADC registers are 10 bit, any value not in 0-1023 range means data got corrupted
		if(data.value.cmd_addr != M16C_READ_CMD)
		{
#ifdef DEBUG
			printf("Received command = %02x\r\nDiscarding values...\r\n", data.value.cmd_addr);
#endif
			usleep(10000);
			continue;
		}		

#ifdef DEBUG
		printf("After conversion Len of data.str = %u\r\n", sizeof(data.str));
		uint8_t i = 0;
		for(i=0; i<sizeof(data.str); i++)
		printf("%02X", data.str[i]);

		printf("\r\n");
#endif

		// Check if the returned value is in a valid range
		real.cmd_addr = data.value.cmd_addr;

		if(data.value.torque < MAX_STEP_ADC_10BIT)
		{// If it is proceed to record value and timestamp
			//Convert to real values
			convert_to_real(MC_TORQUE_ADDR,  &data,  &real);
			mc_data.torque.value = real.torque;
			mc_data.torque.timestamp = Hal_getTimeInMs();
		}
		else
		{// If not, keep previous value and timestamp
			mc_data.torque.value = pData->motor.torque.value;
			mc_data.torque.timestamp = pData->motor.torque.timestamp;
		}
		// Repeat the process for all the readings
		if(data.value.suction_temp < MAX_STEP_ADC_10BIT)
		{
			convert_to_real(MC_SUCTION_TEMP_ADDR,  &data,  &real);
			mc_data.suction_temp.value = real.suction_temp;
			mc_data.suction_temp.timestamp = Hal_getTimeInMs();
		}
		else
		{
			mc_data.suction_temp.value = pData->motor.suction_temp.value;
			mc_data.suction_temp.timestamp = pData->motor.suction_temp.timestamp;
		}

		if(data.value.coolant_in_temp < MAX_STEP_ADC_10BIT)
		{
			convert_to_real(MC_COOLANT_GOING_TEMP_ADDR,  &data,  &real);
			mc_data.coolant_in_temp.value = real.coolant_in_temp;
			mc_data.coolant_in_temp.timestamp = Hal_getTimeInMs();
		}
		else
		{
			mc_data.coolant_in_temp.value = pData->motor.coolant_in_temp.value;
			mc_data.coolant_in_temp.timestamp = pData->motor.coolant_in_temp.timestamp;
		}

		if(data.value.coolant_return_temp < MAX_STEP_ADC_10BIT)
		{
			convert_to_real(MC_COOLANT_RETURN_TEMP_ADDR,  &data,  &real);
			mc_data.coolant_return_temp.value = real.coolant_return_temp;
			mc_data.coolant_return_temp.timestamp = Hal_getTimeInMs();
		}
		else
		{
			mc_data.coolant_return_temp.value = pData->motor.coolant_return_temp.value;
			mc_data.coolant_return_temp.timestamp = pData->motor.coolant_return_temp.timestamp;
		}

		if(data.value.block_temp < MAX_STEP_ADC_10BIT)
		{
			convert_to_real(MC_ENGINE_BLOCK_TEMP_ADDR,  &data,  &real);
			mc_data.block_temp.value = real.block_temp;
			mc_data.block_temp.timestamp = Hal_getTimeInMs();
		}
		else
		{
			mc_data.block_temp.value = pData->motor.block_temp.value;
			mc_data.block_temp.timestamp = pData->motor.block_temp.timestamp;
		}

		if(data.value.exhaust_temp < MAX_STEP_ADC_10BIT)
		{
			convert_to_real(MC_EXHAUST_TEMP_ADDR,  &data,  &real);
			mc_data.exhaust_temp.value = real.exhaust_temp;
			mc_data.exhaust_temp.timestamp = Hal_getTimeInMs();
		}
		else
		{
			mc_data.exhaust_temp.value = pData->motor.exhaust_temp.value;
			mc_data.exhaust_temp.timestamp = pData->motor.exhaust_temp.timestamp;
		}

		if(data.value.oil_temp < MAX_STEP_ADC_10BIT)
		{
			convert_to_real(MC_OIL_TEMP_ADDR,  &data,  &real);
			mc_data.oil_temp.value = real.oil_temp;
			mc_data.oil_temp.timestamp = Hal_getTimeInMs();
		}
		else
		{
			mc_data.oil_temp.value = pData->motor.oil_temp.value;
			mc_data.oil_temp.timestamp = pData->motor.oil_temp.timestamp;
		}


		if(data.value.crankShaft_rpm < 300000)
		{
			convert_to_real(MC_CRANKSHAFT_RPM_ADDR,  &data,  &real);
			mc_data.crankShaft_rpm.value = real.crankShaft_rpm;
			mc_data.crankShaft_rpm.timestamp = Hal_getTimeInMs();
		}
		else
		{
			mc_data.crankShaft_rpm.value = pData->motor.crankShaft_rpm.value;
			mc_data.crankShaft_rpm.timestamp = pData->motor.crankShaft_rpm.timestamp;
		}

		if(data.value.fuel_in < 1700000)
		{
			convert_to_real(MC_FUEL_GOING_ADDR,  &data,  &real);
			mc_data.fuel_in.value = real.fuel_in;
			mc_data.fuel_in.timestamp = Hal_getTimeInMs();
		}
		else
		{
			mc_data.fuel_in.value = pData->motor.fuel_in.value;
			mc_data.fuel_in.timestamp = pData->motor.fuel_in.timestamp;
		}

		if(data.value.fuel_return < 1700000)
		{
			convert_to_real(MC_FUEL_RETURN_ADDR,  &data,  &real);
			mc_data.fuel_return.value = real.fuel_return;
			mc_data.fuel_return.timestamp = Hal_getTimeInMs();
		}
		else
		{
			mc_data.fuel_return.value = pData->motor.fuel_return.value;
			mc_data.fuel_return.timestamp = pData->motor.fuel_return.timestamp;
		}

		if(data.value.suction_flow < 1700000)
		{
			convert_to_real(MC_SUCTION_FLOW_ADDR,  &data,  &real);
			mc_data.suction_flow.value = real.suction_flow;
			mc_data.suction_flow.timestamp = Hal_getTimeInMs();
		}
		else
		{
			mc_data.suction_flow.value = pData->motor.suction_flow.value;
			mc_data.suction_flow.timestamp = pData->motor.suction_flow.timestamp;
		}

		if(data.value.bin_input.bin_all < 256)
		{
			convert_to_real(MC_BIN_INPUT_1,  &data,  &real);
			mc_data.bin_input.value.bin_all = real.bin_input.bin_all;
			mc_data.bin_input.timestamp = Hal_getTimeInMs();
		}
		else
		{
			mc_data.bin_input.value.bin_all = pData->motor.bin_input.value.bin_all;
			mc_data.bin_input.timestamp = pData->motor.bin_input.timestamp;
		}

		sem_wait(&g_DataUpdt_Lock_mutex);

			pData->motor = mc_data;

		sem_post(&g_DataUpdt_Lock_mutex);

		/* Transmit the values */
		transmit_measures(MOTOR_SENSORS_REAL, (void *)&real);
		//transmit_measures(MOTOR_SENSORS_INT, (void *)&data.value);


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

uint32_t g_crankShaft_rpm[SAMPLES_NUM] = {0};
uint32_t g_fuel_in[SAMPLES_NUM] = {0};
uint32_t g_fuel_return[SAMPLES_NUM] = {0};
uint32_t g_suction_flow[SAMPLES_NUM] = {0};

int8_t convert_to_real(uint8_t sensor, tx_MC_data_u *data, MC_real_values_st *real)
{
	int8_t 		ret = 0;


	switch(sensor){

		case MC_REGISTERS_ALL:
			// After a transmission is complete cmd_addr holds the cmd sent at the beggining of the transmission
			real->cmd_addr = data->value.cmd_addr;
			// Convert 10 bit ADC values
			real->suction_temp = (10.0/1023.0) * (float)(data->value.suction_temp);
			real->coolant_in_temp = (150.0/1023.0) * (float)(data->value.coolant_in_temp);
			real->coolant_return_temp = (150.0/1023.0) * (float)(data->value.coolant_return_temp);
			real->block_temp = (150.0/1023.0) * (float)(data->value.block_temp);
			real->exhaust_temp = (150.0/1023.0) * (float)(data->value.exhaust_temp);
			real->oil_temp = (150.0/1023.0) * (float)(data->value.oil_temp);
			// Convert Pulse period measurements and take the average of the previous readings
			real->crankShaft_rpm = RPM((float)pulse_avg(data->value.crankShaft_rpm, g_crankShaft_rpm));  // 1 RPM = 60Hz * 4 PPRev measured using 24Mz clock

			real->fuel_in = FLOW_LITRES_MIN( pulse_avg(data->value.fuel_in, g_fuel_in));
			real->fuel_return = FLOW_LITRES_MIN( pulse_avg(data->value.fuel_return, g_fuel_return));
			real->suction_flow = FLOW_LITRES_MIN( pulse_avg(data->value.suction_flow, g_suction_flow));

			real->bin_input.bin_all = data->value.bin_input.bin_all;
		break;

		case MC_TORQUE_ADDR:
			real->torque = (10.0/1023.0) * (float)data->value.torque;
		break;
		case MC_SUCTION_TEMP_ADDR:
			real->suction_temp = (10.0/1023.0) * (float)(data->value.suction_temp);
		break;
		case MC_COOLANT_GOING_TEMP_ADDR:
			real->coolant_in_temp = (150.0/1023.0) * (float)(data->value.coolant_in_temp);
		break;
		case MC_COOLANT_RETURN_TEMP_ADDR:
			real->coolant_return_temp = (150.0/1023.0) * (float)(data->value.coolant_return_temp);
		break;
		case MC_ENGINE_BLOCK_TEMP_ADDR:
			real->block_temp = (150.0/1023.0) * (float)(data->value.block_temp);
		break;
		case MC_EXHAUST_TEMP_ADDR:
			real->exhaust_temp = (150.0/1023.0) * (float)(data->value.exhaust_temp);
		break;
		case MC_OIL_TEMP_ADDR:
			real->oil_temp = (150.0/1023.0) * (float)(data->value.oil_temp);
		break;
		case MC_CRANKSHAFT_RPM_ADDR:
			real->crankShaft_rpm = RPM((float)pulse_avg((float)data->value.crankShaft_rpm, g_crankShaft_rpm));
		break;
		case MC_FUEL_GOING_ADDR:
			real->fuel_in = FLOW_LITRES_MIN( pulse_avg(data->value.fuel_in, g_fuel_in));
		break;

		case MC_FUEL_RETURN_ADDR:
			real->fuel_return = FLOW_LITRES_MIN( pulse_avg(data->value.fuel_return, g_fuel_return));
		break;
		case MC_SUCTION_FLOW_ADDR:
			real->suction_flow = FLOW_LITRES_MIN( pulse_avg(data->value.suction_flow, g_suction_flow));
		break;
		case MC_BIN_INPUT_1:
			real->bin_input.bin_all = data->value.bin_input.bin_all;
		break;
		default:
			printf("Error in convert to real, parameter not found\r\n");
		break;

	}


	/* Return error */
	return ret;

}

uint32_t pulse_avg(uint32_t lastPulse, uint32_t *pulseArray)
{
	int32_t g_sum = 0;
	uint8_t 	i = 0;

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
