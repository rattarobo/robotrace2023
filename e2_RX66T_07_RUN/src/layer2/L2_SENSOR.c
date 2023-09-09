/*
 * L2_sensor.c
 *
 *  Created on: 2023/04/09
 *      Author: ratta
 */
#include "L1_AD.h"
#include "L1_GPTW.h"
#include "L2_SENSOR.h"
#include "L2_ERROR.h"
 float battery_ave=0.0;

void check_battery(_error *error) {
	//バッテリ電圧の平均値を取得

	battery_ave = (short) (sum_battery /  BATTERY_COUNT);
	if(battery_ave< BATTERY_MIN){
		error->battery=1;
	}
	else{
		error->battery=0;
	}
	sum_battery = 0;

}

_rotate distance[2];
_rotational_speed speed[2];

void distance_velocity(_rotate *distance,_rotational_speed *speed){
	distance[1].r =  21*1e-3* r_enc*(2*3.1415/50)*12 / 42 ; //rθ*（ギア比）で計算
	distance[1].l =  21*1e-3* l_enc* (2*3.1415/50)*12 / 42 ; //円周率はL2_MYMASSに変更よてい
	speed[1].r = ((distance[1].r - distance[0].r) * 1000 );
	speed[1].l = ((distance[1].l - distance[0].l) * 1000 );

	distance[0].r = distance[1].r;
	distance[0].l = distance[1].l;
	speed[0].r = speed[1].r;
	speed[0].l = speed[1].l;
}

