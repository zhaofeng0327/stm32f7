#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "fml_manage_hw.h" 
#define GPRS_PWR_ON 	HAL_GPIO_WritePin(GPRS_PWR_EN_GPIO_PORT, GPRS_PWR_EN_PIN, GPIO_PIN_RESET);
#define GPRS_PWR_OFF HAL_GPIO_WritePin(GPRS_PWR_EN_GPIO_PORT, GPRS_PWR_EN_PIN, GPIO_PIN_SET);

void init_gprs_gpio(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	
	/*Configure GPIO pins : PBPin PBPin PBPin PBPin
	 *                   PBPin PBPin PBPin */
	GPIO_InitStruct.Pin = GPRS_PWR_EN_PIN | GPRS_RESET_PIN | GPRS_PWRKEY_PIN;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
	
	/*Configure GPIO pin Output Level */
	HAL_GPIO_WritePin(GPIOB,GPRS_PWR_EN_PIN | GPRS_RESET_PIN | GPRS_PWRKEY_PIN, GPIO_PIN_RESET);
}


void init_id_gpio(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	
	/*Configure GPIO pins : PEPin PEPin PEPin */
	GPIO_InitStruct.Pin  = BOARD_ID1_PIN | BOARD_ID2_PIN | BOARD_ID3_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
}



