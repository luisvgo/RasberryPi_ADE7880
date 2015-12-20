/******************************************************************************
 * File Name     : main.c
 * Version       : 1.0
 * Tool-Chain    : GNU
 * OS            : None
 * H/W Platform  : Raspi
 * Description   : MCU application project
 *******************************************************************************/

/*******************************************************************************
 Includes   <System Includes> , "Project Includes"
 *******************************************************************************/


#include <termios.h>	/* Keyboard */
#include "main.h"

// Number of running threads
#define THREADS_NUMBER	4

// Unique global task (thread) ID
pthread_t g_tid[THREADS_NUMBER];

/* semaphores used as a mutex to control SPI access and upload values */
sem_t 	g_SPI_Lock_mutex;
sem_t 	g_DataUpdt_Lock_mutex;

/* Global variable to hold keyboard press */
uint8_t g_key;

/*******************************************************************************
 * Prototypes for local functions
 *******************************************************************************/

/******************************************************************************
 * Function name: main
 * Description  : Main program fn
 * Arguments    : none
 * Return value : none
 ******************************************************************************/
int main(void)
{
	server_data_st data;
	error_list_et err;
	g_key = 0xFF;		// Different values stop different threads

	//int *t_ret_ptr[THREADS_NUMBER];		// pointer to threads return
	sem_init(&g_SPI_Lock_mutex, 0, 1);	/* initialize mutex to 1 - binary semaphore */
										/* second param = 0 - semaphore is local */

	sem_init(&g_DataUpdt_Lock_mutex, 0, 1);

	/*
	 Open the console window in to see the output
	 */
	printf("This is the debug console\r\n");

#if READ_FROM_ADE7880
	// Create thread 0 to read energy values
	if ((err = pthread_create(&(g_tid[0]), NULL, &reading_energy, (void *)&data)) != 0)
	{
		printf("\ncan't create thread :[%s] \r\n", strerror(err));
	}
	else
	{
		printf("\nThread for energy meter created successfully \r\n");
	}

	usleep(750000);
#endif

#if READ_FROM_M16C
	// Create thread 1 to read m16c
	if ((err = pthread_create(&(g_tid[1]), NULL, &reading_motor, (void *)&data)) != 0)
	{
		printf("\ncan't create thread :[%s] \r\n", strerror(err));
	}
	else
	{
		printf("\nThread for m16c created successfully \r\n");
	}

	usleep(100000);
#endif

#if RUN_IEC_SERVER
	// Create thread 2 to read/write to server
	if ((err = pthread_create(&(g_tid[2]), NULL, &motor_control_srvc, (void *)&data)) != 0)
	{
		printf("\ncan't create thread :[%s] \r\n", strerror(err));
	}
	else
	{
		printf("\nThread for read/write to server created successfully \r\n");
	}
#endif


#if READ_FROM_AVR
	// Create thread 3 to read AVR THIS HAS NOT BEEN COMPLETELY DEVELOPED
	// go to avr_motor_data and complete it if you are not satisfied with M16C62P implementation
	if ((err = pthread_create(&(g_tid[3]), NULL, &reading_motor_avr, (void *)&data)) != 0)
	{
		printf("\ncan't create thread :[%s] \r\n", strerror(err));
	}
	else
	{
		printf("\nThread for AVR to server created successfully \r\n");
	}
#endif

	/* This is the main loop.  It does nothing but runs the loop periodically */
	while (g_key != 'q')
	{
		g_key = getkey();
		if(g_key == 'q'){
			printf("\nQ KEY PRESSED\nExiting routine... \r\n");
			pthread_cancel(g_tid[0]);
			pthread_cancel(g_tid[1]);
			pthread_cancel(g_tid[2]);
			pthread_cancel(g_tid[3]);
		}
		usleep(100000);
	}

	//pthread_join(g_tid[0], (void**)&(t_ret_ptr[0]));
	//pthread_join(g_tid[1], (void**)&(t_ret_ptr[1]));
	//pthread_join(g_tid[2], (void**)&(t_ret_ptr[2]));
	//pthread_join(g_tid[3], (void**)&(t_ret_ptr[3]));

	/* Close Raspberry hardware SPI channel  */
	if (PI_SPI_CheckInitialized())
	{
		PI_SPI_Close();
	}
	/* Close Raspberry hardware bcm2835 library  */
	if (PI_BCM_CheckInitialized())
	{
		PI_BCM_Close();
	}

	/* destroy semaphores */
	sem_destroy(&g_SPI_Lock_mutex);
	sem_destroy(&g_DataUpdt_Lock_mutex);

	return 0;
} /* End of function main() */



// to capture keyboard press --->(ONLY LINUX BASED SYSTEMS)<---  delete getkey() if other OS is in use: 'key' variable, 'key' condition in line 225 and getkey() call line 227; and implement respective call
int getkey()
{
	int character;
	struct termios orig_term_attr;
	struct termios new_term_attr;

	// set the terminal to raw mode
	tcgetattr(fileno(stdin), &orig_term_attr);
	memcpy(&new_term_attr, &orig_term_attr, sizeof(struct termios));
	new_term_attr.c_lflag &= ~(ECHO | ICANON);
	new_term_attr.c_cc[VTIME] = 0;
	new_term_attr.c_cc[VMIN] = 0;
	tcsetattr(fileno(stdin), TCSANOW, &new_term_attr);

	// read a character from the stdin stream without blocking
	//  returns EOF (-1) if no character is available
	character = fgetc(stdin);

	// restore the original terminal attributes
	tcsetattr(fileno(stdin), TCSANOW, &orig_term_attr);

	return character;
}
