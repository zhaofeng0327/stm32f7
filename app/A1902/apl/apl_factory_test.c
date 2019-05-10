#include "stdio.h"
#include "api_battery.h"
#include "factory_test.h"
#include "battery_protocal.h"
#include "jd_os_middleware.h"
#include "cmsis_os.h"
#include "uart_comm.h"
#include "utils.h"
#include "uart.h"

JD_OM_QUEUE factory_recv_q;
osThreadId ft_tid;

#define FACTORY_TEST_SLOT SLAVE_1

osStatus jd_master_com_send_response(jd_om_comm *hdl,unsigned char type, void *data)
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

	return ret;
}

typedef struct  {
	unsigned int start_time;
	unsigned int stop_time;
	unsigned char slot_list[CHNL_MAX];
} AGE_DATA_T;


void read_age_data_from_file(AGE_DATA_T *data)
{

}

void write_age_data_to_file(AGE_DATA_T *data)
{

}

int get_current_time()
{
	int seconds = 0;
	return seconds;
}

int start_ageing_test(AGE_DATA_T *age_data)
{
	for (int i = 0; i < CHNL_MAX; i++) {
		if (age_data->slot_list[i]) {

			//1. enable slot power
			//2. enalbe slot led
		}
	}
	write_age_data_to_file(age_data);
	return 0;
}

int stop_ageing_test(AGE_DATA_T *age_data)
{
	for (int i = 0; i < CHNL_MAX; i++) {
		if (age_data->slot_list[i]) {

			//1. disable slot power
			//2. disable slot led
			//3. disable lock
		}
	}

	return 0;
}

int check_ageing_time(AGE_DATA_T *age_data)
{
	if (age_data->stop_time && (get_current_time() > age_data->stop_time)) {
		stop_ageing_test(age_data);
		memset(age_data, 0, sizeof(AGE_DATA_T));
		write_age_data_to_file(age_data);
	}
        return 0;
}

