/*
 * L2_sensor.c
 *
 *  Created on: 2023/04/09
 *      Author: ratta
 */
#include "r_smc_entry.h"

#include "L1_AD.h"
#include "L1_GPTW.h"
#include "L1_RSPI.h"
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
float r_speed, l_speed;
float r_speed_b, l_speed_b;
float r_speed_record, l_speed_record;

long r_dis1, r_dis2; //速さ、現在距離、一つ前の距離
long l_dis1, l_dis2;
void distance_velocity(void){
	r_dis1 = r_enc;
	l_dis1 = l_enc;
	r_speed = ((r_dis1 - r_dis2) * 1000 * 12 / 42 / 50); //距離*ギア比＊カウント/１回転当たりの信号量
	l_speed = ((l_dis1 - l_dis2) * 1000 * 12 / 42 / 50);

	r_dis2 = r_dis1;
	l_dis2 = l_dis1;
	r_speed_b = r_speed;
	l_speed_b = l_speed;
}

short Gyro_init(void) {
	unsigned short who;
//	R_Config_RSPI0_Start();

//	spi_exchange(0x6b); //レジスタのリセットspi_exchange(0x006b0000);
	R_BSP_SoftwareDelay(50,BSP_DELAY_MILLISECS);
//	R_Config_RSPI0_Start();
	who=spi_exchange(0xf500); //レジスタの初期化送信spi_exchange(0x00370002);
	R_BSP_SoftwareDelay(50,BSP_DELAY_MILLISECS);

return who;
}

