/*
 * 2017-09-18
 * 盛耀微科技
 * wxj@glinkwin.com
 */
#ifndef _UART_H__
#define _UART_H__

#include "typedef.h"
#include "stm32f7xx.h"

#define ReqNameByAT	"AT+NAME?\r"
#define ResNameByAT	"+NAME:JdWuTuo\r\n\r\nOK\r\n\r\n"




typedef struct {
	GPIO_TypeDef *gp;
	uint32_t pin;
	uint32_t alt;
}GPIO_PIN_T;

typedef enum {
	CHNL1 = 0,
	CHNL2,
	CHNL3,
	CHNL4,
	CHNL5,
	CHNL6,
	CHNL7,
	CHNL8,
	CHNL_MAX
} CHANNEL_T;

typedef enum {
	UART_COM_1 = 0,
	UART_COM_2,
	UART_COM_3_4,
	UART_COM_5_7,
	UART_COM_6_8,
	UART_COM_MAX
}UART_COM_ENUM;

typedef struct {
	CHANNEL_T chn;
	GPIO_PIN_T gpio;
} CHNL_INFO;

typedef struct {
	UART_HandleTypeDef *uart_hdl;
	USART_TypeDef * inst;
	IRQn_Type irq;
	UART_COM_ENUM com_id;
	int chn_cnt;
	int active_id;
	CHNL_INFO chn_info[2];
} UART_SWITCH_T;

EXPORT_API void * jz_uart_init_ex(int usart_no);
EXPORT_API void jz_uart_close_ex(void *fd);
EXPORT_API int jz_uart_write_ex(void *fd, u8 * buffer, int lens,uint32_t ulTimeout/*millisec*/);
EXPORT_API int jz_uart_read_ex(void *fd, u8 * buffer, int lens,uint32_t ulTimeout/*millisec*/);
int uart_gpio_init(USART_TypeDef *inst);
int uart_gpio_deinit(USART_TypeDef *inst);

#endif
