#include "uart.h"
#include "utils.h"

#include "jd_os_middleware.h"
#include "stm32f7xx_hal.h"

#include "stm32f746xx.h"
#include "event_groups.h"

UART_HandleTypeDef huart2;
SemaphoreHandle_t sem_uart2;

//#define USE_HAL_UART_REGISTER_CALLBACKS 1
uint8_t uart2_ch;
//uint8_t uart2_buf[LLC_PACK_SZ_MAX];//LLC_PACK_SZ_MAX
//uint32_t uart2_cnt;
EventGroupHandle_t EventUart2RxHdl;
#define UART2_RX_BIT 1
QueueHandle_t uart2_rx_queue;

typedef struct {
	uint32_t head;
	uint32_t tail;
	uint32_t len;
	u8 ring_buf[LLC_PACK_SZ_MAX];
}RingBuf;

RingBuf uart2_ringbuf;

void init_ringbuf()
{
	memset(&uart2_ringbuf, 0,  sizeof(RingBuf));
}

int write_ringbuf(u8 data)
{
	if(uart2_ringbuf.len >= LLC_PACK_SZ_MAX) //判断缓冲区是否已满
	{
		return 0;
	}
	uart2_ringbuf.ring_buf[uart2_ringbuf.tail++]=data;
	uart2_ringbuf.tail = (uart2_ringbuf.tail)%LLC_PACK_SZ_MAX;//防止越界非法访问
	uart2_ringbuf.len++;
	return 1;
}

void * jz_uart_init_ex(int usart_no)
{
	if (usart_no == 2) {
		debug("%s >>>>>\r\n",__func__);

		huart2.Instance = USART2;
		huart2.Init.BaudRate = 115200;
		huart2.Init.WordLength = UART_WORDLENGTH_8B;
		huart2.Init.StopBits = UART_STOPBITS_1;
		huart2.Init.Parity = UART_PARITY_NONE;
		huart2.Init.Mode = UART_MODE_TX_RX;
		huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
		huart2.Init.OverSampling = UART_OVERSAMPLING_16;
		huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
		huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
		//huart2.RxCpltCallback = HAL_UART_RxCpltCallback;
		sem_uart2 = xSemaphoreCreateBinary();
		//xSemaphoreGive(sem_uart2);

		if (HAL_UART_Init(&huart2) != HAL_OK) {
			//Error_Handler();
                      debug("uart2 init error\r\n");
		} else {
			//HAL_UART_Receive_IT(&huart2, uart2_buf. LLC_PACK_SZ_MAX);
			//huart2.RxCpltCallback = uart2_rx_callback;
			//huart2.RxISR = uart2_rx_callback;
			//huart2.TxISR = uart2_tx_callback;
			EventUart2RxHdl = xEventGroupCreate();
			//uart2_rx_queue = xQueueCreate(100, 4);
			//if (uart2_rx_queue)
			//	printf("create uart2 rx queue\r\n");
			//CLEAR_BIT(huart2.Instance->CR1, USART_CR1_UE_Pos);
			//SET_BIT(huart2.Instance->CR3, USART_CR3_OVRDIS_Pos);
			//__HAL_UART_ENABLE_IT(&huart2, UART_IT_TC);

			init_ringbuf();
			__HAL_UART_ENABLE_IT(&huart2, UART_IT_RXNE);

			HAL_UART_Receive_IT(&huart2, (uint8_t *)&uart2_ch, 1);
			//HAL_UART_Receive_IT(&huart2, (uint8_t *)&uart2_buf, LLC_PACK_SZ_MAX);
			//HAL_UART_Receive_IT(&huart2, (uint8_t *)uart2_buf, 5);
			return &huart2;
		}
	}

	return NULL;
}

void jz_uart_close_ex(void *fd)
{
	debug("%s >>>>>\r\n",__func__);
	HAL_UART_DeInit(&huart2);
}

int jz_uart_write_ex(void *fd, u8 * buffer, int lens,uint32_t ulTimeout/*millisec*/)
{
	int ret = 0;
	if (lens <=  0)
		return 0;
	HAL_UART_Transmit(&huart2, buffer, lens, ulTimeout);
	ret = lens - huart2.TxXferCount;
	//debug("%s lens %d>>>>>\r\n", __func__, lens);
	//dump_buffer(buffer, ret);
	return ret;
#if 0
	int retval = kStatus_Fail;
	/* Send introduction message. */
	//debug("\r\n%s:send start,buf_len=%d,buffer=%s.\r\n",__func__,lens,buffer);
	retval = USART_RTOS_Send((usart_rtos_handle_t *)fd, (uint8_t *)buffer, lens,ulTimeout);
	//debug("\r\n%s:send end.\r\n",__func__);
	if (kStatus_Success != retval)
	{
		//vTaskSuspend(NULL);
	}

	// dump_buffer(buffer, ret);

	return (retval==kStatus_Success)?lens:(-1);
#endif

}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *UartHandle)
{
	//BaseType_t xHigherPriorityTaskWoken;
	if (UartHandle->Instance == USART2) {
		//xSemaphoreTakeFromISR(sem_uart2, &xHigherPriorityTaskWoken);
		write_ringbuf(uart2_ch);
		HAL_UART_Receive_IT(UartHandle, (uint8_t *)&uart2_ch, 1);
		//xSemaphoreGiveFromISR(sem_uart2, &xHigherPriorityTaskWoken);
		//printf("0x%02x\r\n", uart2_ch);
		//portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
	}
}

