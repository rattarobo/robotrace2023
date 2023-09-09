/*
 * L2_MOTOR.h
 *
 *  Created on: 2023/04/10
 *      Author: ratta
 */

#ifndef LAYER2_L2_MOTOR_H_
#define LAYER2_L2_MOTOR_H_

#define  MIN_VOL -6000
#define  MAX_VOL  6000
#define PWM_CYCLE 39999

void change_motor_voltage(long left_voltage, long right_voltage);
#endif /* LAYER2_L2_MOTOR_H_ */
