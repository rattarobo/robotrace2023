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
* File Name        : Config_DMAC1_user.c
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
#include "Config_SCI1.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_DMAC1_Create_UserInit
* Description  : This function adds user code after initializing the DMAC1 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_DMAC1_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
	/* Set DMAC1 destination address */
	DMAC1.DMDAR = (void *)&SCI1.TDR;
	/* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
MD_STATUS R_DMAC1_AsyncTransmit(uint8_t * const tx_buf, const uint16_t tx_num)
{
	MD_STATUS status = MD_OK;
uint8_t * source_address = tx_buf;
// Set DMAC1 transfer count
DMAC1.DMCRA = tx_num;
// Enables DMA transfer
R_Config_DMAC1_Start();
while(DMAC1.DMCRA > 0)  {
// Set DMAC1 source address
DMAC1.DMSAR = (void *) source_address;
source_address++;
// DMA transfer request
R_Config_DMAC1_Set_SoftwareTrigger();
// Sends SCI8 data
R_SCI1_AsyncTransmit(NULL, 1);
}
return (status);
}


/* End user code. Do not edit comment generated here */
