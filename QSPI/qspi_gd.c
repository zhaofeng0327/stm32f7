//------------------------------------------------------------------------------
//
// Copyright (c) 2008-2015 IAR Systems
//
// Licensed under the Apache License, Version 2.0 (the "License")
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// $Revision: 38952 $
//
//------------------------------------------------------------------------------

#include "flash_loader.h"
#include "flash_loader_extra.h"
#include "qspi_gd.h"
void strcopy(char *to, char* from);
/*
uint32_t FlashInit(void *base_of_flash, uint32_t image_size,
                   uint32_t link_address, uint32_t flags,
                   int argc, char const *argv[])
{
//  strcopy(LAYOUT_OVERRIDE_BUFFER,"2 0x100,7 0x200,7 0x1000");
//  SET_BUFSIZE_OVERRIDE(&FlashBufferEnd-&FlashBufferStart+1);
//  SET_PAGESIZE_OVERRIDE(128);
//  return OVERRIDE_LAYOUT | OVERRIDE_BUFEND | OVERRIDE_PAGESIZE;
//  if (flags & FLAG_ERASE_ONLY)
//  {
//    perform full erase
//    return RESULT_ERASE_DONE;
//  }
  return RESULT_OK;
}

uint32_t FlashWrite(void *block_start,
                    uint32_t offset_into_block,
                    uint32_t count,
                    char const *buffer)
{
  char *to = (char*)block_start + offset_into_block;
  while (count--)
  {
    *to++ = *buffer++;
  }
  return 0;
}

uint32_t FlashErase(void *block_start,
                    uint32_t block_size)
{
  char *p = (char*)block_start;
  while (block_size--)
  {
    *p++ = 0;
  }
  return 0;
}

OPTIONAL_CHECKSUM
uint32_t FlashChecksum(void const *begin, uint32_t count)
{
  return Crc16((uint8_t const *)begin, count);
}

OPTIONAL_SIGNOFF
uint32_t FlashSignoff(void)
{
  return 0;
}
void strcopy(char *to, char* from)
{
  while (*to++ = *from++) ;
}

*/
void GD_ReleasePowerDown()
{
	uint32_t cmd;
	uint8_t reg;
	cmd = FMODE_INDIRECT_WR | DMODE_NO | DCYC_NO |
		  ABMODE_NO | ADMODE_NO | IMODE_1_LINE | GD25Q_ReleasePowerDown;

	QSPI_Transfer(cmd, 0, 0, &reg);
}

uint8_t GD_ReadStatusReg(uint8_t id)
{
	uint32_t cmd;
	uint8_t reg;
	cmd = FMODE_INDIRECT_RD | DMODE_1_LINE | DCYC_NO |
		  ABMODE_NO | ADMODE_NO | IMODE_1_LINE | id;

	QSPI_Transfer(cmd, 0, 1, &reg);
	return reg;

}

void GD_WriteEnable()
{
	uint32_t cmd;
	uint8_t reg;

  cmd = FMODE_INDIRECT_WR | DMODE_NO | DCYC_NO |
        ABMODE_NO | ADMODE_NO | IMODE_1_LINE | GD25Q_WriteEnable;

  QSPI_Transfer(cmd, 0, 0, &reg);

  //cmd = FMODE_INDIRECT_RD | DMODE_1_LINE | DCYC_NO |
  //      ABMODE_NO | ADMODE_NO | IMODE_1_LINE | GD25Q_ReadStatusReg1;

  do
  {
    //QSPI_Transfer(cmd, 0, 1, &reg);
	reg = GD_ReadStatusReg(GD25Q_ReadStatusReg1);
  } while((reg & 0x02) == 0);
}

void GD_WaitBusy()
{
uint8_t reg;

  //cmd = FMODE_INDIRECT_RD | DMODE_1_LINE | DCYC_NO |
  //      ABMODE_NO | ADMODE_NO | IMODE_1_LINE | GD25Q_ReadStatusReg1;

  do
  {
    //QSPI_Transfer(cmd, 0, 1, &reg);
    reg = GD_ReadStatusReg(GD25Q_ReadStatusReg1);
  } while((reg & 0x01) != 0);
}

