#include "qspi_spansion.h"

#define SPANSION_READ_CFG_REG_CMD          0x35
#define SPANSION_READ_SR_REG_CMD           0x05
#define SPANSION_WRITE_REG_CMD             0x01

void QSPI_Spansion_Configure()
{
QSPI_CommandTypeDef cmd;
uint8_t regs[2];


  /* Read Volatile Configuration register --------------------------- */
  cmd.CommandID       = SPANSION_READ_SR_REG_CMD;
  cmd.UseAddress      = 0;
  cmd.DataMode        = DATA_SINGLE_LINE;
  cmd.NumData         = 1;
  cmd.Address         = 0;

  QSPI_SendCommand(&cmd);
  QSPI_ReadData(&regs[0],1);

  cmd.CommandID = SPANSION_READ_CFG_REG_CMD;

  QSPI_SendCommand(&cmd);
  QSPI_ReadData(&regs[1],1);

  /* Enable write operations ---------------------------------------- */
  QSPI_Spansion_WriteEnable();

  /* Write Volatile Configuration register (with new dummy cycles) -- */  
  cmd.CommandID = SPANSION_WRITE_REG_CMD;
  cmd.NumData = 2;
  regs[1] |= 0x2;

  QSPI_SendCommand(&cmd);
  QSPI_SendData(regs,2);
  
}

void QSPI_Spansion_WriteEnable()
{
QSPI_CommandTypeDef     cmd;
uint8_t reg;

  cmd.CommandID = WRITE_ENABLE_CMD;
  cmd.Address = 0;
  cmd.DataMode = 0;
  cmd.NumData = 0;
  cmd.UseAddress = 0;

  QSPI_SendCommand(&cmd);

  cmd.CommandID    = SPANSION_READ_SR_REG_CMD;
  cmd.DataMode     = DATA_SINGLE_LINE;
  cmd.NumData      = 1;

  do
  {
    QSPI_SendCommand(&cmd);
    QSPI_ReadData(&reg,1);
  }while((reg & 0x02) == 0);
}

void QSPI_Spansion_AutoPollingMemReady()
{
QSPI_CommandTypeDef     cmd;
uint8_t reg;

  cmd.Address      = 0;
  cmd.CommandID    = SPANSION_READ_SR_REG_CMD;
  cmd.DataMode     = DATA_SINGLE_LINE;
  cmd.NumData      = 1;
  cmd.UseAddress   = 0;

  do
  {
    QSPI_SendCommand(&cmd);
    QSPI_ReadData(&reg,1);
  }while((reg & 0x01) != 0);
}
