/*
 * localization.cpp
 *
 *  Created on: Jul 16, 2024
 *      Author: yujungHuang
 */

#include "localization.h"
#include "stm32g4xx_hal.h"

void localize::Initialize(){
	linear_displacement=0;
	angular_displacement=0;
	theta=0;
}
float localize::linearDistance(float spd){
	linear_displacement=linear_displacement+(spd+last_spd)*0.001/*1000Hz*/*0.5;
	last_spd=spd;
	return linear_displacement;
}
float localize::angularDistance(float spd){
	angular_displacement=angular_displacement+(spd+last_omega)*0.001*0.5;
	last_omega=spd;
	return angular_displacement;
}
int localize::lineAssisting(){
	line=10000*HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9)+1000*HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_7)+100*HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_6)+10*HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)+HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6);
	return line;
}
void localize::thetaUpdate(){
	theta=theta+angular_displacement;
}





