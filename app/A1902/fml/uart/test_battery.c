
#include "test_battery.h"
#include "stm32f7xx.h"
#include "stm32f7xx_hal.h"

#include "cmsis_os.h"
#include "api_battery.h"
#include "uart_comm.h"

void test_bat_protoc()
{
	BATTERY_INFO_T info;

	if (0 == battery_get_info(1, 1, &info))
		printf("1 ok\r\n");
	osDelay(10);

	if (0 ==  battery_get_info(2, 1, &info))
		printf("2 ok\r\n");
	osDelay(1);

	if  (0 == battery_get_info(3, 1, &info))
		printf("3 ok\r\n");
	osDelay(1);

	if (0 == battery_get_info(4, 1, &info))
		printf("4 ok\r\n");
	osDelay(1);

	if  (0 == battery_get_info(5, 1, &info))
		printf("5 ok\r\n");
	osDelay(1);

	if  (0 == battery_get_info(6, 1, &info))
		printf("6 ok\r\n");
	osDelay(1);

	if  (0 == battery_get_info(7, 1, &info))
		printf("7 ok\r\n");
	osDelay(1);

	if  (0 == battery_get_info(8, 1, &info))
		printf("8 ok\r\n");
	return;

	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	//BATTERY_INFO_T info;
	battery_get_info(2, 1, &info);

	osDelay(1000);
	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	battery_set_sn_psw(0, "ABCD123456", 10, "pppssswwwd", 10);
	osDelay(1000);




	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	battery_decode(2,"pppssswwwd", 10);
	osDelay(5000);


	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	battery_encode(2);
	osDelay(5000);


	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	RES_BAT_VIRTUAL_PWR_T virt;
	battery_virtual_psw_info(2, &virt);
	osDelay(5000);


	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	battery_set_discharge_level(2, 1);
	osDelay(5000);


	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	RES_BAT_CHARGE_STATUS_T stat;
	battery_charge_status(2, &stat);
	osDelay(5000);


	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	RES_BAT_PROTOCAL_VERSION_T vers;
	battery_protocal_version(2, &vers);
	osDelay(5000);


	HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	RES_BAT_PASSWD_CHKSUM_T chk;
	battery_passwd_chksum(2, &chk);
	osDelay(5000);
}

