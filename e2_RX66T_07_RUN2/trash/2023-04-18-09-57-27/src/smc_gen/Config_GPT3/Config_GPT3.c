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
* File Name        : Config_GPT3.c
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
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_GPT3_Create
* Description  : This function initializes the GPT3 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_GPT3_Create(void)
{
    /* Disable GPTW3 interrupts */
    IEN(PERIA,INTA211) = 0U;
    IEN(PERIA,INTA210) = 0U;

    /* Cancel GPTW3 module stop state */
    MSTP(GPTW3) = 0U;

    /* Disable GPTW3 control registers write protect */
    GPTW3.GTWP.LONG = 0x0000A500UL;

    /* Set GPTW3 mode */
    GPTW3.GTCR.LONG = _00000000_GPTn_MODE_SAW_WAVE_PWM;

    /* Set GPTW3 count direction and duty */
    GPTW3.GTUDDTYC.LONG = _00000001_GPTn_COUNT_UP | _00000002_GPTn_COUNT_DIR_FORCE;

    /* Clear GPTW3 count direction forcible set */
    GPTW3.GTUDDTYC.BIT.UDF = 0U;

    /* Set GPTW3 count clock and input capture at count stop */
    GPTW3.GTCR.LONG |= (_00000100_GPTn_NO_INPUTCAP_COUNT_STOP | _01000000_GPTn_COUNT_CLK_PCLKC_4);

    /* Set GPTW3 cycle */
    GPTW3.GTPR = _00061A7F_GPT3_CYCLE_VALUE;

    /* Set GPTW3 counter initial value */
    GPTW3.GTCNT = _00000000_GPT3_INIT_COUNT;

    /* Set GPTW3 count-up sources */
    GPTW3.GTUPSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                        _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                        _00000100_GPTn_GTIOCnA_RISE_GTIOCnB_0_ENABLE | _00000800_GPTn_GTIOCnA_FALL_GTIOCnB_1_ENABLE | 
                        _00002000_GPTn_GTIOCnB_RISE_GTIOCnA_1_ENABLE | _00004000_GPTn_GTIOCnB_FALL_GTIOCnA_0_ENABLE | 
                        _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                        _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                        _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                        _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE;

    /* Set GPTW3 count-down sources */
    GPTW3.GTDNSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                        _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                        _00000200_GPTn_GTIOCnA_RISE_GTIOCnB_1_ENABLE | _00000400_GPTn_GTIOCnA_FALL_GTIOCnB_0_ENABLE | 
                        _00001000_GPTn_GTIOCnB_RISE_GTIOCnA_0_ENABLE | _00008000_GPTn_GTIOCnB_FALL_GTIOCnA_1_ENABLE | 
                        _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                        _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                        _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                        _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE;

    /* Set GPTW3 start sources */
    GPTW3.GTSSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                       _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                       _00000000_GPTn_GTIOCnA_RISE_DISABLE | _00000000_GPTn_GTIOCnA_FALL_DISABLE | 
                       _00000000_GPTn_GTIOCnB_RISE_DISABLE | _00000000_GPTn_GTIOCnB_FALL_DISABLE | 
                       _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                       _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                       _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                       _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE | 
                       _80000000_GPTn_SOFTWARE_SOURCE_ENABLE;

    /* Set GPTW3 stop sources */
    GPTW3.GTPSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                       _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                       _00000000_GPTn_GTIOCnA_RISE_DISABLE | _00000000_GPTn_GTIOCnA_FALL_DISABLE | 
                       _00000000_GPTn_GTIOCnB_RISE_DISABLE | _00000000_GPTn_GTIOCnB_FALL_DISABLE | 
                       _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                       _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                       _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                       _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE | 
                       _80000000_GPTn_SOFTWARE_SOURCE_ENABLE;

    /* Set GPTW3 clear sources */
    GPTW3.GTCSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                       _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                       _00000000_GPTn_GTIOCnA_RISE_DISABLE | _00000000_GPTn_GTIOCnA_FALL_DISABLE | 
                       _00000000_GPTn_GTIOCnB_RISE_DISABLE | _00000000_GPTn_GTIOCnB_FALL_DISABLE | 
                       _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                       _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                       _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                       _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE | 
                       _80000000_GPTn_SOFTWARE_SOURCE_ENABLE;

    /* Set GPTW3 output stop detection */
    GPTW3.GTINTAD.LONG = _00000000_GPTn_OUTPUT_STOP_GROUPA | _00000000_GPTn_SIMHIGH_OUTPUT_STOP_DISABLE | 
                         _00000000_GPTn_SIMLOW_OUTPUT_STOP_DISABLE;

    /* Set GPTW3 noise filter GTIOC3A,GTIOC3B */
    GPTW3.GTIOR.LONG |= (_00000000_GPTn_GTIOCnA_NOISE_FILTER_DISABLE | _00000000_GPTn_GTIOCnB_NOISE_FILTER_DISABLE);

    /* Enable GTIOC3A,GTIOC3B pin output */
    GPTW3.GTIOR.LONG |= (_00000000_GPTn_GTCIOCA_OUTPUT_DISABLE | _00000000_GPTn_GTCIOCB_OUTPUT_DISABLE);

    /* Set GPTW3 buffer operations */
    GPTW3.GTBER.LONG = _00000001_GPTn_GTCCR_BUF_OP_DISABLE | _00000002_GPTn_GTPR_BUF_OP_DISABLE | 
                       _00000004_GPTn_GTADTR_BUF_OP_DISABLE | _00000000_GPTn_GTCCRA_BUF_NONE | 
                       _00000000_GPTn_GTCCRB_BUF_NONE | _00000000_GPTn_GTPR_BUF_NONE;

    /* Set GPTW3 compare match value */
    GPTW3.GTCCRA = _00000064_GPT3_COMP_MATCH_A_VALUE;
    GPTW3.GTCCRB = _00000064_GPT3_COMP_MATCH_B_VALUE;
    GPTW3.GTCCRC = _00000064_GPT3_COMP_MATCH_C_VALUE;
    GPTW3.GTCCRD = _00000064_GPT3_COMP_MATCH_D_VALUE;
    GPTW3.GTCCRE = _00000064_GPT3_COMP_MATCH_E_VALUE;
    GPTW3.GTCCRF = _00000064_GPT3_COMP_MATCH_F_VALUE;

    /* Set GPTW3 interrupt and A/D conversion request generation */
    GPTW3.GTINTAD.LONG |= (_00000000_GPTn_ADTRB_DOWNCOUNTING_DISABLE | _00000000_GPTn_ADTRB_UPCOUNTING_DISABLE | 
                          _00000000_GPTn_ADTRA_DOWNCOUNTING_DISABLE | _00000000_GPTn_ADTRA_UPCOUNTING_DISABLE | 
                          _00000040_GPTn_GTCIV_INTERRUPT_ENABLE | _00000080_GPTn_GTCIU_INTERRUPT_ENABLE | 
                          _00000000_GPTn_GTCIF_INTERRUPT_DISABLE | _00000000_GPTn_GTCIE_INTERRUPT_DISABLE | 
                          _00000000_GPTn_GTCID_INTERRUPT_DISABLE | _00000000_GPTn_GTCIC_INTERRUPT_DISABLE | 
                          _00000000_GPTn_GTCIB_INTERRUPT_DISABLE | _00000000_GPTn_GTCIA_INTERRUPT_DISABLE);

    /* Set GPTW3 A/D converter start request signal monitoring */
    GPTW3.GTADSMR.LONG = _00000000_GPTn_AD_START_MONITOR0_DISABLE | _00000000_GPTn_AD_START_MONITOR1_DISABLE;

    /* Set GPTW3 interrupt and A/D conversion request skipping */
    GPTW3.GTITC.LONG = _00000000_GPTn_GTCI_SKIP_DISABLE | _00000000_GPTn_GTCI_SKIPPING_COUNT_0;

    /* Set GPTW3 extended interrupt skipping counter control */
    GPTW3.GTEITC.LONG = _00000000_GPTn_EXT1_SKIP_DISABLE | _00000000_GPTn_EXT2_SKIP_DISABLE;

    /* Disable rising and falling edge adjustment circuit */
    HRPWM.HROCR2.BIT.HRDIS3 = 1U;

    /* Configure GPTW3 interrupts */
    ICU.SLIAR211.BYTE = 0x5AU;
    IPR(PERIA,INTA211) = _0F_GPT_PRIORITY_LEVEL15;
    ICU.SLIAR210.BYTE = 0x5BU;
    IPR(PERIA,INTA210) = _0F_GPT_PRIORITY_LEVEL15;

    /* Set GTIOC3A pin */
    MPC.PD7PFS.BYTE = 0x15U;
    PORTD.PMR.BYTE |= 0x80U;

    /* Set GTIOC3B pin */
    MPC.PD6PFS.BYTE = 0x15U;
    PORTD.PMR.BYTE |= 0x40U;

    R_Config_GPT3_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_GPT3_Start
* Description  : This function starts the GPT3 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_GPT3_Start(void)
{
    /* Enable GPTW3 interrupts */
    IR(PERIA,INTA211) = 0U;
    IEN(PERIA,INTA211) = 1U;
    IR(PERIA,INTA210) = 0U;
    IEN(PERIA,INTA210) = 1U;

    /* Disable GPTW3 start write protect */
    GPTW3.GTWP.BIT.STRWP = 0U;

    /* Start GPTW3 counting */
    GPTW3.GTSTR.BIT.CSTRT3 = 1U;

    /* Enable GPTW3 start write protect */
    GPTW3.GTWP.BIT.STRWP = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_GPT3_Stop
* Description  : This function stops the GPT3 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_GPT3_Stop(void)
{
    /* Disable GPTW3 interrupts */
    IEN(PERIA,INTA211) = 0U;
    IEN(PERIA,INTA210) = 0U;

    /* Disable GPTW3 start write protect */
    GPTW3.GTWP.BIT.STPWP = 0U;

    /* Stop GPTW3 counting */
    GPTW3.GTSTP.BIT.CSTOP3 = 1U;

    /* Enable GPTW3 start write protect */
    GPTW3.GTWP.BIT.STPWP = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_GPT3_Software_Clear
* Description  : This function software clear the GPT3 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_GPT3_Software_Clear(void)
{
    /* Disable GPTW3 clear write protect */
    GPTW3.GTWP.BIT.CLRWP = 0U;

    /* Clear GPTW3 counter */
    GPTW3.GTCLR.BIT.CCLR3 = 1U;

    /* Enable GPTW3 clear write protect */
    GPTW3.GTWP.BIT.CLRWP = 1U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
