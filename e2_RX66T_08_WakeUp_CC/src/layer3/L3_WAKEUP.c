/*
 * L3_WAKEUP.c
 *
 *  Created on: 2023/09/22
 *      Author: ratta
 */
#include "r_smc_entry.h"
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
	_wheel command_value={0.,0.,1.3,1.3};
	_wheel previous_value={0.,0.,0.,0.};
	/* String used to print message at PC terminal */
	static char print_str[80];
	sprintf(print_str, "\r\n Press keyboard to control LED\r\n");
	R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
/********************
 * 機体の移動
 ********************/
	for(int i=0;i<50;i++){
	 previous_value=check_dist_velo(previous_value);
	change_motor_velocity(command_value,previous_value);
	sprintf(print_str, "\r\n%f\t%f\r\n",previous_value.velocity[0],previous_value.velocity[1]);
	R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
	R_BSP_SoftwareDelay(10,BSP_DELAY_MILLISECS );
	}

	command_value.distance[0]=0;
	command_value.distance[1]=0;
	command_value.velocity[0]=0;
	command_value.velocity[1]=0;
	for(int i=0;i<100;i++){
	 previous_value=check_dist_velo(previous_value);

	change_motor_velocity(command_value,previous_value);
	R_BSP_SoftwareDelay(5,BSP_DELAY_MILLISECS );
	}
	/********************
	 * センサー値の取得
	 ********************/
	R_BSP_SoftwareDelay(5,BSP_DELAY_SECS );
	command_value.distance[0]=0;
	command_value.distance[1]=0;
	command_value.velocity[0]=-1.5;
	command_value.velocity[1]=-1.5;
	for(int i=0;i<100;i++){
	 previous_value=check_dist_velo(previous_value);

	change_motor_velocity(command_value,previous_value);
	R_BSP_SoftwareDelay(5,BSP_DELAY_MILLISECS );
	}
}
