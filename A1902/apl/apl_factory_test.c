#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include "api_battery.h"
//#include "apl_app_version.h"
#include "battery_protocal.h"
//#include "bll_manage_hw.h"
//#include "bll_network.h"
#include "cmsis_os.h"
//#include "bll_slot_manage.h"
#include "jd_os_middleware.h"
#include "main.h"
//#include "manage_at_cmd.h"
//#include "rtc.h"
#include "uart.h"
#include "uart_comm.h"
#include "utils.h"
#include "md5.h"
JD_OM_QUEUE factory_recv_q;
osThreadId ft_tid;
//extern RTC_HandleTypeDef hrtc;
static RECV_FILE_DES recv_file_des;
MD5_CTX_T g_ctx;

#define FACTORY_TEST_SLOT SLAVE_1
#define OTP_ADRR_DEVICE_SN ((char *)FLASH_OTP_BASE)
#define OTP_ADRR_AGEING_DATA ((char *)FLASH_OTP_BASE + 16)
#define MAX_GPRS_DATA_LEN (64)
#if 0
typedef enum {
	GPRS_OK = 0,    //成功
	ERR_NO_ACK,     //2G模块无响�?
	ERR_GET_CGMI,   //2G模块名称读取失败
	ERR_CGMI_LEN,   //2G模块名称长度错误
	ERR_GET_CCID,   //SIM卡CCID读取失败
	ERR_CCID_LEN,   //SIM卡CCID数据长度错误
	ERR_GET_RSSI,   //2G模块信号强度读取失败
	ERR_RSSI_LEN,   //2G模块信号强度数据长度错误
}FT_GPRS_CODE;

int ft_gprs_at_cmd(AT_CMD_LIST list_cmd, char *in_cmd_data, unsigned int in_cmd_len, unsigned char *out_data, unsigned int *out_len)
{
	int ret = -1;
	unsigned int timeout = 0, len = 0;
	unsigned char data[MAX_GPRS_DATA_LEN] = { 0 };

	memset(out_data, 0, MAX_GPRS_DATA_LEN);
	*out_len = 0;

	do {
		ret = fml_manage_at_cmd(list_cmd, in_cmd_data, in_cmd_len, data, &len);
		if (errOK == ret)
			break;
		jd_om_msleep(10);
	} while (timeout++ < 3);

	if (ret == errOK) {
		if (len <= sizeof(data)) {
			*out_len = len;
			memcpy(out_data, data, len);
		}
	}

	return ret;
}


int set_rtc_by_utc(time_t t)
{
	RTC_DateTypeDef sdatestructure;
	RTC_TimeTypeDef stimestructure;
	struct tm *p = gmtime(&t);

	/*##-1- Configure the Date #################################################*/
	/* Set Date: Tuesday February 18th 2014 */
	sdatestructure.Year = RTC_ByteToBcd2(p->tm_year - 100);
	sdatestructure.Month = RTC_ByteToBcd2(p->tm_mon + RTC_MONTH_JANUARY);
	sdatestructure.Date = RTC_ByteToBcd2(p->tm_mday);
	sdatestructure.WeekDay = RTC_ByteToBcd2(p->tm_wday + RTC_WEEKDAY_MONDAY);

	if (HAL_RTC_SetDate(&hrtc, &sdatestructure, RTC_FORMAT_BCD) != HAL_OK) {
		/* Initialization Error */
		printf("rtc set date err\r\n");
		return -1;
	}

	/*##-2- Configure the Time #################################################*/
	/* Set Time: 02:00:00 */
	stimestructure.Hours = RTC_ByteToBcd2(p->tm_hour);
	stimestructure.Minutes = RTC_ByteToBcd2(p->tm_min);
	stimestructure.Seconds = RTC_ByteToBcd2(p->tm_sec);

	if (stimestructure.Hours < 12)
		stimestructure.TimeFormat = RTC_HOURFORMAT12_AM;
	else
		stimestructure.TimeFormat = RTC_HOURFORMAT12_PM;

	stimestructure.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	stimestructure.StoreOperation = RTC_STOREOPERATION_RESET;

	if (HAL_RTC_SetTime(&hrtc, &stimestructure, RTC_FORMAT_BCD) != HAL_OK) {
		/* Initialization Error */
		printf("rtc set time err\r\n");
		return -1;
	}

	return 0;
	/*##-3- Writes a data in a RTC Backup data Register1 #######################*/
	//HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x32F2);
}

time_t get_rtc_of_utc()
{
	RTC_DateTypeDef sdatestructureget;
	RTC_TimeTypeDef stimestructureget;

	/* Get the RTC current Time */
	HAL_RTC_GetTime(&hrtc, &stimestructureget, RTC_FORMAT_BIN);
	/* Get the RTC current Date */
	HAL_RTC_GetDate(&hrtc, &sdatestructureget, RTC_FORMAT_BIN);

	struct tm t = {
		.tm_sec		= stimestructureget.Seconds,
		.tm_min		= stimestructureget.Minutes,
		.tm_hour	= stimestructureget.Hours,
		.tm_mday	= sdatestructureget.Date,
		.tm_mon		= sdatestructureget.Month - RTC_MONTH_JANUARY,
		.tm_year	= sdatestructureget.Year,
	};
	return mktime(&t);
}

