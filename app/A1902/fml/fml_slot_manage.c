#include "stm32f7xx_hal.h"
#include "main.h"
#include "fml_slot_manage.h"
#include "fml_log.h"

#define LOG_TAG "FSLOT"

#define SLOT_SUM 8

extern TIM_HandleTypeDef htim6;

typedef struct _cur_led_t {
    int status;     // on/off/blink
    int blink_time; // 
    int blink_interval;
} cur_led_t;

int blink_cnt[SLOT_SUM + 1] = {0};

cur_led_t cur_led_status[SLOT_SUM + 1] = {0};
// cur_led_t last_led_status[SLOT_SUM + 1] = {0};

// cur_blink_t cur_blink[SLOT_SUM + 1] = {0};

// int cur_led_status[SLOT_SUM + 1] = {0};
int it_cnt[9] = {0};
typedef struct {
    GPIO_TypeDef *port;
    uint16_t pin;
} io_map_t;

io_map_t solenoid_m[SLOT_SUM] = {
    { SOLENOID_EN1_GPIO_Port, SOLENOID_EN1_Pin },
    { SOLENOID_EN2_GPIO_Port, SOLENOID_EN2_Pin },
    { SOLENOID_EN3_GPIO_Port, SOLENOID_EN3_Pin },
    { SOLENOID_EN4_GPIO_Port, SOLENOID_EN4_Pin },
    { SOLENOID_EN5_GPIO_Port, SOLENOID_EN5_Pin },
    { SOLENOID_EN6_GPIO_Port, SOLENOID_EN6_Pin },
    { SOLENOID_EN7_GPIO_Port, SOLENOID_EN7_Pin },
    { SOLENOID_EN8_GPIO_Port, SOLENOID_EN8_Pin } };

io_map_t led_m[SLOT_SUM + 1] = {
    { LED1_GPIO_Port, LED1_Pin },
    { LED2_GPIO_Port, LED2_Pin },
    { LED3_GPIO_Port, LED3_Pin },
    { LED4_GPIO_Port, LED4_Pin },
    { LED5_GPIO_Port, LED5_Pin },
    { LED6_GPIO_Port, LED6_Pin },
    { LED7_GPIO_Port, LED7_Pin },
    { LED8_GPIO_Port, LED8_Pin },
    { QR_CODE_LED_GPIO_Port, QR_CODE_LED_Pin } };

io_map_t chg[SLOT_SUM] = {
    { CHARGING_EN1_GPIO_Port, CHARGING_EN1_Pin },
    { CHARGING_EN2_GPIO_Port, CHARGING_EN2_Pin },
    { CHARGING_EN3_GPIO_Port, CHARGING_EN3_Pin },
    { CHARGING_EN4_GPIO_Port, CHARGING_EN4_Pin },
    { CHARGING_EN5_GPIO_Port, CHARGING_EN5_Pin },
    { CHARGING_EN6_GPIO_Port, CHARGING_EN6_Pin },
    { CHARGING_EN7_GPIO_Port, CHARGING_EN7_Pin },
    { CHARGING_EN8_GPIO_Port, CHARGING_EN8_Pin } };

io_map_t swb[SLOT_SUM] = {
    { BAT1_IN_EXTI_GPIO_Port, BAT1_IN_EXTI_Pin },
    { BAT2_IN_EXTI_GPIO_Port, BAT2_IN_EXTI_Pin },
    { BAT3_IN_EXTI_GPIO_Port, BAT3_IN_EXTI_Pin },
    { BAT4_IN_EXTI_GPIO_Port, BAT4_IN_EXTI_Pin },
    { BAT5_IN_EXTI_GPIO_Port, BAT5_IN_EXTI_Pin },
    { BAT6_IN_EXTI_GPIO_Port, BAT6_IN_EXTI_Pin },
    { BAT7_IN_EXTI_GPIO_Port, BAT7_IN_EXTI_Pin },
    { BAT8_IN_EXTI_GPIO_Port, BAT8_IN_EXTI_Pin } };


