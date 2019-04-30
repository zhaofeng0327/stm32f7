#ifndef __BLL_LOG_H__
#define __BLL_LOG_H__

#include "fml_log.h"

#define blog_f(format, args...) flog_f(format, ##args)
#define blog_e(format, args...) flog_e(format, ##args)
#define blog_w(format, args...) flog_w(format, ##args)
#define blog_n(format, args...) flog_n(format, ##args)
#define blog_i(format, args...) flog_i(format, ##args)
#define blog_d(format, args...) flog_d(format, ##args)


// 只给 jd_apl_log_init 调用，应用无需调用
void bll_log_init(log_upload_cb cb);

#endif
