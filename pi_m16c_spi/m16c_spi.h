/*
 * m16c_spi_protocol.h
 *
 *  Created on: Feb 18, 2015
 *      Author: oops
 */

#ifndef M16C_SPI_PROTOCOL_H_
#define M16C_SPI_PROTOCOL_H_

#include "definitions.h"



/***********************************************************************************************************************
 * avoiding the padding
 */
#define OFFSET_ADDR					(0)
#define OFFSET_CMD					(OFFSET_ADDR + REG_LENGTH(uint8_t))
#define OFFSET_CMD_ADDR				(OFFSET_CMD + REG_LENGTH(uint8_t))
#define OFFSET_TORQUE				(OFFSET_CMD_ADDR + REG_LENGTH(uint16_t))
#define OFFSET_SUCT_TMP				(OFFSET_TORQUE + REG_LENGTH(uint16_t))
#define OFFSET_COOLANT_IN			(OFFSET_SUCT_TMP + REG_LENGTH(uint16_t))
#define OFFSET_COOLANT_RET			(OFFSET_COOLANT_IN + REG_LENGTH(uint16_t))
#define OFFSET_BLOCK_TMP			(OFFSET_COOLANT_RET + REG_LENGTH(uint16_t))
#define OFFSET_EXAUST_TMP			(OFFSET_BLOCK_TMP + REG_LENGTH(uint16_t))
#define OFFSET_OIL_TEMP				(OFFSET_EXAUST_TMP + REG_LENGTH(uint16_t))
#define OFFSET_CRNKSFT_RPM			(OFFSET_OIL_TEMP + REG_LENGTH(uint32_t))
#define OFFSET_FUEL_IN				(OFFSET_CRNKSFT_RPM + REG_LENGTH(uint32_t))
#define OFFSET_FUEL_RET				(OFFSET_FUEL_IN + REG_LENGTH(uint32_t))
#define OFFSET_SUCT_FLOW			(OFFSET_FUEL_RET + REG_LENGTH(uint32_t))
#define OFFSET_BIN_SENSORS			(OFFSET_SUCT_FLOW + REG_LENGTH(uint16_t))
#define OFFSET_END					(OFFSET_BIN_SENSORS + REG_LENGTH(uint16_t))



/***************************************************************************
 * To handle the incoming data from m16c, all addresses together
 */
/**
 * holds the transmission buffer (string) all the data is packed without needing specific compiler instructions
 */
typedef struct
{
	uint8_t	msg_all[OFFSET_END];
}tx_m16c_pckd_buff_st;


typedef union
{
	uint16_t  bin_all;
	struct
	{
		uint16_t oil_pressure_OK	:1;
		uint16_t emergency_stop		:1;
		uint16_t min_fuel_lvl		:1;
		uint16_t annealing_ON		:1;
		uint16_t battery_charging	:1;
		uint16_t motor_on			:1;
		uint16_t motor_off			:1;
		uint16_t reserved			:9; // These bits are always 0
	}bit_s;
}bin_input_u;

/* MEASUREMENT ATTRIBUTES: READINGS FROM REGISERS*/
typedef struct
{
	uint8_t	  command;
	uint8_t   cmd_addr;
	uint16_t  torque;
	uint16_t  suction_temp;
	uint16_t  coolant_in_temp;
	uint16_t  coolant_return_temp;
	uint16_t  block_temp;
	uint16_t  exhaust_temp;
	uint16_t  oil_temp;
	uint32_t  crankShaft_rpm;
	uint32_t  fuel_in;
	uint32_t  fuel_return;
	uint32_t  suction_flow;
	bin_input_u   bin_input;
} MC_data_st;

/* MEASUREMENT ATTRIBUTES: REAL DATA*/
typedef struct
{
	uint8_t	command;
	uint8_t cmd_addr;
	float	torque;
	float 	suction_temp;
	float	coolant_in_temp;
	float	coolant_return_temp;
	float	block_temp;
	float	exhaust_temp;
	float	oil_temp;
	float  	crankShaft_rpm;
	float  	fuel_in;
	float  	fuel_return;
	float  	suction_flow;
	bin_input_u   bin_input;
} MC_real_values_st;


typedef union
{
	MC_data_st value;
	uint8_t str[REG_LENGTH(MC_data_st)];
} tx_MC_data_u;

/***************************************************************************************************
 * To handle the incoming data from m16c, single address
 */
typedef struct
{
	uint8_t	msg_all[6];
}tx_m16c_single_pk_buff_st;

/* MEASUREMENT ATTRIBUTES */
typedef struct
{
	uint8_t	  command;
	uint8_t   cmd_addr;
	uint32_t  value;
} MC_singleData_st;

typedef union
{
	MC_singleData_st data;
	uint8_t str[REG_LENGTH(MC_singleData_st)];
} tx_MC_singleData_u;



/* union to handle the possibility of float values transmission */
typedef union
{
	float f;
    uint8_t ch[4];
	uint32_t ul;
} C_Float_u;


int8_t M16C_SPI_read_value		(uint8_t target_register, tx_MC_singleData_u *data, uint32_t pid);
int8_t M16C_SPI_read_all		(tx_MC_data_u *data, uint32_t pid);


#endif /* M16C_SPI_PROTOCOL_H_ */
