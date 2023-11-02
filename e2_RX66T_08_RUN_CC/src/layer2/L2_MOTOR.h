/*
 * L2_MOTOR.h
 *
 *  Created on: 2023/04/10
 *      Author: ratta
 */

#ifndef LAYER2_L2_MOTOR_H_
#define LAYER2_L2_MOTOR_H_
/***********************************************************************************************************
 * define　宣言
 **********************************************************************************************************/
#define  MIN_VOL -6000
#define  MAX_VOL  6000
#define PWM_CYCLE 29999

#define RP 0.005 //1.14
#define RI 0.03 //5.3632525947175e-05  //236.219684578833 //19.8620296172809 //0
#define RD 8.95590881517867e-05 //-5.62971357893227e-05  //0.00851477932055838 //(0.203*5)

#define LP 0.005 //1.14
#define LI 0.03  //5.3632525947175e-05 //236.219684578833 //19.8620296172809 //0
#define LD 8.95590881517867e-05 //-5.62971357893227e-05  //0.00851477932055838 //(0.203*5)
#define N 79.5606556954004

/***********************************************************************************************************
 * 構造体宣言
 **********************************************************************************************************/
//sensor.hにあり
//typedef struct {//0:左　1:右
//	 double distance[2];
//	 float velocity[2];
// } _wheel;
/***********************************************************************************************************
 * extern 関数宣言
 **********************************************************************************************************/
void change_motor_voltage(long left_voltage, long right_voltage);
void change_motor_velocity(_wheel command_value,_wheel recent_value);

#endif /* LAYER2_L2_MOTOR_H_ */
