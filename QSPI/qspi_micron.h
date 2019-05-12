#ifndef __QSPI_MICRON_H
#define __QSPI_MICRON_H

#include "qspi_flash.h"

void QSPI_Micron_Configure(void);
void QSPI_Micron_WriteEnable(void);
void QSPI_Micron_WaitBusy(void);
void QSPI_Micron_Program(uint32_t address, uint32_t size, uint8_t* data);
void QSPI_Micron_EraseSector(uint32_t address);

#endif
