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
* File Name        : r_cg_gpt.h
* Version          : 1.0.111
* Device(s)        : R5F566TEAxFM
* Description      : General header file for GPT peripheral.
***********************************************************************************************************************/

#ifndef GPT_H
#define GPT_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/*
    General PWM Timer Start Source Select Register(GTSSR)
    General PWM Timer Stop Source Select Register(GTPSR)
    General PWM Timer Clear Source Select Register(GTCSR)
    General PWM Timer Count-Up Source Select Register(GTUPSR)
    General PWM Timer Count-Down Source Select Register(GTDNSR)
    General PWM Timer Input Capture Source Select Register A(GTICASR)
    General PWM Timer Input Capture Source Select Register B(GTICBSR)
*/
/* GTETRGA Rising Source Count Start Enable(SSGTRGAR) */
/* GTETRGA Rising Source Count Stop Enable(PSGTRGAR) */
/* GTETRGA Rising Source Counter Clear Enable(CSGTRGAR) */
/* GTETRGA Rising Source Count-Up Enable(USGTRGAR) */
/* GTETRGA Rising Source Count-Down Enable(DSGTRGAR) */
/* GTETRGA Rising Source GTCCRA Input Capture Enable(ASGTRGAR) */
/* GTETRGA Rising Source GTCCRB Input Capture Enable(BSGTRGAR) */
/* GTETRGA Falling Source Count Start Enable (SSGTRGAF) */
/* GTETRGA Falling Source Count Stop Enable(PSGTRGAF) */
/* GTETRGA Falling Source Counter Clear Enable(CSGTRGAF) */
/* GTETRGA Falling Source Count-Up Enable(USGTRGAF) */
/* GTETRGA Falling Source Count-Down Enable(DSGTRGAF) */
/* GTETRGA Falling Source GTCCRA Input Capture Enable(ASGTRGAF) */
/* GTETRGA Falling Source GTCCRB Input Capture Enable(BSGTRGAF) */
#define _00000000_GPTn_GTETRGA_DISABLE                 (0x00000000UL) /* Disable use the GTETRGA input */
#define _00000001_GPTn_GTETRGA_RISE_EDGE               (0x00000001UL) /* Enable at rising of the GTETRGA input */
#define _00000002_GPTn_GTETRGA_FALL_EDGE               (0x00000002UL) /* Enable at falling of the GTETRGA input */
#define _00000003_GPTn_GTETRGA_BOTH_EDGES              (0x00000003UL) /* Enable at both edges of the GTETRGA input */
/* GTETRGB Rising Source Count Start Enable (SSGTRGBR) */
/* GTETRGB Rising Source Count Stop Enable(PSGTRGBR) */
/* GTETRGB Rising Source Counter Clear Enable(CSGTRGBR) */
/* GTETRGB Rising Source Count-Up Enable(USGTRGBR) */
/* GTETRGB Rising Source Count-Down Enable(DSGTRGBR) */
/* GTETRGB Rising Source GTCCRA Input Capture Enable(ASGTRGBR) */
/* GTETRGB Rising Source GTCCRB Input Capture Enable(BSGTRGBR) */
/* GTETRGB Falling Source Count Start Enable (SSGTRGBF) */
/* GTETRGB Falling Source Count Stop Enable(PSGTRGBF) */
/* GTETRGB Falling Source Counter Clear Enable(CSGTRGBF) */
/* GTETRGB Falling Source Count-Up Enable(USGTRGBF) */
/* GTETRGB Falling Source Count-Down Enable(DSGTRGBF) */
/* GTETRGB Falling Source GTCCRB Input Capture Enable(ASGTRGBF) */
/* GTETRGB Falling Source GTCCRB Input Capture Enable(BSGTRGBF) */
#define _00000000_GPTn_GTETRGB_DISABLE                 (0x00000000UL) /* Disable use the GTETRGB input */
#define _00000004_GPTn_GTETRGB_RISE_EDGE               (0x00000004UL) /* Enable at rising of the GTETRGB input */
#define _00000008_GPTn_GTETRGB_FALL_EDGE               (0x00000008UL) /* Enable at falling of the GTETRGB input */
#define _0000000C_GPTn_GTETRGB_BOTH_EDGES              (0x0000000CUL) /* Enable at both edges of the GTETRGB input */
/* GTETRGB Rising source Count Start Enable(SSGTRGCR) */
/* GTETRGC Rising Source Count Stop Enable(PSGTRGCR) */
/* GTETRGC Rising Source Counter Clear Enable(CSGTRGCR) */
/* GTETRGC Rising Source Count-Up Enable(USGTRGCR) */
/* GTETRGC Rising Source Count-Down Enable(DSGTRGCR) */
/* GTETRGC Rising Source GTCCRA Input Capture Enable(ASGTRGCR) */
/* GTETRGC Rising Source GTCCRB Input Capture Enable(BSGTRGCR) */
/* GTETRGC Falling Source Count Start Enable(SSGTRGCF) */
/* GTETRGC Falling Source Count Stop Enable(PSGTRGCF) */
/* GTETRGC Falling Source Counter Clear Enable(CSGTRGCF) */
/* GTETRGC Falling Source Count-Up Enable(USGTRGCF) */
/* GTETRGC Falling Source Count-Down Enable(DSGTRGCF) */
/* GTETRGC Falling Source GTCCRA Input Capture Enable(ASGTRGCF) */
/* GTETRGC Falling Source GTCCRB Input Capture Enable(BSGTRGCF) */
#define _00000000_GPTn_GTETRGC_DISABLE                 (0x00000000UL) /* Disable use the GTETRGC input */
#define _00000010_GPTn_GTETRGC_RISE_EDGE               (0x00000010UL) /* Enable at rising of the GTETRGC input */
#define _00000020_GPTn_GTETRGC_FALL_EDGE               (0x00000020UL) /* Enable at falling of the GTETRGC input */
#define _00000030_GPTn_GTETRGC_BOTH_EDGES              (0x00000030UL) /* Enable at both edges of the GTETRGC input */
/* GTETRGD Rising Source Count Start Enable(SSGTRGDR) */
/* GTETRGD Rising Source Count Stop Enable(PSGTRGDR) */
/* GTETRGD Rising Source Counter Clear Enable(CSGTRGDR) */
/* GTETRGD Rising Source Count-Up Enable(USGTRGDR) */
/* GTETRGD Rising Source Count-Down Enable(DSGTRGDR) */
/* GTETRGD Rising Source GTCCRA Input Capture Enable(ASGTRGDR) */
/* GTETRGD Rising Source GTCCRB Input Capture Enable(BSGTRGDR) */
/* GTETRGD Falling Source Count Start Enable(SSGTRGDF) */
/* GTETRGD Falling Source Count Stop Enable(PSGTRGDF) */
/* GTETRGD Falling Source Counter Clear Enable(CSGTRGDF) */
/* GTETRGD Falling Source Count-Up Enable(USGTRGDF) */
/* GTETRGD Falling Source Count-Down Enable(DSGTRGDF) */
/* GTETRGD Falling Source GTCCRA Input Capture Enable(ASGTRGDF) */
/* GTETRGD Falling Source GTCCRB Input Capture Enable(BSGTRGDF) */
#define _00000000_GPTn_GTETRGD_DISABLE                 (0x00000000UL) /* Disable use the GTETRGD input */
#define _00000040_GPTn_GTETRGD_RISE_EDGE               (0x00000040UL) /* Enable at rising of the GTETRGD input */
#define _00000080_GPTn_GTETRGD_FALL_EDGE               (0x00000080UL) /* Enable at falling of the GTETRGD input */
#define _000000C0_GPTn_GTETRGD_BOTH_EDGES              (0x000000C0UL) /* Enable at both edges of the GTETRGD input */
/* A Pin at Rising and B Pin 0 Source count start disable(SSCARBL) */
/* A Pin at Rising and B Pin 0 Source Count Stop Enable(PSCARBL) */
/* A Pin at Rising and B Pin 0 Source counter clear(CSCARBL) */
/* A Pin at Rising and B Pin 0 Source Count-Up Enable(USCARBL) */
/* A Pin at Rising and B Pin 0 Source Count-Down Enable(DSCARBL) */
/* A Pin at Rising and B Pin 0 Source GTCCRA Input Capture Enable(ASCARBL) */
/* A Pin at Rising and B Pin 0 Source GTCCRB Input Capture Enable(BSCARBL) */
/* A Pin at Rising and B Pin 1 Source count start disable(SSCARBH) */
/* A Pin at Rising and B Pin 1 Source Count Stop Enable(PSCARBH) */
/* A Pin at Rising and B Pin 1 Source Counter Clear Enable(CSCARBH) */
/* A Pin at Rising and B Pin 1 Source Count-Up Enable(USCARBH) */
/* A Pin at Rising and B Pin 1 Source Count-Down Enable(DSCARBH) */
/* A Pin at Rising and B Pin 1 Source GTCCRB Input Capture Enable(ASCARBH) */
/* A Pin at Rising and B Pin 1 Source GTCCRB Input Capture Enable(BSCARBH) */
#define _00000000_GPTn_GTIOCnA_RISE_DISABLE            (0x00000000UL) /* Disable at rising of the GTIOCnA pin input */
#define _00000100_GPTn_GTIOCnA_RISE_GTIOCnB_0_ENABLE   (0x00000100UL) /* Enable at rising of the GTIOCnA pin input
                                                                         while the GTIOCnB pin input is 1 */
#define _00000200_GPTn_GTIOCnA_RISE_GTIOCnB_1_ENABLE   (0x00000200UL) /* Enable at rising of the GTIOCnA pin input
                                                                         while the GTIOCnB pin input is 1 */
#define _00000300_GPTn_GTIOCnA_RISE_ENABLE             (0x00000300UL) /* Enable at rising of the GTIOCnA pin input */
/* A Pin at Falling and B Pin 0 Source Count Start Enable(SSCAFBL) */
/* A Pin at Falling and B Pin 0 Source Count Stop Enable(PSCAFBL) */
/* A Pin at Falling and B Pin 0 Source Counter Clear Enable(CSCAFBL) */
/* A Pin at Falling and B Pin 0 Source Count-Up Enable(USCAFBL) */
/* A Pin at Falling and B Pin 0 Source Count-Down Enable(DSCAFBL) */
/* A Pin at Falling and B Pin 0 Source GTCCRA Input Capture Enable(ASCAFBL) */
/* A Pin at Falling and B Pin 0 Source GTCCRB Input Capture Enable(BSCAFBL) */
/* A Pin at Falling and B Pin 1 Source Count Start Enable(SSCAFBH) */
/* A Pin at Falling and B Pin 1 Source Count Stop Enable(PSCAFBH) */
/* A Pin at Falling and B Pin 1 Source Counter Clear Enable(CSCAFBH) */
/* A Pin at Falling and B Pin 1 Source Count-Up Enable(USCAFBH) */
/* A Pin at Falling and B Pin 1 Source Count-Down Enable(DSCAFBH) */
/* A Pin at Falling and B Pin 1 Source GTCCRA Input Capture Enable(ASCAFBH) */
/* A Pin at Falling and B Pin 1 Source GTCCRB Input Capture Enable(BSCAFBH) */
#define _00000000_GPTn_GTIOCnA_FALL_DISABLE            (0x00000000UL) /* Disable at falling of the GTIOCnA pin input */
#define _00000400_GPTn_GTIOCnA_FALL_GTIOCnB_0_ENABLE   (0x00000400UL) /* Enable at falling of the GTIOCnA pin input
                                                                         while the GTIOCnB pin input is 1 */
#define _00000800_GPTn_GTIOCnA_FALL_GTIOCnB_1_ENABLE   (0x00000800UL) /* Enable at falling of the GTIOCnA pin input
                                                                         while the GTIOCnB pin input is 1 */
