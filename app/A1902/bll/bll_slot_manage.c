#include "bll_slot_manage.h"

void bll_slot_manage_solenoid(cmd_e cmd, slot_e slot)
{
    fml_slot_manage_solenoid(cmd, slot);
}

void bll_slot_manage_chg(cmd_e cmd, slot_e slot)
{
    fml_slot_manage_chg(cmd, slot);
}

io_state_e bll_slot_manage_swb_read(slot_e slot)
{
    io_state_e ret = LOW_LEVEL;
    ret = fml_slot_manage_swb_read(slot);
    return ret;
}

void bll_slot_manage_led(led_cmd_e cmd, led_e num, int blink_time, int blink_interval)
{
    fml_slot_manage_led(cmd, num, blink_time, blink_interval);
}
