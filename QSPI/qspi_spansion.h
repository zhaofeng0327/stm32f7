#ifndef __QSPI_SPANSION_H
#define __QSPI_SPANSION_H

#include "qspi_flash.h"

void QSPI_Spansion_Configure(void);
void QSPI_Spansion_WriteEnable(void);
void QSPI_Spansion_AutoPollingMemReady(void);
void QSPI_Spansion_MemoryMap(void);

#endif
