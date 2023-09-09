/*
 * L2_SENSOR.h
 *
 *  Created on: 2023/04/09
 *      Author: ratta
 */

#ifndef LAYER2_L2_SENSOR_H_
#define LAYER2_L2_SENSOR_H_
#include "L1_AD.h"
#include "L2_ERROR.h"
#define BATTERY_MIN 7.0
#define BATTERY_MAX	8.4
#define BATTERY_COUNT 50

//#define BETA0(i) beta0_ ## i
//#define BETA1(i) beta1_ ## i
//
//#define BETA0_i 0
//#define BETA1_i 0
//#define BETA0_0 0
//#define BETA0_1 0
//#define BETA0_2 0
//#define BETA0_3 0
//#define BETA0_4 -12.7451
//#define BETA0_5 -9.8588
//#define BETA0_6 -18.4861
//#define BETA0_7 -70.4925
//#define BETA0_8 -18.6335
//#define BETA0_9 -9.6293
//#define BETA1_0 0
//#define BETA1_1 0
//#define BETA1_2 0
//#define BETA1_3 0
//#define BETA1_4 0.1062
//#define BETA1_5 0.0334
//#define BETA1_6 0.4453
//#define BETA1_7 0.7008
//#define BETA1_8 0.589
//#define BETA1_9 0.04


typedef struct { //距離の構造体
double r;
double l;
} _rotate;
typedef struct { //速度の構造体
float r;
float l;
} _rotational_speed;

extern _rotate distance[2];
extern _rotational_speed speed[2];
extern _sensor max;
extern _sensor min;
extern _sensor baffa;
extern float battery_ave;
extern  float rad[2];
void check_battery(_error *error);
void distance_velocity(_rotate *distance,_rotational_speed *speed);
void set_chlibration(_sensor *max, _sensor *min, _sensor *raw );
void chalibration(_sensor *max, _sensor *min,_sensor *raw,_sensor *baffa);
void rogistic_chalibration(_sensor *raw,_sensor *Calibration_value);
void radian(_sensor *raw,float rad[2]);
#endif /* LAYER2_L2_SENSOR_H_ */
