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
* File Name        : Config_S12AD0.c
* Component Version: 2.5.0
* Device(s)        : R5F566TEAxFM
* Description      : This file implements device driver for Config_S12AD0.
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
#include "Config_S12AD0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_S12AD0_Create
* Description  : This function initializes the S12AD0 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD0_Create(void)
{
    /* Cancel S12AD0 module stop state */
    MSTP(S12AD) = 0U;

    /* Disable and clear interrupt flags of S12AD0 module */
    S12AD.ADCSR.BIT.ADIE = 0U;
    S12AD.ADCMPCR.BIT.CMPAIE = 0U;
    S12AD.ADCMPCR.BIT.CMPBIE = 0U;
    IR(S12AD, S12ADI) = 0U;
    IEN(S12AD, S12ADI) = 0U;

    /* Set S12AD0 control registers */
    S12AD.ADCSR.WORD = _0000_AD_DBLTRIGGER_DISABLE | _0000_AD_SYNCASYNCTRG_DISABLE | _0000_AD_SINGLE_SCAN_MODE;
    S12AD.ADADC.BYTE = _03_AD_4_TIME_CONVERSION | _80_AD_AVERAGE_MODE;
    S12AD.ADDISCR.BYTE = _00_AD_DISCONECT_UNUSED;

    /* Set channels and sampling time */
    S12AD.ADSSTR0 = _1B_AD0_SAMPLING_STATE_0;
    S12AD.ADSSTR1 = _1B_AD0_SAMPLING_STATE_1;
    S12AD.ADSSTR2 = _1B_AD0_SAMPLING_STATE_2;
    S12AD.ADSSTR7 = _1B_AD0_SAMPLING_STATE_7;
    S12AD.ADANSA0.WORD = _0001_AD_ANx00_USED | _0002_AD_ANx01_USED | _0004_AD_ANx02_USED;
    S12AD.ADADS0.WORD = _0001_AD_ANx00_ADD_USED | _0002_AD_ANx01_ADD_USED | _0004_AD_ANx02_ADD_USED | 
                        _0080_AD_ANx07_ADD_USED;
    /* Set channel AN007 as a target for conversion */
    S12AD.ADPGADCR0.BIT.P000DEN = 0U;
    S12AD.ADPGADCR0.BIT.P001DEN = 0U;
    S12AD.ADPGADCR0.BIT.P002DEN = 0U;
    S12AD.ADANSA0.WORD |= _0080_AD_ANx07_USED;

    /* Set AN000 amplifier */
    S12AD.ADPGACR.BIT.P000CR = _0001_AD_PATH_ANx_NONE_NONE;

    /* Set AN001 amplifier */
    S12AD.ADPGACR.BIT.P001CR = _0001_AD_PATH_ANx_NONE_NONE;

    /* Set AN002 amplifier */
    S12AD.ADPGACR.BIT.P002CR = _0001_AD_PATH_ANx_NONE_NONE;
    S12AD.ADCER.WORD = _0000_AD_AUTO_CLEARING_DISABLE | _0000_AD_SELFTDIAGST_DISABLE | _0000_AD_RIGHT_ALIGNMENT;
    S12AD.ADELCCR.BYTE = _02_ALL_SCAN_COMPLETION;
    S12AD.ADCSR.WORD |= _1000_AD_SCAN_END_INTERRUPT_ENABLE;

    /* Set compare control register */
    S12AD.ADCMPCR.WORD = _0000_AD_WINDOWB_DISABLE | _0000_AD_WINDOWA_DISABLE | _0000_AD_WINDOWFUNCTION_DISABLE;

    /* Set interrupt and priority level */
    IPR(S12AD, S12ADI) = _0F_AD_PRIORITY_LEVEL15;

    /* Set AN000 pin */
    PORT4.PMR.BYTE &= 0xFEU;
    PORT4.PDR.BYTE &= 0xFEU;
    MPC.P40PFS.BYTE = 0x80U;

    /* Set AN001 pin */
    PORT4.PMR.BYTE &= 0xFDU;
    PORT4.PDR.BYTE &= 0xFDU;
    MPC.P41PFS.BYTE = 0x80U;

    /* Set AN002 pin */
    PORT4.PMR.BYTE &= 0xFBU;
    PORT4.PDR.BYTE &= 0xFBU;
    MPC.P42PFS.BYTE = 0x80U;

    /* Set AN007 pin */
    PORTH.PMR.BYTE &= 0xFEU;
    PORTH.PDR.BYTE &= 0xFEU;
    MPC.PH0PFS.BYTE = 0x80U;

    R_Config_S12AD0_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_S12AD0_Start
* Description  : This function starts the AD0 converter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD0_Start(void)
{
    IR(S12AD, S12ADI) = 0U;
    IEN(S12AD, S12ADI) = 1U;
    S12AD.ADCSR.BIT.ADST = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_S12AD0_Stop
* Description  : This function stops the AD0 converter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD0_Stop(void)
{
    S12AD.ADCSR.BIT.ADST = 0U;
    IEN(S12AD, S12ADI) = 0U;
    IR(S12AD, S12ADI) = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_S12AD0_Get_ValueResult
* Description  : This function gets result from the AD0 converter
* Arguments    : channel -
*                    channel of data register to be read
*                buffer -
*                    buffer pointer
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD0_Get_ValueResult(ad_channel_t channel, uint16_t * const buffer)
{
    switch (channel)
    {
        case ADSELFDIAGNOSIS:
        {
            *buffer = (uint16_t)(S12AD.ADRD.WORD);
            break;
        }
        case ADCHANNEL0:
        {
            *buffer = (uint16_t)(S12AD.ADDR0);
            break;
        }
        case ADCHANNEL1:
        {
            *buffer = (uint16_t)(S12AD.ADDR1);
            break;
        }
        case ADCHANNEL2:
        {
            *buffer = (uint16_t)(S12AD.ADDR2);
            break;
        }
        case ADCHANNEL3:
        {
            *buffer = (uint16_t)(S12AD.ADDR3);
            break;
        }
        case ADCHANNEL4:
        {
            *buffer = (uint16_t)(S12AD.ADDR4);
            break;
        }
        case ADCHANNEL5:
        {
            *buffer = (uint16_t)(S12AD.ADDR5);
            break;
        }
        case ADCHANNEL6:
        {
            *buffer = (uint16_t)(S12AD.ADDR6);
            break;
        }
        case ADCHANNEL7:
        {
            *buffer = (uint16_t)(S12AD.ADDR7);
            break;
        }
        case ADDATADUPLICATIONA:
        {
            *buffer = (uint16_t)(S12AD.ADDBLDRA);
            break;
        }
        case ADDATADUPLICATIONB:
        {
            *buffer = (uint16_t)(S12AD.ADDBLDRB);
            break;
        }
        case ADDATADUPLICATION:
        {
            *buffer = (uint16_t)(S12AD.ADDBLDR.WORD);
            break;
        }
        default:
        {
            break;
        }
    }
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
