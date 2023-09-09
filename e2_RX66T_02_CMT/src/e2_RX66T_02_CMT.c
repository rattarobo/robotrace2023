/***********************************************************************
*
*  FILE        : e2_RX66T_02_CMT.c
*  DATE        : 2023-04-08
*  DESCRIPTION : Main Program
*
*  NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "r_smc_entry.h"
#include "L1_IO.h"
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
	R_Config_CMT0_Start();

}
