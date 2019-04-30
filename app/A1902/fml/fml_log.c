#include <stdbool.h>
#include "stm32f7xx_hal.h"
#include "stm32f7xx_hal_uart.h"
#include "usart.h"
#include "fml_log.h"
#include "fml_uart.h"

#define LOG_TAG "LOG"

#define DBG

log_upload_cb log_upload = NULL;
extern UART_HandleTypeDef huart5;

#define LOG_USARTx_CLK_ENABLE() __HAL_RCC_UART5_CLK_ENABLE()
#define LOG_USARTx_CLK_DISABLE() __HAL_RCC_UART5_CLK_DISABLE()
#define LOG_USARTx_RX_GPIO_CLK_ENABLE() __HAL_RCC_GPIOD_CLK_ENABLE() 
#define LOG_USARTx_TX_GPIO_CLK_ENABLE() __HAL_RCC_GPIOC_CLK_ENABLE()
#define LOG_USARTx_FORCE_RESET() __HAL_RCC_USART5_FORCE_RESET()
#define LOG_USARTx_RELEASE_RESET() __HAL_RCC_USART5_RELEASE_RESET()


#ifdef __GNUC__
/* With GCC, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

void fml_log_init(log_upload_cb cb)
{
    if (cb != NULL) {
        log_upload = cb;
    }
    fml_log_uart_init();

}

PUTCHAR_PROTOTYPE
{
    /* e.g. write a character to the USART5 and Loop until the end of transmission */
    HAL_UART_Transmit(&huart5, (uint8_t *)&ch, 1, 0xFFFF);
    return ch;
}
