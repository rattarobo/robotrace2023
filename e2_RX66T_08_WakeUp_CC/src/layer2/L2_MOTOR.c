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
float r_ei=0,l_ei=0;
float lve_ref,rve_ref;


/***************************************************************************************************************
 * 公開関数
 **************************************************************************************************************/
void change_motor_velocity(_wheel command_value,_wheel recent_value){
	long r_gein,l_gein;


	float r_ve=command_value.velocity[1]-recent_value.velocity[1];
	float l_ve=command_value.velocity[0]-recent_value.velocity[0];
	//PIDゲインの導出
	r_gein = (long)(RP * (command_value.velocity[1]-recent_value.velocity[1]) + RI * r_ei+RD*(r_ve-rve_ref) );
	l_gein = (long)(LP * (command_value.velocity[0]-recent_value.velocity[0]) + LI * l_ei+LD*(l_ve-lve_ref) );
	//スピードが0なら止まる　そうでないなら動かす
	if (command_value.velocity[1]==0.){
		l_gein=0;
	}
	if (command_value.velocity[0]==0.){
		r_gein=0;
	}
	change_motor_voltage(l_gein,r_gein);
	if ((r_gein < MAX_VOL) && (r_gein > MIN_VOL)) {
		r_ei += DT * (r_ve + rve_ref) / 2;
	}
	if ((l_gein < MAX_VOL) && (l_gein > MIN_VOL)) {
		l_ei += DT * (l_ve + lve_ref) / 2;
	}
	lve_ref=l_ve;
	rve_ref=r_ve;
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

