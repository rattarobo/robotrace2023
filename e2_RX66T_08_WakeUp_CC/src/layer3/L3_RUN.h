/*
 * L3_RUN.h
 *
 *  Created on: 2023/11/02
 *      Author: ratta
 */

#ifndef LAYER3_L3_RUN_H_
#define LAYER3_L3_RUN_H_

/***********************************************************************************************************
 * define　宣言
 **********************************************************************************************************/
#define T 100
#define RRP 661.8518
#define RLP 661.8518
#define RRI 160.3038
#define RLI 160.3038
#define RRD 0
#define RLD 0
#define RN 100

/***********************************************************************************************************
 * 構造体宣言
 **********************************************************************************************************/

/***********************************************************************************************************
 * extern 関数宣言
 **********************************************************************************************************/
extern void RUN(void);
extern _wheel run_pid(float command_value,float recent_value,_wheel previous_value);
/***********************************************************************************************************
 * extern 変数宣言
 **********************************************************************************************************/
#endif /* LAYER3_L3_RUN_H_ */
