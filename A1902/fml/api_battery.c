#include "api_battery.h"
#include "uart_comm.h"
#include "utils.h"


int battery_set_sn_psw(u8 slot, u8 *sn, u32 sn_len, u8 *psw, u32 psw_len)
{
	int ret = -1;
	int payload_len = sizeof(REQ_BAT_SET_SN_PSW_T);
	int pkt_len = sizeof(MSG_UART_HEAD_T) + payload_len + CHECKSUM_SIZE;

	unsigned char *pt = jd_om_malloc(pkt_len);

	MSG_UART_HEAD_T *head = (MSG_UART_HEAD_T *)pt;

	head->start = START_CMD;
	head->slave = slot;
	head->type = REQ_BAT_SET_SN_PSW;
	head->payload_len = payload_len;
	head->packet_id = get_packet_id();

	REQ_BAT_SET_SN_PSW_T * req = (REQ_BAT_SET_SN_PSW_T *)(pt + sizeof(MSG_UART_HEAD_T));
	req->sn_len = sn_len;
	memcpy(req->sn, sn, sn_len);
	req->passwd_len = psw_len;
	memcpy(req->passwd, psw, psw_len);

	unsigned short checksum = crc16((char *)pt, pkt_len - CHECKSUM_SIZE);
	memcpy((char *)pt + pkt_len - CHECKSUM_SIZE, &checksum, CHECKSUM_SIZE);

	ret = jd_om_mq_send(&(uart_comm_des.send_queue), (void *)pt);
	if (ret) {
		dzlog_error("%s send msg error\n", __func__);
		jd_om_free(pt);
		return -1;
	}

	ret =  wait_battery_response(BAT_EVT_SET_SN, WAIT_RESPONSE_TIME_OUT);
	if (0 == ret) {
		ret = br_set_sn.code;
		dzlog_debug("======set battery sn res %d\r\n", ret);
	}
	return ret;
}



//opt : 0 加密电池 1不加密电池
int battery_get_info(u8 slot, u8 opt, BATTERY_INFO_T *info)
{
	int ret = -1;
	int payload_len = sizeof(REQ_BAT_GET_INFO_T);
	int pkt_len = sizeof(MSG_UART_HEAD_T) + payload_len + CHECKSUM_SIZE;

	unsigned char *pt = jd_om_malloc(pkt_len);

	MSG_UART_HEAD_T *head = (MSG_UART_HEAD_T *)pt;

	head->start = START_CMD;
	head->slave = slot;
	head->type = REQ_BAT_GET_INFO;
	head->payload_len = payload_len;
	head->packet_id = get_packet_id();

	REQ_BAT_GET_INFO_T * req = (REQ_BAT_GET_INFO_T *)(pt + sizeof(MSG_UART_HEAD_T));
	req->opt = opt;

	unsigned short checksum = crc16((char *)pt, pkt_len - CHECKSUM_SIZE);
	memcpy((char *)pt + pkt_len - CHECKSUM_SIZE, &checksum, CHECKSUM_SIZE);

	ret = jd_om_mq_send(&(uart_comm_des.send_queue), (void *)pt);
	if (ret) {
		dzlog_error("%s send msg error\n", __func__);
		jd_om_free(pt);
		return -1;
	}

	ret = wait_battery_response(BAT_EVT_GET_INFO, WAIT_RESPONSE_TIME_OUT);
	if (0 == ret) {
		ret = br_get_info.code;
		if (0 == ret && info) {
			//memcpy(info, &br_get_info, sizeof(RES_BAT_GET_INFO_T));
			info->sn_len = br_get_info.sn_len;
			memcpy(info->sn, br_get_info.sn, br_get_info.sn_len);
			info->temperature = br_get_info.Temp;
			info->voltage = br_get_info.Vol_H * 255 + br_get_info.Vol_L;
			info->fcc = 5200;
			info->rc = 52 * br_get_info.ratio;

			dzlog_debug("======get battery info sn len %d sn %s temp %d vol_h %d vol_l %d ratio %d\r\n",
				br_get_info.sn_len,		//sn 有效长度
				br_get_info.sn,		//sn
				br_get_info.Temp,			//温度: 16进制温度值（单位：摄氏度）+偏移量 40(避免负温度)
				br_get_info.Vol_H,		//电压：高位
				br_get_info.Vol_L,		//电压：低位
				br_get_info.ratio);		//16进制

		}
	}
	return ret;
}


