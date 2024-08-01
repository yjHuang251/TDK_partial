/*
 * localization.cpp
 *
 *  Created on: Jul 16, 2024
 *      Author: yujungHuang
 */

#include "localization.h"
#include "stm32g4xx_hal.h"
#include "math.h"

void localize::Initialize(){
	delta_x=0;
	delta_y=0;
	theta=0;
	last_theta=0;
	last_spd=0;
	last_omega=0;
	locLine=0;
}

float localize::delta_x_update(float spd,float omega){
	if(omega<0.001){
		delta_x=delta_x+(spd+last_spd)*0.001/*1000Hz*/*0.5;
	}
	else delta_x=delta_x+spd*0.001*(sin(theta)-sin(last_theta));
	return delta_x;
}
float localize::delta_y_update(float spd,float omega){
	if(omega<0.01) delta_y=delta_y+(spd+last_spd)*0.001*0.5;
	else delta_y=delta_y+spd*0.001*(cos(last_theta)-cos(theta));
	return delta_y;
}
float localize::thetaUpdate(float omega){
	if(omega>0.001) theta=theta+omega*0.001;
	last_theta=theta;
	return theta;
}

int localize::locLineAssisting(){
	locLine=10000*HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9/*s1*/)+1000*HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7/*s2*/)
		 +100*HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6/*s3*/)+10*HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7/*s4*/)
		 +HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6/*s5*/);
	//test corner
	if(locLine==1||locLine==11||locLine==111||locLine==1111) return 1;//need to turn left
	else if(locLine==10000||locLine==11000||locLine==11100||locLine==11110) return 2;//need to turn right
	else if(locLine==11111) return 3;//T corner, need to stop
	else return 0;
}

int localize::hitWall_Near(){//external interrupt
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_10/*Near*/)){
		//send message to navigation to slow down
		return 1;
	}
	else return 0;
}
int localize::hitWall_CLP(){//external interrupt
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_8/*CLP*/)){
			return 1;
	}
	else return 0;
}





