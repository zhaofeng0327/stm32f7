#include "stdio.h"
#include "string.h"


#define DEVICE_FILE_PATH "0:/device.ini"

#if 0
#include "fatfs.h"
int write_sn(char *sn, unsigned int sn_len)
{
	FRESULT res;
	FIL fp;
	UINT bw;

	printf("write file test......\r\n");
	res = f_open(&fp, DEVICE_FILE_PATH, FA_CREATE_ALWAYS | FA_WRITE);
	if (res != FR_OK) {
		printf("open file error : %d\r\n", res);
	} else {
		res = f_write(&fp, sn, sn_len, &bw);/* Write it to the dst file */
		if (res == FR_OK)
			printf("write data ok! %d\r\n", bw);
		else
			printf("write data error : %d\r\n", res);

		/*close file */
		f_close(&fp);
	}
	return 0;
}

int read_sn(char *buf)
{
	FRESULT res;
	FIL fp;
	UINT br;
	printf("read file test......\r\n");
	res = f_open(&fp, DEVICE_FILE_PATH, FA_OPEN_EXISTING | FA_READ);
	if (res != FR_OK) {
		printf("open file error : %d\r\n", res);
	} else {
		res = f_read(&fp, buf, 10, &br);
		if (res == FR_OK) {
			printf("read data num : %d\r\n", br);
			printf("%s\r\n", buf);
		} else {
			printf("read file error : %d\r\n", res);
		}
		/*close file */
		f_close(&fp);
	}
	return 0;

}
void get_hw_version(char *version)
{
	if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10))
		version[0] = 1;
	else
		version[0] = 0;

	if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_9))
		version[1] = 1;
	else
		version[1] = 0;

	if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12))
		version[2] = 1;
	else
		version[2] = 0;
}


#else

char dev_sn[16];

int write_sn(unsigned char *sn, unsigned int sn_len)
{
	snprintf(dev_sn, sn_len, "%s", sn);
	return 0;
}

int read_sn(unsigned char *buf)
{
	snprintf((char *)buf, sizeof(dev_sn), "%s", dev_sn);
	return 0;
}


void get_soft_version(char *version)
{
	version[0] = 4;
	version[1] = 5;
	version[2] = 6;

}

void get_hw_version(char *version)
{
	version[0] = 1;
	version[1] = 2;
	version[2] = 3;
}
#endif
