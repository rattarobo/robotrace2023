/*
 * L3_CONTROL.h
 *
 *  Created on: 2023/04/16
 *      Author: ratta
 */

#ifndef LAYER3_L3_CONTROL_H_
#define LAYER3_L3_CONTROL_H_

#define Tr_p 5e1
#define Tr_s 1e-3
#define Tr_i 0
#define Tr_d 0

#define Tl_p 5e1
#define Tl_s 1e-3
#define Tl_i 0
#define Tl_d 0

#define T_p (5e-2)
#define T_s 1e-3
#define T_i 0
#define T_d 0

extern volatile _rotational_speed u;
extern volatile _rotational_speed target;
extern volatile float u_sen;
_rotational_speed moter_pid(_rotational_speed target,_rotational_speed speed[2]);
_rotational_speed sensor_pid(float target,float rad[2],float translation);
#endif /* LAYER3_L3_CONTROL_H_ */
