/*
 * L1_IO.c
 *
 *  Created on: 2023/04/07
 *      Author: ratta
 */


#include "L1_IO.h"

#include "r_smc_entry.h"
 LED led;
//LEDをつける
LED led_on(LED a){
	if(a.led1==1)
	LED1=ON;
	else
		LED1=OFF;
	if(a.led2==1)
	LED2=ON;
	else
		LED2=OFF;
	if(a.led3==1)
	LED3=ON;
	else
		LED3=OFF;
	if(a.led4==1)
	LED4=ON;
	else
		LED4=OFF;
	if(a.led5==1)
	LED5=ON;
	else
		LED5=OFF;
	if(a.led6==1)
	LED6=ON;
	else
		LED6=OFF;
	if(a.led7==1)
	LED7=ON;
	else
		LED7=OFF;
	if(a.led8==1)
	LED8=ON;
	else
		LED8=OFF;
	return a;
}
LED led_off(LED a){
	if(a.led1==1)
	LED1=OFF;

	if(a.led2==1)
	LED2=OFF;
	if(a.led3==1)
	LED3=OFF;
	if(a.led4==1)
	LED4=OFF;
	if(a.led5==1)
	LED5=OFF;
	if(a.led6==1)
	LED6=OFF;
	if(a.led7==1)
	LED7=OFF;
	if(a.led8==1)
	LED8=OFF;

	return a;
}

