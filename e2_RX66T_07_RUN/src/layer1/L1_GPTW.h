/*
 * L1_GPTW.h
 *
 *  Created on: 2023/04/10
 *      Author: ratta
 */

#ifndef LAYER1_L1_GPTW_H_
#define LAYER1_L1_GPTW_H_


#define USHRT_MAX 399999
extern signed short r_over;
extern signed short l_over;
extern long l_enc,r_enc;



void GPTW_PWM(long left_PWM, long right_PWM);
void read_encorder(void);
#endif /* LAYER1_L1_GPTW_H_ */
