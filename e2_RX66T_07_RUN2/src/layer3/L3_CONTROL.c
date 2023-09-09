/*
 * L3_CONTROL.c
 *
 *  Created on: 2023/04/16
 *      Author: ratta
 */

#include "L2_SENSOR.h"
#include "L3_CONTROL.h"

volatile _rotational_speed u={0.0,0.0};
volatile _rotational_speed target={0.0,0.0};
volatile float er_k1=0.0,el_k1=0.0,er_k2=0.0,el_k2=0.0;
_rotational_speed moter_pid(_rotational_speed target,_rotational_speed speed[2]){
	volatile	_rotational_speed du;
	volatile float er_k=target.r-(speed[1].r);
	volatile float el_k=target.l-(speed[1].l);

	if((target.r==0.0) &&er_k<1e-4){
		u.r=0;
	}
	else{
		du.r=Tr_p*(er_k-er_k1)+Tr_i*er_k+Tr_d*(er_k-2*er_k1+er_k2);
		u.r=u.r+du.r;
//	u.r=Tr_p*er_k;
	}

	if((target.l==0.0)&&el_k<1e-4){
		u.l=0;
	}
	else{
		du.l=Tl_p*(el_k-el_k1)+Tl_i*el_k+Tl_d*(el_k-2*el_k1+el_k2);
		u.l=u.l+du.l;
//		u.l=Tl_p*el_k;
	}

	er_k2=er_k1;
	er_k1=er_k;
	el_k2=el_k1;
	el_k1=el_k;
	return u;
}
volatile float u_sen=0.0;
float e_k1=0.0,e_k2=0.0;
_rotational_speed sensor_pid(float target_sen,float rad[2],float translation){
	volatile _rotational_speed rs={0.0,0.0};
	volatile float du_sen=0.0;

	volatile float e_k=target_sen-(rad[1]);

		du_sen=T_p*(e_k)+T_i*e_k+T_d*(e_k-e_k1);
		u_sen=du_sen;
//		u_sen=translation;

		rs.r=u_sen;
		rs.l=-u_sen;
	e_k2=e_k1;
	e_k1=e_k;

return rs;
}
