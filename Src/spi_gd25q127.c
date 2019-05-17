#include "spi_gd25q127.h"
#include "GD25Q127.h"
#include "stm32f7xx.h"
#include "main.h"
#include <stdio.h>
#include <string.h>

#define DUMMY_BYTE 0xff

void dump_buffer(unsigned char * buffer,int lens)
{
#if 1
	int i;
	for(i = 0;i<lens;i++){
		if((i%16)==0)printf("\r\n");
		printf("%02x ",buffer[i]);
	}
	printf("\r\n");
#endif
}

extern SPI_HandleTypeDef hspi1;

static int GD_release_power_down()
{
	uint8_t ch = GD25Q_ReleasePowerDown;

	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, &ch, 1, 1000);
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);
	return 0;
}


static int GD_read_id()
{
	uint8_t id[3] = { 0 };

	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);

	uint8_t reg = GD25Q_DeviceID;
	HAL_SPI_Transmit(&hspi1, &reg, 1, 1000);
	HAL_SPI_Receive(&hspi1, id, 3, 1000);


	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);
	int ret = id[0] << 16 | id[1] << 8 | id[2];
	return ret;
}

uint8_t GD_get_status_reg(uint8_t reg)
{
	uint8_t ret;

	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);

	HAL_SPI_Transmit(&hspi1, &reg, 1, 1000);
	HAL_SPI_Receive(&hspi1, &ret, 1, 1000);

	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);
	return ret;
}

void GD_write_enable()
{
	uint8_t reg1 = 0;

	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
	uint8_t ch = GD25Q_WriteEnable;
	HAL_SPI_Transmit(&hspi1, &ch, 1, 10);
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);

	do {
		reg1 = GD_get_status_reg(GD25Q_ReadStatusReg1);
		HAL_Delay(1);
		if (reg1 & GD25Q_SR_WEL)
			break;
	} while (1);
}

void GD_waitbusy()
{
	uint8_t reg1 = 0;

	do {
		reg1 = GD_get_status_reg(GD25Q_ReadStatusReg1);
		HAL_Delay(1);
	} while (reg1 & GD25Q_SR_WIP);
}

static int GD_standard_mode()
{
	uint8_t reg2 = GD_get_status_reg(GD25Q_ReadStatusReg2);

	if (0 == reg2 & GD25Q_SR_QE)
		return QSPI_OK;

	CLEAR_BIT(reg2, GD25Q_SR_QE);
	uint8_t buf[2] = { GD25Q_ReadStatusReg2, reg2 };

	GD_write_enable();

	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, buf, 2, 1000);
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);

	GD_waitbusy();

	reg2 = GD_get_status_reg(GD25Q_ReadStatusReg2);

	if (reg2 & GD25Q_SR_QE)
		return QSPI_ERROR;
	return QSPI_OK;
}

int GD_erase_sector(uint32_t id)
{
	uint8_t addr[4] = { 0 };
	uint32_t eaddr = id * GD25Q_SECTOR_SIZE;
	memcpy(addr, &eaddr, 4);
	uint8_t buf[4] = { GD25Q_SectorErase, addr[2], addr[1], addr[0] };

	GD_write_enable();
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
	HAL_SPI_Transmit(&hspi1, buf, 4, 1000);
	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);
	GD_waitbusy();

	return 0;
}

uint8_t GD_read_fast(uint8_t *pData, uint32_t Rdaddr, uint32_t size)
{
	uint8_t addr[4] = { 0 };

	memcpy(addr, &Rdaddr, 4);

	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);

	uint8_t ch[5] = { GD25Q_FastReadData, addr[2], addr[1], addr[0], 0xff };
	HAL_SPI_Transmit(&hspi1, ch, 5, 1000);
	HAL_SPI_Receive(&hspi1, pData, size, 10000);

	HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);
	return 0;
}

uint8_t GD_write(uint8_t *pData, uint32_t WriteAddr, uint32_t size)
{
	uint32_t end_addr, current_size, current_addr;

	/* Calculation of the size between the write address and the end of the page */
	current_size = GD25Q_PAGE_SIZE - (WriteAddr % GD25Q_PAGE_SIZE);

	/* Check if the size of the data is less than the remaining place in the page */
	if (current_size > size)
		current_size = size;

	/* Initialize the adress variables */
	current_addr = WriteAddr;
	end_addr = WriteAddr + size;


	do {
		uint8_t addr[4] = { 0 };
		memcpy(addr, &current_addr, 4);
		uint8_t ch[4] = { GD25Q_PageProgram, addr[2], addr[1], addr[0] };
		printf("%02X %02X %02X %02X\r\n", ch[0], ch[1], ch[2], ch[3]);

		GD_write_enable();
		HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_RESET);
		HAL_SPI_Transmit(&hspi1, ch, 4, 1000);
		HAL_SPI_Transmit(&hspi1, pData, current_size, 10000);
		HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port, SPI1_NSS_Pin, GPIO_PIN_SET);
		GD_waitbusy();

		/* Update the address and size variables for next page programming */
		current_addr += current_size;
		pData += current_size;
		current_size = ((current_addr + GD25Q_PAGE_SIZE) > end_addr) ? (end_addr - current_addr) : GD25Q_PAGE_SIZE;
	} while (current_addr < end_addr);

	return 0;
}

void test_spi_flash()
{
	int id = GD_read_id();

	printf("read id 0x%08x\r\n", id);


	uint8_t buf[256] = { 0 };
	GD_erase_sector(0);
	GD_read_fast(buf, 0, 256);
	printf("read after erase\r\n");
	dump_buffer(buf, 256);

	uint8_t s[256] = { 0 };
	for (int i = 0; i < 256; i++)
		s[i] = i + 1;
	GD_write(s, 0, 256);


	memset(buf, 0, 256);
	GD_read_fast(buf, 0, 256);
	printf("read after write\r\n");
	dump_buffer(buf, 256);
}

int spi_flash_init()
{
	GD_release_power_down();
	GD_standard_mode();
	//test_spi_flash();
	return 0;
}
