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
#define T (0.)
#define RRP 50
#define RLP 50
#define RRI 0
#define RLI 0
#define RRD 0
#define RLD 0

/***********************************************************************************************************
 * 構造体宣言
 **********************************************************************************************************/

/***********************************************************************************************************
 * extern 関数宣言
 **********************************************************************************************************/
extern void RUN(void);
extern _wheel run_pid(float command_value,float recent_value);
/***********************************************************************************************************
 * extern 変数宣言
 **********************************************************************************************************/
#endif /* LAYER3_L3_RUN_H_ */
