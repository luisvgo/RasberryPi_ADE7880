/// \file ade7880_spi_protocol.c
/// \brief \e Purpose: \n ADE7880 SPI communications protocol

/******************************************************************************
* File Name     : ade7880_spi_protocol.c
* Version       : 2.20
* Device(s)     : RX63N
* Tool-Chain    : Tested with GCC under Linux and RasPi and Renesas RX Standard Toolchain 2.02.00
* OS            : None
* H/W Platform  : ADE7880
* Description   :
*******************************************************************************/
/*******************************************************************************
* History : DD.MM.YYYY     	Version     Description
*         : 22.02.2015     	1.00        First release
*******************************************************************************/

/*******************************************************************************
Includes   <System Includes> , "Project Includes"
*******************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "definitions.h"
#include "sensors.h"
#include "pi_m16c_spi.h"
#include "m16c_spi.h"
#include "m16c_endianness.h"



void 		M16C_set_tx_buffer		( tx_m16c_pckd_buff_st *tx_buffer, tx_MC_data_u *tx_struct );
void 		M16C_set_single_tx_buffer		( tx_m16c_single_pk_buff_st *tx_buffer, tx_MC_singleData_u *tx_struct );
void		M16C_get_tx_buffer		(const tx_m16c_pckd_buff_st *tx_buffer, tx_MC_data_u *tx_struct);
void 		M16C_get_single_tx_buffer		(const tx_m16c_single_pk_buff_st *tx_buffer, tx_MC_singleData_u *tx_struct);


/*! ******************************************************************************************************************
 * \brief  M16C_SPI_write
 *  update  the specified register value on the selected ade7880 chip
 * according to the SPI write Operation protocol, see the device datasheet for more detail
 * On failure -1 will be returned
 *
 *
 * \param [in]
 * \param [in]
 * \param [out]
 *
 *******************************************************************************************************************/
/*
int8_t M16C_SPI_write(uint16_t target_register, int32_t value, uint8_t reg_len, uint32_t pid)
{

	int8_t 					ret 	= 0;
	tx_MC_data_u			 	tx_struct;
	tx_packed_buff_st			tx_buffer;

	// Set write structure members content and establish byte order according to endianness
	tx_struct.value.command 	= M16C_READ_CMD;
	tx_struct.value.cmd_addr	= target_register;

	// Set the value according to the length in bytes to write to the register's content
	if(reg_len == REG_LENGTH(uint8_t))
	{
		tx_struct.msg_fields.value.reg8 		= (uint8_t) value;
	}
	else if(reg_len == REG_LENGTH(uint16_t))
	{
		tx_struct.msg_fields.value.reg16		= htons((uint16_t) value);
	}
	else if(reg_len == REG_LENGTH(uint32_t))
	{
		tx_struct.msg_fields.value.reg32 	= htonl((uint32_t) value);
	}
	else{
		return ADE_ERROR_REG_LENGTH;
	}

	// Build the buffer
	ADE_set_tx_buffer(&tx_buffer, &tx_struct);



	// Call the SPI routine by means of the ADE7880 driver Hardware Abstraction Layer
	 if( M16C_SPI_WRITE_CALLBACK((uint8_t *)&tx_buffer.msg_all, (TX_MSG_OVERHEAD + reg_len), pid) == -1)
	 {
		 return ADE_ERROR_SPI_LOCK_NOT_GRANTED;
	 }

	return ret;
}
*/
/*******************************************************************************************************************
 * END of M16C_SPI_write()
 *******************************************************************************************************************/

/*! ******************************************************************************************************************
 * \brief  M16C_SPI_read_value
 * Reads and returns the specified register value from the selected ade7880 chip
 * according to the SPI read Operation protocol, see the device data-sheet for more detail
 *
 * Note -  the function doesn't consider 24bit signed value registers on the device,
 * if becomes necessary to read from registers of this kind remember to modify it
 *
 * \param target_register
 * \param reg_len
 *
 *******************************************************************************************************************/
