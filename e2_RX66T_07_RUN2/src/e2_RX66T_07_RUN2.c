/***********************************************************************
*
*  FILE        : e2_RX66T_05_GPTW.c
*  DATE        : 2023-04-10
*  DESCRIPTION : Main Program
*
*  NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "r_smc_entry.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "L1_IO.h"
#include "L1_CLOCK.h"
#include "L1_AD.h"
#include "L1_MTU.h"
#include "L1_GPTW.h"

#include "L2_SENSOR.h"
#include "L2_ERROR.h"
#include "L2_MOTOR.h"

#include "L3_CONTROL.h"
void main(void);

/* String used to print message at PC terminal */
static char print_str[80];
/* Flag used to detect whether data is received from PC terminal */
extern volatile uint8_t g_rx_flag_dmac;
/* Global variable used for storing data received from PC terminal */
extern volatile uint8_t g_rx_char_dmac;

void main(void)
{
	u.r=0.0;
	u.l=0.0;
	target.r=0.0;
	target.l=0.0;
	/*Enable CMT operation*/
	R_Config_CMT0_Start();
	R_Config_CMT1_Start();
	R_Config_CMT2_Start();
	/* Set SCI1 receive buffer address and enable receive interrupt */
	R_Config_SCI1_Serial_Receive(NULL, 0);
	/* Enable SCI1 operation */
	R_Config_SCI1_Start();
	/* Enable DMAC0 operation */
	R_Config_DMAC0_Start();
	/* Enable GPTW operation */
	R_Config_GPT2_Start();
	R_Config_GPT3_Start();
	u.r=0.0;
	u.l=0.0;
	target.r=0.0;
	target.l=0.0;

	R_BSP_SoftwareDelay(500,BSP_DELAY_MILLISECS);
	/*エラーの初期化*/
	error_init(&error);
	/*エラーの監視*/
	error_message(&error);


	sprintf(print_str, "\r\n Press keyboard to control LED\r\n");
	R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
	sprintf(print_str, "\r\n 1 ----> LED1 turn on\n");
	R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
	sprintf(print_str, "\r\n 8 ----> LED8 turn on\n");
	R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));

	buzzer_start(523);
	R_BSP_SoftwareDelay(500,BSP_DELAY_MILLISECS);
	buzzer_stop();
	R_BSP_SoftwareDelay(1,BSP_DELAY_SECS);
//	target.r=0.1;
//	target.l=0.1;
	int j;
	float buz=1.f;
	for(j=0;j<1e3;j++){
		if(j%200==1)buz*=1.059;
		buzzer_start((int)(493.883*buz));
	set_chlibration( &max,&min,&raw);
	R_BSP_SoftwareDelay(10,BSP_DELAY_MILLISECS);
	}
	buzzer_stop();
	R_BSP_SoftwareDelay(500,BSP_DELAY_MILLISECS);
	error.calibration=0;
	while(1){
		error_message( &error);
		//受信
		if(g_rx_flag_dmac ==1){

			switch( g_rx_char_dmac){

			case '1':
				R_Config_SCI1_Serial_Receive(NULL, 0);
				//LED点灯
				while(1){
				led.led1=ON;
				R_BSP_SoftwareDelay(1,BSP_DELAY_SECS);
				if(SW==ON){
					break;
				}
				}
				led.led1=OFF;
				break;
			case '2':
				R_Config_SCI1_Serial_Receive(NULL, 0);
				//センサー値の表示
				while(1){
					led.led2=ON;
						for(j=0;j<10;j++){
						sprintf(print_str, " %d=",raw.main[j]);
						R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
						}
						sprintf(print_str, " \r\n");
						R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
						if(SW==ON){
							break;
						}
				}
				led.led2=OFF;
				break;
			case '3':
				R_Config_SCI1_Serial_Receive(NULL, 0);
				//モータの回転
				while(1){
				change_motor_voltage(1000,1000);
				led.led3=ON;
				R_BSP_SoftwareDelay(500,BSP_DELAY_MILLISECS);
				if(SW==ON){
					break;
				}
				}
				break;
			case '4':
				R_Config_SCI1_Serial_Receive(NULL, 0);
				//走行
				while(1){
					get_sensor(&raw);
					radian(&raw,rad);
					target=sensor_pid(-0.285,rad,0.0);
				}
				led.led4=ON;
				break;
			case '5':
				R_Config_SCI1_Serial_Receive(NULL, 0);
				led.led5=ON;
				break;
			case '6':
				R_Config_SCI1_Serial_Receive(NULL, 0);
				led.led6=ON;
				break;
			case '7':
				R_Config_SCI1_Serial_Receive(NULL, 0);
				led.led7=ON;
				break;
			case '8':
				R_Config_SCI1_Serial_Receive(NULL, 0);
				led.led8=ON;
				break;
			case 'A':
				sprintf(print_str, " %d=%f=%f\r\n",global_time,speed[1].r,speed[1].l);
				R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
				target.r=0.5;
				target.l=0.5;

				break;
			case 'B':
				sprintf(print_str, "\r\n r=%f=l=%f\r\n",speed[1].r,speed[1].l);
				R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));

				target.r=-10;
				target.l=-10;
				break;
			default:
				sprintf(print_str, "\r\n r=%f\t l=%f\r\n",distance[1].r,distance[1].l);
				R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));

					led.led1=OFF;
					led.led2=OFF;
					led.led3=OFF;
					led.led4=OFF;
					led.led5=OFF;
					led.led6=OFF;
					led.led7=OFF;
					led.led8=OFF;
					target.r=0.0;
					target.l=0.0;
					break;

				}

				/* Reset SCI1 reception flag*/
				g_rx_flag_dmac = 0;


			}


//		for(j=0;j<10;j++){
//		sprintf(print_str, " %d=",baffa.main[j]);
//		R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
//		}
		sprintf(print_str, " u=%f \r\n",u_sen);
		R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
//		sprintf(print_str, " \r\n");
//		R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
	}

	}

void run_1st(void){
	get_sensor(&raw);
	radian(&raw,rad);
	target=sensor_pid(-0.285,rad,0.0);

}
