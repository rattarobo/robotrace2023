/*
 * L2_ERROR.c
 *
 *  Created on: 2023/04/09
 *      Author: ratta
 */

#include "r_smc_entry.h"
#include <stdio.h>
#include <string.h>
#include "L1_IO.h"
#include "L2_SENSOR.h"
#include "L2_ERROR.h"


_error error;

void error_init(_error *error){
error->battery=0;
error->r_enc=0;
error->l_enc=0;
error->gyro=0;
error->calibration=1;
}
void error_message(_error *error){
	/**初期設定の後にエラーメッセージを出す関数**/
	static char print_error[80];
	while(error->battery==1){
		sprintf(print_error, "\r\n low battery\r\n");
		R_DMAC1_AsyncTransmit((uint8_t *) print_error, (uint16_t) strlen(print_error));

		sprintf(print_error," bat=%d\r\n",battery_ave);
		R_DMAC1_AsyncTransmit((uint8_t *) print_error, (uint16_t) strlen(print_error));
		led.led1=ON;
	}

	if(error->l_enc==1){
		sprintf(print_error, "\r\n left encoder can not read!!\r\n");
		R_DMAC1_AsyncTransmit((uint8_t *) print_error, (uint16_t) strlen(print_error));
		led.led2=ON;
	}
	else led.led2=OFF;
	if(error->r_enc==1){
		sprintf(print_error, "\r\n right encoder can not read!!\r\n");
		R_DMAC1_AsyncTransmit((uint8_t *) print_error, (uint16_t) strlen(print_error));
		led.led3=ON;
	}
	else led.led3=OFF;
	if(error->gyro==1){
			sprintf(print_error, "\r\n gyro can not read!!\r\n");
			R_DMAC1_AsyncTransmit((uint8_t *) print_error, (uint16_t) strlen(print_error));
			led.led4=ON;
	}
	else led.led4=OFF;
	if(error->calibration==1){
			sprintf(print_error, "\r\n calibration is not finish!!\r\n");
			R_DMAC1_AsyncTransmit((uint8_t *) print_error, (uint16_t) strlen(print_error));
			led.led5=ON;
	}
	else led.led5=OFF;

}
