/*
 * navigation.cpp
 *
 *  Created on: Aug 1, 2024
 *      Author: yujungHuang
 */
#include "navigation.h"
#include "math.h"

void navigate::stop(){
	v=0;
	w=0;
}

float navigate::spdControl(float spd, float x_distance, float theta){
	v=spd*cos(theta);
	//1s to speed up to max speed, 3s to slow down to 0
	if(x_distance<goal_distance*0.5&&v<Mv){
		v=v+Mv*0.001/*1000Hz*/;
		return v;
	}
	if(x_distance>goal_distance-0.5*3*Mv&&v>mv) v=v-Mv*0.333*0.001;
	else v=mv;
	v=v/cos(theta);
	return v;
}
float navigate::wControl(float omega, float theta){
	w=omega;
	//0.5s to speed up to max omega, 0.5s to slow down to 0
	if(theta<goal_theta*0.5&&w<Mw){
		w=w+Mw*2*0.001;
		return w;
	}
	if(theta>goal_theta-0.5*0.5*Mw&&w>mw) w=w-Mw*2*0.001;
	else w=mw;
	return w;
}

float navigate::y_correction(float spd, float theta, float y_distance){
	//omega correction: radius of rotation=2.5*y_distance
	y_error=y_distance;
	y_ui=y_ui+y_error*0.001;
	y_PIDval=y_Kp*y_error+y_Ki*y_ui+y_Kd*(y_error-y_last_error);
	y_last_error=y_error;
	y_w=y_PIDval/halfWidth;
	return y_w;
}
float navigate::lineAssisting(int* lineInfo){
	int left=0;
	int center=0;
	int right=0;
	//categorize data
	for(int i=0;i<5;i++){
		if(lineInfo[i]==1){
			switch(i){
			case 0:
			case 1:
				left++;
				break;
			case 2:
				center++;
				break;
			case 3:
			case 4:
				right++;
				break;
			}
		}
	}
	//exclude impossible situation
	if((center==0&&((lineInfo[0]==0&&lineInfo[1]==1)||//010..
	   (lineInfo[3]==1&&lineInfo[4]==0)))||//..010
	   (center==1&&(left>0&&right>0))){//it's impossible that do not detect black line from center but detect from both sides
		weight=0;
		return 0;
	}
	//pid control
	nav_error=right-left;
	nav_ui=nav_ui+nav_error*0.001;
	nav_PIDval=nav_Kp*nav_error+nav_Ki*nav_ui+nav_Kd*(nav_error-nav_last_error);
	nav_last_error=nav_error;
	nav_w=nav_PIDval/halfWidth;
	return nav_w;
}
float navigate::getMeanW(float spd, float theta, float y_distance, int* lineInfo){
	w=y_correction(spd, theta, y_distance)*(1-weight)+lineAssisting(lineInfo)*weight;
	return w;
}
