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
#define y_Kp 1
#define y_Ki 1
#define y_Kd 1
#define nav_Kp 1
#define nav_Ki 1
#define nav_Kd 1
#define halfWidth 30//cm

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

	float lineAssisting(int*);
	float y_correction(float,float,float);
	float getMeanW(float, float, float, int*);

	float goal_distance=0;
	float goal_theta=0;
	float weight=0.5;
private:
	float v=0;
	float w=0;

	float y_w=0;
	float nav_w=0;

	float y_PIDval=0;
	float y_error=0;
	float y_ui=0;
	float y_last_error=0;

	float nav_PIDval=0;
	float nav_error=0;
	float nav_ui=0;
	float nav_last_error=0;
}navigate;



#endif /* INC_NAVIGATION_H_ */
