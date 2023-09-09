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
* File Name        : Config_CMT2_user.c
* Component Version: 2.3.0
* Device(s)        : R5F566TEAxFM
* Description      : This file implements device driver for Config_CMT2.
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
#include "Config_CMT2.h"
/* Start user code for include. Do not edit comment generated here */
#include "L1_CLOCK.h"
#include "L1_IO.h"
#include "L1_AD.h"
#include "L1_GPTW.h"

#include "L2_SENSOR.h"
#include "L2_MOTOR.h"

#include "L3_CONTROL.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_CMT2_Create_UserInit
* Description  : This function adds user code after initializing the CMT2 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_CMT2_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_CMT2_cmi2_interrupt
* Description  : This function is CMI2 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#if FAST_INTERRUPT_VECTOR == VECT_CMT2_CMI2
#pragma interrupt r_Config_CMT2_cmi2_interrupt(vect=VECT(CMT2,CMI2),fint)
#else
#pragma interrupt r_Config_CMT2_cmi2_interrupt(vect=VECT(CMT2,CMI2))
#endif
static void r_Config_CMT2_cmi2_interrupt(void)
{
    /* Start user code for r_Config_CMT2_cmi2_interrupt. Do not edit comment generated here */
	//5ms割り込みはここ
	if(error.calibration==0){
//	 chalibration( &max, &min, &raw, &baffa);
		rogistic_chalibration(&raw, &baffa);
	}
	radian( &baffa,rad);

	u=moter_pid(target,speed);
	change_motor_voltage((long)u.l,(long)u.r);

    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
