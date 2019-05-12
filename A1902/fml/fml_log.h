#ifndef __FSL_LOG_H__
#define __FSL_LOG_H__

#include <stdio.h>
#include <string.h>
#include "jd_os_middleware.h"

typedef int (* log_upload_cb)(void **msg_queue, int len);

extern log_upload_cb log_upload;

#ifndef NDEBUG

#define flog_f(format, args...) printf(format, ##args)
#define flog_e(format, args...) printf(format, ##args)
#define flog_w(format, args...) printf(format, ##args)
#define flog_n(format, args...) printf(format, ##args)
#define flog_i(format, args...) printf(format, ##args)
#define flog_d(format, args...) printf(format, ##args)

#else   /* NDEBUG */

#define log(level, tag, format, args...) \
    do{\
        char outBuf[182] = {0};\
        snprintf(outBuf, (182 - 1), "%s " level "/" tag "(%d:%s): " format, __TIME__, __LINE__, __FUNCTION__, ##args);\
        printf("%s", outBuf);\
    }while(0);


#define flog_f(format, args...) log("F", LOG_TAG, format, ##args)
#define flog_e(format, args...) log("E", LOG_TAG, format, ##args)
#define flog_w(format, args...) log("W", LOG_TAG, format, ##args)
#define flog_n(format, args...) log("N", LOG_TAG, format, ##args)
#define flog_i(format, args...) log("I", LOG_TAG, format, ##args)
#define flog_d(format, args...) log("D", LOG_TAG, format, ##args)

#endif

// 只给 jd_bll_log_init 调用，应用无需调用
void fml_log_init(log_upload_cb cb);

#endif
