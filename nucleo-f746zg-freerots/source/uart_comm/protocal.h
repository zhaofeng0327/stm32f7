#ifndef __PROTOCAL_H__
#define __PROTOCAL_H__

#define PIC1_BUFADDR 0xa0000000
#define PIC2_BUFADDR 0xa0200000
//#define PIC_JPG_BUFADDR 0xa0400000
#define APP_ALLOCATED_HEAP_ADDR 0xa0c00000

#define FW_VER	"1.0.1"
/*
 *Set the lcd display usage
 */
//#define USE_LCD_RGB888 		//define:use RGB888	no define:RGB565

//#define TASK_DEBUG
#ifdef SPIFI_DISK_ENABLE
#define SYSDISK		SPIFIDISK
#else
#define SYSDISK		SDDISK
#endif

#if (SYSDISK==SPIFIDISK)
//switch qspi flash 16MB and 2MB
#define USE_SPIFLASH16MB	//define: use 16MB no define: use 2MB
#endif

#define MP3DISK		SPIFLASHDISK



#define UPGRADE_FILE_DIR "/upgrade"
#define SCHEDULE_FILE_DIR "/schedule"
#define PIC_FILE_DIR "/material"

#define TMP_FILE_DIR "/tmp"
#define SCHEDULE_INFO_FILE "/schedule/scheInfo.dat"

#define START_CMD						0xFF	//鍗忚棣栧瓧鑸?

#define REQ_DEVICE_INFO					0xC0	//鏌滄満璇锋眰鍧炴墭淇℃伅
#define REQ_CONFIG_PASSWORD				0xC1	//鏌滄満璇锋眰璁剧疆鍧炴墭瀵嗙爜
#define REQ_GET_TIME					0xC2	//鏌滄満璇锋眰鑾峰彇鍧炴墭鏃堕棿
#define REQ_SET_TIME					0xC3	//鏌滄満璇锋眰璁剧疆鍧炴墭鏃堕棿
#define REQ_SHOW						0xC4	//鏌滄満璇锋眰闈欐�佸浘鐗囧睍绀?
#define REQ_TRANS_FILE_HEAD				0xC5	//鏌滄満娲惧彂鏂囦欢鑷冲潪鎵樺紑濮?
#define REQ_TRANS_FILE_DATA				0xC6	//鏌滄満娲惧彂鏂囦欢鑷冲潪鎵樿繘琛屼腑
#define REQ_TRANS_FILE_END				0xC7	//鏌滄満娲惧彂鏂囦欢鑷冲潪鎵樼粨鏉?
#define REQ_NOTIFY_ALL_FILE_COMPLETED	0xC8	//all material pic transferred notify
#define REQ_SET_VOLUME					0xC9	//set volume
#define REQ_CLEAR_PASSWORD				0xCA	//clear password
#define REQ_SET_SN						0xCB	//config device sn
#define REQ_SET_DEVICE_ID				0xCC	//config device id

#define RES_DEVICE_INFO					0xA0	//鏌滄満璇锋眰鍧炴墭淇℃伅鍝嶅簲
#define RES_CONFIG_PASSWORD				0xA1	//鏌滄満璇锋眰璁剧疆鍧炴墭瀵嗙爜鍝嶅簲
#define RES_GET_TIME					0xA2	//鏌滄満璇锋眰鑾峰彇鍧炴墭鏃堕棿鍝嶅簲
#define RES_SET_TIME					0xA3	//鏌滄満璇锋眰璁剧疆鍧炴墭鏃堕棿鍝嶅簲
#define RES_SHOW						0xA4	//鏌滄満璇锋眰闈欐�佸浘鐗囧睍绀哄搷搴?
#define RES_TRANS_FILE_HEAD				0xA5	//鏌滄満娲惧彂鏂囦欢鑷冲潪鎵樺紑濮嬪搷搴?
#define RES_TRANS_FILE_DATA				0xA6	//鏌滄満娲惧彂鏂囦欢鑷冲潪鎵樿繘琛屼腑鍝嶅簲
#define RES_TRANS_FILE_END				0xA7	//鏌滄満娲惧彂鏂囦欢鑷冲潪鎵樼粨鏉熷搷搴?
#define RES_NOTIFY_ALL_FILE_COMPLETED	0xA8	//all material pic transferred notify response
#define RES_SET_VOLUME					0xA9	//set volume response
#define RES_CLEAR_PASSWORD				0xAA	//clear password response
#define RES_SET_SN						0xAB	//config device sn response
#define RES_SET_DEVICE_ID				0xAC	//config device id response

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

