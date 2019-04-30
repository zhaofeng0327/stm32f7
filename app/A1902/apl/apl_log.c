#include "apl_log.h"
#include "bll_log.h"
#include "jd_os_middleware.h"
#include "stdio.h"
#define LOG_TAG "LOG"

// 日志添加队列回调
// typedef int (* log_upload_cb)(void **msg_queue);
int log_add_to_queue(void **msg_queue, int len)
{
    if (msg_queue != NULL) {
        // printf(">>> add log msg to queue %p: %s, %d\n", *msg_queue, *msg_queue, len);
        // Todo
        // add msg to upload queue
        jd_om_free(*msg_queue);
    }
    return 0;
}

void apl_log_init(void)
{
    bll_log_init(log_add_to_queue);
}



#ifdef TEST
static void logTest_task(void * p)
{
    int cnt = 0;
    char dmsg[] = "This is a test msg";
    while (1) {
        alog_d("===>>> %d: %s\n", ++cnt, dmsg);
        jd_om_msleep(1000);
    }
}

void log_module_test(void)
{
    JD_OM_THREAD pthread_log_test;

    pthread_log_test = jd_om_thread_create("logTest_task", logTest_task, NULL, 1 * 1024, logTest_task_PRIORITY);
    if (pthread_log_test == NULL) {
        alog_e("Create logTest task fail");
        return;
    }
}
#endif