int battery_decode(u8 slot, u8 *psw, u32 psw_len)
{
	int ret = -1;
	int payload_len = sizeof(REQ_BAT_DECODE_T);
	int pkt_len = sizeof(MSG_UART_HEAD_T) + payload_len + CHECKSUM_SIZE;

	unsigned char *pt = jd_om_malloc(pkt_len);

	MSG_UART_HEAD_T *head = (MSG_UART_HEAD_T *)pt;

	head->start = START_CMD;
	head->slave = slot;
	head->type = REQ_BAT_DECODE;
	head->payload_len = payload_len;
	head->packet_id = get_packet_id();

	REQ_BAT_DECODE_T * req = (REQ_BAT_DECODE_T *)(pt + sizeof(MSG_UART_HEAD_T));
	req->passwd_len = psw_len;
	memcpy(req->passwd, psw, psw_len);

	unsigned short checksum = crc16((char *)pt, pkt_len - CHECKSUM_SIZE);
	memcpy((char *)pt + pkt_len - CHECKSUM_SIZE, &checksum, CHECKSUM_SIZE);

	ret = jd_om_mq_send(&(uart_comm_des.send_queue), (void *)pt);
	if (ret) {
		dzlog_error("%s send msg error\n", __func__);
		jd_om_free(pt);
		return -1;
	}

	ret = wait_battery_response(BAT_EVT_DECODE, WAIT_RESPONSE_TIME_OUT);
	if (0 == ret) {
		ret = br_decode.code;
		dzlog_debug("======battery decode res %d \r\n", ret);
	}
	return ret;
}



int battery_encode(u8 slot)
{
	int ret = -1;
	int payload_len = 0;
	int pkt_len = sizeof(MSG_UART_HEAD_T) + payload_len + CHECKSUM_SIZE;

	unsigned char *pt = jd_om_malloc(pkt_len);

	MSG_UART_HEAD_T *head = (MSG_UART_HEAD_T *)pt;

	head->start = START_CMD;
	head->slave = slot;
	head->type = REQ_BAT_ENCODE;
	head->payload_len = payload_len;
	head->packet_id = get_packet_id();

	unsigned short checksum = crc16((char *)pt, pkt_len - CHECKSUM_SIZE);
	memcpy((char *)pt + pkt_len - CHECKSUM_SIZE, &checksum, CHECKSUM_SIZE);

	ret = jd_om_mq_send(&(uart_comm_des.send_queue), (void *)pt);
	if (ret) {
		dzlog_error("%s send msg error\n", __func__);
		jd_om_free(pt);
		return -1;
	}

	ret = wait_battery_response(BAT_EVT_ENCODE, WAIT_RESPONSE_TIME_OUT);
	if (0 == ret) {
		ret = br_encode.code;
		dzlog_debug("======battery encode res %d\r\n", ret);
	}
	return ret;

}


int battery_virtual_psw_info(u8 slot, RES_BAT_VIRTUAL_PWR_T *info)
{
	int ret = -1;
	int payload_len = 0;
	int pkt_len = sizeof(MSG_UART_HEAD_T) + payload_len + CHECKSUM_SIZE;

	unsigned char *pt = jd_om_malloc(pkt_len);

	MSG_UART_HEAD_T *head = (MSG_UART_HEAD_T *)pt;

	head->start = START_CMD;
	head->slave = slot;
	head->type = REQ_BAT_VIRTUAL_PWR_INFO;
	head->payload_len = payload_len;
	head->packet_id = get_packet_id();

	unsigned short checksum = crc16((char *)pt, pkt_len - CHECKSUM_SIZE);
	memcpy((char *)pt + pkt_len - CHECKSUM_SIZE, &checksum, CHECKSUM_SIZE);

	ret = jd_om_mq_send(&(uart_comm_des.send_queue), (void *)pt);
	if (ret) {
		dzlog_error("%s send msg error\n", __func__);
		jd_om_free(pt);
		return -1;
	}

	ret =  wait_battery_response(BAT_EVT_VIRT_PWR_INFO, WAIT_RESPONSE_TIME_OUT);
	if (0 == ret) {
		if (info) {
			memcpy(info, &br_virt_info, sizeof(RES_BAT_VIRTUAL_PWR_T));
			dzlog_debug("======battery virtual info cnt1 %d cnt2 %d ratio %d last %d discharging %d \r\n",
				info->data[0], info->data[1], info->data[2], info->data[3], info->data[4]);
		}
	}
	return ret;
}

int battery_set_discharge_level(u8 slot, u8 level)
{
	int ret = -1;
	int payload_len = sizeof(REQ_BAT_DISCHARGE_LEVEL_T);
	int pkt_len = sizeof(MSG_UART_HEAD_T) + payload_len + CHECKSUM_SIZE;

	unsigned char *pt = jd_om_malloc(pkt_len);

	MSG_UART_HEAD_T *head = (MSG_UART_HEAD_T *)pt;

	head->start = START_CMD;
	head->slave = slot;
	head->type = REQ_BAT_DISCHARGE_LEVEL;
	head->payload_len = payload_len;
	head->packet_id = get_packet_id();

	REQ_BAT_DISCHARGE_LEVEL_T *req = (REQ_BAT_DISCHARGE_LEVEL_T *)(pt + sizeof(MSG_UART_HEAD_T));
	req->data[0] = level;
	unsigned short checksum = crc16((char *)pt, pkt_len - CHECKSUM_SIZE);
	memcpy((char *)pt + pkt_len - CHECKSUM_SIZE, &checksum, CHECKSUM_SIZE);

	ret = jd_om_mq_send(&(uart_comm_des.send_queue), (void *)pt);
	if (ret) {
		dzlog_error("%s send msg error\n", __func__);
		jd_om_free(pt);
		return -1;
	}

	ret = wait_battery_response(BAT_EVT_DISCHG_LEVEL, WAIT_RESPONSE_TIME_OUT);
	if (0 == ret) {
		ret = br_dis_level.code;
		dzlog_debug("======battery discharge level res %d\r\n", ret);
	}
	return ret;
}


