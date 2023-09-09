/*
 * L1_CLOCK.c
 *
 *  Created on: 2023/04/08
 *      Author: ratta
 */


#include "L1_clock.h"

long global_time=1;

void timer(void){
	global_time ++;
}