//鍗忚澧?
typedef struct {
	unsigned char start;
	unsigned char slave;
	unsigned char type;
	unsigned char packet_id;
	unsigned int payload_len;
}STRUCT_PACKED MSG_UART_HEAD_T;

//鍗忚鏁版嵁鍔?
typedef struct {
	MSG_UART_HEAD_T head;
	void *		payload;
	unsigned char		checksum[CHECKSUM_SIZE];
}STRUCT_PACKED MSG_UART_PACKAGE_T;

/*********************REQ_DEVICE_INFO/RES_DEVICE_INFO***********************/
typedef struct{
	unsigned short service_code;	//素材对应的业务代码.
	//picture info
	unsigned int pic_material_id;	//图片素材ID.
	char pic_md5[16];				//图片素材文件的MD5校验码，为"0"表示素材文件有误需要重新下载
	unsigned int pic_play_count;	//图片播放次数统计
	//vocie info.
	unsigned int voice_material_id; //音频素材ID.
	char voice_md5[16]; 			//音频素材文件的MD5校验码，为"0"表示素材文件不存在或有误需要重新下载
	unsigned int voice_play_count;	//音频播放次数统计
}STRUCT_PACKED AdvMaterialInfo;

typedef struct{
	unsigned int schedule_id;	//排期ID(必填)，为"0"表示没有排期文件.
	char schedule_md5[16];	//坞托当前排期配置文件MD5校验值(必填)：为"0"表示排期文件有误需要重新下载.
	unsigned int material_num;	//素材文件总数目(必填).
	//AdvMaterialInfo *material;	//素材文件信息(可选).
}STRUCT_PACKED AdvScheduleInfo;

typedef struct{
	unsigned char ready_flag;	//坞托信息是否就绪标志：  1(设备信息就绪，以下信息有效),0(设备信息未就绪，以下信息无效，柜机需要重新请求)
	char sn[16];		//坞托sn.
	char device_id[DEVICE_ID_LEN];	//坞托device id.
	unsigned char fw_ver[4];	//坞托固件版本信息.
	unsigned char hw_ver[4];	//坞托硬件版本信息.
	char Encrypted;		//坞托当前加密状态，0=未加密(文件传输使用默认密码：待定),1=加密(文件传输使用已设置密码,密码设置命令参考0xC1).
	unsigned char volume;		//坞托当前加音量(范围:0:mute,1:low,2:middle,3:high)(0表示静音)
	AdvScheduleInfo schedule;	//排期文件信息
}STRUCT_PACKED RES_DEVICE_INFO_T;

/*********************REQ_CONFIG_PASSWORD/RES_CONFIG_PASSWORD***********************/
typedef struct{
	unsigned char cipher_len;	//密码长度.
	char  cipher[32];		//密码.
}STRUCT_PACKED REQ_CONFIG_PASSWORD_T;

typedef struct{
	char code;		//响应代码：ok 为0，fail为1.
}STRUCT_PACKED RES_CONFIG_PASSWORD_T;

/*********************REQ_SET_SN/RES_SET_SN***********************/
typedef struct{
	unsigned char  sn[10];
}STRUCT_PACKED REQ_SET_SN_T;

typedef struct{
	char code;		//响应代码：ok 为0，fail为1.
}STRUCT_PACKED RES_SET_SN_T;

/*********************REQ_SET_DEVICE_ID/RES_SET_DEVICE_ID***********************/
typedef struct{
	char device_id[DEVICE_ID_LEN];
}STRUCT_PACKED REQ_SET_DEVICE_ID_T;

typedef struct{
	char code;		//响应代码：ok 为0，fail为1.
}STRUCT_PACKED RES_SET_DEVICE_ID_T;

/*********************REQ_GET_TIME/RES_GET_TIME***********************/
typedef struct{
	unsigned long int time_sec;	//UTC 时间，秒.
	unsigned long int time_usec;	//UTC 时间，微秒.
}STRUCT_PACKED RES_GET_TIME_T;

/*********************REQ_SET_TIME/RES_SET_TIME***********************/
typedef struct{
	unsigned long int time_sec;	//UTC 时间，秒.
	unsigned long int time_usec;	//UTC 时间，微秒.
}STRUCT_PACKED REQ_SET_TIME_T;

typedef struct{
	char code;		//响应代码：ok 为0，fail为1.
}STRUCT_PACKED RES_SET_TIME_T;

