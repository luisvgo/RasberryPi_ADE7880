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
*         : 24.09.2014     	1.00        First release
*		  : 02.10.2014		2.00		Byte padding avoidance included
*		  : 03.10.2014		2.10		Added write checking option
*		  : 02.02.2015		2.20		Callbacks implemented to avoid calls to external functions
*******************************************************************************/

/*******************************************************************************
Includes   <System Includes> , "Project Includes"
*******************************************************************************/
#include <stdint.h>
#include <string.h>

#include "preamble.h"
#include "ade7880_configuration.h"
#include "ade7880_registers.h"
#include "ade7880_spi_protocol.h"


int8_t 		(*ADE_SPI_WRITE_CALLBACK)	(uint8_t *data, uint8_t usBytes, uint32_t pid) = 0;
int8_t 		(*ADE_SPI_READ_CALLBACK)	(uint8_t *data, uint8_t usBytes, uint32_t pid) = 0;


void ADE_SPI_WRITE_callback_set(int8_t(*func)(uint8_t *data, uint8_t usBytes, uint32_t pid))
{
	ADE_SPI_WRITE_CALLBACK = func;
}

void ADE_SPI_READ_callback_set(int8_t(*func)(uint8_t *data, uint8_t usBytes, uint32_t pid))
{
	ADE_SPI_READ_CALLBACK = func;
}



#ifdef DEBUG_ADE
	uint8_t debug_print = ENABLE;

	/***********************************************************************************************************************
	* Function Name: spi_enable_msg_debug_print
	* Description  : Enable or disable extra print outs when debugging
	* Arguments    : none
	* Return Value : none
	***********************************************************************************************************************/
	void spi_enable_msg_debug_print(uint8_t cmd) {
		debug_print =(cmd==DISABLE)?(0x08|DISABLE):ENABLE; //bit 4 is set to indicate external setting
	} /* End of function spi_enable_msg_debug_print() */
#endif



/*! ******************************************************************************************************************
 * \brief  ADE_SPI_write
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
#include <stdio.h>
#include <unistd.h>
error_list_et ADE_SPI_write(uint16_t target_register, int32_t value, uint8_t reg_len, uint32_t pid)
{
	/**********************************************************
	 * TODO: Process ADE_SPI_Write() return for errors
	 * 		 -Try read LAST_ADDR for checking errors
	 * 		 -DONE: Check R_ADE_SPI_Write() if reg_len necessary, include it in msg??
	 * 				It is necessary
	 *		 -Check byte order for endianness compatibility
	 *		 -The function doesn't consider 24bit signed value registers on the device,
	 * 		 	if it become necessary to write to registers of this kind remember to modify
	 ************************************************************/

	error_list_et					err = ADE_NO_ERROR;
	ade7880_tx_struct_ut	 		tx_struct;
	tx_packed_buff_st				tx_buffer;


	/* Set Write structure members content establishing byte order according to endianness*/
	tx_struct.msg_fields.address_byte.address_all = 0x00;
	tx_struct.msg_fields.address_byte.bits.RD_WR = ADE7880_WR;
	tx_struct.msg_fields.target_register = htons(target_register);


	/* Set the value according to the length in bytes to write to the register's content */
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

	/* Build the buffer */
	ADE_set_tx_buffer(&tx_buffer, &tx_struct);


#ifdef DEBUG_ADE
	 /*******************************************************************************************************
	  * TODO: PERHAPS CALL A FUNCTION TO HANDLE ALL THE DEBUG CALLS
	  */
	if (debug_print & 0x01) {
		printf("-----------------------------------------------------------------\n");
		printf("\nMSG SENT (from ADE_SPI_write()) :\n");
		printf("\nMSG SENT: WR\n");
		printf("\n		Data from tx struct: \n");
		printf("       Chip Address %02X\n", tx_struct.msg_fields.address_byte.address_all);
		printf("       Target Register %04X\n",	ntohs(tx_struct.msg_fields.target_register));
		printf("	   MSG total bytes = %dB\n", reg_len+TX_MSG_OVERHEAD);
		printf("	   Payload bytes = %dB\n", reg_len);
		printf("       Value sent  %08X\n",	ntohl(tx_struct.msg_fields.value.reg32));
	}

	printf("\n		Tx buffer content:  ");
	uint8_t	byte_count =0;
	 for (byte_count = 0; byte_count < reg_len+TX_MSG_OVERHEAD; byte_count++)
	{
		printf("%02X", tx_buffer.msg_all[byte_count]);
	}
	printf("\n");
	printf("-----------------------------------------------------------------\n");
#endif

	/* Call the SPI routine by means of the ADE7880 driver Hardware Abstraction Layer */
	 if( ADE_SPI_WRITE_CALLBACK((uint8_t *)&tx_buffer.msg_all, (TX_MSG_OVERHEAD + reg_len), pid) == -1)
	 {
		 return ADE_ERROR_SPI_LOCK_NOT_GRANTED;
	 }

