/*
 * L1_AD.h
 *
 *  Created on: 2023/04/09
 *      Author: ratta
 */

#ifndef LAYER1_L1_AD_H_
#define LAYER1_L1_AD_H_

typedef struct {
	int main[10];
	int goal;
	int coner;

} _sensorRaw;


extern long sum_battery;
extern _sensorRaw raw;
void get_bat_vol(void);
void get_sensor(_sensorRaw *raw);

#endif /* LAYER1_L1_AD_H_ */
