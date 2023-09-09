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
* File Name        : r_cg_hardware_setup.c
* Version          : 1.0.111
* Device(s)        : R5F566TEAxFM
* Description      : Initialization file for code generation configurations.
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
#include "Config_CMT0.h"
#include "Config_CMT1.h"
#include "Config_DMAC0.h"
#include "Config_DMAC1.h"
#include "Config_GPT2.h"
#include "Config_GPT3.h"
#include "Config_GPT4.h"
#include "Config_MTU0.h"
#include "Config_PORT.h"
#include "Config_S12AD0.h"
#include "Config_S12AD1.h"
#include "Config_S12AD2.h"
#include "Config_SCI1.h"
#include "Config_RSPI0.h"
#include "r_smc_cgc.h"
#include "r_smc_interrupt.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_undefined_exception
* Description  : This function is undefined interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void r_undefined_exception(void)
{
    /* Start user code for r_undefined_exception. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: R_Systeminit
* Description  : This function initializes every configuration
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Systeminit(void)
{
    /* Enable writing to registers related to operating modes, LPC, CGC and software reset */
    SYSTEM.PRCR.WORD = 0xA50BU;

    /* Enable writing to MPC pin function control registers */
    MPC.PWPR.BIT.B0WI = 0U;
    MPC.PWPR.BIT.PFSWE = 1U;

    /* Write 0 to the target bits in the POECR2 registers */
    POE.POECR2.WORD = 0x0000U;

    /* Initialize clocks settings */
    R_CGC_Create();

    /* Set peripheral settings */
    R_Config_PORT_Create();
    R_Config_CMT0_Create();
    R_Config_CMT1_Create();
    R_Config_DMAC0_Create();
    R_Config_DMAC1_Create();
    R_Config_GPT2_Create();
    R_Config_GPT3_Create();
    R_Config_GPT4_Create();
    R_Config_MTU0_Create();
    R_Config_S12AD0_Create();
    R_Config_S12AD1_Create();
    R_Config_S12AD2_Create();
    R_Config_SCI1_Create();
    R_Config_RSPI0_Create();

    /* Set interrupt settings */
    R_Interrupt_Create();

    /* Register undefined interrupt */
    R_BSP_InterruptWrite(BSP_INT_SRC_UNDEFINED_INTERRUPT,(bsp_int_cb_t)r_undefined_exception);

    /* Register group BL0 interrupt TEI1 (SCI1) */
    R_BSP_InterruptWrite(BSP_INT_SRC_BL0_SCI1_TEI1,(bsp_int_cb_t)r_Config_SCI1_transmitend_interrupt);

    /* Register group BL0 interrupt ERI1 (SCI1) */
    R_BSP_InterruptWrite(BSP_INT_SRC_BL0_SCI1_ERI1,(bsp_int_cb_t)r_Config_SCI1_receiveerror_interrupt);

    /* Register group AL0 interrupt SPII0 (RSPI0) */
    R_BSP_InterruptWrite(BSP_INT_SRC_AL0_RSPI0_SPII0,(bsp_int_cb_t)r_Config_RSPI0_idle_interrupt);

    /* Register group AL0 interrupt SPEI0 (RSPI0) */
    R_BSP_InterruptWrite(BSP_INT_SRC_AL0_RSPI0_SPEI0,(bsp_int_cb_t)r_Config_RSPI0_error_interrupt);

    /* Disable writing to MPC pin function control registers */
    MPC.PWPR.BIT.PFSWE = 0U;
    MPC.PWPR.BIT.B0WI = 1U;

    /* Enable protection */
    SYSTEM.PRCR.WORD = 0xA500U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
