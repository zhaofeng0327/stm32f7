#ifndef __QSPI_WINBOND_H
#define __QSPI_WINBOND_H

#include "qspi_flash.h"

void QSPI_Winbond_Configure(void);
void QSPI_Winbond_WriteEnable(void);
void QSPI_Winbond_WaitBusy(void);

#endif
