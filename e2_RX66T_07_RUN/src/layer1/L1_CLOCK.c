/*
 * L1_CLOCK.c
 *
 *  Created on: 2023/04/08
 *      Author: ratta
 */


#include "L1_clock.h"

long global_time=1;
long global_time_50u=1;

void timer(void){
	global_time ++;
}
void timer_50u(void){
	global_time_50u ++;
}
