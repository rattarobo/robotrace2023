/*
 * L2_ERROR.h
 *
 *  Created on: 2023/04/09
 *      Author: ratta
 */

#ifndef LAYER2_L2_ERROR_H_
#define LAYER2_L2_ERROR_H_

#include "stdbool.h"
typedef struct {
	bool battery;
	bool r_enc;
	bool l_enc;
	bool gyro;
	bool calibration;
} _error;
extern  _error error;

void error_init(_error *error);
void error_message(_error *error);

#endif /* LAYER2_L2_ERROR_H_ */
