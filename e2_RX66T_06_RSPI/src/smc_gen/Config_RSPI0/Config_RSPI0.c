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
* File Name        : Config_RSPI0.c
* Component Version: 1.12.0
* Device(s)        : R5F566TEAxFM
* Description      : This file implements device driver for Config_RSPI0.
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
#include "Config_RSPI0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
volatile uint16_t * gp_rspi0_tx_address;              /* RSPI0 transmit buffer address */
volatile uint16_t g_rspi0_tx_count;                   /* RSPI0 transmit data number */
volatile uint16_t * gp_rspi0_rx_address;              /* RSPI0 receive buffer address */
volatile uint16_t g_rspi0_rx_count;                   /* RSPI0 receive data number */
volatile uint16_t g_rspi0_rx_length;                  /* RSPI0 receive data length */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_RSPI0_Create
* Description  : This function initializes RSPI0
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_RSPI0_Create(void)
{
    volatile uint8_t spcr_dummy;

    /* Disable RSPI interrupts */
    IEN(RSPI0,SPTI0) = 0U;
    IEN(RSPI0,SPRI0) = 0U;
    ICU.GENAL0.BIT.EN17 = 0U;
    ICU.GENAL0.BIT.EN16 = 0U;

    /* Cancel RSPI0 module stop state */
    MSTP(RSPI0) = 0U;

    /* Disable RSPI function */
    RSPI0.SPCR.BIT.SPE = 0U;

    /* Set control registers */
    RSPI0.SPPCR.BYTE = _00_RSPI_MOSI_FIXING_PREV_TRANSFER | _00_RSPI_LOOPBACK_DISABLED | _00_RSPI_LOOPBACK2_DISABLED;
    RSPI0.SPBR = _27_RSPI0_DIVISOR;
    RSPI0.SPDCR.BYTE = _00_RSPI_ACCESS_WORD | _00_RSPI_FRAMES_1;
    RSPI0.SPCKD.BYTE = _02_RSPI_RSPCK_DELAY_3;
    RSPI0.SSLND.BYTE = _02_RSPI_SSL_NEGATION_DELAY_3;
    RSPI0.SPND.BYTE = _00_RSPI_NEXT_ACCESS_DELAY_1;
    RSPI0.SPCR2.BYTE = _00_RSPI_PARITY_DISABLE | _00_RSPI_AUTO_STOP_DISABLED;
    RSPI0.SPSCR.BYTE = _00_RSPI_SEQUENCE_LENGTH_1;
    RSPI0.SPCMD0.WORD = _0001_RSPI_RSPCK_SAMPLING_EVEN | _0002_RSPI_RSPCK_POLARITY_HIGH | _0004_RSPI_BASE_BITRATE_2 | 
                        _0F00_RSPI_DATA_LENGTH_BITS_16 | _0000_RSPI_MSB_FIRST | _0000_RSPI_NEXT_ACCESS_DELAY_DISABLE | 
                        _0000_RSPI_NEGATION_DELAY_DISABLE | _0000_RSPI_RSPCK_DELAY_DISABLE;
    RSPI0.SPDCR2.BYTE = _00_RSPI_BYTESWAP_DISABLED;

    /* Set SPTI0 priority level */
    IPR(RSPI0,SPTI0) = _0D_RSPI_PRIORITY_LEVEL13;

    /* Set SPRI0 priority level */
    IPR(RSPI0,SPRI0) = _0D_RSPI_PRIORITY_LEVEL13;

    /* Set RSPCKA pin */
    MPC.PB3PFS.BYTE = 0x0DU;
    PORTB.ODR0.BYTE &= 0xBFU;
    PORTB.PMR.BYTE |= 0x08U;

    /* Set MOSIA pin */
    MPC.PB0PFS.BYTE = 0x0DU;
    PORTB.ODR0.BYTE &= 0xFEU;
    PORTB.PMR.BYTE |= 0x01U;

    /* Set MISOA pin */
    MPC.P22PFS.BYTE = 0x0DU;
    PORT2.ODR0.BYTE &= 0xEFU;
    PORT2.PMR.BYTE |= 0x04U;

    RSPI0.SPCR.BYTE = _01_RSPI_MODE_CLOCK_SYNCHRONOUS | _00_RSPI_FULL_DUPLEX_SYNCHRONOUS | _08_RSPI_MASTER_MODE;
    spcr_dummy = RSPI0.SPCR.BYTE;

    R_Config_RSPI0_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_RSPI0_Start
* Description  : This function starts the RSPI0 module operation
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_RSPI0_Start(void)
{
    volatile uint8_t dummy;

    /* Enable RSPI interrupts */
    IEN(RSPI0,SPTI0) = 1U;
    IEN(RSPI0,SPRI0) = 1U;
    ICU.GENAL0.BIT.EN17 = 1U;
    ICU.GENAL0.BIT.EN16 = 1U;

    /* Clear error sources */
    dummy = RSPI0.SPSR.BYTE;
    RSPI0.SPSR.BYTE = 0xA0U;

    /* Disable idle interrupt */
    RSPI0.SPCR2.BIT.SPIIE = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_RSPI0_Stop
* Description  : This function stops the RSPI0 module operation
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_RSPI0_Stop(void)
{
    /* Disable RSPI interrupts */
    IEN(RSPI0,SPTI0) = 0U;
    IEN(RSPI0,SPRI0) = 0U;
    ICU.GENAL0.BIT.EN17 = 0U;
    ICU.GENAL0.BIT.EN16 = 0U;

    /* Disable RSPI function */
    RSPI0.SPCR.BIT.SPE = 0U;
}

/***********************************************************************************************************************
* Function Name: R_Config_RSPI0_Send_Receive
* Description  : This function sends and receives RSPI0 data
* Arguments    : tx_buf -
*                    transfer buffer pointer (not used when data is handled by DMAC/DTC)
*                tx_num -
*                    buffer size
*                rx_buf -
*                    receive buffer pointer (not used when data is handled by DMAC/DTC)
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/

MD_STATUS R_Config_RSPI0_Send_Receive(uint16_t * const tx_buf, uint16_t tx_num, uint16_t * const rx_buf)
{
    MD_STATUS status = MD_OK;

    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        /* Initialize the global counters */
        gp_rspi0_tx_address = tx_buf;
        g_rspi0_tx_count = tx_num;
        gp_rspi0_rx_address = rx_buf;
        g_rspi0_rx_length = tx_num;
        g_rspi0_rx_count = 0U;

        /* Enable transmit interrupt */
        RSPI0.SPCR.BIT.SPTIE = 1U;

        /* Enable receive interrupt */
        RSPI0.SPCR.BIT.SPRIE = 1U;

        /* Enable error interrupt */
        RSPI0.SPCR.BIT.SPEIE = 1U;

        /* Enable RSPI function */
        RSPI0.SPCR.BIT.SPE = 1U;
    }

    return (status);
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
