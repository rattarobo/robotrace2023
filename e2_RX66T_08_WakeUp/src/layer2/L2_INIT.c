/*
 * L2_INIT.c
 *
 *  Created on: 2023/09/22
 *      Author: ratta
 */

#include "r_smc_entry.h"


void init(void){
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

}
