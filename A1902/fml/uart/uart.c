#include "uart.h"
#include "utils.h"

#include "jd_os_middleware.h"
#include "stm32f7xx_hal.h"

#include "uart_comm.h"

typedef struct {
	volatile uint32_t	head;
	volatile uint32_t	tail;
	volatile uint32_t	len;
	u8		ring_buf[LLC_PACK_SZ_MAX];
}RingBuf;

RingBuf uart2_ringbuf;
RingBuf uart4_ringbuf;
RingBuf uart6_ringbuf;

extern UART_HandleTypeDef huart2;
//extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart6;

volatile uint8_t uart2_ch;
volatile uint8_t uart4_ch;
volatile uint8_t uart6_ch;

osMutexDef(uart_rx_mtx);
osMutexId uart_rx_mtx_id;

UART_PIN_T uart2_chn0_pin = {
	.tx = {
		.gp = GPIOD,
		.pin = GPIO_PIN_5,
		.alt = GPIO_AF7_USART2,
	},
	.rx = {
		.gp = GPIOA,
		.pin = GPIO_PIN_3,
		.alt = GPIO_AF7_USART2,
	},
};


UART_PIN_T uart2_chn2_pin = {
	.tx = {
		.gp = GPIOA,
		.pin = GPIO_PIN_2,
		.alt = GPIO_AF7_USART2,
	},
	.rx = {
		.gp = GPIOD,
		.pin = GPIO_PIN_6,
		.alt = GPIO_AF7_USART2,
	},
};

void init_ringbuf(RingBuf *rbuf)
{
	memset(rbuf, 0, sizeof(RingBuf));
}

int write_ringbuf(RingBuf *rbuf, u8 data)
{
	if (rbuf->len >= LLC_PACK_SZ_MAX) //判断缓冲区是否已满
		return 0;
	rbuf->ring_buf[rbuf->tail++] = data;
	rbuf->tail = (rbuf->tail) % LLC_PACK_SZ_MAX;//防止越界非法访问
	rbuf->len++;
	return 1;
}

void uart_config(UART_HandleTypeDef *hdl, USART_TypeDef *num)
{
	hdl->Instance = num;
	hdl->Init.BaudRate = 115200;
	hdl->Init.WordLength = UART_WORDLENGTH_8B;
	hdl->Init.StopBits = UART_STOPBITS_1;
	hdl->Init.Parity = UART_PARITY_NONE;
	hdl->Init.Mode = UART_MODE_TX_RX;
	hdl->Init.HwFlowCtl = UART_HWCONTROL_NONE;
	hdl->Init.OverSampling = UART_OVERSAMPLING_16;
	hdl->Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
	hdl->AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
}

void *jz_uart_init_ex(int usart_no)
{
	debug("%s %d>>>>>\r\n", __func__, usart_no);

	if (usart_no == 2) {
		uart_config(&huart2, USART2);
		if (HAL_UART_Init(&huart2) != HAL_OK) {
			debug("uart2 init error\r\n");
			return NULL;
		} else {
			init_ringbuf(&uart2_ringbuf);
			HAL_UART_Receive_IT(&huart2, (uint8_t *)&uart2_ch, 1);
			return &huart2;
		}
	}
/*
 *      else if (4 == usart_no) {
 *
 *              uart_config(&huart4, UART4);
 *              if (HAL_HalfDuplex_Init(&huart4) != HAL_OK) {
 *                      debug("uart4 init error\r\n");
 *                      return NULL;
 *              } else {
 *                      init_ringbuf(&uart4_ringbuf);
 *                      HAL_UART_Receive_IT(&huart4, (uint8_t *)&uart4_ch, 1);
 *                      return &huart4;
 *              }
 *      }
 */

     else if (6 == usart_no) {
             uart_config(&huart6, USART6);
             if (HAL_UART_Init(&huart6) != HAL_OK) {
                     debug("uart6 init error\r\n");
                     return NULL;
             } else {
                     init_ringbuf(&uart6_ringbuf);
                     HAL_UART_Receive_IT(&huart6, (uint8_t *)&uart6_ch, 1);
                     return &huart6;
             }
     }

	return NULL;
}

void jz_uart_close_ex(void *fd)
{
	debug("%s >>>>>\r\n", __func__);
	HAL_UART_DeInit(fd);
/*
	UART_HandleTypeDef *hdl = (UART_HandleTypeDef *)fd;
	USART_TypeDef *ins = hdl->Instance;
	if (USART2 == ins)
		init_ringbuf(&uart2_ringbuf);
*/
}

