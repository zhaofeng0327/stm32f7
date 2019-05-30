#ifndef __PROTOCAL_H__
#define __PROTOCAL_H__
#include "typedef.h"

#define START_CMD						0xFF	//协议首字�?

#define REQ_DEVICE_INFO					0xD0	//柜机信息读取
#define REQ_SET_SN						0xD1	//柜机SN写入
#define REQ_GET_TIME					0xD2	//RTC时间读取
#define REQ_SET_TIME					0xD3	//RTC时间设置
#define REQ_FLASH_LED					0xD4	//FLASH LED 测试
#define REQ_SLOT_LED					0xD5	//卡槽LED 测试
#define REQ_SLOT_ELOCK					0xD6	//卡槽电磁阀测试
#define REQ_SLOT_POWER					0xD7	//卡槽电源开关测�?
#define REQ_SLOT_KEY_STAT				0xD8	//卡槽仓底开关状态读�?
#define REQ_BATTERY_ENCRYPT				0xD9	//电池加解密测�?
#define REQ_BATTERY_INFO				0xDA	//电池信息读取
#define REQ_GPRS_MODULE_INFO			0xDB	//2G/4G模块信息读取
#define REQ_GPRS_CONNECT				0xDC	//2G/4G模块gprs测试
#define REQ_DEVICE_AGEING				0xDD	//老化测试
#define REQ_ENV_TEMPRATURE				0xDE	//环境温度测试


#define RES_DEVICE_INFO					0xB0	//柜机信息读取
#define RES_SET_SN						0xB1	//柜机SN写入
#define RES_GET_TIME					0xB2	//RTC时间读取
#define RES_SET_TIME					0xB3	//RTC时间设置
#define RES_FLASH_LED					0xB4	//FLASH LED 测试
#define RES_SLOT_LED					0xB5	//卡槽LED 测试
#define RES_SLOT_ELOCK					0xB6	//卡槽电磁阀测试
#define RES_SLOT_POWER					0xB7	//卡槽电源开关测�?
#define RES_SLOT_KEY_STAT				0xB8	//卡槽仓底开关状态读�?
#define RES_BATTERY_ENCRYPT				0xB9	//电池加解密测�?
#define RES_BATTERY_INFO				0xBA	//电池信息读取
#define RES_GPRS_MODULE_INFO			0xBB	//2G/4G模块信息读取
#define RES_GPRS_CONNECT				0xBC	//2G/4G模块gprs测试
#define RES_DEVICE_AGEING				0xBD	//老化测试
#define RES_ENV_TEMPRATURE				0xBE	//环境温度测试

#define REQ_TRANS_FILE_HEAD				0xF0	//柜机派发文件
#define REQ_TRANS_FILE_DATA				0xF1	//柜机派发文件
#define REQ_TRANS_FILE_END				0xF2	//柜机派发文件
#define RES_TRANS_FILE_HEAD				0xE0	//柜机派发文件
#define RES_TRANS_FILE_DATA				0xE1	//柜机派发文件
#define RES_TRANS_FILE_END				0xE2	//柜机派发文件



#define REQ_BAT_SET_SN_PSW				0xC0
#define REQ_BAT_GET_INFO				0xC1
#define REQ_BAT_DECODE					0xC2
#define REQ_BAT_ENCODE					0xC3
#define REQ_BAT_VIRTUAL_PWR_INFO		0xC4
#define REQ_BAT_DISCHARGE_LEVEL			0xC5
#define REQ_BAT_CHARGE_STATUS			0xC6
#define REQ_BAT_PROTOCAL_VERSION		0xC7
#define REQ_BAT_PASSWD_CHKSUM			0xC8

#define RES_BAT_SET_SN_PSW				0xA0
#define RES_BAT_GET_INFO				0xA1
#define RES_BAT_DECODE					0xA2
#define RES_BAT_ENCODE					0xA3
#define RES_BAT_VIRTUAL_PWR_INFO		0xA4
#define RES_BAT_DISCHARGE_LEVEL			0xA5
#define RES_BAT_CHARGE_STATUS			0xA6
#define RES_BAT_PROTOCAL_VERSION		0xA7
#define RES_BAT_PASSWD_CHKSUM			0xA8


#define MAX_QUEUE_SIZE					(128)
#define MAX_QUEUE_ELEMENT_SIZE			(1024)
#define CHECKSUM_SIZE					(2)

#define MAX_FILE_PATH_SIZE				(128)
#define MD5_SIZE						(16)

#define DEVICE_ID_LEN (32+4)	// such as "1e6a6be3-7a58-43f6-9d51-29906a34de19"

#define STRUCT_PACKED __attribute__((packed))

typedef enum {
	SLAVE_1 = 1,
	SLAVE_2,
	SLAVE_3,
	SLAVE_4,
	SLAVE_5,
	SLAVE_6,
	SLAVE_7,
	SLAVE_8,
	SLAVE_9,
}SLAVE_ENUM;

typedef enum {
	upgrade_file = 0,
}FileType;

