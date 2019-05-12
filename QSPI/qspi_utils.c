#include "qspi_utils.h"

void QSPI_Init(void)
{
  /*Prescaler = 4 and Threshold = 3 half Sample shift & select flash id 1 & dis dual flash*/
  QUADSPI->CR = (4<<24) | (3<<8) | (1<<4);
  /**/
  QUADSPI->CCR = 0;
  /*8MB && 6 select high circle && clock mode 0*/
  QUADSPI->DCR = (22<<16) | (5<<8);
  /*Enable*/
  QUADSPI->CR |= QUADSPI_CR_EN;
}

void QSPI_Transfer(uint32_t config, uint32_t address, uint32_t size, void * data)
{
  /**/
  while(QUADSPI_SR_BUSY & QUADSPI->SR);
  /*set transfer size*/
  QUADSPI->DLR = size - 1;
  /*alternate byte set. Currently not supported*/
  QUADSPI->ABR = 0;
  /*set transfer this will start the transfer if the IMODE != IMODE_NO*/
  QUADSPI->CCR = config;
  /*Set address*/
  QUADSPI->AR = address;

  /*Read or write data. Only if Size > 0*/
  for(uint32_t i = 0;i < size;++i)
  { /*Wait fifo threshold*/
    while(!(QUADSPI_SR_FTF & QUADSPI->SR));
    if(FMODE_INDIRECT_WR == (config & QUADSPI_CCR_FMODE))
    {/*Write */
      *(__IO uint8_t *)(&QUADSPI->DR) = ((uint8_t *)data)[i];
    }    
    else
    {/*Read*/
      ((uint8_t *)data)[i] = *(__IO uint8_t *)(&QUADSPI->DR);
    }
  }
  while(!(QUADSPI_SR_TCF & QUADSPI->SR));
  QUADSPI->FCR |= QUADSPI_FCR_CTCF;
}
