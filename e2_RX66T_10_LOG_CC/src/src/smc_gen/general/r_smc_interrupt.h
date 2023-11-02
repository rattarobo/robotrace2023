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
* File Name        : r_smc_interrupt.h
* Version          : 1.2.21
* Device(s)        : R5F566TEAxFM
* Description      : This file implements interrupt setting.
***********************************************************************************************************************/

#ifndef SMC_INTERRUPT_H
#define SMC_INTERRUPT_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/* Priority level of interrupt source. 
 * These macro definitions are used to set the IPR register directly
 */
#define _00_ICU_PRIORITY_LEVEL0                    (0x00U) /* Level 0 (disabled)  */
#define _01_ICU_PRIORITY_LEVEL1                    (0x01U) /* Level 1  */
#define _02_ICU_PRIORITY_LEVEL2                    (0x02U) /* Level 2  */
#define _03_ICU_PRIORITY_LEVEL3                    (0x03U) /* Level 3  */
#define _04_ICU_PRIORITY_LEVEL4                    (0x04U) /* Level 4  */
#define _05_ICU_PRIORITY_LEVEL5                    (0x05U) /* Level 5  */
#define _06_ICU_PRIORITY_LEVEL6                    (0x06U) /* Level 6  */
#define _07_ICU_PRIORITY_LEVEL7                    (0x07U) /* Level 7  */
#define _08_ICU_PRIORITY_LEVEL8                    (0x08U) /* Level 8  */
#define _09_ICU_PRIORITY_LEVEL9                    (0x09U) /* Level 9  */
#define _0A_ICU_PRIORITY_LEVEL10                   (0x0AU) /* Level 10  */
#define _0B_ICU_PRIORITY_LEVEL11                   (0x0BU) /* Level 11  */
#define _0C_ICU_PRIORITY_LEVEL12                   (0x0CU) /* Level 12  */
#define _0D_ICU_PRIORITY_LEVEL13                   (0x0DU) /* Level 13  */
#define _0E_ICU_PRIORITY_LEVEL14                   (0x0EU) /* Level 14  */
#define _0F_ICU_PRIORITY_LEVEL15                   (0x0FU) /* Level 15  */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define FAST_INTERRUPT_VECTOR                      (0)

/* The macro definitions below list the full set of priority levels as selected in the Interrupts tab
 * Please do not modify this file manually
 */
#define ICU_BSC_BUSERR_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RAM_RAMERR_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_FCU_FIFERR_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_FCU_FRDYI_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_SWINT2_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_SWINT_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CMT0_CMI0_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CMT1_CMI1_PRIORITY                     (_0E_ICU_PRIORITY_LEVEL14)
#define ICU_CMT2_CMI2_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CMT3_CMI3_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_USB0_D0FIFO0_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_USB0_D1FIFO0_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSPI0_SPRI0_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RSPI0_SPTI0_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RIIC0_RXI0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_RIIC0_TXI0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI1_RXI1_PRIORITY                     (_0D_ICU_PRIORITY_LEVEL13)
#define ICU_SCI1_TXI1_PRIORITY                     (_0D_ICU_PRIORITY_LEVEL13)
#define ICU_ICU_IRQ0_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ1_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ2_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ3_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ4_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ5_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ6_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ7_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ8_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ9_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ10_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ11_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ12_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ13_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ14_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_IRQ15_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI5_RXI5_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI5_TXI5_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI6_RXI6_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI6_TXI6_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_LVD1_LVD1_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_LVD2_LVD2_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_USB0_USBR0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_IWDT_IWUNI_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_WDT_WUNI_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI8_RXI8_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI8_TXI8_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI9_RXI9_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI9_TXI9_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_GROUPBE0_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_GROUPBL0_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_GROUPBL1_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ICU_GROUPAL0_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI11_RXI11_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI11_TXI11_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI12_RXI12_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_SCI12_TXI12_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_DMAC_DMAC0I_PRIORITY                   (_0D_ICU_PRIORITY_LEVEL13)
#define ICU_DMAC_DMAC1I_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_DMAC_DMAC2I_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_DMAC_DMAC3I_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_DMAC_DMAC74I_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_OST_OSTDI_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_S12AD_S12ADI_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_S12AD_S12GBADI_PRIORITY                (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_S12AD_S12GCADI_PRIORITY                (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_S12AD1_S12ADI1_PRIORITY                (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_S12AD1_S12GBADI1_PRIORITY              (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_S12AD1_S12GCADI1_PRIORITY              (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_S12AD2_S12ADI2_PRIORITY                (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_S12AD2_S12GBADI2_PRIORITY              (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_S12AD2_S12GCADI2_PRIORITY              (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR0_CMIA0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR0_CMIB0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR0_OVI0_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR1_CMIA1_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR1_CMIB1_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR1_OVI1_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR2_CMIA2_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR2_CMIB2_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR2_OVI2_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR3_CMIA3_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR3_CMIB3_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR3_OVI3_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR4_CMIA4_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR4_CMIB4_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR4_OVI4_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR5_CMIA5_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR5_CMIB5_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR5_OVI5_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR6_CMIA6_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR6_CMIB6_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR6_OVI6_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR7_CMIA7_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR7_CMIB7_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TMR7_OVI7_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CAN0_RXF0_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CAN0_TXF0_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CAN0_RXM0_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CAN0_TXM0_PRIORITY                     (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_USB0_USBI0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ELC_ELSR18I_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_ELC_ELSR19I_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TSIP_RD_PRIORITY                       (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TSIP_WR_PRIORITY                       (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_TSIP_ERR_PRIORITY                      (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CMPC0_CMPC0_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CMPC1_CMPC1_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CMPC2_CMPC2_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CMPC3_CMPC3_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CMPC4_CMPC4_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_CMPC5_CMPC5_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW2_GTCIU2_PRIORITY                  (_0D_ICU_PRIORITY_LEVEL13)
#define ICU_GPTW2_GTCIV2_PRIORITY                  (_0D_ICU_PRIORITY_LEVEL13)
#define ICU_GPTW3_GTCIU3_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW3_GTCIV3_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU0_TCIV0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU0_TGIE0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU0_TGIF0_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU1_TGIA1_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU1_TGIB1_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU1_TCIV1_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU1_TCIU1_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU2_TGIA2_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU2_TGIB2_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU2_TCIV2_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU2_TCIU2_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU3_TGIA3_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU3_TGIB3_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU3_TGIC3_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU3_TGID3_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU3_TCIV3_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU4_TGIA4_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU4_TGIB4_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU4_TGIC4_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU4_TGID4_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU4_TCIV4_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU5_TGIU5_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU5_TGIV5_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU5_TGIW5_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU6_TGIA6_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU6_TGIB6_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU6_TGIC6_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU6_TGID6_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU6_TCIV6_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU7_TGIA7_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU7_TGIB7_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU7_TGIC7_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU7_TGID7_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU7_TCIV7_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU9_TGIA9_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU9_TGIB9_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU9_TGIC9_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU9_TGID9_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU9_TCIV9_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU9_TGIE9_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_MTU9_TGIF9_PRIORITY                    (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW2_GTCIE2_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW2_GTCIF2_PRIORITY                  (_0F_ICU_PRIORITY_LEVEL15)
#define ICU_GPTW2_GDTE2_PRIORITY                   (_0F_ICU_PRIORITY_LEVEL15)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Interrupt_Create(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
