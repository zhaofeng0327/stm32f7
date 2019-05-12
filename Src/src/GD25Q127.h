#ifndef _GD25Q127_H_
#define _GD25Q127_H_
#include <stdint.h>
/* GD25Q127 指令表 */
#define GD25Q_WriteEnable		0x06
#define GD25Q_WriteDisable		0x04

#define GD25Q_ReadStatusReg1	0x05
#define GD25Q_ReadStatusReg2	0x35
#define GD25Q_ReadStatusReg3	0x15

#define GD25Q_WriteStatusReg1	0x01
#define GD25Q_WriteStatusReg2	0x31
#define GD25Q_WriteStatusReg3	0x11

#define GD25Q_ReadData			0x03
#define GD25Q_FastReadData		0x0B

#define GD25Q_FastReadDual		0x3B
#define GD25Q_FastReadDualIO	0xBB

#define GD25Q_FastReadQuad		0x6B
#define GD25Q_FastReadQuadIO	0xEB
#define GD25Q_FastReadQuadWord	0xE7



#define GD25Q_PageProgram		0x02
#define GD25Q_PageProgramQuad	0x32


#define GD25Q_SectorErase		0x20
#define GD25Q_BlockErase32k		0x52
#define GD25Q_BlockErase64k		0xD8
#define GD25Q_ChipErase			0xC7


#define GD25Q_ENABLE_RESET		0x66
#define GD25Q_RESET				0x99

#define GD25Q_PowerDown			0xB9
#define GD25Q_ReleasePowerDown	0xAB


#define GD25Q_ManufactDeviceID		0x90
#define GD25Q_DeviceID_Dual			0x92
#define GD25Q_DeviceID_Quad			0x94
#define GD25Q_DeviceID				0x9F



#define GD25Q_SR_WIP	(0x1)    /*!< Write in progress */
#define GD25Q_SR_WEL	(0x1<<1)    /*!< Write enable latch */
#define GD25Q_SR_BP		(0x1f<<2)    /*!< Block protect */

#define GD25Q_SR_QE		(0x1<<1)    /*!< Quad enable */

#define GD25Q_SR_DRV	(0x3<<5)
#define GD25Q_SR_HOLD	(0x1<<7)


#define QSPI_OK            ((uint8_t)0x00)
#define QSPI_ERROR         ((uint8_t)0x01)
#define QSPI_BUSY          ((uint8_t)0x02)
#define QSPI_NOT_SUPPORTED ((uint8_t)0x04)
#define QSPI_SUSPENDED     ((uint8_t)0x08)

#define QSPI_QUAD_DISABLE       0x0
#define QSPI_QUAD_ENABLE        0x1

#define GD25Q_FLASH_SIZE                0x800000  /* 64 MBits => 8MBytes */
#define GD25Q_SECTOR_SIZE               0x1000    /* 2048 sectors of 4kBytes */
#define GD25Q_PAGE_SIZE               0x100

#define GD25Q_CHIP_ERASE_MAX_TIME       240000
#define GD25Q_BLOCK_ERASE_MAX_TIME      3500
#define GD25Q_SUBBLOCK_ERASE_MAX_TIME   3000
#define GD25Q_SECTOR_ERASE_MAX_TIME     240


#define Q25Q_DUMMY_CYCLES_READ_QUAD 4
#define Q25Q_DUMMY_CYCLES_READ_QUAD_WORD 2
uint8_t BSP_QSPI_Init(void);

#endif
