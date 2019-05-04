
#include "test_battery.h"
#include "stm32f746xx.h"
#include "stm32f7xx_hal.h"

#include "cmsis_os.h"
#include "api_battery.h"
#include "uart_comm.h"

void toogle_uart()
{
	static int chn = 0;
	if (chn == 0) {
		chn = 2;
	} else {
		chn = 0;
	}

	select_uart_channel(chn);

}

void test_bat_protoc()
{
	//toogle_uart();


	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	BATTERY_INFO_T info;
	battery_get_info(1, &info);
	//osDelay(1000);

	return;
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	battery_set_sn_psw("ABCD123456", 10, "pppssswwwd", 10);
	osDelay(5000);

	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	battery_decode("pppssswwwd", 10);
	osDelay(5000);


	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	battery_encode();
	osDelay(5000);


	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	RES_BAT_VIRTUAL_PWR_T virt;
	battery_virtual_psw_info(&virt);
	osDelay(5000);


	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	battery_set_discharge_level(1);
	osDelay(5000);


	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	RES_BAT_CHARGE_STATUS_T stat;
	battery_charge_status(&stat);
	osDelay(5000);


	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	RES_BAT_PROTOCAL_VERSION_T vers;
	battery_protocal_version(&vers);
	osDelay(5000);


	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	RES_BAT_PASSWD_CHKSUM_T chk;
	battery_passwd_chksum(&chk);
	osDelay(5000);
}

