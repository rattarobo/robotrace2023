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

	battery_ave =  ((float)sum_battery /  BATTERY_COUNT);
	if(battery_ave< BATTERY_MIN){
		error->battery=1;
	}
	else{
		error->battery=0;
	}
	sum_battery = 0;

}

_rotate distance[2]; //[0]前[1]現在
_rotational_speed speed[2];

void distance_velocity(_rotate *distance,_rotational_speed *speed){
	distance[1].r =  21*1e-3* (double)r_enc*(2*3.1415/50)*12 / 42 ; //rθ*（ギア比）で計算
	distance[1].l =  21*1e-3* (double)l_enc*(2*3.1415/50)*12 / 42 ; //円周率はL2_MYMASSに変更よてい
	speed[1].r = (float)((distance[1].r - distance[0].r)  );
	speed[1].l = (float)((distance[1].l - distance[0].l)  );
	if(speed[1].r>10 ||speed[1].r<-10 ){//速度がおかしくなったら前の値を参照する。
		speed[1].r = speed[0].r;
	}
	if(speed[1].l>10||speed[1].l<-10){
		speed[1].l = speed[0].l;
	}
	distance[0].r = distance[1].r;
	distance[0].l = distance[1].l;
	speed[0].r = speed[1].r;
	speed[0].l = speed[1].l;
}
_sensor max={0,0,0,0,0,0,0,0,0,0,0,0};
_sensor min={1e4,1e4,1e4,1e4,1e4,1e4,1e4,1e4,1e4,1e4,1e4,1e4};
_sensor baffa;
float beta0[10];
float beta1[10];

void set_chlibration(_sensor *max, _sensor *min, _sensor *raw) {
	char i;

	for (i = 0; i < 10; i++) {
		if (max->main[i] < raw->main[i]) {
			max->main[i] = raw->main[i];
		}

		if (min->main[i] > raw->main[i]) {
				min->main[i] = raw->main[i];
			}
	}

		if (max->coner < raw->coner)
			max->coner = raw->coner;

		if (max->goal < raw->goal)
			max->goal = raw->goal;

		if (min->coner > raw->coner)
			min->coner = raw->coner;

		if (min->goal > raw->goal)
			min->goal = raw->goal;


		beta0[0]= 0;
		beta0[1]= 0;
		beta0[2]= 0;
		beta0[3]= 0;
		beta0[4]= -12.7451;
		beta0[5]= -9.8588;
		beta0[6]= -18.4861;
		beta0[7]= -70.4925;
		beta0[8]= -18.6335;
		beta0[9]= -9.6293;

		beta1[0]= 0;
		beta1[1]= 0;
		beta1[2]= 0;
		beta1[3]= 0;
		beta1[4]= 0.1062;
		beta1[5]= 0.0334;
		beta1[6]= 0.4453;
		beta1[7]= 0.7008;
		beta1[8]= 0.589;
		beta1[9]= 0.04;

}
void chalibration(_sensor *max, _sensor *min,_sensor *raw,_sensor *Calibration_value) {
	char i;
	int baffa;
	for(i=0;i<10;i++){
		baffa=(raw->main[i]- min->main[i]);
		Calibration_value->main[i]=(short)(baffa*100/(max->main[i]-min->main[i]));
	}

}

void rogistic_chalibration(_sensor *raw,_sensor *Calibration_value) {
	char i;
	for(i=0;i<10;i++){
		Calibration_value->main[i]=100*(beta0[i]+beta1[i]*raw->main[i]);
		if(Calibration_value->main[i]<0)
			Calibration_value->main[i]=0;
		else if(Calibration_value->main[i]>100)
			Calibration_value->main[i]=100;

	}


}
float rad[2]={0.0,0.0};
void radian(_sensor *raw,float rad[2]){
	volatile float temp_r,temp_l;
	char i;
	rad[0]=rad[1];
	for(i=0;i<5;i++){
		if(raw->main[4-i]>50)
	temp_l=((float)raw->main[4-i])*0.095*(i)/100;
		if(raw->main[i+5]>50)
	temp_r=((float)raw->main[i+5])*0.095*(i)/100;
	}

	rad[1]=temp_l-temp_r;


}



