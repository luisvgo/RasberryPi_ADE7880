/*
 * energyMeter.c
 *
 *  Created on: Feb 13, 2015
 *      Author: Luis
 */




#include "../main.h"


#ifndef LOW
#define LOW
#endif
#ifndef ENABLE
#define ENABLE	1
#endif

extern sem_t 	g_DataUpdt_Lock_mutex;
extern uint8_t g_key;

void* reading_energy(void *arg)
{
	float result = 0.0;
	uint8_t err = 0;		// return value
	em_data_t data; 	// g_data holds the measurements

	server_data_st *pData  = (server_data_st *)arg;

	printf("reading_energy() running \r\n");

	/*  Initialize the bcm2835 library for GPIO acces */
	if (!PI_BCM_CheckInitialized())
	{
		PI_BCM_Init();
	}

	/* Initialize output pins as gpio */
	PI_ADE_GPIO_pin_initialize();

	/* Open Raspberry hardware SPI channel to communicate with ADE7880 */
	if (!PI_SPI_CheckInitialized())
	{
		PI_SPI_Init(BCM2835_SPI_BIT_ORDER_MSBFIRST, BCM2835_SPI_MODE3,
				BCM2835_SPI_CLOCK_DIVIDER_2048, LOW, BCM2835_SPI_CS0);
	}

	/* Set the ADE7880 driver callbacks to hoock the Raspberry PI_ADE7880 middware */
	PI_ADE_ADE7880_driverCallbacks();

	delay(100);

	/* Example of ADE7880 power up procedure step by step setting SPI as communications protocol */
	err = PI_ADE_power_up_procedure();
	if (err != ADE_NO_ERROR)
	{
		printf("Error num: %d \r\n", err);
		printf("error in main -->  R_ADE_power_up_procedure() \r\n");
		printf("Exiting the program now...");
		pthread_exit(&err);
	}

	/* Start SPI communications and lock it */
	if ((err = ADE_command_handler(ENERGY_APP_PID, ADE7880_SPI_COMM_LOCK, NO_ARGS)) != ADE_NO_ERROR)
	{
		printf("Error num: %d \r\n", err);
		pthread_exit(&err);
	}

	/* HARDWARE INITIALIZATION FINISHED, ADE7880 CONFIG START */
	printf("HARDWARE INITIALIZATION FINISHED, ADE7880 CONFIG START\r\n");

	/******
	 * At this point ADE7880 is up and running listening SPI communications ---
	 * Next, configure ADE7880 registers for common register for energy measurements
	 */
	/* Configure the ADE7880 as an energy meter */
	if ((err = ADE_command_handler(ENERGY_APP_PID, QUICK_SETUP_AS_ENERGY_METER,  DEFAULT_ARGS)) != ADE_NO_ERROR)
	{
		printf("Error num: %d \r\n", err);
		pthread_exit(&err);
	}


	/* Configure ADE7880 registers for harmonics measurements over the neutral line */
/*	if ((err = ADE_command_handler(ENERGY_APP_PID, HARMONICS_INIT, 1, NEUTRAL_LINE)) != ADE_NO_ERROR)
	{
		printf("Error num: %d \r\n", err);
		printf("error in energy thread -->  ADE_command_handler(HARMONICS_INIT, 1, NEUTRAL_LINE)\r\n");
		printf("Exiting the thread now... \r\n");
		pthread_exit(&err);
	}
*/
	/* Turn ON the DSP */
	if ((err = ADE_command_handler(ENERGY_APP_PID, DSP_RUN, 1, ENABLE)) != ADE_NO_ERROR)
	{
		printf("Error num: %d \r\n", err);
		printf("error in energy thread -->  ADE_command_handler(DSP_RUN, NO_ARGS) \r\n");
		pthread_exit(&err);
	}

	/* Delay 750ms, wait for registers to settle */
	delay(750);

	while(1)
	{
#ifdef DEBUG
		printf("Start reading from energy meter\r\n");
#endif
		/* Proceed to read ADE7880 registers one by one */
		/* PHASE A */
		if ((err = ADE_measure(ENERGY_APP_PID, PHASE_IRMS, PHASE_A, NUMBER_OF_SAMPLES, &result)) == 0)
		{
			data.phase_a.IRMS.value = result;
			data.phase_a.IRMS.timestamp = Hal_getTimeInMs();
		}
		else
		{ 	// In case of error keep the previous value and timestamp
			data.phase_a.IRMS.value = pData->energy.phase_a.IRMS.value;//-1; //measure(command, register, number of readings)
			data.phase_a.IRMS.timestamp = pData->energy.phase_a.IRMS.timestamp; // = error timestamp
			printf("\nCMD ERROR in reading_energy(): ADE_measure(PHASE_IRMS, PHASE_A) returned err: %d\r\n", err);
		}

		if ((err= ADE_measure(ENERGY_APP_PID, PHASE_ACTIVE_POWER, PHASE_A, NUMBER_OF_SAMPLES, &result)) == 0)
		{
			data.phase_a.POWER.value  = result;
			data.phase_a.POWER.timestamp = Hal_getTimeInMs();
		}
		else{
			data.phase_a.POWER.value  = pData->energy.phase_a.POWER.value; //measure(command, register, number of readings)
			data.phase_a.POWER.timestamp = pData->energy.phase_a.POWER.timestamp;
			printf("\nCMD ERROR in reading_energy(): ADE_measure(PHASE_ACTIVE_POWER, PHASE_A) returned err: %d\r\n", err);
		}

		if ((err = ADE_measure(ENERGY_APP_PID, PHASE_VRMS, PHASE_A, NUMBER_OF_SAMPLES, &result)) == 0)
		{
			data.phase_a.VRMS.value  = result;
			data.phase_a.VRMS.timestamp = Hal_getTimeInMs();
		}
		else{
			data.phase_a.VRMS.value  = pData->energy.phase_a.VRMS.value; //measure(command, register, number of readings)
			data.phase_a.VRMS.timestamp = pData->energy.phase_a.VRMS.timestamp;
			printf("\nCMD ERROR in reading_energy(): ADE_measure(PHASE_VRMS, PHASE_A) returned err: %d\r\n", err);
		}

		if ((err = ADE_measure(ENERGY_APP_PID, PHASE_ACTIVE_WH,	PHASE_A, NUMBER_OF_SAMPLES, &result)) == 0)
		{
			data.phase_a.WH.value  = result;
			data.phase_a.WH.timestamp = Hal_getTimeInMs();
		}
		else{
			data.phase_a.WH.value  = pData->energy.phase_a.WH.value; //measure(command, register, number of readings)
			data.phase_a.WH.timestamp = pData->energy.phase_a.WH.timestamp;
			printf("\nCMD ERROR in reading_energy(): ADE_measure(PHASE_ACTIVE_WH, PHASE_A) returned err: %d\r\n", err);
		}

		/* PHASE B */
		if ((err = ADE_measure(ENERGY_APP_PID, PHASE_IRMS, PHASE_B, NUMBER_OF_SAMPLES, &result)) == 0)
		{
			data.phase_b.IRMS.value = result;
			data.phase_b.IRMS.timestamp = Hal_getTimeInMs();
		}
		else{
			data.phase_b.IRMS.value = pData->energy.phase_b.IRMS.value; //measure(command, register, number of readings)
			data.phase_b.IRMS.timestamp = pData->energy.phase_b.IRMS.timestamp;
			printf("\nCMD ERROR in reading_energy(): ADE_measure(PHASE_IRMS, PHASE_B) returned err: %d\r\n", err);
		}

		if ((err= ADE_measure(ENERGY_APP_PID, PHASE_ACTIVE_POWER, PHASE_B, NUMBER_OF_SAMPLES, &result)) == 0)
		{
			data.phase_b.POWER.value  = result;
			data.phase_b.POWER.timestamp = Hal_getTimeInMs();
		}
		else{
			data.phase_b.POWER.value  = pData->energy.phase_b.POWER.value; //measure(command, register, number of readings)
			data.phase_b.POWER.timestamp = pData->energy.phase_b.POWER.timestamp;
			printf("\nCMD ERROR in reading_energy(): ADE_measure(PHASE_ACTIVE_POWER, PHASE_B) returned err: %d\r\n", err);
		}

		if ((err = ADE_measure(ENERGY_APP_PID, PHASE_VRMS, PHASE_B, NUMBER_OF_SAMPLES, &result)) == 0)
		{
			data.phase_b.VRMS.value  = result;
			data.phase_b.VRMS.timestamp = Hal_getTimeInMs();
		}
		else{
			data.phase_b.VRMS.value  = pData->energy.phase_b.VRMS.value; //measure(command, register, number of readings)
			data.phase_b.VRMS.timestamp = pData->energy.phase_b.VRMS.timestamp;
			printf("\nCMD ERROR in reading_energy(): ADE_measure(PHASE_VRMS, PHASE_B) returned err: %d\r\n", err);
		}

		if ((err = ADE_measure(ENERGY_APP_PID, PHASE_ACTIVE_WH,	PHASE_B, NUMBER_OF_SAMPLES, &result)) == 0)
		{
			data.phase_b.WH.value  = result;
			data.phase_b.WH.timestamp = Hal_getTimeInMs();
		}
		else{
			data.phase_b.WH.value  = pData->energy.phase_b.WH.value; //measure(command, register, number of readings)
			data.phase_b.WH.timestamp = pData->energy.phase_b.WH.timestamp;
			printf("\nCMD ERROR in reading_energy(): ADE_measure(PHASE_ACTIVE_WH, PHASE_B) returned err: %d\r\n", err);
		}
		/* PHASE C */
		if ((err = ADE_measure(ENERGY_APP_PID, PHASE_IRMS, PHASE_C, NUMBER_OF_SAMPLES, &result)) == 0)
		{
			data.phase_c.IRMS.value = result;
			data.phase_c.IRMS.timestamp = Hal_getTimeInMs();
		}
		else{
			data.phase_c.IRMS.value = pData->energy.phase_c.IRMS.value; //measure(command, register, number of readings)
			data.phase_c.IRMS.timestamp = pData->energy.phase_c.IRMS.timestamp;
			printf("\nCMD ERROR in reading_energy(): ADE_measure(PHASE_IRMS, PHASE_C) returned err: %d\r\n", err);
		}

		if ((err= ADE_measure(ENERGY_APP_PID, PHASE_ACTIVE_POWER, PHASE_C, NUMBER_OF_SAMPLES, &result)) == 0)
		{
			data.phase_c.POWER.value  = result;
			data.phase_c.POWER.timestamp = Hal_getTimeInMs();
		}
		else{
			data.phase_c.POWER.value  = pData->energy.phase_c.POWER.value; //measure(command, register, number of readings)
			data.phase_c.POWER.timestamp = pData->energy.phase_c.POWER.timestamp;
			printf("\nCMD ERROR in reading_energy(): ADE_measure(PHASE_ACTIVE_POWER, PHASE_C) returned err: %d\r\n", err);
		}

		if ((err = ADE_measure(ENERGY_APP_PID, PHASE_VRMS, PHASE_C, NUMBER_OF_SAMPLES, &result)) == 0)
		{
			data.phase_c.VRMS.value  = result;
			data.phase_c.VRMS.timestamp = Hal_getTimeInMs();
		}
		else{
			data.phase_c.VRMS.value  = pData->energy.phase_c.VRMS.value; //measure(command, register, number of readings)
			data.phase_c.VRMS.timestamp = pData->energy.phase_c.VRMS.timestamp;
			printf("\nCMD ERROR in reading_energy(): ADE_measure(PHASE_VRMS, PHASE_C) returned err: %d\r\n", err);
		}

		if ((err = ADE_measure(ENERGY_APP_PID, PHASE_ACTIVE_WH,	PHASE_C, NUMBER_OF_SAMPLES, &result)) == 0)
		{
			data.phase_c.WH.value  = result;
			data.phase_c.WH.timestamp = Hal_getTimeInMs();
		}
		else{
			data.phase_c.WH.value  = pData->energy.phase_c.WH.value; //measure(command, register, number of readings)
			data.phase_c.WH.timestamp = pData->energy.phase_c.WH.timestamp;
			printf("\nCMD ERROR in reading_energy(): ADE_measure(PHASE_ACTIVE_WH, PHASE_C) returned err: %d\r\n", err);
		}


#ifdef DEBUG
		 if(result!=-1)
		 printf("\nREADING SUCESS\n");
		 spi_enable_msg_debug_print(ENABLE);
#endif

		/* END: store the values protecting with a semaphore*/
		 sem_wait(&g_DataUpdt_Lock_mutex);
		 pData->energy = data;
		 sem_post(&g_DataUpdt_Lock_mutex);
		 
		 transmit_measures(ENERGY_MEAS, (void *)&data);

		g_key = getkey();
		if(g_key == 'e'){
			printf("\n'e' KEY PRESSED\nExiting energy routine... \r\n");
			pthread_exit(&result);
		}
		usleep(10000);

	}

	return NULL;
}