void RTC_CalendarShow(uint8_t *showtime, uint8_t *showdate)
{
	RTC_DateTypeDef sdatestructureget;
	RTC_TimeTypeDef stimestructureget;

	/* Get the RTC current Time */
	HAL_RTC_GetTime(&hrtc, &stimestructureget, RTC_FORMAT_BIN);
	/* Get the RTC current Date */
	HAL_RTC_GetDate(&hrtc, &sdatestructureget, RTC_FORMAT_BIN);
	/* Display time Format : hh:mm:ss */
	sprintf((char *)showtime, "%2d:%2d:%2d", stimestructureget.Hours, stimestructureget.Minutes, stimestructureget.Seconds);
	/* Display date Format : mm-dd-yy */
	sprintf((char *)showdate, "%2d-%2d-%2d", sdatestructureget.Month, sdatestructureget.Date, 2000 + sdatestructureget.Year);
}
#endif

osStatus jd_master_com_send_response(unsigned char type, void *data)
{
	int payload_size;
	unsigned char res_type;
	//unsigned int material_num = 0;
	osStatus ret;

	switch (type) {

	case REQ_DEVICE_INFO:
	{
		res_type = RES_DEVICE_INFO;
		payload_size = sizeof(RES_DEVICE_INFO_T);
		break;
	}
	case REQ_SET_SN:
	{
		res_type = RES_SET_SN;
		payload_size = sizeof(RES_SET_SN_T);
		break;
	}

	case REQ_GET_TIME:
	{
		res_type = RES_GET_TIME;
		payload_size = sizeof(RES_GET_TIME_T);
		break;
	}

	case REQ_SET_TIME:
	{
		res_type = RES_SET_TIME;
		payload_size = sizeof(RES_SET_TIME_T);
		break;
	}
	case REQ_FLASH_LED:
	{
		res_type = RES_FLASH_LED;
		payload_size = sizeof(RES_SET_FLASH_LED_T);
		break;
	}
	case REQ_SLOT_LED:
	{
		res_type = RES_SLOT_LED;
		payload_size = sizeof(RES_SET_SLOT_LED_T);
		break;
	}
	case REQ_SLOT_ELOCK:
	{
		res_type = RES_SLOT_ELOCK;
		payload_size = sizeof(RES_SET_SLOT_ELOCK_T);
		break;
	}
	case REQ_SLOT_POWER:
	{
		res_type = RES_SLOT_POWER;
		payload_size = sizeof(RES_SET_SLOT_POWER_T);
		break;
	}
	case REQ_SLOT_KEY_STAT:
	{
		res_type = RES_SLOT_KEY_STAT;
		payload_size = sizeof(RES_GET_SLOT_KEY_T);
		break;
	}
	case REQ_BATTERY_ENCRYPT:
	{
		res_type = RES_BATTERY_ENCRYPT;
		payload_size = sizeof(RES_BATTERY_ENCRYPT_T);
		break;
	}
	case REQ_BATTERY_INFO:
	{
		res_type = RES_BATTERY_INFO;
		payload_size = sizeof(RES_BATTERY_INFO_T);
		break;
	}
	case REQ_GPRS_MODULE_INFO:
	{
		res_type = RES_GPRS_MODULE_INFO;
		payload_size = sizeof(RES_GPRS_MODULE_INFO_T);
		break;
	}
	case REQ_GPRS_CONNECT:
	{
		res_type = RES_GPRS_CONNECT;
		payload_size = sizeof(RES_GPRS_CONNECT_T);
		break;
	}
	case REQ_DEVICE_AGEING:
	{
		res_type = RES_DEVICE_AGEING;
		payload_size = sizeof(RES_AGEING_T);
		break;
	}
	case REQ_ENV_TEMPRATURE:
	{
		res_type = RES_ENV_TEMPRATURE;
		payload_size = sizeof(RES_TEMPRATURE_T);
		break;
	}

	default:
		return osErrorOS;
	}

	int packet_size = sizeof(MSG_UART_HEAD_T) + payload_size + CHECKSUM_SIZE;
	MSG_UART_PACKAGE_T *pkt = jd_om_malloc(packet_size);

	pkt->head.start = START_CMD;
	pkt->head.slave = FACTORY_TEST_SLOT;
	pkt->head.type = res_type;
	pkt->head.payload_len = payload_size;

	memcpy((char *)pkt + sizeof(MSG_UART_HEAD_T), (char *)data, payload_size);

	unsigned short chksum = crc16((char *)pkt, packet_size - CHECKSUM_SIZE);
	memcpy((char *)pkt + packet_size - CHECKSUM_SIZE, &chksum, CHECKSUM_SIZE);

	ret = jd_om_mq_send(&(uart_comm_des.send_queue), (void *)pkt);
	if (osErrorOS == ret)
		dzlog_error("res[%02x] to queue error\r\n", res_type);

	return (osStatus)ret;
}
#if 0
typedef struct  {
	unsigned int	start_time;
	unsigned int	stop_time;
	unsigned char	slot_list[CHNL_MAX];
} AGE_DATA_T;