#if 0
		xSemaphoreTakeFromISR(sem_uart2, &xHigherPriorityTaskWoken);
		uart2_buf[uart2_cnt++] = uart2_ch;
		uart2_cnt = uart2_cnt%LLC_PACK_SZ_MAX;
		HAL_UART_Receive_IT(UartHandle, (uint8_t *)&uart2_ch, 1);
		xSemaphoreGiveFromISR(sem_uart2, &xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken);

		//printf("-\r\n");
		HAL_UART_Receive_IT(UartHandle, (uint8_t *)&uart2_ch, 1);

		printf("0x%02x\r\n", uart2_ch);
		xQueueSendFromISR(uart2_rx_queue, &uart2_ch, &xHigherPriorityTaskWoken);
		portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
		printf("+\r\n");


#endif



int jz_uart_read_ex(void *fd, u8 * buffer, int lens,uint32_t ulTimeout/*millisec*/)
{
	//uint32_t cnt = 0;
	uint32_t timeout = 0;
	uint32_t r;
	uint32_t olen = 0;
	timeout = 0;


	while (1) {
		if (uart2_ringbuf.len == olen) {
			vTaskDelay(1);
			if (timeout++ > 10) {
				timeout = 0;

				if (olen) {
					r = lens > uart2_ringbuf.len ? uart2_ringbuf.len : lens;
					memcpy(buffer, uart2_ringbuf.ring_buf + uart2_ringbuf.head, r);
					uart2_ringbuf.head = (uart2_ringbuf.head + r) % LLC_PACK_SZ_MAX;
					uart2_ringbuf.len -= r;
					return r;
				}
			}
		} else {
			olen = uart2_ringbuf.len;
			timeout = 0;
		}
	}

}

#if 0
	while (uart2_ringbuf.len == 0)
		vTaskDelay(1);


	do {
//		xSemaphoreTake(sem_uart2, portMAX_DELAY);

		if (lens - cnt > uart2_ringbuf.len)
			r = uart2_ringbuf.len;
		else
			r = lens - cnt;

		memcpy(buffer, uart2_ringbuf.ring_buf + uart2_ringbuf.head, r);
		uart2_ringbuf.head = (uart2_ringbuf.head + r) % LLC_PACK_SZ_MAX;
		buffer += r;
		cnt += r;
		uart2_ringbuf.len -= r;
		//xSemaphoreGive(sem_uart2);

		timeout = 0;
		while (uart2_ringbuf.len == 0) {
			vTaskDelay(10);
			if (timeout++ > 10)
				return cnt;
		}

	} while(1);

int cnt = 0;
printf("%s %d %d\r\n", __func__, __LINE__, uxQueueMessagesWaiting(uart2_rx_queue));
do {
	if (true == xQueueReceive(uart2_rx_queue, buffer, 100)) {
		break;
	} else {
		vTaskDelay(10);
	}
} while (1);
printf("%s %d %d\r\n", __func__, __LINE__, uxQueueMessagesWaiting(uart2_rx_queue));

cnt++;
do {
	if (pdFALSE == xQueueReceive(uart2_rx_queue, buffer, 100)) {
		break;
	} else {
		buffer++;
		cnt++;
	}
} while (1);
printf("%s %d %d\r\n", __func__, __LINE__, uxQueueMessagesWaiting(uart2_rx_queue));

return cnt;


void uart2_rx_callback(UART_HandleTypeDef *huart)
{
	uint16_t uhMask = huart2.Mask;
	uint16_t  uhdata;
	uint8_t data;

	uhdata = (uint16_t) READ_REG(huart2.Instance->RDR);
	data = (uint8_t)(uhdata & (uint8_t)uhMask);
	debug("recv data %02x\r\n", data);
	__HAL_UART_SEND_REQ(&huart2, UART_RXDATA_FLUSH_REQUEST);


	BaseType_t xHigherPriorityTaskWoken;
	BaseType_t ret;
	if (huart->Instance == USART2) {
		//printf("uart2 recv data\r\n");
		if (EventUart2RxHdl) {
			ret = xEventGroupSetBitsFromISR(EventUart2RxHdl, UART2_RX_BIT, &xHigherPriorityTaskWoken);
			if (ret != pdTRUE)
				portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
		}
	}

}


