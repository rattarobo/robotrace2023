/*
 * L3_RUN.c
 *
 *  Created on: 2023/11/02
 *      Author: ratta
 */

/***************************************************************************************************************
 * 利用ファイルのヘッダ
 **************************************************************************************************************/
#include "r_smc_entry.h"
#include "L1_IO.h"
#include "L1_AD.h"
#include "L1_MTU.h"
#include "L1_GPTW.h"

#include "L2_SENSOR.h"
#include "L2_ERROR.h"
#include "L2_MOTOR.h"
#include "L2_INIT.h"

/***************************************************************************************************************
 * 自ファイルのヘッダ
 **************************************************************************************************************/
#include "L3_RUN.h"
/***************************************************************************************************************
 * 変数
 **************************************************************************************************************/
float a_ei=0.;
float ave_ref=0.;
char goal_count=0;

/***************************************************************************************************************
 * 公開変数
 **************************************************************************************************************/



/***************************************************************************************************************
 * 公開関数
 **************************************************************************************************************/

void RUN(void){
	static char print_str[80];
	_sensor get;
	float angle;
	while(1){
		get=sensor_callibration(&raw);
		angle=get_sensor_angle(&get);
		mycommand_value =run_pid(0.,angle);

		previous_value=check_dist_velo(previous_value);
		change_motor_velocity(mycommand_value,previous_value);
//		sprintf(print_str, "\r%f\r\n",angle);
//		R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
		if(goal_count >1){
			break;
		}
		}
}

/***************************************************************************************************************
 * 非公開関数
 **************************************************************************************************************/

_wheel run_pid(float command_value,float recent_value){
	_wheel command;
	float a_ve=command_value-recent_value;

		//PIDゲインの導出
		command.distance[1] =(float)(RRP * (a_ve) + RRI * a_ei+RRD*(a_ve-ave_ref) )+Translation;
		command.distance[0] =(float)(RLP * (a_ve) + RLI * a_ei+RLD*(a_ve-ave_ref) )+Translation;
		//スピードが0なら止まる　そうでないなら動かす
		a_ei=a_ei+a_ve;
		ave_ref=a_ve;
	return command;
}
void stop(_sensor *get){
	if(get->goal>0.5){

		goal_count ++;
	}
}
