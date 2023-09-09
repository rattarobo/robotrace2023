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
* File Name        : r_cg_interrupt_handlers.h
* Version          : 1.0.111
* Device(s)        : R5F566TEAxFM
* Description      : This file declares interrupt handlers.
***********************************************************************************************************************/

#ifndef INTERRUPT_HANDLERS_H
#define INTERRUPT_HANDLERS_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* CMT0 CMI0 */
void r_Config_CMT0_cmi0_interrupt(void) __attribute__ ((interrupt(".rvectors",VECT(CMT0,CMI0))));

/* CMT1 CMI1 */
void r_Config_CMT1_cmi1_interrupt(void) __attribute__ ((interrupt(".rvectors",VECT(CMT1,CMI1))));

/* RSPI0 SPRI0 */
void r_Config_RSPI0_receive_interrupt(void) __attribute__ ((interrupt(".rvectors",VECT(RSPI0,SPRI0))));

/* RSPI0 SPTI0 */
void r_Config_RSPI0_transmit_interrupt(void) __attribute__ ((interrupt(".rvectors",VECT(RSPI0,SPTI0))));

/* SCI1 RXI1 */
void r_Config_SCI1_receive_interrupt(void) __attribute__ ((interrupt(".rvectors",VECT(SCI1,RXI1))));

/* SCI1 TXI1 */
void r_Config_SCI1_transmit_interrupt(void) __attribute__ ((interrupt(".rvectors",VECT(SCI1,TXI1))));

/* DMAC DMAC0I */
void r_Config_DMAC0_dmac0i_interrupt(void) __attribute__ ((interrupt(".rvectors",VECT(DMAC,DMAC0I))));

/* S12AD S12ADI */
void r_Config_S12AD0_interrupt(void) __attribute__ ((interrupt(".rvectors",VECT(S12AD,S12ADI))));

/* S12AD1 S12ADI1 */
void r_Config_S12AD1_interrupt(void) __attribute__ ((interrupt(".rvectors",VECT(S12AD1,S12ADI1))));

/* S12AD2 S12ADI2 */
void r_Config_S12AD2_interrupt(void) __attribute__ ((interrupt(".rvectors",VECT(S12AD2,S12ADI2))));

/* GPTW2 GTCIU2 */
void r_Config_GPT2_gtciu2_interrupt(void) __attribute__ ((interrupt(".rvectors",VECT(PERIA,INTA208))));

/* GPTW2 GTCIV2 */
void r_Config_GPT2_gtciv2_interrupt(void) __attribute__ ((interrupt(".rvectors",VECT(PERIA,INTA209))));

/* GPTW3 GTCIU3 */
void r_Config_GPT3_gtciu3_interrupt(void) __attribute__ ((interrupt(".rvectors",VECT(PERIA,INTA210))));

/* GPTW3 GTCIV3 */
void r_Config_GPT3_gtciv3_interrupt(void) __attribute__ ((interrupt(".rvectors",VECT(PERIA,INTA211))));

/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