#define _00000C00_GPTn_GTIOCnA_FALL_ENABLE             (0x00000C00UL) /* Enable at falling of the GTIOCnA pin input */
/* B Pin at Rising and A Pin 0 Source Count Start Enable(SSCBRAL) */
/* B Pin at Rising and A Pin 0 Source Count Stop Enable(PSCBRAL) */
/* B Pin at Rising and A Pin 0 Source Counter Clear Enable(CSCBRAL) */
/* B Pin at Rising and A Pin 0 Source Count-Up Enable(USCBRAL) */
/* B Pin at Rising and A Pin 0 Source Count-Down Enable(DSCBRAL) */
/* B Pin at Rising and A Pin 0 Source GTCCRA Input Capture Enable(ASCBRAL) */
/* B Pin at Rising and A Pin 0 Source GTCCRB Input Capture Enable(BSCBRAL) */
/* B Pin at Rising and A Pin 1 Source Count Start Enable(SSCBRAH) */
/* B Pin at Rising and A Pin 1 Source Count Stop Enable(PSCBRAH) */
/* B Pin at Rising and A Pin 1 Source Counter Clear Enable(CSCBRAH) */
/* B Pin at Rising and A Pin 1 Source Count-Up Enable(USCBRAH) */
/* B Pin at Rising and A Pin 1 Source Count-Down Enable(DSCBRAH) */
/* B Pin at Rising and A Pin 1 Source GTCCRA Input Capture Enable(ASCBRAH) */
/* B Pin at Rising and A Pin 1 Source GTCCRB Input Capture Enable(BSCBRAH) */
#define _00000000_GPTn_GTIOCnB_RISE_DISABLE            (0x00000000UL) /* Disable at rising of the GTIOCnB pin input */
#define _00001000_GPTn_GTIOCnB_RISE_GTIOCnA_0_ENABLE   (0x00001000UL) /* Enable at rising of the GTIOCnB pin input
                                                                         while the GTIOCnA pin input is 1 */
#define _00002000_GPTn_GTIOCnB_RISE_GTIOCnA_1_ENABLE   (0x00002000UL) /* Enable at rising of the GTIOCnB pin input
                                                                         while the GTIOCnA pin input is 1 */
#define _00003000_GPTn_GTIOCnB_RISE_ENABLE             (0x00003000UL) /* Enable at rising of the GTIOCnB pin input */
/* B Pin at Falling and A Pin 0 Source Count Start Enable(SSCBFAL) */
/* B Pin at Falling and A Pin 0 Source Count Stop Enable(PSCBFAL) */
/* B Pin at Falling and A Pin 0 Source Counter Clear Enable(CSCBFAL) */
/* B Pin at Falling and A Pin 0 Source Count-Up Enable(USCBFAL) */
/* B Pin at Falling and A Pin 0 Source Count-Down Enable(DSCBFAL) */
/* B Pin at Falling and A Pin 0 Source GTCCRA Input Capture Enable(ASCBFAL) */
/* B Pin at Falling and A Pin 0 Source GTCCRB Input Capture Enable(BSCBFAL) */
/* B Pin at Falling and A Pin 1 Source Count Start Enable (SSCBFAH) */
/* B Pin at Falling and A Pin 1 Source Count Stop Enable(PSCBFAH) */
/* B Pin at Falling and A Pin 1 Source Counter Clear Enable(CSCBFAH) */
/* B Pin at Falling and A Pin 1 Source Count-Up Enable(USCBFAH) */
/* B Pin at Falling and A Pin 1 Source Count-Down Enable((DSCBFAH) */
/* B Pin at Falling and A Pin 1 Source GTCCRA Input Capture Enable(ASCBFAH) */
/* B Pin at Falling and A Pin 1 Source GTCCRB Input Capture Enable(BSCBFAH) */
#define _00000000_GPTn_GTIOCnB_FALL_DISABLE            (0x00000000UL) /* Disable at falling of the GTIOCnB pin input */
#define _00004000_GPTn_GTIOCnB_FALL_GTIOCnA_0_ENABLE   (0x00004000UL) /* Enable at falling of the GTIOCnB pin input
                                                                         while the GTIOCnA pin input is 1 */
#define _00008000_GPTn_GTIOCnB_FALL_GTIOCnA_1_ENABLE   (0x00008000UL) /* Enable at falling of the GTIOCnB pin input
                                                                         while the GTIOCnA pin input is 1*/
#define _0000C000_GPTn_GTIOCnB_FALL_ENABLE             (0x0000C000UL) /* Enable at falling of the GTIOCnB pin input */
/* ELCA Event Source Count Start Enable (SSELCA) */
/* ELCA Event Source Count Stop Enable(PSELCA) */
/* ELCA Event Source Counter Clear Enable(CSELCA) */
/* ELCA Event Source Count-Up Enable(USELCA) */
/* ELCA Event Source Count-Down Enable(DSELCA) */
/* ELCA event source GTCCRA Input Capture Enable(ASELCA) */
/* ELCA event source GTCCRB Input Capture Enable(BSELCA) */
#define _00000000_GPTn_ELCA_INPUT_DISABLE              (0x00000000UL) /* Disable count start by the ELCA event input */
#define _00010000_GPTn_ELCA_INPUT_ENABLE               (0x00010000UL) /* Enable count start by the ELCA event input */
/* ELCB Event Source Count Start Enable (SSELCB) */
/* ELCB Event Source Count Stop Enable(PSELCB) */
/* ELCB Event Source Counter Clear Enable(CSELCB) */
/* ELCB Event Source Count-Up Enable(USELCB) */
/* ELCB Event Source Count-Down Enable(DSELCB) */
/* ELCB event source GTCCRA Input Capture Enable(ASELCB) */
/* ELCB event source GTCCRB Input Capture Enable(BSELCB) */
#define _00000000_GPTn_ELCB_INPUT_DISABLE              (0x00000000UL) /* Disable count start by the ELCB event input */
#define _00020000_GPTn_ELCB_INPUT_ENABLE               (0x00020000UL) /* Enable count start by the ELCB event input */
/* ELCC Event Source Count Start Enable(SSELCC) */
/* ELCC Event Source Count Stop Enable(PSELCC) */
/* ELCC Event Source Counter Clear Enable(CSELCC) */
/* ELCC Event Source Count-Up Enable(USELCC) */
/* ELCC Event Source Count-Down Enable(DSELCC) */
/* ELCC event source GTCCRA Input Capture Enable(ASELCC) */
/* ELCC event source GTCCRB Input Capture Enable(BSELCC) */
#define _00000000_GPTn_ELCC_INPUT_DISABLE              (0x00000000UL) /* Disable count start by the ELCC event input */
#define _00040000_GPTn_ELCC_INPUT_ENABLE               (0x00040000UL) /* Enable count start by the ELCC event input */
/* ELCD Event Source Count Start Enable(SSELCD) */
/* ELCD Event Source Count Stop Enable(PSELCD) */
/* ELCD Event Source Counter Clear Enable(CSELCD) */
/* ELCD Event Source Count-Up Enable(USELCD) */
/* ELCD Event Source Count-Down Enable(DSELCD) */
/* ELCD event source GTCCRA Input Capture Enable(ASELCD) */
/* ELCD event source GTCCRB Input Capture Enable(BSELCD) */
#define _00000000_GPTn_ELCD_INPUT_DISABLE              (0x00000000UL) /* Disable count start by the ELCD event input */
#define _00080000_GPTn_ELCD_INPUT_ENABLE               (0x00080000UL) /* Enable count start by the ELCD event input */
/* ELCE Event Source Count Start Enable(SSELCE) */
/* ELCE Event Source Count Stop Enable(PSELCE) */
/* ELCE Event Source Counter Clear Enable(CSELCE) */
/* ELCE Event Source Count-Up Enable(USELCE) */
/* ELCE Event Source Count-Down Enable(DSELCE) */
/* ELCE event source GTCCRA Input Capture Enable(ASELCE) */
/* ELCE event source GTCCRB Input Capture Enable(BSELCE) */
#define _00000000_GPTn_ELCE_INPUT_DISABLE              (0x00000000UL) /* Disable count start by the ELCE event input */
#define _00100000_GPTn_ELCE_INPUT_ENABLE               (0x00100000UL) /* Enable count start by the ELCE event input */
/* ELCF Event Source Count Start Enable(SSELCF) */
/* ELCF Event Source Count Stop Enable(PSELCF) */
/* ELCF Event Source Counter Clear Enable(CSELCF) */
/* ELCF Event Source Count-Up Enable(USELCF) */
/* ELCF Event Source Count-Down Enable(DSELCF) */
/* ELCF event source GTCCRA Input Capture Enable(ASELCF) */
/* ELCF event source GTCCRB Input Capture Enable(BSELCF) */
#define _00000000_GPTn_ELCF_INPUT_DISABLE              (0x00000000UL) /* Disable count start by the ELCF event input */
#define _00200000_GPTn_ELCF_INPUT_ENABLE               (0x00200000UL) /* Enable count start by the ELCF event input */
/* ELCG Event Source Count Start Enable(SSELCG) */
/* ELCG Event Source Count Stop Enable(PSELCG) */
/* ELCG Event Source Counter Clear Enable(CSELCG) */
/* ELCG Event Source Count-Up Enable(USELCG) */
/* ELCG Event Source Count-Down Enable(DSELCG) */
/* ELCG event source GTCCRA Input Capture Enable(ASELCG) */
/* ELCG event source GTCCRB Input Capture Enable(BSELCG) */
#define _00000000_GPTn_ELCG_INPUT_DISABLE              (0x00000000UL) /* Disable count start by the ELCG event input */
#define _00400000_GPTn_ELCG_INPUT_ENABLE               (0x00400000UL) /* Enable count start by the ELCG event input */
/* ELCH Event Source Count Start Enable(SSELCH) */
/* ELCH Event Source Count Stop Enable(PSELCH) */
/* ELCH Event Source Counter Clear Enable(CSELCH) */
/* ELCH Event Source Count-Up Enable(USELCH) */
/* ELCH Event Source Count-Down Enable(DSELCH) */
/* ELCH Event Source GTCCRA Input Capture Enable(ASELCH) */
/* ELCH Event Source GTCCRB Input Capture Enable(BSELCH) */
#define _00000000_GPTn_ELCH_INPUT_DISABLE              (0x00000000UL) /* Disable count start by the ELCH event input */
#define _00800000_GPTn_ELCH_INPUT_ENABLE               (0x00800000UL) /* Enable count start by the ELCH event input */
/* Software Source Count Start Enable(CSTRT) */
/* Software Source Count Stop Enable(CSTOP) */
/* Software Source Counter Clear Enable(CCLR) */
#define _00000000_GPTn_SOFTWARE_SOURCE_DISABLE         (0x00000000UL) /* Disable count start / stop / clear / up / down
                                                                         by setting register*/
#define _80000000_GPTn_SOFTWARE_SOURCE_ENABLE          (0x80000000UL) /* Enable count start / stop / clear / up / down
                                                                         by setting register */

/*
    General PWM Timer Control Register (GTCR)
*/
/* Input capture operation select at count stop (ICDS) */
#define _00000000_GPTn_INPUTCAP_COUNT_STOP             (0x00000000UL) /* Input capture is operated at count stop */
#define _00000100_GPTn_NO_INPUTCAP_COUNT_STOP          (0x00000100UL) /* Input capture is not operated at count stop */
/* Mode Select (MD[2:0]) */
#define _00000000_GPTn_MODE_SAW_WAVE_PWM               (0x00000000UL) /* Saw-wave PWM mode */
#define _00010000_GPTn_MODE_SAW_WAVE_ONESHOT           (0x00010000UL) /* Saw-wave one-shot mode */
#define _00040000_GPTn_MODE_TRIANGLE_WAVE_PWM_1        (0x00040000UL) /* Triangle-wave PWM mode 1 */
#define _00050000_GPTn_MODE_TRIANGLE_WAVE_PWM_2        (0x00050000UL) /* Triangle-wave PWM mode 2 */
#define _00060000_GPTn_MODE_TRIANGLE_WAVE_PWM_3        (0x00060000UL) /* Triangle-wave PWM mode 3 */
/* Timer Prescaler Select (TPCS[3:0]) */
#define _00000000_GPTn_COUNT_CLK_PCLKC                 (0x00000000UL) /* PCLKC */
#define _00800000_GPTn_COUNT_CLK_PCLKC_2               (0x00800000UL) /* PCLKC/2 */
#define _01000000_GPTn_COUNT_CLK_PCLKC_4               (0x01000000UL) /* PCLKC/4 */
#define _01800000_GPTn_COUNT_CLK_PCLKC_8               (0x01800000UL) /* PCLKC/8 */
#define _02000000_GPTn_COUNT_CLK_PCLKC_16              (0x02000000UL) /* PCLKC/16 */
#define _02800000_GPTn_COUNT_CLK_PCLKC_32              (0x02800000UL) /* PCLKC/32 */
#define _03000000_GPTn_COUNT_CLK_PCLKC_64              (0x03000000UL) /* PCLKC/64 */
#define _04000000_GPTn_COUNT_CLK_PCLKC_256             (0x04000000UL) /* PCLKC/256 */
#define _05000000_GPTn_COUNT_CLK_PCLKC_1024            (0x05000000UL) /* PCLKC/1024 */
#define _06000000_GPTn_COUNT_CLK_GTETRGA               (0x06000000UL) /* GTETRGA */
#define _06800000_GPTn_COUNT_CLK_GTETRGB               (0x06800000UL) /* GTETRGB */
#define _07000000_GPTn_COUNT_CLK_GTETRGC               (0x07000000UL) /* GTETRGC */
#define _07800000_GPTn_COUNT_CLK_GTETRGD               (0x07800000UL) /* GTETRGD */

