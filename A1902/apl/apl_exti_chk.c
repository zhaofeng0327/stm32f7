#include <stdio.h>
#include "stm32f7xx_hal.h"
#include "apl_exti_chk.h"
#include "jd_os_middleware.h"
#include "apl_log.h"
#include "bll_slot_manage.h"
#include "FreeRTOS.h"
#include "timers.h"

#define LOG_TAG "SLOT"

#define BAT_1_RISE_BIT (1 << 0)
#define BAT_2_RISE_BIT (1 << 1)
#define BAT_3_RISE_BIT (1 << 2)
#define BAT_4_RISE_BIT (1 << 3)
#define BAT_5_RISE_BIT (1 << 4)
#define BAT_6_RISE_BIT (1 << 5)
#define BAT_7_RISE_BIT (1 << 6)
#define BAT_8_RISE_BIT (1 << 7)

#define BAT_1_FALL_BIT (1 << 8)
#define BAT_2_FALL_BIT (1 << 9)
#define BAT_3_FALL_BIT (1 << 10)
#define BAT_4_FALL_BIT (1 << 11)
#define BAT_5_FALL_BIT (1 << 12)
#define BAT_6_FALL_BIT (1 << 13)
#define BAT_7_FALL_BIT (1 << 14)
#define BAT_8_FALL_BIT (1 << 15)

#define REVSER_BIT    (1 << 23)

#define BAT_CHECK_ALL_BITS ( (BAT_1_RISE_BIT) | (BAT_2_RISE_BIT) | (BAT_3_RISE_BIT) | (BAT_4_RISE_BIT) | \
                             (BAT_5_RISE_BIT) | (BAT_6_RISE_BIT) | (BAT_7_RISE_BIT) | (BAT_8_RISE_BIT) | \
                             (BAT_1_FALL_BIT) | (BAT_2_FALL_BIT) | (BAT_3_FALL_BIT) | (BAT_4_FALL_BIT) | \
                             (BAT_5_FALL_BIT) | (BAT_6_FALL_BIT) | (BAT_7_FALL_BIT) | (BAT_8_FALL_BIT) )

static EventGroupHandle_t xEventGroup;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    BaseType_t xHigherPriorityTaskWoken, xResult;
    xHigherPriorityTaskWoken = pdFALSE;
    uint32_t check_bit = REVSER_BIT;
    io_state_e io_state = LOW_LEVEL;
    // io_state_e io_state = bll_slot_manage_swb_read(GPIO_Pin);
    switch (GPIO_Pin) {
        case GPIO_PIN_1:
            io_state = bll_slot_manage_swb_read(SLOT_6);
            if (io_state == HIGH_LEVEL) {
                check_bit = BAT_6_RISE_BIT;
            } else {
                check_bit = BAT_6_FALL_BIT;
            }
            break;
        case GPIO_PIN_4:
            io_state = bll_slot_manage_swb_read(SLOT_5);
            if (io_state == HIGH_LEVEL) {
                check_bit = BAT_5_RISE_BIT;
            } else {
                check_bit = BAT_5_FALL_BIT;
            }
            break;
        case GPIO_PIN_7:
            io_state = bll_slot_manage_swb_read(SLOT_7);
            if (io_state == HIGH_LEVEL) {
                check_bit = BAT_7_RISE_BIT;
            } else {
                check_bit = BAT_7_FALL_BIT;
            }
            break;
        case GPIO_PIN_9:
            io_state = bll_slot_manage_swb_read(SLOT_2);
            if (io_state == HIGH_LEVEL) {
                check_bit = BAT_2_RISE_BIT;
            } else {
                check_bit = BAT_2_FALL_BIT;
            }
            break;
        case GPIO_PIN_11:
            io_state = bll_slot_manage_swb_read(SLOT_8);
            if (io_state == HIGH_LEVEL) {
                check_bit = BAT_8_RISE_BIT;
            } else {
                check_bit = BAT_8_FALL_BIT;
            }
            break;
        case GPIO_PIN_12:
            io_state = bll_slot_manage_swb_read(SLOT_1);
            if (io_state == HIGH_LEVEL) {
                check_bit = BAT_1_RISE_BIT;
            } else {
                check_bit = BAT_1_FALL_BIT;
            }
            break;
        case GPIO_PIN_13:
            io_state = bll_slot_manage_swb_read(SLOT_3);
            if (io_state == HIGH_LEVEL) {
                check_bit = BAT_3_RISE_BIT;
            } else {
                check_bit = BAT_3_FALL_BIT;
            }
            break;
        case GPIO_PIN_14:
            io_state = bll_slot_manage_swb_read(SLOT_4);
            if (io_state == HIGH_LEVEL) {
                check_bit = BAT_4_RISE_BIT;
            } else {
                check_bit = BAT_4_FALL_BIT;
            }
            break;
        default: break;
    }
    xResult = xEventGroupSetBitsFromISR(xEventGroup, check_bit, &xHigherPriorityTaskWoken);
    if (xResult == pdPASS) {
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }
}

