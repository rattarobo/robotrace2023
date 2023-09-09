/***********************************************************************
*
*  FILE        : e2_RX66T_01_IO.c
*  DATE        : 2023-04-06
*  DESCRIPTION : Main Program
*
*  NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "r_smc_entry.h"

#include "layer1/L1_IO.h"
void main(void);

void main(void)
{
	LED led;
	led.led1=0;
	led.led2=0;
	led.led3=0;
	led.led4=0;
	led.led5=0;
	led.led6=0;
	led.led7=0;
	led.led8=0;
	while(1){
	if(SW ==ON){
	led.led1=1;
	led_on(led);
	}
	else{
	led_off(led);
	}
	}
}
