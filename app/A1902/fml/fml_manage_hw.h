#ifndef __FML_MANAGE_HW_H__
#define __FML_MANAGE_HW_H__

#include "stm32f7xx_hal.h"


#define GPRS_PWR_EN_PIN              GPIO_PIN_7
#define GPRS_PWR_EN_GPIO_PORT        GPIOB
#define GPRS_RESET_PIN               GPIO_PIN_8
#define GPRS_RESET_GPIO_PORT         GPIOB
#define GPRS_PWRKEY_PIN              GPIO_PIN_9
#define GPRS_PWRKEY_GPIO_PORT        GPIOB


#define BOARD_ID1_PIN           	GPIO_PIN_3
#define BOARD_ID1_GPIO_PORT		    GPIOE
#define BOARD_ID2_PIN     		    GPIO_PIN_4
#define BOARD_ID2_GPIO_PORT			GPIOE
#define BOARD_ID3_PIN           	GPIO_PIN_5
#define BOARD_ID3_GPIO_PORT		    GPIOE


#endif
