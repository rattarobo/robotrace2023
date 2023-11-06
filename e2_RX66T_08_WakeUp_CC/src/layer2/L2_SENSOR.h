/*
 * L2_SENSOR.h
 *
 *  Created on: 2023/04/09
 *      Author: ratta
 */

#ifndef LAYER2_L2_SENSOR_H_
#define LAYER2_L2_SENSOR_H_

#include "L2_ERROR.h"
/***********************************************************************************************************
 * define　宣言
 **********************************************************************************************************/
#define BATTERY_MIN 7.0
#define BATTERY_MAX	8.4
#define BATTERY_COUNT 50



#define  DT  0.005
#define  DT2 0.05
/*
*角度用のゲイン右ー＞左
*/
#define A0 (-0.365308975*0)
#define A1 (-0.279091932*0)
#define A2 (-0.188405306)
#define A3 (-0.095140467)
#define A4 (-0.005)
#define A5 (0.005)
#define A6 (0.095046088)
#define A7 (0.189048508)
#define A8 (0.279091932)
#define A9 (0.364976597*0)

/***********************************************************************************************************
 * 構造体宣言
 **********************************************************************************************************/
 typedef struct {//0:左　1:右
	 double distance[2];
	 float velocity[2];
 } _wheel;

 typedef struct {
 	float main[10];
 	float goal;
 	float coner;

 } _sensor;
/***********************************************************************************************************
 * extern 関数宣言
 **********************************************************************************************************/
extern float battery_ave;
extern void check_battery(_error *error);
extern _wheel check_dist_velo(_wheel previous);
extern void set_callibration(_sensorRaw *raw);
extern _sensor sensor_callibration(_sensorRaw *raw);
extern float get_sensor_angle(_sensor *get);
extern void reset_value(_wheel previous);
/***********************************************************************************************************
 * extern 変数宣言
 **********************************************************************************************************/
extern float battery_ave;
extern _sensor min,max;

#endif /* LAYER2_L2_SENSOR_H_ */
