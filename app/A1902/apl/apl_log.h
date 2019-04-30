#ifndef __APL_LOG_H__
#define __APL_LOG_H__

#include "bll_log.h"


#define alog_f(format, args...) blog_f(format, ##args)
#define alog_e(format, args...) blog_e(format, ##args)
#define alog_w(format, args...) blog_w(format, ##args)
#define alog_n(format, args...) blog_n(format, ##args)
#define alog_i(format, args...) blog_i(format, ##args)
#define alog_d(format, args...) blog_d(format, ##args)

// 日志模块初始化
void apl_log_init(void);


void log_module_test(void);

#endif
