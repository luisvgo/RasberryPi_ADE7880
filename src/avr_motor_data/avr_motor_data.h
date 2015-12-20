/*
 * motor_data.h
 *
 *  Created on: Feb 18, 2015
 *      Author: oops
 */

#ifndef AVR_MOTOR_DATA_H_
#define AVR_MOTOR_DATA_H_
/*

#define FLOW_STRL_SLOPE	((0.05-0.002)/(850.0-34.0))
#define FLOW_STRL_INTERSEC (0.05-(FLOW_STRL_SLOPE*850.0))
#define FLOW_LITRES_MIN(_X)  ( (_X != 0)? (FLOW_STRL_INTERSEC + FLOW_STRL_SLOPE * (750000.0/_X)*60.0) : 0.0)

#define RPM(_X) ( (_X != 0)?  (3000000.0/(_X * 4.0))*60.0 : 0.0 )

#define SAMPLES_NUM 10
*/
#define MAX_16BIT_VALUE	65535
#define ADC_MAX_VALUE	1023.0

//data from the sensors
typedef struct
{
	uint8_t int_addr;
	uint16_t value;
}avr_measurement;




void* 		reading_motor_avr			(void *arg);
int8_t 		convert_to_real_avr			(uint8_t sensor, tx_MC_data_u *data, MC_real_values_st *real);
uint32_t 	avr_pulse_avg				(uint32_t lastPulse, uint32_t *pulseArray);
#endif /* AVR_MOTOR_DATA_H_ */
