/**
 ******************************************************************************
 * File Name          : USART.c
 * Description        : This file provides code for the configuration
 *                      of the USART instances.
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

/* Includes ------------------------------------------------------------------*/
#include "usart.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

UART_HandleTypeDef huart4;
UART_HandleTypeDef huart5;
UART_HandleTypeDef huart7;
UART_HandleTypeDef huart8;
UART_HandleTypeDef huart1;
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart3;
UART_HandleTypeDef huart6;

/* UART4 init function */
void MX_UART4_Init(void)
{
	huart4.Instance                    = UART4;
	huart4.Init.BaudRate               = 115200;
	huart4.Init.WordLength             = UART_WORDLENGTH_8B;
	huart4.Init.StopBits               = UART_STOPBITS_1;
	huart4.Init.Parity                 = UART_PARITY_NONE;
	huart4.Init.Mode                   = UART_MODE_TX_RX;
	huart4.Init.HwFlowCtl              = UART_HWCONTROL_NONE;
	huart4.Init.OverSampling           = UART_OVERSAMPLING_16;
	huart4.Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
	huart4.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_HalfDuplex_Init(&huart4) != HAL_OK) {
		Error_Handler();
	}
}

/* UART5 init function */
void MX_UART5_Init(void)
{
	huart5.Instance                    = UART5;
	huart5.Init.BaudRate               = 115200;
	huart5.Init.WordLength             = UART_WORDLENGTH_8B;
	huart5.Init.StopBits               = UART_STOPBITS_1;
	huart5.Init.Parity                 = UART_PARITY_NONE;
	huart5.Init.Mode                   = UART_MODE_TX_RX;
	huart5.Init.HwFlowCtl              = UART_HWCONTROL_NONE;
	huart5.Init.OverSampling           = UART_OVERSAMPLING_16;
	huart5.Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
	huart5.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_UART_Init(&huart5) != HAL_OK) {
		Error_Handler();
	}
}

/* UART7 init function */
void MX_UART7_Init(void)
{
	huart7.Instance                    = UART7;
	huart7.Init.BaudRate               = 115200;
	huart7.Init.WordLength             = UART_WORDLENGTH_8B;
	huart7.Init.StopBits               = UART_STOPBITS_1;
	huart7.Init.Parity                 = UART_PARITY_NONE;
	huart7.Init.Mode                   = UART_MODE_TX_RX;
	huart7.Init.HwFlowCtl              = UART_HWCONTROL_RTS_CTS;
	huart7.Init.OverSampling           = UART_OVERSAMPLING_16;
	huart7.Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
	huart7.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_UART_Init(&huart7) != HAL_OK) {
		Error_Handler();
	}
}

/* UART8 init function */
void MX_UART8_Init(void)
{
	huart8.Instance                    = UART8;
	huart8.Init.BaudRate               = 115200;
	huart8.Init.WordLength             = UART_WORDLENGTH_8B;
	huart8.Init.StopBits               = UART_STOPBITS_1;
	huart8.Init.Parity                 = UART_PARITY_NONE;
	huart8.Init.Mode                   = UART_MODE_TX_RX;
	huart8.Init.HwFlowCtl              = UART_HWCONTROL_RTS_CTS;
	huart8.Init.OverSampling           = UART_OVERSAMPLING_16;
	huart8.Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
	huart8.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_UART_Init(&huart8) != HAL_OK) {
		Error_Handler();
	}
}

/* USART1 init function */

void MX_USART1_UART_Init(void)
{
	huart1.Instance                    = USART1;
	huart1.Init.BaudRate               = 115200;
	huart1.Init.WordLength             = UART_WORDLENGTH_8B;
	huart1.Init.StopBits               = UART_STOPBITS_1;
	huart1.Init.Parity                 = UART_PARITY_NONE;
	huart1.Init.Mode                   = UART_MODE_TX_RX;
	huart1.Init.HwFlowCtl              = UART_HWCONTROL_NONE;
	huart1.Init.OverSampling           = UART_OVERSAMPLING_16;
	huart1.Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
	huart1.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_HalfDuplex_Init(&huart1) != HAL_OK) {
		Error_Handler();
	}
}