//协议�?
typedef struct {
	unsigned char start;
	unsigned char slave;
	unsigned char type;
	unsigned char packet_id;
	unsigned int payload_len;
}STRUCT_PACKED MSG_UART_HEAD_T;

//协议数据�?
typedef struct {
	MSG_UART_HEAD_T head;
	void *		payload;
	unsigned char		checksum[CHECKSUM_SIZE];
}STRUCT_PACKED MSG_UART_PACKAGE_T;


typedef struct{
	u8 code;
	u8 sn[16];
	u8 sn_md5[16];
	u8 cpuid[12];
	u8 cpuid_md5[16];
	u8 fw_ver[4];
	u8 hw_ver[4];
	u8 Encrypted;
}STRUCT_PACKED RES_DEVICE_INFO_T;

typedef struct{
	u8 sn_len;
	u8 sn[16];
	u8 sn_md5[16];
}STRUCT_PACKED REQ_SET_SN_T;

typedef struct{
	u8 code;
}STRUCT_PACKED RES_SET_SN_T;


typedef struct{
	u8 code;
	u32 time_sec;
	u32 time_usec;
}STRUCT_PACKED RES_GET_TIME_T;

typedef struct{
	u32 time_sec;
	u32 time_usec;
}STRUCT_PACKED REQ_SET_TIME_T;

typedef struct{
	u8 code;
}STRUCT_PACKED RES_SET_TIME_T;

typedef struct{
	u8 led_status;//  0 �?灯灭.�?1 �?灯亮�? 2 �?闪烁
}STRUCT_PACKED REQ_SET_FLASH_LED_T;

typedef struct{
	u8 code;
}STRUCT_PACKED RES_SET_FLASH_LED_T;


typedef struct{
	u8 slot_num;//卡槽�?
	u8 led_status;//  0 �?灯灭.�?1 �?灯亮�? 2 �?闪烁
}STRUCT_PACKED REQ_SET_SLOT_LED_T;

typedef struct{
	u8 code;
}STRUCT_PACKED RES_SET_SLOT_LED_T;


typedef struct{
	u8 slot_num;//卡槽�?
	u8 elock_status;//1 �?开锁，  0 �?上锁
	u32 keep_time;//备注 �?电磁阀打开保持时间 默认�?
}STRUCT_PACKED REQ_SET_SLOT_ELOCK_T;

typedef struct{
	u8 code;//响应代码：ok �?，fail�?
}STRUCT_PACKED RES_SET_SLOT_ELOCK_T;


typedef struct{
	u8 slot_num;//卡槽�?
	u8 power_status; //1 �?打开�? 0 �?关闭
}STRUCT_PACKED REQ_SET_SLOT_POWER_T;

typedef struct{
	u8 code;//响应代码：ok �?，fail�?
}STRUCT_PACKED RES_SET_SLOT_POWER_T;

typedef struct{
	u8 slot_num;
}STRUCT_PACKED REQ_GET_SLOT_KEY_T;

typedef struct{
	u8 code;
	u8 key_status;//0：下压，1: 弹起
}STRUCT_PACKED RES_GET_SLOT_KEY_T;


typedef struct{
	u8 slot_num;
	u8 opt;//0: 加密 1:解密
	u8 psw_len; //密码长度
	u8 psw[32];	//解密密码
}STRUCT_PACKED REQ_BATTERY_ENCRYPT_T;

typedef struct{
	u8 code;
}STRUCT_PACKED RES_BATTERY_ENCRYPT_T;


typedef struct{
	u8 slot_num;
	u8 opt;//0: 加密 1:解密
}STRUCT_PACKED REQ_BATTERY_INFO_T;

typedef struct{
	u8 code;
	u8 sn[16];
	int temperature;//温度
	int voltage;	//电压
	int ratio;		//电量百分�?
}STRUCT_PACKED RES_BATTERY_INFO_T;


typedef struct{
	char code;	//响应代码：ok �?，fail�?
	char module_name[16]; //模块�?
	char Iccid[32]; //iccid
	char module_ready;//模块是否正常
	char simcard_ready;//sim卡是否正�?
	char gprs_ready;	//gprs 是否正常
	char rssi;		//rssi
}STRUCT_PACKED RES_GPRS_MODULE_INFO_T;


typedef struct{
	u8 opt;		//0：断开 gprs ,1 : 连接gprs
}STRUCT_PACKED REQ_GPRS_CONNECT_T;
typedef struct {
	u8 code;	//响应代码：ok �?，fail�?
}STRUCT_PACKED RES_GPRS_CONNECT_T;

typedef struct __Payload
{
	u8 opt;		//0: 停止 1：开�?
	u8 slot_list[8];	//老化卡槽列表, 值为1老化 �?值为0不老化
	u32 time_sec;	//老化时间
}STRUCT_PACKED REQ_AGEING_T;
typedef struct{
	u8 code;
}STRUCT_PACKED RES_AGEING_T;