static void bat_in_check_task(void * p)
{
    EventBits_t uxBits;
    const TickType_t xTicksToWait = 100 / portTICK_PERIOD_MS;
    int act_slot = -1;
    xEventGroup = xEventGroupCreate();
    if (xEventGroup == NULL) {
        alog_e("create event group error\n");
    }

    while (1) {
        uxBits = xEventGroupWaitBits(
                    xEventGroup,	// The event group being tested.
                    BAT_CHECK_ALL_BITS,	// The bits within the event group to wait for.
                    pdTRUE,			// BAT_CHECK_ALL_BITS should be cleared before returning.
                    pdFALSE,		// Don't wait for both bits, either bit will do.
                    xTicksToWait /*portMAX_DELAY*/ );	// Wait a maximum of 100ms for either bit to be set.
        jd_om_msleep(50);
        if (((uxBits & BAT_1_RISE_BIT) != 0) || ((uxBits & BAT_1_FALL_BIT) != 0)) {
            act_slot = SLOT_1;
        } else if (((uxBits & BAT_2_RISE_BIT) != 0) || ((uxBits & BAT_2_FALL_BIT) != 0)) {
            act_slot = SLOT_2;
        } else if (((uxBits & BAT_3_RISE_BIT) != 0) || ((uxBits & BAT_3_FALL_BIT) != 0)) {
            act_slot = SLOT_3;
        } else if (((uxBits & BAT_4_RISE_BIT) != 0) || ((uxBits & BAT_4_FALL_BIT) != 0)) {
            act_slot = SLOT_4;
        } else if (((uxBits & BAT_5_RISE_BIT) != 0) || ((uxBits & BAT_5_FALL_BIT) != 0)) {
            act_slot = SLOT_5;
        } else if (((uxBits & BAT_6_RISE_BIT) != 0) || ((uxBits & BAT_6_FALL_BIT) != 0)) {
            act_slot = SLOT_6;
        } else if (((uxBits & BAT_7_RISE_BIT) != 0) || ((uxBits & BAT_7_FALL_BIT) != 0)) {
            act_slot = SLOT_7;
        } else if (((uxBits & BAT_8_RISE_BIT) != 0) || ((uxBits & BAT_8_FALL_BIT) != 0)) {
            act_slot = SLOT_8;
        } else {
            act_slot = -1;
        }
        if (act_slot != -1) {
            if (bll_slot_manage_swb_read((slot_e)act_slot) == HIGH_LEVEL) {
                alog_d("slot %d BATT OUT.\n", act_slot + 1);
                //TO DO
                // notify borrow process
            } else {
                alog_d("slot %d BATT IN.\n", act_slot + 1);
                // to do
                // notify return process
            }
        }
    }
}


int create_bat_in_check_task(void)
{
    int ret = 0;
    JD_OM_THREAD pthread_bat_check_task;

    pthread_bat_check_task = jd_om_thread_create("bat_in_check_task", bat_in_check_task, NULL, 1 * 1024, bat_in_check_task_PRIORITY);
    if (pthread_bat_check_task == NULL) {
        alog_e("Create logTest task fail");
        ret = -1;
    }
    return ret;
}