void read_age_data(AGE_DATA_T *data)
{
	memcpy((char *)data, OTP_ADRR_AGEING_DATA, sizeof(AGE_DATA_T));
}

void write_age_data(AGE_DATA_T *data)
{
	memcpy(OTP_ADRR_AGEING_DATA, (char *)data, sizeof(AGE_DATA_T));
}

int get_current_time()
{
	int seconds = get_rtc_of_utc();

	return seconds;
}

int start_ageing_test(AGE_DATA_T *age_data)
{
	for (int i = 0; i < CHNL_MAX; i++) {
		if (age_data->slot_list[i]) {
			//1. enable slot power
			bll_slot_manage_chg((cmd_e)OPEN, (slot_e)i);
			//2. enalbe slot led
			bll_slot_manage_led((led_cmd_e)ON, (led_e)i, 0, 0);
		}
	}
	write_age_data(age_data);
	return 0;
}

int stop_ageing_test(AGE_DATA_T *age_data)
{
	for (int i = 0; i < CHNL_MAX; i++) {
		if (age_data->slot_list[i]) {
			//1. disable slot power
			bll_slot_manage_chg((cmd_e)CLOSE, (slot_e)i);
			//2. disable slot led
			bll_slot_manage_led((led_cmd_e)OFF, (led_e)i, 0, 0);
			//3. disable lock
			bll_slot_manage_solenoid((cmd_e)OPEN, (slot_e)i);
		}
	}

	return 0;
}

int check_ageing_time(AGE_DATA_T *age_data)
{
	if (age_data->stop_time && (get_current_time() > age_data->stop_time)) {
		stop_ageing_test(age_data);
		memset(age_data, 0, sizeof(AGE_DATA_T));
		write_age_data(age_data);
	}
	return 0;
}

int recovery_ageing_test(AGE_DATA_T *age_data)
{
	read_age_data(age_data);
	if (get_current_time() < age_data->stop_time)
		start_ageing_test(age_data);
	return 0;
}
#endif

//char dev_sn[16];
int write_sn(unsigned char *sn, unsigned int sn_len)
{
	//snprintf(dev_sn, sn_len, "%s", sn);
	//return 0;

	if (sn_len == snprintf(OTP_ADRR_DEVICE_SN, 16, "%s", sn))
		return 0;
	else
		return -1;
}

int read_sn(unsigned char *buf)
{
	//snprintf((char *)buf, sizeof(dev_sn), "%s", dev_sn);
	//return 0;
	return snprintf((char *)buf, 16, "%s", OTP_ADRR_DEVICE_SN);
}

int get_soft_version(char *version)
{
#if 0

	int vers[3] = { 0 };

	if (3 == sscanf((char *)APP_VERSION, "%d.%d.%d", vers, vers + 1, vers + 2)) {
		version[0] = vers[0];
		version[1] = vers[1];
		version[2] = vers[2];
		return 0;
	} else {
		return -1;
	}

#else
	version[0] = 1;
	version[1] = 0;
	version[2] = 1;
	return 0;
#endif
}

void get_hw_version(char *version)
{
#if 0
	version[0] = HAL_GPIO_ReadPin(MAIN_BOARD_ID1_GPIO_Port, MAIN_BOARD_ID1_Pin);;
	version[1] = HAL_GPIO_ReadPin(MAIN_BOARD_ID2_GPIO_Port, MAIN_BOARD_ID2_Pin);;
	version[2] = HAL_GPIO_ReadPin(MAIN_BOARD_ID3_GPIO_Port, MAIN_BOARD_ID3_Pin);;
#else
	version[0] = 1;
	version[1] = 0;
	version[2] = 3;
#endif
}

