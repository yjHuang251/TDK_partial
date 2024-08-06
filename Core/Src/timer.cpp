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
#include "resetProcess.h"

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
extern int if_mission;
extern reset_e reset;
extern int if_reset;

void setup(){
	HAL_TIM_Base_Start_IT(&htim6);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	switch(if_reset){
	case -1:
		break;
	case RESETA:
		index=0;
		if_reset=-1;
		break;
	case RESETB:
		index=20;
		if_reset=-1;
		break;
	case RESETC:
		index=23;
		if_reset=-1;
		break;
	case RESETD:
		index=35;
		if_reset=-1;
		break;
	}
	if(!if_mission){
		//localization//
		theta=theta+car.thetaUpdate(omega);
		x_distance=car.delta_x_update(spd,omega);
		y_distance=car.delta_y_update(spd,omega);
		car.getLineData();
		for(int i=0;i<5;i++){
			lineInfo[i]=car.line[i];
		}
		//navigation//
		if(index<=18) chassis.weight=0;
		//whether mission complete
		if(abs(missions[index]-x_distance)>0.005){
			if(spd==0){//rotate mission
				omega=chassis.wControl(omega, theta);
			}
			else {
				//chassis.y_correction(spd, theta, y_distance);
				//chassis.LineAssisting(lineInfo);
				omega=chassis.getMeanW(spd, theta, y_distance, lineInfo);
				if(omega<0.001) omega=0;
				spd=chassis.spdControl(spd, x_distance, theta);
			}
		}else {
			chassis.stop();
			car.Initialize();
			if(index==2||index==3||index==4||index==5||index==6||
			   index==10||index==11||index==12||index==18||index==20||
			   index==27||index==32){
				if_mission=1;
			}
			index++;
			if(missions[index]==2048){
				chassis.stop();
			}
		}
	}
	count++;
}
