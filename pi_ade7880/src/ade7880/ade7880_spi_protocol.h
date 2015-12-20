
/// \file ade7880_spi_protocol.h
/// \brief Provides the required structures for building communications buffer


#ifndef __SRV_ADE7880_PROTOCOL_H
#define __SRV_ADE7880_PROTOCOL_H

/* Callback prototypes. */
/*
#if defined(ADE_SPI_WRITE_CALLBACK)
void ADE_SPI_WRITE_CALLBACK(void);
#endif


*/
/***************************************************************************
 * SECTION:  ADE SPI PROTOCOL CONSTANTS
 ***************************************************************************/
#define ADE7880_RD					1
#define ADE7880_WR					0
#define DUMMY_MSG					0x00000000
#define REG_LENGTH(_x)              (sizeof(_x))
#define TX_MSG_OVERHEAD				3			// 1 byte (chip addr & read or write bit) + 2 bytes (register addresses)
#define RAM_LOCK_MSG_LENGTH		    1

/***********************************************************************************************************************
 * Check: 'avoiding the padding' in this file
 */
#define OFFSET_ADDR					(0)
#define OFFSET_TREG					(OFFSET_ADDR + REG_LENGTH(uint8_t))
#define OFFSET_TX_VAL				(OFFSET_TREG + REG_LENGTH(uint16_t))
#define OFFSET_END					(OFFSET_TX_VAL + REG_LENGTH(uint32_t))


/***********************************************************************************************************************
 * //! address byte of msg structure to ADE7880
 */

typedef union
{
    uint8_t		address_all;
    struct
    {
        uint8_t  	RD_WR:1;
        uint8_t  	chip_address:6;
    } bits;

}address_byte_ut;

typedef union{
uint8_t 		reg8;
uint16_t 		reg16;
uint32_t 		reg32;
}value_ut;


/***********************************************************************************************************************
* ADE7880 tx cmd msg structure
***********************************************************************************************************************/

//! ADE7880 tx cmd msg structure
typedef union
{
    uint8_t 	msg_all[TX_MSG_OVERHEAD + sizeof(uint32_t)] ;
    
    struct
    {	
		address_byte_ut  	address_byte;
		uint16_t  			target_register;
		union{
			uint8_t 		reg8;
			uint16_t 		reg16;
			uint32_t 		reg32;
		}value;
	} msg_fields;
	
}ade7880_tx_struct_ut;

/***********************************************************************************************************************
* Avoiding byte padding when building the network communication buffer
* Description  : A portable, reliable and fast way to avoid the structure padding
* 				 The structure does not define real members but a single array of characters
* 				 Then set of macros are defined to access its content such as follows:
*
* 				 struct paddingless_Buffer {
*					// uint8_t RegisterAddress;
*					// uint16_t TargetRegister;
*					// uint32_t Register_Value;
*
*					#define OFFSET_ADDR					(0)
*					#define OFFSET_TREG					(OFFSET_ADDR + REG_LENGTH(uint8_t))
*					#define OFFSET_TX_VAL				(OFFSET_TREG + REG_LENGTH(uint16_t))
*					#define OFFSET_END					(OFFSET_TX_VAL + REG_LENGTH(uint32_t))
*
*					char msg_all[OFFSET_END];
*				};
*
*				use memcpy to set its content as follows by using the tx_structure:
*				memcpy(paddingless_Buffer.msg_all + OFFSET_TX_VAL,
*						&tx_struct.msg_fields.value.reg32,
*						REG_LENGTH(register_length));
*
*				use memcpy to get its content as follows:
*				memcpy(&tx_struct.msg_fields.value.reg32,
*						paddingless_Buffer.msg_all + OFFSET_TX_VAL,
*						REG_LENGTH(register_length));
*
*
***********************************************************************************************************************/
typedef struct
{
	uint8_t		msg_all[OFFSET_END];
}tx_packed_buff_st;

/***********************************************************************************************************************
 * END of write structure and buffer
 */



error_list_et 	ADE_SPI_read			(uint16_t target_register, uint8_t reg_len, int32_t *result, uint32_t pid);
error_list_et  	ADE_SPI_write			(uint16_t target_register, int32_t value, uint8_t reg_len, uint32_t pid);
error_list_et 	ADE_SPI_Ram_protection	(uint8_t cmd, uint8_t chip_address, uint32_t pid);
void 			ADE_set_tx_buffer		(tx_packed_buff_st *tx_buffer, ade7880_tx_struct_ut *tx_struct);
uint32_t	 	ADE_get_tx_buffer		(const tx_packed_buff_st *tx_buffer, ade7880_tx_struct_ut *tx_struct);
error_list_et	ADE_SPI_wr_tx_check		(uint16_t target_register, uint32_t reg_value, uint8_t reg_len, uint32_t pid);

void 		ADE_SPI_WRITE_callback_set	(int8_t (*func)(uint8_t *data, uint8_t usBytes, uint32_t pid));
void 		ADE_SPI_READ_callback_set	(int8_t (*func)(uint8_t *data, uint8_t usBytes, uint32_t pid));

#ifdef DEBUG_ADE
void 		spi_enable_msg_debug_print	(uint8_t cmd);
#endif



#endif /* __SRV_ADE7880_PROTOCOL_H */
