#include "uart.h"
#include "utils.h"

#include "jd_os_middleware.h"
#include "stm32f7xx_hal.h"

#include "uart_comm.h"

typedef struct {
	volatile uint32_t	head;
	volatile uint32_t	tail;
	volatile uint32_t	len;
	u8 ring_buf[LLC_PACK_SZ_MAX];
}RingBuf;

RingBuf uart_ringbuf[UART_COM_MAX];

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart6;

extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart4;

volatile uint8_t uart_ch[UART_COM_MAX];


osMutexDef(uart_rx_mtx);
osMutexId uart_rx_mtx_id;


UART_SWITCH_T uart_mutx_map[UART_COM_MAX] = {
	{
		.uart_hdl = &huart3,
		.inst = USART3,
		.irq = USART3_IRQn,
		.com_id = UART_COM_3_4,
		.chn_cnt = 2,
		.active_id = -1,
		.chn_info = {
			{
				.chn = CHNL3,
				.gpio = {
					.gp = GPIOD,
					.pin = GPIO_PIN_8,
					.alt = GPIO_AF7_USART3,
				},
			},
			{
				.chn = CHNL4,
				.gpio = {
					.gp = GPIOB,
					.pin = GPIO_PIN_10,
					.alt = GPIO_AF7_USART3,
				},
			}
		},
	},

	{
		.uart_hdl = &huart2,
		.inst = USART2,
		.irq = USART2_IRQn,
		.com_id = UART_COM_5_7,
		.chn_cnt = 2,
		.active_id = -1,
		.chn_info = {
			{
				.chn = CHNL5,
				.gpio = {
					.gp = GPIOA,
					.pin = GPIO_PIN_2,
					.alt = GPIO_AF7_USART2,
				},
			},
			{
				.chn = CHNL7,
				.gpio = {
					.gp = GPIOD,
					.pin = GPIO_PIN_5,
					.alt = GPIO_AF7_USART2,
				},
			}
		},
	},

	{
		.uart_hdl = &huart4,
		.inst = UART4,
		.irq = UART4_IRQn,
		.com_id = UART_COM_6_8,
		.chn_cnt = 2,
		.active_id = -1,
		.chn_info = {
			{
				.chn = CHNL6,
				.gpio = {
					.gp = GPIOA,
					.pin = GPIO_PIN_0,
					.alt = GPIO_AF8_UART4,

				},
			},
			{
				.chn = CHNL8,
				.gpio = {
					.gp = GPIOC,
					.pin = GPIO_PIN_10,
					.alt = GPIO_AF8_UART4,
				},
			}
		},
	},

	{
		.uart_hdl = &huart1,
		.inst = USART1,
		.irq = USART1_IRQn,
		.com_id = UART_COM_1,
		.chn_cnt = 1,
		.active_id = -1,
		.chn_info = {
			{
				.chn = CHNL1,
				.gpio = {
					.gp = GPIOA,
					.pin = GPIO_PIN_9,
					.alt = GPIO_AF7_USART1,

				},
			},
		}
	},

	{
		.uart_hdl = &huart6,
		.inst = USART6,
		.irq = USART6_IRQn,
		.com_id = UART_COM_2,
		.chn_cnt = 1,
		.active_id = -1,
		.chn_info = {
			{
				.chn = CHNL2,
				.gpio = {
					.gp = GPIOC,
					.pin = GPIO_PIN_6,
					.alt = GPIO_AF8_USART6,

				},
			},
		}
	}

};

void init_ringbuf(RingBuf *rbuf)
{
	memset(rbuf, 0,  sizeof(RingBuf));
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

	for (int i = 0; i < UART_COM_MAX; i++) {
		if (usart_no == uart_mutx_map[i].com_id) {
			UART_HandleTypeDef *uart_hdl = uart_mutx_map[i].uart_hdl;
			uart_config(uart_hdl, uart_mutx_map[i].inst);
			if (HAL_HalfDuplex_Init(uart_hdl) != HAL_OK) {
				debug("uart %d init error\r\n", usart_no);
				return NULL;
			} else {
				init_ringbuf(&uart_ringbuf[usart_no]);
				HAL_UART_Receive_IT(uart_hdl, (uint8_t *)&uart_ch[usart_no], 1);
				return uart_hdl;
			}
		}
	}

	return NULL;
}