/*
    General PWM Timer Count Direction and Duty Setting Register (GTUDDTYC)
*/
/* Count Direction Setting (UD) */
#define _00000000_GPTn_COUNT_DOWN                      (0x00000000UL) /* GTCNT counts down */
#define _00000001_GPTn_COUNT_UP                        (0x00000001UL) /* GTCNT counts up */
/* Forcible Count Direction Setting (UDF) */
#define _00000000_GPTn_COUNT_DIR_NORMAL                (0x00000000UL) /* Not forcibly set */
#define _00000002_GPTn_COUNT_DIR_FORCE                 (0x00000002UL) /* Forcibly set */
/* GTIOCnA Pin Output Duty Setting(OADTY[1:0]) */
#define _00000000_GPTn_GTIOCnA_DUTYCYCLE_COMPARE       (0x00000000UL) /* Compare matches determine the duty cycle
                                                                         of the output on GTIOCnA pin */
#define _00020000_GPTn_GTIOCnA_DUTYCYCLE_0             (0x00020000UL) /* The duty cycle of the output on
                                                                         GTIOCnA pin is 0% */
#define _00030000_GPTn_GTIOCnA_DUTYCYCLE_100           (0x00030000UL) /* The duty cycle of the output on
                                                                         GTIOCnA pin is 100% */
/* GTIOCnA Pin Output Duty Forced Setting(OADTYF) */
#define _00000000_GPTn_GTIOCnA_DUTYFORCE_DISABLE       (0x00000000UL) /* Duty of pin output is not forcibly set */
#define _00040000_GPTn_GTIOCnA_DUTYFORCE_ENABLE        (0x00040000UL) /* Duty of pin output is forcibly set */
/* Output after Release of GTIOCnA Pin Output 0%/100% Duty Cycle Settings(OADTYR) */
#define _00000000_GPTn_GTIOCA_RELEASE_OUTPUTVALUE      (0x00000000UL) /* Output value when the duty cycle is set after
                                                                         release */
#define _00080000_GPTn_GTIOCA_RELEASE_COMPAREVALUE     (0x00080000UL) /* Compare match output value which is masked
                                                                         after release */
/* GTIOCnB Pin Output Duty Setting(OBDTY[1:0]) */
#define _00000000_GPTn_GTIOCnB_DUTYCYCLE_COMPARE       (0x00000000UL) /* Compare matches determine the duty cycle
                                                                         of the output on GTIOCnB pin */
#define _02000000_GPTn_GTIOCnB_DUTYCYCLE_0             (0x02000000UL) /* The duty cycle of the output on
                                                                         GTIOCnB pin is 0% */
#define _03000000_GPTn_GTIOCnB_DUTYCYCLE_100           (0x03000000UL) /* The duty cycle of the output on
                                                                         GTIOCnB pin is 100% */
/* GTIOCnB Pin Output Duty Forced Setting(OBDTYF) */
#define _00000000_GPTn_GTIOCnB_DUTYFORCE_DISABLE       (0x00000000UL) /* Duty of pin output is not forcibly set */
#define _04000000_GPTn_GTIOCnB_DUTYFORCE_ENABLE        (0x04000000UL) /* Duty of pin output is forcibly set */
/* Output after Release of GTIOCnB Pin Output 0%/100% Duty Cycle Settings(OBDTYR) */
#define _00000000_GPTn_GTIOCB_RELEASE_OUTPUTVALUE      (0x00000000UL) /* Output value when the duty cycle is set after
                                                                         release */
#define _08000000_GPTn_GTIOCB_RELEASE_COMPAREVALUE     (0x08000000UL) /* Compare match output value which is masked
                                                                         after release */

/*
    General PWM Timer I/O Control Register (GTIOR)
*/
/* GTIOCnA Pin Function Select (GTIOA[4:0]) */
#define _00000000_GPTn_GTIOCA_COMP_MATCH_RETAIN        (0x00000000UL) /* Output retained at compare match */
#define _00000001_GPTn_GTIOCA_COMP_MATCH_LOW           (0x00000001UL) /* Output low at compare match */
#define _00000002_GPTn_GTIOCA_COMP_MATCH_HIGH          (0x00000002UL) /* Output high at compare match */
#define _00000003_GPTn_GTIOCA_COMP_MATCH_TOGGLE        (0x00000003UL) /* Output toggled at compare match */
#define _00000000_GPTn_GTIOCA_CYCLE_END_RETAIN         (0x00000000UL) /* Output retained at cycle end */
#define _00000004_GPTn_GTIOCA_CYCLE_END_LOW            (0x00000004UL) /* Output low at cycle end */
#define _00000008_GPTn_GTIOCA_CYCLE_END_HIGH           (0x00000008UL) /* Output hight at cycle end */
#define _0000000C_GPTn_GTIOCA_CYCLE_END_TOGGLE         (0x0000000CUL) /* Output toggled at cycle end */
#define _00000000_GPTn_GTIOCA_INIT_OUT_LOW             (0x00000000UL) /* Initial output is low */
#define _00000010_GPTn_GTIOCA_INIT_OUT_HIGH            (0x00000010UL) /* Initial output is high */
/* Output Value at GTIOCnA Pin count stop (OADFLT) */
#define _00000000_GPTn_GTIOCA_OUTPUT_ON_STOP_0         (0x00000000UL) /* Outputs low when counting is stopped */
#define _00000040_GPTn_GTIOCA_OUTPUT_ON_STOP_1         (0x00000040UL) /* Outputs high when counting is stopped */
/* Output Retain at GTIOCnA Pin count start/stop (OAHLD) */
#define _00000000_GPTn_GTIOCA_OUTPUT_ON_START_SET      (0x00000000UL) /* Output at start/stop based on setting */
#define _00000080_GPTn_GTIOCA_OUTPUT_ON_START_RETAIN   (0x00000080UL) /* Output at start/stop is retained */
/* GTIOCnA Pin Output Enable (OAE) */
#define _00000000_GPTn_GTCIOCA_OUTPUT_DISABLE          (0x00000000UL) /* No pin output */
#define _00000100_GPTn_GTIOCnA_OUTPUT_ENABLE           (0x00000100UL) /* Pin output */
/* GTIOCnA Pin Negate Value Setting (OADF[1:0]) */
#define _00000000_GPTn_GTIOCnA_NEG_DISABEL             (0x00000000UL) /* None */
#define _00000200_GPTn_GTIOCnA_NEG_HIZ                 (0x00000200UL) /* Hi-Z state for output negation */
#define _00000400_GPTn_GTIOCnA_NEG_OUT0                (0x00000400UL) /* 0 for output negation */
#define _00000600_GPTn_GTIOCnA_NEG_OUT1                (0x00000600UL) /* 1 for output negation */
/* GTIOCnA Pin Input Noise Filter Enable (NFAEN) */
#define _00000000_GPTn_GTIOCnA_NOISE_FILTER_DISABLE    (0x00000000UL) /* The noise filter for GTIOCnA pin disabled */
#define _00002000_GPTn_GTIOCnA_NOISE_FILTER_ENABLE     (0x00002000UL) /* The noise filter for GTIOCnA pin enabled */
/* GTIOCnA Pin Input Noise Filter Sampling Clock Select (NFCSA[1:0]) */
#define _00000000_GPTn_NOISE_FILTERA_PCLKC             (0x00000000UL) /* PCLKC */
#define _00004000_GPTn_NOISE_FILTERA_PCLKC_4           (0x00004000UL) /* PCLKC/4 */
#define _00008000_GPTn_NOISE_FILTERA_PCLKC_16          (0x00008000UL) /* PCLKC/16 */
#define _0000C000_GPTn_NOISE_FILTERA_PCLKC_64          (0x0000C000UL) /* PCLKC/64 */
/* GTIOCnB Pin Function Select (GTIOB[4:0]) */
#define _00000000_GPTn_GTIOCB_COMP_MATCH_RETAIN        (0x00000000UL) /* Output retained at compare match */
#define _00010000_GPTn_GTIOCB_COMP_MATCH_LOW           (0x00010000UL) /* Output low at compare match */
#define _00020000_GPTn_GTIOCB_COMP_MATCH_HIGH          (0x00020000UL) /* Output high at compare match */
#define _00030000_GPTn_GTIOCB_COMP_MATCH_TOGGLE        (0x00030000UL) /* Output toggled at compare match */
#define _00000000_GPTn_GTIOCB_CYCLE_END_RETAIN         (0x00000000UL) /* Output retained at cycle end */
#define _00040000_GPTn_GTIOCB_CYCLE_END_LOW            (0x00040000UL) /* Output low at cycle end */
#define _00080000_GPTn_GTIOCB_CYCLE_END_HIGH           (0x00080000UL) /* Output hight at cycle end */
#define _000C0000_GPTn_GTIOCB_CYCLE_END_TOGGLE         (0x000C0000UL) /* Output toggled at cycle end */
#define _00000000_GPTn_GTIOCB_INIT_OUT_LOW             (0x00000000UL) /* Initial output is low */
#define _00100000_GPTn_GTIOCB_INIT_OUT_HIGH            (0x00100000UL) /* Initial output is high */
/* Output Value at GTIOCnB Pin count stop (OBDFLT) */ 
#define _00000000_GPTn_GTIOCB_OUTPUT_ON_STOP_0         (0x00000000UL) /* Outputs low when counting is stopped */
#define _00400000_GPTn_GTIOCB_OUTPUT_ON_STOP_1         (0x00400000UL) /* Outputs high when counting is stopped */
/* Output Retain at GTIOCnB Pin count start/stop (OBHLD) */
#define _00000000_GPTn_GTIOCB_OUTPUT_ON_START_SET      (0x00000000UL) /* Output at start/stop based on setting */
#define _00800000_GPTn_GTIOCB_OUTPUT_ON_START_RETAIN   (0x00800000UL) /* Output at start/stop is retained */
/* GTIOCnB Pin Output Enable (OBE) */
#define _00000000_GPTn_GTCIOCB_OUTPUT_DISABLE          (0x00000000UL) /* No pin output */
#define _01000000_GPTn_GTIOCnB_OUTPUT_ENABLE           (0x01000000UL) /* Pin output */
/* GTIOCnB Pin Negate Value Setting (OBDF[1:0]) */
#define _00000000_GPTn_GTIOCnB_NEG_DISABEL             (0x00000000UL) /* None */
#define _02000000_GPTn_GTIOCnB_NEG_HIZ                 (0x02000000UL) /* Hi-Z state for output negation */
#define _04000000_GPTn_GTIOCnB_NEG_OUT0                (0x04000000UL) /* 0 for output negation */
#define _06000000_GPTn_GTIOCnB_NEG_OUT1                (0x06000000UL) /* 1 for output negation */
/* GTIOCnB Pin Input Noise Filter Enable (NFBEN) */
#define _00000000_GPTn_GTIOCnB_NOISE_FILTER_DISABLE    (0x00000000UL) /* The noise filter for GTIOCnB pin disabled */
#define _20000000_GPTn_GTIOCnB_NOISE_FILTER_ENABLE     (0x20000000UL) /* The noise filter for GTIOCnB pin enabled */
/* GTIOCnA Pin Input Noise Filter Sampling Clock Select (NFCSB[1:0]) */
#define _00000000_GPTn_NOISE_FILTERB_PCLKC             (0x00000000UL) /* PCLKC */
#define _40000000_GPTn_NOISE_FILTERB_PCLKC_4           (0x40000000UL) /* PCLKC/4 */
#define _80000000_GPTn_NOISE_FILTERB_PCLKC_16          (0x80000000UL) /* PCLKC/16 */
#define _C0000000_GPTn_NOISE_FILTERB_PCLKC_64          (0xC0000000UL) /* PCLKC/64 */

