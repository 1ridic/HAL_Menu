/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f4xx_hal.h"

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
#define SW2_Pin GPIO_PIN_2
#define SW2_GPIO_Port GPIOE
#define SW3_Pin GPIO_PIN_3
#define SW3_GPIO_Port GPIOE
#define SW4_Pin GPIO_PIN_4
#define SW4_GPIO_Port GPIOE
#define SW5_Pin GPIO_PIN_5
#define SW5_GPIO_Port GPIOE
#define SW6_Pin GPIO_PIN_6
#define SW6_GPIO_Port GPIOE
#define BEEP_Pin GPIO_PIN_4
#define BEEP_GPIO_Port GPIOA
#define SW7_Pin GPIO_PIN_7
#define SW7_GPIO_Port GPIOE
#define LED1_Pin GPIO_PIN_12
#define LED1_GPIO_Port GPIOE
#define LED2_Pin GPIO_PIN_13
#define LED2_GPIO_Port GPIOE
#define LED3_Pin GPIO_PIN_14
#define LED3_GPIO_Port GPIOE
#define LED4_Pin GPIO_PIN_15
#define LED4_GPIO_Port GPIOE
#define up_Pin GPIO_PIN_11
#define up_GPIO_Port GPIOD
#define up_EXTI_IRQn EXTI15_10_IRQn
#define down_Pin GPIO_PIN_12
#define down_GPIO_Port GPIOD
#define down_EXTI_IRQn EXTI15_10_IRQn
#define KEY_LF_Pin GPIO_PIN_13
#define KEY_LF_GPIO_Port GPIOD
#define KEY_RT_Pin GPIO_PIN_14
#define KEY_RT_GPIO_Port GPIOD
#define ok_Pin GPIO_PIN_15
#define ok_GPIO_Port GPIOD
#define ok_EXTI_IRQn EXTI15_10_IRQn
#define SPI3_CS1_Pin GPIO_PIN_8
#define SPI3_CS1_GPIO_Port GPIOC
#define SPI3_CS2_Pin GPIO_PIN_9
#define SPI3_CS2_GPIO_Port GPIOC
#define OLED_CS_Pin GPIO_PIN_0
#define OLED_CS_GPIO_Port GPIOD
#define OLED_DC_Pin GPIO_PIN_1
#define OLED_DC_GPIO_Port GPIOD
#define OLED_RES_Pin GPIO_PIN_2
#define OLED_RES_GPIO_Port GPIOD
#define KEY1_Pin GPIO_PIN_4
#define KEY1_GPIO_Port GPIOD
#define KEY2_Pin GPIO_PIN_5
#define KEY2_GPIO_Port GPIOD
#define SW0_Pin GPIO_PIN_0
#define SW0_GPIO_Port GPIOE
#define SW1_Pin GPIO_PIN_1
#define SW1_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
