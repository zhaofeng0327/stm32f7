#ifndef _FACTORY_TEST_H_
#define _FACTORY_TEST_H_

#include "api_rtc.h"

int write_sn(unsigned char *sn, unsigned int sn_len);
int read_sn(unsigned char *buf);
void get_soft_version(char *version);
void get_hw_version(char *version);

#endif
