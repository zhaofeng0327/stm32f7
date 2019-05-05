#ifndef __API_BATTERY_H__
#define __API_BATTERY_H__

#include "battery_protocal.h"

typedef struct {
	unsigned char sn_len;		//sn 有效长度
	unsigned char sn[32];		//sn
	unsigned int temperature;	//温度
	unsigned int voltage;		//电压
	unsigned int fcc;			//充满电量
	unsigned int rc;			//剩余电量
}STRUCT_PACKED BATTERY_INFO_T;


/* 烧写SN及密码 */
int battery_set_sn_psw(u8 *sn, u32 sn_len, u8 *psw, u32 psw_len);

/* 读取SN及相关电池信息 */
int battery_get_info(u8 opt, BATTERY_INFO_T *info);

/* 电池解密 */
int battery_decode(u8 *psw, u32 psw_len);

/* 电池加密 */
int battery_encode();

/* 读取放电虚电数据 */
int battery_virtual_psw_info(RES_BAT_VIRTUAL_PWR_T *info);

/* 设置电池放电电流 */
int battery_set_discharge_level(u8 level);

/* 读取电池充/放电状态 */
int battery_charge_status(RES_BAT_CHARGE_STATUS_T *status);

/* 读取电池通信协议版本 */
int battery_protocal_version(RES_BAT_PROTOCAL_VERSION_T *vers);

/* 读取电池解密密码校验值 */
int battery_passwd_chksum(RES_BAT_PASSWD_CHKSUM_T *chksum);

void test_bat_protoc();


#endif