void GD_EnableQuadMode()
{
	uint32_t cmd;
	uint8_t reg = GD_ReadStatusReg(GD25Q_ReadStatusReg2);
	reg |= 0x1<<1;
	GD_WriteEnable();

	cmd = FMODE_INDIRECT_WR | DMODE_1_LINE | DCYC_NO |
		  ABMODE_NO | ADMODE_NO | IMODE_1_LINE | GD25Q_WriteStatusReg2;

	QSPI_Transfer(cmd, 0, 1, &reg);
	GD_WaitBusy();

	//reg = GD_ReadStatusReg(GD25Q_ReadStatusReg2);
	//if (0 == reg & 0x2)
}

void GD_DisQuadMode()
{
	uint32_t cmd;
	uint8_t reg = GD_ReadStatusReg(GD25Q_ReadStatusReg2);
	reg &= ~(0x1<<1);
	GD_WriteEnable();

	cmd = FMODE_INDIRECT_WR | DMODE_1_LINE | DCYC_NO |
		  ABMODE_NO | ADMODE_NO | IMODE_1_LINE | GD25Q_WriteStatusReg2;

	QSPI_Transfer(cmd, 0, 1, &reg);
	GD_WaitBusy();

	//reg = GD_ReadStatusReg(GD25Q_ReadStatusReg2);
	//if (0 == reg & 0x2)
}




void GD_ReadID_Quad(uint8_t * id)
{
	uint8_t reg[6] = {0};
	uint32_t cmd;
	cmd = FMODE_INDIRECT_RD | DMODE_4_LINES | DCYC_4_CLKS |
		  ABMODE_4_LINES | ABSIZE_8_BITS | ADMODE_4_LINES | ADSIZE_24_BITS | IMODE_1_LINE | GD25Q_DeviceID_Quad;

	QSPI_Transfer(cmd, 0, 6, &reg);
	id[0] = reg[0];
	id[1] = reg[1];
	id[2] = 0xC8;
}

void GD_EraseSector(uint32_t address)
{
  uint32_t cmd;
  uint8_t reg;
  GD_WriteEnable();
  cmd = FMODE_INDIRECT_WR | DMODE_NO | DCYC_NO | ABMODE_NO |
        ADSIZE_24_BITS | ADMODE_1_LINE | IMODE_1_LINE | GD25Q_SectorErase;

  QSPI_Transfer(cmd, address, 0, &reg);
  GD_WaitBusy();
}

void GD_EraseBlock64k(uint32_t address)
{
  uint32_t cmd;
  uint8_t reg;
  GD_WriteEnable();
  cmd = FMODE_INDIRECT_WR | DMODE_NO | DCYC_NO | ABMODE_NO |
        ADSIZE_24_BITS | ADMODE_1_LINE | IMODE_1_LINE | GD25Q_BlockErase64k;

  QSPI_Transfer(cmd, address, 0, &reg);
  GD_WaitBusy();
}


void GD_EraseChip()
{
  GD_WriteEnable();
  QSPI_Common_EraseChip();
  GD_WaitBusy();
}

void GD_Program_Quad(uint32_t address, uint32_t size, uint8_t* data)
{
  uint32_t cmd;
  GD_WriteEnable();
  cmd = FMODE_INDIRECT_WR | DMODE_4_LINES | DCYC_NO | ABMODE_NO |
        ADSIZE_24_BITS | ADMODE_1_LINE | IMODE_1_LINE | GD25Q_PageProgramQuad;

  QSPI_Transfer(cmd, address, size, data);
  GD_WaitBusy();
}



void GD_Program(uint32_t address, uint32_t size, uint8_t* data)
{
  uint32_t cmd;
  GD_WriteEnable();
  cmd = FMODE_INDIRECT_WR | DMODE_4_LINES | DCYC_NO | ABMODE_NO |
        ADSIZE_24_BITS | ADMODE_1_LINE | IMODE_1_LINE | GD25Q_PageProgram;

  QSPI_Transfer(cmd, address, size, data);
  GD_WaitBusy();
}



void GD_Configure()
{
  GD_ReleasePowerDown();
  GD_EnableQuadMode();
  //GD_DisQuadMode();
  GD_WriteEnable();
}

void GD_Read_Quad(uint32_t address, uint32_t size,uint8_t *data)
{
  uint32_t cmd;

  cmd = FMODE_INDIRECT_RD | DMODE_4_LINES | DCYC_4_CLKS | ABMODE_4_LINES | ABSIZE_8_BITS |
                ADSIZE_24_BITS | ADMODE_4_LINES | IMODE_1_LINE | GD25Q_FastReadQuadIO;

  QSPI_Transfer(cmd, address, size, data);


}