static osStatus file_transfer_start(char *file_name)
{
	osStatus ret = osOK;

	recv_file_des.packet_id = 0;
	recv_file_des.offset = 0;

	snprintf(recv_file_des.file_path, MAX_FILE_PATH_SIZE, "%s/%s", "/tmp", file_name);
	if(recv_file_des.type != upgrade_file){
		dzlog_error("recv unknown file type %d\r\n",recv_file_des.type);
		ret = osErrorOS;
		goto RESPONSE;
	}

	if (0 >= recv_file_des.size) {
		dzlog_error("recv slave update file size error\r\n");
		ret = osErrorOS;
		goto RESPONSE;
	}

#if 0
	unsigned char file_Dev = SYSDISK;
	FRESULT error;

	error = ff_open(file_Dev,&(recv_file_des.file_handle),_T(recv_file_des.file_path), (FA_WRITE | FA_READ | FA_CREATE_ALWAYS));
	if (error) {
        if (error == FR_EXIST)
        {
            dzlog_error("File exists.\r\n");
        }
        else
        {
            dzlog_error("Open file failed.\r\n");
        }
		dzlog_error("slave create update file fail[file_name=%s,error=%d]\r\n",recv_file_des.file_path,error);
		ret = osErrorOS;
		goto RESPONSE;
	}

	f_lseek(&(recv_file_des.file_handle), 0U);
#else
	md5_init(&g_ctx);
#endif
RESPONSE:
	{
		int payload_size = sizeof(RES_TRANS_FILE_HEAD_T);
		int packet_size = sizeof(MSG_UART_HEAD_T) + payload_size + CHECKSUM_SIZE;
		MSG_UART_PACKAGE_T *pkt = jd_om_malloc(packet_size);

		pkt->head.start = START_CMD;
		pkt->head.slave = SLAVE_1;
		pkt->head.type = RES_TRANS_FILE_HEAD;
		pkt->head.payload_len = payload_size;

		RES_TRANS_FILE_HEAD_T res;
		res.code = ret;
		memcpy((char *)pkt + sizeof(MSG_UART_HEAD_T), &res, payload_size);

		unsigned short chksum = crc16((char *)pkt, packet_size - CHECKSUM_SIZE);
		memcpy((char *)pkt + packet_size - CHECKSUM_SIZE, &chksum, CHECKSUM_SIZE);

		return jd_om_mq_send(&uart_comm_des.send_queue, (void *)pkt);
	}
}

static osStatus file_transfer_going(unsigned packet_id, char *data, unsigned len)
{
	osStatus ret = osOK;

	if ((packet_id != recv_file_des.packet_id + 1) &&
	    (!(0 == packet_id && 0 == recv_file_des.packet_id))) {
		dzlog_error("slave update packet id err\r\n");
		ret = osErrorOS;
		goto RESPONSE;
	}

#if 0
	UINT bytesWritten;
	f_lseek(&(recv_file_des.file_handle), recv_file_des.offset);
	FRESULT error;
	error = f_write_decrypted_aes_data(hdl,&(recv_file_des.file_handle), data, len, &bytesWritten);
	//error = f_write(&(recv_file_des.file_handle), data, len, &bytesWritten);
	if ((error)/* || (len != bytesWritten)*/) {
		dzlog_error("slave update write file err\r\n");
		ret = osErrorOS;
		goto RESPONSE;
	}
	recv_file_des.packet_id = packet_id;
	recv_file_des.offset += bytesWritten;
#else
	md5_update(&g_ctx, (unsigned char*)data, len);
	recv_file_des.packet_id = packet_id;
	recv_file_des.offset += len;
#endif

	dzlog_debug("file download progress: %d/%d packet_id %d\r\n", recv_file_des.offset, recv_file_des.size, packet_id);

RESPONSE:
	{
		int payload_size = sizeof(RES_TRANS_FILE_DATA_T);
		int packet_size = sizeof(MSG_UART_HEAD_T) + payload_size + CHECKSUM_SIZE;
		MSG_UART_PACKAGE_T *pkt = jd_om_malloc(packet_size);

		pkt->head.start = START_CMD;
		pkt->head.slave = SLAVE_1;
		pkt->head.type = RES_TRANS_FILE_DATA;
		pkt->head.payload_len = payload_size;

		RES_TRANS_FILE_DATA_T res;
		res.packet_id = packet_id;
		res.code = ret;
		memcpy((char *)pkt + sizeof(MSG_UART_HEAD_T), &res, payload_size);

		unsigned short chksum = crc16((char *)pkt, packet_size - CHECKSUM_SIZE);
		memcpy((char *)pkt + packet_size - CHECKSUM_SIZE, &chksum, CHECKSUM_SIZE);

		return jd_om_mq_send(&uart_comm_des.send_queue, (void *)pkt);
	}
}

