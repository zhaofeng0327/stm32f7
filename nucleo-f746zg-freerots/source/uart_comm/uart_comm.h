/************************************************************
Copyright (C), 2017, Tech. Co., Ltd.
FileName: uart_comm.h
Description:
History:
***********************************************************/

#ifndef __UART_COMM_H__
#define __UART_COMM_H__

#include "jd_os_middleware.h"
#include "protocal.h"

int start_uart_service();
void uart_recv_queue_task(void const *p);
void uart_send_queue_task(void const *p);
void uart_recv_task(void const *p);
void uart_task(void const *p);
int uart_sent_dumb();
void test_bat_protoc();


bool jd_master_com_get_dev_sn(unsigned char *sn);


#endif
