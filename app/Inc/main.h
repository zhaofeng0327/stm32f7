/* USER CODE BEGIN Header */

/**
 ******************************************************************************
 * @file           : main.h
 * @brief          : Header for main.c file.
 *                   This file contains the common defines of the application.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
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
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal.h"

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
#define QUADSPI_BK1_IO2_Pin          GPIO_PIN_2
#define QUADSPI_BK1_IO2_GPIO_Port    GPIOE
#define GPRS_BOARD_ID1_Pin           GPIO_PIN_3
#define GPRS_BOARD_ID1_GPIO_Port     GPIOE
#define GPRS_BOARD_ID2_Pin           GPIO_PIN_4
#define GPRS_BOARD_ID2_GPIO_Port     GPIOE
#define GPRS_BOARD_ID3_Pin           GPIO_PIN_5
#define GPRS_BOARD_ID3_GPIO_Port     GPIOE
#define QR_CODE_LED_Pin              GPIO_PIN_6
#define QR_CODE_LED_GPIO_Port        GPIOE
#define RCC_OSC32_IN_Pin             GPIO_PIN_14
#define RCC_OSC32_IN_GPIO_Port       GPIOC
#define RCC_OSC32_OUT_Pin            GPIO_PIN_15
#define RCC_OSC32_OUT_GPIO_Port      GPIOC
#define RCC_OSC_IN_Pin               GPIO_PIN_0
#define RCC_OSC_IN_GPIO_Port         GPIOH
#define RCC_OSC_OUT_Pin              GPIO_PIN_1
#define RCC_OSC_OUT_GPIO_Port        GPIOH
#define ADC1_IN10_NTC_Pin            GPIO_PIN_0
#define ADC1_IN10_NTC_GPIO_Port      GPIOC
#define BAT6_IN_EXTI_Pin             GPIO_PIN_1
#define BAT6_IN_EXTI_GPIO_Port       GPIOC
#define BAT6_IN_EXTI_EXTI_IRQn       EXTI1_IRQn
#define SOLENOID_EN6_Pin             GPIO_PIN_2
#define SOLENOID_EN6_GPIO_Port       GPIOC
#define CHARGING_EN6_Pin             GPIO_PIN_3
#define CHARGING_EN6_GPIO_Port       GPIOC
#define UART4_TX_S6_Pin              GPIO_PIN_0
#define UART4_TX_S6_GPIO_Port        GPIOA
#define CHARGING_EN5_Pin             GPIO_PIN_1
#define CHARGING_EN5_GPIO_Port       GPIOA
#define USART2_TX_S5_Pin             GPIO_PIN_2
#define USART2_TX_S5_GPIO_Port       GPIOA
#define SOLENOID_EN5_Pin             GPIO_PIN_3
#define SOLENOID_EN5_GPIO_Port       GPIOA
#define BAT5_IN_EXTI_Pin             GPIO_PIN_4
#define BAT5_IN_EXTI_GPIO_Port       GPIOA
#define BAT5_IN_EXTI_EXTI_IRQn       EXTI4_IRQn
#define LED1_Pin                     GPIO_PIN_5
#define LED1_GPIO_Port               GPIOA
#define LED2_Pin                     GPIO_PIN_6
#define LED2_GPIO_Port               GPIOA
#define LED3_Pin                     GPIO_PIN_7
#define LED3_GPIO_Port               GPIOA
#define LED4_Pin                     GPIO_PIN_4
#define LED4_GPIO_Port               GPIOC
#define LED5_Pin                     GPIO_PIN_5
#define LED5_GPIO_Port               GPIOC
#define LED6_Pin                     GPIO_PIN_0
#define LED6_GPIO_Port               GPIOB
#define LED7_Pin                     GPIO_PIN_1
#define LED7_GPIO_Port               GPIOB
#define QUADSPI_CLK_Pin              GPIO_PIN_2
#define QUADSPI_CLK_GPIO_Port        GPIOB
#define UART7_RX_Pin                 GPIO_PIN_7
#define UART7_RX_GPIO_Port           GPIOE
#define UART7_TX_Pin                 GPIO_PIN_8
#define UART7_TX_GPIO_Port           GPIOE
#define UART7_RTS_Pin                GPIO_PIN_9
#define UART7_RTS_GPIO_Port          GPIOE
#define UART7_CTS_Pin                GPIO_PIN_10
#define UART7_CTS_GPIO_Port          GPIOE
#define LED8_Pin                     GPIO_PIN_11
#define LED8_GPIO_Port               GPIOE
#define SOLENOID_EN4_Pin             GPIO_PIN_13
#define SOLENOID_EN4_GPIO_Port       GPIOE
#define BAT4_IN_EXTI_Pin             GPIO_PIN_14
#define BAT4_IN_EXTI_GPIO_Port       GPIOE
#define BAT4_IN_EXTI_EXTI_IRQn       EXTI15_10_IRQn
#define CHARGING_EN4_Pin             GPIO_PIN_15
#define CHARGING_EN4_GPIO_Port       GPIOE
#define USART3_TX_S4_Pin             GPIO_PIN_10
#define USART3_TX_S4_GPIO_Port       GPIOB
#define MAIN_BOARD_ID1_Pin           GPIO_PIN_12
#define MAIN_BOARD_ID1_GPIO_Port     GPIOB
#define BAT3_IN_EXTI_Pin             GPIO_PIN_13
#define BAT3_IN_EXTI_GPIO_Port       GPIOB
#define BAT3_IN_EXTI_EXTI_IRQn       EXTI15_10_IRQn
#define SOLENOID_EN3_Pin             GPIO_PIN_14
#define SOLENOID_EN3_GPIO_Port       GPIOB
#define CHARGING_EN3_Pin             GPIO_PIN_15
#define CHARGING_EN3_GPIO_Port       GPIOB
#define USART3_MUTX_S3_Pin           GPIO_PIN_8
#define USART3_MUTX_S3_GPIO_Port     GPIOD
#define MAIN_BOARD_ID2_Pin           GPIO_PIN_9
#define MAIN_BOARD_ID2_GPIO_Port     GPIOD
#define MAIN_BOARD_ID3_Pin           GPIO_PIN_10
#define MAIN_BOARD_ID3_GPIO_Port     GPIOD
#define QUADSPI_BK1_IO0_Pin          GPIO_PIN_11
#define QUADSPI_BK1_IO0_GPIO_Port    GPIOD
#define QUADSPI_BK1_IO1_Pin          GPIO_PIN_12
#define QUADSPI_BK1_IO1_GPIO_Port    GPIOD
#define QUADSPI_BK1_IO3_Pin          GPIO_PIN_13
#define QUADSPI_BK1_IO3_GPIO_Port    GPIOD
#define GPRS_CTS_Pin                 GPIO_PIN_14
#define GPRS_CTS_GPIO_Port           GPIOD
#define GPRS_RTS_Pin                 GPIO_PIN_15
#define GPRS_RTS_GPIO_Port           GPIOD
#define USART6_TX_S2_Pin             GPIO_PIN_6
#define USART6_TX_S2_GPIO_Port       GPIOC
#define CHARGING_EN2_Pin             GPIO_PIN_7
#define CHARGING_EN2_GPIO_Port       GPIOC
#define SOLENOID_EN2_Pin             GPIO_PIN_8
#define SOLENOID_EN2_GPIO_Port       GPIOC
#define BAT2_IN_EXTI_Pin             GPIO_PIN_9
#define BAT2_IN_EXTI_GPIO_Port       GPIOC
#define BAT2_IN_EXTI_EXTI_IRQn       EXTI9_5_IRQn
#define USART1_TX_S1_Pin             GPIO_PIN_9
#define USART1_TX_S1_GPIO_Port       GPIOA
#define CHARGING_EN1_Pin             GPIO_PIN_10
#define CHARGING_EN1_GPIO_Port       GPIOA
#define SOLENOID_EN1_Pin             GPIO_PIN_11
#define SOLENOID_EN1_GPIO_Port       GPIOA
#define BAT1_IN_EXTI_Pin             GPIO_PIN_12
#define BAT1_IN_EXTI_GPIO_Port       GPIOA
#define BAT1_IN_EXTI_EXTI_IRQn       EXTI15_10_IRQn
#define JTMS_SWDIO_Pin               GPIO_PIN_13
#define JTMS_SWDIO_GPIO_Port         GPIOA
#define JTCK_SWCLK_Pin               GPIO_PIN_14
#define JTCK_SWCLK_GPIO_Port         GPIOA
#define JTDI_Pin                     GPIO_PIN_15
#define JTDI_GPIO_Port               GPIOA
#define UART4_MUTX_S8_Pin            GPIO_PIN_10
#define UART4_MUTX_S8_GPIO_Port      GPIOC
#define BAT8_IN_EXTI_Pin             GPIO_PIN_11
#define BAT8_IN_EXTI_GPIO_Port       GPIOC
#define BAT8_IN_EXTI_EXTI_IRQn       EXTI15_10_IRQn
#define UART5_TX_DEBUG_Pin           GPIO_PIN_12
#define UART5_TX_DEBUG_GPIO_Port     GPIOC
#define CHARGING_EN8_Pin             GPIO_PIN_0
#define CHARGING_EN8_GPIO_Port       GPIOD
#define SOLENOID_EN8_Pin             GPIO_PIN_1
#define SOLENOID_EN8_GPIO_Port       GPIOD
#define UART5_RX_DEBUG_Pin           GPIO_PIN_2
#define UART5_RX_DEBUG_GPIO_Port     GPIOD
#define CHARGING_EN7_Pin             GPIO_PIN_4
#define CHARGING_EN7_GPIO_Port       GPIOD
#define USART2_MUTX_S7_Pin           GPIO_PIN_5
#define USART2_MUTX_S7_GPIO_Port     GPIOD
#define SOLENOID_EN7_Pin             GPIO_PIN_6
#define SOLENOID_EN7_GPIO_Port       GPIOD
#define BAT7_IN_EXTI_Pin             GPIO_PIN_7
#define BAT7_IN_EXTI_GPIO_Port       GPIOD
#define BAT7_IN_EXTI_EXTI_IRQn       EXTI9_5_IRQn
#define JTDO_SWO_Pin                 GPIO_PIN_3
#define JTDO_SWO_GPIO_Port           GPIOB
#define JTRST_Pin                    GPIO_PIN_4
#define JTRST_GPIO_Port              GPIOB
#define QUADSPI_BK1_NCS_Pin          GPIO_PIN_6
#define QUADSPI_BK1_NCS_GPIO_Port    GPIOB
#define GPRS_PWR_EN_Pin              GPIO_PIN_7
#define GPRS_PWR_EN_GPIO_Port        GPIOB
#define GPRS_RESET_Pin               GPIO_PIN_8
#define GPRS_RESET_GPIO_Port         GPIOB
#define GPRS_PWRKEY_Pin              GPIO_PIN_9
#define GPRS_PWRKEY_GPIO_Port        GPIOB
#define GPRS_RX_Pin                  GPIO_PIN_0
#define GPRS_RX_GPIO_Port            GPIOE
#define GPRS_TX_Pin                  GPIO_PIN_1
#define GPRS_TX_GPIO_Port            GPIOE
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif	/* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