/*
    General PWM timer Interrupt Output Setting Register (GTINTAD)
*/
/* GTCCRA Compare Match/input capture Interrupt Enable (GTINTA) */
#define _00000000_GPTn_GTCIA_INTERRUPT_DISABLE         (0x00000000UL) /* Interrupt request is disabled */
#define _00000001_GPTn_GTCIA_INTERRUPT_ENABLE          (0x00000001UL) /* Interrupt request is enabled */
/* GTCCRB Compare Match/input capture Interrupt Enable (GTINTB) */
#define _00000000_GPTn_GTCIB_INTERRUPT_DISABLE         (0x00000000UL) /* Interrupt request is disabled */
#define _00000002_GPTn_GTCIB_INTERRUPT_ENABLE          (0x00000002UL) /* Interrupt request is enabled */
/* GTCCRC Compare Match/input capture Interrupt Enable (GTINTC) */
#define _00000000_GPTn_GTCIC_INTERRUPT_DISABLE         (0x00000000UL) /* Interrupt request is disabled */
#define _00000004_GPTn_GTCIC_INTERRUPT_ENABLE          (0x00000004UL) /* Interrupt request is enabled */
/* GTCCRD Compare Match/input capture Interrupt Enable (GTINTD) */
#define _00000000_GPTn_GTCID_INTERRUPT_DISABLE         (0x00000000UL) /* Interrupt request is disabled */
#define _00000008_GPTn_GTCID_INTERRUPT_ENABLE          (0x00000008UL) /* Interrupt request is enabled */
/* GTCCRE Compare Match/input capture Interrupt Enable (GTINTE) */
#define _00000000_GPTn_GTCIE_INTERRUPT_DISABLE         (0x00000000UL) /* Interrupt request is disabled */
#define _00000010_GPTn_GTCIE_INTERRUPT_ENABLE          (0x00000010UL) /* Interrupt request is enabled */
/* GTCCRF Compare Match/input capture Interrupt Enable (GTINTF) */
#define _00000000_GPTn_GTCIF_INTERRUPT_DISABLE         (0x00000000UL) /* Interrupt request is disabled */
#define _00000020_GPTn_GTCIF_INTERRUPT_ENABLE          (0x00000020UL) /* Interrupt request is enabled */
/* GTPR Compare Match Interrupt Enable (GTINTPR[1:0]) */
#define _00000000_GPTn_GTCIV_INTERRUPT_DISABLE         (0x00000000UL) /* Interrupt request is disabled */
#define _00000040_GPTn_GTCIV_INTERRUPT_ENABLE          (0x00000040UL) /* Interrupt request is enabled */
#define _00000000_GPTn_GTCIU_INTERRUPT_DISABLE         (0x00000000UL) /* Interrupt request is disabled */
#define _00000080_GPTn_GTCIU_INTERRUPT_ENABLE          (0x00000080UL) /* Interrupt request is enabled */
/* GTADTRA Compare Match (Up-counting) A/D Converter start Request Enable (ADTRAUEN) */
#define _00000000_GPTn_ADTRA_UPCOUNTING_DISABLE        (0x00000000UL) /* A/D start request is disabled */
#define _00010000_GPTn_ADTRA_UPCOUNTING_ENABLE         (0x00010000UL) /* A/D start request is enabled */
/* GTADTRA Compare Match (Down-counting) A/D Converter start Request Enable (ADTRADEN) */
#define _00000000_GPTn_ADTRA_DOWNCOUNTING_DISABLE      (0x00000000UL) /* A/D start request is disabled */
#define _00020000_GPTn_ADTRA_DOWNCOUNTING_ENABLE       (0x00020000UL) /* A/D start request is enabled */
/* GTADTRB Compare Match (Up-counting) A/D Converter start Request Enable (ADTRBUEN) */
#define _00000000_GPTn_ADTRB_UPCOUNTING_DISABLE        (0x00000000UL) /* A/D start request is disabled */
#define _00040000_GPTn_ADTRB_UPCOUNTING_ENABLE         (0x00040000UL) /* A/D start request is enabled */
/* GTADTRB Compare Match (Down-counting) A/D Converter start Request Enable (ADTRBDEN) */
#define _00000000_GPTn_ADTRB_DOWNCOUNTING_DISABLE      (0x00000000UL) /* A/D start request is disabled */
#define _00080000_GPTn_ADTRB_DOWNCOUNTING_ENABLE       (0x00080000UL) /* A/D start request is enabled */
/* Output Stop Group Select (GRP[1:0]) */
#define _00000000_GPTn_OUTPUT_STOP_GROUPA              (0x00000000UL) /* Group A is selected */
#define _01000000_GPTn_OUTPUT_STOP_GROUPB              (0x01000000UL) /* Group B is selected */
#define _02000000_GPTn_OUTPUT_STOP_GROUPC              (0x02000000UL) /* Group C is selected */
#define _03000000_GPTn_OUTPUT_STOP_GROUPD              (0x03000000UL) /* Group D is selected */
/* Dead Time Error Output Stop Detection Enable (GRPDTE) */
#define _00000000_GPTn_DEADTIME_OUTPUT_STOP_DISABLE    (0x00000000UL) /* Dead time error output stop detection
                                                                         disabled */
#define _10000000_GPTn_DEADTIME_OUTPUT_STOP_ENABLE     (0x10000000UL) /* Dead time error output stop detection
                                                                         enabled */
/* Simultaneous High Output Stop Detection Enable (GRPABH) */
#define _00000000_GPTn_SIMHIGH_OUTPUT_STOP_DISABLE     (0x00000000UL) /* Simultaneous high output stop detection
                                                                         disabled*/
#define _20000000_GPTn_SIMHIGH_OUTPUT_STOP_ENABLE      (0x20000000UL) /* Simultaneous high output stop detection
                                                                         enabled */
/* Simultaneous Low Output Stop Detection Enable (GRPABL) */
#define _00000000_GPTn_SIMLOW_OUTPUT_STOP_DISABLE      (0x00000000UL) /* Simultaneous low output stop detection
                                                                         disabled */
#define _40000000_GPTn_SIMLOW_OUTPUT_STOP_ENABLE       (0x40000000UL) /* Simultaneous low output stop detection
                                                                         enabled */

/*
    General PWM timer Buffer Enable Register (GTBER)
*/
/* GTCCRA/GTCCRB Registers Buffer Operation Disable (BD[0]) */
#define _00000000_GPTn_GTCCR_BUF_OP_ENABLE             (0x00000000UL) /* Buffer operation is enabled */
#define _00000001_GPTn_GTCCR_BUF_OP_DISABLE            (0x00000001UL) /* Buffer operation is disabled */
/* GTPR Register Buffer Operation Disable (BD[1]) */
#define _00000000_GPTn_GTPR_BUF_OP_ENABLE              (0x00000000UL) /* Buffer operation is enabled */
#define _00000002_GPTn_GTPR_BUF_OP_DISABLE             (0x00000002UL) /* Buffer operation is disabled */
/* GTADTRA/GTADTRB Registers Buffer Operation Disable (BD[2]) */
#define _00000000_GPTn_GTADTR_BUF_OP_ENABLE            (0x00000000UL) /* Buffer operation is enabled */
#define _00000004_GPTn_GTADTR_BUF_OP_DISABLE           (0x00000004UL) /* Buffer operation is disabled */
/* GTDVU/GTDVD Registers Buffer Operation Disable (BD[3]) */
#define _00000000_GPTn_GTDV_BUF_OP_ENABLE              (0x00000000UL) /* Buffer operation is enabled */
#define _00000008_GPTn_GTDV_BUF_OP_DISABLE             (0x00000008UL) /* Buffer operation is disabled */
/* GTCCRA Register Double Buffer Repeat Operation Enable (DBRTECA) */
#define _00000000_GPTn_GTCCRA_DOUBLEBUF_REPEAT_DISABLE (0x00000000UL) /* Double buffer repeat operation is disabled */
#define _00000100_GPTn_GTCCRA_DOUBLEBUF_REPEAT_ENABLE  (0x00000100UL) /* Double buffer repeat operation is enabled */
/* GTCCRB Register Double Buffer Repeat Operation Enable (DBRTECB) */
#define _00000000_GPTn_GTCCRB_DOUBLEBUF_REPEAT_DISABLE (0x00000000UL) /* Double buffer repeat operation is disabled */
#define _00000400_GPTn_GTCCRB_DOUBLEBUF_REPEAT_ENABLE  (0x00000400UL) /* Double buffer repeat operation is enabled */
/* GTCCRA Buffer Operation (CCRA[1:0]) */
#define _00000000_GPTn_GTCCRA_BUF_NONE                 (0x00000000UL) /* Buffer operation is not performed */
#define _00010000_GPTn_GTCCRA_BUF_SINGLE               (0x00010000UL) /* Single buffer operation */
#define _00020000_GPTn_GTCCRA_BUF_DOUBLE               (0x00020000UL) /* Double buffer operation */
/* GTCCRB Buffer Operation (CCRB[1:0]) */
#define _00000000_GPTn_GTCCRB_BUF_NONE                 (0x00000000UL) /* Buffer operation is not performed */
#define _00040000_GPTn_GTCCRB_BUF_SINGLE               (0x00040000UL) /* Single buffer operation */
#define _00080000_GPTn_GTCCRB_BUF_DOUBLE               (0x00080000UL) /* Double buffer operation */
/* GTPR Buffer Operation (PR[1:0]) */
#define _00000000_GPTn_GTPR_BUF_NONE                   (0x00000000UL) /* Buffer operation is not performed */
#define _00100000_GPTn_GTPR_BUF_SINGLE                 (0x00100000UL) /* Single buffer operation */
#define _00200000_GPTn_GTPR_BUF_DOUBLE                 (0x00200000UL) /* Double buffer operation */
/* GTCCRA and GTCCRB Forcible Buffer Operation (CCRSWT) */
#define _00000000_GPTn_GTCCR_BUF_TRANS_NORMAL          (0x00000000UL) /* Not forcibly perform buffer transfer */
#define _00400000_GPTn_GTCCR_BUF_TRANS_FORCE           (0x00400000UL) /* Forcibly perform buffer transfer */
/* GTADTRA Buffer Transfer Timing Select ADTTA[1:0] */
#define _00000000_GPTn_GTADTRA_BUF_TRANS_NONE          (0x00000000UL) /* No transfer */
#define _01000000_GPTn_GTADTRA_BUF_TRANS_OVRF_UDRF     (0x01000000UL) /* Transfer at overflow & underflow */
#define _01000000_GPTn_GTADTRA_BUF_TRANS_CREST         (0x01000000UL) /* Transfer at crest */
#define _02000000_GPTn_GTADTRA_BUF_TRANS_TROUGH        (0x02000000UL) /* Transfer at trough */
#define _03000000_GPTn_GTADTRA_BUF_TRANS_BOTH          (0x03000000UL) /* Transfer at both crest & trough */
/* GTADTRA Double Buffer Operation (ADTDA) */
#define _00000000_GPTn_GTADTRA_BUF_SINGLE              (0x00000000UL) /* Single buffer operation */
#define _04000000_GPTn_GTADTRA_BUF_DOUBLE              (0x04000000UL) /* Double buffer operation */
/* GTADTRB Buffer Transfer Timing Select ADTTB[1:0] */
#define _00000000_GPTn_GTADTRB_BUF_TRANS_NONE          (0x00000000UL) /* No transfer */
#define _10000000_GPTn_GTADTRB_BUF_TRANS_OVRF_UDRF     (0x10000000UL) /* Transfer at overflow & underflow */
#define _10000000_GPTn_GTADTRB_BUF_TRANS_CREST         (0x10000000UL) /* Transfer at crest */
#define _20000000_GPTn_GTADTRB_BUF_TRANS_TROUGH        (0x20000000UL) /* Transfer at trough */
#define _30000000_GPTn_GTADTRB_BUF_TRANS_BOTH          (0x30000000UL) /* Transfer at both crest & trough */
/* GTADTRB Double Buffer Operation (ADTDB) */
#define _00000000_GPTn_GTADTRB_BUF_SINGLE              (0x00000000UL) /* Single buffer operation */
#define _40000000_GPTn_GTADTRB_BUF_DOUBLE              (0x40000000UL) /* Double buffer operation */

