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

#include "timer.h"
#include "localization.h"

localize car;
int count=0;

extern TIM_HandleTypeDef htim6;
extern float spd;
extern float omega;
extern float linear_distance;
extern float angular_distance;

void setup(){
	HAL_TIM_Base_Start_IT(&htim6);
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	linear_distance=car.linearDistance(spd);
	angular_distance=car.angularDistance(omega);
	car.lineAssisting();
	count++;
}
