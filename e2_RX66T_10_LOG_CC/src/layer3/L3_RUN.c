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
float translation=0;
char goal_count=0;
char coner_count=0;

/***************************************************************************************************************
 * 公開変数
 **************************************************************************************************************/



/***************************************************************************************************************
 * 公開関数
 **************************************************************************************************************/
_wheel stop(void);

void RUN(void){
	static char print_str[80];
	_sensor get;
	float angle;
	while(1){

		get=sensor_callibration(&raw);
		if(get.main[2]<0.5 && get.main[3]<0.5  &&get.main[4]<0.5  &&get.main[5]<0.5  &&get.main[6]<0.5  &&get.main[7]<0.5 ){
			stop();
		}
		angle=get_sensor_angle(&get);
		mycommand_value =run_pid(0.,angle);
		previous_value=check_dist_velo(previous_value);
		change_motor_velocity(mycommand_value,previous_value);
//ゴール分岐
		if(get.goal >0.5){
			for (int i=1;i<100;i++){
				//走行
				get=sensor_callibration(&raw);
				if(get.main[2]<0.5 && get.main[3]<0.5  &&get.main[4]<0.5  &&get.main[5]<0.5  &&get.main[6]<0.5  &&get.main[7]<0.5 ){
					stop();
				}
				angle=get_sensor_angle(&get);
				mycommand_value =run_pid(0.,angle);
				previous_value=check_dist_velo(previous_value);
				change_motor_velocity(mycommand_value,previous_value);
				//flag管理
				R_BSP_SoftwareDelay(10,BSP_DELAY_MILLISECS );
				if(get.coner >0.5){
					goal_count --;
					break;
				}

			}
			goal_count ++;

		}
//コ－ナー分岐
		if(get.coner >0.5){
			for (int i=1;i<100;i++){
				//走行
				get=sensor_callibration(&raw);
				if(get.main[2]<0.5 && get.main[3]<0.5  &&get.main[4]<0.5  &&get.main[5]<0.5  &&get.main[6]<0.5  &&get.main[7]<0.5 ){
					stop();
				}
				angle=get_sensor_angle(&get);
				mycommand_value =run_pid(0.,angle);
				previous_value=check_dist_velo(previous_value);
				change_motor_velocity(mycommand_value,previous_value);
				R_BSP_SoftwareDelay(10,BSP_DELAY_MILLISECS );

			}
			coner_count++;
		}
		if (goal_count >1){
			for (int i=1;i<300;i++){
				//走行
				get=sensor_callibration(&raw);
				angle=get_sensor_angle(&get);
				mycommand_value =run_pid(0.,angle);
				previous_value=check_dist_velo(previous_value);
				change_motor_velocity(mycommand_value,previous_value);
				R_BSP_SoftwareDelay(10,BSP_DELAY_MILLISECS );

			}
			mycommand_value =stop();
			previous_value=check_dist_velo(previous_value);
			change_motor_velocity(mycommand_value,previous_value);
			break;
		}
		sprintf(print_str, "\r%d!%d\r\n",goal_count,coner_count);
		R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
	}
}

/***************************************************************************************************************
 * 非公開関数
 **************************************************************************************************************/

_wheel run_pid(float command_value,float recent_value){
	_wheel command;
	float a_ve=command_value-recent_value;
	translation+=T;
	//PIDゲインの導出
	command.distance[1] =(float)(RRP * (a_ve) + RRI * a_ei+RRD*(a_ve-ave_ref) )+translation;
	command.distance[0] =(float)(RLP * (a_ve) + RLI * a_ei+RLD*(a_ve-ave_ref) )+translation;
	//スピードが0なら止まる　そうでないなら動かす
	a_ei=a_ei+a_ve;
	ave_ref=a_ve;
	return command;
}
_wheel stop(void){
	_wheel command;

	command.distance[1] =0;
	command.distance[0] =0;
	command.velocity[1] =0;
	command.velocity[0] =0;
	return command;
}
