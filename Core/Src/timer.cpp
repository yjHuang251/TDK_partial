/*
 * timer.cpp
 *
 *  Created on: Jul 16, 2024
 *      Author: yujungHuang
 */

/*
 * when get velocity
 * 1.calculate distance
 * 2.coordinate update
 * 3.line following
 * 4.mission decision according to coordinate
 */

#include "math.h"
#include "timer.h"
#include "localization.h"
#include "navigation.h"

localize car;
navigate chassis;
int count=0;

extern TIM_HandleTypeDef htim6;
extern float spd;
extern float omega;
extern float theta;
extern float x_distance;
extern float y_distance;
extern int lineInfo[];
extern int index;
extern float missions[];

void setup(){
	HAL_TIM_Base_Start_IT(&htim6);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	//localization
	theta=theta+car.thetaUpdate(omega);
	x_distance=car.delta_x_update(spd,omega);
	y_distance=car.delta_y_update(spd,omega);
	for(int i=0;i<5;i++){
		lineInfo[i]=car.line[i];
	}
	//navigation
	if(abs(missions[index]-x_distance)>0.005){
		if(spd==0){
			omega=chassis.wControl(omega, theta);
			if(omega<0.001) omega=0;
		}
		else {
			chassis.y_correction(spd, theta, y_distance);
			chassis.LineAssisting(lineInfo);
			omega=chassis.getMeanW();
			if(omega<0.001) omega=0;
			spd=chassis.spdControl(spd, x_distance, theta);
		}
	}else {
		chassis.stop();
		index++;
		if(missions[index]==2048){
			//send complete message
		}
	}
	count++;
}