/* USART2 init function */

void MX_USART2_UART_Init(void)
{
	huart2.Instance                    = USART2;
	huart2.Init.BaudRate               = 115200;
	huart2.Init.WordLength             = UART_WORDLENGTH_8B;
	huart2.Init.StopBits               = UART_STOPBITS_1;
	huart2.Init.Parity                 = UART_PARITY_NONE;
	huart2.Init.Mode                   = UART_MODE_TX_RX;
	huart2.Init.HwFlowCtl              = UART_HWCONTROL_NONE;
	huart2.Init.OverSampling           = UART_OVERSAMPLING_16;
	huart2.Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
	huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_HalfDuplex_Init(&huart2) != HAL_OK) {
		Error_Handler();
	}
}

/* USART3 init function */

void MX_USART3_UART_Init(void)
{
	huart3.Instance                    = USART3;
	huart3.Init.BaudRate               = 115200;
	huart3.Init.WordLength             = UART_WORDLENGTH_8B;
	huart3.Init.StopBits               = UART_STOPBITS_1;
	huart3.Init.Parity                 = UART_PARITY_NONE;
	huart3.Init.Mode                   = UART_MODE_TX_RX;
	huart3.Init.HwFlowCtl              = UART_HWCONTROL_NONE;
	huart3.Init.OverSampling           = UART_OVERSAMPLING_16;
	huart3.Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
	huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_HalfDuplex_Init(&huart3) != HAL_OK) {
		Error_Handler();
	}
}

/* USART6 init function */

void MX_USART6_UART_Init(void)
{
	huart6.Instance                    = USART6;
	huart6.Init.BaudRate               = 115200;
	huart6.Init.WordLength             = UART_WORDLENGTH_8B;
	huart6.Init.StopBits               = UART_STOPBITS_1;
	huart6.Init.Parity                 = UART_PARITY_NONE;
	huart6.Init.Mode                   = UART_MODE_TX_RX;
	huart6.Init.HwFlowCtl              = UART_HWCONTROL_NONE;
	huart6.Init.OverSampling           = UART_OVERSAMPLING_16;
	huart6.Init.OneBitSampling         = UART_ONE_BIT_SAMPLE_DISABLE;
	huart6.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	if (HAL_HalfDuplex_Init(&huart6) != HAL_OK) {
		Error_Handler();
	}
}

