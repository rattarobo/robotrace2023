/*
 * L2_sensor.c
 *
 *  Created on: 2023/04/09
 *      Author: ratta
 */

/***************************************************************************************************************
 * 利用ファイルのヘッダ
 **************************************************************************************************************/
#include "L1_AD.h"
#include "L1_GPTW.h"
#include "L2_ERROR.h"
/***************************************************************************************************************
 * 自ファイルのヘッダ
 **************************************************************************************************************/
#include "L2_SENSOR.h"


/***************************************************************************************************************
 * 変数
 **************************************************************************************************************/
_wheel reset={0.,0.,0.,0.};

/***************************************************************************************************************
 * 公開変数
 **************************************************************************************************************/
 float battery_ave=0.0;
 _sensor min,max;
 //車輪の回転距離、速度
// typedef struct {
//	 double distance[2];
//	 float velocity[2];
// } _wheel;

/***************************************************************************************************************
 * 公開関数
 **************************************************************************************************************/
 void check_battery(_error *error) {//バッテリ電圧の平均値を取得


 	battery_ave = ((float) sum_battery /  BATTERY_COUNT/1000);
 	if(battery_ave< BATTERY_MIN){
 		error->battery=1;
 	}
 	else{
 		error->battery=0;
 	}
 	sum_battery = 0;

 }
_wheel check_dist_velo(_wheel previous){//距離を求める
	 _wheel temp;
	 //距離を求める
	 temp.distance[0]=(double)(l_enc* 12. / 42.*24/1000  *3.14159265358979/ (400.*4));//距離=ギア比*カウント*タイヤ系/１回転当たりの信号量;左
	 temp.distance[1]=(double)(r_enc* 12. / 42.*24/1000  *3.14159265358979/ (400.*4));//距離=ギア比*カウント*タイヤ系/１回転当たりの信号量;右
	 temp.distance[0]-=reset.distance[0];
	 temp.distance[1]-=reset.distance[1];
	 //速度を求める
	 temp.velocity[0]=(float)(temp.distance[0]-previous.distance[0])/DT;//差分*dt左
	 temp.velocity[1]=(float)(temp.distance[1]-previous.distance[1])/DT;//差分*dt右

	 return temp;
 }

void set_callibration(_sensorRaw *raw){//ラインセンサのキャリブレーション用の設定
	char i;

		for (i = 0; i < 10; i++) {
			if (max.main[i] < raw->main[i]) {
				max.main[i] = (float)raw->main[i];
			}

			if (min.main[i] > raw->main[i]) {
				min.main[i] = (float)raw->main[i];
			}
		}

			if (max.coner < raw->coner) {
				max.coner = (float)raw->coner;
			}

			if (min.coner > raw->coner) {
				min.coner = (float)raw->coner;
			}
			if (max.goal < raw->goal) {
				max.goal = (float)raw->goal;
			}

			if (min.goal > raw->goal) {
				min.goal = (float)raw->goal;
			}

}
_sensor sensor_callibration(_sensorRaw *raw){//ラインセンサのキャリブレーション
		_sensor get;
		char i;
		char temp=0;

		for (i = 0; i < 10; i++) {
			get.main[i] = (float)(raw->main[i] - min.main[i])
					/ (max.main[i] - min.main[i]);
		}
		get.goal= (float)(raw->goal-min.goal) /(max.goal - min.goal);
		get.coner=(float)(raw->coner-min.coner)/(max.coner - min.coner);
//		//前処理
//		for (i = 4; i > 0; i--) {
//			if ((get.main[i + 1] > 0.4 && get.main[i] < 0.4)
//					|| get.main[i] == 0)
//				get.main[i - 1] = 0;
//		}
//		for (i = 5; i < 9; i++) {
//			if ((get.main[i - 1] > 0.4 && get.main[i] < 0.4)
//					|| get.main[i] == 0)
//				get.main[i + 1] = 0;
//		}
		temp=0;
		for (i = 1; i <10; i++) {
			if (get.main[temp]<get.main[i]){
				temp=i;
			}
		}
		for (i = 0; i <10; i++) {
			if (i!=temp&&i!=temp-1&&i!=temp+1){
				get.main[i]=0;
			}
		}
		return get;
}
float get_sensor_angle(_sensor *get){
	float angle,norm=0.;
	angle =A0*get->main[0]+A1*get->main[1]+A2*get->main[2]+A3*get->main[3]+A4*get->main[4]+A5*+get->main[5]+A6*get->main[6]+A7*get->main[7]+A8*get->main[8]+A9*get->main[9];

	for(char i=0;i<10;i++)norm+=get->main[i];
	angle/=norm;
	return angle;
}
void reset_value(_wheel previous){
	reset.distance[0]=previous.distance[0];
	reset.distance[1]=previous.distance[1];
}
/***************************************************************************************************************
 * 非公開関数
 **************************************************************************************************************/






