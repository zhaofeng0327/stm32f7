#include "qspi_winbond.h"

#define WINBOND_READ_STATUS_1_REG_CMD         0x05
#define WINBOND_READ_STATUS_2_REG_CMD         0x35
#define WINBOND_WRITE_STATUS_REG_CMD          0x01

void QSPI_Winbond_Configure()
{
}

void QSPI_Winbond_WriteEnable()
{
uint32_t cmd;
uint8_t reg;
  
  cmd = FMODE_INDIRECT_WR | DMODE_NO | DCYC_NO |
        ABMODE_NO | ADMODE_NO | IMODE_1_LINE | WRITE_ENABLE_CMD;
  
  QSPI_Transfer(cmd, 0, 0, &reg);

  cmd = FMODE_INDIRECT_RD | DMODE_1_LINE | DCYC_NO |
        ABMODE_NO | ADMODE_NO | IMODE_1_LINE | WINBOND_READ_STATUS_1_REG_CMD;

  do
  {
    QSPI_Transfer(cmd, 0, 1, &reg);
  } while((reg & 0x02) == 0);
}

void QSPI_Winbond_WaitBusy()
{
uint32_t cmd;
uint8_t reg;

  cmd = FMODE_INDIRECT_RD | DMODE_1_LINE | DCYC_NO |
        ABMODE_NO | ADMODE_NO | IMODE_1_LINE | WINBOND_READ_STATUS_1_REG_CMD;

  do
  {
    QSPI_Transfer(cmd, 0, 1, &reg);
  } while((reg & 0x01) != 0);
}
