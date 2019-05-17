#ifndef _SPI_GD_H_
#define _SPI_GD_H_


#include <stdint.h>
uint8_t GD_read_fast(uint8_t *pData, uint32_t Rdaddr, uint32_t size);
uint8_t GD_write(uint8_t *pData, uint32_t WriteAddr, uint32_t size);
int GD_erase_sector(uint32_t id);
int spi_flash_init(void);


#endif
