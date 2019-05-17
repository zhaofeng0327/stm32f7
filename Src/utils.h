#ifndef __UTILS_HH__
#define __UTILS_HH__

#include "typedef.h"

void dump_buffer(u8 * buffer,int lens);
unsigned short crc16(char *ptr, int count);
bool ends_with(const char * haystack, const char * needle);
int get_md5(unsigned char *md5, const char *ptr, int len, int type);

#endif
