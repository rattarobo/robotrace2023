/*
 * L2_SENSOR.h
 *
 *  Created on: 2023/04/09
 *      Author: ratta
 */

#ifndef LAYER2_L2_SENSOR_H_
#define LAYER2_L2_SENSOR_H_
#include "L2_ERROR.h"
#define BATTERY_MIN 7.0
#define BATTERY_MAX	8.4
#define BATTERY_COUNT 50

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


extern float battery_ave;
void check_battery(_error *error);
void distance_velocity(_rotate *distance,_rotational_speed *speed);
#endif /* LAYER2_L2_SENSOR_H_ */
