#ifndef __UART_COMM_H__
#define __UART_COMM_H__

#include "jd_os_middleware.h"
#include "battery_protocal.h"

typedef enum {
	TYPE_INVALID = 0,
	TYPE_REQ,
	TYPE_RES,
} CMD_TYPE_T;


typedef struct {
	unsigned char version[4];
	char file_path[MAX_FILE_PATH_SIZE];
	char type;		//文件类型：升级文件为0，广告排期配置文件为1，图片为2.
	int file_handle;
	unsigned long size;
	unsigned long aes_padding_len;
	unsigned char md5[MD5_SIZE];
	unsigned int packet_id;
	unsigned long offset;
	char result;
}RECV_FILE_DES;


typedef struct {
	JD_OM_QUEUE	send_queue;			//for task send message communication.
	JD_OM_QUEUE	recv_queue;			//for uart internal message exchange.
	JD_OM_MUTEX mutex_active_req;
	JD_OM_MUTEX mutex_active_res;
	JD_OM_THREAD	thread_handle_send;
	JD_OM_THREAD	thread_handle_recv;
	JD_OM_THREAD	thread_uart_recv[UART_COM_MAX];
}UART_COMM_DES_T;


#define WAIT_RESPONSE_TIME_OUT (6000)


#define BAT_EVT_SET_SN			1
#define BAT_EVT_GET_INFO		2
#define BAT_EVT_ENCODE			3
#define BAT_EVT_DECODE			4
#define BAT_EVT_VIRT_PWR_INFO	5
#define BAT_EVT_DISCHG_LEVEL	6
#define BAT_EVT_CHARGE_STAT		7
#define BAT_EVT_PROT_VERS		8
#define BAT_EVT_PSW_CHKSUM		9

extern RES_BAT_SET_SN_PSW_T br_set_sn;
extern RES_BAT_GET_INFO_T br_get_info;
extern RES_BAT_DECODE_T br_decode;
extern RES_BAT_ENCODE_T br_encode;
extern RES_BAT_VIRTUAL_PWR_T br_virt_info;
extern RES_BAT_DISCHARGE_LEVEL_T br_dis_level;
extern RES_BAT_CHARGE_STATUS_T br_chg_stat;
extern RES_BAT_PROTOCAL_VERSION_T br_pro_vers;
extern RES_BAT_PASSWD_CHKSUM_T br_psw_chk;

extern UART_COMM_DES_T uart_comm_des;



int start_uart_service(void);
void uart_recv_queue_task(void const *p);
void uart_send_queue_task(void const *p);
void uart_recv_task(void const *p);
void uart_task(void const *p);
int uart_sent_dumb(void);


u8 get_packet_id(void);
int wait_battery_response(EventBits_t bat_evt, TickType_t timeout);
int get_uart_channel(void);

#endif