/*
    General PWM timer Interrupt and A/D Converter start Request Skipping Setting Register (GTITC)
*/
/* GTCCRA Compare Match/input capture Interrupt Link (ITLA) */
#define _00000000_GPTn_GTCIA_INT_SKIP_DISABLE          (0x00000000UL) /* No skipping */
#define _00000001_GPTn_GTCIA_INT_SKIP_ENABLE           (0x00000001UL) /* Linked with GTCIV/GTCIU skipping */
/* GTCCRB Compare Match/input capture Interrupt Link (ITLB) */
#define _00000000_GPTn_GTCIB_INT_SKIP_DISABLE          (0x00000000UL) /* No skipping */
#define _00000002_GPTn_GTCIB_INT_SKIP_ENABLE           (0x00000002UL) /* Linked with GTCIV/GTCIU skipping */
/* GTCCRC Compare Match/input capture Interrupt Link (ITLC) */
#define _00000000_GPTn_GTCIC_INT_SKIP_DISABLE          (0x00000000UL) /* No skipping */
#define _00000004_GPTn_GTCIC_INT_SKIP_ENABLE           (0x00000004UL) /* Linked with GTCIV/GTCIU skipping */
/* GTCCRD Compare Match/input capture Interrupt Link (ITLD) */
#define _00000000_GPTn_GTCID_INT_SKIP_DISABLE          (0x00000000UL) /* No skipping */
#define _00000008_GPTn_GTCID_INT_SKIP_ENABLE           (0x00000008UL) /* Linked with GTCIV/GTCIU skipping */
/* GTCCRE Compare Match/input capture Interrupt Link (ITLE) */
#define _00000000_GPTn_GTCIE_INT_SKIP_DISABLE          (0x00000000UL) /* No skipping */
#define _00000010_GPTn_GTCIE_INT_SKIP_ENABLE           (0x00000010UL) /* Linked with GTCIV/GTCIU skipping */
/* GTCCRF Compare Match/input capture Interrupt Link (ITLF) */
#define _00000000_GPTn_GTCIF_INT_SKIP_DISABLE          (0x00000000UL) /* No skipping */
#define _00000020_GPTn_GTCIF_INT_SKIP_ENABLE           (0x00000020UL) /* Linked with GTCIV/GTCIU skipping */
/* GTCIV/GTCIU Interrupt Skipping Function Select (IVTC[1:0]) */
#define _00000000_GPTn_GTCI_SKIP_DISABLE               (0x00000000UL) /* Skipping is not performed */
#define _00000040_GPTn_GTCI_SKIP_OVRF_UDRF             (0x00000040UL) /* Skipping at overflow & underflow */
#define _00000040_GPTn_GTCI_SKIP_CREST                 (0x00000040UL) /* Skipping at crest */
#define _00000080_GPTn_GTCI_SKIP_TROUGH                (0x00000080UL) /* Skipping at trough */
#define _000000C0_GPTn_GTCI_SKIP_BOTH                  (0x000000C0UL) /* Skipping at both crest & trough */
/* GTCIV/GTCIU Interrupt Skipping count Select (IVTT[2:0]) */
#define _00000000_GPTn_GTCI_SKIPPING_COUNT_0           (0x00000000UL) /* Skipping is not performed */
#define _00000100_GPTn_GTCI_SKIP_COUNT_1               (0x00000100UL) /* Skipping count of 1 */
#define _00000200_GPTn_GTCI_SKIP_COUNT_2               (0x00000200UL) /* Skipping count of 2 */
#define _00000300_GPTn_GTCI_SKIP_COUNT_3               (0x00000300UL) /* Skipping count of 3 */
#define _00000400_GPTn_GTCI_SKIP_COUNT_4               (0x00000400UL) /* Skipping count of 4 */
#define _00000500_GPTn_GTCI_SKIP_COUNT_5               (0x00000500UL) /* Skipping count of 5 */
#define _00000600_GPTn_GTCI_SKIP_COUNT_6               (0x00000600UL) /* Skipping count of 6 */
#define _00000700_GPTn_GTCI_SKIP_COUNT_7               (0x00000700UL) /* Skipping count of 7 */
/* GTADTRA A/D Converter start Request Link (ADTAL) */
#define _00000000_GPTn_ADTRA_REQ_SKIP_DISABLE          (0x00000000UL) /* No skipping */
#define _00001000_GPTn_ADTRA_REQ_SKIP_ENABLE           (0x00001000UL) /* Linked with GTCIV/GTCIU skipping */
/* GTADTRB A/D Converter start Request Link (ADTBL) */
#define _00000000_GPTn_ADTRB_REQ_SKIP_DISABLE          (0x00000000UL) /* No skipping */
#define _00004000_GPTn_ADTRB_REQ_SKIP_ENABLE           (0x00004000UL) /* Linked with GTCIV/GTCIU skipping */

/*
    General PWM timer Dead Time Control Register (GTDTCR)
*/
/* Negative-Phase Waveform Setting (TDE) */
#define _00000000_GPTn_DEAD_TIME_DISABLE               (0x00000000UL) /* GTCCRB is set without dead time */
#define _00000001_GPTn_DEAD_TIME_ENABLE                (0x00000001UL) /* GTCCRB is auto-set with dead time */
/* GTDVU Buffer Operation Enable (TDBUE) */
#define _00000000_GPTn_GTDVU_BUF_DISABLE               (0x00000000UL) /* GTDVU buffer operation is disabled */
#define _00000010_GPTn_GTDVU_BUF_ENABLE                (0x00000010UL) /* GTDVU buffer operation is enabled */
/* GTDVD Buffer Operation Enable (TDBDE) */
#define _00000000_GPTn_GTDVD_BUF_DISABLE               (0x00000000UL) /* GTDVD buffer operation is disabled */
#define _00000020_GPTn_GTDVD_BUF_ENABLE                (0x00000020UL) /* GTDVD buffer operation is enabled */
/* GTDVD Setting (TDFER) */
#define _00000000_GPTn_GTDVD_VALUE_SEPARATE            (0x00000000UL) /* GTDVU and GTDVD are set separately */
#define _00000100_GPTn_GTDVD_VALUE_AUTO                (0x00000100UL) /* GTDVU value is auto-set to GTDVD */

/*
    General PWM Timer A/D Converter Start Request Signal Monitoring Register (GTADSMR)
*/
/* A/D Conversion Start Request Signal Monitor 0 Selection (ADSMS0[1:0]) */
#define _00000000_GPTn_GTADTRA_UP_COUNTING             (0x00000000UL) /* A/D conversion start request signal generated
                                                                         by the GTADTRA during up-counting */
#define _00000001_GPTn_GTADTRA_DOWN_COUNTING           (0x00000001UL) /* A/D conversion start request signal generated
                                                                         by the GTADTRA during down-counting */
#define _00000002_GPTn_GTADTRB_UP_COUNTING             (0x00000002UL) /* A/D conversion start request signal generated
                                                                         by the GTADTRB during up-counting */
#define _00000003_GPTn_GTADTRB_DOWN_COUNTING           (0x00000003UL) /* A/D conversion start request signal generated
                                                                         by the GTADTRB during down-counting */
/* A/D Conversion Start Request Signal Monitor 0 Output Enabling (ADSMEN0) */
#define _00000000_GPTn_AD_START_MONITOR0_DISABLE       (0x00000000UL) /* Output of A/D conversion start request
                                                                         signal monitor 0 is disabled */
#define _00000100_GPTn_AD_START_MONITOR0_ENABLE        (0x00000100UL) /* Output of A/D conversion start request
                                                                         signal monitor 0 is enabled */
/* A/D Conversion Start Request Signal Monitor 1 Selection (ADSMS1[1:0]) */
#define _00010000_GPTn_GTADTRA_DOWN_COUNTING           (0x00010000UL) /* A/D conversion start request signal generated
                                                                         by the GTADTRA during down-counting */
#define _00020000_GPTn_GTADTRB_UP_COUNTING             (0x00020000UL) /* A/D conversion start request signal generated
                                                                         by the GTADTRB during up-counting */
#define _00030000_GPTn_GTADTRB_DOWN_COUNTING           (0x00030000UL) /* A/D conversion start request signal generated
                                                                         by the GTADTRB during down-counting */
/* A/D Conversion Start Request Signal Monitor 1 Output Enabling (ADSMEN1) */
#define _00000000_GPTn_AD_START_MONITOR1_DISABLE       (0x00000000UL) /* Output of A/D conversion start request
                                                                         signal monitor 1 is disabled */
#define _01000000_GPTn_AD_START_MONITOR1_ENABLE        (0x01000000UL) /* Output of A/D conversion start request
                                                                         signal monitor 1 is enabled */

/*
    General PWM Timer Extended Interrupt Skipping Counter Control Register (GTEITC))
*/
/* Extended Interrupt Skipping Counter 1 Count Source Select (EIVTC1[1:0]) */
#define _00000000_GPTn_EXT1_SKIP_DISABLE               (0x00000000UL) /* Not counted */
#define _00000001_GPTn_EXT1_SKIP_OVRF_UDRF             (0x00000001UL) /* Counting both at overflow or underflow */
#define _00000001_GPTn_EXT1_SKIP_CREST                 (0x00000001UL) /* Counting crests */
#define _00000002_GPTn_EXT1_SKIP_TROUGH                (0x00000002UL) /* Counting troughs */
#define _00000003_GPTn_EXT1_SKIP_BOTH                  (0x00000003UL) /* Counting both crests and troughs */
/* Extended Interrupt Skipping 1 Skipping Count Setting (EIVTT1[3:0]) */
#define _00000000_GPTn_EXT1_SKIP_COUNT_0               (0x00000000UL) /* Skipping is not performed */
#define _00000010_GPTn_EXT1_SKIP_1                     (0x00000010UL) /* Skipping count of 1 */
#define _00000020_GPTn_EXT1_SKIP_2                     (0x00000020UL) /* Skipping count of 2 */
#define _00000030_GPTn_EXT1_SKIP_3                     (0x00000030UL) /* Skipping count of 3 */
#define _00000040_GPTn_EXT1_SKIP_4                     (0x00000040UL) /* Skipping count of 4 */
#define _00000050_GPTn_EXT1_SKIP_5                     (0x00000050UL) /* Skipping count of 5 */
#define _00000060_GPTn_EXT1_SKIP_6                     (0x00000060UL) /* Skipping count of 6 */
#define _00000070_GPTn_EXT1_SKIP_7                     (0x00000070UL) /* Skipping count of 7 */
#define _00000080_GPTn_EXT1_SKIP_8                     (0x00000080UL) /* Skipping count of 8 */
#define _00000090_GPTn_EXT1_SKIP_9                     (0x00000090UL) /* Skipping count of 9 */
#define _000000A0_GPTn_EXT1_SKIP_10                    (0x000000A0UL) /* Skipping count of 10 */
#define _000000B0_GPTn_EXT1_SKIP_11                    (0x000000B0UL) /* Skipping count of 11 */
#define _000000C0_GPTn_EXT1_SKIP_12                    (0x000000C0UL) /* Skipping count of 12 */
#define _000000D0_GPTn_EXT1_SKIP_13                    (0x000000D0UL) /* Skipping count of 13 */
#define _000000E0_GPTn_EXT1_SKIP_14                    (0x000000E0UL) /* Skipping count of 14 */
#define _000000F0_GPTn_EXT1_SKIP_15                    (0x000000F0UL) /* Skipping count of 15 */
/* Extended Interrupt Skipping Counter 2 Count Source Select (EIVTC2[1:0]) */
#define _00000000_GPTn_EXT2_SKIP_DISABLE               (0x00000000UL) /* Not counted */
#define _00010000_GPTn_EXT2_SKIP_OVRF_UDRF             (0x00010000UL) /* Counting both at overflow or underflow */
#define _00010000_GPTn_EXT2_SKIP_CREST                 (0x00010000UL) /* Counting crests */
#define _00020000_GPTn_EXT2_SKIP_TROUGH                (0x00020000UL) /* Counting troughs */
#define _00030000_GPTn_EXT2_SKIP_BOTH                  (0x00030000UL) /* Counting both crests and troughs */
/* Extended Interrupt Skipping 2 Skipping Count Setting (EIVTT2[3:0]) */
#define _00000000_GPTn_EXT2_SKIP_COUNT_0               (0x00000000UL) /* Skipping is not performed */
#define _00100000_GPTn_EXT2_SKIP_1                     (0x00100000UL) /* Skipping count of 1 */
#define _00200000_GPTn_EXT2_SKIP_2                     (0x00200000UL) /* Skipping count of 2 */
#define _00300000_GPTn_EXT2_SKIP_3                     (0x00300000UL) /* Skipping count of 3 */
#define _00400000_GPTn_EXT2_SKIP_4                     (0x00400000UL) /* Skipping count of 4 */
#define _00500000_GPTn_EXT2_SKIP_5                     (0x00500000UL) /* Skipping count of 5 */
#define _00600000_GPTn_EXT2_SKIP_6                     (0x00600000UL) /* Skipping count of 6 */
#define _00700000_GPTn_EXT2_SKIP_7                     (0x00700000UL) /* Skipping count of 7 */
#define _00800000_GPTn_EXT2_SKIP_8                     (0x00800000UL) /* Skipping count of 8 */
#define _00900000_GPTn_EXT2_SKIP_9                     (0x00900000UL) /* Skipping count of 9 */
#define _00A00000_GPTn_EXT2_SKIP_10                    (0x00A00000UL) /* Skipping count of 10 */
#define _00B00000_GPTn_EXT2_SKIP_11                    (0x00B00000UL) /* Skipping count of 11 */
#define _00C00000_GPTn_EXT2_SKIP_12                    (0x00C00000UL) /* Skipping count of 12 */
#define _00D00000_GPTn_EXT2_SKIP_13                    (0x00D00000UL) /* Skipping count of 13 */
#define _00E00000_GPTn_EXT2_SKIP_14                    (0x00E00000UL) /* Skipping count of 14 */
#define _00F00000_GPTn_EXT2_SKIP_15                    (0x00F00000UL) /* Skipping count of 15 */
/* Extended Interrupt Skipping Counter 2 Initial Value (EITCNT2IV[3:0]) */
#define _00000000_GPTn_EXT2_SKIP_INIT_0                (0x00000000UL) /* Initial skipping is not performed */
#define _01000000_GPTn_EXT2_SKIP_INIT_1                (0x01000000UL) /* Initial skipping count of 1 */
#define _02000000_GPTn_EXT2_SKIP_INIT_2                (0x02000000UL) /* Initial skipping count of 2 */
#define _03000000_GPTn_EXT2_SKIP_INIT_3                (0x03000000UL) /* Initial skipping count of 3 */
#define _04000000_GPTn_EXT2_SKIP_INIT_4                (0x04000000UL) /* Initial skipping count of 4 */
#define _05000000_GPTn_EXT2_SKIP_INIT_5                (0x05000000UL) /* Initial skipping count of 5 */
#define _06000000_GPTn_EXT2_SKIP_INIT_6                (0x06000000UL) /* Initial skipping count of 6 */
#define _07000000_GPTn_EXT2_SKIP_INIT_7                (0x07000000UL) /* Initial skipping count of 7 */
#define _08000000_GPTn_EXT2_SKIP_INIT_8                (0x08000000UL) /* Initial skipping count of 8 */
#define _09000000_GPTn_EXT2_SKIP_INIT_9                (0x09000000UL) /* Initial skipping count of 9 */
#define _0A000000_GPTn_EXT2_SKIP_INIT_10               (0x0A000000UL) /* Initial skipping count of 10 */
#define _0B000000_GPTn_EXT2_SKIP_INIT_11               (0x0B000000UL) /* Initial skipping count of 11 */
#define _0C000000_GPTn_EXT2_SKIP_INIT_12               (0x0C000000UL) /* Initial skipping count of 12 */
#define _0D000000_GPTn_EXT2_SKIP_INIT_13               (0x0D000000UL) /* Initial skipping count of 13 */
#define _0E000000_GPTn_EXT2_SKIP_INIT_14               (0x0E000000UL) /* Initial skipping count of 14 */
#define _0F000000_GPTn_EXT2_SKIP_INIT_15               (0x0F000000UL) /* Initial skipping count of 15 */

 /*
    General PWM Timer Extended Interrupt Skipping Setting Register 1 (GTEITLI1)
    General PWM Timer Extended Interrupt Skipping Setting Register 2 (GTEITLI2)
    General PWM Timer Extended Buffer Transfer Skipping Setting Register (GTEITLB)
 */