void jz_uart_close_ex(void *fd)
{
	debug("%s >>>>>\r\n", __func__);
	HAL_UART_DeInit(fd);
}

int jz_uart_write_ex(void *fd, u8 *buffer, int lens, uint32_t ulTimeout /*millisec*/)
{
	int ret = 0;

	if (lens <=  0)
		return 0;

	UART_HandleTypeDef *hdl = (UART_HandleTypeDef *)fd;

	HAL_HalfDuplex_EnableTransmitter(hdl);
	HAL_UART_Transmit(fd, buffer, lens, ulTimeout);
	ret = lens - hdl->TxXferCount;
	HAL_HalfDuplex_EnableReceiver(hdl);

	for (int i = 0; i < UART_COM_MAX; i++) {
		if (hdl == uart_mutx_map[i].uart_hdl) {
			UART_COM_ENUM com_id = uart_mutx_map[i].com_id;
			HAL_UART_Receive_IT(hdl, (uint8_t *)&uart_ch[com_id], 1);
			break;
		}
	}

	return ret;

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
	for (int i = 0; i < UART_COM_MAX; i++) {
		if (UartHandle->Instance == uart_mutx_map[i].inst) {
			UART_COM_ENUM com_id = uart_mutx_map[i].com_id;
			write_ringbuf(&uart_ringbuf[com_id], uart_ch[com_id]);
			HAL_UART_Receive_IT(UartHandle, (uint8_t *)&uart_ch[com_id], 1);
			return;
		}
	}
}



int jz_uart_read_ex(void *fd, u8 *buffer, int lens, uint32_t ulTimeout /*millisec*/)
{
	uint32_t timeout = 0;
	uint32_t r = 0;
	uint32_t olen = 0;
	RingBuf *rb = 0;
	uint32_t d = 1;

	if (NULL == fd)
		return 0;

	UART_HandleTypeDef *hdl = (UART_HandleTypeDef *)fd;

	for (int i = 0; i < UART_COM_MAX; i++) {
		if (hdl == uart_mutx_map[i].uart_hdl) {
			UART_COM_ENUM com_id = uart_mutx_map[i].com_id;
			rb = &uart_ringbuf[com_id];
			break;
		}
	}

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

}


int get_uart_pin(USART_TypeDef *inst, GPIO_PIN_T *pin)
{

	for (int i = 0; i < UART_COM_MAX; i++) {
		if (inst == uart_mutx_map[i].inst) {

			int active_id = uart_mutx_map[i].active_id;
			if (active_id >= 0) {
				memcpy(pin, &uart_mutx_map[i].chn_info[active_id].gpio, sizeof(GPIO_PIN_T));
				return 0;
			}
		}
	}

	return -1;
}


int uart_gpio_init(USART_TypeDef *inst)
{
	GPIO_PIN_T pin;
	memset(&pin, 0, sizeof(GPIO_PIN_T));
	int ret = get_uart_pin(inst, &pin);

	if (ret == 0) {
		GPIO_InitTypeDef GPIO_InitStruct = { 0 };
		GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
		GPIO_InitStruct.Pull = GPIO_PULLUP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
		GPIO_InitStruct.Pin = pin.pin;
		GPIO_InitStruct.Alternate = pin.alt;
		HAL_GPIO_Init(pin.gp, &GPIO_InitStruct);

		for (int i = 0; i < UART_COM_MAX; i++) {
			if (inst == uart_mutx_map[i].inst) {
				HAL_NVIC_SetPriority(uart_mutx_map[i].irq, 5, 0);
				HAL_NVIC_EnableIRQ(uart_mutx_map[i].irq);
			}
		}
	}

	return ret;

}

int uart_gpio_deinit(USART_TypeDef *inst)
{
	GPIO_PIN_T pin;
	memset(&pin, 0, sizeof(GPIO_PIN_T));
	int ret = get_uart_pin(inst, &pin);
	if (ret == 0) {
		HAL_GPIO_DeInit(pin.gp, pin.pin);
	}

	return ret;

}
