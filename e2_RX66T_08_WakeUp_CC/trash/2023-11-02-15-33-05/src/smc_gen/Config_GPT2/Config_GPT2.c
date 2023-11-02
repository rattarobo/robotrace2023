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
* File Name        : Config_GPT2.c
* Component Version: 1.5.2
* Device(s)        : R5F566TEAxFM
* Description      : This file implements device driver for Config_GPT2.
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
#include "Config_GPT2.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_GPT2_Create
* Description  : This function initializes the GPT2 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_GPT2_Create(void)
{
    /* Disable GPTW2 interrupts */
    IEN(PERIA,INTA209) = 0U;
    IEN(PERIA,INTA208) = 0U;

    /* Cancel GPTW2 module stop state */
    MSTP(GPTW2) = 0U;

    /* Disable GPTW2 control registers write protect */
    GPTW2.GTWP.LONG = 0x0000A500UL;

    /* Set GPTW2 mode */
    GPTW2.GTCR.LONG = _00000000_GPTn_MODE_SAW_WAVE_PWM;

    /* Set GPTW2 count direction and duty */
    GPTW2.GTUDDTYC.LONG = _00000001_GPTn_COUNT_UP | _00000002_GPTn_COUNT_DIR_FORCE;

    /* Clear GPTW2 count direction forcible set */
    GPTW2.GTUDDTYC.BIT.UDF = 0U;

    /* Set GPTW2 count clock and input capture at count stop */
    GPTW2.GTCR.LONG |= (_00000100_GPTn_NO_INPUTCAP_COUNT_STOP | _01000000_GPTn_COUNT_CLK_PCLKC_4);

    /* Set GPTW2 cycle */
    GPTW2.GTPR = _000493DF_GPT2_CYCLE_VALUE;

    /* Set GPTW2 counter initial value */
    GPTW2.GTCNT = _00000000_GPT2_INIT_COUNT;

    /* Set GPTW2 count-up sources */
    GPTW2.GTUPSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                        _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                        _00000200_GPTn_GTIOCnA_RISE_GTIOCnB_1_ENABLE | _00000400_GPTn_GTIOCnA_FALL_GTIOCnB_0_ENABLE | 
                        _00001000_GPTn_GTIOCnB_RISE_GTIOCnA_0_ENABLE | _00008000_GPTn_GTIOCnB_FALL_GTIOCnA_1_ENABLE | 
                        _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                        _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                        _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                        _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE;

    /* Set GPTW2 count-down sources */
    GPTW2.GTDNSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                        _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                        _00000100_GPTn_GTIOCnA_RISE_GTIOCnB_0_ENABLE | _00000800_GPTn_GTIOCnA_FALL_GTIOCnB_1_ENABLE | 
                        _00002000_GPTn_GTIOCnB_RISE_GTIOCnA_1_ENABLE | _00004000_GPTn_GTIOCnB_FALL_GTIOCnA_0_ENABLE | 
                        _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                        _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                        _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                        _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE;

    /* Set GPTW2 start sources */
    GPTW2.GTSSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                       _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                       _00000000_GPTn_GTIOCnA_RISE_DISABLE | _00000000_GPTn_GTIOCnA_FALL_DISABLE | 
                       _00000000_GPTn_GTIOCnB_RISE_DISABLE | _00000000_GPTn_GTIOCnB_FALL_DISABLE | 
                       _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                       _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                       _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                       _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE | 
                       _80000000_GPTn_SOFTWARE_SOURCE_ENABLE;

    /* Set GPTW2 stop sources */
    GPTW2.GTPSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                       _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                       _00000000_GPTn_GTIOCnA_RISE_DISABLE | _00000000_GPTn_GTIOCnA_FALL_DISABLE | 
                       _00000000_GPTn_GTIOCnB_RISE_DISABLE | _00000000_GPTn_GTIOCnB_FALL_DISABLE | 
                       _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                       _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                       _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                       _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE | 
                       _80000000_GPTn_SOFTWARE_SOURCE_ENABLE;

    /* Set GPTW2 clear sources */
    GPTW2.GTCSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                       _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                       _00000000_GPTn_GTIOCnA_RISE_DISABLE | _00000000_GPTn_GTIOCnA_FALL_DISABLE | 
                       _00000000_GPTn_GTIOCnB_RISE_DISABLE | _00000000_GPTn_GTIOCnB_FALL_DISABLE | 
                       _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                       _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                       _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                       _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE | 
                       _80000000_GPTn_SOFTWARE_SOURCE_ENABLE;

    /* Set GPTW2 output stop detection */
    GPTW2.GTINTAD.LONG = _00000000_GPTn_OUTPUT_STOP_GROUPA | _00000000_GPTn_SIMHIGH_OUTPUT_STOP_DISABLE | 
                         _00000000_GPTn_SIMLOW_OUTPUT_STOP_DISABLE;

    /* Set GPTW2 noise filter GTIOC2A,GTIOC2B */
    GPTW2.GTIOR.LONG |= (_00000000_GPTn_GTIOCnA_NOISE_FILTER_DISABLE | _00000000_GPTn_GTIOCnB_NOISE_FILTER_DISABLE);

    /* Enable GTIOC2A,GTIOC2B pin output */
    GPTW2.GTIOR.LONG |= (_00000000_GPTn_GTCIOCA_OUTPUT_DISABLE | _00000000_GPTn_GTCIOCB_OUTPUT_DISABLE);

    /* Set GPTW2 buffer operations */
    GPTW2.GTBER.LONG = _00000001_GPTn_GTCCR_BUF_OP_DISABLE | _00000002_GPTn_GTPR_BUF_OP_DISABLE | 
                       _00000004_GPTn_GTADTR_BUF_OP_DISABLE | _00000000_GPTn_GTCCRA_BUF_NONE | 
                       _00000000_GPTn_GTCCRB_BUF_NONE | _00000000_GPTn_GTPR_BUF_NONE;

    /* Set GPTW2 compare match value */
    GPTW2.GTCCRA = _00000064_GPT2_COMP_MATCH_A_VALUE;
    GPTW2.GTCCRB = _00000064_GPT2_COMP_MATCH_B_VALUE;
    GPTW2.GTCCRC = _00000064_GPT2_COMP_MATCH_C_VALUE;
    GPTW2.GTCCRD = _00000064_GPT2_COMP_MATCH_D_VALUE;
    GPTW2.GTCCRE = _00000064_GPT2_COMP_MATCH_E_VALUE;
    GPTW2.GTCCRF = _00000064_GPT2_COMP_MATCH_F_VALUE;

    /* Set GPTW2 interrupt and A/D conversion request generation */
    GPTW2.GTINTAD.LONG |= (_00000000_GPTn_ADTRB_DOWNCOUNTING_DISABLE | _00000000_GPTn_ADTRB_UPCOUNTING_DISABLE | 
                          _00000000_GPTn_ADTRA_DOWNCOUNTING_DISABLE | _00000000_GPTn_ADTRA_UPCOUNTING_DISABLE | 
                          _00000040_GPTn_GTCIV_INTERRUPT_ENABLE | _00000080_GPTn_GTCIU_INTERRUPT_ENABLE | 
                          _00000000_GPTn_GTCIF_INTERRUPT_DISABLE | _00000000_GPTn_GTCIE_INTERRUPT_DISABLE | 
                          _00000000_GPTn_GTCID_INTERRUPT_DISABLE | _00000000_GPTn_GTCIC_INTERRUPT_DISABLE | 
                          _00000000_GPTn_GTCIB_INTERRUPT_DISABLE | _00000000_GPTn_GTCIA_INTERRUPT_DISABLE);

    /* Set GPTW2 A/D converter start request signal monitoring */
    GPTW2.GTADSMR.LONG = _00000000_GPTn_AD_START_MONITOR0_DISABLE | _00000000_GPTn_AD_START_MONITOR1_DISABLE;

    /* Set GPTW2 interrupt and A/D conversion request skipping */
    GPTW2.GTITC.LONG = _00000000_GPTn_GTCI_SKIP_DISABLE | _00000000_GPTn_GTCI_SKIPPING_COUNT_0;

    /* Set GPTW2 extended interrupt skipping counter control */
    GPTW2.GTEITC.LONG = _00000000_GPTn_EXT1_SKIP_DISABLE | _00000000_GPTn_EXT2_SKIP_DISABLE;

    /* Disable rising and falling edge adjustment circuit */
    HRPWM.HROCR2.BIT.HRDIS2 = 1U;

    /* Configure GPTW2 interrupts */
    ICU.SLIAR209.BYTE = 0x51U;
    IPR(PERIA,INTA209) = _0D_GPT_PRIORITY_LEVEL13;
    ICU.SLIAR208.BYTE = 0x52U;
    IPR(PERIA,INTA208) = _0D_GPT_PRIORITY_LEVEL13;

    /* Set GTIOC2A pin */
    MPC.PB6PFS.BYTE = 0x14U;
    PORTB.PMR.BYTE |= 0x40U;

    /* Set GTIOC2B pin */
    MPC.PB5PFS.BYTE = 0x14U;
    PORTB.PMR.BYTE |= 0x20U;

    R_Config_GPT2_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_GPT2_Start
* Description  : This function starts the GPT2 channel counter. Note that this function is empty
*                if Count start sources setting is not enabled and no interrupt is configured for GPT2
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_GPT2_Start(void)
{
    /* Enable GPTW2 interrupts */
    IR(PERIA,INTA209) = 0U;
    IEN(PERIA,INTA209) = 1U;
    IR(PERIA,INTA208) = 0U;
    IEN(PERIA,INTA208) = 1U;

    /* Disable GPTW2 start write protect */
    GPTW2.GTWP.BIT.STRWP = 0U;

    /* Start GPTW2 counting */
    GPTW2.GTSTR.BIT.CSTRT2 = 1U;

    /* Enable GPTW2 start write protect */
    GPTW2.GTWP.BIT.STRWP = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_GPT2_Stop
* Description  : This function stops the GPT2 channel counter. Note that this function is empty
*                if Count stop sources setting is not enabled and no interrupt is configured for GPT2
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_GPT2_Stop(void)
{
    /* Disable GPTW2 interrupts */
    IEN(PERIA,INTA209) = 0U;
    IEN(PERIA,INTA208) = 0U;

    /* Disable GPTW2 start write protect */
    GPTW2.GTWP.BIT.STPWP = 0U;

    /* Stop GPTW2 counting */
    GPTW2.GTSTP.BIT.CSTOP2 = 1U;

    /* Enable GPTW2 start write protect */
    GPTW2.GTWP.BIT.STPWP = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_GPT2_Software_Clear
* Description  : This function software clear the GPT2 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_GPT2_Software_Clear(void)
{
    /* Disable GPTW2 clear write protect */
    GPTW2.GTWP.BIT.CLRWP = 0U;

    /* Clear GPTW2 counter */
    GPTW2.GTCLR.BIT.CCLR2 = 1U;

    /* Enable GPTW2 clear write protect */
    GPTW2.GTWP.BIT.CLRWP = 1U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
