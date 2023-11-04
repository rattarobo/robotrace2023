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
* File Name        : Config_GPT4.h
* Component Version: 1.5.2
* Device(s)        : R5F566TEAxFM
* Description      : This file implements device driver for Config_GPT4.
***********************************************************************************************************************/

#ifndef CFG_Config_GPT4_H
#define CFG_Config_GPT4_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_gpt.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define GPT4_PCLK_COUNTER_DIVISION                      (2)
#define _0000EA5F_GPT4_CYCLE_VALUE                      (0x0000EA5FUL) /* GPT4 cycle register value */
#define _00000000_GPT4_INIT_COUNT                       (0x00000000UL) /* GPT4 initial counter value */
#define _00000064_GPT4_COMP_MATCH_A_VALUE               (0x00000064UL) /* GPT4 compare match A value */
#define _00000064_GPT4_COMP_MATCH_B_VALUE               (0x00000064UL) /* GPT4 compare match B value */
#define _00000064_GPT4_COMP_MATCH_C_VALUE               (0x00000064UL) /* GPT4 compare match C value */
#define _00000064_GPT4_COMP_MATCH_D_VALUE               (0x00000064UL) /* GPT4 compare match D value */
#define _00000064_GPT4_COMP_MATCH_E_VALUE               (0x00000064UL) /* GPT4 compare match E value */
#define _00000064_GPT4_COMP_MATCH_F_VALUE               (0x00000064UL) /* GPT4 compare match F value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_GPT4_Create(void);
void R_Config_GPT4_Create_UserInit(void);
void R_Config_GPT4_Start(void);
void R_Config_GPT4_Stop(void);
void R_Config_GPT4_Software_Clear(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
