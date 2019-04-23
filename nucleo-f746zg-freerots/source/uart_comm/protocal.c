#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <sys/stat.h>
#include "typedef.h"
#include "md_5.h"
#include "protocal.h"
#include "jd_os_middleware.h"

unsigned short crc16(char *ptr, int count)
{
	unsigned short crc;
	char i;

	crc = 0;
	while (--count >= 0) {
		crc = crc ^ (int)*ptr++ << 8;
		i = 8;
		do {
			if (crc & 0x8000)
				crc = crc << 1 ^ 0x1021;
			else
				crc = crc << 1;
		} while (--i);
	}

	return crc;
}

#if 0
unsigned long get_file_size(unsigned char file_Dev,const char *filename)
{
	FILINFO buf;
	FRESULT error;

	error = ff_stat(file_Dev,filename, &buf);
	if (error){
		dberr("%s:error\r\n",__func__);
		return 0;
	}
	return (unsigned long)buf.fsize;
}
#endif

bool ends_with(const char * haystack, const char * needle)
{
	const char * end;
	int nlen = strlen(needle);
	int hlen = strlen(haystack);

	if( nlen > hlen )
		return false;
	end = haystack + hlen - nlen;

	return (strcasecmp(end, needle) ? false : true);
}
#if 0
int get_md5(unsigned char file_Dev,unsigned char *md5, const char *ptr, int type)
{
	MD5_CTX_T ctx;
	int i = 0;
	FIL g_fileObject;
	UINT bytesRead;
	FRESULT error;

	if ((type != 0) && (type != 1))
		return -1;

	md5_init(&ctx);
	if (0 == type) {
		unsigned int mem_size = 1024;
		unsigned char *pData = NULL;

		pData = (unsigned char *)jd_om_malloc(mem_size);
		if (NULL == pData) {
			dberr("md5 malloc failed\r\n");
			return -1;
		}

		error = ff_open(file_Dev,&g_fileObject, _T(ptr), FA_READ);
		if (error) {
			dberr("md5 open failed\r\n");
			jd_om_free(pData);
			pData = NULL;
			return -1;
		}

		while ((FR_OK == f_read(&g_fileObject, pData, mem_size, &bytesRead)) && (bytesRead > 0))
			md5_update(&ctx, pData, bytesRead);

		f_close(&g_fileObject);
		jd_om_free(pData);
		pData = NULL;
	} else if (1 == type) {
		md5_update(&ctx, (unsigned char*)ptr, strlen(ptr));
	}
	md5_final(&ctx, md5);
	#if 1
	char dis[33] = { 0 };
	for (i = 0; i < 16; i++)
		sprintf(dis + 2 * i, "%02X", md5[i]);
	debug("md5: %s\r\n", dis);
	#endif

	return 0;
}
#endif
