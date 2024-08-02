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

	return y_w;
}
float navigate::navLineAssisting(int lineInfo){

	return nav_w;
}
float navigate::getMeanW(){
	w=(y_w+nav_w)*0.5;
	return w;
}
