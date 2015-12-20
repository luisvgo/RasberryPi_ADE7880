/*
 * motor_data.h
 *
 *  Created on: Feb 18, 2015
 *      Author: oops
 */

#ifndef M16C_MOTOR_DATA_H_
#define M16C_MOTOR_DATA_H_


#define FLOW_STRL_SLOPE	((0.05-0.002)/(850.0-34.0))
#define FLOW_STRL_INTERSEC (0.05-(FLOW_STRL_SLOPE*850.0))
#define FLOW_LITRES_MIN(_X)  ( (_X != 0)? (FLOW_STRL_INTERSEC + FLOW_STRL_SLOPE * (750000.0/_X)*60.0) : 0.0)

#define RPM(_X) ( (_X != 0)?  (3000000.0/(_X * 4.0))*60.0 : 0.0 )

#define SAMPLES_NUM 10
#define MAX_STEP_ADC_10BIT	1024


void* 		reading_motor			(void *arg);
int8_t 		convert_to_real(uint8_t sensor, tx_MC_data_u *data, MC_real_values_st *real);
uint32_t 	pulse_avg			(uint32_t lastPulse, uint32_t *pulseArray);

#endif /* M16C_MOTOR_DATA_H_ */
