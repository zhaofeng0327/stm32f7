#ifndef __MANAGE_AT_CMD_H__
#define __MANAGE_AT_CMD_H__

#include <stdbool.h>

#define UART_BUF_LEN 512			//FML层串口接收数据的大小
#define GPRS_FRAME_SIZE 512

#define WAITE_50MS (50) 		// ms
#define WAITE_100MS (100) // ms
#define WAITE_500MS (500) // ms
#define WAITE_1S (1000) 		// ms
#define WAITE_2S (2000) 		// ms


#define UART_RESND_DELAY_TIME (1) // s
#define UART_RESND_TIMES (20) // 重新发送次数
#define UART_READ_TIMES (1) // 从uart读取返回值的重试次数

#define UART_SEND_TIMES 5//(360)  //发送数据从uart读返回的次数
#define CMD_LEN (256)


//AT命令集
#define AT_CMD_SGV "AT+GSV\r" // 查询详细模块内软件版本号
#define AT_CMD_ATI "ATI\r" // 查询模块软件版本
#define AT_CMD_CIPSTATUS "AT+CIPSTATUS\r"


#define AT_CMD_AT   "AT\r\n"
#define AT_CMD_ATE0 "ATE0\r\n" // 关闭回显模式
#define AT_CMD_CPIN  "AT+CPIN?\r\n"		// 查询SIM卡是否READY
#define AT_CMD_CSQ   "AT+CSQ\r\n" 		// 查询信号强度
#define AT_CMD_CGREG "AT+CGREG?\r\n"	// 查询注册状态
#define AT_CMD_CGATT "AT+CGATT?\r\n"	// 查询附着分离
#define AT_CMD_CIICR "AT+CIICR\r\n"		// 建立ppp连接(激活移动场景)
#define AT_CMD_CIFSR "AT+CIFSR\r\n" 	// 查询IP地址
#define AT_CMD_CSTT	 "AT+CSTT="			// 设置APN,用户名,密码
#define AT_CMD_CIPSHUT "AT+CIPSHUT\r\n" // 关闭移动场景
#define AT_CMD_CIPMUX "AT+CIPMUX"	//启用多IP连接


#define AT_CMD_CCID  "AT+CCID\r\n" 		// 查询SIM卡ccid值

//MQTT
#define	AT_CMD_MCONFIG 	"AT+MCONFIG="		//设置相关参数	
#define	AT_CMD_MIPSTART "AT+MIPSTART="		//建立TCP连接
#define	AT_CMD_MCONNECT	"AT+MCONNECT="		//请求会话连接
#define	AT_CMD_MSUB		"AT+MSUB="			//订阅主题
#define	AT_CMD_MPUB 	"AT+MPUB="			//发布消息
#define	AT_CMD_MQTTMSGGET "AT+MQTTMSGGET\r\n"	//接收所有订阅消息
#define	AT_CMD_MQTTSTATU "AT+MQTTSTATU\r\n" 	//查询MQTT查询状态
#define	AT_CMD_MDISCONNECT "AT+MQTTSTATU\r\n"	//关闭MQTT连接
#define	AT_CMD_MIPCLOSE	   "AT+MIPCLOSE\r\n"	//关闭TCP连接
#define AT_CMD_MQTTMSGSET "AT+MQTTMSGSET=" //设置MQTT接收消息模式
	
//HTTP/HTTPS
#define AT_CMD_HTTPINIT 		"AT+HTTPINIT\r\n" 			//初始化HTTP服务
#define AT_CMD_HTTPTERM			"AT+HTTPTERM\r\n"			//终止HTTP任务
#define AT_CMD_HTTPPARA 		"AT+HTTPPARA=" 				//设置HTTP参数值
#define AT_CMD_HTTPACTION "AT+HTTPACTION=" 					//HTTP方式激活
#define AT_CMD_HHTTPDATA		"AT+HTTPDATA="				//写数据
#define AT_CMD_HTTPREAD			"AT+HTTPREAD="				//查询HTTP服务响应
#define AT_CMD_HTTPREAD_ALL			"AT+HTTPREAD\r\n"		//一次性读取HTTP 服务器返回数据
#define AT_CMD_HTTPREAD_A "AT+HTTPREAD\r\n"
#define AT_CMD_SAPBR 			"AT+SAPBR=" 				//设置HTTP功能的承载类型