void HAL_UART_MspInit(UART_HandleTypeDef *uartHandle)
{
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	if (uartHandle->Instance == UART4) {
		/* USER CODE BEGIN UART4_MspInit 0 */

		/* USER CODE END UART4_MspInit 0 */
		/* UART4 clock enable */
		__HAL_RCC_UART4_CLK_ENABLE();

		__HAL_RCC_GPIOA_CLK_ENABLE();

		/**UART4 GPIO Configuration
		 * PA0-WKUP     ------> UART4_TX
		 */
		GPIO_InitStruct.Pin       = UART4_TX_S6_Pin;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
		GPIO_InitStruct.Pull      = GPIO_NOPULL;
		GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF8_UART4;
		HAL_GPIO_Init(UART4_TX_S6_GPIO_Port, &GPIO_InitStruct);

		/* USER CODE BEGIN UART4_MspInit 1 */

		/* USER CODE END UART4_MspInit 1 */
	} else if (uartHandle->Instance == UART5)      {
		/* USER CODE BEGIN UART5_MspInit 0 */

		/* USER CODE END UART5_MspInit 0 */
		/* UART5 clock enable */
		__HAL_RCC_UART5_CLK_ENABLE();

		__HAL_RCC_GPIOC_CLK_ENABLE();
		__HAL_RCC_GPIOD_CLK_ENABLE();

		/**UART5 GPIO Configuration
		 * PC12     ------> UART5_TX
		 * PD2     ------> UART5_RX
		 */
		GPIO_InitStruct.Pin       = UART5_TX_DEBUG_Pin;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull      = GPIO_NOPULL;
		GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF8_UART5;
		HAL_GPIO_Init(UART5_TX_DEBUG_GPIO_Port, &GPIO_InitStruct);

		GPIO_InitStruct.Pin       = UART5_RX_DEBUG_Pin;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull      = GPIO_NOPULL;
		GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF8_UART5;
		HAL_GPIO_Init(UART5_RX_DEBUG_GPIO_Port, &GPIO_InitStruct);

		/* USER CODE BEGIN UART5_MspInit 1 */

		/* USER CODE END UART5_MspInit 1 */
	} else if (uartHandle->Instance == UART7)      {
		/* USER CODE BEGIN UART7_MspInit 0 */

		/* USER CODE END UART7_MspInit 0 */
		/* UART7 clock enable */
		__HAL_RCC_UART7_CLK_ENABLE();

		__HAL_RCC_GPIOE_CLK_ENABLE();

		/**UART7 GPIO Configuration
		 * PE7     ------> UART7_RX
		 * PE8     ------> UART7_TX
		 * PE9     ------> UART7_RTS
		 * PE10     ------> UART7_CTS
		 */
		GPIO_InitStruct.Pin       = UART7_RX_Pin | UART7_TX_Pin;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull      = GPIO_NOPULL;
		GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF8_UART7;
		HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

		GPIO_InitStruct.Pin       = UART7_RTS_Pin | UART7_CTS_Pin;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull      = GPIO_NOPULL;
		GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_MEDIUM;
		GPIO_InitStruct.Alternate = GPIO_AF8_UART7;
		HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

		/* USER CODE BEGIN UART7_MspInit 1 */

		/* USER CODE END UART7_MspInit 1 */
	} else if (uartHandle->Instance == UART8)      {
		/* USER CODE BEGIN UART8_MspInit 0 */

		/* USER CODE END UART8_MspInit 0 */
		/* UART8 clock enable */
		__HAL_RCC_UART8_CLK_ENABLE();

		__HAL_RCC_GPIOD_CLK_ENABLE();
		__HAL_RCC_GPIOE_CLK_ENABLE();

		/**UART8 GPIO Configuration
		 * PD14     ------> UART8_CTS
		 * PD15     ------> UART8_RTS
		 * PE0     ------> UART8_RX
		 * PE1     ------> UART8_TX
		 */
		GPIO_InitStruct.Pin       = GPRS_CTS_Pin | GPRS_RTS_Pin;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull      = GPIO_NOPULL;
		GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_MEDIUM;
		GPIO_InitStruct.Alternate = GPIO_AF8_UART8;
		HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

		GPIO_InitStruct.Pin       = GPRS_RX_Pin | GPRS_TX_Pin;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull      = GPIO_NOPULL;
		GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF8_UART8;
		HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

		/* USER CODE BEGIN UART8_MspInit 1 */

		/* USER CODE END UART8_MspInit 1 */
	} else if (uartHandle->Instance == USART1)      {
		/* USER CODE BEGIN USART1_MspInit 0 */

		/* USER CODE END USART1_MspInit 0 */
		/* USART1 clock enable */
		__HAL_RCC_USART1_CLK_ENABLE();

		__HAL_RCC_GPIOA_CLK_ENABLE();

		/**USART1 GPIO Configuration
		 * PA9     ------> USART1_TX
		 */
		GPIO_InitStruct.Pin       = USART1_TX_S1_Pin;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
		GPIO_InitStruct.Pull      = GPIO_NOPULL;
		GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF7_USART1;
		HAL_GPIO_Init(USART1_TX_S1_GPIO_Port, &GPIO_InitStruct);

		/* USER CODE BEGIN USART1_MspInit 1 */

		/* USER CODE END USART1_MspInit 1 */
	} else if (uartHandle->Instance == USART2)      {
		/* USER CODE BEGIN USART2_MspInit 0 */

		/* USER CODE END USART2_MspInit 0 */
		/* USART2 clock enable */
		__HAL_RCC_USART2_CLK_ENABLE();

		__HAL_RCC_GPIOA_CLK_ENABLE();

		/**USART2 GPIO Configuration
		 * PA2     ------> USART2_TX
		 */
		GPIO_InitStruct.Pin       = USART2_TX_S5_Pin;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
		GPIO_InitStruct.Pull      = GPIO_NOPULL;
		GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
		HAL_GPIO_Init(USART2_TX_S5_GPIO_Port, &GPIO_InitStruct);

		/* USER CODE BEGIN USART2_MspInit 1 */

		/* USER CODE END USART2_MspInit 1 */
	} else if (uartHandle->Instance == USART3)      {
		/* USER CODE BEGIN USART3_MspInit 0 */

		/* USER CODE END USART3_MspInit 0 */
		/* USART3 clock enable */
		__HAL_RCC_USART3_CLK_ENABLE();

		__HAL_RCC_GPIOB_CLK_ENABLE();

		/**USART3 GPIO Configuration
		 * PB10     ------> USART3_TX
		 */
		GPIO_InitStruct.Pin       = USART3_TX_S4_Pin;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
		GPIO_InitStruct.Pull      = GPIO_NOPULL;
		GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF7_USART3;
		HAL_GPIO_Init(USART3_TX_S4_GPIO_Port, &GPIO_InitStruct);

		/* USER CODE BEGIN USART3_MspInit 1 */

		/* USER CODE END USART3_MspInit 1 */
	} else if (uartHandle->Instance == USART6)      {
		/* USER CODE BEGIN USART6_MspInit 0 */

		/* USER CODE END USART6_MspInit 0 */
		/* USART6 clock enable */
		__HAL_RCC_USART6_CLK_ENABLE();

		__HAL_RCC_GPIOC_CLK_ENABLE();

		/**USART6 GPIO Configuration
		 * PC6     ------> USART6_TX
		 */
		GPIO_InitStruct.Pin       = USART6_TX_S2_Pin;
		GPIO_InitStruct.Mode      = GPIO_MODE_AF_OD;
		GPIO_InitStruct.Pull      = GPIO_NOPULL;
		GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
		GPIO_InitStruct.Alternate = GPIO_AF8_USART6;
		HAL_GPIO_Init(USART6_TX_S2_GPIO_Port, &GPIO_InitStruct);

		/* USER CODE BEGIN USART6_MspInit 1 */

		/* USER CODE END USART6_MspInit 1 */
	}
} /* HAL_UART_MspInit */

