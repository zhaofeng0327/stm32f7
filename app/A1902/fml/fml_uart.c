#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_uart.h"
#include "usart.h"
#include "fml_uart.h"
#include "fml_log.h"

#define LOG_TAG "UART"

char rxChar = '\0';

// UART_HandleTypeDef huart5;  // debug
char uart5_rx_str[128] = {0};
int uart5_rcv_cnt = 0;

// UART_HandleTypeDef huart8;  // gprs
char uart8_rx_str[128] = {0};
int uart8_rcv_cnt = 0;


// 串口接收完成中断处理
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
    if (UartHandle->Instance == UART5) {
        uart5_rx_str[uart5_rcv_cnt++] = rxChar;
        if (rxChar == 0x0d /* \r */) {
            uart5_rcv_cnt = 0;
            flog_d("UART5: %s\n", uart5_rx_str);
            // To do
            // add to cmd pthread for debug
            memset(uart5_rx_str, 0, 128);
        }
    } else if (UartHandle->Instance == UART8) {
        uart8_rx_str[uart8_rcv_cnt++] = rxChar;
        if (uart8_rcv_cnt == 34 /* \r */) {
            uart8_rcv_cnt = 0;
            flog_d("UART8: %s\n", uart8_rx_str);
            // To do
            // add to cmd pthread for debug
            memset(uart8_rx_str, 0, 128);
        }
    }
    HAL_UART_Receive_IT(UartHandle, (uint8_t *)&rxChar, 1);
}

void fml_log_uart_init(void)
{
    MX_UART5_Init();
    HAL_UART_Receive_IT(&huart5,(uint8_t *)&rxChar,1);
}

void fml_gprs_uart_init(void)
{
    MX_UART8_Init();
    HAL_UART_Receive_IT(&huart8,(uint8_t *)&rxChar,1);
}
