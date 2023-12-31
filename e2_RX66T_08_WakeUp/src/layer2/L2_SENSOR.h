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

#define RP 0.8
#define RI 0.1
#define RD 0

#define LP 0.8
#define LI 0.1
#define LD 0

#define  DT  0.001
#define  DT2 0.05
/***********************************************************************************************************
 * 構造体宣言
 **********************************************************************************************************/
 typedef struct {//0:左　1:右
	 double distance[2];
	 float velocity[2];
 } _wheel;
/***********************************************************************************************************
 * extern 関数宣言
 **********************************************************************************************************/
extern float battery_ave;
extern void check_battery(_error *error);
extern _wheel check_dist_velo(_wheel previous);



#endif /* LAYER2_L2_SENSOR_H_ */
