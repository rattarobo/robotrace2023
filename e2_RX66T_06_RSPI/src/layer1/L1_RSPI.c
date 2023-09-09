/*
 * L1_RSPI.c
 *
 *  Created on: 2023/04/10
 *      Author: ratta
 */
#include "r_smc_entry.h"
#include "L1_RSPI.h"
#include "L1_IO.h"

void RSPI_init(void){
	volatile unsigned char	d;
	//周辺機能の設定
	MPC.PWPR.BIT.B0WI = 0;			// PFSWE�r�b�g�ւ̏������݂�����
	MPC.PWPR.BIT.PFSWE = 1;
	MPC.P22PFS.BIT.PSEL=0x0d;
	MPC.PB0PFS.BIT.PSEL=0x0d;
	MPC.PB3PFS.BIT.PSEL=0x0d;
	MPC.PWPR.BIT.PFSWE = 0;
	MPC.PWPR.BIT.B0WI = 1;			// PFSWE�r�b�g�ւ̏������݂�����
	PORT2.PMR.BIT.B2=1;
	PORTB.PMR.BIT.B0=1;
	PORTB.PMR.BIT.B3=1;
	PORTB.PODR.BIT.B1=0;


	// RSPIc
	RSPI0.SPCR.BYTE = 0x1B;			// RSPI�@�\����
	RSPI0.SSLP.BYTE = 0x00;			// SSL0~3�M���̓A�N�e�B�uLOW
	RSPI0.SPPCR.BYTE = 0x30;		// MOSI�A�C�h������MOSIA�o�͒l��High, �ʏ탂�[�h
	RSPI0.SPBR = 0x05;			// 10Mbps(PCLKA:80MHz)  FRAM(FM25H20)�̏ꍇ��MAX 40Mbps
//	RSPI0.SPBR = 0x05;

//	RSPI0.SPBR = 0x00;			// 40Mbps
	RSPI0.SPDCR.BYTE = 0x00;		// SPDR�̓o�C�g�A�N�Z�X�ASPDR�͎�M�o�b�t�@��ǂݏo���A�t���[������1
//	RSPI0.SPCKD.BYTE = 0x00;		// RSPI�N���b�N�x��   = 1RSPCK(default)
//	RSPI0.SSLND.BYTE = 0x00;		// SSL�l�Q�[�g�x��    = 1RSPCK(default)
//	RSPI0.SPND.BYTE = 0x00;			// RSPI���A�N�Z�X�x�� = 1RPSCK+2PCLK(default)
	RSPI0.SPCR2.BYTE = 0x00;		// non parity, �A�C�h�������֎~, �p���e�B���Ȑf�f����,
	RSPI0.SPSCR.BYTE = 0x00;		// �V�[�P���X�� = 1
	RSPI0.SPCMD0.WORD = 0x0f0f;		// MSB first, 8bit(0100) BDRV=00, CPOL=1(�A�C�h������RSPCK=High) & CPHA=1(�����G�b�W�Ńf�[�^�T���v��) = SPI Mode 3
	RSPI0.SPCMD0.BIT.BRDV=3;	//833 kbps
	RSPI0.SPDCR2.BYTE = 0x00;		// ����M�f�[�^���o�C�g�P�ʂŃX���b�v���Ȃ�
	while(RSPI0.SPSR.BIT.SPRF) {		// �O�̂��߁A��M�o�b�t�@���N���A
		d = RSPI0.SPDR.WORD.H;
	}
	RSPI0.SPSR.BYTE &= 0xA0;		// �O�̂��ߊe��t���O���N���A
	RSPI0.SPCR.BYTE = 0x3B;		//

}

unsigned short spi_exchange(unsigned short data){
	unsigned long receive=0x0001 ;
	volatile uint8_t dummy;
	//上位ビット相手アド，下位ビットが書き込む内容//読み出しのみ上位bitの先頭ビットは１
//	R_Config_RSPI0_Start();
//	PORTB.PODR.BIT.B1=0;
	 dummy = RSPI0.SPSR.BYTE;
	RSPI0.SPSR.BYTE = 0xA0U;
	RSPI0.SPCR2.BIT.SPIIE=0;

	RSPI0.SPCR.BIT.SPE = 1;			//RSPI機能有効
	/* Enable RSPI interrupts */
	    IEN(RSPI0,SPTI0) = 1U;
	    IEN(RSPI0,SPRI0) = 1U;
	    ICU.GENAL0.BIT.EN17 = 1U;
	    ICU.GENAL0.BIT.EN16 = 1U;

	IR(RSPI0,SPRI0) = 0;

	do{
		led.led1=ON;
	}while (IR(RSPI0,SPTI0)==0 && RSPI0.SPSR.BIT.SPTEF==0);

	do{
		RSPI0.SPDR.WORD.H = data;
		led.led2=ON;
		}while (IR(RSPI0,SPTI0)!=1 && RSPI0.SPSR.BIT.SPTEF!=1);
	dummy = RSPI0.SPSR.BIT.IDLNF;
	RSPI0.SPCR.BIT.SPTIE=0;
	RSPI0.SPCR2.BIT.SPIIE=1;

	do{
		led.led3=ON;
	}while (RSPI0.SPSR.BIT.IDLNF==1 );
//	RSPI0.SPCR.BIT.SPE=0;
//	RSPI0.SPCR2.BIT.SPIIE=0;
RSPI0.SPSR.BYTE = 0xA0U;
RSPI0.SPCR2.BIT.SPIIE=0;

RSPI0.SPCR.BIT.SPE = 1;			//RSPI機能有効
/* Enable RSPI interrupts */
    IEN(RSPI0,SPTI0) = 1U;
    IEN(RSPI0,SPRI0) = 1U;
    ICU.GENAL0.BIT.EN17 = 1U;
    ICU.GENAL0.BIT.EN16 = 1U;
	RSPI0.SPCR.BIT.SPE=1;
	while (IR(RSPI0,SPRI0)!=1 && RSPI0.SPSR.BIT.SPRF!=1)//受信バッファフル割り込み発生せず＆受信バッファに有効なデータなし
		{
		led.led4=ON;
//		receive = RSPI0.SPDR.BYTE.HH;

		}

	receive = RSPI0.SPDR.WORD.H;



	RSPI0.SPCR.BIT.SPRIE=0;



	RSPI0.SPCR.BIT.SPE = 0;			//RSPI機能無効

	return (short)(receive&0xFFFF);
//	unsigned short receive =0xf500;
//	R_Config_RSPI0_Start();
//
//	R_BSP_SoftwareDelay(10,BSP_DELAY_MILLISECS);
//	R_Config_RSPI0_Send_Receive((uint16_t *)data, 1U, (uint16_t *)receive);
//	R_BSP_SoftwareDelay(10,BSP_DELAY_MILLISECS);
//	R_Config_RSPI0_Send_Receive((uint16_t *)data, 1U, (uint16_t *)receive);
//
//
//
//
//	return (short)(receive&0xFFFF);
}
