/*************************************************************************
 *
 *   Used with ICCARM and AARM.
 *
 *    (c) Copyright IAR Systems 2015
 *
 *    File name   : FlashSTM32F7xx_QSPI.c
 *    Description : Flash Loader For Serial NOR flash
 *
 *    History :
 *    1. Date        : April, 2015
 *       Author      : Atanas Uzunov
 *       Description : Initial QSPI flashloader for Micron N25Q512A13GSF40E
 *
 *
 *    $Revision: 39 $
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "qspi_flash.h"

/* The flash loader framework API declarations */
#include "flash_loader.h"
#include "flash_loader_extra.h"

/** default settings **/
#define QSPI_PAGE_SIZE 256

/** external functions **/

/** external data **/

/** internal functions **/
#if USE_ARGC_ARGV
/** private functions **/
static const char* FlFindOption(char* option, int with_value, int argc, char const* argv[]);
#endif

/** public data **/
/** private data **/
__no_init QSPI_DrvTypeDef qspi_driver;

/** public functions **/

/*************************************************************************
 * Function Name: FlashInit
 * Parameters: Flash Base Address
 *
 * Return: RESULT_OK
 *         RESULT_ERASE_DONE
 *
 * Description: Init QSPI flash driver.
 *************************************************************************/
#if USE_ARGC_ARGV
uint32_t FlashInit(void *base_of_flash, uint32_t image_size,
                   uint32_t link_address, uint32_t flags,
                   int argc, char const *argv[])
#else
uint32_t FlashInit(void *base_of_flash, uint32_t image_size,
                   uint32_t link_address, uint32_t flags)
#endif  /*USE_ARGC_ARGV*/
{
  QSPI_InitDriver(&qspi_driver);

  if (flags & FLAG_ERASE_ONLY)
  {
    /* the flash loader has been invoked with the sole purpose of erasing
       the whole flash memory */
    /*Poll Flash Busy flag*/
    qspi_driver.WaitBusy();
    /*Enable Write operations*/
    qspi_driver.WriteEnable();
    /**/
    qspi_driver.EraseChip();
    /* Wait operation to complete */
    qspi_driver.WaitBusy();
    
    return RESULT_ERASE_DONE;
  }
  return(RESULT_OK);
}

/*************************************************************************
 * Function Name: FlashWrite
 * Parameters: block base address, offset in block, data size, ram buffer
 *             pointer
 * Return: 0
 *
 * Description. Writes data to QSPI flash
 *************************************************************************/
uint32_t FlashWrite(void *block_start,
                    uint32_t offset_into_block,
                    uint32_t count,
                    char const *buffer)
{
uint32_t size = 0;
/* Set destination address */
uint32_t Dest = (uint32_t)block_start + offset_into_block;
/* Set source address */
uint8_t * Src = (uint8_t *)(buffer);

  while(size < count)
  {
    /*Poll Flash Busy flag*/
    qspi_driver.WaitBusy();
    /*Enable Write operations*/
    qspi_driver.WriteEnable();
    /* Write one page */
    qspi_driver.Program(Dest, QSPI_PAGE_SIZE, Src);

    size += (QSPI_PAGE_SIZE);
    Dest += (QSPI_PAGE_SIZE);
    Src += (QSPI_PAGE_SIZE);
    /* Wait operation to complete */
    qspi_driver.WaitBusy();
  }

  return(RESULT_OK);
}

/*************************************************************************
 * Function Name: FlashErase
 * Parameters:  Block Address, Block Size
 *
 * Return: 0
 *
 * Description: Erase block
 *************************************************************************/
uint32_t FlashErase(void *block_start,
                    uint32_t block_size)
{
  /*Poll Flash Busy flag*/
  qspi_driver.WaitBusy();
  /*Enable Write operations*/
  qspi_driver.WriteEnable();
  /* Erase one flash block */
  qspi_driver.EraseSector((int32_t)block_start);
  /* Wait operation to complete */
  qspi_driver.WaitBusy();
  return RESULT_OK;
}

/*************************************************************************
 * Function Name: FlashSignoff
 * Parameters: none
 *
 * Return: RESULT_OK
 *         RESULT_ERROR
 *
 * Description:
 *************************************************************************/
#if USE_ARGC_ARGV
OPTIONAL_SIGNOFF
uint32_t FlashSignoff(void)
{
  return RESULT_OK;
}
#endif

/** private functions **/
#if USE_ARGC_ARGV
/** private functions **/
static const char* FlFindOption(char* option, int with_value, int argc, char const* argv[])
{
  int i;

  for (i = 0; i < argc; i++)
  {
    if (strcmp(option, argv[i]) == 0)
    {
      if (with_value)
      {
        if (i + 1 < argc)
          return argv[i + 1]; // The next argument is the value.
        else
          return 0; // The option was found but there is no value to return.
      }
      else
      {
        return argv[i]; // Return the flag argument itself just to get a non-zero pointer.
      }
    }
  }
  return 0;
}
#endif // USE_ARGC_ARGV

