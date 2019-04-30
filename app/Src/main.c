/* USER CODE BEGIN Header */

/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "adc.h"
#include "crc.h"
#include "fatfs.h"
#include "iwdg.h"
#include "quadspi.h"
#include "rng.h"
#include "rtc.h"
#include "tim.h"
#include "usart.h"
#include "wwdg.h"
#include "gpio.h"

#ifdef STM32F730xx
#include "aes.h"
#endif

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void MX_FREERTOS_Init(void);
static void MX_NVIC_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* USER CODE BEGIN 1 */

	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_ADC1_Init();
	MX_QUADSPI_Init();
	MX_UART4_Init();
	MX_UART5_Init();
	MX_UART7_Init();
	MX_UART8_Init();
	MX_USART1_UART_Init();
	MX_USART2_UART_Init();
	MX_USART3_UART_Init();
	MX_USART6_UART_Init();
	MX_RTC_Init();
	//	MX_WWDG_Init();
	//	MX_IWDG_Init();
	MX_TIM6_Init();
	MX_RNG_Init();
	MX_CRC_Init();

	#ifdef STM32F730xx
	MX_AES_Init();
	#endif

	/* Initialize interrupts */
	MX_NVIC_Init();
	/* USER CODE BEGIN 2 */

	/* USER CODE END 2 */

	/* Call init function for freertos objects (in freertos.c) */
	MX_FREERTOS_Init();

	/* Start scheduler */
	osKernelStart();

	/* We should never get here as control is now taken by the scheduler */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1) {
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}	/* main */

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct         = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct         = { 0 };
	RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = { 0 };

	/** Configure LSE Drive Capability
	 */
	HAL_PWR_EnableBkUpAccess();
	__HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

	/** Configure the main internal regulator output voltage
	 */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/** Initializes the CPU, AHB and APB busses clocks
	 */
	#ifdef STM32F730xx
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI | RCC_OSCILLATORTYPE_HSE
	  | RCC_OSCILLATORTYPE_LSE;
	RCC_OscInitStruct.HSEState      = RCC_HSE_ON;
	RCC_OscInitStruct.LSEState      = RCC_LSE_ON;
	RCC_OscInitStruct.LSIState      = RCC_LSI_ON;
	RCC_OscInitStruct.PLL.PLLState  = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 12;
	RCC_OscInitStruct.PLL.PLLN = 208;
	#elif defined(STM32F746xx)
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI | RCC_OSCILLATORTYPE_LSI
	  | RCC_OSCILLATORTYPE_LSE;
	RCC_OscInitStruct.LSEState = RCC_LSE_ON;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.LSIState		= RCC_LSI_ON;
	RCC_OscInitStruct.PLL.PLLState	= RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM		= 8;
	RCC_OscInitStruct.PLL.PLLN		= 208;
	#endif

	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/** Activate the Over-Drive mode
	 */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB busses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
	  | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider  = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_6) != HAL_OK) {
		Error_Handler();
	}
	PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC | RCC_PERIPHCLK_USART1
	  | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_USART3
	  | RCC_PERIPHCLK_USART6 | RCC_PERIPHCLK_UART4
	  | RCC_PERIPHCLK_UART5 | RCC_PERIPHCLK_UART7
	  | RCC_PERIPHCLK_UART8 | RCC_PERIPHCLK_CLK48;
	PeriphClkInitStruct.RTCClockSelection    = RCC_RTCCLKSOURCE_LSE;
	PeriphClkInitStruct.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
	PeriphClkInitStruct.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
	PeriphClkInitStruct.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
	PeriphClkInitStruct.Uart4ClockSelection  = RCC_UART4CLKSOURCE_PCLK1;
	PeriphClkInitStruct.Uart5ClockSelection  = RCC_UART5CLKSOURCE_PCLK1;
	PeriphClkInitStruct.Usart6ClockSelection = RCC_USART6CLKSOURCE_PCLK2;
	PeriphClkInitStruct.Uart7ClockSelection  = RCC_UART7CLKSOURCE_PCLK1;
	PeriphClkInitStruct.Uart8ClockSelection  = RCC_UART8CLKSOURCE_PCLK1;
	PeriphClkInitStruct.Clk48ClockSelection  = RCC_CLK48SOURCE_PLL;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK) {
		Error_Handler();
	}
}	/* SystemClock_Config */

/**
 * @brief NVIC Configuration.
 * @retval None
 */
static void MX_NVIC_Init(void)
{
	/* EXTI1_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(EXTI1_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);
	/* EXTI4_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(EXTI4_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
	/* EXTI9_5_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
	/* USART1_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(USART1_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
	/* USART2_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(USART2_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(USART2_IRQn);
	/* USART3_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(USART3_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(USART3_IRQn);
	/* EXTI15_10_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	/* UART4_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(UART4_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(UART4_IRQn);
	/* UART5_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(UART5_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(UART5_IRQn);
	/* USART6_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(USART6_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(USART6_IRQn);
	/* UART7_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(UART7_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(UART7_IRQn);
	/* UART8_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(UART8_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(UART8_IRQn);
	/* WWDG_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(WWDG_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(WWDG_IRQn);
	/* TIM6_DAC_IRQn interrupt configuration */
	HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 5, 0);
	HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);
}	/* MX_NVIC_Init */

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */

	/* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT

/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */

	/* User can add his own implementation to report the file name and line number,
	 * tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}

#endif	/* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