int recovery_ageing_test(AGE_DATA_T *age_data)
{
	read_age_data_from_file(age_data);
	if (get_current_time() < age_data->stop_time) {
		start_ageing_test(age_data);
	}
	return 0;
}
void factory_test_task(void const *p)
{
	void *pt = NULL;
	jd_om_comm *hdl = 0;

	dzlog_debug("%s start >>>>\r\n", __func__);

	AGE_DATA_T age_data;
	memset(&age_data, 0, sizeof(AGE_DATA_T));
	recovery_ageing_test(&age_data);

	while (1) {
		pt = NULL;
		check_ageing_time(&age_data);
		jd_om_mq_recv(&factory_recv_q, (void **)&pt, 1000);
		if (pt) {
			MSG_UART_HEAD_T* head = (MSG_UART_HEAD_T*)pt;
			unsigned char type = head->type;
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
						jd_master_com_send_response(hdl,type,(void *)&res);
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
						jd_master_com_send_response(hdl,type,(void *)&res);

						break;
					}
				case REQ_GET_TIME:
					{
						dzlog_debug("get rtc time 1555733950\r\n");
						RES_GET_TIME_T res;
						res.time_sec = 1555733950;//jd_master_com_get_system_time_second();
						res.time_usec = 0;
						jd_master_com_send_response(hdl,type,(void *)&res);
						break;
					}
				case REQ_SET_TIME:
					{
						REQ_SET_TIME_T * req = (REQ_SET_TIME_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
						dzlog_debug("set time sec %d \r\n", req->time_sec);

						RES_SET_TIME_T res;
						res.code = 0;
						jd_master_com_send_response(hdl,type,(void *)&res);
						break;
					}
				case REQ_FLASH_LED:
					{
						REQ_SET_FLASH_LED_T *req = (REQ_SET_FLASH_LED_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
						dzlog_debug("set flash led %d\r\n", req->led_status);


						RES_SET_FLASH_LED_T res;
						res.code = 0;
						jd_master_com_send_response(hdl,type,(void *)&res);
						break;
					}
				case REQ_SLOT_LED:
					{
						REQ_SET_SLOT_LED_T *req = (REQ_SET_SLOT_LED_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
						dzlog_debug("set slot %d led to %d\r\n", req->slot_num, req->led_status);


						RES_SET_SLOT_LED_T res;
						res.code = 0;
						jd_master_com_send_response(hdl,type,(void *)&res);
						break;
					}
				case REQ_SLOT_ELOCK:
					{
						REQ_SET_SLOT_ELOCK_T *req = (REQ_SET_SLOT_ELOCK_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
						dzlog_debug("set slot %d lock to %d\r\n", req->slot_num, req->elock_status);


						RES_SET_SLOT_ELOCK_T res;
						res.code = 0;
						jd_master_com_send_response(hdl,type,(void *)&res);
						break;
					}
				case REQ_SLOT_POWER:
					{
						REQ_SET_SLOT_POWER_T *req = (REQ_SET_SLOT_POWER_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
						dzlog_debug("set slot %d power to %d\r\n", req->slot_num, req->power_status);

						RES_SET_SLOT_POWER_T res;
						res.code = 0;
						jd_master_com_send_response(hdl,type,(void *)&res);
						break;
					}
				case REQ_SLOT_KEY_STAT:
					{
						REQ_GET_SLOT_KEY_T *req = (REQ_GET_SLOT_KEY_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
						dzlog_debug("get slot %d key status\r\n", req->slot_num);

						RES_GET_SLOT_KEY_T res;
						res.code = 0;
						res.key_status = 1;
						jd_master_com_send_response(hdl,type,(void *)&res);
						break;
					}
				case REQ_BATTERY_ENCRYPT:
					{
						REQ_BATTERY_ENCRYPT_T *req = (REQ_BATTERY_ENCRYPT_T *)((char *)pt + sizeof(MSG_UART_HEAD_T));
						dzlog_debug("set battery %d opt %d\r\n", req->slot_num, req->opt);

						RES_BATTERY_ENCRYPT_T res;
#if 1
						if (0 == req->opt) {
							res.code = battery_encode(req->slot_num);
						} else if (1 == req->opt) {
							res.code = battery_decode(req->slot_num, req->psw, req->psw_len);
						}
#else
						res.code = 0;
#endif
						jd_master_com_send_response(hdl,type,(void *)&res);
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
						jd_master_com_send_response(hdl,type,(void *)&res);
						break;
					}
				case REQ_GPRS_MODULE_INFO:
					{
						dzlog_debug("get gprs info\r\n");

						RES_GPRS_MODULE_INFO_T res;
						res.code = 0;	//响应代码：ok �?，fail�?
						snprintf(res.module_name,16, "%s", "MITU"); //模块�?
						memcpy(res.Iccid, "12345678901234567890", 20); //iccid
						res.module_ready = 1;//模块是否正常
						res.simcard_ready = 1;//sim卡是否正�?
						res.gprs_ready = 1; //gprs 是否正常
						res.rssi = 20;		//rssi
						jd_master_com_send_response(hdl,type,(void *)&res);
						break;
					}
				case REQ_GPRS_CONNECT:
					{
						REQ_GPRS_CONNECT_T * req = (REQ_GPRS_CONNECT_T*)pt + sizeof(MSG_UART_HEAD_T);
						dzlog_debug("gprs connect opt %d\r\n", req->opt);

						RES_GPRS_CONNECT_T res;
						res.code = 0;	//响应代码：ok �?，fail�?
						jd_master_com_send_response(hdl,type,(void *)&res);
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

						jd_master_com_send_response(hdl,type,(void *)&res);
						break;
					}
				case REQ_ENV_TEMPRATURE:
					{
						dzlog_debug("get temprature\r\n");
						RES_TEMPRATURE_T res;
						res.code = 0;
						res.temperature = 23;
						jd_master_com_send_response(hdl,type,(void *)&res);
						break;
					}
				default:
					break;

				}

			jd_om_free((void *)p);

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

	return jd_om_mq_send(&factory_recv_q, p);
}

