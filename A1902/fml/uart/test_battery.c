
#include "test_battery.h"
#include "stm32f746xx.h"
#include "stm32f7xx_hal.h"

#include "cmsis_os.h"
#include "api_battery.h"
#include "uart_comm.h"

void toogle_uart()
{
	int chn = get_uart_channel();

	if (2 == chn)
		select_uart_channel(0);
	else if (0 == chn)
		select_uart_channel(2);
}

void test_bat_protoc()
{
	select_uart_channel(2);
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	BATTERY_INFO_T info;
	battery_get_info(1, &info);

	select_uart_channel(0);
	osDelay(1000);
	//select_uart_channel(0);
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	battery_set_sn_psw("ABCD123456", 10, "pppssswwwd", 10);
	osDelay(1000);

	return;


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

