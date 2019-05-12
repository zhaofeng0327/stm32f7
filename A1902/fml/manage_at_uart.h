
#ifndef __MANAGE_AT_UART_H
#define __MANAGE_AT_UART_H

#include "stm32f7xx.h"

#define UART_RECV_BUF_LEN	512

typedef struct 
{
    unsigned short rx_in;
    unsigned short rx_out;
    unsigned short rx_len;
    char rx_buf[UART_RECV_BUF_LEN];
} uart_t;

void rx_fifo_in(uart_t *p, uint8_t data);  
void at_uart_fifo_clr(void);
unsigned short at_uart_send_data(unsigned char *data_buff,unsigned short data_len);
unsigned int at_uart_recv(unsigned char *pdata, unsigned int len, unsigned int timeout, unsigned char *perro);

#endif


