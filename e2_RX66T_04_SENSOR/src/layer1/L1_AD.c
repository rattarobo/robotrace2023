/*
 * L1_AD.c
 *
 *  Created on: 2023/04/09
 *      Author: ratta
 */

#include "r_smc_entry.h"
#include "L1_io.h"
#include "L1_clock.h"
#include "L1_AD.h"



unsigned short temp0[12], temp1[12];
/**センサー型はこれ**/
//typedef struct {
//	float main[10];
//	float goal;
//	float coner;
//} _sensor;




long sum_battery;

short battery;
_sensor raw;

void get_sensor(_sensor *baffa) {
//	R_Config_DMAC0_Stop();
	SENLED1 = ON;
	SENLED2 = OFF;
	R_BSP_SoftwareDelay(30,BSP_DELAY_MICROSECS );
	R_Config_S12AD0_Start();
	R_Config_S12AD1_Start();
	R_Config_S12AD2_Start();

	while ((S12AD2.ADCSR.BIT.ADST == 1) || (S12AD1.ADCSR.BIT.ADST == 1)
			|| (S12AD.ADCSR.BIT.ADST == 1))
		;
	//			/* Read the A/D conversion result and store in variable */

	R_Config_S12AD2_Stop();
	R_Config_S12AD1_Stop();
	R_Config_S12AD0_Stop();
	SENLED1 = OFF;
	SENLED2 = OFF;
	R_Config_S12AD0_Get_ValueResult(ADCHANNEL7, &temp1[0]);
	R_Config_S12AD0_Get_ValueResult(ADCHANNEL0, &temp1[1]);
	R_Config_S12AD0_Get_ValueResult(ADCHANNEL1, &temp1[2]);
	R_Config_S12AD0_Get_ValueResult(ADCHANNEL2, &temp1[3]);
	R_Config_S12AD1_Get_ValueResult(ADCHANNEL7, &temp1[4]);
	R_Config_S12AD1_Get_ValueResult(ADCHANNEL0, &temp1[5]);
	R_Config_S12AD1_Get_ValueResult(ADCHANNEL1, &temp1[6]);
	R_Config_S12AD1_Get_ValueResult(ADCHANNEL2, &temp1[7]);
	R_Config_S12AD2_Get_ValueResult(ADCHANNEL0, &temp1[8]);
	R_Config_S12AD2_Get_ValueResult(ADCHANNEL1, &temp1[9]);

	//ゴール　コーナーセンサーの値取得
	R_Config_S12AD2_Get_ValueResult(ADCHANNEL17, &temp1[10]);
	R_Config_S12AD2_Get_ValueResult(ADCHANNEL16, &temp1[11]);

	R_BSP_SoftwareDelay(30,BSP_DELAY_MICROSECS );
	SENLED1 = OFF;
	SENLED2 = ON;
	R_BSP_SoftwareDelay(30,BSP_DELAY_MICROSECS );
	R_Config_S12AD0_Start();
	R_Config_S12AD1_Start();
	R_Config_S12AD2_Start();
	while ((S12AD2.ADCSR.BIT.ADST == 1) || (S12AD1.ADCSR.BIT.ADST == 1)
			|| (S12AD.ADCSR.BIT.ADST == 1))
		;
	/* Read the A/D conversion result and store in variable */

	R_Config_S12AD2_Stop();
	R_Config_S12AD1_Stop();
	R_Config_S12AD0_Stop();
	SENLED1 = OFF;
	SENLED2 = OFF;
	R_Config_S12AD0_Get_ValueResult(ADCHANNEL7, &temp0[0]);
	R_Config_S12AD0_Get_ValueResult(ADCHANNEL0, &temp0[1]);
	R_Config_S12AD0_Get_ValueResult(ADCHANNEL1, &temp0[2]);
	R_Config_S12AD0_Get_ValueResult(ADCHANNEL2, &temp0[3]);
	R_Config_S12AD1_Get_ValueResult(ADCHANNEL7, &temp0[4]);
	R_Config_S12AD1_Get_ValueResult(ADCHANNEL0, &temp0[5]);
	R_Config_S12AD1_Get_ValueResult(ADCHANNEL1, &temp0[6]);
	R_Config_S12AD1_Get_ValueResult(ADCHANNEL2, &temp0[7]);
	R_Config_S12AD2_Get_ValueResult(ADCHANNEL0, &temp0[8]);
	R_Config_S12AD2_Get_ValueResult(ADCHANNEL1, &temp0[9]);

	//ゴール　コーナーセンサーの値取得
	R_Config_S12AD2_Get_ValueResult(ADCHANNEL17, &temp0[10]);
	R_Config_S12AD2_Get_ValueResult(ADCHANNEL16, &temp0[11]);

	baffa->main[0] =  (temp0[0]) - (temp1[0]);
	baffa->main[1] =  (temp1[1]) - (temp0[1]);
	baffa->main[2] =  (temp0[2]) - (temp1[2]);
	baffa->main[3] =  (temp1[3]) - (temp0[3]);
	baffa->main[4] =  (temp0[4]) - (temp1[4]);
	baffa->main[5] =  (temp1[5]) - (temp0[5]);
	baffa->main[6] =  (temp0[6]) - (temp1[6]);
	baffa->main[7] =  (temp1[7]) - (temp0[7]);
	baffa->main[8] =  (temp0[8]) - (temp1[8]);
	baffa->main[9] =  (temp1[9]) - (temp0[9]);

	baffa->goal =  (temp1[10]) -  (temp0[10]);
	baffa->coner = (temp1[11]) -  (temp0[11]);
//	R_Config_DMAC0_Start();

}

//バッテリ電圧を取得する関数
//割り込みによって1ms毎に実行される
void get_bat_vol(void) {
	short bat;
	R_Config_S12AD2_Start();

	//変換結果を代入する
	R_Config_S12AD2_Get_ValueResult(ADCHANNEL2, &bat);

	R_Config_S12AD2_Stop(); //AD変換停止

	battery = (short) (bat * 5 / (1 / (1 + 3.0)) * 1000.f / 4095.f); //5V:4095=分圧した電圧:AD変換値
	//battery = (short)(bat * 3.3 / (R2 / (R1 + R2)) * 1000.f / 4095.f);//bat*ぶん3.3V:4095=分圧した電圧:AD変換値
	sum_battery += (long) battery;
}