int8_t M16C_SPI_read_value(uint8_t target_register, tx_MC_singleData_u *data, uint32_t pid)
{
	int8_t 					ret 	= 0;
	tx_MC_singleData_u		 	tx_struct;
	tx_m16c_single_pk_buff_st		tx_buffer;

	/* Set Read structure members content and establish byte order according to endianness*/
	tx_struct.data.command 	= M16C_READ_CMD;
	tx_struct.data.cmd_addr	= target_register;

	/* Build the buffer for network transmission */
	M16C_set_single_tx_buffer(&tx_buffer, &tx_struct);

	/* Read from the register */
	if((ret = PI_M16C_SPI_Read( tx_buffer.msg_all, REG_LENGTH(tx_buffer.msg_all), pid)) == -1)
	{
		return ret;//_ERROR_SPI_LOCK_NOT_GRANTED;
	}

	/* extract the received data from the buffer and place it in a variable */
	M16C_get_single_tx_buffer(&tx_buffer, &tx_struct);

	tx_struct.data.value = ntohl(tx_struct.data.value);
	*data = tx_struct;

	/* Return the value stored in the variable */
	return ret;

}
/*******************************************************************************************************************
 * END of M16C_SPI_read()
 ******************************************************************************************************************/

/*! ******************************************************************************************************************
 * \brief  M16C_SPI_read_all
 * Reads and returns the specified register value from the selected ade7880 chip
 * according to the SPI read Operation protocol, see the device data-sheet for more detail
 *
 * Note -  the function doesn't consider 24bit signed value registers on the device,
 * if becomes necessary to read from registers of this kind remember to modify it
 *
 * \param target_register
 * \param reg_len
 *
 *******************************************************************************************************************/
int8_t M16C_SPI_read_all(tx_MC_data_u *data, uint32_t pid)
{
	int8_t 					ret 	= 0;
	tx_MC_data_u			tx_struct;
	tx_m16c_pckd_buff_st	tx_buffer;

	/* Set Read structure members content and establish byte order according to endianness*/
	tx_struct.value.command 	= M16C_READ_CMD;
	tx_struct.value.cmd_addr	= MC_REGISTERS_ALL;

	/* Build the buffer for network transmission */
	M16C_set_tx_buffer(&tx_buffer, &tx_struct);

	/* Read from the register */
	if((ret = PI_M16C_SPI_Read( tx_buffer.msg_all, REG_LENGTH(tx_buffer.msg_all), pid)) == -1)
	{
		return ret;//_ERROR_SPI_LOCK_NOT_GRANTED;
	}

	/* extract the received data from the buffer and place it in a variable */
	M16C_get_tx_buffer(&tx_buffer, &tx_struct);

	tx_struct.value.torque = ntohs(tx_struct.value.torque);
	tx_struct.value.suction_temp = ntohs(tx_struct.value.suction_temp);
	tx_struct.value.coolant_in_temp = ntohs(tx_struct.value.coolant_in_temp);
	tx_struct.value.coolant_return_temp = ntohs(tx_struct.value.coolant_return_temp);
	tx_struct.value.block_temp = ntohs(tx_struct.value.block_temp);
	tx_struct.value.exhaust_temp = ntohs(tx_struct.value.exhaust_temp);
	tx_struct.value.oil_temp = ntohs(tx_struct.value.oil_temp);
	tx_struct.value.crankShaft_rpm = ntohl(tx_struct.value.crankShaft_rpm);
	tx_struct.value.fuel_in = ntohl(tx_struct.value.fuel_in);
	tx_struct.value.fuel_return = ntohl(tx_struct.value.fuel_return);
	tx_struct.value.suction_flow = ntohl(tx_struct.value.suction_flow);
	tx_struct.value.bin_input.bin_all = ntohs(tx_struct.value.bin_input.bin_all);

	*data = tx_struct;

	/* Return the value stored in the variable */
	return ret;

}
/*******************************************************************************************************************
 * END of M16C_SPI_read()
 ******************************************************************************************************************/

/*! ****************************************************************************************************************
 * \brief  M16C_set_tx_buffer
 * 			Builds the buffer content
 *
 * \param tx_buffer
 * \param tx_struct
 *
 ********************************************************************************************************************/