/*********************REQ_SET_VOLUME/RES_SET_VOLUME***********************/
typedef struct{
	unsigned char volume;	//desired volume(范围:0:mute,1:low,2:middle,3:high)(0表示静音)
}STRUCT_PACKED REQ_SET_VOLUME_T;

typedef struct{
	char code;		//响应代码：ok 为0，fail为1.
}STRUCT_PACKED RES_SET_VOLUME_T;

/*********************REQ_SHOW/RES_SHOW***********************/
typedef struct{
	unsigned short service_code;	//参考业务代码
	unsigned char keep_alive;	//展示时长，单位为秒，0XFF:永远显示; 0:按排期文件中默认值显示.
}STRUCT_PACKED REQ_SHOW_T;

typedef struct{
	char code;		//响应代码：ok 为0，fail为1.
}STRUCT_PACKED RES_SHOW_T;

typedef struct{
	char code;		//响应代码：ok 为0，fail为1.
}STRUCT_PACKED RES_NOTIFY_ALL_FILE_COMPLETED_T;

/*********************REQ_TRANS_FILE_HEAD/RES_TRANS_FILE_HEAD***********************/
typedef struct{
	char type;		//文件类型：升级文件为0，广告排期配置文件为1，图片为2.
	char file_name[64];		//文件名称
	unsigned int size;		//文件大小
	char md5[MD5_SIZE];		//文件md5校验码
}STRUCT_PACKED REQ_TRANS_FILE_HEAD_T;

typedef struct{
	char code;		//响应代码：ok 为0，fail为1.
}STRUCT_PACKED RES_TRANS_FILE_HEAD_T;

/*********************REQ_TRANS_FILE_DATA/RES_TRANS_FILE_DATA***********************/
typedef struct{
	unsigned int packet_id;	//文件分片id.
	char *data;		//数据
}STRUCT_PACKED REQ_TRANS_FILE_DATA_T;

typedef struct{
	char code;		//响应代码：ok 为0，fail为1.
	unsigned int packet_id;	//文件分片id.
}STRUCT_PACKED RES_TRANS_FILE_DATA_T;

/*********************REQ_TRANS_FILE_END/RES_TRANS_FILE_END***********************/
typedef struct{
	char code;		//响应代码：ok 为0，fail为1.
}STRUCT_PACKED RES_TRANS_FILE_END_T;

/*********************RES_CLEAR_PASSWORD***********************/
typedef struct{
	char code;		//响应代码：ok 为0，fail为1.
}STRUCT_PACKED RES_CLEAR_PASSWORD_T;

/*********************COMMON RES for exception***********************/
typedef struct{
	char code;		//响应代码：ok 为0，fail为1.
}STRUCT_PACKED RES_COMMON_T;

/*********************pic play related message queue info***********************/
typedef enum _play_service_code {
  srv_code_err = -2,
  srv_code_cooking = -1,	//pic decode in cooking
  srv_code_adv = 0,
  //battery borrow
  srv_code_borrow_start = 1,
  srv_code_borrow_success = 2,
  srv_code_borrow_fail = 3,
  srv_code_borrow_timeout = 4,
  //battery return
  srv_code_return_start = 10,
  srv_code_return_success = 11,
  srv_code_return_no_slot = 12,
  srv_code_return_timeout = 13,
  srv_code_return_unrecognized = 14,
  //host(cabinet) upgrade
  srv_code_host_upgrade_start = 20,
  srv_code_host_upgrade_going = 21,
  srv_code_host_upgrade_fail = 22,
  srv_code_host_upgrade_restart = 23,
  //battery was broken open
  srv_code_12bat1_broken_open = 30,
  srv_code_12bat2_broken_open = 31,
  srv_code_12bat3_broken_open = 32,
  srv_code_12bat4_broken_open = 33,
  srv_code_12bat5_broken_open = 34,
  srv_code_12bat6_broken_open = 35,
  srv_code_12bat7_broken_open = 36,
  srv_code_12bat8_broken_open = 37,
  srv_code_12bat9_broken_open = 38,
  srv_code_12bat10_broken_open = 39,
  srv_code_12bat11_broken_open = 40,
  srv_code_12bat12_broken_open = 41,
  srv_code_6bat1_broken_open = 42,
  srv_code_6bat2_broken_open = 43,
  srv_code_6bat3_broken_open = 44,
  srv_code_6bat4_broken_open = 45,
  srv_code_6bat5_broken_open = 46,
  srv_code_6bat6_broken_open = 47,
  //static pic play
  srv_code_default = 50,
  srv_code_connect_fail = 51,
  //smartlink connect show
  srv_code_smartlink_connect_start = 70,
  srv_code_smartlink_connectting = 71,
  srv_code_smartlink_connect_ok = 72,
  srv_code_smartlink_connect_fail = 73,
  srv_code_all_srv_background = 9999
}play_service_code;

