/// \file pi_ade7880_config.h
/// \brief \e Purpose: \n Configures ADE7880 hook code.
/***********************************************************************************************************************
* File Name	   : pi_ade7880_config.h
* Version      : 1.0 
* H/W Platform : ADE7880
* Description  : Configures ADE7880 hook code.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 20.09.2014 1.00     First Release
*         : 02.10.2014 2.00		Added endianness correction
***********************************************************************************************************************/



#ifndef ADE_CONFIG_HEADER_FILE
#define ADE_CONFIG_HEADER_FILE

/***********************************************************************************************************************
include Options
**********************************************************************************************************************/


/***********************************************************************************************************************
Configuration Options
**********************************************************************************************************************/


/// Select which RasPi SPI channel should be used to communicate with the ADE7880.
#define ADE_SPI_CHANNEL      	(CHANNEL0_SELECTED)


#define ADE_SPI_CLOCK_SPEED		256     ///< 256 = 1.024us = 976.5625MHz
/* If the code cannot get a lock on the SPI peripheral then there is an option to yield the current task, i.e. if a RTOS
   is present or by setting it in the waiting loop. This define specifies how many µseconds to yield. */
#define ADE_LOCK_DELAY_MICROS     	(1000000)



#endif /* ADE_CONFIG_HEADER_FILE */

