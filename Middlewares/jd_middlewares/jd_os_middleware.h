

/*****************************************************************
 设计目的，头文件保持平台无关
 *****************************************************************/
#ifndef __JD_OS_MIDDLEWARE_H__
#define __JD_OS_MIDDLEWARE_H__

#define TLC_COMM  1

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "timers.h"
#include "event_groups.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;


typedef QueueHandle_t JD_OM_QUEUE;
typedef SemaphoreHandle_t JD_OM_SEM;
typedef SemaphoreHandle_t JD_OM_MUTEX;
typedef TaskHandle_t JD_OM_THREAD;

#define bat_in_check_task_PRIORITY (configMAX_PRIORITIES - 1)

#define logTest_task_PRIORITY (configMAX_PRIORITIES - 1)
#define fml_slot_Test_task_PRIORITY (configMAX_PRIORITIES - 1)

/** Return code for timeouts from sys_arch_mbox_fetch and sys_arch_sem_wait */
#define SYS_ARCH_TIMEOUT 0xffffffffUL

typedef enum  {
    os_OK         =   0,
    os_ErrorOS    =   1,
}os_Status;


/*****************************************************************
* Function:     jd_om_thread_create
*
* Description:  创建线程，并设置为READY
*
* Parameters:
*               pTaskCode: 指向线程实现的指�?
*               pcName: 描述性的线程�?
*               pvParameters:用于修传入创建线程时需要的参数
*
* Return:
 *             JD_OM_THREAD对象:创建线程成功
*              NULL:创建线程未成�?
*****************************************************************/
JD_OM_THREAD jd_om_thread_create( const char *pcName, 
									void( *pxThread )( void *pvParameters ), 
									void *pvArg, 
									int iStackSize, 
									int iPriority );

void jd_om_thread_start(void);

void jd_om_thread_switch(void);

void jd_om_pthread_cond_signal(JD_OM_THREAD *pxThread);

void jd_om_pthread_cond_timedwait(u32 ulTimeout);

/*********************** Mutex Management *****************************
*
*
**********************************************************************/
os_Status jd_om_task_notify(JD_OM_THREAD *pxThread,unsigned char InValue);

os_Status jd_om_task_notify_wait(u32 *OutValue,u32 ulTimeOut);

void jd_om_msleep(u32 millisec);

os_Status jd_om_sem_new( JD_OM_SEM *pxSemaphore);

int jd_om_sem_wait( JD_OM_SEM *pxSemaphore, u32 ulTimeout );

void jd_om_sem_signal( JD_OM_SEM *pxSemaphore );

/*****************************************************************
* Function:     jd_om_mutex_create
*
* Description:  创建互斥�?
*
* Parameters:
*              void
*
 * Return:
 *             JD_OM_MUTEX 对象
 *             返回 NULL 失败
*
*****************************************************************/
os_Status jd_om_mutex_create(JD_OM_MUTEX *pxMutex);

/*****************************************************************
* Function:     jd_om_mutex_lock
*
* Description:  �?
*
* Parameters:
*              
*              JD_OM_MUTEX 对象
*
* Return:
*              os_Status
*
*
*****************************************************************/
void jd_om_mutex_lock(JD_OM_MUTEX *pxMutex);

int jd_om_mutex_try_lock(JD_OM_MUTEX *pxMutex);

/*****************************************************************
* Function:     jd_om_mutex_unlock
*
* Description:  释放�?
*
* Parameters:
*              JD_OM_MUTEX 对象
*
* Return:
*              os_Status
*
*****************************************************************/
void jd_om_mutex_unlock(JD_OM_MUTEX *pxMutex);

/*****************************************************************
* Function:     jd_om_mutex_delete
*
* Description:  删除互斥�?
*
* Parameters:
*              JD_OM_MUTEX 对象
*
* Return:
*              os_Status
*
*****************************************************************/
void jd_om_mutex_delete(JD_OM_MUTEX *pxMutex);

#if 1
/*****************************************************************
* Function:     jd_om_mq_create
*
* Description:  创建一个消息队�?
*
* Parameters:
 *              qsize:队列最大消息数�?
*
*
* Return:
*              JD_OM_QUEUE 对象
*
*****************************************************************/
os_Status jd_om_mq_create(JD_OM_QUEUE *pxQueue,int qsize);

/*****************************************************************
* Function:     jd_om_mq_send
*
* Description:  发送一条消息到消息队列.
*
* Parameters:
 *              queue:JD_OM_QUEUE对象
 *              pdata:数据指针
 *              lens:数据长度，可以长度是0
 *              millisec:不支�?
* Return:
*              os_Status
*
*****************************************************************/
os_Status jd_om_mq_send_to_head(JD_OM_QUEUE *pxQueue,void * pdata);

os_Status jd_om_mq_send(JD_OM_QUEUE *pxQueue,void * pdata);

os_Status jd_om_mq_send_from_isr(JD_OM_QUEUE *pxQueue,void * pdata,BaseType_t *pxHigherPriorityTaskWoken);

/*****************************************************************
* Function:     jd_om_mq_recv
*
* Description:  从消息队列接收一条消�?
*
* Parameters:
*             queue:JD_OM_QUEUE对象
*             pdata:数据指针
*             millisec = 0 阻塞模式
*             millisec > 0 查询模式
* Return:
* 		失败:
*             MQ_PEEK_EMPTY
*       成功:
*            >= 0 返回数据长度 成功
*
*****************************************************************/
u32 jd_om_mq_recv(JD_OM_QUEUE *pxQueue,
                       void ** pdata,
                       u32 millisec);

/*****************************************************************
* Function:     jd_om_mq_counts
*
* Description:  获取消息队列中消息个�?
*
* Parameters:
*             queue:JD_OM_QUEUE对象
* Return:
* 		失败:
*             MQ_LOCK_ERROR 其他线程在访问，失败
*       成功:
*            >= 0 返回数量，成�?
*
*****************************************************************/
int jd_om_mq_counts(JD_OM_QUEUE *pxQueue);


/*****************************************************************
 * Function:     jd_om_delete_mq
 *
 * Description:  删除消息队列:必须为空，不为空返回 error 必须jd_om_mq_free
 *
 * Parameters:
 *             queue:JD_OM_QUEUE对象
 * Return:
 *             os_Status
 *
 *****************************************************************/
void jd_om_delete_mq(JD_OM_QUEUE *pxQueue);

/*********************** Memory Pool Management *****************************
*
*     osPoolId jd_om_mem_pool_create(const osPoolDef_t *pool_def);
*     void *jd_om_mem_pool_alloc(osPoolId pool_id);
*     void *jd_om_mem_pool_calloc(osPoolId pool_id);
*     os_Status jd_om_mem_pool_free(osPoolId pool_id, void *block)
*
**********************************************************************/

void * jd_om_malloc(size_t size);
void jd_om_free(void* p);

#endif
#endif

