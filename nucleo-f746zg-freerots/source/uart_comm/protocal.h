#ifndef __PROTOCAL_H__
#define __PROTOCAL_H__


#define START_CMD						0xFF	//协议首字�?

#define REQ_DEVICE_INFO					0xC0	//柜机信息读取
#define REQ_SET_SN						0xC1	//柜机SN写入
#define REQ_GET_TIME					0xC2	//RTC时间读取
#define REQ_SET_TIME					0xC3	//RTC时间设置
#define REQ_FLASH_LED					0xC4	//FLASH LED 测试
#define REQ_SLOT_LED					0xC5	//卡槽LED 测试
#define REQ_SLOT_ELOCK					0xC6	//卡槽电磁阀测试
#define REQ_SLOT_POWER					0xC7	//卡槽电源开关测�?
#define REQ_SLOT_KEY_STAT				0xC8	//卡槽仓底开关状态读�?
#define REQ_BATTERY_ENCRYPT				0xC9	//电池加解密测�?
#define REQ_BATTERY_INFO				0xCA	//电池信息读取
#define REQ_GPRS_MODULE_INFO			0xCB	//2G/4G模块信息读取
#define REQ_GPRS_CONNECT				0xCE	//2G/4G模块gprs测试
#define REQ_DEVICE_AGEING					0xCF	//老化测试
#define REQ_ENV_TEMPRATURE				0xD0	//环境温度测试


#define RES_DEVICE_INFO					0xA0	//柜机信息读取
#define RES_SET_SN						0xA1	//柜机SN写入
#define RES_GET_TIME					0xA2	//RTC时间读取
#define RES_SET_TIME					0xA3	//RTC时间设置
#define RES_FLASH_LED					0xA4	//FLASH LED 测试
#define RES_SLOT_LED					0xA5	//卡槽LED 测试
#define RES_SLOT_ELOCK					0xA6	//卡槽电磁阀测试
#define RES_SLOT_POWER					0xA7	//卡槽电源开关测�?
#define RES_SLOT_KEY_STAT				0xA8	//卡槽仓底开关状态读�?
#define RES_BATTERY_ENCRYPT				0xA9	//电池加解密测�?
#define RES_BATTERY_INFO				0xAA	//电池信息读取
#define RES_GPRS_MODULE_INFO			0xAB	//2G/4G模块信息读取
#define RES_GPRS_CONNECT				0xAE	//2G/4G模块gprs测试
#define RES_DEVICE_AGEING					0xAF	//老化测试
#define RES_ENV_TEMPRATURE				0xB0	//环境温度测试

#define REQ_TRANS_FILE_HEAD				0xD1	//柜机派发文件
#define REQ_TRANS_FILE_DATA				0xD2	//柜机派发文件
#define REQ_TRANS_FILE_END				0xD3	//柜机派发文件
#define RES_TRANS_FILE_HEAD				0xE1	//柜机派发文件
#define RES_TRANS_FILE_DATA				0xE2	//柜机派发文件
#define RES_TRANS_FILE_END				0xE3	//柜机派发文件


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
	schedule_file = 1,
	picture_file = 2,
	voice_file = 3
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
	u8 slot_num;
	u8 led_status;//  0 �?灯灭.�?1 �?灯亮�? 2 �?闪烁
}STRUCT_PACKED REQ_SET_SLOT_LED_T;

typedef struct{
	u8 code;
}STRUCT_PACKED RES_SET_SLOT_LED_T;


typedef struct{
	u8 slot_num;
	u8 elock_status;//1 �?开锁，  0 �?上锁
	u32 keep_time;
}STRUCT_PACKED REQ_SET_SLOT_ELOCK_T;

typedef struct{
	u8 code;
}STRUCT_PACKED RES_SET_SLOT_ELOCK_T;


typedef struct{
	u8 slot_num;
	u8 power_status;
}STRUCT_PACKED REQ_SET_SLOT_POWER_T;

typedef struct{
	u8 code;//1 �?打开�? 0 �?关闭
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
	u8 psw[16];	//解密密码
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
	int temperature;	//温度
	int voltage;	//电压
	int current;	//电流
	int full_cap;	//满电�?
	int rem_cap;	//剩余电量
	int charge_cnt;	//充放电次�?
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

/*************************************************
Function: crc16
Description: CRC16校验码计�?
Input:
       ptr     内容
       count   长度
Output:
Return:                CRC16校验�?
Others:
*************************************************/
unsigned short crc16(char *ptr, int count);


/*************************************************
Function: get_file_size
Description: 计算文件大小
Input:
	filename: 文件路径
Output:
Return:
	文件字节�?
Others:
*************************************************/
unsigned long get_file_size(unsigned char file_Dev,const char *filename);

bool ends_with(const char * haystack, const char * needle);

/*************************************************
Function: get_md5
Description: 计算文件md5
Input:
       ptr: 文件路径
       type�?文件
                 1 字符�?
Output:
       md5: 文件md5
Return:
       0ﺿ成�?
       <0: 失败
Others:
*************************************************/
int get_md5(unsigned char *md5, const char *ptr, int type);

#endif
