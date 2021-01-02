/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
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
#include "stm32f4xx_hal.h"
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_exti.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_cortex.h"
#include "stm32f4xx_ll_rcc.h"
#include "stm32f4xx_ll_utils.h"
#include "stm32f4xx_ll_pwr.h"
#include "stm32f4xx_ll_dma.h"

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
#define LCD_DC_Pin LL_GPIO_PIN_2
#define LCD_DC_GPIO_Port GPIOE
#define TP_CLK_Pin LL_GPIO_PIN_3
#define TP_CLK_GPIO_Port GPIOE
#define TP_CS_Pin LL_GPIO_PIN_4
#define TP_CS_GPIO_Port GPIOE
#define TP_MOSI_Pin LL_GPIO_PIN_5
#define TP_MOSI_GPIO_Port GPIOE
#define TP_MISO_Pin LL_GPIO_PIN_6
#define TP_MISO_GPIO_Port GPIOE
#define TP_IRQ_Pin LL_GPIO_PIN_13
#define TP_IRQ_GPIO_Port GPIOC
#define Row1_Pin LL_GPIO_PIN_2
#define Row1_GPIO_Port GPIOF
#define Row2_Pin LL_GPIO_PIN_3
#define Row2_GPIO_Port GPIOF
#define Row3_Pin LL_GPIO_PIN_4
#define Row3_GPIO_Port GPIOF
#define Row4_Pin LL_GPIO_PIN_5
#define Row4_GPIO_Port GPIOF
#define Column1_Pin LL_GPIO_PIN_6
#define Column1_GPIO_Port GPIOF
#define Column2_Pin LL_GPIO_PIN_7
#define Column2_GPIO_Port GPIOF
#define Column3_Pin LL_GPIO_PIN_8
#define Column3_GPIO_Port GPIOF
#define Column4_Pin LL_GPIO_PIN_9
#define Column4_GPIO_Port GPIOF
#define BUZZER_Pin LL_GPIO_PIN_1
#define BUZZER_GPIO_Port GPIOG
#define LED_Pin LL_GPIO_PIN_15
#define LED_GPIO_Port GPIOG
#define LCD_RST_Pin LL_GPIO_PIN_0
#define LCD_RST_GPIO_Port GPIOE
#define LCD_CS_Pin LL_GPIO_PIN_1
#define LCD_CS_GPIO_Port GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