static osStatus file_transfer_end()
{
	int restart_sec = 3;
	osStatus ret = osOK;

	unsigned char md5[MD5_SIZE] = { 0 };
#if 0
	unsigned char file_Dev = SYSDISK;
	dzlog_debug("slave update end\r\n");
	f_sync(&(recv_file_des.file_handle));
	f_close(&(recv_file_des.file_handle));
	get_md5(file_Dev,md5, recv_file_des.file_path, 0);

	dzlog_debug("%s:[file_size=%d,padding_len=%d]\r\n",__func__,
		recv_file_des.size,recv_file_des.aes_padding_len);
	if ((recv_file_des.size-recv_file_des.aes_padding_len) != get_file_size(file_Dev,recv_file_des.file_path)) {
		dzlog_error("slave update file size wrong\r\n");
		ret = osErrorOS;
		goto RESPONSE;
	}

	if (0 != memcmp(md5, recv_file_des.md5, MD5_SIZE)) {
		dzlog_error("slave update file md5 wrong\r\n");
		ret = osErrorOS;
	}

	if(ret == osOK)
		file_move_to_destination(recv_file_des.file_path,(FileType)(recv_file_des.type));
RESPONSE:
#else
	md5_final(&g_ctx, md5);
	if (0 != memcmp(md5, recv_file_des.md5, MD5_SIZE)) {
		dzlog_error("trans file md5 wrong\r\n");
		ret = osErrorOS;
	} else {
		dzlog_debug("trans file md5 ok\r\n");
	}

#endif
	{
		dzlog_debug("file trans end\r\n");
		int payload_size = sizeof(RES_TRANS_FILE_END_T);
		int packet_size = sizeof(MSG_UART_HEAD_T) + payload_size + CHECKSUM_SIZE;
		MSG_UART_PACKAGE_T *pkt = jd_om_malloc(packet_size);

		pkt->head.start = START_CMD;
		pkt->head.slave = SLAVE_1;
		pkt->head.type = RES_TRANS_FILE_END;
		pkt->head.payload_len = payload_size;

		RES_TRANS_FILE_END_T res;
		res.code = ret;
		memcpy((char *)pkt + sizeof(MSG_UART_HEAD_T), &res, payload_size);

		unsigned short chksum = crc16((char *)pkt, packet_size - CHECKSUM_SIZE);
		memcpy((char *)pkt + packet_size - CHECKSUM_SIZE, &chksum, CHECKSUM_SIZE);

		ret = jd_om_mq_send(&uart_comm_des.send_queue, (void *)pkt);

		if ((0 == res.code) && (recv_file_des.type == upgrade_file)) {
			dzlog_debug("%s:recv upgrade file completed !\r\n",__func__);
			jd_om_msleep(1000);	//wait host get the response.
			//TODO:set a new bin flag to eeprom to notify boot entry upgrade mode here!
			//if(copy_upgrade_file_to_flash(recv_file_des.file_path) != osOK){
			if (0) {
				debug("upgrade err\n");
			}
			else{
				//set_upgrade_flag();
				dbinfo("upgrade suc\r\n");
				dbinfo("System will reboot in 3s\r\n");
				do{
					dbinfo("%d...\r\n", restart_sec);
					restart_sec--;
					jd_om_msleep(1000);
				}while(restart_sec > 0);
				dbinfo("\r\n===>>>reboot now\r\n");
				//__disable_irq();
				//__set_PSP(0x20018000);
				//EMC_Deinit(EMC);
				//ispPinInit();
				//system_reset();
			}
		}

		if(res.code != osOK){
			dzlog_error("#####%s:start to delete bad file '%s'#####\r\n",__func__,recv_file_des.file_path);
			//ff_unlink(file_Dev,recv_file_des.file_path);
		}
		memset(recv_file_des.version,0,4);
		memset(recv_file_des.file_path, 0, MAX_FILE_PATH_SIZE);
		recv_file_des.type = 0;
		recv_file_des.size = 0;
		recv_file_des.packet_id = 0;
		recv_file_des.offset = 0;
		recv_file_des.size = 0;
		recv_file_des.aes_padding_len = 0;
		memset(recv_file_des.md5, 0, MD5_SIZE);

		return ret;
	}
}

