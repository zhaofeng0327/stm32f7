#include "qspi_micron.h"

#define MICRON_READ_VOL_CFG_REG_CMD          0x85
#define MICRON_WRITE_VOL_CFG_REG_CMD         0x81
#define MICRON_DUMMY_CLOCK_CYCLES_READ_QUAD  0x08
#define MICRON_READ_STATUS_REG_CMD           0x05
#define MICRON_WRITE_STATUS_REG_CMD          0x01
#define MICRON_4B_QUAD_IN_FAST_PROG_CMD      0x34
#define MICRON_4B_SECTOR_ERASE_CMD           0xDC

void QSPI_Micron_Configure()
{
}

/**/
void QSPI_Micron_WriteEnable()
{
uint32_t cmd;
uint8_t reg;

  cmd = FMODE_INDIRECT_WR | DMODE_NO | DCYC_NO |
        ABMODE_NO | ADMODE_NO | IMODE_1_LINE | WRITE_ENABLE_CMD;
  
  QSPI_Transfer(cmd, 0, 0, &reg);

  cmd = FMODE_INDIRECT_RD | DMODE_1_LINE | DCYC_NO |
        ABMODE_NO | ADMODE_NO | IMODE_1_LINE | MICRON_READ_STATUS_REG_CMD;

  do
  {
    QSPI_Transfer(cmd, 0, 1, &reg);
  } while((reg & 0x02) == 0);
}

void QSPI_Micron_WaitBusy()
{
uint32_t cmd;
uint8_t reg;

  cmd = FMODE_INDIRECT_RD | DMODE_1_LINE | DCYC_NO |
        ABMODE_NO | ADMODE_NO | IMODE_1_LINE | MICRON_READ_STATUS_REG_CMD;

  do
  {
    QSPI_Transfer(cmd, 0, 1, &reg);
  } while((reg & 0x01) != 0);
}

void QSPI_Micron_Program(uint32_t address, uint32_t size, uint8_t* data)
{
uint32_t cmd;

  cmd = FMODE_INDIRECT_WR | DMODE_4_LINES | DCYC_NO | ABMODE_NO |
        ADSIZE_32_BITS | ADMODE_1_LINE | IMODE_1_LINE | MICRON_4B_QUAD_IN_FAST_PROG_CMD;
  
  QSPI_Transfer(cmd, address, size, data);
}

void QSPI_Micron_EraseSector(uint32_t address)
{
uint32_t cmd;
uint8_t reg;

  cmd = FMODE_INDIRECT_WR | DMODE_NO | DCYC_NO | ABMODE_NO |
        ADSIZE_32_BITS | ADMODE_1_LINE | IMODE_1_LINE | MICRON_4B_SECTOR_ERASE_CMD;

  QSPI_Transfer(cmd, address, 0, &reg);
}

