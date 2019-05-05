/*
 * 2017-09-18
 * 盛耀微科技
 * wxj@glinkwin.com
 */
#ifndef __JZUART_HH__
#define __JZUART_HH__

#include "typedef.h"
#include "stm32f7xx.h"

#define ReqNameByAT	"AT+NAME?\r"
#define ResNameByAT	"+NAME:JdWuTuo\r\n\r\nOK\r\n\r\n"

typedef struct {
	GPIO_TypeDef *gp;
	uint32_t pin;
	uint32_t alt;
}GPIO_PIN_T;

typedef struct {
	GPIO_PIN_T tx;
	GPIO_PIN_T rx;
}UART_PIN_T;




EXPORT_API void * jz_uart_init_ex(int usart_no);
EXPORT_API void jz_uart_close_ex(void *fd);
EXPORT_API int jz_uart_write_ex(void *fd, u8 * buffer, int lens,uint32_t ulTimeout/*millisec*/);
EXPORT_API int jz_uart_read_ex(void *fd, u8 * buffer, int lens,uint32_t ulTimeout/*millisec*/);
int uart_gpio_init(USART_TypeDef *inst);
int uart_gpio_deinit(USART_TypeDef *inst);

#endif
