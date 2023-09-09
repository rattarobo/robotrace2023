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
extern float r_speed , l_speed ;
extern float r_speed_b , l_speed_b ;

extern float battery_ave;
void check_battery(_error *error);
void distance_velocity(void);
short Gyro_init(void);
#endif /* LAYER2_L2_SENSOR_H_ */
