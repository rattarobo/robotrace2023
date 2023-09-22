/*
 * L3_WAKEUP.c
 *
 *  Created on: 2023/09/22
 *      Author: ratta
 */

#include "L1_IO.h"
#include "L1_AD.h"
#include "L1_MTU.h"
#include "L1_GPTW.h"

#include "L2_SENSOR.h"
#include "L2_ERROR.h"
#include "L2_MOTOR.h"
#include "L2_INIT.h"

void wake_up(void){
	/*
	 * 初期設定
	 * */
	//セットアップ
	init();
	/*エラーの初期化*/
	error_init(&error);
	/*エラーの監視*/
	error_message(&error);
	/*
		 * sensorキャリブレーション
		 * */

}
