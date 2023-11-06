/*
 * L2_MOTOR.c
 *
 *  Created on: 2023/04/10
 *      Author: ratta
 */

/***************************************************************************************************************
 * 利用ファイルのヘッダ

 **************************************************************************************************************/
#include "r_smc_entry.h"
#include "L1_IO.h"
#include "L1_GPTW.h"
#include "L1_AD.h"
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
double r_ei=0,l_ei=0;
double lve_ref,rve_ref;


/***************************************************************************************************************
 * 公開関数
 **************************************************************************************************************/
void change_motor_velocity(_wheel command_value,_wheel recent_value){
	double r_gein,l_gein;


	double r_ve=command_value.distance[1]-recent_value.distance[1];
	double l_ve=command_value.distance[0]-recent_value.distance[0];
	//PIDゲインの導出
	r_gein = (double)(RP * (r_ve) + RI* r_ei+RD/(1+N*DT)*(r_ve-rve_ref) );
	l_gein = (double)(LP * (l_ve) + LI* l_ei+LD/(1+N*DT)*(l_ve-lve_ref) );

	//スピードが0なら止まる　そうでないなら動かす
<<<<<<< HEAD
	if ((l_ve<10 && l_ve>-10)||command_value.velocity[0]==0){
=======
	if (command_value.velocity[0]==0){
>>>>>>> branch 'master' of git@github.com:rattarobo/robotrace2023.git
		l_gein=0;
	}
<<<<<<< HEAD
	if ((r_ve<10 && r_ve>-10)||command_value.velocity[1]==0){
=======
	if (command_value.velocity[1]==0){
>>>>>>> branch 'master' of git@github.com:rattarobo/robotrace2023.git
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

void change_motor_voltage(double left_voltage, double right_voltage){
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

	left_PWM= (unsigned long)(PWM_CYCLE-PWM_CYCLE*left_voltage/battery_ave);
	right_PWM=(unsigned long)(PWM_CYCLE-PWM_CYCLE*left_voltage/battery_ave);

	GPTW_PWM(left_PWM, right_PWM);
}

