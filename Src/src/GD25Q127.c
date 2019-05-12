#include "GD25Q127.h"


#include "stm32f7xx.h"
#include "stm32f7xx_hal.h"
#include "typedef.h"
#include "main.h"
#include "qspi_gd.h"

QSPI_HandleTypeDef QSPIHandle;
#define FLASH_SIZE                0x800000
#if 1


uint32_t __readMemory32(int addr, u8 *type)
{
        uint32_t *a = (uint32_t *)addr;
	return *a;
}
void __writeMemory32(uint32_t reg, int addr, u8 *type)
{
   uint32_t *a = (uint32_t *)addr;
	*a = reg;
}

void QSPI_HARDWARE_INIT()
{
	u32 Reg;
/* Enable QUADSPI Clock*/
  Reg = __readMemory32(0x40023838, "Memory");  // RCC.AHB3ENR
  Reg |= 0x00000002;
  __writeMemory32(Reg, 0x40023838, "Memory");

  /* Reset QUADSPI peripheral */
  Reg = __readMemory32(0x40023818, "Memory");  // RCC.AHB3RSTR
  Reg |= 0x00000002;
  __writeMemory32(Reg, 0x40023818, "Memory");
  Reg &= ~0x00000002;
  __writeMemory32(Reg, 0x40023818, "Memory");


  /* Enable GPIOB, GPIOD and GPIOE AHB1 clock */
  Reg = __readMemory32(0x40023830, "Memory");  // RCC.AHB1ENR
  Reg |= 0x0000001A;
  __writeMemory32(Reg, 0x40023830, "Memory");


  /* QUADSPI_CLK      PB2, AF9  */
  /* QUADSPI_BK1_NCS  PB6, AF10 */

  Reg = __readMemory32(0x40020420, "Memory");  // GPIOB.AFRL
  Reg &= ~((0x0FUL << 24) | (0x0FUL << 8));
  Reg |=  ((0x0AUL << 24) | (0x09UL << 8));
  __writeMemory32(Reg, 0x40020420, "Memory");

  Reg = __readMemory32(0x40020400, "Memory");  // GPIOB.MODER
  Reg &= ~((0x03UL << 12) | (0x03UL << 4));
  Reg |=  ((0x02UL << 12) | (0x02UL << 4));
  __writeMemory32(Reg, 0x40020400, "Memory");

  Reg = __readMemory32(0x40020408, "Memory");  // GPIOB.OSPEEDR
  Reg |=  ((0x03UL << 12) | (0x03UL << 4));
  __writeMemory32(Reg, 0x40020408, "Memory");

  Reg = __readMemory32(0x40020404, "Memory");  // GPIOB.OTYPER
  Reg &= ~((0x01UL << 6) | (0x01UL << 2));
  __writeMemory32(Reg, 0x40020404, "Memory");

  Reg = __readMemory32(0x4002040C, "Memory");  // GPIOB.PUPDR
  Reg &= ~((0x03UL << 12) | (0x03UL << 4));
  __writeMemory32(Reg, 0x4002040C, "Memory");


  /* QUADSPI_BK1_IO2  PE2, AF9 */

  Reg = __readMemory32(0x40021020, "Memory");  // GPIOE.AFRL
  Reg &= ~(0x0FUL << 8);
  Reg |=  (0x09UL << 8);
  __writeMemory32(Reg, 0x40021020, "Memory");

  Reg = __readMemory32(0x40021000, "Memory");  // GPIOE.MODER
  Reg &= ~(0x03UL << 4);
  Reg |=  (0x02UL << 4);
  __writeMemory32(Reg, 0x40021000, "Memory");

  Reg = __readMemory32(0x40021008, "Memory");  // GPIOE.OSPEEDR
  Reg |=  (0x03UL << 4);
  __writeMemory32(Reg, 0x40021008, "Memory");

  Reg = __readMemory32(0x40021004, "Memory");  // GPIOE.OTYPER
  Reg &= ~(0x01UL << 2);
  __writeMemory32(Reg, 0x40021004, "Memory");

  Reg = __readMemory32(0x4002100C, "Memory");  // GPIOE.PUPDR
  Reg &= ~(0x03UL << 4);
  __writeMemory32(Reg, 0x4002100C, "Memory");

  /* QUADSPI_BK1_IO0  PD11, AF9 */
  /* QUADSPI_BK1_IO1  PD12, AF9 */
  /* QUADSPI_BK1_IO3  PD13, AF9 */

  Reg = __readMemory32(0x40020C24, "Memory");  // GPIOD.AFRH
  Reg &= ~(0xFFFUL << 12);
  Reg |=  (0x999UL << 12);
  __writeMemory32(Reg, 0x40020C24, "Memory");

  Reg = __readMemory32(0x40020C00, "Memory");  // GPIOD.MODER
  Reg &= ~(0x3FUL << 22);
  Reg |=  (0x2AUL << 22);
  __writeMemory32(Reg, 0x40020C00, "Memory");

  Reg = __readMemory32(0x40020C08, "Memory");  // GPIOD.OSPEEDR
  Reg |=  (0x3FUL << 22);
  __writeMemory32(Reg, 0x40020C08, "Memory");

  Reg = __readMemory32(0x40020C04, "Memory");  // GPIOD.OTYPER
  Reg &= ~(0x07UL << 11);
  __writeMemory32(Reg, 0x40020C04, "Memory");

  Reg = __readMemory32(0x40020C0C, "Memory");  // GPIOD.PUPDR
  Reg &= ~(0x3FUL << 22);
  __writeMemory32(Reg, 0x40020C0C, "Memory");

}
#endif
void BSP_QSPI_MspInit(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	__HAL_RCC_QSPI_CLK_ENABLE();

	__HAL_RCC_GPIOE_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();

	/*QUADSPI GPIO Configuration
	 *      PE2     ------> QUADSPI_BK1_IO2
	 *      PB2     ------> QUADSPI_CLK
	 *      PD11	 ------> QUADSPI_BK1_IO0
	 *      PD12	 ------> QUADSPI_BK1_IO1
	 *      PD13	 ------> QUADSPI_BK1_IO3
	 *      PB6     ------> QUADSPI_BK1_NCS
	 */
	GPIO_InitStruct.Pin = QUADSPI_BK1_IO2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF9_QUADSPI;
	HAL_GPIO_Init(QUADSPI_BK1_IO2_GPIO_Port, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = QUADSPI_CLK_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF9_QUADSPI;
	HAL_GPIO_Init(QUADSPI_CLK_GPIO_Port, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = QUADSPI_BK1_IO0_Pin | QUADSPI_BK1_IO1_Pin | QUADSPI_BK1_IO3_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF9_QUADSPI;
	HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = QUADSPI_BK1_NCS_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF10_QUADSPI;
	HAL_GPIO_Init(QUADSPI_BK1_NCS_GPIO_Port, &GPIO_InitStruct);
}
void BSP_QSPI_MspDeInit()
{
	HAL_NVIC_DisableIRQ(QUADSPI_IRQn);
	__HAL_RCC_QSPI_CLK_DISABLE();

	/**QUADSPI GPIO Configuration
	 * PE2	 ------> QUADSPI_BK1_IO2
	 * PB2	 ------> QUADSPI_CLK
	 * PD11	  ------> QUADSPI_BK1_IO0
	 * PD12	  ------> QUADSPI_BK1_IO1
	 * PD13	  ------> QUADSPI_BK1_IO3
	 * PB6	 ------> QUADSPI_BK1_NCS
	 */
	HAL_GPIO_DeInit(QUADSPI_BK1_IO2_GPIO_Port, QUADSPI_BK1_IO2_Pin);

	HAL_GPIO_DeInit(GPIOB, QUADSPI_CLK_Pin | QUADSPI_BK1_NCS_Pin);

	HAL_GPIO_DeInit(GPIOD, QUADSPI_BK1_IO0_Pin | QUADSPI_BK1_IO1_Pin | QUADSPI_BK1_IO3_Pin);
}

uint8_t GD25Q_LeaveDeepPowerDown(void)
{
	QSPI_CommandTypeDef sCommand;

	/* Initialize the erase command */
	sCommand.InstructionMode = QSPI_INSTRUCTION_1_LINE;
	sCommand.Instruction = GD25Q_ReleasePowerDown;
	sCommand.AddressMode = QSPI_ADDRESS_NONE;
	sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
	sCommand.DataMode = QSPI_DATA_NONE;
	sCommand.DummyCycles = 0;
	sCommand.DdrMode = QSPI_DDR_MODE_DISABLE;
	sCommand.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
	sCommand.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

	/* Send the command */
	if (HAL_QSPI_Command(&QSPIHandle, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
		return QSPI_ERROR;

	/* --- A NOP command is sent to the memory, as the nCS should be low for at least 20 ns --- */
	/* ---                  Memory takes 35us min to leave deep power down                  --- */

	return QSPI_OK;
}

uint32_t GD25Q_ReadID()
{
	QSPI_CommandTypeDef s_command;
	uint32_t Temp = 0;
	uint8_t pData[3] = { 0 };

	s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;            //命令单线模式
	s_command.Instruction = GD25Q_DeviceID;                         //读ID的命令码
	s_command.DataMode = QSPI_DATA_1_LINE;
	s_command.AddressMode = QSPI_ADDRESS_NONE;                      //没有地址码
	s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;        //没有选项码
	s_command.DummyCycles = 0;                                      //没有空字段
	s_command.NbData = 3;                                           //读取20字节
	s_command.DdrMode = QSPI_DDR_MODE_DISABLE;
	s_command.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
	s_command.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;
	if (HAL_QSPI_Command(&QSPIHandle, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
		printf("read id send err ....\r\n");

	if (HAL_QSPI_Receive(&QSPIHandle, pData, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
		printf("read id recv err ....\r\n");

	Temp = (pData[2] | pData[1] << 8) | (pData[0] << 16);//我们只需要JEDECID即可后面的字节不关心

	return Temp;
}


uint8_t GD25Q_Read_Status(uint32_t id)
{
	QSPI_CommandTypeDef s_command;
	uint8_t reg = 0;

	s_command.Instruction = id;
	s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;

	s_command.Address = 0;
	s_command.AddressMode = QSPI_ADDRESS_NONE;

	s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;

	s_command.DummyCycles = 0;

	s_command.DataMode = QSPI_DATA_1_LINE;
	s_command.NbData = 1;

	s_command.DdrMode = QSPI_DDR_MODE_DISABLE;
	s_command.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
	s_command.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

	if (HAL_QSPI_Command(&QSPIHandle, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
		return QSPI_ERROR;

	if (HAL_QSPI_Receive(&QSPIHandle, &reg, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
		return QSPI_ERROR;

	return reg;
}

uint8_t GD25Q_Write_Enable()
{
	QSPI_CommandTypeDef sCommand;
	QSPI_AutoPollingTypeDef sConfig;

	/* Enable write operations */
	sCommand.InstructionMode = QSPI_INSTRUCTION_1_LINE;
	sCommand.Instruction = GD25Q_WriteEnable;
	sCommand.AddressMode = QSPI_ADDRESS_NONE;
	sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
	sCommand.DataMode = QSPI_DATA_NONE;
	sCommand.DummyCycles = 0;
	sCommand.DdrMode = QSPI_DDR_MODE_DISABLE;
	sCommand.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
	sCommand.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

	if (HAL_QSPI_Command(&QSPIHandle, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
		return QSPI_ERROR;

	/* Configure automatic polling mode to wait for write enabling */
	sConfig.Match = GD25Q_SR_WEL;
	sConfig.Mask = GD25Q_SR_WEL;
	sConfig.MatchMode = QSPI_MATCH_MODE_AND;
	sConfig.StatusBytesSize = 1;
	sConfig.Interval = 0x10;
	sConfig.AutomaticStop = QSPI_AUTOMATIC_STOP_ENABLE;

	sCommand.Instruction = GD25Q_ReadStatusReg1;
	sCommand.DataMode = QSPI_DATA_1_LINE;

	if (HAL_QSPI_AutoPolling(&QSPIHandle, &sCommand, &sConfig, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
		return QSPI_ERROR;
	return QSPI_OK;
}

static uint8_t GD25Q_MemReady(QSPI_HandleTypeDef *hqspi, uint32_t Timeout)
{
	QSPI_CommandTypeDef sCommand;
	QSPI_AutoPollingTypeDef sConfig;

	/* Configure automatic polling mode to wait for memory ready */
	sCommand.InstructionMode = QSPI_INSTRUCTION_1_LINE;
	sCommand.Instruction = GD25Q_ReadStatusReg1;
	sCommand.AddressMode = QSPI_ADDRESS_NONE;
	sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
	sCommand.DataMode = QSPI_DATA_1_LINE;
	sCommand.DummyCycles = 0;
	sCommand.DdrMode = QSPI_DDR_MODE_DISABLE;
	sCommand.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
	sCommand.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

	sConfig.Match = 0;
	sConfig.Mask = GD25Q_SR_WIP;
	sConfig.MatchMode = QSPI_MATCH_MODE_AND;
	sConfig.StatusBytesSize = 1;
	sConfig.Interval = 0x10;
	sConfig.AutomaticStop = QSPI_AUTOMATIC_STOP_ENABLE;

	if (HAL_QSPI_AutoPolling(hqspi, &sCommand, &sConfig, Timeout) != HAL_OK)
		return QSPI_ERROR;

	return QSPI_OK;
}


static uint8_t GD25Q_Enable_QuadMode()
{
	/* Read status register */
	uint8_t reg = GD25Q_Read_Status(GD25Q_ReadStatusReg2);

	/* Activate the Quad mode */
	SET_BIT(reg, GD25Q_SR_QE);

	/* Enable write operations */
	if (GD25Q_Write_Enable() != QSPI_OK)
		return QSPI_ERROR;

	QSPI_CommandTypeDef sCommand;
	sCommand.Instruction = GD25Q_WriteStatusReg2;
	sCommand.InstructionMode = QSPI_INSTRUCTION_1_LINE;
	sCommand.AddressMode = QSPI_ADDRESS_NONE;
	sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
	sCommand.DummyCycles = 0;
	sCommand.DataMode = QSPI_DATA_1_LINE;
	sCommand.NbData = 1;
	sCommand.DdrMode = QSPI_DDR_MODE_DISABLE;
	sCommand.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
	sCommand.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

	if (HAL_QSPI_Command(&QSPIHandle, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
		return QSPI_ERROR;

	if (HAL_QSPI_Transmit(&QSPIHandle, &reg, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
		return QSPI_ERROR;

	/* Wait that memory is ready */
	if (GD25Q_MemReady(&QSPIHandle, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != QSPI_OK)
		return QSPI_ERROR;

	/* Check the configuration has been correctly done */
	reg = GD25Q_Read_Status(GD25Q_ReadStatusReg2);
	if (0 == reg & GD25Q_SR_QE)
		return QSPI_ERROR;

	return QSPI_OK;
}


uint32_t GD25Q_ReadID_Quad()
{
	QSPI_CommandTypeDef s_command;
	uint32_t Temp = 0;
	uint8_t pData[6] = { 0 };

	s_command.Instruction = GD25Q_DeviceID_Quad;                    //读ID的命令码
	s_command.InstructionMode = QSPI_INSTRUCTION_1_LINE;            //命令单线模式

	s_command.Address = 0;
	s_command.AddressMode = QSPI_ADDRESS_4_LINES;                      //没有地址码
	s_command.AddressSize = QSPI_ADDRESS_24_BITS;

	s_command.AlternateByteMode = QSPI_ALTERNATE_BYTES_4_LINES;        //没有选项码
	s_command.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;

	s_command.DummyCycles = 4;                                      //没有空字段

	s_command.DataMode = QSPI_DATA_4_LINES;
	s_command.NbData = 6;                                           //读取20字节

	s_command.DdrMode = QSPI_DDR_MODE_DISABLE;
	s_command.DdrHoldHalfCycle = QSPI_DDR_HHC_ANALOG_DELAY;
	s_command.SIOOMode = QSPI_SIOO_INST_EVERY_CMD;

	if (HAL_QSPI_Command(&QSPIHandle, &s_command, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
		printf("read id send err ....\r\n");

	if (HAL_QSPI_Receive(&QSPIHandle, pData, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
		printf("read id recv err ....\r\n");

	Temp = (pData[1] | pData[0] << 8);//我们只需要JEDECID即可后面的字节不关心

	return Temp;
}
uint32_t GD25Q_Erase_Sector(uint32_t Sector)
{
	QSPI_CommandTypeDef sCommand;

	if (Sector >= (uint32_t)(GD25Q_FLASH_SIZE/GD25Q_SECTOR_SIZE))
	{
	  return QSPI_ERROR;
	}

	/* Initialize the erase command */
	sCommand.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
	sCommand.Instruction	   = GD25Q_SectorErase;
	sCommand.AddressMode	   = QSPI_ADDRESS_1_LINE;
	sCommand.AddressSize	   = QSPI_ADDRESS_24_BITS;
	sCommand.Address		   = (Sector * GD25Q_SECTOR_SIZE);
	sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
	sCommand.DataMode		   = QSPI_DATA_NONE;
	sCommand.DummyCycles	   = 0;
	sCommand.DdrMode		   = QSPI_DDR_MODE_DISABLE;
	sCommand.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
	sCommand.SIOOMode		   = QSPI_SIOO_INST_EVERY_CMD;

	/* Enable write operations */
	if (GD25Q_Write_Enable() != QSPI_OK)
	{
	  return QSPI_ERROR;
	}

	/* Send the command */
	if (HAL_QSPI_Command(&QSPIHandle, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
	{
	  return QSPI_ERROR;
	}

	/* Configure automatic polling mode to wait for end of erase */
	if (GD25Q_MemReady(&QSPIHandle, GD25Q_BLOCK_ERASE_MAX_TIME) != QSPI_OK)
	{
	  return QSPI_ERROR;
	}


	return QSPI_OK;

}

uint8_t GD25Q_Erase_Block64k(uint32_t BlockAddress)
{
  QSPI_CommandTypeDef sCommand;

  /* Initialize the erase command */
  sCommand.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  sCommand.Instruction       = GD25Q_BlockErase64k;
  sCommand.AddressMode       = QSPI_ADDRESS_1_LINE;
  sCommand.AddressSize       = QSPI_ADDRESS_24_BITS;
  sCommand.Address           = BlockAddress;
  sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  sCommand.DataMode          = QSPI_DATA_NONE;
  sCommand.DummyCycles       = 0;
  sCommand.DdrMode           = QSPI_DDR_MODE_DISABLE;
  sCommand.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  sCommand.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* Enable write operations */
  if (GD25Q_Write_Enable() != QSPI_OK)
  {
    return QSPI_ERROR;
  }

  /* Send the command */
  if (HAL_QSPI_Command(&QSPIHandle, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Configure automatic polling mode to wait for end of erase */
  if (GD25Q_MemReady(&QSPIHandle, GD25Q_BLOCK_ERASE_MAX_TIME) != QSPI_OK)
  {
    return QSPI_ERROR;
  }

  return QSPI_OK;
}

uint8_t GD25Q_Erase_Chip(void)
{
  QSPI_CommandTypeDef sCommand;

  /* Initialize the erase command */
  sCommand.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  sCommand.Instruction       = GD25Q_ChipErase;
  sCommand.AddressMode       = QSPI_ADDRESS_NONE;
  sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  sCommand.DataMode          = QSPI_DATA_NONE;
  sCommand.DummyCycles       = 0;
  sCommand.DdrMode           = QSPI_DDR_MODE_DISABLE;
  sCommand.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  sCommand.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* Enable write operations */
  if (GD25Q_Write_Enable() != QSPI_OK)
  {
    return QSPI_ERROR;
  }

  /* Send the command */
  if (HAL_QSPI_Command(&QSPIHandle, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Configure automatic polling mode to wait for end of erase */
  if (GD25Q_MemReady(&QSPIHandle, GD25Q_CHIP_ERASE_MAX_TIME) != QSPI_OK)
  {
    return QSPI_ERROR;
  }

  return QSPI_OK;
}

uint8_t GD25Q_Read_Quad(uint8_t* pData, uint32_t ReadAddr, uint32_t Size)
{
  QSPI_CommandTypeDef sCommand;

  /* Initialize the read command */
  sCommand.InstructionMode    = QSPI_INSTRUCTION_1_LINE;
  sCommand.Instruction        = GD25Q_FastReadQuadIO;
  sCommand.AddressMode        = QSPI_ADDRESS_4_LINES;
  sCommand.AddressSize        = QSPI_ADDRESS_24_BITS;
  sCommand.Address            = ReadAddr;
  sCommand.AlternateByteMode  = QSPI_ALTERNATE_BYTES_4_LINES;
  sCommand.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  sCommand.AlternateBytes     = 0;//if equal 0x30, then continuous read next
  sCommand.DataMode           = QSPI_DATA_4_LINES;
  sCommand.DummyCycles        = Q25Q_DUMMY_CYCLES_READ_QUAD;
  sCommand.NbData             = Size;
  sCommand.DdrMode            = QSPI_DDR_MODE_DISABLE;
  sCommand.DdrHoldHalfCycle   = QSPI_DDR_HHC_ANALOG_DELAY;
  sCommand.SIOOMode           = QSPI_SIOO_INST_EVERY_CMD;

  /* Configure the command */
  if (HAL_QSPI_Command(&QSPIHandle, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* Reception of the data */
  if (HAL_QSPI_Receive(&QSPIHandle, pData, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  return QSPI_OK;
}

uint8_t GD25Q_Write_Quad(uint8_t* pData, uint32_t WriteAddr, uint32_t Size)
{
  QSPI_CommandTypeDef sCommand;
  uint32_t end_addr, current_size, current_addr;

  /* Calculation of the size between the write address and the end of the page */
  current_size = GD25Q_PAGE_SIZE - (WriteAddr % GD25Q_PAGE_SIZE);

  /* Check if the size of the data is less than the remaining place in the page */
  if (current_size > Size)
  {
    current_size = Size;
  }

  /* Initialize the adress variables */
  current_addr = WriteAddr;
  end_addr = WriteAddr + Size;

  /* Initialize the program command */
  sCommand.InstructionMode   = QSPI_INSTRUCTION_1_LINE;
  sCommand.Instruction       = GD25Q_PageProgramQuad;
  sCommand.AddressMode       = QSPI_ADDRESS_1_LINE;
  sCommand.AddressSize       = QSPI_ADDRESS_24_BITS;
  sCommand.AlternateByteMode = QSPI_ALTERNATE_BYTES_NONE;
  sCommand.DataMode          = QSPI_DATA_4_LINES;
  sCommand.DummyCycles       = 0;
  sCommand.DdrMode           = QSPI_DDR_MODE_DISABLE;
  sCommand.DdrHoldHalfCycle  = QSPI_DDR_HHC_ANALOG_DELAY;
  sCommand.SIOOMode          = QSPI_SIOO_INST_EVERY_CMD;

  /* Perform the write page by page */
  do
  {
    sCommand.Address = current_addr;
    sCommand.NbData  = current_size;

    /* Enable write operations */
    if (GD25Q_Write_Enable() != QSPI_OK)
    {
      return QSPI_ERROR;
    }

    /* Configure the command */
    if (HAL_QSPI_Command(&QSPIHandle, &sCommand, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
      return QSPI_ERROR;
    }

    /* Transmission of the data */
    if (HAL_QSPI_Transmit(&QSPIHandle, pData, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != HAL_OK)
    {
      return QSPI_ERROR;
    }

    /* Configure automatic polling mode to wait for end of program */
    if (GD25Q_MemReady(&QSPIHandle, HAL_QPSI_TIMEOUT_DEFAULT_VALUE) != QSPI_OK)
    {
      return QSPI_ERROR;
    }

    /* Update the address and size variables for next page programming */
    current_addr += current_size;
    pData += current_size;
    current_size = ((current_addr + GD25Q_PAGE_SIZE) > end_addr) ? (end_addr - current_addr) : GD25Q_PAGE_SIZE;
  } while (current_addr < end_addr);

  return QSPI_OK;
}

uint8_t BSP_QSPI_EnableMemoryMappedMode(void)
{
  QSPI_CommandTypeDef      sCommand;
  QSPI_MemoryMappedTypeDef sMemMappedCfg;

  /* Configure the command for the read instruction */
  sCommand.InstructionMode    = QSPI_INSTRUCTION_1_LINE;
  sCommand.Instruction        = GD25Q_FastReadQuadIO;
  sCommand.AddressMode        = QSPI_ADDRESS_4_LINES;
  sCommand.AddressSize        = QSPI_ADDRESS_24_BITS;
  sCommand.AlternateByteMode  = QSPI_ALTERNATE_BYTES_4_LINES;
  sCommand.AlternateBytesSize = QSPI_ALTERNATE_BYTES_8_BITS;
  sCommand.AlternateBytes     = 0;
  sCommand.DataMode           = QSPI_DATA_4_LINES;
  sCommand.DummyCycles        = Q25Q_DUMMY_CYCLES_READ_QUAD;
  sCommand.DdrMode            = QSPI_DDR_MODE_DISABLE;
  sCommand.DdrHoldHalfCycle   = QSPI_DDR_HHC_ANALOG_DELAY;
  sCommand.SIOOMode           = QSPI_SIOO_INST_EVERY_CMD;

  /* Configure the memory mapped mode */
  sMemMappedCfg.TimeOutActivation = QSPI_TIMEOUT_COUNTER_DISABLE;

  if (HAL_QSPI_MemoryMapped(&QSPIHandle, &sCommand, &sMemMappedCfg) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  return QSPI_OK;
}

static uint8_t qspi_setClockPrescaler(void)
{
	uint8_t i;

	for (i = 1; i < 255; i++)
		if ((HAL_RCC_GetHCLKFreq() / i) <= 80000000)
			return i;

	return 0;
}

uint8_t BSP_QSPI_Init(void)
{
	QSPIHandle.Instance = QUADSPI;
#if 1
	//BSP_QSPI_MspDeInit();
	QSPI_HARDWARE_INIT();
	QSPI_Init();
#else

	/* Call the DeInit function to reset the driver */
	if (HAL_QSPI_DeInit(&QSPIHandle) != HAL_OK)
		return QSPI_ERROR;

	/* System level initialization */

	BSP_QSPI_MspInit();

	/* QSPI initialization */
	/* High performance mode clock is limited to 80 MHz */
	QSPIHandle.Init.ClockPrescaler = qspi_setClockPrescaler() + 1;          /* QSPI clock = systemCoreClock / (ClockPrescaler+1) */
	QSPIHandle.Init.FifoThreshold = 4;
	QSPIHandle.Init.SampleShifting = QSPI_SAMPLE_SHIFTING_HALFCYCLE;        //QSPI_SAMPLE_SHIFTING_NONE;
	QSPIHandle.Init.FlashSize = POSITION_VAL(FLASH_SIZE) - 1;
	QSPIHandle.Init.ChipSelectHighTime = QSPI_CS_HIGH_TIME_6_CYCLE;         //QSPI_CS_HIGH_TIME_1_CYCLE;
	QSPIHandle.Init.ClockMode = QSPI_CLOCK_MODE_0;
	QSPIHandle.Init.FlashID = QSPI_FLASH_ID_1;
	QSPIHandle.Init.DualFlash = QSPI_DUALFLASH_DISABLE;
	if (HAL_QSPI_Init(&QSPIHandle) != HAL_OK)
		return QSPI_ERROR;
#endif
#if 1


	u8 id[3] = { 0 };
	GD_ReleasePowerDown();
	GD_EnableQuadMode();
	GD_ReadID_Quad(id);

        unsigned char buf[256] = { 0 };
	GD_Read_Quad(0, 256, buf);
	GD_WaitBusy();
        
        //GD_WriteEnable();
	GD_EraseBlock64k(64*1024);
	//GD_WaitBusy();

	GD_Read_Quad(64*1024, 256, buf);
	GD_WaitBusy();


	uint8_t tb[256] = { 0 };
	for (int i=0; i<256; i++)
		tb[i] = i+10;
	//GD_WriteEnable();
	GD_Program_Quad(64*1024, 256, tb);
	//GD_WaitBusy();

	for(int i = 0; i < 256; i++)
		buf[i] = 0;
	GD_Read_Quad(64*1024, 256, buf);

	for(int i = 0; i < 256; i++)
		printf("buf[%d] = 0x%02x\r\n", i, buf[i]);


#else
	GD25Q_LeaveDeepPowerDown();

	GD25Q_ReadID();

	GD25Q_Enable_QuadMode();

	GD25Q_ReadID_Quad();

	GD25Q_Erase_Sector(0);

	uint8_t tb[256] = { 0 };
	for (int i=0; i<256; i++)
		tb[i] = i;
	GD25Q_Write_Quad(tb, 0, 256);
	unsigned char buf[256] = { 0 };
	GD25Q_Read_Quad(buf,0, 256);
	for(int i = 0; i < 256; i++)
		printf("buf[%d] = 0x%02x\r\n", i, buf[i]);
#endif
#if 0
	/* QSPI memory reset */
	if (QSPI_ResetMemory(&QSPIHandle) != QSPI_OK)
		return QSPI_NOT_SUPPORTED;

	/* QSPI quad enable */
	if (QSPI_QuadMode(&QSPIHandle, QSPI_QUAD_ENABLE) != QSPI_OK)
		return QSPI_ERROR;

	/* High performance mode enable */
	if (QSPI_HighPerfMode(&QSPIHandle, QSPI_HIGH_PERF_ENABLE) != QSPI_OK)
		return QSPI_ERROR;

	/* Re-configure the clock for the high performance mode */
	/* High performance mode clock is limited to 80 MHz */
	QSPIHandle.Init.ClockPrescaler = qspi_setClockPrescaler(); /* QSPI clock = systemCoreClock / (ClockPrescaler+1) */

	if (HAL_QSPI_Init(&QSPIHandle) != HAL_OK)
		return QSPI_ERROR;

#endif
	return QSPI_OK;
}


uint8_t BSP_QSPI_DeInit(void)
{
  QSPIHandle.Instance = QUADSPI;

  /* Call the DeInit function to reset the driver */
  if (HAL_QSPI_DeInit(&QSPIHandle) != HAL_OK)
  {
    return QSPI_ERROR;
  }

  /* System level De-initialization */
  BSP_QSPI_MspDeInit();
  //HAL_QSPI_MspDeInit();

  return QSPI_OK;
}