/* GTCCRA Register Compare Match/Input Capture Interrupt Extended Skipping Function Select (EITLA[2:0]) */
/* GTADTRA A/D Converter Start Request Extended Skipping Function Select (EITLA[2:0]) */
/* GTCCRA Register Buffer Transfer Extended Skipping Function Select (EBTLCA[2:0]) */
#define _00000000_GPTn_NO_INT_SKIP_COUNT               (0x00000000UL) /* Do not perform extended interrupt skipping */
#define _00000001_GPTn_EXT1_COUNT_NOT0                 (0x00000001UL) /* When the value for extended interrupt
                                                                         skipping counter 1 is other than 0 */
#define _00000002_GPTn_EXT2_COUNT_NOT0                 (0x00000002UL) /* When the value for extended interrupt
                                                                         skipping counter 2 is other than 0 */
#define _00000003_GPTn_EXT1_OR_EXT2_COUNT_NOT0         (0x00000003UL) /* When the value for extended interrupt
                                                                         skipping counter 1 or 2 is other than 0 */
#define _00000005_GPTn_EXT1_NOT_SKIP_COUNT             (0x00000005UL) /* When the value for extended interrupt
                                                                         skipping counter 1 other than skipping count */
#define _00000006_GPTn_EXT2_NOT_SKIP_COUNT             (0x00000006UL) /* When the value for extended interrupt
                                                                         skipping counter 2 other than skipping count */
#define _00000007_GPTn_EXT1_OR_EXT2_NOT_SKIP_COUNT     (0x00000007UL) /* When the value for extended interrupt skipping
                                                                         counter 1 or 2 other than skipping count */
/* GTCCRB Register Compare Match/Input Capture Interrupt Extended Skipping Function Select (EITLB[2:0]) */
/* GTCCRB Register Compare Match/Input Capture Interrupt Extended Skipping Function Select (EITLB[2:0]) */
/* GTADTRB A/D Converter Start Request Extended Skipping Function Select (EADTBL[2:0]) */
/* GTCCRB Register Buffer Transfer Extended Skipping Function Select (EBTLCB[2:0]) */
#define _00000010_GPTn_EXT1_COUNT_NOT0                 (0x00000010UL) /* When the value for extended interrupt
                                                                         skipping counter 1 is other than 0 */
#define _00000020_GPTn_EXT2_COUNT_NOT0                 (0x00000020UL) /* When the value for extended interrupt
                                                                         skipping counter 2 is other than 0 */
#define _00000030_GPTn_EXT1_OR_EXT2_COUNT_NOT0         (0x00000030UL) /* When the value for extended interrupt
                                                                         skipping counter 1 or 2 is other than 0 */
#define _00000050_GPTn_EXT1_NOT_SKIP_COUNT             (0x00000050UL) /* When the value for extended interrupt
                                                                         skipping counter 1 other than skipping count */
#define _00000060_GPTn_EXT2_NOT_SKIP_COUNT             (0x00000060UL) /* When the value for extended interrupt
                                                                         skipping counter 2 other than skipping count */
#define _00000070_GPTn_EXT1_OR_EXT2_NOT_SKIP_COUNT     (0x00000070UL) /* When the value for extended interrupt skipping
                                                                         counter 1 or 2 other than skipping count */
/* GTCCRC Register Compare Match/Input Capture Interrupt Extended Skipping Function Select (EITLC[2:0]) */
/* GTPR Register Buffer Transfer Extended Skipping Function Select (EBTLPR[2:0]) */
#define _00000100_GPTn_EXT1_COUNT_NOT0                 (0x00000100UL) /* When the value for extended interrupt
                                                                         skipping counter 1 is other than 0 */
#define _00000200_GPTn_EXT2_COUNT_NOT0                 (0x00000200UL) /* When the value for extended interrupt
                                                                         skipping counter 2 is other than 0 */
#define _00000300_GPTn_EXT1_OR_EXT2_COUNT_NOT0         (0x00000300UL) /* When the value for extended interrupt
                                                                         skipping counter 1 or 2 is other than 0 */
#define _00000500_GPTn_EXT1_NOT_SKIP_COUNT             (0x00000500UL) /* When the value for extended interrupt
                                                                         skipping counter 1 other than skipping count */
#define _00000600_GPTn_EXT2_NOT_SKIP_COUNT             (0x00000600UL) /* When the value for extended interrupt
                                                                         skipping counter 2 other than skipping count */
#define _00000700_GPTn_EXT1_OR_EXT2_NOT_SKIP_COUNT     (0x00000700UL) /* When the value for extended interrupt skipping
                                                                         counter 1 or 2 other than skipping count */
/* GTCCRD Register Compare Match/Input Capture Interrupt Extended Skipping Function Select (EITLD[2:0]) */
#define _00001000_GPTn_EXT1_COUNT_NOT0                 (0x00001000UL) /* When the value for extended interrupt
                                                                         skipping counter 1 is other than 0 */
#define _00002000_GPTn_EXT2_COUNT_NOT0                 (0x00002000UL) /* When the value for extended interrupt
                                                                         skipping counter 2 is other than 0 */
#define _00003000_GPTn_EXT1_OR_EXT2_COUNT_NOT0         (0x00003000UL) /* When the value for extended interrupt
                                                                         skipping counter 1 or 2 is other than 0 */
#define _00005000_GPTn_EXT1_NOT_SKIP_COUNT             (0x00005000UL) /* When the value for extended interrupt
                                                                         skipping counter 1 other than skipping count */
#define _00006000_GPTn_EXT2_NOT_SKIP_COUNT             (0x00006000UL) /* When the value for extended interrupt
                                                                         skipping counter 2 other than skipping count */
#define _00007000_GPTn_EXT1_OR_EXT2_NOT_SKIP_COUNT     (0x00007000UL) /* When the value for extended interrupt skipping
                                                                         counter 1 or 2 other than skipping count */
/* GTCCRE Register Compare Match/Input Capture Interrupt Extended Skipping Function Select (EITLE[2:0]) */
/* GTADTRA Register Buffer Transfer Extended Skipping Function Select (EBTLADA[2:0]) */
#define _00010000_GPTn_EXT1_COUNT_NOT0                 (0x00010000UL) /* When the value for extended interrupt
                                                                         skipping counter 1 is other than 0 */
#define _00020000_GPTn_EXT2_COUNT_NOT0                 (0x00020000UL) /* When the value for extended interrupt
                                                                         skipping counter 2 is other than 0 */
#define _00030000_GPTn_EXT1_OR_EXT2_COUNT_NOT0         (0x00030000UL) /* When the value for extended interrupt
                                                                         skipping counter 1 or 2 is other than 0 */
#define _00050000_GPTn_EXT1_NOT_SKIP_COUNT             (0x00050000UL) /* When the value for extended interrupt
                                                                         skipping counter 1 other than skipping count */
#define _00060000_GPTn_EXT2_NOT_SKIP_COUNT             (0x00060000UL) /* When the value for extended interrupt
                                                                         skipping counter 2 other than skipping count */
#define _00070000_GPTn_EXT1_OR_EXT2_NOT_SKIP_COUNT     (0x00070000UL) /* When the value for extended interrupt skipping
                                                                         counter 1 or 2 other than skipping count */
/* GTCCRF Register Compare Match/Input Capture Interrupt Extended Skipping Function Select (EITLF[2:0]) */
/* GTADTRB Register Buffer Transfer Extended Skipping Function Select (EBTLADB[2:0]) */
#define _00100000_GPTn_EXT1_COUNT_NOT0                 (0x00100000UL) /* When the value for extended interrupt
                                                                         skipping counter 1 is other than 0 */
#define _00200000_GPTn_EXT2_COUNT_NOT0                 (0x00200000UL) /* When the value for extended interrupt
                                                                         skipping counter 2 is other than 0 */
#define _00300000_GPTn_EXT1_OR_EXT2_COUNT_NOT0         (0x00300000UL) /* When the value for extended interrupt
                                                                         skipping counter 1 or 2 is other than 0 */
#define _00500000_GPTn_EXT1_NOT_SKIP_COUNT             (0x00500000UL) /* When the value for extended interrupt
                                                                         skipping counter 1 other than skipping count */
#define _00600000_GPTn_EXT2_NOT_SKIP_COUNT             (0x00600000UL) /* When the value for extended interrupt
                                                                         skipping counter 2 other than skipping count */
#define _00700000_GPTn_EXT1_OR_EXT2_NOT_SKIP_COUNT     (0x00700000UL) /* When the value for extended interrupt skipping
                                                                         counter 1 or 2 other than skipping count */
/* Overflow Interrupt Extended Skipping Function Select (EITLV[2:0]) */
/* GTDVU Register Buffer Transfer Extended Skipping Function Select (EBTLDVU[2:0]) */
#define _01000000_GPTn_EXT1_COUNT_NOT0                 (0x01000000UL) /* When the value for extended interrupt
                                                                         skipping counter 1 is other than 0 */
#define _02000000_GPTn_EXT2_COUNT_NOT0                 (0x02000000UL) /* When the value for extended interrupt
                                                                         skipping counter 2 is other than 0 */
#define _03000000_GPTn_EXT1_OR_EXT2_COUNT_NOT0         (0x03000000UL) /* When the value for extended interrupt
                                                                         skipping counter 1 or 2 is other than 0 */
#define _05000000_GPTn_EXT1_NOT_SKIP_COUNT             (0x05000000UL) /* When the value for extended interrupt
                                                                         skipping counter 1 other than skipping count */
#define _06000000_GPTn_EXT2_NOT_SKIP_COUNT             (0x06000000UL) /* When the value for extended interrupt
                                                                         skipping counter 2 other than skipping count */
#define _07000000_GPTn_EXT1_OR_EXT2_NOT_SKIP_COUNT     (0x07000000UL) /* When the value for extended interrupt skipping
                                                                         counter 1 or 2 other than skipping count */
/* Underflow Interrupt Extended Skipping Function Select (EITLU[2:0]) */
/* GTDVD Register Buffer Transfer Extended Skipping Function Select (EBTLDVD[2:0]) */
#define _10000000_GPTn_EXT1_COUNT_NOT0                 (0x10000000UL) /* When the value for extended interrupt
                                                                         skipping counter 1 is other than 0 */
#define _20000000_GPTn_EXT2_COUNT_NOT0                 (0x20000000UL) /* When the value for extended interrupt
                                                                         skipping counter 2 is other than 0 */
