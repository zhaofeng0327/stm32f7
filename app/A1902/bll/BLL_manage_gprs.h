#ifndef __BLL_MANAGE_GPRS_H
#define __BLL_MANAGE_GPRS_H
#include "manage_at_cmd.h"

AT_RESULT gprs_pppd_connect(void);
AT_RESULT mqtt_perform_test(void);
AT_RESULT mqtt_pub_msg(char* topic, unsigned char qos, bool retain, char* message);
AT_RESULT mqtt_get_sub_msg(char* revcmsg, unsigned int *revc_len);
AT_RESULT http_post_perform(char *buffer, unsigned int* datalen, char* url, unsigned int timer);

#endif