/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define s5_Pin GPIO_PIN_6
#define s5_GPIO_Port GPIOA
#define s4_Pin GPIO_PIN_7
#define s4_GPIO_Port GPIOA
#define Near_Pin GPIO_PIN_10
#define Near_GPIO_Port GPIOB
#define resetC_Pin GPIO_PIN_13
#define resetC_GPIO_Port GPIOB
#define resetC_EXTI_IRQn EXTI15_10_IRQn
#define resetD_Pin GPIO_PIN_14
#define resetD_GPIO_Port GPIOB
#define resetD_EXTI_IRQn EXTI15_10_IRQn
#define s2_Pin GPIO_PIN_7
#define s2_GPIO_Port GPIOC
#define CLP_Pin GPIO_PIN_8
#define CLP_GPIO_Port GPIOA
#define s1_Pin GPIO_PIN_9
#define s1_GPIO_Port GPIOA
#define resetB_Pin GPIO_PIN_4
#define resetB_GPIO_Port GPIOB
#define resetB_EXTI_IRQn EXTI4_IRQn
#define resetA_Pin GPIO_PIN_5
#define resetA_GPIO_Port GPIOB
#define resetA_EXTI_IRQn EXTI9_5_IRQn
#define s3_Pin GPIO_PIN_6
#define s3_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