void 	M16C_set_tx_buffer		( tx_m16c_pckd_buff_st *tx_buffer, tx_MC_data_u *tx_struct )
{
    memcpy(tx_buffer->msg_all + OFFSET_ADDR,
			&tx_struct->value.command,
			REG_LENGTH(tx_struct->value.command));

	memcpy(tx_buffer->msg_all + OFFSET_CMD,
			 &tx_struct->value.cmd_addr,
			 REG_LENGTH(tx_struct->value.cmd_addr));

	memcpy(tx_buffer->msg_all + OFFSET_CMD_ADDR,
			 &tx_struct->value.torque,
			 REG_LENGTH(tx_struct->value.torque));
			 
	memcpy(tx_buffer->msg_all + OFFSET_TORQUE,
			 &tx_struct->value.suction_temp,
			 REG_LENGTH(tx_struct->value.suction_temp));
			 
	memcpy(tx_buffer->msg_all + OFFSET_SUCT_TMP,
			 &tx_struct->value.coolant_in_temp,
			 REG_LENGTH(tx_struct->value.coolant_in_temp));
			 
	memcpy(tx_buffer->msg_all + OFFSET_COOLANT_IN,
			 &tx_struct->value.coolant_return_temp,
			 REG_LENGTH(tx_struct->value.coolant_return_temp));
			 
	memcpy(tx_buffer->msg_all + OFFSET_COOLANT_RET,
			 &tx_struct->value.block_temp,
			 REG_LENGTH(tx_struct->value.block_temp));
			 
	memcpy(tx_buffer->msg_all + OFFSET_BLOCK_TMP,
			 &tx_struct->value.exhaust_temp,
			 REG_LENGTH(tx_struct->value.exhaust_temp));
			 
	memcpy(tx_buffer->msg_all + OFFSET_EXAUST_TMP,
			 &tx_struct->value.oil_temp,
			 REG_LENGTH(tx_struct->value.oil_temp));
			 
	memcpy(tx_buffer->msg_all + OFFSET_OIL_TEMP,
			 &tx_struct->value.crankShaft_rpm,
			 REG_LENGTH(tx_struct->value.crankShaft_rpm));

	memcpy(tx_buffer->msg_all + OFFSET_CRNKSFT_RPM,
			 &tx_struct->value.fuel_in,
			 REG_LENGTH(tx_struct->value.fuel_in));
			 
	memcpy(tx_buffer->msg_all + OFFSET_FUEL_IN,
			 &tx_struct->value.fuel_return,
			 REG_LENGTH(tx_struct->value.fuel_return));
			 
	memcpy(tx_buffer->msg_all + OFFSET_FUEL_RET,
			 &tx_struct->value.suction_flow,
			 REG_LENGTH(tx_struct->value.suction_flow));
			 
	memcpy(tx_buffer->msg_all + OFFSET_SUCT_FLOW,
			 &tx_struct->value.bin_input,
			 REG_LENGTH(tx_struct->value.bin_input));

}
/*******************************************************************************************************************
 * END of M16C_set_tx_buffer()
 ******************************************************************************************************************/


/*! ****************************************************************************************************************
 * \brief  M16C_get_tx_buffer
 * 			Gets the returned value from the ADE7880
 *
 * \param tx_buffer
 * \param tx_struct
 *
 ********************************************************************************************************************/
