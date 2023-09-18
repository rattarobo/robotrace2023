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
* File Name        : r_cg_vector_table.c
* Version          : 1.0.120
* Device(s)        : R5F566TEAxFM
* Description      : This file implements interrupt vector table.
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
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
void * const Reserved_Vector[] __attribute((section(".rvectors"))) =
{
    /* 0x0000 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0004 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0008 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x000C Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0010 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0014 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0018 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x001C Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0020 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0024 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0028 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x002C Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0030 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0034 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0038 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x003C Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0040 BSC BUSERR */
    bus_error_isr,
    /* 0x0044 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0048 RAM RAMERR */
    undefined_interrupt_source_isr,
    /* 0x004C Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0050 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0054 FCU FIFERR */
    undefined_interrupt_source_isr,
    /* 0x0058 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x005C FCU FRDYI */
    undefined_interrupt_source_isr,
    /* 0x0060 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0064 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0068 ICU SWINT2 */
    undefined_interrupt_source_isr,
    /* 0x006C ICU SWINT */
    undefined_interrupt_source_isr,
    /* 0x0070 CMT0 CMI0 */
    r_Config_CMT0_cmi0_interrupt,
    /* 0x0074 CMT1 CMI1 */
    r_Config_CMT1_cmi1_interrupt,
    /* 0x0078 CMT2 CMI2 */
    undefined_interrupt_source_isr,
    /* 0x007C CMT3 CMI3 */
    undefined_interrupt_source_isr,
    /* 0x0080 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0084 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0088 USB0 D0FIFO0 */
    undefined_interrupt_source_isr,
    /* 0x008C USB0 D1FIFO0 */
    undefined_interrupt_source_isr,
    /* 0x0090 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0094 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0098 RSPI0 SPRI0 */
    undefined_interrupt_source_isr,
    /* 0x009C RSPI0 SPTI0 */
    undefined_interrupt_source_isr,
    /* 0x00A0 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00A4 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00A8 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00AC Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00B0 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00B4 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00B8 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00BC Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00C0 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00C4 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00C8 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00CC Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00D0 RIIC0 RXI0 */
    undefined_interrupt_source_isr,
    /* 0x00D4 RIIC0 TXI0 */
    undefined_interrupt_source_isr,
    /* 0x00D8 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00DC Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00E0 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00E4 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00E8 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00EC Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00F0 SCI1 RXI1 */
    r_Config_SCI1_receive_interrupt,
    /* 0x00F4 SCI1 TXI1 */
    r_Config_SCI1_transmit_interrupt,
    /* 0x00F8 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x00FC Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0100 ICU IRQ0 */
    undefined_interrupt_source_isr,
    /* 0x0104 ICU IRQ1 */
    undefined_interrupt_source_isr,
    /* 0x0108 ICU IRQ2 */
    undefined_interrupt_source_isr,
    /* 0x010C ICU IRQ3 */
    undefined_interrupt_source_isr,
    /* 0x0110 ICU IRQ4 */
    undefined_interrupt_source_isr,
    /* 0x0114 ICU IRQ5 */
    undefined_interrupt_source_isr,
    /* 0x0118 ICU IRQ6 */
    undefined_interrupt_source_isr,
    /* 0x011C ICU IRQ7 */
    undefined_interrupt_source_isr,
    /* 0x0120 ICU IRQ8 */
    undefined_interrupt_source_isr,
    /* 0x0124 ICU IRQ9 */
    undefined_interrupt_source_isr,
    /* 0x0128 ICU IRQ10 */
    undefined_interrupt_source_isr,
    /* 0x012C ICU IRQ11 */
    undefined_interrupt_source_isr,
    /* 0x0130 ICU IRQ12 */
    undefined_interrupt_source_isr,
    /* 0x0134 ICU IRQ13 */
    undefined_interrupt_source_isr,
    /* 0x0138 ICU IRQ14 */
    undefined_interrupt_source_isr,
    /* 0x013C ICU IRQ15 */
    undefined_interrupt_source_isr,
    /* 0x0140 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0144 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0148 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x014C Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0150 SCI5 RXI5 */
    undefined_interrupt_source_isr,
    /* 0x0154 SCI5 TXI5 */
    undefined_interrupt_source_isr,
    /* 0x0158 SCI6 RXI6 */
    undefined_interrupt_source_isr,
    /* 0x015C SCI6 TXI6 */
    undefined_interrupt_source_isr,
    /* 0x0160 LVD1 LVD1 */
    undefined_interrupt_source_isr,
    /* 0x0164 LVD2 LVD2 */
    undefined_interrupt_source_isr,
    /* 0x0168 USB0 USBR0 */
    undefined_interrupt_source_isr,
    /* 0x016C Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0170 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0174 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0178 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x017C IWDT IWUNI */
    undefined_interrupt_source_isr,
    /* 0x0180 WDT WUNI */
    undefined_interrupt_source_isr,
    /* 0x0184 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0188 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x018C Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0190 SCI8 RXI8 */
    undefined_interrupt_source_isr,
    /* 0x0194 SCI8 TXI8 */
    undefined_interrupt_source_isr,
    /* 0x0198 SCI9 RXI9 */
    undefined_interrupt_source_isr,
    /* 0x019C SCI9 TXI9 */
    undefined_interrupt_source_isr,
    /* 0x01A0 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x01A4 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x01A8 ICU GROUPBE0 */
    undefined_interrupt_source_isr,
    /* 0x01AC Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x01B0 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x01B4 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x01B8 ICU GROUPBL0 */
    group_bl0_handler_isr,
    /* 0x01BC ICU GROUPBL1 */
    group_bl1_handler_isr,
    /* 0x01C0 ICU GROUPAL0 */
    group_al0_handler_isr,
    /* 0x01C4 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x01C8 SCI11 RXI11 */
    undefined_interrupt_source_isr,
    /* 0x01CC SCI11 TXI11 */
    undefined_interrupt_source_isr,
    /* 0x01D0 SCI12 RXI12 */
    undefined_interrupt_source_isr,
    /* 0x01D4 SCI12 TXI12 */
    undefined_interrupt_source_isr,
    /* 0x01D8 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x01DC Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x01E0 DMAC DMAC0I */
    r_Config_DMAC0_dmac0i_interrupt,
    /* 0x01E4 DMAC DMAC1I */
    undefined_interrupt_source_isr,
    /* 0x01E8 DMAC DMAC2I */
    undefined_interrupt_source_isr,
    /* 0x01EC DMAC DMAC3I */
    undefined_interrupt_source_isr,
    /* 0x01F0 DMAC DMAC74I */
    undefined_interrupt_source_isr,
    /* 0x01F4 OST OSTDI */
    undefined_interrupt_source_isr,
    /* 0x01F8 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x01FC Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0200 S12AD S12ADI */
    undefined_interrupt_source_isr,
    /* 0x0204 S12AD S12GBADI */
    undefined_interrupt_source_isr,
    /* 0x0208 S12AD S12GCADI */
    undefined_interrupt_source_isr,
    /* 0x020C Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0210 S12AD1 S12ADI1 */
    undefined_interrupt_source_isr,
    /* 0x0214 S12AD1 S12GBADI1 */
    undefined_interrupt_source_isr,
    /* 0x0218 S12AD1 S12GCADI1 */
    undefined_interrupt_source_isr,
    /* 0x021C Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0220 S12AD2 S12ADI2 */
    undefined_interrupt_source_isr,
    /* 0x0224 S12AD2 S12GBADI2 */
    undefined_interrupt_source_isr,
    /* 0x0228 S12AD2 S12GCADI2 */
    undefined_interrupt_source_isr,
    /* 0x022C Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0230 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0234 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0238 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x023C Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0240 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0244 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0248 TMR0 CMIA0 */
    undefined_interrupt_source_isr,
    /* 0x024C TMR0 CMIB0 */
    undefined_interrupt_source_isr,
    /* 0x0250 TMR0 OVI0 */
    undefined_interrupt_source_isr,
    /* 0x0254 TMR1 CMIA1 */
    undefined_interrupt_source_isr,
    /* 0x0258 TMR1 CMIB1 */
    undefined_interrupt_source_isr,
    /* 0x025C TMR1 OVI1 */
    undefined_interrupt_source_isr,
    /* 0x0260 TMR2 CMIA2 */
    undefined_interrupt_source_isr,
    /* 0x0264 TMR2 CMIB2 */
    undefined_interrupt_source_isr,
    /* 0x0268 TMR2 OVI2 */
    undefined_interrupt_source_isr,
    /* 0x026C TMR3 CMIA3 */
    undefined_interrupt_source_isr,
    /* 0x0270 TMR3 CMIB3 */
    undefined_interrupt_source_isr,
    /* 0x0274 TMR3 OVI3 */
    undefined_interrupt_source_isr,
    /* 0x0278 TMR4 CMIA4 */
    undefined_interrupt_source_isr,
    /* 0x027C TMR4 CMIB4 */
    undefined_interrupt_source_isr,
    /* 0x0280 TMR4 OVI4 */
    undefined_interrupt_source_isr,
    /* 0x0284 TMR5 CMIA5 */
    undefined_interrupt_source_isr,
    /* 0x0288 TMR5 CMIB5 */
    undefined_interrupt_source_isr,
    /* 0x028C TMR5 OVI5 */
    undefined_interrupt_source_isr,
    /* 0x0290 TMR6 CMIA6 */
    undefined_interrupt_source_isr,
    /* 0x0294 TMR6 CMIB6 */
    undefined_interrupt_source_isr,
    /* 0x0298 TMR6 OVI6 */
    undefined_interrupt_source_isr,
    /* 0x029C TMR7 CMIA7 */
    undefined_interrupt_source_isr,
    /* 0x02A0 TMR7 CMIB7 */
    undefined_interrupt_source_isr,
    /* 0x02A4 TMR7 OVI7 */
    undefined_interrupt_source_isr,
    /* 0x02A8 CAN0 RXF0 */
    undefined_interrupt_source_isr,
    /* 0x02AC CAN0 TXF0 */
    undefined_interrupt_source_isr,
    /* 0x02B0 CAN0 RXM0 */
    undefined_interrupt_source_isr,
    /* 0x02B4 CAN0 TXM0 */
    undefined_interrupt_source_isr,
    /* 0x02B8 USB0 USBI0 */
    undefined_interrupt_source_isr,
    /* 0x02BC ELC ELSR18I */
    undefined_interrupt_source_isr,
    /* 0x02C0 ELC ELSR19I */
    undefined_interrupt_source_isr,
    /* 0x02C4 TSIP RD */
    undefined_interrupt_source_isr,
    /* 0x02C8 TSIP WR */
    undefined_interrupt_source_isr,
    /* 0x02CC TSIP ERR */
    undefined_interrupt_source_isr,
    /* 0x02D0 CMPC0 CMPC0 */
    undefined_interrupt_source_isr,
    /* 0x02D4 CMPC1 CMPC1 */
    undefined_interrupt_source_isr,
    /* 0x02D8 CMPC2 CMPC2 */
    undefined_interrupt_source_isr,
    /* 0x02DC CMPC3 CMPC3 */
    undefined_interrupt_source_isr,
    /* 0x02E0 CMPC4 CMPC4 */
    undefined_interrupt_source_isr,
    /* 0x02E4 CMPC5 CMPC5 */
    undefined_interrupt_source_isr,
    /* 0x02E8 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x02EC Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x02F0 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x02F4 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x02F8 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x02FC Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0300 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0304 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0308 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x030C Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0310 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0314 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0318 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x031C Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0320 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0324 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0328 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x032C Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0330 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0334 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0338 Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x033C Reserved */
    (void (*)(void))0xFFFFFFFF,
    /* 0x0340 PERIA INTA208 */
    undefined_interrupt_source_isr,
    /* 0x0344 PERIA INTA209 */
    undefined_interrupt_source_isr,
    /* 0x0348 PERIA INTA210 */
    undefined_interrupt_source_isr,
    /* 0x034C PERIA INTA211 */
    undefined_interrupt_source_isr,
    /* 0x0350 PERIA INTA212 */
    undefined_interrupt_source_isr,
    /* 0x0354 PERIA INTA213 */
    undefined_interrupt_source_isr,
    /* 0x0358 PERIA INTA214 */
    undefined_interrupt_source_isr,
    /* 0x035C PERIA INTA215 */
    undefined_interrupt_source_isr,
    /* 0x0360 PERIA INTA216 */
    undefined_interrupt_source_isr,
    /* 0x0364 PERIA INTA217 */
    undefined_interrupt_source_isr,
    /* 0x0368 PERIA INTA218 */
    undefined_interrupt_source_isr,
    /* 0x036C PERIA INTA219 */
    undefined_interrupt_source_isr,
    /* 0x0370 PERIA INTA220 */
    undefined_interrupt_source_isr,
    /* 0x0374 PERIA INTA221 */
    undefined_interrupt_source_isr,
    /* 0x0378 PERIA INTA222 */
    undefined_interrupt_source_isr,
    /* 0x037C PERIA INTA223 */
    undefined_interrupt_source_isr,
    /* 0x0380 PERIA INTA224 */
    undefined_interrupt_source_isr,
    /* 0x0384 PERIA INTA225 */
    undefined_interrupt_source_isr,
    /* 0x0388 PERIA INTA226 */
    undefined_interrupt_source_isr,
    /* 0x038C PERIA INTA227 */
    undefined_interrupt_source_isr,
    /* 0x0390 PERIA INTA228 */
    undefined_interrupt_source_isr,
    /* 0x0394 PERIA INTA229 */
    undefined_interrupt_source_isr,
    /* 0x0398 PERIA INTA230 */
    undefined_interrupt_source_isr,
    /* 0x039C PERIA INTA231 */
    undefined_interrupt_source_isr,
    /* 0x03A0 PERIA INTA232 */
    undefined_interrupt_source_isr,
    /* 0x03A4 PERIA INTA233 */
    undefined_interrupt_source_isr,
    /* 0x03A8 PERIA INTA234 */
    undefined_interrupt_source_isr,
    /* 0x03AC PERIA INTA235 */
    undefined_interrupt_source_isr,
    /* 0x03B0 PERIA INTA236 */
    undefined_interrupt_source_isr,
    /* 0x03B4 PERIA INTA237 */
    undefined_interrupt_source_isr,
    /* 0x03B8 PERIA INTA238 */
    undefined_interrupt_source_isr,
    /* 0x03BC PERIA INTA239 */
    undefined_interrupt_source_isr,
    /* 0x03C0 PERIA INTA240 */
    undefined_interrupt_source_isr,
    /* 0x03C4 PERIA INTA241 */
    undefined_interrupt_source_isr,
    /* 0x03C8 PERIA INTA242 */
    undefined_interrupt_source_isr,
    /* 0x03CC PERIA INTA243 */
    undefined_interrupt_source_isr,
    /* 0x03D0 PERIA INTA244 */
    undefined_interrupt_source_isr,
    /* 0x03D4 PERIA INTA245 */
    undefined_interrupt_source_isr,
    /* 0x03D8 PERIA INTA246 */
    undefined_interrupt_source_isr,
    /* 0x03DC PERIA INTA247 */
    undefined_interrupt_source_isr,
    /* 0x03E0 PERIA INTA248 */
    undefined_interrupt_source_isr,
    /* 0x03E4 PERIA INTA249 */
    undefined_interrupt_source_isr,
    /* 0x03E8 PERIA INTA250 */
    undefined_interrupt_source_isr,
    /* 0x03EC PERIA INTA251 */
    undefined_interrupt_source_isr,
    /* 0x03F0 PERIA INTA252 */
    undefined_interrupt_source_isr,
    /* 0x03F4 PERIA INTA253 */
    undefined_interrupt_source_isr,
    /* 0x03F8 PERIA INTA254 */
    undefined_interrupt_source_isr,
    /* 0x03FC PERIA INTA255 */
    undefined_interrupt_source_isr
};
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
