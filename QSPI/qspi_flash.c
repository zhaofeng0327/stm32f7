#include "qspi_flash.h"
#include "qspi_spansion.h"
#include "qspi_micron.h"
#include "qspi_winbond.h"
#include "qspi_gd.h"

__no_init QSPI_DrvTypeDef *current_qspi_driver;
static void QSPI_Common_ReadID(uint8_t * id);
static void QSPI_Common_Setup(void);
void QSPI_InitDriver(QSPI_DrvTypeDef *driver)
{
uint8_t id[3];
  current_qspi_driver = driver;
  QSPI_Common_Setup();

//#if defined DRV_GD
#if 1
//        GD_DisQuadMode();
//	driver->ReadID = QSPI_Common_ReadID;

	GD_ReleasePowerDown();
//        GD_DisQuadMode();
	GD_EnableQuadMode();
	driver->ReadID = GD_ReadID_Quad;
	driver->ReadID(id);
        
        
	driver->Configure = GD_Configure;
	driver->WriteEnable = GD_WriteEnable;
	driver->WaitBusy = GD_WaitBusy;
	driver->EraseSector = GD_EraseBlock64k;
	driver->EraseChipTimeout = 1000 * 60; // 1 minute
	driver->EraseChip = GD_EraseChip;
	driver->Program = GD_Program_Quad;


#elif defined DRV_MICRON
  driver->ReadID = QSPI_Common_ReadID;

  driver->ReadID(id);
  driver->Configure = QSPI_Micron_Configure;
  driver->WriteEnable = QSPI_Micron_WriteEnable;
  driver->WaitBusy = QSPI_Micron_WaitBusy;
  driver->EraseChipTimeout = 1000 * 60; // 1 minute
  if(0x18 < id[2])
  {/*Device bigger than 128Mb
     supports 4 Bytes Addres Mode*/
    driver->EraseSector = QSPI_Micron_EraseSector;
    driver->Program = QSPI_Micron_Program;
  }
  else
  {/*Device 128Mb or lower
     does not support 4 Bytes Address Mode     */
    driver->EraseSector = QSPI_Common_EraseSector;
    driver->Program = QSPI_Common_Program;
  }
  driver->EraseChip = QSPI_Common_EraseChip;

#elif defined DRV_WINBOND
  driver->ReadID = QSPI_Common_ReadID;

  driver->ReadID(id);
  driver->Configure = QSPI_Winbond_Configure;
  driver->WriteEnable = QSPI_Winbond_WriteEnable;
  driver->WaitBusy = QSPI_Winbond_WaitBusy;
  driver->EraseChipTimeout = 1000 * 60; // 1 minute
  driver->EraseSector = QSPI_Common_EraseSector;
  driver->Program = QSPI_Common_Program;
  driver->EraseChip = QSPI_Common_EraseChip;

#endif

  driver->Configure();
}

static void QSPI_Common_Setup()
{
  QSPI_Init();
}

static void QSPI_Common_ReadID(uint8_t * id)
{
uint32_t cmd;

  cmd = FMODE_INDIRECT_RD | DMODE_1_LINE | DCYC_NO |
        ABMODE_NO | ADMODE_NO | IMODE_1_LINE | READ_ID_CMD;

  QSPI_Transfer(cmd,0,3, id);
}

void QSPI_Common_Program(uint32_t address, uint32_t size, uint8_t* data)
{
uint32_t cmd;

  cmd = FMODE_INDIRECT_WR | DMODE_4_LINES | DCYC_NO | ABMODE_NO |
        ADSIZE_24_BITS | ADMODE_1_LINE | IMODE_1_LINE | QUAD_IN_FAST_PROG_CMD;

  QSPI_Transfer(cmd, address, size, data);
}

void QSPI_Common_EraseSector(uint32_t address)
{
uint32_t cmd;
uint8_t reg;

  cmd = FMODE_INDIRECT_WR | DMODE_NO | DCYC_NO | ABMODE_NO |
        ADSIZE_24_BITS | ADMODE_1_LINE | IMODE_1_LINE | SECTOR_ERASE_CMD;

  QSPI_Transfer(cmd, address, 0, &reg);
}

void QSPI_Common_EraseChip(void)
{
uint32_t cmd;
uint8_t reg;

  cmd = FMODE_INDIRECT_WR | DMODE_NO | DCYC_NO |
        ABMODE_NO | ADMODE_NO | IMODE_1_LINE | BULK_ERASE_CMD;

  QSPI_Transfer(cmd, 0, 0, &reg);

}

__weak void QSPI_DriverErrorCallback()
{
}