#define _30000000_GPTn_EXT1_OR_EXT2_COUNT_NOT0         (0x30000000UL) /* When the value for extended interrupt
                                                                         skipping counter 1 or 2 is other than 0 */
#define _50000000_GPTn_EXT1_NOT_SKIP_COUNT             (0x50000000UL) /* When the value for extended interrupt
                                                                         skipping counter 1 other than skipping count */
#define _60000000_GPTn_EXT2_NOT_SKIP_COUNT             (0x60000000UL) /* When the value for extended interrupt
                                                                         skipping counter 2 other than skipping count */
#define _70000000_GPTn_EXT1_OR_EXT2_NOT_SKIP_COUNT     (0x70000000UL) /* When the value for extended interrupt skipping
                                                                         counter 1 or 2 other than skipping count */

/*
    HRPWM Operation Control Register (HROCR)
*/
/* DLL Operation Enable (DLLEN) */
#define _0000_GPTn_DLL_DISABLE                         (0x0000U) /* DLL operation is disabled */
#define _0001_GPTn_DLL_ENABLE                          (0x0001U) /* DLL operation is enabled */

/*
    HRPWM Operation Control Register 2 (HROCR2)
*/
/* Channel 0 High Resolution PWM Waveform Output Select(HRSEL0) */
#define _0000_GPT0_HRPWM_DISABLE                       (0x0000U) /* Output an original PWM waveform generated by GPTW0
                                                                      from the GTIOC0A and GTIOC0B pins */
#define _0001_GPT0_HRPWM_ENABLE                        (0x0001U) /* Output a high resolution PWM waveform from GTIOC0A
                                                                      and GTIOC0B pins */
/* Channel 1 High Resolution PWM Waveform Output Select(HRSEL1) */
#define _0000_GPT1_HRPWM_DISABLE                       (0x0000U) /* Output an original PWM waveform generated by GPTW1
                                                                      from the GTIOC1A and GTIOC1B pins */
#define _0002_GPT1_HRPWM_ENABLE                        (0x0002U) /* Output a high resolution PWM waveform from GTIOC1A
                                                                      and GTIOC1B pins */
/* Channel 2 High Resolution PWM Waveform Output Select(HRSEL2) */
#define _0000_GPT2_HRPWM_DISABLE                       (0x0000U) /* Output an original PWM waveform generated by GPTW2
                                                                      from the GTIOC2A and GTIOC2B pins */
#define _0004_GPT2_HRPWM_ENABLE                        (0x0004U) /* Output a high resolution PWM waveform from GTIOC2A
                                                                      and GTIOC2B pins */
/* Channel 3 High Resolution PWM Waveform Output Select(HRSEL3) */
#define _0000_GPT3_HRPWM_DISABLE                       (0x0000U) /* Output an original PWM waveform generated by GPTW3
                                                                      from the GTIOC3A and GTIOC3B pins */
#define _0008_GPT3_HRPWM_ENABLE                        (0x0008U) /* Output a high resolution PWM waveform from GTIOC3A
                                                                      and GTIOC3B pins */
/* Channel 0 Rising and Falling Edge Adjustment Circuit Disable(HRDIS0) */
#define _0000_GPT0_EDGEADJUST_ENABLE                   (0x0000U) /* Enable operation of Channel 0 rising and falling
                                                                     edge adjustment circuit */
#define _0100_GPT0_EDGEADJUST_DISABLE                  (0x0100U) /* Disable operation of Channel 0 rising and falling
                                                                     edge adjustment circuit */
/* Channel 1 Rising and Falling Edge Adjustment Circuit Disable(HRDIS1) */
#define _0000_GPT1_EDGEADJUST_ENABLE                   (0x0000U) /* Enable operation of Channel 1 rising and falling
                                                                     edge adjustment circuit */
#define _0200_GPT1_EDGEADJUST_DISABLE                  (0x0200U) /* Disable operation of Channel 1 rising and falling
                                                                     edge adjustment circuit */
/* Channel 2 Rising and Falling Edge Adjustment Circuit Disable(HRDIS2) */
#define _0000_GPT2_EDGEADJUST_ENABLE                   (0x0000U) /* Enable operation of Channel 2 rising and falling
                                                                     edge adjustment circuit */
#define _0400_GPT2_EDGEADJUST_DISABLE                  (0x0400U) /* Disable operation of Channel 2 rising and falling
                                                                     edge adjustment circuit */
/* Channel 3 Rising and Falling Edge Adjustment Circuit Disable(HRDIS3) */
#define _0000_GPT3_EDGEADJUST_ENABLE                   (0x0000U) /* Enable operation of Channel 3 rising and falling
                                                                     edge adjustment circuit */
#define _0800_GPT3_EDGEADJUST_DISABLE                  (0x0800U) /* Disable operation of Channel 3 rising and falling
                                                                     edge adjustment circuit */

/*
    GTIOCnA Pin Rising Edge Adjustment Register (HRREARnA) (n = 0 to 3)
*/
/* Amount of Delay Select (DLY) */
#define _0000_GPTn_GTIOCA_RISE_DELAY0                  (0x0000U) /* Apply delay of 0/32 times PCLKC period */
#define _0001_GPTn_GTIOCA_RISE_DELAY1                  (0x0001U) /* Apply delay of 1/32 times PCLKC period */
#define _0002_GPTn_GTIOCA_RISE_DELAY2                  (0x0002U) /* Apply delay of 2/32 times PCLKC period */
#define _0003_GPTn_GTIOCA_RISE_DELAY3                  (0x0003U) /* Apply delay of 3/32 times PCLKC period */
#define _0004_GPTn_GTIOCA_RISE_DELAY4                  (0x0004U) /* Apply delay of 4/32 times PCLKC period */
#define _0005_GPTn_GTIOCA_RISE_DELAY5                  (0x0005U) /* Apply delay of 5/32 times PCLKC period */
#define _0006_GPTn_GTIOCA_RISE_DELAY6                  (0x0006U) /* Apply delay of 6/32 times PCLKC period */
#define _0007_GPTn_GTIOCA_RISE_DELAY7                  (0x0007U) /* Apply delay of 7/32 times PCLKC period */
#define _0008_GPTn_GTIOCA_RISE_DELAY8                  (0x0008U) /* Apply delay of 8/32 times PCLKC period */
#define _0009_GPTn_GTIOCA_RISE_DELAY9                  (0x0009U) /* Apply delay of 9/32 times PCLKC period */
#define _000A_GPTn_GTIOCA_RISE_DELAY10                 (0x000AU) /* Apply delay of 10/32 times PCLKC period */
#define _000B_GPTn_GTIOCA_RISE_DELAY11                 (0x000BU) /* Apply delay of 11/32 times PCLKC period */
#define _000C_GPTn_GTIOCA_RISE_DELAY12                 (0x000CU) /* Apply delay of 12/32 times PCLKC period */
#define _000D_GPTn_GTIOCA_RISE_DELAY13                 (0x000DU) /* Apply delay of 13/32 times PCLKC period */
#define _000E_GPTn_GTIOCA_RISE_DELAY14                 (0x000EU) /* Apply delay of 14/32 times PCLKC period */
#define _000F_GPTn_GTIOCA_RISE_DELAY15                 (0x000FU) /* Apply delay of 15/32 times PCLKC period */
#define _0010_GPTn_GTIOCA_RISE_DELAY16                 (0x0010U) /* Apply delay of 16/32 times PCLKC period */
#define _0011_GPTn_GTIOCA_RISE_DELAY17                 (0x0011U) /* Apply delay of 17/32 times PCLKC period */
#define _0012_GPTn_GTIOCA_RISE_DELAY18                 (0x0012U) /* Apply delay of 18/32 times PCLKC period */
#define _0013_GPTn_GTIOCA_RISE_DELAY19                 (0x0013U) /* Apply delay of 19/32 times PCLKC period */
#define _0014_GPTn_GTIOCA_RISE_DELAY20                 (0x0014U) /* Apply delay of 20/32 times PCLKC period */
#define _0015_GPTn_GTIOCA_RISE_DELAY21                 (0x0015U) /* Apply delay of 21/32 times PCLKC period */
#define _0016_GPTn_GTIOCA_RISE_DELAY22                 (0x0016U) /* Apply delay of 22/32 times PCLKC period */
#define _0017_GPTn_GTIOCA_RISE_DELAY23                 (0x0017U) /* Apply delay of 23/32 times PCLKC period */
#define _0018_GPTn_GTIOCA_RISE_DELAY24                 (0x0018U) /* Apply delay of 24/32 times PCLKC period */
#define _0019_GPTn_GTIOCA_RISE_DELAY25                 (0x0019U) /* Apply delay of 25/32 times PCLKC period */
#define _001A_GPTn_GTIOCA_RISE_DELAY26                 (0x001AU) /* Apply delay of 26/32 times PCLKC period */
#define _001B_GPTn_GTIOCA_RISE_DELAY27                 (0x001BU) /* Apply delay of 27/32 times PCLKC period */
#define _001C_GPTn_GTIOCA_RISE_DELAY28                 (0x001CU) /* Apply delay of 28/32 times PCLKC period */
#define _001D_GPTn_GTIOCA_RISE_DELAY29                 (0x001DU) /* Apply delay of 29/32 times PCLKC period */
#define _001E_GPTn_GTIOCA_RISE_DELAY30                 (0x001EU) /* Apply delay of 30/32 times PCLKC period */
#define _001F_GPTn_GTIOCA_RISE_DELAY31                 (0x001FU) /* Apply delay of 31/32 times PCLKC period */

/*
    GTIOCnA Pin Falling Edge Adjustment Register (HRFEARnA) (n = 0 to 3)
*/
/* Amount of Delay Select (DLY) */
#define _0000_GPTn_GTIOCA_FALL_DELAY0                  (0x0000U) /* Apply delay of 0/32 times PCLKC period */
#define _0001_GPTn_GTIOCA_FALL_DELAY1                  (0x0001U) /* Apply delay of 1/32 times PCLKC period */
#define _0002_GPTn_GTIOCA_FALL_DELAY2                  (0x0002U) /* Apply delay of 2/32 times PCLKC period */
#define _0003_GPTn_GTIOCA_FALL_DELAY3                  (0x0003U) /* Apply delay of 3/32 times PCLKC period */
#define _0004_GPTn_GTIOCA_FALL_DELAY4                  (0x0004U) /* Apply delay of 4/32 times PCLKC period */
#define _0005_GPTn_GTIOCA_FALL_DELAY5                  (0x0005U) /* Apply delay of 5/32 times PCLKC period */
#define _0006_GPTn_GTIOCA_FALL_DELAY6                  (0x0006U) /* Apply delay of 6/32 times PCLKC period */
#define _0007_GPTn_GTIOCA_FALL_DELAY7                  (0x0007U) /* Apply delay of 7/32 times PCLKC period */
#define _0008_GPTn_GTIOCA_FALL_DELAY8                  (0x0008U) /* Apply delay of 8/32 times PCLKC period */
#define _0009_GPTn_GTIOCA_FALL_DELAY9                  (0x0009U) /* Apply delay of 9/32 times PCLKC period */
#define _000A_GPTn_GTIOCA_FALL_DELAY10                 (0x000AU) /* Apply delay of 10/32 times PCLKC period */
#define _000B_GPTn_GTIOCA_FALL_DELAY11                 (0x000BU) /* Apply delay of 11/32 times PCLKC period */
#define _000C_GPTn_GTIOCA_FALL_DELAY12                 (0x000CU) /* Apply delay of 12/32 times PCLKC period */
#define _000D_GPTn_GTIOCA_FALL_DELAY13                 (0x000DU) /* Apply delay of 13/32 times PCLKC period */
#define _000E_GPTn_GTIOCA_FALL_DELAY14                 (0x000EU) /* Apply delay of 14/32 times PCLKC period */
#define _000F_GPTn_GTIOCA_FALL_DELAY15                 (0x000FU) /* Apply delay of 15/32 times PCLKC period */
#define _0010_GPTn_GTIOCA_FALL_DELAY16                 (0x0010U) /* Apply delay of 16/32 times PCLKC period */
#define _0011_GPTn_GTIOCA_FALL_DELAY17                 (0x0011U) /* Apply delay of 17/32 times PCLKC period */
#define _0012_GPTn_GTIOCA_FALL_DELAY18                 (0x0012U) /* Apply delay of 18/32 times PCLKC period */
#define _0013_GPTn_GTIOCA_FALL_DELAY19                 (0x0013U) /* Apply delay of 19/32 times PCLKC period */
#define _0014_GPTn_GTIOCA_FALL_DELAY20                 (0x0014U) /* Apply delay of 20/32 times PCLKC period */
#define _0015_GPTn_GTIOCA_FALL_DELAY21                 (0x0015U) /* Apply delay of 21/32 times PCLKC period */
#define _0016_GPTn_GTIOCA_FALL_DELAY22                 (0x0016U) /* Apply delay of 22/32 times PCLKC period */
#define _0017_GPTn_GTIOCA_FALL_DELAY23                 (0x0017U) /* Apply delay of 23/32 times PCLKC period */
#define _0018_GPTn_GTIOCA_FALL_DELAY24                 (0x0018U) /* Apply delay of 24/32 times PCLKC period */
#define _0019_GPTn_GTIOCA_FALL_DELAY25                 (0x0019U) /* Apply delay of 25/32 times PCLKC period */
#define _001A_GPTn_GTIOCA_FALL_DELAY26                 (0x001AU) /* Apply delay of 26/32 times PCLKC period */
#define _001B_GPTn_GTIOCA_FALL_DELAY27                 (0x001BU) /* Apply delay of 27/32 times PCLKC period */
#define _001C_GPTn_GTIOCA_FALL_DELAY28                 (0x001CU) /* Apply delay of 28/32 times PCLKC period */
#define _001D_GPTn_GTIOCA_FALL_DELAY29                 (0x001DU) /* Apply delay of 29/32 times PCLKC period */
#define _001E_GPTn_GTIOCA_FALL_DELAY30                 (0x001EU) /* Apply delay of 30/32 times PCLKC period */
#define _001F_GPTn_GTIOCA_FALL_DELAY31                 (0x001FU) /* Apply delay of 31/32 times PCLKC period */