#if WRITE_TRANSFER_CHECK
	 err = ADE_SPI_wr_tx_check( tx_struct.msg_fields.address_byte.address_all,
			 	 	 	 	 	 tx_struct.msg_fields.target_register,
			 	 	 	 	 	 tx_struct.msg_fields.value.reg32 >> 8,
			 	 	 	 	 	 reg_len,
			 	 	 	 	 	 pid);
#endif

	return err;
}
/*******************************************************************************************************************
 * END of ADE_SPI_write()
 *******************************************************************************************************************/


/*! ******************************************************************************************************************
 * \brief  ADE_SPI_read
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
#include "bcm2835.h"
error_list_et ADE_SPI_read(uint16_t target_register, uint8_t reg_len, int32_t *result, uint32_t pid)
{
	/*******************************************************************************
	 * TODO: -consider 24bit signed value registers on the device
	 */
	error_list_et 				err  =0;
	ade7880_tx_struct_ut	 	tx_struct;
	tx_packed_buff_st			tx_buffer;

	/* Set Read structure members content and establish byte order according to endianness*/
	tx_struct.msg_fields.address_byte.address_all 	= 0x00;
	tx_struct.msg_fields.address_byte.bits.RD_WR	= ADE7880_RD;
	tx_struct.msg_fields.target_register 			= htons(target_register);
	tx_struct.msg_fields.value.reg32 				= DUMMY_MSG;

	/* Build the buffer for network transmission */
	ADE_set_tx_buffer(&tx_buffer, &tx_struct);

#ifdef DEBUG_ADE
	if((debug_print&0x01))
	{
	printf("-----------------------------------------------------------------\n");
	printf("Before sending and after creating the buffer\r\n");
	printf("\nMSG SENT (from ADE_SPI_read()) : RD\n");
	printf("        Chip Address %02X\n",tx_struct.msg_fields.address_byte.address_all);
	printf("        Target Register %04X\n",ntohs(tx_struct.msg_fields.target_register));
	printf("        DUMMY %08X \n",tx_struct.msg_fields.value.reg32);
	}
	printf("\n	Data from tx buffer:  ");
	uint8_t	byte_count =0;
	 for (byte_count = 0; byte_count < reg_len+TX_MSG_OVERHEAD; byte_count++)
	{
		printf("%02X", tx_buffer.msg_all[byte_count]);
	}
	printf("\n");
	printf("-----------------------------------------------------------------\n");
#endif

	/* Read from the register */
	if(ADE_SPI_READ_CALLBACK( tx_buffer.msg_all, ( TX_MSG_OVERHEAD + reg_len), pid) != ADE_NO_ERROR)
	{
		return ADE_ERROR_SPI_LOCK_NOT_GRANTED;
	}


	/* extract the received data from the buffer and place it in a variable */
	ADE_get_tx_buffer(&tx_buffer, &tx_struct);

	if(reg_len == REG_LENGTH(int32_t))
	{
		*result = ( (int32_t)ntohl( tx_struct.msg_fields.value.reg32 ) );
	}
	else if(reg_len == REG_LENGTH(int16_t))
	{
		*result = ( (int32_t)ntohs( tx_struct.msg_fields.value.reg16 ) );
	}
	else if(reg_len == REG_LENGTH(int8_t))
	{
		*result = ( (int32_t)tx_struct.msg_fields.value.reg8 );
	}
	else
		return ADE_ERROR_REG_LENGTH;

#ifdef DEBUG_ADE
		if((debug_print&0x01))
		{
		printf("-----------------------------------------------------------------\n");
		printf("After transmission, read back the value\r\n");
		printf("\nMSG SENT (from ADE_SPI_read()) : RD\n");
		printf("        Chip Address %02X\n",tx_struct.msg_fields.address_byte.address_all);
		printf("        Target Register %04X\n",ntohs(tx_struct.msg_fields.target_register));
		printf("        VALUE %08X \n",tx_struct.msg_fields.value.reg32);
		}
		printf("\n	Data from tx buffer:  ");
		byte_count =0;
		 for (byte_count = 0; byte_count < reg_len+TX_MSG_OVERHEAD; byte_count++)
		{
			printf("%02X", tx_buffer.msg_all[byte_count]);
		}
		printf("\n");
		printf("-----------------------------------------------------------------\n");

	if((debug_print&0x01) || 1)
	{
		printf("\nMSG REPLAY : RD\n");
		printf("        REPLAY :%X\n", *result);
		printf("-----------------------------------------------------------------\n");
	}
#endif

	/* Return the value stored in the variable */
	return err;

}
/*******************************************************************************************************************
 * END of ADE_SPI_read()
 ******************************************************************************************************************/


/*! ****************************************************************************************************************
 * \brief  ADE_set_tx_buffer
 * 			Builds the buffer content
 *
 * \param tx_buffer
 * \param tx_struct
 *
 ********************************************************************************************************************/
