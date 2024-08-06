/*
 * resetProcess.cpp
 *
 *  Created on: 2024年8月6日
 *      Author: yujungHuang
 */
#include "resetProcess.h"
#include "stm32g4xx_hal.h"
int if_reset=-1;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin==GPIO_PIN_5) if_reset=RESETA;
	else if(GPIO_Pin==GPIO_PIN_4) if_reset=RESETB;
	else if(GPIO_Pin==GPIO_PIN_13) if_reset=RESETC;
	else if(GPIO_Pin==GPIO_PIN_14) if_reset=RESETD;
}