/*
    GTIOCnB Pin Rising Edge Adjustment Register (HRREARnB) (n = 0 to 3)
*/
/* Amount of Delay Select (DLY) */
#define _0000_GPTn_GTIOCB_RISE_DELAY0                  (0x0000U) /* Apply delay of 0/32 times PCLKC period */
#define _0001_GPTn_GTIOCB_RISE_DELAY1                  (0x0001U) /* Apply delay of 1/32 times PCLKC period */
#define _0002_GPTn_GTIOCB_RISE_DELAY2                  (0x0002U) /* Apply delay of 2/32 times PCLKC period */
#define _0003_GPTn_GTIOCB_RISE_DELAY3                  (0x0003U) /* Apply delay of 3/32 times PCLKC period */
#define _0004_GPTn_GTIOCB_RISE_DELAY4                  (0x0004U) /* Apply delay of 4/32 times PCLKC period */
#define _0005_GPTn_GTIOCB_RISE_DELAY5                  (0x0005U) /* Apply delay of 5/32 times PCLKC period */
#define _0006_GPTn_GTIOCB_RISE_DELAY6                  (0x0006U) /* Apply delay of 6/32 times PCLKC period */
#define _0007_GPTn_GTIOCB_RISE_DELAY7                  (0x0007U) /* Apply delay of 7/32 times PCLKC period */
#define _0008_GPTn_GTIOCB_RISE_DELAY8                  (0x0008U) /* Apply delay of 8/32 times PCLKC period */
#define _0009_GPTn_GTIOCB_RISE_DELAY9                  (0x0009U) /* Apply delay of 9/32 times PCLKC period */
#define _000A_GPTn_GTIOCB_RISE_DELAY10                 (0x000AU) /* Apply delay of 10/32 times PCLKC period */
#define _000B_GPTn_GTIOCB_RISE_DELAY11                 (0x000BU) /* Apply delay of 11/32 times PCLKC period */
#define _000C_GPTn_GTIOCB_RISE_DELAY12                 (0x000CU) /* Apply delay of 12/32 times PCLKC period */
#define _000D_GPTn_GTIOCB_RISE_DELAY13                 (0x000DU) /* Apply delay of 13/32 times PCLKC period */
#define _000E_GPTn_GTIOCB_RISE_DELAY14                 (0x000EU) /* Apply delay of 14/32 times PCLKC period */
#define _000F_GPTn_GTIOCB_RISE_DELAY15                 (0x000FU) /* Apply delay of 15/32 times PCLKC period */
#define _0010_GPTn_GTIOCB_RISE_DELAY16                 (0x0010U) /* Apply delay of 16/32 times PCLKC period */
#define _0011_GPTn_GTIOCB_RISE_DELAY17                 (0x0011U) /* Apply delay of 17/32 times PCLKC period */
#define _0012_GPTn_GTIOCB_RISE_DELAY18                 (0x0012U) /* Apply delay of 18/32 times PCLKC period */
#define _0013_GPTn_GTIOCB_RISE_DELAY19                 (0x0013U) /* Apply delay of 19/32 times PCLKC period */
#define _0014_GPTn_GTIOCB_RISE_DELAY20                 (0x0014U) /* Apply delay of 20/32 times PCLKC period */
#define _0015_GPTn_GTIOCB_RISE_DELAY21                 (0x0015U) /* Apply delay of 21/32 times PCLKC period */
#define _0016_GPTn_GTIOCB_RISE_DELAY22                 (0x0016U) /* Apply delay of 22/32 times PCLKC period */
#define _0017_GPTn_GTIOCB_RISE_DELAY23                 (0x0017U) /* Apply delay of 23/32 times PCLKC period */
#define _0018_GPTn_GTIOCB_RISE_DELAY24                 (0x0018U) /* Apply delay of 24/32 times PCLKC period */
#define _0019_GPTn_GTIOCB_RISE_DELAY25                 (0x0019U) /* Apply delay of 25/32 times PCLKC period */
#define _001A_GPTn_GTIOCB_RISE_DELAY26                 (0x001AU) /* Apply delay of 26/32 times PCLKC period */
#define _001B_GPTn_GTIOCB_RISE_DELAY27                 (0x001BU) /* Apply delay of 27/32 times PCLKC period */
#define _001C_GPTn_GTIOCB_RISE_DELAY28                 (0x001CU) /* Apply delay of 28/32 times PCLKC period */
#define _001D_GPTn_GTIOCB_RISE_DELAY29                 (0x001DU) /* Apply delay of 29/32 times PCLKC period */
#define _001E_GPTn_GTIOCB_RISE_DELAY30                 (0x001EU) /* Apply delay of 30/32 times PCLKC period */
#define _001F_GPTn_GTIOCB_RISE_DELAY31                 (0x001FU) /* Apply delay of 31/32 times PCLKC period */

/*
    GTIOCnB Pin Falling Edge Adjustment Register (HRFEARnB) (n = 0 to 3)
*/
/* Amount of Delay Select (DLY) */
#define _0000_GPTn_GTIOCB_FALL_DELAY0                  (0x0000U) /* Apply delay of 0/32 times PCLKC period */
#define _0001_GPTn_GTIOCB_FALL_DELAY1                  (0x0001U) /* Apply delay of 1/32 times PCLKC period */
#define _0002_GPTn_GTIOCB_FALL_DELAY2                  (0x0002U) /* Apply delay of 2/32 times PCLKC period */
#define _0003_GPTn_GTIOCB_FALL_DELAY3                  (0x0003U) /* Apply delay of 3/32 times PCLKC period */
#define _0004_GPTn_GTIOCB_FALL_DELAY4                  (0x0004U) /* Apply delay of 4/32 times PCLKC period */
#define _0005_GPTn_GTIOCB_FALL_DELAY5                  (0x0005U) /* Apply delay of 5/32 times PCLKC period */
#define _0006_GPTn_GTIOCB_FALL_DELAY6                  (0x0006U) /* Apply delay of 6/32 times PCLKC period */
#define _0007_GPTn_GTIOCB_FALL_DELAY7                  (0x0007U) /* Apply delay of 7/32 times PCLKC period */
#define _0008_GPTn_GTIOCB_FALL_DELAY8                  (0x0008U) /* Apply delay of 8/32 times PCLKC period */
#define _0009_GPTn_GTIOCB_FALL_DELAY9                  (0x0009U) /* Apply delay of 9/32 times PCLKC period */
#define _000A_GPTn_GTIOCB_FALL_DELAY10                 (0x000AU) /* Apply delay of 10/32 times PCLKC period */
#define _000B_GPTn_GTIOCB_FALL_DELAY11                 (0x000BU) /* Apply delay of 11/32 times PCLKC period */
#define _000C_GPTn_GTIOCB_FALL_DELAY12                 (0x000CU) /* Apply delay of 12/32 times PCLKC period */
#define _000D_GPTn_GTIOCB_FALL_DELAY13                 (0x000DU) /* Apply delay of 13/32 times PCLKC period */
#define _000E_GPTn_GTIOCB_FALL_DELAY14                 (0x000EU) /* Apply delay of 14/32 times PCLKC period */
#define _000F_GPTn_GTIOCB_FALL_DELAY15                 (0x000FU) /* Apply delay of 15/32 times PCLKC period */
#define _0010_GPTn_GTIOCB_FALL_DELAY16                 (0x0010U) /* Apply delay of 16/32 times PCLKC period */
#define _0011_GPTn_GTIOCB_FALL_DELAY17                 (0x0011U) /* Apply delay of 17/32 times PCLKC period */
#define _0012_GPTn_GTIOCB_FALL_DELAY18                 (0x0012U) /* Apply delay of 18/32 times PCLKC period */
#define _0013_GPTn_GTIOCB_FALL_DELAY19                 (0x0013U) /* Apply delay of 19/32 times PCLKC period */
#define _0014_GPTn_GTIOCB_FALL_DELAY20                 (0x0014U) /* Apply delay of 20/32 times PCLKC period */
#define _0015_GPTn_GTIOCB_FALL_DELAY21                 (0x0015U) /* Apply delay of 21/32 times PCLKC period */
#define _0016_GPTn_GTIOCB_FALL_DELAY22                 (0x0016U) /* Apply delay of 22/32 times PCLKC period */
#define _0017_GPTn_GTIOCB_FALL_DELAY23                 (0x0017U) /* Apply delay of 23/32 times PCLKC period */
#define _0018_GPTn_GTIOCB_FALL_DELAY24                 (0x0018U) /* Apply delay of 24/32 times PCLKC period */
#define _0019_GPTn_GTIOCB_FALL_DELAY25                 (0x0019U) /* Apply delay of 25/32 times PCLKC period */
#define _001A_GPTn_GTIOCB_FALL_DELAY26                 (0x001AU) /* Apply delay of 26/32 times PCLKC period */
#define _001B_GPTn_GTIOCB_FALL_DELAY27                 (0x001BU) /* Apply delay of 27/32 times PCLKC period */
#define _001C_GPTn_GTIOCB_FALL_DELAY28                 (0x001CU) /* Apply delay of 28/32 times PCLKC period */
#define _001D_GPTn_GTIOCB_FALL_DELAY29                 (0x001DU) /* Apply delay of 29/32 times PCLKC period */
#define _001E_GPTn_GTIOCB_FALL_DELAY30                 (0x001EU) /* Apply delay of 30/32 times PCLKC period */
#define _001F_GPTn_GTIOCB_FALL_DELAY31                 (0x001FU) /* Apply delay of 31/32 times PCLKC period */

/*
    Interrupt source Priority Register n (IPRn)
*/
/* Interrupt Priority Level Select (IPR[3:0]) */
#define _00_GPT_PRIORITY_LEVEL0                        (0x00U) /* Level 0 (interrupt disabled) */
#define _01_GPT_PRIORITY_LEVEL1                        (0x01U) /* Level 1 */
#define _02_GPT_PRIORITY_LEVEL2                        (0x02U) /* Level 2 */
#define _03_GPT_PRIORITY_LEVEL3                        (0x03U) /* Level 3 */
#define _04_GPT_PRIORITY_LEVEL4                        (0x04U) /* Level 4 */
#define _05_GPT_PRIORITY_LEVEL5                        (0x05U) /* Level 5 */
#define _06_GPT_PRIORITY_LEVEL6                        (0x06U) /* Level 6 */
#define _07_GPT_PRIORITY_LEVEL7                        (0x07U) /* Level 7 */
#define _08_GPT_PRIORITY_LEVEL8                        (0x08U) /* Level 8 */
#define _09_GPT_PRIORITY_LEVEL9                        (0x09U) /* Level 9 */
#define _0A_GPT_PRIORITY_LEVEL10                       (0x0AU) /* Level 10 */
#define _0B_GPT_PRIORITY_LEVEL11                       (0x0BU) /* Level 11 */
#define _0C_GPT_PRIORITY_LEVEL12                       (0x0CU) /* Level 12 */
#define _0D_GPT_PRIORITY_LEVEL13                       (0x0DU) /* Level 13 */
#define _0E_GPT_PRIORITY_LEVEL14                       (0x0EU) /* Level 14 */
#define _0F_GPT_PRIORITY_LEVEL15                       (0x0FU) /* Level 15 (highest) */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