typedef enum _voice_volume_level {
  volume_mute = 0U,   
  volume_low = 1U,
  volume_middle = 2U,
  volume_high = 3U
}voice_volume_level;

typedef struct{
	voice_volume_level level;	//the level
	unsigned char val;			//the real value:0~31.
}volume_relation;

typedef enum _key_push_indication {
  key_pushed_unknown = 0U,   
  key_pushed_vol_up = 1U,
  key_pushed_vol_down = 2U,
  key_pushed_vol = 3U,		//set desired volume
  key_pushed_mute = 4U,		//mute persistently.
  key_pushed_mute_auto = 5U	//mute volatility.
}key_push_indication;

typedef enum _pic_play_msg_type {
  pic_play_file_update_start = 0U,
  pic_play_file_update_end = 1U,
  pic_play_all_file_update_end = 2U,
  pic_play_service_code = 3U,
  pic_play_key_pushed = 4U
}pic_play_msg_type;

typedef struct{
	pic_play_msg_type type;
	union {
		struct {
			play_service_code service_code;
			unsigned char timeout;	//play timeout:second
		}info_service_code;
		struct {
			char type;		//文件类型：升级文件为0，广告排期配置文件为1，图片为2.
			char file_name[64];
			unsigned char md5[MD5_SIZE];
		}info_file;
		struct {
			bool fromIsr;
			key_push_indication value;	//key value.
			voice_volume_level volume;	//set desired volume level.
		}info_key;
		void *reserved;
	}msg;
}pic_play_msg;

/*********************player play related message queue info***********************/
typedef enum _player_play_msg_type {
  player_play_adv = 0U,				//start to play advertisement pic.
  player_play_decode_jpg = 1U,		//start to prep-decode jpeg pic.
  player_play_decode_jpg_done = 2U,	//notify decode jpeg pic finish.
  player_play_decode_clean = 3U,	//start to clean prep-decode queue.
  player_play_bg = 4U,				//notify player play the service background pic.
  player_play_srv = 5U,				//start to play service pic.
  player_play_err = 6U,				//start to play err RGB.
  player_play_pending = 7U,			//start to pending.
  player_play_detect_left_key = 8U,	//detect left key pushed.
  player_play_detect_right_key = 9U,//detect right key pushed.
  player_play_mute_start = 10U,		//display mute string.	
  player_play_mute_clear = 11U		//clear mute string.
}player_play_msg_type;

typedef struct{
	player_play_msg_type type;
	union {
		struct {
			char curr_file_path[MAX_FILE_PATH_SIZE];
			char prep_file_path[MAX_FILE_PATH_SIZE];
		}adv_play;
		char bg_file_path[MAX_FILE_PATH_SIZE];
		struct {
			char file_path[MAX_FILE_PATH_SIZE];
		}srv_play;
		struct {
			char to_decode_file[MAX_FILE_PATH_SIZE];	//file that is need to decode.
			char decoded_file[MAX_FILE_PATH_SIZE];		//file that is decoded.
			bool decoded_ok;							//flag indicate if decode successful.
		}decode_play;
		void *reserved;
	}msg;
	unsigned char res_code;		//response code(0=ok,1=fail)
}player_play_msg;

/*********************mp3 player related message queue info***********************/
typedef enum _mp3_play_msg_type {
  start_access_flash = 0U,	//NXP will take the control of mp3's flash.
  end_access_flash = 1U,	//NXP will give the control of mp3's flash.
  mp3_play_start = 2U,		//req mp3 to play a desired voice.
  mp3_play_stop = 3U,		//req mp3 to stop play.
  mp3_play_get_vol = 4U,	//req mp3 current volume.
  mp3_play_set_vol = 5U,		//req mp3 to set a desired volume.
  mp3_play_connect_status = 6U,	//inquiry mp3 player connect status with device.
  mp3_player_restart = 7U	//notify mp3 player power-on restart.
}mp3_play_msg_type;

