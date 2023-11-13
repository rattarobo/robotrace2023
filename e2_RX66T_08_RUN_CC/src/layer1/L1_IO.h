/*
 * L1_IO.h
 *
 *  Created on: 2023/04/07
 *      Author: ratta
 */

#ifndef LAYER1_L1_IO_H_
#define LAYER1_L1_IO_H_

#include "r_smc_entry.h"
#include "stdbool.h"

/***********************************************************************************************************
 * define　宣言
 **********************************************************************************************************/
//LEDのポートの設定
#define   ON 1
#define   OFF 0

#define	  LED1 PORT7.PODR.BIT.B1
#define	  LED2 PORT7.PODR.BIT.B2
#define	  LED3 PORT7.PODR.BIT.B3
#define	  LED4 PORT7.PODR.BIT.B4
#define	  LED5 PORT7.PODR.BIT.B5
#define	  LED6 PORT7.PODR.BIT.B6
#define	  LED7 PORTB.PODR.BIT.B4
#define	  LED8 PORTD.PODR.BIT.B4
//センサーLEDの設定
#define	 SENLED1 PORT1.PODR.BIT.B1
#define	 SENLED2 PORT0.PODR.BIT.B1


#define  SW PORTE.PIDR.BIT.B2
//モーターの回転方向の設定
#define MOTOR_LIN1 PORT9.PODR.BIT.B4
#define	MOTOR_LIN2 PORT9.PODR.BIT.B3
#define	MOTOR_RIN1 PORT9.PODR.BIT.B0
#define	MOTOR_RIN2 PORT9.PODR.BIT.B1

/***********************************************************************************************************
 * 構造体宣言
 **********************************************************************************************************/

/***********************************************************************************************************
 * extern 関数宣言
 **********************************************************************************************************/
void led_on(unsigned char a);
void led_off(unsigned char a);
/***********************************************************************************************************
 * extern 変数宣言
 **********************************************************************************************************/
extern unsigned char led;


#endif /* LAYER1_L1_IO_H_ */
