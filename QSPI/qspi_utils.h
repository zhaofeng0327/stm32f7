#ifndef __QSPI_UTILS_H
#define __QSPI_UTILS_H

#include "stm32f746xx.h"

#define  IMODE_NO           ((uint32_t)0x00000000)
#define  IMODE_1_LINE       QUADSPI_CCR_IMODE_0
#define  IMODE_2_LINES      QUADSPI_CCR_IMODE_1
#define  IMODE_4_LINES      (QUADSPI_CCR_IMODE_0|QUADSPI_CCR_IMODE_1)

#define  ADMODE_NO          ((uint32_t)0x00000000)
#define  ADMODE_1_LINE      QUADSPI_CCR_ADMODE_0
#define  ADMODE_2_LINES     QUADSPI_CCR_ADMODE_1
#define  ADMODE_4_LINES     (QUADSPI_CCR_ADMODE_0|QUADSPI_CCR_ADMODE_1)

#define  ADSIZE_8_BITS      ((uint32_t)0x00000000)
#define  ADSIZE_16_BITS     QUADSPI_CCR_ADSIZE_0
#define  ADSIZE_24_BITS     QUADSPI_CCR_ADSIZE_1
#define  ADSIZE_32_BITS     (QUADSPI_CCR_ADSIZE_0|QUADSPI_CCR_ADSIZE_1)

#define  ABMODE_NO          ((uint32_t)0x00000000)
#define  ABMODE_1_LINE      QUADSPI_CCR_ABMODE_0
#define  ABMODE_2_LINES     QUADSPI_CCR_ABMODE_1
#define  ABMODE_4_LINES     (QUADSPI_CCR_ABMODE_0|QUADSPI_CCR_ABMODE_1)

#define  ABSIZE_8_BITS      ((uint32_t)0x00000000)
#define  ABSIZE_16_BITS     QUADSPI_CCR_ABSIZE_0
#define  ABSIZE_24_BITS     QUADSPI_CCR_ABSIZE_1
#define  ABSIZE_32_BITS     (QUADSPI_CCR_ABSIZE_0|QUADSPI_CCR_ABSIZE_1)

#define  DCYC_NO            ((uint32_t)0x00000000)
#define  DCYC_1_CLK         ((uint32_t)0x00040000)
#define  DCYC_2_CLKS        ((uint32_t)0x00080000)
#define  DCYC_3_CLKS        ((uint32_t)0x000C0000)
#define  DCYC_4_CLKS        ((uint32_t)0x00100000)
#define  DCYC_5_CLKS        ((uint32_t)0x00140000)
#define  DCYC_6_CLKS        ((uint32_t)0x00180000)
#define  DCYC_7_CLKS        ((uint32_t)0x001C0000)
#define  DCYC_8_CLKS        ((uint32_t)0x00200000)
#define  DCYC_9_CLKS        ((uint32_t)0x00240000)
#define  DCYC_10_CLKS       ((uint32_t)0x00280000)
#define  DCYC_11_CLKS       ((uint32_t)0x002C0000)
#define  DCYC_12_CLKS       ((uint32_t)0x00300000)
#define  DCYC_13_CLKS       ((uint32_t)0x00340000)
#define  DCYC_14_CLKS       ((uint32_t)0x00380000)
#define  DCYC_15_CLKS       ((uint32_t)0x003C0000)
#define  DCYC_16_CLKS       ((uint32_t)0x00400000)
#define  DCYC_17_CLKS       ((uint32_t)0x00440000)
#define  DCYC_18_CLKS       ((uint32_t)0x00480000)
#define  DCYC_19_CLKS       ((uint32_t)0x004C0000)
#define  DCYC_20_CLKS       ((uint32_t)0x00500000)
#define  DCYC_21_CLKS       ((uint32_t)0x00540000)
#define  DCYC_22_CLKS       ((uint32_t)0x00580000)
#define  DCYC_23_CLKS       ((uint32_t)0x005C0000)
#define  DCYC_24_CLKS       ((uint32_t)0x00600000)
#define  DCYC_25_CLKS       ((uint32_t)0x00640000)
#define  DCYC_26_CLKS       ((uint32_t)0x00680000)
#define  DCYC_27_CLKS       ((uint32_t)0x006C0000)
#define  DCYC_28_CLKS       ((uint32_t)0x00700000)
#define  DCYC_29_CLKS       ((uint32_t)0x00740000)
#define  DCYC_30_CLKS       ((uint32_t)0x00780000)
#define  DCYC_31_CLKS       ((uint32_t)0x007C0000)

#define  DMODE_NO           ((uint32_t)0x00000000)
#define  DMODE_1_LINE       QUADSPI_CCR_DMODE_0
#define  DMODE_2_LINES      QUADSPI_CCR_DMODE_1
#define  DMODE_4_LINES      (QUADSPI_CCR_DMODE_0|QUADSPI_CCR_DMODE_1)

#define  FMODE_INDIRECT_WR  ((uint32_t)0x00000000)
#define  FMODE_INDIRECT_RD  QUADSPI_CCR_FMODE_0
#define  FMODE_AUTO_POLL    QUADSPI_CCR_FMODE_1
#define  FMODE_MEM_MAP      (QUADSPI_CCR_FMODE_0|QUADSPI_CCR_FMODE_1)

#define  QUADSPI_CCR_FMODE                        ((uint32_t)0x0C000000)            /*!< FMODE[1:0]: Functional Mode        */
#define  QUADSPI_CCR_FMODE_0                      ((uint32_t)0x04000000)            /*!< Bit 0 */
#define  QUADSPI_CCR_FMODE_1                      ((uint32_t)0x08000000)            /*!< Bit 1 */

void QSPI_Init(void);
void QSPI_Transfer(uint32_t config, uint32_t address, uint32_t size, void * data);
//void QSPI_SendCommand(QSPI_CommandTypeDef* cmd);
//void QSPI_SendData(uint8_t *data,uint32_t size);
//void QSPI_ReadData(uint8_t *data,uint32_t size);
//void QSPI_SendDataQuad(uint8_t *data,uint32_t size);

#endif