int battery_charge_status(u8 slot, RES_BAT_CHARGE_STATUS_T *status)
{
	int ret = -1;
	int payload_len = 0;
	int pkt_len = sizeof(MSG_UART_HEAD_T) + payload_len + CHECKSUM_SIZE;

	unsigned char *pt = jd_om_malloc(pkt_len);

	MSG_UART_HEAD_T *head = (MSG_UART_HEAD_T *)pt;

	head->start = START_CMD;
	head->slave = slot;
	head->type = REQ_BAT_CHARGE_STATUS;
	head->payload_len = payload_len;
	head->packet_id = get_packet_id();

	unsigned short checksum = crc16((char *)pt, pkt_len - CHECKSUM_SIZE);
	memcpy((char *)pt + pkt_len - CHECKSUM_SIZE, &checksum, CHECKSUM_SIZE);

	ret = jd_om_mq_send(&(uart_comm_des.send_queue), (void *)pt);
	if (ret) {
		dzlog_error("%s send msg error\n", __func__);
		jd_om_free(pt);
			return -1;
	}

	ret = wait_battery_response(BAT_EVT_CHARGE_STAT, WAIT_RESPONSE_TIME_OUT);
	if (0 == ret) {
		if (status) {
			memcpy(status, &br_chg_stat, sizeof(RES_BAT_CHARGE_STATUS_T));
			dzlog_debug("======battery charge status level %d status %d\r\n", status->data[0], status->data[1]);
		}
	}
	return ret;
}

int battery_protocal_version(u8 slot, RES_BAT_PROTOCAL_VERSION_T *vers)
{
	int ret = -1;
	int payload_len = 0;
	int pkt_len = sizeof(MSG_UART_HEAD_T) + payload_len + CHECKSUM_SIZE;

	unsigned char *pt = jd_om_malloc(pkt_len);

	MSG_UART_HEAD_T *head = (MSG_UART_HEAD_T *)pt;

	head->start = START_CMD;
	head->slave = slot;
	head->type = REQ_BAT_PROTOCAL_VERSION;
	head->payload_len = payload_len;
	head->packet_id = get_packet_id();

	unsigned short checksum = crc16((char *)pt, pkt_len - CHECKSUM_SIZE);
	memcpy((char *)pt + pkt_len - CHECKSUM_SIZE, &checksum, CHECKSUM_SIZE);

	ret = jd_om_mq_send(&(uart_comm_des.send_queue), (void *)pt);
	if (ret) {
		dzlog_error("%s send msg error\n", __func__);
		jd_om_free(pt);
		return -1;
	}

	ret = wait_battery_response(BAT_EVT_PROT_VERS, WAIT_RESPONSE_TIME_OUT);
	if (0 == ret) {
		if (vers) {
			memcpy(vers, &br_pro_vers, sizeof(RES_BAT_PROTOCAL_VERSION_T));
			dzlog_debug("======battery protocal version len %d version %d.%d.%d\r\n",
							vers->ver_len, vers->ver[0], vers->ver[1], vers->ver[2]);

		}
	}
	return ret;
}


int battery_passwd_chksum(u8 slot, RES_BAT_PASSWD_CHKSUM_T *chksum)
{
	int ret = -1;
	int payload_len = 0;
	int pkt_len = sizeof(MSG_UART_HEAD_T) + payload_len + CHECKSUM_SIZE;

	unsigned char *pt = jd_om_malloc(pkt_len);

	MSG_UART_HEAD_T *head = (MSG_UART_HEAD_T *)pt;

	head->start = START_CMD;
	head->slave = slot;
	head->type = REQ_BAT_PASSWD_CHKSUM;
	head->payload_len = payload_len;
	head->packet_id = get_packet_id();

	unsigned short checksum = crc16((char *)pt, pkt_len - CHECKSUM_SIZE);
	memcpy((char *)pt + pkt_len - CHECKSUM_SIZE, &checksum, CHECKSUM_SIZE);

	ret = jd_om_mq_send(&(uart_comm_des.send_queue), (void *)pt);
	if (ret) {
		dzlog_error("%s send msg error\n", __func__);
		jd_om_free(pt);
		return -1;
	}

	ret = wait_battery_response(BAT_EVT_PSW_CHKSUM, WAIT_RESPONSE_TIME_OUT);
	if (0 == ret) {
		if (chksum) {
			memcpy(chksum, &br_psw_chk, sizeof(RES_BAT_PASSWD_CHKSUM_T));
			dzlog_debug("======battery crc 0x%02x 0x%02x\r\n", chksum->crc[0], chksum->crc[1]);

		}
	}
	return ret;
}


