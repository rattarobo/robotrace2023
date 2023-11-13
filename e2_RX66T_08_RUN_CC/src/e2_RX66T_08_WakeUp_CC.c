/***********************************************************************
 *
 *  FILE        : e2_RX66T_08_WakeUp_CC.c
 *  DATE        : 2023-10-28
 *  DESCRIPTION : Main Program
 *
 *  NOTE:THIS IS A TYPICAL EXAMPLE.
 *
 ***********************************************************************/
#include "r_smc_entry.h"

/***************************************************************************************************************
 * 利用ファイルのヘッダ
 **************************************************************************************************************/
#include "L1_AD.h"
#include "L2_SENSOR.h"

#include "L3_WAKEUP.h"
#include "L3_RUN.h"
#include "L3_MODE.h"
/***************************************************************************************************************
 * 公開変数
 **************************************************************************************************************/

/***************************************************************************************************************
 * 公開関数
 **************************************************************************************************************/

void main(void);

void main(void)
{
	char num=0;
	wake_up();
	num=mode();
	RUN();


}
/***************************************************************************************************************
 * 非公開関数
 **************************************************************************************************************/