void factory_test_task(void const *p)
{
	void *pt = NULL;
	static unsigned int old_pkt_id = 1;
	memset(recv_file_des.file_path, 0, MAX_FILE_PATH_SIZE);

	dzlog_debug("%s start >>>>\r\n", __func__);
#if 0
	AGE_DATA_T age_data;
	memset(&age_data, 0, sizeof(AGE_DATA_T));
	recovery_ageing_test(&age_data);
#endif
	while (1) {
		pt = NULL;
#if 0
		check_ageing_time(&age_data);
#endif
		jd_om_mq_recv(&factory_recv_q, (void **)&pt, 1000);
		if (pt) {
			MSG_UART_HEAD_T* head = (MSG_UART_HEAD_T*)pt;
			unsigned char type = head->type;
			unsigned int payload_len = head->payload_len;

			switch (type) {
				case REQ_DEVICE_INFO:
					{
						dzlog_debug("get device info\r\n");
						unsigned char sn[16] = { 0 };

						RES_DEVICE_INFO_T res;

						read_sn(sn);
						snprintf((char *)res.sn, 16, "%s", sn);
						get_md5((unsigned char *)res.sn_md5, (char const *)res.sn, 12, 1);
						u32 cpuid = HAL_GetUIDw0();
						memcpy((char *)res.cpuid, (char *)&cpuid, 4);
						cpuid = HAL_GetUIDw1();
						memcpy((char *)res.cpuid + 4, (char *)&cpuid, 4);
						cpuid = HAL_GetUIDw2();
						memcpy((char *)res.cpuid + 8, (char *)&cpuid, 4);
						get_md5((unsigned char *)res.cpuid_md5, (char const *)res.cpuid, 12, 1);

						//snprintf((char *)res.fw_ver, 4, "%c%c%c%c", 1,0,0,0);
						get_soft_version((char *)res.fw_ver);

						//snprintf((char *)res.hw_ver, 4, "%c%c%c%c", 1,0,1,0);
						get_hw_version((char *)res.hw_ver);

						res.Encrypted = 0;
						res.code = 0;
						jd_master_com_send_response(type, (void *)&res);
						break;
					}
				case REQ_SET_SN:
					{
						REQ_SET_SN_T *req = (REQ_SET_SN_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
						dzlog_debug("set sn : %s\r\n", req->sn);
						char sn_md5[16];
						get_md5((unsigned char *)sn_md5, (char const *)req->sn, req->sn_len, 1);
						RES_SET_SN_T res;
						if (memcmp(sn_md5, req->sn_md5, 16)) {
							res.code = 1;/* md5 校验失败 */
						} else {
							if(write_sn(req->sn, req->sn_len)) {
								res.code = 2;/* 写入sn失败 */
							} else {
								unsigned char sn[16] = { 0 };
								read_sn(sn);
								if (memcmp(sn, req->sn, req->sn_len))
									res.code = 2;
								else
									res.code = 0;
							}
						}
						jd_master_com_send_response(type,(void *)&res);

						break;
					}
#if 0

				case REQ_GET_TIME:
					{
						dzlog_debug("get rtc time 1555733950\r\n");
						RES_GET_TIME_T res;
				res.code = 0;
				res.time_sec = get_rtc_of_utc();                //jd_master_com_get_system_time_second();
						res.time_usec = 0;
						jd_master_com_send_response(type,(void *)&res);
						break;
					}
				case REQ_SET_TIME:
					{
						REQ_SET_TIME_T * req = (REQ_SET_TIME_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
						dzlog_debug("set time sec %d \r\n", req->time_sec);

						RES_SET_TIME_T res;
				if (0 == set_rtc_by_utc(req->time_sec))
						res.code = 0;
				else
					res.code = 1;
						jd_master_com_send_response(type,(void *)&res);
						break;
					}
				case REQ_FLASH_LED:
					{
						REQ_SET_FLASH_LED_T *req = (REQ_SET_FLASH_LED_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
						dzlog_debug("set flash led %d\r\n", req->led_status);

				bll_manage_qr_led((led_cmd_e)req->led_status, 4, 250);

						RES_SET_FLASH_LED_T res;
						res.code = 0;
						jd_master_com_send_response(type,(void *)&res);
						break;
					}
				case REQ_SLOT_LED:
					{
						REQ_SET_SLOT_LED_T *req = (REQ_SET_SLOT_LED_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
						dzlog_debug("set slot %d led to %d\r\n", req->slot_num, req->led_status);

				bll_slot_manage_led((led_cmd_e)(req->led_status), (led_e)(req->slot_num), 4, 250);

						RES_SET_SLOT_LED_T res;
						res.code = 0;
						jd_master_com_send_response(type,(void *)&res);
						break;
					}
				case REQ_SLOT_ELOCK:
					{
						REQ_SET_SLOT_ELOCK_T *req = (REQ_SET_SLOT_ELOCK_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
						dzlog_debug("set slot %d lock to %d\r\n", req->slot_num, req->elock_status);

				bll_slot_manage_solenoid((cmd_e)req->elock_status, (slot_e)req->slot_num);

						RES_SET_SLOT_ELOCK_T res;
						res.code = 0;
						jd_master_com_send_response(type,(void *)&res);
						break;
					}
				case REQ_SLOT_POWER:
					{
						REQ_SET_SLOT_POWER_T *req = (REQ_SET_SLOT_POWER_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
						dzlog_debug("set slot %d power to %d\r\n", req->slot_num, req->power_status);

				bll_slot_manage_chg((cmd_e)req->power_status, (slot_e)req->slot_num);

						RES_SET_SLOT_POWER_T res;
						res.code = 0;
						jd_master_com_send_response(type,(void *)&res);
						break;
					}
				case REQ_SLOT_KEY_STAT:
					{
						REQ_GET_SLOT_KEY_T *req = (REQ_GET_SLOT_KEY_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
						dzlog_debug("get slot %d key status\r\n", req->slot_num);

						RES_GET_SLOT_KEY_T res;
						res.code = 0;
				res.key_status = bll_slot_manage_swb_read((slot_e)req->slot_num);
						jd_master_com_send_response(type,(void *)&res);
						break;
					}
				case REQ_BATTERY_ENCRYPT:
					{
						REQ_BATTERY_ENCRYPT_T *req = (REQ_BATTERY_ENCRYPT_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
						dzlog_debug("set battery %d opt %d\r\n", req->slot_num, req->opt);

						RES_BATTERY_ENCRYPT_T res;
#if 1
				if (0 == req->opt)
					res.code = battery_encode(req->slot_num);
				else if (1 == req->opt)
					res.code = battery_decode(req->slot_num, req->psw, req->psw_len);

#else
						res.code = 0;
#endif
						jd_master_com_send_response(type,(void *)&res);
						break;
					}
				case REQ_BATTERY_INFO:
					{
						REQ_BATTERY_INFO_T *req = (REQ_BATTERY_INFO_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
						dzlog_debug("get battery %d info opt %d\r\n", req->slot_num, req->opt);

						BATTERY_INFO_T info;
						RES_BATTERY_INFO_T res;

						memset(&info, 0, sizeof(BATTERY_INFO_T));
						memset(&res, 0, sizeof(RES_BATTERY_INFO_T));

#if 1
				res.code = battery_get_info(req->slot_num, req->opt, &info);
						if (0 == res.code) {
							memcpy(res.sn, info.sn, info.sn_len);
							res.temperature = info.temperature;
							res.voltage = info.voltage;
							res.ratio = 100 * info.rc / info.fcc;
						}
#else
						res.code = 0;
						snprintf((char *)res.sn, 16, "%s", "BAT1234567");
						res.temperature = 23;
						res.voltage = 4100; //电压
						res.ratio = 88;
#endif
						jd_master_com_send_response(type,(void *)&res);
						break;
					}
				case REQ_GPRS_MODULE_INFO:
					{
						dzlog_debug("get gprs info\r\n");

						RES_GPRS_MODULE_INFO_T res;
				memset(&res, 0, sizeof(RES_GPRS_MODULE_INFO_T));
#if 1
				//module ready
				unsigned int len = 0;
				unsigned char data[MAX_GPRS_DATA_LEN] = { 0 };
				if (ft_gprs_at_cmd(LIST_CMD_AT, AT_CMD_AT, 0, data, &len)) {
					res.code = ERR_NO_ACK;                  //2G模块无响�?
					goto FT_GPRS_RET;
				} else {
					res.module_ready = 1;
				}

				//module name
				if (ft_gprs_at_cmd(LIST_CMD_CGMI, AT_CMD_CGMI, 0, data, &len)) {
					res.code = ERR_GET_CGMI;                //2G模块名称读取失败
					goto FT_GPRS_RET;
				} else {
					if (len > 0 && len <= sizeof(res.module_name)) {
						snprintf(res.module_name, sizeof(res.module_name), "%s", data);
					} else {
						res.code = ERR_CGMI_LEN;                //2G模块名称长度错误
						goto FT_GPRS_RET;
					}
				}

				//sim card status
				if (ft_gprs_at_cmd(LIST_CMD_CPIN, AT_CMD_CPIN, 0, data, &len)) {
					res.simcard_ready = 0;;                //SIM卡状态读取失�?
					goto FT_GPRS_RET;
				} else {
					res.simcard_ready = 1;
				}

				//ccid
				if (ft_gprs_at_cmd(LIST_CMD_CCID, AT_CMD_CCID, 0, data, &len)) {
					res.code = ERR_GET_CCID;                //SIM卡CCID读取失败
					goto FT_GPRS_RET;
				} else {
					if (len > 0 && len <= sizeof(res.Iccid)) {
						memcpy(res.Iccid, data, len);
					} else {
						res.code = ERR_CCID_LEN;                //SIM卡CCID数据长度错误
						goto FT_GPRS_RET;
					}
				}

				//rssi
				if (ft_gprs_at_cmd(LIST_CMD_CSQ, AT_CMD_CSQ, 0, data, &len)) {
					res.code = ERR_GET_RSSI;                //2G模块信号强度读取失败
					goto FT_GPRS_RET;
				} else {
					if (len > 0 && len <= sizeof(data)) {
						res.rssi = ((rssi_data_t *)data)->rssi;
					} else {
						res.code = ERR_RSSI_LEN;                //2G模块信号强度数据长度错误
						goto FT_GPRS_RET;
					}
				}

				//gprs reg status
				if (ft_gprs_at_cmd(LIST_CMD_CGREG, AT_CMD_CGREG, 0, data, &len))
					res.gprs_ready = 0;
				else
					res.gprs_ready = 1;

#else
						snprintf(res.module_name,16, "%s", "MITU"); //模块�?
						memcpy(res.Iccid, "12345678901234567890", 20); //iccid
						res.module_ready = 1;//模块是否正常
						res.simcard_ready = 1;//sim卡是否正�?
						res.gprs_ready = 1; //gprs 是否正常
						res.rssi = 20;		//rssi
#endif

				res.code = 0;                   //响应代码：ok �?，fail�?

FT_GPRS_RET:
						jd_master_com_send_response(type,(void *)&res);
						break;
					}
				case REQ_GPRS_CONNECT:
					{
						REQ_GPRS_CONNECT_T * req = (REQ_GPRS_CONNECT_T*)pt + sizeof(MSG_UART_HEAD_T);
						dzlog_debug("gprs connect opt %d\r\n", req->opt);

						RES_GPRS_CONNECT_T res;
				if (req->opt) {
					/* pppd connect */
					unsigned char ip_addr[IP_ADDR_LEN] = { 0 };
					if (!bll_network_connect(ip_addr))
						res.code = 0;	//响应代码：ok �?，fail�?
					else
						res.code = 1;
				} else {
					bll_gprs_reset();
					res.code = 0;
				}
						jd_master_com_send_response(type,(void *)&res);
						break;
					}
				case REQ_DEVICE_AGEING:
					{
						REQ_AGEING_T *req = (REQ_AGEING_T *)pt + sizeof(MSG_UART_HEAD_T);
						dzlog_debug("ageing opt %d\r\n", req->opt);

				age_data.start_time = get_current_time();
				age_data.stop_time = age_data.start_time + req->time_sec;
				memcpy(age_data.slot_list, req->slot_list, CHNL_MAX);

						RES_AGEING_T res;
				if (req->opt)
					res.code = start_ageing_test(&age_data);
				else
					res.code = stop_ageing_test(&age_data);

						jd_master_com_send_response(type,(void *)&res);
						break;
					}
				case REQ_ENV_TEMPRATURE:
					{
						dzlog_debug("get temprature\r\n");
						RES_TEMPRATURE_T res;
						res.code = 0;
						res.temperature = 23;
						jd_master_com_send_response(type,(void *)&res);
						break;
					}
#endif

				case REQ_TRANS_FILE_HEAD:
				{
					REQ_TRANS_FILE_HEAD_T *req = (REQ_TRANS_FILE_HEAD_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
					if(strlen(recv_file_des.file_path) > 0){
						dzlog_error("###############last transfer file '%s' not closed#############\r\n",
							recv_file_des.file_path);
						//f_sync(&(recv_file_des.file_handle));
						//f_close(&(recv_file_des.file_handle));
					}
					memset(recv_file_des.version, 0, 4);
					memset(recv_file_des.file_path, 0, MAX_FILE_PATH_SIZE);
					memset(recv_file_des.md5, 0, MD5_SIZE);
					memcpy(recv_file_des.md5, req->md5, MD5_SIZE);
					recv_file_des.size = req->size;
					recv_file_des.type = req->type;
					recv_file_des.aes_padding_len = 0;	//init aes padding length.
					old_pkt_id = 1;
					if((recv_file_des.type == upgrade_file) && (!ends_with(req->file_name,".hex"))){
						dzlog_error("firmware type mismatch with file name '%s'###\r\n",req->file_name);
					} else {
						file_transfer_start(req->file_name);
					}
					break;
				}

				case REQ_TRANS_FILE_DATA:
				{
					REQ_TRANS_FILE_DATA_T *req = (REQ_TRANS_FILE_DATA_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
					if (old_pkt_id != req->packet_id) {
						old_pkt_id = req->packet_id;
						file_transfer_going(req->packet_id, (char *)&(req->packet_id) + 4, payload_len - 4);
					} else {
						dzlog_error("recv a same fragment id=%d\r\n",old_pkt_id);
					}
					break;
				}

				case REQ_TRANS_FILE_END:
				{
					file_transfer_end();
					break;
				}

				default:
					break;

				}

			jd_om_free((void *)pt);
		}
	}
}

void stop_factory_test_service()
{
	if (ft_tid) {
		osThreadTerminate(ft_tid);
		ft_tid = NULL;
	}

	if (factory_recv_q) {
		jd_om_delete_mq(&factory_recv_q);
		factory_recv_q = NULL;
	}
}


int start_factory_test_service()
{
	if (NULL == factory_recv_q) {
		osStatus ret = jd_om_mq_create(&factory_recv_q, MAX_QUEUE_SIZE);
		if(ret != osOK) {
			dberr("create factory_recv_q fail.\r\n");
			return -1;
		}
	}

	if (NULL == ft_tid) {
		osThreadDef(ft_task, factory_test_task, osPriorityNormal, 0, 1024);
		ft_tid = osThreadCreate(osThread(ft_task), 0);
		if (NULL == ft_tid) {
			printf("create factory test task failed!.\r\n");
			return -1;
		} else {
			printf("factory test task create successful !\r\n");
		}
	}

        return 0;
}


osStatus add_factory_test_item(void *p)
{
	if (osThreadDeleted == osThreadGetState(ft_tid) || NULL == factory_recv_q)
		return osErrorResource;

	return (osStatus)jd_om_mq_send(&factory_recv_q, p);
}