void HAL_UART_MspDeInit(UART_HandleTypeDef *uartHandle)
{
	if (uartHandle->Instance == UART4) {
		/* USER CODE BEGIN UART4_MspDeInit 0 */

		/* USER CODE END UART4_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_UART4_CLK_DISABLE();

		/**UART4 GPIO Configuration
		 * PA0-WKUP     ------> UART4_TX
		 */
		HAL_GPIO_DeInit(UART4_TX_S6_GPIO_Port, UART4_TX_S6_Pin);

		/* UART4 interrupt Deinit */
		HAL_NVIC_DisableIRQ(UART4_IRQn);
		/* USER CODE BEGIN UART4_MspDeInit 1 */

		/* USER CODE END UART4_MspDeInit 1 */
	} else if (uartHandle->Instance == UART5)      {
		/* USER CODE BEGIN UART5_MspDeInit 0 */

		/* USER CODE END UART5_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_UART5_CLK_DISABLE();

		/**UART5 GPIO Configuration
		 * PC12     ------> UART5_TX
		 * PD2     ------> UART5_RX
		 */
		HAL_GPIO_DeInit(UART5_TX_DEBUG_GPIO_Port, UART5_TX_DEBUG_Pin);

		HAL_GPIO_DeInit(UART5_RX_DEBUG_GPIO_Port, UART5_RX_DEBUG_Pin);

		/* UART5 interrupt Deinit */
		HAL_NVIC_DisableIRQ(UART5_IRQn);
		/* USER CODE BEGIN UART5_MspDeInit 1 */

		/* USER CODE END UART5_MspDeInit 1 */
	} else if (uartHandle->Instance == UART7)      {
		/* USER CODE BEGIN UART7_MspDeInit 0 */

		/* USER CODE END UART7_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_UART7_CLK_DISABLE();

		/**UART7 GPIO Configuration
		 * PE7     ------> UART7_RX
		 * PE8     ------> UART7_TX
		 * PE9     ------> UART7_RTS
		 * PE10     ------> UART7_CTS
		 */
		HAL_GPIO_DeInit(GPIOE, UART7_RX_Pin | UART7_TX_Pin | UART7_RTS_Pin | UART7_CTS_Pin);

		/* UART7 interrupt Deinit */
		HAL_NVIC_DisableIRQ(UART7_IRQn);
		/* USER CODE BEGIN UART7_MspDeInit 1 */

		/* USER CODE END UART7_MspDeInit 1 */
	} else if (uartHandle->Instance == UART8)      {
		/* USER CODE BEGIN UART8_MspDeInit 0 */

		/* USER CODE END UART8_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_UART8_CLK_DISABLE();

		/**UART8 GPIO Configuration
		 * PD14     ------> UART8_CTS
		 * PD15     ------> UART8_RTS
		 * PE0     ------> UART8_RX
		 * PE1     ------> UART8_TX
		 */
		HAL_GPIO_DeInit(GPIOD, GPRS_CTS_Pin | GPRS_RTS_Pin);

		HAL_GPIO_DeInit(GPIOE, GPRS_RX_Pin | GPRS_TX_Pin);

		/* UART8 interrupt Deinit */
		HAL_NVIC_DisableIRQ(UART8_IRQn);
		/* USER CODE BEGIN UART8_MspDeInit 1 */

		/* USER CODE END UART8_MspDeInit 1 */
	} else if (uartHandle->Instance == USART1)      {
		/* USER CODE BEGIN USART1_MspDeInit 0 */

		/* USER CODE END USART1_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_USART1_CLK_DISABLE();

		/**USART1 GPIO Configuration
		 * PA9     ------> USART1_TX
		 */
		HAL_GPIO_DeInit(USART1_TX_S1_GPIO_Port, USART1_TX_S1_Pin);

		/* USART1 interrupt Deinit */
		HAL_NVIC_DisableIRQ(USART1_IRQn);
		/* USER CODE BEGIN USART1_MspDeInit 1 */

		/* USER CODE END USART1_MspDeInit 1 */
	} else if (uartHandle->Instance == USART2)      {
		/* USER CODE BEGIN USART2_MspDeInit 0 */

		/* USER CODE END USART2_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_USART2_CLK_DISABLE();

		/**USART2 GPIO Configuration
		 * PA2     ------> USART2_TX
		 */
		HAL_GPIO_DeInit(USART2_TX_S5_GPIO_Port, USART2_TX_S5_Pin);

		/* USART2 interrupt Deinit */
		HAL_NVIC_DisableIRQ(USART2_IRQn);
		/* USER CODE BEGIN USART2_MspDeInit 1 */

		/* USER CODE END USART2_MspDeInit 1 */
	} else if (uartHandle->Instance == USART3)      {
		/* USER CODE BEGIN USART3_MspDeInit 0 */

		/* USER CODE END USART3_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_USART3_CLK_DISABLE();

		/**USART3 GPIO Configuration
		 * PB10     ------> USART3_TX
		 */
		HAL_GPIO_DeInit(USART3_TX_S4_GPIO_Port, USART3_TX_S4_Pin);

		/* USART3 interrupt Deinit */
		HAL_NVIC_DisableIRQ(USART3_IRQn);
		/* USER CODE BEGIN USART3_MspDeInit 1 */

		/* USER CODE END USART3_MspDeInit 1 */
	} else if (uartHandle->Instance == USART6)      {
		/* USER CODE BEGIN USART6_MspDeInit 0 */

		/* USER CODE END USART6_MspDeInit 0 */
		/* Peripheral clock disable */
		__HAL_RCC_USART6_CLK_DISABLE();

		/**USART6 GPIO Configuration
		 * PC6     ------> USART6_TX
		 */
		HAL_GPIO_DeInit(USART6_TX_S2_GPIO_Port, USART6_TX_S2_Pin);

		/* USART6 interrupt Deinit */
		HAL_NVIC_DisableIRQ(USART6_IRQn);
		/* USER CODE BEGIN USART6_MspDeInit 1 */

		/* USER CODE END USART6_MspDeInit 1 */
	}
} /* HAL_UART_MspDeInit */

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
