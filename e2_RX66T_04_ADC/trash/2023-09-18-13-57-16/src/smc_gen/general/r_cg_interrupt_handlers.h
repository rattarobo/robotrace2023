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
* Version          : 1.0.120
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
/* BSC BUSERR */
void bus_error_isr(void) __attribute__ ((interrupt));

/* CMT0 CMI0 */
void r_Config_CMT0_cmi0_interrupt(void) __attribute__ ((interrupt));

/* CMT1 CMI1 */
void r_Config_CMT1_cmi1_interrupt(void) __attribute__ ((interrupt));

/* SCI1 RXI1 */
void r_Config_SCI1_receive_interrupt(void) __attribute__ ((interrupt));

/* SCI1 TXI1 */
void r_Config_SCI1_transmit_interrupt(void) __attribute__ ((interrupt));

/* ICU GROUPBL0 */
void group_bl0_handler_isr(void) __attribute__ ((interrupt));

/* ICU GROUPBL1 */
void group_bl1_handler_isr(void) __attribute__ ((interrupt));

/* ICU GROUPAL0 */
void group_al0_handler_isr(void) __attribute__ ((interrupt));

/* DMAC DMAC0I */
void r_Config_DMAC0_dmac0i_interrupt(void) __attribute__ ((interrupt));

/* S12AD S12ADI */
void r_Config_S12AD0_interrupt(void) __attribute__ ((interrupt));

/* S12AD1 S12ADI1 */
void r_Config_S12AD1_interrupt(void) __attribute__ ((interrupt));

/* S12AD2 S12ADI2 */
void r_Config_S12AD2_interrupt(void) __attribute__ ((interrupt));

/* Idle Vectors */
void undefined_interrupt_source_isr(void) __attribute__ ((interrupt));
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