void 	M16C_get_tx_buffer		(const tx_m16c_pckd_buff_st *tx_buffer, tx_MC_data_u *tx_struct)
{
    memcpy( &tx_struct->value.command,
    		tx_buffer->msg_all + OFFSET_ADDR,
			REG_LENGTH(tx_struct->value.command));

	memcpy( &tx_struct->value.cmd_addr,
			tx_buffer->msg_all + OFFSET_CMD,
			REG_LENGTH(tx_struct->value.cmd_addr));

	memcpy( &tx_struct->value.torque,
			tx_buffer->msg_all + OFFSET_CMD_ADDR,
			REG_LENGTH(tx_struct->value.torque));

	memcpy( &tx_struct->value.suction_temp,
			tx_buffer->msg_all + OFFSET_TORQUE,
			REG_LENGTH(tx_struct->value.suction_temp));

	memcpy( &tx_struct->value.coolant_in_temp,
			tx_buffer->msg_all + OFFSET_SUCT_TMP,
			REG_LENGTH(tx_struct->value.coolant_in_temp));

	memcpy( &tx_struct->value.coolant_return_temp,
			tx_buffer->msg_all + OFFSET_COOLANT_IN,
			REG_LENGTH(tx_struct->value.coolant_return_temp));

	memcpy( &tx_struct->value.block_temp,
			tx_buffer->msg_all + OFFSET_COOLANT_RET,
			REG_LENGTH(tx_struct->value.block_temp));

	memcpy( &tx_struct->value.exhaust_temp,
			tx_buffer->msg_all + OFFSET_BLOCK_TMP,
			REG_LENGTH(tx_struct->value.exhaust_temp));

	memcpy( &tx_struct->value.oil_temp,
			tx_buffer->msg_all + OFFSET_EXAUST_TMP,
			REG_LENGTH(tx_struct->value.oil_temp));

	memcpy( &tx_struct->value.crankShaft_rpm,
			tx_buffer->msg_all + OFFSET_OIL_TEMP,
			REG_LENGTH(tx_struct->value.crankShaft_rpm));

	memcpy( &tx_struct->value.fuel_in,
			tx_buffer->msg_all + OFFSET_CRNKSFT_RPM,
			REG_LENGTH(tx_struct->value.fuel_in));

	memcpy( &tx_struct->value.fuel_return,
			tx_buffer->msg_all + OFFSET_FUEL_IN,
			REG_LENGTH(tx_struct->value.fuel_return));

	memcpy( &tx_struct->value.suction_flow,
			tx_buffer->msg_all + OFFSET_FUEL_RET,
			REG_LENGTH(tx_struct->value.suction_flow));

	memcpy( &tx_struct->value.bin_input,
			tx_buffer->msg_all + OFFSET_SUCT_FLOW,
			REG_LENGTH(tx_struct->value.bin_input));

}
/*******************************************************************************************************************
 * END of M16C_get_tx_buffer()
 ******************************************************************************************************************/


/*! ****************************************************************************************************************
 * \brief  M16C_set_single_tx_buffer
 * 			Builds the buffer content
 *
 * \param tx_buffer
 * \param tx_struct
 *
 ********************************************************************************************************************/
void 	M16C_set_single_tx_buffer		( tx_m16c_single_pk_buff_st *tx_buffer, tx_MC_singleData_u *tx_struct )
{
    memcpy(tx_buffer->msg_all + OFFSET_ADDR,
			&tx_struct->data.command,
			REG_LENGTH(tx_struct->data.command));

	memcpy(tx_buffer->msg_all + OFFSET_CMD,
			 &tx_struct->data.cmd_addr,
			 REG_LENGTH(tx_struct->data.cmd_addr));

	memcpy(tx_buffer->msg_all + OFFSET_CMD_ADDR,
			 &tx_struct->data.value,
			 REG_LENGTH(tx_struct->data.value));
}
/*******************************************************************************************************************
 * END of M16C_set_tx_buffer()
 ******************************************************************************************************************/
/*! ****************************************************************************************************************
 * \brief  M16C_get_single_tx_buffer
 * 			Gets the returned value from the ADE7880
 *
 * \param tx_buffer
 * \param tx_struct
 *
 ********************************************************************************************************************/
void 	M16C_get_single_tx_buffer		(const tx_m16c_single_pk_buff_st *tx_buffer, tx_MC_singleData_u *tx_struct)
{
    memcpy( &tx_struct->data.command,
    		tx_buffer->msg_all + OFFSET_ADDR,
			REG_LENGTH(tx_struct->data.command));

	memcpy( &tx_struct->data.cmd_addr,
			tx_buffer->msg_all + OFFSET_CMD,
			REG_LENGTH(tx_struct->data.cmd_addr));

	memcpy( &tx_struct->data.value,
			tx_buffer->msg_all + OFFSET_CMD_ADDR,
			REG_LENGTH(tx_struct->data.value));

}
/*******************************************************************************************************************
 * END of M16C_get_single_tx_buffer()
 ******************************************************************************************************************/
