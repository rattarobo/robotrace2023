/*
 * L2_sensor.c
 *
 *  Created on: 2023/04/09
 *      Author: ratta
 */
#include "L1_AD.h"
#include "L2_SENSOR.h"
#include "L2_ERROR.h"
 float battery_ave=0.0;

void check_battery(_error *error) {
	//バッテリ電圧の平均値を取得

	battery_ave = (float) (sum_battery /  BATTERY_COUNT);
	if(battery_ave< BATTERY_MIN){
		error->battery=1;
	}
	else{
		error->battery=0;
	}
	sum_battery = 0;

}

