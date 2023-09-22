/*
 * L2_MOTOR.c
 *
 *  Created on: 2023/04/10
 *      Author: ratta
 */

/***************************************************************************************************************
 * 利用ファイルのヘッダ
 **************************************************************************************************************/
#include "L1_IO.h"
#include "L1_GPTW.h"
#include "L2_SENSOR.h"

/***************************************************************************************************************
 * 自ファイルのヘッダ
 **************************************************************************************************************/
#include "L2_MOTOR.h"
/***************************************************************************************************************
 * 変数
 **************************************************************************************************************/


/***************************************************************************************************************
 * 公開変数
 **************************************************************************************************************/

/***************************************************************************************************************
 * 公開関数
 **************************************************************************************************************/
void change_motor_velocity(float left_velocity, float right_velocity){

	change_motor_voltage();
}

/***************************************************************************************************************
 * 非公開関数
 **************************************************************************************************************/

void change_motor_voltage(long left_voltage, long right_voltage){
long left_PWM,right_PWM;
	if(left_voltage > 0){		//正転
		MOTOR_LIN1 = 0;
		MOTOR_LIN2 = 1;

	}
	else if(left_voltage < 0){	//逆転
		MOTOR_LIN1 = 1;
		MOTOR_LIN2 = 0;
		left_voltage = -left_voltage;
	}
	else {						//静止
		MOTOR_LIN1 = 0;
		MOTOR_LIN2 = 0;
	}
	if(right_voltage > 0){		//正転
		MOTOR_RIN1 = 0;
		MOTOR_RIN2 = 1;
	}
	else if(right_voltage < 0){//逆転
		MOTOR_RIN1 = 1;
		MOTOR_RIN2 = 0;
		right_voltage = -right_voltage;
	}
	else {						//静止
		MOTOR_RIN1 = 0;
		MOTOR_RIN2 = 0;
	}
	if(left_voltage < MIN_VOL )		left_voltage = MIN_VOL;
	if(left_voltage > MAX_VOL)		left_voltage = MAX_VOL;
	if(right_voltage < MIN_VOL)		right_voltage = MIN_VOL;
	if(right_voltage > MAX_VOL)		right_voltage = MAX_VOL;

	left_PWM=(long)(PWM_CYCLE -PWM_CYCLE *left_voltage/battery_ave);
	right_PWM=(long)(PWM_CYCLE -PWM_CYCLE *right_voltage/battery_ave);

	GPTW_PWM(left_PWM, right_PWM);
}

