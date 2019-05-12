#ifndef __BLL_SLOT_MANAGE_H__
#define __BLL_SLOT_MANAGE_H__

#include "fml_slot_manage.h"

void bll_slot_manage_solenoid(cmd_e cmd, slot_e slot);
void bll_slot_manage_chg(cmd_e cmd, slot_e slot);
io_state_e bll_slot_manage_swb_read(slot_e slot);

void fml_slot_manage_led(led_cmd_e cmd, led_e num, int blink_time, int blink_interval);

#endif
