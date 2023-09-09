/*
 * L1_MTU.c
 *
 *  Created on: 2023/04/10
 *      Author: ratta
 */
#include "r_smc_entry.h"
#include "L1_MTU.h"
void buzzer_start(int hz) {//hz>100
	if (MTU.TSTRA.BIT.CST0 == 1U){
		R_Config_MTU0_Stop();
	}
	if (hz <= 0)
		R_Config_MTU0_Stop(); //カウント動作停止
	else {
		//T=カウントクロック/Hz
		MTU0.TGRA = (unsigned short) BUZZER_MAX / hz; //TGRBはTGRAの半分
		MTU0.TGRB = (unsigned short) MTU0.TGRA / 2;  //カウンタ設定

		R_Config_MTU0_Start();  //カウント動作開始
	}
}
void buzzer_stop(void){
	R_Config_MTU0_Stop();
}

