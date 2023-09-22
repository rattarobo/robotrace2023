/*
 * L1_GPTW.c
 *
 *  Created on: 2023/04/10
 *      Author: ratta
 */

#include "L1_IO.h"
#include "L1_GPTW.h"



void GPTW_PWM(long left_PWM, long right_PWM){
	R_Config_GPT4_Stop();
	GPTW4.GTCCRE=left_PWM;//　GTIOC4B 左
	GPTW4.GTCCRC=right_PWM;//GTIOC4A 右
	R_Config_GPT4_Start();
}

long l_enc, r_enc;
short r_over;
short l_over;
void read_encorder(void) {

	l_enc = (signed long int) (GPTW3.GTCNT)
			+ (signed long int) (USHRT_MAX) * (signed long int) r_over; //1周期：400パルス＊位相係数：4＊ギア比３　＝4800
	r_enc = (signed long int) (GPTW2.GTCNT)
			+ (signed long int) (USHRT_MAX) * (signed long int) l_over; //1周期：400パルス＊位相係数：4＊ギア比３　＝4800
}
