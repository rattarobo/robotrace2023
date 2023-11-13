/*
 * L1_IO.c
 *
 *  Created on: 2023/04/07
 *      Author: ratta
 */

/***************************************************************************************************************
 * 利用ファイルのヘッダ
 **************************************************************************************************************/
#include "r_smc_entry.h"
/***************************************************************************************************************
 * 自ファイルのヘッダ
 **************************************************************************************************************/
#include "L1_IO.h"
/***************************************************************************************************************
 * 変数
 **************************************************************************************************************/

/***************************************************************************************************************
 * 公開変数
 **************************************************************************************************************/
unsigned char led;
//87654321の順
/***************************************************************************************************************
 * 公開関数
 **************************************************************************************************************/

//LEDをつける
void led_on(unsigned char a){
	if((a&0x01)==0x01)LED1=ON;
	else LED1=OFF;
	if((a&0x02)==0x02)LED2=ON;
	else LED2=OFF;
	if((a&0x04)==0x04)LED3=ON;
	else LED3=OFF;
	if((a&0x08)==0x08)LED4=ON;
	else LED4=OFF;
	if((a&0x10)==0x10)LED5=ON;
	else LED5=OFF;
	if((a&0x20)==0x20)LED6=ON;
	else LED6=OFF;
	if((a&0x40)==0x40)LED7=ON;
	else LED7=OFF;
	if((a&0x80)==0x80)LED8=ON;
	else LED8=OFF;

}
//LEDを消す
void led_off(unsigned char a){
	if(a&0x01==0x01)
	LED1=OFF;
	if(a&0x02==0x02)
	LED2=OFF;
	if(a&0x04==0x04)
	LED3=OFF;
	if(a&0x08==0x08)
	LED4=OFF;
	if(a&0x10==0x10)
	LED5=OFF;
	if(a&0x20==0x20)
	LED6=OFF;
	if(a&0x40==0x40)
	LED7=OFF;
	if(a&0x80==0x80)
	LED8=OFF;

}
/***************************************************************************************************************
 * 非公開関数
 **************************************************************************************************************/



