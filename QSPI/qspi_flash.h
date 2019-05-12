#ifndef __QSPI_FLASH_H
#define __QSPI_FLASH_H

#include "qspi_utils.h"

/* Common commands definition */
#define READ_ID_CMD                          0x9F
#define QUAD_OUT_FAST_READ_CMD               0x6B
#define WRITE_ENABLE_CMD                     0x06
#define SECTOR_ERASE_CMD                     0xD8
#define QUAD_IN_FAST_PROG_CMD                0x32
#define BULK_ERASE_CMD                       0xC7

/* Common macro definition */
#define QSPI_ID_GET_VID(x)                   (x & 0xFF)
#define QSPI_ID_GET_PID(x)                   ((x & 0xFFFF00) >> 8)

typedef struct
{
  uint32_t   EraseChipTimeout;
  void       (*ReadID)(uint8_t *);
  void       (*Configure)(void);
  void       (*WriteEnable)(void);
  void       (*WaitBusy)(void);
  void       (*EraseSector)(uint32_t address);
  void       (*EraseChip)(void);
  void       (*Program)(uint32_t address, uint32_t size, uint8_t* data);
}QSPI_DrvTypeDef;

extern QSPI_DrvTypeDef *current_qspi_driver;

void QSPI_InitDriver(QSPI_DrvTypeDef *driver);
void QSPI_DriverErrorCallback(void);
void QSPI_Common_EraseSector(uint32_t address);
void QSPI_Common_Program(uint32_t address, uint32_t size, uint8_t* data);
void QSPI_Common_EraseChip(void);

#endif
