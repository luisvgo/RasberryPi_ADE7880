/// \file pi_ade7880_gpio.c
/// \brief \e Purpose: \n Access to the RasPi GPIO pins for additional functionality
/******************************************************************************
* File Name     : pi_ade7880_gpio.c
* Version       : 1.0
* Device(s)     : ADE7880
* Tool-Chain    : Renesas RX Standard Toolchain 1.0.0
* OS            : None
* H/W Platform  : YRDKRX63N
* Description   : This provides with acces to the ADE7880 GPIO from the Renesas
*                 board
*******************************************************************************/
/*******************************************************************************
* History : DD.MM.YYYY     	Version     Description
*         : 11.10.2014     	1.00        First release
*******************************************************************************/

/*******************************************************************************
Includes   <System Includes> , "Project Includes"
*******************************************************************************/
/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
/* Std IO library */
#include <stdbool.h>
#include <stdint.h>
#include <bcm2835.h>
#include "pi_ade7880_drv.h"
#include "./ade7880/preamble.h"

//#include <stdio.h>



/*******************************************************************************
* Prototypes for local functions
*******************************************************************************/
void ADE_HREADY_isr (void);

/******************************************************************************
Local global variables
******************************************************************************/
uint8_t g_IRQ_flag 		= 0x00;


/******************************************************************************
* name 		PI_ADE_GPIO_pin_initialize
* Description  : Set up extra pins as GPIO for other purposes, i,e, Power Mode
* Arguments    : none
* Return value : none
******************************************************************************/
void PI_ADE_GPIO_pin_initialize (void)
{
	/* CS PIN output */
	PIN_PDR(PIN_CS, OUTPUT_PIN);
	PIN_LEVEL_HIGH(PIN_CS);

	/* Make Power Mode pins as outputs */
	PIN_PDR(PIN_PM0, OUTPUT_PIN);
	PIN_PDR(PIN_PM1, OUTPUT_PIN);
	/* Set PM output pins, PM! should be as 1 before power up, ADE has pull up resistors for this pins so they should always start up at high level, PSM3 */
	PIN_LEVEL_HIGH(PIN_PM0);
	PIN_LEVEL_LOW(PIN_PM1);

	/* IRQ pins active low */
	PIN_LEVEL_HIGH(PIN_IRQ0);
	PIN_LEVEL_HIGH(PIN_IRQ1);

	/* Reset pin in inactive state high */
	PIN_PDR(PIN_RESET, OUTPUT_PIN); // Make pin an output
	PIN_LEVEL_HIGH(PIN_RESET);

    /* Make the IRQ pins input */
	PIN_PDR(PIN_IRQ0, INPUT_PIN);
	PIN_PDR(PIN_IRQ1, INPUT_PIN);
	PIN_LEVEL_HIGH(PIN_IRQ0);
	PIN_LEVEL_HIGH(PIN_IRQ1);
} // End of function PI_ADE_GPIO_pin_initialize()



/******************************************************************************
* Function name: ADE_IRQ0_isr
* Description  : ISR for /IRQ0 input.
* Arguments    : none
* Return value : none
******************************************************************************/
void ADE_IRQ0_isr (void)
{
	/****************************
	 * TODO: improve IRQ flag system
	 */
    g_IRQ_flag |= b0;
} // End of ADE_IRQ0_isr


bool callback_IRQ0(void)
{
	bool IRQ_state = FALSE;

	if(g_IRQ_flag & b0){
		IRQ_state = TRUE;
		g_IRQ_flag &= ~(1 << 0);
	}else{
		IRQ_state = FALSE;
	}
	return IRQ_state;
}

/******************************************************************************
* Function name: ADE_IRQ1_isr
* Description  : ISR for /IRQ0 input.
* Arguments    : none
* Return value : none
******************************************************************************/
void ADE_IRQ1_isr (void)
{
    g_IRQ_flag |= b1;
} /* End of ADE_IRQ1_isr */


bool callback_IRQ1(void)
{
	bool IRQ_state = FALSE;

	if(g_IRQ_flag & b1){
		IRQ_state = TRUE;
		g_IRQ_flag &= ~(1 << 1);
	}else{
		IRQ_state = FALSE;
	}
	return IRQ_state;
}

/******************************************************************************
* Function name: ADE_HREADY_isr
* Description  : ISR for /IRQ0 input.
* Arguments    : none
* Return value : none
******************************************************************************/
void ADE_HREADY_isr (void)
{
	/****************************
	 * TODO: improve IRQ flag system
	 */
    g_IRQ_flag |= b2;
} /* End of ADE_IRQ0_isr */


bool callback_HREADY(void)
{
	bool IRQ_state = FALSE;

	if(g_IRQ_flag & b2){
		IRQ_state = TRUE;
		g_IRQ_flag &= ~(1 << 2);
	}else{
		IRQ_state = FALSE;
	}
	return IRQ_state;
}
