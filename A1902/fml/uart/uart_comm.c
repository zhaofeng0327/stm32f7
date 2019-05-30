#include "uart_comm.h"
#include "typedef.h"
#include "utils.h"
//#include "aes.h"
#include "stm32f746xx.h"
#include "stm32f7xx_hal.h"

#include "cmsis_os.h"
#include "api_battery.h"
//#include "fatfs.h"
#define UINT unsigned int
//#define AES_CBC_256_DBG
//#include "factory_test.h"
#include "apl_factory_test.h"

#define UART_CNT 2
unsigned char cipher[32];

UART_COMM_DES_T uart_comm_des;
JD_OM_MUTEX mutex_channel_select;
jd_om_comm uart_channels[UART_CNT+1];
int active_channel = -1;


EventGroupHandle_t BatteryResEvents;
RES_BAT_SET_SN_PSW_T br_set_sn;
RES_BAT_GET_INFO_T br_get_info;
RES_BAT_DECODE_T br_decode;
RES_BAT_ENCODE_T br_encode;
RES_BAT_VIRTUAL_PWR_T br_virt_info;
RES_BAT_DISCHARGE_LEVEL_T br_dis_level;
RES_BAT_CHARGE_STATUS_T br_chg_stat;
RES_BAT_PROTOCAL_VERSION_T br_pro_vers;
RES_BAT_PASSWD_CHKSUM_T br_psw_chk;

