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
* File Name        : Config_GPT3_user.c
* Component Version: 1.5.2
* Device(s)        : R5F566TEAxFM
* Description      : This file implements device driver for Config_GPT3.
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
#include "Config_GPT3.h"
/* Start user code for include. Do not edit comment generated here */
#include "L1_GPTW.h"

/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_GPT3_Create_UserInit
* Description  : This function adds user code after initializing the GPT3 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_GPT3_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_GPT3_gtciv3_interrupt
* Description  : This function is GTCIV3 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_PERIA_INTA211
#pragma interrupt r_Config_GPT3_gtciv3_interrupt(vect=VECT(PERIA,INTA211),fint)
#else
#pragma interrupt r_Config_GPT3_gtciv3_interrupt(vect=VECT(PERIA,INTA211))
#endif
static void r_Config_GPT3_gtciv3_interrupt(void)
{
    /* Start user code for r_Config_GPT3_gtciv3_interrupt. Do not edit comment generated here */
	l_over++;
	/* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_GPT3_gtciu3_interrupt
* Description  : This function is GTCIU3 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_PERIA_INTA210
#pragma interrupt r_Config_GPT3_gtciu3_interrupt(vect=VECT(PERIA,INTA210),fint)
#else
#pragma interrupt r_Config_GPT3_gtciu3_interrupt(vect=VECT(PERIA,INTA210))
#endif
static void r_Config_GPT3_gtciu3_interrupt(void)
{
    /* Start user code for r_Config_GPT3_gtciu3_interrupt. Do not edit comment generated here */
	l_over--;
	/* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
