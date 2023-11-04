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
* File Name        : Config_GPT4.c
* Component Version: 1.5.2
* Device(s)        : R5F566TEAxFM
* Description      : This file implements device driver for Config_GPT4.
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
#include "Config_GPT4.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_GPT4_Create
* Description  : This function initializes the GPT4 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_GPT4_Create(void)
{
    /* Cancel GPTW4 module stop state */
    MSTP(GPTW4) = 0U;

    /* Disable GPTW4 control registers write protect */
    GPTW4.GTWP.LONG = 0x0000A500UL;

    /* Set GPTW4 mode */
    GPTW4.GTCR.LONG = _00000000_GPTn_MODE_SAW_WAVE_PWM;

    /* Set GPTW4 count direction and duty */
    GPTW4.GTUDDTYC.LONG = _00000001_GPTn_COUNT_UP | _00000002_GPTn_COUNT_DIR_FORCE | 
                          _00000000_GPTn_GTIOCnA_DUTYCYCLE_COMPARE | _00000000_GPTn_GTIOCnB_DUTYCYCLE_COMPARE;

    /* Clear GPTW4 count direction forcible set */
    GPTW4.GTUDDTYC.BIT.UDF = 0U;

    /* Set GPTW4 count clock and input capture at count stop */
    GPTW4.GTCR.LONG |= (_00000100_GPTn_NO_INPUTCAP_COUNT_STOP | _00800000_GPTn_COUNT_CLK_PCLKC_2);

    /* Set GPTW4 cycle */
    GPTW4.GTPR = _0000EA5F_GPT4_CYCLE_VALUE;

    /* Set GPTW4 counter initial value */
    GPTW4.GTCNT = _00000000_GPT4_INIT_COUNT;

    /* Set GPTW4 count-up sources */
    GPTW4.GTUPSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                        _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                        _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                        _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                        _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                        _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE;

    /* Set GPTW4 count-down sources */
    GPTW4.GTDNSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                        _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                        _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                        _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                        _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                        _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE;

    /* Set GPTW4 start sources */
    GPTW4.GTSSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                       _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                       _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                       _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                       _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                       _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE | 
                       _80000000_GPTn_SOFTWARE_SOURCE_ENABLE;

    /* Set GPTW4 stop sources */
    GPTW4.GTPSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                       _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                       _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                       _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                       _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                       _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE | 
                       _80000000_GPTn_SOFTWARE_SOURCE_ENABLE;

    /* Set GPTW4 clear sources */
    GPTW4.GTCSR.LONG = _00000000_GPTn_GTETRGA_DISABLE | _00000000_GPTn_GTETRGB_DISABLE | 
                       _00000000_GPTn_GTETRGC_DISABLE | _00000000_GPTn_GTETRGD_DISABLE | 
                       _00000000_GPTn_ELCA_INPUT_DISABLE | _00000000_GPTn_ELCB_INPUT_DISABLE | 
                       _00000000_GPTn_ELCC_INPUT_DISABLE | _00000000_GPTn_ELCD_INPUT_DISABLE | 
                       _00000000_GPTn_ELCE_INPUT_DISABLE | _00000000_GPTn_ELCF_INPUT_DISABLE | 
                       _00000000_GPTn_ELCG_INPUT_DISABLE | _00000000_GPTn_ELCH_INPUT_DISABLE | 
                       _80000000_GPTn_SOFTWARE_SOURCE_ENABLE;

    /* Set GPTW4 output stop detection */
    GPTW4.GTINTAD.LONG = _00000000_GPTn_OUTPUT_STOP_GROUPA | _00000000_GPTn_SIMHIGH_OUTPUT_STOP_DISABLE | 
                         _00000000_GPTn_SIMLOW_OUTPUT_STOP_DISABLE;

    /* Set GTIOC4A,GTIOC4B pin function */
    GPTW4.GTIOR.LONG = _00000003_GPTn_GTIOCA_COMP_MATCH_TOGGLE | _00000000_GPTn_GTIOCA_CYCLE_END_RETAIN | 
                       _00000000_GPTn_GTIOCA_INIT_OUT_LOW | _00000000_GPTn_GTIOCA_OUTPUT_ON_STOP_0 | 
                       _00000000_GPTn_GTIOCA_OUTPUT_ON_START_SET | _00000000_GPTn_GTIOCnA_NEG_DISABEL | 
                       _00030000_GPTn_GTIOCB_COMP_MATCH_TOGGLE | _00000000_GPTn_GTIOCB_CYCLE_END_RETAIN | 
                       _00000000_GPTn_GTIOCB_INIT_OUT_LOW | _00000000_GPTn_GTIOCB_OUTPUT_ON_STOP_0 | 
                       _00000000_GPTn_GTIOCB_OUTPUT_ON_START_SET | _00000000_GPTn_GTIOCnB_NEG_DISABEL;

    /* Enable GTIOC4A,GTIOC4B pin output */
    GPTW4.GTIOR.LONG |= (_00000100_GPTn_GTIOCnA_OUTPUT_ENABLE | _01000000_GPTn_GTIOCnB_OUTPUT_ENABLE);

    /* Set GPTW4 buffer operations */
    GPTW4.GTBER.LONG = _00000001_GPTn_GTCCR_BUF_OP_DISABLE | _00000002_GPTn_GTPR_BUF_OP_DISABLE | 
                       _00000004_GPTn_GTADTR_BUF_OP_DISABLE | _00000000_GPTn_GTCCRA_BUF_NONE | 
                       _00000000_GPTn_GTCCRB_BUF_NONE | _00000000_GPTn_GTPR_BUF_NONE;

    /* Set GPTW4 compare match value */
    GPTW4.GTCCRA = _00000064_GPT4_COMP_MATCH_A_VALUE;
    GPTW4.GTCCRB = _00000064_GPT4_COMP_MATCH_B_VALUE;
    GPTW4.GTCCRC = _00000064_GPT4_COMP_MATCH_C_VALUE;
    GPTW4.GTCCRD = _00000064_GPT4_COMP_MATCH_D_VALUE;
    GPTW4.GTCCRE = _00000064_GPT4_COMP_MATCH_E_VALUE;
    GPTW4.GTCCRF = _00000064_GPT4_COMP_MATCH_F_VALUE;

    /* Set GPTW4 interrupt and A/D conversion request generation */
    GPTW4.GTINTAD.LONG |= (_00000000_GPTn_ADTRB_DOWNCOUNTING_DISABLE | _00000000_GPTn_ADTRB_UPCOUNTING_DISABLE | 
                          _00000000_GPTn_ADTRA_DOWNCOUNTING_DISABLE | _00000000_GPTn_ADTRA_UPCOUNTING_DISABLE | 
                          _00000000_GPTn_GTCIV_INTERRUPT_DISABLE | _00000000_GPTn_GTCIU_INTERRUPT_DISABLE | 
                          _00000000_GPTn_GTCIF_INTERRUPT_DISABLE | _00000000_GPTn_GTCIE_INTERRUPT_DISABLE | 
                          _00000000_GPTn_GTCID_INTERRUPT_DISABLE | _00000000_GPTn_GTCIC_INTERRUPT_DISABLE | 
                          _00000000_GPTn_GTCIB_INTERRUPT_DISABLE | _00000000_GPTn_GTCIA_INTERRUPT_DISABLE);

    /* Set GPTW4 A/D converter start request signal monitoring */
    GPTW4.GTADSMR.LONG = _00000000_GPTn_AD_START_MONITOR0_DISABLE | _00000000_GPTn_AD_START_MONITOR1_DISABLE;

    /* Set GPTW4 interrupt and A/D conversion request skipping */
    GPTW4.GTITC.LONG = _00000000_GPTn_GTCI_SKIP_DISABLE | _00000000_GPTn_GTCI_SKIPPING_COUNT_0;

    /* Set GPTW4 extended interrupt skipping counter control */
    GPTW4.GTEITC.LONG = _00000000_GPTn_EXT1_SKIP_DISABLE | _00000000_GPTn_EXT2_SKIP_DISABLE;

    /* Set GTIOC4A pin */
    MPC.P95PFS.BYTE = 0x14U;
    PORT9.PMR.BYTE |= 0x20U;

    /* Set GTIOC4B pin */
    MPC.P92PFS.BYTE = 0x14U;
    PORT9.PMR.BYTE |= 0x04U;

    R_Config_GPT4_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_GPT4_Start
* Description  : This function starts the GPT4 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_GPT4_Start(void)
{
    /* Disable GPTW4 start write protect */
    GPTW4.GTWP.BIT.STRWP = 0U;

    /* Start GPTW4 counting */
    GPTW4.GTSTR.BIT.CSTRT4 = 1U;

    /* Enable GPTW4 start write protect */
    GPTW4.GTWP.BIT.STRWP = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_GPT4_Stop
* Description  : This function stops the GPT4 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_GPT4_Stop(void)
{
    /* Disable GPTW4 start write protect */
    GPTW4.GTWP.BIT.STPWP = 0U;

    /* Stop GPTW4 counting */
    GPTW4.GTSTP.BIT.CSTOP4 = 1U;

    /* Enable GPTW4 start write protect */
    GPTW4.GTWP.BIT.STPWP = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_GPT4_Software_Clear
* Description  : This function software clear the GPT4 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_GPT4_Software_Clear(void)
{
    /* Disable GPTW4 clear write protect */
    GPTW4.GTWP.BIT.CLRWP = 0U;

    /* Clear GPTW4 counter */
    GPTW4.GTCLR.BIT.CCLR4 = 1U;

    /* Enable GPTW4 clear write protect */
    GPTW4.GTWP.BIT.CLRWP = 1U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