#define TRHEAD_NAME_ID(name, id) (&os_thread_def_##name_##id)
#define THREAD_DEF(name, id, thread, priority, instances, stacksz)  \
	const osThreadDef_t os_thread_def_##name_##id = \
	{ #name#id, (thread), (priority), (instances), (stacksz)}


void mutex_uart_switch(int slot_num)
{
	if (slot_num != 2 && slot_num != 0)
		return;


	if (active_channel == slot_num)
		return;


	if (slot_num == 2) {
		if (-1 == jd_om_comm_close(&uart_channels[0]))
			printf("close chn 0 err\r\n");
	} else if (0 == slot_num) {
		if (-1 == jd_om_comm_close(&uart_channels[2]))
			printf("close chn 2 err\r\n");
	}

	jd_om_mutex_lock(&(mutex_channel_select));
	active_channel = slot_num;
	jd_om_mutex_unlock(&(mutex_channel_select));
//        return;

	if (slot_num == 2 || slot_num == 0) {

	if (uart_comm_des.thread_uart_recv[0])
		osThreadTerminate(uart_comm_des.thread_uart_recv[0]);

		int ret = 0;
		jd_om_comm_addr local_addr;
		jd_om_comm_addr addr_mask;

		local_addr.addr = tlc_iaddr("1.0.0");
		addr_mask.addr = tlc_iaddr("255.0.0");

		memset(&uart_channels[0], 0, sizeof(jd_om_comm));
		memset(&uart_channels[2], 0, sizeof(jd_om_comm));
		ret = jd_om_comm_open(&uart_channels[slot_num], &local_addr, &addr_mask, 2);
		if (0 != ret) {
			dzlog_error("open uart channel %d fail ret %d.\r\n", slot_num, ret);
			vTaskSuspend(NULL);
		} else {

			if (slot_num == 0)
				memcpy(&uart_channels[2], &uart_channels[0], sizeof(jd_om_comm));
			else
				memcpy(&uart_channels[0], &uart_channels[2], sizeof(jd_om_comm));

		}

		THREAD_DEF(uartRecv, 0, uart_recv_task, osPriorityHigh, 0, 1024);
		uart_comm_des.thread_uart_recv[0] = osThreadCreate(TRHEAD_NAME_ID(uartRecv, 0), &uart_channels[0]);
		if (NULL == uart_comm_des.thread_uart_recv[0]) {
			printf("create Uart recv Task %d failed!.\r\n", 0);
			while (1);
		} else {
			printf("Uart recv task %d create successful !\r\n", 0);
		}

		osDelay(100);
	}

}

int get_uart_channel()
{
	int chn;
	jd_om_mutex_lock(&(mutex_channel_select));
	chn = active_channel;
	jd_om_mutex_unlock(&(mutex_channel_select));
	return chn;
}

CMD_TYPE_T get_cmd_typte(unsigned char type)
{
	if ((type >= 0xC0 &&  type <= 0xDF) || (type >= 0xF0)) {
		return TYPE_REQ;
	}
	else if ((type >= 0xA0 && type <= 0xBF) || (type >= 0xE0 &&  type <= 0xEF)) {
		return TYPE_RES;
	}
	else {
		return TYPE_INVALID;
	}
}
#if 0

static bool is_null_data(unsigned char *buf,int buf_size)
{
	bool is_null = true;
	int i=0;

	for(i=0;i<buf_size;i++){
		if((buf[i]&0xFF) != 0){
			is_null = false;
			break;
		}
	}
	return is_null;
}
#endif
void print_hex(char *func,char *data, int len)
{
#if 1
	int i;
	char hex[128] = { 0 };
	//dzlog_debug("%s[%d sec]:\r\n", func,RTC->COUNT);
	for (i = 0; i < len; i++) {
		if (0 == i % 16) {
			dzlog_debug("%s\r\n", hex);
			memset(hex, 0, 128);
		}
		sprintf(hex + 3 * (i % 16), "%02x ", data[i]);
	}
	dzlog_debug("%s\r\n", hex);
#endif
}

static unsigned char get_active_res(int ulTimeOut/*millisecond*/)
{
	unsigned int res = 0;
	if(jd_om_task_notify_wait(&res,ulTimeOut) != osOK)	//timeout
		res = 0;
	return (unsigned char)res;
}

static void set_active_res(unsigned char res)
{
	jd_om_task_notify(&(uart_comm_des.thread_handle_send),res);
	//dzlog_debug("set active res as 0x%02x.\r\n", res);
}

unsigned char wait_response(unsigned char ActiveReq)
{
	//unsigned char ret = 1;
	unsigned char res;
	int cnt = WAIT_RESPONSE_TIME_OUT;
	unsigned char req = ActiveReq;

	if (REQ_TRANS_FILE_HEAD == req)
		cnt = WAIT_RESPONSE_TIME_OUT * 5;
	else if (REQ_TRANS_FILE_DATA== req) //mike:need consider not fetch !
		cnt = WAIT_RESPONSE_TIME_OUT * 10;
	else
		cnt = WAIT_RESPONSE_TIME_OUT;

	while (cnt--) {
		res = get_active_res(1);
		if (0 != res) {
			res &= 0xf;
			req &= 0xf;

			if (res == req)
				return 0;
		}
	}

	return 1;
}
#if 0
static FRESULT f_write_decrypted_aes_data(
	jd_om_comm *hdl,
	FIL* fp,			/* Pointer to the file object */
	char *buff,			/* Pointer to the data to be written */
	UINT btw,			/* Number of bytes to write */
	UINT* bw			/* Pointer to number of bytes written */
)
{
	FRESULT error;
    unsigned char iv[AES_BLOCKLEN];        // init vector
    struct AES_ctx ctx;
    unsigned int len;        // encrypt length (in multiple of AES_BLOCK_SIZE)
    unsigned char padding_len = 0;
    int i;

	if(!is_null_data(hdl->cipher,sizeof(hdl->cipher))){
		dzlog_debug("%s:decrypted data\r\n",__func__);

		if((btw%AES_BLOCKLEN) != 0){
			dzlog_error("%s:encrypted data len is not the multiple of AES block ???\r\n",__func__);
			return FR_INVALID_OBJECT;
		}
		for (i=0; i<AES_BLOCKLEN; ++i) {
			iv[i] = 0;
		}
		len = btw;
		AES_init_ctx_iv(&ctx, (uint8_t *)hdl->cipher, iv);
		AES_CBC_decrypt_buffer(&ctx, (uint8_t *)buff, len);
		//print_hex((char *)__func__,buff,len);	//before trim padding
		padding_len = buff[len-1];
		recv_file_des.aes_padding_len += padding_len;
		len -= padding_len;
		//print_hex((char *)__func__,buff,len);	//after trim padding
	#ifdef AES_CBC_256_DBG
		//eject test only
		dzlog_debug("%s:test eject !!!!!!!!!!!!!\r\n",__func__);
		return FR_INVALID_OBJECT;
	#endif
		error = f_write(fp, buff, len, bw);

		if(len != *bw)
			error = FR_INVALID_OBJECT;
	}
	else{
		dzlog_debug("%s:raw data\r\n",__func__);
		error = f_write(fp, buff, btw, bw);
		if(btw != *bw)
			error = FR_INVALID_OBJECT;

	}
	return error;
}

static void file_move_to_destination(char *file_path,FileType type)
{
	char old_file[MAX_FILE_PATH_SIZE]={0};
	unsigned char old_md5[MD5_SIZE] = { 0 };
	unsigned char new_md5[MD5_SIZE] = { 0 };
	unsigned char file_Dev = SYSDISK;
	unsigned long file_len = 0;
	FRESULT error;

	strncpy(old_file,file_path,strlen(file_path));
	memset(file_path,0,MAX_FILE_PATH_SIZE);
	switch(type){
		case upgrade_file:
			snprintf(file_path,MAX_FILE_PATH_SIZE,"%s/%s", UPGRADE_FILE_DIR,strrchr(old_file,'/')+1);
			break;

		case schedule_file:
			snprintf(file_path,MAX_FILE_PATH_SIZE,"%s/%s", SCHEDULE_FILE_DIR,strrchr(old_file,'/')+1);
			break;

		case picture_file:
			snprintf(file_path,MAX_FILE_PATH_SIZE,"%s/%s", PIC_FILE_DIR,strrchr(old_file,'/')+1);
			break;

		case voice_file:
			snprintf(file_path,MAX_FILE_PATH_SIZE,"/%s", strrchr(old_file,'/')+1);
			file_Dev = MP3DISK;
			break;

		default:
			dzlog_error("%s:recv unknown file type %d ???\r\n",__func__,type);
			return;
	}

#ifdef PRIVATE_MP3_FLASH_FS
	if(type == voice_file){
		file_len = get_file_size(SYSDISK,old_file);
		if(PrivateMp3PlayerValidFileSize(file_len)){
			PrivateMp3PlayerSaveFile(old_file);
		}
		else{
			dzlog_error("%s:file size '%d' too large,deny to save !!!\r\n",__func__,file_len);
		}
		ff_unlink(SYSDISK,old_file);
		return;
	}
#endif

	again:
	error = ff_rename(file_Dev,old_file,file_path);
	if(error){
		//fail
		dberr("%s: rename file '%s' to '%s' error=%d\r\n",__func__,old_file,file_path,error);
		if(error == FR_EXIST){	//file exist !
			get_md5(file_Dev,old_md5, old_file, 0);
			get_md5(file_Dev,new_md5, file_path, 0);
			if (0 != memcmp(old_md5, new_md5, MD5_SIZE)) {
				dzlog_error("%s:not the same file,remove '%s',try again...\r\n",__func__,file_path);
				ff_unlink(file_Dev,file_path);
				goto again;
			}
			else{
				dzlog_debug("%s:the same file,ignore rename to '%s'...\r\n",__func__,file_path);
				ff_unlink(file_Dev,old_file);
			}
		}
	}
	else{
		//ok
		dberr("%s: rename file '%s' to '%s' sucessful\r\n",__func__,old_file,file_path);
	}
	return;
}

static osStatus jd_master_com_send_exception_response(jd_om_comm *hdl,unsigned char type, void *data)
{
	int payload_size;
	unsigned char res_type;
	osStatus ret;

	res_type = (type&0x0F)|0xA0;
	payload_size = sizeof(RES_COMMON_T);

	int packet_size = sizeof(MSG_UART_HEAD_T) + payload_size + CHECKSUM_SIZE;
	MSG_UART_PACKAGE_T *pkt = jd_om_malloc(packet_size);

	pkt->head.start = START_CMD;
	pkt->head.slave = SLAVE_1;
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
#endif
int uart_sent_dumb()
{
	int ret = -1;
	int payload_len = 512;
	int pkt_len = sizeof(MSG_UART_HEAD_T) + payload_len + CHECKSUM_SIZE;
	static u32 packetid = 0;
	unsigned char *pt = jd_om_malloc(pkt_len);

	MSG_UART_HEAD_T *head = (MSG_UART_HEAD_T *)pt;

	head->start = START_CMD;
	head->type = RES_GET_TIME;
	head->payload_len = payload_len;
	head->packet_id = packetid++;

	memset(pt + sizeof(MSG_UART_HEAD_T), 0xde, payload_len);

	unsigned short checksum = crc16((char *)pt, pkt_len - CHECKSUM_SIZE);
	memcpy((char *)pt + pkt_len - CHECKSUM_SIZE, &checksum, CHECKSUM_SIZE);

	ret = jd_om_mq_send(&(uart_comm_des.send_queue), (void *)pt);
	if (ret) {
		dzlog_error("%s send msg error\n", __func__);
		jd_om_free(pt);
	}

	return 0;
}

u8 get_packet_id()
{
	static unsigned char uart_packet_id = 0;
	return uart_packet_id++;
}


int wait_battery_response(EventBits_t bat_evt, TickType_t timeout)
{
	EventBits_t bits;
	xEventGroupClearBits(BatteryResEvents, bat_evt);
	bits = xEventGroupWaitBits(BatteryResEvents, bat_evt, (BaseType_t)pdTRUE, (BaseType_t)pdTRUE, timeout);
	if (bits & bat_evt) {
		return 0;
	} else {
		dzlog_error("######## wait event %ld err %ld\r\n", bat_evt, bits);
		return -1;
	}
}


#define SECONDS_IN_A_DAY (86400U)
#define SECONDS_IN_A_HOUR (3600U)
#define SECONDS_IN_A_MINUTE (60U)
#define DAYS_IN_A_YEAR (365U)
#define YEAR_RANGE_START (1970U)
#define YEAR_RANGE_END (2099U)
#if 0
static void RTC_ConvertSecondsToDatetime(uint32_t seconds, rtc_datetime_t *datetime)
{
    assert(datetime);

    uint32_t x;
    uint32_t secondsRemaining, days;
    uint16_t daysInYear;
    /* Table of days in a month for a non leap year. First entry in the table is not used,
     * valid months start from 1
     */
    uint8_t daysPerMonth[] = {0U, 31U, 28U, 31U, 30U, 31U, 30U, 31U, 31U, 30U, 31U, 30U, 31U};

    /* Start with the seconds value that is passed in to be converted to date time format */
    secondsRemaining = seconds;

    /* Calcuate the number of days, we add 1 for the current day which is represented in the
     * hours and seconds field
     */
    days = secondsRemaining / SECONDS_IN_A_DAY + 1;

    /* Update seconds left*/
    secondsRemaining = secondsRemaining % SECONDS_IN_A_DAY;

    /* Calculate the datetime hour, minute and second fields */
    datetime->hour = secondsRemaining / SECONDS_IN_A_HOUR;
    secondsRemaining = secondsRemaining % SECONDS_IN_A_HOUR;
    datetime->minute = secondsRemaining / 60U;
    datetime->second = secondsRemaining % SECONDS_IN_A_MINUTE;

    /* Calculate year */
    daysInYear = DAYS_IN_A_YEAR;
    datetime->year = YEAR_RANGE_START;
    while (days > daysInYear)
    {
        /* Decrease day count by a year and increment year by 1 */
        days -= daysInYear;
        datetime->year++;

        /* Adjust the number of days for a leap year */
        if (datetime->year & 3U)
        {
            daysInYear = DAYS_IN_A_YEAR;
        }
        else
        {
            daysInYear = DAYS_IN_A_YEAR + 1;
        }
    }

    /* Adjust the days in February for a leap year */
    if (!(datetime->year & 3U))
    {
        daysPerMonth[2] = 29U;
    }

    for (x = 1U; x <= 12U; x++)
    {
        if (days <= daysPerMonth[x])
        {
            datetime->month = x;
            break;
        }
        else
        {
            days -= daysPerMonth[x];
        }
    }

    datetime->day = days;
}

static void jd_master_com_set_system_time(uint32_t timeSeconds)
{
	rtc_datetime_t date;
	uint32_t seconds = 0;

	seconds = timeSeconds + (60*60*8);	//transfer UTC to BeiJing Time.
	RTC_ConvertSecondsToDatetime(seconds, &date);

    /* RTC time counter has to be stopped before setting the date & time in the TSR register */
    RTC_StopTimer(RTC);

    /* Set RTC time to default */
    RTC_SetDatetime(RTC, &date);

    /* Enable at the NVIC */
    EnableIRQ(RTC_IRQn);

    /* Start the RTC time counter */
    RTC_StartTimer(RTC);
}

static uint32_t jd_master_com_get_system_time_second(void)
{
	uint32_t currSeconds = 0;

	//transfer current seconds to UTC time.
	currSeconds = RTC->COUNT - (60*60*8);	//transfer BeiJing Time to UTC.
	return currSeconds;
}

static void jd_master_com_clear_communication_cipher(void)
{
	uint32_t eeprom_data = 0x00000000U;
	int i=0;

	dzlog_debug("%s:clear Cipher sucessful\r\n",__func__);
	//clear cipher
	for(i=0;i<8;i++){
		EEPROM_WriteWord(EXAMPLE_EEPROM, EEPROM_ADDR_CIPHER+(i*4),eeprom_data);
	}
	//clear flag.
	EEPROM_WriteWord(EXAMPLE_EEPROM, EEPROM_ADDR_CIPHER_FLAG,eeprom_data);
}

static unsigned char jd_master_com_set_communication_cipher(unsigned char len,char *cipher)
{
	uint32_t eeprom_data = 0xFFFFFFFFU;
	int i=0;
	unsigned char ret = 0;	//default 0:ok.

	if(AES_KEYLEN != len){
		dzlog_error("%s:wrong key len[desired len %d but get len %d]!!!!!\r\n",
			__func__,AES_KEYLEN,len);
		ret = 1;
		return ret;
	}

	for(i=0;i<(len/4);i++){
		dzlog_debug("%s:Write EEPROM...%d Value = 0x%02X 0x%02X 0x%02X 0x%02X\r\n",__func__,
			i,cipher[i*4],cipher[i*4+1],cipher[i*4+2],cipher[i*4+3]);
		EEPROM_WriteWord(EXAMPLE_EEPROM, EEPROM_ADDR_CIPHER+(i*4),
			(cipher[i*4]<<24)|(cipher[i*4+1]<<16)|(cipher[i*4+2]<<8)|cipher[i*4+3]);
	}
	//read out the cipher
	for(i=0;i<(len/4);i++){
		eeprom_data = *((uint32_t *)(FSL_FEATURE_EEPROM_BASE_ADDRESS + EEPROM_ADDR_CIPHER +(i*4)));
		if(eeprom_data != ((cipher[i*4]<<24)|(cipher[i*4+1]<<16)|(cipher[i*4+2]<<8)|cipher[i*4+3])){
			dzlog_error("%s:Read EEPROM error...%d eeprom_Value = 0x%X,origin_Value = %02x %02x %02x %02x\r\n",
				__func__,i,eeprom_data,cipher[i*4],cipher[i*4+1],cipher[i*4+2],cipher[i*4+3]);
			ret = 1;
			break;
		}
	}
	//set the valid flag if write cipher ok.
	if(ret==0){
		EEPROM_WriteWord(EXAMPLE_EEPROM, EEPROM_ADDR_CIPHER_FLAG,EEPROM_CIPGER_FLAG_VALID);
		dzlog_debug("%s:Write Cipher to EEPROM sucessful\r\n",__func__);
	}
	return ret;
}

static bool jd_master_com_get_communication_cipher(unsigned char len,unsigned char *cipher)
{
	uint32_t eeprom_data = 0xFFFFFFFFU;
	int i=0;
	bool cipherSet = false;

	eeprom_data = *((uint32_t *)(FSL_FEATURE_EEPROM_BASE_ADDRESS + EEPROM_ADDR_CIPHER_FLAG));
	if(eeprom_data == EEPROM_CIPGER_FLAG_VALID){
		for(i=0;i<(len/4);i++){
			eeprom_data = *((uint32_t *)(FSL_FEATURE_EEPROM_BASE_ADDRESS + EEPROM_ADDR_CIPHER+(i*4)));
			cipher[i*4] = (eeprom_data>>24)&0xFF;
			cipher[i*4+1] = (eeprom_data>>16)&0xFF;
			cipher[i*4+2] = (eeprom_data>>8)&0xFF;
			cipher[i*4+3] = eeprom_data&0xFF;
		}
		cipherSet = true;
	}
	return cipherSet;
}

static unsigned char jd_master_com_set_dev_sn(unsigned char *sn)
{
	uint32_t eeprom_data = 0xFFFFFFFFU;
	unsigned char tmp_sn[12];
	int i=0;
	unsigned char ret = 0;	//default 0:ok.

	memset(tmp_sn,0,sizeof(tmp_sn));
	memcpy(tmp_sn,sn,10);
	for(i=0;i<10;i++){
		dzlog_debug("%s:Write EEPROM...%d Value = 0x%02X\r\n",__func__,i,tmp_sn[i]);
	}

	//write the sn into eeprom
	for(i=0;i<3;i++){
		EEPROM_WriteWord(EXAMPLE_EEPROM, EEPROM_ADDR_SN+(i*4),
			(tmp_sn[i*4]<<24)|(tmp_sn[i*4+1]<<16)|(tmp_sn[i*4+2]<<8)|tmp_sn[i*4+3]);
	}

	//read out the sn from eeprom
	for(i=0;i<3;i++){
		eeprom_data = *((uint32_t *)(FSL_FEATURE_EEPROM_BASE_ADDRESS + EEPROM_ADDR_SN +(i*4)));
		if(eeprom_data != ((tmp_sn[i*4]<<24)|(tmp_sn[i*4+1]<<16)|(tmp_sn[i*4+2]<<8)|tmp_sn[i*4+3])){
			dzlog_error("%s:Read EEPROM error...%d eeprom_Value = 0x%X,origin_Value = %02x %02x %02x %02x\r\n",
				__func__,i,eeprom_data,tmp_sn[i*4],tmp_sn[i*4+1],tmp_sn[i*4+2],tmp_sn[i*4+3]);
			ret = 1;
			break;
		}
	}
	//set the valid flag if write sn ok.
	if(ret==0){
		EEPROM_WriteWord(EXAMPLE_EEPROM, EEPROM_ADDR_SN_FLAG,EEPROM_SN_VALID_FLAG);
		dzlog_debug("%s:Write SN to EEPROM sucessful\r\n",__func__);
	}
	return ret;
}

bool jd_master_com_get_dev_sn(unsigned char *sn)
{
	uint32_t eeprom_data = 0xFFFFFFFFU;
	int i=0;
	unsigned char tmp_sn[12];
	bool snSet = false;

	eeprom_data = *((uint32_t *)(FSL_FEATURE_EEPROM_BASE_ADDRESS + EEPROM_ADDR_SN_FLAG));
	if(eeprom_data == EEPROM_SN_VALID_FLAG){
		for(i=0;i<3;i++){
			eeprom_data = *((uint32_t *)(FSL_FEATURE_EEPROM_BASE_ADDRESS + EEPROM_ADDR_SN +(i*4)));
			tmp_sn[i*4] = (eeprom_data>>24)&0xFF;
			tmp_sn[i*4+1] = (eeprom_data>>16)&0xFF;
			tmp_sn[i*4+2] = (eeprom_data>>8)&0xFF;
			tmp_sn[i*4+3] = eeprom_data&0xFF;
		}
		if(sn != NULL)
			memcpy(sn,tmp_sn,10);
		snSet = true;
	}

	return snSet;
}

static unsigned char jd_master_com_set_dev_id(char *device_id)
{
	uint32_t eeprom_data = 0xFFFFFFFFU;
	unsigned char tmp_dev_id[DEVICE_ID_LEN+1];
	int i=0;
	unsigned char ret = 0;	//default 0:ok.

	memset(tmp_dev_id,0,sizeof(tmp_dev_id));
	memcpy(tmp_dev_id,device_id,DEVICE_ID_LEN);
	for(i=0;i<DEVICE_ID_LEN;i++){
		dzlog_debug("%s:Write EEPROM...%d Value = %c\r\n",__func__,i,(char)tmp_dev_id[i]);
	}

	//write the device id into eeprom
	for(i=0;i<(DEVICE_ID_LEN/4);i++){
		EEPROM_WriteWord(EXAMPLE_EEPROM, EEPROM_ADDR_DEVID+(i*4),
			(tmp_dev_id[i*4]<<24)|(tmp_dev_id[i*4+1]<<16)|(tmp_dev_id[i*4+2]<<8)|tmp_dev_id[i*4+3]);
	}

	//read out the device id from eeprom
	for(i=0;i<(DEVICE_ID_LEN/4);i++){
		eeprom_data = *((uint32_t *)(FSL_FEATURE_EEPROM_BASE_ADDRESS + EEPROM_ADDR_DEVID +(i*4)));
		if(eeprom_data != ((tmp_dev_id[i*4]<<24)|(tmp_dev_id[i*4+1]<<16)|(tmp_dev_id[i*4+2]<<8)|tmp_dev_id[i*4+3])){
			dzlog_error("%s:Read EEPROM error...%d eeprom_Value = 0x%X,origin_Value = %02x %02x %02x %02x\r\n",
				__func__,i,eeprom_data,tmp_dev_id[i*4],tmp_dev_id[i*4+1],tmp_dev_id[i*4+2],tmp_dev_id[i*4+3]);
			ret = 1;
			break;
		}
	}
	//set the valid flag if write device id ok.
	if(ret==0){
		EEPROM_WriteWord(EXAMPLE_EEPROM, EEPROM_ADDR_DEVID_FLAG,EEPROM_DEVID_FLAG_VALID);
		dzlog_debug("%s:Write DeviceId to EEPROM sucessful\r\n",__func__);
	}
	return ret;
}

static bool jd_master_com_get_dev_id(unsigned char *device_id)
{
	uint32_t eeprom_data = 0xFFFFFFFFU;
	int i=0;
	unsigned char tmp_dev_id[DEVICE_ID_LEN+1];
	bool devIdSet = false;

	eeprom_data = *((uint32_t *)(FSL_FEATURE_EEPROM_BASE_ADDRESS + EEPROM_ADDR_DEVID_FLAG));
	if(eeprom_data == EEPROM_DEVID_FLAG_VALID){
		for(i=0;i<(DEVICE_ID_LEN/4);i++){
			eeprom_data = *((uint32_t *)(FSL_FEATURE_EEPROM_BASE_ADDRESS + EEPROM_ADDR_DEVID +(i*4)));
			tmp_dev_id[i*4] = (eeprom_data>>24)&0xFF;
			tmp_dev_id[i*4+1] = (eeprom_data>>16)&0xFF;
			tmp_dev_id[i*4+2] = (eeprom_data>>8)&0xFF;
			tmp_dev_id[i*4+3] = eeprom_data&0xFF;
		}
		memcpy(device_id,tmp_dev_id,DEVICE_ID_LEN);
		devIdSet = true;
	}

	return devIdSet;
}

static void jd_master_com_get_hw_ver(jd_om_comm *hdl,unsigned char *hw_ver)
{
	hw_ver[0] = hdl->hw_ver[0];
	hw_ver[1] = hdl->hw_ver[1];
	hw_ver[2] = hdl->hw_ver[2];
	hw_ver[3] = hdl->hw_ver[3];
}

static void jd_master_com_get_fw_ver(unsigned char *fw_ver)
{
	fetch_fw_ver(fw_ver);
}

static void jd_master_get_volume_level(unsigned char vol/*input:0~31*/,voice_volume_level *out_lvl)
{
	int i;

	for(i=0;i<sizeof(volume_table)/sizeof(volume_relation);i++){
		if(vol == volume_table[i].val){
			*out_lvl = volume_table[i].level;
			break;
		}
	}
}

static void jd_master_com_fill_device_info(jd_om_comm *hdl,RES_DEVICE_INFO_T **res)
{
	int material_num = 0,i = 0;
	RES_DEVICE_INFO_T *response = NULL;
	unsigned char dev_ready = 0;
	bool mute_on = false;
	unsigned char volume = 0;
	voice_volume_level volume_level = volume_mute;

#ifdef PLAY_SCHEDULE_LIST
	AdvMaterialInfo *adv_material = NULL;
	MaterialList *_Materal = NULL;
	if(jd_om_mutex_try_lock(&(hdl->uart_comm_des.schedule_mutex))){
		//no ready
		dzlog_error("%s:schedule no_ready wait@1?\r\n",__func__);
	}
	else{
		if(hdl->uart_comm_des.current_schedule == NULL){
			//no ready
			jd_om_mutex_unlock(&(hdl->uart_comm_des.schedule_mutex));
			dzlog_error("%s:schedule no_ready wait@2?\r\n",__func__);
		}

		else if(hdl->uart_comm_des.current_schedule->InCritical){
			//no ready
			jd_om_mutex_unlock(&(hdl->uart_comm_des.schedule_mutex));
			dzlog_error("%s:schedule in critical wait@3?\r\n",__func__);
		}
		else
			dev_ready = 1;
	}

	if(dev_ready){
		material_num = hdl->uart_comm_des.current_schedule->total_num;
		*res = jd_om_malloc(sizeof(RES_DEVICE_INFO_T) + material_num*sizeof(AdvMaterialInfo));
		//fill device status
		response = *res;
		response->ready_flag = 1;
		response->Encrypted = is_null_data(hdl->cipher,sizeof(hdl->cipher))?0:1;
		pic_play_get_mp3_volume_info(&mute_on,&volume);
		jd_master_get_volume_level(volume,&volume_level);
		response->volume = mute_on?0:volume_level;	//0:mute,1:low,2:middle,3:high.
		memset(response->sn,0,sizeof(response->sn));
		jd_master_com_get_dev_sn((unsigned char *)(response->sn));
		jd_master_com_get_dev_id((unsigned char *)(response->device_id));
		jd_master_com_get_hw_ver(hdl,response->hw_ver);
		jd_master_com_get_fw_ver(response->fw_ver);
		//fill schedule info
		response->schedule.schedule_id = hdl->uart_comm_des.current_schedule->scheduleId;
		memcpy(response->schedule.schedule_md5,hdl->uart_comm_des.current_schedule->file_md5,16);
		response->schedule.material_num = material_num;
		//file material array
		if(material_num > 0){
			adv_material = (AdvMaterialInfo *)((unsigned char *)response + sizeof(RES_DEVICE_INFO_T));
			_Materal = hdl->uart_comm_des.current_schedule->first_material;
			for(i=0;i<material_num;i++){
				adv_material[i].service_code = _Materal->material.service_code;
				//picture info.
				adv_material[i].pic_material_id = _Materal->material.materialId;
				adv_material[i].pic_play_count = _Materal->material.playCount;
				memcpy(adv_material[i].pic_md5,_Materal->material.file_md5,16);
				//voice info.
				adv_material[i].voice_material_id = _Materal->material.voice_materialId;
				adv_material[i].voice_play_count = FILE_MD5_IS_NULL(_Materal->material.voice_file_md5)?0:(_Materal->material.playCount);
				memcpy(adv_material[i].voice_md5,_Materal->material.voice_file_md5,16);
				_Materal = _Materal->next;
			}
		}
		jd_om_mutex_unlock(&(hdl->uart_comm_des.schedule_mutex));
	}
	else{
		*res = jd_om_malloc(sizeof(RES_DEVICE_INFO_T));
		response = *res;
		response->ready_flag = 0;
	}
#endif
}
#endif

static char recv_data_dispatch(jd_om_comm *hdl,char *pt,bool *file_trans,UINT *trans_timeout_cnt)
{
	char payload[MAX_QUEUE_ELEMENT_SIZE] = { 0 };
	MSG_UART_HEAD_T* head = (MSG_UART_HEAD_T*)pt;
	static unsigned char last_session_id_req = 255;
	static unsigned char last_session_id_res = 255;
	//static unsigned int old_pkt_id = 1;
	unsigned int payload_len = 0;
	unsigned char type;

	// 获取start字段
	unsigned char start = head->start;

	//	判断start字段值是否正�?
	if (START_CMD != start) {
		dzlog_error("recv invalid packet\r\n");
		goto FREE;
	}

	// 获取type字段
	type = head->type;
	//dzlog_debug("recv type %02x\r\n", type);

	//判断start字段值是否正�?
	switch(get_cmd_typte(type)) {
		case TYPE_INVALID:
			goto FREE;
		case TYPE_RES:
			set_active_res(type);
			if(head->packet_id == last_session_id_res){
				dzlog_error("recv repeat res packet %d\r\n", last_session_id_res);
				goto FREE;
			} else{
				last_session_id_res = head->packet_id;
			}
			break;
		case TYPE_REQ:
			if(head->packet_id == last_session_id_req){
				dzlog_error("recv repeat req packet %d\r\n", last_session_id_req);
				goto FREE;
			} else{
				last_session_id_req = head->packet_id;
			}
			break;
		default:
			break;
	}

	// 获取payload_len字段
	payload_len = head->payload_len;

	// 校验payload_len合法
	if (payload_len >= MAX_QUEUE_ELEMENT_SIZE) {
		dzlog_error("recv invalid payload_len:%d\r\n",payload_len);
		goto FREE;
	}

	// 获取payload
	memset(payload, 0, MAX_QUEUE_ELEMENT_SIZE);
	memcpy(payload, pt + sizeof(MSG_UART_HEAD_T), payload_len);


	//获取checksum
	unsigned short chksum;
	memcpy(&chksum, pt + sizeof(MSG_UART_HEAD_T) + payload_len, sizeof(chksum));
	if (chksum != crc16(pt, sizeof(MSG_UART_HEAD_T) + payload_len)) {
		dzlog_error("checksum wrong\r\n");
		goto FREE;
	}

	switch (type) {
	case REQ_DEVICE_INFO:
	case REQ_SET_SN:
	case REQ_GET_TIME:
	case REQ_SET_TIME:
	case REQ_FLASH_LED:
	case REQ_SLOT_LED:
	case REQ_SLOT_ELOCK:
	case REQ_SLOT_POWER:
	case REQ_SLOT_KEY_STAT:
	case REQ_BATTERY_ENCRYPT:
	case REQ_BATTERY_INFO:
	case REQ_GPRS_MODULE_INFO:
	case REQ_GPRS_CONNECT:
	case REQ_DEVICE_AGEING:
	case REQ_ENV_TEMPRATURE:
	case REQ_TRANS_FILE_HEAD:
	case REQ_TRANS_FILE_DATA:
	case REQ_TRANS_FILE_END:
		{
			add_factory_test_item(pt);
			return 0;

		}

		case RES_BAT_SET_SN_PSW:
		{
			if (payload_len != sizeof(RES_BAT_SET_SN_PSW_T)) {
				goto WRONG_PAYLOAD_LEN;
			}
			RES_BAT_SET_SN_PSW_T *res = (RES_BAT_SET_SN_PSW_T *)(pt + sizeof(MSG_UART_HEAD_T));
			dzlog_debug("++++++set battery sn res %d\r\n", res->code);
			memcpy(&br_set_sn, res, sizeof(RES_BAT_SET_SN_PSW_T));
			xEventGroupSetBits(BatteryResEvents, BAT_EVT_SET_SN);
			break;
		}
		case RES_BAT_GET_INFO:
		{
			if (payload_len != sizeof(RES_BAT_GET_INFO_T)) {
				goto WRONG_PAYLOAD_LEN;
			}
			RES_BAT_GET_INFO_T *res = (RES_BAT_GET_INFO_T *)(pt + sizeof(MSG_UART_HEAD_T));

			if (res->sn_len <= sizeof(res->sn)) {
			dzlog_debug("++++++get battery info sn len %d sn %s temp %d vol_h %d vol_l %d ratio %d\r\n",
				res->sn_len,		//sn 有效长度
				res->sn,		//sn
				res->Temp,			//温度: 16进制温度值（单位：摄氏度�?偏移�?40(避免负温�?
				res->Vol_H,		//电压：高�?
				res->Vol_L,		//电压：低�?
				res->ratio);		//16进制
			} else {
				dzlog_error("++++++get battery info invalid battery sn len %d\r\n", res->sn_len);
			}

			memcpy(&br_get_info, res, sizeof(RES_BAT_GET_INFO_T));
			xEventGroupSetBits(BatteryResEvents, BAT_EVT_GET_INFO);
			break;
		}
		case RES_BAT_ENCODE:
		{
			if (payload_len != sizeof(RES_BAT_ENCODE_T)) {
				goto WRONG_PAYLOAD_LEN;
			}
			RES_BAT_ENCODE_T *res = (RES_BAT_ENCODE_T *)(pt + sizeof(MSG_UART_HEAD_T));
			dzlog_debug("++++++battery encode res %d\r\n", res->code);
			memcpy(&br_encode, res, sizeof(RES_BAT_ENCODE_T));
			xEventGroupSetBits(BatteryResEvents, BAT_EVT_ENCODE);
			break;
		}
		case RES_BAT_DECODE:
		{
			if (payload_len != sizeof(RES_BAT_DECODE_T)) {
				goto WRONG_PAYLOAD_LEN;
			}
			RES_BAT_DECODE_T *res = (RES_BAT_DECODE_T *)(pt + sizeof(MSG_UART_HEAD_T));
			dzlog_debug("++++++battery decode res %d \r\n", res->code);
			memcpy(&br_decode, res, sizeof(RES_BAT_DECODE_T));
			xEventGroupSetBits(BatteryResEvents, BAT_EVT_DECODE);
			break;
		}
		case RES_BAT_VIRTUAL_PWR_INFO:
		{

			if (payload_len != sizeof(RES_BAT_VIRTUAL_PWR_T)) {
				goto WRONG_PAYLOAD_LEN;
			}
			RES_BAT_VIRTUAL_PWR_T *res = (RES_BAT_VIRTUAL_PWR_T *)(pt + sizeof(MSG_UART_HEAD_T));
			dzlog_debug("++++++battery virtual info cnt1 %d cnt2 %d ratio %d last %d discharging %d \r\n",
				res->data[0], res->data[1], res->data[2], res->data[3], res->data[4]);

			memcpy(&br_virt_info, res, sizeof(RES_BAT_VIRTUAL_PWR_T));
			xEventGroupSetBits(BatteryResEvents, BAT_EVT_VIRT_PWR_INFO);
			break;
		}
		case RES_BAT_DISCHARGE_LEVEL:
		{
			if (payload_len != sizeof(RES_BAT_DISCHARGE_LEVEL_T)) {
				goto WRONG_PAYLOAD_LEN;
			}
			RES_BAT_DISCHARGE_LEVEL_T *res = (RES_BAT_DISCHARGE_LEVEL_T *)(pt + sizeof(MSG_UART_HEAD_T));
			dzlog_debug("++++++battery discharge level res %d\r\n", res->code);
			memcpy(&br_dis_level, res, sizeof(RES_BAT_DISCHARGE_LEVEL_T));
			xEventGroupSetBits(BatteryResEvents, BAT_EVT_DISCHG_LEVEL);
			break;
		}
		case RES_BAT_CHARGE_STATUS:
		{
			if (payload_len != sizeof(RES_BAT_CHARGE_STATUS_T)) {
				goto WRONG_PAYLOAD_LEN;
			}
			RES_BAT_CHARGE_STATUS_T *res = (RES_BAT_CHARGE_STATUS_T *)(pt + sizeof(MSG_UART_HEAD_T));
			dzlog_debug("++++++battery charge status level %d status %d\r\n", res->data[0], res->data[1]);
			memcpy(&br_chg_stat, res, sizeof(RES_BAT_CHARGE_STATUS_T));
			xEventGroupSetBits(BatteryResEvents, BAT_EVT_CHARGE_STAT);
			break;
		}
		case RES_BAT_PROTOCAL_VERSION:
		{
			if (payload_len != sizeof(RES_BAT_PROTOCAL_VERSION_T)) {
				goto WRONG_PAYLOAD_LEN;
			}
			RES_BAT_PROTOCAL_VERSION_T *res = (RES_BAT_PROTOCAL_VERSION_T *)(pt + sizeof(MSG_UART_HEAD_T));
			dzlog_debug("++++++battery protocal version len %d version %d.%d.%d\r\n",
				res->ver_len, res->ver[0], res->ver[1], res->ver[2]);
			memcpy(&br_pro_vers, res, sizeof(RES_BAT_PROTOCAL_VERSION_T));
			xEventGroupSetBits(BatteryResEvents, BAT_EVT_PROT_VERS);
			break;
		}
		case RES_BAT_PASSWD_CHKSUM:
		{
			if (payload_len != sizeof(RES_BAT_PASSWD_CHKSUM_T)) {
				goto WRONG_PAYLOAD_LEN;
			}
			RES_BAT_PASSWD_CHKSUM_T *res = (RES_BAT_PASSWD_CHKSUM_T *)(pt + sizeof(MSG_UART_HEAD_T));
			dzlog_debug("++++++battery crc 0x%02x 0x%02x\r\n", res->crc[0], res->crc[1]);
			memcpy(&br_psw_chk, res, sizeof(RES_BAT_PASSWD_CHKSUM_T));
			xEventGroupSetBits(BatteryResEvents, BAT_EVT_PSW_CHKSUM);
			break;
		}

		default:
			break;
	}

FREE:
	jd_om_free(pt);
	return 0;

WRONG_PAYLOAD_LEN:
	dzlog_error("payload len dismatch type\r\n");
	jd_om_free(pt);
	return 0;
}

#if 0

		//recevicing file here.
		case REQ_TRANS_FILE_HEAD:
		{
			REQ_TRANS_FILE_HEAD_T *req = (REQ_TRANS_FILE_HEAD_T *)(pt + sizeof(MSG_UART_HEAD_T));
			if(strlen(recv_file_des.file_path)>0){
				dzlog_error("###############last transfer file '%s' not closed#############\r\n",
					recv_file_des.file_path);
				f_sync(&(recv_file_des.file_handle));
				f_close(&(recv_file_des.file_handle));
			}
			memset(recv_file_des.version,0,4);
			memset(recv_file_des.file_path, 0, MAX_FILE_PATH_SIZE);
			memset(recv_file_des.md5, 0, MD5_SIZE);
			memcpy(recv_file_des.md5, req->md5, MD5_SIZE);
			recv_file_des.size = req->size;
			recv_file_des.type = req->type;
			recv_file_des.aes_padding_len = 0;	//init aes padding length.
			old_pkt_id = 1;
			if((recv_file_des.type == voice_file) && (!ends_with(req->file_name,".mp3"))){
				dzlog_error("voice type mismatch with file name '%s'###\r\n",req->file_name);
			}
			else{
				jd_master_com_send_play_msg(hdl,type,(void *)req);
				file_transfer_start(hdl,req->file_name);
				*trans_timeout_cnt = 0;
				*file_trans = true;
				has_send_res = true;
			}
			break;
		}

		case REQ_TRANS_FILE_DATA:
		{
			REQ_TRANS_FILE_DATA_T *req = (REQ_TRANS_FILE_DATA_T *)(pt + sizeof(MSG_UART_HEAD_T));
			if (old_pkt_id != req->packet_id) {
				old_pkt_id = req->packet_id;
				file_transfer_going(hdl,req->packet_id, (char *)&(req->packet_id) + 4, payload_len - 4);
				*trans_timeout_cnt = 0;
				has_send_res = true;
			}
			else{
				dzlog_error("recv a same fragment id=%d\r\n",old_pkt_id);
			}
			break;
		}

		case REQ_TRANS_FILE_END:
		{
			file_transfer_end(hdl);
			*trans_timeout_cnt = 0;
			has_send_res = true;
			break;
		}

		case REQ_NOTIFY_ALL_FILE_COMPLETED:
		{
			RES_NOTIFY_ALL_FILE_COMPLETED_T res;

			//send to play task to process
			jd_master_com_send_play_msg(hdl,type,NULL);
			//send response to host
			res.code = 0;
			jd_master_com_send_response(hdl,type,(void *)&res);
			*trans_timeout_cnt = 0;
			*file_trans = false;
			has_send_res = true;
			break;
		}

		default:
			break;
	}
#endif

void uart_recv_queue_task(void const *p)
{
	jd_om_comm *hdl = (jd_om_comm *)p;
	void *pt = NULL;
	unsigned int disconnect_cnt = 0,lose_times = 0;
	unsigned int loseMaximumSec = 0;
	bool ever_disconnect_notify = false;
	//REQ_SHOW_T req;
	bool fileTransering = false;
	UINT fileTransTimeCnt = 0;

	dzlog_info("%s start\r\n", __func__);

	while (1) {
		//daemon_flag_clear(uart_daemon);
		//dzlog_debug("%s:@@1@@\r\n",__func__);
		jd_om_mq_recv(&(uart_comm_des.recv_queue), (void **)&pt, 1000/*millisecond timeout*/);

		//dzlog_debug("%s:##2##\r\n",__func__);
		#if 0
		if(fileTransering){
			if(fileTransTimeCnt++>50){
				//we've too much time not received host data transfer,so force to interrupt it.
				dzlog_debug("uart_recv_queue_task>>>wait data transfer timeout,force to interrupt it!!!\r\n");
				jd_master_com_send_play_msg(hdl,REQ_NOTIFY_ALL_FILE_COMPLETED,NULL);
				fileTransering = false;
				fileTransTimeCnt = 0;
			}
		}
		#endif

		if(pt == NULL){
			//printf("%s:%d\r\n", __func__, __LINE__);
			//dzlog_error("%s: timeout\r\n",__func__);
			if(lose_times>0)
				loseMaximumSec = 420;	// seconed time or later detection:5 minutes + 2 minutes alarm.
			else
				loseMaximumSec = 300;	// first time detection:5 minutes timeout.
			if(disconnect_cnt++ >= loseMaximumSec){	// only trigger one time.
				//dzlog_debug("%s:##lose connect %d seconds with host##\r\n",__func__,loseMaximumSec);
				//req.service_code = srv_code_connect_fail;
				//req.keep_alive = 0;
				//jd_master_com_send_play_msg(hdl,REQ_SHOW,&req);
				ever_disconnect_notify = true;
				disconnect_cnt = 0;	//stop counter
				lose_times++;
			}
		}
		else{
			if(ever_disconnect_notify){
				//req.service_code = srv_code_default;
				//req.keep_alive = 5;
				//jd_master_com_send_play_msg(hdl,REQ_SHOW,&req);
				ever_disconnect_notify = false;
			}
			disconnect_cnt = 0;	//stop counter
			lose_times = 0;
			if(strncmp((char *)pt,ReqNameByAT,strlen(ReqNameByAT))==0){
				dzlog_debug("%s:recv req AT name\r\n",__func__);
				jd_om_free(pt);
			}
			else{
				recv_data_dispatch(hdl,(char *)pt,&fileTransering,&fileTransTimeCnt);
			}
		}
	}
}

void uart_send_queue_task(void const *p)
{
	jd_om_comm *hdl = 0;//(jd_om_comm *)p;
	int slave = SLAVE_1;
	int ret;
	int lens;
	void *pt = NULL;
	jd_om_comm_addr to_addr;
	char slave_addr[16] = { 0 };
	int cnt_resend = 0;
	//int send_err = 0;
	unsigned char active_req = 0;

	dzlog_info("%s start\r\n", __func__);

	//char buf[128];
	static u32 num_ok = 0, num_fail = 0;
#if 0
	while(1) {
		//osDelay(1000);
		//jz_uart_write_ex(0, "hello\r\n", 7, 1000);
		memset(buf, 128, 0);
		ret = jz_uart_read_ex(0, buf, 128, 1000);
		if (ret)
			print_hex((char *)__func__,buf, ret);
			//printf("recv : %s\r\n", buf);
		else
			printf("recv no data\r\n");
	}
#endif
	while (1) {
		MSG_UART_HEAD_T *head = NULL;
		char res;
		jd_om_mq_recv(&(uart_comm_des.send_queue), (void **)&pt, 0);
		if(pt == NULL){
			dzlog_error("%s: invalid message: NULL\r\n",__func__);
			continue;
		}

		head = (MSG_UART_HEAD_T *)pt;
		lens = sizeof(MSG_UART_HEAD_T) + head->payload_len + CHECKSUM_SIZE;
		//print_hex((char *)__func__,pt, lens);
		res = head->type;
		slave = head->slave;
		sprintf(slave_addr, "0.%d.0", slave);
		to_addr.addr = tlc_iaddr(slave_addr);

#if 1
		mutex_uart_switch(slave);
		hdl = &uart_channels[slave];
#else
		hdl = mutex_uart_switch(slave);
		if (NULL == hdl) {
			printf("uart switch err\r\n");
			goto SEND_FREE;
		}
#endif

		switch (get_cmd_typte(res)) {
			case TYPE_INVALID:
			{
				dzlog_error("invalid type 0x%02x\n", res);
				jd_om_free(pt);
				continue;
			}
			case TYPE_RES:
			{
				ret = jd_om_send(hdl, &to_addr, pt, lens, 0);
				if (ret <= 0)
					dzlog_error("send to batt uart fail\n");
				continue;
			}
			case TYPE_REQ:
				goto SEND_REQ;
			default:
				break;
		}

SEND_REQ:
		active_req = head->type;
		//set_active_req(head->type);
		cnt_resend = 1;

RESEND_DATA:
		set_active_res(0);

		active_req = head->type;

		dzlog_debug("send msg\r\n");

		//print_hex((char *)__func__, pt, lens);
		ret = jd_om_send(hdl, &to_addr, pt, lens, 0);
		if (ret <= 0) {
			num_fail++;
			dzlog_error("send fail count %d\r\n", cnt_resend);
			if (res == REQ_TRANS_FILE_DATA) {
				if (cnt_resend++ <= 3) {
					osDelay(2000);
					goto RESEND_DATA;
				}
			}
		} else {
			if (1 == wait_response(active_req))
				dzlog_error("response time out>>>>>>\n");
			num_ok++;
		}

		dzlog_debug("send %d err/ok : %d/%d\r\n", lens, num_fail, num_ok);
		set_active_res(0xa0 | (0xf & active_req));
SEND_FREE:
		jd_om_free(pt);
	}
}





/*!
 * @brief uart receive Task responsible for loopback.
 */
void uart_recv_task(void const *p)
{
	jd_om_comm *uart_hdl = (jd_om_comm *)p;
	int r_len;
	jd_om_comm_addr from_addr;
	char buf[MAX_QUEUE_ELEMENT_SIZE] = { 0 };
	char *pt;
	dzlog_info("uart_recv_task start>>>\r\n");

	//task of receving.
	while (1) {
		memset(buf, 0, MAX_QUEUE_ELEMENT_SIZE);
//		uart_hdl = &uart_channels[get_uart_channel()];
//		printf("recv hdl 0x%x uart2 0x%x uart6 0x%x\r\n", uart_hdl->ptlc->pllc->fd, uart_channels[0].ptlc->pllc->fd, uart_channels[1].ptlc->pllc->fd);
		r_len = jd_om_recv(uart_hdl, &from_addr, buf, MAX_QUEUE_ELEMENT_SIZE);
		if (0 == r_len)
			continue;

		if ((r_len > sizeof(MSG_UART_HEAD_T)) ||
			((r_len == strlen(ReqNameByAT)) && (strncmp(buf,ReqNameByAT,r_len)==0))) {
			//print_hex((char *)__func__,buf, r_len);
			pt = jd_om_malloc(r_len);
			memcpy(pt, buf, r_len);
			jd_om_mq_send(&(uart_comm_des.recv_queue), pt);
			//dzlog_debug("%s:send recv queue end...\r\n",__func__);
		}
		else{
			dzlog_error("recv msg from uart. invalid len:%d\r\n", r_len);
		}
	}
}

#if 0
void eeprom_setting_show_test(void)
{
	uint32_t eeprom_data = 0xFFFFFFFFU;
	int i=0;

	dzlog_info("\r\n");
	for(i=0;i<(EEPROM_ADDR_END/4);i++){
		eeprom_data = *((uint32_t *)(FSL_FEATURE_EEPROM_BASE_ADDRESS + (i*4)));
		dzlog_info("%s::::::[%02x %02x %02x %02x][byte %d]\r\n",__func__,
			(eeprom_data>>24)&0xFF,
			(eeprom_data>>16)&0xFF,
			(eeprom_data>>8)&0xFF,
			eeprom_data&0xFF,
			i*4);
	}
}
#endif


#ifdef AES_CBC_256_DBG
static void aes_cbc_encrypt_desrypt_testing(char *in_string)
{
	uint8_t key[] = { 0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81,
					  0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4 };
	unsigned char iv[AES_BLOCKLEN];		 // init vector
	struct AES_ctx ctx;
	unsigned char *in;
	unsigned int len;		 // encrypt length (in multiple of AES_BLOCK_SIZE)
	unsigned char padding_len = 0;
	int i;

	dzlog_info("################aes_cbc test start################\r\n");
	dzlog_info("input string: [len=%d,%s]\r\n",strlen(in_string),in_string);
	len = 0;
	/*
	padding PKCS7 is recommendable.
	01
	02 02
	03 03 03
	04 04 04 04
	05 05 05 05 05
	06 06 06 06 06 06
	etc.
	*/
	if ((strlen(in_string) + 1) % AES_BLOCKLEN == 0) {
		len = strlen(in_string) + 1;
	} else {
		len = ((strlen(in_string) + 1) / AES_BLOCKLEN + 1) * AES_BLOCKLEN;
	}

	 padding_len = len-strlen(in_string);

	// set the input string
	in = (unsigned char*)jd_om_malloc(len);
	if (in == NULL) {
		dzlog_error("Unable to allocate memory for input_string\r\n");
		return;
	}
	memset(in,padding_len,len);
	strncpy((char*)in, in_string, strlen(in_string));

   dzlog_info("original string hex[len=%d,padding_len=%d]: \r\n",len,padding_len);
   for(i=0;i<len;i++){
	dzlog_info("%02x ",(unsigned char)in[i]);
	if((i+1)%16==0)
		dzlog_info("\r\n");
   }
   //dzlog_info("\r\n");

	//encrypt start(iv will change)
	for (i=0; i<AES_BLOCKLEN; ++i) {
		iv[i] = 0;
	}
	AES_init_ctx_iv(&ctx, key, iv);
	AES_CBC_encrypt_buffer(&ctx, in, len);
	dzlog_info("CBC encrypted hex[len=%d]: \r\n",len);
   for(i=0;i<len;i++){
	dzlog_info("%02x ",(unsigned char)in[i]);
	if((i+1)%16==0)
		dzlog_info("\r\n");
   }
   //dzlog_info("\n");

   //decrypt start(iv will change)
	for (i=0; i<AES_BLOCKLEN; ++i) {
		iv[i] = 0;
	}
   AES_init_ctx_iv(&ctx, key, iv);
   AES_CBC_decrypt_buffer(&ctx, in, len);
   dzlog_info("CBC decrypted hex: \r\n");
   for(i=0;i<len;i++){
	dzlog_info("%02x ",(unsigned char)in[i]);
	if((i+1)%16==0)
		dzlog_info("\r\n");
   }
   //real data after trim the padding
   padding_len = in[len-1];
   len -= padding_len;
   dzlog_info("CBC decrypted hex after trim padding: \r\n");
   for(i=0;i<len;i++){
	dzlog_info("%02x ",(unsigned char)in[i]);
	if((i+1)%16==0)
		dzlog_info("\r\n");
   }
   dzlog_info("\r\n");
   memset(&(in[len]),0,padding_len);

   dzlog_info("CBC decrypted string: [%s]\r\n",in);
   dzlog_info("################aes_cbc test end################\r\n");
   jd_om_free(in);
}
#endif


int stop_uart_service()
{

#if 1
	for (int i = 0; i < UART_CNT; i++) {
		osThreadTerminate(uart_comm_des.thread_uart_recv[i]);
	}

#else
	for (int i = 0; i < UART_COM_MAX; i++) {
		if (uart_comm_des.thread_uart_recv[i]) {
		osThreadTerminate(uart_comm_des.thread_uart_recv[i]);
			uart_comm_des.thread_uart_recv[i] = 0;
		}
	}
#endif

	osThreadTerminate(uart_comm_des.thread_handle_send);
	osThreadTerminate(uart_comm_des.thread_handle_recv);

#if 1
	for (int i=0; i < UART_CNT; i++) {
		if (uart_channels[i].ptlc)
			jd_om_comm_close(&uart_channels[i]);
	}
#else
	for (int i=0; i < UART_COM_MAX; i++) {
		if (uart_comms[i].ptlc)
			jd_om_comm_close(&uart_comms[i]);
	}
#endif

	jd_om_delete_mq(&(uart_comm_des.recv_queue));
	jd_om_delete_mq(&(uart_comm_des.send_queue));
	jd_om_mutex_delete(&uart_comm_des.mutex_active_req);
	jd_om_mutex_delete(&uart_comm_des.mutex_active_res);
	jd_om_mutex_delete(&mutex_channel_select);
	vEventGroupDelete(BatteryResEvents);

	return 0;
}

int start_uart_service()
{
	int ret = 0;
	jd_om_comm_addr local_addr;
	jd_om_comm_addr addr_mask;

	if(jd_om_mq_create(&(uart_comm_des.send_queue),MAX_QUEUE_SIZE) != osOK){
		dberr("create send queue fail.\r\n");
		return -1;
	}

	if(jd_om_mq_create(&(uart_comm_des.recv_queue),MAX_QUEUE_SIZE) != osOK){
		dberr("create recv queue fail.\r\n");
		return -1;
	}

	if (jd_om_mutex_create(&(uart_comm_des.mutex_active_req)) != osOK){
		dzlog_error("mutex_active_req init error\r\n");
		vTaskSuspend(NULL);
	}

	if (jd_om_mutex_create(&(uart_comm_des.mutex_active_res)) != osOK){
		dzlog_error("mutex_active_res init error\r\n");
		vTaskSuspend(NULL);
	}

	if (jd_om_mutex_create(&(mutex_channel_select)) != osOK){
		dzlog_error("mutex_chanel_select init error\r\n");
		vTaskSuspend(NULL);
	}



	BatteryResEvents = xEventGroupCreate();
	if (NULL == BatteryResEvents) {
		dzlog_error("create battery events error\r\n");
		vTaskSuspend(NULL);
	}

#if 0
	//get communication cipher.
	memset(uart_hdl->cipher,0,sizeof(uart_hdl->cipher));
	jd_master_com_get_communication_cipher(sizeof(uart_hdl->cipher),uart_hdl->cipher);
#endif





	//printf("uart4 0x%x uart6 0x%x\r\n", uart_channels[0].ptlc->pllc->fd, uart_channels[1].ptlc->pllc->fd);

#if 1


	//start_factory_test_service();


	/* definition and creation of uartSendQueueTask */
	osThreadDef(uartSendQueueTask, uart_send_queue_task, osPriorityNormal, 0, 1024);
	uart_comm_des.thread_handle_send = osThreadCreate(osThread(uartSendQueueTask), 0);
	if(uart_comm_des.thread_handle_send == NULL){
		printf("create send thread fail.\r\n");
		while (1)
			;
	} else {
		printf("Uart_send_queue_task create successful !\r\n");
	}

	/* definition and creation of uartRecvQueueTask */
	osThreadDef(uartRecvQueueTask, uart_recv_queue_task, osPriorityNormal, 0, 5120);
	uart_comm_des.thread_handle_recv = osThreadCreate(osThread(uartRecvQueueTask), 0);
	if(uart_comm_des.thread_handle_recv == NULL){
		printf("create recv thread fail.\r\n");
		while (1);
	} else {
		printf("Uart_recv_queue_task create successful !\r\n");
	}


	start_factory_test_service();

	local_addr.addr = tlc_iaddr("1.0.0");
	addr_mask.addr = tlc_iaddr("255.0.0");
	ret = jd_om_comm_open(&uart_channels[1], &local_addr, &addr_mask, 6);
	if (0 != ret) {
		dzlog_error("open uart number %d fail ret %d.\r\n", 4, ret);
		vTaskSuspend(NULL);
	}


	THREAD_DEF(uartRecv, 1, uart_recv_task, osPriorityNormal, 0, 1024);
	uart_comm_des.thread_uart_recv[1] = osThreadCreate(TRHEAD_NAME_ID(uartRecv, 1), &uart_channels[1]);
	if (NULL == uart_comm_des.thread_uart_recv[1]) {
		printf("create Uart recv Task %d failed!.\r\n", 1);
		while (1);
	} else {
		printf("Uart recv task %d create successful !\r\n", 1);
	}



#if 0
	printf("remember only one recv task\r\n");
	/* definition and creation of uartRecv */
	for (int i = 0; i < UART_CNT; i++) {
		THREAD_DEF(uartRecv, i, uart_recv_task, osPriorityNormal, 0, 1024);
		uart_comm_des.thread_uart_recv[i] = osThreadCreate(TRHEAD_NAME_ID(uartRecv, i), &uart_channels[i]);
		if (NULL == uart_comm_des.thread_uart_recv[i]) {
			printf("create Uart recv Task %d failed!.\r\n", i);
			while (1);
		} else {
			printf("Uart recv task %d create successful !\r\n", i);
		}
	}
#endif

#else
	osThreadDef(uartTask, uart_task, osPriorityNormal, 0, 5120);
	if (NULL == osThreadCreate(osThread(uartTask), uart_hdl)) {
		printf("create Uart Task failed!.\r\n");
		while (1);
	} else {
		printf("Uart task create successful !\r\n");
	}
#endif

#ifdef AES_CBC_256_DBG
	aes_cbc_encrypt_desrypt_testing("123456789012345");		//15 bytes
	aes_cbc_encrypt_desrypt_testing("1234567890123456");	//16 bytes
	aes_cbc_encrypt_desrypt_testing("12345678901234567");	//17 bytes
#endif


	return 0;
}

//HOOK function to detect task stack overflow!
void vApplicationStackOverflowHook( TaskHandle_t xTask, signed char *pcTaskName )
{
     dzlog_error("task:[%s] ######stack overflow######\r\n", pcTaskName);
}