//定位与时间
#define AT_CMD_NTPM 					"AT%NTPM="			//查询连接小区信息
#define AT_CMD_AMGSMLOC        "AT+AMGSMLOC="				//获取基站定位（LBS）位置和日期时间
#define AT_CMD_CNTPCID					"AT+CNTPCID="		//设置 GPRS 承载场景 ID
#define AT_CMD_CNTP						"AT+CNTP\r\n"		//同步网络时间
#define AT_CMD_CCLK						"AT+CCLK?\r\n"		//获取时间


//解释字符串返回,定义字符串,
//普通AT返回
#define AT_CMDR_OK "OK"
#define AT_CMDR_ERR "ERROR"

//MQTT
#define AT_CMDR_CONN_OK 		"CONNECT OK"	//TCP CONNET
#define AT_CMDR_CONN_ALREADY 	"ALREADY CONNECT"
#define AT_CMDR_CONN_FAIL 		"CONNECT FAIL"
#define AT_CMDR_MCONN_OK   		"CONNACK OK"
#define AT_CMDR_MPUB_OK			"PUBACK"
#define AT_CMDR_MSUB_OK			"SUBACK"

//HTTP
#define AT_CMDR_HTTP_ACTION "+HTTPACTION:"


typedef enum _TCP_CONN_STATUS
{
	TCP_CONN_OK=0,
	TCP_CONN_ALREADY=1,
	TCP_CONN_FAIL=2,
}TCP_CONN_STATUS;

typedef enum _MQTT_CONN_STATUS
{
	MQTT_CONN_OFF=0,
	MQTT_CONN_OK=1,
	MQTT_CONN_DOING=2,
}MQTT_CONN_STATUS;

typedef enum _AT_RESULT
{
	errOK = 0,
	errAtCmd = -1,		//AT命令参数有错误
	errBuffPara = -1,
	errRvcData=-2,		//AT返回数据解释错误
	errNotAnyData = -3,	//AT无返回数据错误
	errTimeOut = -4,
	
	errGprsModule = -5,	//AT
	errSIMCard = -6,	//CPIN
	errCardCcid = -30,	//CCID
	errCSQ = -7,		//CSQ
	errModuleReg = -8,	//CGREG
	errAttach = -9,		//CGATT
	errPPP = -10, 		//CIICR
	errSetAPN = -11,	//CSTT
	errIpFailed = -12,	//CIFSR
	

	//MQTT
	errMQTTSetCfg = -13,		//MCONFIG
	errMQTTTCPConnect = -14, 	//MIPSTART
	errMQTTConnect = -15,		//MCONNECT
	errMQTTPub = -16, 			//MPUB
	errMQTTSub	= -17,			//MSUB
	errMQTTGetStatu = -18, 		//查询MQTT查询状态
	errMQTTGetMsg 	= -19,		//MQTTMSGGET
	errMQTTDisConect = -20,		//MDISCONNECT
	errMQTTTCPClose	 = -21, 	//MIPCLOSE 关闭TCP连接	
	errMQTTSetMsg = -21,	//设置MQTT接收消息模式

	//HTTP	
	errCIPShut = -22,		//关闭移动场景
	errHttpInit = -23,
	errHttpTerm = -24,
	errHttpPara = -25,
	errHttpAction = -26,
	errHttpData = -27,
	errHttpRead = -28,	
	errSapbr = -29,

	//时间与定位信息
	errNTPM = -30,	//查询连接小区信息
	errAMGSMLOC = -31  ,	//获取基站定位（LBS）位置和日期时间
	errCNTP = -32,//同步网络时间
	errCNTPCID	 = -33,	//设置 GPRS 承载场景 ID	
	errCCLK = -34,			//获取时间
}AT_RESULT;