typedef struct{
	mp3_play_msg_type type;
	union {
		struct {
			char mp3_name[64];
			unsigned char index;//voice index
			bool repeated;		// whether if repeat to play a voice?
			unsigned short repeated_timeout;	//timeout seconds to repeat play.
		}info_play;
		struct {
			unsigned char vol;	//vol level:00(mute)~0x1F(maximum)
		}info_volume;
		struct {
			unsigned char status;	//connect status.
		}info_status;
		void *reserved;
	}msg;
	unsigned char res_code;		//response code(0=ok,1=fail,0xff=timeout)
}mp3_play_msg;

#define EXAMPLE_EEPROM EEPROM
//eeprom address defination
#define EEPROM_ADDR_UPGRADE_FLAG       	0U 
#define EEPROM_ADDR_SPI_INIT_FLAG       4U
#define EEPROM_ADDR_SN_FLAG       		8U
#define EEPROM_ADDR_SN       			12U		//occupy 3 DWORDs:10 bytes valid.
#define EEPROM_ADDR_CIPHER_FLAG       	24U
#define EEPROM_ADDR_CIPHER       		28U		//occupy 8 DWORDs:32 bytes valid. 
#define EEPROM_ADDR_DEVID_FLAG			60U
#define EEPROM_ADDR_DEVID       		64U		//occupy 9 DWORDs:36 bytes valid.
#define EEPROM_ADDR_VOLUME_FLAG			100U	
#define EEPROM_ADDR_VOLUME				104U
#define EEPROM_ADDR_MUTE_FLAG			108U
#define EEPROM_ADDR_FW_VER_FLAG			112U
#define EEPROM_ADDR_FW_VER				116U
#define EEPROM_ADDR_END					120U	//the end setting addr of app..........

//eeprom related valid flag value defination
#define EEPROM_UPGRADE_FLAG_VALID       0x00112233	//this value indicate:boot need start to upgrade fw.
#define EEPROM_SPI_INIT_FLAG_VALID      0x11223344	//this value indicate:SD or SPI-flash has been formatted.
#define EEPROM_SN_VALID_FLAG      		0x22334455	//this value indicate:sn has been burned.
#define EEPROM_CIPGER_FLAG_VALID		0x33445566	//this value indicate:device cipher has been set.
#define EEPROM_DEVID_FLAG_VALID			0x44556677	//this value indicate:device device id has been set.
#define EEPROM_VOLUME_VALID				0x55667788	//this value indicate:mp3 volume has been set.
#define EEPROM_MUTE_ON_VALID			0x66778899	//this value indicate:mp3 mute is set to be on.
#define EEPROM_MUTE_OFF_VALID			0x778899aa	//this value indicate:mp3 mute is set to be off.
#define EEPROM_FW_VER_VALID				0xaabbccdd	//this value indicate:fw ver is valid.

#define FILE_MD5_IS_NULL(_a)              \
    ((_a)[0] == 0 &&                         \
     (_a)[1] == 0 &&                         \
     (_a)[2] == 0 &&                         \
     (_a)[3] == 0 &&                         \
     (_a)[4] == 0 &&                         \
	 (_a)[5] == 0 && 						\
	 (_a)[6] == 0 && 						\
	 (_a)[7] == 0 && 						\
	 (_a)[8] == 0 && 						\
	 (_a)[9] == 0 && 						\
	 (_a)[10] == 0 && 						\
	 (_a)[11] == 0 && 						\
	 (_a)[12] == 0 && 						\
	 (_a)[13] == 0 && 					   \
	 (_a)[14] == 0 && 					   \
     (_a)[15] == 0)

/*************************************************
Function: crc16
Description: CRC16鏍￠獙鐮佽绗?
Input:
       ptr     鍐呭
       count   闀垮害
Output:
Return:                CRC16鏍￠獙鐬?
Others:
*************************************************/
unsigned short crc16(char *ptr, int count);


/*************************************************
Function: get_file_size
Description: 璁＄畻鏂囦欢澶у皬
Input:
	filename: 鏂囦欢璺緞
Output:
Return:
	鏂囦欢瀛楄妭鎿?
Others:
*************************************************/
unsigned long get_file_size(unsigned char file_Dev,const char *filename);

bool ends_with(const char * haystack, const char * needle);

/*************************************************
Function: get_md5
Description: 璁＄畻鏂囦欢md5
Input:
       ptr: 鏂囦欢璺緞
       type锖?鏂囦欢
                 1 瀛楃涠?
Output:
       md5: 鏂囦欢md5
Return:
       0锖挎垚鍔?
       <0: 澶辫触
Others:
*************************************************/
int get_md5(unsigned char file_Dev,unsigned char *md5, const char *ptr, int type);

#endif
