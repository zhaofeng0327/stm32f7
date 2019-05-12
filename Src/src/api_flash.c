#include <stdio.h>
#include "typedef.h"
#include "cmsis_os.h"

//#include "MX25R6435F.h"
//#include "mx25r6435f_driver.h"
#include "GD25Q127.h"


#define BUFFER_SIZE         ((uint32_t)0x0100)
#define WRITE_READ_ADDR     0//((uint32_t)0x0050)
uint8_t aTxBuffer[BUFFER_SIZE];
uint8_t aRxBuffer[BUFFER_SIZE];


static void Fill_Buffer(uint8_t *pBuffer, uint32_t uwBufferLenght, uint32_t uwOffset)
{
	uint32_t tmpIndex = 0;

	/* Put in global buffer different values */
	for (tmpIndex = 0; tmpIndex < uwBufferLenght; tmpIndex++)
		pBuffer[tmpIndex] = tmpIndex + uwOffset;
}

static uint8_t Buffercmp(uint8_t *pBuffer1, uint8_t *pBuffer2, uint32_t BufferLength)
{
	while (BufferLength--) {
		if (*pBuffer1 != *pBuffer2)
			return 1;

		pBuffer1++;
		pBuffer2++;
	}

	return 0;
}


int init_flash()
{
//	BSP_QSPI_DeInit();
	BSP_QSPI_Init();

#if 0
	uint16_t id = QSPI_FLASH_ReadID();

	uint8_t status = BSP_QSPI_GetStatus();
	if ((status == MEMORY_ERROR) || (status == MEMORY_SUSPENDED) || (status == MEMORY_BUSY)) {
		printf("Init : FAILED, Test Aborted");
	} else {
		printf("Init : OK");
		QSPI_Info pInfo;
		BSP_QSPI_GetInfo(&pInfo);
		/*##-2- Read & check the info #######################################*/
		if (pInfo.FlashSize != 0x800000 ||
			pInfo.EraseSectorSize != 0x1000 ||
			pInfo.ProgPageSize != 0x100 ||
			pInfo.EraseSectorsNumber != 2048 ||
			pInfo.ProgPagesNumber != 32768)
		{
			printf("GET INFO : FAILED, Test Aborted");
		} else {
			printf("GET INFO : OK");

			/*##-3- Erase memory ################################################*/
			if (BSP_QSPI_Erase_Block(WRITE_READ_ADDR) != MEMORY_OK) {
				printf("ERASE : FAILED, Test Aborted");
			} else {
				printf("ERASE : OK");

				if (QSPI_OK == BSP_QSPI_Erase_Chip())
					printf("ERASE CHIP: OK");

				if (BSP_QSPI_Read(aRxBuffer, WRITE_READ_ADDR, BUFFER_SIZE) == QSPI_OK)
					printf("READ : OK");

				/*##-4- memory read/write access  #################################*/
				/* Fill the buffer to write */
				Fill_Buffer(aTxBuffer, BUFFER_SIZE, 0x0);

				/* Write data to the QSPI memory */
				if (BSP_QSPI_Write(aTxBuffer, WRITE_READ_ADDR, BUFFER_SIZE) != QSPI_OK) {
					printf("WRITE : FAILED, Test Aborted");
				} else {
					printf("WRITE : OK");

					/* Read back data from the QSPI memory */
					if (BSP_QSPI_Read(aRxBuffer, WRITE_READ_ADDR, BUFFER_SIZE) == QSPI_OK)
						printf("READ : OK");

					/*##-5- Checking data integrity ############################################*/
					if (Buffercmp(aRxBuffer, aTxBuffer, BUFFER_SIZE) > 0)
						printf("COMPARE : FAILED, Test Aborted");
					else
						printf("Test : OK");
				}
			}
		}
	}

	// Enables the deep power mode
	BSP_QSPI_EnterDeepPowerDown();
	osDelay(5000);
	BSP_QSPI_LeaveDeepPowerDown();
#endif
	return 0;
}
