/***********************************************************************
*
*  FILE        : e2_RX66T_06_RSPI.c
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
#include "L1_AD.h"
#include "L1_MTU.h"
#include "L1_GPTW.h"
#include "L1_RSPI.h"

#include "L2_SENSOR.h"
#include "L2_ERROR.h"
#include "L2_MOTOR.h"

void main(void);
/* String used to print message at PC terminal */
static char print_str[80];
/* Flag used to detect whether data is received from PC terminal */
extern volatile uint8_t g_rx_flag_dmac;
/* Global variable used for storing data received from PC terminal */
extern volatile uint8_t g_rx_char_dmac;
extern volatile uint16_t g_rspi0_tx_buf;
extern volatile uint16_t g_rspi0_rx_buf;
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
		/* Enable GPTW operation */
		R_Config_GPT2_Start();
		R_Config_GPT3_Start();
//		RSPI_init();
//		R_Config_RSPI0_Start();

		/*エラーの初期化*/

		char i,i1;
		volatile unsigned short who;

		sprintf(print_str, "\r\n Press keyboard to control LED\r\n");
		R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
		sprintf(print_str, "\r\n 1 ----> LED1 turn on\n");
		R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
		sprintf(print_str, "\r\n 8 ----> LED8 turn on\n");
		R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
		who =Gyro_init();
		sprintf(print_str, "\r\n who=%x\r\n",who);
		R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));

		/* Start the RSPI0 module operation */
		while(1){

			who =Gyro_init();
			sprintf(print_str, "\r\n who=%x\r\n",who);
			R_DMAC1_AsyncTransmit((uint8_t *) print_str, (uint16_t) strlen(print_str));
			led.led1=OFF;
			led.led2=OFF;
			led.led3=OFF;
			led.led4=OFF;
			led.led5=OFF;
			led.led6=OFF;
			led.led7=OFF;
			led.led8=OFF;
		}
}
