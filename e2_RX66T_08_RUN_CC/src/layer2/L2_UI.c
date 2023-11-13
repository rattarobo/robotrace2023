/*
 * L2_UI.c
 *
 *  Created on: 2023/11/10
 *      Author: ratta
 */

/***************************************************************************************************************
 * 利用ファイルのヘッダ
 **************************************************************************************************************/
#include "L1_IO.h"
/***************************************************************************************************************
 * 自ファイルのヘッダ
 **************************************************************************************************************/
#include "L2_UI.h"
/***************************************************************************************************************
 * 変数
 **************************************************************************************************************/

/***************************************************************************************************************
 * 公開変数
 **************************************************************************************************************/

/***************************************************************************************************************
 * 公開関数
 **************************************************************************************************************/
void ui_num(char num){
	ui_off();
	led_on((unsigned char)num);
}
void ui_off(void){
	led_off(255);
}
/***************************************************************************************************************
 * 非公開関数
 **************************************************************************************************************/






