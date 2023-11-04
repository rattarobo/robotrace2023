/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_DMAC0_user.c
* Component Version: 1.8.0
* Device(s)        : R5F566TEAxFM
* Description      : This file implements device driver for Config_DMAC0.
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_DMAC0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* Global variable used to receive a character from SCI1 */
volatile uint8_t g_rx_char_dmac;
/* Flag used to detect whether data is received */
volatile uint8_t g_rx_flag_dmac;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_DMAC0_Create_UserInit
* Description  : This function adds user code after initializing the DMAC0 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_DMAC0_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
	/* Clear receive flag */ g_rx_flag_dmac = 0U;
	/* Set DMAC0 source address */
	DMAC0.DMSAR = (void *)&SCI1.RDR;
	/* Set DMAC0 destination address */
	DMAC0.DMDAR = (void *)&g_rx_char_dmac;
	/* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_DMAC0_dmac0i_interrupt
* Description  : This function is dmac0i interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_DMAC_DMAC0I
#pragma interrupt r_Config_DMAC0_dmac0i_interrupt(vect=VECT(DMAC,DMAC0I),fint)
#else
#pragma interrupt r_Config_DMAC0_dmac0i_interrupt(vect=VECT(DMAC,DMAC0I))
#endif
static void r_Config_DMAC0_dmac0i_interrupt(void)
{
    if (DMAC0.DMSTS.BIT.DTIF == 1U)
    {
        DMAC0.DMSTS.BIT.DTIF = 0U;
        r_dmac0_callback_transfer_end();
    }
}

/***********************************************************************************************************************
* Function Name: r_dmac0_callback_transfer_end
* Description  : This function is dmac0 transfer end callback function
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

static void r_dmac0_callback_transfer_end(void)
{
    /* Start user code for r_dmac0_callback_transfer_end. Do not edit comment generated here */
	/* Set receive completion flag */
	g_rx_flag_dmac = 1U;
	/* Set DMAC0 transfer count */
	DMAC0.DMCRA = _00000001_DMAC0_DMCRA_COUNT;
	/* Enable DMAC0 transfer */
	R_Config_DMAC0_Start();
	/* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