void fml_slot_manage_solenoid(cmd_e cmd, slot_e slot)
{
    HAL_GPIO_WritePin(solenoid_m[slot].port, solenoid_m[slot].pin, (GPIO_PinState)cmd);
}

void fml_slot_manage_chg(cmd_e cmd, slot_e slot)
{
    HAL_GPIO_WritePin(chg[slot].port, chg[slot].pin, (GPIO_PinState)cmd);
}

io_state_e fml_slot_manage_swb_read(slot_e slot)
{
    io_state_e ret = LOW_LEVEL;
    ret = (io_state_e)HAL_GPIO_ReadPin(swb[slot].port, swb[slot].pin);
    return ret;
}

void fml_slot_manage_led(led_cmd_e cmd, led_e num, int blink_time, int blink_interval)
{
    cur_led_status[num].status = cmd;
    cur_led_status[num].blink_time = blink_time;
    cur_led_status[num].blink_interval = blink_interval / 50;
    if (cmd != BLINK) {
        HAL_GPIO_WritePin(led_m[num].port, led_m[num].pin, (GPIO_PinState)cmd);
    }
}

void update_led_tim6_it_cb(void)
{
    for (int i = 0; i <= 8; i++) {
        if (cur_led_status[i].status == BLINK) {
            if ((it_cnt[i]++)%cur_led_status[i].blink_interval == 0) {
                HAL_GPIO_TogglePin(led_m[i].port, led_m[i].pin);
                if (cur_led_status[i].blink_time != 0) {
                    if (blink_cnt[i]++ == 2 * cur_led_status[i].blink_time) {
                        HAL_GPIO_WritePin(led_m[i].port, led_m[i].pin, (GPIO_PinState)GPIO_PIN_RESET);
                        cur_led_status[i].status = OFF;
                        cur_led_status[i].blink_time = 0;
                        cur_led_status[i].blink_interval = 0;
                        blink_cnt[i] = 0;
                        it_cnt[i] = 0;
                    }
                }
            }
        }
    }
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == &htim6) {
        update_led_tim6_it_cb();
    }
}




// Test
#ifdef TEST
#include "jd_os_middleware.h"
static void fml_slot_Test_task(void * p)
{
    while (1) {
        for (int i = 0; i < 8; i++) {
            fml_slot_manage_chg(OPEN, (slot_e)i);
            fml_slot_manage_led(ON, (led_e)i, 0, 0);
            jd_om_msleep(5000);
            // fml_slot_manage_solenoid(OPEN, (slot_e)i);
            fml_slot_manage_led(BLINK, (led_e)i, 80, 300);
            jd_om_msleep(5000);
            // fml_slot_manage_solenoid(CLOSE, (slot_e)i);
            fml_slot_manage_led(OFF, (led_e)i, 0, 0);
            fml_slot_manage_chg(CLOSE, (slot_e)i);
        }
            fml_slot_manage_led(BLINK, (led_e)0, 0, 200);
            fml_slot_manage_led(BLINK, (led_e)1, 90, 200);
            fml_slot_manage_led(BLINK, (led_e)2, 80, 300);
            fml_slot_manage_led(BLINK, (led_e)3, 70, 400);
            fml_slot_manage_led(BLINK, (led_e)4, 60, 500);
            fml_slot_manage_led(BLINK, (led_e)5, 50, 600);
            fml_slot_manage_led(BLINK, (led_e)6, 40, 700);
            fml_slot_manage_led(BLINK, (led_e)7, 30, 800);
        while(1) {
            flog_d("blink cmd complete\n");
            jd_om_msleep(1 * 1000);
        }
    }
}

void fml_slot_test(void)
{
    JD_OM_THREAD pthread_fml_slot_test;

    pthread_fml_slot_test = jd_om_thread_create("fml_slot_Test_task", fml_slot_Test_task, NULL, 1 * 1024, fml_slot_Test_task_PRIORITY);
    if (pthread_fml_slot_test == NULL) {
        flog_e("Create pthread_fml_slot_test task fail");
        return;
    }
}

#endif