typedef struct{
	u8 code;
	int  temperature;		//温度
}STRUCT_PACKED RES_TEMPRATURE_T;

typedef struct{
	u8 code;
}STRUCT_PACKED RES_COMMON_T;

/*********************REQ_TRANS_FILE_HEAD/RES_TRANS_FILE_HEAD***********************/
typedef struct{
	char type;		//�ļ����ͣ������ļ�Ϊ0��������������ļ�Ϊ1��ͼƬΪ2.
	char file_name[64];		//�ļ�����
	unsigned int size;		//�ļ���С
	char md5[MD5_SIZE];		//�ļ�md5У����
}STRUCT_PACKED REQ_TRANS_FILE_HEAD_T;

typedef struct{
	char code;		//��Ӧ���룺ok Ϊ0��failΪ1.
}STRUCT_PACKED RES_TRANS_FILE_HEAD_T;

/*********************REQ_TRANS_FILE_DATA/RES_TRANS_FILE_DATA***********************/
typedef struct{
	unsigned int packet_id;	//�ļ���Ƭid.
	char *data;		//����
}STRUCT_PACKED REQ_TRANS_FILE_DATA_T;

typedef struct{
	char code;		//��Ӧ���룺ok Ϊ0��failΪ1.
	unsigned int packet_id;	//�ļ���Ƭid.
}STRUCT_PACKED RES_TRANS_FILE_DATA_T;

/*********************REQ_TRANS_FILE_END/RES_TRANS_FILE_END***********************/
typedef struct{
	char code;		//��Ӧ���룺ok Ϊ0��failΪ1.
}STRUCT_PACKED RES_TRANS_FILE_END_T;

typedef struct {
	unsigned char sn_len;		//sn有效长度
	unsigned char sn[32];		// sn.
	unsigned char passwd_len;		// password长度
	unsigned char passwd[32];		// password
}STRUCT_PACKED  REQ_BAT_SET_SN_PSW_T;

typedef struct {
	unsigned char code;
}STRUCT_PACKED  RES_BAT_SET_SN_PSW_T;

typedef struct {
	unsigned char opt;			//0: 加密电池 1:不加密电�?
}STRUCT_PACKED  REQ_BAT_GET_INFO_T;

typedef struct {
	char code;					//响应代码：ok �?，fail�?
	unsigned char sn_len;		//sn 有效长度
	unsigned char sn[32];		//sn
	unsigned char Temp;			//温度: 16进制温度值（单位：摄氏度�?偏移�?40(避免负温�?
	unsigned char Vol_H;		//电压：高�?
	unsigned char Vol_L;		//电压：低�?
	unsigned char ratio;		//16进制电量百分�?RC/FCC)值：5,10,20,30,40,50,60,70,80,90,100.
}STRUCT_PACKED RES_BAT_GET_INFO_T;

typedef struct {
	unsigned char passwd_len;		//password长度
	unsigned char passwd[32];		// password.
}STRUCT_PACKED REQ_BAT_DECODE_T;
typedef struct {
	unsigned char code;
}STRUCT_PACKED RES_BAT_DECODE_T;


typedef struct {
	unsigned char code;
}STRUCT_PACKED RES_BAT_ENCODE_T;

typedef struct {
	unsigned char data[5];	// data[0]表示放电虚电情况一的次数；
							//data[1]表示放电虚电情况二的次数�?
							//data[2]表示剩余电量百分比；
							//data[3]表示持续放电时间，单位为分钟�?
							//data[4]值为0x01时，表示已经连接负载并且正在放电，值为0x00时，表示断开负载.
}STRUCT_PACKED RES_BAT_VIRTUAL_PWR_T;

typedef struct {
	unsigned char data [4];		/*data[0]表示设置放电电流的档位，0x01代表设置为虚电放电电流（比如�?.0A�?0x00代表设置为电池默认电流放电（正常放电电流�?.8A）；
data[1],data[2],data[3]为保留字�? 默认data[1],data[2]值为0x00.*/
}STRUCT_PACKED REQ_BAT_DISCHARGE_LEVEL_T;
typedef struct {
	unsigned char code;
}STRUCT_PACKED RES_BAT_DISCHARGE_LEVEL_T;

typedef struct {
	unsigned char data [4];		/* data[0]�?x00表示电池处于正常电流放电档位（默认为1.8A），�?x01代表为此电池为虚电放电档位（比如�?.0A）；
data[1]�?x00表示电池当前处于不充电不放电状态，�?x01代表电池当前为充电状态，�?x02代表为放电状态；
data[2],data[3]为保留字节，默认值为0x00,以便未来扩展功能.*/
}STRUCT_PACKED RES_BAT_CHARGE_STATUS_T;

typedef struct {
	unsigned char ver_len;	// 协议版本长度
	unsigned char ver[32];	// 协议版本�?
}STRUCT_PACKED RES_BAT_PROTOCAL_VERSION_T;

typedef struct {
	unsigned char crc[2];
}STRUCT_PACKED RES_BAT_PASSWD_CHKSUM_T;


#endif
