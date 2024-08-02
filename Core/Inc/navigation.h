/*
 * navigation.h
 *
 *  Created on: Aug 1, 2024
 *      Author: yujungHuang
 */
#define pi 3.14159265358979323846
#define Mv 15//m/s
#define mv 0.2//m/s
#define Mw 0.2*pi//rad/s
#define mw 0.02*pi//red/s

#ifndef INC_NAVIGATION_H_
#define INC_NAVIGATION_H_

//extern float x_distance;
//extern float y_distance;
//extern float theta;
//extern float spd;
//extern float omega;
//extern int lineInfo;
extern float missions[];

typedef class navigate{
public:
	void stop();

	float spdControl(float,float,float);
	float wControl(float,float);

	float navLineAssisting(int);
	float y_correction(float,float,float);
	float getMeanW();

	float goal_distance;
	float goal_theta;
private:
	float v=0;
	float w=0;

	float y_w=0;
	float nav_w=0;
}navigate;



#endif /* INC_NAVIGATION_H_ */