void 	ADE_set_tx_buffer		( tx_packed_buff_st *tx_buffer, ade7880_tx_struct_ut *tx_struct )
{
	 memcpy(tx_buffer->msg_all + OFFSET_ADDR,
			&tx_struct->msg_fields.address_byte.address_all,
			REG_LENGTH(tx_struct->msg_fields.address_byte.address_all));

	 memcpy(tx_buffer->msg_all + OFFSET_TREG,
			 &tx_struct->msg_fields.target_register,
			 REG_LENGTH(tx_struct->msg_fields.target_register));

	 memcpy(tx_buffer->msg_all + OFFSET_TX_VAL,
			 &tx_struct->msg_fields.value,
			 REG_LENGTH(tx_struct->msg_fields.value.reg32));
}
/*******************************************************************************************************************
 * END of ADE_set_tx_buffer()
 ******************************************************************************************************************/


/*! ****************************************************************************************************************
 * \brief  ADE_get_tx_buffer
 * 			Gets the returned value from the ADE7880
 *
 * \param tx_buffer
 * \param tx_struct
 *
 ********************************************************************************************************************/
uint32_t 	ADE_get_tx_buffer		(const tx_packed_buff_st *tx_buffer, ade7880_tx_struct_ut *tx_struct)
{
	memcpy(&tx_struct->msg_fields.value.reg32,
			tx_buffer->msg_all + OFFSET_TX_VAL,
			REG_LENGTH(tx_struct->msg_fields.value.reg32));

	return tx_struct->msg_fields.value.reg32;
}
/*******************************************************************************************************************
 * END of ADE_get_tx_buffer()
 ******************************************************************************************************************/


/***********************************************************************************************************************
* Function Name: ADE_SPI_tx_check()
* Description  :
* Arguments    : data-
*
* Return Value : none
***********************************************************************************************************************/
error_list_et ADE_SPI_wr_tx_check(uint16_t target_register, uint32_t reg_value, uint8_t reg_len, uint32_t pid)
{
	error_list_et	err 	= 0;
	uint16_t 		result16 = 0;
	int32_t 		result = 0;

#ifdef DEBUG_ADE
	if (!(debug_print & 0x80))
		debug_print = DISABLE;
	printf("\nVerifying last operation  ...\n");
#endif
	err = ADE_SPI_read( LAST_OP, TX_MSG_OVERHEAD + REG_LENGTH( uint8_t ), &result, pid);
	if ((uint8_t)result != 0xCA)
	{ //LAST_OP!=WR
#ifdef DEBUG_ADE
		printf(
				"\n                                               <---  WR failure : LAST_OP \n");
		printf("        LAST_OP value  :%02X\n", (uint8_t)result);
#endif
		return ADE_ERROR_LAST_OP_WR;
	}
	else if (err != ADE_NO_ERROR)
	{
		return err;
	}
	else
	{
#ifdef DEBUG_ADE
		printf("        LAST_OP value  :%02X\n", (uint8_t)result);
#endif
	}

#ifdef DEBUG_ADE
	printf("\nVerifying last accessed register  ...\n");
#endif
	err = ADE_SPI_read(LAST_ADD, TX_MSG_OVERHEAD + REG_LENGTH(uint16_t), &result, pid);
	if ((result16 = ntohs(result)) != target_register)
	{
#ifdef DEBUG_ADE
		printf(
				"\n                                               <---  WR failure : LAST_ADD\n");
		printf("        Target Register :%04X\n", ntohs(target_register));
		printf("        LAST_ADD value  :%04X\n", result16);
#endif
		return ADE_ERROR_LAST_TARGET_REG;
	}
	else if (err != ADE_NO_ERROR)
	{
		return err;
	}
	else
	{
#ifdef DEBUG_ADE
		printf("       LAST_ADD value  :%04X\n", ntohs(result16));
#endif
	}

#ifdef DEBUG_ADE
	printf("\nVerifying last accessed register content:\n");
#endif
	if (reg_len == REG_LENGTH(uint8_t))
	{
		err = ADE_SPI_read(LAST_RWDATA8, TX_MSG_OVERHEAD+REG_LENGTH(uint8_t), &result, pid);
		result &= 0x000000FF;
	}
	else if (reg_len == REG_LENGTH(uint16_t))
	{
		err = ADE_SPI_read(LAST_RWDATA16, TX_MSG_OVERHEAD+REG_LENGTH(uint16_t), &result, pid);
		result &= 0x0000FFFF;
	}
	else if (reg_len == REG_LENGTH(uint32_t))
	{
		err = ADE_SPI_read(LAST_RWDATA32, TX_MSG_OVERHEAD+REG_LENGTH(uint32_t), &result, pid);
	}

	if(err != ADE_NO_ERROR)
	{
		return err;
	}
	else if (result != reg_value)
	{
#ifdef DEBUG_ADE
		printf(
				"\n                                               <---  WR failure : LAST_RWDATA\n");
	printf("       Sent Value        :%08X\n", reg_value);
	printf("       LAST_RWDATA value :%08X\n", result);

	if (!(debug_print & 0x80))
		debug_print = ENABLE;
	printf(
			"-----------------------------------------------------------------\n");
#endif

		return ADE_ERROR_LAST_REG_VALUE;
	}

	return err;
}
/*******************************************************************************************************************
 * END of ADE_get_tx_buffer()
 ******************************************************************************************************************/