typedef enum _AT_CMD_LIST 
{
	LIST_CMD_AT,	
	LIST_CMD_ATE0,	//关闭回显模式
	LIST_CMD_CPIN,	//查询SIM卡是否READY
	LIST_CMD_CSQ,	//查询信号强度
	LIST_CMD_CGREG,	//查询注册状态
	LIST_CMD_CGATT, //查询附着分离
	LIST_CMD_CIICR, //建立ppp连接(激活移动场景)
	LIST_CMD_CIFSR,	//查询IP地址
	LIST_CMD_CSTT,	//设置APN,用户名,密码
	LIST_CMD_CCID,   //查询SIM卡ccid值
	LIST_CMD_CIPSHUT, //关闭移动场景

	LIST_CMD_IMEI,
	LIST_CMD_ICCID,
	LIST_CMD_IMSI,
	LIST_CMD_GMM,

	LIST_CMD_CFUN0,
	LIST_CMD_CFUN1,
	LIST_CMD_CFUN11,

	LIST_CMD_QENG,
	LIST_CMD_QENG11,
	LIST_CMD_SERVINGCELL,
	LIST_CMD_AT_NEIGHBOURCELL,

	
	//MQTT
	LIST_CMD_MCONFIG,	//设置相关参数	
	LIST_CMD_MIPSTART,	//建立TCP连接
	LIST_CMD_MCONNECT,	//请求会话连接
	LIST_CMD_MSUB,		//订阅主题
	LIST_CMD_MPUB,		//发布消息
	LIST_CMD_MQTTSTATU, //查询MQTT查询状态
	LIST_CMD_MQTTMSGGET,//接收所有订阅消息
	LIST_CMD_MDISCONNECT,//关闭MQTT连接
	LIST_CMD_MIPCLOSE,	 //关闭TCP连接
	LIST_CMD_MQTTMSGSET, //设置MQTT接收消息模式
	
	//HTTP/HTTPS
	LIST_CMD_HTTPINIT,			//初始化HTTP服务
	LIST_CMD_HTTPTERM,			//终止HTTP任务
	LIST_CMD_HTTPPARA, 			//设置HTTP参数值
	LIST_CMD_HTTPACTION, 		//HTTP方式激活
	LIST_CMD_HHTTPDATA,			//写数据
	LIST_CMD_HTTPREAD,			//查询HTTP服务响应
	LIST_CMD_SAPBR, 			//设置HTTP功能的承载类型
	LIST_CMD_REQ_SAPBR,			//查询HTTP功能的承载类型

	//定位信息与时间
	LIST_CMD_NTPM, 			//查询连接小区信息
	LIST_CMD_AMGSMLOC, 		//获取基站定位（LBS）位置和日期时间
	LIST_CMD_CNTP,			//同步网络时间
	LIST_CMD_CNTPCID,		//设置 GPRS承载场景ID
	LIST_CMD_CCLK,			//获取时间
} AT_CMD_LIST;


typedef struct _rssi_data_t 
{
	int rssi;
	int biterror;
}rssi_data_t;

typedef struct _mqtt_msg_t
{
	int len;
	char *msg_buf;
}mqtt_msg_t;

typedef struct _http_action_result_t
{
	unsigned char method;
    unsigned int status_code;
	unsigned int data_len;
}http_action_result_t;


typedef struct _http_sapbr_t
{
	unsigned char cid;
	unsigned char status;
	char ip[32];
	char paramtag[16];
}http_sapbr_t;


AT_RESULT manage_at_cmd(AT_CMD_LIST list_cmd, char * in_cmd_data,char *out_data, unsigned int* out_len);
unsigned int recieve_at_command(char *rcvbuf, unsigned int buflen, unsigned int waittime,unsigned char* err);
bool memncmp(const char *mem1, const char *mem2, unsigned int mem1_len, unsigned int mem2_len);
#endif
