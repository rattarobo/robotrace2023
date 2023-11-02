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

#define RP 8 //1.14
#define RI 0 //0
#define RD 3 //(0.203*5)

#define LP 8.5 //1.14
#define LI 0 //0
#define LD 3.5 //(0.203*5)

#define  DT  0.005
#define  DT2 0.05
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
/***********************************************************************************************************
 * extern 変数宣言
 **********************************************************************************************************/
extern float battery_ave;
extern _sensor min,max;

#endif /* LAYER2_L2_SENSOR_H_ */
