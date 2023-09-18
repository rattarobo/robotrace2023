/***********************************************************************
 *
 *  FILE        : e2_RX66T_04_ADC.c
 *  DATE        : 2023-04-09
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
#include "L1_AD.h"
#include "L2_SENSOR.h"
#include "L2_ERROR.h"
void main(void);

/* String used to print message at PC terminal */
static char print_str[80];
/* Flag used to detect whether data is received from PC terminal */
extern volatile uint8_t g_rx_flag_dmac;
/* Global variable used for storing data received from PC terminal */
extern volatile uint8_t g_rx_char_dmac;

void main(void)
{
	/*Enable CMT operation*/
	R_Config_CMT0_Start();
	R_Config_CMT1_Start();
	/* Set SCI1 receive buffer address and enable receive interrupt */
	R_Config_SCI1_Serial_Receive(NULL, 0);
	/* Enable SCI1 operation */
	R_Config_SCI1_Start();
	/* Enable DMAC0 operation */
	R_Config_DMAC0_Start();



	/*エラーの初期化*/
	error_init(&error);
	/*エラーの監視*/
	error_message(&error);
	char i;

	sprintf(print_str, "\r\n Press keyboard to control LED\r\n");
	R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
	sprintf(print_str, "\r\n 1 ----> LED1 turn on\n");
	R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
	sprintf(print_str, "\r\n 8 ----> LED8 turn on\n");
	R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
	while(1){

		//受信
		if(g_rx_flag_dmac ==1){

			switch( g_rx_char_dmac){

			case '1':
				R_Config_SCI1_Serial_Receive(NULL, 0);
				led.led1=ON;
				break;
			case '2':
				R_Config_SCI1_Serial_Receive(NULL, 0);
				led.led2=ON;
				break;
			case '3':
				R_Config_SCI1_Serial_Receive(NULL, 0);
				led.led3=ON;
				break;
			case '4':
				R_Config_SCI1_Serial_Receive(NULL, 0);
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

			default:
//				sprintf(print_str, "\r\n bat=%d\r\n",(short)battery_ave);
//				R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
				for(i=0;i<10;i++){
					sprintf(print_str, " =%d=%d",i,raw.main[i]);
					R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));

				}
				sprintf(print_str, "\r\n");
				R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
//				sprintf(print_str, " \nGoal =%d\r\n",raw.goal);
//				R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
//				sprintf(print_str, " coner =%d\r\n",raw.coner);
//				R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));

					led.led1=OFF;
					led.led2=OFF;
					led.led3=OFF;
					led.led4=OFF;
					led.led5=OFF;
					led.led6=OFF;
					led.led7=OFF;
					led.led8=OFF;
					break;

				}

				/* Reset SCI1 reception flag*/
				g_rx_flag_dmac = 0;

			}

		}

	}

