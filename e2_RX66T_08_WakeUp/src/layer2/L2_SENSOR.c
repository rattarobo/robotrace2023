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
	 temp.distance[0]=(double)(l_enc* 12 / 42  / 400);//距離*ギア比*カウント/１回転当たりの信号量;左
	 temp.distance[1]=(double)(r_enc* 12 / 42  / 400);//距離*ギア比*カウント/１回転当たりの信号量;右
	 //速度を求める
	 temp.velocity[0]=(float)(previous.distance[0]-temp.distance[0])*DT;//差分*dt左
	 temp.velocity[1]=(float)(previous.distance[1]-temp.distance[1])*DT;//差分*dt右
	 return temp;
 }

/***************************************************************************************************************
 * 非公開関数
 **************************************************************************************************************/






