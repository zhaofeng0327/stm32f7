#include "manage_at_uart.h"

#include "stm32f7xx_hal.h"
#include "jd_os_middleware.h"
#include "fml_log.h"

uart_t at_uart = {0,0,0,};

extern UART_HandleTypeDef huart8;

void dump_buffer(unsigned char * buffer,int lens)
{
	int i = 0;
	
	for(i = 0; i < lens; i++)
	{
		if((i % 16) == 0)
			printf("\n");
		
		printf("%02x ",buffer[i]);
	}
	printf("\n");
}


// rx software fifo in,call by interrupt
 void rx_fifo_in(uart_t *p, uint8_t data)
{
    if (p->rx_len < (sizeof(p->rx_buf)/sizeof(p->rx_buf[0]))) 
    {   
        // not full yet.
        p->rx_buf[p->rx_in++] = data;
        p->rx_in %= sizeof(p->rx_buf)/sizeof(p->rx_buf[0]);
        p->rx_len++;
    }
}


//rx software fifo out
static uint8_t rx_fifo_out(uart_t *p, uint32_t timeout, uint8_t *perro)
{
	//uint32_t cpu_sr;
	uint8_t data = 0;

	if (timeout == 0) 
	{
		while(p->rx_len == 0)
		{
			//OSTimeDly(1);//需要适当处理
          jd_om_msleep(1);
		}
	} 
	else 
	{
		while (timeout != 0)
		{
			if (p->rx_len == 0) 
			{
				timeout--;
				//OSTimeDly(1);
                jd_om_msleep(1);
			} 
			else
			{
				break;
			}
		}

		if (timeout == 0) 
		{
			*perro = 1;//接收数据超时
			return 0;
		}
	}

    //OS_ENTER_CRITICAL();
    __HAL_UART_DISABLE_IT(&huart8, UART_IT_RXNE);
    if (p->rx_len != 0) 
    {
        p->rx_len--;
        data = p->rx_buf[p->rx_out++];
        p->rx_out %= sizeof(p->rx_buf)/sizeof(p->rx_buf[0]);
    }
	  __HAL_UART_ENABLE_IT(&huart8, UART_IT_RXNE);
    //OS_EXIT_CRITICAL();

    *perro = 0;
    return data;
}


void uart_fifo_clr(void)
{
    at_uart.rx_in  = 0;
    at_uart.rx_out = 0;
    at_uart.rx_len = 0;
    
	memset(at_uart.rx_buf,0,sizeof(at_uart.rx_buf));
}


#if 0
//AT UART ISR
void UART1_IRQHandler(void)
{
  char data;

  if(UART_GetITStatus(UART1, UART_IT_RXIEN) != RESET)	
  {
	  UART_ClearITPendingBit(UART1,UART_IT_RXIEN);
	  data =UART_ReceiveData(UART1);   
	  rx_fifo_in(at_uart, data);
   } 
}
#endif

unsigned short at_uart_send_data(unsigned char *data_buff,unsigned short data_len)
{
#if 0
	unsigned short i = 0;
	unsigned short temp = data_len;
	char* addr = data_buff;
	
	//硬件相关
	for(;data_len>0;data_len--,data_buff++)
	{

		while((UART1->CSR&((uint16_t)0x0001)) == 0);//UART_IT_TXIEN
		UART1->TDR = (*data_buff & (uint16_t)0x00FF); 	
		i++;
	
	}
#endif
    
	int ret = 0;
	//printf("uart send data=%s\n",data_buff);
	ret = HAL_UART_Transmit(&huart8, (uint8_t*)data_buff, data_len, 0xFFFF);
	//dump_buffer(addr,temp);
	return ret;
}

// 接收第一个字节由传入的timeout 作为超时
// 如果200ms 没有收到下一字节，则超时返回
unsigned int at_uart_recv(unsigned char *pdata, unsigned int len, unsigned int timeout, unsigned char *perro)
{
	unsigned int i = 0;
	unsigned int tmptimeout = timeout;
	
	if (0 == timeout)
	{
		timeout = 1000;//OS_TICKS_PER_SEC;//采用系统时间比较好些
	}

    while (1) 
    {
        if (len != 0) 
        {
            unsigned char data = rx_fifo_out(&at_uart, tmptimeout, perro);
            if (*perro == 0) 
            {        
                tmptimeout = 200;//OS_TICKS_PER_SEC/5;  //采用系统时间
                *pdata++ = data;   
                len--;
                i++;
            } 
            else
            {
                break;
            }
        } 
        else
        {
            break;
		}
    }

    return i;
}
