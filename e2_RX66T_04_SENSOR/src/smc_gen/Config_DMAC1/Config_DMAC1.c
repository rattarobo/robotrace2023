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
* File Name        : Config_DMAC1.c
* Component Version: 1.8.0
* Device(s)        : R5F566TEAxFM
* Description      : This file implements device driver for Config_DMAC1.
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
#include "Config_DMAC1.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_DMAC1_Create
* Description  : This function initializes the DMAC1 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_DMAC1_Create(void)
{
    /* Cancel DMAC/DTC module stop state in LPC */
    MSTP(DMAC) = 0U;

    /* Disable DMAC interrupts */
    IEN(DMAC,DMAC1I) = 0U;

    /* Disable DMAC1 transfer */
    DMAC1.DMCNT.BIT.DTE = 0U;

    /* Set DMAC1 transfer address update and extended repeat setting */
    DMAC1.DMAMD.WORD = _0000_DMAC_SRC_ADDR_UPDATE_FIXED | _0000_DMAC_DST_ADDR_UPDATE_FIXED | 
                       _0000_DMAC1_SRC_EXT_RPT_AREA | _0000_DMAC1_DST_EXT_RPT_AREA;

    /* Set DMAC1 transfer mode, data size and repeat area */
    DMAC1.DMTMD.WORD = _0000_DMAC_TRANS_MODE_NORMAL | _2000_DMAC_REPEAT_AREA_NONE | _0000_DMAC_TRANS_DATA_SIZE_8 | 
                       _0000_DMAC_TRANS_REQ_SOURCE_SOFTWARE;

    /* Set DMAC1 software start bit auto clear */
    DMAC1.DMREQ.BYTE = _00_DMAC_TRIGGER_SOFTWARE_CLEAR_AUTO;

    /* Set DMAC1 source address */
    DMAC1.DMSAR = (void *)_00000000_DMAC1_SRC_ADDR;

    /* Set DMAC1 destination address */
    DMAC1.DMDAR = (void *)_00000000_DMAC1_DST_ADDR;

    /* Set DMAC1 transfer count */
    DMAC1.DMCRA = _00000001_DMAC1_DMCRA_COUNT;

    /* Enable DMAC activation */
    DMAC.DMAST.BIT.DMST = 1U;
    
    R_Config_DMAC1_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_DMAC1_Start
* Description  : This function enable the DMAC1 activation
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_DMAC1_Start(void)
{
    DMAC1.DMCNT.BIT.DTE = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_DMAC1_Stop
* Description  : This function disable the DMAC1 activation
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_DMAC1_Stop(void)
{
    DMAC1.DMCNT.BIT.DTE = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_DMAC1_Set_SoftwareTrigger
* Description  : This function set the DMAC1 software trigger
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_DMAC1_Set_SoftwareTrigger(void)
{
    DMAC1.DMREQ.BIT.SWREQ = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_DMAC1_Clear_SoftwareTrigger
* Description  : This function clear the DMAC1 software trigger
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_DMAC1_Clear_SoftwareTrigger(void)
{
    DMAC1.DMREQ.BIT.SWREQ = 0U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