int uart2_wait_ack(int timeout)
{
	EventBits_t bits;
	bits = xEventGroupWaitBits(EventUart2RxHdl, (EventBits_t)UART2_RX_BIT, (BaseType_t)pdTRUE, (BaseType_t)pdTRUE, timeout);

	if (bits & UART2_RX_BIT)
		return 1;
	else
		return 0;
}

int uart2_rx_ack()
{
	xEventGroupSetBits(EventUart2RxHdl, UART2_RX_BIT);
}

void uart2_tx_callback(UART_HandleTypeDef * huart)
{
	printf("tx cb\r\n");
}

#endif

#if 0
void uart2_handle()
{
	u32 timeout = 0;
	u32 maxDelay = 0x1FFFF;
	BaseType_t xHigherPriorityTaskWoken;

	while (HAL_UART_GetState(&huart2) != HAL_UART_STATE_READY) {
		if (timeout++ > maxDelay)
			break;
	}

	timeout = 0;
	while (HAL_UART_Receive_IT(&huart2,(uint8_t *)&uart2_buf, LLC_PACK_SZ_MAX) != HAL_OK) {
		if (timeout++ > maxDelay)
			break;
	}

	dump_buffer(uart2_buf, LLC_PACK_SZ_MAX - huart2.RxXferCount);

	//xSemaphoreGiveFromISR(sem_uart2, &xHigherPriorityTaskWoken);
	//portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}


#endif



#if 0
	int len = 0;
	HAL_StatusTypeDef  ret;

	//SET_BIT(huart2.Instance->ICR, USART_ICR_NCF_Pos);
	ret = HAL_UART_Receive(&huart2, buffer, lens, ulTimeout);
	len = lens - huart2.RxXferCount;
	if (HAL_IS_BIT_SET(huart2.Instance->ISR, USART_ISR_ORE_Pos))
		SET_BIT(huart2.Instance->ICR, USART_ICR_ORECF_Pos);

	printf("%s ret %d len %d ISR 0x%x\r\n", __func__, ret, len, huart2.Instance->ISR);
	return len;
#endif
#if 0
	if(HAL_UART_Receive_IT(&huart2, (uint8_t *)uart2_buf, lens) != HAL_OK) {
		/* Transfer error in reception process */
		Error_Handler();
	}

	while (HAL_UART_GetState(&huart2) != HAL_UART_STATE_READY) {// && ulTimeout-
		//vTaskDelay(1);
	}

	if (len > 0) {
		len = lens - huart2.RxXferCount;
		memcpy(buffer, huart2.pRxBuffPtr, len);
		huart2.RxXferCount = 0;
		huart2.pRxBuffPtr = uart2_buf;
	}
	return len;
#endif
#if 0
	HAL_StatusTypeDef ret = 0;
	EventBits_t bits;
	uint16_t uhMask = huart2.Mask;
	uint16_t  uhdata;
	uint8_t data;
	if (lens <=  0)
		return 0;

	bits = xEventGroupWaitBits(EventUart2RxHdl, (EventBits_t)UART2_RX_BIT, (BaseType_t)pdTRUE, (BaseType_t)pdTRUE, ulTimeout);

	//printf("recv bits 0x%x -----------\r\n", bits);

	//memcpy(buffer, &huart2.pRxBuffPtr, );
	//ret = HAL_UART_Receive(&huart2, buffer, lens, 100);
	uhdata = (uint16_t) READ_REG(huart2.Instance->RDR);
	data = (uint8_t)(uhdata & (uint8_t)uhMask);
	debug("recv data %02x\r\n", data);
	__HAL_UART_SEND_REQ(&huart2, UART_RXDATA_FLUSH_REQUEST);
	//debug("read ret %d len %d\r\n", ret, lens - huart2.RxXferCount);

	xEventGroupClearBits(EventUart2RxHdl, UART2_RX_BIT);
	return lens - huart2.RxXferCount;
#endif

#if 0
	size_t ret=0;
	int error;
	//debug("%s:recv start,buf_len=%d\r\n",__func__,lens);
	error = USART_RTOS_Receive((usart_rtos_handle_t *)fd, buffer, lens, &ret,ulTimeout);
	if (error == kStatus_USART_RxRingBufferOverrun)
	{
		/* Notify about hardware buffer overrun */
	#if 0
		if (kStatus_Success !=
			USART_RTOS_Send((usart_rtos_handle_t *)fd, (uint8_t *)send_buffer_overrun, strlen(send_buffer_overrun),ulTimeout))
		{
			vTaskSuspend(NULL);
		}
	#endif
	}

	if(ret > 0){
		//debug("\r\n%s:[len=%d,buffer=%s]\r\n",__func__,(int)ret,(char *)buffer);
	}

	return (int)ret;

	return 0;
}
#endif


/*-----------------------------EOF-----------------------------------*/

