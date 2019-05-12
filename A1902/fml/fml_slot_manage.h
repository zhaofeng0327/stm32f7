#ifndef __FML_SLOT_MANAGE_H__
#define __FML_SLOT_MANAGE_H__

typedef enum _cmd_e {
    CLOSE = 0,
    OPEN
} cmd_e;

typedef enum _led_cmd_e {
    OFF = 0,
    ON,
    BLINK
} led_cmd_e;

typedef enum _io_state {
    LOW_LEVEL = 0,
    HIGH_LEVEL
} io_state_e;

typedef enum _led_e{
    LED_1 = 0,
    LED_2,
    LED_3,
    LED_4,
    LED_5,
    LED_6,
    LED_7,
    LED_8,
    LED_QR
}led_e;

typedef enum _slot_e{
    SLOT_1 = 0,
    SLOT_2,
    SLOT_3,
    SLOT_4,
    SLOT_5,
    SLOT_6,
    SLOT_7,
    SLOT_8
}slot_e;

void fml_slot_manage_solenoid(cmd_e cmd, slot_e slot);
void fml_slot_manage_chg(cmd_e cmd, slot_e slot);
io_state_e fml_slot_manage_swb_read(slot_e slot);

void fml_slot_manage_led(led_cmd_e cmd, led_e num, int blink_time, int blink_interval);

void update_led_tim6_it_cb(void);

// Todo
// battery encrypt / decrypt
// read battery bms

/* Test */
#ifdef TEST
void fml_slot_test(void);
#endif

#endif
