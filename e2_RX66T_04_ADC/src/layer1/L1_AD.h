/*
 * L1_AD.h
 *
 *  Created on: 2023/04/09
 *      Author: ratta
 */

#ifndef LAYER1_L1_AD_H_
#define LAYER1_L1_AD_H_

typedef struct {
	short main[10];
	short goal;
	short coner;

} _sensor;


extern long sum_battery;
extern _sensor raw;
void get_bat_vol(void);
void get_sensor(_sensor *raw);

#endif /* LAYER1_L1_AD_H_ */
