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
* File Name        : Config_S12AD2.c
* Component Version: 2.5.0
* Device(s)        : R5F566TEAxFM
* Description      : This file implements device driver for Config_S12AD2.
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
#include "Config_S12AD2.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_S12AD2_Create
* Description  : This function initializes the S12AD2 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD2_Create(void)
{
    /* Cancel S12AD2 module stop state */
    MSTP(S12AD2) = 0U;

    /* Disable and clear interrupt flags of S12AD2 module */
    S12AD2.ADCSR.BIT.ADIE = 0U;
    S12AD2.ADCMPCR.BIT.CMPAIE = 0U;
    S12AD2.ADCMPCR.BIT.CMPBIE = 0U;
    IR(S12AD2, S12ADI2) = 0U;
    IEN(S12AD2, S12ADI2) = 0U;

    /* Set S12AD2 control registers */
    S12AD2.ADCSR.WORD = _0000_AD_DBLTRIGGER_DISABLE | _0000_AD_SYNCASYNCTRG_DISABLE | _0000_AD_SINGLE_SCAN_MODE;
    S12AD2.ADADC.BYTE = _03_AD_4_TIME_CONVERSION | _80_AD_AVERAGE_MODE;
    S12AD2.ADDISCR.BYTE = _00_AD_DISCONECT_UNUSED;

    /* Set channels and sampling time */
    S12AD2.ADSSTR0 = _3C_AD2_SAMPLING_STATE_0;
    S12AD2.ADSSTR1 = _3C_AD2_SAMPLING_STATE_1;
    S12AD2.ADSSTR2 = _3C_AD2_SAMPLING_STATE_2;
    S12AD2.ADSSTRL = _3C_AD2_SAMPLING_STATE_L;
    S12AD2.ADANSA0.WORD = _0001_AD_ANx00_USED | _0002_AD_ANx01_USED | _0004_AD_ANx02_USED;
    S12AD2.ADANSA1.WORD = _0001_AD_AN216_USED | _0002_AD_AN217_USED;
    S12AD2.ADADS0.WORD = _0001_AD_ANx00_ADD_USED | _0002_AD_ANx01_ADD_USED | _0004_AD_ANx02_ADD_USED;
    S12AD2.ADADS1.WORD = _0001_AD_AN216_ADD_USED | _0002_AD_AN217_ADD_USED;
    S12AD2.ADCER.WORD = _0000_AD_AUTO_CLEARING_DISABLE | _0000_AD_SELFTDIAGST_DISABLE | _0000_AD_RIGHT_ALIGNMENT;
    S12AD2.ADELCCR.BYTE = _02_ALL_SCAN_COMPLETION;
    S12AD2.ADCSR.WORD |= _1000_AD_SCAN_END_INTERRUPT_ENABLE;

    /* Set compare control register */
    S12AD2.ADCMPCR.WORD = _0000_AD_WINDOWB_DISABLE | _0000_AD_WINDOWA_DISABLE | _0000_AD_WINDOWFUNCTION_DISABLE;

    /* Set interrupt and priority level */
    IPR(S12AD2, S12ADI2) = _0F_AD_PRIORITY_LEVEL15;

    /* Set AN200 pin */
    PORT5.PMR.BYTE &= 0xFBU;
    PORT5.PDR.BYTE &= 0xFBU;
    MPC.P52PFS.BYTE = 0x80U;

    /* Set AN201 pin */
    PORT5.PMR.BYTE &= 0xF7U;
    PORT5.PDR.BYTE &= 0xF7U;
    MPC.P53PFS.BYTE = 0x80U;

    /* Set AN202 pin */
    PORT5.PMR.BYTE &= 0xEFU;
    PORT5.PDR.BYTE &= 0xEFU;
    MPC.P54PFS.BYTE = 0x80U;

    /* Set AN216 pin */
    PORT2.PMR.BYTE &= 0xFEU;
    PORT2.PDR.BYTE &= 0xFEU;
    MPC.P20PFS.BYTE = 0x80U;

    /* Set AN217 pin */
    PORT2.PMR.BYTE &= 0xFDU;
    PORT2.PDR.BYTE &= 0xFDU;
    MPC.P21PFS.BYTE = 0x80U;

    R_Config_S12AD2_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_S12AD2_Start
* Description  : This function starts the AD2 converter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD2_Start(void)
{
    IR(S12AD2, S12ADI2) = 0U;
    IEN(S12AD2, S12ADI2) = 1U;
    S12AD2.ADCSR.BIT.ADST = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_S12AD2_Stop
* Description  : This function stops the AD2 converter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD2_Stop(void)
{
    S12AD2.ADCSR.BIT.ADST = 0U;
    IEN(S12AD2, S12ADI2) = 0U;
    IR(S12AD2, S12ADI2) = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_S12AD2_Get_ValueResult
* Description  : This function gets result from the AD2 converter
* Arguments    : channel -
*                    channel of data register to be read
*                buffer -
*                    buffer pointer
* Return Value : None
***********************************************************************************************************************/

void R_Config_S12AD2_Get_ValueResult(ad_channel_t channel, uint16_t * const buffer)
{
    switch (channel)
    {
        case ADSELFDIAGNOSIS:
        {
            *buffer = (uint16_t)(S12AD2.ADRD.WORD);
            break;
        }
        case ADCHANNEL0:
        {
            *buffer = (uint16_t)(S12AD2.ADDR0);
            break;
        }
        case ADCHANNEL1:
        {
            *buffer = (uint16_t)(S12AD2.ADDR1);
            break;
        }
        case ADCHANNEL2:
        {
            *buffer = (uint16_t)(S12AD2.ADDR2);
            break;
        }
        case ADCHANNEL3:
        {
            *buffer = (uint16_t)(S12AD2.ADDR3);
            break;
        }
        case ADCHANNEL4:
        {
            *buffer = (uint16_t)(S12AD2.ADDR4);
            break;
        }
        case ADCHANNEL5:
        {
            *buffer = (uint16_t)(S12AD2.ADDR5);
            break;
        }
        case ADCHANNEL6:
        {
            *buffer = (uint16_t)(S12AD2.ADDR6);
            break;
        }
        case ADCHANNEL7:
        {
            *buffer = (uint16_t)(S12AD2.ADDR7);
            break;
        }
        case ADCHANNEL8:
        {
            *buffer = (uint16_t)(S12AD2.ADDR8);
            break;
        }
        case ADCHANNEL9:
        {
            *buffer = (uint16_t)(S12AD2.ADDR9);
            break;
        }
        case ADCHANNEL10:
        {
            *buffer = (uint16_t)(S12AD2.ADDR10);
            break;
        }
        case ADCHANNEL11:
        {
            *buffer = (uint16_t)(S12AD2.ADDR11);
            break;
        }
        case ADCHANNEL16:
        {
            *buffer = (uint16_t)(S12AD2.ADDR16);
            break;
        }
        case ADCHANNEL17:
        {
            *buffer = (uint16_t)(S12AD2.ADDR17);
            break;
        }
        case ADTEMPSENSOR:
        {
            *buffer = (uint16_t)(S12AD2.ADTSDR);
            break;
        }
        case ADINTERREFVOLT:
        {
            *buffer = (uint16_t)(S12AD2.ADOCDR);
            break;
        }
        case ADDATADUPLICATIONA:
        {
            *buffer = (uint16_t)(S12AD2.ADDBLDRA);
            break;
        }
        case ADDATADUPLICATIONB:
        {
            *buffer = (uint16_t)(S12AD2.ADDBLDRB);
            break;
        }
        case ADDATADUPLICATION:
        {
            *buffer = (uint16_t)(S12AD2.ADDBLDR);
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