int jz_uart_write_ex(void *fd, u8 *buffer, int lens, uint32_t ulTimeout /*millisec*/)
{
	int ret = 0;

	if (lens <= 0)
		return 0;

	UART_HandleTypeDef *hdl = (UART_HandleTypeDef *)fd;
	USART_TypeDef *ins = hdl->Instance;

	if (UART4 == ins)
		HAL_HalfDuplex_EnableTransmitter(hdl);

	HAL_UART_Transmit(fd, buffer, lens, ulTimeout);
	ret = lens - hdl->TxXferCount;

	if (USART2 == ins) {
		//HAL_UART_Receive_IT(hdl, (uint8_t *)&uart2_ch, 1);
	} else if (UART4 == ins) {
		HAL_HalfDuplex_EnableReceiver(hdl);
		HAL_UART_Receive_IT(hdl, (uint8_t *)&uart4_ch, 1);
	} else if (USART6 == ins) {
		HAL_UART_Receive_IT(hdl, (uint8_t *)&uart6_ch, 1);
	}
	return ret;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
	if (USART2 == UartHandle->Instance) {
		write_ringbuf(&uart2_ringbuf, uart2_ch);
		HAL_UART_Receive_IT(UartHandle, (uint8_t *)&uart2_ch, 1);
	} else if (UART4 == UartHandle->Instance) {
		write_ringbuf(&uart4_ringbuf, uart4_ch);
		HAL_UART_Receive_IT(UartHandle, (uint8_t *)&uart4_ch, 1);
	} else if (USART6 == UartHandle->Instance) {
		write_ringbuf(&uart6_ringbuf, uart6_ch);
		HAL_UART_Receive_IT(UartHandle, (uint8_t *)&uart6_ch, 1);
	}
}



int jz_uart_read_ex(void *fd, u8 *buffer, int lens, uint32_t ulTimeout /*millisec*/)
{
	uint32_t timeout = 0;
	uint32_t r = 0;
	uint32_t olen = 0;
	RingBuf *rb = 0;
	uint32_t d = 5;

	if (NULL == fd)
		return 0;

	UART_HandleTypeDef *hdl = (UART_HandleTypeDef *)fd;
	USART_TypeDef *ins = hdl->Instance;

	if (USART2 == ins) {
		rb = &uart2_ringbuf;
		d = 1;
	} else if (UART4 == ins) {
		rb = &uart4_ringbuf;
		d = 1;
	} else if (USART6 == ins) {
		rb = &uart6_ringbuf;
		d = 2;
	} else {
		return 0;
	}

#if 0

	while (1) {

		if (rb->ring_buf[rb->tail-1] == 0xa5) {
			r = lens > rb->len ? rb->len : lens;
			memcpy(buffer, rb->ring_buf + rb->head, r);
			rb->head = (rb->head + r) % LLC_PACK_SZ_MAX;
			rb->len -= r;
			return r;
		}

	}

#else
	while (1) {
		if (rb->len == olen) {
			jd_om_msleep(d);
			if (timeout++ > 2) {
				timeout = 0;

				if (olen) {
					r = lens > olen ? olen : lens;
					if (rb->head < rb->tail) {
						memcpy(buffer, rb->ring_buf + rb->head, r);
					} else {
						int len1 = LLC_PACK_SZ_MAX - rb->head;
						memcpy(buffer, rb->ring_buf + rb->head, len1);
						memcpy(buffer + len1, rb->ring_buf, r - len1);
					}

					//for(int i = 0 ;i < r; i++)
					//	buffer[i] = rb->ring_buf[rb->head+i];
					rb->head = (rb->head + r) % LLC_PACK_SZ_MAX;
					rb->len -= r;
					return r;
				}
				//else {
					//return 0;
				//}
			}
		} else {
			olen = rb->len;
			timeout = 0;
		}
	}
#endif
}


void get_uart_pin(USART_TypeDef *inst, UART_PIN_T *pin)
{
	if (USART2 == inst) {

		switch (get_uart_channel()) {
		case 0:
			memcpy(pin, &uart2_chn0_pin, sizeof(UART_PIN_T));
			break;
		case 2:
			memcpy(pin, &uart2_chn2_pin, sizeof(UART_PIN_T));
			break;
		default:
			break;
		}

	}
}
int uart_gpio_init(USART_TypeDef *inst)
{
	int num = get_uart_channel();

	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	UART_PIN_T pin;

	get_uart_pin(inst, &pin);

	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Pin = pin.tx.pin;
	GPIO_InitStruct.Alternate = pin.tx.alt;
	HAL_GPIO_Init(pin.tx.gp, &GPIO_InitStruct);

	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Pin = pin.rx.pin;
	GPIO_InitStruct.Alternate = pin.rx.alt;
	HAL_GPIO_Init(pin.rx.gp, &GPIO_InitStruct);


	return 0;
}

int uart_gpio_deinit(USART_TypeDef *inst)
{
	UART_PIN_T pin;

	get_uart_pin(inst, &pin);

	HAL_GPIO_DeInit(pin.tx.gp, pin.tx.pin);
	HAL_GPIO_DeInit(pin.rx.gp, pin.rx.pin);

	return 0;
/*
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Pin = pin.tx.pin;

	HAL_GPIO_Init(pin.tx.gp, &GPIO_InitStruct);

	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	GPIO_InitStruct.Pin = pin.rx.pin;

	HAL_GPIO_Init(pin.rx.gp, &GPIO_InitStruct);

*/
}
