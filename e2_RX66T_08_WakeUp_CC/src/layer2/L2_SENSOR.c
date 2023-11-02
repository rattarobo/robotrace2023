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


 	battery_ave = (float) (sum_battery /  BATTERY_COUNT);
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
	 temp.distance[0]=(double)(l_enc* 12. / 42.  / 400.);//距離*ギア比*カウント/１回転当たりの信号量;左
	 temp.distance[1]=(double)(r_enc* 12. / 42.  / 400.);//距離*ギア比*カウント/１回転当たりの信号量;右

	 //速度を求める
	 temp.velocity[0]=(float)(temp.distance[0]-previous.distance[0]);//差分*dt左
	 temp.velocity[1]=(float)(temp.distance[1]-previous.distance[1]);//差分*dt右
	 if (temp.velocity[0]>10 ||temp.velocity[0]<-10){
		 temp.velocity[0]=previous.distance[0];
	 }
	 if (temp.velocity[1]>10 ||temp.velocity[1]<-10){
		 temp.velocity[1]=previous.distance[1];
	 }
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

		for (i = 0; i < 10; i++) {
			get.main[i] = (float)(raw->main[i] - min.main[i])
					/ (max.main[i] - min.main[i]);
		}
		get.goal=(float)(raw->goal-min.goal)/(max.goal - min.goal);
		get.coner=(float)(raw->coner-min.coner)/(max.coner - min.coner);
//		//前処理
//		for (i = 4; i > 0; i--) {
//			if ((get.main[i + 1] > 80 && get.main[i] < 80)
//					|| get.main[i] == 0)
//				get.main[i - 1] = 0;
//		}
//		for (i = 5; i < 9; i++) {
//			if ((get.main[i - 1] > 80 && get.main[i] < 80)
//					|| get.main[i] == 0)
//				get.main[i + 1] = 0;
//		}
		return get;
}
/***************************************************************************************************************
 * 非公開関数
 **************************************************************************************************************/






