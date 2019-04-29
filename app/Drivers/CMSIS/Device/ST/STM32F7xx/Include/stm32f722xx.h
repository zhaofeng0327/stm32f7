/**
 ******************************************************************************
 * @file    stm32f722xx.h
 * @author  MCD Application Team
 * @brief   CMSIS Cortex-M7 Device Peripheral Access Layer Header File.
 *
 *          This file contains:
 *           - Data structures and the address mapping for all peripherals
 *           - Peripheral's registers declarations and bits definition
 *           - Macros to access peripherals registers hardware
 *
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2016 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/** @addtogroup CMSIS_Device
 * @{
 */

/** @addtogroup stm32f722xx
 * @{
 */

#ifndef __STM32F722xx_H
#define __STM32F722xx_H

#ifdef __cplusplus
extern "C" {
#endif	/* __cplusplus */

/** @addtogroup Configuration_section_for_CMSIS
 * @{
 */

/**
 * @brief STM32F7xx Interrupt Number Definition, according to the selected device
 *        in @ref Library_configuration_section
 */
typedef enum {
	/******  Cortex-M7 Processor Exceptions Numbers ****************************************************************/
	NonMaskableInt_IRQn     = -14,	/*!< 2 Non Maskable Interrupt                                          */
	MemoryManagement_IRQn   = -12,	/*!< 4 Cortex-M7 Memory Management Interrupt                           */
	BusFault_IRQn           = -11,	/*!< 5 Cortex-M7 Bus Fault Interrupt                                   */
	UsageFault_IRQn         = -10,	/*!< 6 Cortex-M7 Usage Fault Interrupt                                 */
	SVCall_IRQn             = -5,	/*!< 11 Cortex-M7 SV Call Interrupt                                    */
	DebugMonitor_IRQn       = -4,	/*!< 12 Cortex-M7 Debug Monitor Interrupt                              */
	PendSV_IRQn             = -2,	/*!< 14 Cortex-M7 Pend SV Interrupt                                    */
	SysTick_IRQn            = -1,	/*!< 15 Cortex-M7 System Tick Interrupt                                */
	/******  STM32 specific Interrupt Numbers **********************************************************************/
	WWDG_IRQn               = 0,	/*!< Window WatchDog Interrupt                                         */
	PVD_IRQn                = 1,	/*!< PVD through EXTI Line detection Interrupt                         */
	TAMP_STAMP_IRQn         = 2,	/*!< Tamper and TimeStamp interrupts through the EXTI line             */
	RTC_WKUP_IRQn           = 3,	/*!< RTC Wakeup interrupt through the EXTI line                        */
	FLASH_IRQn              = 4,	/*!< FLASH global Interrupt                                            */
	RCC_IRQn                = 5,	/*!< RCC global Interrupt                                              */
	EXTI0_IRQn              = 6,	/*!< EXTI Line0 Interrupt                                              */
	EXTI1_IRQn              = 7,	/*!< EXTI Line1 Interrupt                                              */
	EXTI2_IRQn              = 8,	/*!< EXTI Line2 Interrupt                                              */
	EXTI3_IRQn              = 9,	/*!< EXTI Line3 Interrupt                                              */
	EXTI4_IRQn              = 10,	/*!< EXTI Line4 Interrupt                                              */
	DMA1_Stream0_IRQn       = 11,	/*!< DMA1 Stream 0 global Interrupt                                    */
	DMA1_Stream1_IRQn       = 12,	/*!< DMA1 Stream 1 global Interrupt                                    */
	DMA1_Stream2_IRQn       = 13,	/*!< DMA1 Stream 2 global Interrupt                                    */
	DMA1_Stream3_IRQn       = 14,	/*!< DMA1 Stream 3 global Interrupt                                    */
	DMA1_Stream4_IRQn       = 15,	/*!< DMA1 Stream 4 global Interrupt                                    */
	DMA1_Stream5_IRQn       = 16,	/*!< DMA1 Stream 5 global Interrupt                                    */
	DMA1_Stream6_IRQn       = 17,	/*!< DMA1 Stream 6 global Interrupt                                    */
	ADC_IRQn                = 18,	/*!< ADC1, ADC2 and ADC3 global Interrupts                             */
	CAN1_TX_IRQn            = 19,	/*!< CAN1 TX Interrupt                                                 */
	CAN1_RX0_IRQn           = 20,	/*!< CAN1 RX0 Interrupt                                                */
	CAN1_RX1_IRQn           = 21,	/*!< CAN1 RX1 Interrupt                                                */
	CAN1_SCE_IRQn           = 22,	/*!< CAN1 SCE Interrupt                                                */
	EXTI9_5_IRQn            = 23,	/*!< External Line[9:5] Interrupts                                     */
	TIM1_BRK_TIM9_IRQn      = 24,	/*!< TIM1 Break interrupt and TIM9 global interrupt                    */
	TIM1_UP_TIM10_IRQn      = 25,	/*!< TIM1 Update Interrupt and TIM10 global interrupt                  */
	TIM1_TRG_COM_TIM11_IRQn = 26,	/*!< TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
	TIM1_CC_IRQn            = 27,	/*!< TIM1 Capture Compare Interrupt                                    */
	TIM2_IRQn               = 28,	/*!< TIM2 global Interrupt                                             */
	TIM3_IRQn               = 29,	/*!< TIM3 global Interrupt                                             */
	TIM4_IRQn               = 30,	/*!< TIM4 global Interrupt                                             */
	I2C1_EV_IRQn            = 31,	/*!< I2C1 Event Interrupt                                              */
	I2C1_ER_IRQn            = 32,	/*!< I2C1 Error Interrupt                                              */
	I2C2_EV_IRQn            = 33,	/*!< I2C2 Event Interrupt                                              */
	I2C2_ER_IRQn            = 34,	/*!< I2C2 Error Interrupt                                              */
	SPI1_IRQn               = 35,	/*!< SPI1 global Interrupt                                             */
	SPI2_IRQn               = 36,	/*!< SPI2 global Interrupt                                             */
	USART1_IRQn             = 37,	/*!< USART1 global Interrupt                                           */
	USART2_IRQn             = 38,	/*!< USART2 global Interrupt                                           */
	USART3_IRQn             = 39,	/*!< USART3 global Interrupt                                           */
	EXTI15_10_IRQn          = 40,	/*!< External Line[15:10] Interrupts                                   */
	RTC_Alarm_IRQn          = 41,	/*!< RTC Alarm (A and B) through EXTI Line Interrupt                   */
	OTG_FS_WKUP_IRQn        = 42,	/*!< USB OTG FS Wakeup through EXTI line interrupt                     */
	TIM8_BRK_TIM12_IRQn     = 43,	/*!< TIM8 Break Interrupt and TIM12 global interrupt                   */
	TIM8_UP_TIM13_IRQn      = 44,	/*!< TIM8 Update Interrupt and TIM13 global interrupt                  */
	TIM8_TRG_COM_TIM14_IRQn = 45,	/*!< TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
	TIM8_CC_IRQn            = 46,	/*!< TIM8 Capture Compare Interrupt                                    */
	DMA1_Stream7_IRQn       = 47,	/*!< DMA1 Stream7 Interrupt                                            */
	FMC_IRQn                = 48,	/*!< FMC global Interrupt                                              */
	SDMMC1_IRQn             = 49,	/*!< SDMMC1 global Interrupt                                           */
	TIM5_IRQn               = 50,	/*!< TIM5 global Interrupt                                             */
	SPI3_IRQn               = 51,	/*!< SPI3 global Interrupt                                             */
	UART4_IRQn              = 52,	/*!< UART4 global Interrupt                                            */
	UART5_IRQn              = 53,	/*!< UART5 global Interrupt                                            */
	TIM6_DAC_IRQn           = 54,	/*!< TIM6 global and DAC1&2 underrun error  interrupts                 */
	TIM7_IRQn               = 55,	/*!< TIM7 global interrupt                                             */
	DMA2_Stream0_IRQn       = 56,	/*!< DMA2 Stream 0 global Interrupt                                    */
	DMA2_Stream1_IRQn       = 57,	/*!< DMA2 Stream 1 global Interrupt                                    */
	DMA2_Stream2_IRQn       = 58,	/*!< DMA2 Stream 2 global Interrupt                                    */
	DMA2_Stream3_IRQn       = 59,	/*!< DMA2 Stream 3 global Interrupt                                    */
	DMA2_Stream4_IRQn       = 60,	/*!< DMA2 Stream 4 global Interrupt                                    */
	ETH_IRQn                = 61,	/*!< Ethernet global Interrupt                                         */
	ETH_WKUP_IRQn           = 62,	/*!< Ethernet Wakeup through EXTI line Interrupt                       */
	OTG_FS_IRQn             = 67,	/*!< USB OTG FS global Interrupt                                       */
	DMA2_Stream5_IRQn       = 68,	/*!< DMA2 Stream 5 global interrupt                                    */
	DMA2_Stream6_IRQn       = 69,	/*!< DMA2 Stream 6 global interrupt                                    */
	DMA2_Stream7_IRQn       = 70,	/*!< DMA2 Stream 7 global interrupt                                    */
	USART6_IRQn             = 71,	/*!< USART6 global interrupt                                           */
	I2C3_EV_IRQn            = 72,	/*!< I2C3 event interrupt                                              */
	I2C3_ER_IRQn            = 73,	/*!< I2C3 error interrupt                                              */
	OTG_HS_EP1_OUT_IRQn     = 74,	/*!< USB OTG HS End Point 1 Out global interrupt                       */
	OTG_HS_EP1_IN_IRQn      = 75,	/*!< USB OTG HS End Point 1 In global interrupt                        */
	OTG_HS_WKUP_IRQn        = 76,	/*!< USB OTG HS Wakeup through EXTI interrupt                          */
	OTG_HS_IRQn             = 77,	/*!< USB OTG HS global interrupt                                       */
	RNG_IRQn                = 80,	/*!< RNG global interrupt                                              */
	FPU_IRQn                = 81,	/*!< FPU global interrupt                                              */
	UART7_IRQn              = 82,	/*!< UART7 global interrupt                                            */
	UART8_IRQn              = 83,	/*!< UART8 global interrupt                                            */
	SPI4_IRQn               = 84,	/*!< SPI4 global Interrupt                                             */
	SPI5_IRQn               = 85,	/*!< SPI5 global Interrupt                                             */
	SAI1_IRQn               = 87,	/*!< SAI1 global Interrupt                                             */
	SAI2_IRQn               = 91,	/*!< SAI2 global Interrupt                                             */
	QUADSPI_IRQn            = 92,	/*!< Quad SPI global interrupt                                         */
	LPTIM1_IRQn             = 93,	/*!< LP TIM1 interrupt                                                 */
	SDMMC2_IRQn             = 103,	/*!< SDMMC2 global Interrupt                                           */
} IRQn_Type;

/**
 * @}
 */

/**
 * @brief Configuration of the Cortex-M7 Processor and Core Peripherals
 */
#define __CM7_REV                 0x0100U	/*!< Cortex-M7 revision r1p0                       */
#define __MPU_PRESENT             1			/*!< CM7 provides an MPU                           */
#define __NVIC_PRIO_BITS          4			/*!< CM7 uses 4 Bits for the Priority Levels       */
#define __Vendor_SysTickConfig    0			/*!< Set to 1 if different SysTick Config is used  */
#define __FPU_PRESENT             1			/*!< FPU present                                   */
#define __ICACHE_PRESENT          1			/*!< CM7 instruction cache present                 */
#define __DCACHE_PRESENT          1			/*!< CM7 data cache present                        */
#include "core_cm7.h"						/*!< Cortex-M7 processor and core peripherals      */


#include "system_stm32f7xx.h"
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
 * @{
 */

/**
 * @brief Analog to Digital Converter
 */

typedef struct {
	__IO uint32_t SR;	/*!< ADC status register,                         Address offset: 0x00 */
	__IO uint32_t CR1;	/*!< ADC control register 1,                      Address offset: 0x04 */
	__IO uint32_t CR2;	/*!< ADC control register 2,                      Address offset: 0x08 */
	__IO uint32_t SMPR1;/*!< ADC sample time register 1,                  Address offset: 0x0C */
	__IO uint32_t SMPR2;/*!< ADC sample time register 2,                  Address offset: 0x10 */
	__IO uint32_t JOFR1;/*!< ADC injected channel data offset register 1, Address offset: 0x14 */
	__IO uint32_t JOFR2;/*!< ADC injected channel data offset register 2, Address offset: 0x18 */
	__IO uint32_t JOFR3;/*!< ADC injected channel data offset register 3, Address offset: 0x1C */
	__IO uint32_t JOFR4;/*!< ADC injected channel data offset register 4, Address offset: 0x20 */
	__IO uint32_t HTR;	/*!< ADC watchdog higher threshold register,      Address offset: 0x24 */
	__IO uint32_t LTR;	/*!< ADC watchdog lower threshold register,       Address offset: 0x28 */
	__IO uint32_t SQR1;	/*!< ADC regular sequence register 1,             Address offset: 0x2C */
	__IO uint32_t SQR2;	/*!< ADC regular sequence register 2,             Address offset: 0x30 */
	__IO uint32_t SQR3;	/*!< ADC regular sequence register 3,             Address offset: 0x34 */
	__IO uint32_t JSQR;	/*!< ADC injected sequence register,              Address offset: 0x38*/
	__IO uint32_t JDR1;	/*!< ADC injected data register 1,                Address offset: 0x3C */
	__IO uint32_t JDR2;	/*!< ADC injected data register 2,                Address offset: 0x40 */
	__IO uint32_t JDR3;	/*!< ADC injected data register 3,                Address offset: 0x44 */
	__IO uint32_t JDR4;	/*!< ADC injected data register 4,                Address offset: 0x48 */
	__IO uint32_t DR;	/*!< ADC regular data register,                   Address offset: 0x4C */
} ADC_TypeDef;

typedef struct {
	__IO uint32_t CSR;	/*!< ADC Common status register,                  Address offset: ADC1 base address + 0x300 */
	__IO uint32_t CCR;	/*!< ADC common control register,                 Address offset: ADC1 base address + 0x304 */
	__IO uint32_t CDR;	/*!< ADC common regular data register for dual
						 *   AND triple modes,                            Address offset: ADC1 base address + 0x308 */
} ADC_Common_TypeDef;


/**
 * @brief Controller Area Network TxMailBox
 */

typedef struct {
	__IO uint32_t TIR;	/*!< CAN TX mailbox identifier register */
	__IO uint32_t TDTR;	/*!< CAN mailbox data length control and time stamp register */
	__IO uint32_t TDLR;	/*!< CAN mailbox data low register */
	__IO uint32_t TDHR;	/*!< CAN mailbox data high register */
} CAN_TxMailBox_TypeDef;

/**
 * @brief Controller Area Network FIFOMailBox
 */

typedef struct {
	__IO uint32_t RIR;	/*!< CAN receive FIFO mailbox identifier register */
	__IO uint32_t RDTR;	/*!< CAN receive FIFO mailbox data length control and time stamp register */
	__IO uint32_t RDLR;	/*!< CAN receive FIFO mailbox data low register */
	__IO uint32_t RDHR;	/*!< CAN receive FIFO mailbox data high register */
} CAN_FIFOMailBox_TypeDef;

/**
 * @brief Controller Area Network FilterRegister
 */

typedef struct {
	__IO uint32_t FR1;	/*!< CAN Filter bank register 1 */
	__IO uint32_t FR2;	/*!< CAN Filter bank register 1 */
} CAN_FilterRegister_TypeDef;

/**
 * @brief Controller Area Network
 */

typedef struct {
	__IO uint32_t              MCR;					/*!< CAN master control register,         Address offset: 0x00          */
	__IO uint32_t              MSR;					/*!< CAN master status register,          Address offset: 0x04          */
	__IO uint32_t              TSR;					/*!< CAN transmit status register,        Address offset: 0x08          */
	__IO uint32_t              RF0R;				/*!< CAN receive FIFO 0 register,         Address offset: 0x0C          */
	__IO uint32_t              RF1R;				/*!< CAN receive FIFO 1 register,         Address offset: 0x10          */
	__IO uint32_t              IER;					/*!< CAN interrupt enable register,       Address offset: 0x14          */
	__IO uint32_t              ESR;					/*!< CAN error status register,           Address offset: 0x18          */
	__IO uint32_t              BTR;					/*!< CAN bit timing register,             Address offset: 0x1C          */
	uint32_t                   RESERVED0[88];		/*!< Reserved, 0x020 - 0x17F                                            */
	CAN_TxMailBox_TypeDef      sTxMailBox[3];		/*!< CAN Tx MailBox,                      Address offset: 0x180 - 0x1AC */
	CAN_FIFOMailBox_TypeDef    sFIFOMailBox[2];		/*!< CAN FIFO MailBox,                    Address offset: 0x1B0 - 0x1CC */
	uint32_t                   RESERVED1[12];		/*!< Reserved, 0x1D0 - 0x1FF                                            */
	__IO uint32_t              FMR;					/*!< CAN filter master register,          Address offset: 0x200         */
	__IO uint32_t              FM1R;				/*!< CAN filter mode register,            Address offset: 0x204         */
	uint32_t                   RESERVED2;			/*!< Reserved, 0x208                                                    */
	__IO uint32_t              FS1R;				/*!< CAN filter scale register,           Address offset: 0x20C         */
	uint32_t                   RESERVED3;			/*!< Reserved, 0x210                                                    */
	__IO uint32_t              FFA1R;				/*!< CAN filter FIFO assignment register, Address offset: 0x214         */
	uint32_t                   RESERVED4;			/*!< Reserved, 0x218                                                    */
	__IO uint32_t              FA1R;				/*!< CAN filter activation register,      Address offset: 0x21C         */
	uint32_t                   RESERVED5[8];		/*!< Reserved, 0x220-0x23F                                              */
	CAN_FilterRegister_TypeDef sFilterRegister[28];	/*!< CAN Filter Register,                 Address offset: 0x240-0x31C   */
} CAN_TypeDef;


/**
 * @brief CRC calculation unit
 */

typedef struct {
	__IO uint32_t DR;	/*!< CRC Data register,                           Address offset: 0x00 */
	__IO uint8_t  IDR;	/*!< CRC Independent data register,               Address offset: 0x04 */
	uint8_t       RESERVED0;/*!< Reserved, 0x05                                                    */
	uint16_t      RESERVED1;/*!< Reserved, 0x06                                                    */
	__IO uint32_t CR;	/*!< CRC Control register,                        Address offset: 0x08 */
	uint32_t      RESERVED2;/*!< Reserved,                                                    0x0C */
	__IO uint32_t INIT;	/*!< Initial CRC value register,                  Address offset: 0x10 */
	__IO uint32_t POL;	/*!< CRC polynomial register,                     Address offset: 0x14 */
} CRC_TypeDef;

/**
 * @brief Digital to Analog Converter
 */

typedef struct {
	__IO uint32_t CR;		/*!< DAC control register,                                    Address offset: 0x00 */
	__IO uint32_t SWTRIGR;	/*!< DAC software trigger register,                           Address offset: 0x04 */
	__IO uint32_t DHR12R1;	/*!< DAC channel1 12-bit right-aligned data holding register, Address offset: 0x08 */
	__IO uint32_t DHR12L1;	/*!< DAC channel1 12-bit left aligned data holding register,  Address offset: 0x0C */
	__IO uint32_t DHR8R1;	/*!< DAC channel1 8-bit right aligned data holding register,  Address offset: 0x10 */
	__IO uint32_t DHR12R2;	/*!< DAC channel2 12-bit right aligned data holding register, Address offset: 0x14 */
	__IO uint32_t DHR12L2;	/*!< DAC channel2 12-bit left aligned data holding register,  Address offset: 0x18 */
	__IO uint32_t DHR8R2;	/*!< DAC channel2 8-bit right-aligned data holding register,  Address offset: 0x1C */
	__IO uint32_t DHR12RD;	/*!< Dual DAC 12-bit right-aligned data holding register,     Address offset: 0x20 */
	__IO uint32_t DHR12LD;	/*!< DUAL DAC 12-bit left aligned data holding register,      Address offset: 0x24 */
	__IO uint32_t DHR8RD;	/*!< DUAL DAC 8-bit right aligned data holding register,      Address offset: 0x28 */
	__IO uint32_t DOR1;		/*!< DAC channel1 data output register,                       Address offset: 0x2C */
	__IO uint32_t DOR2;		/*!< DAC channel2 data output register,                       Address offset: 0x30 */
	__IO uint32_t SR;		/*!< DAC status register,                                     Address offset: 0x34 */
} DAC_TypeDef;


/**
 * @brief Debug MCU
 */

typedef struct {
	__IO uint32_t IDCODE;	/*!< MCU device ID code,               Address offset: 0x00 */
	__IO uint32_t CR;		/*!< Debug MCU configuration register, Address offset: 0x04 */
	__IO uint32_t APB1FZ;	/*!< Debug MCU APB1 freeze register,   Address offset: 0x08 */
	__IO uint32_t APB2FZ;	/*!< Debug MCU APB2 freeze register,   Address offset: 0x0C */
} DBGMCU_TypeDef;


/**
 * @brief DMA Controller
 */

typedef struct {
	__IO uint32_t CR;	/*!< DMA stream x configuration register      */
	__IO uint32_t NDTR;	/*!< DMA stream x number of data register     */
	__IO uint32_t PAR;	/*!< DMA stream x peripheral address register */
	__IO uint32_t M0AR;	/*!< DMA stream x memory 0 address register   */
	__IO uint32_t M1AR;	/*!< DMA stream x memory 1 address register   */
	__IO uint32_t FCR;	/*!< DMA stream x FIFO control register       */
} DMA_Stream_TypeDef;

typedef struct {
	__IO uint32_t LISR;	/*!< DMA low interrupt status register,      Address offset: 0x00 */
	__IO uint32_t HISR;	/*!< DMA high interrupt status register,     Address offset: 0x04 */
	__IO uint32_t LIFCR;/*!< DMA low interrupt flag clear register,  Address offset: 0x08 */
	__IO uint32_t HIFCR;/*!< DMA high interrupt flag clear register, Address offset: 0x0C */
} DMA_TypeDef;


/**
 * @brief External Interrupt/Event Controller
 */

typedef struct {
	__IO uint32_t IMR;	/*!< EXTI Interrupt mask register,            Address offset: 0x00 */
	__IO uint32_t EMR;	/*!< EXTI Event mask register,                Address offset: 0x04 */
	__IO uint32_t RTSR;	/*!< EXTI Rising trigger selection register,  Address offset: 0x08 */
	__IO uint32_t FTSR;	/*!< EXTI Falling trigger selection register, Address offset: 0x0C */
	__IO uint32_t SWIER;/*!< EXTI Software interrupt event register,  Address offset: 0x10 */
	__IO uint32_t PR;	/*!< EXTI Pending register,                   Address offset: 0x14 */
} EXTI_TypeDef;

/**
 * @brief FLASH Registers
 */

typedef struct {
	__IO uint32_t ACR;		/*!< FLASH access control register,     Address offset: 0x00 */
	__IO uint32_t KEYR;		/*!< FLASH key register,                Address offset: 0x04 */
	__IO uint32_t OPTKEYR;	/*!< FLASH option key register,         Address offset: 0x08 */
	__IO uint32_t SR;		/*!< FLASH status register,             Address offset: 0x0C */
	__IO uint32_t CR;		/*!< FLASH control register,            Address offset: 0x10 */
	__IO uint32_t OPTCR;	/*!< FLASH option control register ,    Address offset: 0x14 */
	__IO uint32_t OPTCR1;	/*!< FLASH option control register 1 ,  Address offset: 0x18 */
	__IO uint32_t OPTCR2;	/*!< FLASH option control register 2 ,  Address offset: 0x1C */
} FLASH_TypeDef;


/**
 * @brief Flexible Memory Controller
 */

typedef struct {
	__IO uint32_t BTCR[8];	/*!< NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR), Address offset: 0x00-1C */
} FMC_Bank1_TypeDef;

/**
 * @brief Flexible Memory Controller Bank1E
 */

typedef struct {
	__IO uint32_t BWTR[7];	/*!< NOR/PSRAM write timing registers, Address offset: 0x104-0x11C */
} FMC_Bank1E_TypeDef;

/**
 * @brief Flexible Memory Controller Bank3
 */

typedef struct {
	__IO uint32_t PCR;	/*!< NAND Flash control register,                       Address offset: 0x80 */
	__IO uint32_t SR;	/*!< NAND Flash FIFO status and interrupt register,     Address offset: 0x84 */
	__IO uint32_t PMEM;	/*!< NAND Flash Common memory space timing register,    Address offset: 0x88 */
	__IO uint32_t PATT;	/*!< NAND Flash Attribute memory space timing register, Address offset: 0x8C */
	uint32_t      RESERVED0;/*!< Reserved, 0x90                                                          */
	__IO uint32_t ECCR;	/*!< NAND Flash ECC result registers,                   Address offset: 0x94 */
} FMC_Bank3_TypeDef;

/**
 * @brief Flexible Memory Controller Bank5_6
 */

typedef struct {
	__IO uint32_t SDCR[2];	/*!< SDRAM Control registers ,      Address offset: 0x140-0x144  */
	__IO uint32_t SDTR[2];	/*!< SDRAM Timing registers ,       Address offset: 0x148-0x14C  */
	__IO uint32_t SDCMR;	/*!< SDRAM Command Mode register,    Address offset: 0x150  */
	__IO uint32_t SDRTR;	/*!< SDRAM Refresh Timer register,   Address offset: 0x154  */
	__IO uint32_t SDSR;		/*!< SDRAM Status register,          Address offset: 0x158  */
} FMC_Bank5_6_TypeDef;


/**
 * @brief General Purpose I/O
 */

typedef struct {
	__IO uint32_t MODER;	/*!< GPIO port mode register,               Address offset: 0x00      */
	__IO uint32_t OTYPER;	/*!< GPIO port output type register,        Address offset: 0x04      */
	__IO uint32_t OSPEEDR;	/*!< GPIO port output speed register,       Address offset: 0x08      */
	__IO uint32_t PUPDR;	/*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
	__IO uint32_t IDR;		/*!< GPIO port input data register,         Address offset: 0x10      */
	__IO uint32_t ODR;		/*!< GPIO port output data register,        Address offset: 0x14      */
	__IO uint32_t BSRR;		/*!< GPIO port bit set/reset register,      Address offset: 0x18      */
	__IO uint32_t LCKR;		/*!< GPIO port configuration lock register, Address offset: 0x1C      */
	__IO uint32_t AFR[2];	/*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

/**
 * @brief System configuration controller
 */

typedef struct {
	__IO uint32_t MEMRMP;		/*!< SYSCFG memory remap register,                      Address offset: 0x00      */
	__IO uint32_t PMC;			/*!< SYSCFG peripheral mode configuration register,     Address offset: 0x04      */
	__IO uint32_t EXTICR[4];	/*!< SYSCFG external interrupt configuration registers, Address offset: 0x08-0x14 */
	uint32_t      RESERVED[2];	/*!< Reserved, 0x18-0x1C                                                          */
	__IO uint32_t CMPCR;		/*!< SYSCFG Compensation cell control register,         Address offset: 0x20      */
} SYSCFG_TypeDef;

/**
 * @brief Inter-integrated Circuit Interface
 */

typedef struct {
	__IO uint32_t CR1;		/*!< I2C Control register 1,            Address offset: 0x00 */
	__IO uint32_t CR2;		/*!< I2C Control register 2,            Address offset: 0x04 */
	__IO uint32_t OAR1;		/*!< I2C Own address 1 register,        Address offset: 0x08 */
	__IO uint32_t OAR2;		/*!< I2C Own address 2 register,        Address offset: 0x0C */
	__IO uint32_t TIMINGR;	/*!< I2C Timing register,               Address offset: 0x10 */
	__IO uint32_t TIMEOUTR;	/*!< I2C Timeout register,              Address offset: 0x14 */
	__IO uint32_t ISR;		/*!< I2C Interrupt and status register, Address offset: 0x18 */
	__IO uint32_t ICR;		/*!< I2C Interrupt clear register,      Address offset: 0x1C */
	__IO uint32_t PECR;		/*!< I2C PEC register,                  Address offset: 0x20 */
	__IO uint32_t RXDR;		/*!< I2C Receive data register,         Address offset: 0x24 */
	__IO uint32_t TXDR;		/*!< I2C Transmit data register,        Address offset: 0x28 */
} I2C_TypeDef;

/**
 * @brief Independent WATCHDOG
 */

typedef struct {
	__IO uint32_t KR;	/*!< IWDG Key register,       Address offset: 0x00 */
	__IO uint32_t PR;	/*!< IWDG Prescaler register, Address offset: 0x04 */
	__IO uint32_t RLR;	/*!< IWDG Reload register,    Address offset: 0x08 */
	__IO uint32_t SR;	/*!< IWDG Status register,    Address offset: 0x0C */
	__IO uint32_t WINR;	/*!< IWDG Window register,    Address offset: 0x10 */
} IWDG_TypeDef;


/**
 * @brief Power Control
 */

typedef struct {
	__IO uint32_t CR1;	/*!< PWR power control register 1,        Address offset: 0x00 */
	__IO uint32_t CSR1;	/*!< PWR power control/status register 2, Address offset: 0x04 */
	__IO uint32_t CR2;	/*!< PWR power control register 2,        Address offset: 0x08 */
	__IO uint32_t CSR2;	/*!< PWR power control/status register 2, Address offset: 0x0C */
} PWR_TypeDef;


/**
 * @brief Reset and Clock Control
 */

typedef struct {
	__IO uint32_t CR;			/*!< RCC clock control register,                                  Address offset: 0x00 */
	__IO uint32_t PLLCFGR;		/*!< RCC PLL configuration register,                              Address offset: 0x04 */
	__IO uint32_t CFGR;			/*!< RCC clock configuration register,                            Address offset: 0x08 */
	__IO uint32_t CIR;			/*!< RCC clock interrupt register,                                Address offset: 0x0C */
	__IO uint32_t AHB1RSTR;		/*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
	__IO uint32_t AHB2RSTR;		/*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
	__IO uint32_t AHB3RSTR;		/*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
	uint32_t      RESERVED0;	/*!< Reserved, 0x1C                                                                    */
	__IO uint32_t APB1RSTR;		/*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
	__IO uint32_t APB2RSTR;		/*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
	uint32_t      RESERVED1[2];	/*!< Reserved, 0x28-0x2C                                                               */
	__IO uint32_t AHB1ENR;		/*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
	__IO uint32_t AHB2ENR;		/*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
	__IO uint32_t AHB3ENR;		/*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
	uint32_t      RESERVED2;	/*!< Reserved, 0x3C                                                                    */
	__IO uint32_t APB1ENR;		/*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
	__IO uint32_t APB2ENR;		/*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
	uint32_t      RESERVED3[2];	/*!< Reserved, 0x48-0x4C                                                               */
	__IO uint32_t AHB1LPENR;	/*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
	__IO uint32_t AHB2LPENR;	/*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
	__IO uint32_t AHB3LPENR;	/*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
	uint32_t      RESERVED4;	/*!< Reserved, 0x5C                                                                    */
	__IO uint32_t APB1LPENR;	/*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
	__IO uint32_t APB2LPENR;	/*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
	uint32_t      RESERVED5[2];	/*!< Reserved, 0x68-0x6C                                                               */
	__IO uint32_t BDCR;			/*!< RCC Backup domain control register,                          Address offset: 0x70 */
	__IO uint32_t CSR;			/*!< RCC clock control & status register,                         Address offset: 0x74 */
	uint32_t      RESERVED6[2];	/*!< Reserved, 0x78-0x7C                                                               */
	__IO uint32_t SSCGR;		/*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
	__IO uint32_t PLLI2SCFGR;	/*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
	__IO uint32_t PLLSAICFGR;	/*!< RCC PLLSAI configuration register,                           Address offset: 0x88 */
	__IO uint32_t DCKCFGR1;		/*!< RCC Dedicated Clocks configuration register1,                 Address offset: 0x8C */
	__IO uint32_t DCKCFGR2;		/*!< RCC Dedicated Clocks configuration register 2,               Address offset: 0x90 */
} RCC_TypeDef;

/**
 * @brief Real-Time Clock
 */

typedef struct {
	__IO uint32_t TR;		/*!< RTC time register,                                         Address offset: 0x00 */
	__IO uint32_t DR;		/*!< RTC date register,                                         Address offset: 0x04 */
	__IO uint32_t CR;		/*!< RTC control register,                                      Address offset: 0x08 */
	__IO uint32_t ISR;		/*!< RTC initialization and status register,                    Address offset: 0x0C */
	__IO uint32_t PRER;		/*!< RTC prescaler register,                                    Address offset: 0x10 */
	__IO uint32_t WUTR;		/*!< RTC wakeup timer register,                                 Address offset: 0x14 */
	uint32_t      reserved;	/*!< Reserved  */
	__IO uint32_t ALRMAR;	/*!< RTC alarm A register,                                      Address offset: 0x1C */
	__IO uint32_t ALRMBR;	/*!< RTC alarm B register,                                      Address offset: 0x20 */
	__IO uint32_t WPR;		/*!< RTC write protection register,                             Address offset: 0x24 */
	__IO uint32_t SSR;		/*!< RTC sub second register,                                   Address offset: 0x28 */
	__IO uint32_t SHIFTR;	/*!< RTC shift control register,                                Address offset: 0x2C */
	__IO uint32_t TSTR;		/*!< RTC time stamp time register,                              Address offset: 0x30 */
	__IO uint32_t TSDR;		/*!< RTC time stamp date register,                              Address offset: 0x34 */
	__IO uint32_t TSSSR;	/*!< RTC time-stamp sub second register,                        Address offset: 0x38 */
	__IO uint32_t CALR;		/*!< RTC calibration register,                                  Address offset: 0x3C */
	__IO uint32_t TAMPCR;	/*!< RTC tamper configuration register,                         Address offset: 0x40 */
	__IO uint32_t ALRMASSR;	/*!< RTC alarm A sub second register,                           Address offset: 0x44 */
	__IO uint32_t ALRMBSSR;	/*!< RTC alarm B sub second register,                           Address offset: 0x48 */
	__IO uint32_t OR;		/*!< RTC option register,                                       Address offset: 0x4C */
	__IO uint32_t BKP0R;	/*!< RTC backup register 0,                                     Address offset: 0x50 */
	__IO uint32_t BKP1R;	/*!< RTC backup register 1,                                     Address offset: 0x54 */
	__IO uint32_t BKP2R;	/*!< RTC backup register 2,                                     Address offset: 0x58 */
	__IO uint32_t BKP3R;	/*!< RTC backup register 3,                                     Address offset: 0x5C */
	__IO uint32_t BKP4R;	/*!< RTC backup register 4,                                     Address offset: 0x60 */
	__IO uint32_t BKP5R;	/*!< RTC backup register 5,                                     Address offset: 0x64 */
	__IO uint32_t BKP6R;	/*!< RTC backup register 6,                                     Address offset: 0x68 */
	__IO uint32_t BKP7R;	/*!< RTC backup register 7,                                     Address offset: 0x6C */
	__IO uint32_t BKP8R;	/*!< RTC backup register 8,                                     Address offset: 0x70 */
	__IO uint32_t BKP9R;	/*!< RTC backup register 9,                                     Address offset: 0x74 */
	__IO uint32_t BKP10R;	/*!< RTC backup register 10,                                    Address offset: 0x78 */
	__IO uint32_t BKP11R;	/*!< RTC backup register 11,                                    Address offset: 0x7C */
	__IO uint32_t BKP12R;	/*!< RTC backup register 12,                                    Address offset: 0x80 */
	__IO uint32_t BKP13R;	/*!< RTC backup register 13,                                    Address offset: 0x84 */
	__IO uint32_t BKP14R;	/*!< RTC backup register 14,                                    Address offset: 0x88 */
	__IO uint32_t BKP15R;	/*!< RTC backup register 15,                                    Address offset: 0x8C */
	__IO uint32_t BKP16R;	/*!< RTC backup register 16,                                    Address offset: 0x90 */
	__IO uint32_t BKP17R;	/*!< RTC backup register 17,                                    Address offset: 0x94 */
	__IO uint32_t BKP18R;	/*!< RTC backup register 18,                                    Address offset: 0x98 */
	__IO uint32_t BKP19R;	/*!< RTC backup register 19,                                    Address offset: 0x9C */
	__IO uint32_t BKP20R;	/*!< RTC backup register 20,                                    Address offset: 0xA0 */
	__IO uint32_t BKP21R;	/*!< RTC backup register 21,                                    Address offset: 0xA4 */
	__IO uint32_t BKP22R;	/*!< RTC backup register 22,                                    Address offset: 0xA8 */
	__IO uint32_t BKP23R;	/*!< RTC backup register 23,                                    Address offset: 0xAC */
	__IO uint32_t BKP24R;	/*!< RTC backup register 24,                                    Address offset: 0xB0 */
	__IO uint32_t BKP25R;	/*!< RTC backup register 25,                                    Address offset: 0xB4 */
	__IO uint32_t BKP26R;	/*!< RTC backup register 26,                                    Address offset: 0xB8 */
	__IO uint32_t BKP27R;	/*!< RTC backup register 27,                                    Address offset: 0xBC */
	__IO uint32_t BKP28R;	/*!< RTC backup register 28,                                    Address offset: 0xC0 */
	__IO uint32_t BKP29R;	/*!< RTC backup register 29,                                    Address offset: 0xC4 */
	__IO uint32_t BKP30R;	/*!< RTC backup register 30,                                    Address offset: 0xC8 */
	__IO uint32_t BKP31R;	/*!< RTC backup register 31,                                    Address offset: 0xCC */
} RTC_TypeDef;


/**
 * @brief Serial Audio Interface
 */

typedef struct {
	__IO uint32_t GCR;	/*!< SAI global configuration register,        Address offset: 0x00 */
} SAI_TypeDef;

typedef struct {
	__IO uint32_t CR1;	/*!< SAI block x configuration register 1,     Address offset: 0x04 */
	__IO uint32_t CR2;	/*!< SAI block x configuration register 2,     Address offset: 0x08 */
	__IO uint32_t FRCR;	/*!< SAI block x frame configuration register, Address offset: 0x0C */
	__IO uint32_t SLOTR;/*!< SAI block x slot register,                Address offset: 0x10 */
	__IO uint32_t IMR;	/*!< SAI block x interrupt mask register,      Address offset: 0x14 */
	__IO uint32_t SR;	/*!< SAI block x status register,              Address offset: 0x18 */
	__IO uint32_t CLRFR;/*!< SAI block x clear flag register,          Address offset: 0x1C */
	__IO uint32_t DR;	/*!< SAI block x data register,                Address offset: 0x20 */
} SAI_Block_TypeDef;


/**
 * @brief SD host Interface
 */

typedef struct {
	__IO uint32_t POWER;		/*!< SDMMC power control register,    Address offset: 0x00 */
	__IO uint32_t CLKCR;		/*!< SDMMClock control register,     Address offset: 0x04 */
	__IO uint32_t ARG;			/*!< SDMMC argument register,         Address offset: 0x08 */
	__IO uint32_t CMD;			/*!< SDMMC command register,          Address offset: 0x0C */
	__I uint32_t  RESPCMD;		/*!< SDMMC command response register, Address offset: 0x10 */
	__I uint32_t  RESP1;		/*!< SDMMC response 1 register,       Address offset: 0x14 */
	__I uint32_t  RESP2;		/*!< SDMMC response 2 register,       Address offset: 0x18 */
	__I uint32_t  RESP3;		/*!< SDMMC response 3 register,       Address offset: 0x1C */
	__I uint32_t  RESP4;		/*!< SDMMC response 4 register,       Address offset: 0x20 */
	__IO uint32_t DTIMER;		/*!< SDMMC data timer register,       Address offset: 0x24 */
	__IO uint32_t DLEN;			/*!< SDMMC data length register,      Address offset: 0x28 */
	__IO uint32_t DCTRL;		/*!< SDMMC data control register,     Address offset: 0x2C */
	__I uint32_t  DCOUNT;		/*!< SDMMC data counter register,     Address offset: 0x30 */
	__I uint32_t  STA;			/*!< SDMMC status register,           Address offset: 0x34 */
	__IO uint32_t ICR;			/*!< SDMMC interrupt clear register,  Address offset: 0x38 */
	__IO uint32_t MASK;			/*!< SDMMC mask register,             Address offset: 0x3C */
	uint32_t      RESERVED0[2];	/*!< Reserved, 0x40-0x44                                  */
	__I uint32_t  FIFOCNT;		/*!< SDMMC FIFO counter register,     Address offset: 0x48 */
	uint32_t      RESERVED1[13];/*!< Reserved, 0x4C-0x7C                                  */
	__IO uint32_t FIFO;	/*!< SDMMC data FIFO register,        Address offset: 0x80 */
} SDMMC_TypeDef;

/**
 * @brief Serial Peripheral Interface
 */

typedef struct {
	__IO uint32_t CR1;		/*!< SPI control register 1 (not used in I2S mode),      Address offset: 0x00 */
	__IO uint32_t CR2;		/*!< SPI control register 2,                             Address offset: 0x04 */
	__IO uint32_t SR;		/*!< SPI status register,                                Address offset: 0x08 */
	__IO uint32_t DR;		/*!< SPI data register,                                  Address offset: 0x0C */
	__IO uint32_t CRCPR;	/*!< SPI CRC polynomial register (not used in I2S mode), Address offset: 0x10 */
	__IO uint32_t RXCRCR;	/*!< SPI RX CRC register (not used in I2S mode),         Address offset: 0x14 */
	__IO uint32_t TXCRCR;	/*!< SPI TX CRC register (not used in I2S mode),         Address offset: 0x18 */
	__IO uint32_t I2SCFGR;	/*!< SPI_I2S configuration register,                     Address offset: 0x1C */
	__IO uint32_t I2SPR;	/*!< SPI_I2S prescaler register,                         Address offset: 0x20 */
} SPI_TypeDef;

/**
 * @brief QUAD Serial Peripheral Interface
 */

typedef struct {
	__IO uint32_t CR;	/*!< QUADSPI Control register,                           Address offset: 0x00 */
	__IO uint32_t DCR;	/*!< QUADSPI Device Configuration register,              Address offset: 0x04 */
	__IO uint32_t SR;	/*!< QUADSPI Status register,                            Address offset: 0x08 */
	__IO uint32_t FCR;	/*!< QUADSPI Flag Clear register,                        Address offset: 0x0C */
	__IO uint32_t DLR;	/*!< QUADSPI Data Length register,                       Address offset: 0x10 */
	__IO uint32_t CCR;	/*!< QUADSPI Communication Configuration register,       Address offset: 0x14 */
	__IO uint32_t AR;	/*!< QUADSPI Address register,                           Address offset: 0x18 */
	__IO uint32_t ABR;	/*!< QUADSPI Alternate Bytes register,                   Address offset: 0x1C */
	__IO uint32_t DR;	/*!< QUADSPI Data register,                              Address offset: 0x20 */
	__IO uint32_t PSMKR;/*!< QUADSPI Polling Status Mask register,               Address offset: 0x24 */
	__IO uint32_t PSMAR;/*!< QUADSPI Polling Status Match register,              Address offset: 0x28 */
	__IO uint32_t PIR;	/*!< QUADSPI Polling Interval register,                  Address offset: 0x2C */
	__IO uint32_t LPTR;	/*!< QUADSPI Low Power Timeout register,                 Address offset: 0x30 */
} QUADSPI_TypeDef;

/**
 * @brief TIM
 */

typedef struct {
	__IO uint32_t CR1;	/*!< TIM control register 1,              Address offset: 0x00 */
	__IO uint32_t CR2;	/*!< TIM control register 2,              Address offset: 0x04 */
	__IO uint32_t SMCR;	/*!< TIM slave mode control register,     Address offset: 0x08 */
	__IO uint32_t DIER;	/*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
	__IO uint32_t SR;	/*!< TIM status register,                 Address offset: 0x10 */
	__IO uint32_t EGR;	/*!< TIM event generation register,       Address offset: 0x14 */
	__IO uint32_t CCMR1;/*!< TIM capture/compare mode register 1, Address offset: 0x18 */
	__IO uint32_t CCMR2;/*!< TIM capture/compare mode register 2, Address offset: 0x1C */
	__IO uint32_t CCER;	/*!< TIM capture/compare enable register, Address offset: 0x20 */
	__IO uint32_t CNT;	/*!< TIM counter register,                Address offset: 0x24 */
	__IO uint32_t PSC;	/*!< TIM prescaler,                       Address offset: 0x28 */
	__IO uint32_t ARR;	/*!< TIM auto-reload register,            Address offset: 0x2C */
	__IO uint32_t RCR;	/*!< TIM repetition counter register,     Address offset: 0x30 */
	__IO uint32_t CCR1;	/*!< TIM capture/compare register 1,      Address offset: 0x34 */
	__IO uint32_t CCR2;	/*!< TIM capture/compare register 2,      Address offset: 0x38 */
	__IO uint32_t CCR3;	/*!< TIM capture/compare register 3,      Address offset: 0x3C */
	__IO uint32_t CCR4;	/*!< TIM capture/compare register 4,      Address offset: 0x40 */
	__IO uint32_t BDTR;	/*!< TIM break and dead-time register,    Address offset: 0x44 */
	__IO uint32_t DCR;	/*!< TIM DMA control register,            Address offset: 0x48 */
	__IO uint32_t DMAR;	/*!< TIM DMA address for full transfer,   Address offset: 0x4C */
	__IO uint32_t OR;	/*!< TIM option register,                 Address offset: 0x50 */
	__IO uint32_t CCMR3;/*!< TIM capture/compare mode register 3,      Address offset: 0x54 */
	__IO uint32_t CCR5;	/*!< TIM capture/compare mode register5,       Address offset: 0x58 */
	__IO uint32_t CCR6;	/*!< TIM capture/compare mode register6,       Address offset: 0x5C */
} TIM_TypeDef;

/**
 * @brief LPTIMIMER
 */
typedef struct {
	__IO uint32_t ISR;	/*!< LPTIM Interrupt and Status register,                Address offset: 0x00 */
	__IO uint32_t ICR;	/*!< LPTIM Interrupt Clear register,                     Address offset: 0x04 */
	__IO uint32_t IER;	/*!< LPTIM Interrupt Enable register,                    Address offset: 0x08 */
	__IO uint32_t CFGR;	/*!< LPTIM Configuration register,                       Address offset: 0x0C */
	__IO uint32_t CR;	/*!< LPTIM Control register,                             Address offset: 0x10 */
	__IO uint32_t CMP;	/*!< LPTIM Compare register,                             Address offset: 0x14 */
	__IO uint32_t ARR;	/*!< LPTIM Autoreload register,                          Address offset: 0x18 */
	__IO uint32_t CNT;	/*!< LPTIM Counter register,                             Address offset: 0x1C */
} LPTIM_TypeDef;


/**
 * @brief Universal Synchronous Asynchronous Receiver Transmitter
 */

typedef struct {
	__IO uint32_t CR1;	/*!< USART Control register 1,                 Address offset: 0x00 */
	__IO uint32_t CR2;	/*!< USART Control register 2,                 Address offset: 0x04 */
	__IO uint32_t CR3;	/*!< USART Control register 3,                 Address offset: 0x08 */
	__IO uint32_t BRR;	/*!< USART Baud rate register,                 Address offset: 0x0C */
	__IO uint32_t GTPR;	/*!< USART Guard time and prescaler register,  Address offset: 0x10 */
	__IO uint32_t RTOR;	/*!< USART Receiver Time Out register,         Address offset: 0x14 */
	__IO uint32_t RQR;	/*!< USART Request register,                   Address offset: 0x18 */
	__IO uint32_t ISR;	/*!< USART Interrupt and status register,      Address offset: 0x1C */
	__IO uint32_t ICR;	/*!< USART Interrupt flag Clear register,      Address offset: 0x20 */
	__IO uint32_t RDR;	/*!< USART Receive Data register,              Address offset: 0x24 */
	__IO uint32_t TDR;	/*!< USART Transmit Data register,             Address offset: 0x28 */
} USART_TypeDef;


/**
 * @brief Window WATCHDOG
 */

typedef struct {
	__IO uint32_t CR;	/*!< WWDG Control register,       Address offset: 0x00 */
	__IO uint32_t CFR;	/*!< WWDG Configuration register, Address offset: 0x04 */
	__IO uint32_t SR;	/*!< WWDG Status register,        Address offset: 0x08 */
} WWDG_TypeDef;


/**
 * @brief RNG
 */

typedef struct {
	__IO uint32_t CR;	/*!< RNG control register, Address offset: 0x00 */
	__IO uint32_t SR;	/*!< RNG status register,  Address offset: 0x04 */
	__IO uint32_t DR;	/*!< RNG data register,    Address offset: 0x08 */
} RNG_TypeDef;

/**
 * @}
 */

/**
 * @brief USB_OTG_Core_Registers
 */
typedef struct {
	__IO uint32_t GOTGCTL;				/*!< USB_OTG Control and Status Register          000h */
	__IO uint32_t GOTGINT;				/*!< USB_OTG Interrupt Register                   004h */
	__IO uint32_t GAHBCFG;				/*!< Core AHB Configuration Register              008h */
	__IO uint32_t GUSBCFG;				/*!< Core USB Configuration Register              00Ch */
	__IO uint32_t GRSTCTL;				/*!< Core Reset Register                          010h */
	__IO uint32_t GINTSTS;				/*!< Core Interrupt Register                      014h */
	__IO uint32_t GINTMSK;				/*!< Core Interrupt Mask Register                 018h */
	__IO uint32_t GRXSTSR;				/*!< Receive Sts Q Read Register                  01Ch */
	__IO uint32_t GRXSTSP;				/*!< Receive Sts Q Read & POP Register            020h */
	__IO uint32_t GRXFSIZ;				/*!< Receive FIFO Size Register                   024h */
	__IO uint32_t DIEPTXF0_HNPTXFSIZ;	/*!< EP0 / Non Periodic Tx FIFO Size Register     028h */
	__IO uint32_t HNPTXSTS;				/*!< Non Periodic Tx FIFO/Queue Sts reg           02Ch */
	uint32_t      Reserved30[2];		/*!< Reserved                                     030h */
	__IO uint32_t GCCFG;				/*!< General Purpose IO Register                  038h */
	__IO uint32_t CID;					/*!< User ID Register                             03Ch */
	uint32_t      Reserved5[3];			/*!< Reserved                                040h-048h */
	__IO uint32_t GHWCFG3;				/*!< User HW config3                              04Ch */
	uint32_t      Reserved6;			/*!< Reserved                                     050h */
	__IO uint32_t GLPMCFG;				/*!< LPM Register                                 054h */
	uint32_t      Reserved7;			/*!< Reserved                                     058h */
	__IO uint32_t GDFIFOCFG;			/*!< DFIFO Software Config Register               05Ch */
	uint32_t      Reserved43[40];		/*!< Reserved                                 60h-0FFh */
	__IO uint32_t HPTXFSIZ;				/*!< Host Periodic Tx FIFO Size Reg               100h */
	__IO uint32_t DIEPTXF[0x0F];		/*!< dev Periodic Transmit FIFO              104h-13Ch */
} USB_OTG_GlobalTypeDef;


/**
 * @brief USB_OTG_device_Registers
 */
typedef struct {
	__IO uint32_t DCFG;				/*!< dev Configuration Register   800h */
	__IO uint32_t DCTL;				/*!< dev Control Register         804h */
	__IO uint32_t DSTS;				/*!< dev Status Register (RO)     808h */
	uint32_t      Reserved0C;		/*!< Reserved                     80Ch */
	__IO uint32_t DIEPMSK;			/*!< dev IN Endpoint Mask         810h */
	__IO uint32_t DOEPMSK;			/*!< dev OUT Endpoint Mask        814h */
	__IO uint32_t DAINT;			/*!< dev All Endpoints Itr Reg    818h */
	__IO uint32_t DAINTMSK;			/*!< dev All Endpoints Itr Mask   81Ch */
	uint32_t      Reserved20;		/*!< Reserved                     820h */
	uint32_t      Reserved9;		/*!< Reserved                     824h */
	__IO uint32_t DVBUSDIS;			/*!< dev VBUS discharge Register  828h */
	__IO uint32_t DVBUSPULSE;		/*!< dev VBUS Pulse Register      82Ch */
	__IO uint32_t DTHRCTL;			/*!< dev threshold                830h */
	__IO uint32_t DIEPEMPMSK;		/*!< dev empty msk                834h */
	__IO uint32_t DEACHINT;			/*!< dedicated EP interrupt       838h */
	__IO uint32_t DEACHMSK;			/*!< dedicated EP msk             83Ch */
	uint32_t      Reserved40;		/*!< dedicated EP mask            840h */
	__IO uint32_t DINEP1MSK;		/*!< dedicated EP mask            844h */
	uint32_t      Reserved44[15];	/*!< Reserved                 844-87Ch */
	__IO uint32_t DOUTEP1MSK;		/*!< dedicated EP msk             884h */
} USB_OTG_DeviceTypeDef;


/**
 * @brief USB_OTG_IN_Endpoint-Specific_Register
 */
typedef struct {
	__IO uint32_t DIEPCTL;		/*!< dev IN Endpoint Control Reg    900h + (ep_num * 20h) + 00h */
	uint32_t      Reserved04;	/*!< Reserved                       900h + (ep_num * 20h) + 04h */
	__IO uint32_t DIEPINT;		/*!< dev IN Endpoint Itr Reg        900h + (ep_num * 20h) + 08h */
	uint32_t      Reserved0C;	/*!< Reserved                       900h + (ep_num * 20h) + 0Ch */
	__IO uint32_t DIEPTSIZ;		/*!< IN Endpoint Txfer Size         900h + (ep_num * 20h) + 10h */
	__IO uint32_t DIEPDMA;		/*!< IN Endpoint DMA Address Reg    900h + (ep_num * 20h) + 14h */
	__IO uint32_t DTXFSTS;		/*!< IN Endpoint Tx FIFO Status Reg 900h + (ep_num * 20h) + 18h */
	uint32_t      Reserved18;	/*!< Reserved  900h+(ep_num*20h)+1Ch-900h+ (ep_num * 20h) + 1Ch */
} USB_OTG_INEndpointTypeDef;


/**
 * @brief USB_OTG_OUT_Endpoint-Specific_Registers
 */
typedef struct {
	__IO uint32_t DOEPCTL;		/*!< dev OUT Endpoint Control Reg           B00h + (ep_num * 20h) + 00h */
	uint32_t      Reserved04;	/*!< Reserved                               B00h + (ep_num * 20h) + 04h */
	__IO uint32_t DOEPINT;		/*!< dev OUT Endpoint Itr Reg               B00h + (ep_num * 20h) + 08h */
	uint32_t      Reserved0C;	/*!< Reserved                               B00h + (ep_num * 20h) + 0Ch */
	__IO uint32_t DOEPTSIZ;		/*!< dev OUT Endpoint Txfer Size            B00h + (ep_num * 20h) + 10h */
	__IO uint32_t DOEPDMA;		/*!< dev OUT Endpoint DMA Address           B00h + (ep_num * 20h) + 14h */
	uint32_t      Reserved18[2];/*!< Reserved B00h + (ep_num * 20h) + 18h - B00h + (ep_num * 20h) + 1Ch */
} USB_OTG_OUTEndpointTypeDef;


/**
 * @brief USB_OTG_Host_Mode_Register_Structures
 */
typedef struct {
	__IO uint32_t HCFG;			/*!< Host Configuration Register          400h */
	__IO uint32_t HFIR;			/*!< Host Frame Interval Register         404h */
	__IO uint32_t HFNUM;		/*!< Host Frame Nbr/Frame Remaining       408h */
	uint32_t      Reserved40C;	/*!< Reserved                             40Ch */
	__IO uint32_t HPTXSTS;		/*!< Host Periodic Tx FIFO/ Queue Status  410h */
	__IO uint32_t HAINT;		/*!< Host All Channels Interrupt Register 414h */
	__IO uint32_t HAINTMSK;		/*!< Host All Channels Interrupt Mask     418h */
} USB_OTG_HostTypeDef;

/**
 * @brief USB_OTG_Host_Channel_Specific_Registers
 */
typedef struct {
	__IO uint32_t HCCHAR;		/*!< Host Channel Characteristics Register    500h */
	__IO uint32_t HCSPLT;		/*!< Host Channel Split Control Register      504h */
	__IO uint32_t HCINT;		/*!< Host Channel Interrupt Register          508h */
	__IO uint32_t HCINTMSK;		/*!< Host Channel Interrupt Mask Register     50Ch */
	__IO uint32_t HCTSIZ;		/*!< Host Channel Transfer Size Register      510h */
	__IO uint32_t HCDMA;		/*!< Host Channel DMA Address Register        514h */
	uint32_t      Reserved[2];	/*!< Reserved                                      */
} USB_OTG_HostChannelTypeDef;

/**
 * @}
 */


/** @addtogroup Peripheral_memory_map
 * @{
 */
#define RAMITCM_BASE      0x00000000UL	/*!< Base address of : 16KB RAM reserved for CPU execution/instruction accessible over ITCM  */
#define FLASHITCM_BASE    0x00200000UL	/*!< Base address of : (up to 512 KB) embedded FLASH memory  accessible over ITCM            */
#define FLASHAXI_BASE     0x08000000UL	/*!< Base address of : (up to 512 KB) embedded FLASH memory accessible over AXI              */
#define RAMDTCM_BASE      0x20000000UL	/*!< Base address of : 64KB system data RAM accessible over DTCM                             */
#define PERIPH_BASE       0x40000000UL	/*!< Base address of : AHB/ABP Peripherals                                                   */
#define BKPSRAM_BASE      0x40024000UL	/*!< Base address of : Backup SRAM(4 KB)                                                     */
#define QSPI_BASE         0x90000000UL	/*!< Base address of : QSPI memories  accessible over AXI                                    */
#define FMC_R_BASE        0xA0000000UL	/*!< Base address of : FMC Control registers                                                 */
#define QSPI_R_BASE       0xA0001000UL	/*!< Base address of : QSPI Control  registers                                               */
#define SRAM1_BASE        0x20010000UL	/*!< Base address of : 176KB RAM1 accessible over AXI/AHB                                    */
#define SRAM2_BASE        0x2003C000UL	/*!< Base address of : 16KB RAM2 accessible over AXI/AHB                                     */
#define FLASH_END         0x0807FFFFUL	/*!< FLASH end address */
#define FLASH_OTP_BASE    0x1FF07800UL	/*!< Base address of : (up to 528 Bytes) embedded FLASH OTP Area                             */
#define FLASH_OTP_END     0x1FF07A0FUL	/*!< End address of : (up to 528 Bytes) embedded FLASH OTP Area                              */

/* Legacy define */
#define FLASH_BASE    FLASHAXI_BASE

/*!< Peripheral memory map */
#define APB1PERIPH_BASE    PERIPH_BASE
#define APB2PERIPH_BASE    (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE    (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE    (PERIPH_BASE + 0x10000000UL)

/*!< APB1 peripherals */
#define TIM2_BASE      (APB1PERIPH_BASE + 0x0000UL)
#define TIM3_BASE      (APB1PERIPH_BASE + 0x0400UL)
#define TIM4_BASE      (APB1PERIPH_BASE + 0x0800UL)
#define TIM5_BASE      (APB1PERIPH_BASE + 0x0C00UL)
#define TIM6_BASE      (APB1PERIPH_BASE + 0x1000UL)
#define TIM7_BASE      (APB1PERIPH_BASE + 0x1400UL)
#define TIM12_BASE     (APB1PERIPH_BASE + 0x1800UL)
#define TIM13_BASE     (APB1PERIPH_BASE + 0x1C00UL)
#define TIM14_BASE     (APB1PERIPH_BASE + 0x2000UL)
#define LPTIM1_BASE    (APB1PERIPH_BASE + 0x2400UL)
#define RTC_BASE       (APB1PERIPH_BASE + 0x2800UL)
#define WWDG_BASE      (APB1PERIPH_BASE + 0x2C00UL)
#define IWDG_BASE      (APB1PERIPH_BASE + 0x3000UL)
#define SPI2_BASE      (APB1PERIPH_BASE + 0x3800UL)
#define SPI3_BASE      (APB1PERIPH_BASE + 0x3C00UL)
#define USART2_BASE    (APB1PERIPH_BASE + 0x4400UL)
#define USART3_BASE    (APB1PERIPH_BASE + 0x4800UL)
#define UART4_BASE     (APB1PERIPH_BASE + 0x4C00UL)
#define UART5_BASE     (APB1PERIPH_BASE + 0x5000UL)
#define I2C1_BASE      (APB1PERIPH_BASE + 0x5400UL)
#define I2C2_BASE      (APB1PERIPH_BASE + 0x5800UL)
#define I2C3_BASE      (APB1PERIPH_BASE + 0x5C00UL)
#define CAN1_BASE      (APB1PERIPH_BASE + 0x6400UL)
#define PWR_BASE       (APB1PERIPH_BASE + 0x7000UL)
#define DAC_BASE       (APB1PERIPH_BASE + 0x7400UL)
#define UART7_BASE     (APB1PERIPH_BASE + 0x7800UL)
#define UART8_BASE     (APB1PERIPH_BASE + 0x7C00UL)

/*!< APB2 peripherals */
#define TIM1_BASE             (APB2PERIPH_BASE + 0x0000UL)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x0400UL)
#define USART1_BASE           (APB2PERIPH_BASE + 0x1000UL)
#define USART6_BASE           (APB2PERIPH_BASE + 0x1400UL)
#define SDMMC2_BASE           (APB2PERIPH_BASE + 0x1C00UL)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x2000UL)
#define ADC2_BASE             (APB2PERIPH_BASE + 0x2100UL)
#define ADC3_BASE             (APB2PERIPH_BASE + 0x2200UL)
#define ADC_BASE              (APB2PERIPH_BASE + 0x2300UL)
#define SDMMC1_BASE           (APB2PERIPH_BASE + 0x2C00UL)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000UL)
#define SPI4_BASE             (APB2PERIPH_BASE + 0x3400UL)
#define SYSCFG_BASE           (APB2PERIPH_BASE + 0x3800UL)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x3C00UL)
#define TIM9_BASE             (APB2PERIPH_BASE + 0x4000UL)
#define TIM10_BASE            (APB2PERIPH_BASE + 0x4400UL)
#define TIM11_BASE            (APB2PERIPH_BASE + 0x4800UL)
#define SPI5_BASE             (APB2PERIPH_BASE + 0x5000UL)
#define SAI1_BASE             (APB2PERIPH_BASE + 0x5800UL)
#define SAI2_BASE             (APB2PERIPH_BASE + 0x5C00UL)
#define SAI1_Block_A_BASE     (SAI1_BASE + 0x004UL)
#define SAI1_Block_B_BASE     (SAI1_BASE + 0x024UL)
#define SAI2_Block_A_BASE     (SAI2_BASE + 0x004UL)
#define SAI2_Block_B_BASE     (SAI2_BASE + 0x024UL)
/*!< AHB1 peripherals */
#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400UL)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800UL)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00UL)
#define GPIOI_BASE            (AHB1PERIPH_BASE + 0x2000UL)
#define CRC_BASE              (AHB1PERIPH_BASE + 0x3000UL)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800UL)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x3C00UL)
#define UID_BASE              0x1FF07A10UL	/*!< Unique device ID register base address */
#define FLASHSIZE_BASE        0x1FF07A22UL	/*!< FLASH Size register base address */
#define PACKAGE_BASE          0x1FF07BF0UL	/*!< Package size register base address */
/* Legacy define */
#define PACKAGESIZE_BASE      PACKAGE_BASE

#define DMA1_BASE             (AHB1PERIPH_BASE + 0x6000UL)
#define DMA1_Stream0_BASE     (DMA1_BASE + 0x010UL)
#define DMA1_Stream1_BASE     (DMA1_BASE + 0x028UL)
#define DMA1_Stream2_BASE     (DMA1_BASE + 0x040UL)
#define DMA1_Stream3_BASE     (DMA1_BASE + 0x058UL)
#define DMA1_Stream4_BASE     (DMA1_BASE + 0x070UL)
#define DMA1_Stream5_BASE     (DMA1_BASE + 0x088UL)
#define DMA1_Stream6_BASE     (DMA1_BASE + 0x0A0UL)
#define DMA1_Stream7_BASE     (DMA1_BASE + 0x0B8UL)
#define DMA2_BASE             (AHB1PERIPH_BASE + 0x6400UL)
#define DMA2_Stream0_BASE     (DMA2_BASE + 0x010UL)
#define DMA2_Stream1_BASE     (DMA2_BASE + 0x028UL)
#define DMA2_Stream2_BASE     (DMA2_BASE + 0x040UL)
#define DMA2_Stream3_BASE     (DMA2_BASE + 0x058UL)
#define DMA2_Stream4_BASE     (DMA2_BASE + 0x070UL)
#define DMA2_Stream5_BASE     (DMA2_BASE + 0x088UL)
#define DMA2_Stream6_BASE     (DMA2_BASE + 0x0A0UL)
#define DMA2_Stream7_BASE     (DMA2_BASE + 0x0B8UL)
/*!< AHB2 peripherals */
#define RNG_BASE              (AHB2PERIPH_BASE + 0x60800UL)
/*!< FMC Bankx registers base address */
#define FMC_Bank1_R_BASE      (FMC_R_BASE + 0x0000UL)
#define FMC_Bank1E_R_BASE     (FMC_R_BASE + 0x0104UL)
#define FMC_Bank3_R_BASE      (FMC_R_BASE + 0x0080UL)
#define FMC_Bank5_6_R_BASE    (FMC_R_BASE + 0x0140UL)

/* Debug MCU registers base address */
#define DBGMCU_BASE    0xE0042000UL

/*!< USB registers base address */
#define USB_OTG_HS_PERIPH_BASE       0x40040000UL
#define USB_OTG_FS_PERIPH_BASE       0x50000000UL

#define USB_OTG_GLOBAL_BASE          0x0000UL
#define USB_OTG_DEVICE_BASE          0x0800UL
#define USB_OTG_IN_ENDPOINT_BASE     0x0900UL
#define USB_OTG_OUT_ENDPOINT_BASE    0x0B00UL
#define USB_OTG_EP_REG_SIZE          0x0020UL
#define USB_OTG_HOST_BASE            0x0400UL
#define USB_OTG_HOST_PORT_BASE       0x0440UL
#define USB_OTG_HOST_CHANNEL_BASE    0x0500UL
#define USB_OTG_HOST_CHANNEL_SIZE    0x0020UL
#define USB_OTG_PCGCCTL_BASE         0x0E00UL
#define USB_OTG_FIFO_BASE            0x1000UL
#define USB_OTG_FIFO_SIZE            0x1000UL

/**
 * @}
 */

/** @addtogroup Peripheral_declaration
 * @{
 */
#define TIM2             ((TIM_TypeDef *) TIM2_BASE)
#define TIM3             ((TIM_TypeDef *) TIM3_BASE)
#define TIM4             ((TIM_TypeDef *) TIM4_BASE)
#define TIM5             ((TIM_TypeDef *) TIM5_BASE)
#define TIM6             ((TIM_TypeDef *) TIM6_BASE)
#define TIM7             ((TIM_TypeDef *) TIM7_BASE)
#define TIM12            ((TIM_TypeDef *) TIM12_BASE)
#define TIM13            ((TIM_TypeDef *) TIM13_BASE)
#define TIM14            ((TIM_TypeDef *) TIM14_BASE)
#define LPTIM1           ((LPTIM_TypeDef *) LPTIM1_BASE)
#define RTC              ((RTC_TypeDef *) RTC_BASE)
#define WWDG             ((WWDG_TypeDef *) WWDG_BASE)
#define IWDG             ((IWDG_TypeDef *) IWDG_BASE)
#define SPI2             ((SPI_TypeDef *) SPI2_BASE)
#define SPI3             ((SPI_TypeDef *) SPI3_BASE)
#define USART2           ((USART_TypeDef *) USART2_BASE)
#define USART3           ((USART_TypeDef *) USART3_BASE)
#define UART4            ((USART_TypeDef *) UART4_BASE)
#define UART5            ((USART_TypeDef *) UART5_BASE)
#define I2C1             ((I2C_TypeDef *) I2C1_BASE)
#define I2C2             ((I2C_TypeDef *) I2C2_BASE)
#define I2C3             ((I2C_TypeDef *) I2C3_BASE)
#define CAN1             ((CAN_TypeDef *) CAN1_BASE)
#define PWR              ((PWR_TypeDef *) PWR_BASE)
#define DAC1             ((DAC_TypeDef *) DAC_BASE)
#define DAC              ((DAC_TypeDef *) DAC_BASE)	/* Kept for legacy purpose */
#define UART7            ((USART_TypeDef *) UART7_BASE)
#define UART8            ((USART_TypeDef *) UART8_BASE)
#define TIM1             ((TIM_TypeDef *) TIM1_BASE)
#define TIM8             ((TIM_TypeDef *) TIM8_BASE)
#define USART1           ((USART_TypeDef *) USART1_BASE)
#define USART6           ((USART_TypeDef *) USART6_BASE)
#define ADC              ((ADC_Common_TypeDef *) ADC_BASE)
#define ADC1             ((ADC_TypeDef *) ADC1_BASE)
#define ADC2             ((ADC_TypeDef *) ADC2_BASE)
#define ADC3             ((ADC_TypeDef *) ADC3_BASE)
#define ADC123_COMMON    ((ADC_Common_TypeDef *) ADC_BASE)
#define SDMMC1           ((SDMMC_TypeDef *) SDMMC1_BASE)
#define SPI1             ((SPI_TypeDef *) SPI1_BASE)
#define SPI4             ((SPI_TypeDef *) SPI4_BASE)
#define SYSCFG           ((SYSCFG_TypeDef *) SYSCFG_BASE)
#define EXTI             ((EXTI_TypeDef *) EXTI_BASE)
#define TIM9             ((TIM_TypeDef *) TIM9_BASE)
#define TIM10            ((TIM_TypeDef *) TIM10_BASE)
#define TIM11            ((TIM_TypeDef *) TIM11_BASE)
#define SPI5             ((SPI_TypeDef *) SPI5_BASE)
#define SAI1             ((SAI_TypeDef *) SAI1_BASE)
#define SAI2             ((SAI_TypeDef *) SAI2_BASE)
#define SAI1_Block_A     ((SAI_Block_TypeDef *) SAI1_Block_A_BASE)
#define SAI1_Block_B     ((SAI_Block_TypeDef *) SAI1_Block_B_BASE)
#define SAI2_Block_A     ((SAI_Block_TypeDef *) SAI2_Block_A_BASE)
#define SAI2_Block_B     ((SAI_Block_TypeDef *) SAI2_Block_B_BASE)
#define GPIOA            ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB            ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC            ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD            ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE            ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF            ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG            ((GPIO_TypeDef *) GPIOG_BASE)
#define GPIOH            ((GPIO_TypeDef *) GPIOH_BASE)
#define GPIOI            ((GPIO_TypeDef *) GPIOI_BASE)
#define CRC              ((CRC_TypeDef *) CRC_BASE)
#define RCC              ((RCC_TypeDef *) RCC_BASE)
#define FLASH            ((FLASH_TypeDef *) FLASH_R_BASE)
#define DMA1             ((DMA_TypeDef *) DMA1_BASE)
#define DMA1_Stream0     ((DMA_Stream_TypeDef *) DMA1_Stream0_BASE)
#define DMA1_Stream1     ((DMA_Stream_TypeDef *) DMA1_Stream1_BASE)
#define DMA1_Stream2     ((DMA_Stream_TypeDef *) DMA1_Stream2_BASE)
#define DMA1_Stream3     ((DMA_Stream_TypeDef *) DMA1_Stream3_BASE)
#define DMA1_Stream4     ((DMA_Stream_TypeDef *) DMA1_Stream4_BASE)
#define DMA1_Stream5     ((DMA_Stream_TypeDef *) DMA1_Stream5_BASE)
#define DMA1_Stream6     ((DMA_Stream_TypeDef *) DMA1_Stream6_BASE)
#define DMA1_Stream7     ((DMA_Stream_TypeDef *) DMA1_Stream7_BASE)
#define DMA2             ((DMA_TypeDef *) DMA2_BASE)
#define DMA2_Stream0     ((DMA_Stream_TypeDef *) DMA2_Stream0_BASE)
#define DMA2_Stream1     ((DMA_Stream_TypeDef *) DMA2_Stream1_BASE)
#define DMA2_Stream2     ((DMA_Stream_TypeDef *) DMA2_Stream2_BASE)
#define DMA2_Stream3     ((DMA_Stream_TypeDef *) DMA2_Stream3_BASE)
#define DMA2_Stream4     ((DMA_Stream_TypeDef *) DMA2_Stream4_BASE)
#define DMA2_Stream5     ((DMA_Stream_TypeDef *) DMA2_Stream5_BASE)
#define DMA2_Stream6     ((DMA_Stream_TypeDef *) DMA2_Stream6_BASE)
#define DMA2_Stream7     ((DMA_Stream_TypeDef *) DMA2_Stream7_BASE)
#define RNG              ((RNG_TypeDef *) RNG_BASE)
#define FMC_Bank1        ((FMC_Bank1_TypeDef *) FMC_Bank1_R_BASE)
#define FMC_Bank1E       ((FMC_Bank1E_TypeDef *) FMC_Bank1E_R_BASE)
#define FMC_Bank3        ((FMC_Bank3_TypeDef *) FMC_Bank3_R_BASE)
#define FMC_Bank5_6      ((FMC_Bank5_6_TypeDef *) FMC_Bank5_6_R_BASE)
#define QUADSPI          ((QUADSPI_TypeDef *) QSPI_R_BASE)
#define DBGMCU           ((DBGMCU_TypeDef *) DBGMCU_BASE)
#define USB_OTG_FS       ((USB_OTG_GlobalTypeDef *) USB_OTG_FS_PERIPH_BASE)
#define USB_OTG_HS       ((USB_OTG_GlobalTypeDef *) USB_OTG_HS_PERIPH_BASE)
#define SDMMC2           ((SDMMC_TypeDef *) SDMMC2_BASE)

/**
 * @}
 */

/** @addtogroup Exported_constants
 * @{
 */

/** @addtogroup Peripheral_Registers_Bits_Definition
 * @{
 */

/******************************************************************************/
/*                         Peripheral Registers_Bits_Definition               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                        Analog to Digital Converter                         */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for ADC_SR register  ********************/
#define ADC_SR_AWD_Pos      (0U)
#define ADC_SR_AWD_Msk      (0x1UL << ADC_SR_AWD_Pos)	/*!< 0x00000001 */
#define ADC_SR_AWD          ADC_SR_AWD_Msk				/*!<Analog watchdog flag                                 */
#define ADC_SR_EOC_Pos      (1U)
#define ADC_SR_EOC_Msk      (0x1UL << ADC_SR_EOC_Pos)	/*!< 0x00000002 */
#define ADC_SR_EOC          ADC_SR_EOC_Msk				/*!<End of conversion                                    */
#define ADC_SR_JEOC_Pos     (2U)
#define ADC_SR_JEOC_Msk     (0x1UL << ADC_SR_JEOC_Pos)	/*!< 0x00000004 */
#define ADC_SR_JEOC         ADC_SR_JEOC_Msk				/*!<Injected channel end of conversion                   */
#define ADC_SR_JSTRT_Pos    (3U)
#define ADC_SR_JSTRT_Msk    (0x1UL << ADC_SR_JSTRT_Pos)	/*!< 0x00000008 */
#define ADC_SR_JSTRT        ADC_SR_JSTRT_Msk/*!<Injected channel Start flag                          */
#define ADC_SR_STRT_Pos     (4U)
#define ADC_SR_STRT_Msk     (0x1UL << ADC_SR_STRT_Pos)	/*!< 0x00000010 */
#define ADC_SR_STRT         ADC_SR_STRT_Msk				/*!<Regular channel Start flag                           */
#define ADC_SR_OVR_Pos      (5U)
#define ADC_SR_OVR_Msk      (0x1UL << ADC_SR_OVR_Pos)	/*!< 0x00000020 */
#define ADC_SR_OVR          ADC_SR_OVR_Msk				/*!<Overrun flag                                         */

/*******************  Bit definition for ADC_CR1 register  ********************/
#define ADC_CR1_AWDCH_Pos      (0U)
#define ADC_CR1_AWDCH_Msk      (0x1FUL << ADC_CR1_AWDCH_Pos)/*!< 0x0000001F */
#define ADC_CR1_AWDCH          ADC_CR1_AWDCH_Msk/*!<AWDCH[4:0] bits (Analog watchdog channel select bits) */
#define ADC_CR1_AWDCH_0        (0x01UL << ADC_CR1_AWDCH_Pos)/*!< 0x00000001 */
#define ADC_CR1_AWDCH_1        (0x02UL << ADC_CR1_AWDCH_Pos)/*!< 0x00000002 */
#define ADC_CR1_AWDCH_2        (0x04UL << ADC_CR1_AWDCH_Pos)/*!< 0x00000004 */
#define ADC_CR1_AWDCH_3        (0x08UL << ADC_CR1_AWDCH_Pos)/*!< 0x00000008 */
#define ADC_CR1_AWDCH_4        (0x10UL << ADC_CR1_AWDCH_Pos)/*!< 0x00000010 */
#define ADC_CR1_EOCIE_Pos      (5U)
#define ADC_CR1_EOCIE_Msk      (0x1UL << ADC_CR1_EOCIE_Pos)	/*!< 0x00000020 */
#define ADC_CR1_EOCIE          ADC_CR1_EOCIE_Msk/*!<Interrupt enable for EOC                             */
#define ADC_CR1_AWDIE_Pos      (6U)
#define ADC_CR1_AWDIE_Msk      (0x1UL << ADC_CR1_AWDIE_Pos)	/*!< 0x00000040 */
#define ADC_CR1_AWDIE          ADC_CR1_AWDIE_Msk/*!<AAnalog Watchdog interrupt enable                    */
#define ADC_CR1_JEOCIE_Pos     (7U)
#define ADC_CR1_JEOCIE_Msk     (0x1UL << ADC_CR1_JEOCIE_Pos)/*!< 0x00000080 */
#define ADC_CR1_JEOCIE         ADC_CR1_JEOCIE_Msk	/*!<Interrupt enable for injected channels               */
#define ADC_CR1_SCAN_Pos       (8U)
#define ADC_CR1_SCAN_Msk       (0x1UL << ADC_CR1_SCAN_Pos)	/*!< 0x00000100 */
#define ADC_CR1_SCAN           ADC_CR1_SCAN_Msk				/*!<Scan mode */
#define ADC_CR1_AWDSGL_Pos     (9U)
#define ADC_CR1_AWDSGL_Msk     (0x1UL << ADC_CR1_AWDSGL_Pos)/*!< 0x00000200 */
#define ADC_CR1_AWDSGL         ADC_CR1_AWDSGL_Msk	/*!<Enable the watchdog on a single channel in scan mode */
#define ADC_CR1_JAUTO_Pos      (10U)
#define ADC_CR1_JAUTO_Msk      (0x1UL << ADC_CR1_JAUTO_Pos)	/*!< 0x00000400 */
#define ADC_CR1_JAUTO          ADC_CR1_JAUTO_Msk/*!<Automatic injected group conversion                  */
#define ADC_CR1_DISCEN_Pos     (11U)
#define ADC_CR1_DISCEN_Msk     (0x1UL << ADC_CR1_DISCEN_Pos)/*!< 0x00000800 */
#define ADC_CR1_DISCEN         ADC_CR1_DISCEN_Msk	/*!<Discontinuous mode on regular channels               */
#define ADC_CR1_JDISCEN_Pos    (12U)
#define ADC_CR1_JDISCEN_Msk    (0x1UL << ADC_CR1_JDISCEN_Pos)	/*!< 0x00001000 */
#define ADC_CR1_JDISCEN        ADC_CR1_JDISCEN_Msk				/*!<Discontinuous mode on injected channels              */
#define ADC_CR1_DISCNUM_Pos    (13U)
#define ADC_CR1_DISCNUM_Msk    (0x7UL << ADC_CR1_DISCNUM_Pos)	/*!< 0x0000E000 */
#define ADC_CR1_DISCNUM        ADC_CR1_DISCNUM_Msk				/*!<DISCNUM[2:0] bits (Discontinuous mode channel count) */
#define ADC_CR1_DISCNUM_0      (0x1UL << ADC_CR1_DISCNUM_Pos)	/*!< 0x00002000 */
#define ADC_CR1_DISCNUM_1      (0x2UL << ADC_CR1_DISCNUM_Pos)	/*!< 0x00004000 */
#define ADC_CR1_DISCNUM_2      (0x4UL << ADC_CR1_DISCNUM_Pos)	/*!< 0x00008000 */
#define ADC_CR1_JAWDEN_Pos     (22U)
#define ADC_CR1_JAWDEN_Msk     (0x1UL << ADC_CR1_JAWDEN_Pos)/*!< 0x00400000 */
#define ADC_CR1_JAWDEN         ADC_CR1_JAWDEN_Msk	/*!<Analog watchdog enable on injected channels          */
#define ADC_CR1_AWDEN_Pos      (23U)
#define ADC_CR1_AWDEN_Msk      (0x1UL << ADC_CR1_AWDEN_Pos)	/*!< 0x00800000 */
#define ADC_CR1_AWDEN          ADC_CR1_AWDEN_Msk/*!<Analog watchdog enable on regular channels           */
#define ADC_CR1_RES_Pos        (24U)
#define ADC_CR1_RES_Msk        (0x3UL << ADC_CR1_RES_Pos)	/*!< 0x03000000 */
#define ADC_CR1_RES            ADC_CR1_RES_Msk				/*!<RES[2:0] bits (Resolution)                           */
#define ADC_CR1_RES_0          (0x1UL << ADC_CR1_RES_Pos)	/*!< 0x01000000 */
#define ADC_CR1_RES_1          (0x2UL << ADC_CR1_RES_Pos)	/*!< 0x02000000 */
#define ADC_CR1_OVRIE_Pos      (26U)
#define ADC_CR1_OVRIE_Msk      (0x1UL << ADC_CR1_OVRIE_Pos)	/*!< 0x04000000 */
#define ADC_CR1_OVRIE          ADC_CR1_OVRIE_Msk/*!<overrun interrupt enable */

/*******************  Bit definition for ADC_CR2 register  ********************/
#define ADC_CR2_ADON_Pos        (0U)
#define ADC_CR2_ADON_Msk        (0x1UL << ADC_CR2_ADON_Pos)	/*!< 0x00000001 */
#define ADC_CR2_ADON            ADC_CR2_ADON_Msk/*!<A/D Converter ON / OFF                                       */
#define ADC_CR2_CONT_Pos        (1U)
#define ADC_CR2_CONT_Msk        (0x1UL << ADC_CR2_CONT_Pos)	/*!< 0x00000002 */
#define ADC_CR2_CONT            ADC_CR2_CONT_Msk/*!<Continuous Conversion                                        */
#define ADC_CR2_DMA_Pos         (8U)
#define ADC_CR2_DMA_Msk         (0x1UL << ADC_CR2_DMA_Pos)	/*!< 0x00000100 */
#define ADC_CR2_DMA             ADC_CR2_DMA_Msk				/*!<Direct Memory access mode                                    */
#define ADC_CR2_DDS_Pos         (9U)
#define ADC_CR2_DDS_Msk         (0x1UL << ADC_CR2_DDS_Pos)	/*!< 0x00000200 */
#define ADC_CR2_DDS             ADC_CR2_DDS_Msk				/*!<DMA disable selection (Single ADC)                           */
#define ADC_CR2_EOCS_Pos        (10U)
#define ADC_CR2_EOCS_Msk        (0x1UL << ADC_CR2_EOCS_Pos)	/*!< 0x00000400 */
#define ADC_CR2_EOCS            ADC_CR2_EOCS_Msk/*!<End of conversion selection                                  */
#define ADC_CR2_ALIGN_Pos       (11U)
#define ADC_CR2_ALIGN_Msk       (0x1UL << ADC_CR2_ALIGN_Pos)/*!< 0x00000800 */
#define ADC_CR2_ALIGN           ADC_CR2_ALIGN_Msk	/*!<Data Alignment                                               */
#define ADC_CR2_JEXTSEL_Pos     (16U)
#define ADC_CR2_JEXTSEL_Msk     (0xFUL << ADC_CR2_JEXTSEL_Pos)	/*!< 0x000F0000 */
#define ADC_CR2_JEXTSEL         ADC_CR2_JEXTSEL_Msk				/*!<JEXTSEL[3:0] bits (External event select for injected group) */
#define ADC_CR2_JEXTSEL_0       (0x1UL << ADC_CR2_JEXTSEL_Pos)	/*!< 0x00010000 */
#define ADC_CR2_JEXTSEL_1       (0x2UL << ADC_CR2_JEXTSEL_Pos)	/*!< 0x00020000 */
#define ADC_CR2_JEXTSEL_2       (0x4UL << ADC_CR2_JEXTSEL_Pos)	/*!< 0x00040000 */
#define ADC_CR2_JEXTSEL_3       (0x8UL << ADC_CR2_JEXTSEL_Pos)	/*!< 0x00080000 */
#define ADC_CR2_JEXTEN_Pos      (20U)
#define ADC_CR2_JEXTEN_Msk      (0x3UL << ADC_CR2_JEXTEN_Pos)	/*!< 0x00300000 */
#define ADC_CR2_JEXTEN          ADC_CR2_JEXTEN_Msk				/*!<JEXTEN[1:0] bits (External Trigger Conversion mode for injected channelsp) */
#define ADC_CR2_JEXTEN_0        (0x1UL << ADC_CR2_JEXTEN_Pos)	/*!< 0x00100000 */
#define ADC_CR2_JEXTEN_1        (0x2UL << ADC_CR2_JEXTEN_Pos)	/*!< 0x00200000 */
#define ADC_CR2_JSWSTART_Pos    (22U)
#define ADC_CR2_JSWSTART_Msk    (0x1UL << ADC_CR2_JSWSTART_Pos)	/*!< 0x00400000 */
#define ADC_CR2_JSWSTART        ADC_CR2_JSWSTART_Msk/*!<Start Conversion of injected channels */
#define ADC_CR2_EXTSEL_Pos      (24U)
#define ADC_CR2_EXTSEL_Msk      (0xFUL << ADC_CR2_EXTSEL_Pos)	/*!< 0x0F000000 */
#define ADC_CR2_EXTSEL          ADC_CR2_EXTSEL_Msk				/*!<EXTSEL[3:0] bits (External Event Select for regular group) */
#define ADC_CR2_EXTSEL_0        (0x1UL << ADC_CR2_EXTSEL_Pos)	/*!< 0x01000000 */
#define ADC_CR2_EXTSEL_1        (0x2UL << ADC_CR2_EXTSEL_Pos)	/*!< 0x02000000 */
#define ADC_CR2_EXTSEL_2        (0x4UL << ADC_CR2_EXTSEL_Pos)	/*!< 0x04000000 */
#define ADC_CR2_EXTSEL_3        (0x8UL << ADC_CR2_EXTSEL_Pos)	/*!< 0x08000000 */
#define ADC_CR2_EXTEN_Pos       (28U)
#define ADC_CR2_EXTEN_Msk       (0x3UL << ADC_CR2_EXTEN_Pos)/*!< 0x30000000 */
#define ADC_CR2_EXTEN           ADC_CR2_EXTEN_Msk	/*!<EXTEN[1:0] bits (External Trigger Conversion mode for regular channelsp) */
#define ADC_CR2_EXTEN_0         (0x1UL << ADC_CR2_EXTEN_Pos)/*!< 0x10000000 */
#define ADC_CR2_EXTEN_1         (0x2UL << ADC_CR2_EXTEN_Pos)/*!< 0x20000000 */
#define ADC_CR2_SWSTART_Pos     (30U)
#define ADC_CR2_SWSTART_Msk     (0x1UL << ADC_CR2_SWSTART_Pos)	/*!< 0x40000000 */
#define ADC_CR2_SWSTART         ADC_CR2_SWSTART_Msk				/*!<Start Conversion of regular channels */

/******************  Bit definition for ADC_SMPR1 register  *******************/
#define ADC_SMPR1_SMP10_Pos    (0U)
#define ADC_SMPR1_SMP10_Msk    (0x7UL << ADC_SMPR1_SMP10_Pos)	/*!< 0x00000007 */
#define ADC_SMPR1_SMP10        ADC_SMPR1_SMP10_Msk				/*!<SMP10[2:0] bits (Channel 10 Sample time selection) */
#define ADC_SMPR1_SMP10_0      (0x1UL << ADC_SMPR1_SMP10_Pos)	/*!< 0x00000001 */
#define ADC_SMPR1_SMP10_1      (0x2UL << ADC_SMPR1_SMP10_Pos)	/*!< 0x00000002 */
#define ADC_SMPR1_SMP10_2      (0x4UL << ADC_SMPR1_SMP10_Pos)	/*!< 0x00000004 */
#define ADC_SMPR1_SMP11_Pos    (3U)
#define ADC_SMPR1_SMP11_Msk    (0x7UL << ADC_SMPR1_SMP11_Pos)	/*!< 0x00000038 */
#define ADC_SMPR1_SMP11        ADC_SMPR1_SMP11_Msk				/*!<SMP11[2:0] bits (Channel 11 Sample time selection) */
#define ADC_SMPR1_SMP11_0      (0x1UL << ADC_SMPR1_SMP11_Pos)	/*!< 0x00000008 */
#define ADC_SMPR1_SMP11_1      (0x2UL << ADC_SMPR1_SMP11_Pos)	/*!< 0x00000010 */
#define ADC_SMPR1_SMP11_2      (0x4UL << ADC_SMPR1_SMP11_Pos)	/*!< 0x00000020 */
#define ADC_SMPR1_SMP12_Pos    (6U)
#define ADC_SMPR1_SMP12_Msk    (0x7UL << ADC_SMPR1_SMP12_Pos)	/*!< 0x000001C0 */
#define ADC_SMPR1_SMP12        ADC_SMPR1_SMP12_Msk				/*!<SMP12[2:0] bits (Channel 12 Sample time selection) */
#define ADC_SMPR1_SMP12_0      (0x1UL << ADC_SMPR1_SMP12_Pos)	/*!< 0x00000040 */
#define ADC_SMPR1_SMP12_1      (0x2UL << ADC_SMPR1_SMP12_Pos)	/*!< 0x00000080 */
#define ADC_SMPR1_SMP12_2      (0x4UL << ADC_SMPR1_SMP12_Pos)	/*!< 0x00000100 */
#define ADC_SMPR1_SMP13_Pos    (9U)
#define ADC_SMPR1_SMP13_Msk    (0x7UL << ADC_SMPR1_SMP13_Pos)	/*!< 0x00000E00 */
#define ADC_SMPR1_SMP13        ADC_SMPR1_SMP13_Msk				/*!<SMP13[2:0] bits (Channel 13 Sample time selection) */
#define ADC_SMPR1_SMP13_0      (0x1UL << ADC_SMPR1_SMP13_Pos)	/*!< 0x00000200 */
#define ADC_SMPR1_SMP13_1      (0x2UL << ADC_SMPR1_SMP13_Pos)	/*!< 0x00000400 */
#define ADC_SMPR1_SMP13_2      (0x4UL << ADC_SMPR1_SMP13_Pos)	/*!< 0x00000800 */
#define ADC_SMPR1_SMP14_Pos    (12U)
#define ADC_SMPR1_SMP14_Msk    (0x7UL << ADC_SMPR1_SMP14_Pos)	/*!< 0x00007000 */
#define ADC_SMPR1_SMP14        ADC_SMPR1_SMP14_Msk				/*!<SMP14[2:0] bits (Channel 14 Sample time selection) */
#define ADC_SMPR1_SMP14_0      (0x1UL << ADC_SMPR1_SMP14_Pos)	/*!< 0x00001000 */
#define ADC_SMPR1_SMP14_1      (0x2UL << ADC_SMPR1_SMP14_Pos)	/*!< 0x00002000 */
#define ADC_SMPR1_SMP14_2      (0x4UL << ADC_SMPR1_SMP14_Pos)	/*!< 0x00004000 */
#define ADC_SMPR1_SMP15_Pos    (15U)
#define ADC_SMPR1_SMP15_Msk    (0x7UL << ADC_SMPR1_SMP15_Pos)	/*!< 0x00038000 */
#define ADC_SMPR1_SMP15        ADC_SMPR1_SMP15_Msk				/*!<SMP15[2:0] bits (Channel 15 Sample time selection) */
#define ADC_SMPR1_SMP15_0      (0x1UL << ADC_SMPR1_SMP15_Pos)	/*!< 0x00008000 */
#define ADC_SMPR1_SMP15_1      (0x2UL << ADC_SMPR1_SMP15_Pos)	/*!< 0x00010000 */
#define ADC_SMPR1_SMP15_2      (0x4UL << ADC_SMPR1_SMP15_Pos)	/*!< 0x00020000 */
#define ADC_SMPR1_SMP16_Pos    (18U)
#define ADC_SMPR1_SMP16_Msk    (0x7UL << ADC_SMPR1_SMP16_Pos)	/*!< 0x001C0000 */
#define ADC_SMPR1_SMP16        ADC_SMPR1_SMP16_Msk				/*!<SMP16[2:0] bits (Channel 16 Sample time selection) */
#define ADC_SMPR1_SMP16_0      (0x1UL << ADC_SMPR1_SMP16_Pos)	/*!< 0x00040000 */
#define ADC_SMPR1_SMP16_1      (0x2UL << ADC_SMPR1_SMP16_Pos)	/*!< 0x00080000 */
#define ADC_SMPR1_SMP16_2      (0x4UL << ADC_SMPR1_SMP16_Pos)	/*!< 0x00100000 */
#define ADC_SMPR1_SMP17_Pos    (21U)
#define ADC_SMPR1_SMP17_Msk    (0x7UL << ADC_SMPR1_SMP17_Pos)	/*!< 0x00E00000 */
#define ADC_SMPR1_SMP17        ADC_SMPR1_SMP17_Msk				/*!<SMP17[2:0] bits (Channel 17 Sample time selection) */
#define ADC_SMPR1_SMP17_0      (0x1UL << ADC_SMPR1_SMP17_Pos)	/*!< 0x00200000 */
#define ADC_SMPR1_SMP17_1      (0x2UL << ADC_SMPR1_SMP17_Pos)	/*!< 0x00400000 */
#define ADC_SMPR1_SMP17_2      (0x4UL << ADC_SMPR1_SMP17_Pos)	/*!< 0x00800000 */
#define ADC_SMPR1_SMP18_Pos    (24U)
#define ADC_SMPR1_SMP18_Msk    (0x7UL << ADC_SMPR1_SMP18_Pos)	/*!< 0x07000000 */
#define ADC_SMPR1_SMP18        ADC_SMPR1_SMP18_Msk				/*!<SMP18[2:0] bits (Channel 18 Sample time selection) */
#define ADC_SMPR1_SMP18_0      (0x1UL << ADC_SMPR1_SMP18_Pos)	/*!< 0x01000000 */
#define ADC_SMPR1_SMP18_1      (0x2UL << ADC_SMPR1_SMP18_Pos)	/*!< 0x02000000 */
#define ADC_SMPR1_SMP18_2      (0x4UL << ADC_SMPR1_SMP18_Pos)	/*!< 0x04000000 */

/******************  Bit definition for ADC_SMPR2 register  *******************/
#define ADC_SMPR2_SMP0_Pos    (0U)
#define ADC_SMPR2_SMP0_Msk    (0x7UL << ADC_SMPR2_SMP0_Pos)	/*!< 0x00000007 */
#define ADC_SMPR2_SMP0        ADC_SMPR2_SMP0_Msk/*!<SMP0[2:0] bits (Channel 0 Sample time selection) */
#define ADC_SMPR2_SMP0_0      (0x1UL << ADC_SMPR2_SMP0_Pos)	/*!< 0x00000001 */
#define ADC_SMPR2_SMP0_1      (0x2UL << ADC_SMPR2_SMP0_Pos)	/*!< 0x00000002 */
#define ADC_SMPR2_SMP0_2      (0x4UL << ADC_SMPR2_SMP0_Pos)	/*!< 0x00000004 */
#define ADC_SMPR2_SMP1_Pos    (3U)
#define ADC_SMPR2_SMP1_Msk    (0x7UL << ADC_SMPR2_SMP1_Pos)	/*!< 0x00000038 */
#define ADC_SMPR2_SMP1        ADC_SMPR2_SMP1_Msk/*!<SMP1[2:0] bits (Channel 1 Sample time selection) */
#define ADC_SMPR2_SMP1_0      (0x1UL << ADC_SMPR2_SMP1_Pos)	/*!< 0x00000008 */
#define ADC_SMPR2_SMP1_1      (0x2UL << ADC_SMPR2_SMP1_Pos)	/*!< 0x00000010 */
#define ADC_SMPR2_SMP1_2      (0x4UL << ADC_SMPR2_SMP1_Pos)	/*!< 0x00000020 */
#define ADC_SMPR2_SMP2_Pos    (6U)
#define ADC_SMPR2_SMP2_Msk    (0x7UL << ADC_SMPR2_SMP2_Pos)	/*!< 0x000001C0 */
#define ADC_SMPR2_SMP2        ADC_SMPR2_SMP2_Msk/*!<SMP2[2:0] bits (Channel 2 Sample time selection) */
#define ADC_SMPR2_SMP2_0      (0x1UL << ADC_SMPR2_SMP2_Pos)	/*!< 0x00000040 */
#define ADC_SMPR2_SMP2_1      (0x2UL << ADC_SMPR2_SMP2_Pos)	/*!< 0x00000080 */
#define ADC_SMPR2_SMP2_2      (0x4UL << ADC_SMPR2_SMP2_Pos)	/*!< 0x00000100 */
#define ADC_SMPR2_SMP3_Pos    (9U)
#define ADC_SMPR2_SMP3_Msk    (0x7UL << ADC_SMPR2_SMP3_Pos)	/*!< 0x00000E00 */
#define ADC_SMPR2_SMP3        ADC_SMPR2_SMP3_Msk/*!<SMP3[2:0] bits (Channel 3 Sample time selection) */
#define ADC_SMPR2_SMP3_0      (0x1UL << ADC_SMPR2_SMP3_Pos)	/*!< 0x00000200 */
#define ADC_SMPR2_SMP3_1      (0x2UL << ADC_SMPR2_SMP3_Pos)	/*!< 0x00000400 */
#define ADC_SMPR2_SMP3_2      (0x4UL << ADC_SMPR2_SMP3_Pos)	/*!< 0x00000800 */
#define ADC_SMPR2_SMP4_Pos    (12U)
#define ADC_SMPR2_SMP4_Msk    (0x7UL << ADC_SMPR2_SMP4_Pos)	/*!< 0x00007000 */
#define ADC_SMPR2_SMP4        ADC_SMPR2_SMP4_Msk/*!<SMP4[2:0] bits (Channel 4 Sample time selection) */
#define ADC_SMPR2_SMP4_0      (0x1UL << ADC_SMPR2_SMP4_Pos)	/*!< 0x00001000 */
#define ADC_SMPR2_SMP4_1      (0x2UL << ADC_SMPR2_SMP4_Pos)	/*!< 0x00002000 */
#define ADC_SMPR2_SMP4_2      (0x4UL << ADC_SMPR2_SMP4_Pos)	/*!< 0x00004000 */
#define ADC_SMPR2_SMP5_Pos    (15U)
#define ADC_SMPR2_SMP5_Msk    (0x7UL << ADC_SMPR2_SMP5_Pos)	/*!< 0x00038000 */
#define ADC_SMPR2_SMP5        ADC_SMPR2_SMP5_Msk/*!<SMP5[2:0] bits (Channel 5 Sample time selection) */
#define ADC_SMPR2_SMP5_0      (0x1UL << ADC_SMPR2_SMP5_Pos)	/*!< 0x00008000 */
#define ADC_SMPR2_SMP5_1      (0x2UL << ADC_SMPR2_SMP5_Pos)	/*!< 0x00010000 */
#define ADC_SMPR2_SMP5_2      (0x4UL << ADC_SMPR2_SMP5_Pos)	/*!< 0x00020000 */
#define ADC_SMPR2_SMP6_Pos    (18U)
#define ADC_SMPR2_SMP6_Msk    (0x7UL << ADC_SMPR2_SMP6_Pos)	/*!< 0x001C0000 */
#define ADC_SMPR2_SMP6        ADC_SMPR2_SMP6_Msk/*!<SMP6[2:0] bits (Channel 6 Sample time selection) */
#define ADC_SMPR2_SMP6_0      (0x1UL << ADC_SMPR2_SMP6_Pos)	/*!< 0x00040000 */
#define ADC_SMPR2_SMP6_1      (0x2UL << ADC_SMPR2_SMP6_Pos)	/*!< 0x00080000 */
#define ADC_SMPR2_SMP6_2      (0x4UL << ADC_SMPR2_SMP6_Pos)	/*!< 0x00100000 */
#define ADC_SMPR2_SMP7_Pos    (21U)
#define ADC_SMPR2_SMP7_Msk    (0x7UL << ADC_SMPR2_SMP7_Pos)	/*!< 0x00E00000 */
#define ADC_SMPR2_SMP7        ADC_SMPR2_SMP7_Msk/*!<SMP7[2:0] bits (Channel 7 Sample time selection) */
#define ADC_SMPR2_SMP7_0      (0x1UL << ADC_SMPR2_SMP7_Pos)	/*!< 0x00200000 */
#define ADC_SMPR2_SMP7_1      (0x2UL << ADC_SMPR2_SMP7_Pos)	/*!< 0x00400000 */
#define ADC_SMPR2_SMP7_2      (0x4UL << ADC_SMPR2_SMP7_Pos)	/*!< 0x00800000 */
#define ADC_SMPR2_SMP8_Pos    (24U)
#define ADC_SMPR2_SMP8_Msk    (0x7UL << ADC_SMPR2_SMP8_Pos)	/*!< 0x07000000 */
#define ADC_SMPR2_SMP8        ADC_SMPR2_SMP8_Msk/*!<SMP8[2:0] bits (Channel 8 Sample time selection) */
#define ADC_SMPR2_SMP8_0      (0x1UL << ADC_SMPR2_SMP8_Pos)	/*!< 0x01000000 */
#define ADC_SMPR2_SMP8_1      (0x2UL << ADC_SMPR2_SMP8_Pos)	/*!< 0x02000000 */
#define ADC_SMPR2_SMP8_2      (0x4UL << ADC_SMPR2_SMP8_Pos)	/*!< 0x04000000 */
#define ADC_SMPR2_SMP9_Pos    (27U)
#define ADC_SMPR2_SMP9_Msk    (0x7UL << ADC_SMPR2_SMP9_Pos)	/*!< 0x38000000 */
#define ADC_SMPR2_SMP9        ADC_SMPR2_SMP9_Msk/*!<SMP9[2:0] bits (Channel 9 Sample time selection) */
#define ADC_SMPR2_SMP9_0      (0x1UL << ADC_SMPR2_SMP9_Pos)	/*!< 0x08000000 */
#define ADC_SMPR2_SMP9_1      (0x2UL << ADC_SMPR2_SMP9_Pos)	/*!< 0x10000000 */
#define ADC_SMPR2_SMP9_2      (0x4UL << ADC_SMPR2_SMP9_Pos)	/*!< 0x20000000 */

/******************  Bit definition for ADC_JOFR1 register  *******************/
#define ADC_JOFR1_JOFFSET1_Pos    (0U)
#define ADC_JOFR1_JOFFSET1_Msk    (0xFFFUL << ADC_JOFR1_JOFFSET1_Pos)	/*!< 0x00000FFF */
#define ADC_JOFR1_JOFFSET1        ADC_JOFR1_JOFFSET1_Msk				/*!<Data offset for injected channel 1 */

/******************  Bit definition for ADC_JOFR2 register  *******************/
#define ADC_JOFR2_JOFFSET2_Pos    (0U)
#define ADC_JOFR2_JOFFSET2_Msk    (0xFFFUL << ADC_JOFR2_JOFFSET2_Pos)	/*!< 0x00000FFF */
#define ADC_JOFR2_JOFFSET2        ADC_JOFR2_JOFFSET2_Msk				/*!<Data offset for injected channel 2 */

/******************  Bit definition for ADC_JOFR3 register  *******************/
#define ADC_JOFR3_JOFFSET3_Pos    (0U)
#define ADC_JOFR3_JOFFSET3_Msk    (0xFFFUL << ADC_JOFR3_JOFFSET3_Pos)	/*!< 0x00000FFF */
#define ADC_JOFR3_JOFFSET3        ADC_JOFR3_JOFFSET3_Msk				/*!<Data offset for injected channel 3 */

/******************  Bit definition for ADC_JOFR4 register  *******************/
#define ADC_JOFR4_JOFFSET4_Pos    (0U)
#define ADC_JOFR4_JOFFSET4_Msk    (0xFFFUL << ADC_JOFR4_JOFFSET4_Pos)	/*!< 0x00000FFF */
#define ADC_JOFR4_JOFFSET4        ADC_JOFR4_JOFFSET4_Msk				/*!<Data offset for injected channel 4 */

/*******************  Bit definition for ADC_HTR register  ********************/
#define ADC_HTR_HT_Pos    (0U)
#define ADC_HTR_HT_Msk    (0xFFFUL << ADC_HTR_HT_Pos)	/*!< 0x00000FFF */
#define ADC_HTR_HT        ADC_HTR_HT_Msk				/*!<Analog watchdog high threshold */

/*******************  Bit definition for ADC_LTR register  ********************/
#define ADC_LTR_LT_Pos    (0U)
#define ADC_LTR_LT_Msk    (0xFFFUL << ADC_LTR_LT_Pos)	/*!< 0x00000FFF */
#define ADC_LTR_LT        ADC_LTR_LT_Msk				/*!<Analog watchdog low threshold */

/*******************  Bit definition for ADC_SQR1 register  *******************/
#define ADC_SQR1_SQ13_Pos    (0U)
#define ADC_SQR1_SQ13_Msk    (0x1FUL << ADC_SQR1_SQ13_Pos)	/*!< 0x0000001F */
#define ADC_SQR1_SQ13        ADC_SQR1_SQ13_Msk				/*!<SQ13[4:0] bits (13th conversion in regular sequence) */
#define ADC_SQR1_SQ13_0      (0x01UL << ADC_SQR1_SQ13_Pos)	/*!< 0x00000001 */
#define ADC_SQR1_SQ13_1      (0x02UL << ADC_SQR1_SQ13_Pos)	/*!< 0x00000002 */
#define ADC_SQR1_SQ13_2      (0x04UL << ADC_SQR1_SQ13_Pos)	/*!< 0x00000004 */
#define ADC_SQR1_SQ13_3      (0x08UL << ADC_SQR1_SQ13_Pos)	/*!< 0x00000008 */
#define ADC_SQR1_SQ13_4      (0x10UL << ADC_SQR1_SQ13_Pos)	/*!< 0x00000010 */
#define ADC_SQR1_SQ14_Pos    (5U)
#define ADC_SQR1_SQ14_Msk    (0x1FUL << ADC_SQR1_SQ14_Pos)	/*!< 0x000003E0 */
#define ADC_SQR1_SQ14        ADC_SQR1_SQ14_Msk				/*!<SQ14[4:0] bits (14th conversion in regular sequence) */
#define ADC_SQR1_SQ14_0      (0x01UL << ADC_SQR1_SQ14_Pos)	/*!< 0x00000020 */
#define ADC_SQR1_SQ14_1      (0x02UL << ADC_SQR1_SQ14_Pos)	/*!< 0x00000040 */
#define ADC_SQR1_SQ14_2      (0x04UL << ADC_SQR1_SQ14_Pos)	/*!< 0x00000080 */
#define ADC_SQR1_SQ14_3      (0x08UL << ADC_SQR1_SQ14_Pos)	/*!< 0x00000100 */
#define ADC_SQR1_SQ14_4      (0x10UL << ADC_SQR1_SQ14_Pos)	/*!< 0x00000200 */
#define ADC_SQR1_SQ15_Pos    (10U)
#define ADC_SQR1_SQ15_Msk    (0x1FUL << ADC_SQR1_SQ15_Pos)	/*!< 0x00007C00 */
#define ADC_SQR1_SQ15        ADC_SQR1_SQ15_Msk				/*!<SQ15[4:0] bits (15th conversion in regular sequence) */
#define ADC_SQR1_SQ15_0      (0x01UL << ADC_SQR1_SQ15_Pos)	/*!< 0x00000400 */
#define ADC_SQR1_SQ15_1      (0x02UL << ADC_SQR1_SQ15_Pos)	/*!< 0x00000800 */
#define ADC_SQR1_SQ15_2      (0x04UL << ADC_SQR1_SQ15_Pos)	/*!< 0x00001000 */
#define ADC_SQR1_SQ15_3      (0x08UL << ADC_SQR1_SQ15_Pos)	/*!< 0x00002000 */
#define ADC_SQR1_SQ15_4      (0x10UL << ADC_SQR1_SQ15_Pos)	/*!< 0x00004000 */
#define ADC_SQR1_SQ16_Pos    (15U)
#define ADC_SQR1_SQ16_Msk    (0x1FUL << ADC_SQR1_SQ16_Pos)	/*!< 0x000F8000 */
#define ADC_SQR1_SQ16        ADC_SQR1_SQ16_Msk				/*!<SQ16[4:0] bits (16th conversion in regular sequence) */
#define ADC_SQR1_SQ16_0      (0x01UL << ADC_SQR1_SQ16_Pos)	/*!< 0x00008000 */
#define ADC_SQR1_SQ16_1      (0x02UL << ADC_SQR1_SQ16_Pos)	/*!< 0x00010000 */
#define ADC_SQR1_SQ16_2      (0x04UL << ADC_SQR1_SQ16_Pos)	/*!< 0x00020000 */
#define ADC_SQR1_SQ16_3      (0x08UL << ADC_SQR1_SQ16_Pos)	/*!< 0x00040000 */
#define ADC_SQR1_SQ16_4      (0x10UL << ADC_SQR1_SQ16_Pos)	/*!< 0x00080000 */
#define ADC_SQR1_L_Pos       (20U)
#define ADC_SQR1_L_Msk       (0xFUL << ADC_SQR1_L_Pos)	/*!< 0x00F00000 */
#define ADC_SQR1_L           ADC_SQR1_L_Msk				/*!<L[3:0] bits (Regular channel sequence length) */
#define ADC_SQR1_L_0         (0x1UL << ADC_SQR1_L_Pos)	/*!< 0x00100000 */
#define ADC_SQR1_L_1         (0x2UL << ADC_SQR1_L_Pos)	/*!< 0x00200000 */
#define ADC_SQR1_L_2         (0x4UL << ADC_SQR1_L_Pos)	/*!< 0x00400000 */
#define ADC_SQR1_L_3         (0x8UL << ADC_SQR1_L_Pos)	/*!< 0x00800000 */

/*******************  Bit definition for ADC_SQR2 register  *******************/
#define ADC_SQR2_SQ7_Pos     (0U)
#define ADC_SQR2_SQ7_Msk     (0x1FUL << ADC_SQR2_SQ7_Pos)	/*!< 0x0000001F */
#define ADC_SQR2_SQ7         ADC_SQR2_SQ7_Msk				/*!<SQ7[4:0] bits (7th conversion in regular sequence) */
#define ADC_SQR2_SQ7_0       (0x01UL << ADC_SQR2_SQ7_Pos)	/*!< 0x00000001 */
#define ADC_SQR2_SQ7_1       (0x02UL << ADC_SQR2_SQ7_Pos)	/*!< 0x00000002 */
#define ADC_SQR2_SQ7_2       (0x04UL << ADC_SQR2_SQ7_Pos)	/*!< 0x00000004 */
#define ADC_SQR2_SQ7_3       (0x08UL << ADC_SQR2_SQ7_Pos)	/*!< 0x00000008 */
#define ADC_SQR2_SQ7_4       (0x10UL << ADC_SQR2_SQ7_Pos)	/*!< 0x00000010 */
#define ADC_SQR2_SQ8_Pos     (5U)
#define ADC_SQR2_SQ8_Msk     (0x1FUL << ADC_SQR2_SQ8_Pos)	/*!< 0x000003E0 */
#define ADC_SQR2_SQ8         ADC_SQR2_SQ8_Msk				/*!<SQ8[4:0] bits (8th conversion in regular sequence) */
#define ADC_SQR2_SQ8_0       (0x01UL << ADC_SQR2_SQ8_Pos)	/*!< 0x00000020 */
#define ADC_SQR2_SQ8_1       (0x02UL << ADC_SQR2_SQ8_Pos)	/*!< 0x00000040 */
#define ADC_SQR2_SQ8_2       (0x04UL << ADC_SQR2_SQ8_Pos)	/*!< 0x00000080 */
#define ADC_SQR2_SQ8_3       (0x08UL << ADC_SQR2_SQ8_Pos)	/*!< 0x00000100 */
#define ADC_SQR2_SQ8_4       (0x10UL << ADC_SQR2_SQ8_Pos)	/*!< 0x00000200 */
#define ADC_SQR2_SQ9_Pos     (10U)
#define ADC_SQR2_SQ9_Msk     (0x1FUL << ADC_SQR2_SQ9_Pos)	/*!< 0x00007C00 */
#define ADC_SQR2_SQ9         ADC_SQR2_SQ9_Msk				/*!<SQ9[4:0] bits (9th conversion in regular sequence) */
#define ADC_SQR2_SQ9_0       (0x01UL << ADC_SQR2_SQ9_Pos)	/*!< 0x00000400 */
#define ADC_SQR2_SQ9_1       (0x02UL << ADC_SQR2_SQ9_Pos)	/*!< 0x00000800 */
#define ADC_SQR2_SQ9_2       (0x04UL << ADC_SQR2_SQ9_Pos)	/*!< 0x00001000 */
#define ADC_SQR2_SQ9_3       (0x08UL << ADC_SQR2_SQ9_Pos)	/*!< 0x00002000 */
#define ADC_SQR2_SQ9_4       (0x10UL << ADC_SQR2_SQ9_Pos)	/*!< 0x00004000 */
#define ADC_SQR2_SQ10_Pos    (15U)
#define ADC_SQR2_SQ10_Msk    (0x1FUL << ADC_SQR2_SQ10_Pos)	/*!< 0x000F8000 */
#define ADC_SQR2_SQ10        ADC_SQR2_SQ10_Msk				/*!<SQ10[4:0] bits (10th conversion in regular sequence) */
#define ADC_SQR2_SQ10_0      (0x01UL << ADC_SQR2_SQ10_Pos)	/*!< 0x00008000 */
#define ADC_SQR2_SQ10_1      (0x02UL << ADC_SQR2_SQ10_Pos)	/*!< 0x00010000 */
#define ADC_SQR2_SQ10_2      (0x04UL << ADC_SQR2_SQ10_Pos)	/*!< 0x00020000 */
#define ADC_SQR2_SQ10_3      (0x08UL << ADC_SQR2_SQ10_Pos)	/*!< 0x00040000 */
#define ADC_SQR2_SQ10_4      (0x10UL << ADC_SQR2_SQ10_Pos)	/*!< 0x00080000 */
#define ADC_SQR2_SQ11_Pos    (20U)
#define ADC_SQR2_SQ11_Msk    (0x1FUL << ADC_SQR2_SQ11_Pos)	/*!< 0x01F00000 */
#define ADC_SQR2_SQ11        ADC_SQR2_SQ11_Msk				/*!<SQ11[4:0] bits (11th conversion in regular sequence) */
#define ADC_SQR2_SQ11_0      (0x01UL << ADC_SQR2_SQ11_Pos)	/*!< 0x00100000 */
#define ADC_SQR2_SQ11_1      (0x02UL << ADC_SQR2_SQ11_Pos)	/*!< 0x00200000 */
#define ADC_SQR2_SQ11_2      (0x04UL << ADC_SQR2_SQ11_Pos)	/*!< 0x00400000 */
#define ADC_SQR2_SQ11_3      (0x08UL << ADC_SQR2_SQ11_Pos)	/*!< 0x00800000 */
#define ADC_SQR2_SQ11_4      (0x10UL << ADC_SQR2_SQ11_Pos)	/*!< 0x01000000 */
#define ADC_SQR2_SQ12_Pos    (25U)
#define ADC_SQR2_SQ12_Msk    (0x1FUL << ADC_SQR2_SQ12_Pos)	/*!< 0x3E000000 */
#define ADC_SQR2_SQ12        ADC_SQR2_SQ12_Msk				/*!<SQ12[4:0] bits (12th conversion in regular sequence) */
#define ADC_SQR2_SQ12_0      (0x01UL << ADC_SQR2_SQ12_Pos)	/*!< 0x02000000 */
#define ADC_SQR2_SQ12_1      (0x02UL << ADC_SQR2_SQ12_Pos)	/*!< 0x04000000 */
#define ADC_SQR2_SQ12_2      (0x04UL << ADC_SQR2_SQ12_Pos)	/*!< 0x08000000 */
#define ADC_SQR2_SQ12_3      (0x08UL << ADC_SQR2_SQ12_Pos)	/*!< 0x10000000 */
#define ADC_SQR2_SQ12_4      (0x10UL << ADC_SQR2_SQ12_Pos)	/*!< 0x20000000 */

/*******************  Bit definition for ADC_SQR3 register  *******************/
#define ADC_SQR3_SQ1_Pos    (0U)
#define ADC_SQR3_SQ1_Msk    (0x1FUL << ADC_SQR3_SQ1_Pos)/*!< 0x0000001F */
#define ADC_SQR3_SQ1        ADC_SQR3_SQ1_Msk/*!<SQ1[4:0] bits (1st conversion in regular sequence) */
#define ADC_SQR3_SQ1_0      (0x01UL << ADC_SQR3_SQ1_Pos)/*!< 0x00000001 */
#define ADC_SQR3_SQ1_1      (0x02UL << ADC_SQR3_SQ1_Pos)/*!< 0x00000002 */
#define ADC_SQR3_SQ1_2      (0x04UL << ADC_SQR3_SQ1_Pos)/*!< 0x00000004 */
#define ADC_SQR3_SQ1_3      (0x08UL << ADC_SQR3_SQ1_Pos)/*!< 0x00000008 */
#define ADC_SQR3_SQ1_4      (0x10UL << ADC_SQR3_SQ1_Pos)/*!< 0x00000010 */
#define ADC_SQR3_SQ2_Pos    (5U)
#define ADC_SQR3_SQ2_Msk    (0x1FUL << ADC_SQR3_SQ2_Pos)/*!< 0x000003E0 */
#define ADC_SQR3_SQ2        ADC_SQR3_SQ2_Msk/*!<SQ2[4:0] bits (2nd conversion in regular sequence) */
#define ADC_SQR3_SQ2_0      (0x01UL << ADC_SQR3_SQ2_Pos)/*!< 0x00000020 */
#define ADC_SQR3_SQ2_1      (0x02UL << ADC_SQR3_SQ2_Pos)/*!< 0x00000040 */
#define ADC_SQR3_SQ2_2      (0x04UL << ADC_SQR3_SQ2_Pos)/*!< 0x00000080 */
#define ADC_SQR3_SQ2_3      (0x08UL << ADC_SQR3_SQ2_Pos)/*!< 0x00000100 */
#define ADC_SQR3_SQ2_4      (0x10UL << ADC_SQR3_SQ2_Pos)/*!< 0x00000200 */
#define ADC_SQR3_SQ3_Pos    (10U)
#define ADC_SQR3_SQ3_Msk    (0x1FUL << ADC_SQR3_SQ3_Pos)/*!< 0x00007C00 */
#define ADC_SQR3_SQ3        ADC_SQR3_SQ3_Msk/*!<SQ3[4:0] bits (3rd conversion in regular sequence) */
#define ADC_SQR3_SQ3_0      (0x01UL << ADC_SQR3_SQ3_Pos)/*!< 0x00000400 */
#define ADC_SQR3_SQ3_1      (0x02UL << ADC_SQR3_SQ3_Pos)/*!< 0x00000800 */
#define ADC_SQR3_SQ3_2      (0x04UL << ADC_SQR3_SQ3_Pos)/*!< 0x00001000 */
#define ADC_SQR3_SQ3_3      (0x08UL << ADC_SQR3_SQ3_Pos)/*!< 0x00002000 */
#define ADC_SQR3_SQ3_4      (0x10UL << ADC_SQR3_SQ3_Pos)/*!< 0x00004000 */
#define ADC_SQR3_SQ4_Pos    (15U)
#define ADC_SQR3_SQ4_Msk    (0x1FUL << ADC_SQR3_SQ4_Pos)/*!< 0x000F8000 */
#define ADC_SQR3_SQ4        ADC_SQR3_SQ4_Msk/*!<SQ4[4:0] bits (4th conversion in regular sequence) */
#define ADC_SQR3_SQ4_0      (0x01UL << ADC_SQR3_SQ4_Pos)/*!< 0x00008000 */
#define ADC_SQR3_SQ4_1      (0x02UL << ADC_SQR3_SQ4_Pos)/*!< 0x00010000 */
#define ADC_SQR3_SQ4_2      (0x04UL << ADC_SQR3_SQ4_Pos)/*!< 0x00020000 */
#define ADC_SQR3_SQ4_3      (0x08UL << ADC_SQR3_SQ4_Pos)/*!< 0x00040000 */
#define ADC_SQR3_SQ4_4      (0x10UL << ADC_SQR3_SQ4_Pos)/*!< 0x00080000 */
#define ADC_SQR3_SQ5_Pos    (20U)
#define ADC_SQR3_SQ5_Msk    (0x1FUL << ADC_SQR3_SQ5_Pos)/*!< 0x01F00000 */
#define ADC_SQR3_SQ5        ADC_SQR3_SQ5_Msk/*!<SQ5[4:0] bits (5th conversion in regular sequence) */
#define ADC_SQR3_SQ5_0      (0x01UL << ADC_SQR3_SQ5_Pos)/*!< 0x00100000 */
#define ADC_SQR3_SQ5_1      (0x02UL << ADC_SQR3_SQ5_Pos)/*!< 0x00200000 */
#define ADC_SQR3_SQ5_2      (0x04UL << ADC_SQR3_SQ5_Pos)/*!< 0x00400000 */
#define ADC_SQR3_SQ5_3      (0x08UL << ADC_SQR3_SQ5_Pos)/*!< 0x00800000 */
#define ADC_SQR3_SQ5_4      (0x10UL << ADC_SQR3_SQ5_Pos)/*!< 0x01000000 */
#define ADC_SQR3_SQ6_Pos    (25U)
#define ADC_SQR3_SQ6_Msk    (0x1FUL << ADC_SQR3_SQ6_Pos)/*!< 0x3E000000 */
#define ADC_SQR3_SQ6        ADC_SQR3_SQ6_Msk/*!<SQ6[4:0] bits (6th conversion in regular sequence) */
#define ADC_SQR3_SQ6_0      (0x01UL << ADC_SQR3_SQ6_Pos)/*!< 0x02000000 */
#define ADC_SQR3_SQ6_1      (0x02UL << ADC_SQR3_SQ6_Pos)/*!< 0x04000000 */
#define ADC_SQR3_SQ6_2      (0x04UL << ADC_SQR3_SQ6_Pos)/*!< 0x08000000 */
#define ADC_SQR3_SQ6_3      (0x08UL << ADC_SQR3_SQ6_Pos)/*!< 0x10000000 */
#define ADC_SQR3_SQ6_4      (0x10UL << ADC_SQR3_SQ6_Pos)/*!< 0x20000000 */

/*******************  Bit definition for ADC_JSQR register  *******************/
#define ADC_JSQR_JSQ1_Pos    (0U)
#define ADC_JSQR_JSQ1_Msk    (0x1FUL << ADC_JSQR_JSQ1_Pos)	/*!< 0x0000001F */
#define ADC_JSQR_JSQ1        ADC_JSQR_JSQ1_Msk				/*!<JSQ1[4:0] bits (1st conversion in injected sequence) */
#define ADC_JSQR_JSQ1_0      (0x01UL << ADC_JSQR_JSQ1_Pos)	/*!< 0x00000001 */
#define ADC_JSQR_JSQ1_1      (0x02UL << ADC_JSQR_JSQ1_Pos)	/*!< 0x00000002 */
#define ADC_JSQR_JSQ1_2      (0x04UL << ADC_JSQR_JSQ1_Pos)	/*!< 0x00000004 */
#define ADC_JSQR_JSQ1_3      (0x08UL << ADC_JSQR_JSQ1_Pos)	/*!< 0x00000008 */
#define ADC_JSQR_JSQ1_4      (0x10UL << ADC_JSQR_JSQ1_Pos)	/*!< 0x00000010 */
#define ADC_JSQR_JSQ2_Pos    (5U)
#define ADC_JSQR_JSQ2_Msk    (0x1FUL << ADC_JSQR_JSQ2_Pos)	/*!< 0x000003E0 */
#define ADC_JSQR_JSQ2        ADC_JSQR_JSQ2_Msk				/*!<JSQ2[4:0] bits (2nd conversion in injected sequence) */
#define ADC_JSQR_JSQ2_0      (0x01UL << ADC_JSQR_JSQ2_Pos)	/*!< 0x00000020 */
#define ADC_JSQR_JSQ2_1      (0x02UL << ADC_JSQR_JSQ2_Pos)	/*!< 0x00000040 */
#define ADC_JSQR_JSQ2_2      (0x04UL << ADC_JSQR_JSQ2_Pos)	/*!< 0x00000080 */
#define ADC_JSQR_JSQ2_3      (0x08UL << ADC_JSQR_JSQ2_Pos)	/*!< 0x00000100 */
#define ADC_JSQR_JSQ2_4      (0x10UL << ADC_JSQR_JSQ2_Pos)	/*!< 0x00000200 */
#define ADC_JSQR_JSQ3_Pos    (10U)
#define ADC_JSQR_JSQ3_Msk    (0x1FUL << ADC_JSQR_JSQ3_Pos)	/*!< 0x00007C00 */
#define ADC_JSQR_JSQ3        ADC_JSQR_JSQ3_Msk				/*!<JSQ3[4:0] bits (3rd conversion in injected sequence) */
#define ADC_JSQR_JSQ3_0      (0x01UL << ADC_JSQR_JSQ3_Pos)	/*!< 0x00000400 */
#define ADC_JSQR_JSQ3_1      (0x02UL << ADC_JSQR_JSQ3_Pos)	/*!< 0x00000800 */
#define ADC_JSQR_JSQ3_2      (0x04UL << ADC_JSQR_JSQ3_Pos)	/*!< 0x00001000 */
#define ADC_JSQR_JSQ3_3      (0x08UL << ADC_JSQR_JSQ3_Pos)	/*!< 0x00002000 */
#define ADC_JSQR_JSQ3_4      (0x10UL << ADC_JSQR_JSQ3_Pos)	/*!< 0x00004000 */
#define ADC_JSQR_JSQ4_Pos    (15U)
#define ADC_JSQR_JSQ4_Msk    (0x1FUL << ADC_JSQR_JSQ4_Pos)	/*!< 0x000F8000 */
#define ADC_JSQR_JSQ4        ADC_JSQR_JSQ4_Msk				/*!<JSQ4[4:0] bits (4th conversion in injected sequence) */
#define ADC_JSQR_JSQ4_0      (0x01UL << ADC_JSQR_JSQ4_Pos)	/*!< 0x00008000 */
#define ADC_JSQR_JSQ4_1      (0x02UL << ADC_JSQR_JSQ4_Pos)	/*!< 0x00010000 */
#define ADC_JSQR_JSQ4_2      (0x04UL << ADC_JSQR_JSQ4_Pos)	/*!< 0x00020000 */
#define ADC_JSQR_JSQ4_3      (0x08UL << ADC_JSQR_JSQ4_Pos)	/*!< 0x00040000 */
#define ADC_JSQR_JSQ4_4      (0x10UL << ADC_JSQR_JSQ4_Pos)	/*!< 0x00080000 */
#define ADC_JSQR_JL_Pos      (20U)
#define ADC_JSQR_JL_Msk      (0x3UL << ADC_JSQR_JL_Pos)	/*!< 0x00300000 */
#define ADC_JSQR_JL          ADC_JSQR_JL_Msk/*!<JL[1:0] bits (Injected Sequence length) */
#define ADC_JSQR_JL_0        (0x1UL << ADC_JSQR_JL_Pos)	/*!< 0x00100000 */
#define ADC_JSQR_JL_1        (0x2UL << ADC_JSQR_JL_Pos)	/*!< 0x00200000 */

/*******************  Bit definition for ADC_JDR1 register  *******************/
#define ADC_JDR1_JDATA    ((uint16_t) 0xFFFFU)	/*!<Injected data */

/*******************  Bit definition for ADC_JDR2 register  *******************/
#define ADC_JDR2_JDATA    ((uint16_t) 0xFFFFU)	/*!<Injected data */

/*******************  Bit definition for ADC_JDR3 register  *******************/
#define ADC_JDR3_JDATA    ((uint16_t) 0xFFFFU)	/*!<Injected data */

/*******************  Bit definition for ADC_JDR4 register  *******************/
#define ADC_JDR4_JDATA    ((uint16_t) 0xFFFFU)	/*!<Injected data */

/********************  Bit definition for ADC_DR register  ********************/
#define ADC_DR_DATA_Pos        (0U)
#define ADC_DR_DATA_Msk        (0xFFFFUL << ADC_DR_DATA_Pos)/*!< 0x0000FFFF */
#define ADC_DR_DATA            ADC_DR_DATA_Msk	/*!<Regular data */
#define ADC_DR_ADC2DATA_Pos    (16U)
#define ADC_DR_ADC2DATA_Msk    (0xFFFFUL << ADC_DR_ADC2DATA_Pos)/*!< 0xFFFF0000 */
#define ADC_DR_ADC2DATA        ADC_DR_ADC2DATA_Msk	/*!<ADC2 data */

/*******************  Bit definition for ADC_CSR register  ********************/
#define ADC_CSR_AWD1_Pos      (0U)
#define ADC_CSR_AWD1_Msk      (0x1UL << ADC_CSR_AWD1_Pos)	/*!< 0x00000001 */
#define ADC_CSR_AWD1          ADC_CSR_AWD1_Msk				/*!<ADC1 Analog watchdog flag               */
#define ADC_CSR_EOC1_Pos      (1U)
#define ADC_CSR_EOC1_Msk      (0x1UL << ADC_CSR_EOC1_Pos)	/*!< 0x00000002 */
#define ADC_CSR_EOC1          ADC_CSR_EOC1_Msk				/*!<ADC1 End of conversion                  */
#define ADC_CSR_JEOC1_Pos     (2U)
#define ADC_CSR_JEOC1_Msk     (0x1UL << ADC_CSR_JEOC1_Pos)	/*!< 0x00000004 */
#define ADC_CSR_JEOC1         ADC_CSR_JEOC1_Msk				/*!<ADC1 Injected channel end of conversion */
#define ADC_CSR_JSTRT1_Pos    (3U)
#define ADC_CSR_JSTRT1_Msk    (0x1UL << ADC_CSR_JSTRT1_Pos)	/*!< 0x00000008 */
#define ADC_CSR_JSTRT1        ADC_CSR_JSTRT1_Msk/*!<ADC1 Injected channel Start flag        */
#define ADC_CSR_STRT1_Pos     (4U)
#define ADC_CSR_STRT1_Msk     (0x1UL << ADC_CSR_STRT1_Pos)	/*!< 0x00000010 */
#define ADC_CSR_STRT1         ADC_CSR_STRT1_Msk				/*!<ADC1 Regular channel Start flag         */
#define ADC_CSR_OVR1_Pos      (5U)
#define ADC_CSR_OVR1_Msk      (0x1UL << ADC_CSR_OVR1_Pos)	/*!< 0x00000020 */
#define ADC_CSR_OVR1          ADC_CSR_OVR1_Msk				/*!<ADC1 Overrun flag                       */
#define ADC_CSR_AWD2_Pos      (8U)
#define ADC_CSR_AWD2_Msk      (0x1UL << ADC_CSR_AWD2_Pos)	/*!< 0x00000100 */
#define ADC_CSR_AWD2          ADC_CSR_AWD2_Msk				/*!<ADC2 Analog watchdog flag               */
#define ADC_CSR_EOC2_Pos      (9U)
#define ADC_CSR_EOC2_Msk      (0x1UL << ADC_CSR_EOC2_Pos)	/*!< 0x00000200 */
#define ADC_CSR_EOC2          ADC_CSR_EOC2_Msk				/*!<ADC2 End of conversion                  */
#define ADC_CSR_JEOC2_Pos     (10U)
#define ADC_CSR_JEOC2_Msk     (0x1UL << ADC_CSR_JEOC2_Pos)	/*!< 0x00000400 */
#define ADC_CSR_JEOC2         ADC_CSR_JEOC2_Msk				/*!<ADC2 Injected channel end of conversion */
#define ADC_CSR_JSTRT2_Pos    (11U)
#define ADC_CSR_JSTRT2_Msk    (0x1UL << ADC_CSR_JSTRT2_Pos)	/*!< 0x00000800 */
#define ADC_CSR_JSTRT2        ADC_CSR_JSTRT2_Msk/*!<ADC2 Injected channel Start flag        */
#define ADC_CSR_STRT2_Pos     (12U)
#define ADC_CSR_STRT2_Msk     (0x1UL << ADC_CSR_STRT2_Pos)	/*!< 0x00001000 */
#define ADC_CSR_STRT2         ADC_CSR_STRT2_Msk				/*!<ADC2 Regular channel Start flag         */
#define ADC_CSR_OVR2_Pos      (13U)
#define ADC_CSR_OVR2_Msk      (0x1UL << ADC_CSR_OVR2_Pos)	/*!< 0x00002000 */
#define ADC_CSR_OVR2          ADC_CSR_OVR2_Msk				/*!<ADC2 Overrun flag                       */
#define ADC_CSR_AWD3_Pos      (16U)
#define ADC_CSR_AWD3_Msk      (0x1UL << ADC_CSR_AWD3_Pos)	/*!< 0x00010000 */
#define ADC_CSR_AWD3          ADC_CSR_AWD3_Msk				/*!<ADC3 Analog watchdog flag               */
#define ADC_CSR_EOC3_Pos      (17U)
#define ADC_CSR_EOC3_Msk      (0x1UL << ADC_CSR_EOC3_Pos)	/*!< 0x00020000 */
#define ADC_CSR_EOC3          ADC_CSR_EOC3_Msk				/*!<ADC3 End of conversion                  */
#define ADC_CSR_JEOC3_Pos     (18U)
#define ADC_CSR_JEOC3_Msk     (0x1UL << ADC_CSR_JEOC3_Pos)	/*!< 0x00040000 */
#define ADC_CSR_JEOC3         ADC_CSR_JEOC3_Msk				/*!<ADC3 Injected channel end of conversion */
#define ADC_CSR_JSTRT3_Pos    (19U)
#define ADC_CSR_JSTRT3_Msk    (0x1UL << ADC_CSR_JSTRT3_Pos)	/*!< 0x00080000 */
#define ADC_CSR_JSTRT3        ADC_CSR_JSTRT3_Msk/*!<ADC3 Injected channel Start flag        */
#define ADC_CSR_STRT3_Pos     (20U)
#define ADC_CSR_STRT3_Msk     (0x1UL << ADC_CSR_STRT3_Pos)	/*!< 0x00100000 */
#define ADC_CSR_STRT3         ADC_CSR_STRT3_Msk				/*!<ADC3 Regular channel Start flag         */
#define ADC_CSR_OVR3_Pos      (21U)
#define ADC_CSR_OVR3_Msk      (0x1UL << ADC_CSR_OVR3_Pos)	/*!< 0x00200000 */
#define ADC_CSR_OVR3          ADC_CSR_OVR3_Msk				/*!<ADC3 Overrun flag                       */

/* Legacy defines */
#define  ADC_CSR_DOVR1    ADC_CSR_OVR1
#define  ADC_CSR_DOVR2    ADC_CSR_OVR2
#define  ADC_CSR_DOVR3    ADC_CSR_OVR3


/*******************  Bit definition for ADC_CCR register  ********************/
#define ADC_CCR_MULTI_Pos      (0U)
#define ADC_CCR_MULTI_Msk      (0x1FUL << ADC_CCR_MULTI_Pos)/*!< 0x0000001F */
#define ADC_CCR_MULTI          ADC_CCR_MULTI_Msk/*!<MULTI[4:0] bits (Multi-ADC mode selection) */
#define ADC_CCR_MULTI_0        (0x01UL << ADC_CCR_MULTI_Pos)/*!< 0x00000001 */
#define ADC_CCR_MULTI_1        (0x02UL << ADC_CCR_MULTI_Pos)/*!< 0x00000002 */
#define ADC_CCR_MULTI_2        (0x04UL << ADC_CCR_MULTI_Pos)/*!< 0x00000004 */
#define ADC_CCR_MULTI_3        (0x08UL << ADC_CCR_MULTI_Pos)/*!< 0x00000008 */
#define ADC_CCR_MULTI_4        (0x10UL << ADC_CCR_MULTI_Pos)/*!< 0x00000010 */
#define ADC_CCR_DELAY_Pos      (8U)
#define ADC_CCR_DELAY_Msk      (0xFUL << ADC_CCR_DELAY_Pos)	/*!< 0x00000F00 */
#define ADC_CCR_DELAY          ADC_CCR_DELAY_Msk/*!<DELAY[3:0] bits (Delay between 2 sampling phases) */
#define ADC_CCR_DELAY_0        (0x1UL << ADC_CCR_DELAY_Pos)	/*!< 0x00000100 */
#define ADC_CCR_DELAY_1        (0x2UL << ADC_CCR_DELAY_Pos)	/*!< 0x00000200 */
#define ADC_CCR_DELAY_2        (0x4UL << ADC_CCR_DELAY_Pos)	/*!< 0x00000400 */
#define ADC_CCR_DELAY_3        (0x8UL << ADC_CCR_DELAY_Pos)	/*!< 0x00000800 */
#define ADC_CCR_DDS_Pos        (13U)
#define ADC_CCR_DDS_Msk        (0x1UL << ADC_CCR_DDS_Pos)	/*!< 0x00002000 */
#define ADC_CCR_DDS            ADC_CCR_DDS_Msk				/*!<DMA disable selection (Multi-ADC mode) */
#define ADC_CCR_DMA_Pos        (14U)
#define ADC_CCR_DMA_Msk        (0x3UL << ADC_CCR_DMA_Pos)	/*!< 0x0000C000 */
#define ADC_CCR_DMA            ADC_CCR_DMA_Msk				/*!<DMA[1:0] bits (Direct Memory Access mode for multimode) */
#define ADC_CCR_DMA_0          (0x1UL << ADC_CCR_DMA_Pos)	/*!< 0x00004000 */
#define ADC_CCR_DMA_1          (0x2UL << ADC_CCR_DMA_Pos)	/*!< 0x00008000 */
#define ADC_CCR_ADCPRE_Pos     (16U)
#define ADC_CCR_ADCPRE_Msk     (0x3UL << ADC_CCR_ADCPRE_Pos)/*!< 0x00030000 */
#define ADC_CCR_ADCPRE         ADC_CCR_ADCPRE_Msk	/*!<ADCPRE[1:0] bits (ADC prescaler) */
#define ADC_CCR_ADCPRE_0       (0x1UL << ADC_CCR_ADCPRE_Pos)/*!< 0x00010000 */
#define ADC_CCR_ADCPRE_1       (0x2UL << ADC_CCR_ADCPRE_Pos)/*!< 0x00020000 */
#define ADC_CCR_VBATE_Pos      (22U)
#define ADC_CCR_VBATE_Msk      (0x1UL << ADC_CCR_VBATE_Pos)	/*!< 0x00400000 */
#define ADC_CCR_VBATE          ADC_CCR_VBATE_Msk/*!<VBAT Enable */
#define ADC_CCR_TSVREFE_Pos    (23U)
#define ADC_CCR_TSVREFE_Msk    (0x1UL << ADC_CCR_TSVREFE_Pos)	/*!< 0x00800000 */
#define ADC_CCR_TSVREFE        ADC_CCR_TSVREFE_Msk				/*!<Temperature Sensor and VREFINT Enable */

/*******************  Bit definition for ADC_CDR register  ********************/
#define ADC_CDR_DATA1_Pos    (0U)
#define ADC_CDR_DATA1_Msk    (0xFFFFUL << ADC_CDR_DATA1_Pos)/*!< 0x0000FFFF */
#define ADC_CDR_DATA1        ADC_CDR_DATA1_Msk	/*!<1st data of a pair of regular conversions */
#define ADC_CDR_DATA2_Pos    (16U)
#define ADC_CDR_DATA2_Msk    (0xFFFFUL << ADC_CDR_DATA2_Pos)/*!< 0xFFFF0000 */
#define ADC_CDR_DATA2        ADC_CDR_DATA2_Msk	/*!<2nd data of a pair of regular conversions */

/* Legacy defines */
#define ADC_CDR_RDATA_MST    ADC_CDR_DATA1
#define ADC_CDR_RDATA_SLV    ADC_CDR_DATA2

/******************************************************************************/
/*                                                                            */
/*                         Controller Area Network                            */
/*                                                                            */
/******************************************************************************/
/*!<CAN control and status registers */
/*******************  Bit definition for CAN_MCR register  ********************/
#define CAN_MCR_INRQ_Pos     (0U)
#define CAN_MCR_INRQ_Msk     (0x1UL << CAN_MCR_INRQ_Pos)/*!< 0x00000001 */
#define CAN_MCR_INRQ         CAN_MCR_INRQ_Msk	/*!<Initialization Request            */
#define CAN_MCR_SLEEP_Pos    (1U)
#define CAN_MCR_SLEEP_Msk    (0x1UL << CAN_MCR_SLEEP_Pos)	/*!< 0x00000002 */
#define CAN_MCR_SLEEP        CAN_MCR_SLEEP_Msk				/*!<Sleep Mode Request                */
#define CAN_MCR_TXFP_Pos     (2U)
#define CAN_MCR_TXFP_Msk     (0x1UL << CAN_MCR_TXFP_Pos)/*!< 0x00000004 */
#define CAN_MCR_TXFP         CAN_MCR_TXFP_Msk	/*!<Transmit FIFO Priority            */
#define CAN_MCR_RFLM_Pos     (3U)
#define CAN_MCR_RFLM_Msk     (0x1UL << CAN_MCR_RFLM_Pos)/*!< 0x00000008 */
#define CAN_MCR_RFLM         CAN_MCR_RFLM_Msk	/*!<Receive FIFO Locked Mode          */
#define CAN_MCR_NART_Pos     (4U)
#define CAN_MCR_NART_Msk     (0x1UL << CAN_MCR_NART_Pos)/*!< 0x00000010 */
#define CAN_MCR_NART         CAN_MCR_NART_Msk	/*!<No Automatic Retransmission       */
#define CAN_MCR_AWUM_Pos     (5U)
#define CAN_MCR_AWUM_Msk     (0x1UL << CAN_MCR_AWUM_Pos)/*!< 0x00000020 */
#define CAN_MCR_AWUM         CAN_MCR_AWUM_Msk	/*!<Automatic Wakeup Mode             */
#define CAN_MCR_ABOM_Pos     (6U)
#define CAN_MCR_ABOM_Msk     (0x1UL << CAN_MCR_ABOM_Pos)/*!< 0x00000040 */
#define CAN_MCR_ABOM         CAN_MCR_ABOM_Msk	/*!<Automatic Bus-Off Management      */
#define CAN_MCR_TTCM_Pos     (7U)
#define CAN_MCR_TTCM_Msk     (0x1UL << CAN_MCR_TTCM_Pos)/*!< 0x00000080 */
#define CAN_MCR_TTCM         CAN_MCR_TTCM_Msk	/*!<Time Triggered Communication Mode */
#define CAN_MCR_RESET_Pos    (15U)
#define CAN_MCR_RESET_Msk    (0x1UL << CAN_MCR_RESET_Pos)	/*!< 0x00008000 */
#define CAN_MCR_RESET        CAN_MCR_RESET_Msk				/*!<bxCAN software master reset       */

/*******************  Bit definition for CAN_MSR register  ********************/
#define CAN_MSR_INAK_Pos     (0U)
#define CAN_MSR_INAK_Msk     (0x1UL << CAN_MSR_INAK_Pos)/*!< 0x00000001 */
#define CAN_MSR_INAK         CAN_MSR_INAK_Msk	/*!<Initialization Acknowledge  */
#define CAN_MSR_SLAK_Pos     (1U)
#define CAN_MSR_SLAK_Msk     (0x1UL << CAN_MSR_SLAK_Pos)/*!< 0x00000002 */
#define CAN_MSR_SLAK         CAN_MSR_SLAK_Msk	/*!<Sleep Acknowledge           */
#define CAN_MSR_ERRI_Pos     (2U)
#define CAN_MSR_ERRI_Msk     (0x1UL << CAN_MSR_ERRI_Pos)/*!< 0x00000004 */
#define CAN_MSR_ERRI         CAN_MSR_ERRI_Msk	/*!<Error Interrupt             */
#define CAN_MSR_WKUI_Pos     (3U)
#define CAN_MSR_WKUI_Msk     (0x1UL << CAN_MSR_WKUI_Pos)/*!< 0x00000008 */
#define CAN_MSR_WKUI         CAN_MSR_WKUI_Msk	/*!<Wakeup Interrupt            */
#define CAN_MSR_SLAKI_Pos    (4U)
#define CAN_MSR_SLAKI_Msk    (0x1UL << CAN_MSR_SLAKI_Pos)	/*!< 0x00000010 */
#define CAN_MSR_SLAKI        CAN_MSR_SLAKI_Msk				/*!<Sleep Acknowledge Interrupt */
#define CAN_MSR_TXM_Pos      (8U)
#define CAN_MSR_TXM_Msk      (0x1UL << CAN_MSR_TXM_Pos)	/*!< 0x00000100 */
#define CAN_MSR_TXM          CAN_MSR_TXM_Msk/*!<Transmit Mode               */
#define CAN_MSR_RXM_Pos      (9U)
#define CAN_MSR_RXM_Msk      (0x1UL << CAN_MSR_RXM_Pos)	/*!< 0x00000200 */
#define CAN_MSR_RXM          CAN_MSR_RXM_Msk/*!<Receive Mode                */
#define CAN_MSR_SAMP_Pos     (10U)
#define CAN_MSR_SAMP_Msk     (0x1UL << CAN_MSR_SAMP_Pos)/*!< 0x00000400 */
#define CAN_MSR_SAMP         CAN_MSR_SAMP_Msk	/*!<Last Sample Point           */
#define CAN_MSR_RX_Pos       (11U)
#define CAN_MSR_RX_Msk       (0x1UL << CAN_MSR_RX_Pos)	/*!< 0x00000800 */
#define CAN_MSR_RX           CAN_MSR_RX_Msk				/*!<CAN Rx Signal               */

/*******************  Bit definition for CAN_TSR register  ********************/
#define CAN_TSR_RQCP0_Pos    (0U)
#define CAN_TSR_RQCP0_Msk    (0x1UL << CAN_TSR_RQCP0_Pos)	/*!< 0x00000001 */
#define CAN_TSR_RQCP0        CAN_TSR_RQCP0_Msk				/*!<Request Completed Mailbox0      */
#define CAN_TSR_TXOK0_Pos    (1U)
#define CAN_TSR_TXOK0_Msk    (0x1UL << CAN_TSR_TXOK0_Pos)	/*!< 0x00000002 */
#define CAN_TSR_TXOK0        CAN_TSR_TXOK0_Msk				/*!<Transmission OK of Mailbox0     */
#define CAN_TSR_ALST0_Pos    (2U)
#define CAN_TSR_ALST0_Msk    (0x1UL << CAN_TSR_ALST0_Pos)	/*!< 0x00000004 */
#define CAN_TSR_ALST0        CAN_TSR_ALST0_Msk				/*!<Arbitration Lost for Mailbox0   */
#define CAN_TSR_TERR0_Pos    (3U)
#define CAN_TSR_TERR0_Msk    (0x1UL << CAN_TSR_TERR0_Pos)	/*!< 0x00000008 */
#define CAN_TSR_TERR0        CAN_TSR_TERR0_Msk				/*!<Transmission Error of Mailbox0  */
#define CAN_TSR_ABRQ0_Pos    (7U)
#define CAN_TSR_ABRQ0_Msk    (0x1UL << CAN_TSR_ABRQ0_Pos)	/*!< 0x00000080 */
#define CAN_TSR_ABRQ0        CAN_TSR_ABRQ0_Msk				/*!<Abort Request for Mailbox0      */
#define CAN_TSR_RQCP1_Pos    (8U)
#define CAN_TSR_RQCP1_Msk    (0x1UL << CAN_TSR_RQCP1_Pos)	/*!< 0x00000100 */
#define CAN_TSR_RQCP1        CAN_TSR_RQCP1_Msk				/*!<Request Completed Mailbox1      */
#define CAN_TSR_TXOK1_Pos    (9U)
#define CAN_TSR_TXOK1_Msk    (0x1UL << CAN_TSR_TXOK1_Pos)	/*!< 0x00000200 */
#define CAN_TSR_TXOK1        CAN_TSR_TXOK1_Msk				/*!<Transmission OK of Mailbox1     */
#define CAN_TSR_ALST1_Pos    (10U)
#define CAN_TSR_ALST1_Msk    (0x1UL << CAN_TSR_ALST1_Pos)	/*!< 0x00000400 */
#define CAN_TSR_ALST1        CAN_TSR_ALST1_Msk				/*!<Arbitration Lost for Mailbox1   */
#define CAN_TSR_TERR1_Pos    (11U)
#define CAN_TSR_TERR1_Msk    (0x1UL << CAN_TSR_TERR1_Pos)	/*!< 0x00000800 */
#define CAN_TSR_TERR1        CAN_TSR_TERR1_Msk				/*!<Transmission Error of Mailbox1  */
#define CAN_TSR_ABRQ1_Pos    (15U)
#define CAN_TSR_ABRQ1_Msk    (0x1UL << CAN_TSR_ABRQ1_Pos)	/*!< 0x00008000 */
#define CAN_TSR_ABRQ1        CAN_TSR_ABRQ1_Msk				/*!<Abort Request for Mailbox 1     */
#define CAN_TSR_RQCP2_Pos    (16U)
#define CAN_TSR_RQCP2_Msk    (0x1UL << CAN_TSR_RQCP2_Pos)	/*!< 0x00010000 */
#define CAN_TSR_RQCP2        CAN_TSR_RQCP2_Msk				/*!<Request Completed Mailbox2      */
#define CAN_TSR_TXOK2_Pos    (17U)
#define CAN_TSR_TXOK2_Msk    (0x1UL << CAN_TSR_TXOK2_Pos)	/*!< 0x00020000 */
#define CAN_TSR_TXOK2        CAN_TSR_TXOK2_Msk				/*!<Transmission OK of Mailbox 2    */
#define CAN_TSR_ALST2_Pos    (18U)
#define CAN_TSR_ALST2_Msk    (0x1UL << CAN_TSR_ALST2_Pos)	/*!< 0x00040000 */
#define CAN_TSR_ALST2        CAN_TSR_ALST2_Msk				/*!<Arbitration Lost for mailbox 2  */
#define CAN_TSR_TERR2_Pos    (19U)
#define CAN_TSR_TERR2_Msk    (0x1UL << CAN_TSR_TERR2_Pos)	/*!< 0x00080000 */
#define CAN_TSR_TERR2        CAN_TSR_TERR2_Msk				/*!<Transmission Error of Mailbox 2 */
#define CAN_TSR_ABRQ2_Pos    (23U)
#define CAN_TSR_ABRQ2_Msk    (0x1UL << CAN_TSR_ABRQ2_Pos)	/*!< 0x00800000 */
#define CAN_TSR_ABRQ2        CAN_TSR_ABRQ2_Msk				/*!<Abort Request for Mailbox 2     */
#define CAN_TSR_CODE_Pos     (24U)
#define CAN_TSR_CODE_Msk     (0x3UL << CAN_TSR_CODE_Pos)/*!< 0x03000000 */
#define CAN_TSR_CODE         CAN_TSR_CODE_Msk	/*!<Mailbox Code                    */

#define CAN_TSR_TME_Pos      (26U)
#define CAN_TSR_TME_Msk      (0x7UL << CAN_TSR_TME_Pos)	/*!< 0x1C000000 */
#define CAN_TSR_TME          CAN_TSR_TME_Msk/*!<TME[2:0] bits */
#define CAN_TSR_TME0_Pos     (26U)
#define CAN_TSR_TME0_Msk     (0x1UL << CAN_TSR_TME0_Pos)/*!< 0x04000000 */
#define CAN_TSR_TME0         CAN_TSR_TME0_Msk	/*!<Transmit Mailbox 0 Empty */
#define CAN_TSR_TME1_Pos     (27U)
#define CAN_TSR_TME1_Msk     (0x1UL << CAN_TSR_TME1_Pos)/*!< 0x08000000 */
#define CAN_TSR_TME1         CAN_TSR_TME1_Msk	/*!<Transmit Mailbox 1 Empty */
#define CAN_TSR_TME2_Pos     (28U)
#define CAN_TSR_TME2_Msk     (0x1UL << CAN_TSR_TME2_Pos)/*!< 0x10000000 */
#define CAN_TSR_TME2         CAN_TSR_TME2_Msk	/*!<Transmit Mailbox 2 Empty */

#define CAN_TSR_LOW_Pos      (29U)
#define CAN_TSR_LOW_Msk      (0x7UL << CAN_TSR_LOW_Pos)	/*!< 0xE0000000 */
#define CAN_TSR_LOW          CAN_TSR_LOW_Msk/*!<LOW[2:0] bits */
#define CAN_TSR_LOW0_Pos     (29U)
#define CAN_TSR_LOW0_Msk     (0x1UL << CAN_TSR_LOW0_Pos)/*!< 0x20000000 */
#define CAN_TSR_LOW0         CAN_TSR_LOW0_Msk	/*!<Lowest Priority Flag for Mailbox 0 */
#define CAN_TSR_LOW1_Pos     (30U)
#define CAN_TSR_LOW1_Msk     (0x1UL << CAN_TSR_LOW1_Pos)/*!< 0x40000000 */
#define CAN_TSR_LOW1         CAN_TSR_LOW1_Msk	/*!<Lowest Priority Flag for Mailbox 1 */
#define CAN_TSR_LOW2_Pos     (31U)
#define CAN_TSR_LOW2_Msk     (0x1UL << CAN_TSR_LOW2_Pos)/*!< 0x80000000 */
#define CAN_TSR_LOW2         CAN_TSR_LOW2_Msk	/*!<Lowest Priority Flag for Mailbox 2 */

/*******************  Bit definition for CAN_RF0R register  *******************/
#define CAN_RF0R_FMP0_Pos     (0U)
#define CAN_RF0R_FMP0_Msk     (0x3UL << CAN_RF0R_FMP0_Pos)	/*!< 0x00000003 */
#define CAN_RF0R_FMP0         CAN_RF0R_FMP0_Msk				/*!<FIFO 0 Message Pending        */
#define CAN_RF0R_FULL0_Pos    (3U)
#define CAN_RF0R_FULL0_Msk    (0x1UL << CAN_RF0R_FULL0_Pos)	/*!< 0x00000008 */
#define CAN_RF0R_FULL0        CAN_RF0R_FULL0_Msk/*!<FIFO 0 Full                   */
#define CAN_RF0R_FOVR0_Pos    (4U)
#define CAN_RF0R_FOVR0_Msk    (0x1UL << CAN_RF0R_FOVR0_Pos)	/*!< 0x00000010 */
#define CAN_RF0R_FOVR0        CAN_RF0R_FOVR0_Msk/*!<FIFO 0 Overrun                */
#define CAN_RF0R_RFOM0_Pos    (5U)
#define CAN_RF0R_RFOM0_Msk    (0x1UL << CAN_RF0R_RFOM0_Pos)	/*!< 0x00000020 */
#define CAN_RF0R_RFOM0        CAN_RF0R_RFOM0_Msk/*!<Release FIFO 0 Output Mailbox */

/*******************  Bit definition for CAN_RF1R register  *******************/
#define CAN_RF1R_FMP1_Pos     (0U)
#define CAN_RF1R_FMP1_Msk     (0x3UL << CAN_RF1R_FMP1_Pos)	/*!< 0x00000003 */
#define CAN_RF1R_FMP1         CAN_RF1R_FMP1_Msk				/*!<FIFO 1 Message Pending        */
#define CAN_RF1R_FULL1_Pos    (3U)
#define CAN_RF1R_FULL1_Msk    (0x1UL << CAN_RF1R_FULL1_Pos)	/*!< 0x00000008 */
#define CAN_RF1R_FULL1        CAN_RF1R_FULL1_Msk/*!<FIFO 1 Full                   */
#define CAN_RF1R_FOVR1_Pos    (4U)
#define CAN_RF1R_FOVR1_Msk    (0x1UL << CAN_RF1R_FOVR1_Pos)	/*!< 0x00000010 */
#define CAN_RF1R_FOVR1        CAN_RF1R_FOVR1_Msk/*!<FIFO 1 Overrun                */
#define CAN_RF1R_RFOM1_Pos    (5U)
#define CAN_RF1R_RFOM1_Msk    (0x1UL << CAN_RF1R_RFOM1_Pos)	/*!< 0x00000020 */
#define CAN_RF1R_RFOM1        CAN_RF1R_RFOM1_Msk/*!<Release FIFO 1 Output Mailbox */

/********************  Bit definition for CAN_IER register  *******************/
#define CAN_IER_TMEIE_Pos     (0U)
#define CAN_IER_TMEIE_Msk     (0x1UL << CAN_IER_TMEIE_Pos)	/*!< 0x00000001 */
#define CAN_IER_TMEIE         CAN_IER_TMEIE_Msk				/*!<Transmit Mailbox Empty Interrupt Enable */
#define CAN_IER_FMPIE0_Pos    (1U)
#define CAN_IER_FMPIE0_Msk    (0x1UL << CAN_IER_FMPIE0_Pos)	/*!< 0x00000002 */
#define CAN_IER_FMPIE0        CAN_IER_FMPIE0_Msk/*!<FIFO Message Pending Interrupt Enable   */
#define CAN_IER_FFIE0_Pos     (2U)
#define CAN_IER_FFIE0_Msk     (0x1UL << CAN_IER_FFIE0_Pos)	/*!< 0x00000004 */
#define CAN_IER_FFIE0         CAN_IER_FFIE0_Msk				/*!<FIFO Full Interrupt Enable              */
#define CAN_IER_FOVIE0_Pos    (3U)
#define CAN_IER_FOVIE0_Msk    (0x1UL << CAN_IER_FOVIE0_Pos)	/*!< 0x00000008 */
#define CAN_IER_FOVIE0        CAN_IER_FOVIE0_Msk/*!<FIFO Overrun Interrupt Enable           */
#define CAN_IER_FMPIE1_Pos    (4U)
#define CAN_IER_FMPIE1_Msk    (0x1UL << CAN_IER_FMPIE1_Pos)	/*!< 0x00000010 */
#define CAN_IER_FMPIE1        CAN_IER_FMPIE1_Msk/*!<FIFO Message Pending Interrupt Enable   */
#define CAN_IER_FFIE1_Pos     (5U)
#define CAN_IER_FFIE1_Msk     (0x1UL << CAN_IER_FFIE1_Pos)	/*!< 0x00000020 */
#define CAN_IER_FFIE1         CAN_IER_FFIE1_Msk				/*!<FIFO Full Interrupt Enable              */
#define CAN_IER_FOVIE1_Pos    (6U)
#define CAN_IER_FOVIE1_Msk    (0x1UL << CAN_IER_FOVIE1_Pos)	/*!< 0x00000040 */
#define CAN_IER_FOVIE1        CAN_IER_FOVIE1_Msk/*!<FIFO Overrun Interrupt Enable           */
#define CAN_IER_EWGIE_Pos     (8U)
#define CAN_IER_EWGIE_Msk     (0x1UL << CAN_IER_EWGIE_Pos)	/*!< 0x00000100 */
#define CAN_IER_EWGIE         CAN_IER_EWGIE_Msk				/*!<Error Warning Interrupt Enable          */
#define CAN_IER_EPVIE_Pos     (9U)
#define CAN_IER_EPVIE_Msk     (0x1UL << CAN_IER_EPVIE_Pos)	/*!< 0x00000200 */
#define CAN_IER_EPVIE         CAN_IER_EPVIE_Msk				/*!<Error Passive Interrupt Enable          */
#define CAN_IER_BOFIE_Pos     (10U)
#define CAN_IER_BOFIE_Msk     (0x1UL << CAN_IER_BOFIE_Pos)	/*!< 0x00000400 */
#define CAN_IER_BOFIE         CAN_IER_BOFIE_Msk				/*!<Bus-Off Interrupt Enable                */
#define CAN_IER_LECIE_Pos     (11U)
#define CAN_IER_LECIE_Msk     (0x1UL << CAN_IER_LECIE_Pos)	/*!< 0x00000800 */
#define CAN_IER_LECIE         CAN_IER_LECIE_Msk				/*!<Last Error Code Interrupt Enable        */
#define CAN_IER_ERRIE_Pos     (15U)
#define CAN_IER_ERRIE_Msk     (0x1UL << CAN_IER_ERRIE_Pos)	/*!< 0x00008000 */
#define CAN_IER_ERRIE         CAN_IER_ERRIE_Msk				/*!<Error Interrupt Enable                  */
#define CAN_IER_WKUIE_Pos     (16U)
#define CAN_IER_WKUIE_Msk     (0x1UL << CAN_IER_WKUIE_Pos)	/*!< 0x00010000 */
#define CAN_IER_WKUIE         CAN_IER_WKUIE_Msk				/*!<Wakeup Interrupt Enable                 */
#define CAN_IER_SLKIE_Pos     (17U)
#define CAN_IER_SLKIE_Msk     (0x1UL << CAN_IER_SLKIE_Pos)	/*!< 0x00020000 */
#define CAN_IER_SLKIE         CAN_IER_SLKIE_Msk				/*!<Sleep Interrupt Enable                  */

/********************  Bit definition for CAN_ESR register  *******************/
#define CAN_ESR_EWGF_Pos    (0U)
#define CAN_ESR_EWGF_Msk    (0x1UL << CAN_ESR_EWGF_Pos)	/*!< 0x00000001 */
#define CAN_ESR_EWGF        CAN_ESR_EWGF_Msk/*!<Error Warning Flag */
#define CAN_ESR_EPVF_Pos    (1U)
#define CAN_ESR_EPVF_Msk    (0x1UL << CAN_ESR_EPVF_Pos)	/*!< 0x00000002 */
#define CAN_ESR_EPVF        CAN_ESR_EPVF_Msk/*!<Error Passive Flag */
#define CAN_ESR_BOFF_Pos    (2U)
#define CAN_ESR_BOFF_Msk    (0x1UL << CAN_ESR_BOFF_Pos)	/*!< 0x00000004 */
#define CAN_ESR_BOFF        CAN_ESR_BOFF_Msk/*!<Bus-Off Flag */

#define CAN_ESR_LEC_Pos     (4U)
#define CAN_ESR_LEC_Msk     (0x7UL << CAN_ESR_LEC_Pos)	/*!< 0x00000070 */
#define CAN_ESR_LEC         CAN_ESR_LEC_Msk				/*!<LEC[2:0] bits (Last Error Code) */
#define CAN_ESR_LEC_0       (0x1UL << CAN_ESR_LEC_Pos)	/*!< 0x00000010 */
#define CAN_ESR_LEC_1       (0x2UL << CAN_ESR_LEC_Pos)	/*!< 0x00000020 */
#define CAN_ESR_LEC_2       (0x4UL << CAN_ESR_LEC_Pos)	/*!< 0x00000040 */

#define CAN_ESR_TEC_Pos     (16U)
#define CAN_ESR_TEC_Msk     (0xFFUL << CAN_ESR_TEC_Pos)	/*!< 0x00FF0000 */
#define CAN_ESR_TEC         CAN_ESR_TEC_Msk				/*!<Least significant byte of the 9-bit Transmit Error Counter */
#define CAN_ESR_REC_Pos     (24U)
#define CAN_ESR_REC_Msk     (0xFFUL << CAN_ESR_REC_Pos)	/*!< 0xFF000000 */
#define CAN_ESR_REC         CAN_ESR_REC_Msk				/*!<Receive Error Counter */

/*******************  Bit definition for CAN_BTR register  ********************/
#define CAN_BTR_BRP_Pos     (0U)
#define CAN_BTR_BRP_Msk     (0x3FFUL << CAN_BTR_BRP_Pos)/*!< 0x000003FF */
#define CAN_BTR_BRP         CAN_BTR_BRP_Msk	/*!<Baud Rate Prescaler           */
#define CAN_BTR_TS1_Pos     (16U)
#define CAN_BTR_TS1_Msk     (0xFUL << CAN_BTR_TS1_Pos)	/*!< 0x000F0000 */
#define CAN_BTR_TS1         CAN_BTR_TS1_Msk				/*!<Time Segment 1                */
#define CAN_BTR_TS1_0       (0x1UL << CAN_BTR_TS1_Pos)	/*!< 0x00010000 */
#define CAN_BTR_TS1_1       (0x2UL << CAN_BTR_TS1_Pos)	/*!< 0x00020000 */
#define CAN_BTR_TS1_2       (0x4UL << CAN_BTR_TS1_Pos)	/*!< 0x00040000 */
#define CAN_BTR_TS1_3       (0x8UL << CAN_BTR_TS1_Pos)	/*!< 0x00080000 */
#define CAN_BTR_TS2_Pos     (20U)
#define CAN_BTR_TS2_Msk     (0x7UL << CAN_BTR_TS2_Pos)	/*!< 0x00700000 */
#define CAN_BTR_TS2         CAN_BTR_TS2_Msk				/*!<Time Segment 2                */
#define CAN_BTR_TS2_0       (0x1UL << CAN_BTR_TS2_Pos)	/*!< 0x00100000 */
#define CAN_BTR_TS2_1       (0x2UL << CAN_BTR_TS2_Pos)	/*!< 0x00200000 */
#define CAN_BTR_TS2_2       (0x4UL << CAN_BTR_TS2_Pos)	/*!< 0x00400000 */
#define CAN_BTR_SJW_Pos     (24U)
#define CAN_BTR_SJW_Msk     (0x3UL << CAN_BTR_SJW_Pos)	/*!< 0x03000000 */
#define CAN_BTR_SJW         CAN_BTR_SJW_Msk				/*!<Resynchronization Jump Width  */
#define CAN_BTR_SJW_0       (0x1UL << CAN_BTR_SJW_Pos)	/*!< 0x01000000 */
#define CAN_BTR_SJW_1       (0x2UL << CAN_BTR_SJW_Pos)	/*!< 0x02000000 */
#define CAN_BTR_LBKM_Pos    (30U)
#define CAN_BTR_LBKM_Msk    (0x1UL << CAN_BTR_LBKM_Pos)	/*!< 0x40000000 */
#define CAN_BTR_LBKM        CAN_BTR_LBKM_Msk/*!<Loop Back Mode (Debug)        */
#define CAN_BTR_SILM_Pos    (31U)
#define CAN_BTR_SILM_Msk    (0x1UL << CAN_BTR_SILM_Pos)	/*!< 0x80000000 */
#define CAN_BTR_SILM        CAN_BTR_SILM_Msk/*!<Silent Mode                   */

/*!<Mailbox registers */
/******************  Bit definition for CAN_TI0R register  ********************/
#define CAN_TI0R_TXRQ_Pos    (0U)
#define CAN_TI0R_TXRQ_Msk    (0x1UL << CAN_TI0R_TXRQ_Pos)	/*!< 0x00000001 */
#define CAN_TI0R_TXRQ        CAN_TI0R_TXRQ_Msk				/*!<Transmit Mailbox Request                   */
#define CAN_TI0R_RTR_Pos     (1U)
#define CAN_TI0R_RTR_Msk     (0x1UL << CAN_TI0R_RTR_Pos)/*!< 0x00000002 */
#define CAN_TI0R_RTR         CAN_TI0R_RTR_Msk	/*!<Remote Transmission Request                */
#define CAN_TI0R_IDE_Pos     (2U)
#define CAN_TI0R_IDE_Msk     (0x1UL << CAN_TI0R_IDE_Pos)/*!< 0x00000004 */
#define CAN_TI0R_IDE         CAN_TI0R_IDE_Msk	/*!<Identifier Extension                       */
#define CAN_TI0R_EXID_Pos    (3U)
#define CAN_TI0R_EXID_Msk    (0x3FFFFUL << CAN_TI0R_EXID_Pos)	/*!< 0x001FFFF8 */
#define CAN_TI0R_EXID        CAN_TI0R_EXID_Msk					/*!<Extended Identifier                        */
#define CAN_TI0R_STID_Pos    (21U)
#define CAN_TI0R_STID_Msk    (0x7FFUL << CAN_TI0R_STID_Pos)	/*!< 0xFFE00000 */
#define CAN_TI0R_STID        CAN_TI0R_STID_Msk				/*!<Standard Identifier or Extended Identifier */

/******************  Bit definition for CAN_TDT0R register  *******************/
#define CAN_TDT0R_DLC_Pos     (0U)
#define CAN_TDT0R_DLC_Msk     (0xFUL << CAN_TDT0R_DLC_Pos)	/*!< 0x0000000F */
#define CAN_TDT0R_DLC         CAN_TDT0R_DLC_Msk				/*!<Data Length Code     */
#define CAN_TDT0R_TGT_Pos     (8U)
#define CAN_TDT0R_TGT_Msk     (0x1UL << CAN_TDT0R_TGT_Pos)	/*!< 0x00000100 */
#define CAN_TDT0R_TGT         CAN_TDT0R_TGT_Msk				/*!<Transmit Global Time */
#define CAN_TDT0R_TIME_Pos    (16U)
#define CAN_TDT0R_TIME_Msk    (0xFFFFUL << CAN_TDT0R_TIME_Pos)	/*!< 0xFFFF0000 */
#define CAN_TDT0R_TIME        CAN_TDT0R_TIME_Msk				/*!<Message Time Stamp   */

/******************  Bit definition for CAN_TDL0R register  *******************/
#define CAN_TDL0R_DATA0_Pos    (0U)
#define CAN_TDL0R_DATA0_Msk    (0xFFUL << CAN_TDL0R_DATA0_Pos)	/*!< 0x000000FF */
#define CAN_TDL0R_DATA0        CAN_TDL0R_DATA0_Msk				/*!<Data byte 0 */
#define CAN_TDL0R_DATA1_Pos    (8U)
#define CAN_TDL0R_DATA1_Msk    (0xFFUL << CAN_TDL0R_DATA1_Pos)	/*!< 0x0000FF00 */
#define CAN_TDL0R_DATA1        CAN_TDL0R_DATA1_Msk				/*!<Data byte 1 */
#define CAN_TDL0R_DATA2_Pos    (16U)
#define CAN_TDL0R_DATA2_Msk    (0xFFUL << CAN_TDL0R_DATA2_Pos)	/*!< 0x00FF0000 */
#define CAN_TDL0R_DATA2        CAN_TDL0R_DATA2_Msk				/*!<Data byte 2 */
#define CAN_TDL0R_DATA3_Pos    (24U)
#define CAN_TDL0R_DATA3_Msk    (0xFFUL << CAN_TDL0R_DATA3_Pos)	/*!< 0xFF000000 */
#define CAN_TDL0R_DATA3        CAN_TDL0R_DATA3_Msk				/*!<Data byte 3 */

/******************  Bit definition for CAN_TDH0R register  *******************/
#define CAN_TDH0R_DATA4_Pos    (0U)
#define CAN_TDH0R_DATA4_Msk    (0xFFUL << CAN_TDH0R_DATA4_Pos)	/*!< 0x000000FF */
#define CAN_TDH0R_DATA4        CAN_TDH0R_DATA4_Msk				/*!<Data byte 4 */
#define CAN_TDH0R_DATA5_Pos    (8U)
#define CAN_TDH0R_DATA5_Msk    (0xFFUL << CAN_TDH0R_DATA5_Pos)	/*!< 0x0000FF00 */
#define CAN_TDH0R_DATA5        CAN_TDH0R_DATA5_Msk				/*!<Data byte 5 */
#define CAN_TDH0R_DATA6_Pos    (16U)
#define CAN_TDH0R_DATA6_Msk    (0xFFUL << CAN_TDH0R_DATA6_Pos)	/*!< 0x00FF0000 */
#define CAN_TDH0R_DATA6        CAN_TDH0R_DATA6_Msk				/*!<Data byte 6 */
#define CAN_TDH0R_DATA7_Pos    (24U)
#define CAN_TDH0R_DATA7_Msk    (0xFFUL << CAN_TDH0R_DATA7_Pos)	/*!< 0xFF000000 */
#define CAN_TDH0R_DATA7        CAN_TDH0R_DATA7_Msk				/*!<Data byte 7 */

/*******************  Bit definition for CAN_TI1R register  *******************/
#define CAN_TI1R_TXRQ_Pos    (0U)
#define CAN_TI1R_TXRQ_Msk    (0x1UL << CAN_TI1R_TXRQ_Pos)	/*!< 0x00000001 */
#define CAN_TI1R_TXRQ        CAN_TI1R_TXRQ_Msk				/*!<Transmit Mailbox Request                   */
#define CAN_TI1R_RTR_Pos     (1U)
#define CAN_TI1R_RTR_Msk     (0x1UL << CAN_TI1R_RTR_Pos)/*!< 0x00000002 */
#define CAN_TI1R_RTR         CAN_TI1R_RTR_Msk	/*!<Remote Transmission Request                */
#define CAN_TI1R_IDE_Pos     (2U)
#define CAN_TI1R_IDE_Msk     (0x1UL << CAN_TI1R_IDE_Pos)/*!< 0x00000004 */
#define CAN_TI1R_IDE         CAN_TI1R_IDE_Msk	/*!<Identifier Extension                       */
#define CAN_TI1R_EXID_Pos    (3U)
#define CAN_TI1R_EXID_Msk    (0x3FFFFUL << CAN_TI1R_EXID_Pos)	/*!< 0x001FFFF8 */
#define CAN_TI1R_EXID        CAN_TI1R_EXID_Msk					/*!<Extended Identifier                        */
#define CAN_TI1R_STID_Pos    (21U)
#define CAN_TI1R_STID_Msk    (0x7FFUL << CAN_TI1R_STID_Pos)	/*!< 0xFFE00000 */
#define CAN_TI1R_STID        CAN_TI1R_STID_Msk				/*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDT1R register  ******************/
#define CAN_TDT1R_DLC_Pos     (0U)
#define CAN_TDT1R_DLC_Msk     (0xFUL << CAN_TDT1R_DLC_Pos)	/*!< 0x0000000F */
#define CAN_TDT1R_DLC         CAN_TDT1R_DLC_Msk				/*!<Data Length Code     */
#define CAN_TDT1R_TGT_Pos     (8U)
#define CAN_TDT1R_TGT_Msk     (0x1UL << CAN_TDT1R_TGT_Pos)	/*!< 0x00000100 */
#define CAN_TDT1R_TGT         CAN_TDT1R_TGT_Msk				/*!<Transmit Global Time */
#define CAN_TDT1R_TIME_Pos    (16U)
#define CAN_TDT1R_TIME_Msk    (0xFFFFUL << CAN_TDT1R_TIME_Pos)	/*!< 0xFFFF0000 */
#define CAN_TDT1R_TIME        CAN_TDT1R_TIME_Msk				/*!<Message Time Stamp   */

/*******************  Bit definition for CAN_TDL1R register  ******************/
#define CAN_TDL1R_DATA0_Pos    (0U)
#define CAN_TDL1R_DATA0_Msk    (0xFFUL << CAN_TDL1R_DATA0_Pos)	/*!< 0x000000FF */
#define CAN_TDL1R_DATA0        CAN_TDL1R_DATA0_Msk				/*!<Data byte 0 */
#define CAN_TDL1R_DATA1_Pos    (8U)
#define CAN_TDL1R_DATA1_Msk    (0xFFUL << CAN_TDL1R_DATA1_Pos)	/*!< 0x0000FF00 */
#define CAN_TDL1R_DATA1        CAN_TDL1R_DATA1_Msk				/*!<Data byte 1 */
#define CAN_TDL1R_DATA2_Pos    (16U)
#define CAN_TDL1R_DATA2_Msk    (0xFFUL << CAN_TDL1R_DATA2_Pos)	/*!< 0x00FF0000 */
#define CAN_TDL1R_DATA2        CAN_TDL1R_DATA2_Msk				/*!<Data byte 2 */
#define CAN_TDL1R_DATA3_Pos    (24U)
#define CAN_TDL1R_DATA3_Msk    (0xFFUL << CAN_TDL1R_DATA3_Pos)	/*!< 0xFF000000 */
#define CAN_TDL1R_DATA3        CAN_TDL1R_DATA3_Msk				/*!<Data byte 3 */

/*******************  Bit definition for CAN_TDH1R register  ******************/
#define CAN_TDH1R_DATA4_Pos    (0U)
#define CAN_TDH1R_DATA4_Msk    (0xFFUL << CAN_TDH1R_DATA4_Pos)	/*!< 0x000000FF */
#define CAN_TDH1R_DATA4        CAN_TDH1R_DATA4_Msk				/*!<Data byte 4 */
#define CAN_TDH1R_DATA5_Pos    (8U)
#define CAN_TDH1R_DATA5_Msk    (0xFFUL << CAN_TDH1R_DATA5_Pos)	/*!< 0x0000FF00 */
#define CAN_TDH1R_DATA5        CAN_TDH1R_DATA5_Msk				/*!<Data byte 5 */
#define CAN_TDH1R_DATA6_Pos    (16U)
#define CAN_TDH1R_DATA6_Msk    (0xFFUL << CAN_TDH1R_DATA6_Pos)	/*!< 0x00FF0000 */
#define CAN_TDH1R_DATA6        CAN_TDH1R_DATA6_Msk				/*!<Data byte 6 */
#define CAN_TDH1R_DATA7_Pos    (24U)
#define CAN_TDH1R_DATA7_Msk    (0xFFUL << CAN_TDH1R_DATA7_Pos)	/*!< 0xFF000000 */
#define CAN_TDH1R_DATA7        CAN_TDH1R_DATA7_Msk				/*!<Data byte 7 */

/*******************  Bit definition for CAN_TI2R register  *******************/
#define CAN_TI2R_TXRQ_Pos    (0U)
#define CAN_TI2R_TXRQ_Msk    (0x1UL << CAN_TI2R_TXRQ_Pos)	/*!< 0x00000001 */
#define CAN_TI2R_TXRQ        CAN_TI2R_TXRQ_Msk				/*!<Transmit Mailbox Request                   */
#define CAN_TI2R_RTR_Pos     (1U)
#define CAN_TI2R_RTR_Msk     (0x1UL << CAN_TI2R_RTR_Pos)/*!< 0x00000002 */
#define CAN_TI2R_RTR         CAN_TI2R_RTR_Msk	/*!<Remote Transmission Request                */
#define CAN_TI2R_IDE_Pos     (2U)
#define CAN_TI2R_IDE_Msk     (0x1UL << CAN_TI2R_IDE_Pos)/*!< 0x00000004 */
#define CAN_TI2R_IDE         CAN_TI2R_IDE_Msk	/*!<Identifier Extension                       */
#define CAN_TI2R_EXID_Pos    (3U)
#define CAN_TI2R_EXID_Msk    (0x3FFFFUL << CAN_TI2R_EXID_Pos)	/*!< 0x001FFFF8 */
#define CAN_TI2R_EXID        CAN_TI2R_EXID_Msk					/*!<Extended identifier                        */
#define CAN_TI2R_STID_Pos    (21U)
#define CAN_TI2R_STID_Msk    (0x7FFUL << CAN_TI2R_STID_Pos)	/*!< 0xFFE00000 */
#define CAN_TI2R_STID        CAN_TI2R_STID_Msk				/*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_TDT2R register  ******************/
#define CAN_TDT2R_DLC_Pos     (0U)
#define CAN_TDT2R_DLC_Msk     (0xFUL << CAN_TDT2R_DLC_Pos)	/*!< 0x0000000F */
#define CAN_TDT2R_DLC         CAN_TDT2R_DLC_Msk				/*!<Data Length Code      */
#define CAN_TDT2R_TGT_Pos     (8U)
#define CAN_TDT2R_TGT_Msk     (0x1UL << CAN_TDT2R_TGT_Pos)	/*!< 0x00000100 */
#define CAN_TDT2R_TGT         CAN_TDT2R_TGT_Msk				/*!<Transmit Global Time  */
#define CAN_TDT2R_TIME_Pos    (16U)
#define CAN_TDT2R_TIME_Msk    (0xFFFFUL << CAN_TDT2R_TIME_Pos)	/*!< 0xFFFF0000 */
#define CAN_TDT2R_TIME        CAN_TDT2R_TIME_Msk				/*!<Message Time Stamp    */

/*******************  Bit definition for CAN_TDL2R register  ******************/
#define CAN_TDL2R_DATA0_Pos    (0U)
#define CAN_TDL2R_DATA0_Msk    (0xFFUL << CAN_TDL2R_DATA0_Pos)	/*!< 0x000000FF */
#define CAN_TDL2R_DATA0        CAN_TDL2R_DATA0_Msk				/*!<Data byte 0 */
#define CAN_TDL2R_DATA1_Pos    (8U)
#define CAN_TDL2R_DATA1_Msk    (0xFFUL << CAN_TDL2R_DATA1_Pos)	/*!< 0x0000FF00 */
#define CAN_TDL2R_DATA1        CAN_TDL2R_DATA1_Msk				/*!<Data byte 1 */
#define CAN_TDL2R_DATA2_Pos    (16U)
#define CAN_TDL2R_DATA2_Msk    (0xFFUL << CAN_TDL2R_DATA2_Pos)	/*!< 0x00FF0000 */
#define CAN_TDL2R_DATA2        CAN_TDL2R_DATA2_Msk				/*!<Data byte 2 */
#define CAN_TDL2R_DATA3_Pos    (24U)
#define CAN_TDL2R_DATA3_Msk    (0xFFUL << CAN_TDL2R_DATA3_Pos)	/*!< 0xFF000000 */
#define CAN_TDL2R_DATA3        CAN_TDL2R_DATA3_Msk				/*!<Data byte 3 */

/*******************  Bit definition for CAN_TDH2R register  ******************/
#define CAN_TDH2R_DATA4_Pos    (0U)
#define CAN_TDH2R_DATA4_Msk    (0xFFUL << CAN_TDH2R_DATA4_Pos)	/*!< 0x000000FF */
#define CAN_TDH2R_DATA4        CAN_TDH2R_DATA4_Msk				/*!<Data byte 4 */
#define CAN_TDH2R_DATA5_Pos    (8U)
#define CAN_TDH2R_DATA5_Msk    (0xFFUL << CAN_TDH2R_DATA5_Pos)	/*!< 0x0000FF00 */
#define CAN_TDH2R_DATA5        CAN_TDH2R_DATA5_Msk				/*!<Data byte 5 */
#define CAN_TDH2R_DATA6_Pos    (16U)
#define CAN_TDH2R_DATA6_Msk    (0xFFUL << CAN_TDH2R_DATA6_Pos)	/*!< 0x00FF0000 */
#define CAN_TDH2R_DATA6        CAN_TDH2R_DATA6_Msk				/*!<Data byte 6 */
#define CAN_TDH2R_DATA7_Pos    (24U)
#define CAN_TDH2R_DATA7_Msk    (0xFFUL << CAN_TDH2R_DATA7_Pos)	/*!< 0xFF000000 */
#define CAN_TDH2R_DATA7        CAN_TDH2R_DATA7_Msk				/*!<Data byte 7 */

/*******************  Bit definition for CAN_RI0R register  *******************/
#define CAN_RI0R_RTR_Pos     (1U)
#define CAN_RI0R_RTR_Msk     (0x1UL << CAN_RI0R_RTR_Pos)/*!< 0x00000002 */
#define CAN_RI0R_RTR         CAN_RI0R_RTR_Msk	/*!<Remote Transmission Request                */
#define CAN_RI0R_IDE_Pos     (2U)
#define CAN_RI0R_IDE_Msk     (0x1UL << CAN_RI0R_IDE_Pos)/*!< 0x00000004 */
#define CAN_RI0R_IDE         CAN_RI0R_IDE_Msk	/*!<Identifier Extension                       */
#define CAN_RI0R_EXID_Pos    (3U)
#define CAN_RI0R_EXID_Msk    (0x3FFFFUL << CAN_RI0R_EXID_Pos)	/*!< 0x001FFFF8 */
#define CAN_RI0R_EXID        CAN_RI0R_EXID_Msk					/*!<Extended Identifier                        */
#define CAN_RI0R_STID_Pos    (21U)
#define CAN_RI0R_STID_Msk    (0x7FFUL << CAN_RI0R_STID_Pos)	/*!< 0xFFE00000 */
#define CAN_RI0R_STID        CAN_RI0R_STID_Msk				/*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT0R register  ******************/
#define CAN_RDT0R_DLC_Pos     (0U)
#define CAN_RDT0R_DLC_Msk     (0xFUL << CAN_RDT0R_DLC_Pos)	/*!< 0x0000000F */
#define CAN_RDT0R_DLC         CAN_RDT0R_DLC_Msk				/*!<Data Length Code */
#define CAN_RDT0R_FMI_Pos     (8U)
#define CAN_RDT0R_FMI_Msk     (0xFFUL << CAN_RDT0R_FMI_Pos)	/*!< 0x0000FF00 */
#define CAN_RDT0R_FMI         CAN_RDT0R_FMI_Msk				/*!<Filter Match Index */
#define CAN_RDT0R_TIME_Pos    (16U)
#define CAN_RDT0R_TIME_Msk    (0xFFFFUL << CAN_RDT0R_TIME_Pos)	/*!< 0xFFFF0000 */
#define CAN_RDT0R_TIME        CAN_RDT0R_TIME_Msk				/*!<Message Time Stamp */

/*******************  Bit definition for CAN_RDL0R register  ******************/
#define CAN_RDL0R_DATA0_Pos    (0U)
#define CAN_RDL0R_DATA0_Msk    (0xFFUL << CAN_RDL0R_DATA0_Pos)	/*!< 0x000000FF */
#define CAN_RDL0R_DATA0        CAN_RDL0R_DATA0_Msk				/*!<Data byte 0 */
#define CAN_RDL0R_DATA1_Pos    (8U)
#define CAN_RDL0R_DATA1_Msk    (0xFFUL << CAN_RDL0R_DATA1_Pos)	/*!< 0x0000FF00 */
#define CAN_RDL0R_DATA1        CAN_RDL0R_DATA1_Msk				/*!<Data byte 1 */
#define CAN_RDL0R_DATA2_Pos    (16U)
#define CAN_RDL0R_DATA2_Msk    (0xFFUL << CAN_RDL0R_DATA2_Pos)	/*!< 0x00FF0000 */
#define CAN_RDL0R_DATA2        CAN_RDL0R_DATA2_Msk				/*!<Data byte 2 */
#define CAN_RDL0R_DATA3_Pos    (24U)
#define CAN_RDL0R_DATA3_Msk    (0xFFUL << CAN_RDL0R_DATA3_Pos)	/*!< 0xFF000000 */
#define CAN_RDL0R_DATA3        CAN_RDL0R_DATA3_Msk				/*!<Data byte 3 */

/*******************  Bit definition for CAN_RDH0R register  ******************/
#define CAN_RDH0R_DATA4_Pos    (0U)
#define CAN_RDH0R_DATA4_Msk    (0xFFUL << CAN_RDH0R_DATA4_Pos)	/*!< 0x000000FF */
#define CAN_RDH0R_DATA4        CAN_RDH0R_DATA4_Msk				/*!<Data byte 4 */
#define CAN_RDH0R_DATA5_Pos    (8U)
#define CAN_RDH0R_DATA5_Msk    (0xFFUL << CAN_RDH0R_DATA5_Pos)	/*!< 0x0000FF00 */
#define CAN_RDH0R_DATA5        CAN_RDH0R_DATA5_Msk				/*!<Data byte 5 */
#define CAN_RDH0R_DATA6_Pos    (16U)
#define CAN_RDH0R_DATA6_Msk    (0xFFUL << CAN_RDH0R_DATA6_Pos)	/*!< 0x00FF0000 */
#define CAN_RDH0R_DATA6        CAN_RDH0R_DATA6_Msk				/*!<Data byte 6 */
#define CAN_RDH0R_DATA7_Pos    (24U)
#define CAN_RDH0R_DATA7_Msk    (0xFFUL << CAN_RDH0R_DATA7_Pos)	/*!< 0xFF000000 */
#define CAN_RDH0R_DATA7        CAN_RDH0R_DATA7_Msk				/*!<Data byte 7 */

/*******************  Bit definition for CAN_RI1R register  *******************/
#define CAN_RI1R_RTR_Pos     (1U)
#define CAN_RI1R_RTR_Msk     (0x1UL << CAN_RI1R_RTR_Pos)/*!< 0x00000002 */
#define CAN_RI1R_RTR         CAN_RI1R_RTR_Msk	/*!<Remote Transmission Request                */
#define CAN_RI1R_IDE_Pos     (2U)
#define CAN_RI1R_IDE_Msk     (0x1UL << CAN_RI1R_IDE_Pos)/*!< 0x00000004 */
#define CAN_RI1R_IDE         CAN_RI1R_IDE_Msk	/*!<Identifier Extension                       */
#define CAN_RI1R_EXID_Pos    (3U)
#define CAN_RI1R_EXID_Msk    (0x3FFFFUL << CAN_RI1R_EXID_Pos)	/*!< 0x001FFFF8 */
#define CAN_RI1R_EXID        CAN_RI1R_EXID_Msk					/*!<Extended identifier                        */
#define CAN_RI1R_STID_Pos    (21U)
#define CAN_RI1R_STID_Msk    (0x7FFUL << CAN_RI1R_STID_Pos)	/*!< 0xFFE00000 */
#define CAN_RI1R_STID        CAN_RI1R_STID_Msk				/*!<Standard Identifier or Extended Identifier */

/*******************  Bit definition for CAN_RDT1R register  ******************/
#define CAN_RDT1R_DLC_Pos     (0U)
#define CAN_RDT1R_DLC_Msk     (0xFUL << CAN_RDT1R_DLC_Pos)	/*!< 0x0000000F */
#define CAN_RDT1R_DLC         CAN_RDT1R_DLC_Msk				/*!<Data Length Code   */
#define CAN_RDT1R_FMI_Pos     (8U)
#define CAN_RDT1R_FMI_Msk     (0xFFUL << CAN_RDT1R_FMI_Pos)	/*!< 0x0000FF00 */
#define CAN_RDT1R_FMI         CAN_RDT1R_FMI_Msk				/*!<Filter Match Index */
#define CAN_RDT1R_TIME_Pos    (16U)
#define CAN_RDT1R_TIME_Msk    (0xFFFFUL << CAN_RDT1R_TIME_Pos)	/*!< 0xFFFF0000 */
#define CAN_RDT1R_TIME        CAN_RDT1R_TIME_Msk				/*!<Message Time Stamp */

/*******************  Bit definition for CAN_RDL1R register  ******************/
#define CAN_RDL1R_DATA0_Pos    (0U)
#define CAN_RDL1R_DATA0_Msk    (0xFFUL << CAN_RDL1R_DATA0_Pos)	/*!< 0x000000FF */
#define CAN_RDL1R_DATA0        CAN_RDL1R_DATA0_Msk				/*!<Data byte 0 */
#define CAN_RDL1R_DATA1_Pos    (8U)
#define CAN_RDL1R_DATA1_Msk    (0xFFUL << CAN_RDL1R_DATA1_Pos)	/*!< 0x0000FF00 */
#define CAN_RDL1R_DATA1        CAN_RDL1R_DATA1_Msk				/*!<Data byte 1 */
#define CAN_RDL1R_DATA2_Pos    (16U)
#define CAN_RDL1R_DATA2_Msk    (0xFFUL << CAN_RDL1R_DATA2_Pos)	/*!< 0x00FF0000 */
#define CAN_RDL1R_DATA2        CAN_RDL1R_DATA2_Msk				/*!<Data byte 2 */
#define CAN_RDL1R_DATA3_Pos    (24U)
#define CAN_RDL1R_DATA3_Msk    (0xFFUL << CAN_RDL1R_DATA3_Pos)	/*!< 0xFF000000 */
#define CAN_RDL1R_DATA3        CAN_RDL1R_DATA3_Msk				/*!<Data byte 3 */

/*******************  Bit definition for CAN_RDH1R register  ******************/
#define CAN_RDH1R_DATA4_Pos    (0U)
#define CAN_RDH1R_DATA4_Msk    (0xFFUL << CAN_RDH1R_DATA4_Pos)	/*!< 0x000000FF */
#define CAN_RDH1R_DATA4        CAN_RDH1R_DATA4_Msk				/*!<Data byte 4 */
#define CAN_RDH1R_DATA5_Pos    (8U)
#define CAN_RDH1R_DATA5_Msk    (0xFFUL << CAN_RDH1R_DATA5_Pos)	/*!< 0x0000FF00 */
#define CAN_RDH1R_DATA5        CAN_RDH1R_DATA5_Msk				/*!<Data byte 5 */
#define CAN_RDH1R_DATA6_Pos    (16U)
#define CAN_RDH1R_DATA6_Msk    (0xFFUL << CAN_RDH1R_DATA6_Pos)	/*!< 0x00FF0000 */
#define CAN_RDH1R_DATA6        CAN_RDH1R_DATA6_Msk				/*!<Data byte 6 */
#define CAN_RDH1R_DATA7_Pos    (24U)
#define CAN_RDH1R_DATA7_Msk    (0xFFUL << CAN_RDH1R_DATA7_Pos)	/*!< 0xFF000000 */
#define CAN_RDH1R_DATA7        CAN_RDH1R_DATA7_Msk				/*!<Data byte 7 */

/*!<CAN filter registers */
/*******************  Bit definition for CAN_FMR register  ********************/
#define CAN_FMR_FINIT    ((uint8_t) 0x01U)	/*!<Filter Init Mode */

/*******************  Bit definition for CAN_FM1R register  *******************/
#define CAN_FM1R_FBM_Pos      (0U)
#define CAN_FM1R_FBM_Msk      (0x3FFFUL << CAN_FM1R_FBM_Pos)/*!< 0x00003FFF */
#define CAN_FM1R_FBM          CAN_FM1R_FBM_Msk	/*!<Filter Mode */
#define CAN_FM1R_FBM0_Pos     (0U)
#define CAN_FM1R_FBM0_Msk     (0x1UL << CAN_FM1R_FBM0_Pos)	/*!< 0x00000001 */
#define CAN_FM1R_FBM0         CAN_FM1R_FBM0_Msk				/*!<Filter Init Mode bit 0  */
#define CAN_FM1R_FBM1_Pos     (1U)
#define CAN_FM1R_FBM1_Msk     (0x1UL << CAN_FM1R_FBM1_Pos)	/*!< 0x00000002 */
#define CAN_FM1R_FBM1         CAN_FM1R_FBM1_Msk				/*!<Filter Init Mode bit 1  */
#define CAN_FM1R_FBM2_Pos     (2U)
#define CAN_FM1R_FBM2_Msk     (0x1UL << CAN_FM1R_FBM2_Pos)	/*!< 0x00000004 */
#define CAN_FM1R_FBM2         CAN_FM1R_FBM2_Msk				/*!<Filter Init Mode bit 2  */
#define CAN_FM1R_FBM3_Pos     (3U)
#define CAN_FM1R_FBM3_Msk     (0x1UL << CAN_FM1R_FBM3_Pos)	/*!< 0x00000008 */
#define CAN_FM1R_FBM3         CAN_FM1R_FBM3_Msk				/*!<Filter Init Mode bit 3  */
#define CAN_FM1R_FBM4_Pos     (4U)
#define CAN_FM1R_FBM4_Msk     (0x1UL << CAN_FM1R_FBM4_Pos)	/*!< 0x00000010 */
#define CAN_FM1R_FBM4         CAN_FM1R_FBM4_Msk				/*!<Filter Init Mode bit 4  */
#define CAN_FM1R_FBM5_Pos     (5U)
#define CAN_FM1R_FBM5_Msk     (0x1UL << CAN_FM1R_FBM5_Pos)	/*!< 0x00000020 */
#define CAN_FM1R_FBM5         CAN_FM1R_FBM5_Msk				/*!<Filter Init Mode bit 5  */
#define CAN_FM1R_FBM6_Pos     (6U)
#define CAN_FM1R_FBM6_Msk     (0x1UL << CAN_FM1R_FBM6_Pos)	/*!< 0x00000040 */
#define CAN_FM1R_FBM6         CAN_FM1R_FBM6_Msk				/*!<Filter Init Mode bit 6  */
#define CAN_FM1R_FBM7_Pos     (7U)
#define CAN_FM1R_FBM7_Msk     (0x1UL << CAN_FM1R_FBM7_Pos)	/*!< 0x00000080 */
#define CAN_FM1R_FBM7         CAN_FM1R_FBM7_Msk				/*!<Filter Init Mode bit 7  */
#define CAN_FM1R_FBM8_Pos     (8U)
#define CAN_FM1R_FBM8_Msk     (0x1UL << CAN_FM1R_FBM8_Pos)	/*!< 0x00000100 */
#define CAN_FM1R_FBM8         CAN_FM1R_FBM8_Msk				/*!<Filter Init Mode bit 8  */
#define CAN_FM1R_FBM9_Pos     (9U)
#define CAN_FM1R_FBM9_Msk     (0x1UL << CAN_FM1R_FBM9_Pos)	/*!< 0x00000200 */
#define CAN_FM1R_FBM9         CAN_FM1R_FBM9_Msk				/*!<Filter Init Mode bit 9  */
#define CAN_FM1R_FBM10_Pos    (10U)
#define CAN_FM1R_FBM10_Msk    (0x1UL << CAN_FM1R_FBM10_Pos)	/*!< 0x00000400 */
#define CAN_FM1R_FBM10        CAN_FM1R_FBM10_Msk/*!<Filter Init Mode bit 10 */
#define CAN_FM1R_FBM11_Pos    (11U)
#define CAN_FM1R_FBM11_Msk    (0x1UL << CAN_FM1R_FBM11_Pos)	/*!< 0x00000800 */
#define CAN_FM1R_FBM11        CAN_FM1R_FBM11_Msk/*!<Filter Init Mode bit 11 */
#define CAN_FM1R_FBM12_Pos    (12U)
#define CAN_FM1R_FBM12_Msk    (0x1UL << CAN_FM1R_FBM12_Pos)	/*!< 0x00001000 */
#define CAN_FM1R_FBM12        CAN_FM1R_FBM12_Msk/*!<Filter Init Mode bit 12 */
#define CAN_FM1R_FBM13_Pos    (13U)
#define CAN_FM1R_FBM13_Msk    (0x1UL << CAN_FM1R_FBM13_Pos)	/*!< 0x00002000 */
#define CAN_FM1R_FBM13        CAN_FM1R_FBM13_Msk/*!<Filter Init Mode bit 13 */

/*******************  Bit definition for CAN_FS1R register  *******************/
#define CAN_FS1R_FSC_Pos      (0U)
#define CAN_FS1R_FSC_Msk      (0x3FFFUL << CAN_FS1R_FSC_Pos)/*!< 0x00003FFF */
#define CAN_FS1R_FSC          CAN_FS1R_FSC_Msk	/*!<Filter Scale Configuration        */
#define CAN_FS1R_FSC0_Pos     (0U)
#define CAN_FS1R_FSC0_Msk     (0x1UL << CAN_FS1R_FSC0_Pos)	/*!< 0x00000001 */
#define CAN_FS1R_FSC0         CAN_FS1R_FSC0_Msk				/*!<Filter Scale Configuration bit 0  */
#define CAN_FS1R_FSC1_Pos     (1U)
#define CAN_FS1R_FSC1_Msk     (0x1UL << CAN_FS1R_FSC1_Pos)	/*!< 0x00000002 */
#define CAN_FS1R_FSC1         CAN_FS1R_FSC1_Msk				/*!<Filter Scale Configuration bit 1  */
#define CAN_FS1R_FSC2_Pos     (2U)
#define CAN_FS1R_FSC2_Msk     (0x1UL << CAN_FS1R_FSC2_Pos)	/*!< 0x00000004 */
#define CAN_FS1R_FSC2         CAN_FS1R_FSC2_Msk				/*!<Filter Scale Configuration bit 2  */
#define CAN_FS1R_FSC3_Pos     (3U)
#define CAN_FS1R_FSC3_Msk     (0x1UL << CAN_FS1R_FSC3_Pos)	/*!< 0x00000008 */
#define CAN_FS1R_FSC3         CAN_FS1R_FSC3_Msk				/*!<Filter Scale Configuration bit 3  */
#define CAN_FS1R_FSC4_Pos     (4U)
#define CAN_FS1R_FSC4_Msk     (0x1UL << CAN_FS1R_FSC4_Pos)	/*!< 0x00000010 */
#define CAN_FS1R_FSC4         CAN_FS1R_FSC4_Msk				/*!<Filter Scale Configuration bit 4  */
#define CAN_FS1R_FSC5_Pos     (5U)
#define CAN_FS1R_FSC5_Msk     (0x1UL << CAN_FS1R_FSC5_Pos)	/*!< 0x00000020 */
#define CAN_FS1R_FSC5         CAN_FS1R_FSC5_Msk				/*!<Filter Scale Configuration bit 5  */
#define CAN_FS1R_FSC6_Pos     (6U)
#define CAN_FS1R_FSC6_Msk     (0x1UL << CAN_FS1R_FSC6_Pos)	/*!< 0x00000040 */
#define CAN_FS1R_FSC6         CAN_FS1R_FSC6_Msk				/*!<Filter Scale Configuration bit 6  */
#define CAN_FS1R_FSC7_Pos     (7U)
#define CAN_FS1R_FSC7_Msk     (0x1UL << CAN_FS1R_FSC7_Pos)	/*!< 0x00000080 */
#define CAN_FS1R_FSC7         CAN_FS1R_FSC7_Msk				/*!<Filter Scale Configuration bit 7  */
#define CAN_FS1R_FSC8_Pos     (8U)
#define CAN_FS1R_FSC8_Msk     (0x1UL << CAN_FS1R_FSC8_Pos)	/*!< 0x00000100 */
#define CAN_FS1R_FSC8         CAN_FS1R_FSC8_Msk				/*!<Filter Scale Configuration bit 8  */
#define CAN_FS1R_FSC9_Pos     (9U)
#define CAN_FS1R_FSC9_Msk     (0x1UL << CAN_FS1R_FSC9_Pos)	/*!< 0x00000200 */
#define CAN_FS1R_FSC9         CAN_FS1R_FSC9_Msk				/*!<Filter Scale Configuration bit 9  */
#define CAN_FS1R_FSC10_Pos    (10U)
#define CAN_FS1R_FSC10_Msk    (0x1UL << CAN_FS1R_FSC10_Pos)	/*!< 0x00000400 */
#define CAN_FS1R_FSC10        CAN_FS1R_FSC10_Msk/*!<Filter Scale Configuration bit 10 */
#define CAN_FS1R_FSC11_Pos    (11U)
#define CAN_FS1R_FSC11_Msk    (0x1UL << CAN_FS1R_FSC11_Pos)	/*!< 0x00000800 */
#define CAN_FS1R_FSC11        CAN_FS1R_FSC11_Msk/*!<Filter Scale Configuration bit 11 */
#define CAN_FS1R_FSC12_Pos    (12U)
#define CAN_FS1R_FSC12_Msk    (0x1UL << CAN_FS1R_FSC12_Pos)	/*!< 0x00001000 */
#define CAN_FS1R_FSC12        CAN_FS1R_FSC12_Msk/*!<Filter Scale Configuration bit 12 */
#define CAN_FS1R_FSC13_Pos    (13U)
#define CAN_FS1R_FSC13_Msk    (0x1UL << CAN_FS1R_FSC13_Pos)	/*!< 0x00002000 */
#define CAN_FS1R_FSC13        CAN_FS1R_FSC13_Msk/*!<Filter Scale Configuration bit 13 */

/******************  Bit definition for CAN_FFA1R register  *******************/
#define CAN_FFA1R_FFA_Pos      (0U)
#define CAN_FFA1R_FFA_Msk      (0x3FFFUL << CAN_FFA1R_FFA_Pos)	/*!< 0x00003FFF */
#define CAN_FFA1R_FFA          CAN_FFA1R_FFA_Msk				/*!<Filter FIFO Assignment */
#define CAN_FFA1R_FFA0_Pos     (0U)
#define CAN_FFA1R_FFA0_Msk     (0x1UL << CAN_FFA1R_FFA0_Pos)/*!< 0x00000001 */
#define CAN_FFA1R_FFA0         CAN_FFA1R_FFA0_Msk	/*!<Filter FIFO Assignment for Filter 0 */
#define CAN_FFA1R_FFA1_Pos     (1U)
#define CAN_FFA1R_FFA1_Msk     (0x1UL << CAN_FFA1R_FFA1_Pos)/*!< 0x00000002 */
#define CAN_FFA1R_FFA1         CAN_FFA1R_FFA1_Msk	/*!<Filter FIFO Assignment for Filter 1 */
#define CAN_FFA1R_FFA2_Pos     (2U)
#define CAN_FFA1R_FFA2_Msk     (0x1UL << CAN_FFA1R_FFA2_Pos)/*!< 0x00000004 */
#define CAN_FFA1R_FFA2         CAN_FFA1R_FFA2_Msk	/*!<Filter FIFO Assignment for Filter 2 */
#define CAN_FFA1R_FFA3_Pos     (3U)
#define CAN_FFA1R_FFA3_Msk     (0x1UL << CAN_FFA1R_FFA3_Pos)/*!< 0x00000008 */
#define CAN_FFA1R_FFA3         CAN_FFA1R_FFA3_Msk	/*!<Filter FIFO Assignment for Filter 3 */
#define CAN_FFA1R_FFA4_Pos     (4U)
#define CAN_FFA1R_FFA4_Msk     (0x1UL << CAN_FFA1R_FFA4_Pos)/*!< 0x00000010 */
#define CAN_FFA1R_FFA4         CAN_FFA1R_FFA4_Msk	/*!<Filter FIFO Assignment for Filter 4 */
#define CAN_FFA1R_FFA5_Pos     (5U)
#define CAN_FFA1R_FFA5_Msk     (0x1UL << CAN_FFA1R_FFA5_Pos)/*!< 0x00000020 */
#define CAN_FFA1R_FFA5         CAN_FFA1R_FFA5_Msk	/*!<Filter FIFO Assignment for Filter 5 */
#define CAN_FFA1R_FFA6_Pos     (6U)
#define CAN_FFA1R_FFA6_Msk     (0x1UL << CAN_FFA1R_FFA6_Pos)/*!< 0x00000040 */
#define CAN_FFA1R_FFA6         CAN_FFA1R_FFA6_Msk	/*!<Filter FIFO Assignment for Filter 6 */
#define CAN_FFA1R_FFA7_Pos     (7U)
#define CAN_FFA1R_FFA7_Msk     (0x1UL << CAN_FFA1R_FFA7_Pos)/*!< 0x00000080 */
#define CAN_FFA1R_FFA7         CAN_FFA1R_FFA7_Msk	/*!<Filter FIFO Assignment for Filter 7 */
#define CAN_FFA1R_FFA8_Pos     (8U)
#define CAN_FFA1R_FFA8_Msk     (0x1UL << CAN_FFA1R_FFA8_Pos)/*!< 0x00000100 */
#define CAN_FFA1R_FFA8         CAN_FFA1R_FFA8_Msk	/*!<Filter FIFO Assignment for Filter 8 */
#define CAN_FFA1R_FFA9_Pos     (9U)
#define CAN_FFA1R_FFA9_Msk     (0x1UL << CAN_FFA1R_FFA9_Pos)/*!< 0x00000200 */
#define CAN_FFA1R_FFA9         CAN_FFA1R_FFA9_Msk	/*!<Filter FIFO Assignment for Filter 9 */
#define CAN_FFA1R_FFA10_Pos    (10U)
#define CAN_FFA1R_FFA10_Msk    (0x1UL << CAN_FFA1R_FFA10_Pos)	/*!< 0x00000400 */
#define CAN_FFA1R_FFA10        CAN_FFA1R_FFA10_Msk				/*!<Filter FIFO Assignment for Filter 10 */
#define CAN_FFA1R_FFA11_Pos    (11U)
#define CAN_FFA1R_FFA11_Msk    (0x1UL << CAN_FFA1R_FFA11_Pos)	/*!< 0x00000800 */
#define CAN_FFA1R_FFA11        CAN_FFA1R_FFA11_Msk				/*!<Filter FIFO Assignment for Filter 11 */
#define CAN_FFA1R_FFA12_Pos    (12U)
#define CAN_FFA1R_FFA12_Msk    (0x1UL << CAN_FFA1R_FFA12_Pos)	/*!< 0x00001000 */
#define CAN_FFA1R_FFA12        CAN_FFA1R_FFA12_Msk				/*!<Filter FIFO Assignment for Filter 12 */
#define CAN_FFA1R_FFA13_Pos    (13U)
#define CAN_FFA1R_FFA13_Msk    (0x1UL << CAN_FFA1R_FFA13_Pos)	/*!< 0x00002000 */
#define CAN_FFA1R_FFA13        CAN_FFA1R_FFA13_Msk				/*!<Filter FIFO Assignment for Filter 13 */

/*******************  Bit definition for CAN_FA1R register  *******************/
#define CAN_FA1R_FACT_Pos      (0U)
#define CAN_FA1R_FACT_Msk      (0x3FFFUL << CAN_FA1R_FACT_Pos)	/*!< 0x00003FFF */
#define CAN_FA1R_FACT          CAN_FA1R_FACT_Msk				/*!<Filter Active    */
#define CAN_FA1R_FACT0_Pos     (0U)
#define CAN_FA1R_FACT0_Msk     (0x1UL << CAN_FA1R_FACT0_Pos)/*!< 0x00000001 */
#define CAN_FA1R_FACT0         CAN_FA1R_FACT0_Msk	/*!<Filter 0 Active  */
#define CAN_FA1R_FACT1_Pos     (1U)
#define CAN_FA1R_FACT1_Msk     (0x1UL << CAN_FA1R_FACT1_Pos)/*!< 0x00000002 */
#define CAN_FA1R_FACT1         CAN_FA1R_FACT1_Msk	/*!<Filter 1 Active  */
#define CAN_FA1R_FACT2_Pos     (2U)
#define CAN_FA1R_FACT2_Msk     (0x1UL << CAN_FA1R_FACT2_Pos)/*!< 0x00000004 */
#define CAN_FA1R_FACT2         CAN_FA1R_FACT2_Msk	/*!<Filter 2 Active  */
#define CAN_FA1R_FACT3_Pos     (3U)
#define CAN_FA1R_FACT3_Msk     (0x1UL << CAN_FA1R_FACT3_Pos)/*!< 0x00000008 */
#define CAN_FA1R_FACT3         CAN_FA1R_FACT3_Msk	/*!<Filter 3 Active  */
#define CAN_FA1R_FACT4_Pos     (4U)
#define CAN_FA1R_FACT4_Msk     (0x1UL << CAN_FA1R_FACT4_Pos)/*!< 0x00000010 */
#define CAN_FA1R_FACT4         CAN_FA1R_FACT4_Msk	/*!<Filter 4 Active  */
#define CAN_FA1R_FACT5_Pos     (5U)
#define CAN_FA1R_FACT5_Msk     (0x1UL << CAN_FA1R_FACT5_Pos)/*!< 0x00000020 */
#define CAN_FA1R_FACT5         CAN_FA1R_FACT5_Msk	/*!<Filter 5 Active  */
#define CAN_FA1R_FACT6_Pos     (6U)
#define CAN_FA1R_FACT6_Msk     (0x1UL << CAN_FA1R_FACT6_Pos)/*!< 0x00000040 */
#define CAN_FA1R_FACT6         CAN_FA1R_FACT6_Msk	/*!<Filter 6 Active  */
#define CAN_FA1R_FACT7_Pos     (7U)
#define CAN_FA1R_FACT7_Msk     (0x1UL << CAN_FA1R_FACT7_Pos)/*!< 0x00000080 */
#define CAN_FA1R_FACT7         CAN_FA1R_FACT7_Msk	/*!<Filter 7 Active  */
#define CAN_FA1R_FACT8_Pos     (8U)
#define CAN_FA1R_FACT8_Msk     (0x1UL << CAN_FA1R_FACT8_Pos)/*!< 0x00000100 */
#define CAN_FA1R_FACT8         CAN_FA1R_FACT8_Msk	/*!<Filter 8 Active  */
#define CAN_FA1R_FACT9_Pos     (9U)
#define CAN_FA1R_FACT9_Msk     (0x1UL << CAN_FA1R_FACT9_Pos)/*!< 0x00000200 */
#define CAN_FA1R_FACT9         CAN_FA1R_FACT9_Msk	/*!<Filter 9 Active  */
#define CAN_FA1R_FACT10_Pos    (10U)
#define CAN_FA1R_FACT10_Msk    (0x1UL << CAN_FA1R_FACT10_Pos)	/*!< 0x00000400 */
#define CAN_FA1R_FACT10        CAN_FA1R_FACT10_Msk				/*!<Filter 10 Active */
#define CAN_FA1R_FACT11_Pos    (11U)
#define CAN_FA1R_FACT11_Msk    (0x1UL << CAN_FA1R_FACT11_Pos)	/*!< 0x00000800 */
#define CAN_FA1R_FACT11        CAN_FA1R_FACT11_Msk				/*!<Filter 11 Active */
#define CAN_FA1R_FACT12_Pos    (12U)
#define CAN_FA1R_FACT12_Msk    (0x1UL << CAN_FA1R_FACT12_Pos)	/*!< 0x00001000 */
#define CAN_FA1R_FACT12        CAN_FA1R_FACT12_Msk				/*!<Filter 12 Active */
#define CAN_FA1R_FACT13_Pos    (13U)
#define CAN_FA1R_FACT13_Msk    (0x1UL << CAN_FA1R_FACT13_Pos)	/*!< 0x00002000 */
#define CAN_FA1R_FACT13        CAN_FA1R_FACT13_Msk				/*!<Filter 13 Active */

/*******************  Bit definition for CAN_F0R1 register  *******************/
#define CAN_F0R1_FB0_Pos     (0U)
#define CAN_F0R1_FB0_Msk     (0x1UL << CAN_F0R1_FB0_Pos)/*!< 0x00000001 */
#define CAN_F0R1_FB0         CAN_F0R1_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F0R1_FB1_Pos     (1U)
#define CAN_F0R1_FB1_Msk     (0x1UL << CAN_F0R1_FB1_Pos)/*!< 0x00000002 */
#define CAN_F0R1_FB1         CAN_F0R1_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F0R1_FB2_Pos     (2U)
#define CAN_F0R1_FB2_Msk     (0x1UL << CAN_F0R1_FB2_Pos)/*!< 0x00000004 */
#define CAN_F0R1_FB2         CAN_F0R1_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F0R1_FB3_Pos     (3U)
#define CAN_F0R1_FB3_Msk     (0x1UL << CAN_F0R1_FB3_Pos)/*!< 0x00000008 */
#define CAN_F0R1_FB3         CAN_F0R1_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F0R1_FB4_Pos     (4U)
#define CAN_F0R1_FB4_Msk     (0x1UL << CAN_F0R1_FB4_Pos)/*!< 0x00000010 */
#define CAN_F0R1_FB4         CAN_F0R1_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F0R1_FB5_Pos     (5U)
#define CAN_F0R1_FB5_Msk     (0x1UL << CAN_F0R1_FB5_Pos)/*!< 0x00000020 */
#define CAN_F0R1_FB5         CAN_F0R1_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F0R1_FB6_Pos     (6U)
#define CAN_F0R1_FB6_Msk     (0x1UL << CAN_F0R1_FB6_Pos)/*!< 0x00000040 */
#define CAN_F0R1_FB6         CAN_F0R1_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F0R1_FB7_Pos     (7U)
#define CAN_F0R1_FB7_Msk     (0x1UL << CAN_F0R1_FB7_Pos)/*!< 0x00000080 */
#define CAN_F0R1_FB7         CAN_F0R1_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F0R1_FB8_Pos     (8U)
#define CAN_F0R1_FB8_Msk     (0x1UL << CAN_F0R1_FB8_Pos)/*!< 0x00000100 */
#define CAN_F0R1_FB8         CAN_F0R1_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F0R1_FB9_Pos     (9U)
#define CAN_F0R1_FB9_Msk     (0x1UL << CAN_F0R1_FB9_Pos)/*!< 0x00000200 */
#define CAN_F0R1_FB9         CAN_F0R1_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F0R1_FB10_Pos    (10U)
#define CAN_F0R1_FB10_Msk    (0x1UL << CAN_F0R1_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F0R1_FB10        CAN_F0R1_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F0R1_FB11_Pos    (11U)
#define CAN_F0R1_FB11_Msk    (0x1UL << CAN_F0R1_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F0R1_FB11        CAN_F0R1_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F0R1_FB12_Pos    (12U)
#define CAN_F0R1_FB12_Msk    (0x1UL << CAN_F0R1_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F0R1_FB12        CAN_F0R1_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F0R1_FB13_Pos    (13U)
#define CAN_F0R1_FB13_Msk    (0x1UL << CAN_F0R1_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F0R1_FB13        CAN_F0R1_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F0R1_FB14_Pos    (14U)
#define CAN_F0R1_FB14_Msk    (0x1UL << CAN_F0R1_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F0R1_FB14        CAN_F0R1_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F0R1_FB15_Pos    (15U)
#define CAN_F0R1_FB15_Msk    (0x1UL << CAN_F0R1_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F0R1_FB15        CAN_F0R1_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F0R1_FB16_Pos    (16U)
#define CAN_F0R1_FB16_Msk    (0x1UL << CAN_F0R1_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F0R1_FB16        CAN_F0R1_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F0R1_FB17_Pos    (17U)
#define CAN_F0R1_FB17_Msk    (0x1UL << CAN_F0R1_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F0R1_FB17        CAN_F0R1_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F0R1_FB18_Pos    (18U)
#define CAN_F0R1_FB18_Msk    (0x1UL << CAN_F0R1_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F0R1_FB18        CAN_F0R1_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F0R1_FB19_Pos    (19U)
#define CAN_F0R1_FB19_Msk    (0x1UL << CAN_F0R1_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F0R1_FB19        CAN_F0R1_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F0R1_FB20_Pos    (20U)
#define CAN_F0R1_FB20_Msk    (0x1UL << CAN_F0R1_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F0R1_FB20        CAN_F0R1_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F0R1_FB21_Pos    (21U)
#define CAN_F0R1_FB21_Msk    (0x1UL << CAN_F0R1_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F0R1_FB21        CAN_F0R1_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F0R1_FB22_Pos    (22U)
#define CAN_F0R1_FB22_Msk    (0x1UL << CAN_F0R1_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F0R1_FB22        CAN_F0R1_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F0R1_FB23_Pos    (23U)
#define CAN_F0R1_FB23_Msk    (0x1UL << CAN_F0R1_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F0R1_FB23        CAN_F0R1_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F0R1_FB24_Pos    (24U)
#define CAN_F0R1_FB24_Msk    (0x1UL << CAN_F0R1_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F0R1_FB24        CAN_F0R1_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F0R1_FB25_Pos    (25U)
#define CAN_F0R1_FB25_Msk    (0x1UL << CAN_F0R1_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F0R1_FB25        CAN_F0R1_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F0R1_FB26_Pos    (26U)
#define CAN_F0R1_FB26_Msk    (0x1UL << CAN_F0R1_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F0R1_FB26        CAN_F0R1_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F0R1_FB27_Pos    (27U)
#define CAN_F0R1_FB27_Msk    (0x1UL << CAN_F0R1_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F0R1_FB27        CAN_F0R1_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F0R1_FB28_Pos    (28U)
#define CAN_F0R1_FB28_Msk    (0x1UL << CAN_F0R1_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F0R1_FB28        CAN_F0R1_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F0R1_FB29_Pos    (29U)
#define CAN_F0R1_FB29_Msk    (0x1UL << CAN_F0R1_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F0R1_FB29        CAN_F0R1_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F0R1_FB30_Pos    (30U)
#define CAN_F0R1_FB30_Msk    (0x1UL << CAN_F0R1_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F0R1_FB30        CAN_F0R1_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F0R1_FB31_Pos    (31U)
#define CAN_F0R1_FB31_Msk    (0x1UL << CAN_F0R1_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F0R1_FB31        CAN_F0R1_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F1R1 register  *******************/
#define CAN_F1R1_FB0_Pos     (0U)
#define CAN_F1R1_FB0_Msk     (0x1UL << CAN_F1R1_FB0_Pos)/*!< 0x00000001 */
#define CAN_F1R1_FB0         CAN_F1R1_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F1R1_FB1_Pos     (1U)
#define CAN_F1R1_FB1_Msk     (0x1UL << CAN_F1R1_FB1_Pos)/*!< 0x00000002 */
#define CAN_F1R1_FB1         CAN_F1R1_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F1R1_FB2_Pos     (2U)
#define CAN_F1R1_FB2_Msk     (0x1UL << CAN_F1R1_FB2_Pos)/*!< 0x00000004 */
#define CAN_F1R1_FB2         CAN_F1R1_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F1R1_FB3_Pos     (3U)
#define CAN_F1R1_FB3_Msk     (0x1UL << CAN_F1R1_FB3_Pos)/*!< 0x00000008 */
#define CAN_F1R1_FB3         CAN_F1R1_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F1R1_FB4_Pos     (4U)
#define CAN_F1R1_FB4_Msk     (0x1UL << CAN_F1R1_FB4_Pos)/*!< 0x00000010 */
#define CAN_F1R1_FB4         CAN_F1R1_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F1R1_FB5_Pos     (5U)
#define CAN_F1R1_FB5_Msk     (0x1UL << CAN_F1R1_FB5_Pos)/*!< 0x00000020 */
#define CAN_F1R1_FB5         CAN_F1R1_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F1R1_FB6_Pos     (6U)
#define CAN_F1R1_FB6_Msk     (0x1UL << CAN_F1R1_FB6_Pos)/*!< 0x00000040 */
#define CAN_F1R1_FB6         CAN_F1R1_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F1R1_FB7_Pos     (7U)
#define CAN_F1R1_FB7_Msk     (0x1UL << CAN_F1R1_FB7_Pos)/*!< 0x00000080 */
#define CAN_F1R1_FB7         CAN_F1R1_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F1R1_FB8_Pos     (8U)
#define CAN_F1R1_FB8_Msk     (0x1UL << CAN_F1R1_FB8_Pos)/*!< 0x00000100 */
#define CAN_F1R1_FB8         CAN_F1R1_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F1R1_FB9_Pos     (9U)
#define CAN_F1R1_FB9_Msk     (0x1UL << CAN_F1R1_FB9_Pos)/*!< 0x00000200 */
#define CAN_F1R1_FB9         CAN_F1R1_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F1R1_FB10_Pos    (10U)
#define CAN_F1R1_FB10_Msk    (0x1UL << CAN_F1R1_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F1R1_FB10        CAN_F1R1_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F1R1_FB11_Pos    (11U)
#define CAN_F1R1_FB11_Msk    (0x1UL << CAN_F1R1_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F1R1_FB11        CAN_F1R1_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F1R1_FB12_Pos    (12U)
#define CAN_F1R1_FB12_Msk    (0x1UL << CAN_F1R1_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F1R1_FB12        CAN_F1R1_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F1R1_FB13_Pos    (13U)
#define CAN_F1R1_FB13_Msk    (0x1UL << CAN_F1R1_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F1R1_FB13        CAN_F1R1_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F1R1_FB14_Pos    (14U)
#define CAN_F1R1_FB14_Msk    (0x1UL << CAN_F1R1_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F1R1_FB14        CAN_F1R1_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F1R1_FB15_Pos    (15U)
#define CAN_F1R1_FB15_Msk    (0x1UL << CAN_F1R1_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F1R1_FB15        CAN_F1R1_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F1R1_FB16_Pos    (16U)
#define CAN_F1R1_FB16_Msk    (0x1UL << CAN_F1R1_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F1R1_FB16        CAN_F1R1_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F1R1_FB17_Pos    (17U)
#define CAN_F1R1_FB17_Msk    (0x1UL << CAN_F1R1_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F1R1_FB17        CAN_F1R1_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F1R1_FB18_Pos    (18U)
#define CAN_F1R1_FB18_Msk    (0x1UL << CAN_F1R1_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F1R1_FB18        CAN_F1R1_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F1R1_FB19_Pos    (19U)
#define CAN_F1R1_FB19_Msk    (0x1UL << CAN_F1R1_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F1R1_FB19        CAN_F1R1_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F1R1_FB20_Pos    (20U)
#define CAN_F1R1_FB20_Msk    (0x1UL << CAN_F1R1_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F1R1_FB20        CAN_F1R1_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F1R1_FB21_Pos    (21U)
#define CAN_F1R1_FB21_Msk    (0x1UL << CAN_F1R1_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F1R1_FB21        CAN_F1R1_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F1R1_FB22_Pos    (22U)
#define CAN_F1R1_FB22_Msk    (0x1UL << CAN_F1R1_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F1R1_FB22        CAN_F1R1_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F1R1_FB23_Pos    (23U)
#define CAN_F1R1_FB23_Msk    (0x1UL << CAN_F1R1_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F1R1_FB23        CAN_F1R1_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F1R1_FB24_Pos    (24U)
#define CAN_F1R1_FB24_Msk    (0x1UL << CAN_F1R1_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F1R1_FB24        CAN_F1R1_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F1R1_FB25_Pos    (25U)
#define CAN_F1R1_FB25_Msk    (0x1UL << CAN_F1R1_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F1R1_FB25        CAN_F1R1_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F1R1_FB26_Pos    (26U)
#define CAN_F1R1_FB26_Msk    (0x1UL << CAN_F1R1_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F1R1_FB26        CAN_F1R1_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F1R1_FB27_Pos    (27U)
#define CAN_F1R1_FB27_Msk    (0x1UL << CAN_F1R1_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F1R1_FB27        CAN_F1R1_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F1R1_FB28_Pos    (28U)
#define CAN_F1R1_FB28_Msk    (0x1UL << CAN_F1R1_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F1R1_FB28        CAN_F1R1_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F1R1_FB29_Pos    (29U)
#define CAN_F1R1_FB29_Msk    (0x1UL << CAN_F1R1_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F1R1_FB29        CAN_F1R1_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F1R1_FB30_Pos    (30U)
#define CAN_F1R1_FB30_Msk    (0x1UL << CAN_F1R1_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F1R1_FB30        CAN_F1R1_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F1R1_FB31_Pos    (31U)
#define CAN_F1R1_FB31_Msk    (0x1UL << CAN_F1R1_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F1R1_FB31        CAN_F1R1_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F2R1 register  *******************/
#define CAN_F2R1_FB0_Pos     (0U)
#define CAN_F2R1_FB0_Msk     (0x1UL << CAN_F2R1_FB0_Pos)/*!< 0x00000001 */
#define CAN_F2R1_FB0         CAN_F2R1_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F2R1_FB1_Pos     (1U)
#define CAN_F2R1_FB1_Msk     (0x1UL << CAN_F2R1_FB1_Pos)/*!< 0x00000002 */
#define CAN_F2R1_FB1         CAN_F2R1_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F2R1_FB2_Pos     (2U)
#define CAN_F2R1_FB2_Msk     (0x1UL << CAN_F2R1_FB2_Pos)/*!< 0x00000004 */
#define CAN_F2R1_FB2         CAN_F2R1_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F2R1_FB3_Pos     (3U)
#define CAN_F2R1_FB3_Msk     (0x1UL << CAN_F2R1_FB3_Pos)/*!< 0x00000008 */
#define CAN_F2R1_FB3         CAN_F2R1_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F2R1_FB4_Pos     (4U)
#define CAN_F2R1_FB4_Msk     (0x1UL << CAN_F2R1_FB4_Pos)/*!< 0x00000010 */
#define CAN_F2R1_FB4         CAN_F2R1_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F2R1_FB5_Pos     (5U)
#define CAN_F2R1_FB5_Msk     (0x1UL << CAN_F2R1_FB5_Pos)/*!< 0x00000020 */
#define CAN_F2R1_FB5         CAN_F2R1_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F2R1_FB6_Pos     (6U)
#define CAN_F2R1_FB6_Msk     (0x1UL << CAN_F2R1_FB6_Pos)/*!< 0x00000040 */
#define CAN_F2R1_FB6         CAN_F2R1_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F2R1_FB7_Pos     (7U)
#define CAN_F2R1_FB7_Msk     (0x1UL << CAN_F2R1_FB7_Pos)/*!< 0x00000080 */
#define CAN_F2R1_FB7         CAN_F2R1_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F2R1_FB8_Pos     (8U)
#define CAN_F2R1_FB8_Msk     (0x1UL << CAN_F2R1_FB8_Pos)/*!< 0x00000100 */
#define CAN_F2R1_FB8         CAN_F2R1_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F2R1_FB9_Pos     (9U)
#define CAN_F2R1_FB9_Msk     (0x1UL << CAN_F2R1_FB9_Pos)/*!< 0x00000200 */
#define CAN_F2R1_FB9         CAN_F2R1_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F2R1_FB10_Pos    (10U)
#define CAN_F2R1_FB10_Msk    (0x1UL << CAN_F2R1_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F2R1_FB10        CAN_F2R1_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F2R1_FB11_Pos    (11U)
#define CAN_F2R1_FB11_Msk    (0x1UL << CAN_F2R1_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F2R1_FB11        CAN_F2R1_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F2R1_FB12_Pos    (12U)
#define CAN_F2R1_FB12_Msk    (0x1UL << CAN_F2R1_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F2R1_FB12        CAN_F2R1_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F2R1_FB13_Pos    (13U)
#define CAN_F2R1_FB13_Msk    (0x1UL << CAN_F2R1_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F2R1_FB13        CAN_F2R1_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F2R1_FB14_Pos    (14U)
#define CAN_F2R1_FB14_Msk    (0x1UL << CAN_F2R1_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F2R1_FB14        CAN_F2R1_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F2R1_FB15_Pos    (15U)
#define CAN_F2R1_FB15_Msk    (0x1UL << CAN_F2R1_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F2R1_FB15        CAN_F2R1_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F2R1_FB16_Pos    (16U)
#define CAN_F2R1_FB16_Msk    (0x1UL << CAN_F2R1_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F2R1_FB16        CAN_F2R1_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F2R1_FB17_Pos    (17U)
#define CAN_F2R1_FB17_Msk    (0x1UL << CAN_F2R1_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F2R1_FB17        CAN_F2R1_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F2R1_FB18_Pos    (18U)
#define CAN_F2R1_FB18_Msk    (0x1UL << CAN_F2R1_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F2R1_FB18        CAN_F2R1_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F2R1_FB19_Pos    (19U)
#define CAN_F2R1_FB19_Msk    (0x1UL << CAN_F2R1_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F2R1_FB19        CAN_F2R1_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F2R1_FB20_Pos    (20U)
#define CAN_F2R1_FB20_Msk    (0x1UL << CAN_F2R1_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F2R1_FB20        CAN_F2R1_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F2R1_FB21_Pos    (21U)
#define CAN_F2R1_FB21_Msk    (0x1UL << CAN_F2R1_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F2R1_FB21        CAN_F2R1_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F2R1_FB22_Pos    (22U)
#define CAN_F2R1_FB22_Msk    (0x1UL << CAN_F2R1_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F2R1_FB22        CAN_F2R1_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F2R1_FB23_Pos    (23U)
#define CAN_F2R1_FB23_Msk    (0x1UL << CAN_F2R1_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F2R1_FB23        CAN_F2R1_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F2R1_FB24_Pos    (24U)
#define CAN_F2R1_FB24_Msk    (0x1UL << CAN_F2R1_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F2R1_FB24        CAN_F2R1_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F2R1_FB25_Pos    (25U)
#define CAN_F2R1_FB25_Msk    (0x1UL << CAN_F2R1_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F2R1_FB25        CAN_F2R1_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F2R1_FB26_Pos    (26U)
#define CAN_F2R1_FB26_Msk    (0x1UL << CAN_F2R1_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F2R1_FB26        CAN_F2R1_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F2R1_FB27_Pos    (27U)
#define CAN_F2R1_FB27_Msk    (0x1UL << CAN_F2R1_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F2R1_FB27        CAN_F2R1_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F2R1_FB28_Pos    (28U)
#define CAN_F2R1_FB28_Msk    (0x1UL << CAN_F2R1_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F2R1_FB28        CAN_F2R1_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F2R1_FB29_Pos    (29U)
#define CAN_F2R1_FB29_Msk    (0x1UL << CAN_F2R1_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F2R1_FB29        CAN_F2R1_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F2R1_FB30_Pos    (30U)
#define CAN_F2R1_FB30_Msk    (0x1UL << CAN_F2R1_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F2R1_FB30        CAN_F2R1_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F2R1_FB31_Pos    (31U)
#define CAN_F2R1_FB31_Msk    (0x1UL << CAN_F2R1_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F2R1_FB31        CAN_F2R1_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F3R1 register  *******************/
#define CAN_F3R1_FB0_Pos     (0U)
#define CAN_F3R1_FB0_Msk     (0x1UL << CAN_F3R1_FB0_Pos)/*!< 0x00000001 */
#define CAN_F3R1_FB0         CAN_F3R1_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F3R1_FB1_Pos     (1U)
#define CAN_F3R1_FB1_Msk     (0x1UL << CAN_F3R1_FB1_Pos)/*!< 0x00000002 */
#define CAN_F3R1_FB1         CAN_F3R1_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F3R1_FB2_Pos     (2U)
#define CAN_F3R1_FB2_Msk     (0x1UL << CAN_F3R1_FB2_Pos)/*!< 0x00000004 */
#define CAN_F3R1_FB2         CAN_F3R1_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F3R1_FB3_Pos     (3U)
#define CAN_F3R1_FB3_Msk     (0x1UL << CAN_F3R1_FB3_Pos)/*!< 0x00000008 */
#define CAN_F3R1_FB3         CAN_F3R1_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F3R1_FB4_Pos     (4U)
#define CAN_F3R1_FB4_Msk     (0x1UL << CAN_F3R1_FB4_Pos)/*!< 0x00000010 */
#define CAN_F3R1_FB4         CAN_F3R1_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F3R1_FB5_Pos     (5U)
#define CAN_F3R1_FB5_Msk     (0x1UL << CAN_F3R1_FB5_Pos)/*!< 0x00000020 */
#define CAN_F3R1_FB5         CAN_F3R1_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F3R1_FB6_Pos     (6U)
#define CAN_F3R1_FB6_Msk     (0x1UL << CAN_F3R1_FB6_Pos)/*!< 0x00000040 */
#define CAN_F3R1_FB6         CAN_F3R1_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F3R1_FB7_Pos     (7U)
#define CAN_F3R1_FB7_Msk     (0x1UL << CAN_F3R1_FB7_Pos)/*!< 0x00000080 */
#define CAN_F3R1_FB7         CAN_F3R1_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F3R1_FB8_Pos     (8U)
#define CAN_F3R1_FB8_Msk     (0x1UL << CAN_F3R1_FB8_Pos)/*!< 0x00000100 */
#define CAN_F3R1_FB8         CAN_F3R1_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F3R1_FB9_Pos     (9U)
#define CAN_F3R1_FB9_Msk     (0x1UL << CAN_F3R1_FB9_Pos)/*!< 0x00000200 */
#define CAN_F3R1_FB9         CAN_F3R1_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F3R1_FB10_Pos    (10U)
#define CAN_F3R1_FB10_Msk    (0x1UL << CAN_F3R1_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F3R1_FB10        CAN_F3R1_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F3R1_FB11_Pos    (11U)
#define CAN_F3R1_FB11_Msk    (0x1UL << CAN_F3R1_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F3R1_FB11        CAN_F3R1_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F3R1_FB12_Pos    (12U)
#define CAN_F3R1_FB12_Msk    (0x1UL << CAN_F3R1_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F3R1_FB12        CAN_F3R1_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F3R1_FB13_Pos    (13U)
#define CAN_F3R1_FB13_Msk    (0x1UL << CAN_F3R1_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F3R1_FB13        CAN_F3R1_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F3R1_FB14_Pos    (14U)
#define CAN_F3R1_FB14_Msk    (0x1UL << CAN_F3R1_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F3R1_FB14        CAN_F3R1_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F3R1_FB15_Pos    (15U)
#define CAN_F3R1_FB15_Msk    (0x1UL << CAN_F3R1_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F3R1_FB15        CAN_F3R1_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F3R1_FB16_Pos    (16U)
#define CAN_F3R1_FB16_Msk    (0x1UL << CAN_F3R1_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F3R1_FB16        CAN_F3R1_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F3R1_FB17_Pos    (17U)
#define CAN_F3R1_FB17_Msk    (0x1UL << CAN_F3R1_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F3R1_FB17        CAN_F3R1_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F3R1_FB18_Pos    (18U)
#define CAN_F3R1_FB18_Msk    (0x1UL << CAN_F3R1_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F3R1_FB18        CAN_F3R1_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F3R1_FB19_Pos    (19U)
#define CAN_F3R1_FB19_Msk    (0x1UL << CAN_F3R1_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F3R1_FB19        CAN_F3R1_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F3R1_FB20_Pos    (20U)
#define CAN_F3R1_FB20_Msk    (0x1UL << CAN_F3R1_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F3R1_FB20        CAN_F3R1_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F3R1_FB21_Pos    (21U)
#define CAN_F3R1_FB21_Msk    (0x1UL << CAN_F3R1_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F3R1_FB21        CAN_F3R1_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F3R1_FB22_Pos    (22U)
#define CAN_F3R1_FB22_Msk    (0x1UL << CAN_F3R1_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F3R1_FB22        CAN_F3R1_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F3R1_FB23_Pos    (23U)
#define CAN_F3R1_FB23_Msk    (0x1UL << CAN_F3R1_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F3R1_FB23        CAN_F3R1_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F3R1_FB24_Pos    (24U)
#define CAN_F3R1_FB24_Msk    (0x1UL << CAN_F3R1_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F3R1_FB24        CAN_F3R1_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F3R1_FB25_Pos    (25U)
#define CAN_F3R1_FB25_Msk    (0x1UL << CAN_F3R1_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F3R1_FB25        CAN_F3R1_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F3R1_FB26_Pos    (26U)
#define CAN_F3R1_FB26_Msk    (0x1UL << CAN_F3R1_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F3R1_FB26        CAN_F3R1_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F3R1_FB27_Pos    (27U)
#define CAN_F3R1_FB27_Msk    (0x1UL << CAN_F3R1_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F3R1_FB27        CAN_F3R1_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F3R1_FB28_Pos    (28U)
#define CAN_F3R1_FB28_Msk    (0x1UL << CAN_F3R1_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F3R1_FB28        CAN_F3R1_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F3R1_FB29_Pos    (29U)
#define CAN_F3R1_FB29_Msk    (0x1UL << CAN_F3R1_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F3R1_FB29        CAN_F3R1_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F3R1_FB30_Pos    (30U)
#define CAN_F3R1_FB30_Msk    (0x1UL << CAN_F3R1_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F3R1_FB30        CAN_F3R1_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F3R1_FB31_Pos    (31U)
#define CAN_F3R1_FB31_Msk    (0x1UL << CAN_F3R1_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F3R1_FB31        CAN_F3R1_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F4R1 register  *******************/
#define CAN_F4R1_FB0_Pos     (0U)
#define CAN_F4R1_FB0_Msk     (0x1UL << CAN_F4R1_FB0_Pos)/*!< 0x00000001 */
#define CAN_F4R1_FB0         CAN_F4R1_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F4R1_FB1_Pos     (1U)
#define CAN_F4R1_FB1_Msk     (0x1UL << CAN_F4R1_FB1_Pos)/*!< 0x00000002 */
#define CAN_F4R1_FB1         CAN_F4R1_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F4R1_FB2_Pos     (2U)
#define CAN_F4R1_FB2_Msk     (0x1UL << CAN_F4R1_FB2_Pos)/*!< 0x00000004 */
#define CAN_F4R1_FB2         CAN_F4R1_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F4R1_FB3_Pos     (3U)
#define CAN_F4R1_FB3_Msk     (0x1UL << CAN_F4R1_FB3_Pos)/*!< 0x00000008 */
#define CAN_F4R1_FB3         CAN_F4R1_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F4R1_FB4_Pos     (4U)
#define CAN_F4R1_FB4_Msk     (0x1UL << CAN_F4R1_FB4_Pos)/*!< 0x00000010 */
#define CAN_F4R1_FB4         CAN_F4R1_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F4R1_FB5_Pos     (5U)
#define CAN_F4R1_FB5_Msk     (0x1UL << CAN_F4R1_FB5_Pos)/*!< 0x00000020 */
#define CAN_F4R1_FB5         CAN_F4R1_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F4R1_FB6_Pos     (6U)
#define CAN_F4R1_FB6_Msk     (0x1UL << CAN_F4R1_FB6_Pos)/*!< 0x00000040 */
#define CAN_F4R1_FB6         CAN_F4R1_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F4R1_FB7_Pos     (7U)
#define CAN_F4R1_FB7_Msk     (0x1UL << CAN_F4R1_FB7_Pos)/*!< 0x00000080 */
#define CAN_F4R1_FB7         CAN_F4R1_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F4R1_FB8_Pos     (8U)
#define CAN_F4R1_FB8_Msk     (0x1UL << CAN_F4R1_FB8_Pos)/*!< 0x00000100 */
#define CAN_F4R1_FB8         CAN_F4R1_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F4R1_FB9_Pos     (9U)
#define CAN_F4R1_FB9_Msk     (0x1UL << CAN_F4R1_FB9_Pos)/*!< 0x00000200 */
#define CAN_F4R1_FB9         CAN_F4R1_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F4R1_FB10_Pos    (10U)
#define CAN_F4R1_FB10_Msk    (0x1UL << CAN_F4R1_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F4R1_FB10        CAN_F4R1_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F4R1_FB11_Pos    (11U)
#define CAN_F4R1_FB11_Msk    (0x1UL << CAN_F4R1_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F4R1_FB11        CAN_F4R1_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F4R1_FB12_Pos    (12U)
#define CAN_F4R1_FB12_Msk    (0x1UL << CAN_F4R1_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F4R1_FB12        CAN_F4R1_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F4R1_FB13_Pos    (13U)
#define CAN_F4R1_FB13_Msk    (0x1UL << CAN_F4R1_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F4R1_FB13        CAN_F4R1_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F4R1_FB14_Pos    (14U)
#define CAN_F4R1_FB14_Msk    (0x1UL << CAN_F4R1_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F4R1_FB14        CAN_F4R1_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F4R1_FB15_Pos    (15U)
#define CAN_F4R1_FB15_Msk    (0x1UL << CAN_F4R1_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F4R1_FB15        CAN_F4R1_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F4R1_FB16_Pos    (16U)
#define CAN_F4R1_FB16_Msk    (0x1UL << CAN_F4R1_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F4R1_FB16        CAN_F4R1_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F4R1_FB17_Pos    (17U)
#define CAN_F4R1_FB17_Msk    (0x1UL << CAN_F4R1_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F4R1_FB17        CAN_F4R1_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F4R1_FB18_Pos    (18U)
#define CAN_F4R1_FB18_Msk    (0x1UL << CAN_F4R1_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F4R1_FB18        CAN_F4R1_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F4R1_FB19_Pos    (19U)
#define CAN_F4R1_FB19_Msk    (0x1UL << CAN_F4R1_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F4R1_FB19        CAN_F4R1_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F4R1_FB20_Pos    (20U)
#define CAN_F4R1_FB20_Msk    (0x1UL << CAN_F4R1_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F4R1_FB20        CAN_F4R1_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F4R1_FB21_Pos    (21U)
#define CAN_F4R1_FB21_Msk    (0x1UL << CAN_F4R1_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F4R1_FB21        CAN_F4R1_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F4R1_FB22_Pos    (22U)
#define CAN_F4R1_FB22_Msk    (0x1UL << CAN_F4R1_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F4R1_FB22        CAN_F4R1_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F4R1_FB23_Pos    (23U)
#define CAN_F4R1_FB23_Msk    (0x1UL << CAN_F4R1_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F4R1_FB23        CAN_F4R1_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F4R1_FB24_Pos    (24U)
#define CAN_F4R1_FB24_Msk    (0x1UL << CAN_F4R1_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F4R1_FB24        CAN_F4R1_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F4R1_FB25_Pos    (25U)
#define CAN_F4R1_FB25_Msk    (0x1UL << CAN_F4R1_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F4R1_FB25        CAN_F4R1_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F4R1_FB26_Pos    (26U)
#define CAN_F4R1_FB26_Msk    (0x1UL << CAN_F4R1_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F4R1_FB26        CAN_F4R1_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F4R1_FB27_Pos    (27U)
#define CAN_F4R1_FB27_Msk    (0x1UL << CAN_F4R1_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F4R1_FB27        CAN_F4R1_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F4R1_FB28_Pos    (28U)
#define CAN_F4R1_FB28_Msk    (0x1UL << CAN_F4R1_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F4R1_FB28        CAN_F4R1_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F4R1_FB29_Pos    (29U)
#define CAN_F4R1_FB29_Msk    (0x1UL << CAN_F4R1_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F4R1_FB29        CAN_F4R1_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F4R1_FB30_Pos    (30U)
#define CAN_F4R1_FB30_Msk    (0x1UL << CAN_F4R1_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F4R1_FB30        CAN_F4R1_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F4R1_FB31_Pos    (31U)
#define CAN_F4R1_FB31_Msk    (0x1UL << CAN_F4R1_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F4R1_FB31        CAN_F4R1_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F5R1 register  *******************/
#define CAN_F5R1_FB0_Pos     (0U)
#define CAN_F5R1_FB0_Msk     (0x1UL << CAN_F5R1_FB0_Pos)/*!< 0x00000001 */
#define CAN_F5R1_FB0         CAN_F5R1_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F5R1_FB1_Pos     (1U)
#define CAN_F5R1_FB1_Msk     (0x1UL << CAN_F5R1_FB1_Pos)/*!< 0x00000002 */
#define CAN_F5R1_FB1         CAN_F5R1_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F5R1_FB2_Pos     (2U)
#define CAN_F5R1_FB2_Msk     (0x1UL << CAN_F5R1_FB2_Pos)/*!< 0x00000004 */
#define CAN_F5R1_FB2         CAN_F5R1_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F5R1_FB3_Pos     (3U)
#define CAN_F5R1_FB3_Msk     (0x1UL << CAN_F5R1_FB3_Pos)/*!< 0x00000008 */
#define CAN_F5R1_FB3         CAN_F5R1_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F5R1_FB4_Pos     (4U)
#define CAN_F5R1_FB4_Msk     (0x1UL << CAN_F5R1_FB4_Pos)/*!< 0x00000010 */
#define CAN_F5R1_FB4         CAN_F5R1_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F5R1_FB5_Pos     (5U)
#define CAN_F5R1_FB5_Msk     (0x1UL << CAN_F5R1_FB5_Pos)/*!< 0x00000020 */
#define CAN_F5R1_FB5         CAN_F5R1_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F5R1_FB6_Pos     (6U)
#define CAN_F5R1_FB6_Msk     (0x1UL << CAN_F5R1_FB6_Pos)/*!< 0x00000040 */
#define CAN_F5R1_FB6         CAN_F5R1_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F5R1_FB7_Pos     (7U)
#define CAN_F5R1_FB7_Msk     (0x1UL << CAN_F5R1_FB7_Pos)/*!< 0x00000080 */
#define CAN_F5R1_FB7         CAN_F5R1_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F5R1_FB8_Pos     (8U)
#define CAN_F5R1_FB8_Msk     (0x1UL << CAN_F5R1_FB8_Pos)/*!< 0x00000100 */
#define CAN_F5R1_FB8         CAN_F5R1_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F5R1_FB9_Pos     (9U)
#define CAN_F5R1_FB9_Msk     (0x1UL << CAN_F5R1_FB9_Pos)/*!< 0x00000200 */
#define CAN_F5R1_FB9         CAN_F5R1_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F5R1_FB10_Pos    (10U)
#define CAN_F5R1_FB10_Msk    (0x1UL << CAN_F5R1_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F5R1_FB10        CAN_F5R1_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F5R1_FB11_Pos    (11U)
#define CAN_F5R1_FB11_Msk    (0x1UL << CAN_F5R1_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F5R1_FB11        CAN_F5R1_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F5R1_FB12_Pos    (12U)
#define CAN_F5R1_FB12_Msk    (0x1UL << CAN_F5R1_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F5R1_FB12        CAN_F5R1_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F5R1_FB13_Pos    (13U)
#define CAN_F5R1_FB13_Msk    (0x1UL << CAN_F5R1_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F5R1_FB13        CAN_F5R1_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F5R1_FB14_Pos    (14U)
#define CAN_F5R1_FB14_Msk    (0x1UL << CAN_F5R1_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F5R1_FB14        CAN_F5R1_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F5R1_FB15_Pos    (15U)
#define CAN_F5R1_FB15_Msk    (0x1UL << CAN_F5R1_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F5R1_FB15        CAN_F5R1_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F5R1_FB16_Pos    (16U)
#define CAN_F5R1_FB16_Msk    (0x1UL << CAN_F5R1_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F5R1_FB16        CAN_F5R1_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F5R1_FB17_Pos    (17U)
#define CAN_F5R1_FB17_Msk    (0x1UL << CAN_F5R1_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F5R1_FB17        CAN_F5R1_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F5R1_FB18_Pos    (18U)
#define CAN_F5R1_FB18_Msk    (0x1UL << CAN_F5R1_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F5R1_FB18        CAN_F5R1_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F5R1_FB19_Pos    (19U)
#define CAN_F5R1_FB19_Msk    (0x1UL << CAN_F5R1_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F5R1_FB19        CAN_F5R1_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F5R1_FB20_Pos    (20U)
#define CAN_F5R1_FB20_Msk    (0x1UL << CAN_F5R1_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F5R1_FB20        CAN_F5R1_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F5R1_FB21_Pos    (21U)
#define CAN_F5R1_FB21_Msk    (0x1UL << CAN_F5R1_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F5R1_FB21        CAN_F5R1_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F5R1_FB22_Pos    (22U)
#define CAN_F5R1_FB22_Msk    (0x1UL << CAN_F5R1_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F5R1_FB22        CAN_F5R1_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F5R1_FB23_Pos    (23U)
#define CAN_F5R1_FB23_Msk    (0x1UL << CAN_F5R1_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F5R1_FB23        CAN_F5R1_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F5R1_FB24_Pos    (24U)
#define CAN_F5R1_FB24_Msk    (0x1UL << CAN_F5R1_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F5R1_FB24        CAN_F5R1_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F5R1_FB25_Pos    (25U)
#define CAN_F5R1_FB25_Msk    (0x1UL << CAN_F5R1_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F5R1_FB25        CAN_F5R1_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F5R1_FB26_Pos    (26U)
#define CAN_F5R1_FB26_Msk    (0x1UL << CAN_F5R1_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F5R1_FB26        CAN_F5R1_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F5R1_FB27_Pos    (27U)
#define CAN_F5R1_FB27_Msk    (0x1UL << CAN_F5R1_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F5R1_FB27        CAN_F5R1_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F5R1_FB28_Pos    (28U)
#define CAN_F5R1_FB28_Msk    (0x1UL << CAN_F5R1_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F5R1_FB28        CAN_F5R1_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F5R1_FB29_Pos    (29U)
#define CAN_F5R1_FB29_Msk    (0x1UL << CAN_F5R1_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F5R1_FB29        CAN_F5R1_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F5R1_FB30_Pos    (30U)
#define CAN_F5R1_FB30_Msk    (0x1UL << CAN_F5R1_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F5R1_FB30        CAN_F5R1_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F5R1_FB31_Pos    (31U)
#define CAN_F5R1_FB31_Msk    (0x1UL << CAN_F5R1_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F5R1_FB31        CAN_F5R1_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F6R1 register  *******************/
#define CAN_F6R1_FB0_Pos     (0U)
#define CAN_F6R1_FB0_Msk     (0x1UL << CAN_F6R1_FB0_Pos)/*!< 0x00000001 */
#define CAN_F6R1_FB0         CAN_F6R1_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F6R1_FB1_Pos     (1U)
#define CAN_F6R1_FB1_Msk     (0x1UL << CAN_F6R1_FB1_Pos)/*!< 0x00000002 */
#define CAN_F6R1_FB1         CAN_F6R1_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F6R1_FB2_Pos     (2U)
#define CAN_F6R1_FB2_Msk     (0x1UL << CAN_F6R1_FB2_Pos)/*!< 0x00000004 */
#define CAN_F6R1_FB2         CAN_F6R1_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F6R1_FB3_Pos     (3U)
#define CAN_F6R1_FB3_Msk     (0x1UL << CAN_F6R1_FB3_Pos)/*!< 0x00000008 */
#define CAN_F6R1_FB3         CAN_F6R1_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F6R1_FB4_Pos     (4U)
#define CAN_F6R1_FB4_Msk     (0x1UL << CAN_F6R1_FB4_Pos)/*!< 0x00000010 */
#define CAN_F6R1_FB4         CAN_F6R1_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F6R1_FB5_Pos     (5U)
#define CAN_F6R1_FB5_Msk     (0x1UL << CAN_F6R1_FB5_Pos)/*!< 0x00000020 */
#define CAN_F6R1_FB5         CAN_F6R1_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F6R1_FB6_Pos     (6U)
#define CAN_F6R1_FB6_Msk     (0x1UL << CAN_F6R1_FB6_Pos)/*!< 0x00000040 */
#define CAN_F6R1_FB6         CAN_F6R1_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F6R1_FB7_Pos     (7U)
#define CAN_F6R1_FB7_Msk     (0x1UL << CAN_F6R1_FB7_Pos)/*!< 0x00000080 */
#define CAN_F6R1_FB7         CAN_F6R1_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F6R1_FB8_Pos     (8U)
#define CAN_F6R1_FB8_Msk     (0x1UL << CAN_F6R1_FB8_Pos)/*!< 0x00000100 */
#define CAN_F6R1_FB8         CAN_F6R1_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F6R1_FB9_Pos     (9U)
#define CAN_F6R1_FB9_Msk     (0x1UL << CAN_F6R1_FB9_Pos)/*!< 0x00000200 */
#define CAN_F6R1_FB9         CAN_F6R1_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F6R1_FB10_Pos    (10U)
#define CAN_F6R1_FB10_Msk    (0x1UL << CAN_F6R1_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F6R1_FB10        CAN_F6R1_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F6R1_FB11_Pos    (11U)
#define CAN_F6R1_FB11_Msk    (0x1UL << CAN_F6R1_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F6R1_FB11        CAN_F6R1_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F6R1_FB12_Pos    (12U)
#define CAN_F6R1_FB12_Msk    (0x1UL << CAN_F6R1_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F6R1_FB12        CAN_F6R1_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F6R1_FB13_Pos    (13U)
#define CAN_F6R1_FB13_Msk    (0x1UL << CAN_F6R1_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F6R1_FB13        CAN_F6R1_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F6R1_FB14_Pos    (14U)
#define CAN_F6R1_FB14_Msk    (0x1UL << CAN_F6R1_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F6R1_FB14        CAN_F6R1_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F6R1_FB15_Pos    (15U)
#define CAN_F6R1_FB15_Msk    (0x1UL << CAN_F6R1_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F6R1_FB15        CAN_F6R1_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F6R1_FB16_Pos    (16U)
#define CAN_F6R1_FB16_Msk    (0x1UL << CAN_F6R1_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F6R1_FB16        CAN_F6R1_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F6R1_FB17_Pos    (17U)
#define CAN_F6R1_FB17_Msk    (0x1UL << CAN_F6R1_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F6R1_FB17        CAN_F6R1_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F6R1_FB18_Pos    (18U)
#define CAN_F6R1_FB18_Msk    (0x1UL << CAN_F6R1_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F6R1_FB18        CAN_F6R1_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F6R1_FB19_Pos    (19U)
#define CAN_F6R1_FB19_Msk    (0x1UL << CAN_F6R1_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F6R1_FB19        CAN_F6R1_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F6R1_FB20_Pos    (20U)
#define CAN_F6R1_FB20_Msk    (0x1UL << CAN_F6R1_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F6R1_FB20        CAN_F6R1_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F6R1_FB21_Pos    (21U)
#define CAN_F6R1_FB21_Msk    (0x1UL << CAN_F6R1_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F6R1_FB21        CAN_F6R1_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F6R1_FB22_Pos    (22U)
#define CAN_F6R1_FB22_Msk    (0x1UL << CAN_F6R1_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F6R1_FB22        CAN_F6R1_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F6R1_FB23_Pos    (23U)
#define CAN_F6R1_FB23_Msk    (0x1UL << CAN_F6R1_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F6R1_FB23        CAN_F6R1_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F6R1_FB24_Pos    (24U)
#define CAN_F6R1_FB24_Msk    (0x1UL << CAN_F6R1_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F6R1_FB24        CAN_F6R1_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F6R1_FB25_Pos    (25U)
#define CAN_F6R1_FB25_Msk    (0x1UL << CAN_F6R1_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F6R1_FB25        CAN_F6R1_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F6R1_FB26_Pos    (26U)
#define CAN_F6R1_FB26_Msk    (0x1UL << CAN_F6R1_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F6R1_FB26        CAN_F6R1_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F6R1_FB27_Pos    (27U)
#define CAN_F6R1_FB27_Msk    (0x1UL << CAN_F6R1_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F6R1_FB27        CAN_F6R1_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F6R1_FB28_Pos    (28U)
#define CAN_F6R1_FB28_Msk    (0x1UL << CAN_F6R1_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F6R1_FB28        CAN_F6R1_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F6R1_FB29_Pos    (29U)
#define CAN_F6R1_FB29_Msk    (0x1UL << CAN_F6R1_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F6R1_FB29        CAN_F6R1_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F6R1_FB30_Pos    (30U)
#define CAN_F6R1_FB30_Msk    (0x1UL << CAN_F6R1_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F6R1_FB30        CAN_F6R1_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F6R1_FB31_Pos    (31U)
#define CAN_F6R1_FB31_Msk    (0x1UL << CAN_F6R1_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F6R1_FB31        CAN_F6R1_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F7R1 register  *******************/
#define CAN_F7R1_FB0_Pos     (0U)
#define CAN_F7R1_FB0_Msk     (0x1UL << CAN_F7R1_FB0_Pos)/*!< 0x00000001 */
#define CAN_F7R1_FB0         CAN_F7R1_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F7R1_FB1_Pos     (1U)
#define CAN_F7R1_FB1_Msk     (0x1UL << CAN_F7R1_FB1_Pos)/*!< 0x00000002 */
#define CAN_F7R1_FB1         CAN_F7R1_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F7R1_FB2_Pos     (2U)
#define CAN_F7R1_FB2_Msk     (0x1UL << CAN_F7R1_FB2_Pos)/*!< 0x00000004 */
#define CAN_F7R1_FB2         CAN_F7R1_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F7R1_FB3_Pos     (3U)
#define CAN_F7R1_FB3_Msk     (0x1UL << CAN_F7R1_FB3_Pos)/*!< 0x00000008 */
#define CAN_F7R1_FB3         CAN_F7R1_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F7R1_FB4_Pos     (4U)
#define CAN_F7R1_FB4_Msk     (0x1UL << CAN_F7R1_FB4_Pos)/*!< 0x00000010 */
#define CAN_F7R1_FB4         CAN_F7R1_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F7R1_FB5_Pos     (5U)
#define CAN_F7R1_FB5_Msk     (0x1UL << CAN_F7R1_FB5_Pos)/*!< 0x00000020 */
#define CAN_F7R1_FB5         CAN_F7R1_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F7R1_FB6_Pos     (6U)
#define CAN_F7R1_FB6_Msk     (0x1UL << CAN_F7R1_FB6_Pos)/*!< 0x00000040 */
#define CAN_F7R1_FB6         CAN_F7R1_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F7R1_FB7_Pos     (7U)
#define CAN_F7R1_FB7_Msk     (0x1UL << CAN_F7R1_FB7_Pos)/*!< 0x00000080 */
#define CAN_F7R1_FB7         CAN_F7R1_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F7R1_FB8_Pos     (8U)
#define CAN_F7R1_FB8_Msk     (0x1UL << CAN_F7R1_FB8_Pos)/*!< 0x00000100 */
#define CAN_F7R1_FB8         CAN_F7R1_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F7R1_FB9_Pos     (9U)
#define CAN_F7R1_FB9_Msk     (0x1UL << CAN_F7R1_FB9_Pos)/*!< 0x00000200 */
#define CAN_F7R1_FB9         CAN_F7R1_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F7R1_FB10_Pos    (10U)
#define CAN_F7R1_FB10_Msk    (0x1UL << CAN_F7R1_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F7R1_FB10        CAN_F7R1_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F7R1_FB11_Pos    (11U)
#define CAN_F7R1_FB11_Msk    (0x1UL << CAN_F7R1_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F7R1_FB11        CAN_F7R1_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F7R1_FB12_Pos    (12U)
#define CAN_F7R1_FB12_Msk    (0x1UL << CAN_F7R1_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F7R1_FB12        CAN_F7R1_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F7R1_FB13_Pos    (13U)
#define CAN_F7R1_FB13_Msk    (0x1UL << CAN_F7R1_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F7R1_FB13        CAN_F7R1_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F7R1_FB14_Pos    (14U)
#define CAN_F7R1_FB14_Msk    (0x1UL << CAN_F7R1_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F7R1_FB14        CAN_F7R1_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F7R1_FB15_Pos    (15U)
#define CAN_F7R1_FB15_Msk    (0x1UL << CAN_F7R1_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F7R1_FB15        CAN_F7R1_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F7R1_FB16_Pos    (16U)
#define CAN_F7R1_FB16_Msk    (0x1UL << CAN_F7R1_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F7R1_FB16        CAN_F7R1_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F7R1_FB17_Pos    (17U)
#define CAN_F7R1_FB17_Msk    (0x1UL << CAN_F7R1_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F7R1_FB17        CAN_F7R1_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F7R1_FB18_Pos    (18U)
#define CAN_F7R1_FB18_Msk    (0x1UL << CAN_F7R1_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F7R1_FB18        CAN_F7R1_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F7R1_FB19_Pos    (19U)
#define CAN_F7R1_FB19_Msk    (0x1UL << CAN_F7R1_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F7R1_FB19        CAN_F7R1_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F7R1_FB20_Pos    (20U)
#define CAN_F7R1_FB20_Msk    (0x1UL << CAN_F7R1_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F7R1_FB20        CAN_F7R1_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F7R1_FB21_Pos    (21U)
#define CAN_F7R1_FB21_Msk    (0x1UL << CAN_F7R1_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F7R1_FB21        CAN_F7R1_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F7R1_FB22_Pos    (22U)
#define CAN_F7R1_FB22_Msk    (0x1UL << CAN_F7R1_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F7R1_FB22        CAN_F7R1_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F7R1_FB23_Pos    (23U)
#define CAN_F7R1_FB23_Msk    (0x1UL << CAN_F7R1_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F7R1_FB23        CAN_F7R1_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F7R1_FB24_Pos    (24U)
#define CAN_F7R1_FB24_Msk    (0x1UL << CAN_F7R1_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F7R1_FB24        CAN_F7R1_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F7R1_FB25_Pos    (25U)
#define CAN_F7R1_FB25_Msk    (0x1UL << CAN_F7R1_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F7R1_FB25        CAN_F7R1_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F7R1_FB26_Pos    (26U)
#define CAN_F7R1_FB26_Msk    (0x1UL << CAN_F7R1_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F7R1_FB26        CAN_F7R1_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F7R1_FB27_Pos    (27U)
#define CAN_F7R1_FB27_Msk    (0x1UL << CAN_F7R1_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F7R1_FB27        CAN_F7R1_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F7R1_FB28_Pos    (28U)
#define CAN_F7R1_FB28_Msk    (0x1UL << CAN_F7R1_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F7R1_FB28        CAN_F7R1_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F7R1_FB29_Pos    (29U)
#define CAN_F7R1_FB29_Msk    (0x1UL << CAN_F7R1_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F7R1_FB29        CAN_F7R1_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F7R1_FB30_Pos    (30U)
#define CAN_F7R1_FB30_Msk    (0x1UL << CAN_F7R1_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F7R1_FB30        CAN_F7R1_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F7R1_FB31_Pos    (31U)
#define CAN_F7R1_FB31_Msk    (0x1UL << CAN_F7R1_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F7R1_FB31        CAN_F7R1_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F8R1 register  *******************/
#define CAN_F8R1_FB0_Pos     (0U)
#define CAN_F8R1_FB0_Msk     (0x1UL << CAN_F8R1_FB0_Pos)/*!< 0x00000001 */
#define CAN_F8R1_FB0         CAN_F8R1_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F8R1_FB1_Pos     (1U)
#define CAN_F8R1_FB1_Msk     (0x1UL << CAN_F8R1_FB1_Pos)/*!< 0x00000002 */
#define CAN_F8R1_FB1         CAN_F8R1_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F8R1_FB2_Pos     (2U)
#define CAN_F8R1_FB2_Msk     (0x1UL << CAN_F8R1_FB2_Pos)/*!< 0x00000004 */
#define CAN_F8R1_FB2         CAN_F8R1_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F8R1_FB3_Pos     (3U)
#define CAN_F8R1_FB3_Msk     (0x1UL << CAN_F8R1_FB3_Pos)/*!< 0x00000008 */
#define CAN_F8R1_FB3         CAN_F8R1_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F8R1_FB4_Pos     (4U)
#define CAN_F8R1_FB4_Msk     (0x1UL << CAN_F8R1_FB4_Pos)/*!< 0x00000010 */
#define CAN_F8R1_FB4         CAN_F8R1_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F8R1_FB5_Pos     (5U)
#define CAN_F8R1_FB5_Msk     (0x1UL << CAN_F8R1_FB5_Pos)/*!< 0x00000020 */
#define CAN_F8R1_FB5         CAN_F8R1_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F8R1_FB6_Pos     (6U)
#define CAN_F8R1_FB6_Msk     (0x1UL << CAN_F8R1_FB6_Pos)/*!< 0x00000040 */
#define CAN_F8R1_FB6         CAN_F8R1_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F8R1_FB7_Pos     (7U)
#define CAN_F8R1_FB7_Msk     (0x1UL << CAN_F8R1_FB7_Pos)/*!< 0x00000080 */
#define CAN_F8R1_FB7         CAN_F8R1_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F8R1_FB8_Pos     (8U)
#define CAN_F8R1_FB8_Msk     (0x1UL << CAN_F8R1_FB8_Pos)/*!< 0x00000100 */
#define CAN_F8R1_FB8         CAN_F8R1_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F8R1_FB9_Pos     (9U)
#define CAN_F8R1_FB9_Msk     (0x1UL << CAN_F8R1_FB9_Pos)/*!< 0x00000200 */
#define CAN_F8R1_FB9         CAN_F8R1_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F8R1_FB10_Pos    (10U)
#define CAN_F8R1_FB10_Msk    (0x1UL << CAN_F8R1_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F8R1_FB10        CAN_F8R1_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F8R1_FB11_Pos    (11U)
#define CAN_F8R1_FB11_Msk    (0x1UL << CAN_F8R1_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F8R1_FB11        CAN_F8R1_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F8R1_FB12_Pos    (12U)
#define CAN_F8R1_FB12_Msk    (0x1UL << CAN_F8R1_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F8R1_FB12        CAN_F8R1_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F8R1_FB13_Pos    (13U)
#define CAN_F8R1_FB13_Msk    (0x1UL << CAN_F8R1_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F8R1_FB13        CAN_F8R1_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F8R1_FB14_Pos    (14U)
#define CAN_F8R1_FB14_Msk    (0x1UL << CAN_F8R1_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F8R1_FB14        CAN_F8R1_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F8R1_FB15_Pos    (15U)
#define CAN_F8R1_FB15_Msk    (0x1UL << CAN_F8R1_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F8R1_FB15        CAN_F8R1_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F8R1_FB16_Pos    (16U)
#define CAN_F8R1_FB16_Msk    (0x1UL << CAN_F8R1_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F8R1_FB16        CAN_F8R1_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F8R1_FB17_Pos    (17U)
#define CAN_F8R1_FB17_Msk    (0x1UL << CAN_F8R1_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F8R1_FB17        CAN_F8R1_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F8R1_FB18_Pos    (18U)
#define CAN_F8R1_FB18_Msk    (0x1UL << CAN_F8R1_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F8R1_FB18        CAN_F8R1_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F8R1_FB19_Pos    (19U)
#define CAN_F8R1_FB19_Msk    (0x1UL << CAN_F8R1_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F8R1_FB19        CAN_F8R1_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F8R1_FB20_Pos    (20U)
#define CAN_F8R1_FB20_Msk    (0x1UL << CAN_F8R1_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F8R1_FB20        CAN_F8R1_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F8R1_FB21_Pos    (21U)
#define CAN_F8R1_FB21_Msk    (0x1UL << CAN_F8R1_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F8R1_FB21        CAN_F8R1_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F8R1_FB22_Pos    (22U)
#define CAN_F8R1_FB22_Msk    (0x1UL << CAN_F8R1_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F8R1_FB22        CAN_F8R1_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F8R1_FB23_Pos    (23U)
#define CAN_F8R1_FB23_Msk    (0x1UL << CAN_F8R1_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F8R1_FB23        CAN_F8R1_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F8R1_FB24_Pos    (24U)
#define CAN_F8R1_FB24_Msk    (0x1UL << CAN_F8R1_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F8R1_FB24        CAN_F8R1_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F8R1_FB25_Pos    (25U)
#define CAN_F8R1_FB25_Msk    (0x1UL << CAN_F8R1_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F8R1_FB25        CAN_F8R1_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F8R1_FB26_Pos    (26U)
#define CAN_F8R1_FB26_Msk    (0x1UL << CAN_F8R1_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F8R1_FB26        CAN_F8R1_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F8R1_FB27_Pos    (27U)
#define CAN_F8R1_FB27_Msk    (0x1UL << CAN_F8R1_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F8R1_FB27        CAN_F8R1_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F8R1_FB28_Pos    (28U)
#define CAN_F8R1_FB28_Msk    (0x1UL << CAN_F8R1_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F8R1_FB28        CAN_F8R1_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F8R1_FB29_Pos    (29U)
#define CAN_F8R1_FB29_Msk    (0x1UL << CAN_F8R1_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F8R1_FB29        CAN_F8R1_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F8R1_FB30_Pos    (30U)
#define CAN_F8R1_FB30_Msk    (0x1UL << CAN_F8R1_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F8R1_FB30        CAN_F8R1_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F8R1_FB31_Pos    (31U)
#define CAN_F8R1_FB31_Msk    (0x1UL << CAN_F8R1_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F8R1_FB31        CAN_F8R1_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F9R1 register  *******************/
#define CAN_F9R1_FB0_Pos     (0U)
#define CAN_F9R1_FB0_Msk     (0x1UL << CAN_F9R1_FB0_Pos)/*!< 0x00000001 */
#define CAN_F9R1_FB0         CAN_F9R1_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F9R1_FB1_Pos     (1U)
#define CAN_F9R1_FB1_Msk     (0x1UL << CAN_F9R1_FB1_Pos)/*!< 0x00000002 */
#define CAN_F9R1_FB1         CAN_F9R1_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F9R1_FB2_Pos     (2U)
#define CAN_F9R1_FB2_Msk     (0x1UL << CAN_F9R1_FB2_Pos)/*!< 0x00000004 */
#define CAN_F9R1_FB2         CAN_F9R1_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F9R1_FB3_Pos     (3U)
#define CAN_F9R1_FB3_Msk     (0x1UL << CAN_F9R1_FB3_Pos)/*!< 0x00000008 */
#define CAN_F9R1_FB3         CAN_F9R1_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F9R1_FB4_Pos     (4U)
#define CAN_F9R1_FB4_Msk     (0x1UL << CAN_F9R1_FB4_Pos)/*!< 0x00000010 */
#define CAN_F9R1_FB4         CAN_F9R1_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F9R1_FB5_Pos     (5U)
#define CAN_F9R1_FB5_Msk     (0x1UL << CAN_F9R1_FB5_Pos)/*!< 0x00000020 */
#define CAN_F9R1_FB5         CAN_F9R1_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F9R1_FB6_Pos     (6U)
#define CAN_F9R1_FB6_Msk     (0x1UL << CAN_F9R1_FB6_Pos)/*!< 0x00000040 */
#define CAN_F9R1_FB6         CAN_F9R1_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F9R1_FB7_Pos     (7U)
#define CAN_F9R1_FB7_Msk     (0x1UL << CAN_F9R1_FB7_Pos)/*!< 0x00000080 */
#define CAN_F9R1_FB7         CAN_F9R1_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F9R1_FB8_Pos     (8U)
#define CAN_F9R1_FB8_Msk     (0x1UL << CAN_F9R1_FB8_Pos)/*!< 0x00000100 */
#define CAN_F9R1_FB8         CAN_F9R1_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F9R1_FB9_Pos     (9U)
#define CAN_F9R1_FB9_Msk     (0x1UL << CAN_F9R1_FB9_Pos)/*!< 0x00000200 */
#define CAN_F9R1_FB9         CAN_F9R1_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F9R1_FB10_Pos    (10U)
#define CAN_F9R1_FB10_Msk    (0x1UL << CAN_F9R1_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F9R1_FB10        CAN_F9R1_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F9R1_FB11_Pos    (11U)
#define CAN_F9R1_FB11_Msk    (0x1UL << CAN_F9R1_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F9R1_FB11        CAN_F9R1_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F9R1_FB12_Pos    (12U)
#define CAN_F9R1_FB12_Msk    (0x1UL << CAN_F9R1_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F9R1_FB12        CAN_F9R1_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F9R1_FB13_Pos    (13U)
#define CAN_F9R1_FB13_Msk    (0x1UL << CAN_F9R1_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F9R1_FB13        CAN_F9R1_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F9R1_FB14_Pos    (14U)
#define CAN_F9R1_FB14_Msk    (0x1UL << CAN_F9R1_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F9R1_FB14        CAN_F9R1_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F9R1_FB15_Pos    (15U)
#define CAN_F9R1_FB15_Msk    (0x1UL << CAN_F9R1_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F9R1_FB15        CAN_F9R1_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F9R1_FB16_Pos    (16U)
#define CAN_F9R1_FB16_Msk    (0x1UL << CAN_F9R1_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F9R1_FB16        CAN_F9R1_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F9R1_FB17_Pos    (17U)
#define CAN_F9R1_FB17_Msk    (0x1UL << CAN_F9R1_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F9R1_FB17        CAN_F9R1_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F9R1_FB18_Pos    (18U)
#define CAN_F9R1_FB18_Msk    (0x1UL << CAN_F9R1_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F9R1_FB18        CAN_F9R1_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F9R1_FB19_Pos    (19U)
#define CAN_F9R1_FB19_Msk    (0x1UL << CAN_F9R1_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F9R1_FB19        CAN_F9R1_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F9R1_FB20_Pos    (20U)
#define CAN_F9R1_FB20_Msk    (0x1UL << CAN_F9R1_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F9R1_FB20        CAN_F9R1_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F9R1_FB21_Pos    (21U)
#define CAN_F9R1_FB21_Msk    (0x1UL << CAN_F9R1_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F9R1_FB21        CAN_F9R1_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F9R1_FB22_Pos    (22U)
#define CAN_F9R1_FB22_Msk    (0x1UL << CAN_F9R1_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F9R1_FB22        CAN_F9R1_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F9R1_FB23_Pos    (23U)
#define CAN_F9R1_FB23_Msk    (0x1UL << CAN_F9R1_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F9R1_FB23        CAN_F9R1_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F9R1_FB24_Pos    (24U)
#define CAN_F9R1_FB24_Msk    (0x1UL << CAN_F9R1_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F9R1_FB24        CAN_F9R1_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F9R1_FB25_Pos    (25U)
#define CAN_F9R1_FB25_Msk    (0x1UL << CAN_F9R1_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F9R1_FB25        CAN_F9R1_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F9R1_FB26_Pos    (26U)
#define CAN_F9R1_FB26_Msk    (0x1UL << CAN_F9R1_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F9R1_FB26        CAN_F9R1_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F9R1_FB27_Pos    (27U)
#define CAN_F9R1_FB27_Msk    (0x1UL << CAN_F9R1_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F9R1_FB27        CAN_F9R1_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F9R1_FB28_Pos    (28U)
#define CAN_F9R1_FB28_Msk    (0x1UL << CAN_F9R1_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F9R1_FB28        CAN_F9R1_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F9R1_FB29_Pos    (29U)
#define CAN_F9R1_FB29_Msk    (0x1UL << CAN_F9R1_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F9R1_FB29        CAN_F9R1_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F9R1_FB30_Pos    (30U)
#define CAN_F9R1_FB30_Msk    (0x1UL << CAN_F9R1_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F9R1_FB30        CAN_F9R1_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F9R1_FB31_Pos    (31U)
#define CAN_F9R1_FB31_Msk    (0x1UL << CAN_F9R1_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F9R1_FB31        CAN_F9R1_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F10R1 register  ******************/
#define CAN_F10R1_FB0_Pos     (0U)
#define CAN_F10R1_FB0_Msk     (0x1UL << CAN_F10R1_FB0_Pos)	/*!< 0x00000001 */
#define CAN_F10R1_FB0         CAN_F10R1_FB0_Msk				/*!<Filter bit 0 */
#define CAN_F10R1_FB1_Pos     (1U)
#define CAN_F10R1_FB1_Msk     (0x1UL << CAN_F10R1_FB1_Pos)	/*!< 0x00000002 */
#define CAN_F10R1_FB1         CAN_F10R1_FB1_Msk				/*!<Filter bit 1 */
#define CAN_F10R1_FB2_Pos     (2U)
#define CAN_F10R1_FB2_Msk     (0x1UL << CAN_F10R1_FB2_Pos)	/*!< 0x00000004 */
#define CAN_F10R1_FB2         CAN_F10R1_FB2_Msk				/*!<Filter bit 2 */
#define CAN_F10R1_FB3_Pos     (3U)
#define CAN_F10R1_FB3_Msk     (0x1UL << CAN_F10R1_FB3_Pos)	/*!< 0x00000008 */
#define CAN_F10R1_FB3         CAN_F10R1_FB3_Msk				/*!<Filter bit 3 */
#define CAN_F10R1_FB4_Pos     (4U)
#define CAN_F10R1_FB4_Msk     (0x1UL << CAN_F10R1_FB4_Pos)	/*!< 0x00000010 */
#define CAN_F10R1_FB4         CAN_F10R1_FB4_Msk				/*!<Filter bit 4 */
#define CAN_F10R1_FB5_Pos     (5U)
#define CAN_F10R1_FB5_Msk     (0x1UL << CAN_F10R1_FB5_Pos)	/*!< 0x00000020 */
#define CAN_F10R1_FB5         CAN_F10R1_FB5_Msk				/*!<Filter bit 5 */
#define CAN_F10R1_FB6_Pos     (6U)
#define CAN_F10R1_FB6_Msk     (0x1UL << CAN_F10R1_FB6_Pos)	/*!< 0x00000040 */
#define CAN_F10R1_FB6         CAN_F10R1_FB6_Msk				/*!<Filter bit 6 */
#define CAN_F10R1_FB7_Pos     (7U)
#define CAN_F10R1_FB7_Msk     (0x1UL << CAN_F10R1_FB7_Pos)	/*!< 0x00000080 */
#define CAN_F10R1_FB7         CAN_F10R1_FB7_Msk				/*!<Filter bit 7 */
#define CAN_F10R1_FB8_Pos     (8U)
#define CAN_F10R1_FB8_Msk     (0x1UL << CAN_F10R1_FB8_Pos)	/*!< 0x00000100 */
#define CAN_F10R1_FB8         CAN_F10R1_FB8_Msk				/*!<Filter bit 8 */
#define CAN_F10R1_FB9_Pos     (9U)
#define CAN_F10R1_FB9_Msk     (0x1UL << CAN_F10R1_FB9_Pos)	/*!< 0x00000200 */
#define CAN_F10R1_FB9         CAN_F10R1_FB9_Msk				/*!<Filter bit 9 */
#define CAN_F10R1_FB10_Pos    (10U)
#define CAN_F10R1_FB10_Msk    (0x1UL << CAN_F10R1_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F10R1_FB10        CAN_F10R1_FB10_Msk/*!<Filter bit 10 */
#define CAN_F10R1_FB11_Pos    (11U)
#define CAN_F10R1_FB11_Msk    (0x1UL << CAN_F10R1_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F10R1_FB11        CAN_F10R1_FB11_Msk/*!<Filter bit 11 */
#define CAN_F10R1_FB12_Pos    (12U)
#define CAN_F10R1_FB12_Msk    (0x1UL << CAN_F10R1_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F10R1_FB12        CAN_F10R1_FB12_Msk/*!<Filter bit 12 */
#define CAN_F10R1_FB13_Pos    (13U)
#define CAN_F10R1_FB13_Msk    (0x1UL << CAN_F10R1_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F10R1_FB13        CAN_F10R1_FB13_Msk/*!<Filter bit 13 */
#define CAN_F10R1_FB14_Pos    (14U)
#define CAN_F10R1_FB14_Msk    (0x1UL << CAN_F10R1_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F10R1_FB14        CAN_F10R1_FB14_Msk/*!<Filter bit 14 */
#define CAN_F10R1_FB15_Pos    (15U)
#define CAN_F10R1_FB15_Msk    (0x1UL << CAN_F10R1_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F10R1_FB15        CAN_F10R1_FB15_Msk/*!<Filter bit 15 */
#define CAN_F10R1_FB16_Pos    (16U)
#define CAN_F10R1_FB16_Msk    (0x1UL << CAN_F10R1_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F10R1_FB16        CAN_F10R1_FB16_Msk/*!<Filter bit 16 */
#define CAN_F10R1_FB17_Pos    (17U)
#define CAN_F10R1_FB17_Msk    (0x1UL << CAN_F10R1_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F10R1_FB17        CAN_F10R1_FB17_Msk/*!<Filter bit 17 */
#define CAN_F10R1_FB18_Pos    (18U)
#define CAN_F10R1_FB18_Msk    (0x1UL << CAN_F10R1_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F10R1_FB18        CAN_F10R1_FB18_Msk/*!<Filter bit 18 */
#define CAN_F10R1_FB19_Pos    (19U)
#define CAN_F10R1_FB19_Msk    (0x1UL << CAN_F10R1_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F10R1_FB19        CAN_F10R1_FB19_Msk/*!<Filter bit 19 */
#define CAN_F10R1_FB20_Pos    (20U)
#define CAN_F10R1_FB20_Msk    (0x1UL << CAN_F10R1_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F10R1_FB20        CAN_F10R1_FB20_Msk/*!<Filter bit 20 */
#define CAN_F10R1_FB21_Pos    (21U)
#define CAN_F10R1_FB21_Msk    (0x1UL << CAN_F10R1_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F10R1_FB21        CAN_F10R1_FB21_Msk/*!<Filter bit 21 */
#define CAN_F10R1_FB22_Pos    (22U)
#define CAN_F10R1_FB22_Msk    (0x1UL << CAN_F10R1_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F10R1_FB22        CAN_F10R1_FB22_Msk/*!<Filter bit 22 */
#define CAN_F10R1_FB23_Pos    (23U)
#define CAN_F10R1_FB23_Msk    (0x1UL << CAN_F10R1_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F10R1_FB23        CAN_F10R1_FB23_Msk/*!<Filter bit 23 */
#define CAN_F10R1_FB24_Pos    (24U)
#define CAN_F10R1_FB24_Msk    (0x1UL << CAN_F10R1_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F10R1_FB24        CAN_F10R1_FB24_Msk/*!<Filter bit 24 */
#define CAN_F10R1_FB25_Pos    (25U)
#define CAN_F10R1_FB25_Msk    (0x1UL << CAN_F10R1_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F10R1_FB25        CAN_F10R1_FB25_Msk/*!<Filter bit 25 */
#define CAN_F10R1_FB26_Pos    (26U)
#define CAN_F10R1_FB26_Msk    (0x1UL << CAN_F10R1_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F10R1_FB26        CAN_F10R1_FB26_Msk/*!<Filter bit 26 */
#define CAN_F10R1_FB27_Pos    (27U)
#define CAN_F10R1_FB27_Msk    (0x1UL << CAN_F10R1_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F10R1_FB27        CAN_F10R1_FB27_Msk/*!<Filter bit 27 */
#define CAN_F10R1_FB28_Pos    (28U)
#define CAN_F10R1_FB28_Msk    (0x1UL << CAN_F10R1_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F10R1_FB28        CAN_F10R1_FB28_Msk/*!<Filter bit 28 */
#define CAN_F10R1_FB29_Pos    (29U)
#define CAN_F10R1_FB29_Msk    (0x1UL << CAN_F10R1_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F10R1_FB29        CAN_F10R1_FB29_Msk/*!<Filter bit 29 */
#define CAN_F10R1_FB30_Pos    (30U)
#define CAN_F10R1_FB30_Msk    (0x1UL << CAN_F10R1_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F10R1_FB30        CAN_F10R1_FB30_Msk/*!<Filter bit 30 */
#define CAN_F10R1_FB31_Pos    (31U)
#define CAN_F10R1_FB31_Msk    (0x1UL << CAN_F10R1_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F10R1_FB31        CAN_F10R1_FB31_Msk/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F11R1 register  ******************/
#define CAN_F11R1_FB0_Pos     (0U)
#define CAN_F11R1_FB0_Msk     (0x1UL << CAN_F11R1_FB0_Pos)	/*!< 0x00000001 */
#define CAN_F11R1_FB0         CAN_F11R1_FB0_Msk				/*!<Filter bit 0 */
#define CAN_F11R1_FB1_Pos     (1U)
#define CAN_F11R1_FB1_Msk     (0x1UL << CAN_F11R1_FB1_Pos)	/*!< 0x00000002 */
#define CAN_F11R1_FB1         CAN_F11R1_FB1_Msk				/*!<Filter bit 1 */
#define CAN_F11R1_FB2_Pos     (2U)
#define CAN_F11R1_FB2_Msk     (0x1UL << CAN_F11R1_FB2_Pos)	/*!< 0x00000004 */
#define CAN_F11R1_FB2         CAN_F11R1_FB2_Msk				/*!<Filter bit 2 */
#define CAN_F11R1_FB3_Pos     (3U)
#define CAN_F11R1_FB3_Msk     (0x1UL << CAN_F11R1_FB3_Pos)	/*!< 0x00000008 */
#define CAN_F11R1_FB3         CAN_F11R1_FB3_Msk				/*!<Filter bit 3 */
#define CAN_F11R1_FB4_Pos     (4U)
#define CAN_F11R1_FB4_Msk     (0x1UL << CAN_F11R1_FB4_Pos)	/*!< 0x00000010 */
#define CAN_F11R1_FB4         CAN_F11R1_FB4_Msk				/*!<Filter bit 4 */
#define CAN_F11R1_FB5_Pos     (5U)
#define CAN_F11R1_FB5_Msk     (0x1UL << CAN_F11R1_FB5_Pos)	/*!< 0x00000020 */
#define CAN_F11R1_FB5         CAN_F11R1_FB5_Msk				/*!<Filter bit 5 */
#define CAN_F11R1_FB6_Pos     (6U)
#define CAN_F11R1_FB6_Msk     (0x1UL << CAN_F11R1_FB6_Pos)	/*!< 0x00000040 */
#define CAN_F11R1_FB6         CAN_F11R1_FB6_Msk				/*!<Filter bit 6 */
#define CAN_F11R1_FB7_Pos     (7U)
#define CAN_F11R1_FB7_Msk     (0x1UL << CAN_F11R1_FB7_Pos)	/*!< 0x00000080 */
#define CAN_F11R1_FB7         CAN_F11R1_FB7_Msk				/*!<Filter bit 7 */
#define CAN_F11R1_FB8_Pos     (8U)
#define CAN_F11R1_FB8_Msk     (0x1UL << CAN_F11R1_FB8_Pos)	/*!< 0x00000100 */
#define CAN_F11R1_FB8         CAN_F11R1_FB8_Msk				/*!<Filter bit 8 */
#define CAN_F11R1_FB9_Pos     (9U)
#define CAN_F11R1_FB9_Msk     (0x1UL << CAN_F11R1_FB9_Pos)	/*!< 0x00000200 */
#define CAN_F11R1_FB9         CAN_F11R1_FB9_Msk				/*!<Filter bit 9 */
#define CAN_F11R1_FB10_Pos    (10U)
#define CAN_F11R1_FB10_Msk    (0x1UL << CAN_F11R1_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F11R1_FB10        CAN_F11R1_FB10_Msk/*!<Filter bit 10 */
#define CAN_F11R1_FB11_Pos    (11U)
#define CAN_F11R1_FB11_Msk    (0x1UL << CAN_F11R1_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F11R1_FB11        CAN_F11R1_FB11_Msk/*!<Filter bit 11 */
#define CAN_F11R1_FB12_Pos    (12U)
#define CAN_F11R1_FB12_Msk    (0x1UL << CAN_F11R1_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F11R1_FB12        CAN_F11R1_FB12_Msk/*!<Filter bit 12 */
#define CAN_F11R1_FB13_Pos    (13U)
#define CAN_F11R1_FB13_Msk    (0x1UL << CAN_F11R1_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F11R1_FB13        CAN_F11R1_FB13_Msk/*!<Filter bit 13 */
#define CAN_F11R1_FB14_Pos    (14U)
#define CAN_F11R1_FB14_Msk    (0x1UL << CAN_F11R1_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F11R1_FB14        CAN_F11R1_FB14_Msk/*!<Filter bit 14 */
#define CAN_F11R1_FB15_Pos    (15U)
#define CAN_F11R1_FB15_Msk    (0x1UL << CAN_F11R1_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F11R1_FB15        CAN_F11R1_FB15_Msk/*!<Filter bit 15 */
#define CAN_F11R1_FB16_Pos    (16U)
#define CAN_F11R1_FB16_Msk    (0x1UL << CAN_F11R1_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F11R1_FB16        CAN_F11R1_FB16_Msk/*!<Filter bit 16 */
#define CAN_F11R1_FB17_Pos    (17U)
#define CAN_F11R1_FB17_Msk    (0x1UL << CAN_F11R1_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F11R1_FB17        CAN_F11R1_FB17_Msk/*!<Filter bit 17 */
#define CAN_F11R1_FB18_Pos    (18U)
#define CAN_F11R1_FB18_Msk    (0x1UL << CAN_F11R1_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F11R1_FB18        CAN_F11R1_FB18_Msk/*!<Filter bit 18 */
#define CAN_F11R1_FB19_Pos    (19U)
#define CAN_F11R1_FB19_Msk    (0x1UL << CAN_F11R1_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F11R1_FB19        CAN_F11R1_FB19_Msk/*!<Filter bit 19 */
#define CAN_F11R1_FB20_Pos    (20U)
#define CAN_F11R1_FB20_Msk    (0x1UL << CAN_F11R1_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F11R1_FB20        CAN_F11R1_FB20_Msk/*!<Filter bit 20 */
#define CAN_F11R1_FB21_Pos    (21U)
#define CAN_F11R1_FB21_Msk    (0x1UL << CAN_F11R1_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F11R1_FB21        CAN_F11R1_FB21_Msk/*!<Filter bit 21 */
#define CAN_F11R1_FB22_Pos    (22U)
#define CAN_F11R1_FB22_Msk    (0x1UL << CAN_F11R1_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F11R1_FB22        CAN_F11R1_FB22_Msk/*!<Filter bit 22 */
#define CAN_F11R1_FB23_Pos    (23U)
#define CAN_F11R1_FB23_Msk    (0x1UL << CAN_F11R1_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F11R1_FB23        CAN_F11R1_FB23_Msk/*!<Filter bit 23 */
#define CAN_F11R1_FB24_Pos    (24U)
#define CAN_F11R1_FB24_Msk    (0x1UL << CAN_F11R1_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F11R1_FB24        CAN_F11R1_FB24_Msk/*!<Filter bit 24 */
#define CAN_F11R1_FB25_Pos    (25U)
#define CAN_F11R1_FB25_Msk    (0x1UL << CAN_F11R1_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F11R1_FB25        CAN_F11R1_FB25_Msk/*!<Filter bit 25 */
#define CAN_F11R1_FB26_Pos    (26U)
#define CAN_F11R1_FB26_Msk    (0x1UL << CAN_F11R1_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F11R1_FB26        CAN_F11R1_FB26_Msk/*!<Filter bit 26 */
#define CAN_F11R1_FB27_Pos    (27U)
#define CAN_F11R1_FB27_Msk    (0x1UL << CAN_F11R1_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F11R1_FB27        CAN_F11R1_FB27_Msk/*!<Filter bit 27 */
#define CAN_F11R1_FB28_Pos    (28U)
#define CAN_F11R1_FB28_Msk    (0x1UL << CAN_F11R1_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F11R1_FB28        CAN_F11R1_FB28_Msk/*!<Filter bit 28 */
#define CAN_F11R1_FB29_Pos    (29U)
#define CAN_F11R1_FB29_Msk    (0x1UL << CAN_F11R1_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F11R1_FB29        CAN_F11R1_FB29_Msk/*!<Filter bit 29 */
#define CAN_F11R1_FB30_Pos    (30U)
#define CAN_F11R1_FB30_Msk    (0x1UL << CAN_F11R1_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F11R1_FB30        CAN_F11R1_FB30_Msk/*!<Filter bit 30 */
#define CAN_F11R1_FB31_Pos    (31U)
#define CAN_F11R1_FB31_Msk    (0x1UL << CAN_F11R1_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F11R1_FB31        CAN_F11R1_FB31_Msk/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F12R1 register  ******************/
#define CAN_F12R1_FB0_Pos     (0U)
#define CAN_F12R1_FB0_Msk     (0x1UL << CAN_F12R1_FB0_Pos)	/*!< 0x00000001 */
#define CAN_F12R1_FB0         CAN_F12R1_FB0_Msk				/*!<Filter bit 0 */
#define CAN_F12R1_FB1_Pos     (1U)
#define CAN_F12R1_FB1_Msk     (0x1UL << CAN_F12R1_FB1_Pos)	/*!< 0x00000002 */
#define CAN_F12R1_FB1         CAN_F12R1_FB1_Msk				/*!<Filter bit 1 */
#define CAN_F12R1_FB2_Pos     (2U)
#define CAN_F12R1_FB2_Msk     (0x1UL << CAN_F12R1_FB2_Pos)	/*!< 0x00000004 */
#define CAN_F12R1_FB2         CAN_F12R1_FB2_Msk				/*!<Filter bit 2 */
#define CAN_F12R1_FB3_Pos     (3U)
#define CAN_F12R1_FB3_Msk     (0x1UL << CAN_F12R1_FB3_Pos)	/*!< 0x00000008 */
#define CAN_F12R1_FB3         CAN_F12R1_FB3_Msk				/*!<Filter bit 3 */
#define CAN_F12R1_FB4_Pos     (4U)
#define CAN_F12R1_FB4_Msk     (0x1UL << CAN_F12R1_FB4_Pos)	/*!< 0x00000010 */
#define CAN_F12R1_FB4         CAN_F12R1_FB4_Msk				/*!<Filter bit 4 */
#define CAN_F12R1_FB5_Pos     (5U)
#define CAN_F12R1_FB5_Msk     (0x1UL << CAN_F12R1_FB5_Pos)	/*!< 0x00000020 */
#define CAN_F12R1_FB5         CAN_F12R1_FB5_Msk				/*!<Filter bit 5 */
#define CAN_F12R1_FB6_Pos     (6U)
#define CAN_F12R1_FB6_Msk     (0x1UL << CAN_F12R1_FB6_Pos)	/*!< 0x00000040 */
#define CAN_F12R1_FB6         CAN_F12R1_FB6_Msk				/*!<Filter bit 6 */
#define CAN_F12R1_FB7_Pos     (7U)
#define CAN_F12R1_FB7_Msk     (0x1UL << CAN_F12R1_FB7_Pos)	/*!< 0x00000080 */
#define CAN_F12R1_FB7         CAN_F12R1_FB7_Msk				/*!<Filter bit 7 */
#define CAN_F12R1_FB8_Pos     (8U)
#define CAN_F12R1_FB8_Msk     (0x1UL << CAN_F12R1_FB8_Pos)	/*!< 0x00000100 */
#define CAN_F12R1_FB8         CAN_F12R1_FB8_Msk				/*!<Filter bit 8 */
#define CAN_F12R1_FB9_Pos     (9U)
#define CAN_F12R1_FB9_Msk     (0x1UL << CAN_F12R1_FB9_Pos)	/*!< 0x00000200 */
#define CAN_F12R1_FB9         CAN_F12R1_FB9_Msk				/*!<Filter bit 9 */
#define CAN_F12R1_FB10_Pos    (10U)
#define CAN_F12R1_FB10_Msk    (0x1UL << CAN_F12R1_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F12R1_FB10        CAN_F12R1_FB10_Msk/*!<Filter bit 10 */
#define CAN_F12R1_FB11_Pos    (11U)
#define CAN_F12R1_FB11_Msk    (0x1UL << CAN_F12R1_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F12R1_FB11        CAN_F12R1_FB11_Msk/*!<Filter bit 11 */
#define CAN_F12R1_FB12_Pos    (12U)
#define CAN_F12R1_FB12_Msk    (0x1UL << CAN_F12R1_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F12R1_FB12        CAN_F12R1_FB12_Msk/*!<Filter bit 12 */
#define CAN_F12R1_FB13_Pos    (13U)
#define CAN_F12R1_FB13_Msk    (0x1UL << CAN_F12R1_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F12R1_FB13        CAN_F12R1_FB13_Msk/*!<Filter bit 13 */
#define CAN_F12R1_FB14_Pos    (14U)
#define CAN_F12R1_FB14_Msk    (0x1UL << CAN_F12R1_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F12R1_FB14        CAN_F12R1_FB14_Msk/*!<Filter bit 14 */
#define CAN_F12R1_FB15_Pos    (15U)
#define CAN_F12R1_FB15_Msk    (0x1UL << CAN_F12R1_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F12R1_FB15        CAN_F12R1_FB15_Msk/*!<Filter bit 15 */
#define CAN_F12R1_FB16_Pos    (16U)
#define CAN_F12R1_FB16_Msk    (0x1UL << CAN_F12R1_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F12R1_FB16        CAN_F12R1_FB16_Msk/*!<Filter bit 16 */
#define CAN_F12R1_FB17_Pos    (17U)
#define CAN_F12R1_FB17_Msk    (0x1UL << CAN_F12R1_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F12R1_FB17        CAN_F12R1_FB17_Msk/*!<Filter bit 17 */
#define CAN_F12R1_FB18_Pos    (18U)
#define CAN_F12R1_FB18_Msk    (0x1UL << CAN_F12R1_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F12R1_FB18        CAN_F12R1_FB18_Msk/*!<Filter bit 18 */
#define CAN_F12R1_FB19_Pos    (19U)
#define CAN_F12R1_FB19_Msk    (0x1UL << CAN_F12R1_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F12R1_FB19        CAN_F12R1_FB19_Msk/*!<Filter bit 19 */
#define CAN_F12R1_FB20_Pos    (20U)
#define CAN_F12R1_FB20_Msk    (0x1UL << CAN_F12R1_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F12R1_FB20        CAN_F12R1_FB20_Msk/*!<Filter bit 20 */
#define CAN_F12R1_FB21_Pos    (21U)
#define CAN_F12R1_FB21_Msk    (0x1UL << CAN_F12R1_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F12R1_FB21        CAN_F12R1_FB21_Msk/*!<Filter bit 21 */
#define CAN_F12R1_FB22_Pos    (22U)
#define CAN_F12R1_FB22_Msk    (0x1UL << CAN_F12R1_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F12R1_FB22        CAN_F12R1_FB22_Msk/*!<Filter bit 22 */
#define CAN_F12R1_FB23_Pos    (23U)
#define CAN_F12R1_FB23_Msk    (0x1UL << CAN_F12R1_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F12R1_FB23        CAN_F12R1_FB23_Msk/*!<Filter bit 23 */
#define CAN_F12R1_FB24_Pos    (24U)
#define CAN_F12R1_FB24_Msk    (0x1UL << CAN_F12R1_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F12R1_FB24        CAN_F12R1_FB24_Msk/*!<Filter bit 24 */
#define CAN_F12R1_FB25_Pos    (25U)
#define CAN_F12R1_FB25_Msk    (0x1UL << CAN_F12R1_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F12R1_FB25        CAN_F12R1_FB25_Msk/*!<Filter bit 25 */
#define CAN_F12R1_FB26_Pos    (26U)
#define CAN_F12R1_FB26_Msk    (0x1UL << CAN_F12R1_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F12R1_FB26        CAN_F12R1_FB26_Msk/*!<Filter bit 26 */
#define CAN_F12R1_FB27_Pos    (27U)
#define CAN_F12R1_FB27_Msk    (0x1UL << CAN_F12R1_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F12R1_FB27        CAN_F12R1_FB27_Msk/*!<Filter bit 27 */
#define CAN_F12R1_FB28_Pos    (28U)
#define CAN_F12R1_FB28_Msk    (0x1UL << CAN_F12R1_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F12R1_FB28        CAN_F12R1_FB28_Msk/*!<Filter bit 28 */
#define CAN_F12R1_FB29_Pos    (29U)
#define CAN_F12R1_FB29_Msk    (0x1UL << CAN_F12R1_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F12R1_FB29        CAN_F12R1_FB29_Msk/*!<Filter bit 29 */
#define CAN_F12R1_FB30_Pos    (30U)
#define CAN_F12R1_FB30_Msk    (0x1UL << CAN_F12R1_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F12R1_FB30        CAN_F12R1_FB30_Msk/*!<Filter bit 30 */
#define CAN_F12R1_FB31_Pos    (31U)
#define CAN_F12R1_FB31_Msk    (0x1UL << CAN_F12R1_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F12R1_FB31        CAN_F12R1_FB31_Msk/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F13R1 register  ******************/
#define CAN_F13R1_FB0_Pos     (0U)
#define CAN_F13R1_FB0_Msk     (0x1UL << CAN_F13R1_FB0_Pos)	/*!< 0x00000001 */
#define CAN_F13R1_FB0         CAN_F13R1_FB0_Msk				/*!<Filter bit 0 */
#define CAN_F13R1_FB1_Pos     (1U)
#define CAN_F13R1_FB1_Msk     (0x1UL << CAN_F13R1_FB1_Pos)	/*!< 0x00000002 */
#define CAN_F13R1_FB1         CAN_F13R1_FB1_Msk				/*!<Filter bit 1 */
#define CAN_F13R1_FB2_Pos     (2U)
#define CAN_F13R1_FB2_Msk     (0x1UL << CAN_F13R1_FB2_Pos)	/*!< 0x00000004 */
#define CAN_F13R1_FB2         CAN_F13R1_FB2_Msk				/*!<Filter bit 2 */
#define CAN_F13R1_FB3_Pos     (3U)
#define CAN_F13R1_FB3_Msk     (0x1UL << CAN_F13R1_FB3_Pos)	/*!< 0x00000008 */
#define CAN_F13R1_FB3         CAN_F13R1_FB3_Msk				/*!<Filter bit 3 */
#define CAN_F13R1_FB4_Pos     (4U)
#define CAN_F13R1_FB4_Msk     (0x1UL << CAN_F13R1_FB4_Pos)	/*!< 0x00000010 */
#define CAN_F13R1_FB4         CAN_F13R1_FB4_Msk				/*!<Filter bit 4 */
#define CAN_F13R1_FB5_Pos     (5U)
#define CAN_F13R1_FB5_Msk     (0x1UL << CAN_F13R1_FB5_Pos)	/*!< 0x00000020 */
#define CAN_F13R1_FB5         CAN_F13R1_FB5_Msk				/*!<Filter bit 5 */
#define CAN_F13R1_FB6_Pos     (6U)
#define CAN_F13R1_FB6_Msk     (0x1UL << CAN_F13R1_FB6_Pos)	/*!< 0x00000040 */
#define CAN_F13R1_FB6         CAN_F13R1_FB6_Msk				/*!<Filter bit 6 */
#define CAN_F13R1_FB7_Pos     (7U)
#define CAN_F13R1_FB7_Msk     (0x1UL << CAN_F13R1_FB7_Pos)	/*!< 0x00000080 */
#define CAN_F13R1_FB7         CAN_F13R1_FB7_Msk				/*!<Filter bit 7 */
#define CAN_F13R1_FB8_Pos     (8U)
#define CAN_F13R1_FB8_Msk     (0x1UL << CAN_F13R1_FB8_Pos)	/*!< 0x00000100 */
#define CAN_F13R1_FB8         CAN_F13R1_FB8_Msk				/*!<Filter bit 8 */
#define CAN_F13R1_FB9_Pos     (9U)
#define CAN_F13R1_FB9_Msk     (0x1UL << CAN_F13R1_FB9_Pos)	/*!< 0x00000200 */
#define CAN_F13R1_FB9         CAN_F13R1_FB9_Msk				/*!<Filter bit 9 */
#define CAN_F13R1_FB10_Pos    (10U)
#define CAN_F13R1_FB10_Msk    (0x1UL << CAN_F13R1_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F13R1_FB10        CAN_F13R1_FB10_Msk/*!<Filter bit 10 */
#define CAN_F13R1_FB11_Pos    (11U)
#define CAN_F13R1_FB11_Msk    (0x1UL << CAN_F13R1_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F13R1_FB11        CAN_F13R1_FB11_Msk/*!<Filter bit 11 */
#define CAN_F13R1_FB12_Pos    (12U)
#define CAN_F13R1_FB12_Msk    (0x1UL << CAN_F13R1_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F13R1_FB12        CAN_F13R1_FB12_Msk/*!<Filter bit 12 */
#define CAN_F13R1_FB13_Pos    (13U)
#define CAN_F13R1_FB13_Msk    (0x1UL << CAN_F13R1_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F13R1_FB13        CAN_F13R1_FB13_Msk/*!<Filter bit 13 */
#define CAN_F13R1_FB14_Pos    (14U)
#define CAN_F13R1_FB14_Msk    (0x1UL << CAN_F13R1_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F13R1_FB14        CAN_F13R1_FB14_Msk/*!<Filter bit 14 */
#define CAN_F13R1_FB15_Pos    (15U)
#define CAN_F13R1_FB15_Msk    (0x1UL << CAN_F13R1_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F13R1_FB15        CAN_F13R1_FB15_Msk/*!<Filter bit 15 */
#define CAN_F13R1_FB16_Pos    (16U)
#define CAN_F13R1_FB16_Msk    (0x1UL << CAN_F13R1_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F13R1_FB16        CAN_F13R1_FB16_Msk/*!<Filter bit 16 */
#define CAN_F13R1_FB17_Pos    (17U)
#define CAN_F13R1_FB17_Msk    (0x1UL << CAN_F13R1_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F13R1_FB17        CAN_F13R1_FB17_Msk/*!<Filter bit 17 */
#define CAN_F13R1_FB18_Pos    (18U)
#define CAN_F13R1_FB18_Msk    (0x1UL << CAN_F13R1_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F13R1_FB18        CAN_F13R1_FB18_Msk/*!<Filter bit 18 */
#define CAN_F13R1_FB19_Pos    (19U)
#define CAN_F13R1_FB19_Msk    (0x1UL << CAN_F13R1_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F13R1_FB19        CAN_F13R1_FB19_Msk/*!<Filter bit 19 */
#define CAN_F13R1_FB20_Pos    (20U)
#define CAN_F13R1_FB20_Msk    (0x1UL << CAN_F13R1_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F13R1_FB20        CAN_F13R1_FB20_Msk/*!<Filter bit 20 */
#define CAN_F13R1_FB21_Pos    (21U)
#define CAN_F13R1_FB21_Msk    (0x1UL << CAN_F13R1_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F13R1_FB21        CAN_F13R1_FB21_Msk/*!<Filter bit 21 */
#define CAN_F13R1_FB22_Pos    (22U)
#define CAN_F13R1_FB22_Msk    (0x1UL << CAN_F13R1_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F13R1_FB22        CAN_F13R1_FB22_Msk/*!<Filter bit 22 */
#define CAN_F13R1_FB23_Pos    (23U)
#define CAN_F13R1_FB23_Msk    (0x1UL << CAN_F13R1_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F13R1_FB23        CAN_F13R1_FB23_Msk/*!<Filter bit 23 */
#define CAN_F13R1_FB24_Pos    (24U)
#define CAN_F13R1_FB24_Msk    (0x1UL << CAN_F13R1_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F13R1_FB24        CAN_F13R1_FB24_Msk/*!<Filter bit 24 */
#define CAN_F13R1_FB25_Pos    (25U)
#define CAN_F13R1_FB25_Msk    (0x1UL << CAN_F13R1_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F13R1_FB25        CAN_F13R1_FB25_Msk/*!<Filter bit 25 */
#define CAN_F13R1_FB26_Pos    (26U)
#define CAN_F13R1_FB26_Msk    (0x1UL << CAN_F13R1_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F13R1_FB26        CAN_F13R1_FB26_Msk/*!<Filter bit 26 */
#define CAN_F13R1_FB27_Pos    (27U)
#define CAN_F13R1_FB27_Msk    (0x1UL << CAN_F13R1_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F13R1_FB27        CAN_F13R1_FB27_Msk/*!<Filter bit 27 */
#define CAN_F13R1_FB28_Pos    (28U)
#define CAN_F13R1_FB28_Msk    (0x1UL << CAN_F13R1_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F13R1_FB28        CAN_F13R1_FB28_Msk/*!<Filter bit 28 */
#define CAN_F13R1_FB29_Pos    (29U)
#define CAN_F13R1_FB29_Msk    (0x1UL << CAN_F13R1_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F13R1_FB29        CAN_F13R1_FB29_Msk/*!<Filter bit 29 */
#define CAN_F13R1_FB30_Pos    (30U)
#define CAN_F13R1_FB30_Msk    (0x1UL << CAN_F13R1_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F13R1_FB30        CAN_F13R1_FB30_Msk/*!<Filter bit 30 */
#define CAN_F13R1_FB31_Pos    (31U)
#define CAN_F13R1_FB31_Msk    (0x1UL << CAN_F13R1_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F13R1_FB31        CAN_F13R1_FB31_Msk/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F0R2 register  *******************/
#define CAN_F0R2_FB0_Pos     (0U)
#define CAN_F0R2_FB0_Msk     (0x1UL << CAN_F0R2_FB0_Pos)/*!< 0x00000001 */
#define CAN_F0R2_FB0         CAN_F0R2_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F0R2_FB1_Pos     (1U)
#define CAN_F0R2_FB1_Msk     (0x1UL << CAN_F0R2_FB1_Pos)/*!< 0x00000002 */
#define CAN_F0R2_FB1         CAN_F0R2_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F0R2_FB2_Pos     (2U)
#define CAN_F0R2_FB2_Msk     (0x1UL << CAN_F0R2_FB2_Pos)/*!< 0x00000004 */
#define CAN_F0R2_FB2         CAN_F0R2_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F0R2_FB3_Pos     (3U)
#define CAN_F0R2_FB3_Msk     (0x1UL << CAN_F0R2_FB3_Pos)/*!< 0x00000008 */
#define CAN_F0R2_FB3         CAN_F0R2_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F0R2_FB4_Pos     (4U)
#define CAN_F0R2_FB4_Msk     (0x1UL << CAN_F0R2_FB4_Pos)/*!< 0x00000010 */
#define CAN_F0R2_FB4         CAN_F0R2_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F0R2_FB5_Pos     (5U)
#define CAN_F0R2_FB5_Msk     (0x1UL << CAN_F0R2_FB5_Pos)/*!< 0x00000020 */
#define CAN_F0R2_FB5         CAN_F0R2_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F0R2_FB6_Pos     (6U)
#define CAN_F0R2_FB6_Msk     (0x1UL << CAN_F0R2_FB6_Pos)/*!< 0x00000040 */
#define CAN_F0R2_FB6         CAN_F0R2_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F0R2_FB7_Pos     (7U)
#define CAN_F0R2_FB7_Msk     (0x1UL << CAN_F0R2_FB7_Pos)/*!< 0x00000080 */
#define CAN_F0R2_FB7         CAN_F0R2_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F0R2_FB8_Pos     (8U)
#define CAN_F0R2_FB8_Msk     (0x1UL << CAN_F0R2_FB8_Pos)/*!< 0x00000100 */
#define CAN_F0R2_FB8         CAN_F0R2_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F0R2_FB9_Pos     (9U)
#define CAN_F0R2_FB9_Msk     (0x1UL << CAN_F0R2_FB9_Pos)/*!< 0x00000200 */
#define CAN_F0R2_FB9         CAN_F0R2_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F0R2_FB10_Pos    (10U)
#define CAN_F0R2_FB10_Msk    (0x1UL << CAN_F0R2_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F0R2_FB10        CAN_F0R2_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F0R2_FB11_Pos    (11U)
#define CAN_F0R2_FB11_Msk    (0x1UL << CAN_F0R2_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F0R2_FB11        CAN_F0R2_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F0R2_FB12_Pos    (12U)
#define CAN_F0R2_FB12_Msk    (0x1UL << CAN_F0R2_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F0R2_FB12        CAN_F0R2_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F0R2_FB13_Pos    (13U)
#define CAN_F0R2_FB13_Msk    (0x1UL << CAN_F0R2_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F0R2_FB13        CAN_F0R2_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F0R2_FB14_Pos    (14U)
#define CAN_F0R2_FB14_Msk    (0x1UL << CAN_F0R2_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F0R2_FB14        CAN_F0R2_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F0R2_FB15_Pos    (15U)
#define CAN_F0R2_FB15_Msk    (0x1UL << CAN_F0R2_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F0R2_FB15        CAN_F0R2_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F0R2_FB16_Pos    (16U)
#define CAN_F0R2_FB16_Msk    (0x1UL << CAN_F0R2_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F0R2_FB16        CAN_F0R2_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F0R2_FB17_Pos    (17U)
#define CAN_F0R2_FB17_Msk    (0x1UL << CAN_F0R2_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F0R2_FB17        CAN_F0R2_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F0R2_FB18_Pos    (18U)
#define CAN_F0R2_FB18_Msk    (0x1UL << CAN_F0R2_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F0R2_FB18        CAN_F0R2_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F0R2_FB19_Pos    (19U)
#define CAN_F0R2_FB19_Msk    (0x1UL << CAN_F0R2_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F0R2_FB19        CAN_F0R2_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F0R2_FB20_Pos    (20U)
#define CAN_F0R2_FB20_Msk    (0x1UL << CAN_F0R2_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F0R2_FB20        CAN_F0R2_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F0R2_FB21_Pos    (21U)
#define CAN_F0R2_FB21_Msk    (0x1UL << CAN_F0R2_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F0R2_FB21        CAN_F0R2_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F0R2_FB22_Pos    (22U)
#define CAN_F0R2_FB22_Msk    (0x1UL << CAN_F0R2_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F0R2_FB22        CAN_F0R2_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F0R2_FB23_Pos    (23U)
#define CAN_F0R2_FB23_Msk    (0x1UL << CAN_F0R2_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F0R2_FB23        CAN_F0R2_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F0R2_FB24_Pos    (24U)
#define CAN_F0R2_FB24_Msk    (0x1UL << CAN_F0R2_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F0R2_FB24        CAN_F0R2_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F0R2_FB25_Pos    (25U)
#define CAN_F0R2_FB25_Msk    (0x1UL << CAN_F0R2_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F0R2_FB25        CAN_F0R2_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F0R2_FB26_Pos    (26U)
#define CAN_F0R2_FB26_Msk    (0x1UL << CAN_F0R2_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F0R2_FB26        CAN_F0R2_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F0R2_FB27_Pos    (27U)
#define CAN_F0R2_FB27_Msk    (0x1UL << CAN_F0R2_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F0R2_FB27        CAN_F0R2_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F0R2_FB28_Pos    (28U)
#define CAN_F0R2_FB28_Msk    (0x1UL << CAN_F0R2_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F0R2_FB28        CAN_F0R2_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F0R2_FB29_Pos    (29U)
#define CAN_F0R2_FB29_Msk    (0x1UL << CAN_F0R2_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F0R2_FB29        CAN_F0R2_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F0R2_FB30_Pos    (30U)
#define CAN_F0R2_FB30_Msk    (0x1UL << CAN_F0R2_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F0R2_FB30        CAN_F0R2_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F0R2_FB31_Pos    (31U)
#define CAN_F0R2_FB31_Msk    (0x1UL << CAN_F0R2_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F0R2_FB31        CAN_F0R2_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F1R2 register  *******************/
#define CAN_F1R2_FB0_Pos     (0U)
#define CAN_F1R2_FB0_Msk     (0x1UL << CAN_F1R2_FB0_Pos)/*!< 0x00000001 */
#define CAN_F1R2_FB0         CAN_F1R2_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F1R2_FB1_Pos     (1U)
#define CAN_F1R2_FB1_Msk     (0x1UL << CAN_F1R2_FB1_Pos)/*!< 0x00000002 */
#define CAN_F1R2_FB1         CAN_F1R2_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F1R2_FB2_Pos     (2U)
#define CAN_F1R2_FB2_Msk     (0x1UL << CAN_F1R2_FB2_Pos)/*!< 0x00000004 */
#define CAN_F1R2_FB2         CAN_F1R2_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F1R2_FB3_Pos     (3U)
#define CAN_F1R2_FB3_Msk     (0x1UL << CAN_F1R2_FB3_Pos)/*!< 0x00000008 */
#define CAN_F1R2_FB3         CAN_F1R2_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F1R2_FB4_Pos     (4U)
#define CAN_F1R2_FB4_Msk     (0x1UL << CAN_F1R2_FB4_Pos)/*!< 0x00000010 */
#define CAN_F1R2_FB4         CAN_F1R2_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F1R2_FB5_Pos     (5U)
#define CAN_F1R2_FB5_Msk     (0x1UL << CAN_F1R2_FB5_Pos)/*!< 0x00000020 */
#define CAN_F1R2_FB5         CAN_F1R2_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F1R2_FB6_Pos     (6U)
#define CAN_F1R2_FB6_Msk     (0x1UL << CAN_F1R2_FB6_Pos)/*!< 0x00000040 */
#define CAN_F1R2_FB6         CAN_F1R2_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F1R2_FB7_Pos     (7U)
#define CAN_F1R2_FB7_Msk     (0x1UL << CAN_F1R2_FB7_Pos)/*!< 0x00000080 */
#define CAN_F1R2_FB7         CAN_F1R2_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F1R2_FB8_Pos     (8U)
#define CAN_F1R2_FB8_Msk     (0x1UL << CAN_F1R2_FB8_Pos)/*!< 0x00000100 */
#define CAN_F1R2_FB8         CAN_F1R2_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F1R2_FB9_Pos     (9U)
#define CAN_F1R2_FB9_Msk     (0x1UL << CAN_F1R2_FB9_Pos)/*!< 0x00000200 */
#define CAN_F1R2_FB9         CAN_F1R2_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F1R2_FB10_Pos    (10U)
#define CAN_F1R2_FB10_Msk    (0x1UL << CAN_F1R2_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F1R2_FB10        CAN_F1R2_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F1R2_FB11_Pos    (11U)
#define CAN_F1R2_FB11_Msk    (0x1UL << CAN_F1R2_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F1R2_FB11        CAN_F1R2_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F1R2_FB12_Pos    (12U)
#define CAN_F1R2_FB12_Msk    (0x1UL << CAN_F1R2_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F1R2_FB12        CAN_F1R2_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F1R2_FB13_Pos    (13U)
#define CAN_F1R2_FB13_Msk    (0x1UL << CAN_F1R2_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F1R2_FB13        CAN_F1R2_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F1R2_FB14_Pos    (14U)
#define CAN_F1R2_FB14_Msk    (0x1UL << CAN_F1R2_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F1R2_FB14        CAN_F1R2_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F1R2_FB15_Pos    (15U)
#define CAN_F1R2_FB15_Msk    (0x1UL << CAN_F1R2_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F1R2_FB15        CAN_F1R2_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F1R2_FB16_Pos    (16U)
#define CAN_F1R2_FB16_Msk    (0x1UL << CAN_F1R2_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F1R2_FB16        CAN_F1R2_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F1R2_FB17_Pos    (17U)
#define CAN_F1R2_FB17_Msk    (0x1UL << CAN_F1R2_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F1R2_FB17        CAN_F1R2_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F1R2_FB18_Pos    (18U)
#define CAN_F1R2_FB18_Msk    (0x1UL << CAN_F1R2_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F1R2_FB18        CAN_F1R2_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F1R2_FB19_Pos    (19U)
#define CAN_F1R2_FB19_Msk    (0x1UL << CAN_F1R2_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F1R2_FB19        CAN_F1R2_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F1R2_FB20_Pos    (20U)
#define CAN_F1R2_FB20_Msk    (0x1UL << CAN_F1R2_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F1R2_FB20        CAN_F1R2_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F1R2_FB21_Pos    (21U)
#define CAN_F1R2_FB21_Msk    (0x1UL << CAN_F1R2_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F1R2_FB21        CAN_F1R2_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F1R2_FB22_Pos    (22U)
#define CAN_F1R2_FB22_Msk    (0x1UL << CAN_F1R2_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F1R2_FB22        CAN_F1R2_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F1R2_FB23_Pos    (23U)
#define CAN_F1R2_FB23_Msk    (0x1UL << CAN_F1R2_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F1R2_FB23        CAN_F1R2_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F1R2_FB24_Pos    (24U)
#define CAN_F1R2_FB24_Msk    (0x1UL << CAN_F1R2_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F1R2_FB24        CAN_F1R2_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F1R2_FB25_Pos    (25U)
#define CAN_F1R2_FB25_Msk    (0x1UL << CAN_F1R2_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F1R2_FB25        CAN_F1R2_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F1R2_FB26_Pos    (26U)
#define CAN_F1R2_FB26_Msk    (0x1UL << CAN_F1R2_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F1R2_FB26        CAN_F1R2_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F1R2_FB27_Pos    (27U)
#define CAN_F1R2_FB27_Msk    (0x1UL << CAN_F1R2_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F1R2_FB27        CAN_F1R2_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F1R2_FB28_Pos    (28U)
#define CAN_F1R2_FB28_Msk    (0x1UL << CAN_F1R2_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F1R2_FB28        CAN_F1R2_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F1R2_FB29_Pos    (29U)
#define CAN_F1R2_FB29_Msk    (0x1UL << CAN_F1R2_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F1R2_FB29        CAN_F1R2_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F1R2_FB30_Pos    (30U)
#define CAN_F1R2_FB30_Msk    (0x1UL << CAN_F1R2_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F1R2_FB30        CAN_F1R2_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F1R2_FB31_Pos    (31U)
#define CAN_F1R2_FB31_Msk    (0x1UL << CAN_F1R2_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F1R2_FB31        CAN_F1R2_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F2R2 register  *******************/
#define CAN_F2R2_FB0_Pos     (0U)
#define CAN_F2R2_FB0_Msk     (0x1UL << CAN_F2R2_FB0_Pos)/*!< 0x00000001 */
#define CAN_F2R2_FB0         CAN_F2R2_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F2R2_FB1_Pos     (1U)
#define CAN_F2R2_FB1_Msk     (0x1UL << CAN_F2R2_FB1_Pos)/*!< 0x00000002 */
#define CAN_F2R2_FB1         CAN_F2R2_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F2R2_FB2_Pos     (2U)
#define CAN_F2R2_FB2_Msk     (0x1UL << CAN_F2R2_FB2_Pos)/*!< 0x00000004 */
#define CAN_F2R2_FB2         CAN_F2R2_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F2R2_FB3_Pos     (3U)
#define CAN_F2R2_FB3_Msk     (0x1UL << CAN_F2R2_FB3_Pos)/*!< 0x00000008 */
#define CAN_F2R2_FB3         CAN_F2R2_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F2R2_FB4_Pos     (4U)
#define CAN_F2R2_FB4_Msk     (0x1UL << CAN_F2R2_FB4_Pos)/*!< 0x00000010 */
#define CAN_F2R2_FB4         CAN_F2R2_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F2R2_FB5_Pos     (5U)
#define CAN_F2R2_FB5_Msk     (0x1UL << CAN_F2R2_FB5_Pos)/*!< 0x00000020 */
#define CAN_F2R2_FB5         CAN_F2R2_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F2R2_FB6_Pos     (6U)
#define CAN_F2R2_FB6_Msk     (0x1UL << CAN_F2R2_FB6_Pos)/*!< 0x00000040 */
#define CAN_F2R2_FB6         CAN_F2R2_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F2R2_FB7_Pos     (7U)
#define CAN_F2R2_FB7_Msk     (0x1UL << CAN_F2R2_FB7_Pos)/*!< 0x00000080 */
#define CAN_F2R2_FB7         CAN_F2R2_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F2R2_FB8_Pos     (8U)
#define CAN_F2R2_FB8_Msk     (0x1UL << CAN_F2R2_FB8_Pos)/*!< 0x00000100 */
#define CAN_F2R2_FB8         CAN_F2R2_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F2R2_FB9_Pos     (9U)
#define CAN_F2R2_FB9_Msk     (0x1UL << CAN_F2R2_FB9_Pos)/*!< 0x00000200 */
#define CAN_F2R2_FB9         CAN_F2R2_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F2R2_FB10_Pos    (10U)
#define CAN_F2R2_FB10_Msk    (0x1UL << CAN_F2R2_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F2R2_FB10        CAN_F2R2_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F2R2_FB11_Pos    (11U)
#define CAN_F2R2_FB11_Msk    (0x1UL << CAN_F2R2_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F2R2_FB11        CAN_F2R2_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F2R2_FB12_Pos    (12U)
#define CAN_F2R2_FB12_Msk    (0x1UL << CAN_F2R2_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F2R2_FB12        CAN_F2R2_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F2R2_FB13_Pos    (13U)
#define CAN_F2R2_FB13_Msk    (0x1UL << CAN_F2R2_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F2R2_FB13        CAN_F2R2_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F2R2_FB14_Pos    (14U)
#define CAN_F2R2_FB14_Msk    (0x1UL << CAN_F2R2_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F2R2_FB14        CAN_F2R2_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F2R2_FB15_Pos    (15U)
#define CAN_F2R2_FB15_Msk    (0x1UL << CAN_F2R2_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F2R2_FB15        CAN_F2R2_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F2R2_FB16_Pos    (16U)
#define CAN_F2R2_FB16_Msk    (0x1UL << CAN_F2R2_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F2R2_FB16        CAN_F2R2_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F2R2_FB17_Pos    (17U)
#define CAN_F2R2_FB17_Msk    (0x1UL << CAN_F2R2_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F2R2_FB17        CAN_F2R2_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F2R2_FB18_Pos    (18U)
#define CAN_F2R2_FB18_Msk    (0x1UL << CAN_F2R2_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F2R2_FB18        CAN_F2R2_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F2R2_FB19_Pos    (19U)
#define CAN_F2R2_FB19_Msk    (0x1UL << CAN_F2R2_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F2R2_FB19        CAN_F2R2_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F2R2_FB20_Pos    (20U)
#define CAN_F2R2_FB20_Msk    (0x1UL << CAN_F2R2_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F2R2_FB20        CAN_F2R2_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F2R2_FB21_Pos    (21U)
#define CAN_F2R2_FB21_Msk    (0x1UL << CAN_F2R2_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F2R2_FB21        CAN_F2R2_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F2R2_FB22_Pos    (22U)
#define CAN_F2R2_FB22_Msk    (0x1UL << CAN_F2R2_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F2R2_FB22        CAN_F2R2_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F2R2_FB23_Pos    (23U)
#define CAN_F2R2_FB23_Msk    (0x1UL << CAN_F2R2_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F2R2_FB23        CAN_F2R2_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F2R2_FB24_Pos    (24U)
#define CAN_F2R2_FB24_Msk    (0x1UL << CAN_F2R2_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F2R2_FB24        CAN_F2R2_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F2R2_FB25_Pos    (25U)
#define CAN_F2R2_FB25_Msk    (0x1UL << CAN_F2R2_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F2R2_FB25        CAN_F2R2_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F2R2_FB26_Pos    (26U)
#define CAN_F2R2_FB26_Msk    (0x1UL << CAN_F2R2_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F2R2_FB26        CAN_F2R2_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F2R2_FB27_Pos    (27U)
#define CAN_F2R2_FB27_Msk    (0x1UL << CAN_F2R2_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F2R2_FB27        CAN_F2R2_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F2R2_FB28_Pos    (28U)
#define CAN_F2R2_FB28_Msk    (0x1UL << CAN_F2R2_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F2R2_FB28        CAN_F2R2_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F2R2_FB29_Pos    (29U)
#define CAN_F2R2_FB29_Msk    (0x1UL << CAN_F2R2_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F2R2_FB29        CAN_F2R2_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F2R2_FB30_Pos    (30U)
#define CAN_F2R2_FB30_Msk    (0x1UL << CAN_F2R2_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F2R2_FB30        CAN_F2R2_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F2R2_FB31_Pos    (31U)
#define CAN_F2R2_FB31_Msk    (0x1UL << CAN_F2R2_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F2R2_FB31        CAN_F2R2_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F3R2 register  *******************/
#define CAN_F3R2_FB0_Pos     (0U)
#define CAN_F3R2_FB0_Msk     (0x1UL << CAN_F3R2_FB0_Pos)/*!< 0x00000001 */
#define CAN_F3R2_FB0         CAN_F3R2_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F3R2_FB1_Pos     (1U)
#define CAN_F3R2_FB1_Msk     (0x1UL << CAN_F3R2_FB1_Pos)/*!< 0x00000002 */
#define CAN_F3R2_FB1         CAN_F3R2_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F3R2_FB2_Pos     (2U)
#define CAN_F3R2_FB2_Msk     (0x1UL << CAN_F3R2_FB2_Pos)/*!< 0x00000004 */
#define CAN_F3R2_FB2         CAN_F3R2_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F3R2_FB3_Pos     (3U)
#define CAN_F3R2_FB3_Msk     (0x1UL << CAN_F3R2_FB3_Pos)/*!< 0x00000008 */
#define CAN_F3R2_FB3         CAN_F3R2_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F3R2_FB4_Pos     (4U)
#define CAN_F3R2_FB4_Msk     (0x1UL << CAN_F3R2_FB4_Pos)/*!< 0x00000010 */
#define CAN_F3R2_FB4         CAN_F3R2_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F3R2_FB5_Pos     (5U)
#define CAN_F3R2_FB5_Msk     (0x1UL << CAN_F3R2_FB5_Pos)/*!< 0x00000020 */
#define CAN_F3R2_FB5         CAN_F3R2_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F3R2_FB6_Pos     (6U)
#define CAN_F3R2_FB6_Msk     (0x1UL << CAN_F3R2_FB6_Pos)/*!< 0x00000040 */
#define CAN_F3R2_FB6         CAN_F3R2_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F3R2_FB7_Pos     (7U)
#define CAN_F3R2_FB7_Msk     (0x1UL << CAN_F3R2_FB7_Pos)/*!< 0x00000080 */
#define CAN_F3R2_FB7         CAN_F3R2_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F3R2_FB8_Pos     (8U)
#define CAN_F3R2_FB8_Msk     (0x1UL << CAN_F3R2_FB8_Pos)/*!< 0x00000100 */
#define CAN_F3R2_FB8         CAN_F3R2_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F3R2_FB9_Pos     (9U)
#define CAN_F3R2_FB9_Msk     (0x1UL << CAN_F3R2_FB9_Pos)/*!< 0x00000200 */
#define CAN_F3R2_FB9         CAN_F3R2_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F3R2_FB10_Pos    (10U)
#define CAN_F3R2_FB10_Msk    (0x1UL << CAN_F3R2_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F3R2_FB10        CAN_F3R2_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F3R2_FB11_Pos    (11U)
#define CAN_F3R2_FB11_Msk    (0x1UL << CAN_F3R2_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F3R2_FB11        CAN_F3R2_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F3R2_FB12_Pos    (12U)
#define CAN_F3R2_FB12_Msk    (0x1UL << CAN_F3R2_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F3R2_FB12        CAN_F3R2_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F3R2_FB13_Pos    (13U)
#define CAN_F3R2_FB13_Msk    (0x1UL << CAN_F3R2_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F3R2_FB13        CAN_F3R2_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F3R2_FB14_Pos    (14U)
#define CAN_F3R2_FB14_Msk    (0x1UL << CAN_F3R2_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F3R2_FB14        CAN_F3R2_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F3R2_FB15_Pos    (15U)
#define CAN_F3R2_FB15_Msk    (0x1UL << CAN_F3R2_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F3R2_FB15        CAN_F3R2_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F3R2_FB16_Pos    (16U)
#define CAN_F3R2_FB16_Msk    (0x1UL << CAN_F3R2_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F3R2_FB16        CAN_F3R2_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F3R2_FB17_Pos    (17U)
#define CAN_F3R2_FB17_Msk    (0x1UL << CAN_F3R2_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F3R2_FB17        CAN_F3R2_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F3R2_FB18_Pos    (18U)
#define CAN_F3R2_FB18_Msk    (0x1UL << CAN_F3R2_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F3R2_FB18        CAN_F3R2_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F3R2_FB19_Pos    (19U)
#define CAN_F3R2_FB19_Msk    (0x1UL << CAN_F3R2_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F3R2_FB19        CAN_F3R2_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F3R2_FB20_Pos    (20U)
#define CAN_F3R2_FB20_Msk    (0x1UL << CAN_F3R2_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F3R2_FB20        CAN_F3R2_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F3R2_FB21_Pos    (21U)
#define CAN_F3R2_FB21_Msk    (0x1UL << CAN_F3R2_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F3R2_FB21        CAN_F3R2_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F3R2_FB22_Pos    (22U)
#define CAN_F3R2_FB22_Msk    (0x1UL << CAN_F3R2_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F3R2_FB22        CAN_F3R2_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F3R2_FB23_Pos    (23U)
#define CAN_F3R2_FB23_Msk    (0x1UL << CAN_F3R2_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F3R2_FB23        CAN_F3R2_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F3R2_FB24_Pos    (24U)
#define CAN_F3R2_FB24_Msk    (0x1UL << CAN_F3R2_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F3R2_FB24        CAN_F3R2_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F3R2_FB25_Pos    (25U)
#define CAN_F3R2_FB25_Msk    (0x1UL << CAN_F3R2_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F3R2_FB25        CAN_F3R2_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F3R2_FB26_Pos    (26U)
#define CAN_F3R2_FB26_Msk    (0x1UL << CAN_F3R2_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F3R2_FB26        CAN_F3R2_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F3R2_FB27_Pos    (27U)
#define CAN_F3R2_FB27_Msk    (0x1UL << CAN_F3R2_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F3R2_FB27        CAN_F3R2_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F3R2_FB28_Pos    (28U)
#define CAN_F3R2_FB28_Msk    (0x1UL << CAN_F3R2_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F3R2_FB28        CAN_F3R2_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F3R2_FB29_Pos    (29U)
#define CAN_F3R2_FB29_Msk    (0x1UL << CAN_F3R2_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F3R2_FB29        CAN_F3R2_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F3R2_FB30_Pos    (30U)
#define CAN_F3R2_FB30_Msk    (0x1UL << CAN_F3R2_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F3R2_FB30        CAN_F3R2_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F3R2_FB31_Pos    (31U)
#define CAN_F3R2_FB31_Msk    (0x1UL << CAN_F3R2_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F3R2_FB31        CAN_F3R2_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F4R2 register  *******************/
#define CAN_F4R2_FB0_Pos     (0U)
#define CAN_F4R2_FB0_Msk     (0x1UL << CAN_F4R2_FB0_Pos)/*!< 0x00000001 */
#define CAN_F4R2_FB0         CAN_F4R2_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F4R2_FB1_Pos     (1U)
#define CAN_F4R2_FB1_Msk     (0x1UL << CAN_F4R2_FB1_Pos)/*!< 0x00000002 */
#define CAN_F4R2_FB1         CAN_F4R2_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F4R2_FB2_Pos     (2U)
#define CAN_F4R2_FB2_Msk     (0x1UL << CAN_F4R2_FB2_Pos)/*!< 0x00000004 */
#define CAN_F4R2_FB2         CAN_F4R2_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F4R2_FB3_Pos     (3U)
#define CAN_F4R2_FB3_Msk     (0x1UL << CAN_F4R2_FB3_Pos)/*!< 0x00000008 */
#define CAN_F4R2_FB3         CAN_F4R2_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F4R2_FB4_Pos     (4U)
#define CAN_F4R2_FB4_Msk     (0x1UL << CAN_F4R2_FB4_Pos)/*!< 0x00000010 */
#define CAN_F4R2_FB4         CAN_F4R2_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F4R2_FB5_Pos     (5U)
#define CAN_F4R2_FB5_Msk     (0x1UL << CAN_F4R2_FB5_Pos)/*!< 0x00000020 */
#define CAN_F4R2_FB5         CAN_F4R2_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F4R2_FB6_Pos     (6U)
#define CAN_F4R2_FB6_Msk     (0x1UL << CAN_F4R2_FB6_Pos)/*!< 0x00000040 */
#define CAN_F4R2_FB6         CAN_F4R2_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F4R2_FB7_Pos     (7U)
#define CAN_F4R2_FB7_Msk     (0x1UL << CAN_F4R2_FB7_Pos)/*!< 0x00000080 */
#define CAN_F4R2_FB7         CAN_F4R2_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F4R2_FB8_Pos     (8U)
#define CAN_F4R2_FB8_Msk     (0x1UL << CAN_F4R2_FB8_Pos)/*!< 0x00000100 */
#define CAN_F4R2_FB8         CAN_F4R2_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F4R2_FB9_Pos     (9U)
#define CAN_F4R2_FB9_Msk     (0x1UL << CAN_F4R2_FB9_Pos)/*!< 0x00000200 */
#define CAN_F4R2_FB9         CAN_F4R2_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F4R2_FB10_Pos    (10U)
#define CAN_F4R2_FB10_Msk    (0x1UL << CAN_F4R2_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F4R2_FB10        CAN_F4R2_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F4R2_FB11_Pos    (11U)
#define CAN_F4R2_FB11_Msk    (0x1UL << CAN_F4R2_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F4R2_FB11        CAN_F4R2_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F4R2_FB12_Pos    (12U)
#define CAN_F4R2_FB12_Msk    (0x1UL << CAN_F4R2_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F4R2_FB12        CAN_F4R2_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F4R2_FB13_Pos    (13U)
#define CAN_F4R2_FB13_Msk    (0x1UL << CAN_F4R2_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F4R2_FB13        CAN_F4R2_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F4R2_FB14_Pos    (14U)
#define CAN_F4R2_FB14_Msk    (0x1UL << CAN_F4R2_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F4R2_FB14        CAN_F4R2_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F4R2_FB15_Pos    (15U)
#define CAN_F4R2_FB15_Msk    (0x1UL << CAN_F4R2_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F4R2_FB15        CAN_F4R2_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F4R2_FB16_Pos    (16U)
#define CAN_F4R2_FB16_Msk    (0x1UL << CAN_F4R2_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F4R2_FB16        CAN_F4R2_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F4R2_FB17_Pos    (17U)
#define CAN_F4R2_FB17_Msk    (0x1UL << CAN_F4R2_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F4R2_FB17        CAN_F4R2_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F4R2_FB18_Pos    (18U)
#define CAN_F4R2_FB18_Msk    (0x1UL << CAN_F4R2_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F4R2_FB18        CAN_F4R2_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F4R2_FB19_Pos    (19U)
#define CAN_F4R2_FB19_Msk    (0x1UL << CAN_F4R2_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F4R2_FB19        CAN_F4R2_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F4R2_FB20_Pos    (20U)
#define CAN_F4R2_FB20_Msk    (0x1UL << CAN_F4R2_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F4R2_FB20        CAN_F4R2_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F4R2_FB21_Pos    (21U)
#define CAN_F4R2_FB21_Msk    (0x1UL << CAN_F4R2_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F4R2_FB21        CAN_F4R2_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F4R2_FB22_Pos    (22U)
#define CAN_F4R2_FB22_Msk    (0x1UL << CAN_F4R2_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F4R2_FB22        CAN_F4R2_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F4R2_FB23_Pos    (23U)
#define CAN_F4R2_FB23_Msk    (0x1UL << CAN_F4R2_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F4R2_FB23        CAN_F4R2_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F4R2_FB24_Pos    (24U)
#define CAN_F4R2_FB24_Msk    (0x1UL << CAN_F4R2_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F4R2_FB24        CAN_F4R2_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F4R2_FB25_Pos    (25U)
#define CAN_F4R2_FB25_Msk    (0x1UL << CAN_F4R2_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F4R2_FB25        CAN_F4R2_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F4R2_FB26_Pos    (26U)
#define CAN_F4R2_FB26_Msk    (0x1UL << CAN_F4R2_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F4R2_FB26        CAN_F4R2_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F4R2_FB27_Pos    (27U)
#define CAN_F4R2_FB27_Msk    (0x1UL << CAN_F4R2_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F4R2_FB27        CAN_F4R2_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F4R2_FB28_Pos    (28U)
#define CAN_F4R2_FB28_Msk    (0x1UL << CAN_F4R2_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F4R2_FB28        CAN_F4R2_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F4R2_FB29_Pos    (29U)
#define CAN_F4R2_FB29_Msk    (0x1UL << CAN_F4R2_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F4R2_FB29        CAN_F4R2_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F4R2_FB30_Pos    (30U)
#define CAN_F4R2_FB30_Msk    (0x1UL << CAN_F4R2_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F4R2_FB30        CAN_F4R2_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F4R2_FB31_Pos    (31U)
#define CAN_F4R2_FB31_Msk    (0x1UL << CAN_F4R2_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F4R2_FB31        CAN_F4R2_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F5R2 register  *******************/
#define CAN_F5R2_FB0_Pos     (0U)
#define CAN_F5R2_FB0_Msk     (0x1UL << CAN_F5R2_FB0_Pos)/*!< 0x00000001 */
#define CAN_F5R2_FB0         CAN_F5R2_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F5R2_FB1_Pos     (1U)
#define CAN_F5R2_FB1_Msk     (0x1UL << CAN_F5R2_FB1_Pos)/*!< 0x00000002 */
#define CAN_F5R2_FB1         CAN_F5R2_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F5R2_FB2_Pos     (2U)
#define CAN_F5R2_FB2_Msk     (0x1UL << CAN_F5R2_FB2_Pos)/*!< 0x00000004 */
#define CAN_F5R2_FB2         CAN_F5R2_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F5R2_FB3_Pos     (3U)
#define CAN_F5R2_FB3_Msk     (0x1UL << CAN_F5R2_FB3_Pos)/*!< 0x00000008 */
#define CAN_F5R2_FB3         CAN_F5R2_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F5R2_FB4_Pos     (4U)
#define CAN_F5R2_FB4_Msk     (0x1UL << CAN_F5R2_FB4_Pos)/*!< 0x00000010 */
#define CAN_F5R2_FB4         CAN_F5R2_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F5R2_FB5_Pos     (5U)
#define CAN_F5R2_FB5_Msk     (0x1UL << CAN_F5R2_FB5_Pos)/*!< 0x00000020 */
#define CAN_F5R2_FB5         CAN_F5R2_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F5R2_FB6_Pos     (6U)
#define CAN_F5R2_FB6_Msk     (0x1UL << CAN_F5R2_FB6_Pos)/*!< 0x00000040 */
#define CAN_F5R2_FB6         CAN_F5R2_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F5R2_FB7_Pos     (7U)
#define CAN_F5R2_FB7_Msk     (0x1UL << CAN_F5R2_FB7_Pos)/*!< 0x00000080 */
#define CAN_F5R2_FB7         CAN_F5R2_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F5R2_FB8_Pos     (8U)
#define CAN_F5R2_FB8_Msk     (0x1UL << CAN_F5R2_FB8_Pos)/*!< 0x00000100 */
#define CAN_F5R2_FB8         CAN_F5R2_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F5R2_FB9_Pos     (9U)
#define CAN_F5R2_FB9_Msk     (0x1UL << CAN_F5R2_FB9_Pos)/*!< 0x00000200 */
#define CAN_F5R2_FB9         CAN_F5R2_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F5R2_FB10_Pos    (10U)
#define CAN_F5R2_FB10_Msk    (0x1UL << CAN_F5R2_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F5R2_FB10        CAN_F5R2_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F5R2_FB11_Pos    (11U)
#define CAN_F5R2_FB11_Msk    (0x1UL << CAN_F5R2_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F5R2_FB11        CAN_F5R2_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F5R2_FB12_Pos    (12U)
#define CAN_F5R2_FB12_Msk    (0x1UL << CAN_F5R2_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F5R2_FB12        CAN_F5R2_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F5R2_FB13_Pos    (13U)
#define CAN_F5R2_FB13_Msk    (0x1UL << CAN_F5R2_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F5R2_FB13        CAN_F5R2_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F5R2_FB14_Pos    (14U)
#define CAN_F5R2_FB14_Msk    (0x1UL << CAN_F5R2_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F5R2_FB14        CAN_F5R2_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F5R2_FB15_Pos    (15U)
#define CAN_F5R2_FB15_Msk    (0x1UL << CAN_F5R2_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F5R2_FB15        CAN_F5R2_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F5R2_FB16_Pos    (16U)
#define CAN_F5R2_FB16_Msk    (0x1UL << CAN_F5R2_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F5R2_FB16        CAN_F5R2_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F5R2_FB17_Pos    (17U)
#define CAN_F5R2_FB17_Msk    (0x1UL << CAN_F5R2_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F5R2_FB17        CAN_F5R2_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F5R2_FB18_Pos    (18U)
#define CAN_F5R2_FB18_Msk    (0x1UL << CAN_F5R2_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F5R2_FB18        CAN_F5R2_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F5R2_FB19_Pos    (19U)
#define CAN_F5R2_FB19_Msk    (0x1UL << CAN_F5R2_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F5R2_FB19        CAN_F5R2_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F5R2_FB20_Pos    (20U)
#define CAN_F5R2_FB20_Msk    (0x1UL << CAN_F5R2_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F5R2_FB20        CAN_F5R2_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F5R2_FB21_Pos    (21U)
#define CAN_F5R2_FB21_Msk    (0x1UL << CAN_F5R2_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F5R2_FB21        CAN_F5R2_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F5R2_FB22_Pos    (22U)
#define CAN_F5R2_FB22_Msk    (0x1UL << CAN_F5R2_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F5R2_FB22        CAN_F5R2_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F5R2_FB23_Pos    (23U)
#define CAN_F5R2_FB23_Msk    (0x1UL << CAN_F5R2_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F5R2_FB23        CAN_F5R2_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F5R2_FB24_Pos    (24U)
#define CAN_F5R2_FB24_Msk    (0x1UL << CAN_F5R2_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F5R2_FB24        CAN_F5R2_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F5R2_FB25_Pos    (25U)
#define CAN_F5R2_FB25_Msk    (0x1UL << CAN_F5R2_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F5R2_FB25        CAN_F5R2_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F5R2_FB26_Pos    (26U)
#define CAN_F5R2_FB26_Msk    (0x1UL << CAN_F5R2_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F5R2_FB26        CAN_F5R2_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F5R2_FB27_Pos    (27U)
#define CAN_F5R2_FB27_Msk    (0x1UL << CAN_F5R2_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F5R2_FB27        CAN_F5R2_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F5R2_FB28_Pos    (28U)
#define CAN_F5R2_FB28_Msk    (0x1UL << CAN_F5R2_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F5R2_FB28        CAN_F5R2_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F5R2_FB29_Pos    (29U)
#define CAN_F5R2_FB29_Msk    (0x1UL << CAN_F5R2_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F5R2_FB29        CAN_F5R2_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F5R2_FB30_Pos    (30U)
#define CAN_F5R2_FB30_Msk    (0x1UL << CAN_F5R2_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F5R2_FB30        CAN_F5R2_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F5R2_FB31_Pos    (31U)
#define CAN_F5R2_FB31_Msk    (0x1UL << CAN_F5R2_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F5R2_FB31        CAN_F5R2_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F6R2 register  *******************/
#define CAN_F6R2_FB0_Pos     (0U)
#define CAN_F6R2_FB0_Msk     (0x1UL << CAN_F6R2_FB0_Pos)/*!< 0x00000001 */
#define CAN_F6R2_FB0         CAN_F6R2_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F6R2_FB1_Pos     (1U)
#define CAN_F6R2_FB1_Msk     (0x1UL << CAN_F6R2_FB1_Pos)/*!< 0x00000002 */
#define CAN_F6R2_FB1         CAN_F6R2_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F6R2_FB2_Pos     (2U)
#define CAN_F6R2_FB2_Msk     (0x1UL << CAN_F6R2_FB2_Pos)/*!< 0x00000004 */
#define CAN_F6R2_FB2         CAN_F6R2_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F6R2_FB3_Pos     (3U)
#define CAN_F6R2_FB3_Msk     (0x1UL << CAN_F6R2_FB3_Pos)/*!< 0x00000008 */
#define CAN_F6R2_FB3         CAN_F6R2_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F6R2_FB4_Pos     (4U)
#define CAN_F6R2_FB4_Msk     (0x1UL << CAN_F6R2_FB4_Pos)/*!< 0x00000010 */
#define CAN_F6R2_FB4         CAN_F6R2_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F6R2_FB5_Pos     (5U)
#define CAN_F6R2_FB5_Msk     (0x1UL << CAN_F6R2_FB5_Pos)/*!< 0x00000020 */
#define CAN_F6R2_FB5         CAN_F6R2_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F6R2_FB6_Pos     (6U)
#define CAN_F6R2_FB6_Msk     (0x1UL << CAN_F6R2_FB6_Pos)/*!< 0x00000040 */
#define CAN_F6R2_FB6         CAN_F6R2_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F6R2_FB7_Pos     (7U)
#define CAN_F6R2_FB7_Msk     (0x1UL << CAN_F6R2_FB7_Pos)/*!< 0x00000080 */
#define CAN_F6R2_FB7         CAN_F6R2_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F6R2_FB8_Pos     (8U)
#define CAN_F6R2_FB8_Msk     (0x1UL << CAN_F6R2_FB8_Pos)/*!< 0x00000100 */
#define CAN_F6R2_FB8         CAN_F6R2_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F6R2_FB9_Pos     (9U)
#define CAN_F6R2_FB9_Msk     (0x1UL << CAN_F6R2_FB9_Pos)/*!< 0x00000200 */
#define CAN_F6R2_FB9         CAN_F6R2_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F6R2_FB10_Pos    (10U)
#define CAN_F6R2_FB10_Msk    (0x1UL << CAN_F6R2_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F6R2_FB10        CAN_F6R2_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F6R2_FB11_Pos    (11U)
#define CAN_F6R2_FB11_Msk    (0x1UL << CAN_F6R2_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F6R2_FB11        CAN_F6R2_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F6R2_FB12_Pos    (12U)
#define CAN_F6R2_FB12_Msk    (0x1UL << CAN_F6R2_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F6R2_FB12        CAN_F6R2_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F6R2_FB13_Pos    (13U)
#define CAN_F6R2_FB13_Msk    (0x1UL << CAN_F6R2_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F6R2_FB13        CAN_F6R2_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F6R2_FB14_Pos    (14U)
#define CAN_F6R2_FB14_Msk    (0x1UL << CAN_F6R2_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F6R2_FB14        CAN_F6R2_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F6R2_FB15_Pos    (15U)
#define CAN_F6R2_FB15_Msk    (0x1UL << CAN_F6R2_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F6R2_FB15        CAN_F6R2_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F6R2_FB16_Pos    (16U)
#define CAN_F6R2_FB16_Msk    (0x1UL << CAN_F6R2_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F6R2_FB16        CAN_F6R2_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F6R2_FB17_Pos    (17U)
#define CAN_F6R2_FB17_Msk    (0x1UL << CAN_F6R2_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F6R2_FB17        CAN_F6R2_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F6R2_FB18_Pos    (18U)
#define CAN_F6R2_FB18_Msk    (0x1UL << CAN_F6R2_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F6R2_FB18        CAN_F6R2_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F6R2_FB19_Pos    (19U)
#define CAN_F6R2_FB19_Msk    (0x1UL << CAN_F6R2_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F6R2_FB19        CAN_F6R2_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F6R2_FB20_Pos    (20U)
#define CAN_F6R2_FB20_Msk    (0x1UL << CAN_F6R2_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F6R2_FB20        CAN_F6R2_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F6R2_FB21_Pos    (21U)
#define CAN_F6R2_FB21_Msk    (0x1UL << CAN_F6R2_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F6R2_FB21        CAN_F6R2_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F6R2_FB22_Pos    (22U)
#define CAN_F6R2_FB22_Msk    (0x1UL << CAN_F6R2_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F6R2_FB22        CAN_F6R2_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F6R2_FB23_Pos    (23U)
#define CAN_F6R2_FB23_Msk    (0x1UL << CAN_F6R2_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F6R2_FB23        CAN_F6R2_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F6R2_FB24_Pos    (24U)
#define CAN_F6R2_FB24_Msk    (0x1UL << CAN_F6R2_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F6R2_FB24        CAN_F6R2_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F6R2_FB25_Pos    (25U)
#define CAN_F6R2_FB25_Msk    (0x1UL << CAN_F6R2_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F6R2_FB25        CAN_F6R2_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F6R2_FB26_Pos    (26U)
#define CAN_F6R2_FB26_Msk    (0x1UL << CAN_F6R2_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F6R2_FB26        CAN_F6R2_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F6R2_FB27_Pos    (27U)
#define CAN_F6R2_FB27_Msk    (0x1UL << CAN_F6R2_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F6R2_FB27        CAN_F6R2_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F6R2_FB28_Pos    (28U)
#define CAN_F6R2_FB28_Msk    (0x1UL << CAN_F6R2_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F6R2_FB28        CAN_F6R2_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F6R2_FB29_Pos    (29U)
#define CAN_F6R2_FB29_Msk    (0x1UL << CAN_F6R2_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F6R2_FB29        CAN_F6R2_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F6R2_FB30_Pos    (30U)
#define CAN_F6R2_FB30_Msk    (0x1UL << CAN_F6R2_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F6R2_FB30        CAN_F6R2_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F6R2_FB31_Pos    (31U)
#define CAN_F6R2_FB31_Msk    (0x1UL << CAN_F6R2_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F6R2_FB31        CAN_F6R2_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F7R2 register  *******************/
#define CAN_F7R2_FB0_Pos     (0U)
#define CAN_F7R2_FB0_Msk     (0x1UL << CAN_F7R2_FB0_Pos)/*!< 0x00000001 */
#define CAN_F7R2_FB0         CAN_F7R2_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F7R2_FB1_Pos     (1U)
#define CAN_F7R2_FB1_Msk     (0x1UL << CAN_F7R2_FB1_Pos)/*!< 0x00000002 */
#define CAN_F7R2_FB1         CAN_F7R2_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F7R2_FB2_Pos     (2U)
#define CAN_F7R2_FB2_Msk     (0x1UL << CAN_F7R2_FB2_Pos)/*!< 0x00000004 */
#define CAN_F7R2_FB2         CAN_F7R2_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F7R2_FB3_Pos     (3U)
#define CAN_F7R2_FB3_Msk     (0x1UL << CAN_F7R2_FB3_Pos)/*!< 0x00000008 */
#define CAN_F7R2_FB3         CAN_F7R2_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F7R2_FB4_Pos     (4U)
#define CAN_F7R2_FB4_Msk     (0x1UL << CAN_F7R2_FB4_Pos)/*!< 0x00000010 */
#define CAN_F7R2_FB4         CAN_F7R2_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F7R2_FB5_Pos     (5U)
#define CAN_F7R2_FB5_Msk     (0x1UL << CAN_F7R2_FB5_Pos)/*!< 0x00000020 */
#define CAN_F7R2_FB5         CAN_F7R2_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F7R2_FB6_Pos     (6U)
#define CAN_F7R2_FB6_Msk     (0x1UL << CAN_F7R2_FB6_Pos)/*!< 0x00000040 */
#define CAN_F7R2_FB6         CAN_F7R2_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F7R2_FB7_Pos     (7U)
#define CAN_F7R2_FB7_Msk     (0x1UL << CAN_F7R2_FB7_Pos)/*!< 0x00000080 */
#define CAN_F7R2_FB7         CAN_F7R2_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F7R2_FB8_Pos     (8U)
#define CAN_F7R2_FB8_Msk     (0x1UL << CAN_F7R2_FB8_Pos)/*!< 0x00000100 */
#define CAN_F7R2_FB8         CAN_F7R2_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F7R2_FB9_Pos     (9U)
#define CAN_F7R2_FB9_Msk     (0x1UL << CAN_F7R2_FB9_Pos)/*!< 0x00000200 */
#define CAN_F7R2_FB9         CAN_F7R2_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F7R2_FB10_Pos    (10U)
#define CAN_F7R2_FB10_Msk    (0x1UL << CAN_F7R2_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F7R2_FB10        CAN_F7R2_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F7R2_FB11_Pos    (11U)
#define CAN_F7R2_FB11_Msk    (0x1UL << CAN_F7R2_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F7R2_FB11        CAN_F7R2_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F7R2_FB12_Pos    (12U)
#define CAN_F7R2_FB12_Msk    (0x1UL << CAN_F7R2_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F7R2_FB12        CAN_F7R2_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F7R2_FB13_Pos    (13U)
#define CAN_F7R2_FB13_Msk    (0x1UL << CAN_F7R2_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F7R2_FB13        CAN_F7R2_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F7R2_FB14_Pos    (14U)
#define CAN_F7R2_FB14_Msk    (0x1UL << CAN_F7R2_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F7R2_FB14        CAN_F7R2_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F7R2_FB15_Pos    (15U)
#define CAN_F7R2_FB15_Msk    (0x1UL << CAN_F7R2_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F7R2_FB15        CAN_F7R2_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F7R2_FB16_Pos    (16U)
#define CAN_F7R2_FB16_Msk    (0x1UL << CAN_F7R2_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F7R2_FB16        CAN_F7R2_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F7R2_FB17_Pos    (17U)
#define CAN_F7R2_FB17_Msk    (0x1UL << CAN_F7R2_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F7R2_FB17        CAN_F7R2_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F7R2_FB18_Pos    (18U)
#define CAN_F7R2_FB18_Msk    (0x1UL << CAN_F7R2_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F7R2_FB18        CAN_F7R2_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F7R2_FB19_Pos    (19U)
#define CAN_F7R2_FB19_Msk    (0x1UL << CAN_F7R2_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F7R2_FB19        CAN_F7R2_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F7R2_FB20_Pos    (20U)
#define CAN_F7R2_FB20_Msk    (0x1UL << CAN_F7R2_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F7R2_FB20        CAN_F7R2_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F7R2_FB21_Pos    (21U)
#define CAN_F7R2_FB21_Msk    (0x1UL << CAN_F7R2_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F7R2_FB21        CAN_F7R2_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F7R2_FB22_Pos    (22U)
#define CAN_F7R2_FB22_Msk    (0x1UL << CAN_F7R2_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F7R2_FB22        CAN_F7R2_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F7R2_FB23_Pos    (23U)
#define CAN_F7R2_FB23_Msk    (0x1UL << CAN_F7R2_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F7R2_FB23        CAN_F7R2_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F7R2_FB24_Pos    (24U)
#define CAN_F7R2_FB24_Msk    (0x1UL << CAN_F7R2_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F7R2_FB24        CAN_F7R2_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F7R2_FB25_Pos    (25U)
#define CAN_F7R2_FB25_Msk    (0x1UL << CAN_F7R2_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F7R2_FB25        CAN_F7R2_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F7R2_FB26_Pos    (26U)
#define CAN_F7R2_FB26_Msk    (0x1UL << CAN_F7R2_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F7R2_FB26        CAN_F7R2_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F7R2_FB27_Pos    (27U)
#define CAN_F7R2_FB27_Msk    (0x1UL << CAN_F7R2_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F7R2_FB27        CAN_F7R2_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F7R2_FB28_Pos    (28U)
#define CAN_F7R2_FB28_Msk    (0x1UL << CAN_F7R2_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F7R2_FB28        CAN_F7R2_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F7R2_FB29_Pos    (29U)
#define CAN_F7R2_FB29_Msk    (0x1UL << CAN_F7R2_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F7R2_FB29        CAN_F7R2_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F7R2_FB30_Pos    (30U)
#define CAN_F7R2_FB30_Msk    (0x1UL << CAN_F7R2_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F7R2_FB30        CAN_F7R2_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F7R2_FB31_Pos    (31U)
#define CAN_F7R2_FB31_Msk    (0x1UL << CAN_F7R2_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F7R2_FB31        CAN_F7R2_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F8R2 register  *******************/
#define CAN_F8R2_FB0_Pos     (0U)
#define CAN_F8R2_FB0_Msk     (0x1UL << CAN_F8R2_FB0_Pos)/*!< 0x00000001 */
#define CAN_F8R2_FB0         CAN_F8R2_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F8R2_FB1_Pos     (1U)
#define CAN_F8R2_FB1_Msk     (0x1UL << CAN_F8R2_FB1_Pos)/*!< 0x00000002 */
#define CAN_F8R2_FB1         CAN_F8R2_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F8R2_FB2_Pos     (2U)
#define CAN_F8R2_FB2_Msk     (0x1UL << CAN_F8R2_FB2_Pos)/*!< 0x00000004 */
#define CAN_F8R2_FB2         CAN_F8R2_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F8R2_FB3_Pos     (3U)
#define CAN_F8R2_FB3_Msk     (0x1UL << CAN_F8R2_FB3_Pos)/*!< 0x00000008 */
#define CAN_F8R2_FB3         CAN_F8R2_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F8R2_FB4_Pos     (4U)
#define CAN_F8R2_FB4_Msk     (0x1UL << CAN_F8R2_FB4_Pos)/*!< 0x00000010 */
#define CAN_F8R2_FB4         CAN_F8R2_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F8R2_FB5_Pos     (5U)
#define CAN_F8R2_FB5_Msk     (0x1UL << CAN_F8R2_FB5_Pos)/*!< 0x00000020 */
#define CAN_F8R2_FB5         CAN_F8R2_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F8R2_FB6_Pos     (6U)
#define CAN_F8R2_FB6_Msk     (0x1UL << CAN_F8R2_FB6_Pos)/*!< 0x00000040 */
#define CAN_F8R2_FB6         CAN_F8R2_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F8R2_FB7_Pos     (7U)
#define CAN_F8R2_FB7_Msk     (0x1UL << CAN_F8R2_FB7_Pos)/*!< 0x00000080 */
#define CAN_F8R2_FB7         CAN_F8R2_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F8R2_FB8_Pos     (8U)
#define CAN_F8R2_FB8_Msk     (0x1UL << CAN_F8R2_FB8_Pos)/*!< 0x00000100 */
#define CAN_F8R2_FB8         CAN_F8R2_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F8R2_FB9_Pos     (9U)
#define CAN_F8R2_FB9_Msk     (0x1UL << CAN_F8R2_FB9_Pos)/*!< 0x00000200 */
#define CAN_F8R2_FB9         CAN_F8R2_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F8R2_FB10_Pos    (10U)
#define CAN_F8R2_FB10_Msk    (0x1UL << CAN_F8R2_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F8R2_FB10        CAN_F8R2_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F8R2_FB11_Pos    (11U)
#define CAN_F8R2_FB11_Msk    (0x1UL << CAN_F8R2_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F8R2_FB11        CAN_F8R2_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F8R2_FB12_Pos    (12U)
#define CAN_F8R2_FB12_Msk    (0x1UL << CAN_F8R2_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F8R2_FB12        CAN_F8R2_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F8R2_FB13_Pos    (13U)
#define CAN_F8R2_FB13_Msk    (0x1UL << CAN_F8R2_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F8R2_FB13        CAN_F8R2_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F8R2_FB14_Pos    (14U)
#define CAN_F8R2_FB14_Msk    (0x1UL << CAN_F8R2_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F8R2_FB14        CAN_F8R2_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F8R2_FB15_Pos    (15U)
#define CAN_F8R2_FB15_Msk    (0x1UL << CAN_F8R2_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F8R2_FB15        CAN_F8R2_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F8R2_FB16_Pos    (16U)
#define CAN_F8R2_FB16_Msk    (0x1UL << CAN_F8R2_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F8R2_FB16        CAN_F8R2_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F8R2_FB17_Pos    (17U)
#define CAN_F8R2_FB17_Msk    (0x1UL << CAN_F8R2_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F8R2_FB17        CAN_F8R2_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F8R2_FB18_Pos    (18U)
#define CAN_F8R2_FB18_Msk    (0x1UL << CAN_F8R2_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F8R2_FB18        CAN_F8R2_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F8R2_FB19_Pos    (19U)
#define CAN_F8R2_FB19_Msk    (0x1UL << CAN_F8R2_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F8R2_FB19        CAN_F8R2_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F8R2_FB20_Pos    (20U)
#define CAN_F8R2_FB20_Msk    (0x1UL << CAN_F8R2_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F8R2_FB20        CAN_F8R2_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F8R2_FB21_Pos    (21U)
#define CAN_F8R2_FB21_Msk    (0x1UL << CAN_F8R2_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F8R2_FB21        CAN_F8R2_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F8R2_FB22_Pos    (22U)
#define CAN_F8R2_FB22_Msk    (0x1UL << CAN_F8R2_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F8R2_FB22        CAN_F8R2_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F8R2_FB23_Pos    (23U)
#define CAN_F8R2_FB23_Msk    (0x1UL << CAN_F8R2_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F8R2_FB23        CAN_F8R2_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F8R2_FB24_Pos    (24U)
#define CAN_F8R2_FB24_Msk    (0x1UL << CAN_F8R2_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F8R2_FB24        CAN_F8R2_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F8R2_FB25_Pos    (25U)
#define CAN_F8R2_FB25_Msk    (0x1UL << CAN_F8R2_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F8R2_FB25        CAN_F8R2_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F8R2_FB26_Pos    (26U)
#define CAN_F8R2_FB26_Msk    (0x1UL << CAN_F8R2_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F8R2_FB26        CAN_F8R2_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F8R2_FB27_Pos    (27U)
#define CAN_F8R2_FB27_Msk    (0x1UL << CAN_F8R2_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F8R2_FB27        CAN_F8R2_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F8R2_FB28_Pos    (28U)
#define CAN_F8R2_FB28_Msk    (0x1UL << CAN_F8R2_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F8R2_FB28        CAN_F8R2_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F8R2_FB29_Pos    (29U)
#define CAN_F8R2_FB29_Msk    (0x1UL << CAN_F8R2_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F8R2_FB29        CAN_F8R2_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F8R2_FB30_Pos    (30U)
#define CAN_F8R2_FB30_Msk    (0x1UL << CAN_F8R2_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F8R2_FB30        CAN_F8R2_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F8R2_FB31_Pos    (31U)
#define CAN_F8R2_FB31_Msk    (0x1UL << CAN_F8R2_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F8R2_FB31        CAN_F8R2_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F9R2 register  *******************/
#define CAN_F9R2_FB0_Pos     (0U)
#define CAN_F9R2_FB0_Msk     (0x1UL << CAN_F9R2_FB0_Pos)/*!< 0x00000001 */
#define CAN_F9R2_FB0         CAN_F9R2_FB0_Msk	/*!<Filter bit 0 */
#define CAN_F9R2_FB1_Pos     (1U)
#define CAN_F9R2_FB1_Msk     (0x1UL << CAN_F9R2_FB1_Pos)/*!< 0x00000002 */
#define CAN_F9R2_FB1         CAN_F9R2_FB1_Msk	/*!<Filter bit 1 */
#define CAN_F9R2_FB2_Pos     (2U)
#define CAN_F9R2_FB2_Msk     (0x1UL << CAN_F9R2_FB2_Pos)/*!< 0x00000004 */
#define CAN_F9R2_FB2         CAN_F9R2_FB2_Msk	/*!<Filter bit 2 */
#define CAN_F9R2_FB3_Pos     (3U)
#define CAN_F9R2_FB3_Msk     (0x1UL << CAN_F9R2_FB3_Pos)/*!< 0x00000008 */
#define CAN_F9R2_FB3         CAN_F9R2_FB3_Msk	/*!<Filter bit 3 */
#define CAN_F9R2_FB4_Pos     (4U)
#define CAN_F9R2_FB4_Msk     (0x1UL << CAN_F9R2_FB4_Pos)/*!< 0x00000010 */
#define CAN_F9R2_FB4         CAN_F9R2_FB4_Msk	/*!<Filter bit 4 */
#define CAN_F9R2_FB5_Pos     (5U)
#define CAN_F9R2_FB5_Msk     (0x1UL << CAN_F9R2_FB5_Pos)/*!< 0x00000020 */
#define CAN_F9R2_FB5         CAN_F9R2_FB5_Msk	/*!<Filter bit 5 */
#define CAN_F9R2_FB6_Pos     (6U)
#define CAN_F9R2_FB6_Msk     (0x1UL << CAN_F9R2_FB6_Pos)/*!< 0x00000040 */
#define CAN_F9R2_FB6         CAN_F9R2_FB6_Msk	/*!<Filter bit 6 */
#define CAN_F9R2_FB7_Pos     (7U)
#define CAN_F9R2_FB7_Msk     (0x1UL << CAN_F9R2_FB7_Pos)/*!< 0x00000080 */
#define CAN_F9R2_FB7         CAN_F9R2_FB7_Msk	/*!<Filter bit 7 */
#define CAN_F9R2_FB8_Pos     (8U)
#define CAN_F9R2_FB8_Msk     (0x1UL << CAN_F9R2_FB8_Pos)/*!< 0x00000100 */
#define CAN_F9R2_FB8         CAN_F9R2_FB8_Msk	/*!<Filter bit 8 */
#define CAN_F9R2_FB9_Pos     (9U)
#define CAN_F9R2_FB9_Msk     (0x1UL << CAN_F9R2_FB9_Pos)/*!< 0x00000200 */
#define CAN_F9R2_FB9         CAN_F9R2_FB9_Msk	/*!<Filter bit 9 */
#define CAN_F9R2_FB10_Pos    (10U)
#define CAN_F9R2_FB10_Msk    (0x1UL << CAN_F9R2_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F9R2_FB10        CAN_F9R2_FB10_Msk				/*!<Filter bit 10 */
#define CAN_F9R2_FB11_Pos    (11U)
#define CAN_F9R2_FB11_Msk    (0x1UL << CAN_F9R2_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F9R2_FB11        CAN_F9R2_FB11_Msk				/*!<Filter bit 11 */
#define CAN_F9R2_FB12_Pos    (12U)
#define CAN_F9R2_FB12_Msk    (0x1UL << CAN_F9R2_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F9R2_FB12        CAN_F9R2_FB12_Msk				/*!<Filter bit 12 */
#define CAN_F9R2_FB13_Pos    (13U)
#define CAN_F9R2_FB13_Msk    (0x1UL << CAN_F9R2_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F9R2_FB13        CAN_F9R2_FB13_Msk				/*!<Filter bit 13 */
#define CAN_F9R2_FB14_Pos    (14U)
#define CAN_F9R2_FB14_Msk    (0x1UL << CAN_F9R2_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F9R2_FB14        CAN_F9R2_FB14_Msk				/*!<Filter bit 14 */
#define CAN_F9R2_FB15_Pos    (15U)
#define CAN_F9R2_FB15_Msk    (0x1UL << CAN_F9R2_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F9R2_FB15        CAN_F9R2_FB15_Msk				/*!<Filter bit 15 */
#define CAN_F9R2_FB16_Pos    (16U)
#define CAN_F9R2_FB16_Msk    (0x1UL << CAN_F9R2_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F9R2_FB16        CAN_F9R2_FB16_Msk				/*!<Filter bit 16 */
#define CAN_F9R2_FB17_Pos    (17U)
#define CAN_F9R2_FB17_Msk    (0x1UL << CAN_F9R2_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F9R2_FB17        CAN_F9R2_FB17_Msk				/*!<Filter bit 17 */
#define CAN_F9R2_FB18_Pos    (18U)
#define CAN_F9R2_FB18_Msk    (0x1UL << CAN_F9R2_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F9R2_FB18        CAN_F9R2_FB18_Msk				/*!<Filter bit 18 */
#define CAN_F9R2_FB19_Pos    (19U)
#define CAN_F9R2_FB19_Msk    (0x1UL << CAN_F9R2_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F9R2_FB19        CAN_F9R2_FB19_Msk				/*!<Filter bit 19 */
#define CAN_F9R2_FB20_Pos    (20U)
#define CAN_F9R2_FB20_Msk    (0x1UL << CAN_F9R2_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F9R2_FB20        CAN_F9R2_FB20_Msk				/*!<Filter bit 20 */
#define CAN_F9R2_FB21_Pos    (21U)
#define CAN_F9R2_FB21_Msk    (0x1UL << CAN_F9R2_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F9R2_FB21        CAN_F9R2_FB21_Msk				/*!<Filter bit 21 */
#define CAN_F9R2_FB22_Pos    (22U)
#define CAN_F9R2_FB22_Msk    (0x1UL << CAN_F9R2_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F9R2_FB22        CAN_F9R2_FB22_Msk				/*!<Filter bit 22 */
#define CAN_F9R2_FB23_Pos    (23U)
#define CAN_F9R2_FB23_Msk    (0x1UL << CAN_F9R2_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F9R2_FB23        CAN_F9R2_FB23_Msk				/*!<Filter bit 23 */
#define CAN_F9R2_FB24_Pos    (24U)
#define CAN_F9R2_FB24_Msk    (0x1UL << CAN_F9R2_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F9R2_FB24        CAN_F9R2_FB24_Msk				/*!<Filter bit 24 */
#define CAN_F9R2_FB25_Pos    (25U)
#define CAN_F9R2_FB25_Msk    (0x1UL << CAN_F9R2_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F9R2_FB25        CAN_F9R2_FB25_Msk				/*!<Filter bit 25 */
#define CAN_F9R2_FB26_Pos    (26U)
#define CAN_F9R2_FB26_Msk    (0x1UL << CAN_F9R2_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F9R2_FB26        CAN_F9R2_FB26_Msk				/*!<Filter bit 26 */
#define CAN_F9R2_FB27_Pos    (27U)
#define CAN_F9R2_FB27_Msk    (0x1UL << CAN_F9R2_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F9R2_FB27        CAN_F9R2_FB27_Msk				/*!<Filter bit 27 */
#define CAN_F9R2_FB28_Pos    (28U)
#define CAN_F9R2_FB28_Msk    (0x1UL << CAN_F9R2_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F9R2_FB28        CAN_F9R2_FB28_Msk				/*!<Filter bit 28 */
#define CAN_F9R2_FB29_Pos    (29U)
#define CAN_F9R2_FB29_Msk    (0x1UL << CAN_F9R2_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F9R2_FB29        CAN_F9R2_FB29_Msk				/*!<Filter bit 29 */
#define CAN_F9R2_FB30_Pos    (30U)
#define CAN_F9R2_FB30_Msk    (0x1UL << CAN_F9R2_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F9R2_FB30        CAN_F9R2_FB30_Msk				/*!<Filter bit 30 */
#define CAN_F9R2_FB31_Pos    (31U)
#define CAN_F9R2_FB31_Msk    (0x1UL << CAN_F9R2_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F9R2_FB31        CAN_F9R2_FB31_Msk				/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F10R2 register  ******************/
#define CAN_F10R2_FB0_Pos     (0U)
#define CAN_F10R2_FB0_Msk     (0x1UL << CAN_F10R2_FB0_Pos)	/*!< 0x00000001 */
#define CAN_F10R2_FB0         CAN_F10R2_FB0_Msk				/*!<Filter bit 0 */
#define CAN_F10R2_FB1_Pos     (1U)
#define CAN_F10R2_FB1_Msk     (0x1UL << CAN_F10R2_FB1_Pos)	/*!< 0x00000002 */
#define CAN_F10R2_FB1         CAN_F10R2_FB1_Msk				/*!<Filter bit 1 */
#define CAN_F10R2_FB2_Pos     (2U)
#define CAN_F10R2_FB2_Msk     (0x1UL << CAN_F10R2_FB2_Pos)	/*!< 0x00000004 */
#define CAN_F10R2_FB2         CAN_F10R2_FB2_Msk				/*!<Filter bit 2 */
#define CAN_F10R2_FB3_Pos     (3U)
#define CAN_F10R2_FB3_Msk     (0x1UL << CAN_F10R2_FB3_Pos)	/*!< 0x00000008 */
#define CAN_F10R2_FB3         CAN_F10R2_FB3_Msk				/*!<Filter bit 3 */
#define CAN_F10R2_FB4_Pos     (4U)
#define CAN_F10R2_FB4_Msk     (0x1UL << CAN_F10R2_FB4_Pos)	/*!< 0x00000010 */
#define CAN_F10R2_FB4         CAN_F10R2_FB4_Msk				/*!<Filter bit 4 */
#define CAN_F10R2_FB5_Pos     (5U)
#define CAN_F10R2_FB5_Msk     (0x1UL << CAN_F10R2_FB5_Pos)	/*!< 0x00000020 */
#define CAN_F10R2_FB5         CAN_F10R2_FB5_Msk				/*!<Filter bit 5 */
#define CAN_F10R2_FB6_Pos     (6U)
#define CAN_F10R2_FB6_Msk     (0x1UL << CAN_F10R2_FB6_Pos)	/*!< 0x00000040 */
#define CAN_F10R2_FB6         CAN_F10R2_FB6_Msk				/*!<Filter bit 6 */
#define CAN_F10R2_FB7_Pos     (7U)
#define CAN_F10R2_FB7_Msk     (0x1UL << CAN_F10R2_FB7_Pos)	/*!< 0x00000080 */
#define CAN_F10R2_FB7         CAN_F10R2_FB7_Msk				/*!<Filter bit 7 */
#define CAN_F10R2_FB8_Pos     (8U)
#define CAN_F10R2_FB8_Msk     (0x1UL << CAN_F10R2_FB8_Pos)	/*!< 0x00000100 */
#define CAN_F10R2_FB8         CAN_F10R2_FB8_Msk				/*!<Filter bit 8 */
#define CAN_F10R2_FB9_Pos     (9U)
#define CAN_F10R2_FB9_Msk     (0x1UL << CAN_F10R2_FB9_Pos)	/*!< 0x00000200 */
#define CAN_F10R2_FB9         CAN_F10R2_FB9_Msk				/*!<Filter bit 9 */
#define CAN_F10R2_FB10_Pos    (10U)
#define CAN_F10R2_FB10_Msk    (0x1UL << CAN_F10R2_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F10R2_FB10        CAN_F10R2_FB10_Msk/*!<Filter bit 10 */
#define CAN_F10R2_FB11_Pos    (11U)
#define CAN_F10R2_FB11_Msk    (0x1UL << CAN_F10R2_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F10R2_FB11        CAN_F10R2_FB11_Msk/*!<Filter bit 11 */
#define CAN_F10R2_FB12_Pos    (12U)
#define CAN_F10R2_FB12_Msk    (0x1UL << CAN_F10R2_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F10R2_FB12        CAN_F10R2_FB12_Msk/*!<Filter bit 12 */
#define CAN_F10R2_FB13_Pos    (13U)
#define CAN_F10R2_FB13_Msk    (0x1UL << CAN_F10R2_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F10R2_FB13        CAN_F10R2_FB13_Msk/*!<Filter bit 13 */
#define CAN_F10R2_FB14_Pos    (14U)
#define CAN_F10R2_FB14_Msk    (0x1UL << CAN_F10R2_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F10R2_FB14        CAN_F10R2_FB14_Msk/*!<Filter bit 14 */
#define CAN_F10R2_FB15_Pos    (15U)
#define CAN_F10R2_FB15_Msk    (0x1UL << CAN_F10R2_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F10R2_FB15        CAN_F10R2_FB15_Msk/*!<Filter bit 15 */
#define CAN_F10R2_FB16_Pos    (16U)
#define CAN_F10R2_FB16_Msk    (0x1UL << CAN_F10R2_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F10R2_FB16        CAN_F10R2_FB16_Msk/*!<Filter bit 16 */
#define CAN_F10R2_FB17_Pos    (17U)
#define CAN_F10R2_FB17_Msk    (0x1UL << CAN_F10R2_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F10R2_FB17        CAN_F10R2_FB17_Msk/*!<Filter bit 17 */
#define CAN_F10R2_FB18_Pos    (18U)
#define CAN_F10R2_FB18_Msk    (0x1UL << CAN_F10R2_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F10R2_FB18        CAN_F10R2_FB18_Msk/*!<Filter bit 18 */
#define CAN_F10R2_FB19_Pos    (19U)
#define CAN_F10R2_FB19_Msk    (0x1UL << CAN_F10R2_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F10R2_FB19        CAN_F10R2_FB19_Msk/*!<Filter bit 19 */
#define CAN_F10R2_FB20_Pos    (20U)
#define CAN_F10R2_FB20_Msk    (0x1UL << CAN_F10R2_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F10R2_FB20        CAN_F10R2_FB20_Msk/*!<Filter bit 20 */
#define CAN_F10R2_FB21_Pos    (21U)
#define CAN_F10R2_FB21_Msk    (0x1UL << CAN_F10R2_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F10R2_FB21        CAN_F10R2_FB21_Msk/*!<Filter bit 21 */
#define CAN_F10R2_FB22_Pos    (22U)
#define CAN_F10R2_FB22_Msk    (0x1UL << CAN_F10R2_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F10R2_FB22        CAN_F10R2_FB22_Msk/*!<Filter bit 22 */
#define CAN_F10R2_FB23_Pos    (23U)
#define CAN_F10R2_FB23_Msk    (0x1UL << CAN_F10R2_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F10R2_FB23        CAN_F10R2_FB23_Msk/*!<Filter bit 23 */
#define CAN_F10R2_FB24_Pos    (24U)
#define CAN_F10R2_FB24_Msk    (0x1UL << CAN_F10R2_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F10R2_FB24        CAN_F10R2_FB24_Msk/*!<Filter bit 24 */
#define CAN_F10R2_FB25_Pos    (25U)
#define CAN_F10R2_FB25_Msk    (0x1UL << CAN_F10R2_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F10R2_FB25        CAN_F10R2_FB25_Msk/*!<Filter bit 25 */
#define CAN_F10R2_FB26_Pos    (26U)
#define CAN_F10R2_FB26_Msk    (0x1UL << CAN_F10R2_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F10R2_FB26        CAN_F10R2_FB26_Msk/*!<Filter bit 26 */
#define CAN_F10R2_FB27_Pos    (27U)
#define CAN_F10R2_FB27_Msk    (0x1UL << CAN_F10R2_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F10R2_FB27        CAN_F10R2_FB27_Msk/*!<Filter bit 27 */
#define CAN_F10R2_FB28_Pos    (28U)
#define CAN_F10R2_FB28_Msk    (0x1UL << CAN_F10R2_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F10R2_FB28        CAN_F10R2_FB28_Msk/*!<Filter bit 28 */
#define CAN_F10R2_FB29_Pos    (29U)
#define CAN_F10R2_FB29_Msk    (0x1UL << CAN_F10R2_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F10R2_FB29        CAN_F10R2_FB29_Msk/*!<Filter bit 29 */
#define CAN_F10R2_FB30_Pos    (30U)
#define CAN_F10R2_FB30_Msk    (0x1UL << CAN_F10R2_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F10R2_FB30        CAN_F10R2_FB30_Msk/*!<Filter bit 30 */
#define CAN_F10R2_FB31_Pos    (31U)
#define CAN_F10R2_FB31_Msk    (0x1UL << CAN_F10R2_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F10R2_FB31        CAN_F10R2_FB31_Msk/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F11R2 register  ******************/
#define CAN_F11R2_FB0_Pos     (0U)
#define CAN_F11R2_FB0_Msk     (0x1UL << CAN_F11R2_FB0_Pos)	/*!< 0x00000001 */
#define CAN_F11R2_FB0         CAN_F11R2_FB0_Msk				/*!<Filter bit 0 */
#define CAN_F11R2_FB1_Pos     (1U)
#define CAN_F11R2_FB1_Msk     (0x1UL << CAN_F11R2_FB1_Pos)	/*!< 0x00000002 */
#define CAN_F11R2_FB1         CAN_F11R2_FB1_Msk				/*!<Filter bit 1 */
#define CAN_F11R2_FB2_Pos     (2U)
#define CAN_F11R2_FB2_Msk     (0x1UL << CAN_F11R2_FB2_Pos)	/*!< 0x00000004 */
#define CAN_F11R2_FB2         CAN_F11R2_FB2_Msk				/*!<Filter bit 2 */
#define CAN_F11R2_FB3_Pos     (3U)
#define CAN_F11R2_FB3_Msk     (0x1UL << CAN_F11R2_FB3_Pos)	/*!< 0x00000008 */
#define CAN_F11R2_FB3         CAN_F11R2_FB3_Msk				/*!<Filter bit 3 */
#define CAN_F11R2_FB4_Pos     (4U)
#define CAN_F11R2_FB4_Msk     (0x1UL << CAN_F11R2_FB4_Pos)	/*!< 0x00000010 */
#define CAN_F11R2_FB4         CAN_F11R2_FB4_Msk				/*!<Filter bit 4 */
#define CAN_F11R2_FB5_Pos     (5U)
#define CAN_F11R2_FB5_Msk     (0x1UL << CAN_F11R2_FB5_Pos)	/*!< 0x00000020 */
#define CAN_F11R2_FB5         CAN_F11R2_FB5_Msk				/*!<Filter bit 5 */
#define CAN_F11R2_FB6_Pos     (6U)
#define CAN_F11R2_FB6_Msk     (0x1UL << CAN_F11R2_FB6_Pos)	/*!< 0x00000040 */
#define CAN_F11R2_FB6         CAN_F11R2_FB6_Msk				/*!<Filter bit 6 */
#define CAN_F11R2_FB7_Pos     (7U)
#define CAN_F11R2_FB7_Msk     (0x1UL << CAN_F11R2_FB7_Pos)	/*!< 0x00000080 */
#define CAN_F11R2_FB7         CAN_F11R2_FB7_Msk				/*!<Filter bit 7 */
#define CAN_F11R2_FB8_Pos     (8U)
#define CAN_F11R2_FB8_Msk     (0x1UL << CAN_F11R2_FB8_Pos)	/*!< 0x00000100 */
#define CAN_F11R2_FB8         CAN_F11R2_FB8_Msk				/*!<Filter bit 8 */
#define CAN_F11R2_FB9_Pos     (9U)
#define CAN_F11R2_FB9_Msk     (0x1UL << CAN_F11R2_FB9_Pos)	/*!< 0x00000200 */
#define CAN_F11R2_FB9         CAN_F11R2_FB9_Msk				/*!<Filter bit 9 */
#define CAN_F11R2_FB10_Pos    (10U)
#define CAN_F11R2_FB10_Msk    (0x1UL << CAN_F11R2_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F11R2_FB10        CAN_F11R2_FB10_Msk/*!<Filter bit 10 */
#define CAN_F11R2_FB11_Pos    (11U)
#define CAN_F11R2_FB11_Msk    (0x1UL << CAN_F11R2_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F11R2_FB11        CAN_F11R2_FB11_Msk/*!<Filter bit 11 */
#define CAN_F11R2_FB12_Pos    (12U)
#define CAN_F11R2_FB12_Msk    (0x1UL << CAN_F11R2_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F11R2_FB12        CAN_F11R2_FB12_Msk/*!<Filter bit 12 */
#define CAN_F11R2_FB13_Pos    (13U)
#define CAN_F11R2_FB13_Msk    (0x1UL << CAN_F11R2_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F11R2_FB13        CAN_F11R2_FB13_Msk/*!<Filter bit 13 */
#define CAN_F11R2_FB14_Pos    (14U)
#define CAN_F11R2_FB14_Msk    (0x1UL << CAN_F11R2_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F11R2_FB14        CAN_F11R2_FB14_Msk/*!<Filter bit 14 */
#define CAN_F11R2_FB15_Pos    (15U)
#define CAN_F11R2_FB15_Msk    (0x1UL << CAN_F11R2_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F11R2_FB15        CAN_F11R2_FB15_Msk/*!<Filter bit 15 */
#define CAN_F11R2_FB16_Pos    (16U)
#define CAN_F11R2_FB16_Msk    (0x1UL << CAN_F11R2_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F11R2_FB16        CAN_F11R2_FB16_Msk/*!<Filter bit 16 */
#define CAN_F11R2_FB17_Pos    (17U)
#define CAN_F11R2_FB17_Msk    (0x1UL << CAN_F11R2_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F11R2_FB17        CAN_F11R2_FB17_Msk/*!<Filter bit 17 */
#define CAN_F11R2_FB18_Pos    (18U)
#define CAN_F11R2_FB18_Msk    (0x1UL << CAN_F11R2_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F11R2_FB18        CAN_F11R2_FB18_Msk/*!<Filter bit 18 */
#define CAN_F11R2_FB19_Pos    (19U)
#define CAN_F11R2_FB19_Msk    (0x1UL << CAN_F11R2_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F11R2_FB19        CAN_F11R2_FB19_Msk/*!<Filter bit 19 */
#define CAN_F11R2_FB20_Pos    (20U)
#define CAN_F11R2_FB20_Msk    (0x1UL << CAN_F11R2_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F11R2_FB20        CAN_F11R2_FB20_Msk/*!<Filter bit 20 */
#define CAN_F11R2_FB21_Pos    (21U)
#define CAN_F11R2_FB21_Msk    (0x1UL << CAN_F11R2_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F11R2_FB21        CAN_F11R2_FB21_Msk/*!<Filter bit 21 */
#define CAN_F11R2_FB22_Pos    (22U)
#define CAN_F11R2_FB22_Msk    (0x1UL << CAN_F11R2_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F11R2_FB22        CAN_F11R2_FB22_Msk/*!<Filter bit 22 */
#define CAN_F11R2_FB23_Pos    (23U)
#define CAN_F11R2_FB23_Msk    (0x1UL << CAN_F11R2_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F11R2_FB23        CAN_F11R2_FB23_Msk/*!<Filter bit 23 */
#define CAN_F11R2_FB24_Pos    (24U)
#define CAN_F11R2_FB24_Msk    (0x1UL << CAN_F11R2_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F11R2_FB24        CAN_F11R2_FB24_Msk/*!<Filter bit 24 */
#define CAN_F11R2_FB25_Pos    (25U)
#define CAN_F11R2_FB25_Msk    (0x1UL << CAN_F11R2_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F11R2_FB25        CAN_F11R2_FB25_Msk/*!<Filter bit 25 */
#define CAN_F11R2_FB26_Pos    (26U)
#define CAN_F11R2_FB26_Msk    (0x1UL << CAN_F11R2_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F11R2_FB26        CAN_F11R2_FB26_Msk/*!<Filter bit 26 */
#define CAN_F11R2_FB27_Pos    (27U)
#define CAN_F11R2_FB27_Msk    (0x1UL << CAN_F11R2_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F11R2_FB27        CAN_F11R2_FB27_Msk/*!<Filter bit 27 */
#define CAN_F11R2_FB28_Pos    (28U)
#define CAN_F11R2_FB28_Msk    (0x1UL << CAN_F11R2_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F11R2_FB28        CAN_F11R2_FB28_Msk/*!<Filter bit 28 */
#define CAN_F11R2_FB29_Pos    (29U)
#define CAN_F11R2_FB29_Msk    (0x1UL << CAN_F11R2_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F11R2_FB29        CAN_F11R2_FB29_Msk/*!<Filter bit 29 */
#define CAN_F11R2_FB30_Pos    (30U)
#define CAN_F11R2_FB30_Msk    (0x1UL << CAN_F11R2_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F11R2_FB30        CAN_F11R2_FB30_Msk/*!<Filter bit 30 */
#define CAN_F11R2_FB31_Pos    (31U)
#define CAN_F11R2_FB31_Msk    (0x1UL << CAN_F11R2_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F11R2_FB31        CAN_F11R2_FB31_Msk/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F12R2 register  ******************/
#define CAN_F12R2_FB0_Pos     (0U)
#define CAN_F12R2_FB0_Msk     (0x1UL << CAN_F12R2_FB0_Pos)	/*!< 0x00000001 */
#define CAN_F12R2_FB0         CAN_F12R2_FB0_Msk				/*!<Filter bit 0 */
#define CAN_F12R2_FB1_Pos     (1U)
#define CAN_F12R2_FB1_Msk     (0x1UL << CAN_F12R2_FB1_Pos)	/*!< 0x00000002 */
#define CAN_F12R2_FB1         CAN_F12R2_FB1_Msk				/*!<Filter bit 1 */
#define CAN_F12R2_FB2_Pos     (2U)
#define CAN_F12R2_FB2_Msk     (0x1UL << CAN_F12R2_FB2_Pos)	/*!< 0x00000004 */
#define CAN_F12R2_FB2         CAN_F12R2_FB2_Msk				/*!<Filter bit 2 */
#define CAN_F12R2_FB3_Pos     (3U)
#define CAN_F12R2_FB3_Msk     (0x1UL << CAN_F12R2_FB3_Pos)	/*!< 0x00000008 */
#define CAN_F12R2_FB3         CAN_F12R2_FB3_Msk				/*!<Filter bit 3 */
#define CAN_F12R2_FB4_Pos     (4U)
#define CAN_F12R2_FB4_Msk     (0x1UL << CAN_F12R2_FB4_Pos)	/*!< 0x00000010 */
#define CAN_F12R2_FB4         CAN_F12R2_FB4_Msk				/*!<Filter bit 4 */
#define CAN_F12R2_FB5_Pos     (5U)
#define CAN_F12R2_FB5_Msk     (0x1UL << CAN_F12R2_FB5_Pos)	/*!< 0x00000020 */
#define CAN_F12R2_FB5         CAN_F12R2_FB5_Msk				/*!<Filter bit 5 */
#define CAN_F12R2_FB6_Pos     (6U)
#define CAN_F12R2_FB6_Msk     (0x1UL << CAN_F12R2_FB6_Pos)	/*!< 0x00000040 */
#define CAN_F12R2_FB6         CAN_F12R2_FB6_Msk				/*!<Filter bit 6 */
#define CAN_F12R2_FB7_Pos     (7U)
#define CAN_F12R2_FB7_Msk     (0x1UL << CAN_F12R2_FB7_Pos)	/*!< 0x00000080 */
#define CAN_F12R2_FB7         CAN_F12R2_FB7_Msk				/*!<Filter bit 7 */
#define CAN_F12R2_FB8_Pos     (8U)
#define CAN_F12R2_FB8_Msk     (0x1UL << CAN_F12R2_FB8_Pos)	/*!< 0x00000100 */
#define CAN_F12R2_FB8         CAN_F12R2_FB8_Msk				/*!<Filter bit 8 */
#define CAN_F12R2_FB9_Pos     (9U)
#define CAN_F12R2_FB9_Msk     (0x1UL << CAN_F12R2_FB9_Pos)	/*!< 0x00000200 */
#define CAN_F12R2_FB9         CAN_F12R2_FB9_Msk				/*!<Filter bit 9 */
#define CAN_F12R2_FB10_Pos    (10U)
#define CAN_F12R2_FB10_Msk    (0x1UL << CAN_F12R2_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F12R2_FB10        CAN_F12R2_FB10_Msk/*!<Filter bit 10 */
#define CAN_F12R2_FB11_Pos    (11U)
#define CAN_F12R2_FB11_Msk    (0x1UL << CAN_F12R2_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F12R2_FB11        CAN_F12R2_FB11_Msk/*!<Filter bit 11 */
#define CAN_F12R2_FB12_Pos    (12U)
#define CAN_F12R2_FB12_Msk    (0x1UL << CAN_F12R2_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F12R2_FB12        CAN_F12R2_FB12_Msk/*!<Filter bit 12 */
#define CAN_F12R2_FB13_Pos    (13U)
#define CAN_F12R2_FB13_Msk    (0x1UL << CAN_F12R2_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F12R2_FB13        CAN_F12R2_FB13_Msk/*!<Filter bit 13 */
#define CAN_F12R2_FB14_Pos    (14U)
#define CAN_F12R2_FB14_Msk    (0x1UL << CAN_F12R2_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F12R2_FB14        CAN_F12R2_FB14_Msk/*!<Filter bit 14 */
#define CAN_F12R2_FB15_Pos    (15U)
#define CAN_F12R2_FB15_Msk    (0x1UL << CAN_F12R2_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F12R2_FB15        CAN_F12R2_FB15_Msk/*!<Filter bit 15 */
#define CAN_F12R2_FB16_Pos    (16U)
#define CAN_F12R2_FB16_Msk    (0x1UL << CAN_F12R2_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F12R2_FB16        CAN_F12R2_FB16_Msk/*!<Filter bit 16 */
#define CAN_F12R2_FB17_Pos    (17U)
#define CAN_F12R2_FB17_Msk    (0x1UL << CAN_F12R2_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F12R2_FB17        CAN_F12R2_FB17_Msk/*!<Filter bit 17 */
#define CAN_F12R2_FB18_Pos    (18U)
#define CAN_F12R2_FB18_Msk    (0x1UL << CAN_F12R2_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F12R2_FB18        CAN_F12R2_FB18_Msk/*!<Filter bit 18 */
#define CAN_F12R2_FB19_Pos    (19U)
#define CAN_F12R2_FB19_Msk    (0x1UL << CAN_F12R2_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F12R2_FB19        CAN_F12R2_FB19_Msk/*!<Filter bit 19 */
#define CAN_F12R2_FB20_Pos    (20U)
#define CAN_F12R2_FB20_Msk    (0x1UL << CAN_F12R2_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F12R2_FB20        CAN_F12R2_FB20_Msk/*!<Filter bit 20 */
#define CAN_F12R2_FB21_Pos    (21U)
#define CAN_F12R2_FB21_Msk    (0x1UL << CAN_F12R2_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F12R2_FB21        CAN_F12R2_FB21_Msk/*!<Filter bit 21 */
#define CAN_F12R2_FB22_Pos    (22U)
#define CAN_F12R2_FB22_Msk    (0x1UL << CAN_F12R2_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F12R2_FB22        CAN_F12R2_FB22_Msk/*!<Filter bit 22 */
#define CAN_F12R2_FB23_Pos    (23U)
#define CAN_F12R2_FB23_Msk    (0x1UL << CAN_F12R2_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F12R2_FB23        CAN_F12R2_FB23_Msk/*!<Filter bit 23 */
#define CAN_F12R2_FB24_Pos    (24U)
#define CAN_F12R2_FB24_Msk    (0x1UL << CAN_F12R2_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F12R2_FB24        CAN_F12R2_FB24_Msk/*!<Filter bit 24 */
#define CAN_F12R2_FB25_Pos    (25U)
#define CAN_F12R2_FB25_Msk    (0x1UL << CAN_F12R2_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F12R2_FB25        CAN_F12R2_FB25_Msk/*!<Filter bit 25 */
#define CAN_F12R2_FB26_Pos    (26U)
#define CAN_F12R2_FB26_Msk    (0x1UL << CAN_F12R2_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F12R2_FB26        CAN_F12R2_FB26_Msk/*!<Filter bit 26 */
#define CAN_F12R2_FB27_Pos    (27U)
#define CAN_F12R2_FB27_Msk    (0x1UL << CAN_F12R2_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F12R2_FB27        CAN_F12R2_FB27_Msk/*!<Filter bit 27 */
#define CAN_F12R2_FB28_Pos    (28U)
#define CAN_F12R2_FB28_Msk    (0x1UL << CAN_F12R2_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F12R2_FB28        CAN_F12R2_FB28_Msk/*!<Filter bit 28 */
#define CAN_F12R2_FB29_Pos    (29U)
#define CAN_F12R2_FB29_Msk    (0x1UL << CAN_F12R2_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F12R2_FB29        CAN_F12R2_FB29_Msk/*!<Filter bit 29 */
#define CAN_F12R2_FB30_Pos    (30U)
#define CAN_F12R2_FB30_Msk    (0x1UL << CAN_F12R2_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F12R2_FB30        CAN_F12R2_FB30_Msk/*!<Filter bit 30 */
#define CAN_F12R2_FB31_Pos    (31U)
#define CAN_F12R2_FB31_Msk    (0x1UL << CAN_F12R2_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F12R2_FB31        CAN_F12R2_FB31_Msk/*!<Filter bit 31 */

/*******************  Bit definition for CAN_F13R2 register  ******************/
#define CAN_F13R2_FB0_Pos     (0U)
#define CAN_F13R2_FB0_Msk     (0x1UL << CAN_F13R2_FB0_Pos)	/*!< 0x00000001 */
#define CAN_F13R2_FB0         CAN_F13R2_FB0_Msk				/*!<Filter bit 0 */
#define CAN_F13R2_FB1_Pos     (1U)
#define CAN_F13R2_FB1_Msk     (0x1UL << CAN_F13R2_FB1_Pos)	/*!< 0x00000002 */
#define CAN_F13R2_FB1         CAN_F13R2_FB1_Msk				/*!<Filter bit 1 */
#define CAN_F13R2_FB2_Pos     (2U)
#define CAN_F13R2_FB2_Msk     (0x1UL << CAN_F13R2_FB2_Pos)	/*!< 0x00000004 */
#define CAN_F13R2_FB2         CAN_F13R2_FB2_Msk				/*!<Filter bit 2 */
#define CAN_F13R2_FB3_Pos     (3U)
#define CAN_F13R2_FB3_Msk     (0x1UL << CAN_F13R2_FB3_Pos)	/*!< 0x00000008 */
#define CAN_F13R2_FB3         CAN_F13R2_FB3_Msk				/*!<Filter bit 3 */
#define CAN_F13R2_FB4_Pos     (4U)
#define CAN_F13R2_FB4_Msk     (0x1UL << CAN_F13R2_FB4_Pos)	/*!< 0x00000010 */
#define CAN_F13R2_FB4         CAN_F13R2_FB4_Msk				/*!<Filter bit 4 */
#define CAN_F13R2_FB5_Pos     (5U)
#define CAN_F13R2_FB5_Msk     (0x1UL << CAN_F13R2_FB5_Pos)	/*!< 0x00000020 */
#define CAN_F13R2_FB5         CAN_F13R2_FB5_Msk				/*!<Filter bit 5 */
#define CAN_F13R2_FB6_Pos     (6U)
#define CAN_F13R2_FB6_Msk     (0x1UL << CAN_F13R2_FB6_Pos)	/*!< 0x00000040 */
#define CAN_F13R2_FB6         CAN_F13R2_FB6_Msk				/*!<Filter bit 6 */
#define CAN_F13R2_FB7_Pos     (7U)
#define CAN_F13R2_FB7_Msk     (0x1UL << CAN_F13R2_FB7_Pos)	/*!< 0x00000080 */
#define CAN_F13R2_FB7         CAN_F13R2_FB7_Msk				/*!<Filter bit 7 */
#define CAN_F13R2_FB8_Pos     (8U)
#define CAN_F13R2_FB8_Msk     (0x1UL << CAN_F13R2_FB8_Pos)	/*!< 0x00000100 */
#define CAN_F13R2_FB8         CAN_F13R2_FB8_Msk				/*!<Filter bit 8 */
#define CAN_F13R2_FB9_Pos     (9U)
#define CAN_F13R2_FB9_Msk     (0x1UL << CAN_F13R2_FB9_Pos)	/*!< 0x00000200 */
#define CAN_F13R2_FB9         CAN_F13R2_FB9_Msk				/*!<Filter bit 9 */
#define CAN_F13R2_FB10_Pos    (10U)
#define CAN_F13R2_FB10_Msk    (0x1UL << CAN_F13R2_FB10_Pos)	/*!< 0x00000400 */
#define CAN_F13R2_FB10        CAN_F13R2_FB10_Msk/*!<Filter bit 10 */
#define CAN_F13R2_FB11_Pos    (11U)
#define CAN_F13R2_FB11_Msk    (0x1UL << CAN_F13R2_FB11_Pos)	/*!< 0x00000800 */
#define CAN_F13R2_FB11        CAN_F13R2_FB11_Msk/*!<Filter bit 11 */
#define CAN_F13R2_FB12_Pos    (12U)
#define CAN_F13R2_FB12_Msk    (0x1UL << CAN_F13R2_FB12_Pos)	/*!< 0x00001000 */
#define CAN_F13R2_FB12        CAN_F13R2_FB12_Msk/*!<Filter bit 12 */
#define CAN_F13R2_FB13_Pos    (13U)
#define CAN_F13R2_FB13_Msk    (0x1UL << CAN_F13R2_FB13_Pos)	/*!< 0x00002000 */
#define CAN_F13R2_FB13        CAN_F13R2_FB13_Msk/*!<Filter bit 13 */
#define CAN_F13R2_FB14_Pos    (14U)
#define CAN_F13R2_FB14_Msk    (0x1UL << CAN_F13R2_FB14_Pos)	/*!< 0x00004000 */
#define CAN_F13R2_FB14        CAN_F13R2_FB14_Msk/*!<Filter bit 14 */
#define CAN_F13R2_FB15_Pos    (15U)
#define CAN_F13R2_FB15_Msk    (0x1UL << CAN_F13R2_FB15_Pos)	/*!< 0x00008000 */
#define CAN_F13R2_FB15        CAN_F13R2_FB15_Msk/*!<Filter bit 15 */
#define CAN_F13R2_FB16_Pos    (16U)
#define CAN_F13R2_FB16_Msk    (0x1UL << CAN_F13R2_FB16_Pos)	/*!< 0x00010000 */
#define CAN_F13R2_FB16        CAN_F13R2_FB16_Msk/*!<Filter bit 16 */
#define CAN_F13R2_FB17_Pos    (17U)
#define CAN_F13R2_FB17_Msk    (0x1UL << CAN_F13R2_FB17_Pos)	/*!< 0x00020000 */
#define CAN_F13R2_FB17        CAN_F13R2_FB17_Msk/*!<Filter bit 17 */
#define CAN_F13R2_FB18_Pos    (18U)
#define CAN_F13R2_FB18_Msk    (0x1UL << CAN_F13R2_FB18_Pos)	/*!< 0x00040000 */
#define CAN_F13R2_FB18        CAN_F13R2_FB18_Msk/*!<Filter bit 18 */
#define CAN_F13R2_FB19_Pos    (19U)
#define CAN_F13R2_FB19_Msk    (0x1UL << CAN_F13R2_FB19_Pos)	/*!< 0x00080000 */
#define CAN_F13R2_FB19        CAN_F13R2_FB19_Msk/*!<Filter bit 19 */
#define CAN_F13R2_FB20_Pos    (20U)
#define CAN_F13R2_FB20_Msk    (0x1UL << CAN_F13R2_FB20_Pos)	/*!< 0x00100000 */
#define CAN_F13R2_FB20        CAN_F13R2_FB20_Msk/*!<Filter bit 20 */
#define CAN_F13R2_FB21_Pos    (21U)
#define CAN_F13R2_FB21_Msk    (0x1UL << CAN_F13R2_FB21_Pos)	/*!< 0x00200000 */
#define CAN_F13R2_FB21        CAN_F13R2_FB21_Msk/*!<Filter bit 21 */
#define CAN_F13R2_FB22_Pos    (22U)
#define CAN_F13R2_FB22_Msk    (0x1UL << CAN_F13R2_FB22_Pos)	/*!< 0x00400000 */
#define CAN_F13R2_FB22        CAN_F13R2_FB22_Msk/*!<Filter bit 22 */
#define CAN_F13R2_FB23_Pos    (23U)
#define CAN_F13R2_FB23_Msk    (0x1UL << CAN_F13R2_FB23_Pos)	/*!< 0x00800000 */
#define CAN_F13R2_FB23        CAN_F13R2_FB23_Msk/*!<Filter bit 23 */
#define CAN_F13R2_FB24_Pos    (24U)
#define CAN_F13R2_FB24_Msk    (0x1UL << CAN_F13R2_FB24_Pos)	/*!< 0x01000000 */
#define CAN_F13R2_FB24        CAN_F13R2_FB24_Msk/*!<Filter bit 24 */
#define CAN_F13R2_FB25_Pos    (25U)
#define CAN_F13R2_FB25_Msk    (0x1UL << CAN_F13R2_FB25_Pos)	/*!< 0x02000000 */
#define CAN_F13R2_FB25        CAN_F13R2_FB25_Msk/*!<Filter bit 25 */
#define CAN_F13R2_FB26_Pos    (26U)
#define CAN_F13R2_FB26_Msk    (0x1UL << CAN_F13R2_FB26_Pos)	/*!< 0x04000000 */
#define CAN_F13R2_FB26        CAN_F13R2_FB26_Msk/*!<Filter bit 26 */
#define CAN_F13R2_FB27_Pos    (27U)
#define CAN_F13R2_FB27_Msk    (0x1UL << CAN_F13R2_FB27_Pos)	/*!< 0x08000000 */
#define CAN_F13R2_FB27        CAN_F13R2_FB27_Msk/*!<Filter bit 27 */
#define CAN_F13R2_FB28_Pos    (28U)
#define CAN_F13R2_FB28_Msk    (0x1UL << CAN_F13R2_FB28_Pos)	/*!< 0x10000000 */
#define CAN_F13R2_FB28        CAN_F13R2_FB28_Msk/*!<Filter bit 28 */
#define CAN_F13R2_FB29_Pos    (29U)
#define CAN_F13R2_FB29_Msk    (0x1UL << CAN_F13R2_FB29_Pos)	/*!< 0x20000000 */
#define CAN_F13R2_FB29        CAN_F13R2_FB29_Msk/*!<Filter bit 29 */
#define CAN_F13R2_FB30_Pos    (30U)
#define CAN_F13R2_FB30_Msk    (0x1UL << CAN_F13R2_FB30_Pos)	/*!< 0x40000000 */
#define CAN_F13R2_FB30        CAN_F13R2_FB30_Msk/*!<Filter bit 30 */
#define CAN_F13R2_FB31_Pos    (31U)
#define CAN_F13R2_FB31_Msk    (0x1UL << CAN_F13R2_FB31_Pos)	/*!< 0x80000000 */
#define CAN_F13R2_FB31        CAN_F13R2_FB31_Msk/*!<Filter bit 31 */


/******************************************************************************/
/*                                                                            */
/*                          CRC calculation unit                              */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for CRC_DR register  *********************/
#define CRC_DR_DR_Pos    (0U)
#define CRC_DR_DR_Msk    (0xFFFFFFFFUL << CRC_DR_DR_Pos)/*!< 0xFFFFFFFF */
#define CRC_DR_DR        CRC_DR_DR_Msk	/*!< Data register bits */

/*******************  Bit definition for CRC_IDR register  ********************/
#define CRC_IDR_IDR_Pos    (0U)
#define CRC_IDR_IDR_Msk    (0xFFUL << CRC_IDR_IDR_Pos)	/*!< 0x000000FF */
#define CRC_IDR_IDR        CRC_IDR_IDR_Msk				/*!< General-purpose 8-bit data register bits */

/********************  Bit definition for CRC_CR register  ********************/
#define CRC_CR_RESET_Pos       (0U)
#define CRC_CR_RESET_Msk       (0x1UL << CRC_CR_RESET_Pos)	/*!< 0x00000001 */
#define CRC_CR_RESET           CRC_CR_RESET_Msk				/*!< RESET the CRC computation unit bit */
#define CRC_CR_POLYSIZE_Pos    (3U)
#define CRC_CR_POLYSIZE_Msk    (0x3UL << CRC_CR_POLYSIZE_Pos)	/*!< 0x00000018 */
#define CRC_CR_POLYSIZE        CRC_CR_POLYSIZE_Msk				/*!< Polynomial size bits               */
#define CRC_CR_POLYSIZE_0      (0x1UL << CRC_CR_POLYSIZE_Pos)	/*!< 0x00000008 */
#define CRC_CR_POLYSIZE_1      (0x2UL << CRC_CR_POLYSIZE_Pos)	/*!< 0x00000010 */
#define CRC_CR_REV_IN_Pos      (5U)
#define CRC_CR_REV_IN_Msk      (0x3UL << CRC_CR_REV_IN_Pos)	/*!< 0x00000060 */
#define CRC_CR_REV_IN          CRC_CR_REV_IN_Msk/*!< REV_IN Reverse Input Data bits     */
#define CRC_CR_REV_IN_0        (0x1UL << CRC_CR_REV_IN_Pos)	/*!< 0x00000020 */
#define CRC_CR_REV_IN_1        (0x2UL << CRC_CR_REV_IN_Pos)	/*!< 0x00000040 */
#define CRC_CR_REV_OUT_Pos     (7U)
#define CRC_CR_REV_OUT_Msk     (0x1UL << CRC_CR_REV_OUT_Pos)/*!< 0x00000080 */
#define CRC_CR_REV_OUT         CRC_CR_REV_OUT_Msk	/*!< REV_OUT Reverse Output Data bits   */

/*******************  Bit definition for CRC_INIT register  *******************/
#define CRC_INIT_INIT_Pos    (0U)
#define CRC_INIT_INIT_Msk    (0xFFFFFFFFUL << CRC_INIT_INIT_Pos)/*!< 0xFFFFFFFF */
#define CRC_INIT_INIT        CRC_INIT_INIT_Msk	/*!< Initial CRC value bits         */

/*******************  Bit definition for CRC_POL register  ********************/
#define CRC_POL_POL_Pos    (0U)
#define CRC_POL_POL_Msk    (0xFFFFFFFFUL << CRC_POL_POL_Pos)/*!< 0xFFFFFFFF */
#define CRC_POL_POL        CRC_POL_POL_Msk	/*!< Coefficients of the polynomial */


/******************************************************************************/
/*                                                                            */
/*                      Digital to Analog Converter                           */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DAC_CR register  ********************/
#define DAC_CR_EN1_Pos          (0U)
#define DAC_CR_EN1_Msk          (0x1UL << DAC_CR_EN1_Pos)	/*!< 0x00000001 */
#define DAC_CR_EN1              DAC_CR_EN1_Msk				/*!<DAC channel1 enable                         */
#define DAC_CR_BOFF1_Pos        (1U)
#define DAC_CR_BOFF1_Msk        (0x1UL << DAC_CR_BOFF1_Pos)	/*!< 0x00000002 */
#define DAC_CR_BOFF1            DAC_CR_BOFF1_Msk/*!<DAC channel1 output buffer disable          */
#define DAC_CR_TEN1_Pos         (2U)
#define DAC_CR_TEN1_Msk         (0x1UL << DAC_CR_TEN1_Pos)	/*!< 0x00000004 */
#define DAC_CR_TEN1             DAC_CR_TEN1_Msk				/*!<DAC channel1 Trigger enable                 */
#define DAC_CR_TSEL1_Pos        (3U)
#define DAC_CR_TSEL1_Msk        (0x7UL << DAC_CR_TSEL1_Pos)	/*!< 0x00000038 */
#define DAC_CR_TSEL1            DAC_CR_TSEL1_Msk/*!<TSEL1[2:0] (DAC channel1 Trigger selection) */
#define DAC_CR_TSEL1_0          (0x1UL << DAC_CR_TSEL1_Pos)	/*!< 0x00000008 */
#define DAC_CR_TSEL1_1          (0x2UL << DAC_CR_TSEL1_Pos)	/*!< 0x00000010 */
#define DAC_CR_TSEL1_2          (0x4UL << DAC_CR_TSEL1_Pos)	/*!< 0x00000020 */
#define DAC_CR_WAVE1_Pos        (6U)
#define DAC_CR_WAVE1_Msk        (0x3UL << DAC_CR_WAVE1_Pos)	/*!< 0x000000C0 */
#define DAC_CR_WAVE1            DAC_CR_WAVE1_Msk/*!<WAVE1[1:0] (DAC channel1 noise/triangle wave generation enablEU) */
#define DAC_CR_WAVE1_0          (0x1UL << DAC_CR_WAVE1_Pos)	/*!< 0x00000040 */
#define DAC_CR_WAVE1_1          (0x2UL << DAC_CR_WAVE1_Pos)	/*!< 0x00000080 */
#define DAC_CR_MAMP1_Pos        (8U)
#define DAC_CR_MAMP1_Msk        (0xFUL << DAC_CR_MAMP1_Pos)	/*!< 0x00000F00 */
#define DAC_CR_MAMP1            DAC_CR_MAMP1_Msk/*!<MAMP1[3:0] (DAC channel1 Mask/Amplitude selector) */
#define DAC_CR_MAMP1_0          (0x1UL << DAC_CR_MAMP1_Pos)	/*!< 0x00000100 */
#define DAC_CR_MAMP1_1          (0x2UL << DAC_CR_MAMP1_Pos)	/*!< 0x00000200 */
#define DAC_CR_MAMP1_2          (0x4UL << DAC_CR_MAMP1_Pos)	/*!< 0x00000400 */
#define DAC_CR_MAMP1_3          (0x8UL << DAC_CR_MAMP1_Pos)	/*!< 0x00000800 */
#define DAC_CR_DMAEN1_Pos       (12U)
#define DAC_CR_DMAEN1_Msk       (0x1UL << DAC_CR_DMAEN1_Pos)/*!< 0x00001000 */
#define DAC_CR_DMAEN1           DAC_CR_DMAEN1_Msk	/*!<DAC channel1 DMA enable                     */
#define DAC_CR_DMAUDRIE1_Pos    (13U)
#define DAC_CR_DMAUDRIE1_Msk    (0x1UL << DAC_CR_DMAUDRIE1_Pos)	/*!< 0x00002000 */
#define DAC_CR_DMAUDRIE1        DAC_CR_DMAUDRIE1_Msk/*!<DAC channel1 DMA underrun interrupt enable  */
#define DAC_CR_EN2_Pos          (16U)
#define DAC_CR_EN2_Msk          (0x1UL << DAC_CR_EN2_Pos)	/*!< 0x00010000 */
#define DAC_CR_EN2              DAC_CR_EN2_Msk				/*!<DAC channel2 enable                         */
#define DAC_CR_BOFF2_Pos        (17U)
#define DAC_CR_BOFF2_Msk        (0x1UL << DAC_CR_BOFF2_Pos)	/*!< 0x00020000 */
#define DAC_CR_BOFF2            DAC_CR_BOFF2_Msk/*!<DAC channel2 output buffer disable          */
#define DAC_CR_TEN2_Pos         (18U)
#define DAC_CR_TEN2_Msk         (0x1UL << DAC_CR_TEN2_Pos)	/*!< 0x00040000 */
#define DAC_CR_TEN2             DAC_CR_TEN2_Msk				/*!<DAC channel2 Trigger enable                 */
#define DAC_CR_TSEL2_Pos        (19U)
#define DAC_CR_TSEL2_Msk        (0x7UL << DAC_CR_TSEL2_Pos)	/*!< 0x00380000 */
#define DAC_CR_TSEL2            DAC_CR_TSEL2_Msk/*!<TSEL2[2:0] (DAC channel2 Trigger selection) */
#define DAC_CR_TSEL2_0          (0x1UL << DAC_CR_TSEL2_Pos)	/*!< 0x00080000 */
#define DAC_CR_TSEL2_1          (0x2UL << DAC_CR_TSEL2_Pos)	/*!< 0x00100000 */
#define DAC_CR_TSEL2_2          (0x4UL << DAC_CR_TSEL2_Pos)	/*!< 0x00200000 */
#define DAC_CR_WAVE2_Pos        (22U)
#define DAC_CR_WAVE2_Msk        (0x3UL << DAC_CR_WAVE2_Pos)	/*!< 0x00C00000 */
#define DAC_CR_WAVE2            DAC_CR_WAVE2_Msk/*!<WAVE2[1:0] (DAC channel2 noise/triangle wave generation enable) */
#define DAC_CR_WAVE2_0          (0x1UL << DAC_CR_WAVE2_Pos)	/*!< 0x00400000 */
#define DAC_CR_WAVE2_1          (0x2UL << DAC_CR_WAVE2_Pos)	/*!< 0x00800000 */
#define DAC_CR_MAMP2_Pos        (24U)
#define DAC_CR_MAMP2_Msk        (0xFUL << DAC_CR_MAMP2_Pos)	/*!< 0x0F000000 */
#define DAC_CR_MAMP2            DAC_CR_MAMP2_Msk/*!<MAMP2[3:0] (DAC channel2 Mask/Amplitude selector) */
#define DAC_CR_MAMP2_0          (0x1UL << DAC_CR_MAMP2_Pos)	/*!< 0x01000000 */
#define DAC_CR_MAMP2_1          (0x2UL << DAC_CR_MAMP2_Pos)	/*!< 0x02000000 */
#define DAC_CR_MAMP2_2          (0x4UL << DAC_CR_MAMP2_Pos)	/*!< 0x04000000 */
#define DAC_CR_MAMP2_3          (0x8UL << DAC_CR_MAMP2_Pos)	/*!< 0x08000000 */
#define DAC_CR_DMAEN2_Pos       (28U)
#define DAC_CR_DMAEN2_Msk       (0x1UL << DAC_CR_DMAEN2_Pos)/*!< 0x10000000 */
#define DAC_CR_DMAEN2           DAC_CR_DMAEN2_Msk	/*!<DAC channel2 DMA enable                    */
#define DAC_CR_DMAUDRIE2_Pos    (29U)
#define DAC_CR_DMAUDRIE2_Msk    (0x1UL << DAC_CR_DMAUDRIE2_Pos)	/*!< 0x20000000 */
#define DAC_CR_DMAUDRIE2        DAC_CR_DMAUDRIE2_Msk/*!<DAC channel2 DMA underrun interrupt enable */

/*****************  Bit definition for DAC_SWTRIGR register  ******************/
#define DAC_SWTRIGR_SWTRIG1_Pos    (0U)
#define DAC_SWTRIGR_SWTRIG1_Msk    (0x1UL << DAC_SWTRIGR_SWTRIG1_Pos)	/*!< 0x00000001 */
#define DAC_SWTRIGR_SWTRIG1        DAC_SWTRIGR_SWTRIG1_Msk				/*!<DAC channel1 software trigger */
#define DAC_SWTRIGR_SWTRIG2_Pos    (1U)
#define DAC_SWTRIGR_SWTRIG2_Msk    (0x1UL << DAC_SWTRIGR_SWTRIG2_Pos)	/*!< 0x00000002 */
#define DAC_SWTRIGR_SWTRIG2        DAC_SWTRIGR_SWTRIG2_Msk				/*!<DAC channel2 software trigger */

/*****************  Bit definition for DAC_DHR12R1 register  ******************/
#define DAC_DHR12R1_DACC1DHR_Pos    (0U)
#define DAC_DHR12R1_DACC1DHR_Msk    (0xFFFUL << DAC_DHR12R1_DACC1DHR_Pos)	/*!< 0x00000FFF */
#define DAC_DHR12R1_DACC1DHR        DAC_DHR12R1_DACC1DHR_Msk				/*!<DAC channel1 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12L1 register  ******************/
#define DAC_DHR12L1_DACC1DHR_Pos    (4U)
#define DAC_DHR12L1_DACC1DHR_Msk    (0xFFFUL << DAC_DHR12L1_DACC1DHR_Pos)	/*!< 0x0000FFF0 */
#define DAC_DHR12L1_DACC1DHR        DAC_DHR12L1_DACC1DHR_Msk				/*!<DAC channel1 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8R1 register  ******************/
#define DAC_DHR8R1_DACC1DHR_Pos    (0U)
#define DAC_DHR8R1_DACC1DHR_Msk    (0xFFUL << DAC_DHR8R1_DACC1DHR_Pos)	/*!< 0x000000FF */
#define DAC_DHR8R1_DACC1DHR        DAC_DHR8R1_DACC1DHR_Msk				/*!<DAC channel1 8-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12R2 register  ******************/
#define DAC_DHR12R2_DACC2DHR_Pos    (0U)
#define DAC_DHR12R2_DACC2DHR_Msk    (0xFFFUL << DAC_DHR12R2_DACC2DHR_Pos)	/*!< 0x00000FFF */
#define DAC_DHR12R2_DACC2DHR        DAC_DHR12R2_DACC2DHR_Msk				/*!<DAC channel2 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12L2 register  ******************/
#define DAC_DHR12L2_DACC2DHR_Pos    (4U)
#define DAC_DHR12L2_DACC2DHR_Msk    (0xFFFUL << DAC_DHR12L2_DACC2DHR_Pos)	/*!< 0x0000FFF0 */
#define DAC_DHR12L2_DACC2DHR        DAC_DHR12L2_DACC2DHR_Msk				/*!<DAC channel2 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8R2 register  ******************/
#define DAC_DHR8R2_DACC2DHR_Pos    (0U)
#define DAC_DHR8R2_DACC2DHR_Msk    (0xFFUL << DAC_DHR8R2_DACC2DHR_Pos)	/*!< 0x000000FF */
#define DAC_DHR8R2_DACC2DHR        DAC_DHR8R2_DACC2DHR_Msk				/*!<DAC channel2 8-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12RD register  ******************/
#define DAC_DHR12RD_DACC1DHR_Pos    (0U)
#define DAC_DHR12RD_DACC1DHR_Msk    (0xFFFUL << DAC_DHR12RD_DACC1DHR_Pos)	/*!< 0x00000FFF */
#define DAC_DHR12RD_DACC1DHR        DAC_DHR12RD_DACC1DHR_Msk				/*!<DAC channel1 12-bit Right aligned data */
#define DAC_DHR12RD_DACC2DHR_Pos    (16U)
#define DAC_DHR12RD_DACC2DHR_Msk    (0xFFFUL << DAC_DHR12RD_DACC2DHR_Pos)	/*!< 0x0FFF0000 */
#define DAC_DHR12RD_DACC2DHR        DAC_DHR12RD_DACC2DHR_Msk				/*!<DAC channel2 12-bit Right aligned data */

/*****************  Bit definition for DAC_DHR12LD register  ******************/
#define DAC_DHR12LD_DACC1DHR_Pos    (4U)
#define DAC_DHR12LD_DACC1DHR_Msk    (0xFFFUL << DAC_DHR12LD_DACC1DHR_Pos)	/*!< 0x0000FFF0 */
#define DAC_DHR12LD_DACC1DHR        DAC_DHR12LD_DACC1DHR_Msk				/*!<DAC channel1 12-bit Left aligned data */
#define DAC_DHR12LD_DACC2DHR_Pos    (20U)
#define DAC_DHR12LD_DACC2DHR_Msk    (0xFFFUL << DAC_DHR12LD_DACC2DHR_Pos)	/*!< 0xFFF00000 */
#define DAC_DHR12LD_DACC2DHR        DAC_DHR12LD_DACC2DHR_Msk				/*!<DAC channel2 12-bit Left aligned data */

/******************  Bit definition for DAC_DHR8RD register  ******************/
#define DAC_DHR8RD_DACC1DHR_Pos    (0U)
#define DAC_DHR8RD_DACC1DHR_Msk    (0xFFUL << DAC_DHR8RD_DACC1DHR_Pos)	/*!< 0x000000FF */
#define DAC_DHR8RD_DACC1DHR        DAC_DHR8RD_DACC1DHR_Msk				/*!<DAC channel1 8-bit Right aligned data */
#define DAC_DHR8RD_DACC2DHR_Pos    (8U)
#define DAC_DHR8RD_DACC2DHR_Msk    (0xFFUL << DAC_DHR8RD_DACC2DHR_Pos)	/*!< 0x0000FF00 */
#define DAC_DHR8RD_DACC2DHR        DAC_DHR8RD_DACC2DHR_Msk				/*!<DAC channel2 8-bit Right aligned data */

/*******************  Bit definition for DAC_DOR1 register  *******************/
#define DAC_DOR1_DACC1DOR_Pos    (0U)
#define DAC_DOR1_DACC1DOR_Msk    (0xFFFUL << DAC_DOR1_DACC1DOR_Pos)	/*!< 0x00000FFF */
#define DAC_DOR1_DACC1DOR        DAC_DOR1_DACC1DOR_Msk				/*!<DAC channel1 data output */

/*******************  Bit definition for DAC_DOR2 register  *******************/
#define DAC_DOR2_DACC2DOR_Pos    (0U)
#define DAC_DOR2_DACC2DOR_Msk    (0xFFFUL << DAC_DOR2_DACC2DOR_Pos)	/*!< 0x00000FFF */
#define DAC_DOR2_DACC2DOR        DAC_DOR2_DACC2DOR_Msk				/*!<DAC channel2 data output */

/********************  Bit definition for DAC_SR register  ********************/
#define DAC_SR_DMAUDR1_Pos    (13U)
#define DAC_SR_DMAUDR1_Msk    (0x1UL << DAC_SR_DMAUDR1_Pos)	/*!< 0x00002000 */
#define DAC_SR_DMAUDR1        DAC_SR_DMAUDR1_Msk/*!<DAC channel1 DMA underrun flag */
#define DAC_SR_DMAUDR2_Pos    (29U)
#define DAC_SR_DMAUDR2_Msk    (0x1UL << DAC_SR_DMAUDR2_Pos)	/*!< 0x20000000 */
#define DAC_SR_DMAUDR2        DAC_SR_DMAUDR2_Msk/*!<DAC channel2 DMA underrun flag */


/******************************************************************************/
/*                                                                            */
/*                                 Debug MCU                                  */
/*                                                                            */
/******************************************************************************/


/******************************************************************************/
/*                                                                            */
/*                             DMA Controller                                 */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for DMA_SxCR register  *****************/
#define DMA_SxCR_CHSEL_Pos     (25U)
#define DMA_SxCR_CHSEL_Msk     (0xFUL << DMA_SxCR_CHSEL_Pos)/*!< 0x1E000000 */
#define DMA_SxCR_CHSEL         DMA_SxCR_CHSEL_Msk
#define DMA_SxCR_CHSEL_0       (0x1UL << DMA_SxCR_CHSEL_Pos)/*!< 0x02000000 */
#define DMA_SxCR_CHSEL_1       (0x2UL << DMA_SxCR_CHSEL_Pos)/*!< 0x04000000 */
#define DMA_SxCR_CHSEL_2       (0x4UL << DMA_SxCR_CHSEL_Pos)/*!< 0x08000000 */
#define DMA_SxCR_CHSEL_3       (0x8UL << DMA_SxCR_CHSEL_Pos)/*!< 0x10000000 */
#define DMA_SxCR_MBURST_Pos    (23U)
#define DMA_SxCR_MBURST_Msk    (0x3UL << DMA_SxCR_MBURST_Pos)	/*!< 0x01800000 */
#define DMA_SxCR_MBURST        DMA_SxCR_MBURST_Msk
#define DMA_SxCR_MBURST_0      (0x1UL << DMA_SxCR_MBURST_Pos)	/*!< 0x00800000 */
#define DMA_SxCR_MBURST_1      (0x2UL << DMA_SxCR_MBURST_Pos)	/*!< 0x01000000 */
#define DMA_SxCR_PBURST_Pos    (21U)
#define DMA_SxCR_PBURST_Msk    (0x3UL << DMA_SxCR_PBURST_Pos)	/*!< 0x00600000 */
#define DMA_SxCR_PBURST        DMA_SxCR_PBURST_Msk
#define DMA_SxCR_PBURST_0      (0x1UL << DMA_SxCR_PBURST_Pos)	/*!< 0x00200000 */
#define DMA_SxCR_PBURST_1      (0x2UL << DMA_SxCR_PBURST_Pos)	/*!< 0x00400000 */
#define DMA_SxCR_CT_Pos        (19U)
#define DMA_SxCR_CT_Msk        (0x1UL << DMA_SxCR_CT_Pos)	/*!< 0x00080000 */
#define DMA_SxCR_CT            DMA_SxCR_CT_Msk
#define DMA_SxCR_DBM_Pos       (18U)
#define DMA_SxCR_DBM_Msk       (0x1UL << DMA_SxCR_DBM_Pos)	/*!< 0x00040000 */
#define DMA_SxCR_DBM           DMA_SxCR_DBM_Msk
#define DMA_SxCR_PL_Pos        (16U)
#define DMA_SxCR_PL_Msk        (0x3UL << DMA_SxCR_PL_Pos)	/*!< 0x00030000 */
#define DMA_SxCR_PL            DMA_SxCR_PL_Msk
#define DMA_SxCR_PL_0          (0x1UL << DMA_SxCR_PL_Pos)	/*!< 0x00010000 */
#define DMA_SxCR_PL_1          (0x2UL << DMA_SxCR_PL_Pos)	/*!< 0x00020000 */
#define DMA_SxCR_PINCOS_Pos    (15U)
#define DMA_SxCR_PINCOS_Msk    (0x1UL << DMA_SxCR_PINCOS_Pos)	/*!< 0x00008000 */
#define DMA_SxCR_PINCOS        DMA_SxCR_PINCOS_Msk
#define DMA_SxCR_MSIZE_Pos     (13U)
#define DMA_SxCR_MSIZE_Msk     (0x3UL << DMA_SxCR_MSIZE_Pos)/*!< 0x00006000 */
#define DMA_SxCR_MSIZE         DMA_SxCR_MSIZE_Msk
#define DMA_SxCR_MSIZE_0       (0x1UL << DMA_SxCR_MSIZE_Pos)/*!< 0x00002000 */
#define DMA_SxCR_MSIZE_1       (0x2UL << DMA_SxCR_MSIZE_Pos)/*!< 0x00004000 */
#define DMA_SxCR_PSIZE_Pos     (11U)
#define DMA_SxCR_PSIZE_Msk     (0x3UL << DMA_SxCR_PSIZE_Pos)/*!< 0x00001800 */
#define DMA_SxCR_PSIZE         DMA_SxCR_PSIZE_Msk
#define DMA_SxCR_PSIZE_0       (0x1UL << DMA_SxCR_PSIZE_Pos)/*!< 0x00000800 */
#define DMA_SxCR_PSIZE_1       (0x2UL << DMA_SxCR_PSIZE_Pos)/*!< 0x00001000 */
#define DMA_SxCR_MINC_Pos      (10U)
#define DMA_SxCR_MINC_Msk      (0x1UL << DMA_SxCR_MINC_Pos)	/*!< 0x00000400 */
#define DMA_SxCR_MINC          DMA_SxCR_MINC_Msk
#define DMA_SxCR_PINC_Pos      (9U)
#define DMA_SxCR_PINC_Msk      (0x1UL << DMA_SxCR_PINC_Pos)	/*!< 0x00000200 */
#define DMA_SxCR_PINC          DMA_SxCR_PINC_Msk
#define DMA_SxCR_CIRC_Pos      (8U)
#define DMA_SxCR_CIRC_Msk      (0x1UL << DMA_SxCR_CIRC_Pos)	/*!< 0x00000100 */
#define DMA_SxCR_CIRC          DMA_SxCR_CIRC_Msk
#define DMA_SxCR_DIR_Pos       (6U)
#define DMA_SxCR_DIR_Msk       (0x3UL << DMA_SxCR_DIR_Pos)	/*!< 0x000000C0 */
#define DMA_SxCR_DIR           DMA_SxCR_DIR_Msk
#define DMA_SxCR_DIR_0         (0x1UL << DMA_SxCR_DIR_Pos)	/*!< 0x00000040 */
#define DMA_SxCR_DIR_1         (0x2UL << DMA_SxCR_DIR_Pos)	/*!< 0x00000080 */
#define DMA_SxCR_PFCTRL_Pos    (5U)
#define DMA_SxCR_PFCTRL_Msk    (0x1UL << DMA_SxCR_PFCTRL_Pos)	/*!< 0x00000020 */
#define DMA_SxCR_PFCTRL        DMA_SxCR_PFCTRL_Msk
#define DMA_SxCR_TCIE_Pos      (4U)
#define DMA_SxCR_TCIE_Msk      (0x1UL << DMA_SxCR_TCIE_Pos)	/*!< 0x00000010 */
#define DMA_SxCR_TCIE          DMA_SxCR_TCIE_Msk
#define DMA_SxCR_HTIE_Pos      (3U)
#define DMA_SxCR_HTIE_Msk      (0x1UL << DMA_SxCR_HTIE_Pos)	/*!< 0x00000008 */
#define DMA_SxCR_HTIE          DMA_SxCR_HTIE_Msk
#define DMA_SxCR_TEIE_Pos      (2U)
#define DMA_SxCR_TEIE_Msk      (0x1UL << DMA_SxCR_TEIE_Pos)	/*!< 0x00000004 */
#define DMA_SxCR_TEIE          DMA_SxCR_TEIE_Msk
#define DMA_SxCR_DMEIE_Pos     (1U)
#define DMA_SxCR_DMEIE_Msk     (0x1UL << DMA_SxCR_DMEIE_Pos)/*!< 0x00000002 */
#define DMA_SxCR_DMEIE         DMA_SxCR_DMEIE_Msk
#define DMA_SxCR_EN_Pos        (0U)
#define DMA_SxCR_EN_Msk        (0x1UL << DMA_SxCR_EN_Pos)	/*!< 0x00000001 */
#define DMA_SxCR_EN            DMA_SxCR_EN_Msk

/********************  Bits definition for DMA_SxCNDTR register  **************/
#define DMA_SxNDT_Pos    (0U)
#define DMA_SxNDT_Msk    (0xFFFFUL << DMA_SxNDT_Pos)/*!< 0x0000FFFF */
#define DMA_SxNDT        DMA_SxNDT_Msk
#define DMA_SxNDT_0      (0x0001UL << DMA_SxNDT_Pos)/*!< 0x00000001 */
#define DMA_SxNDT_1      (0x0002UL << DMA_SxNDT_Pos)/*!< 0x00000002 */
#define DMA_SxNDT_2      (0x0004UL << DMA_SxNDT_Pos)/*!< 0x00000004 */
#define DMA_SxNDT_3      (0x0008UL << DMA_SxNDT_Pos)/*!< 0x00000008 */
#define DMA_SxNDT_4      (0x0010UL << DMA_SxNDT_Pos)/*!< 0x00000010 */
#define DMA_SxNDT_5      (0x0020UL << DMA_SxNDT_Pos)/*!< 0x00000020 */
#define DMA_SxNDT_6      (0x0040UL << DMA_SxNDT_Pos)/*!< 0x00000040 */
#define DMA_SxNDT_7      (0x0080UL << DMA_SxNDT_Pos)/*!< 0x00000080 */
#define DMA_SxNDT_8      (0x0100UL << DMA_SxNDT_Pos)/*!< 0x00000100 */
#define DMA_SxNDT_9      (0x0200UL << DMA_SxNDT_Pos)/*!< 0x00000200 */
#define DMA_SxNDT_10     (0x0400UL << DMA_SxNDT_Pos)/*!< 0x00000400 */
#define DMA_SxNDT_11     (0x0800UL << DMA_SxNDT_Pos)/*!< 0x00000800 */
#define DMA_SxNDT_12     (0x1000UL << DMA_SxNDT_Pos)/*!< 0x00001000 */
#define DMA_SxNDT_13     (0x2000UL << DMA_SxNDT_Pos)/*!< 0x00002000 */
#define DMA_SxNDT_14     (0x4000UL << DMA_SxNDT_Pos)/*!< 0x00004000 */
#define DMA_SxNDT_15     (0x8000UL << DMA_SxNDT_Pos)/*!< 0x00008000 */

/********************  Bits definition for DMA_SxFCR register  ****************/
#define DMA_SxFCR_FEIE_Pos     (7U)
#define DMA_SxFCR_FEIE_Msk     (0x1UL << DMA_SxFCR_FEIE_Pos)/*!< 0x00000080 */
#define DMA_SxFCR_FEIE         DMA_SxFCR_FEIE_Msk
#define DMA_SxFCR_FS_Pos       (3U)
#define DMA_SxFCR_FS_Msk       (0x7UL << DMA_SxFCR_FS_Pos)	/*!< 0x00000038 */
#define DMA_SxFCR_FS           DMA_SxFCR_FS_Msk
#define DMA_SxFCR_FS_0         (0x1UL << DMA_SxFCR_FS_Pos)	/*!< 0x00000008 */
#define DMA_SxFCR_FS_1         (0x2UL << DMA_SxFCR_FS_Pos)	/*!< 0x00000010 */
#define DMA_SxFCR_FS_2         (0x4UL << DMA_SxFCR_FS_Pos)	/*!< 0x00000020 */
#define DMA_SxFCR_DMDIS_Pos    (2U)
#define DMA_SxFCR_DMDIS_Msk    (0x1UL << DMA_SxFCR_DMDIS_Pos)	/*!< 0x00000004 */
#define DMA_SxFCR_DMDIS        DMA_SxFCR_DMDIS_Msk
#define DMA_SxFCR_FTH_Pos      (0U)
#define DMA_SxFCR_FTH_Msk      (0x3UL << DMA_SxFCR_FTH_Pos)	/*!< 0x00000003 */
#define DMA_SxFCR_FTH          DMA_SxFCR_FTH_Msk
#define DMA_SxFCR_FTH_0        (0x1UL << DMA_SxFCR_FTH_Pos)	/*!< 0x00000001 */
#define DMA_SxFCR_FTH_1        (0x2UL << DMA_SxFCR_FTH_Pos)	/*!< 0x00000002 */

/********************  Bits definition for DMA_LISR register  *****************/
#define DMA_LISR_TCIF3_Pos     (27U)
#define DMA_LISR_TCIF3_Msk     (0x1UL << DMA_LISR_TCIF3_Pos)/*!< 0x08000000 */
#define DMA_LISR_TCIF3         DMA_LISR_TCIF3_Msk
#define DMA_LISR_HTIF3_Pos     (26U)
#define DMA_LISR_HTIF3_Msk     (0x1UL << DMA_LISR_HTIF3_Pos)/*!< 0x04000000 */
#define DMA_LISR_HTIF3         DMA_LISR_HTIF3_Msk
#define DMA_LISR_TEIF3_Pos     (25U)
#define DMA_LISR_TEIF3_Msk     (0x1UL << DMA_LISR_TEIF3_Pos)/*!< 0x02000000 */
#define DMA_LISR_TEIF3         DMA_LISR_TEIF3_Msk
#define DMA_LISR_DMEIF3_Pos    (24U)
#define DMA_LISR_DMEIF3_Msk    (0x1UL << DMA_LISR_DMEIF3_Pos)	/*!< 0x01000000 */
#define DMA_LISR_DMEIF3        DMA_LISR_DMEIF3_Msk
#define DMA_LISR_FEIF3_Pos     (22U)
#define DMA_LISR_FEIF3_Msk     (0x1UL << DMA_LISR_FEIF3_Pos)/*!< 0x00400000 */
#define DMA_LISR_FEIF3         DMA_LISR_FEIF3_Msk
#define DMA_LISR_TCIF2_Pos     (21U)
#define DMA_LISR_TCIF2_Msk     (0x1UL << DMA_LISR_TCIF2_Pos)/*!< 0x00200000 */
#define DMA_LISR_TCIF2         DMA_LISR_TCIF2_Msk
#define DMA_LISR_HTIF2_Pos     (20U)
#define DMA_LISR_HTIF2_Msk     (0x1UL << DMA_LISR_HTIF2_Pos)/*!< 0x00100000 */
#define DMA_LISR_HTIF2         DMA_LISR_HTIF2_Msk
#define DMA_LISR_TEIF2_Pos     (19U)
#define DMA_LISR_TEIF2_Msk     (0x1UL << DMA_LISR_TEIF2_Pos)/*!< 0x00080000 */
#define DMA_LISR_TEIF2         DMA_LISR_TEIF2_Msk
#define DMA_LISR_DMEIF2_Pos    (18U)
#define DMA_LISR_DMEIF2_Msk    (0x1UL << DMA_LISR_DMEIF2_Pos)	/*!< 0x00040000 */
#define DMA_LISR_DMEIF2        DMA_LISR_DMEIF2_Msk
#define DMA_LISR_FEIF2_Pos     (16U)
#define DMA_LISR_FEIF2_Msk     (0x1UL << DMA_LISR_FEIF2_Pos)/*!< 0x00010000 */
#define DMA_LISR_FEIF2         DMA_LISR_FEIF2_Msk
#define DMA_LISR_TCIF1_Pos     (11U)
#define DMA_LISR_TCIF1_Msk     (0x1UL << DMA_LISR_TCIF1_Pos)/*!< 0x00000800 */
#define DMA_LISR_TCIF1         DMA_LISR_TCIF1_Msk
#define DMA_LISR_HTIF1_Pos     (10U)
#define DMA_LISR_HTIF1_Msk     (0x1UL << DMA_LISR_HTIF1_Pos)/*!< 0x00000400 */
#define DMA_LISR_HTIF1         DMA_LISR_HTIF1_Msk
#define DMA_LISR_TEIF1_Pos     (9U)
#define DMA_LISR_TEIF1_Msk     (0x1UL << DMA_LISR_TEIF1_Pos)/*!< 0x00000200 */
#define DMA_LISR_TEIF1         DMA_LISR_TEIF1_Msk
#define DMA_LISR_DMEIF1_Pos    (8U)
#define DMA_LISR_DMEIF1_Msk    (0x1UL << DMA_LISR_DMEIF1_Pos)	/*!< 0x00000100 */
#define DMA_LISR_DMEIF1        DMA_LISR_DMEIF1_Msk
#define DMA_LISR_FEIF1_Pos     (6U)
#define DMA_LISR_FEIF1_Msk     (0x1UL << DMA_LISR_FEIF1_Pos)/*!< 0x00000040 */
#define DMA_LISR_FEIF1         DMA_LISR_FEIF1_Msk
#define DMA_LISR_TCIF0_Pos     (5U)
#define DMA_LISR_TCIF0_Msk     (0x1UL << DMA_LISR_TCIF0_Pos)/*!< 0x00000020 */
#define DMA_LISR_TCIF0         DMA_LISR_TCIF0_Msk
#define DMA_LISR_HTIF0_Pos     (4U)
#define DMA_LISR_HTIF0_Msk     (0x1UL << DMA_LISR_HTIF0_Pos)/*!< 0x00000010 */
#define DMA_LISR_HTIF0         DMA_LISR_HTIF0_Msk
#define DMA_LISR_TEIF0_Pos     (3U)
#define DMA_LISR_TEIF0_Msk     (0x1UL << DMA_LISR_TEIF0_Pos)/*!< 0x00000008 */
#define DMA_LISR_TEIF0         DMA_LISR_TEIF0_Msk
#define DMA_LISR_DMEIF0_Pos    (2U)
#define DMA_LISR_DMEIF0_Msk    (0x1UL << DMA_LISR_DMEIF0_Pos)	/*!< 0x00000004 */
#define DMA_LISR_DMEIF0        DMA_LISR_DMEIF0_Msk
#define DMA_LISR_FEIF0_Pos     (0U)
#define DMA_LISR_FEIF0_Msk     (0x1UL << DMA_LISR_FEIF0_Pos)/*!< 0x00000001 */
#define DMA_LISR_FEIF0         DMA_LISR_FEIF0_Msk

/********************  Bits definition for DMA_HISR register  *****************/
#define DMA_HISR_TCIF7_Pos     (27U)
#define DMA_HISR_TCIF7_Msk     (0x1UL << DMA_HISR_TCIF7_Pos)/*!< 0x08000000 */
#define DMA_HISR_TCIF7         DMA_HISR_TCIF7_Msk
#define DMA_HISR_HTIF7_Pos     (26U)
#define DMA_HISR_HTIF7_Msk     (0x1UL << DMA_HISR_HTIF7_Pos)/*!< 0x04000000 */
#define DMA_HISR_HTIF7         DMA_HISR_HTIF7_Msk
#define DMA_HISR_TEIF7_Pos     (25U)
#define DMA_HISR_TEIF7_Msk     (0x1UL << DMA_HISR_TEIF7_Pos)/*!< 0x02000000 */
#define DMA_HISR_TEIF7         DMA_HISR_TEIF7_Msk
#define DMA_HISR_DMEIF7_Pos    (24U)
#define DMA_HISR_DMEIF7_Msk    (0x1UL << DMA_HISR_DMEIF7_Pos)	/*!< 0x01000000 */
#define DMA_HISR_DMEIF7        DMA_HISR_DMEIF7_Msk
#define DMA_HISR_FEIF7_Pos     (22U)
#define DMA_HISR_FEIF7_Msk     (0x1UL << DMA_HISR_FEIF7_Pos)/*!< 0x00400000 */
#define DMA_HISR_FEIF7         DMA_HISR_FEIF7_Msk
#define DMA_HISR_TCIF6_Pos     (21U)
#define DMA_HISR_TCIF6_Msk     (0x1UL << DMA_HISR_TCIF6_Pos)/*!< 0x00200000 */
#define DMA_HISR_TCIF6         DMA_HISR_TCIF6_Msk
#define DMA_HISR_HTIF6_Pos     (20U)
#define DMA_HISR_HTIF6_Msk     (0x1UL << DMA_HISR_HTIF6_Pos)/*!< 0x00100000 */
#define DMA_HISR_HTIF6         DMA_HISR_HTIF6_Msk
#define DMA_HISR_TEIF6_Pos     (19U)
#define DMA_HISR_TEIF6_Msk     (0x1UL << DMA_HISR_TEIF6_Pos)/*!< 0x00080000 */
#define DMA_HISR_TEIF6         DMA_HISR_TEIF6_Msk
#define DMA_HISR_DMEIF6_Pos    (18U)
#define DMA_HISR_DMEIF6_Msk    (0x1UL << DMA_HISR_DMEIF6_Pos)	/*!< 0x00040000 */
#define DMA_HISR_DMEIF6        DMA_HISR_DMEIF6_Msk
#define DMA_HISR_FEIF6_Pos     (16U)
#define DMA_HISR_FEIF6_Msk     (0x1UL << DMA_HISR_FEIF6_Pos)/*!< 0x00010000 */
#define DMA_HISR_FEIF6         DMA_HISR_FEIF6_Msk
#define DMA_HISR_TCIF5_Pos     (11U)
#define DMA_HISR_TCIF5_Msk     (0x1UL << DMA_HISR_TCIF5_Pos)/*!< 0x00000800 */
#define DMA_HISR_TCIF5         DMA_HISR_TCIF5_Msk
#define DMA_HISR_HTIF5_Pos     (10U)
#define DMA_HISR_HTIF5_Msk     (0x1UL << DMA_HISR_HTIF5_Pos)/*!< 0x00000400 */
#define DMA_HISR_HTIF5         DMA_HISR_HTIF5_Msk
#define DMA_HISR_TEIF5_Pos     (9U)
#define DMA_HISR_TEIF5_Msk     (0x1UL << DMA_HISR_TEIF5_Pos)/*!< 0x00000200 */
#define DMA_HISR_TEIF5         DMA_HISR_TEIF5_Msk
#define DMA_HISR_DMEIF5_Pos    (8U)
#define DMA_HISR_DMEIF5_Msk    (0x1UL << DMA_HISR_DMEIF5_Pos)	/*!< 0x00000100 */
#define DMA_HISR_DMEIF5        DMA_HISR_DMEIF5_Msk
#define DMA_HISR_FEIF5_Pos     (6U)
#define DMA_HISR_FEIF5_Msk     (0x1UL << DMA_HISR_FEIF5_Pos)/*!< 0x00000040 */
#define DMA_HISR_FEIF5         DMA_HISR_FEIF5_Msk
#define DMA_HISR_TCIF4_Pos     (5U)
#define DMA_HISR_TCIF4_Msk     (0x1UL << DMA_HISR_TCIF4_Pos)/*!< 0x00000020 */
#define DMA_HISR_TCIF4         DMA_HISR_TCIF4_Msk
#define DMA_HISR_HTIF4_Pos     (4U)
#define DMA_HISR_HTIF4_Msk     (0x1UL << DMA_HISR_HTIF4_Pos)/*!< 0x00000010 */
#define DMA_HISR_HTIF4         DMA_HISR_HTIF4_Msk
#define DMA_HISR_TEIF4_Pos     (3U)
#define DMA_HISR_TEIF4_Msk     (0x1UL << DMA_HISR_TEIF4_Pos)/*!< 0x00000008 */
#define DMA_HISR_TEIF4         DMA_HISR_TEIF4_Msk
#define DMA_HISR_DMEIF4_Pos    (2U)
#define DMA_HISR_DMEIF4_Msk    (0x1UL << DMA_HISR_DMEIF4_Pos)	/*!< 0x00000004 */
#define DMA_HISR_DMEIF4        DMA_HISR_DMEIF4_Msk
#define DMA_HISR_FEIF4_Pos     (0U)
#define DMA_HISR_FEIF4_Msk     (0x1UL << DMA_HISR_FEIF4_Pos)/*!< 0x00000001 */
#define DMA_HISR_FEIF4         DMA_HISR_FEIF4_Msk

/********************  Bits definition for DMA_LIFCR register  ****************/
#define DMA_LIFCR_CTCIF3_Pos     (27U)
#define DMA_LIFCR_CTCIF3_Msk     (0x1UL << DMA_LIFCR_CTCIF3_Pos)/*!< 0x08000000 */
#define DMA_LIFCR_CTCIF3         DMA_LIFCR_CTCIF3_Msk
#define DMA_LIFCR_CHTIF3_Pos     (26U)
#define DMA_LIFCR_CHTIF3_Msk     (0x1UL << DMA_LIFCR_CHTIF3_Pos)/*!< 0x04000000 */
#define DMA_LIFCR_CHTIF3         DMA_LIFCR_CHTIF3_Msk
#define DMA_LIFCR_CTEIF3_Pos     (25U)
#define DMA_LIFCR_CTEIF3_Msk     (0x1UL << DMA_LIFCR_CTEIF3_Pos)/*!< 0x02000000 */
#define DMA_LIFCR_CTEIF3         DMA_LIFCR_CTEIF3_Msk
#define DMA_LIFCR_CDMEIF3_Pos    (24U)
#define DMA_LIFCR_CDMEIF3_Msk    (0x1UL << DMA_LIFCR_CDMEIF3_Pos)	/*!< 0x01000000 */
#define DMA_LIFCR_CDMEIF3        DMA_LIFCR_CDMEIF3_Msk
#define DMA_LIFCR_CFEIF3_Pos     (22U)
#define DMA_LIFCR_CFEIF3_Msk     (0x1UL << DMA_LIFCR_CFEIF3_Pos)/*!< 0x00400000 */
#define DMA_LIFCR_CFEIF3         DMA_LIFCR_CFEIF3_Msk
#define DMA_LIFCR_CTCIF2_Pos     (21U)
#define DMA_LIFCR_CTCIF2_Msk     (0x1UL << DMA_LIFCR_CTCIF2_Pos)/*!< 0x00200000 */
#define DMA_LIFCR_CTCIF2         DMA_LIFCR_CTCIF2_Msk
#define DMA_LIFCR_CHTIF2_Pos     (20U)
#define DMA_LIFCR_CHTIF2_Msk     (0x1UL << DMA_LIFCR_CHTIF2_Pos)/*!< 0x00100000 */
#define DMA_LIFCR_CHTIF2         DMA_LIFCR_CHTIF2_Msk
#define DMA_LIFCR_CTEIF2_Pos     (19U)
#define DMA_LIFCR_CTEIF2_Msk     (0x1UL << DMA_LIFCR_CTEIF2_Pos)/*!< 0x00080000 */
#define DMA_LIFCR_CTEIF2         DMA_LIFCR_CTEIF2_Msk
#define DMA_LIFCR_CDMEIF2_Pos    (18U)
#define DMA_LIFCR_CDMEIF2_Msk    (0x1UL << DMA_LIFCR_CDMEIF2_Pos)	/*!< 0x00040000 */
#define DMA_LIFCR_CDMEIF2        DMA_LIFCR_CDMEIF2_Msk
#define DMA_LIFCR_CFEIF2_Pos     (16U)
#define DMA_LIFCR_CFEIF2_Msk     (0x1UL << DMA_LIFCR_CFEIF2_Pos)/*!< 0x00010000 */
#define DMA_LIFCR_CFEIF2         DMA_LIFCR_CFEIF2_Msk
#define DMA_LIFCR_CTCIF1_Pos     (11U)
#define DMA_LIFCR_CTCIF1_Msk     (0x1UL << DMA_LIFCR_CTCIF1_Pos)/*!< 0x00000800 */
#define DMA_LIFCR_CTCIF1         DMA_LIFCR_CTCIF1_Msk
#define DMA_LIFCR_CHTIF1_Pos     (10U)
#define DMA_LIFCR_CHTIF1_Msk     (0x1UL << DMA_LIFCR_CHTIF1_Pos)/*!< 0x00000400 */
#define DMA_LIFCR_CHTIF1         DMA_LIFCR_CHTIF1_Msk
#define DMA_LIFCR_CTEIF1_Pos     (9U)
#define DMA_LIFCR_CTEIF1_Msk     (0x1UL << DMA_LIFCR_CTEIF1_Pos)/*!< 0x00000200 */
#define DMA_LIFCR_CTEIF1         DMA_LIFCR_CTEIF1_Msk
#define DMA_LIFCR_CDMEIF1_Pos    (8U)
#define DMA_LIFCR_CDMEIF1_Msk    (0x1UL << DMA_LIFCR_CDMEIF1_Pos)	/*!< 0x00000100 */
#define DMA_LIFCR_CDMEIF1        DMA_LIFCR_CDMEIF1_Msk
#define DMA_LIFCR_CFEIF1_Pos     (6U)
#define DMA_LIFCR_CFEIF1_Msk     (0x1UL << DMA_LIFCR_CFEIF1_Pos)/*!< 0x00000040 */
#define DMA_LIFCR_CFEIF1         DMA_LIFCR_CFEIF1_Msk
#define DMA_LIFCR_CTCIF0_Pos     (5U)
#define DMA_LIFCR_CTCIF0_Msk     (0x1UL << DMA_LIFCR_CTCIF0_Pos)/*!< 0x00000020 */
#define DMA_LIFCR_CTCIF0         DMA_LIFCR_CTCIF0_Msk
#define DMA_LIFCR_CHTIF0_Pos     (4U)
#define DMA_LIFCR_CHTIF0_Msk     (0x1UL << DMA_LIFCR_CHTIF0_Pos)/*!< 0x00000010 */
#define DMA_LIFCR_CHTIF0         DMA_LIFCR_CHTIF0_Msk
#define DMA_LIFCR_CTEIF0_Pos     (3U)
#define DMA_LIFCR_CTEIF0_Msk     (0x1UL << DMA_LIFCR_CTEIF0_Pos)/*!< 0x00000008 */
#define DMA_LIFCR_CTEIF0         DMA_LIFCR_CTEIF0_Msk
#define DMA_LIFCR_CDMEIF0_Pos    (2U)
#define DMA_LIFCR_CDMEIF0_Msk    (0x1UL << DMA_LIFCR_CDMEIF0_Pos)	/*!< 0x00000004 */
#define DMA_LIFCR_CDMEIF0        DMA_LIFCR_CDMEIF0_Msk
#define DMA_LIFCR_CFEIF0_Pos     (0U)
#define DMA_LIFCR_CFEIF0_Msk     (0x1UL << DMA_LIFCR_CFEIF0_Pos)/*!< 0x00000001 */
#define DMA_LIFCR_CFEIF0         DMA_LIFCR_CFEIF0_Msk

/********************  Bits definition for DMA_HIFCR  register  ****************/
#define DMA_HIFCR_CTCIF7_Pos     (27U)
#define DMA_HIFCR_CTCIF7_Msk     (0x1UL << DMA_HIFCR_CTCIF7_Pos)/*!< 0x08000000 */
#define DMA_HIFCR_CTCIF7         DMA_HIFCR_CTCIF7_Msk
#define DMA_HIFCR_CHTIF7_Pos     (26U)
#define DMA_HIFCR_CHTIF7_Msk     (0x1UL << DMA_HIFCR_CHTIF7_Pos)/*!< 0x04000000 */
#define DMA_HIFCR_CHTIF7         DMA_HIFCR_CHTIF7_Msk
#define DMA_HIFCR_CTEIF7_Pos     (25U)
#define DMA_HIFCR_CTEIF7_Msk     (0x1UL << DMA_HIFCR_CTEIF7_Pos)/*!< 0x02000000 */
#define DMA_HIFCR_CTEIF7         DMA_HIFCR_CTEIF7_Msk
#define DMA_HIFCR_CDMEIF7_Pos    (24U)
#define DMA_HIFCR_CDMEIF7_Msk    (0x1UL << DMA_HIFCR_CDMEIF7_Pos)	/*!< 0x01000000 */
#define DMA_HIFCR_CDMEIF7        DMA_HIFCR_CDMEIF7_Msk
#define DMA_HIFCR_CFEIF7_Pos     (22U)
#define DMA_HIFCR_CFEIF7_Msk     (0x1UL << DMA_HIFCR_CFEIF7_Pos)/*!< 0x00400000 */
#define DMA_HIFCR_CFEIF7         DMA_HIFCR_CFEIF7_Msk
#define DMA_HIFCR_CTCIF6_Pos     (21U)
#define DMA_HIFCR_CTCIF6_Msk     (0x1UL << DMA_HIFCR_CTCIF6_Pos)/*!< 0x00200000 */
#define DMA_HIFCR_CTCIF6         DMA_HIFCR_CTCIF6_Msk
#define DMA_HIFCR_CHTIF6_Pos     (20U)
#define DMA_HIFCR_CHTIF6_Msk     (0x1UL << DMA_HIFCR_CHTIF6_Pos)/*!< 0x00100000 */
#define DMA_HIFCR_CHTIF6         DMA_HIFCR_CHTIF6_Msk
#define DMA_HIFCR_CTEIF6_Pos     (19U)
#define DMA_HIFCR_CTEIF6_Msk     (0x1UL << DMA_HIFCR_CTEIF6_Pos)/*!< 0x00080000 */
#define DMA_HIFCR_CTEIF6         DMA_HIFCR_CTEIF6_Msk
#define DMA_HIFCR_CDMEIF6_Pos    (18U)
#define DMA_HIFCR_CDMEIF6_Msk    (0x1UL << DMA_HIFCR_CDMEIF6_Pos)	/*!< 0x00040000 */
#define DMA_HIFCR_CDMEIF6        DMA_HIFCR_CDMEIF6_Msk
#define DMA_HIFCR_CFEIF6_Pos     (16U)
#define DMA_HIFCR_CFEIF6_Msk     (0x1UL << DMA_HIFCR_CFEIF6_Pos)/*!< 0x00010000 */
#define DMA_HIFCR_CFEIF6         DMA_HIFCR_CFEIF6_Msk
#define DMA_HIFCR_CTCIF5_Pos     (11U)
#define DMA_HIFCR_CTCIF5_Msk     (0x1UL << DMA_HIFCR_CTCIF5_Pos)/*!< 0x00000800 */
#define DMA_HIFCR_CTCIF5         DMA_HIFCR_CTCIF5_Msk
#define DMA_HIFCR_CHTIF5_Pos     (10U)
#define DMA_HIFCR_CHTIF5_Msk     (0x1UL << DMA_HIFCR_CHTIF5_Pos)/*!< 0x00000400 */
#define DMA_HIFCR_CHTIF5         DMA_HIFCR_CHTIF5_Msk
#define DMA_HIFCR_CTEIF5_Pos     (9U)
#define DMA_HIFCR_CTEIF5_Msk     (0x1UL << DMA_HIFCR_CTEIF5_Pos)/*!< 0x00000200 */
#define DMA_HIFCR_CTEIF5         DMA_HIFCR_CTEIF5_Msk
#define DMA_HIFCR_CDMEIF5_Pos    (8U)
#define DMA_HIFCR_CDMEIF5_Msk    (0x1UL << DMA_HIFCR_CDMEIF5_Pos)	/*!< 0x00000100 */
#define DMA_HIFCR_CDMEIF5        DMA_HIFCR_CDMEIF5_Msk
#define DMA_HIFCR_CFEIF5_Pos     (6U)
#define DMA_HIFCR_CFEIF5_Msk     (0x1UL << DMA_HIFCR_CFEIF5_Pos)/*!< 0x00000040 */
#define DMA_HIFCR_CFEIF5         DMA_HIFCR_CFEIF5_Msk
#define DMA_HIFCR_CTCIF4_Pos     (5U)
#define DMA_HIFCR_CTCIF4_Msk     (0x1UL << DMA_HIFCR_CTCIF4_Pos)/*!< 0x00000020 */
#define DMA_HIFCR_CTCIF4         DMA_HIFCR_CTCIF4_Msk
#define DMA_HIFCR_CHTIF4_Pos     (4U)
#define DMA_HIFCR_CHTIF4_Msk     (0x1UL << DMA_HIFCR_CHTIF4_Pos)/*!< 0x00000010 */
#define DMA_HIFCR_CHTIF4         DMA_HIFCR_CHTIF4_Msk
#define DMA_HIFCR_CTEIF4_Pos     (3U)
#define DMA_HIFCR_CTEIF4_Msk     (0x1UL << DMA_HIFCR_CTEIF4_Pos)/*!< 0x00000008 */
#define DMA_HIFCR_CTEIF4         DMA_HIFCR_CTEIF4_Msk
#define DMA_HIFCR_CDMEIF4_Pos    (2U)
#define DMA_HIFCR_CDMEIF4_Msk    (0x1UL << DMA_HIFCR_CDMEIF4_Pos)	/*!< 0x00000004 */
#define DMA_HIFCR_CDMEIF4        DMA_HIFCR_CDMEIF4_Msk
#define DMA_HIFCR_CFEIF4_Pos     (0U)
#define DMA_HIFCR_CFEIF4_Msk     (0x1UL << DMA_HIFCR_CFEIF4_Pos)/*!< 0x00000001 */
#define DMA_HIFCR_CFEIF4         DMA_HIFCR_CFEIF4_Msk

/******************  Bit definition for DMA_SxPAR register  ********************/
#define DMA_SxPAR_PA_Pos    (0U)
#define DMA_SxPAR_PA_Msk    (0xFFFFFFFFUL << DMA_SxPAR_PA_Pos)	/*!< 0xFFFFFFFF */
#define DMA_SxPAR_PA        DMA_SxPAR_PA_Msk					/*!< Peripheral Address */

/******************  Bit definition for DMA_SxM0AR register  ********************/
#define DMA_SxM0AR_M0A_Pos    (0U)
#define DMA_SxM0AR_M0A_Msk    (0xFFFFFFFFUL << DMA_SxM0AR_M0A_Pos)	/*!< 0xFFFFFFFF */
#define DMA_SxM0AR_M0A        DMA_SxM0AR_M0A_Msk					/*!< Memory Address */

/******************  Bit definition for DMA_SxM1AR register  ********************/
#define DMA_SxM1AR_M1A_Pos    (0U)
#define DMA_SxM1AR_M1A_Msk    (0xFFFFFFFFUL << DMA_SxM1AR_M1A_Pos)	/*!< 0xFFFFFFFF */
#define DMA_SxM1AR_M1A        DMA_SxM1AR_M1A_Msk					/*!< Memory Address */


/******************************************************************************/
/*                                                                            */
/*                    External Interrupt/Event Controller                     */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for EXTI_IMR register  *******************/
#define EXTI_IMR_MR0_Pos     (0U)
#define EXTI_IMR_MR0_Msk     (0x1UL << EXTI_IMR_MR0_Pos)/*!< 0x00000001 */
#define EXTI_IMR_MR0         EXTI_IMR_MR0_Msk	/*!< Interrupt Mask on line 0 */
#define EXTI_IMR_MR1_Pos     (1U)
#define EXTI_IMR_MR1_Msk     (0x1UL << EXTI_IMR_MR1_Pos)/*!< 0x00000002 */
#define EXTI_IMR_MR1         EXTI_IMR_MR1_Msk	/*!< Interrupt Mask on line 1 */
#define EXTI_IMR_MR2_Pos     (2U)
#define EXTI_IMR_MR2_Msk     (0x1UL << EXTI_IMR_MR2_Pos)/*!< 0x00000004 */
#define EXTI_IMR_MR2         EXTI_IMR_MR2_Msk	/*!< Interrupt Mask on line 2 */
#define EXTI_IMR_MR3_Pos     (3U)
#define EXTI_IMR_MR3_Msk     (0x1UL << EXTI_IMR_MR3_Pos)/*!< 0x00000008 */
#define EXTI_IMR_MR3         EXTI_IMR_MR3_Msk	/*!< Interrupt Mask on line 3 */
#define EXTI_IMR_MR4_Pos     (4U)
#define EXTI_IMR_MR4_Msk     (0x1UL << EXTI_IMR_MR4_Pos)/*!< 0x00000010 */
#define EXTI_IMR_MR4         EXTI_IMR_MR4_Msk	/*!< Interrupt Mask on line 4 */
#define EXTI_IMR_MR5_Pos     (5U)
#define EXTI_IMR_MR5_Msk     (0x1UL << EXTI_IMR_MR5_Pos)/*!< 0x00000020 */
#define EXTI_IMR_MR5         EXTI_IMR_MR5_Msk	/*!< Interrupt Mask on line 5 */
#define EXTI_IMR_MR6_Pos     (6U)
#define EXTI_IMR_MR6_Msk     (0x1UL << EXTI_IMR_MR6_Pos)/*!< 0x00000040 */
#define EXTI_IMR_MR6         EXTI_IMR_MR6_Msk	/*!< Interrupt Mask on line 6 */
#define EXTI_IMR_MR7_Pos     (7U)
#define EXTI_IMR_MR7_Msk     (0x1UL << EXTI_IMR_MR7_Pos)/*!< 0x00000080 */
#define EXTI_IMR_MR7         EXTI_IMR_MR7_Msk	/*!< Interrupt Mask on line 7 */
#define EXTI_IMR_MR8_Pos     (8U)
#define EXTI_IMR_MR8_Msk     (0x1UL << EXTI_IMR_MR8_Pos)/*!< 0x00000100 */
#define EXTI_IMR_MR8         EXTI_IMR_MR8_Msk	/*!< Interrupt Mask on line 8 */
#define EXTI_IMR_MR9_Pos     (9U)
#define EXTI_IMR_MR9_Msk     (0x1UL << EXTI_IMR_MR9_Pos)/*!< 0x00000200 */
#define EXTI_IMR_MR9         EXTI_IMR_MR9_Msk	/*!< Interrupt Mask on line 9 */
#define EXTI_IMR_MR10_Pos    (10U)
#define EXTI_IMR_MR10_Msk    (0x1UL << EXTI_IMR_MR10_Pos)	/*!< 0x00000400 */
#define EXTI_IMR_MR10        EXTI_IMR_MR10_Msk				/*!< Interrupt Mask on line 10 */
#define EXTI_IMR_MR11_Pos    (11U)
#define EXTI_IMR_MR11_Msk    (0x1UL << EXTI_IMR_MR11_Pos)	/*!< 0x00000800 */
#define EXTI_IMR_MR11        EXTI_IMR_MR11_Msk				/*!< Interrupt Mask on line 11 */
#define EXTI_IMR_MR12_Pos    (12U)
#define EXTI_IMR_MR12_Msk    (0x1UL << EXTI_IMR_MR12_Pos)	/*!< 0x00001000 */
#define EXTI_IMR_MR12        EXTI_IMR_MR12_Msk				/*!< Interrupt Mask on line 12 */
#define EXTI_IMR_MR13_Pos    (13U)
#define EXTI_IMR_MR13_Msk    (0x1UL << EXTI_IMR_MR13_Pos)	/*!< 0x00002000 */
#define EXTI_IMR_MR13        EXTI_IMR_MR13_Msk				/*!< Interrupt Mask on line 13 */
#define EXTI_IMR_MR14_Pos    (14U)
#define EXTI_IMR_MR14_Msk    (0x1UL << EXTI_IMR_MR14_Pos)	/*!< 0x00004000 */
#define EXTI_IMR_MR14        EXTI_IMR_MR14_Msk				/*!< Interrupt Mask on line 14 */
#define EXTI_IMR_MR15_Pos    (15U)
#define EXTI_IMR_MR15_Msk    (0x1UL << EXTI_IMR_MR15_Pos)	/*!< 0x00008000 */
#define EXTI_IMR_MR15        EXTI_IMR_MR15_Msk				/*!< Interrupt Mask on line 15 */
#define EXTI_IMR_MR16_Pos    (16U)
#define EXTI_IMR_MR16_Msk    (0x1UL << EXTI_IMR_MR16_Pos)	/*!< 0x00010000 */
#define EXTI_IMR_MR16        EXTI_IMR_MR16_Msk				/*!< Interrupt Mask on line 16 */
#define EXTI_IMR_MR17_Pos    (17U)
#define EXTI_IMR_MR17_Msk    (0x1UL << EXTI_IMR_MR17_Pos)	/*!< 0x00020000 */
#define EXTI_IMR_MR17        EXTI_IMR_MR17_Msk				/*!< Interrupt Mask on line 17 */
#define EXTI_IMR_MR18_Pos    (18U)
#define EXTI_IMR_MR18_Msk    (0x1UL << EXTI_IMR_MR18_Pos)	/*!< 0x00040000 */
#define EXTI_IMR_MR18        EXTI_IMR_MR18_Msk				/*!< Interrupt Mask on line 18 */
#define EXTI_IMR_MR19_Pos    (19U)
#define EXTI_IMR_MR19_Msk    (0x1UL << EXTI_IMR_MR19_Pos)	/*!< 0x00080000 */
#define EXTI_IMR_MR19        EXTI_IMR_MR19_Msk				/*!< Interrupt Mask on line 19 */
#define EXTI_IMR_MR20_Pos    (20U)
#define EXTI_IMR_MR20_Msk    (0x1UL << EXTI_IMR_MR20_Pos)	/*!< 0x00100000 */
#define EXTI_IMR_MR20        EXTI_IMR_MR20_Msk				/*!< Interrupt Mask on line 20 */
#define EXTI_IMR_MR21_Pos    (21U)
#define EXTI_IMR_MR21_Msk    (0x1UL << EXTI_IMR_MR21_Pos)	/*!< 0x00200000 */
#define EXTI_IMR_MR21        EXTI_IMR_MR21_Msk				/*!< Interrupt Mask on line 21 */
#define EXTI_IMR_MR22_Pos    (22U)
#define EXTI_IMR_MR22_Msk    (0x1UL << EXTI_IMR_MR22_Pos)	/*!< 0x00400000 */
#define EXTI_IMR_MR22        EXTI_IMR_MR22_Msk				/*!< Interrupt Mask on line 22 */
#define EXTI_IMR_MR23_Pos    (23U)
#define EXTI_IMR_MR23_Msk    (0x1UL << EXTI_IMR_MR23_Pos)	/*!< 0x00800000 */
#define EXTI_IMR_MR23        EXTI_IMR_MR23_Msk				/*!< Interrupt Mask on line 23 */

/* Reference Defines */
#define  EXTI_IMR_IM0      EXTI_IMR_MR0
#define  EXTI_IMR_IM1      EXTI_IMR_MR1
#define  EXTI_IMR_IM2      EXTI_IMR_MR2
#define  EXTI_IMR_IM3      EXTI_IMR_MR3
#define  EXTI_IMR_IM4      EXTI_IMR_MR4
#define  EXTI_IMR_IM5      EXTI_IMR_MR5
#define  EXTI_IMR_IM6      EXTI_IMR_MR6
#define  EXTI_IMR_IM7      EXTI_IMR_MR7
#define  EXTI_IMR_IM8      EXTI_IMR_MR8
#define  EXTI_IMR_IM9      EXTI_IMR_MR9
#define  EXTI_IMR_IM10     EXTI_IMR_MR10
#define  EXTI_IMR_IM11     EXTI_IMR_MR11
#define  EXTI_IMR_IM12     EXTI_IMR_MR12
#define  EXTI_IMR_IM13     EXTI_IMR_MR13
#define  EXTI_IMR_IM14     EXTI_IMR_MR14
#define  EXTI_IMR_IM15     EXTI_IMR_MR15
#define  EXTI_IMR_IM16     EXTI_IMR_MR16
#define  EXTI_IMR_IM17     EXTI_IMR_MR17
#define  EXTI_IMR_IM18     EXTI_IMR_MR18
#define  EXTI_IMR_IM19     EXTI_IMR_MR19
#define  EXTI_IMR_IM20     EXTI_IMR_MR20
#define  EXTI_IMR_IM21     EXTI_IMR_MR21
#define  EXTI_IMR_IM22     EXTI_IMR_MR22
#define  EXTI_IMR_IM23     EXTI_IMR_MR23

#define EXTI_IMR_IM_Pos    (0U)
#define EXTI_IMR_IM_Msk    (0xFFFFFFUL << EXTI_IMR_IM_Pos)	/*!< 0x00FFFFFF */
#define EXTI_IMR_IM        EXTI_IMR_IM_Msk					/*!< Interrupt Mask All */

/*******************  Bit definition for EXTI_EMR register  *******************/
#define EXTI_EMR_MR0_Pos     (0U)
#define EXTI_EMR_MR0_Msk     (0x1UL << EXTI_EMR_MR0_Pos)/*!< 0x00000001 */
#define EXTI_EMR_MR0         EXTI_EMR_MR0_Msk	/*!< Event Mask on line 0 */
#define EXTI_EMR_MR1_Pos     (1U)
#define EXTI_EMR_MR1_Msk     (0x1UL << EXTI_EMR_MR1_Pos)/*!< 0x00000002 */
#define EXTI_EMR_MR1         EXTI_EMR_MR1_Msk	/*!< Event Mask on line 1 */
#define EXTI_EMR_MR2_Pos     (2U)
#define EXTI_EMR_MR2_Msk     (0x1UL << EXTI_EMR_MR2_Pos)/*!< 0x00000004 */
#define EXTI_EMR_MR2         EXTI_EMR_MR2_Msk	/*!< Event Mask on line 2 */
#define EXTI_EMR_MR3_Pos     (3U)
#define EXTI_EMR_MR3_Msk     (0x1UL << EXTI_EMR_MR3_Pos)/*!< 0x00000008 */
#define EXTI_EMR_MR3         EXTI_EMR_MR3_Msk	/*!< Event Mask on line 3 */
#define EXTI_EMR_MR4_Pos     (4U)
#define EXTI_EMR_MR4_Msk     (0x1UL << EXTI_EMR_MR4_Pos)/*!< 0x00000010 */
#define EXTI_EMR_MR4         EXTI_EMR_MR4_Msk	/*!< Event Mask on line 4 */
#define EXTI_EMR_MR5_Pos     (5U)
#define EXTI_EMR_MR5_Msk     (0x1UL << EXTI_EMR_MR5_Pos)/*!< 0x00000020 */
#define EXTI_EMR_MR5         EXTI_EMR_MR5_Msk	/*!< Event Mask on line 5 */
#define EXTI_EMR_MR6_Pos     (6U)
#define EXTI_EMR_MR6_Msk     (0x1UL << EXTI_EMR_MR6_Pos)/*!< 0x00000040 */
#define EXTI_EMR_MR6         EXTI_EMR_MR6_Msk	/*!< Event Mask on line 6 */
#define EXTI_EMR_MR7_Pos     (7U)
#define EXTI_EMR_MR7_Msk     (0x1UL << EXTI_EMR_MR7_Pos)/*!< 0x00000080 */
#define EXTI_EMR_MR7         EXTI_EMR_MR7_Msk	/*!< Event Mask on line 7 */
#define EXTI_EMR_MR8_Pos     (8U)
#define EXTI_EMR_MR8_Msk     (0x1UL << EXTI_EMR_MR8_Pos)/*!< 0x00000100 */
#define EXTI_EMR_MR8         EXTI_EMR_MR8_Msk	/*!< Event Mask on line 8 */
#define EXTI_EMR_MR9_Pos     (9U)
#define EXTI_EMR_MR9_Msk     (0x1UL << EXTI_EMR_MR9_Pos)/*!< 0x00000200 */
#define EXTI_EMR_MR9         EXTI_EMR_MR9_Msk	/*!< Event Mask on line 9 */
#define EXTI_EMR_MR10_Pos    (10U)
#define EXTI_EMR_MR10_Msk    (0x1UL << EXTI_EMR_MR10_Pos)	/*!< 0x00000400 */
#define EXTI_EMR_MR10        EXTI_EMR_MR10_Msk				/*!< Event Mask on line 10 */
#define EXTI_EMR_MR11_Pos    (11U)
#define EXTI_EMR_MR11_Msk    (0x1UL << EXTI_EMR_MR11_Pos)	/*!< 0x00000800 */
#define EXTI_EMR_MR11        EXTI_EMR_MR11_Msk				/*!< Event Mask on line 11 */
#define EXTI_EMR_MR12_Pos    (12U)
#define EXTI_EMR_MR12_Msk    (0x1UL << EXTI_EMR_MR12_Pos)	/*!< 0x00001000 */
#define EXTI_EMR_MR12        EXTI_EMR_MR12_Msk				/*!< Event Mask on line 12 */
#define EXTI_EMR_MR13_Pos    (13U)
#define EXTI_EMR_MR13_Msk    (0x1UL << EXTI_EMR_MR13_Pos)	/*!< 0x00002000 */
#define EXTI_EMR_MR13        EXTI_EMR_MR13_Msk				/*!< Event Mask on line 13 */
#define EXTI_EMR_MR14_Pos    (14U)
#define EXTI_EMR_MR14_Msk    (0x1UL << EXTI_EMR_MR14_Pos)	/*!< 0x00004000 */
#define EXTI_EMR_MR14        EXTI_EMR_MR14_Msk				/*!< Event Mask on line 14 */
#define EXTI_EMR_MR15_Pos    (15U)
#define EXTI_EMR_MR15_Msk    (0x1UL << EXTI_EMR_MR15_Pos)	/*!< 0x00008000 */
#define EXTI_EMR_MR15        EXTI_EMR_MR15_Msk				/*!< Event Mask on line 15 */
#define EXTI_EMR_MR16_Pos    (16U)
#define EXTI_EMR_MR16_Msk    (0x1UL << EXTI_EMR_MR16_Pos)	/*!< 0x00010000 */
#define EXTI_EMR_MR16        EXTI_EMR_MR16_Msk				/*!< Event Mask on line 16 */
#define EXTI_EMR_MR17_Pos    (17U)
#define EXTI_EMR_MR17_Msk    (0x1UL << EXTI_EMR_MR17_Pos)	/*!< 0x00020000 */
#define EXTI_EMR_MR17        EXTI_EMR_MR17_Msk				/*!< Event Mask on line 17 */
#define EXTI_EMR_MR18_Pos    (18U)
#define EXTI_EMR_MR18_Msk    (0x1UL << EXTI_EMR_MR18_Pos)	/*!< 0x00040000 */
#define EXTI_EMR_MR18        EXTI_EMR_MR18_Msk				/*!< Event Mask on line 18 */
#define EXTI_EMR_MR19_Pos    (19U)
#define EXTI_EMR_MR19_Msk    (0x1UL << EXTI_EMR_MR19_Pos)	/*!< 0x00080000 */
#define EXTI_EMR_MR19        EXTI_EMR_MR19_Msk				/*!< Event Mask on line 19 */
#define EXTI_EMR_MR20_Pos    (20U)
#define EXTI_EMR_MR20_Msk    (0x1UL << EXTI_EMR_MR20_Pos)	/*!< 0x00100000 */
#define EXTI_EMR_MR20        EXTI_EMR_MR20_Msk				/*!< Event Mask on line 20 */
#define EXTI_EMR_MR21_Pos    (21U)
#define EXTI_EMR_MR21_Msk    (0x1UL << EXTI_EMR_MR21_Pos)	/*!< 0x00200000 */
#define EXTI_EMR_MR21        EXTI_EMR_MR21_Msk				/*!< Event Mask on line 21 */
#define EXTI_EMR_MR22_Pos    (22U)
#define EXTI_EMR_MR22_Msk    (0x1UL << EXTI_EMR_MR22_Pos)	/*!< 0x00400000 */
#define EXTI_EMR_MR22        EXTI_EMR_MR22_Msk				/*!< Event Mask on line 22 */
#define EXTI_EMR_MR23_Pos    (23U)
#define EXTI_EMR_MR23_Msk    (0x1UL << EXTI_EMR_MR23_Pos)	/*!< 0x00800000 */
#define EXTI_EMR_MR23        EXTI_EMR_MR23_Msk				/*!< Event Mask on line 23 */

/* Reference Defines */
#define  EXTI_EMR_EM0     EXTI_EMR_MR0
#define  EXTI_EMR_EM1     EXTI_EMR_MR1
#define  EXTI_EMR_EM2     EXTI_EMR_MR2
#define  EXTI_EMR_EM3     EXTI_EMR_MR3
#define  EXTI_EMR_EM4     EXTI_EMR_MR4
#define  EXTI_EMR_EM5     EXTI_EMR_MR5
#define  EXTI_EMR_EM6     EXTI_EMR_MR6
#define  EXTI_EMR_EM7     EXTI_EMR_MR7
#define  EXTI_EMR_EM8     EXTI_EMR_MR8
#define  EXTI_EMR_EM9     EXTI_EMR_MR9
#define  EXTI_EMR_EM10    EXTI_EMR_MR10
#define  EXTI_EMR_EM11    EXTI_EMR_MR11
#define  EXTI_EMR_EM12    EXTI_EMR_MR12
#define  EXTI_EMR_EM13    EXTI_EMR_MR13
#define  EXTI_EMR_EM14    EXTI_EMR_MR14
#define  EXTI_EMR_EM15    EXTI_EMR_MR15
#define  EXTI_EMR_EM16    EXTI_EMR_MR16
#define  EXTI_EMR_EM17    EXTI_EMR_MR17
#define  EXTI_EMR_EM18    EXTI_EMR_MR18
#define  EXTI_EMR_EM19    EXTI_EMR_MR19
#define  EXTI_EMR_EM20    EXTI_EMR_MR20
#define  EXTI_EMR_EM21    EXTI_EMR_MR21
#define  EXTI_EMR_EM22    EXTI_EMR_MR22
#define  EXTI_EMR_EM23    EXTI_EMR_MR23


/******************  Bit definition for EXTI_RTSR register  *******************/
#define EXTI_RTSR_TR0_Pos     (0U)
#define EXTI_RTSR_TR0_Msk     (0x1UL << EXTI_RTSR_TR0_Pos)	/*!< 0x00000001 */
#define EXTI_RTSR_TR0         EXTI_RTSR_TR0_Msk				/*!< Rising trigger event configuration bit of line 0 */
#define EXTI_RTSR_TR1_Pos     (1U)
#define EXTI_RTSR_TR1_Msk     (0x1UL << EXTI_RTSR_TR1_Pos)	/*!< 0x00000002 */
#define EXTI_RTSR_TR1         EXTI_RTSR_TR1_Msk				/*!< Rising trigger event configuration bit of line 1 */
#define EXTI_RTSR_TR2_Pos     (2U)
#define EXTI_RTSR_TR2_Msk     (0x1UL << EXTI_RTSR_TR2_Pos)	/*!< 0x00000004 */
#define EXTI_RTSR_TR2         EXTI_RTSR_TR2_Msk				/*!< Rising trigger event configuration bit of line 2 */
#define EXTI_RTSR_TR3_Pos     (3U)
#define EXTI_RTSR_TR3_Msk     (0x1UL << EXTI_RTSR_TR3_Pos)	/*!< 0x00000008 */
#define EXTI_RTSR_TR3         EXTI_RTSR_TR3_Msk				/*!< Rising trigger event configuration bit of line 3 */
#define EXTI_RTSR_TR4_Pos     (4U)
#define EXTI_RTSR_TR4_Msk     (0x1UL << EXTI_RTSR_TR4_Pos)	/*!< 0x00000010 */
#define EXTI_RTSR_TR4         EXTI_RTSR_TR4_Msk				/*!< Rising trigger event configuration bit of line 4 */
#define EXTI_RTSR_TR5_Pos     (5U)
#define EXTI_RTSR_TR5_Msk     (0x1UL << EXTI_RTSR_TR5_Pos)	/*!< 0x00000020 */
#define EXTI_RTSR_TR5         EXTI_RTSR_TR5_Msk				/*!< Rising trigger event configuration bit of line 5 */
#define EXTI_RTSR_TR6_Pos     (6U)
#define EXTI_RTSR_TR6_Msk     (0x1UL << EXTI_RTSR_TR6_Pos)	/*!< 0x00000040 */
#define EXTI_RTSR_TR6         EXTI_RTSR_TR6_Msk				/*!< Rising trigger event configuration bit of line 6 */
#define EXTI_RTSR_TR7_Pos     (7U)
#define EXTI_RTSR_TR7_Msk     (0x1UL << EXTI_RTSR_TR7_Pos)	/*!< 0x00000080 */
#define EXTI_RTSR_TR7         EXTI_RTSR_TR7_Msk				/*!< Rising trigger event configuration bit of line 7 */
#define EXTI_RTSR_TR8_Pos     (8U)
#define EXTI_RTSR_TR8_Msk     (0x1UL << EXTI_RTSR_TR8_Pos)	/*!< 0x00000100 */
#define EXTI_RTSR_TR8         EXTI_RTSR_TR8_Msk				/*!< Rising trigger event configuration bit of line 8 */
#define EXTI_RTSR_TR9_Pos     (9U)
#define EXTI_RTSR_TR9_Msk     (0x1UL << EXTI_RTSR_TR9_Pos)	/*!< 0x00000200 */
#define EXTI_RTSR_TR9         EXTI_RTSR_TR9_Msk				/*!< Rising trigger event configuration bit of line 9 */
#define EXTI_RTSR_TR10_Pos    (10U)
#define EXTI_RTSR_TR10_Msk    (0x1UL << EXTI_RTSR_TR10_Pos)	/*!< 0x00000400 */
#define EXTI_RTSR_TR10        EXTI_RTSR_TR10_Msk/*!< Rising trigger event configuration bit of line 10 */
#define EXTI_RTSR_TR11_Pos    (11U)
#define EXTI_RTSR_TR11_Msk    (0x1UL << EXTI_RTSR_TR11_Pos)	/*!< 0x00000800 */
#define EXTI_RTSR_TR11        EXTI_RTSR_TR11_Msk/*!< Rising trigger event configuration bit of line 11 */
#define EXTI_RTSR_TR12_Pos    (12U)
#define EXTI_RTSR_TR12_Msk    (0x1UL << EXTI_RTSR_TR12_Pos)	/*!< 0x00001000 */
#define EXTI_RTSR_TR12        EXTI_RTSR_TR12_Msk/*!< Rising trigger event configuration bit of line 12 */
#define EXTI_RTSR_TR13_Pos    (13U)
#define EXTI_RTSR_TR13_Msk    (0x1UL << EXTI_RTSR_TR13_Pos)	/*!< 0x00002000 */
#define EXTI_RTSR_TR13        EXTI_RTSR_TR13_Msk/*!< Rising trigger event configuration bit of line 13 */
#define EXTI_RTSR_TR14_Pos    (14U)
#define EXTI_RTSR_TR14_Msk    (0x1UL << EXTI_RTSR_TR14_Pos)	/*!< 0x00004000 */
#define EXTI_RTSR_TR14        EXTI_RTSR_TR14_Msk/*!< Rising trigger event configuration bit of line 14 */
#define EXTI_RTSR_TR15_Pos    (15U)
#define EXTI_RTSR_TR15_Msk    (0x1UL << EXTI_RTSR_TR15_Pos)	/*!< 0x00008000 */
#define EXTI_RTSR_TR15        EXTI_RTSR_TR15_Msk/*!< Rising trigger event configuration bit of line 15 */
#define EXTI_RTSR_TR16_Pos    (16U)
#define EXTI_RTSR_TR16_Msk    (0x1UL << EXTI_RTSR_TR16_Pos)	/*!< 0x00010000 */
#define EXTI_RTSR_TR16        EXTI_RTSR_TR16_Msk/*!< Rising trigger event configuration bit of line 16 */
#define EXTI_RTSR_TR17_Pos    (17U)
#define EXTI_RTSR_TR17_Msk    (0x1UL << EXTI_RTSR_TR17_Pos)	/*!< 0x00020000 */
#define EXTI_RTSR_TR17        EXTI_RTSR_TR17_Msk/*!< Rising trigger event configuration bit of line 17 */
#define EXTI_RTSR_TR18_Pos    (18U)
#define EXTI_RTSR_TR18_Msk    (0x1UL << EXTI_RTSR_TR18_Pos)	/*!< 0x00040000 */
#define EXTI_RTSR_TR18        EXTI_RTSR_TR18_Msk/*!< Rising trigger event configuration bit of line 18 */
#define EXTI_RTSR_TR19_Pos    (19U)
#define EXTI_RTSR_TR19_Msk    (0x1UL << EXTI_RTSR_TR19_Pos)	/*!< 0x00080000 */
#define EXTI_RTSR_TR19        EXTI_RTSR_TR19_Msk/*!< Rising trigger event configuration bit of line 19 */
#define EXTI_RTSR_TR20_Pos    (20U)
#define EXTI_RTSR_TR20_Msk    (0x1UL << EXTI_RTSR_TR20_Pos)	/*!< 0x00100000 */
#define EXTI_RTSR_TR20        EXTI_RTSR_TR20_Msk/*!< Rising trigger event configuration bit of line 20 */
#define EXTI_RTSR_TR21_Pos    (21U)
#define EXTI_RTSR_TR21_Msk    (0x1UL << EXTI_RTSR_TR21_Pos)	/*!< 0x00200000 */
#define EXTI_RTSR_TR21        EXTI_RTSR_TR21_Msk/*!< Rising trigger event configuration bit of line 21 */
#define EXTI_RTSR_TR22_Pos    (22U)
#define EXTI_RTSR_TR22_Msk    (0x1UL << EXTI_RTSR_TR22_Pos)	/*!< 0x00400000 */
#define EXTI_RTSR_TR22        EXTI_RTSR_TR22_Msk/*!< Rising trigger event configuration bit of line 22 */
#define EXTI_RTSR_TR23_Pos    (23U)
#define EXTI_RTSR_TR23_Msk    (0x1UL << EXTI_RTSR_TR23_Pos)	/*!< 0x00800000 */
#define EXTI_RTSR_TR23        EXTI_RTSR_TR23_Msk/*!< Rising trigger event configuration bit of line 23 */

/******************  Bit definition for EXTI_FTSR register  *******************/
#define EXTI_FTSR_TR0_Pos     (0U)
#define EXTI_FTSR_TR0_Msk     (0x1UL << EXTI_FTSR_TR0_Pos)	/*!< 0x00000001 */
#define EXTI_FTSR_TR0         EXTI_FTSR_TR0_Msk				/*!< Falling trigger event configuration bit of line 0 */
#define EXTI_FTSR_TR1_Pos     (1U)
#define EXTI_FTSR_TR1_Msk     (0x1UL << EXTI_FTSR_TR1_Pos)	/*!< 0x00000002 */
#define EXTI_FTSR_TR1         EXTI_FTSR_TR1_Msk				/*!< Falling trigger event configuration bit of line 1 */
#define EXTI_FTSR_TR2_Pos     (2U)
#define EXTI_FTSR_TR2_Msk     (0x1UL << EXTI_FTSR_TR2_Pos)	/*!< 0x00000004 */
#define EXTI_FTSR_TR2         EXTI_FTSR_TR2_Msk				/*!< Falling trigger event configuration bit of line 2 */
#define EXTI_FTSR_TR3_Pos     (3U)
#define EXTI_FTSR_TR3_Msk     (0x1UL << EXTI_FTSR_TR3_Pos)	/*!< 0x00000008 */
#define EXTI_FTSR_TR3         EXTI_FTSR_TR3_Msk				/*!< Falling trigger event configuration bit of line 3 */
#define EXTI_FTSR_TR4_Pos     (4U)
#define EXTI_FTSR_TR4_Msk     (0x1UL << EXTI_FTSR_TR4_Pos)	/*!< 0x00000010 */
#define EXTI_FTSR_TR4         EXTI_FTSR_TR4_Msk				/*!< Falling trigger event configuration bit of line 4 */
#define EXTI_FTSR_TR5_Pos     (5U)
#define EXTI_FTSR_TR5_Msk     (0x1UL << EXTI_FTSR_TR5_Pos)	/*!< 0x00000020 */
#define EXTI_FTSR_TR5         EXTI_FTSR_TR5_Msk				/*!< Falling trigger event configuration bit of line 5 */
#define EXTI_FTSR_TR6_Pos     (6U)
#define EXTI_FTSR_TR6_Msk     (0x1UL << EXTI_FTSR_TR6_Pos)	/*!< 0x00000040 */
#define EXTI_FTSR_TR6         EXTI_FTSR_TR6_Msk				/*!< Falling trigger event configuration bit of line 6 */
#define EXTI_FTSR_TR7_Pos     (7U)
#define EXTI_FTSR_TR7_Msk     (0x1UL << EXTI_FTSR_TR7_Pos)	/*!< 0x00000080 */
#define EXTI_FTSR_TR7         EXTI_FTSR_TR7_Msk				/*!< Falling trigger event configuration bit of line 7 */
#define EXTI_FTSR_TR8_Pos     (8U)
#define EXTI_FTSR_TR8_Msk     (0x1UL << EXTI_FTSR_TR8_Pos)	/*!< 0x00000100 */
#define EXTI_FTSR_TR8         EXTI_FTSR_TR8_Msk				/*!< Falling trigger event configuration bit of line 8 */
#define EXTI_FTSR_TR9_Pos     (9U)
#define EXTI_FTSR_TR9_Msk     (0x1UL << EXTI_FTSR_TR9_Pos)	/*!< 0x00000200 */
#define EXTI_FTSR_TR9         EXTI_FTSR_TR9_Msk				/*!< Falling trigger event configuration bit of line 9 */
#define EXTI_FTSR_TR10_Pos    (10U)
#define EXTI_FTSR_TR10_Msk    (0x1UL << EXTI_FTSR_TR10_Pos)	/*!< 0x00000400 */
#define EXTI_FTSR_TR10        EXTI_FTSR_TR10_Msk/*!< Falling trigger event configuration bit of line 10 */
#define EXTI_FTSR_TR11_Pos    (11U)
#define EXTI_FTSR_TR11_Msk    (0x1UL << EXTI_FTSR_TR11_Pos)	/*!< 0x00000800 */
#define EXTI_FTSR_TR11        EXTI_FTSR_TR11_Msk/*!< Falling trigger event configuration bit of line 11 */
#define EXTI_FTSR_TR12_Pos    (12U)
#define EXTI_FTSR_TR12_Msk    (0x1UL << EXTI_FTSR_TR12_Pos)	/*!< 0x00001000 */
#define EXTI_FTSR_TR12        EXTI_FTSR_TR12_Msk/*!< Falling trigger event configuration bit of line 12 */
#define EXTI_FTSR_TR13_Pos    (13U)
#define EXTI_FTSR_TR13_Msk    (0x1UL << EXTI_FTSR_TR13_Pos)	/*!< 0x00002000 */
#define EXTI_FTSR_TR13        EXTI_FTSR_TR13_Msk/*!< Falling trigger event configuration bit of line 13 */
#define EXTI_FTSR_TR14_Pos    (14U)
#define EXTI_FTSR_TR14_Msk    (0x1UL << EXTI_FTSR_TR14_Pos)	/*!< 0x00004000 */
#define EXTI_FTSR_TR14        EXTI_FTSR_TR14_Msk/*!< Falling trigger event configuration bit of line 14 */
#define EXTI_FTSR_TR15_Pos    (15U)
#define EXTI_FTSR_TR15_Msk    (0x1UL << EXTI_FTSR_TR15_Pos)	/*!< 0x00008000 */
#define EXTI_FTSR_TR15        EXTI_FTSR_TR15_Msk/*!< Falling trigger event configuration bit of line 15 */
#define EXTI_FTSR_TR16_Pos    (16U)
#define EXTI_FTSR_TR16_Msk    (0x1UL << EXTI_FTSR_TR16_Pos)	/*!< 0x00010000 */
#define EXTI_FTSR_TR16        EXTI_FTSR_TR16_Msk/*!< Falling trigger event configuration bit of line 16 */
#define EXTI_FTSR_TR17_Pos    (17U)
#define EXTI_FTSR_TR17_Msk    (0x1UL << EXTI_FTSR_TR17_Pos)	/*!< 0x00020000 */
#define EXTI_FTSR_TR17        EXTI_FTSR_TR17_Msk/*!< Falling trigger event configuration bit of line 17 */
#define EXTI_FTSR_TR18_Pos    (18U)
#define EXTI_FTSR_TR18_Msk    (0x1UL << EXTI_FTSR_TR18_Pos)	/*!< 0x00040000 */
#define EXTI_FTSR_TR18        EXTI_FTSR_TR18_Msk/*!< Falling trigger event configuration bit of line 18 */
#define EXTI_FTSR_TR19_Pos    (19U)
#define EXTI_FTSR_TR19_Msk    (0x1UL << EXTI_FTSR_TR19_Pos)	/*!< 0x00080000 */
#define EXTI_FTSR_TR19        EXTI_FTSR_TR19_Msk/*!< Falling trigger event configuration bit of line 19 */
#define EXTI_FTSR_TR20_Pos    (20U)
#define EXTI_FTSR_TR20_Msk    (0x1UL << EXTI_FTSR_TR20_Pos)	/*!< 0x00100000 */
#define EXTI_FTSR_TR20        EXTI_FTSR_TR20_Msk/*!< Falling trigger event configuration bit of line 20 */
#define EXTI_FTSR_TR21_Pos    (21U)
#define EXTI_FTSR_TR21_Msk    (0x1UL << EXTI_FTSR_TR21_Pos)	/*!< 0x00200000 */
#define EXTI_FTSR_TR21        EXTI_FTSR_TR21_Msk/*!< Falling trigger event configuration bit of line 21 */
#define EXTI_FTSR_TR22_Pos    (22U)
#define EXTI_FTSR_TR22_Msk    (0x1UL << EXTI_FTSR_TR22_Pos)	/*!< 0x00400000 */
#define EXTI_FTSR_TR22        EXTI_FTSR_TR22_Msk/*!< Falling trigger event configuration bit of line 22 */
#define EXTI_FTSR_TR23_Pos    (23U)
#define EXTI_FTSR_TR23_Msk    (0x1UL << EXTI_FTSR_TR23_Pos)	/*!< 0x00800000 */
#define EXTI_FTSR_TR23        EXTI_FTSR_TR23_Msk/*!< Falling trigger event configuration bit of line 23 */

/******************  Bit definition for EXTI_SWIER register  ******************/
#define EXTI_SWIER_SWIER0_Pos     (0U)
#define EXTI_SWIER_SWIER0_Msk     (0x1UL << EXTI_SWIER_SWIER0_Pos)	/*!< 0x00000001 */
#define EXTI_SWIER_SWIER0         EXTI_SWIER_SWIER0_Msk				/*!< Software Interrupt on line 0 */
#define EXTI_SWIER_SWIER1_Pos     (1U)
#define EXTI_SWIER_SWIER1_Msk     (0x1UL << EXTI_SWIER_SWIER1_Pos)	/*!< 0x00000002 */
#define EXTI_SWIER_SWIER1         EXTI_SWIER_SWIER1_Msk				/*!< Software Interrupt on line 1 */
#define EXTI_SWIER_SWIER2_Pos     (2U)
#define EXTI_SWIER_SWIER2_Msk     (0x1UL << EXTI_SWIER_SWIER2_Pos)	/*!< 0x00000004 */
#define EXTI_SWIER_SWIER2         EXTI_SWIER_SWIER2_Msk				/*!< Software Interrupt on line 2 */
#define EXTI_SWIER_SWIER3_Pos     (3U)
#define EXTI_SWIER_SWIER3_Msk     (0x1UL << EXTI_SWIER_SWIER3_Pos)	/*!< 0x00000008 */
#define EXTI_SWIER_SWIER3         EXTI_SWIER_SWIER3_Msk				/*!< Software Interrupt on line 3 */
#define EXTI_SWIER_SWIER4_Pos     (4U)
#define EXTI_SWIER_SWIER4_Msk     (0x1UL << EXTI_SWIER_SWIER4_Pos)	/*!< 0x00000010 */
#define EXTI_SWIER_SWIER4         EXTI_SWIER_SWIER4_Msk				/*!< Software Interrupt on line 4 */
#define EXTI_SWIER_SWIER5_Pos     (5U)
#define EXTI_SWIER_SWIER5_Msk     (0x1UL << EXTI_SWIER_SWIER5_Pos)	/*!< 0x00000020 */
#define EXTI_SWIER_SWIER5         EXTI_SWIER_SWIER5_Msk				/*!< Software Interrupt on line 5 */
#define EXTI_SWIER_SWIER6_Pos     (6U)
#define EXTI_SWIER_SWIER6_Msk     (0x1UL << EXTI_SWIER_SWIER6_Pos)	/*!< 0x00000040 */
#define EXTI_SWIER_SWIER6         EXTI_SWIER_SWIER6_Msk				/*!< Software Interrupt on line 6 */
#define EXTI_SWIER_SWIER7_Pos     (7U)
#define EXTI_SWIER_SWIER7_Msk     (0x1UL << EXTI_SWIER_SWIER7_Pos)	/*!< 0x00000080 */
#define EXTI_SWIER_SWIER7         EXTI_SWIER_SWIER7_Msk				/*!< Software Interrupt on line 7 */
#define EXTI_SWIER_SWIER8_Pos     (8U)
#define EXTI_SWIER_SWIER8_Msk     (0x1UL << EXTI_SWIER_SWIER8_Pos)	/*!< 0x00000100 */
#define EXTI_SWIER_SWIER8         EXTI_SWIER_SWIER8_Msk				/*!< Software Interrupt on line 8 */
#define EXTI_SWIER_SWIER9_Pos     (9U)
#define EXTI_SWIER_SWIER9_Msk     (0x1UL << EXTI_SWIER_SWIER9_Pos)	/*!< 0x00000200 */
#define EXTI_SWIER_SWIER9         EXTI_SWIER_SWIER9_Msk				/*!< Software Interrupt on line 9 */
#define EXTI_SWIER_SWIER10_Pos    (10U)
#define EXTI_SWIER_SWIER10_Msk    (0x1UL << EXTI_SWIER_SWIER10_Pos)	/*!< 0x00000400 */
#define EXTI_SWIER_SWIER10        EXTI_SWIER_SWIER10_Msk/*!< Software Interrupt on line 10 */
#define EXTI_SWIER_SWIER11_Pos    (11U)
#define EXTI_SWIER_SWIER11_Msk    (0x1UL << EXTI_SWIER_SWIER11_Pos)	/*!< 0x00000800 */
#define EXTI_SWIER_SWIER11        EXTI_SWIER_SWIER11_Msk/*!< Software Interrupt on line 11 */
#define EXTI_SWIER_SWIER12_Pos    (12U)
#define EXTI_SWIER_SWIER12_Msk    (0x1UL << EXTI_SWIER_SWIER12_Pos)	/*!< 0x00001000 */
#define EXTI_SWIER_SWIER12        EXTI_SWIER_SWIER12_Msk/*!< Software Interrupt on line 12 */
#define EXTI_SWIER_SWIER13_Pos    (13U)
#define EXTI_SWIER_SWIER13_Msk    (0x1UL << EXTI_SWIER_SWIER13_Pos)	/*!< 0x00002000 */
#define EXTI_SWIER_SWIER13        EXTI_SWIER_SWIER13_Msk/*!< Software Interrupt on line 13 */
#define EXTI_SWIER_SWIER14_Pos    (14U)
#define EXTI_SWIER_SWIER14_Msk    (0x1UL << EXTI_SWIER_SWIER14_Pos)	/*!< 0x00004000 */
#define EXTI_SWIER_SWIER14        EXTI_SWIER_SWIER14_Msk/*!< Software Interrupt on line 14 */
#define EXTI_SWIER_SWIER15_Pos    (15U)
#define EXTI_SWIER_SWIER15_Msk    (0x1UL << EXTI_SWIER_SWIER15_Pos)	/*!< 0x00008000 */
#define EXTI_SWIER_SWIER15        EXTI_SWIER_SWIER15_Msk/*!< Software Interrupt on line 15 */
#define EXTI_SWIER_SWIER16_Pos    (16U)
#define EXTI_SWIER_SWIER16_Msk    (0x1UL << EXTI_SWIER_SWIER16_Pos)	/*!< 0x00010000 */
#define EXTI_SWIER_SWIER16        EXTI_SWIER_SWIER16_Msk/*!< Software Interrupt on line 16 */
#define EXTI_SWIER_SWIER17_Pos    (17U)
#define EXTI_SWIER_SWIER17_Msk    (0x1UL << EXTI_SWIER_SWIER17_Pos)	/*!< 0x00020000 */
#define EXTI_SWIER_SWIER17        EXTI_SWIER_SWIER17_Msk/*!< Software Interrupt on line 17 */
#define EXTI_SWIER_SWIER18_Pos    (18U)
#define EXTI_SWIER_SWIER18_Msk    (0x1UL << EXTI_SWIER_SWIER18_Pos)	/*!< 0x00040000 */
#define EXTI_SWIER_SWIER18        EXTI_SWIER_SWIER18_Msk/*!< Software Interrupt on line 18 */
#define EXTI_SWIER_SWIER19_Pos    (19U)
#define EXTI_SWIER_SWIER19_Msk    (0x1UL << EXTI_SWIER_SWIER19_Pos)	/*!< 0x00080000 */
#define EXTI_SWIER_SWIER19        EXTI_SWIER_SWIER19_Msk/*!< Software Interrupt on line 19 */
#define EXTI_SWIER_SWIER20_Pos    (20U)
#define EXTI_SWIER_SWIER20_Msk    (0x1UL << EXTI_SWIER_SWIER20_Pos)	/*!< 0x00100000 */
#define EXTI_SWIER_SWIER20        EXTI_SWIER_SWIER20_Msk/*!< Software Interrupt on line 20 */
#define EXTI_SWIER_SWIER21_Pos    (21U)
#define EXTI_SWIER_SWIER21_Msk    (0x1UL << EXTI_SWIER_SWIER21_Pos)	/*!< 0x00200000 */
#define EXTI_SWIER_SWIER21        EXTI_SWIER_SWIER21_Msk/*!< Software Interrupt on line 21 */
#define EXTI_SWIER_SWIER22_Pos    (22U)
#define EXTI_SWIER_SWIER22_Msk    (0x1UL << EXTI_SWIER_SWIER22_Pos)	/*!< 0x00400000 */
#define EXTI_SWIER_SWIER22        EXTI_SWIER_SWIER22_Msk/*!< Software Interrupt on line 22 */
#define EXTI_SWIER_SWIER23_Pos    (23U)
#define EXTI_SWIER_SWIER23_Msk    (0x1UL << EXTI_SWIER_SWIER23_Pos)	/*!< 0x00800000 */
#define EXTI_SWIER_SWIER23        EXTI_SWIER_SWIER23_Msk/*!< Software Interrupt on line 23 */

/*******************  Bit definition for EXTI_PR register  ********************/
#define EXTI_PR_PR0_Pos     (0U)
#define EXTI_PR_PR0_Msk     (0x1UL << EXTI_PR_PR0_Pos)	/*!< 0x00000001 */
#define EXTI_PR_PR0         EXTI_PR_PR0_Msk				/*!< Pending bit for line 0 */
#define EXTI_PR_PR1_Pos     (1U)
#define EXTI_PR_PR1_Msk     (0x1UL << EXTI_PR_PR1_Pos)	/*!< 0x00000002 */
#define EXTI_PR_PR1         EXTI_PR_PR1_Msk				/*!< Pending bit for line 1 */
#define EXTI_PR_PR2_Pos     (2U)
#define EXTI_PR_PR2_Msk     (0x1UL << EXTI_PR_PR2_Pos)	/*!< 0x00000004 */
#define EXTI_PR_PR2         EXTI_PR_PR2_Msk				/*!< Pending bit for line 2 */
#define EXTI_PR_PR3_Pos     (3U)
#define EXTI_PR_PR3_Msk     (0x1UL << EXTI_PR_PR3_Pos)	/*!< 0x00000008 */
#define EXTI_PR_PR3         EXTI_PR_PR3_Msk				/*!< Pending bit for line 3 */
#define EXTI_PR_PR4_Pos     (4U)
#define EXTI_PR_PR4_Msk     (0x1UL << EXTI_PR_PR4_Pos)	/*!< 0x00000010 */
#define EXTI_PR_PR4         EXTI_PR_PR4_Msk				/*!< Pending bit for line 4 */
#define EXTI_PR_PR5_Pos     (5U)
#define EXTI_PR_PR5_Msk     (0x1UL << EXTI_PR_PR5_Pos)	/*!< 0x00000020 */
#define EXTI_PR_PR5         EXTI_PR_PR5_Msk				/*!< Pending bit for line 5 */
#define EXTI_PR_PR6_Pos     (6U)
#define EXTI_PR_PR6_Msk     (0x1UL << EXTI_PR_PR6_Pos)	/*!< 0x00000040 */
#define EXTI_PR_PR6         EXTI_PR_PR6_Msk				/*!< Pending bit for line 6 */
#define EXTI_PR_PR7_Pos     (7U)
#define EXTI_PR_PR7_Msk     (0x1UL << EXTI_PR_PR7_Pos)	/*!< 0x00000080 */
#define EXTI_PR_PR7         EXTI_PR_PR7_Msk				/*!< Pending bit for line 7 */
#define EXTI_PR_PR8_Pos     (8U)
#define EXTI_PR_PR8_Msk     (0x1UL << EXTI_PR_PR8_Pos)	/*!< 0x00000100 */
#define EXTI_PR_PR8         EXTI_PR_PR8_Msk				/*!< Pending bit for line 8 */
#define EXTI_PR_PR9_Pos     (9U)
#define EXTI_PR_PR9_Msk     (0x1UL << EXTI_PR_PR9_Pos)	/*!< 0x00000200 */
#define EXTI_PR_PR9         EXTI_PR_PR9_Msk				/*!< Pending bit for line 9 */
#define EXTI_PR_PR10_Pos    (10U)
#define EXTI_PR_PR10_Msk    (0x1UL << EXTI_PR_PR10_Pos)	/*!< 0x00000400 */
#define EXTI_PR_PR10        EXTI_PR_PR10_Msk/*!< Pending bit for line 10 */
#define EXTI_PR_PR11_Pos    (11U)
#define EXTI_PR_PR11_Msk    (0x1UL << EXTI_PR_PR11_Pos)	/*!< 0x00000800 */
#define EXTI_PR_PR11        EXTI_PR_PR11_Msk/*!< Pending bit for line 11 */
#define EXTI_PR_PR12_Pos    (12U)
#define EXTI_PR_PR12_Msk    (0x1UL << EXTI_PR_PR12_Pos)	/*!< 0x00001000 */
#define EXTI_PR_PR12        EXTI_PR_PR12_Msk/*!< Pending bit for line 12 */
#define EXTI_PR_PR13_Pos    (13U)
#define EXTI_PR_PR13_Msk    (0x1UL << EXTI_PR_PR13_Pos)	/*!< 0x00002000 */
#define EXTI_PR_PR13        EXTI_PR_PR13_Msk/*!< Pending bit for line 13 */
#define EXTI_PR_PR14_Pos    (14U)
#define EXTI_PR_PR14_Msk    (0x1UL << EXTI_PR_PR14_Pos)	/*!< 0x00004000 */
#define EXTI_PR_PR14        EXTI_PR_PR14_Msk/*!< Pending bit for line 14 */
#define EXTI_PR_PR15_Pos    (15U)
#define EXTI_PR_PR15_Msk    (0x1UL << EXTI_PR_PR15_Pos)	/*!< 0x00008000 */
#define EXTI_PR_PR15        EXTI_PR_PR15_Msk/*!< Pending bit for line 15 */
#define EXTI_PR_PR16_Pos    (16U)
#define EXTI_PR_PR16_Msk    (0x1UL << EXTI_PR_PR16_Pos)	/*!< 0x00010000 */
#define EXTI_PR_PR16        EXTI_PR_PR16_Msk/*!< Pending bit for line 16 */
#define EXTI_PR_PR17_Pos    (17U)
#define EXTI_PR_PR17_Msk    (0x1UL << EXTI_PR_PR17_Pos)	/*!< 0x00020000 */
#define EXTI_PR_PR17        EXTI_PR_PR17_Msk/*!< Pending bit for line 17 */
#define EXTI_PR_PR18_Pos    (18U)
#define EXTI_PR_PR18_Msk    (0x1UL << EXTI_PR_PR18_Pos)	/*!< 0x00040000 */
#define EXTI_PR_PR18        EXTI_PR_PR18_Msk/*!< Pending bit for line 18 */
#define EXTI_PR_PR19_Pos    (19U)
#define EXTI_PR_PR19_Msk    (0x1UL << EXTI_PR_PR19_Pos)	/*!< 0x00080000 */
#define EXTI_PR_PR19        EXTI_PR_PR19_Msk/*!< Pending bit for line 19 */
#define EXTI_PR_PR20_Pos    (20U)
#define EXTI_PR_PR20_Msk    (0x1UL << EXTI_PR_PR20_Pos)	/*!< 0x00100000 */
#define EXTI_PR_PR20        EXTI_PR_PR20_Msk/*!< Pending bit for line 20 */
#define EXTI_PR_PR21_Pos    (21U)
#define EXTI_PR_PR21_Msk    (0x1UL << EXTI_PR_PR21_Pos)	/*!< 0x00200000 */
#define EXTI_PR_PR21        EXTI_PR_PR21_Msk/*!< Pending bit for line 21 */
#define EXTI_PR_PR22_Pos    (22U)
#define EXTI_PR_PR22_Msk    (0x1UL << EXTI_PR_PR22_Pos)	/*!< 0x00400000 */
#define EXTI_PR_PR22        EXTI_PR_PR22_Msk/*!< Pending bit for line 22 */
#define EXTI_PR_PR23_Pos    (23U)
#define EXTI_PR_PR23_Msk    (0x1UL << EXTI_PR_PR23_Pos)	/*!< 0x00800000 */
#define EXTI_PR_PR23        EXTI_PR_PR23_Msk/*!< Pending bit for line 23 */

/******************************************************************************/
/*                                                                            */
/*                                    FLASH                                   */
/*                                                                            */
/******************************************************************************/

/*
 * @brief FLASH Total Sectors Number
 */
#define FLASH_SECTOR_TOTAL    8

/*******************  Bits definition for FLASH_ACR register  *****************/
#define FLASH_ACR_LATENCY_Pos     (0U)
#define FLASH_ACR_LATENCY_Msk     (0xFUL << FLASH_ACR_LATENCY_Pos)	/*!< 0x0000000F */
#define FLASH_ACR_LATENCY         FLASH_ACR_LATENCY_Msk
#define FLASH_ACR_LATENCY_0WS     0x00000000U
#define FLASH_ACR_LATENCY_1WS     0x00000001U
#define FLASH_ACR_LATENCY_2WS     0x00000002U
#define FLASH_ACR_LATENCY_3WS     0x00000003U
#define FLASH_ACR_LATENCY_4WS     0x00000004U
#define FLASH_ACR_LATENCY_5WS     0x00000005U
#define FLASH_ACR_LATENCY_6WS     0x00000006U
#define FLASH_ACR_LATENCY_7WS     0x00000007U
#define FLASH_ACR_LATENCY_8WS     0x00000008U
#define FLASH_ACR_LATENCY_9WS     0x00000009U
#define FLASH_ACR_LATENCY_10WS    0x0000000AU
#define FLASH_ACR_LATENCY_11WS    0x0000000BU
#define FLASH_ACR_LATENCY_12WS    0x0000000CU
#define FLASH_ACR_LATENCY_13WS    0x0000000DU
#define FLASH_ACR_LATENCY_14WS    0x0000000EU
#define FLASH_ACR_LATENCY_15WS    0x0000000FU
#define FLASH_ACR_PRFTEN_Pos      (8U)
#define FLASH_ACR_PRFTEN_Msk      (0x1UL << FLASH_ACR_PRFTEN_Pos)	/*!< 0x00000100 */
#define FLASH_ACR_PRFTEN          FLASH_ACR_PRFTEN_Msk
#define FLASH_ACR_ARTEN_Pos       (9U)
#define FLASH_ACR_ARTEN_Msk       (0x1UL << FLASH_ACR_ARTEN_Pos)/*!< 0x00000200 */
#define FLASH_ACR_ARTEN           FLASH_ACR_ARTEN_Msk
#define FLASH_ACR_ARTRST_Pos      (11U)
#define FLASH_ACR_ARTRST_Msk      (0x1UL << FLASH_ACR_ARTRST_Pos)	/*!< 0x00000800 */
#define FLASH_ACR_ARTRST          FLASH_ACR_ARTRST_Msk

/*******************  Bits definition for FLASH_SR register  ******************/
#define FLASH_SR_EOP_Pos       (0U)
#define FLASH_SR_EOP_Msk       (0x1UL << FLASH_SR_EOP_Pos)	/*!< 0x00000001 */
#define FLASH_SR_EOP           FLASH_SR_EOP_Msk
#define FLASH_SR_OPERR_Pos     (1U)
#define FLASH_SR_OPERR_Msk     (0x1UL << FLASH_SR_OPERR_Pos)/*!< 0x00000002 */
#define FLASH_SR_OPERR         FLASH_SR_OPERR_Msk
#define FLASH_SR_WRPERR_Pos    (4U)
#define FLASH_SR_WRPERR_Msk    (0x1UL << FLASH_SR_WRPERR_Pos)	/*!< 0x00000010 */
#define FLASH_SR_WRPERR        FLASH_SR_WRPERR_Msk
#define FLASH_SR_PGAERR_Pos    (5U)
#define FLASH_SR_PGAERR_Msk    (0x1UL << FLASH_SR_PGAERR_Pos)	/*!< 0x00000020 */
#define FLASH_SR_PGAERR        FLASH_SR_PGAERR_Msk
#define FLASH_SR_PGPERR_Pos    (6U)
#define FLASH_SR_PGPERR_Msk    (0x1UL << FLASH_SR_PGPERR_Pos)	/*!< 0x00000040 */
#define FLASH_SR_PGPERR        FLASH_SR_PGPERR_Msk
#define FLASH_SR_ERSERR_Pos    (7U)
#define FLASH_SR_ERSERR_Msk    (0x1UL << FLASH_SR_ERSERR_Pos)	/*!< 0x00000080 */
#define FLASH_SR_ERSERR        FLASH_SR_ERSERR_Msk
#define FLASH_SR_RDERR_Pos     (8U)
#define FLASH_SR_RDERR_Msk     (0x1UL << FLASH_SR_RDERR_Pos)/*!< 0x00000100 */
#define FLASH_SR_RDERR         FLASH_SR_RDERR_Msk
#define FLASH_SR_BSY_Pos       (16U)
#define FLASH_SR_BSY_Msk       (0x1UL << FLASH_SR_BSY_Pos)	/*!< 0x00010000 */
#define FLASH_SR_BSY           FLASH_SR_BSY_Msk

/*******************  Bits definition for FLASH_CR register  ******************/
#define FLASH_CR_PG_Pos         (0U)
#define FLASH_CR_PG_Msk         (0x1UL << FLASH_CR_PG_Pos)	/*!< 0x00000001 */
#define FLASH_CR_PG             FLASH_CR_PG_Msk
#define FLASH_CR_SER_Pos        (1U)
#define FLASH_CR_SER_Msk        (0x1UL << FLASH_CR_SER_Pos)	/*!< 0x00000002 */
#define FLASH_CR_SER            FLASH_CR_SER_Msk
#define FLASH_CR_MER_Pos        (2U)
#define FLASH_CR_MER_Msk        (0x1UL << FLASH_CR_MER_Pos)	/*!< 0x00000004 */
#define FLASH_CR_MER            FLASH_CR_MER_Msk
#define FLASH_CR_SNB_Pos        (3U)
#define FLASH_CR_SNB_Msk        (0xFUL << FLASH_CR_SNB_Pos)	/*!< 0x00000078 */
#define FLASH_CR_SNB            FLASH_CR_SNB_Msk
#define FLASH_CR_SNB_0          0x00000008U
#define FLASH_CR_SNB_1          0x00000010U
#define FLASH_CR_SNB_2          0x00000020U
#define FLASH_CR_SNB_3          0x00000040U
#define FLASH_CR_PSIZE_Pos      (8U)
#define FLASH_CR_PSIZE_Msk      (0x3UL << FLASH_CR_PSIZE_Pos)	/*!< 0x00000300 */
#define FLASH_CR_PSIZE          FLASH_CR_PSIZE_Msk
#define FLASH_CR_PSIZE_0        (0x1UL << FLASH_CR_PSIZE_Pos)	/*!< 0x00000100 */
#define FLASH_CR_PSIZE_1        (0x2UL << FLASH_CR_PSIZE_Pos)	/*!< 0x00000200 */
#define FLASH_CR_STRT_Pos       (16U)
#define FLASH_CR_STRT_Msk       (0x1UL << FLASH_CR_STRT_Pos)/*!< 0x00010000 */
#define FLASH_CR_STRT           FLASH_CR_STRT_Msk
#define FLASH_CR_EOPIE_Pos      (24U)
#define FLASH_CR_EOPIE_Msk      (0x1UL << FLASH_CR_EOPIE_Pos)	/*!< 0x01000000 */
#define FLASH_CR_EOPIE          FLASH_CR_EOPIE_Msk
#define FLASH_CR_ERRIE_Pos      (25U)
#define FLASH_CR_ERRIE_Msk      (0x1UL << FLASH_CR_ERRIE_Pos)	/*!< 0x02000000 */
#define FLASH_CR_ERRIE          FLASH_CR_ERRIE_Msk
#define FLASH_CR_RDERRIE_Pos    (26U)
#define FLASH_CR_RDERRIE_Msk    (0x1UL << FLASH_CR_RDERRIE_Pos)	/*!< 0x04000000 */
#define FLASH_CR_RDERRIE        FLASH_CR_RDERRIE_Msk
#define FLASH_CR_LOCK_Pos       (31U)
#define FLASH_CR_LOCK_Msk       (0x1UL << FLASH_CR_LOCK_Pos)/*!< 0x80000000 */
#define FLASH_CR_LOCK           FLASH_CR_LOCK_Msk

/*******************  Bits definition for FLASH_OPTCR register  ***************/
#define FLASH_OPTCR_OPTLOCK_Pos       (0U)
#define FLASH_OPTCR_OPTLOCK_Msk       (0x1UL << FLASH_OPTCR_OPTLOCK_Pos)/*!< 0x00000001 */
#define FLASH_OPTCR_OPTLOCK           FLASH_OPTCR_OPTLOCK_Msk
#define FLASH_OPTCR_OPTSTRT_Pos       (1U)
#define FLASH_OPTCR_OPTSTRT_Msk       (0x1UL << FLASH_OPTCR_OPTSTRT_Pos)/*!< 0x00000002 */
#define FLASH_OPTCR_OPTSTRT           FLASH_OPTCR_OPTSTRT_Msk
#define FLASH_OPTCR_BOR_LEV_Pos       (2U)
#define FLASH_OPTCR_BOR_LEV_Msk       (0x3UL << FLASH_OPTCR_BOR_LEV_Pos)/*!< 0x0000000C */
#define FLASH_OPTCR_BOR_LEV           FLASH_OPTCR_BOR_LEV_Msk
#define FLASH_OPTCR_BOR_LEV_0         (0x1UL << FLASH_OPTCR_BOR_LEV_Pos)/*!< 0x00000004 */
#define FLASH_OPTCR_BOR_LEV_1         (0x2UL << FLASH_OPTCR_BOR_LEV_Pos)/*!< 0x00000008 */
#define FLASH_OPTCR_WWDG_SW_Pos       (4U)
#define FLASH_OPTCR_WWDG_SW_Msk       (0x1UL << FLASH_OPTCR_WWDG_SW_Pos)/*!< 0x00000010 */
#define FLASH_OPTCR_WWDG_SW           FLASH_OPTCR_WWDG_SW_Msk
#define FLASH_OPTCR_IWDG_SW_Pos       (5U)
#define FLASH_OPTCR_IWDG_SW_Msk       (0x1UL << FLASH_OPTCR_IWDG_SW_Pos)/*!< 0x00000020 */
#define FLASH_OPTCR_IWDG_SW           FLASH_OPTCR_IWDG_SW_Msk
#define FLASH_OPTCR_nRST_STOP_Pos     (6U)
#define FLASH_OPTCR_nRST_STOP_Msk     (0x1UL << FLASH_OPTCR_nRST_STOP_Pos)	/*!< 0x00000040 */
#define FLASH_OPTCR_nRST_STOP         FLASH_OPTCR_nRST_STOP_Msk
#define FLASH_OPTCR_nRST_STDBY_Pos    (7U)
#define FLASH_OPTCR_nRST_STDBY_Msk    (0x1UL << FLASH_OPTCR_nRST_STDBY_Pos)	/*!< 0x00000080 */
#define FLASH_OPTCR_nRST_STDBY        FLASH_OPTCR_nRST_STDBY_Msk
#define FLASH_OPTCR_RDP_Pos           (8U)
#define FLASH_OPTCR_RDP_Msk           (0xFFUL << FLASH_OPTCR_RDP_Pos)	/*!< 0x0000FF00 */
#define FLASH_OPTCR_RDP               FLASH_OPTCR_RDP_Msk
#define FLASH_OPTCR_RDP_0             (0x01UL << FLASH_OPTCR_RDP_Pos)	/*!< 0x00000100 */
#define FLASH_OPTCR_RDP_1             (0x02UL << FLASH_OPTCR_RDP_Pos)	/*!< 0x00000200 */
#define FLASH_OPTCR_RDP_2             (0x04UL << FLASH_OPTCR_RDP_Pos)	/*!< 0x00000400 */
#define FLASH_OPTCR_RDP_3             (0x08UL << FLASH_OPTCR_RDP_Pos)	/*!< 0x00000800 */
#define FLASH_OPTCR_RDP_4             (0x10UL << FLASH_OPTCR_RDP_Pos)	/*!< 0x00001000 */
#define FLASH_OPTCR_RDP_5             (0x20UL << FLASH_OPTCR_RDP_Pos)	/*!< 0x00002000 */
#define FLASH_OPTCR_RDP_6             (0x40UL << FLASH_OPTCR_RDP_Pos)	/*!< 0x00004000 */
#define FLASH_OPTCR_RDP_7             (0x80UL << FLASH_OPTCR_RDP_Pos)	/*!< 0x00008000 */
#define FLASH_OPTCR_nWRP_Pos          (16U)
#define FLASH_OPTCR_nWRP_Msk          (0xFFUL << FLASH_OPTCR_nWRP_Pos)	/*!< 0x00FF0000 */
#define FLASH_OPTCR_nWRP              FLASH_OPTCR_nWRP_Msk
#define FLASH_OPTCR_nWRP_0            0x00010000U
#define FLASH_OPTCR_nWRP_1            0x00020000U
#define FLASH_OPTCR_nWRP_2            0x00040000U
#define FLASH_OPTCR_nWRP_3            0x00080000U
#define FLASH_OPTCR_nWRP_4            0x00100000U
#define FLASH_OPTCR_nWRP_5            0x00200000U
#define FLASH_OPTCR_nWRP_6            0x00400000U
#define FLASH_OPTCR_nWRP_7            0x00800000U
#define FLASH_OPTCR_IWDG_STDBY_Pos    (30U)
#define FLASH_OPTCR_IWDG_STDBY_Msk    (0x1UL << FLASH_OPTCR_IWDG_STDBY_Pos)	/*!< 0x40000000 */
#define FLASH_OPTCR_IWDG_STDBY        FLASH_OPTCR_IWDG_STDBY_Msk
#define FLASH_OPTCR_IWDG_STOP_Pos     (31U)
#define FLASH_OPTCR_IWDG_STOP_Msk     (0x1UL << FLASH_OPTCR_IWDG_STOP_Pos)	/*!< 0x80000000 */
#define FLASH_OPTCR_IWDG_STOP         FLASH_OPTCR_IWDG_STOP_Msk

/*******************  Bits definition for FLASH_OPTCR1 register  ***************/
#define FLASH_OPTCR1_BOOT_ADD0_Pos    (0U)
#define FLASH_OPTCR1_BOOT_ADD0_Msk    (0xFFFFUL << FLASH_OPTCR1_BOOT_ADD0_Pos)	/*!< 0x0000FFFF */
#define FLASH_OPTCR1_BOOT_ADD0        FLASH_OPTCR1_BOOT_ADD0_Msk
#define FLASH_OPTCR1_BOOT_ADD1_Pos    (16U)
#define FLASH_OPTCR1_BOOT_ADD1_Msk    (0xFFFFUL << FLASH_OPTCR1_BOOT_ADD1_Pos)	/*!< 0xFFFF0000 */
#define FLASH_OPTCR1_BOOT_ADD1        FLASH_OPTCR1_BOOT_ADD1_Msk

/*******************  Bits definition for FLASH_OPTCR2 register  ***************/
#define FLASH_OPTCR2_PCROP_Pos        (0U)
#define FLASH_OPTCR2_PCROP_Msk        (0xFFUL << FLASH_OPTCR2_PCROP_Pos)/*!< 0x000000FF */
#define FLASH_OPTCR2_PCROP            FLASH_OPTCR2_PCROP_Msk
#define FLASH_OPTCR2_PCROP_0          (0x01UL << FLASH_OPTCR2_PCROP_Pos)/*!< 0x00000001 */
#define FLASH_OPTCR2_PCROP_1          (0x02UL << FLASH_OPTCR2_PCROP_Pos)/*!< 0x00000002 */
#define FLASH_OPTCR2_PCROP_2          (0x04UL << FLASH_OPTCR2_PCROP_Pos)/*!< 0x00000004 */
#define FLASH_OPTCR2_PCROP_3          (0x08UL << FLASH_OPTCR2_PCROP_Pos)/*!< 0x00000008 */
#define FLASH_OPTCR2_PCROP_4          (0x10UL << FLASH_OPTCR2_PCROP_Pos)/*!< 0x00000010 */
#define FLASH_OPTCR2_PCROP_5          (0x20UL << FLASH_OPTCR2_PCROP_Pos)/*!< 0x00000020 */
#define FLASH_OPTCR2_PCROP_6          (0x40UL << FLASH_OPTCR2_PCROP_Pos)/*!< 0x00000040 */
#define FLASH_OPTCR2_PCROP_7          (0x80UL << FLASH_OPTCR2_PCROP_Pos)/*!< 0x00000080 */
#define FLASH_OPTCR2_PCROP_RDP_Pos    (31U)
#define FLASH_OPTCR2_PCROP_RDP_Msk    (0x1UL << FLASH_OPTCR2_PCROP_RDP_Pos)	/*!< 0x80000000 */
#define FLASH_OPTCR2_PCROP_RDP        FLASH_OPTCR2_PCROP_RDP_Msk

/******************************************************************************/
/*                                                                            */
/*                          Flexible Memory Controller                        */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for FMC_BCR1 register  *******************/
#define FMC_BCR1_MBKEN_Pos        (0U)
#define FMC_BCR1_MBKEN_Msk        (0x1UL << FMC_BCR1_MBKEN_Pos)	/*!< 0x00000001 */
#define FMC_BCR1_MBKEN            FMC_BCR1_MBKEN_Msk/*!<Memory bank enable bit                 */
#define FMC_BCR1_MUXEN_Pos        (1U)
#define FMC_BCR1_MUXEN_Msk        (0x1UL << FMC_BCR1_MUXEN_Pos)	/*!< 0x00000002 */
#define FMC_BCR1_MUXEN            FMC_BCR1_MUXEN_Msk/*!<Address/data multiplexing enable bit   */
#define FMC_BCR1_MTYP_Pos         (2U)
#define FMC_BCR1_MTYP_Msk         (0x3UL << FMC_BCR1_MTYP_Pos)	/*!< 0x0000000C */
#define FMC_BCR1_MTYP             FMC_BCR1_MTYP_Msk				/*!<MTYP[1:0] bits (Memory type)           */
#define FMC_BCR1_MTYP_0           (0x1UL << FMC_BCR1_MTYP_Pos)	/*!< 0x00000004 */
#define FMC_BCR1_MTYP_1           (0x2UL << FMC_BCR1_MTYP_Pos)	/*!< 0x00000008 */
#define FMC_BCR1_MWID_Pos         (4U)
#define FMC_BCR1_MWID_Msk         (0x3UL << FMC_BCR1_MWID_Pos)	/*!< 0x00000030 */
#define FMC_BCR1_MWID             FMC_BCR1_MWID_Msk				/*!<MWID[1:0] bits (Memory data bus width) */
#define FMC_BCR1_MWID_0           (0x1UL << FMC_BCR1_MWID_Pos)	/*!< 0x00000010 */
#define FMC_BCR1_MWID_1           (0x2UL << FMC_BCR1_MWID_Pos)	/*!< 0x00000020 */
#define FMC_BCR1_FACCEN_Pos       (6U)
#define FMC_BCR1_FACCEN_Msk       (0x1UL << FMC_BCR1_FACCEN_Pos)/*!< 0x00000040 */
#define FMC_BCR1_FACCEN           FMC_BCR1_FACCEN_Msk	/*!<Flash access enable        */
#define FMC_BCR1_BURSTEN_Pos      (8U)
#define FMC_BCR1_BURSTEN_Msk      (0x1UL << FMC_BCR1_BURSTEN_Pos)	/*!< 0x00000100 */
#define FMC_BCR1_BURSTEN          FMC_BCR1_BURSTEN_Msk				/*!<Burst enable bit           */
#define FMC_BCR1_WAITPOL_Pos      (9U)
#define FMC_BCR1_WAITPOL_Msk      (0x1UL << FMC_BCR1_WAITPOL_Pos)	/*!< 0x00000200 */
#define FMC_BCR1_WAITPOL          FMC_BCR1_WAITPOL_Msk				/*!<Wait signal polarity bit   */
#define FMC_BCR1_WRAPMOD_Pos      (10U)
#define FMC_BCR1_WRAPMOD_Msk      (0x1UL << FMC_BCR1_WRAPMOD_Pos)	/*!< 0x00000400 */
#define FMC_BCR1_WRAPMOD          FMC_BCR1_WRAPMOD_Msk				/*!<Wrapped burst mode support */
#define FMC_BCR1_WAITCFG_Pos      (11U)
#define FMC_BCR1_WAITCFG_Msk      (0x1UL << FMC_BCR1_WAITCFG_Pos)	/*!< 0x00000800 */
#define FMC_BCR1_WAITCFG          FMC_BCR1_WAITCFG_Msk				/*!<Wait timing configuration  */
#define FMC_BCR1_WREN_Pos         (12U)
#define FMC_BCR1_WREN_Msk         (0x1UL << FMC_BCR1_WREN_Pos)	/*!< 0x00001000 */
#define FMC_BCR1_WREN             FMC_BCR1_WREN_Msk				/*!<Write enable bit           */
#define FMC_BCR1_WAITEN_Pos       (13U)
#define FMC_BCR1_WAITEN_Msk       (0x1UL << FMC_BCR1_WAITEN_Pos)/*!< 0x00002000 */
#define FMC_BCR1_WAITEN           FMC_BCR1_WAITEN_Msk	/*!<Wait enable bit            */
#define FMC_BCR1_EXTMOD_Pos       (14U)
#define FMC_BCR1_EXTMOD_Msk       (0x1UL << FMC_BCR1_EXTMOD_Pos)/*!< 0x00004000 */
#define FMC_BCR1_EXTMOD           FMC_BCR1_EXTMOD_Msk	/*!<Extended mode enable       */
#define FMC_BCR1_ASYNCWAIT_Pos    (15U)
#define FMC_BCR1_ASYNCWAIT_Msk    (0x1UL << FMC_BCR1_ASYNCWAIT_Pos)	/*!< 0x00008000 */
#define FMC_BCR1_ASYNCWAIT        FMC_BCR1_ASYNCWAIT_Msk/*!<Asynchronous wait          */
#define FMC_BCR1_CPSIZE_Pos       (16U)
#define FMC_BCR1_CPSIZE_Msk       (0x7UL << FMC_BCR1_CPSIZE_Pos)/*!< 0x00070000 */
#define FMC_BCR1_CPSIZE           FMC_BCR1_CPSIZE_Msk	/*!<CRAM page size             */
#define FMC_BCR1_CPSIZE_0         (0x1UL << FMC_BCR1_CPSIZE_Pos)/*!< 0x00010000 */
#define FMC_BCR1_CPSIZE_1         (0x2UL << FMC_BCR1_CPSIZE_Pos)/*!< 0x00020000 */
#define FMC_BCR1_CPSIZE_2         (0x4UL << FMC_BCR1_CPSIZE_Pos)/*!< 0x00040000 */
#define FMC_BCR1_CBURSTRW_Pos     (19U)
#define FMC_BCR1_CBURSTRW_Msk     (0x1UL << FMC_BCR1_CBURSTRW_Pos)	/*!< 0x00080000 */
#define FMC_BCR1_CBURSTRW         FMC_BCR1_CBURSTRW_Msk				/*!<Write burst enable         */
#define FMC_BCR1_CCLKEN_Pos       (20U)
#define FMC_BCR1_CCLKEN_Msk       (0x1UL << FMC_BCR1_CCLKEN_Pos)/*!< 0x00100000 */
#define FMC_BCR1_CCLKEN           FMC_BCR1_CCLKEN_Msk	/*!<Continous clock enable     */
#define FMC_BCR1_WFDIS_Pos        (21U)
#define FMC_BCR1_WFDIS_Msk        (0x1UL << FMC_BCR1_WFDIS_Pos)	/*!< 0x00200000 */
#define FMC_BCR1_WFDIS            FMC_BCR1_WFDIS_Msk/*!<Write FIFO Disable         */

/******************  Bit definition for FMC_BCR2 register  *******************/
#define FMC_BCR2_MBKEN_Pos        (0U)
#define FMC_BCR2_MBKEN_Msk        (0x1UL << FMC_BCR2_MBKEN_Pos)	/*!< 0x00000001 */
#define FMC_BCR2_MBKEN            FMC_BCR2_MBKEN_Msk/*!<Memory bank enable bit                 */
#define FMC_BCR2_MUXEN_Pos        (1U)
#define FMC_BCR2_MUXEN_Msk        (0x1UL << FMC_BCR2_MUXEN_Pos)	/*!< 0x00000002 */
#define FMC_BCR2_MUXEN            FMC_BCR2_MUXEN_Msk/*!<Address/data multiplexing enable bit   */
#define FMC_BCR2_MTYP_Pos         (2U)
#define FMC_BCR2_MTYP_Msk         (0x3UL << FMC_BCR2_MTYP_Pos)	/*!< 0x0000000C */
#define FMC_BCR2_MTYP             FMC_BCR2_MTYP_Msk				/*!<MTYP[1:0] bits (Memory type)           */
#define FMC_BCR2_MTYP_0           (0x1UL << FMC_BCR2_MTYP_Pos)	/*!< 0x00000004 */
#define FMC_BCR2_MTYP_1           (0x2UL << FMC_BCR2_MTYP_Pos)	/*!< 0x00000008 */
#define FMC_BCR2_MWID_Pos         (4U)
#define FMC_BCR2_MWID_Msk         (0x3UL << FMC_BCR2_MWID_Pos)	/*!< 0x00000030 */
#define FMC_BCR2_MWID             FMC_BCR2_MWID_Msk				/*!<MWID[1:0] bits (Memory data bus width) */
#define FMC_BCR2_MWID_0           (0x1UL << FMC_BCR2_MWID_Pos)	/*!< 0x00000010 */
#define FMC_BCR2_MWID_1           (0x2UL << FMC_BCR2_MWID_Pos)	/*!< 0x00000020 */
#define FMC_BCR2_FACCEN_Pos       (6U)
#define FMC_BCR2_FACCEN_Msk       (0x1UL << FMC_BCR2_FACCEN_Pos)/*!< 0x00000040 */
#define FMC_BCR2_FACCEN           FMC_BCR2_FACCEN_Msk	/*!<Flash access enable        */
#define FMC_BCR2_BURSTEN_Pos      (8U)
#define FMC_BCR2_BURSTEN_Msk      (0x1UL << FMC_BCR2_BURSTEN_Pos)	/*!< 0x00000100 */
#define FMC_BCR2_BURSTEN          FMC_BCR2_BURSTEN_Msk				/*!<Burst enable bit           */
#define FMC_BCR2_WAITPOL_Pos      (9U)
#define FMC_BCR2_WAITPOL_Msk      (0x1UL << FMC_BCR2_WAITPOL_Pos)	/*!< 0x00000200 */
#define FMC_BCR2_WAITPOL          FMC_BCR2_WAITPOL_Msk				/*!<Wait signal polarity bit   */
#define FMC_BCR2_WRAPMOD_Pos      (10U)
#define FMC_BCR2_WRAPMOD_Msk      (0x1UL << FMC_BCR2_WRAPMOD_Pos)	/*!< 0x00000400 */
#define FMC_BCR2_WRAPMOD          FMC_BCR2_WRAPMOD_Msk				/*!<Wrapped burst mode support */
#define FMC_BCR2_WAITCFG_Pos      (11U)
#define FMC_BCR2_WAITCFG_Msk      (0x1UL << FMC_BCR2_WAITCFG_Pos)	/*!< 0x00000800 */
#define FMC_BCR2_WAITCFG          FMC_BCR2_WAITCFG_Msk				/*!<Wait timing configuration  */
#define FMC_BCR2_WREN_Pos         (12U)
#define FMC_BCR2_WREN_Msk         (0x1UL << FMC_BCR2_WREN_Pos)	/*!< 0x00001000 */
#define FMC_BCR2_WREN             FMC_BCR2_WREN_Msk				/*!<Write enable bit           */
#define FMC_BCR2_WAITEN_Pos       (13U)
#define FMC_BCR2_WAITEN_Msk       (0x1UL << FMC_BCR2_WAITEN_Pos)/*!< 0x00002000 */
#define FMC_BCR2_WAITEN           FMC_BCR2_WAITEN_Msk	/*!<Wait enable bit            */
#define FMC_BCR2_EXTMOD_Pos       (14U)
#define FMC_BCR2_EXTMOD_Msk       (0x1UL << FMC_BCR2_EXTMOD_Pos)/*!< 0x00004000 */
#define FMC_BCR2_EXTMOD           FMC_BCR2_EXTMOD_Msk	/*!<Extended mode enable       */
#define FMC_BCR2_ASYNCWAIT_Pos    (15U)
#define FMC_BCR2_ASYNCWAIT_Msk    (0x1UL << FMC_BCR2_ASYNCWAIT_Pos)	/*!< 0x00008000 */
#define FMC_BCR2_ASYNCWAIT        FMC_BCR2_ASYNCWAIT_Msk/*!<Asynchronous wait          */
#define FMC_BCR2_CPSIZE_Pos       (16U)
#define FMC_BCR2_CPSIZE_Msk       (0x7UL << FMC_BCR2_CPSIZE_Pos)/*!< 0x00070000 */
#define FMC_BCR2_CPSIZE           FMC_BCR2_CPSIZE_Msk	/*!<CRAM page size             */
#define FMC_BCR2_CPSIZE_0         (0x1UL << FMC_BCR2_CPSIZE_Pos)/*!< 0x00010000 */
#define FMC_BCR2_CPSIZE_1         (0x2UL << FMC_BCR2_CPSIZE_Pos)/*!< 0x00020000 */
#define FMC_BCR2_CPSIZE_2         (0x4UL << FMC_BCR2_CPSIZE_Pos)/*!< 0x00040000 */
#define FMC_BCR2_CBURSTRW_Pos     (19U)
#define FMC_BCR2_CBURSTRW_Msk     (0x1UL << FMC_BCR2_CBURSTRW_Pos)	/*!< 0x00080000 */
#define FMC_BCR2_CBURSTRW         FMC_BCR2_CBURSTRW_Msk				/*!<Write burst enable         */

/******************  Bit definition for FMC_BCR3 register  *******************/
#define FMC_BCR3_MBKEN_Pos        (0U)
#define FMC_BCR3_MBKEN_Msk        (0x1UL << FMC_BCR3_MBKEN_Pos)	/*!< 0x00000001 */
#define FMC_BCR3_MBKEN            FMC_BCR3_MBKEN_Msk/*!<Memory bank enable bit                 */
#define FMC_BCR3_MUXEN_Pos        (1U)
#define FMC_BCR3_MUXEN_Msk        (0x1UL << FMC_BCR3_MUXEN_Pos)	/*!< 0x00000002 */
#define FMC_BCR3_MUXEN            FMC_BCR3_MUXEN_Msk/*!<Address/data multiplexing enable bit   */
#define FMC_BCR3_MTYP_Pos         (2U)
#define FMC_BCR3_MTYP_Msk         (0x3UL << FMC_BCR3_MTYP_Pos)	/*!< 0x0000000C */
#define FMC_BCR3_MTYP             FMC_BCR3_MTYP_Msk				/*!<MTYP[1:0] bits (Memory type)           */
#define FMC_BCR3_MTYP_0           (0x1UL << FMC_BCR3_MTYP_Pos)	/*!< 0x00000004 */
#define FMC_BCR3_MTYP_1           (0x2UL << FMC_BCR3_MTYP_Pos)	/*!< 0x00000008 */
#define FMC_BCR3_MWID_Pos         (4U)
#define FMC_BCR3_MWID_Msk         (0x3UL << FMC_BCR3_MWID_Pos)	/*!< 0x00000030 */
#define FMC_BCR3_MWID             FMC_BCR3_MWID_Msk				/*!<MWID[1:0] bits (Memory data bus width) */
#define FMC_BCR3_MWID_0           (0x1UL << FMC_BCR3_MWID_Pos)	/*!< 0x00000010 */
#define FMC_BCR3_MWID_1           (0x2UL << FMC_BCR3_MWID_Pos)	/*!< 0x00000020 */
#define FMC_BCR3_FACCEN_Pos       (6U)
#define FMC_BCR3_FACCEN_Msk       (0x1UL << FMC_BCR3_FACCEN_Pos)/*!< 0x00000040 */
#define FMC_BCR3_FACCEN           FMC_BCR3_FACCEN_Msk	/*!<Flash access enable        */
#define FMC_BCR3_BURSTEN_Pos      (8U)
#define FMC_BCR3_BURSTEN_Msk      (0x1UL << FMC_BCR3_BURSTEN_Pos)	/*!< 0x00000100 */
#define FMC_BCR3_BURSTEN          FMC_BCR3_BURSTEN_Msk				/*!<Burst enable bit           */
#define FMC_BCR3_WAITPOL_Pos      (9U)
#define FMC_BCR3_WAITPOL_Msk      (0x1UL << FMC_BCR3_WAITPOL_Pos)	/*!< 0x00000200 */
#define FMC_BCR3_WAITPOL          FMC_BCR3_WAITPOL_Msk				/*!<Wait signal polarity bit   */
#define FMC_BCR3_WRAPMOD_Pos      (10U)
#define FMC_BCR3_WRAPMOD_Msk      (0x1UL << FMC_BCR3_WRAPMOD_Pos)	/*!< 0x00000400 */
#define FMC_BCR3_WRAPMOD          FMC_BCR3_WRAPMOD_Msk				/*!<Wrapped burst mode support */
#define FMC_BCR3_WAITCFG_Pos      (11U)
#define FMC_BCR3_WAITCFG_Msk      (0x1UL << FMC_BCR3_WAITCFG_Pos)	/*!< 0x00000800 */
#define FMC_BCR3_WAITCFG          FMC_BCR3_WAITCFG_Msk				/*!<Wait timing configuration  */
#define FMC_BCR3_WREN_Pos         (12U)
#define FMC_BCR3_WREN_Msk         (0x1UL << FMC_BCR3_WREN_Pos)	/*!< 0x00001000 */
#define FMC_BCR3_WREN             FMC_BCR3_WREN_Msk				/*!<Write enable bit           */
#define FMC_BCR3_WAITEN_Pos       (13U)
#define FMC_BCR3_WAITEN_Msk       (0x1UL << FMC_BCR3_WAITEN_Pos)/*!< 0x00002000 */
#define FMC_BCR3_WAITEN           FMC_BCR3_WAITEN_Msk	/*!<Wait enable bit            */
#define FMC_BCR3_EXTMOD_Pos       (14U)
#define FMC_BCR3_EXTMOD_Msk       (0x1UL << FMC_BCR3_EXTMOD_Pos)/*!< 0x00004000 */
#define FMC_BCR3_EXTMOD           FMC_BCR3_EXTMOD_Msk	/*!<Extended mode enable       */
#define FMC_BCR3_ASYNCWAIT_Pos    (15U)
#define FMC_BCR3_ASYNCWAIT_Msk    (0x1UL << FMC_BCR3_ASYNCWAIT_Pos)	/*!< 0x00008000 */
#define FMC_BCR3_ASYNCWAIT        FMC_BCR3_ASYNCWAIT_Msk/*!<Asynchronous wait          */
#define FMC_BCR3_CPSIZE_Pos       (16U)
#define FMC_BCR3_CPSIZE_Msk       (0x7UL << FMC_BCR3_CPSIZE_Pos)/*!< 0x00070000 */
#define FMC_BCR3_CPSIZE           FMC_BCR3_CPSIZE_Msk	/*!<CRAM page size             */
#define FMC_BCR3_CPSIZE_0         (0x1UL << FMC_BCR3_CPSIZE_Pos)/*!< 0x00010000 */
#define FMC_BCR3_CPSIZE_1         (0x2UL << FMC_BCR3_CPSIZE_Pos)/*!< 0x00020000 */
#define FMC_BCR3_CPSIZE_2         (0x4UL << FMC_BCR3_CPSIZE_Pos)/*!< 0x00040000 */
#define FMC_BCR3_CBURSTRW_Pos     (19U)
#define FMC_BCR3_CBURSTRW_Msk     (0x1UL << FMC_BCR3_CBURSTRW_Pos)	/*!< 0x00080000 */
#define FMC_BCR3_CBURSTRW         FMC_BCR3_CBURSTRW_Msk				/*!<Write burst enable         */

/******************  Bit definition for FMC_BCR4 register  *******************/
#define FMC_BCR4_MBKEN_Pos        (0U)
#define FMC_BCR4_MBKEN_Msk        (0x1UL << FMC_BCR4_MBKEN_Pos)	/*!< 0x00000001 */
#define FMC_BCR4_MBKEN            FMC_BCR4_MBKEN_Msk/*!<Memory bank enable bit                 */
#define FMC_BCR4_MUXEN_Pos        (1U)
#define FMC_BCR4_MUXEN_Msk        (0x1UL << FMC_BCR4_MUXEN_Pos)	/*!< 0x00000002 */
#define FMC_BCR4_MUXEN            FMC_BCR4_MUXEN_Msk/*!<Address/data multiplexing enable bit   */
#define FMC_BCR4_MTYP_Pos         (2U)
#define FMC_BCR4_MTYP_Msk         (0x3UL << FMC_BCR4_MTYP_Pos)	/*!< 0x0000000C */
#define FMC_BCR4_MTYP             FMC_BCR4_MTYP_Msk				/*!<MTYP[1:0] bits (Memory type)           */
#define FMC_BCR4_MTYP_0           (0x1UL << FMC_BCR4_MTYP_Pos)	/*!< 0x00000004 */
#define FMC_BCR4_MTYP_1           (0x2UL << FMC_BCR4_MTYP_Pos)	/*!< 0x00000008 */
#define FMC_BCR4_MWID_Pos         (4U)
#define FMC_BCR4_MWID_Msk         (0x3UL << FMC_BCR4_MWID_Pos)	/*!< 0x00000030 */
#define FMC_BCR4_MWID             FMC_BCR4_MWID_Msk				/*!<MWID[1:0] bits (Memory data bus width) */
#define FMC_BCR4_MWID_0           (0x1UL << FMC_BCR4_MWID_Pos)	/*!< 0x00000010 */
#define FMC_BCR4_MWID_1           (0x2UL << FMC_BCR4_MWID_Pos)	/*!< 0x00000020 */
#define FMC_BCR4_FACCEN_Pos       (6U)
#define FMC_BCR4_FACCEN_Msk       (0x1UL << FMC_BCR4_FACCEN_Pos)/*!< 0x00000040 */
#define FMC_BCR4_FACCEN           FMC_BCR4_FACCEN_Msk	/*!<Flash access enable        */
#define FMC_BCR4_BURSTEN_Pos      (8U)
#define FMC_BCR4_BURSTEN_Msk      (0x1UL << FMC_BCR4_BURSTEN_Pos)	/*!< 0x00000100 */
#define FMC_BCR4_BURSTEN          FMC_BCR4_BURSTEN_Msk				/*!<Burst enable bit           */
#define FMC_BCR4_WAITPOL_Pos      (9U)
#define FMC_BCR4_WAITPOL_Msk      (0x1UL << FMC_BCR4_WAITPOL_Pos)	/*!< 0x00000200 */
#define FMC_BCR4_WAITPOL          FMC_BCR4_WAITPOL_Msk				/*!<Wait signal polarity bit   */
#define FMC_BCR4_WRAPMOD_Pos      (10U)
#define FMC_BCR4_WRAPMOD_Msk      (0x1UL << FMC_BCR4_WRAPMOD_Pos)	/*!< 0x00000400 */
#define FMC_BCR4_WRAPMOD          FMC_BCR4_WRAPMOD_Msk				/*!<Wrapped burst mode support */
#define FMC_BCR4_WAITCFG_Pos      (11U)
#define FMC_BCR4_WAITCFG_Msk      (0x1UL << FMC_BCR4_WAITCFG_Pos)	/*!< 0x00000800 */
#define FMC_BCR4_WAITCFG          FMC_BCR4_WAITCFG_Msk				/*!<Wait timing configuration  */
#define FMC_BCR4_WREN_Pos         (12U)
#define FMC_BCR4_WREN_Msk         (0x1UL << FMC_BCR4_WREN_Pos)	/*!< 0x00001000 */
#define FMC_BCR4_WREN             FMC_BCR4_WREN_Msk				/*!<Write enable bit           */
#define FMC_BCR4_WAITEN_Pos       (13U)
#define FMC_BCR4_WAITEN_Msk       (0x1UL << FMC_BCR4_WAITEN_Pos)/*!< 0x00002000 */
#define FMC_BCR4_WAITEN           FMC_BCR4_WAITEN_Msk	/*!<Wait enable bit            */
#define FMC_BCR4_EXTMOD_Pos       (14U)
#define FMC_BCR4_EXTMOD_Msk       (0x1UL << FMC_BCR4_EXTMOD_Pos)/*!< 0x00004000 */
#define FMC_BCR4_EXTMOD           FMC_BCR4_EXTMOD_Msk	/*!<Extended mode enable       */
#define FMC_BCR4_ASYNCWAIT_Pos    (15U)
#define FMC_BCR4_ASYNCWAIT_Msk    (0x1UL << FMC_BCR4_ASYNCWAIT_Pos)	/*!< 0x00008000 */
#define FMC_BCR4_ASYNCWAIT        FMC_BCR4_ASYNCWAIT_Msk/*!<Asynchronous wait          */
#define FMC_BCR4_CPSIZE_Pos       (16U)
#define FMC_BCR4_CPSIZE_Msk       (0x7UL << FMC_BCR4_CPSIZE_Pos)/*!< 0x00070000 */
#define FMC_BCR4_CPSIZE           FMC_BCR4_CPSIZE_Msk	/*!<CRAM page size             */
#define FMC_BCR4_CPSIZE_0         (0x1UL << FMC_BCR4_CPSIZE_Pos)/*!< 0x00010000 */
#define FMC_BCR4_CPSIZE_1         (0x2UL << FMC_BCR4_CPSIZE_Pos)/*!< 0x00020000 */
#define FMC_BCR4_CPSIZE_2         (0x4UL << FMC_BCR4_CPSIZE_Pos)/*!< 0x00040000 */
#define FMC_BCR4_CBURSTRW_Pos     (19U)
#define FMC_BCR4_CBURSTRW_Msk     (0x1UL << FMC_BCR4_CBURSTRW_Pos)	/*!< 0x00080000 */
#define FMC_BCR4_CBURSTRW         FMC_BCR4_CBURSTRW_Msk				/*!<Write burst enable         */

/******************  Bit definition for FMC_BTR1 register  ******************/
#define FMC_BTR1_ADDSET_Pos     (0U)
#define FMC_BTR1_ADDSET_Msk     (0xFUL << FMC_BTR1_ADDSET_Pos)	/*!< 0x0000000F */
#define FMC_BTR1_ADDSET         FMC_BTR1_ADDSET_Msk				/*!<ADDSET[3:0] bits (Address setup phase duration) */
#define FMC_BTR1_ADDSET_0       (0x1UL << FMC_BTR1_ADDSET_Pos)	/*!< 0x00000001 */
#define FMC_BTR1_ADDSET_1       (0x2UL << FMC_BTR1_ADDSET_Pos)	/*!< 0x00000002 */
#define FMC_BTR1_ADDSET_2       (0x4UL << FMC_BTR1_ADDSET_Pos)	/*!< 0x00000004 */
#define FMC_BTR1_ADDSET_3       (0x8UL << FMC_BTR1_ADDSET_Pos)	/*!< 0x00000008 */
#define FMC_BTR1_ADDHLD_Pos     (4U)
#define FMC_BTR1_ADDHLD_Msk     (0xFUL << FMC_BTR1_ADDHLD_Pos)	/*!< 0x000000F0 */
#define FMC_BTR1_ADDHLD         FMC_BTR1_ADDHLD_Msk				/*!<ADDHLD[3:0] bits (Address-hold phase duration)  */
#define FMC_BTR1_ADDHLD_0       (0x1UL << FMC_BTR1_ADDHLD_Pos)	/*!< 0x00000010 */
#define FMC_BTR1_ADDHLD_1       (0x2UL << FMC_BTR1_ADDHLD_Pos)	/*!< 0x00000020 */
#define FMC_BTR1_ADDHLD_2       (0x4UL << FMC_BTR1_ADDHLD_Pos)	/*!< 0x00000040 */
#define FMC_BTR1_ADDHLD_3       (0x8UL << FMC_BTR1_ADDHLD_Pos)	/*!< 0x00000080 */
#define FMC_BTR1_DATAST_Pos     (8U)
#define FMC_BTR1_DATAST_Msk     (0xFFUL << FMC_BTR1_DATAST_Pos)	/*!< 0x0000FF00 */
#define FMC_BTR1_DATAST         FMC_BTR1_DATAST_Msk				/*!<DATAST [3:0] bits (Data-phase duration) */
#define FMC_BTR1_DATAST_0       (0x01UL << FMC_BTR1_DATAST_Pos)	/*!< 0x00000100 */
#define FMC_BTR1_DATAST_1       (0x02UL << FMC_BTR1_DATAST_Pos)	/*!< 0x00000200 */
#define FMC_BTR1_DATAST_2       (0x04UL << FMC_BTR1_DATAST_Pos)	/*!< 0x00000400 */
#define FMC_BTR1_DATAST_3       (0x08UL << FMC_BTR1_DATAST_Pos)	/*!< 0x00000800 */
#define FMC_BTR1_DATAST_4       (0x10UL << FMC_BTR1_DATAST_Pos)	/*!< 0x00001000 */
#define FMC_BTR1_DATAST_5       (0x20UL << FMC_BTR1_DATAST_Pos)	/*!< 0x00002000 */
#define FMC_BTR1_DATAST_6       (0x40UL << FMC_BTR1_DATAST_Pos)	/*!< 0x00004000 */
#define FMC_BTR1_DATAST_7       (0x80UL << FMC_BTR1_DATAST_Pos)	/*!< 0x00008000 */
#define FMC_BTR1_BUSTURN_Pos    (16U)
#define FMC_BTR1_BUSTURN_Msk    (0xFUL << FMC_BTR1_BUSTURN_Pos)	/*!< 0x000F0000 */
#define FMC_BTR1_BUSTURN        FMC_BTR1_BUSTURN_Msk/*!<BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define FMC_BTR1_BUSTURN_0      (0x1UL << FMC_BTR1_BUSTURN_Pos)	/*!< 0x00010000 */
#define FMC_BTR1_BUSTURN_1      (0x2UL << FMC_BTR1_BUSTURN_Pos)	/*!< 0x00020000 */
#define FMC_BTR1_BUSTURN_2      (0x4UL << FMC_BTR1_BUSTURN_Pos)	/*!< 0x00040000 */
#define FMC_BTR1_BUSTURN_3      (0x8UL << FMC_BTR1_BUSTURN_Pos)	/*!< 0x00080000 */
#define FMC_BTR1_CLKDIV_Pos     (20U)
#define FMC_BTR1_CLKDIV_Msk     (0xFUL << FMC_BTR1_CLKDIV_Pos)	/*!< 0x00F00000 */
#define FMC_BTR1_CLKDIV         FMC_BTR1_CLKDIV_Msk				/*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define FMC_BTR1_CLKDIV_0       (0x1UL << FMC_BTR1_CLKDIV_Pos)	/*!< 0x00100000 */
#define FMC_BTR1_CLKDIV_1       (0x2UL << FMC_BTR1_CLKDIV_Pos)	/*!< 0x00200000 */
#define FMC_BTR1_CLKDIV_2       (0x4UL << FMC_BTR1_CLKDIV_Pos)	/*!< 0x00400000 */
#define FMC_BTR1_CLKDIV_3       (0x8UL << FMC_BTR1_CLKDIV_Pos)	/*!< 0x00800000 */
#define FMC_BTR1_DATLAT_Pos     (24U)
#define FMC_BTR1_DATLAT_Msk     (0xFUL << FMC_BTR1_DATLAT_Pos)	/*!< 0x0F000000 */
#define FMC_BTR1_DATLAT         FMC_BTR1_DATLAT_Msk				/*!<DATLA[3:0] bits (Data latency) */
#define FMC_BTR1_DATLAT_0       (0x1UL << FMC_BTR1_DATLAT_Pos)	/*!< 0x01000000 */
#define FMC_BTR1_DATLAT_1       (0x2UL << FMC_BTR1_DATLAT_Pos)	/*!< 0x02000000 */
#define FMC_BTR1_DATLAT_2       (0x4UL << FMC_BTR1_DATLAT_Pos)	/*!< 0x04000000 */
#define FMC_BTR1_DATLAT_3       (0x8UL << FMC_BTR1_DATLAT_Pos)	/*!< 0x08000000 */
#define FMC_BTR1_ACCMOD_Pos     (28U)
#define FMC_BTR1_ACCMOD_Msk     (0x3UL << FMC_BTR1_ACCMOD_Pos)	/*!< 0x30000000 */
#define FMC_BTR1_ACCMOD         FMC_BTR1_ACCMOD_Msk				/*!<ACCMOD[1:0] bits (Access mode) */
#define FMC_BTR1_ACCMOD_0       (0x1UL << FMC_BTR1_ACCMOD_Pos)	/*!< 0x10000000 */
#define FMC_BTR1_ACCMOD_1       (0x2UL << FMC_BTR1_ACCMOD_Pos)	/*!< 0x20000000 */

/******************  Bit definition for FMC_BTR2 register  *******************/
#define FMC_BTR2_ADDSET_Pos     (0U)
#define FMC_BTR2_ADDSET_Msk     (0xFUL << FMC_BTR2_ADDSET_Pos)	/*!< 0x0000000F */
#define FMC_BTR2_ADDSET         FMC_BTR2_ADDSET_Msk				/*!<ADDSET[3:0] bits (Address setup phase duration) */
#define FMC_BTR2_ADDSET_0       (0x1UL << FMC_BTR2_ADDSET_Pos)	/*!< 0x00000001 */
#define FMC_BTR2_ADDSET_1       (0x2UL << FMC_BTR2_ADDSET_Pos)	/*!< 0x00000002 */
#define FMC_BTR2_ADDSET_2       (0x4UL << FMC_BTR2_ADDSET_Pos)	/*!< 0x00000004 */
#define FMC_BTR2_ADDSET_3       (0x8UL << FMC_BTR2_ADDSET_Pos)	/*!< 0x00000008 */
#define FMC_BTR2_ADDHLD_Pos     (4U)
#define FMC_BTR2_ADDHLD_Msk     (0xFUL << FMC_BTR2_ADDHLD_Pos)	/*!< 0x000000F0 */
#define FMC_BTR2_ADDHLD         FMC_BTR2_ADDHLD_Msk				/*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define FMC_BTR2_ADDHLD_0       (0x1UL << FMC_BTR2_ADDHLD_Pos)	/*!< 0x00000010 */
#define FMC_BTR2_ADDHLD_1       (0x2UL << FMC_BTR2_ADDHLD_Pos)	/*!< 0x00000020 */
#define FMC_BTR2_ADDHLD_2       (0x4UL << FMC_BTR2_ADDHLD_Pos)	/*!< 0x00000040 */
#define FMC_BTR2_ADDHLD_3       (0x8UL << FMC_BTR2_ADDHLD_Pos)	/*!< 0x00000080 */
#define FMC_BTR2_DATAST_Pos     (8U)
#define FMC_BTR2_DATAST_Msk     (0xFFUL << FMC_BTR2_DATAST_Pos)	/*!< 0x0000FF00 */
#define FMC_BTR2_DATAST         FMC_BTR2_DATAST_Msk				/*!<DATAST [3:0] bits (Data-phase duration) */
#define FMC_BTR2_DATAST_0       (0x01UL << FMC_BTR2_DATAST_Pos)	/*!< 0x00000100 */
#define FMC_BTR2_DATAST_1       (0x02UL << FMC_BTR2_DATAST_Pos)	/*!< 0x00000200 */
#define FMC_BTR2_DATAST_2       (0x04UL << FMC_BTR2_DATAST_Pos)	/*!< 0x00000400 */
#define FMC_BTR2_DATAST_3       (0x08UL << FMC_BTR2_DATAST_Pos)	/*!< 0x00000800 */
#define FMC_BTR2_DATAST_4       (0x10UL << FMC_BTR2_DATAST_Pos)	/*!< 0x00001000 */
#define FMC_BTR2_DATAST_5       (0x20UL << FMC_BTR2_DATAST_Pos)	/*!< 0x00002000 */
#define FMC_BTR2_DATAST_6       (0x40UL << FMC_BTR2_DATAST_Pos)	/*!< 0x00004000 */
#define FMC_BTR2_DATAST_7       (0x80UL << FMC_BTR2_DATAST_Pos)	/*!< 0x00008000 */
#define FMC_BTR2_BUSTURN_Pos    (16U)
#define FMC_BTR2_BUSTURN_Msk    (0xFUL << FMC_BTR2_BUSTURN_Pos)	/*!< 0x000F0000 */
#define FMC_BTR2_BUSTURN        FMC_BTR2_BUSTURN_Msk/*!<BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define FMC_BTR2_BUSTURN_0      (0x1UL << FMC_BTR2_BUSTURN_Pos)	/*!< 0x00010000 */
#define FMC_BTR2_BUSTURN_1      (0x2UL << FMC_BTR2_BUSTURN_Pos)	/*!< 0x00020000 */
#define FMC_BTR2_BUSTURN_2      (0x4UL << FMC_BTR2_BUSTURN_Pos)	/*!< 0x00040000 */
#define FMC_BTR2_BUSTURN_3      (0x8UL << FMC_BTR2_BUSTURN_Pos)	/*!< 0x00080000 */
#define FMC_BTR2_CLKDIV_Pos     (20U)
#define FMC_BTR2_CLKDIV_Msk     (0xFUL << FMC_BTR2_CLKDIV_Pos)	/*!< 0x00F00000 */
#define FMC_BTR2_CLKDIV         FMC_BTR2_CLKDIV_Msk				/*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define FMC_BTR2_CLKDIV_0       (0x1UL << FMC_BTR2_CLKDIV_Pos)	/*!< 0x00100000 */
#define FMC_BTR2_CLKDIV_1       (0x2UL << FMC_BTR2_CLKDIV_Pos)	/*!< 0x00200000 */
#define FMC_BTR2_CLKDIV_2       (0x4UL << FMC_BTR2_CLKDIV_Pos)	/*!< 0x00400000 */
#define FMC_BTR2_CLKDIV_3       (0x8UL << FMC_BTR2_CLKDIV_Pos)	/*!< 0x00800000 */
#define FMC_BTR2_DATLAT_Pos     (24U)
#define FMC_BTR2_DATLAT_Msk     (0xFUL << FMC_BTR2_DATLAT_Pos)	/*!< 0x0F000000 */
#define FMC_BTR2_DATLAT         FMC_BTR2_DATLAT_Msk				/*!<DATLA[3:0] bits (Data latency) */
#define FMC_BTR2_DATLAT_0       (0x1UL << FMC_BTR2_DATLAT_Pos)	/*!< 0x01000000 */
#define FMC_BTR2_DATLAT_1       (0x2UL << FMC_BTR2_DATLAT_Pos)	/*!< 0x02000000 */
#define FMC_BTR2_DATLAT_2       (0x4UL << FMC_BTR2_DATLAT_Pos)	/*!< 0x04000000 */
#define FMC_BTR2_DATLAT_3       (0x8UL << FMC_BTR2_DATLAT_Pos)	/*!< 0x08000000 */
#define FMC_BTR2_ACCMOD_Pos     (28U)
#define FMC_BTR2_ACCMOD_Msk     (0x3UL << FMC_BTR2_ACCMOD_Pos)	/*!< 0x30000000 */
#define FMC_BTR2_ACCMOD         FMC_BTR2_ACCMOD_Msk				/*!<ACCMOD[1:0] bits (Access mode) */
#define FMC_BTR2_ACCMOD_0       (0x1UL << FMC_BTR2_ACCMOD_Pos)	/*!< 0x10000000 */
#define FMC_BTR2_ACCMOD_1       (0x2UL << FMC_BTR2_ACCMOD_Pos)	/*!< 0x20000000 */

/*******************  Bit definition for FMC_BTR3 register  *******************/
#define FMC_BTR3_ADDSET_Pos     (0U)
#define FMC_BTR3_ADDSET_Msk     (0xFUL << FMC_BTR3_ADDSET_Pos)	/*!< 0x0000000F */
#define FMC_BTR3_ADDSET         FMC_BTR3_ADDSET_Msk				/*!<ADDSET[3:0] bits (Address setup phase duration) */
#define FMC_BTR3_ADDSET_0       (0x1UL << FMC_BTR3_ADDSET_Pos)	/*!< 0x00000001 */
#define FMC_BTR3_ADDSET_1       (0x2UL << FMC_BTR3_ADDSET_Pos)	/*!< 0x00000002 */
#define FMC_BTR3_ADDSET_2       (0x4UL << FMC_BTR3_ADDSET_Pos)	/*!< 0x00000004 */
#define FMC_BTR3_ADDSET_3       (0x8UL << FMC_BTR3_ADDSET_Pos)	/*!< 0x00000008 */
#define FMC_BTR3_ADDHLD_Pos     (4U)
#define FMC_BTR3_ADDHLD_Msk     (0xFUL << FMC_BTR3_ADDHLD_Pos)	/*!< 0x000000F0 */
#define FMC_BTR3_ADDHLD         FMC_BTR3_ADDHLD_Msk				/*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define FMC_BTR3_ADDHLD_0       (0x1UL << FMC_BTR3_ADDHLD_Pos)	/*!< 0x00000010 */
#define FMC_BTR3_ADDHLD_1       (0x2UL << FMC_BTR3_ADDHLD_Pos)	/*!< 0x00000020 */
#define FMC_BTR3_ADDHLD_2       (0x4UL << FMC_BTR3_ADDHLD_Pos)	/*!< 0x00000040 */
#define FMC_BTR3_ADDHLD_3       (0x8UL << FMC_BTR3_ADDHLD_Pos)	/*!< 0x00000080 */
#define FMC_BTR3_DATAST_Pos     (8U)
#define FMC_BTR3_DATAST_Msk     (0xFFUL << FMC_BTR3_DATAST_Pos)	/*!< 0x0000FF00 */
#define FMC_BTR3_DATAST         FMC_BTR3_DATAST_Msk				/*!<DATAST [3:0] bits (Data-phase duration) */
#define FMC_BTR3_DATAST_0       (0x01UL << FMC_BTR3_DATAST_Pos)	/*!< 0x00000100 */
#define FMC_BTR3_DATAST_1       (0x02UL << FMC_BTR3_DATAST_Pos)	/*!< 0x00000200 */
#define FMC_BTR3_DATAST_2       (0x04UL << FMC_BTR3_DATAST_Pos)	/*!< 0x00000400 */
#define FMC_BTR3_DATAST_3       (0x08UL << FMC_BTR3_DATAST_Pos)	/*!< 0x00000800 */
#define FMC_BTR3_DATAST_4       (0x10UL << FMC_BTR3_DATAST_Pos)	/*!< 0x00001000 */
#define FMC_BTR3_DATAST_5       (0x20UL << FMC_BTR3_DATAST_Pos)	/*!< 0x00002000 */
#define FMC_BTR3_DATAST_6       (0x40UL << FMC_BTR3_DATAST_Pos)	/*!< 0x00004000 */
#define FMC_BTR3_DATAST_7       (0x80UL << FMC_BTR3_DATAST_Pos)	/*!< 0x00008000 */
#define FMC_BTR3_BUSTURN_Pos    (16U)
#define FMC_BTR3_BUSTURN_Msk    (0xFUL << FMC_BTR3_BUSTURN_Pos)	/*!< 0x000F0000 */
#define FMC_BTR3_BUSTURN        FMC_BTR3_BUSTURN_Msk/*!<BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define FMC_BTR3_BUSTURN_0      (0x1UL << FMC_BTR3_BUSTURN_Pos)	/*!< 0x00010000 */
#define FMC_BTR3_BUSTURN_1      (0x2UL << FMC_BTR3_BUSTURN_Pos)	/*!< 0x00020000 */
#define FMC_BTR3_BUSTURN_2      (0x4UL << FMC_BTR3_BUSTURN_Pos)	/*!< 0x00040000 */
#define FMC_BTR3_BUSTURN_3      (0x8UL << FMC_BTR3_BUSTURN_Pos)	/*!< 0x00080000 */
#define FMC_BTR3_CLKDIV_Pos     (20U)
#define FMC_BTR3_CLKDIV_Msk     (0xFUL << FMC_BTR3_CLKDIV_Pos)	/*!< 0x00F00000 */
#define FMC_BTR3_CLKDIV         FMC_BTR3_CLKDIV_Msk				/*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define FMC_BTR3_CLKDIV_0       (0x1UL << FMC_BTR3_CLKDIV_Pos)	/*!< 0x00100000 */
#define FMC_BTR3_CLKDIV_1       (0x2UL << FMC_BTR3_CLKDIV_Pos)	/*!< 0x00200000 */
#define FMC_BTR3_CLKDIV_2       (0x4UL << FMC_BTR3_CLKDIV_Pos)	/*!< 0x00400000 */
#define FMC_BTR3_CLKDIV_3       (0x8UL << FMC_BTR3_CLKDIV_Pos)	/*!< 0x00800000 */
#define FMC_BTR3_DATLAT_Pos     (24U)
#define FMC_BTR3_DATLAT_Msk     (0xFUL << FMC_BTR3_DATLAT_Pos)	/*!< 0x0F000000 */
#define FMC_BTR3_DATLAT         FMC_BTR3_DATLAT_Msk				/*!<DATLA[3:0] bits (Data latency) */
#define FMC_BTR3_DATLAT_0       (0x1UL << FMC_BTR3_DATLAT_Pos)	/*!< 0x01000000 */
#define FMC_BTR3_DATLAT_1       (0x2UL << FMC_BTR3_DATLAT_Pos)	/*!< 0x02000000 */
#define FMC_BTR3_DATLAT_2       (0x4UL << FMC_BTR3_DATLAT_Pos)	/*!< 0x04000000 */
#define FMC_BTR3_DATLAT_3       (0x8UL << FMC_BTR3_DATLAT_Pos)	/*!< 0x08000000 */
#define FMC_BTR3_ACCMOD_Pos     (28U)
#define FMC_BTR3_ACCMOD_Msk     (0x3UL << FMC_BTR3_ACCMOD_Pos)	/*!< 0x30000000 */
#define FMC_BTR3_ACCMOD         FMC_BTR3_ACCMOD_Msk				/*!<ACCMOD[1:0] bits (Access mode) */
#define FMC_BTR3_ACCMOD_0       (0x1UL << FMC_BTR3_ACCMOD_Pos)	/*!< 0x10000000 */
#define FMC_BTR3_ACCMOD_1       (0x2UL << FMC_BTR3_ACCMOD_Pos)	/*!< 0x20000000 */

/******************  Bit definition for FMC_BTR4 register  *******************/
#define FMC_BTR4_ADDSET_Pos     (0U)
#define FMC_BTR4_ADDSET_Msk     (0xFUL << FMC_BTR4_ADDSET_Pos)	/*!< 0x0000000F */
#define FMC_BTR4_ADDSET         FMC_BTR4_ADDSET_Msk				/*!<ADDSET[3:0] bits (Address setup phase duration) */
#define FMC_BTR4_ADDSET_0       (0x1UL << FMC_BTR4_ADDSET_Pos)	/*!< 0x00000001 */
#define FMC_BTR4_ADDSET_1       (0x2UL << FMC_BTR4_ADDSET_Pos)	/*!< 0x00000002 */
#define FMC_BTR4_ADDSET_2       (0x4UL << FMC_BTR4_ADDSET_Pos)	/*!< 0x00000004 */
#define FMC_BTR4_ADDSET_3       (0x8UL << FMC_BTR4_ADDSET_Pos)	/*!< 0x00000008 */
#define FMC_BTR4_ADDHLD_Pos     (4U)
#define FMC_BTR4_ADDHLD_Msk     (0xFUL << FMC_BTR4_ADDHLD_Pos)	/*!< 0x000000F0 */
#define FMC_BTR4_ADDHLD         FMC_BTR4_ADDHLD_Msk				/*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define FMC_BTR4_ADDHLD_0       (0x1UL << FMC_BTR4_ADDHLD_Pos)	/*!< 0x00000010 */
#define FMC_BTR4_ADDHLD_1       (0x2UL << FMC_BTR4_ADDHLD_Pos)	/*!< 0x00000020 */
#define FMC_BTR4_ADDHLD_2       (0x4UL << FMC_BTR4_ADDHLD_Pos)	/*!< 0x00000040 */
#define FMC_BTR4_ADDHLD_3       (0x8UL << FMC_BTR4_ADDHLD_Pos)	/*!< 0x00000080 */
#define FMC_BTR4_DATAST_Pos     (8U)
#define FMC_BTR4_DATAST_Msk     (0xFFUL << FMC_BTR4_DATAST_Pos)	/*!< 0x0000FF00 */
#define FMC_BTR4_DATAST         FMC_BTR4_DATAST_Msk				/*!<DATAST [3:0] bits (Data-phase duration) */
#define FMC_BTR4_DATAST_0       (0x01UL << FMC_BTR4_DATAST_Pos)	/*!< 0x00000100 */
#define FMC_BTR4_DATAST_1       (0x02UL << FMC_BTR4_DATAST_Pos)	/*!< 0x00000200 */
#define FMC_BTR4_DATAST_2       (0x04UL << FMC_BTR4_DATAST_Pos)	/*!< 0x00000400 */
#define FMC_BTR4_DATAST_3       (0x08UL << FMC_BTR4_DATAST_Pos)	/*!< 0x00000800 */
#define FMC_BTR4_DATAST_4       (0x10UL << FMC_BTR4_DATAST_Pos)	/*!< 0x00001000 */
#define FMC_BTR4_DATAST_5       (0x20UL << FMC_BTR4_DATAST_Pos)	/*!< 0x00002000 */
#define FMC_BTR4_DATAST_6       (0x40UL << FMC_BTR4_DATAST_Pos)	/*!< 0x00004000 */
#define FMC_BTR4_DATAST_7       (0x80UL << FMC_BTR4_DATAST_Pos)	/*!< 0x00008000 */
#define FMC_BTR4_BUSTURN_Pos    (16U)
#define FMC_BTR4_BUSTURN_Msk    (0xFUL << FMC_BTR4_BUSTURN_Pos)	/*!< 0x000F0000 */
#define FMC_BTR4_BUSTURN        FMC_BTR4_BUSTURN_Msk/*!<BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define FMC_BTR4_BUSTURN_0      (0x1UL << FMC_BTR4_BUSTURN_Pos)	/*!< 0x00010000 */
#define FMC_BTR4_BUSTURN_1      (0x2UL << FMC_BTR4_BUSTURN_Pos)	/*!< 0x00020000 */
#define FMC_BTR4_BUSTURN_2      (0x4UL << FMC_BTR4_BUSTURN_Pos)	/*!< 0x00040000 */
#define FMC_BTR4_BUSTURN_3      (0x8UL << FMC_BTR4_BUSTURN_Pos)	/*!< 0x00080000 */
#define FMC_BTR4_CLKDIV_Pos     (20U)
#define FMC_BTR4_CLKDIV_Msk     (0xFUL << FMC_BTR4_CLKDIV_Pos)	/*!< 0x00F00000 */
#define FMC_BTR4_CLKDIV         FMC_BTR4_CLKDIV_Msk				/*!<CLKDIV[3:0] bits (Clock divide ratio) */
#define FMC_BTR4_CLKDIV_0       (0x1UL << FMC_BTR4_CLKDIV_Pos)	/*!< 0x00100000 */
#define FMC_BTR4_CLKDIV_1       (0x2UL << FMC_BTR4_CLKDIV_Pos)	/*!< 0x00200000 */
#define FMC_BTR4_CLKDIV_2       (0x4UL << FMC_BTR4_CLKDIV_Pos)	/*!< 0x00400000 */
#define FMC_BTR4_CLKDIV_3       (0x8UL << FMC_BTR4_CLKDIV_Pos)	/*!< 0x00800000 */
#define FMC_BTR4_DATLAT_Pos     (24U)
#define FMC_BTR4_DATLAT_Msk     (0xFUL << FMC_BTR4_DATLAT_Pos)	/*!< 0x0F000000 */
#define FMC_BTR4_DATLAT         FMC_BTR4_DATLAT_Msk				/*!<DATLA[3:0] bits (Data latency) */
#define FMC_BTR4_DATLAT_0       (0x1UL << FMC_BTR4_DATLAT_Pos)	/*!< 0x01000000 */
#define FMC_BTR4_DATLAT_1       (0x2UL << FMC_BTR4_DATLAT_Pos)	/*!< 0x02000000 */
#define FMC_BTR4_DATLAT_2       (0x4UL << FMC_BTR4_DATLAT_Pos)	/*!< 0x04000000 */
#define FMC_BTR4_DATLAT_3       (0x8UL << FMC_BTR4_DATLAT_Pos)	/*!< 0x08000000 */
#define FMC_BTR4_ACCMOD_Pos     (28U)
#define FMC_BTR4_ACCMOD_Msk     (0x3UL << FMC_BTR4_ACCMOD_Pos)	/*!< 0x30000000 */
#define FMC_BTR4_ACCMOD         FMC_BTR4_ACCMOD_Msk				/*!<ACCMOD[1:0] bits (Access mode) */
#define FMC_BTR4_ACCMOD_0       (0x1UL << FMC_BTR4_ACCMOD_Pos)	/*!< 0x10000000 */
#define FMC_BTR4_ACCMOD_1       (0x2UL << FMC_BTR4_ACCMOD_Pos)	/*!< 0x20000000 */

/******************  Bit definition for FMC_BWTR1 register  ******************/
#define FMC_BWTR1_ADDSET_Pos     (0U)
#define FMC_BWTR1_ADDSET_Msk     (0xFUL << FMC_BWTR1_ADDSET_Pos)/*!< 0x0000000F */
#define FMC_BWTR1_ADDSET         FMC_BWTR1_ADDSET_Msk	/*!<ADDSET[3:0] bits (Address setup phase duration) */
#define FMC_BWTR1_ADDSET_0       (0x1UL << FMC_BWTR1_ADDSET_Pos)/*!< 0x00000001 */
#define FMC_BWTR1_ADDSET_1       (0x2UL << FMC_BWTR1_ADDSET_Pos)/*!< 0x00000002 */
#define FMC_BWTR1_ADDSET_2       (0x4UL << FMC_BWTR1_ADDSET_Pos)/*!< 0x00000004 */
#define FMC_BWTR1_ADDSET_3       (0x8UL << FMC_BWTR1_ADDSET_Pos)/*!< 0x00000008 */
#define FMC_BWTR1_ADDHLD_Pos     (4U)
#define FMC_BWTR1_ADDHLD_Msk     (0xFUL << FMC_BWTR1_ADDHLD_Pos)/*!< 0x000000F0 */
#define FMC_BWTR1_ADDHLD         FMC_BWTR1_ADDHLD_Msk	/*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define FMC_BWTR1_ADDHLD_0       (0x1UL << FMC_BWTR1_ADDHLD_Pos)/*!< 0x00000010 */
#define FMC_BWTR1_ADDHLD_1       (0x2UL << FMC_BWTR1_ADDHLD_Pos)/*!< 0x00000020 */
#define FMC_BWTR1_ADDHLD_2       (0x4UL << FMC_BWTR1_ADDHLD_Pos)/*!< 0x00000040 */
#define FMC_BWTR1_ADDHLD_3       (0x8UL << FMC_BWTR1_ADDHLD_Pos)/*!< 0x00000080 */
#define FMC_BWTR1_DATAST_Pos     (8U)
#define FMC_BWTR1_DATAST_Msk     (0xFFUL << FMC_BWTR1_DATAST_Pos)	/*!< 0x0000FF00 */
#define FMC_BWTR1_DATAST         FMC_BWTR1_DATAST_Msk				/*!<DATAST [3:0] bits (Data-phase duration) */
#define FMC_BWTR1_DATAST_0       (0x01UL << FMC_BWTR1_DATAST_Pos)	/*!< 0x00000100 */
#define FMC_BWTR1_DATAST_1       (0x02UL << FMC_BWTR1_DATAST_Pos)	/*!< 0x00000200 */
#define FMC_BWTR1_DATAST_2       (0x04UL << FMC_BWTR1_DATAST_Pos)	/*!< 0x00000400 */
#define FMC_BWTR1_DATAST_3       (0x08UL << FMC_BWTR1_DATAST_Pos)	/*!< 0x00000800 */
#define FMC_BWTR1_DATAST_4       (0x10UL << FMC_BWTR1_DATAST_Pos)	/*!< 0x00001000 */
#define FMC_BWTR1_DATAST_5       (0x20UL << FMC_BWTR1_DATAST_Pos)	/*!< 0x00002000 */
#define FMC_BWTR1_DATAST_6       (0x40UL << FMC_BWTR1_DATAST_Pos)	/*!< 0x00004000 */
#define FMC_BWTR1_DATAST_7       (0x80UL << FMC_BWTR1_DATAST_Pos)	/*!< 0x00008000 */
#define FMC_BWTR1_BUSTURN_Pos    (16U)
#define FMC_BWTR1_BUSTURN_Msk    (0xFUL << FMC_BWTR1_BUSTURN_Pos)	/*!< 0x000F0000 */
#define FMC_BWTR1_BUSTURN        FMC_BWTR1_BUSTURN_Msk				/*!<BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define FMC_BWTR1_BUSTURN_0      (0x1UL << FMC_BWTR1_BUSTURN_Pos)	/*!< 0x00010000 */
#define FMC_BWTR1_BUSTURN_1      (0x2UL << FMC_BWTR1_BUSTURN_Pos)	/*!< 0x00020000 */
#define FMC_BWTR1_BUSTURN_2      (0x4UL << FMC_BWTR1_BUSTURN_Pos)	/*!< 0x00040000 */
#define FMC_BWTR1_BUSTURN_3      (0x8UL << FMC_BWTR1_BUSTURN_Pos)	/*!< 0x00080000 */
#define FMC_BWTR1_ACCMOD_Pos     (28U)
#define FMC_BWTR1_ACCMOD_Msk     (0x3UL << FMC_BWTR1_ACCMOD_Pos)/*!< 0x30000000 */
#define FMC_BWTR1_ACCMOD         FMC_BWTR1_ACCMOD_Msk	/*!<ACCMOD[1:0] bits (Access mode) */
#define FMC_BWTR1_ACCMOD_0       (0x1UL << FMC_BWTR1_ACCMOD_Pos)/*!< 0x10000000 */
#define FMC_BWTR1_ACCMOD_1       (0x2UL << FMC_BWTR1_ACCMOD_Pos)/*!< 0x20000000 */

/******************  Bit definition for FMC_BWTR2 register  ******************/
#define FMC_BWTR2_ADDSET_Pos     (0U)
#define FMC_BWTR2_ADDSET_Msk     (0xFUL << FMC_BWTR2_ADDSET_Pos)/*!< 0x0000000F */
#define FMC_BWTR2_ADDSET         FMC_BWTR2_ADDSET_Msk	/*!<ADDSET[3:0] bits (Address setup phase duration) */
#define FMC_BWTR2_ADDSET_0       (0x1UL << FMC_BWTR2_ADDSET_Pos)/*!< 0x00000001 */
#define FMC_BWTR2_ADDSET_1       (0x2UL << FMC_BWTR2_ADDSET_Pos)/*!< 0x00000002 */
#define FMC_BWTR2_ADDSET_2       (0x4UL << FMC_BWTR2_ADDSET_Pos)/*!< 0x00000004 */
#define FMC_BWTR2_ADDSET_3       (0x8UL << FMC_BWTR2_ADDSET_Pos)/*!< 0x00000008 */
#define FMC_BWTR2_ADDHLD_Pos     (4U)
#define FMC_BWTR2_ADDHLD_Msk     (0xFUL << FMC_BWTR2_ADDHLD_Pos)/*!< 0x000000F0 */
#define FMC_BWTR2_ADDHLD         FMC_BWTR2_ADDHLD_Msk	/*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define FMC_BWTR2_ADDHLD_0       (0x1UL << FMC_BWTR2_ADDHLD_Pos)/*!< 0x00000010 */
#define FMC_BWTR2_ADDHLD_1       (0x2UL << FMC_BWTR2_ADDHLD_Pos)/*!< 0x00000020 */
#define FMC_BWTR2_ADDHLD_2       (0x4UL << FMC_BWTR2_ADDHLD_Pos)/*!< 0x00000040 */
#define FMC_BWTR2_ADDHLD_3       (0x8UL << FMC_BWTR2_ADDHLD_Pos)/*!< 0x00000080 */
#define FMC_BWTR2_DATAST_Pos     (8U)
#define FMC_BWTR2_DATAST_Msk     (0xFFUL << FMC_BWTR2_DATAST_Pos)	/*!< 0x0000FF00 */
#define FMC_BWTR2_DATAST         FMC_BWTR2_DATAST_Msk				/*!<DATAST [3:0] bits (Data-phase duration) */
#define FMC_BWTR2_DATAST_0       (0x01UL << FMC_BWTR2_DATAST_Pos)	/*!< 0x00000100 */
#define FMC_BWTR2_DATAST_1       (0x02UL << FMC_BWTR2_DATAST_Pos)	/*!< 0x00000200 */
#define FMC_BWTR2_DATAST_2       (0x04UL << FMC_BWTR2_DATAST_Pos)	/*!< 0x00000400 */
#define FMC_BWTR2_DATAST_3       (0x08UL << FMC_BWTR2_DATAST_Pos)	/*!< 0x00000800 */
#define FMC_BWTR2_DATAST_4       (0x10UL << FMC_BWTR2_DATAST_Pos)	/*!< 0x00001000 */
#define FMC_BWTR2_DATAST_5       (0x20UL << FMC_BWTR2_DATAST_Pos)	/*!< 0x00002000 */
#define FMC_BWTR2_DATAST_6       (0x40UL << FMC_BWTR2_DATAST_Pos)	/*!< 0x00004000 */
#define FMC_BWTR2_DATAST_7       (0x80UL << FMC_BWTR2_DATAST_Pos)	/*!< 0x00008000 */
#define FMC_BWTR2_BUSTURN_Pos    (16U)
#define FMC_BWTR2_BUSTURN_Msk    (0xFUL << FMC_BWTR2_BUSTURN_Pos)	/*!< 0x000F0000 */
#define FMC_BWTR2_BUSTURN        FMC_BWTR2_BUSTURN_Msk				/*!<BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define FMC_BWTR2_BUSTURN_0      (0x1UL << FMC_BWTR2_BUSTURN_Pos)	/*!< 0x00010000 */
#define FMC_BWTR2_BUSTURN_1      (0x2UL << FMC_BWTR2_BUSTURN_Pos)	/*!< 0x00020000 */
#define FMC_BWTR2_BUSTURN_2      (0x4UL << FMC_BWTR2_BUSTURN_Pos)	/*!< 0x00040000 */
#define FMC_BWTR2_BUSTURN_3      (0x8UL << FMC_BWTR2_BUSTURN_Pos)	/*!< 0x00080000 */
#define FMC_BWTR2_ACCMOD_Pos     (28U)
#define FMC_BWTR2_ACCMOD_Msk     (0x3UL << FMC_BWTR2_ACCMOD_Pos)/*!< 0x30000000 */
#define FMC_BWTR2_ACCMOD         FMC_BWTR2_ACCMOD_Msk	/*!<ACCMOD[1:0] bits (Access mode) */
#define FMC_BWTR2_ACCMOD_0       (0x1UL << FMC_BWTR2_ACCMOD_Pos)/*!< 0x10000000 */
#define FMC_BWTR2_ACCMOD_1       (0x2UL << FMC_BWTR2_ACCMOD_Pos)/*!< 0x20000000 */

/******************  Bit definition for FMC_BWTR3 register  ******************/
#define FMC_BWTR3_ADDSET_Pos     (0U)
#define FMC_BWTR3_ADDSET_Msk     (0xFUL << FMC_BWTR3_ADDSET_Pos)/*!< 0x0000000F */
#define FMC_BWTR3_ADDSET         FMC_BWTR3_ADDSET_Msk	/*!<ADDSET[3:0] bits (Address setup phase duration) */
#define FMC_BWTR3_ADDSET_0       (0x1UL << FMC_BWTR3_ADDSET_Pos)/*!< 0x00000001 */
#define FMC_BWTR3_ADDSET_1       (0x2UL << FMC_BWTR3_ADDSET_Pos)/*!< 0x00000002 */
#define FMC_BWTR3_ADDSET_2       (0x4UL << FMC_BWTR3_ADDSET_Pos)/*!< 0x00000004 */
#define FMC_BWTR3_ADDSET_3       (0x8UL << FMC_BWTR3_ADDSET_Pos)/*!< 0x00000008 */
#define FMC_BWTR3_ADDHLD_Pos     (4U)
#define FMC_BWTR3_ADDHLD_Msk     (0xFUL << FMC_BWTR3_ADDHLD_Pos)/*!< 0x000000F0 */
#define FMC_BWTR3_ADDHLD         FMC_BWTR3_ADDHLD_Msk	/*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define FMC_BWTR3_ADDHLD_0       (0x1UL << FMC_BWTR3_ADDHLD_Pos)/*!< 0x00000010 */
#define FMC_BWTR3_ADDHLD_1       (0x2UL << FMC_BWTR3_ADDHLD_Pos)/*!< 0x00000020 */
#define FMC_BWTR3_ADDHLD_2       (0x4UL << FMC_BWTR3_ADDHLD_Pos)/*!< 0x00000040 */
#define FMC_BWTR3_ADDHLD_3       (0x8UL << FMC_BWTR3_ADDHLD_Pos)/*!< 0x00000080 */
#define FMC_BWTR3_DATAST_Pos     (8U)
#define FMC_BWTR3_DATAST_Msk     (0xFFUL << FMC_BWTR3_DATAST_Pos)	/*!< 0x0000FF00 */
#define FMC_BWTR3_DATAST         FMC_BWTR3_DATAST_Msk				/*!<DATAST [3:0] bits (Data-phase duration) */
#define FMC_BWTR3_DATAST_0       (0x01UL << FMC_BWTR3_DATAST_Pos)	/*!< 0x00000100 */
#define FMC_BWTR3_DATAST_1       (0x02UL << FMC_BWTR3_DATAST_Pos)	/*!< 0x00000200 */
#define FMC_BWTR3_DATAST_2       (0x04UL << FMC_BWTR3_DATAST_Pos)	/*!< 0x00000400 */
#define FMC_BWTR3_DATAST_3       (0x08UL << FMC_BWTR3_DATAST_Pos)	/*!< 0x00000800 */
#define FMC_BWTR3_DATAST_4       (0x10UL << FMC_BWTR3_DATAST_Pos)	/*!< 0x00001000 */
#define FMC_BWTR3_DATAST_5       (0x20UL << FMC_BWTR3_DATAST_Pos)	/*!< 0x00002000 */
#define FMC_BWTR3_DATAST_6       (0x40UL << FMC_BWTR3_DATAST_Pos)	/*!< 0x00004000 */
#define FMC_BWTR3_DATAST_7       (0x80UL << FMC_BWTR3_DATAST_Pos)	/*!< 0x00008000 */
#define FMC_BWTR3_BUSTURN_Pos    (16U)
#define FMC_BWTR3_BUSTURN_Msk    (0xFUL << FMC_BWTR3_BUSTURN_Pos)	/*!< 0x000F0000 */
#define FMC_BWTR3_BUSTURN        FMC_BWTR3_BUSTURN_Msk				/*!<BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define FMC_BWTR3_BUSTURN_0      (0x1UL << FMC_BWTR3_BUSTURN_Pos)	/*!< 0x00010000 */
#define FMC_BWTR3_BUSTURN_1      (0x2UL << FMC_BWTR3_BUSTURN_Pos)	/*!< 0x00020000 */
#define FMC_BWTR3_BUSTURN_2      (0x4UL << FMC_BWTR3_BUSTURN_Pos)	/*!< 0x00040000 */
#define FMC_BWTR3_BUSTURN_3      (0x8UL << FMC_BWTR3_BUSTURN_Pos)	/*!< 0x00080000 */
#define FMC_BWTR3_ACCMOD_Pos     (28U)
#define FMC_BWTR3_ACCMOD_Msk     (0x3UL << FMC_BWTR3_ACCMOD_Pos)/*!< 0x30000000 */
#define FMC_BWTR3_ACCMOD         FMC_BWTR3_ACCMOD_Msk	/*!<ACCMOD[1:0] bits (Access mode) */
#define FMC_BWTR3_ACCMOD_0       (0x1UL << FMC_BWTR3_ACCMOD_Pos)/*!< 0x10000000 */
#define FMC_BWTR3_ACCMOD_1       (0x2UL << FMC_BWTR3_ACCMOD_Pos)/*!< 0x20000000 */

/******************  Bit definition for FMC_BWTR4 register  ******************/
#define FMC_BWTR4_ADDSET_Pos     (0U)
#define FMC_BWTR4_ADDSET_Msk     (0xFUL << FMC_BWTR4_ADDSET_Pos)/*!< 0x0000000F */
#define FMC_BWTR4_ADDSET         FMC_BWTR4_ADDSET_Msk	/*!<ADDSET[3:0] bits (Address setup phase duration) */
#define FMC_BWTR4_ADDSET_0       (0x1UL << FMC_BWTR4_ADDSET_Pos)/*!< 0x00000001 */
#define FMC_BWTR4_ADDSET_1       (0x2UL << FMC_BWTR4_ADDSET_Pos)/*!< 0x00000002 */
#define FMC_BWTR4_ADDSET_2       (0x4UL << FMC_BWTR4_ADDSET_Pos)/*!< 0x00000004 */
#define FMC_BWTR4_ADDSET_3       (0x8UL << FMC_BWTR4_ADDSET_Pos)/*!< 0x00000008 */
#define FMC_BWTR4_ADDHLD_Pos     (4U)
#define FMC_BWTR4_ADDHLD_Msk     (0xFUL << FMC_BWTR4_ADDHLD_Pos)/*!< 0x000000F0 */
#define FMC_BWTR4_ADDHLD         FMC_BWTR4_ADDHLD_Msk	/*!<ADDHLD[3:0] bits (Address-hold phase duration) */
#define FMC_BWTR4_ADDHLD_0       (0x1UL << FMC_BWTR4_ADDHLD_Pos)/*!< 0x00000010 */
#define FMC_BWTR4_ADDHLD_1       (0x2UL << FMC_BWTR4_ADDHLD_Pos)/*!< 0x00000020 */
#define FMC_BWTR4_ADDHLD_2       (0x4UL << FMC_BWTR4_ADDHLD_Pos)/*!< 0x00000040 */
#define FMC_BWTR4_ADDHLD_3       (0x8UL << FMC_BWTR4_ADDHLD_Pos)/*!< 0x00000080 */
#define FMC_BWTR4_DATAST_Pos     (8U)
#define FMC_BWTR4_DATAST_Msk     (0xFFUL << FMC_BWTR4_DATAST_Pos)	/*!< 0x0000FF00 */
#define FMC_BWTR4_DATAST         FMC_BWTR4_DATAST_Msk				/*!<DATAST [3:0] bits (Data-phase duration) */
#define FMC_BWTR4_DATAST_0       (0x01UL << FMC_BWTR4_DATAST_Pos)	/*!< 0x00000100 */
#define FMC_BWTR4_DATAST_1       (0x02UL << FMC_BWTR4_DATAST_Pos)	/*!< 0x00000200 */
#define FMC_BWTR4_DATAST_2       (0x04UL << FMC_BWTR4_DATAST_Pos)	/*!< 0x00000400 */
#define FMC_BWTR4_DATAST_3       (0x08UL << FMC_BWTR4_DATAST_Pos)	/*!< 0x00000800 */
#define FMC_BWTR4_DATAST_4       (0x10UL << FMC_BWTR4_DATAST_Pos)	/*!< 0x00001000 */
#define FMC_BWTR4_DATAST_5       (0x20UL << FMC_BWTR4_DATAST_Pos)	/*!< 0x00002000 */
#define FMC_BWTR4_DATAST_6       (0x40UL << FMC_BWTR4_DATAST_Pos)	/*!< 0x00004000 */
#define FMC_BWTR4_DATAST_7       (0x80UL << FMC_BWTR4_DATAST_Pos)	/*!< 0x00008000 */
#define FMC_BWTR4_BUSTURN_Pos    (16U)
#define FMC_BWTR4_BUSTURN_Msk    (0xFUL << FMC_BWTR4_BUSTURN_Pos)	/*!< 0x000F0000 */
#define FMC_BWTR4_BUSTURN        FMC_BWTR4_BUSTURN_Msk				/*!<BUSTURN[3:0] bits (Bus turnaround phase duration) */
#define FMC_BWTR4_BUSTURN_0      (0x1UL << FMC_BWTR4_BUSTURN_Pos)	/*!< 0x00010000 */
#define FMC_BWTR4_BUSTURN_1      (0x2UL << FMC_BWTR4_BUSTURN_Pos)	/*!< 0x00020000 */
#define FMC_BWTR4_BUSTURN_2      (0x4UL << FMC_BWTR4_BUSTURN_Pos)	/*!< 0x00040000 */
#define FMC_BWTR4_BUSTURN_3      (0x8UL << FMC_BWTR4_BUSTURN_Pos)	/*!< 0x00080000 */
#define FMC_BWTR4_ACCMOD_Pos     (28U)
#define FMC_BWTR4_ACCMOD_Msk     (0x3UL << FMC_BWTR4_ACCMOD_Pos)/*!< 0x30000000 */
#define FMC_BWTR4_ACCMOD         FMC_BWTR4_ACCMOD_Msk	/*!<ACCMOD[1:0] bits (Access mode) */
#define FMC_BWTR4_ACCMOD_0       (0x1UL << FMC_BWTR4_ACCMOD_Pos)/*!< 0x10000000 */
#define FMC_BWTR4_ACCMOD_1       (0x2UL << FMC_BWTR4_ACCMOD_Pos)/*!< 0x20000000 */

/******************  Bit definition for FMC_PCR register  *******************/
#define FMC_PCR_PWAITEN_Pos    (1U)
#define FMC_PCR_PWAITEN_Msk    (0x1UL << FMC_PCR_PWAITEN_Pos)	/*!< 0x00000002 */
#define FMC_PCR_PWAITEN        FMC_PCR_PWAITEN_Msk				/*!<Wait feature enable bit                   */
#define FMC_PCR_PBKEN_Pos      (2U)
#define FMC_PCR_PBKEN_Msk      (0x1UL << FMC_PCR_PBKEN_Pos)	/*!< 0x00000004 */
#define FMC_PCR_PBKEN          FMC_PCR_PBKEN_Msk/*!<PC Card/NAND Flash memory bank enable bit */
#define FMC_PCR_PTYP_Pos       (3U)
#define FMC_PCR_PTYP_Msk       (0x1UL << FMC_PCR_PTYP_Pos)	/*!< 0x00000008 */
#define FMC_PCR_PTYP           FMC_PCR_PTYP_Msk				/*!<Memory type                               */
#define FMC_PCR_PWID_Pos       (4U)
#define FMC_PCR_PWID_Msk       (0x3UL << FMC_PCR_PWID_Pos)	/*!< 0x00000030 */
#define FMC_PCR_PWID           FMC_PCR_PWID_Msk				/*!<PWID[1:0] bits (NAND Flash databus width) */
#define FMC_PCR_PWID_0         (0x1UL << FMC_PCR_PWID_Pos)	/*!< 0x00000010 */
#define FMC_PCR_PWID_1         (0x2UL << FMC_PCR_PWID_Pos)	/*!< 0x00000020 */
#define FMC_PCR_ECCEN_Pos      (6U)
#define FMC_PCR_ECCEN_Msk      (0x1UL << FMC_PCR_ECCEN_Pos)	/*!< 0x00000040 */
#define FMC_PCR_ECCEN          FMC_PCR_ECCEN_Msk/*!<ECC computation logic enable bit          */
#define FMC_PCR_TCLR_Pos       (9U)
#define FMC_PCR_TCLR_Msk       (0xFUL << FMC_PCR_TCLR_Pos)	/*!< 0x00001E00 */
#define FMC_PCR_TCLR           FMC_PCR_TCLR_Msk				/*!<TCLR[3:0] bits (CLE to RE delay)          */
#define FMC_PCR_TCLR_0         (0x1UL << FMC_PCR_TCLR_Pos)	/*!< 0x00000200 */
#define FMC_PCR_TCLR_1         (0x2UL << FMC_PCR_TCLR_Pos)	/*!< 0x00000400 */
#define FMC_PCR_TCLR_2         (0x4UL << FMC_PCR_TCLR_Pos)	/*!< 0x00000800 */
#define FMC_PCR_TCLR_3         (0x8UL << FMC_PCR_TCLR_Pos)	/*!< 0x00001000 */
#define FMC_PCR_TAR_Pos        (13U)
#define FMC_PCR_TAR_Msk        (0xFUL << FMC_PCR_TAR_Pos)	/*!< 0x0001E000 */
#define FMC_PCR_TAR            FMC_PCR_TAR_Msk				/*!<TAR[3:0] bits (ALE to RE delay)           */
#define FMC_PCR_TAR_0          (0x1UL << FMC_PCR_TAR_Pos)	/*!< 0x00002000 */
#define FMC_PCR_TAR_1          (0x2UL << FMC_PCR_TAR_Pos)	/*!< 0x00004000 */
#define FMC_PCR_TAR_2          (0x4UL << FMC_PCR_TAR_Pos)	/*!< 0x00008000 */
#define FMC_PCR_TAR_3          (0x8UL << FMC_PCR_TAR_Pos)	/*!< 0x00010000 */
#define FMC_PCR_ECCPS_Pos      (17U)
#define FMC_PCR_ECCPS_Msk      (0x7UL << FMC_PCR_ECCPS_Pos)	/*!< 0x000E0000 */
#define FMC_PCR_ECCPS          FMC_PCR_ECCPS_Msk/*!<ECCPS[2:0] bits (ECC page size)           */
#define FMC_PCR_ECCPS_0        (0x1UL << FMC_PCR_ECCPS_Pos)	/*!< 0x00020000 */
#define FMC_PCR_ECCPS_1        (0x2UL << FMC_PCR_ECCPS_Pos)	/*!< 0x00040000 */
#define FMC_PCR_ECCPS_2        (0x4UL << FMC_PCR_ECCPS_Pos)	/*!< 0x00080000 */

/*******************  Bit definition for FMC_SR register  *******************/
#define FMC_SR_IRS_Pos      (0U)
#define FMC_SR_IRS_Msk      (0x1UL << FMC_SR_IRS_Pos)	/*!< 0x00000001 */
#define FMC_SR_IRS          FMC_SR_IRS_Msk				/*!<Interrupt Rising Edge status                */
#define FMC_SR_ILS_Pos      (1U)
#define FMC_SR_ILS_Msk      (0x1UL << FMC_SR_ILS_Pos)	/*!< 0x00000002 */
#define FMC_SR_ILS          FMC_SR_ILS_Msk				/*!<Interrupt Level status                      */
#define FMC_SR_IFS_Pos      (2U)
#define FMC_SR_IFS_Msk      (0x1UL << FMC_SR_IFS_Pos)	/*!< 0x00000004 */
#define FMC_SR_IFS          FMC_SR_IFS_Msk				/*!<Interrupt Falling Edge status               */
#define FMC_SR_IREN_Pos     (3U)
#define FMC_SR_IREN_Msk     (0x1UL << FMC_SR_IREN_Pos)	/*!< 0x00000008 */
#define FMC_SR_IREN         FMC_SR_IREN_Msk				/*!<Interrupt Rising Edge detection Enable bit  */
#define FMC_SR_ILEN_Pos     (4U)
#define FMC_SR_ILEN_Msk     (0x1UL << FMC_SR_ILEN_Pos)	/*!< 0x00000010 */
#define FMC_SR_ILEN         FMC_SR_ILEN_Msk				/*!<Interrupt Level detection Enable bit        */
#define FMC_SR_IFEN_Pos     (5U)
#define FMC_SR_IFEN_Msk     (0x1UL << FMC_SR_IFEN_Pos)	/*!< 0x00000020 */
#define FMC_SR_IFEN         FMC_SR_IFEN_Msk				/*!<Interrupt Falling Edge detection Enable bit */
#define FMC_SR_FEMPT_Pos    (6U)
#define FMC_SR_FEMPT_Msk    (0x1UL << FMC_SR_FEMPT_Pos)	/*!< 0x00000040 */
#define FMC_SR_FEMPT        FMC_SR_FEMPT_Msk/*!<FIFO empty                                  */

/******************  Bit definition for FMC_PMEM register  ******************/
#define FMC_PMEM_MEMSET3_Pos     (0U)
#define FMC_PMEM_MEMSET3_Msk     (0xFFUL << FMC_PMEM_MEMSET3_Pos)	/*!< 0x000000FF */
#define FMC_PMEM_MEMSET3         FMC_PMEM_MEMSET3_Msk				/*!<MEMSET3[7:0] bits (Common memory 3 setup time) */
#define FMC_PMEM_MEMSET3_0       (0x01UL << FMC_PMEM_MEMSET3_Pos)	/*!< 0x00000001 */
#define FMC_PMEM_MEMSET3_1       (0x02UL << FMC_PMEM_MEMSET3_Pos)	/*!< 0x00000002 */
#define FMC_PMEM_MEMSET3_2       (0x04UL << FMC_PMEM_MEMSET3_Pos)	/*!< 0x00000004 */
#define FMC_PMEM_MEMSET3_3       (0x08UL << FMC_PMEM_MEMSET3_Pos)	/*!< 0x00000008 */
#define FMC_PMEM_MEMSET3_4       (0x10UL << FMC_PMEM_MEMSET3_Pos)	/*!< 0x00000010 */
#define FMC_PMEM_MEMSET3_5       (0x20UL << FMC_PMEM_MEMSET3_Pos)	/*!< 0x00000020 */
#define FMC_PMEM_MEMSET3_6       (0x40UL << FMC_PMEM_MEMSET3_Pos)	/*!< 0x00000040 */
#define FMC_PMEM_MEMSET3_7       (0x80UL << FMC_PMEM_MEMSET3_Pos)	/*!< 0x00000080 */
#define FMC_PMEM_MEMWAIT3_Pos    (8U)
#define FMC_PMEM_MEMWAIT3_Msk    (0xFFUL << FMC_PMEM_MEMWAIT3_Pos)	/*!< 0x0000FF00 */
#define FMC_PMEM_MEMWAIT3        FMC_PMEM_MEMWAIT3_Msk				/*!<MEMWAIT3[7:0] bits (Common memory 3 wait time) */
#define FMC_PMEM_MEMWAIT3_0      (0x01UL << FMC_PMEM_MEMWAIT3_Pos)	/*!< 0x00000100 */
#define FMC_PMEM_MEMWAIT3_1      (0x02UL << FMC_PMEM_MEMWAIT3_Pos)	/*!< 0x00000200 */
#define FMC_PMEM_MEMWAIT3_2      (0x04UL << FMC_PMEM_MEMWAIT3_Pos)	/*!< 0x00000400 */
#define FMC_PMEM_MEMWAIT3_3      (0x08UL << FMC_PMEM_MEMWAIT3_Pos)	/*!< 0x00000800 */
#define FMC_PMEM_MEMWAIT3_4      (0x10UL << FMC_PMEM_MEMWAIT3_Pos)	/*!< 0x00001000 */
#define FMC_PMEM_MEMWAIT3_5      (0x20UL << FMC_PMEM_MEMWAIT3_Pos)	/*!< 0x00002000 */
#define FMC_PMEM_MEMWAIT3_6      (0x40UL << FMC_PMEM_MEMWAIT3_Pos)	/*!< 0x00004000 */
#define FMC_PMEM_MEMWAIT3_7      (0x80UL << FMC_PMEM_MEMWAIT3_Pos)	/*!< 0x00008000 */
#define FMC_PMEM_MEMHOLD3_Pos    (16U)
#define FMC_PMEM_MEMHOLD3_Msk    (0xFFUL << FMC_PMEM_MEMHOLD3_Pos)	/*!< 0x00FF0000 */
#define FMC_PMEM_MEMHOLD3        FMC_PMEM_MEMHOLD3_Msk				/*!<MEMHOLD3[7:0] bits (Common memory 3 hold time) */
#define FMC_PMEM_MEMHOLD3_0      (0x01UL << FMC_PMEM_MEMHOLD3_Pos)	/*!< 0x00010000 */
#define FMC_PMEM_MEMHOLD3_1      (0x02UL << FMC_PMEM_MEMHOLD3_Pos)	/*!< 0x00020000 */
#define FMC_PMEM_MEMHOLD3_2      (0x04UL << FMC_PMEM_MEMHOLD3_Pos)	/*!< 0x00040000 */
#define FMC_PMEM_MEMHOLD3_3      (0x08UL << FMC_PMEM_MEMHOLD3_Pos)	/*!< 0x00080000 */
#define FMC_PMEM_MEMHOLD3_4      (0x10UL << FMC_PMEM_MEMHOLD3_Pos)	/*!< 0x00100000 */
#define FMC_PMEM_MEMHOLD3_5      (0x20UL << FMC_PMEM_MEMHOLD3_Pos)	/*!< 0x00200000 */
#define FMC_PMEM_MEMHOLD3_6      (0x40UL << FMC_PMEM_MEMHOLD3_Pos)	/*!< 0x00400000 */
#define FMC_PMEM_MEMHOLD3_7      (0x80UL << FMC_PMEM_MEMHOLD3_Pos)	/*!< 0x00800000 */
#define FMC_PMEM_MEMHIZ3_Pos     (24U)
#define FMC_PMEM_MEMHIZ3_Msk     (0xFFUL << FMC_PMEM_MEMHIZ3_Pos)	/*!< 0xFF000000 */
#define FMC_PMEM_MEMHIZ3         FMC_PMEM_MEMHIZ3_Msk				/*!<MEMHIZ3[7:0] bits (Common memory 3 databus HiZ time) */
#define FMC_PMEM_MEMHIZ3_0       (0x01UL << FMC_PMEM_MEMHIZ3_Pos)	/*!< 0x01000000 */
#define FMC_PMEM_MEMHIZ3_1       (0x02UL << FMC_PMEM_MEMHIZ3_Pos)	/*!< 0x02000000 */
#define FMC_PMEM_MEMHIZ3_2       (0x04UL << FMC_PMEM_MEMHIZ3_Pos)	/*!< 0x04000000 */
#define FMC_PMEM_MEMHIZ3_3       (0x08UL << FMC_PMEM_MEMHIZ3_Pos)	/*!< 0x08000000 */
#define FMC_PMEM_MEMHIZ3_4       (0x10UL << FMC_PMEM_MEMHIZ3_Pos)	/*!< 0x10000000 */
#define FMC_PMEM_MEMHIZ3_5       (0x20UL << FMC_PMEM_MEMHIZ3_Pos)	/*!< 0x20000000 */
#define FMC_PMEM_MEMHIZ3_6       (0x40UL << FMC_PMEM_MEMHIZ3_Pos)	/*!< 0x40000000 */
#define FMC_PMEM_MEMHIZ3_7       (0x80UL << FMC_PMEM_MEMHIZ3_Pos)	/*!< 0x80000000 */

/******************  Bit definition for FMC_PATT register  ******************/
#define FMC_PATT_ATTSET3_Pos     (0U)
#define FMC_PATT_ATTSET3_Msk     (0xFFUL << FMC_PATT_ATTSET3_Pos)	/*!< 0x000000FF */
#define FMC_PATT_ATTSET3         FMC_PATT_ATTSET3_Msk				/*!<ATTSET3[7:0] bits (Attribute memory 3 setup time) */
#define FMC_PATT_ATTSET3_0       (0x01UL << FMC_PATT_ATTSET3_Pos)	/*!< 0x00000001 */
#define FMC_PATT_ATTSET3_1       (0x02UL << FMC_PATT_ATTSET3_Pos)	/*!< 0x00000002 */
#define FMC_PATT_ATTSET3_2       (0x04UL << FMC_PATT_ATTSET3_Pos)	/*!< 0x00000004 */
#define FMC_PATT_ATTSET3_3       (0x08UL << FMC_PATT_ATTSET3_Pos)	/*!< 0x00000008 */
#define FMC_PATT_ATTSET3_4       (0x10UL << FMC_PATT_ATTSET3_Pos)	/*!< 0x00000010 */
#define FMC_PATT_ATTSET3_5       (0x20UL << FMC_PATT_ATTSET3_Pos)	/*!< 0x00000020 */
#define FMC_PATT_ATTSET3_6       (0x40UL << FMC_PATT_ATTSET3_Pos)	/*!< 0x00000040 */
#define FMC_PATT_ATTSET3_7       (0x80UL << FMC_PATT_ATTSET3_Pos)	/*!< 0x00000080 */
#define FMC_PATT_ATTWAIT3_Pos    (8U)
#define FMC_PATT_ATTWAIT3_Msk    (0xFFUL << FMC_PATT_ATTWAIT3_Pos)	/*!< 0x0000FF00 */
#define FMC_PATT_ATTWAIT3        FMC_PATT_ATTWAIT3_Msk				/*!<ATTWAIT3[7:0] bits (Attribute memory 3 wait time) */
#define FMC_PATT_ATTWAIT3_0      (0x01UL << FMC_PATT_ATTWAIT3_Pos)	/*!< 0x00000100 */
#define FMC_PATT_ATTWAIT3_1      (0x02UL << FMC_PATT_ATTWAIT3_Pos)	/*!< 0x00000200 */
#define FMC_PATT_ATTWAIT3_2      (0x04UL << FMC_PATT_ATTWAIT3_Pos)	/*!< 0x00000400 */
#define FMC_PATT_ATTWAIT3_3      (0x08UL << FMC_PATT_ATTWAIT3_Pos)	/*!< 0x00000800 */
#define FMC_PATT_ATTWAIT3_4      (0x10UL << FMC_PATT_ATTWAIT3_Pos)	/*!< 0x00001000 */
#define FMC_PATT_ATTWAIT3_5      (0x20UL << FMC_PATT_ATTWAIT3_Pos)	/*!< 0x00002000 */
#define FMC_PATT_ATTWAIT3_6      (0x40UL << FMC_PATT_ATTWAIT3_Pos)	/*!< 0x00004000 */
#define FMC_PATT_ATTWAIT3_7      (0x80UL << FMC_PATT_ATTWAIT3_Pos)	/*!< 0x00008000 */
#define FMC_PATT_ATTHOLD3_Pos    (16U)
#define FMC_PATT_ATTHOLD3_Msk    (0xFFUL << FMC_PATT_ATTHOLD3_Pos)	/*!< 0x00FF0000 */
#define FMC_PATT_ATTHOLD3        FMC_PATT_ATTHOLD3_Msk				/*!<ATTHOLD3[7:0] bits (Attribute memory 3 hold time) */
#define FMC_PATT_ATTHOLD3_0      (0x01UL << FMC_PATT_ATTHOLD3_Pos)	/*!< 0x00010000 */
#define FMC_PATT_ATTHOLD3_1      (0x02UL << FMC_PATT_ATTHOLD3_Pos)	/*!< 0x00020000 */
#define FMC_PATT_ATTHOLD3_2      (0x04UL << FMC_PATT_ATTHOLD3_Pos)	/*!< 0x00040000 */
#define FMC_PATT_ATTHOLD3_3      (0x08UL << FMC_PATT_ATTHOLD3_Pos)	/*!< 0x00080000 */
#define FMC_PATT_ATTHOLD3_4      (0x10UL << FMC_PATT_ATTHOLD3_Pos)	/*!< 0x00100000 */
#define FMC_PATT_ATTHOLD3_5      (0x20UL << FMC_PATT_ATTHOLD3_Pos)	/*!< 0x00200000 */
#define FMC_PATT_ATTHOLD3_6      (0x40UL << FMC_PATT_ATTHOLD3_Pos)	/*!< 0x00400000 */
#define FMC_PATT_ATTHOLD3_7      (0x80UL << FMC_PATT_ATTHOLD3_Pos)	/*!< 0x00800000 */
#define FMC_PATT_ATTHIZ3_Pos     (24U)
#define FMC_PATT_ATTHIZ3_Msk     (0xFFUL << FMC_PATT_ATTHIZ3_Pos)	/*!< 0xFF000000 */
#define FMC_PATT_ATTHIZ3         FMC_PATT_ATTHIZ3_Msk				/*!<ATTHIZ3[7:0] bits (Attribute memory 3 databus HiZ time) */
#define FMC_PATT_ATTHIZ3_0       (0x01UL << FMC_PATT_ATTHIZ3_Pos)	/*!< 0x01000000 */
#define FMC_PATT_ATTHIZ3_1       (0x02UL << FMC_PATT_ATTHIZ3_Pos)	/*!< 0x02000000 */
#define FMC_PATT_ATTHIZ3_2       (0x04UL << FMC_PATT_ATTHIZ3_Pos)	/*!< 0x04000000 */
#define FMC_PATT_ATTHIZ3_3       (0x08UL << FMC_PATT_ATTHIZ3_Pos)	/*!< 0x08000000 */
#define FMC_PATT_ATTHIZ3_4       (0x10UL << FMC_PATT_ATTHIZ3_Pos)	/*!< 0x10000000 */
#define FMC_PATT_ATTHIZ3_5       (0x20UL << FMC_PATT_ATTHIZ3_Pos)	/*!< 0x20000000 */
#define FMC_PATT_ATTHIZ3_6       (0x40UL << FMC_PATT_ATTHIZ3_Pos)	/*!< 0x40000000 */
#define FMC_PATT_ATTHIZ3_7       (0x80UL << FMC_PATT_ATTHIZ3_Pos)	/*!< 0x80000000 */

/******************  Bit definition for FMC_ECCR register  ******************/
#define FMC_ECCR_ECC3_Pos    (0U)
#define FMC_ECCR_ECC3_Msk    (0xFFFFFFFFUL << FMC_ECCR_ECC3_Pos)/*!< 0xFFFFFFFF */
#define FMC_ECCR_ECC3        FMC_ECCR_ECC3_Msk	/*!<ECC result */

/******************  Bit definition for FMC_SDCR1 register  ******************/
#define FMC_SDCR1_NC_Pos        (0U)
#define FMC_SDCR1_NC_Msk        (0x3UL << FMC_SDCR1_NC_Pos)	/*!< 0x00000003 */
#define FMC_SDCR1_NC            FMC_SDCR1_NC_Msk/*!<NC[1:0] bits (Number of column bits) */
#define FMC_SDCR1_NC_0          (0x1UL << FMC_SDCR1_NC_Pos)	/*!< 0x00000001 */
#define FMC_SDCR1_NC_1          (0x2UL << FMC_SDCR1_NC_Pos)	/*!< 0x00000002 */
#define FMC_SDCR1_NR_Pos        (2U)
#define FMC_SDCR1_NR_Msk        (0x3UL << FMC_SDCR1_NR_Pos)	/*!< 0x0000000C */
#define FMC_SDCR1_NR            FMC_SDCR1_NR_Msk/*!<NR[1:0] bits (Number of row bits) */
#define FMC_SDCR1_NR_0          (0x1UL << FMC_SDCR1_NR_Pos)	/*!< 0x00000004 */
#define FMC_SDCR1_NR_1          (0x2UL << FMC_SDCR1_NR_Pos)	/*!< 0x00000008 */
#define FMC_SDCR1_MWID_Pos      (4U)
#define FMC_SDCR1_MWID_Msk      (0x3UL << FMC_SDCR1_MWID_Pos)	/*!< 0x00000030 */
#define FMC_SDCR1_MWID          FMC_SDCR1_MWID_Msk				/*!<NR[1:0] bits (Number of row bits) */
#define FMC_SDCR1_MWID_0        (0x1UL << FMC_SDCR1_MWID_Pos)	/*!< 0x00000010 */
#define FMC_SDCR1_MWID_1        (0x2UL << FMC_SDCR1_MWID_Pos)	/*!< 0x00000020 */
#define FMC_SDCR1_NB_Pos        (6U)
#define FMC_SDCR1_NB_Msk        (0x1UL << FMC_SDCR1_NB_Pos)	/*!< 0x00000040 */
#define FMC_SDCR1_NB            FMC_SDCR1_NB_Msk/*!<Number of internal bank */
#define FMC_SDCR1_CAS_Pos       (7U)
#define FMC_SDCR1_CAS_Msk       (0x3UL << FMC_SDCR1_CAS_Pos)/*!< 0x00000180 */
#define FMC_SDCR1_CAS           FMC_SDCR1_CAS_Msk	/*!<CAS[1:0] bits (CAS latency) */
#define FMC_SDCR1_CAS_0         (0x1UL << FMC_SDCR1_CAS_Pos)/*!< 0x00000080 */
#define FMC_SDCR1_CAS_1         (0x2UL << FMC_SDCR1_CAS_Pos)/*!< 0x00000100 */
#define FMC_SDCR1_WP_Pos        (9U)
#define FMC_SDCR1_WP_Msk        (0x1UL << FMC_SDCR1_WP_Pos)	/*!< 0x00000200 */
#define FMC_SDCR1_WP            FMC_SDCR1_WP_Msk/*!<Write protection */
#define FMC_SDCR1_SDCLK_Pos     (10U)
#define FMC_SDCR1_SDCLK_Msk     (0x3UL << FMC_SDCR1_SDCLK_Pos)	/*!< 0x00000C00 */
#define FMC_SDCR1_SDCLK         FMC_SDCR1_SDCLK_Msk				/*!<SDRAM clock configuration */
#define FMC_SDCR1_SDCLK_0       (0x1UL << FMC_SDCR1_SDCLK_Pos)	/*!< 0x00000400 */
#define FMC_SDCR1_SDCLK_1       (0x2UL << FMC_SDCR1_SDCLK_Pos)	/*!< 0x00000800 */
#define FMC_SDCR1_RBURST_Pos    (12U)
#define FMC_SDCR1_RBURST_Msk    (0x1UL << FMC_SDCR1_RBURST_Pos)	/*!< 0x00001000 */
#define FMC_SDCR1_RBURST        FMC_SDCR1_RBURST_Msk/*!<Read burst */
#define FMC_SDCR1_RPIPE_Pos     (13U)
#define FMC_SDCR1_RPIPE_Msk     (0x3UL << FMC_SDCR1_RPIPE_Pos)	/*!< 0x00006000 */
#define FMC_SDCR1_RPIPE         FMC_SDCR1_RPIPE_Msk				/*!<Write protection */
#define FMC_SDCR1_RPIPE_0       (0x1UL << FMC_SDCR1_RPIPE_Pos)	/*!< 0x00002000 */
#define FMC_SDCR1_RPIPE_1       (0x2UL << FMC_SDCR1_RPIPE_Pos)	/*!< 0x00004000 */

/******************  Bit definition for FMC_SDCR2 register  ******************/
#define FMC_SDCR2_NC_Pos        (0U)
#define FMC_SDCR2_NC_Msk        (0x3UL << FMC_SDCR2_NC_Pos)	/*!< 0x00000003 */
#define FMC_SDCR2_NC            FMC_SDCR2_NC_Msk/*!<NC[1:0] bits (Number of column bits) */
#define FMC_SDCR2_NC_0          (0x1UL << FMC_SDCR2_NC_Pos)	/*!< 0x00000001 */
#define FMC_SDCR2_NC_1          (0x2UL << FMC_SDCR2_NC_Pos)	/*!< 0x00000002 */
#define FMC_SDCR2_NR_Pos        (2U)
#define FMC_SDCR2_NR_Msk        (0x3UL << FMC_SDCR2_NR_Pos)	/*!< 0x0000000C */
#define FMC_SDCR2_NR            FMC_SDCR2_NR_Msk/*!<NR[1:0] bits (Number of row bits) */
#define FMC_SDCR2_NR_0          (0x1UL << FMC_SDCR2_NR_Pos)	/*!< 0x00000004 */
#define FMC_SDCR2_NR_1          (0x2UL << FMC_SDCR2_NR_Pos)	/*!< 0x00000008 */
#define FMC_SDCR2_MWID_Pos      (4U)
#define FMC_SDCR2_MWID_Msk      (0x3UL << FMC_SDCR2_MWID_Pos)	/*!< 0x00000030 */
#define FMC_SDCR2_MWID          FMC_SDCR2_MWID_Msk				/*!<NR[1:0] bits (Number of row bits) */
#define FMC_SDCR2_MWID_0        (0x1UL << FMC_SDCR2_MWID_Pos)	/*!< 0x00000010 */
#define FMC_SDCR2_MWID_1        (0x2UL << FMC_SDCR2_MWID_Pos)	/*!< 0x00000020 */
#define FMC_SDCR2_NB_Pos        (6U)
#define FMC_SDCR2_NB_Msk        (0x1UL << FMC_SDCR2_NB_Pos)	/*!< 0x00000040 */
#define FMC_SDCR2_NB            FMC_SDCR2_NB_Msk/*!<Number of internal bank */
#define FMC_SDCR2_CAS_Pos       (7U)
#define FMC_SDCR2_CAS_Msk       (0x3UL << FMC_SDCR2_CAS_Pos)/*!< 0x00000180 */
#define FMC_SDCR2_CAS           FMC_SDCR2_CAS_Msk	/*!<CAS[1:0] bits (CAS latency) */
#define FMC_SDCR2_CAS_0         (0x1UL << FMC_SDCR2_CAS_Pos)/*!< 0x00000080 */
#define FMC_SDCR2_CAS_1         (0x2UL << FMC_SDCR2_CAS_Pos)/*!< 0x00000100 */
#define FMC_SDCR2_WP_Pos        (9U)
#define FMC_SDCR2_WP_Msk        (0x1UL << FMC_SDCR2_WP_Pos)	/*!< 0x00000200 */
#define FMC_SDCR2_WP            FMC_SDCR2_WP_Msk/*!<Write protection */
#define FMC_SDCR2_SDCLK_Pos     (10U)
#define FMC_SDCR2_SDCLK_Msk     (0x3UL << FMC_SDCR2_SDCLK_Pos)	/*!< 0x00000C00 */
#define FMC_SDCR2_SDCLK         FMC_SDCR2_SDCLK_Msk				/*!<SDCLK[1:0] (SDRAM clock configuration) */
#define FMC_SDCR2_SDCLK_0       (0x1UL << FMC_SDCR2_SDCLK_Pos)	/*!< 0x00000400 */
#define FMC_SDCR2_SDCLK_1       (0x2UL << FMC_SDCR2_SDCLK_Pos)	/*!< 0x00000800 */
#define FMC_SDCR2_RBURST_Pos    (12U)
#define FMC_SDCR2_RBURST_Msk    (0x1UL << FMC_SDCR2_RBURST_Pos)	/*!< 0x00001000 */
#define FMC_SDCR2_RBURST        FMC_SDCR2_RBURST_Msk/*!<Read burst */
#define FMC_SDCR2_RPIPE_Pos     (13U)
#define FMC_SDCR2_RPIPE_Msk     (0x3UL << FMC_SDCR2_RPIPE_Pos)	/*!< 0x00006000 */
#define FMC_SDCR2_RPIPE         FMC_SDCR2_RPIPE_Msk				/*!<RPIPE[1:0](Read pipe) */
#define FMC_SDCR2_RPIPE_0       (0x1UL << FMC_SDCR2_RPIPE_Pos)	/*!< 0x00002000 */
#define FMC_SDCR2_RPIPE_1       (0x2UL << FMC_SDCR2_RPIPE_Pos)	/*!< 0x00004000 */

/******************  Bit definition for FMC_SDTR1 register  ******************/
#define FMC_SDTR1_TMRD_Pos    (0U)
#define FMC_SDTR1_TMRD_Msk    (0xFUL << FMC_SDTR1_TMRD_Pos)	/*!< 0x0000000F */
#define FMC_SDTR1_TMRD        FMC_SDTR1_TMRD_Msk/*!<TMRD[3:0] bits (Load mode register to active) */
#define FMC_SDTR1_TMRD_0      (0x1UL << FMC_SDTR1_TMRD_Pos)	/*!< 0x00000001 */
#define FMC_SDTR1_TMRD_1      (0x2UL << FMC_SDTR1_TMRD_Pos)	/*!< 0x00000002 */
#define FMC_SDTR1_TMRD_2      (0x4UL << FMC_SDTR1_TMRD_Pos)	/*!< 0x00000004 */
#define FMC_SDTR1_TMRD_3      (0x8UL << FMC_SDTR1_TMRD_Pos)	/*!< 0x00000008 */
#define FMC_SDTR1_TXSR_Pos    (4U)
#define FMC_SDTR1_TXSR_Msk    (0xFUL << FMC_SDTR1_TXSR_Pos)	/*!< 0x000000F0 */
#define FMC_SDTR1_TXSR        FMC_SDTR1_TXSR_Msk/*!<TXSR[3:0] bits (Exit self refresh) */
#define FMC_SDTR1_TXSR_0      (0x1UL << FMC_SDTR1_TXSR_Pos)	/*!< 0x00000010 */
#define FMC_SDTR1_TXSR_1      (0x2UL << FMC_SDTR1_TXSR_Pos)	/*!< 0x00000020 */
#define FMC_SDTR1_TXSR_2      (0x4UL << FMC_SDTR1_TXSR_Pos)	/*!< 0x00000040 */
#define FMC_SDTR1_TXSR_3      (0x8UL << FMC_SDTR1_TXSR_Pos)	/*!< 0x00000080 */
#define FMC_SDTR1_TRAS_Pos    (8U)
#define FMC_SDTR1_TRAS_Msk    (0xFUL << FMC_SDTR1_TRAS_Pos)	/*!< 0x00000F00 */
#define FMC_SDTR1_TRAS        FMC_SDTR1_TRAS_Msk/*!<TRAS[3:0] bits (Self refresh time) */
#define FMC_SDTR1_TRAS_0      (0x1UL << FMC_SDTR1_TRAS_Pos)	/*!< 0x00000100 */
#define FMC_SDTR1_TRAS_1      (0x2UL << FMC_SDTR1_TRAS_Pos)	/*!< 0x00000200 */
#define FMC_SDTR1_TRAS_2      (0x4UL << FMC_SDTR1_TRAS_Pos)	/*!< 0x00000400 */
#define FMC_SDTR1_TRAS_3      (0x8UL << FMC_SDTR1_TRAS_Pos)	/*!< 0x00000800 */
#define FMC_SDTR1_TRC_Pos     (12U)
#define FMC_SDTR1_TRC_Msk     (0xFUL << FMC_SDTR1_TRC_Pos)	/*!< 0x0000F000 */
#define FMC_SDTR1_TRC         FMC_SDTR1_TRC_Msk				/*!<TRC[2:0] bits (Row cycle delay) */
#define FMC_SDTR1_TRC_0       (0x1UL << FMC_SDTR1_TRC_Pos)	/*!< 0x00001000 */
#define FMC_SDTR1_TRC_1       (0x2UL << FMC_SDTR1_TRC_Pos)	/*!< 0x00002000 */
#define FMC_SDTR1_TRC_2       (0x4UL << FMC_SDTR1_TRC_Pos)	/*!< 0x00004000 */
#define FMC_SDTR1_TWR_Pos     (16U)
#define FMC_SDTR1_TWR_Msk     (0xFUL << FMC_SDTR1_TWR_Pos)	/*!< 0x000F0000 */
#define FMC_SDTR1_TWR         FMC_SDTR1_TWR_Msk				/*!<TRC[2:0] bits (Write recovery delay) */
#define FMC_SDTR1_TWR_0       (0x1UL << FMC_SDTR1_TWR_Pos)	/*!< 0x00010000 */
#define FMC_SDTR1_TWR_1       (0x2UL << FMC_SDTR1_TWR_Pos)	/*!< 0x00020000 */
#define FMC_SDTR1_TWR_2       (0x4UL << FMC_SDTR1_TWR_Pos)	/*!< 0x00040000 */
#define FMC_SDTR1_TRP_Pos     (20U)
#define FMC_SDTR1_TRP_Msk     (0xFUL << FMC_SDTR1_TRP_Pos)	/*!< 0x00F00000 */
#define FMC_SDTR1_TRP         FMC_SDTR1_TRP_Msk				/*!<TRP[2:0] bits (Row precharge delay) */
#define FMC_SDTR1_TRP_0       (0x1UL << FMC_SDTR1_TRP_Pos)	/*!< 0x00100000 */
#define FMC_SDTR1_TRP_1       (0x2UL << FMC_SDTR1_TRP_Pos)	/*!< 0x00200000 */
#define FMC_SDTR1_TRP_2       (0x4UL << FMC_SDTR1_TRP_Pos)	/*!< 0x00400000 */
#define FMC_SDTR1_TRCD_Pos    (24U)
#define FMC_SDTR1_TRCD_Msk    (0xFUL << FMC_SDTR1_TRCD_Pos)	/*!< 0x0F000000 */
#define FMC_SDTR1_TRCD        FMC_SDTR1_TRCD_Msk/*!<TRP[2:0] bits (Row to column delay) */
#define FMC_SDTR1_TRCD_0      (0x1UL << FMC_SDTR1_TRCD_Pos)	/*!< 0x01000000 */
#define FMC_SDTR1_TRCD_1      (0x2UL << FMC_SDTR1_TRCD_Pos)	/*!< 0x02000000 */
#define FMC_SDTR1_TRCD_2      (0x4UL << FMC_SDTR1_TRCD_Pos)	/*!< 0x04000000 */

/******************  Bit definition for FMC_SDTR2 register  ******************/
#define FMC_SDTR2_TMRD_Pos    (0U)
#define FMC_SDTR2_TMRD_Msk    (0xFUL << FMC_SDTR2_TMRD_Pos)	/*!< 0x0000000F */
#define FMC_SDTR2_TMRD        FMC_SDTR2_TMRD_Msk/*!<TMRD[3:0] bits (Load mode register to active) */
#define FMC_SDTR2_TMRD_0      (0x1UL << FMC_SDTR2_TMRD_Pos)	/*!< 0x00000001 */
#define FMC_SDTR2_TMRD_1      (0x2UL << FMC_SDTR2_TMRD_Pos)	/*!< 0x00000002 */
#define FMC_SDTR2_TMRD_2      (0x4UL << FMC_SDTR2_TMRD_Pos)	/*!< 0x00000004 */
#define FMC_SDTR2_TMRD_3      (0x8UL << FMC_SDTR2_TMRD_Pos)	/*!< 0x00000008 */
#define FMC_SDTR2_TXSR_Pos    (4U)
#define FMC_SDTR2_TXSR_Msk    (0xFUL << FMC_SDTR2_TXSR_Pos)	/*!< 0x000000F0 */
#define FMC_SDTR2_TXSR        FMC_SDTR2_TXSR_Msk/*!<TXSR[3:0] bits (Exit self refresh) */
#define FMC_SDTR2_TXSR_0      (0x1UL << FMC_SDTR2_TXSR_Pos)	/*!< 0x00000010 */
#define FMC_SDTR2_TXSR_1      (0x2UL << FMC_SDTR2_TXSR_Pos)	/*!< 0x00000020 */
#define FMC_SDTR2_TXSR_2      (0x4UL << FMC_SDTR2_TXSR_Pos)	/*!< 0x00000040 */
#define FMC_SDTR2_TXSR_3      (0x8UL << FMC_SDTR2_TXSR_Pos)	/*!< 0x00000080 */
#define FMC_SDTR2_TRAS_Pos    (8U)
#define FMC_SDTR2_TRAS_Msk    (0xFUL << FMC_SDTR2_TRAS_Pos)	/*!< 0x00000F00 */
#define FMC_SDTR2_TRAS        FMC_SDTR2_TRAS_Msk/*!<TRAS[3:0] bits (Self refresh time) */
#define FMC_SDTR2_TRAS_0      (0x1UL << FMC_SDTR2_TRAS_Pos)	/*!< 0x00000100 */
#define FMC_SDTR2_TRAS_1      (0x2UL << FMC_SDTR2_TRAS_Pos)	/*!< 0x00000200 */
#define FMC_SDTR2_TRAS_2      (0x4UL << FMC_SDTR2_TRAS_Pos)	/*!< 0x00000400 */
#define FMC_SDTR2_TRAS_3      (0x8UL << FMC_SDTR2_TRAS_Pos)	/*!< 0x00000800 */
#define FMC_SDTR2_TRC_Pos     (12U)
#define FMC_SDTR2_TRC_Msk     (0xFUL << FMC_SDTR2_TRC_Pos)	/*!< 0x0000F000 */
#define FMC_SDTR2_TRC         FMC_SDTR2_TRC_Msk				/*!<TRC[2:0] bits (Row cycle delay) */
#define FMC_SDTR2_TRC_0       (0x1UL << FMC_SDTR2_TRC_Pos)	/*!< 0x00001000 */
#define FMC_SDTR2_TRC_1       (0x2UL << FMC_SDTR2_TRC_Pos)	/*!< 0x00002000 */
#define FMC_SDTR2_TRC_2       (0x4UL << FMC_SDTR2_TRC_Pos)	/*!< 0x00004000 */
#define FMC_SDTR2_TWR_Pos     (16U)
#define FMC_SDTR2_TWR_Msk     (0xFUL << FMC_SDTR2_TWR_Pos)	/*!< 0x000F0000 */
#define FMC_SDTR2_TWR         FMC_SDTR2_TWR_Msk				/*!<TRC[2:0] bits (Write recovery delay) */
#define FMC_SDTR2_TWR_0       (0x1UL << FMC_SDTR2_TWR_Pos)	/*!< 0x00010000 */
#define FMC_SDTR2_TWR_1       (0x2UL << FMC_SDTR2_TWR_Pos)	/*!< 0x00020000 */
#define FMC_SDTR2_TWR_2       (0x4UL << FMC_SDTR2_TWR_Pos)	/*!< 0x00040000 */
#define FMC_SDTR2_TRP_Pos     (20U)
#define FMC_SDTR2_TRP_Msk     (0xFUL << FMC_SDTR2_TRP_Pos)	/*!< 0x00F00000 */
#define FMC_SDTR2_TRP         FMC_SDTR2_TRP_Msk				/*!<TRP[2:0] bits (Row precharge delay) */
#define FMC_SDTR2_TRP_0       (0x1UL << FMC_SDTR2_TRP_Pos)	/*!< 0x00100000 */
#define FMC_SDTR2_TRP_1       (0x2UL << FMC_SDTR2_TRP_Pos)	/*!< 0x00200000 */
#define FMC_SDTR2_TRP_2       (0x4UL << FMC_SDTR2_TRP_Pos)	/*!< 0x00400000 */
#define FMC_SDTR2_TRCD_Pos    (24U)
#define FMC_SDTR2_TRCD_Msk    (0xFUL << FMC_SDTR2_TRCD_Pos)	/*!< 0x0F000000 */
#define FMC_SDTR2_TRCD        FMC_SDTR2_TRCD_Msk/*!<TRP[2:0] bits (Row to column delay) */
#define FMC_SDTR2_TRCD_0      (0x1UL << FMC_SDTR2_TRCD_Pos)	/*!< 0x01000000 */
#define FMC_SDTR2_TRCD_1      (0x2UL << FMC_SDTR2_TRCD_Pos)	/*!< 0x02000000 */
#define FMC_SDTR2_TRCD_2      (0x4UL << FMC_SDTR2_TRCD_Pos)	/*!< 0x04000000 */

/******************  Bit definition for FMC_SDCMR register  ******************/
#define FMC_SDCMR_MODE_Pos    (0U)
#define FMC_SDCMR_MODE_Msk    (0x7UL << FMC_SDCMR_MODE_Pos)	/*!< 0x00000007 */
#define FMC_SDCMR_MODE        FMC_SDCMR_MODE_Msk/*!<MODE[2:0] bits (Command mode) */
#define FMC_SDCMR_MODE_0      (0x1UL << FMC_SDCMR_MODE_Pos)	/*!< 0x00000001 */
#define FMC_SDCMR_MODE_1      (0x2UL << FMC_SDCMR_MODE_Pos)	/*!< 0x00000002 */
#define FMC_SDCMR_MODE_2      (0x4UL << FMC_SDCMR_MODE_Pos)	/*!< 0x00000004 */
#define FMC_SDCMR_CTB2_Pos    (3U)
#define FMC_SDCMR_CTB2_Msk    (0x1UL << FMC_SDCMR_CTB2_Pos)	/*!< 0x00000008 */
#define FMC_SDCMR_CTB2        FMC_SDCMR_CTB2_Msk/*!<Command target 2 */
#define FMC_SDCMR_CTB1_Pos    (4U)
#define FMC_SDCMR_CTB1_Msk    (0x1UL << FMC_SDCMR_CTB1_Pos)	/*!< 0x00000010 */
#define FMC_SDCMR_CTB1        FMC_SDCMR_CTB1_Msk/*!<Command target 1 */
#define FMC_SDCMR_NRFS_Pos    (5U)
#define FMC_SDCMR_NRFS_Msk    (0xFUL << FMC_SDCMR_NRFS_Pos)	/*!< 0x000001E0 */
#define FMC_SDCMR_NRFS        FMC_SDCMR_NRFS_Msk/*!<NRFS[3:0] bits (Number of auto-refresh) */
#define FMC_SDCMR_NRFS_0      (0x1UL << FMC_SDCMR_NRFS_Pos)	/*!< 0x00000020 */
#define FMC_SDCMR_NRFS_1      (0x2UL << FMC_SDCMR_NRFS_Pos)	/*!< 0x00000040 */
#define FMC_SDCMR_NRFS_2      (0x4UL << FMC_SDCMR_NRFS_Pos)	/*!< 0x00000080 */
#define FMC_SDCMR_NRFS_3      (0x8UL << FMC_SDCMR_NRFS_Pos)	/*!< 0x00000100 */
#define FMC_SDCMR_MRD_Pos     (9U)
#define FMC_SDCMR_MRD_Msk     (0x1FFFUL << FMC_SDCMR_MRD_Pos)	/*!< 0x003FFE00 */
#define FMC_SDCMR_MRD         FMC_SDCMR_MRD_Msk					/*!<MRD[12:0] bits (Mode register definition) */

/******************  Bit definition for FMC_SDRTR register  ******************/
#define FMC_SDRTR_CRE_Pos      (0U)
#define FMC_SDRTR_CRE_Msk      (0x1UL << FMC_SDRTR_CRE_Pos)	/*!< 0x00000001 */
#define FMC_SDRTR_CRE          FMC_SDRTR_CRE_Msk/*!<Clear refresh error flag */
#define FMC_SDRTR_COUNT_Pos    (1U)
#define FMC_SDRTR_COUNT_Msk    (0x1FFFUL << FMC_SDRTR_COUNT_Pos)/*!< 0x00003FFE */
#define FMC_SDRTR_COUNT        FMC_SDRTR_COUNT_Msk	/*!<COUNT[12:0] bits (Refresh timer count) */
#define FMC_SDRTR_REIE_Pos     (14U)
#define FMC_SDRTR_REIE_Msk     (0x1UL << FMC_SDRTR_REIE_Pos)/*!< 0x00004000 */
#define FMC_SDRTR_REIE         FMC_SDRTR_REIE_Msk	/*!<RES interupt enable */

/******************  Bit definition for FMC_SDSR register  ******************/
#define FMC_SDSR_RE_Pos        (0U)
#define FMC_SDSR_RE_Msk        (0x1UL << FMC_SDSR_RE_Pos)	/*!< 0x00000001 */
#define FMC_SDSR_RE            FMC_SDSR_RE_Msk				/*!<Refresh error flag */
#define FMC_SDSR_MODES1_Pos    (1U)
#define FMC_SDSR_MODES1_Msk    (0x3UL << FMC_SDSR_MODES1_Pos)	/*!< 0x00000006 */
#define FMC_SDSR_MODES1        FMC_SDSR_MODES1_Msk				/*!<MODES1[1:0]bits (Status mode for bank 1) */
#define FMC_SDSR_MODES1_0      (0x1UL << FMC_SDSR_MODES1_Pos)	/*!< 0x00000002 */
#define FMC_SDSR_MODES1_1      (0x2UL << FMC_SDSR_MODES1_Pos)	/*!< 0x00000004 */
#define FMC_SDSR_MODES2_Pos    (3U)
#define FMC_SDSR_MODES2_Msk    (0x3UL << FMC_SDSR_MODES2_Pos)	/*!< 0x00000018 */
#define FMC_SDSR_MODES2        FMC_SDSR_MODES2_Msk				/*!<MODES2[1:0]bits (Status mode for bank 2) */
#define FMC_SDSR_MODES2_0      (0x1UL << FMC_SDSR_MODES2_Pos)	/*!< 0x00000008 */
#define FMC_SDSR_MODES2_1      (0x2UL << FMC_SDSR_MODES2_Pos)	/*!< 0x00000010 */
#define FMC_SDSR_BUSY_Pos      (5U)
#define FMC_SDSR_BUSY_Msk      (0x1UL << FMC_SDSR_BUSY_Pos)	/*!< 0x00000020 */
#define FMC_SDSR_BUSY          FMC_SDSR_BUSY_Msk/*!<Busy status */

/******************************************************************************/
/*                                                                            */
/*                            General Purpose I/O                             */
/*                                                                            */
/******************************************************************************/
/******************  Bits definition for GPIO_MODER register  *****************/
#define GPIO_MODER_MODER0_Pos     (0U)
#define GPIO_MODER_MODER0_Msk     (0x3UL << GPIO_MODER_MODER0_Pos)	/*!< 0x00000003 */
#define GPIO_MODER_MODER0         GPIO_MODER_MODER0_Msk
#define GPIO_MODER_MODER0_0       (0x1UL << GPIO_MODER_MODER0_Pos)	/*!< 0x00000001 */
#define GPIO_MODER_MODER0_1       (0x2UL << GPIO_MODER_MODER0_Pos)	/*!< 0x00000002 */
#define GPIO_MODER_MODER1_Pos     (2U)
#define GPIO_MODER_MODER1_Msk     (0x3UL << GPIO_MODER_MODER1_Pos)	/*!< 0x0000000C */
#define GPIO_MODER_MODER1         GPIO_MODER_MODER1_Msk
#define GPIO_MODER_MODER1_0       (0x1UL << GPIO_MODER_MODER1_Pos)	/*!< 0x00000004 */
#define GPIO_MODER_MODER1_1       (0x2UL << GPIO_MODER_MODER1_Pos)	/*!< 0x00000008 */
#define GPIO_MODER_MODER2_Pos     (4U)
#define GPIO_MODER_MODER2_Msk     (0x3UL << GPIO_MODER_MODER2_Pos)	/*!< 0x00000030 */
#define GPIO_MODER_MODER2         GPIO_MODER_MODER2_Msk
#define GPIO_MODER_MODER2_0       (0x1UL << GPIO_MODER_MODER2_Pos)	/*!< 0x00000010 */
#define GPIO_MODER_MODER2_1       (0x2UL << GPIO_MODER_MODER2_Pos)	/*!< 0x00000020 */
#define GPIO_MODER_MODER3_Pos     (6U)
#define GPIO_MODER_MODER3_Msk     (0x3UL << GPIO_MODER_MODER3_Pos)	/*!< 0x000000C0 */
#define GPIO_MODER_MODER3         GPIO_MODER_MODER3_Msk
#define GPIO_MODER_MODER3_0       (0x1UL << GPIO_MODER_MODER3_Pos)	/*!< 0x00000040 */
#define GPIO_MODER_MODER3_1       (0x2UL << GPIO_MODER_MODER3_Pos)	/*!< 0x00000080 */
#define GPIO_MODER_MODER4_Pos     (8U)
#define GPIO_MODER_MODER4_Msk     (0x3UL << GPIO_MODER_MODER4_Pos)	/*!< 0x00000300 */
#define GPIO_MODER_MODER4         GPIO_MODER_MODER4_Msk
#define GPIO_MODER_MODER4_0       (0x1UL << GPIO_MODER_MODER4_Pos)	/*!< 0x00000100 */
#define GPIO_MODER_MODER4_1       (0x2UL << GPIO_MODER_MODER4_Pos)	/*!< 0x00000200 */
#define GPIO_MODER_MODER5_Pos     (10U)
#define GPIO_MODER_MODER5_Msk     (0x3UL << GPIO_MODER_MODER5_Pos)	/*!< 0x00000C00 */
#define GPIO_MODER_MODER5         GPIO_MODER_MODER5_Msk
#define GPIO_MODER_MODER5_0       (0x1UL << GPIO_MODER_MODER5_Pos)	/*!< 0x00000400 */
#define GPIO_MODER_MODER5_1       (0x2UL << GPIO_MODER_MODER5_Pos)	/*!< 0x00000800 */
#define GPIO_MODER_MODER6_Pos     (12U)
#define GPIO_MODER_MODER6_Msk     (0x3UL << GPIO_MODER_MODER6_Pos)	/*!< 0x00003000 */
#define GPIO_MODER_MODER6         GPIO_MODER_MODER6_Msk
#define GPIO_MODER_MODER6_0       (0x1UL << GPIO_MODER_MODER6_Pos)	/*!< 0x00001000 */
#define GPIO_MODER_MODER6_1       (0x2UL << GPIO_MODER_MODER6_Pos)	/*!< 0x00002000 */
#define GPIO_MODER_MODER7_Pos     (14U)
#define GPIO_MODER_MODER7_Msk     (0x3UL << GPIO_MODER_MODER7_Pos)	/*!< 0x0000C000 */
#define GPIO_MODER_MODER7         GPIO_MODER_MODER7_Msk
#define GPIO_MODER_MODER7_0       (0x1UL << GPIO_MODER_MODER7_Pos)	/*!< 0x00004000 */
#define GPIO_MODER_MODER7_1       (0x2UL << GPIO_MODER_MODER7_Pos)	/*!< 0x00008000 */
#define GPIO_MODER_MODER8_Pos     (16U)
#define GPIO_MODER_MODER8_Msk     (0x3UL << GPIO_MODER_MODER8_Pos)	/*!< 0x00030000 */
#define GPIO_MODER_MODER8         GPIO_MODER_MODER8_Msk
#define GPIO_MODER_MODER8_0       (0x1UL << GPIO_MODER_MODER8_Pos)	/*!< 0x00010000 */
#define GPIO_MODER_MODER8_1       (0x2UL << GPIO_MODER_MODER8_Pos)	/*!< 0x00020000 */
#define GPIO_MODER_MODER9_Pos     (18U)
#define GPIO_MODER_MODER9_Msk     (0x3UL << GPIO_MODER_MODER9_Pos)	/*!< 0x000C0000 */
#define GPIO_MODER_MODER9         GPIO_MODER_MODER9_Msk
#define GPIO_MODER_MODER9_0       (0x1UL << GPIO_MODER_MODER9_Pos)	/*!< 0x00040000 */
#define GPIO_MODER_MODER9_1       (0x2UL << GPIO_MODER_MODER9_Pos)	/*!< 0x00080000 */
#define GPIO_MODER_MODER10_Pos    (20U)
#define GPIO_MODER_MODER10_Msk    (0x3UL << GPIO_MODER_MODER10_Pos)	/*!< 0x00300000 */
#define GPIO_MODER_MODER10        GPIO_MODER_MODER10_Msk
#define GPIO_MODER_MODER10_0      (0x1UL << GPIO_MODER_MODER10_Pos)	/*!< 0x00100000 */
#define GPIO_MODER_MODER10_1      (0x2UL << GPIO_MODER_MODER10_Pos)	/*!< 0x00200000 */
#define GPIO_MODER_MODER11_Pos    (22U)
#define GPIO_MODER_MODER11_Msk    (0x3UL << GPIO_MODER_MODER11_Pos)	/*!< 0x00C00000 */
#define GPIO_MODER_MODER11        GPIO_MODER_MODER11_Msk
#define GPIO_MODER_MODER11_0      (0x1UL << GPIO_MODER_MODER11_Pos)	/*!< 0x00400000 */
#define GPIO_MODER_MODER11_1      (0x2UL << GPIO_MODER_MODER11_Pos)	/*!< 0x00800000 */
#define GPIO_MODER_MODER12_Pos    (24U)
#define GPIO_MODER_MODER12_Msk    (0x3UL << GPIO_MODER_MODER12_Pos)	/*!< 0x03000000 */
#define GPIO_MODER_MODER12        GPIO_MODER_MODER12_Msk
#define GPIO_MODER_MODER12_0      (0x1UL << GPIO_MODER_MODER12_Pos)	/*!< 0x01000000 */
#define GPIO_MODER_MODER12_1      (0x2UL << GPIO_MODER_MODER12_Pos)	/*!< 0x02000000 */
#define GPIO_MODER_MODER13_Pos    (26U)
#define GPIO_MODER_MODER13_Msk    (0x3UL << GPIO_MODER_MODER13_Pos)	/*!< 0x0C000000 */
#define GPIO_MODER_MODER13        GPIO_MODER_MODER13_Msk
#define GPIO_MODER_MODER13_0      (0x1UL << GPIO_MODER_MODER13_Pos)	/*!< 0x04000000 */
#define GPIO_MODER_MODER13_1      (0x2UL << GPIO_MODER_MODER13_Pos)	/*!< 0x08000000 */
#define GPIO_MODER_MODER14_Pos    (28U)
#define GPIO_MODER_MODER14_Msk    (0x3UL << GPIO_MODER_MODER14_Pos)	/*!< 0x30000000 */
#define GPIO_MODER_MODER14        GPIO_MODER_MODER14_Msk
#define GPIO_MODER_MODER14_0      (0x1UL << GPIO_MODER_MODER14_Pos)	/*!< 0x10000000 */
#define GPIO_MODER_MODER14_1      (0x2UL << GPIO_MODER_MODER14_Pos)	/*!< 0x20000000 */
#define GPIO_MODER_MODER15_Pos    (30U)
#define GPIO_MODER_MODER15_Msk    (0x3UL << GPIO_MODER_MODER15_Pos)	/*!< 0xC0000000 */
#define GPIO_MODER_MODER15        GPIO_MODER_MODER15_Msk
#define GPIO_MODER_MODER15_0      (0x1UL << GPIO_MODER_MODER15_Pos)	/*!< 0x40000000 */
#define GPIO_MODER_MODER15_1      (0x2UL << GPIO_MODER_MODER15_Pos)	/*!< 0x80000000 */

/******************  Bits definition for GPIO_OTYPER register  ****************/
#define GPIO_OTYPER_OT_0     0x00000001U
#define GPIO_OTYPER_OT_1     0x00000002U
#define GPIO_OTYPER_OT_2     0x00000004U
#define GPIO_OTYPER_OT_3     0x00000008U
#define GPIO_OTYPER_OT_4     0x00000010U
#define GPIO_OTYPER_OT_5     0x00000020U
#define GPIO_OTYPER_OT_6     0x00000040U
#define GPIO_OTYPER_OT_7     0x00000080U
#define GPIO_OTYPER_OT_8     0x00000100U
#define GPIO_OTYPER_OT_9     0x00000200U
#define GPIO_OTYPER_OT_10    0x00000400U
#define GPIO_OTYPER_OT_11    0x00000800U
#define GPIO_OTYPER_OT_12    0x00001000U
#define GPIO_OTYPER_OT_13    0x00002000U
#define GPIO_OTYPER_OT_14    0x00004000U
#define GPIO_OTYPER_OT_15    0x00008000U

/******************  Bits definition for GPIO_OSPEEDR register  ***************/
#define GPIO_OSPEEDER_OSPEEDR0_Pos     (0U)
#define GPIO_OSPEEDER_OSPEEDR0_Msk     (0x3UL << GPIO_OSPEEDER_OSPEEDR0_Pos)/*!< 0x00000003 */
#define GPIO_OSPEEDER_OSPEEDR0         GPIO_OSPEEDER_OSPEEDR0_Msk
#define GPIO_OSPEEDER_OSPEEDR0_0       (0x1UL << GPIO_OSPEEDER_OSPEEDR0_Pos)/*!< 0x00000001 */
#define GPIO_OSPEEDER_OSPEEDR0_1       (0x2UL << GPIO_OSPEEDER_OSPEEDR0_Pos)/*!< 0x00000002 */
#define GPIO_OSPEEDER_OSPEEDR1_Pos     (2U)
#define GPIO_OSPEEDER_OSPEEDR1_Msk     (0x3UL << GPIO_OSPEEDER_OSPEEDR1_Pos)/*!< 0x0000000C */
#define GPIO_OSPEEDER_OSPEEDR1         GPIO_OSPEEDER_OSPEEDR1_Msk
#define GPIO_OSPEEDER_OSPEEDR1_0       (0x1UL << GPIO_OSPEEDER_OSPEEDR1_Pos)/*!< 0x00000004 */
#define GPIO_OSPEEDER_OSPEEDR1_1       (0x2UL << GPIO_OSPEEDER_OSPEEDR1_Pos)/*!< 0x00000008 */
#define GPIO_OSPEEDER_OSPEEDR2_Pos     (4U)
#define GPIO_OSPEEDER_OSPEEDR2_Msk     (0x3UL << GPIO_OSPEEDER_OSPEEDR2_Pos)/*!< 0x00000030 */
#define GPIO_OSPEEDER_OSPEEDR2         GPIO_OSPEEDER_OSPEEDR2_Msk
#define GPIO_OSPEEDER_OSPEEDR2_0       (0x1UL << GPIO_OSPEEDER_OSPEEDR2_Pos)/*!< 0x00000010 */
#define GPIO_OSPEEDER_OSPEEDR2_1       (0x2UL << GPIO_OSPEEDER_OSPEEDR2_Pos)/*!< 0x00000020 */
#define GPIO_OSPEEDER_OSPEEDR3_Pos     (6U)
#define GPIO_OSPEEDER_OSPEEDR3_Msk     (0x3UL << GPIO_OSPEEDER_OSPEEDR3_Pos)/*!< 0x000000C0 */
#define GPIO_OSPEEDER_OSPEEDR3         GPIO_OSPEEDER_OSPEEDR3_Msk
#define GPIO_OSPEEDER_OSPEEDR3_0       (0x1UL << GPIO_OSPEEDER_OSPEEDR3_Pos)/*!< 0x00000040 */
#define GPIO_OSPEEDER_OSPEEDR3_1       (0x2UL << GPIO_OSPEEDER_OSPEEDR3_Pos)/*!< 0x00000080 */
#define GPIO_OSPEEDER_OSPEEDR4_Pos     (8U)
#define GPIO_OSPEEDER_OSPEEDR4_Msk     (0x3UL << GPIO_OSPEEDER_OSPEEDR4_Pos)/*!< 0x00000300 */
#define GPIO_OSPEEDER_OSPEEDR4         GPIO_OSPEEDER_OSPEEDR4_Msk
#define GPIO_OSPEEDER_OSPEEDR4_0       (0x1UL << GPIO_OSPEEDER_OSPEEDR4_Pos)/*!< 0x00000100 */
#define GPIO_OSPEEDER_OSPEEDR4_1       (0x2UL << GPIO_OSPEEDER_OSPEEDR4_Pos)/*!< 0x00000200 */
#define GPIO_OSPEEDER_OSPEEDR5_Pos     (10U)
#define GPIO_OSPEEDER_OSPEEDR5_Msk     (0x3UL << GPIO_OSPEEDER_OSPEEDR5_Pos)/*!< 0x00000C00 */
#define GPIO_OSPEEDER_OSPEEDR5         GPIO_OSPEEDER_OSPEEDR5_Msk
#define GPIO_OSPEEDER_OSPEEDR5_0       (0x1UL << GPIO_OSPEEDER_OSPEEDR5_Pos)/*!< 0x00000400 */
#define GPIO_OSPEEDER_OSPEEDR5_1       (0x2UL << GPIO_OSPEEDER_OSPEEDR5_Pos)/*!< 0x00000800 */
#define GPIO_OSPEEDER_OSPEEDR6_Pos     (12U)
#define GPIO_OSPEEDER_OSPEEDR6_Msk     (0x3UL << GPIO_OSPEEDER_OSPEEDR6_Pos)/*!< 0x00003000 */
#define GPIO_OSPEEDER_OSPEEDR6         GPIO_OSPEEDER_OSPEEDR6_Msk
#define GPIO_OSPEEDER_OSPEEDR6_0       (0x1UL << GPIO_OSPEEDER_OSPEEDR6_Pos)/*!< 0x00001000 */
#define GPIO_OSPEEDER_OSPEEDR6_1       (0x2UL << GPIO_OSPEEDER_OSPEEDR6_Pos)/*!< 0x00002000 */
#define GPIO_OSPEEDER_OSPEEDR7_Pos     (14U)
#define GPIO_OSPEEDER_OSPEEDR7_Msk     (0x3UL << GPIO_OSPEEDER_OSPEEDR7_Pos)/*!< 0x0000C000 */
#define GPIO_OSPEEDER_OSPEEDR7         GPIO_OSPEEDER_OSPEEDR7_Msk
#define GPIO_OSPEEDER_OSPEEDR7_0       (0x1UL << GPIO_OSPEEDER_OSPEEDR7_Pos)/*!< 0x00004000 */
#define GPIO_OSPEEDER_OSPEEDR7_1       (0x2UL << GPIO_OSPEEDER_OSPEEDR7_Pos)/*!< 0x00008000 */
#define GPIO_OSPEEDER_OSPEEDR8_Pos     (16U)
#define GPIO_OSPEEDER_OSPEEDR8_Msk     (0x3UL << GPIO_OSPEEDER_OSPEEDR8_Pos)/*!< 0x00030000 */
#define GPIO_OSPEEDER_OSPEEDR8         GPIO_OSPEEDER_OSPEEDR8_Msk
#define GPIO_OSPEEDER_OSPEEDR8_0       (0x1UL << GPIO_OSPEEDER_OSPEEDR8_Pos)/*!< 0x00010000 */
#define GPIO_OSPEEDER_OSPEEDR8_1       (0x2UL << GPIO_OSPEEDER_OSPEEDR8_Pos)/*!< 0x00020000 */
#define GPIO_OSPEEDER_OSPEEDR9_Pos     (18U)
#define GPIO_OSPEEDER_OSPEEDR9_Msk     (0x3UL << GPIO_OSPEEDER_OSPEEDR9_Pos)/*!< 0x000C0000 */
#define GPIO_OSPEEDER_OSPEEDR9         GPIO_OSPEEDER_OSPEEDR9_Msk
#define GPIO_OSPEEDER_OSPEEDR9_0       (0x1UL << GPIO_OSPEEDER_OSPEEDR9_Pos)/*!< 0x00040000 */
#define GPIO_OSPEEDER_OSPEEDR9_1       (0x2UL << GPIO_OSPEEDER_OSPEEDR9_Pos)/*!< 0x00080000 */
#define GPIO_OSPEEDER_OSPEEDR10_Pos    (20U)
#define GPIO_OSPEEDER_OSPEEDR10_Msk    (0x3UL << GPIO_OSPEEDER_OSPEEDR10_Pos)	/*!< 0x00300000 */
#define GPIO_OSPEEDER_OSPEEDR10        GPIO_OSPEEDER_OSPEEDR10_Msk
#define GPIO_OSPEEDER_OSPEEDR10_0      (0x1UL << GPIO_OSPEEDER_OSPEEDR10_Pos)	/*!< 0x00100000 */
#define GPIO_OSPEEDER_OSPEEDR10_1      (0x2UL << GPIO_OSPEEDER_OSPEEDR10_Pos)	/*!< 0x00200000 */
#define GPIO_OSPEEDER_OSPEEDR11_Pos    (22U)
#define GPIO_OSPEEDER_OSPEEDR11_Msk    (0x3UL << GPIO_OSPEEDER_OSPEEDR11_Pos)	/*!< 0x00C00000 */
#define GPIO_OSPEEDER_OSPEEDR11        GPIO_OSPEEDER_OSPEEDR11_Msk
#define GPIO_OSPEEDER_OSPEEDR11_0      (0x1UL << GPIO_OSPEEDER_OSPEEDR11_Pos)	/*!< 0x00400000 */
#define GPIO_OSPEEDER_OSPEEDR11_1      (0x2UL << GPIO_OSPEEDER_OSPEEDR11_Pos)	/*!< 0x00800000 */
#define GPIO_OSPEEDER_OSPEEDR12_Pos    (24U)
#define GPIO_OSPEEDER_OSPEEDR12_Msk    (0x3UL << GPIO_OSPEEDER_OSPEEDR12_Pos)	/*!< 0x03000000 */
#define GPIO_OSPEEDER_OSPEEDR12        GPIO_OSPEEDER_OSPEEDR12_Msk
#define GPIO_OSPEEDER_OSPEEDR12_0      (0x1UL << GPIO_OSPEEDER_OSPEEDR12_Pos)	/*!< 0x01000000 */
#define GPIO_OSPEEDER_OSPEEDR12_1      (0x2UL << GPIO_OSPEEDER_OSPEEDR12_Pos)	/*!< 0x02000000 */
#define GPIO_OSPEEDER_OSPEEDR13_Pos    (26U)
#define GPIO_OSPEEDER_OSPEEDR13_Msk    (0x3UL << GPIO_OSPEEDER_OSPEEDR13_Pos)	/*!< 0x0C000000 */
#define GPIO_OSPEEDER_OSPEEDR13        GPIO_OSPEEDER_OSPEEDR13_Msk
#define GPIO_OSPEEDER_OSPEEDR13_0      (0x1UL << GPIO_OSPEEDER_OSPEEDR13_Pos)	/*!< 0x04000000 */
#define GPIO_OSPEEDER_OSPEEDR13_1      (0x2UL << GPIO_OSPEEDER_OSPEEDR13_Pos)	/*!< 0x08000000 */
#define GPIO_OSPEEDER_OSPEEDR14_Pos    (28U)
#define GPIO_OSPEEDER_OSPEEDR14_Msk    (0x3UL << GPIO_OSPEEDER_OSPEEDR14_Pos)	/*!< 0x30000000 */
#define GPIO_OSPEEDER_OSPEEDR14        GPIO_OSPEEDER_OSPEEDR14_Msk
#define GPIO_OSPEEDER_OSPEEDR14_0      (0x1UL << GPIO_OSPEEDER_OSPEEDR14_Pos)	/*!< 0x10000000 */
#define GPIO_OSPEEDER_OSPEEDR14_1      (0x2UL << GPIO_OSPEEDER_OSPEEDR14_Pos)	/*!< 0x20000000 */
#define GPIO_OSPEEDER_OSPEEDR15_Pos    (30U)
#define GPIO_OSPEEDER_OSPEEDR15_Msk    (0x3UL << GPIO_OSPEEDER_OSPEEDR15_Pos)	/*!< 0xC0000000 */
#define GPIO_OSPEEDER_OSPEEDR15        GPIO_OSPEEDER_OSPEEDR15_Msk
#define GPIO_OSPEEDER_OSPEEDR15_0      (0x1UL << GPIO_OSPEEDER_OSPEEDR15_Pos)	/*!< 0x40000000 */
#define GPIO_OSPEEDER_OSPEEDR15_1      (0x2UL << GPIO_OSPEEDER_OSPEEDR15_Pos)	/*!< 0x80000000 */

/******************  Bits definition for GPIO_PUPDR register  *****************/
#define GPIO_PUPDR_PUPDR0_Pos     (0U)
#define GPIO_PUPDR_PUPDR0_Msk     (0x3UL << GPIO_PUPDR_PUPDR0_Pos)	/*!< 0x00000003 */
#define GPIO_PUPDR_PUPDR0         GPIO_PUPDR_PUPDR0_Msk
#define GPIO_PUPDR_PUPDR0_0       (0x1UL << GPIO_PUPDR_PUPDR0_Pos)	/*!< 0x00000001 */
#define GPIO_PUPDR_PUPDR0_1       (0x2UL << GPIO_PUPDR_PUPDR0_Pos)	/*!< 0x00000002 */
#define GPIO_PUPDR_PUPDR1_Pos     (2U)
#define GPIO_PUPDR_PUPDR1_Msk     (0x3UL << GPIO_PUPDR_PUPDR1_Pos)	/*!< 0x0000000C */
#define GPIO_PUPDR_PUPDR1         GPIO_PUPDR_PUPDR1_Msk
#define GPIO_PUPDR_PUPDR1_0       (0x1UL << GPIO_PUPDR_PUPDR1_Pos)	/*!< 0x00000004 */
#define GPIO_PUPDR_PUPDR1_1       (0x2UL << GPIO_PUPDR_PUPDR1_Pos)	/*!< 0x00000008 */
#define GPIO_PUPDR_PUPDR2_Pos     (4U)
#define GPIO_PUPDR_PUPDR2_Msk     (0x3UL << GPIO_PUPDR_PUPDR2_Pos)	/*!< 0x00000030 */
#define GPIO_PUPDR_PUPDR2         GPIO_PUPDR_PUPDR2_Msk
#define GPIO_PUPDR_PUPDR2_0       (0x1UL << GPIO_PUPDR_PUPDR2_Pos)	/*!< 0x00000010 */
#define GPIO_PUPDR_PUPDR2_1       (0x2UL << GPIO_PUPDR_PUPDR2_Pos)	/*!< 0x00000020 */
#define GPIO_PUPDR_PUPDR3_Pos     (6U)
#define GPIO_PUPDR_PUPDR3_Msk     (0x3UL << GPIO_PUPDR_PUPDR3_Pos)	/*!< 0x000000C0 */
#define GPIO_PUPDR_PUPDR3         GPIO_PUPDR_PUPDR3_Msk
#define GPIO_PUPDR_PUPDR3_0       (0x1UL << GPIO_PUPDR_PUPDR3_Pos)	/*!< 0x00000040 */
#define GPIO_PUPDR_PUPDR3_1       (0x2UL << GPIO_PUPDR_PUPDR3_Pos)	/*!< 0x00000080 */
#define GPIO_PUPDR_PUPDR4_Pos     (8U)
#define GPIO_PUPDR_PUPDR4_Msk     (0x3UL << GPIO_PUPDR_PUPDR4_Pos)	/*!< 0x00000300 */
#define GPIO_PUPDR_PUPDR4         GPIO_PUPDR_PUPDR4_Msk
#define GPIO_PUPDR_PUPDR4_0       (0x1UL << GPIO_PUPDR_PUPDR4_Pos)	/*!< 0x00000100 */
#define GPIO_PUPDR_PUPDR4_1       (0x2UL << GPIO_PUPDR_PUPDR4_Pos)	/*!< 0x00000200 */
#define GPIO_PUPDR_PUPDR5_Pos     (10U)
#define GPIO_PUPDR_PUPDR5_Msk     (0x3UL << GPIO_PUPDR_PUPDR5_Pos)	/*!< 0x00000C00 */
#define GPIO_PUPDR_PUPDR5         GPIO_PUPDR_PUPDR5_Msk
#define GPIO_PUPDR_PUPDR5_0       (0x1UL << GPIO_PUPDR_PUPDR5_Pos)	/*!< 0x00000400 */
#define GPIO_PUPDR_PUPDR5_1       (0x2UL << GPIO_PUPDR_PUPDR5_Pos)	/*!< 0x00000800 */
#define GPIO_PUPDR_PUPDR6_Pos     (12U)
#define GPIO_PUPDR_PUPDR6_Msk     (0x3UL << GPIO_PUPDR_PUPDR6_Pos)	/*!< 0x00003000 */
#define GPIO_PUPDR_PUPDR6         GPIO_PUPDR_PUPDR6_Msk
#define GPIO_PUPDR_PUPDR6_0       (0x1UL << GPIO_PUPDR_PUPDR6_Pos)	/*!< 0x00001000 */
#define GPIO_PUPDR_PUPDR6_1       (0x2UL << GPIO_PUPDR_PUPDR6_Pos)	/*!< 0x00002000 */
#define GPIO_PUPDR_PUPDR7_Pos     (14U)
#define GPIO_PUPDR_PUPDR7_Msk     (0x3UL << GPIO_PUPDR_PUPDR7_Pos)	/*!< 0x0000C000 */
#define GPIO_PUPDR_PUPDR7         GPIO_PUPDR_PUPDR7_Msk
#define GPIO_PUPDR_PUPDR7_0       (0x1UL << GPIO_PUPDR_PUPDR7_Pos)	/*!< 0x00004000 */
#define GPIO_PUPDR_PUPDR7_1       (0x2UL << GPIO_PUPDR_PUPDR7_Pos)	/*!< 0x00008000 */
#define GPIO_PUPDR_PUPDR8_Pos     (16U)
#define GPIO_PUPDR_PUPDR8_Msk     (0x3UL << GPIO_PUPDR_PUPDR8_Pos)	/*!< 0x00030000 */
#define GPIO_PUPDR_PUPDR8         GPIO_PUPDR_PUPDR8_Msk
#define GPIO_PUPDR_PUPDR8_0       (0x1UL << GPIO_PUPDR_PUPDR8_Pos)	/*!< 0x00010000 */
#define GPIO_PUPDR_PUPDR8_1       (0x2UL << GPIO_PUPDR_PUPDR8_Pos)	/*!< 0x00020000 */
#define GPIO_PUPDR_PUPDR9_Pos     (18U)
#define GPIO_PUPDR_PUPDR9_Msk     (0x3UL << GPIO_PUPDR_PUPDR9_Pos)	/*!< 0x000C0000 */
#define GPIO_PUPDR_PUPDR9         GPIO_PUPDR_PUPDR9_Msk
#define GPIO_PUPDR_PUPDR9_0       (0x1UL << GPIO_PUPDR_PUPDR9_Pos)	/*!< 0x00040000 */
#define GPIO_PUPDR_PUPDR9_1       (0x2UL << GPIO_PUPDR_PUPDR9_Pos)	/*!< 0x00080000 */
#define GPIO_PUPDR_PUPDR10_Pos    (20U)
#define GPIO_PUPDR_PUPDR10_Msk    (0x3UL << GPIO_PUPDR_PUPDR10_Pos)	/*!< 0x00300000 */
#define GPIO_PUPDR_PUPDR10        GPIO_PUPDR_PUPDR10_Msk
#define GPIO_PUPDR_PUPDR10_0      (0x1UL << GPIO_PUPDR_PUPDR10_Pos)	/*!< 0x00100000 */
#define GPIO_PUPDR_PUPDR10_1      (0x2UL << GPIO_PUPDR_PUPDR10_Pos)	/*!< 0x00200000 */
#define GPIO_PUPDR_PUPDR11_Pos    (22U)
#define GPIO_PUPDR_PUPDR11_Msk    (0x3UL << GPIO_PUPDR_PUPDR11_Pos)	/*!< 0x00C00000 */
#define GPIO_PUPDR_PUPDR11        GPIO_PUPDR_PUPDR11_Msk
#define GPIO_PUPDR_PUPDR11_0      (0x1UL << GPIO_PUPDR_PUPDR11_Pos)	/*!< 0x00400000 */
#define GPIO_PUPDR_PUPDR11_1      (0x2UL << GPIO_PUPDR_PUPDR11_Pos)	/*!< 0x00800000 */
#define GPIO_PUPDR_PUPDR12_Pos    (24U)
#define GPIO_PUPDR_PUPDR12_Msk    (0x3UL << GPIO_PUPDR_PUPDR12_Pos)	/*!< 0x03000000 */
#define GPIO_PUPDR_PUPDR12        GPIO_PUPDR_PUPDR12_Msk
#define GPIO_PUPDR_PUPDR12_0      (0x1UL << GPIO_PUPDR_PUPDR12_Pos)	/*!< 0x01000000 */
#define GPIO_PUPDR_PUPDR12_1      (0x2UL << GPIO_PUPDR_PUPDR12_Pos)	/*!< 0x02000000 */
#define GPIO_PUPDR_PUPDR13_Pos    (26U)
#define GPIO_PUPDR_PUPDR13_Msk    (0x3UL << GPIO_PUPDR_PUPDR13_Pos)	/*!< 0x0C000000 */
#define GPIO_PUPDR_PUPDR13        GPIO_PUPDR_PUPDR13_Msk
#define GPIO_PUPDR_PUPDR13_0      (0x1UL << GPIO_PUPDR_PUPDR13_Pos)	/*!< 0x04000000 */
#define GPIO_PUPDR_PUPDR13_1      (0x2UL << GPIO_PUPDR_PUPDR13_Pos)	/*!< 0x08000000 */
#define GPIO_PUPDR_PUPDR14_Pos    (28U)
#define GPIO_PUPDR_PUPDR14_Msk    (0x3UL << GPIO_PUPDR_PUPDR14_Pos)	/*!< 0x30000000 */
#define GPIO_PUPDR_PUPDR14        GPIO_PUPDR_PUPDR14_Msk
#define GPIO_PUPDR_PUPDR14_0      (0x1UL << GPIO_PUPDR_PUPDR14_Pos)	/*!< 0x10000000 */
#define GPIO_PUPDR_PUPDR14_1      (0x2UL << GPIO_PUPDR_PUPDR14_Pos)	/*!< 0x20000000 */
#define GPIO_PUPDR_PUPDR15_Pos    (30U)
#define GPIO_PUPDR_PUPDR15_Msk    (0x3UL << GPIO_PUPDR_PUPDR15_Pos)	/*!< 0xC0000000 */
#define GPIO_PUPDR_PUPDR15        GPIO_PUPDR_PUPDR15_Msk
#define GPIO_PUPDR_PUPDR15_0      (0x1UL << GPIO_PUPDR_PUPDR15_Pos)	/*!< 0x40000000 */
#define GPIO_PUPDR_PUPDR15_1      (0x2UL << GPIO_PUPDR_PUPDR15_Pos)	/*!< 0x80000000 */

/******************  Bits definition for GPIO_IDR register  *******************/
#define GPIO_IDR_IDR_0     0x00000001U
#define GPIO_IDR_IDR_1     0x00000002U
#define GPIO_IDR_IDR_2     0x00000004U
#define GPIO_IDR_IDR_3     0x00000008U
#define GPIO_IDR_IDR_4     0x00000010U
#define GPIO_IDR_IDR_5     0x00000020U
#define GPIO_IDR_IDR_6     0x00000040U
#define GPIO_IDR_IDR_7     0x00000080U
#define GPIO_IDR_IDR_8     0x00000100U
#define GPIO_IDR_IDR_9     0x00000200U
#define GPIO_IDR_IDR_10    0x00000400U
#define GPIO_IDR_IDR_11    0x00000800U
#define GPIO_IDR_IDR_12    0x00001000U
#define GPIO_IDR_IDR_13    0x00002000U
#define GPIO_IDR_IDR_14    0x00004000U
#define GPIO_IDR_IDR_15    0x00008000U

/******************  Bits definition for GPIO_ODR register  *******************/
#define GPIO_ODR_ODR_0     0x00000001U
#define GPIO_ODR_ODR_1     0x00000002U
#define GPIO_ODR_ODR_2     0x00000004U
#define GPIO_ODR_ODR_3     0x00000008U
#define GPIO_ODR_ODR_4     0x00000010U
#define GPIO_ODR_ODR_5     0x00000020U
#define GPIO_ODR_ODR_6     0x00000040U
#define GPIO_ODR_ODR_7     0x00000080U
#define GPIO_ODR_ODR_8     0x00000100U
#define GPIO_ODR_ODR_9     0x00000200U
#define GPIO_ODR_ODR_10    0x00000400U
#define GPIO_ODR_ODR_11    0x00000800U
#define GPIO_ODR_ODR_12    0x00001000U
#define GPIO_ODR_ODR_13    0x00002000U
#define GPIO_ODR_ODR_14    0x00004000U
#define GPIO_ODR_ODR_15    0x00008000U

/******************  Bits definition for GPIO_BSRR register  ******************/
#define GPIO_BSRR_BS_0     0x00000001U
#define GPIO_BSRR_BS_1     0x00000002U
#define GPIO_BSRR_BS_2     0x00000004U
#define GPIO_BSRR_BS_3     0x00000008U
#define GPIO_BSRR_BS_4     0x00000010U
#define GPIO_BSRR_BS_5     0x00000020U
#define GPIO_BSRR_BS_6     0x00000040U
#define GPIO_BSRR_BS_7     0x00000080U
#define GPIO_BSRR_BS_8     0x00000100U
#define GPIO_BSRR_BS_9     0x00000200U
#define GPIO_BSRR_BS_10    0x00000400U
#define GPIO_BSRR_BS_11    0x00000800U
#define GPIO_BSRR_BS_12    0x00001000U
#define GPIO_BSRR_BS_13    0x00002000U
#define GPIO_BSRR_BS_14    0x00004000U
#define GPIO_BSRR_BS_15    0x00008000U
#define GPIO_BSRR_BR_0     0x00010000U
#define GPIO_BSRR_BR_1     0x00020000U
#define GPIO_BSRR_BR_2     0x00040000U
#define GPIO_BSRR_BR_3     0x00080000U
#define GPIO_BSRR_BR_4     0x00100000U
#define GPIO_BSRR_BR_5     0x00200000U
#define GPIO_BSRR_BR_6     0x00400000U
#define GPIO_BSRR_BR_7     0x00800000U
#define GPIO_BSRR_BR_8     0x01000000U
#define GPIO_BSRR_BR_9     0x02000000U
#define GPIO_BSRR_BR_10    0x04000000U
#define GPIO_BSRR_BR_11    0x08000000U
#define GPIO_BSRR_BR_12    0x10000000U
#define GPIO_BSRR_BR_13    0x20000000U
#define GPIO_BSRR_BR_14    0x40000000U
#define GPIO_BSRR_BR_15    0x80000000U

/****************** Bit definition for GPIO_LCKR register *********************/
#define GPIO_LCKR_LCK0_Pos     (0U)
#define GPIO_LCKR_LCK0_Msk     (0x1UL << GPIO_LCKR_LCK0_Pos)/*!< 0x00000001 */
#define GPIO_LCKR_LCK0         GPIO_LCKR_LCK0_Msk
#define GPIO_LCKR_LCK1_Pos     (1U)
#define GPIO_LCKR_LCK1_Msk     (0x1UL << GPIO_LCKR_LCK1_Pos)/*!< 0x00000002 */
#define GPIO_LCKR_LCK1         GPIO_LCKR_LCK1_Msk
#define GPIO_LCKR_LCK2_Pos     (2U)
#define GPIO_LCKR_LCK2_Msk     (0x1UL << GPIO_LCKR_LCK2_Pos)/*!< 0x00000004 */
#define GPIO_LCKR_LCK2         GPIO_LCKR_LCK2_Msk
#define GPIO_LCKR_LCK3_Pos     (3U)
#define GPIO_LCKR_LCK3_Msk     (0x1UL << GPIO_LCKR_LCK3_Pos)/*!< 0x00000008 */
#define GPIO_LCKR_LCK3         GPIO_LCKR_LCK3_Msk
#define GPIO_LCKR_LCK4_Pos     (4U)
#define GPIO_LCKR_LCK4_Msk     (0x1UL << GPIO_LCKR_LCK4_Pos)/*!< 0x00000010 */
#define GPIO_LCKR_LCK4         GPIO_LCKR_LCK4_Msk
#define GPIO_LCKR_LCK5_Pos     (5U)
#define GPIO_LCKR_LCK5_Msk     (0x1UL << GPIO_LCKR_LCK5_Pos)/*!< 0x00000020 */
#define GPIO_LCKR_LCK5         GPIO_LCKR_LCK5_Msk
#define GPIO_LCKR_LCK6_Pos     (6U)
#define GPIO_LCKR_LCK6_Msk     (0x1UL << GPIO_LCKR_LCK6_Pos)/*!< 0x00000040 */
#define GPIO_LCKR_LCK6         GPIO_LCKR_LCK6_Msk
#define GPIO_LCKR_LCK7_Pos     (7U)
#define GPIO_LCKR_LCK7_Msk     (0x1UL << GPIO_LCKR_LCK7_Pos)/*!< 0x00000080 */
#define GPIO_LCKR_LCK7         GPIO_LCKR_LCK7_Msk
#define GPIO_LCKR_LCK8_Pos     (8U)
#define GPIO_LCKR_LCK8_Msk     (0x1UL << GPIO_LCKR_LCK8_Pos)/*!< 0x00000100 */
#define GPIO_LCKR_LCK8         GPIO_LCKR_LCK8_Msk
#define GPIO_LCKR_LCK9_Pos     (9U)
#define GPIO_LCKR_LCK9_Msk     (0x1UL << GPIO_LCKR_LCK9_Pos)/*!< 0x00000200 */
#define GPIO_LCKR_LCK9         GPIO_LCKR_LCK9_Msk
#define GPIO_LCKR_LCK10_Pos    (10U)
#define GPIO_LCKR_LCK10_Msk    (0x1UL << GPIO_LCKR_LCK10_Pos)	/*!< 0x00000400 */
#define GPIO_LCKR_LCK10        GPIO_LCKR_LCK10_Msk
#define GPIO_LCKR_LCK11_Pos    (11U)
#define GPIO_LCKR_LCK11_Msk    (0x1UL << GPIO_LCKR_LCK11_Pos)	/*!< 0x00000800 */
#define GPIO_LCKR_LCK11        GPIO_LCKR_LCK11_Msk
#define GPIO_LCKR_LCK12_Pos    (12U)
#define GPIO_LCKR_LCK12_Msk    (0x1UL << GPIO_LCKR_LCK12_Pos)	/*!< 0x00001000 */
#define GPIO_LCKR_LCK12        GPIO_LCKR_LCK12_Msk
#define GPIO_LCKR_LCK13_Pos    (13U)
#define GPIO_LCKR_LCK13_Msk    (0x1UL << GPIO_LCKR_LCK13_Pos)	/*!< 0x00002000 */
#define GPIO_LCKR_LCK13        GPIO_LCKR_LCK13_Msk
#define GPIO_LCKR_LCK14_Pos    (14U)
#define GPIO_LCKR_LCK14_Msk    (0x1UL << GPIO_LCKR_LCK14_Pos)	/*!< 0x00004000 */
#define GPIO_LCKR_LCK14        GPIO_LCKR_LCK14_Msk
#define GPIO_LCKR_LCK15_Pos    (15U)
#define GPIO_LCKR_LCK15_Msk    (0x1UL << GPIO_LCKR_LCK15_Pos)	/*!< 0x00008000 */
#define GPIO_LCKR_LCK15        GPIO_LCKR_LCK15_Msk
#define GPIO_LCKR_LCKK_Pos     (16U)
#define GPIO_LCKR_LCKK_Msk     (0x1UL << GPIO_LCKR_LCKK_Pos)/*!< 0x00010000 */
#define GPIO_LCKR_LCKK         GPIO_LCKR_LCKK_Msk

/****************** Bit definition for GPIO_AFRL register *********************/
#define GPIO_AFRL_AFRL0_Pos    (0U)
#define GPIO_AFRL_AFRL0_Msk    (0xFUL << GPIO_AFRL_AFRL0_Pos)	/*!< 0x0000000F */
#define GPIO_AFRL_AFRL0        GPIO_AFRL_AFRL0_Msk
#define GPIO_AFRL_AFRL0_0      (0x1UL << GPIO_AFRL_AFRL0_Pos)	/*!< 0x00000001 */
#define GPIO_AFRL_AFRL0_1      (0x2UL << GPIO_AFRL_AFRL0_Pos)	/*!< 0x00000002 */
#define GPIO_AFRL_AFRL0_2      (0x4UL << GPIO_AFRL_AFRL0_Pos)	/*!< 0x00000004 */
#define GPIO_AFRL_AFRL0_3      (0x8UL << GPIO_AFRL_AFRL0_Pos)	/*!< 0x00000008 */
#define GPIO_AFRL_AFRL1_Pos    (4U)
#define GPIO_AFRL_AFRL1_Msk    (0xFUL << GPIO_AFRL_AFRL1_Pos)	/*!< 0x000000F0 */
#define GPIO_AFRL_AFRL1        GPIO_AFRL_AFRL1_Msk
#define GPIO_AFRL_AFRL1_0      (0x1UL << GPIO_AFRL_AFRL1_Pos)	/*!< 0x00000010 */
#define GPIO_AFRL_AFRL1_1      (0x2UL << GPIO_AFRL_AFRL1_Pos)	/*!< 0x00000020 */
#define GPIO_AFRL_AFRL1_2      (0x4UL << GPIO_AFRL_AFRL1_Pos)	/*!< 0x00000040 */
#define GPIO_AFRL_AFRL1_3      (0x8UL << GPIO_AFRL_AFRL1_Pos)	/*!< 0x00000080 */
#define GPIO_AFRL_AFRL2_Pos    (8U)
#define GPIO_AFRL_AFRL2_Msk    (0xFUL << GPIO_AFRL_AFRL2_Pos)	/*!< 0x00000F00 */
#define GPIO_AFRL_AFRL2        GPIO_AFRL_AFRL2_Msk
#define GPIO_AFRL_AFRL2_0      (0x1UL << GPIO_AFRL_AFRL2_Pos)	/*!< 0x00000100 */
#define GPIO_AFRL_AFRL2_1      (0x2UL << GPIO_AFRL_AFRL2_Pos)	/*!< 0x00000200 */
#define GPIO_AFRL_AFRL2_2      (0x4UL << GPIO_AFRL_AFRL2_Pos)	/*!< 0x00000400 */
#define GPIO_AFRL_AFRL2_3      (0x8UL << GPIO_AFRL_AFRL2_Pos)	/*!< 0x00000800 */
#define GPIO_AFRL_AFRL3_Pos    (12U)
#define GPIO_AFRL_AFRL3_Msk    (0xFUL << GPIO_AFRL_AFRL3_Pos)	/*!< 0x0000F000 */
#define GPIO_AFRL_AFRL3        GPIO_AFRL_AFRL3_Msk
#define GPIO_AFRL_AFRL3_0      (0x1UL << GPIO_AFRL_AFRL3_Pos)	/*!< 0x00001000 */
#define GPIO_AFRL_AFRL3_1      (0x2UL << GPIO_AFRL_AFRL3_Pos)	/*!< 0x00002000 */
#define GPIO_AFRL_AFRL3_2      (0x4UL << GPIO_AFRL_AFRL3_Pos)	/*!< 0x00004000 */
#define GPIO_AFRL_AFRL3_3      (0x8UL << GPIO_AFRL_AFRL3_Pos)	/*!< 0x00008000 */
#define GPIO_AFRL_AFRL4_Pos    (16U)
#define GPIO_AFRL_AFRL4_Msk    (0xFUL << GPIO_AFRL_AFRL4_Pos)	/*!< 0x000F0000 */
#define GPIO_AFRL_AFRL4        GPIO_AFRL_AFRL4_Msk
#define GPIO_AFRL_AFRL4_0      (0x1UL << GPIO_AFRL_AFRL4_Pos)	/*!< 0x00010000 */
#define GPIO_AFRL_AFRL4_1      (0x2UL << GPIO_AFRL_AFRL4_Pos)	/*!< 0x00020000 */
#define GPIO_AFRL_AFRL4_2      (0x4UL << GPIO_AFRL_AFRL4_Pos)	/*!< 0x00040000 */
#define GPIO_AFRL_AFRL4_3      (0x8UL << GPIO_AFRL_AFRL4_Pos)	/*!< 0x00080000 */
#define GPIO_AFRL_AFRL5_Pos    (20U)
#define GPIO_AFRL_AFRL5_Msk    (0xFUL << GPIO_AFRL_AFRL5_Pos)	/*!< 0x00F00000 */
#define GPIO_AFRL_AFRL5        GPIO_AFRL_AFRL5_Msk
#define GPIO_AFRL_AFRL5_0      (0x1UL << GPIO_AFRL_AFRL5_Pos)	/*!< 0x00100000 */
#define GPIO_AFRL_AFRL5_1      (0x2UL << GPIO_AFRL_AFRL5_Pos)	/*!< 0x00200000 */
#define GPIO_AFRL_AFRL5_2      (0x4UL << GPIO_AFRL_AFRL5_Pos)	/*!< 0x00400000 */
#define GPIO_AFRL_AFRL5_3      (0x8UL << GPIO_AFRL_AFRL5_Pos)	/*!< 0x00800000 */
#define GPIO_AFRL_AFRL6_Pos    (24U)
#define GPIO_AFRL_AFRL6_Msk    (0xFUL << GPIO_AFRL_AFRL6_Pos)	/*!< 0x0F000000 */
#define GPIO_AFRL_AFRL6        GPIO_AFRL_AFRL6_Msk
#define GPIO_AFRL_AFRL6_0      (0x1UL << GPIO_AFRL_AFRL6_Pos)	/*!< 0x01000000 */
#define GPIO_AFRL_AFRL6_1      (0x2UL << GPIO_AFRL_AFRL6_Pos)	/*!< 0x02000000 */
#define GPIO_AFRL_AFRL6_2      (0x4UL << GPIO_AFRL_AFRL6_Pos)	/*!< 0x04000000 */
#define GPIO_AFRL_AFRL6_3      (0x8UL << GPIO_AFRL_AFRL6_Pos)	/*!< 0x08000000 */
#define GPIO_AFRL_AFRL7_Pos    (28U)
#define GPIO_AFRL_AFRL7_Msk    (0xFUL << GPIO_AFRL_AFRL7_Pos)	/*!< 0xF0000000 */
#define GPIO_AFRL_AFRL7        GPIO_AFRL_AFRL7_Msk
#define GPIO_AFRL_AFRL7_0      (0x1UL << GPIO_AFRL_AFRL7_Pos)	/*!< 0x10000000 */
#define GPIO_AFRL_AFRL7_1      (0x2UL << GPIO_AFRL_AFRL7_Pos)	/*!< 0x20000000 */
#define GPIO_AFRL_AFRL7_2      (0x4UL << GPIO_AFRL_AFRL7_Pos)	/*!< 0x40000000 */
#define GPIO_AFRL_AFRL7_3      (0x8UL << GPIO_AFRL_AFRL7_Pos)	/*!< 0x80000000 */

/****************** Bit definition for GPIO_AFRH register *********************/
#define GPIO_AFRH_AFRH0_Pos    (0U)
#define GPIO_AFRH_AFRH0_Msk    (0xFUL << GPIO_AFRH_AFRH0_Pos)	/*!< 0x0000000F */
#define GPIO_AFRH_AFRH0        GPIO_AFRH_AFRH0_Msk
#define GPIO_AFRH_AFRH0_0      (0x1UL << GPIO_AFRH_AFRH0_Pos)	/*!< 0x00000001 */
#define GPIO_AFRH_AFRH0_1      (0x2UL << GPIO_AFRH_AFRH0_Pos)	/*!< 0x00000002 */
#define GPIO_AFRH_AFRH0_2      (0x4UL << GPIO_AFRH_AFRH0_Pos)	/*!< 0x00000004 */
#define GPIO_AFRH_AFRH0_3      (0x8UL << GPIO_AFRH_AFRH0_Pos)	/*!< 0x00000008 */
#define GPIO_AFRH_AFRH1_Pos    (4U)
#define GPIO_AFRH_AFRH1_Msk    (0xFUL << GPIO_AFRH_AFRH1_Pos)	/*!< 0x000000F0 */
#define GPIO_AFRH_AFRH1        GPIO_AFRH_AFRH1_Msk
#define GPIO_AFRH_AFRH1_0      (0x1UL << GPIO_AFRH_AFRH1_Pos)	/*!< 0x00000010 */
#define GPIO_AFRH_AFRH1_1      (0x2UL << GPIO_AFRH_AFRH1_Pos)	/*!< 0x00000020 */
#define GPIO_AFRH_AFRH1_2      (0x4UL << GPIO_AFRH_AFRH1_Pos)	/*!< 0x00000040 */
#define GPIO_AFRH_AFRH1_3      (0x8UL << GPIO_AFRH_AFRH1_Pos)	/*!< 0x00000080 */
#define GPIO_AFRH_AFRH2_Pos    (8U)
#define GPIO_AFRH_AFRH2_Msk    (0xFUL << GPIO_AFRH_AFRH2_Pos)	/*!< 0x00000F00 */
#define GPIO_AFRH_AFRH2        GPIO_AFRH_AFRH2_Msk
#define GPIO_AFRH_AFRH2_0      (0x1UL << GPIO_AFRH_AFRH2_Pos)	/*!< 0x00000100 */
#define GPIO_AFRH_AFRH2_1      (0x2UL << GPIO_AFRH_AFRH2_Pos)	/*!< 0x00000200 */
#define GPIO_AFRH_AFRH2_2      (0x4UL << GPIO_AFRH_AFRH2_Pos)	/*!< 0x00000400 */
#define GPIO_AFRH_AFRH2_3      (0x8UL << GPIO_AFRH_AFRH2_Pos)	/*!< 0x00000800 */
#define GPIO_AFRH_AFRH3_Pos    (12U)
#define GPIO_AFRH_AFRH3_Msk    (0xFUL << GPIO_AFRH_AFRH3_Pos)	/*!< 0x0000F000 */
#define GPIO_AFRH_AFRH3        GPIO_AFRH_AFRH3_Msk
#define GPIO_AFRH_AFRH3_0      (0x1UL << GPIO_AFRH_AFRH3_Pos)	/*!< 0x00001000 */
#define GPIO_AFRH_AFRH3_1      (0x2UL << GPIO_AFRH_AFRH3_Pos)	/*!< 0x00002000 */
#define GPIO_AFRH_AFRH3_2      (0x4UL << GPIO_AFRH_AFRH3_Pos)	/*!< 0x00004000 */
#define GPIO_AFRH_AFRH3_3      (0x8UL << GPIO_AFRH_AFRH3_Pos)	/*!< 0x00008000 */
#define GPIO_AFRH_AFRH4_Pos    (16U)
#define GPIO_AFRH_AFRH4_Msk    (0xFUL << GPIO_AFRH_AFRH4_Pos)	/*!< 0x000F0000 */
#define GPIO_AFRH_AFRH4        GPIO_AFRH_AFRH4_Msk
#define GPIO_AFRH_AFRH4_0      (0x1UL << GPIO_AFRH_AFRH4_Pos)	/*!< 0x00010000 */
#define GPIO_AFRH_AFRH4_1      (0x2UL << GPIO_AFRH_AFRH4_Pos)	/*!< 0x00020000 */
#define GPIO_AFRH_AFRH4_2      (0x4UL << GPIO_AFRH_AFRH4_Pos)	/*!< 0x00040000 */
#define GPIO_AFRH_AFRH4_3      (0x8UL << GPIO_AFRH_AFRH4_Pos)	/*!< 0x00080000 */
#define GPIO_AFRH_AFRH5_Pos    (20U)
#define GPIO_AFRH_AFRH5_Msk    (0xFUL << GPIO_AFRH_AFRH5_Pos)	/*!< 0x00F00000 */
#define GPIO_AFRH_AFRH5        GPIO_AFRH_AFRH5_Msk
#define GPIO_AFRH_AFRH5_0      (0x1UL << GPIO_AFRH_AFRH5_Pos)	/*!< 0x00100000 */
#define GPIO_AFRH_AFRH5_1      (0x2UL << GPIO_AFRH_AFRH5_Pos)	/*!< 0x00200000 */
#define GPIO_AFRH_AFRH5_2      (0x4UL << GPIO_AFRH_AFRH5_Pos)	/*!< 0x00400000 */
#define GPIO_AFRH_AFRH5_3      (0x8UL << GPIO_AFRH_AFRH5_Pos)	/*!< 0x00800000 */
#define GPIO_AFRH_AFRH6_Pos    (24U)
#define GPIO_AFRH_AFRH6_Msk    (0xFUL << GPIO_AFRH_AFRH6_Pos)	/*!< 0x0F000000 */
#define GPIO_AFRH_AFRH6        GPIO_AFRH_AFRH6_Msk
#define GPIO_AFRH_AFRH6_0      (0x1UL << GPIO_AFRH_AFRH6_Pos)	/*!< 0x01000000 */
#define GPIO_AFRH_AFRH6_1      (0x2UL << GPIO_AFRH_AFRH6_Pos)	/*!< 0x02000000 */
#define GPIO_AFRH_AFRH6_2      (0x4UL << GPIO_AFRH_AFRH6_Pos)	/*!< 0x04000000 */
#define GPIO_AFRH_AFRH6_3      (0x8UL << GPIO_AFRH_AFRH6_Pos)	/*!< 0x08000000 */
#define GPIO_AFRH_AFRH7_Pos    (28U)
#define GPIO_AFRH_AFRH7_Msk    (0xFUL << GPIO_AFRH_AFRH7_Pos)	/*!< 0xF0000000 */
#define GPIO_AFRH_AFRH7        GPIO_AFRH_AFRH7_Msk
#define GPIO_AFRH_AFRH7_0      (0x1UL << GPIO_AFRH_AFRH7_Pos)	/*!< 0x10000000 */
#define GPIO_AFRH_AFRH7_1      (0x2UL << GPIO_AFRH_AFRH7_Pos)	/*!< 0x20000000 */
#define GPIO_AFRH_AFRH7_2      (0x4UL << GPIO_AFRH_AFRH7_Pos)	/*!< 0x40000000 */
#define GPIO_AFRH_AFRH7_3      (0x8UL << GPIO_AFRH_AFRH7_Pos)	/*!< 0x80000000 */


/******************************************************************************/
/*                                                                            */
/*                      Inter-integrated Circuit Interface (I2C)              */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for I2C_CR1 register  *******************/
#define I2C_CR1_PE_Pos           (0U)
#define I2C_CR1_PE_Msk           (0x1UL << I2C_CR1_PE_Pos)	/*!< 0x00000001 */
#define I2C_CR1_PE               I2C_CR1_PE_Msk				/*!< Peripheral enable                   */
#define I2C_CR1_TXIE_Pos         (1U)
#define I2C_CR1_TXIE_Msk         (0x1UL << I2C_CR1_TXIE_Pos)/*!< 0x00000002 */
#define I2C_CR1_TXIE             I2C_CR1_TXIE_Msk	/*!< TX interrupt enable                 */
#define I2C_CR1_RXIE_Pos         (2U)
#define I2C_CR1_RXIE_Msk         (0x1UL << I2C_CR1_RXIE_Pos)/*!< 0x00000004 */
#define I2C_CR1_RXIE             I2C_CR1_RXIE_Msk	/*!< RX interrupt enable                 */
#define I2C_CR1_ADDRIE_Pos       (3U)
#define I2C_CR1_ADDRIE_Msk       (0x1UL << I2C_CR1_ADDRIE_Pos)	/*!< 0x00000008 */
#define I2C_CR1_ADDRIE           I2C_CR1_ADDRIE_Msk				/*!< Address match interrupt enable      */
#define I2C_CR1_NACKIE_Pos       (4U)
#define I2C_CR1_NACKIE_Msk       (0x1UL << I2C_CR1_NACKIE_Pos)	/*!< 0x00000010 */
#define I2C_CR1_NACKIE           I2C_CR1_NACKIE_Msk				/*!< NACK received interrupt enable      */
#define I2C_CR1_STOPIE_Pos       (5U)
#define I2C_CR1_STOPIE_Msk       (0x1UL << I2C_CR1_STOPIE_Pos)	/*!< 0x00000020 */
#define I2C_CR1_STOPIE           I2C_CR1_STOPIE_Msk				/*!< STOP detection interrupt enable     */
#define I2C_CR1_TCIE_Pos         (6U)
#define I2C_CR1_TCIE_Msk         (0x1UL << I2C_CR1_TCIE_Pos)/*!< 0x00000040 */
#define I2C_CR1_TCIE             I2C_CR1_TCIE_Msk	/*!< Transfer complete interrupt enable  */
#define I2C_CR1_ERRIE_Pos        (7U)
#define I2C_CR1_ERRIE_Msk        (0x1UL << I2C_CR1_ERRIE_Pos)	/*!< 0x00000080 */
#define I2C_CR1_ERRIE            I2C_CR1_ERRIE_Msk				/*!< Errors interrupt enable             */
#define I2C_CR1_DNF_Pos          (8U)
#define I2C_CR1_DNF_Msk          (0xFUL << I2C_CR1_DNF_Pos)	/*!< 0x00000F00 */
#define I2C_CR1_DNF              I2C_CR1_DNF_Msk/*!< Digital noise filter                */
#define I2C_CR1_ANFOFF_Pos       (12U)
#define I2C_CR1_ANFOFF_Msk       (0x1UL << I2C_CR1_ANFOFF_Pos)	/*!< 0x00001000 */
#define I2C_CR1_ANFOFF           I2C_CR1_ANFOFF_Msk				/*!< Analog noise filter OFF             */
#define I2C_CR1_TXDMAEN_Pos      (14U)
#define I2C_CR1_TXDMAEN_Msk      (0x1UL << I2C_CR1_TXDMAEN_Pos)	/*!< 0x00004000 */
#define I2C_CR1_TXDMAEN          I2C_CR1_TXDMAEN_Msk/*!< DMA transmission requests enable    */
#define I2C_CR1_RXDMAEN_Pos      (15U)
#define I2C_CR1_RXDMAEN_Msk      (0x1UL << I2C_CR1_RXDMAEN_Pos)	/*!< 0x00008000 */
#define I2C_CR1_RXDMAEN          I2C_CR1_RXDMAEN_Msk/*!< DMA reception requests enable       */
#define I2C_CR1_SBC_Pos          (16U)
#define I2C_CR1_SBC_Msk          (0x1UL << I2C_CR1_SBC_Pos)	/*!< 0x00010000 */
#define I2C_CR1_SBC              I2C_CR1_SBC_Msk/*!< Slave byte control                  */
#define I2C_CR1_NOSTRETCH_Pos    (17U)
#define I2C_CR1_NOSTRETCH_Msk    (0x1UL << I2C_CR1_NOSTRETCH_Pos)	/*!< 0x00020000 */
#define I2C_CR1_NOSTRETCH        I2C_CR1_NOSTRETCH_Msk				/*!< Clock stretching disable            */
#define I2C_CR1_GCEN_Pos         (19U)
#define I2C_CR1_GCEN_Msk         (0x1UL << I2C_CR1_GCEN_Pos)/*!< 0x00080000 */
#define I2C_CR1_GCEN             I2C_CR1_GCEN_Msk	/*!< General call enable                 */
#define I2C_CR1_SMBHEN_Pos       (20U)
#define I2C_CR1_SMBHEN_Msk       (0x1UL << I2C_CR1_SMBHEN_Pos)	/*!< 0x00100000 */
#define I2C_CR1_SMBHEN           I2C_CR1_SMBHEN_Msk				/*!< SMBus host address enable           */
#define I2C_CR1_SMBDEN_Pos       (21U)
#define I2C_CR1_SMBDEN_Msk       (0x1UL << I2C_CR1_SMBDEN_Pos)	/*!< 0x00200000 */
#define I2C_CR1_SMBDEN           I2C_CR1_SMBDEN_Msk				/*!< SMBus device default address enable */
#define I2C_CR1_ALERTEN_Pos      (22U)
#define I2C_CR1_ALERTEN_Msk      (0x1UL << I2C_CR1_ALERTEN_Pos)	/*!< 0x00400000 */
#define I2C_CR1_ALERTEN          I2C_CR1_ALERTEN_Msk/*!< SMBus alert enable                  */
#define I2C_CR1_PECEN_Pos        (23U)
#define I2C_CR1_PECEN_Msk        (0x1UL << I2C_CR1_PECEN_Pos)	/*!< 0x00800000 */
#define I2C_CR1_PECEN            I2C_CR1_PECEN_Msk				/*!< PEC enable                          */


/******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_SADD_Pos       (0U)
#define I2C_CR2_SADD_Msk       (0x3FFUL << I2C_CR2_SADD_Pos)/*!< 0x000003FF */
#define I2C_CR2_SADD           I2C_CR2_SADD_Msk	/*!< Slave address (master mode)                             */
#define I2C_CR2_RD_WRN_Pos     (10U)
#define I2C_CR2_RD_WRN_Msk     (0x1UL << I2C_CR2_RD_WRN_Pos)/*!< 0x00000400 */
#define I2C_CR2_RD_WRN         I2C_CR2_RD_WRN_Msk	/*!< Transfer direction (master mode)                        */
#define I2C_CR2_ADD10_Pos      (11U)
#define I2C_CR2_ADD10_Msk      (0x1UL << I2C_CR2_ADD10_Pos)	/*!< 0x00000800 */
#define I2C_CR2_ADD10          I2C_CR2_ADD10_Msk/*!< 10-bit addressing mode (master mode)                    */
#define I2C_CR2_HEAD10R_Pos    (12U)
#define I2C_CR2_HEAD10R_Msk    (0x1UL << I2C_CR2_HEAD10R_Pos)	/*!< 0x00001000 */
#define I2C_CR2_HEAD10R        I2C_CR2_HEAD10R_Msk				/*!< 10-bit address header only read direction (master mode) */
#define I2C_CR2_START_Pos      (13U)
#define I2C_CR2_START_Msk      (0x1UL << I2C_CR2_START_Pos)	/*!< 0x00002000 */
#define I2C_CR2_START          I2C_CR2_START_Msk/*!< START generation                                        */
#define I2C_CR2_STOP_Pos       (14U)
#define I2C_CR2_STOP_Msk       (0x1UL << I2C_CR2_STOP_Pos)	/*!< 0x00004000 */
#define I2C_CR2_STOP           I2C_CR2_STOP_Msk				/*!< STOP generation (master mode)                           */
#define I2C_CR2_NACK_Pos       (15U)
#define I2C_CR2_NACK_Msk       (0x1UL << I2C_CR2_NACK_Pos)	/*!< 0x00008000 */
#define I2C_CR2_NACK           I2C_CR2_NACK_Msk				/*!< NACK generation (slave mode)                            */
#define I2C_CR2_NBYTES_Pos     (16U)
#define I2C_CR2_NBYTES_Msk     (0xFFUL << I2C_CR2_NBYTES_Pos)	/*!< 0x00FF0000 */
#define I2C_CR2_NBYTES         I2C_CR2_NBYTES_Msk				/*!< Number of bytes                                         */
#define I2C_CR2_RELOAD_Pos     (24U)
#define I2C_CR2_RELOAD_Msk     (0x1UL << I2C_CR2_RELOAD_Pos)/*!< 0x01000000 */
#define I2C_CR2_RELOAD         I2C_CR2_RELOAD_Msk	/*!< NBYTES reload mode                                      */
#define I2C_CR2_AUTOEND_Pos    (25U)
#define I2C_CR2_AUTOEND_Msk    (0x1UL << I2C_CR2_AUTOEND_Pos)	/*!< 0x02000000 */
#define I2C_CR2_AUTOEND        I2C_CR2_AUTOEND_Msk				/*!< Automatic end mode (master mode)                        */
#define I2C_CR2_PECBYTE_Pos    (26U)
#define I2C_CR2_PECBYTE_Msk    (0x1UL << I2C_CR2_PECBYTE_Pos)	/*!< 0x04000000 */
#define I2C_CR2_PECBYTE        I2C_CR2_PECBYTE_Msk				/*!< Packet error checking byte                              */

/*******************  Bit definition for I2C_OAR1 register  ******************/
#define I2C_OAR1_OA1_Pos        (0U)
#define I2C_OAR1_OA1_Msk        (0x3FFUL << I2C_OAR1_OA1_Pos)	/*!< 0x000003FF */
#define I2C_OAR1_OA1            I2C_OAR1_OA1_Msk				/*!< Interface own address 1   */
#define I2C_OAR1_OA1MODE_Pos    (10U)
#define I2C_OAR1_OA1MODE_Msk    (0x1UL << I2C_OAR1_OA1MODE_Pos)	/*!< 0x00000400 */
#define I2C_OAR1_OA1MODE        I2C_OAR1_OA1MODE_Msk/*!< Own address 1 10-bit mode */
#define I2C_OAR1_OA1EN_Pos      (15U)
#define I2C_OAR1_OA1EN_Msk      (0x1UL << I2C_OAR1_OA1EN_Pos)	/*!< 0x00008000 */
#define I2C_OAR1_OA1EN          I2C_OAR1_OA1EN_Msk				/*!< Own address 1 enable      */

/*******************  Bit definition for I2C_OAR2 register  ******************/
#define I2C_OAR2_OA2_Pos          (1U)
#define I2C_OAR2_OA2_Msk          (0x7FUL << I2C_OAR2_OA2_Pos)	/*!< 0x000000FE */
#define I2C_OAR2_OA2              I2C_OAR2_OA2_Msk				/*!< Interface own address 2 */
#define I2C_OAR2_OA2MSK_Pos       (8U)
#define I2C_OAR2_OA2MSK_Msk       (0x7UL << I2C_OAR2_OA2MSK_Pos)/*!< 0x00000700 */
#define I2C_OAR2_OA2MSK           I2C_OAR2_OA2MSK_Msk	/*!< Own address 2 masks     */
#define I2C_OAR2_OA2NOMASK        0x00000000U			/*!< No mask */
#define I2C_OAR2_OA2MASK01_Pos    (8U)
#define I2C_OAR2_OA2MASK01_Msk    (0x1UL << I2C_OAR2_OA2MASK01_Pos)	/*!< 0x00000100 */
#define I2C_OAR2_OA2MASK01        I2C_OAR2_OA2MASK01_Msk/*!< OA2[1] is masked, Only OA2[7:2] are compared */
#define I2C_OAR2_OA2MASK02_Pos    (9U)
#define I2C_OAR2_OA2MASK02_Msk    (0x1UL << I2C_OAR2_OA2MASK02_Pos)	/*!< 0x00000200 */
#define I2C_OAR2_OA2MASK02        I2C_OAR2_OA2MASK02_Msk/*!< OA2[2:1] is masked, Only OA2[7:3] are compared */
#define I2C_OAR2_OA2MASK03_Pos    (8U)
#define I2C_OAR2_OA2MASK03_Msk    (0x3UL << I2C_OAR2_OA2MASK03_Pos)	/*!< 0x00000300 */
#define I2C_OAR2_OA2MASK03        I2C_OAR2_OA2MASK03_Msk/*!< OA2[3:1] is masked, Only OA2[7:4] are compared */
#define I2C_OAR2_OA2MASK04_Pos    (10U)
#define I2C_OAR2_OA2MASK04_Msk    (0x1UL << I2C_OAR2_OA2MASK04_Pos)	/*!< 0x00000400 */
#define I2C_OAR2_OA2MASK04        I2C_OAR2_OA2MASK04_Msk/*!< OA2[4:1] is masked, Only OA2[7:5] are compared */
#define I2C_OAR2_OA2MASK05_Pos    (8U)
#define I2C_OAR2_OA2MASK05_Msk    (0x5UL << I2C_OAR2_OA2MASK05_Pos)	/*!< 0x00000500 */
#define I2C_OAR2_OA2MASK05        I2C_OAR2_OA2MASK05_Msk/*!< OA2[5:1] is masked, Only OA2[7:6] are compared */
#define I2C_OAR2_OA2MASK06_Pos    (9U)
#define I2C_OAR2_OA2MASK06_Msk    (0x3UL << I2C_OAR2_OA2MASK06_Pos)	/*!< 0x00000600 */
#define I2C_OAR2_OA2MASK06        I2C_OAR2_OA2MASK06_Msk/*!< OA2[6:1] is masked, Only OA2[7] are compared */
#define I2C_OAR2_OA2MASK07_Pos    (8U)
#define I2C_OAR2_OA2MASK07_Msk    (0x7UL << I2C_OAR2_OA2MASK07_Pos)	/*!< 0x00000700 */
#define I2C_OAR2_OA2MASK07        I2C_OAR2_OA2MASK07_Msk/*!< OA2[7:1] is masked, No comparison is done */
#define I2C_OAR2_OA2EN_Pos        (15U)
#define I2C_OAR2_OA2EN_Msk        (0x1UL << I2C_OAR2_OA2EN_Pos)	/*!< 0x00008000 */
#define I2C_OAR2_OA2EN            I2C_OAR2_OA2EN_Msk/*!< Own address 2 enable    */

/*******************  Bit definition for I2C_TIMINGR register *******************/
#define I2C_TIMINGR_SCLL_Pos      (0U)
#define I2C_TIMINGR_SCLL_Msk      (0xFFUL << I2C_TIMINGR_SCLL_Pos)	/*!< 0x000000FF */
#define I2C_TIMINGR_SCLL          I2C_TIMINGR_SCLL_Msk				/*!< SCL low period (master mode)  */
#define I2C_TIMINGR_SCLH_Pos      (8U)
#define I2C_TIMINGR_SCLH_Msk      (0xFFUL << I2C_TIMINGR_SCLH_Pos)	/*!< 0x0000FF00 */
#define I2C_TIMINGR_SCLH          I2C_TIMINGR_SCLH_Msk				/*!< SCL high period (master mode) */
#define I2C_TIMINGR_SDADEL_Pos    (16U)
#define I2C_TIMINGR_SDADEL_Msk    (0xFUL << I2C_TIMINGR_SDADEL_Pos)	/*!< 0x000F0000 */
#define I2C_TIMINGR_SDADEL        I2C_TIMINGR_SDADEL_Msk/*!< Data hold time                */
#define I2C_TIMINGR_SCLDEL_Pos    (20U)
#define I2C_TIMINGR_SCLDEL_Msk    (0xFUL << I2C_TIMINGR_SCLDEL_Pos)	/*!< 0x00F00000 */
#define I2C_TIMINGR_SCLDEL        I2C_TIMINGR_SCLDEL_Msk/*!< Data setup time               */
#define I2C_TIMINGR_PRESC_Pos     (28U)
#define I2C_TIMINGR_PRESC_Msk     (0xFUL << I2C_TIMINGR_PRESC_Pos)	/*!< 0xF0000000 */
#define I2C_TIMINGR_PRESC         I2C_TIMINGR_PRESC_Msk				/*!< Timings prescaler             */

/******************* Bit definition for I2C_TIMEOUTR register *******************/
#define I2C_TIMEOUTR_TIMEOUTA_Pos    (0U)
#define I2C_TIMEOUTR_TIMEOUTA_Msk    (0xFFFUL << I2C_TIMEOUTR_TIMEOUTA_Pos)	/*!< 0x00000FFF */
#define I2C_TIMEOUTR_TIMEOUTA        I2C_TIMEOUTR_TIMEOUTA_Msk				/*!< Bus timeout A                 */
#define I2C_TIMEOUTR_TIDLE_Pos       (12U)
#define I2C_TIMEOUTR_TIDLE_Msk       (0x1UL << I2C_TIMEOUTR_TIDLE_Pos)	/*!< 0x00001000 */
#define I2C_TIMEOUTR_TIDLE           I2C_TIMEOUTR_TIDLE_Msk				/*!< Idle clock timeout detection  */
#define I2C_TIMEOUTR_TIMOUTEN_Pos    (15U)
#define I2C_TIMEOUTR_TIMOUTEN_Msk    (0x1UL << I2C_TIMEOUTR_TIMOUTEN_Pos)	/*!< 0x00008000 */
#define I2C_TIMEOUTR_TIMOUTEN        I2C_TIMEOUTR_TIMOUTEN_Msk				/*!< Clock timeout enable          */
#define I2C_TIMEOUTR_TIMEOUTB_Pos    (16U)
#define I2C_TIMEOUTR_TIMEOUTB_Msk    (0xFFFUL << I2C_TIMEOUTR_TIMEOUTB_Pos)	/*!< 0x0FFF0000 */
#define I2C_TIMEOUTR_TIMEOUTB        I2C_TIMEOUTR_TIMEOUTB_Msk				/*!< Bus timeout B                 */
#define I2C_TIMEOUTR_TEXTEN_Pos      (31U)
#define I2C_TIMEOUTR_TEXTEN_Msk      (0x1UL << I2C_TIMEOUTR_TEXTEN_Pos)	/*!< 0x80000000 */
#define I2C_TIMEOUTR_TEXTEN          I2C_TIMEOUTR_TEXTEN_Msk/*!< Extended clock timeout enable */

/******************  Bit definition for I2C_ISR register  *********************/
#define I2C_ISR_TXE_Pos        (0U)
#define I2C_ISR_TXE_Msk        (0x1UL << I2C_ISR_TXE_Pos)	/*!< 0x00000001 */
#define I2C_ISR_TXE            I2C_ISR_TXE_Msk				/*!< Transmit data register empty    */
#define I2C_ISR_TXIS_Pos       (1U)
#define I2C_ISR_TXIS_Msk       (0x1UL << I2C_ISR_TXIS_Pos)	/*!< 0x00000002 */
#define I2C_ISR_TXIS           I2C_ISR_TXIS_Msk				/*!< Transmit interrupt status       */
#define I2C_ISR_RXNE_Pos       (2U)
#define I2C_ISR_RXNE_Msk       (0x1UL << I2C_ISR_RXNE_Pos)	/*!< 0x00000004 */
#define I2C_ISR_RXNE           I2C_ISR_RXNE_Msk				/*!< Receive data register not empty */
#define I2C_ISR_ADDR_Pos       (3U)
#define I2C_ISR_ADDR_Msk       (0x1UL << I2C_ISR_ADDR_Pos)	/*!< 0x00000008 */
#define I2C_ISR_ADDR           I2C_ISR_ADDR_Msk				/*!< Address matched (slave mode)    */
#define I2C_ISR_NACKF_Pos      (4U)
#define I2C_ISR_NACKF_Msk      (0x1UL << I2C_ISR_NACKF_Pos)	/*!< 0x00000010 */
#define I2C_ISR_NACKF          I2C_ISR_NACKF_Msk/*!< NACK received flag              */
#define I2C_ISR_STOPF_Pos      (5U)
#define I2C_ISR_STOPF_Msk      (0x1UL << I2C_ISR_STOPF_Pos)	/*!< 0x00000020 */
#define I2C_ISR_STOPF          I2C_ISR_STOPF_Msk/*!< STOP detection flag             */
#define I2C_ISR_TC_Pos         (6U)
#define I2C_ISR_TC_Msk         (0x1UL << I2C_ISR_TC_Pos)/*!< 0x00000040 */
#define I2C_ISR_TC             I2C_ISR_TC_Msk	/*!< Transfer complete (master mode) */
#define I2C_ISR_TCR_Pos        (7U)
#define I2C_ISR_TCR_Msk        (0x1UL << I2C_ISR_TCR_Pos)	/*!< 0x00000080 */
#define I2C_ISR_TCR            I2C_ISR_TCR_Msk				/*!< Transfer complete reload        */
#define I2C_ISR_BERR_Pos       (8U)
#define I2C_ISR_BERR_Msk       (0x1UL << I2C_ISR_BERR_Pos)	/*!< 0x00000100 */
#define I2C_ISR_BERR           I2C_ISR_BERR_Msk				/*!< Bus error                       */
#define I2C_ISR_ARLO_Pos       (9U)
#define I2C_ISR_ARLO_Msk       (0x1UL << I2C_ISR_ARLO_Pos)	/*!< 0x00000200 */
#define I2C_ISR_ARLO           I2C_ISR_ARLO_Msk				/*!< Arbitration lost                */
#define I2C_ISR_OVR_Pos        (10U)
#define I2C_ISR_OVR_Msk        (0x1UL << I2C_ISR_OVR_Pos)	/*!< 0x00000400 */
#define I2C_ISR_OVR            I2C_ISR_OVR_Msk				/*!< Overrun/Underrun                */
#define I2C_ISR_PECERR_Pos     (11U)
#define I2C_ISR_PECERR_Msk     (0x1UL << I2C_ISR_PECERR_Pos)/*!< 0x00000800 */
#define I2C_ISR_PECERR         I2C_ISR_PECERR_Msk	/*!< PEC error in reception          */
#define I2C_ISR_TIMEOUT_Pos    (12U)
#define I2C_ISR_TIMEOUT_Msk    (0x1UL << I2C_ISR_TIMEOUT_Pos)	/*!< 0x00001000 */
#define I2C_ISR_TIMEOUT        I2C_ISR_TIMEOUT_Msk				/*!< Timeout or Tlow detection flag  */
#define I2C_ISR_ALERT_Pos      (13U)
#define I2C_ISR_ALERT_Msk      (0x1UL << I2C_ISR_ALERT_Pos)	/*!< 0x00002000 */
#define I2C_ISR_ALERT          I2C_ISR_ALERT_Msk/*!< SMBus alert                     */
#define I2C_ISR_BUSY_Pos       (15U)
#define I2C_ISR_BUSY_Msk       (0x1UL << I2C_ISR_BUSY_Pos)	/*!< 0x00008000 */
#define I2C_ISR_BUSY           I2C_ISR_BUSY_Msk				/*!< Bus busy                        */
#define I2C_ISR_DIR_Pos        (16U)
#define I2C_ISR_DIR_Msk        (0x1UL << I2C_ISR_DIR_Pos)	/*!< 0x00010000 */
#define I2C_ISR_DIR            I2C_ISR_DIR_Msk				/*!< Transfer direction (slave mode) */
#define I2C_ISR_ADDCODE_Pos    (17U)
#define I2C_ISR_ADDCODE_Msk    (0x7FUL << I2C_ISR_ADDCODE_Pos)	/*!< 0x00FE0000 */
#define I2C_ISR_ADDCODE        I2C_ISR_ADDCODE_Msk				/*!< Address match code (slave mode) */

/******************  Bit definition for I2C_ICR register  *********************/
#define I2C_ICR_ADDRCF_Pos      (3U)
#define I2C_ICR_ADDRCF_Msk      (0x1UL << I2C_ICR_ADDRCF_Pos)	/*!< 0x00000008 */
#define I2C_ICR_ADDRCF          I2C_ICR_ADDRCF_Msk				/*!< Address matched clear flag      */
#define I2C_ICR_NACKCF_Pos      (4U)
#define I2C_ICR_NACKCF_Msk      (0x1UL << I2C_ICR_NACKCF_Pos)	/*!< 0x00000010 */
#define I2C_ICR_NACKCF          I2C_ICR_NACKCF_Msk				/*!< NACK clear flag                 */
#define I2C_ICR_STOPCF_Pos      (5U)
#define I2C_ICR_STOPCF_Msk      (0x1UL << I2C_ICR_STOPCF_Pos)	/*!< 0x00000020 */
#define I2C_ICR_STOPCF          I2C_ICR_STOPCF_Msk				/*!< STOP detection clear flag       */
#define I2C_ICR_BERRCF_Pos      (8U)
#define I2C_ICR_BERRCF_Msk      (0x1UL << I2C_ICR_BERRCF_Pos)	/*!< 0x00000100 */
#define I2C_ICR_BERRCF          I2C_ICR_BERRCF_Msk				/*!< Bus error clear flag            */
#define I2C_ICR_ARLOCF_Pos      (9U)
#define I2C_ICR_ARLOCF_Msk      (0x1UL << I2C_ICR_ARLOCF_Pos)	/*!< 0x00000200 */
#define I2C_ICR_ARLOCF          I2C_ICR_ARLOCF_Msk				/*!< Arbitration lost clear flag     */
#define I2C_ICR_OVRCF_Pos       (10U)
#define I2C_ICR_OVRCF_Msk       (0x1UL << I2C_ICR_OVRCF_Pos)/*!< 0x00000400 */
#define I2C_ICR_OVRCF           I2C_ICR_OVRCF_Msk	/*!< Overrun/Underrun clear flag     */
#define I2C_ICR_PECCF_Pos       (11U)
#define I2C_ICR_PECCF_Msk       (0x1UL << I2C_ICR_PECCF_Pos)/*!< 0x00000800 */
#define I2C_ICR_PECCF           I2C_ICR_PECCF_Msk	/*!< PAC error clear flag            */
#define I2C_ICR_TIMOUTCF_Pos    (12U)
#define I2C_ICR_TIMOUTCF_Msk    (0x1UL << I2C_ICR_TIMOUTCF_Pos)	/*!< 0x00001000 */
#define I2C_ICR_TIMOUTCF        I2C_ICR_TIMOUTCF_Msk/*!< Timeout clear flag              */
#define I2C_ICR_ALERTCF_Pos     (13U)
#define I2C_ICR_ALERTCF_Msk     (0x1UL << I2C_ICR_ALERTCF_Pos)	/*!< 0x00002000 */
#define I2C_ICR_ALERTCF         I2C_ICR_ALERTCF_Msk				/*!< Alert clear flag                */

/******************  Bit definition for I2C_PECR register  *********************/
#define I2C_PECR_PEC_Pos    (0U)
#define I2C_PECR_PEC_Msk    (0xFFUL << I2C_PECR_PEC_Pos)/*!< 0x000000FF */
#define I2C_PECR_PEC        I2C_PECR_PEC_Msk/*!< PEC register        */

/******************  Bit definition for I2C_RXDR register  *********************/
#define I2C_RXDR_RXDATA_Pos    (0U)
#define I2C_RXDR_RXDATA_Msk    (0xFFUL << I2C_RXDR_RXDATA_Pos)	/*!< 0x000000FF */
#define I2C_RXDR_RXDATA        I2C_RXDR_RXDATA_Msk				/*!< 8-bit receive data  */

/******************  Bit definition for I2C_TXDR register  *********************/
#define I2C_TXDR_TXDATA_Pos    (0U)
#define I2C_TXDR_TXDATA_Msk    (0xFFUL << I2C_TXDR_TXDATA_Pos)	/*!< 0x000000FF */
#define I2C_TXDR_TXDATA        I2C_TXDR_TXDATA_Msk				/*!< 8-bit transmit data */


/******************************************************************************/
/*                                                                            */
/*                           Independent WATCHDOG                             */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for IWDG_KR register  ********************/
#define IWDG_KR_KEY_Pos    (0U)
#define IWDG_KR_KEY_Msk    (0xFFFFUL << IWDG_KR_KEY_Pos)/*!< 0x0000FFFF */
#define IWDG_KR_KEY        IWDG_KR_KEY_Msk	/*!<Key value (write only, read 0000h)  */

/*******************  Bit definition for IWDG_PR register  ********************/
#define IWDG_PR_PR_Pos    (0U)
#define IWDG_PR_PR_Msk    (0x7UL << IWDG_PR_PR_Pos)	/*!< 0x00000007 */
#define IWDG_PR_PR        IWDG_PR_PR_Msk/*!<PR[2:0] (Prescaler divider)         */
#define IWDG_PR_PR_0      (0x1UL << IWDG_PR_PR_Pos)	/*!< 0x01 */
#define IWDG_PR_PR_1      (0x2UL << IWDG_PR_PR_Pos)	/*!< 0x02 */
#define IWDG_PR_PR_2      (0x4UL << IWDG_PR_PR_Pos)	/*!< 0x04 */

/*******************  Bit definition for IWDG_RLR register  *******************/
#define IWDG_RLR_RL_Pos    (0U)
#define IWDG_RLR_RL_Msk    (0xFFFUL << IWDG_RLR_RL_Pos)	/*!< 0x00000FFF */
#define IWDG_RLR_RL        IWDG_RLR_RL_Msk				/*!<Watchdog counter reload value        */

/*******************  Bit definition for IWDG_SR register  ********************/
#define IWDG_SR_PVU_Pos    (0U)
#define IWDG_SR_PVU_Msk    (0x1UL << IWDG_SR_PVU_Pos)	/*!< 0x00000001 */
#define IWDG_SR_PVU        IWDG_SR_PVU_Msk				/*!< Watchdog prescaler value update */
#define IWDG_SR_RVU_Pos    (1U)
#define IWDG_SR_RVU_Msk    (0x1UL << IWDG_SR_RVU_Pos)	/*!< 0x00000002 */
#define IWDG_SR_RVU        IWDG_SR_RVU_Msk				/*!< Watchdog counter reload value update */
#define IWDG_SR_WVU_Pos    (2U)
#define IWDG_SR_WVU_Msk    (0x1UL << IWDG_SR_WVU_Pos)	/*!< 0x00000004 */
#define IWDG_SR_WVU        IWDG_SR_WVU_Msk				/*!< Watchdog counter window value update */

/*******************  Bit definition for IWDG_KR register  ********************/
#define IWDG_WINR_WIN_Pos    (0U)
#define IWDG_WINR_WIN_Msk    (0xFFFUL << IWDG_WINR_WIN_Pos)	/*!< 0x00000FFF */
#define IWDG_WINR_WIN        IWDG_WINR_WIN_Msk				/*!< Watchdog counter window value */


/******************************************************************************/
/*                                                                            */
/*                             Power Control                                  */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for PWR_CR1 register  ********************/
#define PWR_CR1_LPDS_Pos    (0U)
#define PWR_CR1_LPDS_Msk    (0x1UL << PWR_CR1_LPDS_Pos)	/*!< 0x00000001 */
#define PWR_CR1_LPDS        PWR_CR1_LPDS_Msk/*!< Low-Power Deepsleep                 */
#define PWR_CR1_PDDS_Pos    (1U)
#define PWR_CR1_PDDS_Msk    (0x1UL << PWR_CR1_PDDS_Pos)	/*!< 0x00000002 */
#define PWR_CR1_PDDS        PWR_CR1_PDDS_Msk/*!< Power Down Deepsleep                */
#define PWR_CR1_CSBF_Pos    (3U)
#define PWR_CR1_CSBF_Msk    (0x1UL << PWR_CR1_CSBF_Pos)	/*!< 0x00000008 */
#define PWR_CR1_CSBF        PWR_CR1_CSBF_Msk/*!< Clear Standby Flag                  */
#define PWR_CR1_PVDE_Pos    (4U)
#define PWR_CR1_PVDE_Msk    (0x1UL << PWR_CR1_PVDE_Pos)	/*!< 0x00000010 */
#define PWR_CR1_PVDE        PWR_CR1_PVDE_Msk/*!< Power Voltage Detector Enable       */
#define PWR_CR1_PLS_Pos     (5U)
#define PWR_CR1_PLS_Msk     (0x7UL << PWR_CR1_PLS_Pos)	/*!< 0x000000E0 */
#define PWR_CR1_PLS         PWR_CR1_PLS_Msk				/*!< PLS[2:0] bits (PVD Level Selection) */
#define PWR_CR1_PLS_0       (0x1UL << PWR_CR1_PLS_Pos)	/*!< 0x00000020 */
#define PWR_CR1_PLS_1       (0x2UL << PWR_CR1_PLS_Pos)	/*!< 0x00000040 */
#define PWR_CR1_PLS_2       (0x4UL << PWR_CR1_PLS_Pos)	/*!< 0x00000080 */

/*!< PVD level configuration */
#define PWR_CR1_PLS_LEV0        0x00000000U	/*!< PVD level 0 */
#define PWR_CR1_PLS_LEV1_Pos    (5U)
#define PWR_CR1_PLS_LEV1_Msk    (0x1UL << PWR_CR1_PLS_LEV1_Pos)	/*!< 0x00000020 */
#define PWR_CR1_PLS_LEV1        PWR_CR1_PLS_LEV1_Msk/*!< PVD level 1 */
#define PWR_CR1_PLS_LEV2_Pos    (6U)
#define PWR_CR1_PLS_LEV2_Msk    (0x1UL << PWR_CR1_PLS_LEV2_Pos)	/*!< 0x00000040 */
#define PWR_CR1_PLS_LEV2        PWR_CR1_PLS_LEV2_Msk/*!< PVD level 2 */
#define PWR_CR1_PLS_LEV3_Pos    (5U)
#define PWR_CR1_PLS_LEV3_Msk    (0x3UL << PWR_CR1_PLS_LEV3_Pos)	/*!< 0x00000060 */
#define PWR_CR1_PLS_LEV3        PWR_CR1_PLS_LEV3_Msk/*!< PVD level 3 */
#define PWR_CR1_PLS_LEV4_Pos    (7U)
#define PWR_CR1_PLS_LEV4_Msk    (0x1UL << PWR_CR1_PLS_LEV4_Pos)	/*!< 0x00000080 */
#define PWR_CR1_PLS_LEV4        PWR_CR1_PLS_LEV4_Msk/*!< PVD level 4 */
#define PWR_CR1_PLS_LEV5_Pos    (5U)
#define PWR_CR1_PLS_LEV5_Msk    (0x5UL << PWR_CR1_PLS_LEV5_Pos)	/*!< 0x000000A0 */
#define PWR_CR1_PLS_LEV5        PWR_CR1_PLS_LEV5_Msk/*!< PVD level 5 */
#define PWR_CR1_PLS_LEV6_Pos    (6U)
#define PWR_CR1_PLS_LEV6_Msk    (0x3UL << PWR_CR1_PLS_LEV6_Pos)	/*!< 0x000000C0 */
#define PWR_CR1_PLS_LEV6        PWR_CR1_PLS_LEV6_Msk/*!< PVD level 6 */
#define PWR_CR1_PLS_LEV7_Pos    (5U)
#define PWR_CR1_PLS_LEV7_Msk    (0x7UL << PWR_CR1_PLS_LEV7_Pos)	/*!< 0x000000E0 */
#define PWR_CR1_PLS_LEV7        PWR_CR1_PLS_LEV7_Msk/*!< PVD level 7 */
#define PWR_CR1_DBP_Pos         (8U)
#define PWR_CR1_DBP_Msk         (0x1UL << PWR_CR1_DBP_Pos)	/*!< 0x00000100 */
#define PWR_CR1_DBP             PWR_CR1_DBP_Msk				/*!< Disable Backup Domain write protection                     */
#define PWR_CR1_FPDS_Pos        (9U)
#define PWR_CR1_FPDS_Msk        (0x1UL << PWR_CR1_FPDS_Pos)	/*!< 0x00000200 */
#define PWR_CR1_FPDS            PWR_CR1_FPDS_Msk/*!< Flash power down in Stop mode                              */
#define PWR_CR1_LPUDS_Pos       (10U)
#define PWR_CR1_LPUDS_Msk       (0x1UL << PWR_CR1_LPUDS_Pos)/*!< 0x00000400 */
#define PWR_CR1_LPUDS           PWR_CR1_LPUDS_Msk	/*!< Low-power regulator in deepsleep under-drive mode          */
#define PWR_CR1_MRUDS_Pos       (11U)
#define PWR_CR1_MRUDS_Msk       (0x1UL << PWR_CR1_MRUDS_Pos)/*!< 0x00000800 */
#define PWR_CR1_MRUDS           PWR_CR1_MRUDS_Msk	/*!< Main regulator in deepsleep under-drive mode               */
#define PWR_CR1_ADCDC1_Pos      (13U)
#define PWR_CR1_ADCDC1_Msk      (0x1UL << PWR_CR1_ADCDC1_Pos)	/*!< 0x00002000 */
#define PWR_CR1_ADCDC1          PWR_CR1_ADCDC1_Msk				/*!< Refer to AN4073 on how to use this bit */
#define PWR_CR1_VOS_Pos         (14U)
#define PWR_CR1_VOS_Msk         (0x3UL << PWR_CR1_VOS_Pos)	/*!< 0x0000C000 */
#define PWR_CR1_VOS             PWR_CR1_VOS_Msk				/*!< VOS[1:0] bits (Regulator voltage scaling output selection) */
#define PWR_CR1_VOS_0           (0x1UL << PWR_CR1_VOS_Pos)	/*!< 0x00004000 */
#define PWR_CR1_VOS_1           (0x2UL << PWR_CR1_VOS_Pos)	/*!< 0x00008000 */
#define PWR_CR1_ODEN_Pos        (16U)
#define PWR_CR1_ODEN_Msk        (0x1UL << PWR_CR1_ODEN_Pos)	/*!< 0x00010000 */
#define PWR_CR1_ODEN            PWR_CR1_ODEN_Msk/*!< Over Drive enable                   */
#define PWR_CR1_ODSWEN_Pos      (17U)
#define PWR_CR1_ODSWEN_Msk      (0x1UL << PWR_CR1_ODSWEN_Pos)	/*!< 0x00020000 */
#define PWR_CR1_ODSWEN          PWR_CR1_ODSWEN_Msk				/*!< Over Drive switch enabled           */
#define PWR_CR1_UDEN_Pos        (18U)
#define PWR_CR1_UDEN_Msk        (0x3UL << PWR_CR1_UDEN_Pos)	/*!< 0x000C0000 */
#define PWR_CR1_UDEN            PWR_CR1_UDEN_Msk/*!< Under Drive enable in stop mode     */
#define PWR_CR1_UDEN_0          (0x1UL << PWR_CR1_UDEN_Pos)	/*!< 0x00040000 */
#define PWR_CR1_UDEN_1          (0x2UL << PWR_CR1_UDEN_Pos)	/*!< 0x00080000 */

/*******************  Bit definition for PWR_CSR1 register  ********************/
#define PWR_CSR1_WUIF_Pos       (0U)
#define PWR_CSR1_WUIF_Msk       (0x1UL << PWR_CSR1_WUIF_Pos)/*!< 0x00000001 */
#define PWR_CSR1_WUIF           PWR_CSR1_WUIF_Msk	/*!< Wake up internal Flag                            */
#define PWR_CSR1_SBF_Pos        (1U)
#define PWR_CSR1_SBF_Msk        (0x1UL << PWR_CSR1_SBF_Pos)	/*!< 0x00000002 */
#define PWR_CSR1_SBF            PWR_CSR1_SBF_Msk/*!< Standby Flag                                     */
#define PWR_CSR1_PVDO_Pos       (2U)
#define PWR_CSR1_PVDO_Msk       (0x1UL << PWR_CSR1_PVDO_Pos)/*!< 0x00000004 */
#define PWR_CSR1_PVDO           PWR_CSR1_PVDO_Msk	/*!< PVD Output                                       */
#define PWR_CSR1_BRR_Pos        (3U)
#define PWR_CSR1_BRR_Msk        (0x1UL << PWR_CSR1_BRR_Pos)	/*!< 0x00000008 */
#define PWR_CSR1_BRR            PWR_CSR1_BRR_Msk/*!< Backup regulator ready                           */
#define PWR_CSR1_EIWUP_Pos      (8U)
#define PWR_CSR1_EIWUP_Msk      (0x1UL << PWR_CSR1_EIWUP_Pos)	/*!< 0x00000100 */
#define PWR_CSR1_EIWUP          PWR_CSR1_EIWUP_Msk				/*!< Enable internal wakeup                           */
#define PWR_CSR1_BRE_Pos        (9U)
#define PWR_CSR1_BRE_Msk        (0x1UL << PWR_CSR1_BRE_Pos)	/*!< 0x00000200 */
#define PWR_CSR1_BRE            PWR_CSR1_BRE_Msk/*!< Backup regulator enable                          */
#define PWR_CSR1_VOSRDY_Pos     (14U)
#define PWR_CSR1_VOSRDY_Msk     (0x1UL << PWR_CSR1_VOSRDY_Pos)	/*!< 0x00004000 */
#define PWR_CSR1_VOSRDY         PWR_CSR1_VOSRDY_Msk				/*!< Regulator voltage scaling output selection ready */
#define PWR_CSR1_ODRDY_Pos      (16U)
#define PWR_CSR1_ODRDY_Msk      (0x1UL << PWR_CSR1_ODRDY_Pos)	/*!< 0x00010000 */
#define PWR_CSR1_ODRDY          PWR_CSR1_ODRDY_Msk				/*!< Over Drive generator ready                       */
#define PWR_CSR1_ODSWRDY_Pos    (17U)
#define PWR_CSR1_ODSWRDY_Msk    (0x1UL << PWR_CSR1_ODSWRDY_Pos)	/*!< 0x00020000 */
#define PWR_CSR1_ODSWRDY        PWR_CSR1_ODSWRDY_Msk/*!< Over Drive Switch ready                          */
#define PWR_CSR1_UDRDY_Pos      (18U)
#define PWR_CSR1_UDRDY_Msk      (0x3UL << PWR_CSR1_UDRDY_Pos)	/*!< 0x000C0000 */
#define PWR_CSR1_UDRDY          PWR_CSR1_UDRDY_Msk				/*!< Under Drive ready                                */


/********************  Bit definition for PWR_CR2 register  ********************/
#define PWR_CR2_CWUPF1_Pos    (0U)
#define PWR_CR2_CWUPF1_Msk    (0x1UL << PWR_CR2_CWUPF1_Pos)	/*!< 0x00000001 */
#define PWR_CR2_CWUPF1        PWR_CR2_CWUPF1_Msk/*!< Clear Wakeup Pin Flag for PA0      */
#define PWR_CR2_CWUPF2_Pos    (1U)
#define PWR_CR2_CWUPF2_Msk    (0x1UL << PWR_CR2_CWUPF2_Pos)	/*!< 0x00000002 */
#define PWR_CR2_CWUPF2        PWR_CR2_CWUPF2_Msk/*!< Clear Wakeup Pin Flag for PA2      */
#define PWR_CR2_CWUPF3_Pos    (2U)
#define PWR_CR2_CWUPF3_Msk    (0x1UL << PWR_CR2_CWUPF3_Pos)	/*!< 0x00000004 */
#define PWR_CR2_CWUPF3        PWR_CR2_CWUPF3_Msk/*!< Clear Wakeup Pin Flag for PC1      */
#define PWR_CR2_CWUPF4_Pos    (3U)
#define PWR_CR2_CWUPF4_Msk    (0x1UL << PWR_CR2_CWUPF4_Pos)	/*!< 0x00000008 */
#define PWR_CR2_CWUPF4        PWR_CR2_CWUPF4_Msk/*!< Clear Wakeup Pin Flag for PC13     */
#define PWR_CR2_CWUPF5_Pos    (4U)
#define PWR_CR2_CWUPF5_Msk    (0x1UL << PWR_CR2_CWUPF5_Pos)	/*!< 0x00000010 */
#define PWR_CR2_CWUPF5        PWR_CR2_CWUPF5_Msk/*!< Clear Wakeup Pin Flag for PI8      */
#define PWR_CR2_CWUPF6_Pos    (5U)
#define PWR_CR2_CWUPF6_Msk    (0x1UL << PWR_CR2_CWUPF6_Pos)	/*!< 0x00000020 */
#define PWR_CR2_CWUPF6        PWR_CR2_CWUPF6_Msk/*!< Clear Wakeup Pin Flag for PI11     */
#define PWR_CR2_WUPP1_Pos     (8U)
#define PWR_CR2_WUPP1_Msk     (0x1UL << PWR_CR2_WUPP1_Pos)	/*!< 0x00000100 */
#define PWR_CR2_WUPP1         PWR_CR2_WUPP1_Msk				/*!< Wakeup Pin Polarity bit for PA0    */
#define PWR_CR2_WUPP2_Pos     (9U)
#define PWR_CR2_WUPP2_Msk     (0x1UL << PWR_CR2_WUPP2_Pos)	/*!< 0x00000200 */
#define PWR_CR2_WUPP2         PWR_CR2_WUPP2_Msk				/*!< Wakeup Pin Polarity bit for PA2    */
#define PWR_CR2_WUPP3_Pos     (10U)
#define PWR_CR2_WUPP3_Msk     (0x1UL << PWR_CR2_WUPP3_Pos)	/*!< 0x00000400 */
#define PWR_CR2_WUPP3         PWR_CR2_WUPP3_Msk				/*!< Wakeup Pin Polarity bit for PC1    */
#define PWR_CR2_WUPP4_Pos     (11U)
#define PWR_CR2_WUPP4_Msk     (0x1UL << PWR_CR2_WUPP4_Pos)	/*!< 0x00000800 */
#define PWR_CR2_WUPP4         PWR_CR2_WUPP4_Msk				/*!< Wakeup Pin Polarity bit for PC13   */
#define PWR_CR2_WUPP5_Pos     (12U)
#define PWR_CR2_WUPP5_Msk     (0x1UL << PWR_CR2_WUPP5_Pos)	/*!< 0x00001000 */
#define PWR_CR2_WUPP5         PWR_CR2_WUPP5_Msk				/*!< Wakeup Pin Polarity bit for PI8    */
#define PWR_CR2_WUPP6_Pos     (13U)
#define PWR_CR2_WUPP6_Msk     (0x1UL << PWR_CR2_WUPP6_Pos)	/*!< 0x00002000 */
#define PWR_CR2_WUPP6         PWR_CR2_WUPP6_Msk				/*!< Wakeup Pin Polarity bit for PI11   */

/*******************  Bit definition for PWR_CSR2 register  ********************/
#define PWR_CSR2_WUPF1_Pos    (0U)
#define PWR_CSR2_WUPF1_Msk    (0x1UL << PWR_CSR2_WUPF1_Pos)	/*!< 0x00000001 */
#define PWR_CSR2_WUPF1        PWR_CSR2_WUPF1_Msk/*!< Wakeup Pin Flag for PA0            */
#define PWR_CSR2_WUPF2_Pos    (1U)
#define PWR_CSR2_WUPF2_Msk    (0x1UL << PWR_CSR2_WUPF2_Pos)	/*!< 0x00000002 */
#define PWR_CSR2_WUPF2        PWR_CSR2_WUPF2_Msk/*!< Wakeup Pin Flag for PA2            */
#define PWR_CSR2_WUPF3_Pos    (2U)
#define PWR_CSR2_WUPF3_Msk    (0x1UL << PWR_CSR2_WUPF3_Pos)	/*!< 0x00000004 */
#define PWR_CSR2_WUPF3        PWR_CSR2_WUPF3_Msk/*!< Wakeup Pin Flag for PC1            */
#define PWR_CSR2_WUPF4_Pos    (3U)
#define PWR_CSR2_WUPF4_Msk    (0x1UL << PWR_CSR2_WUPF4_Pos)	/*!< 0x00000008 */
#define PWR_CSR2_WUPF4        PWR_CSR2_WUPF4_Msk/*!< Wakeup Pin Flag for PC13           */
#define PWR_CSR2_WUPF5_Pos    (4U)
#define PWR_CSR2_WUPF5_Msk    (0x1UL << PWR_CSR2_WUPF5_Pos)	/*!< 0x00000010 */
#define PWR_CSR2_WUPF5        PWR_CSR2_WUPF5_Msk/*!< Wakeup Pin Flag for PI8            */
#define PWR_CSR2_WUPF6_Pos    (5U)
#define PWR_CSR2_WUPF6_Msk    (0x1UL << PWR_CSR2_WUPF6_Pos)	/*!< 0x00000020 */
#define PWR_CSR2_WUPF6        PWR_CSR2_WUPF6_Msk/*!< Wakeup Pin Flag for PI11           */
#define PWR_CSR2_EWUP1_Pos    (8U)
#define PWR_CSR2_EWUP1_Msk    (0x1UL << PWR_CSR2_EWUP1_Pos)	/*!< 0x00000100 */
#define PWR_CSR2_EWUP1        PWR_CSR2_EWUP1_Msk/*!< Enable Wakeup Pin PA0              */
#define PWR_CSR2_EWUP2_Pos    (9U)
#define PWR_CSR2_EWUP2_Msk    (0x1UL << PWR_CSR2_EWUP2_Pos)	/*!< 0x00000200 */
#define PWR_CSR2_EWUP2        PWR_CSR2_EWUP2_Msk/*!< Enable Wakeup Pin PA2              */
#define PWR_CSR2_EWUP3_Pos    (10U)
#define PWR_CSR2_EWUP3_Msk    (0x1UL << PWR_CSR2_EWUP3_Pos)	/*!< 0x00000400 */
#define PWR_CSR2_EWUP3        PWR_CSR2_EWUP3_Msk/*!< Enable Wakeup Pin PC1              */
#define PWR_CSR2_EWUP4_Pos    (11U)
#define PWR_CSR2_EWUP4_Msk    (0x1UL << PWR_CSR2_EWUP4_Pos)	/*!< 0x00000800 */
#define PWR_CSR2_EWUP4        PWR_CSR2_EWUP4_Msk/*!< Enable Wakeup Pin PC13             */
#define PWR_CSR2_EWUP5_Pos    (12U)
#define PWR_CSR2_EWUP5_Msk    (0x1UL << PWR_CSR2_EWUP5_Pos)	/*!< 0x00001000 */
#define PWR_CSR2_EWUP5        PWR_CSR2_EWUP5_Msk/*!< Enable Wakeup Pin PI8              */
#define PWR_CSR2_EWUP6_Pos    (13U)
#define PWR_CSR2_EWUP6_Msk    (0x1UL << PWR_CSR2_EWUP6_Pos)	/*!< 0x00002000 */
#define PWR_CSR2_EWUP6        PWR_CSR2_EWUP6_Msk/*!< Enable Wakeup Pin PI11             */

/******************************************************************************/
/*                                                                            */
/*                                    QUADSPI                                 */
/*                                                                            */
/******************************************************************************/
/*****************  Bit definition for QUADSPI_CR register  *******************/
#define QUADSPI_CR_EN_Pos           (0U)
#define QUADSPI_CR_EN_Msk           (0x1UL << QUADSPI_CR_EN_Pos)/*!< 0x00000001 */
#define QUADSPI_CR_EN               QUADSPI_CR_EN_Msk	/*!< Enable                            */
#define QUADSPI_CR_ABORT_Pos        (1U)
#define QUADSPI_CR_ABORT_Msk        (0x1UL << QUADSPI_CR_ABORT_Pos)	/*!< 0x00000002 */
#define QUADSPI_CR_ABORT            QUADSPI_CR_ABORT_Msk/*!< Abort request                     */
#define QUADSPI_CR_DMAEN_Pos        (2U)
#define QUADSPI_CR_DMAEN_Msk        (0x1UL << QUADSPI_CR_DMAEN_Pos)	/*!< 0x00000004 */
#define QUADSPI_CR_DMAEN            QUADSPI_CR_DMAEN_Msk/*!< DMA Enable                        */
#define QUADSPI_CR_TCEN_Pos         (3U)
#define QUADSPI_CR_TCEN_Msk         (0x1UL << QUADSPI_CR_TCEN_Pos)	/*!< 0x00000008 */
#define QUADSPI_CR_TCEN             QUADSPI_CR_TCEN_Msk				/*!< Timeout Counter Enable            */
#define QUADSPI_CR_SSHIFT_Pos       (4U)
#define QUADSPI_CR_SSHIFT_Msk       (0x1UL << QUADSPI_CR_SSHIFT_Pos)/*!< 0x00000010 */
#define QUADSPI_CR_SSHIFT           QUADSPI_CR_SSHIFT_Msk	/*!< Sample Shift                      */
#define QUADSPI_CR_DFM_Pos          (6U)
#define QUADSPI_CR_DFM_Msk          (0x1UL << QUADSPI_CR_DFM_Pos)	/*!< 0x00000040 */
#define QUADSPI_CR_DFM              QUADSPI_CR_DFM_Msk				/*!< Dual Flash Mode                   */
#define QUADSPI_CR_FSEL_Pos         (7U)
#define QUADSPI_CR_FSEL_Msk         (0x1UL << QUADSPI_CR_FSEL_Pos)	/*!< 0x00000080 */
#define QUADSPI_CR_FSEL             QUADSPI_CR_FSEL_Msk				/*!< Flash Select                      */
#define QUADSPI_CR_FTHRES_Pos       (8U)
#define QUADSPI_CR_FTHRES_Msk       (0x1FUL << QUADSPI_CR_FTHRES_Pos)	/*!< 0x00001F00 */
#define QUADSPI_CR_FTHRES           QUADSPI_CR_FTHRES_Msk				/*!< FTHRES[4:0] FIFO Level            */
#define QUADSPI_CR_FTHRES_0         (0x01UL << QUADSPI_CR_FTHRES_Pos)	/*!< 0x00000100 */
#define QUADSPI_CR_FTHRES_1         (0x02UL << QUADSPI_CR_FTHRES_Pos)	/*!< 0x00000200 */
#define QUADSPI_CR_FTHRES_2         (0x04UL << QUADSPI_CR_FTHRES_Pos)	/*!< 0x00000400 */
#define QUADSPI_CR_FTHRES_3         (0x08UL << QUADSPI_CR_FTHRES_Pos)	/*!< 0x00000800 */
#define QUADSPI_CR_FTHRES_4         (0x10UL << QUADSPI_CR_FTHRES_Pos)	/*!< 0x00001000 */
#define QUADSPI_CR_TEIE_Pos         (16U)
#define QUADSPI_CR_TEIE_Msk         (0x1UL << QUADSPI_CR_TEIE_Pos)	/*!< 0x00010000 */
#define QUADSPI_CR_TEIE             QUADSPI_CR_TEIE_Msk				/*!< Transfer Error Interrupt Enable    */
#define QUADSPI_CR_TCIE_Pos         (17U)
#define QUADSPI_CR_TCIE_Msk         (0x1UL << QUADSPI_CR_TCIE_Pos)	/*!< 0x00020000 */
#define QUADSPI_CR_TCIE             QUADSPI_CR_TCIE_Msk				/*!< Transfer Complete Interrupt Enable */
#define QUADSPI_CR_FTIE_Pos         (18U)
#define QUADSPI_CR_FTIE_Msk         (0x1UL << QUADSPI_CR_FTIE_Pos)	/*!< 0x00040000 */
#define QUADSPI_CR_FTIE             QUADSPI_CR_FTIE_Msk				/*!< FIFO Threshold Interrupt Enable    */
#define QUADSPI_CR_SMIE_Pos         (19U)
#define QUADSPI_CR_SMIE_Msk         (0x1UL << QUADSPI_CR_SMIE_Pos)	/*!< 0x00080000 */
#define QUADSPI_CR_SMIE             QUADSPI_CR_SMIE_Msk				/*!< Status Match Interrupt Enable      */
#define QUADSPI_CR_TOIE_Pos         (20U)
#define QUADSPI_CR_TOIE_Msk         (0x1UL << QUADSPI_CR_TOIE_Pos)	/*!< 0x00100000 */
#define QUADSPI_CR_TOIE             QUADSPI_CR_TOIE_Msk				/*!< TimeOut Interrupt Enable           */
#define QUADSPI_CR_APMS_Pos         (22U)
#define QUADSPI_CR_APMS_Msk         (0x1UL << QUADSPI_CR_APMS_Pos)	/*!< 0x00400000 */
#define QUADSPI_CR_APMS             QUADSPI_CR_APMS_Msk				/*!< Bit 1                              */
#define QUADSPI_CR_PMM_Pos          (23U)
#define QUADSPI_CR_PMM_Msk          (0x1UL << QUADSPI_CR_PMM_Pos)	/*!< 0x00800000 */
#define QUADSPI_CR_PMM              QUADSPI_CR_PMM_Msk				/*!< Polling Match Mode                 */
#define QUADSPI_CR_PRESCALER_Pos    (24U)
#define QUADSPI_CR_PRESCALER_Msk    (0xFFUL << QUADSPI_CR_PRESCALER_Pos)/*!< 0xFF000000 */
#define QUADSPI_CR_PRESCALER        QUADSPI_CR_PRESCALER_Msk/*!< PRESCALER[7:0] Clock prescaler     */
#define QUADSPI_CR_PRESCALER_0      (0x01UL << QUADSPI_CR_PRESCALER_Pos)/*!< 0x01000000 */
#define QUADSPI_CR_PRESCALER_1      (0x02UL << QUADSPI_CR_PRESCALER_Pos)/*!< 0x02000000 */
#define QUADSPI_CR_PRESCALER_2      (0x04UL << QUADSPI_CR_PRESCALER_Pos)/*!< 0x04000000 */
#define QUADSPI_CR_PRESCALER_3      (0x08UL << QUADSPI_CR_PRESCALER_Pos)/*!< 0x08000000 */
#define QUADSPI_CR_PRESCALER_4      (0x10UL << QUADSPI_CR_PRESCALER_Pos)/*!< 0x10000000 */
#define QUADSPI_CR_PRESCALER_5      (0x20UL << QUADSPI_CR_PRESCALER_Pos)/*!< 0x20000000 */
#define QUADSPI_CR_PRESCALER_6      (0x40UL << QUADSPI_CR_PRESCALER_Pos)/*!< 0x40000000 */
#define QUADSPI_CR_PRESCALER_7      (0x80UL << QUADSPI_CR_PRESCALER_Pos)/*!< 0x80000000 */

/*****************  Bit definition for QUADSPI_DCR register  ******************/
#define QUADSPI_DCR_CKMODE_Pos    (0U)
#define QUADSPI_DCR_CKMODE_Msk    (0x1UL << QUADSPI_DCR_CKMODE_Pos)	/*!< 0x00000001 */
#define QUADSPI_DCR_CKMODE        QUADSPI_DCR_CKMODE_Msk/*!< Mode 0 / Mode 3                 */
#define QUADSPI_DCR_CSHT_Pos      (8U)
#define QUADSPI_DCR_CSHT_Msk      (0x7UL << QUADSPI_DCR_CSHT_Pos)	/*!< 0x00000700 */
#define QUADSPI_DCR_CSHT          QUADSPI_DCR_CSHT_Msk				/*!< CSHT[2:0]: ChipSelect High Time */
#define QUADSPI_DCR_CSHT_0        (0x1UL << QUADSPI_DCR_CSHT_Pos)	/*!< 0x00000100 */
#define QUADSPI_DCR_CSHT_1        (0x2UL << QUADSPI_DCR_CSHT_Pos)	/*!< 0x00000200 */
#define QUADSPI_DCR_CSHT_2        (0x4UL << QUADSPI_DCR_CSHT_Pos)	/*!< 0x00000400 */
#define QUADSPI_DCR_FSIZE_Pos     (16U)
#define QUADSPI_DCR_FSIZE_Msk     (0x1FUL << QUADSPI_DCR_FSIZE_Pos)	/*!< 0x001F0000 */
#define QUADSPI_DCR_FSIZE         QUADSPI_DCR_FSIZE_Msk				/*!< FSIZE[4:0]: Flash Size          */
#define QUADSPI_DCR_FSIZE_0       (0x01UL << QUADSPI_DCR_FSIZE_Pos)	/*!< 0x00010000 */
#define QUADSPI_DCR_FSIZE_1       (0x02UL << QUADSPI_DCR_FSIZE_Pos)	/*!< 0x00020000 */
#define QUADSPI_DCR_FSIZE_2       (0x04UL << QUADSPI_DCR_FSIZE_Pos)	/*!< 0x00040000 */
#define QUADSPI_DCR_FSIZE_3       (0x08UL << QUADSPI_DCR_FSIZE_Pos)	/*!< 0x00080000 */
#define QUADSPI_DCR_FSIZE_4       (0x10UL << QUADSPI_DCR_FSIZE_Pos)	/*!< 0x00100000 */

/******************  Bit definition for QUADSPI_SR register  *******************/
#define QUADSPI_SR_TEF_Pos       (0U)
#define QUADSPI_SR_TEF_Msk       (0x1UL << QUADSPI_SR_TEF_Pos)	/*!< 0x00000001 */
#define QUADSPI_SR_TEF           QUADSPI_SR_TEF_Msk				/*!< Transfer Error Flag    */
#define QUADSPI_SR_TCF_Pos       (1U)
#define QUADSPI_SR_TCF_Msk       (0x1UL << QUADSPI_SR_TCF_Pos)	/*!< 0x00000002 */
#define QUADSPI_SR_TCF           QUADSPI_SR_TCF_Msk				/*!< Transfer Complete Flag */
#define QUADSPI_SR_FTF_Pos       (2U)
#define QUADSPI_SR_FTF_Msk       (0x1UL << QUADSPI_SR_FTF_Pos)	/*!< 0x00000004 */
#define QUADSPI_SR_FTF           QUADSPI_SR_FTF_Msk				/*!< FIFO Threshlod Flag    */
#define QUADSPI_SR_SMF_Pos       (3U)
#define QUADSPI_SR_SMF_Msk       (0x1UL << QUADSPI_SR_SMF_Pos)	/*!< 0x00000008 */
#define QUADSPI_SR_SMF           QUADSPI_SR_SMF_Msk				/*!< Status Match Flag      */
#define QUADSPI_SR_TOF_Pos       (4U)
#define QUADSPI_SR_TOF_Msk       (0x1UL << QUADSPI_SR_TOF_Pos)	/*!< 0x00000010 */
#define QUADSPI_SR_TOF           QUADSPI_SR_TOF_Msk				/*!< Timeout Flag           */
#define QUADSPI_SR_BUSY_Pos      (5U)
#define QUADSPI_SR_BUSY_Msk      (0x1UL << QUADSPI_SR_BUSY_Pos)	/*!< 0x00000020 */
#define QUADSPI_SR_BUSY          QUADSPI_SR_BUSY_Msk/*!< Busy                   */
#define QUADSPI_SR_FLEVEL_Pos    (8U)
#define QUADSPI_SR_FLEVEL_Msk    (0x3FUL << QUADSPI_SR_FLEVEL_Pos)	/*!< 0x00003F00 */
#define QUADSPI_SR_FLEVEL        QUADSPI_SR_FLEVEL_Msk				/*!< FIFO Threshlod Flag    */
#define QUADSPI_SR_FLEVEL_0      (0x01UL << QUADSPI_SR_FLEVEL_Pos)	/*!< 0x00000100 */
#define QUADSPI_SR_FLEVEL_1      (0x02UL << QUADSPI_SR_FLEVEL_Pos)	/*!< 0x00000200 */
#define QUADSPI_SR_FLEVEL_2      (0x04UL << QUADSPI_SR_FLEVEL_Pos)	/*!< 0x00000400 */
#define QUADSPI_SR_FLEVEL_3      (0x08UL << QUADSPI_SR_FLEVEL_Pos)	/*!< 0x00000800 */
#define QUADSPI_SR_FLEVEL_4      (0x10UL << QUADSPI_SR_FLEVEL_Pos)	/*!< 0x00001000 */
#define QUADSPI_SR_FLEVEL_5      (0x20UL << QUADSPI_SR_FLEVEL_Pos)	/*!< 0x00002000 */

/******************  Bit definition for QUADSPI_FCR register  ******************/
#define QUADSPI_FCR_CTEF_Pos    (0U)
#define QUADSPI_FCR_CTEF_Msk    (0x1UL << QUADSPI_FCR_CTEF_Pos)	/*!< 0x00000001 */
#define QUADSPI_FCR_CTEF        QUADSPI_FCR_CTEF_Msk/*!< Clear Transfer Error Flag    */
#define QUADSPI_FCR_CTCF_Pos    (1U)
#define QUADSPI_FCR_CTCF_Msk    (0x1UL << QUADSPI_FCR_CTCF_Pos)	/*!< 0x00000002 */
#define QUADSPI_FCR_CTCF        QUADSPI_FCR_CTCF_Msk/*!< Clear Transfer Complete Flag */
#define QUADSPI_FCR_CSMF_Pos    (3U)
#define QUADSPI_FCR_CSMF_Msk    (0x1UL << QUADSPI_FCR_CSMF_Pos)	/*!< 0x00000008 */
#define QUADSPI_FCR_CSMF        QUADSPI_FCR_CSMF_Msk/*!< Clear Status Match Flag      */
#define QUADSPI_FCR_CTOF_Pos    (4U)
#define QUADSPI_FCR_CTOF_Msk    (0x1UL << QUADSPI_FCR_CTOF_Pos)	/*!< 0x00000010 */
#define QUADSPI_FCR_CTOF        QUADSPI_FCR_CTOF_Msk/*!< Clear Timeout Flag           */

/******************  Bit definition for QUADSPI_DLR register  ******************/
#define QUADSPI_DLR_DL_Pos    (0U)
#define QUADSPI_DLR_DL_Msk    (0xFFFFFFFFUL << QUADSPI_DLR_DL_Pos)	/*!< 0xFFFFFFFF */
#define QUADSPI_DLR_DL        QUADSPI_DLR_DL_Msk					/*!< DL[31:0]: Data Length */

/******************  Bit definition for QUADSPI_CCR register  ******************/
#define QUADSPI_CCR_INSTRUCTION_Pos    (0U)
#define QUADSPI_CCR_INSTRUCTION_Msk    (0xFFUL << QUADSPI_CCR_INSTRUCTION_Pos)	/*!< 0x000000FF */
#define QUADSPI_CCR_INSTRUCTION        QUADSPI_CCR_INSTRUCTION_Msk				/*!< INSTRUCTION[7:0]: Instruction    */
#define QUADSPI_CCR_INSTRUCTION_0      (0x01UL << QUADSPI_CCR_INSTRUCTION_Pos)	/*!< 0x00000001 */
#define QUADSPI_CCR_INSTRUCTION_1      (0x02UL << QUADSPI_CCR_INSTRUCTION_Pos)	/*!< 0x00000002 */
#define QUADSPI_CCR_INSTRUCTION_2      (0x04UL << QUADSPI_CCR_INSTRUCTION_Pos)	/*!< 0x00000004 */
#define QUADSPI_CCR_INSTRUCTION_3      (0x08UL << QUADSPI_CCR_INSTRUCTION_Pos)	/*!< 0x00000008 */
#define QUADSPI_CCR_INSTRUCTION_4      (0x10UL << QUADSPI_CCR_INSTRUCTION_Pos)	/*!< 0x00000010 */
#define QUADSPI_CCR_INSTRUCTION_5      (0x20UL << QUADSPI_CCR_INSTRUCTION_Pos)	/*!< 0x00000020 */
#define QUADSPI_CCR_INSTRUCTION_6      (0x40UL << QUADSPI_CCR_INSTRUCTION_Pos)	/*!< 0x00000040 */
#define QUADSPI_CCR_INSTRUCTION_7      (0x80UL << QUADSPI_CCR_INSTRUCTION_Pos)	/*!< 0x00000080 */
#define QUADSPI_CCR_IMODE_Pos          (8U)
#define QUADSPI_CCR_IMODE_Msk          (0x3UL << QUADSPI_CCR_IMODE_Pos)	/*!< 0x00000300 */
#define QUADSPI_CCR_IMODE              QUADSPI_CCR_IMODE_Msk/*!< IMODE[1:0]: Instruction Mode      */
#define QUADSPI_CCR_IMODE_0            (0x1UL << QUADSPI_CCR_IMODE_Pos)	/*!< 0x00000100 */
#define QUADSPI_CCR_IMODE_1            (0x2UL << QUADSPI_CCR_IMODE_Pos)	/*!< 0x00000200 */
#define QUADSPI_CCR_ADMODE_Pos         (10U)
#define QUADSPI_CCR_ADMODE_Msk         (0x3UL << QUADSPI_CCR_ADMODE_Pos)/*!< 0x00000C00 */
#define QUADSPI_CCR_ADMODE             QUADSPI_CCR_ADMODE_Msk	/*!< ADMODE[1:0]: Address Mode         */
#define QUADSPI_CCR_ADMODE_0           (0x1UL << QUADSPI_CCR_ADMODE_Pos)/*!< 0x00000400 */
#define QUADSPI_CCR_ADMODE_1           (0x2UL << QUADSPI_CCR_ADMODE_Pos)/*!< 0x00000800 */
#define QUADSPI_CCR_ADSIZE_Pos         (12U)
#define QUADSPI_CCR_ADSIZE_Msk         (0x3UL << QUADSPI_CCR_ADSIZE_Pos)/*!< 0x00003000 */
#define QUADSPI_CCR_ADSIZE             QUADSPI_CCR_ADSIZE_Msk	/*!< ADSIZE[1:0]: Address Size         */
#define QUADSPI_CCR_ADSIZE_0           (0x1UL << QUADSPI_CCR_ADSIZE_Pos)/*!< 0x00001000 */
#define QUADSPI_CCR_ADSIZE_1           (0x2UL << QUADSPI_CCR_ADSIZE_Pos)/*!< 0x00002000 */
#define QUADSPI_CCR_ABMODE_Pos         (14U)
#define QUADSPI_CCR_ABMODE_Msk         (0x3UL << QUADSPI_CCR_ABMODE_Pos)/*!< 0x0000C000 */
#define QUADSPI_CCR_ABMODE             QUADSPI_CCR_ABMODE_Msk	/*!< ABMODE[1:0]: Alternate Bytes Mode */
#define QUADSPI_CCR_ABMODE_0           (0x1UL << QUADSPI_CCR_ABMODE_Pos)/*!< 0x00004000 */
#define QUADSPI_CCR_ABMODE_1           (0x2UL << QUADSPI_CCR_ABMODE_Pos)/*!< 0x00008000 */
#define QUADSPI_CCR_ABSIZE_Pos         (16U)
#define QUADSPI_CCR_ABSIZE_Msk         (0x3UL << QUADSPI_CCR_ABSIZE_Pos)/*!< 0x00030000 */
#define QUADSPI_CCR_ABSIZE             QUADSPI_CCR_ABSIZE_Msk	/*!< ABSIZE[1:0]: Instruction Mode     */
#define QUADSPI_CCR_ABSIZE_0           (0x1UL << QUADSPI_CCR_ABSIZE_Pos)/*!< 0x00010000 */
#define QUADSPI_CCR_ABSIZE_1           (0x2UL << QUADSPI_CCR_ABSIZE_Pos)/*!< 0x00020000 */
#define QUADSPI_CCR_DCYC_Pos           (18U)
#define QUADSPI_CCR_DCYC_Msk           (0x1FUL << QUADSPI_CCR_DCYC_Pos)	/*!< 0x007C0000 */
#define QUADSPI_CCR_DCYC               QUADSPI_CCR_DCYC_Msk				/*!< DCYC[4:0]: Dummy Cycles           */
#define QUADSPI_CCR_DCYC_0             (0x01UL << QUADSPI_CCR_DCYC_Pos)	/*!< 0x00040000 */
#define QUADSPI_CCR_DCYC_1             (0x02UL << QUADSPI_CCR_DCYC_Pos)	/*!< 0x00080000 */
#define QUADSPI_CCR_DCYC_2             (0x04UL << QUADSPI_CCR_DCYC_Pos)	/*!< 0x00100000 */
#define QUADSPI_CCR_DCYC_3             (0x08UL << QUADSPI_CCR_DCYC_Pos)	/*!< 0x00200000 */
#define QUADSPI_CCR_DCYC_4             (0x10UL << QUADSPI_CCR_DCYC_Pos)	/*!< 0x00400000 */
#define QUADSPI_CCR_DMODE_Pos          (24U)
#define QUADSPI_CCR_DMODE_Msk          (0x3UL << QUADSPI_CCR_DMODE_Pos)	/*!< 0x03000000 */
#define QUADSPI_CCR_DMODE              QUADSPI_CCR_DMODE_Msk/*!< DMODE[1:0]: Data Mode              */
#define QUADSPI_CCR_DMODE_0            (0x1UL << QUADSPI_CCR_DMODE_Pos)	/*!< 0x01000000 */
#define QUADSPI_CCR_DMODE_1            (0x2UL << QUADSPI_CCR_DMODE_Pos)	/*!< 0x02000000 */
#define QUADSPI_CCR_FMODE_Pos          (26U)
#define QUADSPI_CCR_FMODE_Msk          (0x3UL << QUADSPI_CCR_FMODE_Pos)	/*!< 0x0C000000 */
#define QUADSPI_CCR_FMODE              QUADSPI_CCR_FMODE_Msk/*!< FMODE[1:0]: Functional Mode        */
#define QUADSPI_CCR_FMODE_0            (0x1UL << QUADSPI_CCR_FMODE_Pos)	/*!< 0x04000000 */
#define QUADSPI_CCR_FMODE_1            (0x2UL << QUADSPI_CCR_FMODE_Pos)	/*!< 0x08000000 */
#define QUADSPI_CCR_SIOO_Pos           (28U)
#define QUADSPI_CCR_SIOO_Msk           (0x1UL << QUADSPI_CCR_SIOO_Pos)	/*!< 0x10000000 */
#define QUADSPI_CCR_SIOO               QUADSPI_CCR_SIOO_Msk				/*!< SIOO: Send Instruction Only Once Mode */
#define QUADSPI_CCR_DHHC_Pos           (30U)
#define QUADSPI_CCR_DHHC_Msk           (0x1UL << QUADSPI_CCR_DHHC_Pos)	/*!< 0x40000000 */
#define QUADSPI_CCR_DHHC               QUADSPI_CCR_DHHC_Msk				/*!< DHHC: Delay Half Hclk Cycle           */
#define QUADSPI_CCR_DDRM_Pos           (31U)
#define QUADSPI_CCR_DDRM_Msk           (0x1UL << QUADSPI_CCR_DDRM_Pos)	/*!< 0x80000000 */
#define QUADSPI_CCR_DDRM               QUADSPI_CCR_DDRM_Msk				/*!< DDRM: Double Data Rate Mode           */
/******************  Bit definition for QUADSPI_AR register  *******************/
#define QUADSPI_AR_ADDRESS_Pos         (0U)
#define QUADSPI_AR_ADDRESS_Msk         (0xFFFFFFFFUL << QUADSPI_AR_ADDRESS_Pos)	/*!< 0xFFFFFFFF */
#define QUADSPI_AR_ADDRESS             QUADSPI_AR_ADDRESS_Msk					/*!< ADDRESS[31:0]: Address */

/******************  Bit definition for QUADSPI_ABR register  ******************/
#define QUADSPI_ABR_ALTERNATE_Pos    (0U)
#define QUADSPI_ABR_ALTERNATE_Msk    (0xFFFFFFFFUL << QUADSPI_ABR_ALTERNATE_Pos)/*!< 0xFFFFFFFF */
#define QUADSPI_ABR_ALTERNATE        QUADSPI_ABR_ALTERNATE_Msk	/*!< ALTERNATE[31:0]: Alternate Bytes */

/******************  Bit definition for QUADSPI_DR register  *******************/
#define QUADSPI_DR_DATA_Pos    (0U)
#define QUADSPI_DR_DATA_Msk    (0xFFFFFFFFUL << QUADSPI_DR_DATA_Pos)/*!< 0xFFFFFFFF */
#define QUADSPI_DR_DATA        QUADSPI_DR_DATA_Msk	/*!< DATA[31:0]: Data */

/******************  Bit definition for QUADSPI_PSMKR register  ****************/
#define QUADSPI_PSMKR_MASK_Pos    (0U)
#define QUADSPI_PSMKR_MASK_Msk    (0xFFFFFFFFUL << QUADSPI_PSMKR_MASK_Pos)	/*!< 0xFFFFFFFF */
#define QUADSPI_PSMKR_MASK        QUADSPI_PSMKR_MASK_Msk					/*!< MASK[31:0]: Status Mask */

/******************  Bit definition for QUADSPI_PSMAR register  ****************/
#define QUADSPI_PSMAR_MATCH_Pos    (0U)
#define QUADSPI_PSMAR_MATCH_Msk    (0xFFFFFFFFUL << QUADSPI_PSMAR_MATCH_Pos)/*!< 0xFFFFFFFF */
#define QUADSPI_PSMAR_MATCH        QUADSPI_PSMAR_MATCH_Msk	/*!< MATCH[31:0]: Status Match */

/******************  Bit definition for QUADSPI_PIR register  *****************/
#define QUADSPI_PIR_INTERVAL_Pos    (0U)
#define QUADSPI_PIR_INTERVAL_Msk    (0xFFFFUL << QUADSPI_PIR_INTERVAL_Pos)	/*!< 0x0000FFFF */
#define QUADSPI_PIR_INTERVAL        QUADSPI_PIR_INTERVAL_Msk				/*!< INTERVAL[15:0]: Polling Interval */

/******************  Bit definition for QUADSPI_LPTR register  *****************/
#define QUADSPI_LPTR_TIMEOUT_Pos    (0U)
#define QUADSPI_LPTR_TIMEOUT_Msk    (0xFFFFUL << QUADSPI_LPTR_TIMEOUT_Pos)	/*!< 0x0000FFFF */
#define QUADSPI_LPTR_TIMEOUT        QUADSPI_LPTR_TIMEOUT_Msk				/*!< TIMEOUT[15:0]: Timeout period */

/******************************************************************************/
/*                                                                            */
/*                         Reset and Clock Control            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for RCC_CR register  ********************/
#define RCC_CR_HSION_Pos        (0U)
#define RCC_CR_HSION_Msk        (0x1UL << RCC_CR_HSION_Pos)	/*!< 0x00000001 */
#define RCC_CR_HSION            RCC_CR_HSION_Msk
#define RCC_CR_HSIRDY_Pos       (1U)
#define RCC_CR_HSIRDY_Msk       (0x1UL << RCC_CR_HSIRDY_Pos)/*!< 0x00000002 */
#define RCC_CR_HSIRDY           RCC_CR_HSIRDY_Msk
#define RCC_CR_HSITRIM_Pos      (3U)
#define RCC_CR_HSITRIM_Msk      (0x1FUL << RCC_CR_HSITRIM_Pos)	/*!< 0x000000F8 */
#define RCC_CR_HSITRIM          RCC_CR_HSITRIM_Msk
#define RCC_CR_HSITRIM_0        (0x01UL << RCC_CR_HSITRIM_Pos)	/*!< 0x00000008 */
#define RCC_CR_HSITRIM_1        (0x02UL << RCC_CR_HSITRIM_Pos)	/*!< 0x00000010 */
#define RCC_CR_HSITRIM_2        (0x04UL << RCC_CR_HSITRIM_Pos)	/*!< 0x00000020 */
#define RCC_CR_HSITRIM_3        (0x08UL << RCC_CR_HSITRIM_Pos)	/*!< 0x00000040 */
#define RCC_CR_HSITRIM_4        (0x10UL << RCC_CR_HSITRIM_Pos)	/*!< 0x00000080 */
#define RCC_CR_HSICAL_Pos       (8U)
#define RCC_CR_HSICAL_Msk       (0xFFUL << RCC_CR_HSICAL_Pos)	/*!< 0x0000FF00 */
#define RCC_CR_HSICAL           RCC_CR_HSICAL_Msk
#define RCC_CR_HSICAL_0         (0x01UL << RCC_CR_HSICAL_Pos)	/*!< 0x00000100 */
#define RCC_CR_HSICAL_1         (0x02UL << RCC_CR_HSICAL_Pos)	/*!< 0x00000200 */
#define RCC_CR_HSICAL_2         (0x04UL << RCC_CR_HSICAL_Pos)	/*!< 0x00000400 */
#define RCC_CR_HSICAL_3         (0x08UL << RCC_CR_HSICAL_Pos)	/*!< 0x00000800 */
#define RCC_CR_HSICAL_4         (0x10UL << RCC_CR_HSICAL_Pos)	/*!< 0x00001000 */
#define RCC_CR_HSICAL_5         (0x20UL << RCC_CR_HSICAL_Pos)	/*!< 0x00002000 */
#define RCC_CR_HSICAL_6         (0x40UL << RCC_CR_HSICAL_Pos)	/*!< 0x00004000 */
#define RCC_CR_HSICAL_7         (0x80UL << RCC_CR_HSICAL_Pos)	/*!< 0x00008000 */
#define RCC_CR_HSEON_Pos        (16U)
#define RCC_CR_HSEON_Msk        (0x1UL << RCC_CR_HSEON_Pos)	/*!< 0x00010000 */
#define RCC_CR_HSEON            RCC_CR_HSEON_Msk
#define RCC_CR_HSERDY_Pos       (17U)
#define RCC_CR_HSERDY_Msk       (0x1UL << RCC_CR_HSERDY_Pos)/*!< 0x00020000 */
#define RCC_CR_HSERDY           RCC_CR_HSERDY_Msk
#define RCC_CR_HSEBYP_Pos       (18U)
#define RCC_CR_HSEBYP_Msk       (0x1UL << RCC_CR_HSEBYP_Pos)/*!< 0x00040000 */
#define RCC_CR_HSEBYP           RCC_CR_HSEBYP_Msk
#define RCC_CR_CSSON_Pos        (19U)
#define RCC_CR_CSSON_Msk        (0x1UL << RCC_CR_CSSON_Pos)	/*!< 0x00080000 */
#define RCC_CR_CSSON            RCC_CR_CSSON_Msk
#define RCC_CR_PLLON_Pos        (24U)
#define RCC_CR_PLLON_Msk        (0x1UL << RCC_CR_PLLON_Pos)	/*!< 0x01000000 */
#define RCC_CR_PLLON            RCC_CR_PLLON_Msk
#define RCC_CR_PLLRDY_Pos       (25U)
#define RCC_CR_PLLRDY_Msk       (0x1UL << RCC_CR_PLLRDY_Pos)/*!< 0x02000000 */
#define RCC_CR_PLLRDY           RCC_CR_PLLRDY_Msk
#define RCC_CR_PLLI2SON_Pos     (26U)
#define RCC_CR_PLLI2SON_Msk     (0x1UL << RCC_CR_PLLI2SON_Pos)	/*!< 0x04000000 */
#define RCC_CR_PLLI2SON         RCC_CR_PLLI2SON_Msk
#define RCC_CR_PLLI2SRDY_Pos    (27U)
#define RCC_CR_PLLI2SRDY_Msk    (0x1UL << RCC_CR_PLLI2SRDY_Pos)	/*!< 0x08000000 */
#define RCC_CR_PLLI2SRDY        RCC_CR_PLLI2SRDY_Msk
#define RCC_CR_PLLSAION_Pos     (28U)
#define RCC_CR_PLLSAION_Msk     (0x1UL << RCC_CR_PLLSAION_Pos)	/*!< 0x10000000 */
#define RCC_CR_PLLSAION         RCC_CR_PLLSAION_Msk
#define RCC_CR_PLLSAIRDY_Pos    (29U)
#define RCC_CR_PLLSAIRDY_Msk    (0x1UL << RCC_CR_PLLSAIRDY_Pos)	/*!< 0x20000000 */
#define RCC_CR_PLLSAIRDY        RCC_CR_PLLSAIRDY_Msk

/********************  Bit definition for RCC_PLLCFGR register  ***************/
#define RCC_PLLCFGR_PLLM_Pos          (0U)
#define RCC_PLLCFGR_PLLM_Msk          (0x3FUL << RCC_PLLCFGR_PLLM_Pos)	/*!< 0x0000003F */
#define RCC_PLLCFGR_PLLM              RCC_PLLCFGR_PLLM_Msk
#define RCC_PLLCFGR_PLLM_0            (0x01UL << RCC_PLLCFGR_PLLM_Pos)	/*!< 0x00000001 */
#define RCC_PLLCFGR_PLLM_1            (0x02UL << RCC_PLLCFGR_PLLM_Pos)	/*!< 0x00000002 */
#define RCC_PLLCFGR_PLLM_2            (0x04UL << RCC_PLLCFGR_PLLM_Pos)	/*!< 0x00000004 */
#define RCC_PLLCFGR_PLLM_3            (0x08UL << RCC_PLLCFGR_PLLM_Pos)	/*!< 0x00000008 */
#define RCC_PLLCFGR_PLLM_4            (0x10UL << RCC_PLLCFGR_PLLM_Pos)	/*!< 0x00000010 */
#define RCC_PLLCFGR_PLLM_5            (0x20UL << RCC_PLLCFGR_PLLM_Pos)	/*!< 0x00000020 */
#define RCC_PLLCFGR_PLLN_Pos          (6U)
#define RCC_PLLCFGR_PLLN_Msk          (0x1FFUL << RCC_PLLCFGR_PLLN_Pos)	/*!< 0x00007FC0 */
#define RCC_PLLCFGR_PLLN              RCC_PLLCFGR_PLLN_Msk
#define RCC_PLLCFGR_PLLN_0            (0x001UL << RCC_PLLCFGR_PLLN_Pos)	/*!< 0x00000040 */
#define RCC_PLLCFGR_PLLN_1            (0x002UL << RCC_PLLCFGR_PLLN_Pos)	/*!< 0x00000080 */
#define RCC_PLLCFGR_PLLN_2            (0x004UL << RCC_PLLCFGR_PLLN_Pos)	/*!< 0x00000100 */
#define RCC_PLLCFGR_PLLN_3            (0x008UL << RCC_PLLCFGR_PLLN_Pos)	/*!< 0x00000200 */
#define RCC_PLLCFGR_PLLN_4            (0x010UL << RCC_PLLCFGR_PLLN_Pos)	/*!< 0x00000400 */
#define RCC_PLLCFGR_PLLN_5            (0x020UL << RCC_PLLCFGR_PLLN_Pos)	/*!< 0x00000800 */
#define RCC_PLLCFGR_PLLN_6            (0x040UL << RCC_PLLCFGR_PLLN_Pos)	/*!< 0x00001000 */
#define RCC_PLLCFGR_PLLN_7            (0x080UL << RCC_PLLCFGR_PLLN_Pos)	/*!< 0x00002000 */
#define RCC_PLLCFGR_PLLN_8            (0x100UL << RCC_PLLCFGR_PLLN_Pos)	/*!< 0x00004000 */
#define RCC_PLLCFGR_PLLP_Pos          (16U)
#define RCC_PLLCFGR_PLLP_Msk          (0x3UL << RCC_PLLCFGR_PLLP_Pos)	/*!< 0x00030000 */
#define RCC_PLLCFGR_PLLP              RCC_PLLCFGR_PLLP_Msk
#define RCC_PLLCFGR_PLLP_0            (0x1UL << RCC_PLLCFGR_PLLP_Pos)	/*!< 0x00010000 */
#define RCC_PLLCFGR_PLLP_1            (0x2UL << RCC_PLLCFGR_PLLP_Pos)	/*!< 0x00020000 */
#define RCC_PLLCFGR_PLLSRC_Pos        (22U)
#define RCC_PLLCFGR_PLLSRC_Msk        (0x1UL << RCC_PLLCFGR_PLLSRC_Pos)	/*!< 0x00400000 */
#define RCC_PLLCFGR_PLLSRC            RCC_PLLCFGR_PLLSRC_Msk
#define RCC_PLLCFGR_PLLSRC_HSE_Pos    (22U)
#define RCC_PLLCFGR_PLLSRC_HSE_Msk    (0x1UL << RCC_PLLCFGR_PLLSRC_HSE_Pos)	/*!< 0x00400000 */
#define RCC_PLLCFGR_PLLSRC_HSE        RCC_PLLCFGR_PLLSRC_HSE_Msk
#define RCC_PLLCFGR_PLLSRC_HSI        0x00000000U
#define RCC_PLLCFGR_PLLQ_Pos          (24U)
#define RCC_PLLCFGR_PLLQ_Msk          (0xFUL << RCC_PLLCFGR_PLLQ_Pos)	/*!< 0x0F000000 */
#define RCC_PLLCFGR_PLLQ              RCC_PLLCFGR_PLLQ_Msk
#define RCC_PLLCFGR_PLLQ_0            (0x1UL << RCC_PLLCFGR_PLLQ_Pos)	/*!< 0x01000000 */
#define RCC_PLLCFGR_PLLQ_1            (0x2UL << RCC_PLLCFGR_PLLQ_Pos)	/*!< 0x02000000 */
#define RCC_PLLCFGR_PLLQ_2            (0x4UL << RCC_PLLCFGR_PLLQ_Pos)	/*!< 0x04000000 */
#define RCC_PLLCFGR_PLLQ_3            (0x8UL << RCC_PLLCFGR_PLLQ_Pos)	/*!< 0x08000000 */


/********************  Bit definition for RCC_CFGR register  ******************/
/*!< SW configuration */
#define RCC_CFGR_SW_Pos    (0U)
#define RCC_CFGR_SW_Msk    (0x3UL << RCC_CFGR_SW_Pos)	/*!< 0x00000003 */
#define RCC_CFGR_SW        RCC_CFGR_SW_Msk				/*!< SW[1:0] bits (System clock Switch) */
#define RCC_CFGR_SW_0      (0x1UL << RCC_CFGR_SW_Pos)	/*!< 0x00000001 */
#define RCC_CFGR_SW_1      (0x2UL << RCC_CFGR_SW_Pos)	/*!< 0x00000002 */
#define RCC_CFGR_SW_HSI    0x00000000U					/*!< HSI selected as system clock */
#define RCC_CFGR_SW_HSE    0x00000001U					/*!< HSE selected as system clock */
#define RCC_CFGR_SW_PLL    0x00000002U					/*!< PLL selected as system clock */

/*!< SWS configuration */
#define RCC_CFGR_SWS_Pos    (2U)
#define RCC_CFGR_SWS_Msk    (0x3UL << RCC_CFGR_SWS_Pos)	/*!< 0x0000000C */
#define RCC_CFGR_SWS        RCC_CFGR_SWS_Msk/*!< SWS[1:0] bits (System Clock Switch Status) */
#define RCC_CFGR_SWS_0      (0x1UL << RCC_CFGR_SWS_Pos)	/*!< 0x00000004 */
#define RCC_CFGR_SWS_1      (0x2UL << RCC_CFGR_SWS_Pos)	/*!< 0x00000008 */
#define RCC_CFGR_SWS_HSI    0x00000000U					/*!< HSI oscillator used as system clock */
#define RCC_CFGR_SWS_HSE    0x00000004U					/*!< HSE oscillator used as system clock */
#define RCC_CFGR_SWS_PLL    0x00000008U					/*!< PLL used as system clock */

/*!< HPRE configuration */
#define RCC_CFGR_HPRE_Pos       (4U)
#define RCC_CFGR_HPRE_Msk       (0xFUL << RCC_CFGR_HPRE_Pos)/*!< 0x000000F0 */
#define RCC_CFGR_HPRE           RCC_CFGR_HPRE_Msk	/*!< HPRE[3:0] bits (AHB prescaler) */
#define RCC_CFGR_HPRE_0         (0x1UL << RCC_CFGR_HPRE_Pos)/*!< 0x00000010 */
#define RCC_CFGR_HPRE_1         (0x2UL << RCC_CFGR_HPRE_Pos)/*!< 0x00000020 */
#define RCC_CFGR_HPRE_2         (0x4UL << RCC_CFGR_HPRE_Pos)/*!< 0x00000040 */
#define RCC_CFGR_HPRE_3         (0x8UL << RCC_CFGR_HPRE_Pos)/*!< 0x00000080 */

#define RCC_CFGR_HPRE_DIV1      0x00000000U	/*!< SYSCLK not divided */
#define RCC_CFGR_HPRE_DIV2      0x00000080U	/*!< SYSCLK divided by 2 */
#define RCC_CFGR_HPRE_DIV4      0x00000090U	/*!< SYSCLK divided by 4 */
#define RCC_CFGR_HPRE_DIV8      0x000000A0U	/*!< SYSCLK divided by 8 */
#define RCC_CFGR_HPRE_DIV16     0x000000B0U	/*!< SYSCLK divided by 16 */
#define RCC_CFGR_HPRE_DIV64     0x000000C0U	/*!< SYSCLK divided by 64 */
#define RCC_CFGR_HPRE_DIV128    0x000000D0U	/*!< SYSCLK divided by 128 */
#define RCC_CFGR_HPRE_DIV256    0x000000E0U	/*!< SYSCLK divided by 256 */
#define RCC_CFGR_HPRE_DIV512    0x000000F0U	/*!< SYSCLK divided by 512 */

/*!< PPRE1 configuration */
#define RCC_CFGR_PPRE1_Pos      (10U)
#define RCC_CFGR_PPRE1_Msk      (0x7UL << RCC_CFGR_PPRE1_Pos)	/*!< 0x00001C00 */
#define RCC_CFGR_PPRE1          RCC_CFGR_PPRE1_Msk				/*!< PRE1[2:0] bits (APB1 prescaler) */
#define RCC_CFGR_PPRE1_0        (0x1UL << RCC_CFGR_PPRE1_Pos)	/*!< 0x00000400 */
#define RCC_CFGR_PPRE1_1        (0x2UL << RCC_CFGR_PPRE1_Pos)	/*!< 0x00000800 */
#define RCC_CFGR_PPRE1_2        (0x4UL << RCC_CFGR_PPRE1_Pos)	/*!< 0x00001000 */

#define RCC_CFGR_PPRE1_DIV1     0x00000000U	/*!< HCLK not divided */
#define RCC_CFGR_PPRE1_DIV2     0x00001000U	/*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE1_DIV4     0x00001400U	/*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE1_DIV8     0x00001800U	/*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE1_DIV16    0x00001C00U	/*!< HCLK divided by 16 */

/*!< PPRE2 configuration */
#define RCC_CFGR_PPRE2_Pos      (13U)
#define RCC_CFGR_PPRE2_Msk      (0x7UL << RCC_CFGR_PPRE2_Pos)	/*!< 0x0000E000 */
#define RCC_CFGR_PPRE2          RCC_CFGR_PPRE2_Msk				/*!< PRE2[2:0] bits (APB2 prescaler) */
#define RCC_CFGR_PPRE2_0        (0x1UL << RCC_CFGR_PPRE2_Pos)	/*!< 0x00002000 */
#define RCC_CFGR_PPRE2_1        (0x2UL << RCC_CFGR_PPRE2_Pos)	/*!< 0x00004000 */
#define RCC_CFGR_PPRE2_2        (0x4UL << RCC_CFGR_PPRE2_Pos)	/*!< 0x00008000 */

#define RCC_CFGR_PPRE2_DIV1     0x00000000U	/*!< HCLK not divided */
#define RCC_CFGR_PPRE2_DIV2     0x00008000U	/*!< HCLK divided by 2 */
#define RCC_CFGR_PPRE2_DIV4     0x0000A000U	/*!< HCLK divided by 4 */
#define RCC_CFGR_PPRE2_DIV8     0x0000C000U	/*!< HCLK divided by 8 */
#define RCC_CFGR_PPRE2_DIV16    0x0000E000U	/*!< HCLK divided by 16 */

/*!< RTCPRE configuration */
#define RCC_CFGR_RTCPRE_Pos    (16U)
#define RCC_CFGR_RTCPRE_Msk    (0x1FUL << RCC_CFGR_RTCPRE_Pos)	/*!< 0x001F0000 */
#define RCC_CFGR_RTCPRE        RCC_CFGR_RTCPRE_Msk
#define RCC_CFGR_RTCPRE_0      (0x01UL << RCC_CFGR_RTCPRE_Pos)	/*!< 0x00010000 */
#define RCC_CFGR_RTCPRE_1      (0x02UL << RCC_CFGR_RTCPRE_Pos)	/*!< 0x00020000 */
#define RCC_CFGR_RTCPRE_2      (0x04UL << RCC_CFGR_RTCPRE_Pos)	/*!< 0x00040000 */
#define RCC_CFGR_RTCPRE_3      (0x08UL << RCC_CFGR_RTCPRE_Pos)	/*!< 0x00080000 */
#define RCC_CFGR_RTCPRE_4      (0x10UL << RCC_CFGR_RTCPRE_Pos)	/*!< 0x00100000 */

/*!< MCO1 configuration */
#define RCC_CFGR_MCO1_Pos       (21U)
#define RCC_CFGR_MCO1_Msk       (0x3UL << RCC_CFGR_MCO1_Pos)/*!< 0x00600000 */
#define RCC_CFGR_MCO1           RCC_CFGR_MCO1_Msk
#define RCC_CFGR_MCO1_0         (0x1UL << RCC_CFGR_MCO1_Pos)/*!< 0x00200000 */
#define RCC_CFGR_MCO1_1         (0x2UL << RCC_CFGR_MCO1_Pos)/*!< 0x00400000 */

#define RCC_CFGR_I2SSRC_Pos     (23U)
#define RCC_CFGR_I2SSRC_Msk     (0x1UL << RCC_CFGR_I2SSRC_Pos)	/*!< 0x00800000 */
#define RCC_CFGR_I2SSRC         RCC_CFGR_I2SSRC_Msk

#define RCC_CFGR_MCO1PRE_Pos    (24U)
#define RCC_CFGR_MCO1PRE_Msk    (0x7UL << RCC_CFGR_MCO1PRE_Pos)	/*!< 0x07000000 */
#define RCC_CFGR_MCO1PRE        RCC_CFGR_MCO1PRE_Msk
#define RCC_CFGR_MCO1PRE_0      (0x1UL << RCC_CFGR_MCO1PRE_Pos)	/*!< 0x01000000 */
#define RCC_CFGR_MCO1PRE_1      (0x2UL << RCC_CFGR_MCO1PRE_Pos)	/*!< 0x02000000 */
#define RCC_CFGR_MCO1PRE_2      (0x4UL << RCC_CFGR_MCO1PRE_Pos)	/*!< 0x04000000 */

#define RCC_CFGR_MCO2PRE_Pos    (27U)
#define RCC_CFGR_MCO2PRE_Msk    (0x7UL << RCC_CFGR_MCO2PRE_Pos)	/*!< 0x38000000 */
#define RCC_CFGR_MCO2PRE        RCC_CFGR_MCO2PRE_Msk
#define RCC_CFGR_MCO2PRE_0      (0x1UL << RCC_CFGR_MCO2PRE_Pos)	/*!< 0x08000000 */
#define RCC_CFGR_MCO2PRE_1      (0x2UL << RCC_CFGR_MCO2PRE_Pos)	/*!< 0x10000000 */
#define RCC_CFGR_MCO2PRE_2      (0x4UL << RCC_CFGR_MCO2PRE_Pos)	/*!< 0x20000000 */

#define RCC_CFGR_MCO2_Pos       (30U)
#define RCC_CFGR_MCO2_Msk       (0x3UL << RCC_CFGR_MCO2_Pos)/*!< 0xC0000000 */
#define RCC_CFGR_MCO2           RCC_CFGR_MCO2_Msk
#define RCC_CFGR_MCO2_0         (0x1UL << RCC_CFGR_MCO2_Pos)/*!< 0x40000000 */
#define RCC_CFGR_MCO2_1         (0x2UL << RCC_CFGR_MCO2_Pos)/*!< 0x80000000 */

/********************  Bit definition for RCC_CIR register  *******************/
#define RCC_CIR_LSIRDYF_Pos        (0U)
#define RCC_CIR_LSIRDYF_Msk        (0x1UL << RCC_CIR_LSIRDYF_Pos)	/*!< 0x00000001 */
#define RCC_CIR_LSIRDYF            RCC_CIR_LSIRDYF_Msk
#define RCC_CIR_LSERDYF_Pos        (1U)
#define RCC_CIR_LSERDYF_Msk        (0x1UL << RCC_CIR_LSERDYF_Pos)	/*!< 0x00000002 */
#define RCC_CIR_LSERDYF            RCC_CIR_LSERDYF_Msk
#define RCC_CIR_HSIRDYF_Pos        (2U)
#define RCC_CIR_HSIRDYF_Msk        (0x1UL << RCC_CIR_HSIRDYF_Pos)	/*!< 0x00000004 */
#define RCC_CIR_HSIRDYF            RCC_CIR_HSIRDYF_Msk
#define RCC_CIR_HSERDYF_Pos        (3U)
#define RCC_CIR_HSERDYF_Msk        (0x1UL << RCC_CIR_HSERDYF_Pos)	/*!< 0x00000008 */
#define RCC_CIR_HSERDYF            RCC_CIR_HSERDYF_Msk
#define RCC_CIR_PLLRDYF_Pos        (4U)
#define RCC_CIR_PLLRDYF_Msk        (0x1UL << RCC_CIR_PLLRDYF_Pos)	/*!< 0x00000010 */
#define RCC_CIR_PLLRDYF            RCC_CIR_PLLRDYF_Msk
#define RCC_CIR_PLLI2SRDYF_Pos     (5U)
#define RCC_CIR_PLLI2SRDYF_Msk     (0x1UL << RCC_CIR_PLLI2SRDYF_Pos)/*!< 0x00000020 */
#define RCC_CIR_PLLI2SRDYF         RCC_CIR_PLLI2SRDYF_Msk
#define RCC_CIR_PLLSAIRDYF_Pos     (6U)
#define RCC_CIR_PLLSAIRDYF_Msk     (0x1UL << RCC_CIR_PLLSAIRDYF_Pos)/*!< 0x00000040 */
#define RCC_CIR_PLLSAIRDYF         RCC_CIR_PLLSAIRDYF_Msk
#define RCC_CIR_CSSF_Pos           (7U)
#define RCC_CIR_CSSF_Msk           (0x1UL << RCC_CIR_CSSF_Pos)	/*!< 0x00000080 */
#define RCC_CIR_CSSF               RCC_CIR_CSSF_Msk
#define RCC_CIR_LSIRDYIE_Pos       (8U)
#define RCC_CIR_LSIRDYIE_Msk       (0x1UL << RCC_CIR_LSIRDYIE_Pos)	/*!< 0x00000100 */
#define RCC_CIR_LSIRDYIE           RCC_CIR_LSIRDYIE_Msk
#define RCC_CIR_LSERDYIE_Pos       (9U)
#define RCC_CIR_LSERDYIE_Msk       (0x1UL << RCC_CIR_LSERDYIE_Pos)	/*!< 0x00000200 */
#define RCC_CIR_LSERDYIE           RCC_CIR_LSERDYIE_Msk
#define RCC_CIR_HSIRDYIE_Pos       (10U)
#define RCC_CIR_HSIRDYIE_Msk       (0x1UL << RCC_CIR_HSIRDYIE_Pos)	/*!< 0x00000400 */
#define RCC_CIR_HSIRDYIE           RCC_CIR_HSIRDYIE_Msk
#define RCC_CIR_HSERDYIE_Pos       (11U)
#define RCC_CIR_HSERDYIE_Msk       (0x1UL << RCC_CIR_HSERDYIE_Pos)	/*!< 0x00000800 */
#define RCC_CIR_HSERDYIE           RCC_CIR_HSERDYIE_Msk
#define RCC_CIR_PLLRDYIE_Pos       (12U)
#define RCC_CIR_PLLRDYIE_Msk       (0x1UL << RCC_CIR_PLLRDYIE_Pos)	/*!< 0x00001000 */
#define RCC_CIR_PLLRDYIE           RCC_CIR_PLLRDYIE_Msk
#define RCC_CIR_PLLI2SRDYIE_Pos    (13U)
#define RCC_CIR_PLLI2SRDYIE_Msk    (0x1UL << RCC_CIR_PLLI2SRDYIE_Pos)	/*!< 0x00002000 */
#define RCC_CIR_PLLI2SRDYIE        RCC_CIR_PLLI2SRDYIE_Msk
#define RCC_CIR_PLLSAIRDYIE_Pos    (14U)
#define RCC_CIR_PLLSAIRDYIE_Msk    (0x1UL << RCC_CIR_PLLSAIRDYIE_Pos)	/*!< 0x00004000 */
#define RCC_CIR_PLLSAIRDYIE        RCC_CIR_PLLSAIRDYIE_Msk
#define RCC_CIR_LSIRDYC_Pos        (16U)
#define RCC_CIR_LSIRDYC_Msk        (0x1UL << RCC_CIR_LSIRDYC_Pos)	/*!< 0x00010000 */
#define RCC_CIR_LSIRDYC            RCC_CIR_LSIRDYC_Msk
#define RCC_CIR_LSERDYC_Pos        (17U)
#define RCC_CIR_LSERDYC_Msk        (0x1UL << RCC_CIR_LSERDYC_Pos)	/*!< 0x00020000 */
#define RCC_CIR_LSERDYC            RCC_CIR_LSERDYC_Msk
#define RCC_CIR_HSIRDYC_Pos        (18U)
#define RCC_CIR_HSIRDYC_Msk        (0x1UL << RCC_CIR_HSIRDYC_Pos)	/*!< 0x00040000 */
#define RCC_CIR_HSIRDYC            RCC_CIR_HSIRDYC_Msk
#define RCC_CIR_HSERDYC_Pos        (19U)
#define RCC_CIR_HSERDYC_Msk        (0x1UL << RCC_CIR_HSERDYC_Pos)	/*!< 0x00080000 */
#define RCC_CIR_HSERDYC            RCC_CIR_HSERDYC_Msk
#define RCC_CIR_PLLRDYC_Pos        (20U)
#define RCC_CIR_PLLRDYC_Msk        (0x1UL << RCC_CIR_PLLRDYC_Pos)	/*!< 0x00100000 */
#define RCC_CIR_PLLRDYC            RCC_CIR_PLLRDYC_Msk
#define RCC_CIR_PLLI2SRDYC_Pos     (21U)
#define RCC_CIR_PLLI2SRDYC_Msk     (0x1UL << RCC_CIR_PLLI2SRDYC_Pos)/*!< 0x00200000 */
#define RCC_CIR_PLLI2SRDYC         RCC_CIR_PLLI2SRDYC_Msk
#define RCC_CIR_PLLSAIRDYC_Pos     (22U)
#define RCC_CIR_PLLSAIRDYC_Msk     (0x1UL << RCC_CIR_PLLSAIRDYC_Pos)/*!< 0x00400000 */
#define RCC_CIR_PLLSAIRDYC         RCC_CIR_PLLSAIRDYC_Msk
#define RCC_CIR_CSSC_Pos           (23U)
#define RCC_CIR_CSSC_Msk           (0x1UL << RCC_CIR_CSSC_Pos)	/*!< 0x00800000 */
#define RCC_CIR_CSSC               RCC_CIR_CSSC_Msk

/********************  Bit definition for RCC_AHB1RSTR register  **************/
#define RCC_AHB1RSTR_GPIOARST_Pos    (0U)
#define RCC_AHB1RSTR_GPIOARST_Msk    (0x1UL << RCC_AHB1RSTR_GPIOARST_Pos)	/*!< 0x00000001 */
#define RCC_AHB1RSTR_GPIOARST        RCC_AHB1RSTR_GPIOARST_Msk
#define RCC_AHB1RSTR_GPIOBRST_Pos    (1U)
#define RCC_AHB1RSTR_GPIOBRST_Msk    (0x1UL << RCC_AHB1RSTR_GPIOBRST_Pos)	/*!< 0x00000002 */
#define RCC_AHB1RSTR_GPIOBRST        RCC_AHB1RSTR_GPIOBRST_Msk
#define RCC_AHB1RSTR_GPIOCRST_Pos    (2U)
#define RCC_AHB1RSTR_GPIOCRST_Msk    (0x1UL << RCC_AHB1RSTR_GPIOCRST_Pos)	/*!< 0x00000004 */
#define RCC_AHB1RSTR_GPIOCRST        RCC_AHB1RSTR_GPIOCRST_Msk
#define RCC_AHB1RSTR_GPIODRST_Pos    (3U)
#define RCC_AHB1RSTR_GPIODRST_Msk    (0x1UL << RCC_AHB1RSTR_GPIODRST_Pos)	/*!< 0x00000008 */
#define RCC_AHB1RSTR_GPIODRST        RCC_AHB1RSTR_GPIODRST_Msk
#define RCC_AHB1RSTR_GPIOERST_Pos    (4U)
#define RCC_AHB1RSTR_GPIOERST_Msk    (0x1UL << RCC_AHB1RSTR_GPIOERST_Pos)	/*!< 0x00000010 */
#define RCC_AHB1RSTR_GPIOERST        RCC_AHB1RSTR_GPIOERST_Msk
#define RCC_AHB1RSTR_GPIOFRST_Pos    (5U)
#define RCC_AHB1RSTR_GPIOFRST_Msk    (0x1UL << RCC_AHB1RSTR_GPIOFRST_Pos)	/*!< 0x00000020 */
#define RCC_AHB1RSTR_GPIOFRST        RCC_AHB1RSTR_GPIOFRST_Msk
#define RCC_AHB1RSTR_GPIOGRST_Pos    (6U)
#define RCC_AHB1RSTR_GPIOGRST_Msk    (0x1UL << RCC_AHB1RSTR_GPIOGRST_Pos)	/*!< 0x00000040 */
#define RCC_AHB1RSTR_GPIOGRST        RCC_AHB1RSTR_GPIOGRST_Msk
#define RCC_AHB1RSTR_GPIOHRST_Pos    (7U)
#define RCC_AHB1RSTR_GPIOHRST_Msk    (0x1UL << RCC_AHB1RSTR_GPIOHRST_Pos)	/*!< 0x00000080 */
#define RCC_AHB1RSTR_GPIOHRST        RCC_AHB1RSTR_GPIOHRST_Msk
#define RCC_AHB1RSTR_GPIOIRST_Pos    (8U)
#define RCC_AHB1RSTR_GPIOIRST_Msk    (0x1UL << RCC_AHB1RSTR_GPIOIRST_Pos)	/*!< 0x00000100 */
#define RCC_AHB1RSTR_GPIOIRST        RCC_AHB1RSTR_GPIOIRST_Msk
#define RCC_AHB1RSTR_CRCRST_Pos      (12U)
#define RCC_AHB1RSTR_CRCRST_Msk      (0x1UL << RCC_AHB1RSTR_CRCRST_Pos)	/*!< 0x00001000 */
#define RCC_AHB1RSTR_CRCRST          RCC_AHB1RSTR_CRCRST_Msk
#define RCC_AHB1RSTR_DMA1RST_Pos     (21U)
#define RCC_AHB1RSTR_DMA1RST_Msk     (0x1UL << RCC_AHB1RSTR_DMA1RST_Pos)/*!< 0x00200000 */
#define RCC_AHB1RSTR_DMA1RST         RCC_AHB1RSTR_DMA1RST_Msk
#define RCC_AHB1RSTR_DMA2RST_Pos     (22U)
#define RCC_AHB1RSTR_DMA2RST_Msk     (0x1UL << RCC_AHB1RSTR_DMA2RST_Pos)/*!< 0x00400000 */
#define RCC_AHB1RSTR_DMA2RST         RCC_AHB1RSTR_DMA2RST_Msk
#define RCC_AHB1RSTR_OTGHRST_Pos     (29U)
#define RCC_AHB1RSTR_OTGHRST_Msk     (0x1UL << RCC_AHB1RSTR_OTGHRST_Pos)/*!< 0x20000000 */
#define RCC_AHB1RSTR_OTGHRST         RCC_AHB1RSTR_OTGHRST_Msk

/********************  Bit definition for RCC_AHB2RSTR register  **************/
#define RCC_AHB2RSTR_RNGRST_Pos      (6U)
#define RCC_AHB2RSTR_RNGRST_Msk      (0x1UL << RCC_AHB2RSTR_RNGRST_Pos)	/*!< 0x00000040 */
#define RCC_AHB2RSTR_RNGRST          RCC_AHB2RSTR_RNGRST_Msk
#define RCC_AHB2RSTR_OTGFSRST_Pos    (7U)
#define RCC_AHB2RSTR_OTGFSRST_Msk    (0x1UL << RCC_AHB2RSTR_OTGFSRST_Pos)	/*!< 0x00000080 */
#define RCC_AHB2RSTR_OTGFSRST        RCC_AHB2RSTR_OTGFSRST_Msk

/********************  Bit definition for RCC_AHB3RSTR register  **************/

#define RCC_AHB3RSTR_FMCRST_Pos     (0U)
#define RCC_AHB3RSTR_FMCRST_Msk     (0x1UL << RCC_AHB3RSTR_FMCRST_Pos)	/*!< 0x00000001 */
#define RCC_AHB3RSTR_FMCRST         RCC_AHB3RSTR_FMCRST_Msk
#define RCC_AHB3RSTR_QSPIRST_Pos    (1U)
#define RCC_AHB3RSTR_QSPIRST_Msk    (0x1UL << RCC_AHB3RSTR_QSPIRST_Pos)	/*!< 0x00000002 */
#define RCC_AHB3RSTR_QSPIRST        RCC_AHB3RSTR_QSPIRST_Msk

/********************  Bit definition for RCC_APB1RSTR register  **************/
#define RCC_APB1RSTR_TIM2RST_Pos      (0U)
#define RCC_APB1RSTR_TIM2RST_Msk      (0x1UL << RCC_APB1RSTR_TIM2RST_Pos)	/*!< 0x00000001 */
#define RCC_APB1RSTR_TIM2RST          RCC_APB1RSTR_TIM2RST_Msk
#define RCC_APB1RSTR_TIM3RST_Pos      (1U)
#define RCC_APB1RSTR_TIM3RST_Msk      (0x1UL << RCC_APB1RSTR_TIM3RST_Pos)	/*!< 0x00000002 */
#define RCC_APB1RSTR_TIM3RST          RCC_APB1RSTR_TIM3RST_Msk
#define RCC_APB1RSTR_TIM4RST_Pos      (2U)
#define RCC_APB1RSTR_TIM4RST_Msk      (0x1UL << RCC_APB1RSTR_TIM4RST_Pos)	/*!< 0x00000004 */
#define RCC_APB1RSTR_TIM4RST          RCC_APB1RSTR_TIM4RST_Msk
#define RCC_APB1RSTR_TIM5RST_Pos      (3U)
#define RCC_APB1RSTR_TIM5RST_Msk      (0x1UL << RCC_APB1RSTR_TIM5RST_Pos)	/*!< 0x00000008 */
#define RCC_APB1RSTR_TIM5RST          RCC_APB1RSTR_TIM5RST_Msk
#define RCC_APB1RSTR_TIM6RST_Pos      (4U)
#define RCC_APB1RSTR_TIM6RST_Msk      (0x1UL << RCC_APB1RSTR_TIM6RST_Pos)	/*!< 0x00000010 */
#define RCC_APB1RSTR_TIM6RST          RCC_APB1RSTR_TIM6RST_Msk
#define RCC_APB1RSTR_TIM7RST_Pos      (5U)
#define RCC_APB1RSTR_TIM7RST_Msk      (0x1UL << RCC_APB1RSTR_TIM7RST_Pos)	/*!< 0x00000020 */
#define RCC_APB1RSTR_TIM7RST          RCC_APB1RSTR_TIM7RST_Msk
#define RCC_APB1RSTR_TIM12RST_Pos     (6U)
#define RCC_APB1RSTR_TIM12RST_Msk     (0x1UL << RCC_APB1RSTR_TIM12RST_Pos)	/*!< 0x00000040 */
#define RCC_APB1RSTR_TIM12RST         RCC_APB1RSTR_TIM12RST_Msk
#define RCC_APB1RSTR_TIM13RST_Pos     (7U)
#define RCC_APB1RSTR_TIM13RST_Msk     (0x1UL << RCC_APB1RSTR_TIM13RST_Pos)	/*!< 0x00000080 */
#define RCC_APB1RSTR_TIM13RST         RCC_APB1RSTR_TIM13RST_Msk
#define RCC_APB1RSTR_TIM14RST_Pos     (8U)
#define RCC_APB1RSTR_TIM14RST_Msk     (0x1UL << RCC_APB1RSTR_TIM14RST_Pos)	/*!< 0x00000100 */
#define RCC_APB1RSTR_TIM14RST         RCC_APB1RSTR_TIM14RST_Msk
#define RCC_APB1RSTR_LPTIM1RST_Pos    (9U)
#define RCC_APB1RSTR_LPTIM1RST_Msk    (0x1UL << RCC_APB1RSTR_LPTIM1RST_Pos)	/*!< 0x00000200 */
#define RCC_APB1RSTR_LPTIM1RST        RCC_APB1RSTR_LPTIM1RST_Msk
#define RCC_APB1RSTR_WWDGRST_Pos      (11U)
#define RCC_APB1RSTR_WWDGRST_Msk      (0x1UL << RCC_APB1RSTR_WWDGRST_Pos)	/*!< 0x00000800 */
#define RCC_APB1RSTR_WWDGRST          RCC_APB1RSTR_WWDGRST_Msk
#define RCC_APB1RSTR_SPI2RST_Pos      (14U)
#define RCC_APB1RSTR_SPI2RST_Msk      (0x1UL << RCC_APB1RSTR_SPI2RST_Pos)	/*!< 0x00004000 */
#define RCC_APB1RSTR_SPI2RST          RCC_APB1RSTR_SPI2RST_Msk
#define RCC_APB1RSTR_SPI3RST_Pos      (15U)
#define RCC_APB1RSTR_SPI3RST_Msk      (0x1UL << RCC_APB1RSTR_SPI3RST_Pos)	/*!< 0x00008000 */
#define RCC_APB1RSTR_SPI3RST          RCC_APB1RSTR_SPI3RST_Msk
#define RCC_APB1RSTR_USART2RST_Pos    (17U)
#define RCC_APB1RSTR_USART2RST_Msk    (0x1UL << RCC_APB1RSTR_USART2RST_Pos)	/*!< 0x00020000 */
#define RCC_APB1RSTR_USART2RST        RCC_APB1RSTR_USART2RST_Msk
#define RCC_APB1RSTR_USART3RST_Pos    (18U)
#define RCC_APB1RSTR_USART3RST_Msk    (0x1UL << RCC_APB1RSTR_USART3RST_Pos)	/*!< 0x00040000 */
#define RCC_APB1RSTR_USART3RST        RCC_APB1RSTR_USART3RST_Msk
#define RCC_APB1RSTR_UART4RST_Pos     (19U)
#define RCC_APB1RSTR_UART4RST_Msk     (0x1UL << RCC_APB1RSTR_UART4RST_Pos)	/*!< 0x00080000 */
#define RCC_APB1RSTR_UART4RST         RCC_APB1RSTR_UART4RST_Msk
#define RCC_APB1RSTR_UART5RST_Pos     (20U)
#define RCC_APB1RSTR_UART5RST_Msk     (0x1UL << RCC_APB1RSTR_UART5RST_Pos)	/*!< 0x00100000 */
#define RCC_APB1RSTR_UART5RST         RCC_APB1RSTR_UART5RST_Msk
#define RCC_APB1RSTR_I2C1RST_Pos      (21U)
#define RCC_APB1RSTR_I2C1RST_Msk      (0x1UL << RCC_APB1RSTR_I2C1RST_Pos)	/*!< 0x00200000 */
#define RCC_APB1RSTR_I2C1RST          RCC_APB1RSTR_I2C1RST_Msk
#define RCC_APB1RSTR_I2C2RST_Pos      (22U)
#define RCC_APB1RSTR_I2C2RST_Msk      (0x1UL << RCC_APB1RSTR_I2C2RST_Pos)	/*!< 0x00400000 */
#define RCC_APB1RSTR_I2C2RST          RCC_APB1RSTR_I2C2RST_Msk
#define RCC_APB1RSTR_I2C3RST_Pos      (23U)
#define RCC_APB1RSTR_I2C3RST_Msk      (0x1UL << RCC_APB1RSTR_I2C3RST_Pos)	/*!< 0x00800000 */
#define RCC_APB1RSTR_I2C3RST          RCC_APB1RSTR_I2C3RST_Msk
#define RCC_APB1RSTR_CAN1RST_Pos      (25U)
#define RCC_APB1RSTR_CAN1RST_Msk      (0x1UL << RCC_APB1RSTR_CAN1RST_Pos)	/*!< 0x02000000 */
#define RCC_APB1RSTR_CAN1RST          RCC_APB1RSTR_CAN1RST_Msk
#define RCC_APB1RSTR_PWRRST_Pos       (28U)
#define RCC_APB1RSTR_PWRRST_Msk       (0x1UL << RCC_APB1RSTR_PWRRST_Pos)/*!< 0x10000000 */
#define RCC_APB1RSTR_PWRRST           RCC_APB1RSTR_PWRRST_Msk
#define RCC_APB1RSTR_DACRST_Pos       (29U)
#define RCC_APB1RSTR_DACRST_Msk       (0x1UL << RCC_APB1RSTR_DACRST_Pos)/*!< 0x20000000 */
#define RCC_APB1RSTR_DACRST           RCC_APB1RSTR_DACRST_Msk
#define RCC_APB1RSTR_UART7RST_Pos     (30U)
#define RCC_APB1RSTR_UART7RST_Msk     (0x1UL << RCC_APB1RSTR_UART7RST_Pos)	/*!< 0x40000000 */
#define RCC_APB1RSTR_UART7RST         RCC_APB1RSTR_UART7RST_Msk
#define RCC_APB1RSTR_UART8RST_Pos     (31U)
#define RCC_APB1RSTR_UART8RST_Msk     (0x1UL << RCC_APB1RSTR_UART8RST_Pos)	/*!< 0x80000000 */
#define RCC_APB1RSTR_UART8RST         RCC_APB1RSTR_UART8RST_Msk

/********************  Bit definition for RCC_APB2RSTR register  **************/
#define RCC_APB2RSTR_TIM1RST_Pos      (0U)
#define RCC_APB2RSTR_TIM1RST_Msk      (0x1UL << RCC_APB2RSTR_TIM1RST_Pos)	/*!< 0x00000001 */
#define RCC_APB2RSTR_TIM1RST          RCC_APB2RSTR_TIM1RST_Msk
#define RCC_APB2RSTR_TIM8RST_Pos      (1U)
#define RCC_APB2RSTR_TIM8RST_Msk      (0x1UL << RCC_APB2RSTR_TIM8RST_Pos)	/*!< 0x00000002 */
#define RCC_APB2RSTR_TIM8RST          RCC_APB2RSTR_TIM8RST_Msk
#define RCC_APB2RSTR_USART1RST_Pos    (4U)
#define RCC_APB2RSTR_USART1RST_Msk    (0x1UL << RCC_APB2RSTR_USART1RST_Pos)	/*!< 0x00000010 */
#define RCC_APB2RSTR_USART1RST        RCC_APB2RSTR_USART1RST_Msk
#define RCC_APB2RSTR_USART6RST_Pos    (5U)
#define RCC_APB2RSTR_USART6RST_Msk    (0x1UL << RCC_APB2RSTR_USART6RST_Pos)	/*!< 0x00000020 */
#define RCC_APB2RSTR_USART6RST        RCC_APB2RSTR_USART6RST_Msk
#define RCC_APB2RSTR_SDMMC2RST_Pos    (7U)
#define RCC_APB2RSTR_SDMMC2RST_Msk    (0x1UL << RCC_APB2RSTR_SDMMC2RST_Pos)	/*!< 0x00000080 */
#define RCC_APB2RSTR_SDMMC2RST        RCC_APB2RSTR_SDMMC2RST_Msk
#define RCC_APB2RSTR_ADCRST_Pos       (8U)
#define RCC_APB2RSTR_ADCRST_Msk       (0x1UL << RCC_APB2RSTR_ADCRST_Pos)/*!< 0x00000100 */
#define RCC_APB2RSTR_ADCRST           RCC_APB2RSTR_ADCRST_Msk
#define RCC_APB2RSTR_SDMMC1RST_Pos    (11U)
#define RCC_APB2RSTR_SDMMC1RST_Msk    (0x1UL << RCC_APB2RSTR_SDMMC1RST_Pos)	/*!< 0x00000800 */
#define RCC_APB2RSTR_SDMMC1RST        RCC_APB2RSTR_SDMMC1RST_Msk
#define RCC_APB2RSTR_SPI1RST_Pos      (12U)
#define RCC_APB2RSTR_SPI1RST_Msk      (0x1UL << RCC_APB2RSTR_SPI1RST_Pos)	/*!< 0x00001000 */
#define RCC_APB2RSTR_SPI1RST          RCC_APB2RSTR_SPI1RST_Msk
#define RCC_APB2RSTR_SPI4RST_Pos      (13U)
#define RCC_APB2RSTR_SPI4RST_Msk      (0x1UL << RCC_APB2RSTR_SPI4RST_Pos)	/*!< 0x00002000 */
#define RCC_APB2RSTR_SPI4RST          RCC_APB2RSTR_SPI4RST_Msk
#define RCC_APB2RSTR_SYSCFGRST_Pos    (14U)
#define RCC_APB2RSTR_SYSCFGRST_Msk    (0x1UL << RCC_APB2RSTR_SYSCFGRST_Pos)	/*!< 0x00004000 */
#define RCC_APB2RSTR_SYSCFGRST        RCC_APB2RSTR_SYSCFGRST_Msk
#define RCC_APB2RSTR_TIM9RST_Pos      (16U)
#define RCC_APB2RSTR_TIM9RST_Msk      (0x1UL << RCC_APB2RSTR_TIM9RST_Pos)	/*!< 0x00010000 */
#define RCC_APB2RSTR_TIM9RST          RCC_APB2RSTR_TIM9RST_Msk
#define RCC_APB2RSTR_TIM10RST_Pos     (17U)
#define RCC_APB2RSTR_TIM10RST_Msk     (0x1UL << RCC_APB2RSTR_TIM10RST_Pos)	/*!< 0x00020000 */
#define RCC_APB2RSTR_TIM10RST         RCC_APB2RSTR_TIM10RST_Msk
#define RCC_APB2RSTR_TIM11RST_Pos     (18U)
#define RCC_APB2RSTR_TIM11RST_Msk     (0x1UL << RCC_APB2RSTR_TIM11RST_Pos)	/*!< 0x00040000 */
#define RCC_APB2RSTR_TIM11RST         RCC_APB2RSTR_TIM11RST_Msk
#define RCC_APB2RSTR_SPI5RST_Pos      (20U)
#define RCC_APB2RSTR_SPI5RST_Msk      (0x1UL << RCC_APB2RSTR_SPI5RST_Pos)	/*!< 0x00100000 */
#define RCC_APB2RSTR_SPI5RST          RCC_APB2RSTR_SPI5RST_Msk
#define RCC_APB2RSTR_SAI1RST_Pos      (22U)
#define RCC_APB2RSTR_SAI1RST_Msk      (0x1UL << RCC_APB2RSTR_SAI1RST_Pos)	/*!< 0x00400000 */
#define RCC_APB2RSTR_SAI1RST          RCC_APB2RSTR_SAI1RST_Msk
#define RCC_APB2RSTR_SAI2RST_Pos      (23U)
#define RCC_APB2RSTR_SAI2RST_Msk      (0x1UL << RCC_APB2RSTR_SAI2RST_Pos)	/*!< 0x00800000 */
#define RCC_APB2RSTR_SAI2RST          RCC_APB2RSTR_SAI2RST_Msk

/********************  Bit definition for RCC_AHB1ENR register  ***************/
#define RCC_AHB1ENR_GPIOAEN_Pos        (0U)
#define RCC_AHB1ENR_GPIOAEN_Msk        (0x1UL << RCC_AHB1ENR_GPIOAEN_Pos)	/*!< 0x00000001 */
#define RCC_AHB1ENR_GPIOAEN            RCC_AHB1ENR_GPIOAEN_Msk
#define RCC_AHB1ENR_GPIOBEN_Pos        (1U)
#define RCC_AHB1ENR_GPIOBEN_Msk        (0x1UL << RCC_AHB1ENR_GPIOBEN_Pos)	/*!< 0x00000002 */
#define RCC_AHB1ENR_GPIOBEN            RCC_AHB1ENR_GPIOBEN_Msk
#define RCC_AHB1ENR_GPIOCEN_Pos        (2U)
#define RCC_AHB1ENR_GPIOCEN_Msk        (0x1UL << RCC_AHB1ENR_GPIOCEN_Pos)	/*!< 0x00000004 */
#define RCC_AHB1ENR_GPIOCEN            RCC_AHB1ENR_GPIOCEN_Msk
#define RCC_AHB1ENR_GPIODEN_Pos        (3U)
#define RCC_AHB1ENR_GPIODEN_Msk        (0x1UL << RCC_AHB1ENR_GPIODEN_Pos)	/*!< 0x00000008 */
#define RCC_AHB1ENR_GPIODEN            RCC_AHB1ENR_GPIODEN_Msk
#define RCC_AHB1ENR_GPIOEEN_Pos        (4U)
#define RCC_AHB1ENR_GPIOEEN_Msk        (0x1UL << RCC_AHB1ENR_GPIOEEN_Pos)	/*!< 0x00000010 */
#define RCC_AHB1ENR_GPIOEEN            RCC_AHB1ENR_GPIOEEN_Msk
#define RCC_AHB1ENR_GPIOFEN_Pos        (5U)
#define RCC_AHB1ENR_GPIOFEN_Msk        (0x1UL << RCC_AHB1ENR_GPIOFEN_Pos)	/*!< 0x00000020 */
#define RCC_AHB1ENR_GPIOFEN            RCC_AHB1ENR_GPIOFEN_Msk
#define RCC_AHB1ENR_GPIOGEN_Pos        (6U)
#define RCC_AHB1ENR_GPIOGEN_Msk        (0x1UL << RCC_AHB1ENR_GPIOGEN_Pos)	/*!< 0x00000040 */
#define RCC_AHB1ENR_GPIOGEN            RCC_AHB1ENR_GPIOGEN_Msk
#define RCC_AHB1ENR_GPIOHEN_Pos        (7U)
#define RCC_AHB1ENR_GPIOHEN_Msk        (0x1UL << RCC_AHB1ENR_GPIOHEN_Pos)	/*!< 0x00000080 */
#define RCC_AHB1ENR_GPIOHEN            RCC_AHB1ENR_GPIOHEN_Msk
#define RCC_AHB1ENR_GPIOIEN_Pos        (8U)
#define RCC_AHB1ENR_GPIOIEN_Msk        (0x1UL << RCC_AHB1ENR_GPIOIEN_Pos)	/*!< 0x00000100 */
#define RCC_AHB1ENR_GPIOIEN            RCC_AHB1ENR_GPIOIEN_Msk
#define RCC_AHB1ENR_CRCEN_Pos          (12U)
#define RCC_AHB1ENR_CRCEN_Msk          (0x1UL << RCC_AHB1ENR_CRCEN_Pos)	/*!< 0x00001000 */
#define RCC_AHB1ENR_CRCEN              RCC_AHB1ENR_CRCEN_Msk
#define RCC_AHB1ENR_BKPSRAMEN_Pos      (18U)
#define RCC_AHB1ENR_BKPSRAMEN_Msk      (0x1UL << RCC_AHB1ENR_BKPSRAMEN_Pos)	/*!< 0x00040000 */
#define RCC_AHB1ENR_BKPSRAMEN          RCC_AHB1ENR_BKPSRAMEN_Msk
#define RCC_AHB1ENR_DTCMRAMEN_Pos      (20U)
#define RCC_AHB1ENR_DTCMRAMEN_Msk      (0x1UL << RCC_AHB1ENR_DTCMRAMEN_Pos)	/*!< 0x00100000 */
#define RCC_AHB1ENR_DTCMRAMEN          RCC_AHB1ENR_DTCMRAMEN_Msk
#define RCC_AHB1ENR_DMA1EN_Pos         (21U)
#define RCC_AHB1ENR_DMA1EN_Msk         (0x1UL << RCC_AHB1ENR_DMA1EN_Pos)/*!< 0x00200000 */
#define RCC_AHB1ENR_DMA1EN             RCC_AHB1ENR_DMA1EN_Msk
#define RCC_AHB1ENR_DMA2EN_Pos         (22U)
#define RCC_AHB1ENR_DMA2EN_Msk         (0x1UL << RCC_AHB1ENR_DMA2EN_Pos)/*!< 0x00400000 */
#define RCC_AHB1ENR_DMA2EN             RCC_AHB1ENR_DMA2EN_Msk
#define RCC_AHB1ENR_OTGHSEN_Pos        (29U)
#define RCC_AHB1ENR_OTGHSEN_Msk        (0x1UL << RCC_AHB1ENR_OTGHSEN_Pos)	/*!< 0x20000000 */
#define RCC_AHB1ENR_OTGHSEN            RCC_AHB1ENR_OTGHSEN_Msk
#define RCC_AHB1ENR_OTGHSULPIEN_Pos    (30U)
#define RCC_AHB1ENR_OTGHSULPIEN_Msk    (0x1UL << RCC_AHB1ENR_OTGHSULPIEN_Pos)	/*!< 0x40000000 */
#define RCC_AHB1ENR_OTGHSULPIEN        RCC_AHB1ENR_OTGHSULPIEN_Msk

/********************  Bit definition for RCC_AHB2ENR register  ***************/
#define RCC_AHB2ENR_RNGEN_Pos      (6U)
#define RCC_AHB2ENR_RNGEN_Msk      (0x1UL << RCC_AHB2ENR_RNGEN_Pos)	/*!< 0x00000040 */
#define RCC_AHB2ENR_RNGEN          RCC_AHB2ENR_RNGEN_Msk
#define RCC_AHB2ENR_OTGFSEN_Pos    (7U)
#define RCC_AHB2ENR_OTGFSEN_Msk    (0x1UL << RCC_AHB2ENR_OTGFSEN_Pos)	/*!< 0x00000080 */
#define RCC_AHB2ENR_OTGFSEN        RCC_AHB2ENR_OTGFSEN_Msk

/********************  Bit definition for RCC_AHB3ENR register  ***************/
#define RCC_AHB3ENR_FMCEN_Pos     (0U)
#define RCC_AHB3ENR_FMCEN_Msk     (0x1UL << RCC_AHB3ENR_FMCEN_Pos)	/*!< 0x00000001 */
#define RCC_AHB3ENR_FMCEN         RCC_AHB3ENR_FMCEN_Msk
#define RCC_AHB3ENR_QSPIEN_Pos    (1U)
#define RCC_AHB3ENR_QSPIEN_Msk    (0x1UL << RCC_AHB3ENR_QSPIEN_Pos)	/*!< 0x00000002 */
#define RCC_AHB3ENR_QSPIEN        RCC_AHB3ENR_QSPIEN_Msk

/********************  Bit definition for RCC_APB1ENR register  ***************/
#define RCC_APB1ENR_TIM2EN_Pos      (0U)
#define RCC_APB1ENR_TIM2EN_Msk      (0x1UL << RCC_APB1ENR_TIM2EN_Pos)	/*!< 0x00000001 */
#define RCC_APB1ENR_TIM2EN          RCC_APB1ENR_TIM2EN_Msk
#define RCC_APB1ENR_TIM3EN_Pos      (1U)
#define RCC_APB1ENR_TIM3EN_Msk      (0x1UL << RCC_APB1ENR_TIM3EN_Pos)	/*!< 0x00000002 */
#define RCC_APB1ENR_TIM3EN          RCC_APB1ENR_TIM3EN_Msk
#define RCC_APB1ENR_TIM4EN_Pos      (2U)
#define RCC_APB1ENR_TIM4EN_Msk      (0x1UL << RCC_APB1ENR_TIM4EN_Pos)	/*!< 0x00000004 */
#define RCC_APB1ENR_TIM4EN          RCC_APB1ENR_TIM4EN_Msk
#define RCC_APB1ENR_TIM5EN_Pos      (3U)
#define RCC_APB1ENR_TIM5EN_Msk      (0x1UL << RCC_APB1ENR_TIM5EN_Pos)	/*!< 0x00000008 */
#define RCC_APB1ENR_TIM5EN          RCC_APB1ENR_TIM5EN_Msk
#define RCC_APB1ENR_TIM6EN_Pos      (4U)
#define RCC_APB1ENR_TIM6EN_Msk      (0x1UL << RCC_APB1ENR_TIM6EN_Pos)	/*!< 0x00000010 */
#define RCC_APB1ENR_TIM6EN          RCC_APB1ENR_TIM6EN_Msk
#define RCC_APB1ENR_TIM7EN_Pos      (5U)
#define RCC_APB1ENR_TIM7EN_Msk      (0x1UL << RCC_APB1ENR_TIM7EN_Pos)	/*!< 0x00000020 */
#define RCC_APB1ENR_TIM7EN          RCC_APB1ENR_TIM7EN_Msk
#define RCC_APB1ENR_TIM12EN_Pos     (6U)
#define RCC_APB1ENR_TIM12EN_Msk     (0x1UL << RCC_APB1ENR_TIM12EN_Pos)	/*!< 0x00000040 */
#define RCC_APB1ENR_TIM12EN         RCC_APB1ENR_TIM12EN_Msk
#define RCC_APB1ENR_TIM13EN_Pos     (7U)
#define RCC_APB1ENR_TIM13EN_Msk     (0x1UL << RCC_APB1ENR_TIM13EN_Pos)	/*!< 0x00000080 */
#define RCC_APB1ENR_TIM13EN         RCC_APB1ENR_TIM13EN_Msk
#define RCC_APB1ENR_TIM14EN_Pos     (8U)
#define RCC_APB1ENR_TIM14EN_Msk     (0x1UL << RCC_APB1ENR_TIM14EN_Pos)	/*!< 0x00000100 */
#define RCC_APB1ENR_TIM14EN         RCC_APB1ENR_TIM14EN_Msk
#define RCC_APB1ENR_LPTIM1EN_Pos    (9U)
#define RCC_APB1ENR_LPTIM1EN_Msk    (0x1UL << RCC_APB1ENR_LPTIM1EN_Pos)	/*!< 0x00000200 */
#define RCC_APB1ENR_LPTIM1EN        RCC_APB1ENR_LPTIM1EN_Msk
#define RCC_APB1ENR_RTCEN_Pos       (10U)
#define RCC_APB1ENR_RTCEN_Msk       (0x1UL << RCC_APB1ENR_RTCEN_Pos)/*!< 0x00000400 */
#define RCC_APB1ENR_RTCEN           RCC_APB1ENR_RTCEN_Msk
#define RCC_APB1ENR_WWDGEN_Pos      (11U)
#define RCC_APB1ENR_WWDGEN_Msk      (0x1UL << RCC_APB1ENR_WWDGEN_Pos)	/*!< 0x00000800 */
#define RCC_APB1ENR_WWDGEN          RCC_APB1ENR_WWDGEN_Msk
#define RCC_APB1ENR_SPI2EN_Pos      (14U)
#define RCC_APB1ENR_SPI2EN_Msk      (0x1UL << RCC_APB1ENR_SPI2EN_Pos)	/*!< 0x00004000 */
#define RCC_APB1ENR_SPI2EN          RCC_APB1ENR_SPI2EN_Msk
#define RCC_APB1ENR_SPI3EN_Pos      (15U)
#define RCC_APB1ENR_SPI3EN_Msk      (0x1UL << RCC_APB1ENR_SPI3EN_Pos)	/*!< 0x00008000 */
#define RCC_APB1ENR_SPI3EN          RCC_APB1ENR_SPI3EN_Msk
#define RCC_APB1ENR_USART2EN_Pos    (17U)
#define RCC_APB1ENR_USART2EN_Msk    (0x1UL << RCC_APB1ENR_USART2EN_Pos)	/*!< 0x00020000 */
#define RCC_APB1ENR_USART2EN        RCC_APB1ENR_USART2EN_Msk
#define RCC_APB1ENR_USART3EN_Pos    (18U)
#define RCC_APB1ENR_USART3EN_Msk    (0x1UL << RCC_APB1ENR_USART3EN_Pos)	/*!< 0x00040000 */
#define RCC_APB1ENR_USART3EN        RCC_APB1ENR_USART3EN_Msk
#define RCC_APB1ENR_UART4EN_Pos     (19U)
#define RCC_APB1ENR_UART4EN_Msk     (0x1UL << RCC_APB1ENR_UART4EN_Pos)	/*!< 0x00080000 */
#define RCC_APB1ENR_UART4EN         RCC_APB1ENR_UART4EN_Msk
#define RCC_APB1ENR_UART5EN_Pos     (20U)
#define RCC_APB1ENR_UART5EN_Msk     (0x1UL << RCC_APB1ENR_UART5EN_Pos)	/*!< 0x00100000 */
#define RCC_APB1ENR_UART5EN         RCC_APB1ENR_UART5EN_Msk
#define RCC_APB1ENR_I2C1EN_Pos      (21U)
#define RCC_APB1ENR_I2C1EN_Msk      (0x1UL << RCC_APB1ENR_I2C1EN_Pos)	/*!< 0x00200000 */
#define RCC_APB1ENR_I2C1EN          RCC_APB1ENR_I2C1EN_Msk
#define RCC_APB1ENR_I2C2EN_Pos      (22U)
#define RCC_APB1ENR_I2C2EN_Msk      (0x1UL << RCC_APB1ENR_I2C2EN_Pos)	/*!< 0x00400000 */
#define RCC_APB1ENR_I2C2EN          RCC_APB1ENR_I2C2EN_Msk
#define RCC_APB1ENR_I2C3EN_Pos      (23U)
#define RCC_APB1ENR_I2C3EN_Msk      (0x1UL << RCC_APB1ENR_I2C3EN_Pos)	/*!< 0x00800000 */
#define RCC_APB1ENR_I2C3EN          RCC_APB1ENR_I2C3EN_Msk
#define RCC_APB1ENR_CAN1EN_Pos      (25U)
#define RCC_APB1ENR_CAN1EN_Msk      (0x1UL << RCC_APB1ENR_CAN1EN_Pos)	/*!< 0x02000000 */
#define RCC_APB1ENR_CAN1EN          RCC_APB1ENR_CAN1EN_Msk
#define RCC_APB1ENR_PWREN_Pos       (28U)
#define RCC_APB1ENR_PWREN_Msk       (0x1UL << RCC_APB1ENR_PWREN_Pos)/*!< 0x10000000 */
#define RCC_APB1ENR_PWREN           RCC_APB1ENR_PWREN_Msk
#define RCC_APB1ENR_DACEN_Pos       (29U)
#define RCC_APB1ENR_DACEN_Msk       (0x1UL << RCC_APB1ENR_DACEN_Pos)/*!< 0x20000000 */
#define RCC_APB1ENR_DACEN           RCC_APB1ENR_DACEN_Msk
#define RCC_APB1ENR_UART7EN_Pos     (30U)
#define RCC_APB1ENR_UART7EN_Msk     (0x1UL << RCC_APB1ENR_UART7EN_Pos)	/*!< 0x40000000 */
#define RCC_APB1ENR_UART7EN         RCC_APB1ENR_UART7EN_Msk
#define RCC_APB1ENR_UART8EN_Pos     (31U)
#define RCC_APB1ENR_UART8EN_Msk     (0x1UL << RCC_APB1ENR_UART8EN_Pos)	/*!< 0x80000000 */
#define RCC_APB1ENR_UART8EN         RCC_APB1ENR_UART8EN_Msk

/********************  Bit definition for RCC_APB2ENR register  ***************/
#define RCC_APB2ENR_TIM1EN_Pos      (0U)
#define RCC_APB2ENR_TIM1EN_Msk      (0x1UL << RCC_APB2ENR_TIM1EN_Pos)	/*!< 0x00000001 */
#define RCC_APB2ENR_TIM1EN          RCC_APB2ENR_TIM1EN_Msk
#define RCC_APB2ENR_TIM8EN_Pos      (1U)
#define RCC_APB2ENR_TIM8EN_Msk      (0x1UL << RCC_APB2ENR_TIM8EN_Pos)	/*!< 0x00000002 */
#define RCC_APB2ENR_TIM8EN          RCC_APB2ENR_TIM8EN_Msk
#define RCC_APB2ENR_USART1EN_Pos    (4U)
#define RCC_APB2ENR_USART1EN_Msk    (0x1UL << RCC_APB2ENR_USART1EN_Pos)	/*!< 0x00000010 */
#define RCC_APB2ENR_USART1EN        RCC_APB2ENR_USART1EN_Msk
#define RCC_APB2ENR_USART6EN_Pos    (5U)
#define RCC_APB2ENR_USART6EN_Msk    (0x1UL << RCC_APB2ENR_USART6EN_Pos)	/*!< 0x00000020 */
#define RCC_APB2ENR_USART6EN        RCC_APB2ENR_USART6EN_Msk
#define RCC_APB2ENR_SDMMC2EN_Pos    (7U)
#define RCC_APB2ENR_SDMMC2EN_Msk    (0x1UL << RCC_APB2ENR_SDMMC2EN_Pos)	/*!< 0x00000080 */
#define RCC_APB2ENR_SDMMC2EN        RCC_APB2ENR_SDMMC2EN_Msk
#define RCC_APB2ENR_ADC1EN_Pos      (8U)
#define RCC_APB2ENR_ADC1EN_Msk      (0x1UL << RCC_APB2ENR_ADC1EN_Pos)	/*!< 0x00000100 */
#define RCC_APB2ENR_ADC1EN          RCC_APB2ENR_ADC1EN_Msk
#define RCC_APB2ENR_ADC2EN_Pos      (9U)
#define RCC_APB2ENR_ADC2EN_Msk      (0x1UL << RCC_APB2ENR_ADC2EN_Pos)	/*!< 0x00000200 */
#define RCC_APB2ENR_ADC2EN          RCC_APB2ENR_ADC2EN_Msk
#define RCC_APB2ENR_ADC3EN_Pos      (10U)
#define RCC_APB2ENR_ADC3EN_Msk      (0x1UL << RCC_APB2ENR_ADC3EN_Pos)	/*!< 0x00000400 */
#define RCC_APB2ENR_ADC3EN          RCC_APB2ENR_ADC3EN_Msk
#define RCC_APB2ENR_SDMMC1EN_Pos    (11U)
#define RCC_APB2ENR_SDMMC1EN_Msk    (0x1UL << RCC_APB2ENR_SDMMC1EN_Pos)	/*!< 0x00000800 */
#define RCC_APB2ENR_SDMMC1EN        RCC_APB2ENR_SDMMC1EN_Msk
#define RCC_APB2ENR_SPI1EN_Pos      (12U)
#define RCC_APB2ENR_SPI1EN_Msk      (0x1UL << RCC_APB2ENR_SPI1EN_Pos)	/*!< 0x00001000 */
#define RCC_APB2ENR_SPI1EN          RCC_APB2ENR_SPI1EN_Msk
#define RCC_APB2ENR_SPI4EN_Pos      (13U)
#define RCC_APB2ENR_SPI4EN_Msk      (0x1UL << RCC_APB2ENR_SPI4EN_Pos)	/*!< 0x00002000 */
#define RCC_APB2ENR_SPI4EN          RCC_APB2ENR_SPI4EN_Msk
#define RCC_APB2ENR_SYSCFGEN_Pos    (14U)
#define RCC_APB2ENR_SYSCFGEN_Msk    (0x1UL << RCC_APB2ENR_SYSCFGEN_Pos)	/*!< 0x00004000 */
#define RCC_APB2ENR_SYSCFGEN        RCC_APB2ENR_SYSCFGEN_Msk
#define RCC_APB2ENR_TIM9EN_Pos      (16U)
#define RCC_APB2ENR_TIM9EN_Msk      (0x1UL << RCC_APB2ENR_TIM9EN_Pos)	/*!< 0x00010000 */
#define RCC_APB2ENR_TIM9EN          RCC_APB2ENR_TIM9EN_Msk
#define RCC_APB2ENR_TIM10EN_Pos     (17U)
#define RCC_APB2ENR_TIM10EN_Msk     (0x1UL << RCC_APB2ENR_TIM10EN_Pos)	/*!< 0x00020000 */
#define RCC_APB2ENR_TIM10EN         RCC_APB2ENR_TIM10EN_Msk
#define RCC_APB2ENR_TIM11EN_Pos     (18U)
#define RCC_APB2ENR_TIM11EN_Msk     (0x1UL << RCC_APB2ENR_TIM11EN_Pos)	/*!< 0x00040000 */
#define RCC_APB2ENR_TIM11EN         RCC_APB2ENR_TIM11EN_Msk
#define RCC_APB2ENR_SPI5EN_Pos      (20U)
#define RCC_APB2ENR_SPI5EN_Msk      (0x1UL << RCC_APB2ENR_SPI5EN_Pos)	/*!< 0x00100000 */
#define RCC_APB2ENR_SPI5EN          RCC_APB2ENR_SPI5EN_Msk
#define RCC_APB2ENR_SAI1EN_Pos      (22U)
#define RCC_APB2ENR_SAI1EN_Msk      (0x1UL << RCC_APB2ENR_SAI1EN_Pos)	/*!< 0x00400000 */
#define RCC_APB2ENR_SAI1EN          RCC_APB2ENR_SAI1EN_Msk
#define RCC_APB2ENR_SAI2EN_Pos      (23U)
#define RCC_APB2ENR_SAI2EN_Msk      (0x1UL << RCC_APB2ENR_SAI2EN_Pos)	/*!< 0x00800000 */
#define RCC_APB2ENR_SAI2EN          RCC_APB2ENR_SAI2EN_Msk

/********************  Bit definition for RCC_AHB1LPENR register  *************/
#define RCC_AHB1LPENR_GPIOALPEN_Pos        (0U)
#define RCC_AHB1LPENR_GPIOALPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOALPEN_Pos)	/*!< 0x00000001 */
#define RCC_AHB1LPENR_GPIOALPEN            RCC_AHB1LPENR_GPIOALPEN_Msk
#define RCC_AHB1LPENR_GPIOBLPEN_Pos        (1U)
#define RCC_AHB1LPENR_GPIOBLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOBLPEN_Pos)	/*!< 0x00000002 */
#define RCC_AHB1LPENR_GPIOBLPEN            RCC_AHB1LPENR_GPIOBLPEN_Msk
#define RCC_AHB1LPENR_GPIOCLPEN_Pos        (2U)
#define RCC_AHB1LPENR_GPIOCLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOCLPEN_Pos)	/*!< 0x00000004 */
#define RCC_AHB1LPENR_GPIOCLPEN            RCC_AHB1LPENR_GPIOCLPEN_Msk
#define RCC_AHB1LPENR_GPIODLPEN_Pos        (3U)
#define RCC_AHB1LPENR_GPIODLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIODLPEN_Pos)	/*!< 0x00000008 */
#define RCC_AHB1LPENR_GPIODLPEN            RCC_AHB1LPENR_GPIODLPEN_Msk
#define RCC_AHB1LPENR_GPIOELPEN_Pos        (4U)
#define RCC_AHB1LPENR_GPIOELPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOELPEN_Pos)	/*!< 0x00000010 */
#define RCC_AHB1LPENR_GPIOELPEN            RCC_AHB1LPENR_GPIOELPEN_Msk
#define RCC_AHB1LPENR_GPIOFLPEN_Pos        (5U)
#define RCC_AHB1LPENR_GPIOFLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOFLPEN_Pos)	/*!< 0x00000020 */
#define RCC_AHB1LPENR_GPIOFLPEN            RCC_AHB1LPENR_GPIOFLPEN_Msk
#define RCC_AHB1LPENR_GPIOGLPEN_Pos        (6U)
#define RCC_AHB1LPENR_GPIOGLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOGLPEN_Pos)	/*!< 0x00000040 */
#define RCC_AHB1LPENR_GPIOGLPEN            RCC_AHB1LPENR_GPIOGLPEN_Msk
#define RCC_AHB1LPENR_GPIOHLPEN_Pos        (7U)
#define RCC_AHB1LPENR_GPIOHLPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOHLPEN_Pos)	/*!< 0x00000080 */
#define RCC_AHB1LPENR_GPIOHLPEN            RCC_AHB1LPENR_GPIOHLPEN_Msk
#define RCC_AHB1LPENR_GPIOILPEN_Pos        (8U)
#define RCC_AHB1LPENR_GPIOILPEN_Msk        (0x1UL << RCC_AHB1LPENR_GPIOILPEN_Pos)	/*!< 0x00000100 */
#define RCC_AHB1LPENR_GPIOILPEN            RCC_AHB1LPENR_GPIOILPEN_Msk
#define RCC_AHB1LPENR_CRCLPEN_Pos          (12U)
#define RCC_AHB1LPENR_CRCLPEN_Msk          (0x1UL << RCC_AHB1LPENR_CRCLPEN_Pos)	/*!< 0x00001000 */
#define RCC_AHB1LPENR_CRCLPEN              RCC_AHB1LPENR_CRCLPEN_Msk
#define RCC_AHB1LPENR_AXILPEN_Pos          (13U)
#define RCC_AHB1LPENR_AXILPEN_Msk          (0x1UL << RCC_AHB1LPENR_AXILPEN_Pos)	/*!< 0x00002000 */
#define RCC_AHB1LPENR_AXILPEN              RCC_AHB1LPENR_AXILPEN_Msk
#define RCC_AHB1LPENR_FLITFLPEN_Pos        (15U)
#define RCC_AHB1LPENR_FLITFLPEN_Msk        (0x1UL << RCC_AHB1LPENR_FLITFLPEN_Pos)	/*!< 0x00008000 */
#define RCC_AHB1LPENR_FLITFLPEN            RCC_AHB1LPENR_FLITFLPEN_Msk
#define RCC_AHB1LPENR_SRAM1LPEN_Pos        (16U)
#define RCC_AHB1LPENR_SRAM1LPEN_Msk        (0x1UL << RCC_AHB1LPENR_SRAM1LPEN_Pos)	/*!< 0x00010000 */
#define RCC_AHB1LPENR_SRAM1LPEN            RCC_AHB1LPENR_SRAM1LPEN_Msk
#define RCC_AHB1LPENR_SRAM2LPEN_Pos        (17U)
#define RCC_AHB1LPENR_SRAM2LPEN_Msk        (0x1UL << RCC_AHB1LPENR_SRAM2LPEN_Pos)	/*!< 0x00020000 */
#define RCC_AHB1LPENR_SRAM2LPEN            RCC_AHB1LPENR_SRAM2LPEN_Msk
#define RCC_AHB1LPENR_BKPSRAMLPEN_Pos      (18U)
#define RCC_AHB1LPENR_BKPSRAMLPEN_Msk      (0x1UL << RCC_AHB1LPENR_BKPSRAMLPEN_Pos)	/*!< 0x00040000 */
#define RCC_AHB1LPENR_BKPSRAMLPEN          RCC_AHB1LPENR_BKPSRAMLPEN_Msk
#define RCC_AHB1LPENR_DTCMLPEN_Pos         (20U)
#define RCC_AHB1LPENR_DTCMLPEN_Msk         (0x1UL << RCC_AHB1LPENR_DTCMLPEN_Pos)/*!< 0x00100000 */
#define RCC_AHB1LPENR_DTCMLPEN             RCC_AHB1LPENR_DTCMLPEN_Msk
#define RCC_AHB1LPENR_DMA1LPEN_Pos         (21U)
#define RCC_AHB1LPENR_DMA1LPEN_Msk         (0x1UL << RCC_AHB1LPENR_DMA1LPEN_Pos)/*!< 0x00200000 */
#define RCC_AHB1LPENR_DMA1LPEN             RCC_AHB1LPENR_DMA1LPEN_Msk
#define RCC_AHB1LPENR_DMA2LPEN_Pos         (22U)
#define RCC_AHB1LPENR_DMA2LPEN_Msk         (0x1UL << RCC_AHB1LPENR_DMA2LPEN_Pos)/*!< 0x00400000 */
#define RCC_AHB1LPENR_DMA2LPEN             RCC_AHB1LPENR_DMA2LPEN_Msk
#define RCC_AHB1LPENR_OTGHSLPEN_Pos        (29U)
#define RCC_AHB1LPENR_OTGHSLPEN_Msk        (0x1UL << RCC_AHB1LPENR_OTGHSLPEN_Pos)	/*!< 0x20000000 */
#define RCC_AHB1LPENR_OTGHSLPEN            RCC_AHB1LPENR_OTGHSLPEN_Msk
#define RCC_AHB1LPENR_OTGHSULPILPEN_Pos    (30U)
#define RCC_AHB1LPENR_OTGHSULPILPEN_Msk    (0x1UL << RCC_AHB1LPENR_OTGHSULPILPEN_Pos)	/*!< 0x40000000 */
#define RCC_AHB1LPENR_OTGHSULPILPEN        RCC_AHB1LPENR_OTGHSULPILPEN_Msk

/********************  Bit definition for RCC_AHB2LPENR register  *************/
#define RCC_AHB2LPENR_RNGLPEN_Pos      (6U)
#define RCC_AHB2LPENR_RNGLPEN_Msk      (0x1UL << RCC_AHB2LPENR_RNGLPEN_Pos)	/*!< 0x00000040 */
#define RCC_AHB2LPENR_RNGLPEN          RCC_AHB2LPENR_RNGLPEN_Msk
#define RCC_AHB2LPENR_OTGFSLPEN_Pos    (7U)
#define RCC_AHB2LPENR_OTGFSLPEN_Msk    (0x1UL << RCC_AHB2LPENR_OTGFSLPEN_Pos)	/*!< 0x00000080 */
#define RCC_AHB2LPENR_OTGFSLPEN        RCC_AHB2LPENR_OTGFSLPEN_Msk

/********************  Bit definition for RCC_AHB3LPENR register  *************/
#define RCC_AHB3LPENR_FMCLPEN_Pos       (0U)
#define RCC_AHB3LPENR_FMCLPEN_Msk       (0x1UL << RCC_AHB3LPENR_FMCLPEN_Pos)/*!< 0x00000001 */
#define RCC_AHB3LPENR_FMCLPEN           RCC_AHB3LPENR_FMCLPEN_Msk
#define RCC_AHB3LPENR_QSPILPEN_Pos      (1U)
#define RCC_AHB3LPENR_QSPILPEN_Msk      (0x1UL << RCC_AHB3LPENR_QSPILPEN_Pos)	/*!< 0x00000002 */
#define RCC_AHB3LPENR_QSPILPEN          RCC_AHB3LPENR_QSPILPEN_Msk
/********************  Bit definition for RCC_APB1LPENR register  *************/
#define RCC_APB1LPENR_TIM2LPEN_Pos      (0U)
#define RCC_APB1LPENR_TIM2LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM2LPEN_Pos)	/*!< 0x00000001 */
#define RCC_APB1LPENR_TIM2LPEN          RCC_APB1LPENR_TIM2LPEN_Msk
#define RCC_APB1LPENR_TIM3LPEN_Pos      (1U)
#define RCC_APB1LPENR_TIM3LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM3LPEN_Pos)	/*!< 0x00000002 */
#define RCC_APB1LPENR_TIM3LPEN          RCC_APB1LPENR_TIM3LPEN_Msk
#define RCC_APB1LPENR_TIM4LPEN_Pos      (2U)
#define RCC_APB1LPENR_TIM4LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM4LPEN_Pos)	/*!< 0x00000004 */
#define RCC_APB1LPENR_TIM4LPEN          RCC_APB1LPENR_TIM4LPEN_Msk
#define RCC_APB1LPENR_TIM5LPEN_Pos      (3U)
#define RCC_APB1LPENR_TIM5LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM5LPEN_Pos)	/*!< 0x00000008 */
#define RCC_APB1LPENR_TIM5LPEN          RCC_APB1LPENR_TIM5LPEN_Msk
#define RCC_APB1LPENR_TIM6LPEN_Pos      (4U)
#define RCC_APB1LPENR_TIM6LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM6LPEN_Pos)	/*!< 0x00000010 */
#define RCC_APB1LPENR_TIM6LPEN          RCC_APB1LPENR_TIM6LPEN_Msk
#define RCC_APB1LPENR_TIM7LPEN_Pos      (5U)
#define RCC_APB1LPENR_TIM7LPEN_Msk      (0x1UL << RCC_APB1LPENR_TIM7LPEN_Pos)	/*!< 0x00000020 */
#define RCC_APB1LPENR_TIM7LPEN          RCC_APB1LPENR_TIM7LPEN_Msk
#define RCC_APB1LPENR_TIM12LPEN_Pos     (6U)
#define RCC_APB1LPENR_TIM12LPEN_Msk     (0x1UL << RCC_APB1LPENR_TIM12LPEN_Pos)	/*!< 0x00000040 */
#define RCC_APB1LPENR_TIM12LPEN         RCC_APB1LPENR_TIM12LPEN_Msk
#define RCC_APB1LPENR_TIM13LPEN_Pos     (7U)
#define RCC_APB1LPENR_TIM13LPEN_Msk     (0x1UL << RCC_APB1LPENR_TIM13LPEN_Pos)	/*!< 0x00000080 */
#define RCC_APB1LPENR_TIM13LPEN         RCC_APB1LPENR_TIM13LPEN_Msk
#define RCC_APB1LPENR_TIM14LPEN_Pos     (8U)
#define RCC_APB1LPENR_TIM14LPEN_Msk     (0x1UL << RCC_APB1LPENR_TIM14LPEN_Pos)	/*!< 0x00000100 */
#define RCC_APB1LPENR_TIM14LPEN         RCC_APB1LPENR_TIM14LPEN_Msk
#define RCC_APB1LPENR_LPTIM1LPEN_Pos    (9U)
#define RCC_APB1LPENR_LPTIM1LPEN_Msk    (0x1UL << RCC_APB1LPENR_LPTIM1LPEN_Pos)	/*!< 0x00000200 */
#define RCC_APB1LPENR_LPTIM1LPEN        RCC_APB1LPENR_LPTIM1LPEN_Msk
#define RCC_APB1LPENR_RTCLPEN_Pos       (10U)
#define RCC_APB1LPENR_RTCLPEN_Msk       (0x1UL << RCC_APB1LPENR_RTCLPEN_Pos)/*!< 0x00000400 */
#define RCC_APB1LPENR_RTCLPEN           RCC_APB1LPENR_RTCLPEN_Msk
#define RCC_APB1LPENR_WWDGLPEN_Pos      (11U)
#define RCC_APB1LPENR_WWDGLPEN_Msk      (0x1UL << RCC_APB1LPENR_WWDGLPEN_Pos)	/*!< 0x00000800 */
#define RCC_APB1LPENR_WWDGLPEN          RCC_APB1LPENR_WWDGLPEN_Msk
#define RCC_APB1LPENR_SPI2LPEN_Pos      (14U)
#define RCC_APB1LPENR_SPI2LPEN_Msk      (0x1UL << RCC_APB1LPENR_SPI2LPEN_Pos)	/*!< 0x00004000 */
#define RCC_APB1LPENR_SPI2LPEN          RCC_APB1LPENR_SPI2LPEN_Msk
#define RCC_APB1LPENR_SPI3LPEN_Pos      (15U)
#define RCC_APB1LPENR_SPI3LPEN_Msk      (0x1UL << RCC_APB1LPENR_SPI3LPEN_Pos)	/*!< 0x00008000 */
#define RCC_APB1LPENR_SPI3LPEN          RCC_APB1LPENR_SPI3LPEN_Msk
#define RCC_APB1LPENR_USART2LPEN_Pos    (17U)
#define RCC_APB1LPENR_USART2LPEN_Msk    (0x1UL << RCC_APB1LPENR_USART2LPEN_Pos)	/*!< 0x00020000 */
#define RCC_APB1LPENR_USART2LPEN        RCC_APB1LPENR_USART2LPEN_Msk
#define RCC_APB1LPENR_USART3LPEN_Pos    (18U)
#define RCC_APB1LPENR_USART3LPEN_Msk    (0x1UL << RCC_APB1LPENR_USART3LPEN_Pos)	/*!< 0x00040000 */
#define RCC_APB1LPENR_USART3LPEN        RCC_APB1LPENR_USART3LPEN_Msk
#define RCC_APB1LPENR_UART4LPEN_Pos     (19U)
#define RCC_APB1LPENR_UART4LPEN_Msk     (0x1UL << RCC_APB1LPENR_UART4LPEN_Pos)	/*!< 0x00080000 */
#define RCC_APB1LPENR_UART4LPEN         RCC_APB1LPENR_UART4LPEN_Msk
#define RCC_APB1LPENR_UART5LPEN_Pos     (20U)
#define RCC_APB1LPENR_UART5LPEN_Msk     (0x1UL << RCC_APB1LPENR_UART5LPEN_Pos)	/*!< 0x00100000 */
#define RCC_APB1LPENR_UART5LPEN         RCC_APB1LPENR_UART5LPEN_Msk
#define RCC_APB1LPENR_I2C1LPEN_Pos      (21U)
#define RCC_APB1LPENR_I2C1LPEN_Msk      (0x1UL << RCC_APB1LPENR_I2C1LPEN_Pos)	/*!< 0x00200000 */
#define RCC_APB1LPENR_I2C1LPEN          RCC_APB1LPENR_I2C1LPEN_Msk
#define RCC_APB1LPENR_I2C2LPEN_Pos      (22U)
#define RCC_APB1LPENR_I2C2LPEN_Msk      (0x1UL << RCC_APB1LPENR_I2C2LPEN_Pos)	/*!< 0x00400000 */
#define RCC_APB1LPENR_I2C2LPEN          RCC_APB1LPENR_I2C2LPEN_Msk
#define RCC_APB1LPENR_I2C3LPEN_Pos      (23U)
#define RCC_APB1LPENR_I2C3LPEN_Msk      (0x1UL << RCC_APB1LPENR_I2C3LPEN_Pos)	/*!< 0x00800000 */
#define RCC_APB1LPENR_I2C3LPEN          RCC_APB1LPENR_I2C3LPEN_Msk
#define RCC_APB1LPENR_CAN1LPEN_Pos      (25U)
#define RCC_APB1LPENR_CAN1LPEN_Msk      (0x1UL << RCC_APB1LPENR_CAN1LPEN_Pos)	/*!< 0x02000000 */
#define RCC_APB1LPENR_CAN1LPEN          RCC_APB1LPENR_CAN1LPEN_Msk
#define RCC_APB1LPENR_PWRLPEN_Pos       (28U)
#define RCC_APB1LPENR_PWRLPEN_Msk       (0x1UL << RCC_APB1LPENR_PWRLPEN_Pos)/*!< 0x10000000 */
#define RCC_APB1LPENR_PWRLPEN           RCC_APB1LPENR_PWRLPEN_Msk
#define RCC_APB1LPENR_DACLPEN_Pos       (29U)
#define RCC_APB1LPENR_DACLPEN_Msk       (0x1UL << RCC_APB1LPENR_DACLPEN_Pos)/*!< 0x20000000 */
#define RCC_APB1LPENR_DACLPEN           RCC_APB1LPENR_DACLPEN_Msk
#define RCC_APB1LPENR_UART7LPEN_Pos     (30U)
#define RCC_APB1LPENR_UART7LPEN_Msk     (0x1UL << RCC_APB1LPENR_UART7LPEN_Pos)	/*!< 0x40000000 */
#define RCC_APB1LPENR_UART7LPEN         RCC_APB1LPENR_UART7LPEN_Msk
#define RCC_APB1LPENR_UART8LPEN_Pos     (31U)
#define RCC_APB1LPENR_UART8LPEN_Msk     (0x1UL << RCC_APB1LPENR_UART8LPEN_Pos)	/*!< 0x80000000 */
#define RCC_APB1LPENR_UART8LPEN         RCC_APB1LPENR_UART8LPEN_Msk

/********************  Bit definition for RCC_APB2LPENR register  *************/
#define RCC_APB2LPENR_TIM1LPEN_Pos      (0U)
#define RCC_APB2LPENR_TIM1LPEN_Msk      (0x1UL << RCC_APB2LPENR_TIM1LPEN_Pos)	/*!< 0x00000001 */
#define RCC_APB2LPENR_TIM1LPEN          RCC_APB2LPENR_TIM1LPEN_Msk
#define RCC_APB2LPENR_TIM8LPEN_Pos      (1U)
#define RCC_APB2LPENR_TIM8LPEN_Msk      (0x1UL << RCC_APB2LPENR_TIM8LPEN_Pos)	/*!< 0x00000002 */
#define RCC_APB2LPENR_TIM8LPEN          RCC_APB2LPENR_TIM8LPEN_Msk
#define RCC_APB2LPENR_USART1LPEN_Pos    (4U)
#define RCC_APB2LPENR_USART1LPEN_Msk    (0x1UL << RCC_APB2LPENR_USART1LPEN_Pos)	/*!< 0x00000010 */
#define RCC_APB2LPENR_USART1LPEN        RCC_APB2LPENR_USART1LPEN_Msk
#define RCC_APB2LPENR_USART6LPEN_Pos    (5U)
#define RCC_APB2LPENR_USART6LPEN_Msk    (0x1UL << RCC_APB2LPENR_USART6LPEN_Pos)	/*!< 0x00000020 */
#define RCC_APB2LPENR_USART6LPEN        RCC_APB2LPENR_USART6LPEN_Msk
#define RCC_APB2LPENR_SDMMC2LPEN_Pos    (7U)
#define RCC_APB2LPENR_SDMMC2LPEN_Msk    (0x1UL << RCC_APB2LPENR_SDMMC2LPEN_Pos)	/*!< 0x00000080 */
#define RCC_APB2LPENR_SDMMC2LPEN        RCC_APB2LPENR_SDMMC2LPEN_Msk
#define RCC_APB2LPENR_ADC1LPEN_Pos      (8U)
#define RCC_APB2LPENR_ADC1LPEN_Msk      (0x1UL << RCC_APB2LPENR_ADC1LPEN_Pos)	/*!< 0x00000100 */
#define RCC_APB2LPENR_ADC1LPEN          RCC_APB2LPENR_ADC1LPEN_Msk
#define RCC_APB2LPENR_ADC2LPEN_Pos      (9U)
#define RCC_APB2LPENR_ADC2LPEN_Msk      (0x1UL << RCC_APB2LPENR_ADC2LPEN_Pos)	/*!< 0x00000200 */
#define RCC_APB2LPENR_ADC2LPEN          RCC_APB2LPENR_ADC2LPEN_Msk
#define RCC_APB2LPENR_ADC3LPEN_Pos      (10U)
#define RCC_APB2LPENR_ADC3LPEN_Msk      (0x1UL << RCC_APB2LPENR_ADC3LPEN_Pos)	/*!< 0x00000400 */
#define RCC_APB2LPENR_ADC3LPEN          RCC_APB2LPENR_ADC3LPEN_Msk
#define RCC_APB2LPENR_SDMMC1LPEN_Pos    (11U)
#define RCC_APB2LPENR_SDMMC1LPEN_Msk    (0x1UL << RCC_APB2LPENR_SDMMC1LPEN_Pos)	/*!< 0x00000800 */
#define RCC_APB2LPENR_SDMMC1LPEN        RCC_APB2LPENR_SDMMC1LPEN_Msk
#define RCC_APB2LPENR_SPI1LPEN_Pos      (12U)
#define RCC_APB2LPENR_SPI1LPEN_Msk      (0x1UL << RCC_APB2LPENR_SPI1LPEN_Pos)	/*!< 0x00001000 */
#define RCC_APB2LPENR_SPI1LPEN          RCC_APB2LPENR_SPI1LPEN_Msk
#define RCC_APB2LPENR_SPI4LPEN_Pos      (13U)
#define RCC_APB2LPENR_SPI4LPEN_Msk      (0x1UL << RCC_APB2LPENR_SPI4LPEN_Pos)	/*!< 0x00002000 */
#define RCC_APB2LPENR_SPI4LPEN          RCC_APB2LPENR_SPI4LPEN_Msk
#define RCC_APB2LPENR_SYSCFGLPEN_Pos    (14U)
#define RCC_APB2LPENR_SYSCFGLPEN_Msk    (0x1UL << RCC_APB2LPENR_SYSCFGLPEN_Pos)	/*!< 0x00004000 */
#define RCC_APB2LPENR_SYSCFGLPEN        RCC_APB2LPENR_SYSCFGLPEN_Msk
#define RCC_APB2LPENR_TIM9LPEN_Pos      (16U)
#define RCC_APB2LPENR_TIM9LPEN_Msk      (0x1UL << RCC_APB2LPENR_TIM9LPEN_Pos)	/*!< 0x00010000 */
#define RCC_APB2LPENR_TIM9LPEN          RCC_APB2LPENR_TIM9LPEN_Msk
#define RCC_APB2LPENR_TIM10LPEN_Pos     (17U)
#define RCC_APB2LPENR_TIM10LPEN_Msk     (0x1UL << RCC_APB2LPENR_TIM10LPEN_Pos)	/*!< 0x00020000 */
#define RCC_APB2LPENR_TIM10LPEN         RCC_APB2LPENR_TIM10LPEN_Msk
#define RCC_APB2LPENR_TIM11LPEN_Pos     (18U)
#define RCC_APB2LPENR_TIM11LPEN_Msk     (0x1UL << RCC_APB2LPENR_TIM11LPEN_Pos)	/*!< 0x00040000 */
#define RCC_APB2LPENR_TIM11LPEN         RCC_APB2LPENR_TIM11LPEN_Msk
#define RCC_APB2LPENR_SPI5LPEN_Pos      (20U)
#define RCC_APB2LPENR_SPI5LPEN_Msk      (0x1UL << RCC_APB2LPENR_SPI5LPEN_Pos)	/*!< 0x00100000 */
#define RCC_APB2LPENR_SPI5LPEN          RCC_APB2LPENR_SPI5LPEN_Msk
#define RCC_APB2LPENR_SAI1LPEN_Pos      (22U)
#define RCC_APB2LPENR_SAI1LPEN_Msk      (0x1UL << RCC_APB2LPENR_SAI1LPEN_Pos)	/*!< 0x00400000 */
#define RCC_APB2LPENR_SAI1LPEN          RCC_APB2LPENR_SAI1LPEN_Msk
#define RCC_APB2LPENR_SAI2LPEN_Pos      (23U)
#define RCC_APB2LPENR_SAI2LPEN_Msk      (0x1UL << RCC_APB2LPENR_SAI2LPEN_Pos)	/*!< 0x00800000 */
#define RCC_APB2LPENR_SAI2LPEN          RCC_APB2LPENR_SAI2LPEN_Msk

/********************  Bit definition for RCC_BDCR register  ******************/
#define RCC_BDCR_LSEON_Pos     (0U)
#define RCC_BDCR_LSEON_Msk     (0x1UL << RCC_BDCR_LSEON_Pos)/*!< 0x00000001 */
#define RCC_BDCR_LSEON         RCC_BDCR_LSEON_Msk
#define RCC_BDCR_LSERDY_Pos    (1U)
#define RCC_BDCR_LSERDY_Msk    (0x1UL << RCC_BDCR_LSERDY_Pos)	/*!< 0x00000002 */
#define RCC_BDCR_LSERDY        RCC_BDCR_LSERDY_Msk
#define RCC_BDCR_LSEBYP_Pos    (2U)
#define RCC_BDCR_LSEBYP_Msk    (0x1UL << RCC_BDCR_LSEBYP_Pos)	/*!< 0x00000004 */
#define RCC_BDCR_LSEBYP        RCC_BDCR_LSEBYP_Msk
#define RCC_BDCR_LSEDRV_Pos    (3U)
#define RCC_BDCR_LSEDRV_Msk    (0x3UL << RCC_BDCR_LSEDRV_Pos)	/*!< 0x00000018 */
#define RCC_BDCR_LSEDRV        RCC_BDCR_LSEDRV_Msk
#define RCC_BDCR_LSEDRV_0      (0x1UL << RCC_BDCR_LSEDRV_Pos)	/*!< 0x00000008 */
#define RCC_BDCR_LSEDRV_1      (0x2UL << RCC_BDCR_LSEDRV_Pos)	/*!< 0x00000010 */
#define RCC_BDCR_RTCSEL_Pos    (8U)
#define RCC_BDCR_RTCSEL_Msk    (0x3UL << RCC_BDCR_RTCSEL_Pos)	/*!< 0x00000300 */
#define RCC_BDCR_RTCSEL        RCC_BDCR_RTCSEL_Msk
#define RCC_BDCR_RTCSEL_0      (0x1UL << RCC_BDCR_RTCSEL_Pos)	/*!< 0x00000100 */
#define RCC_BDCR_RTCSEL_1      (0x2UL << RCC_BDCR_RTCSEL_Pos)	/*!< 0x00000200 */
#define RCC_BDCR_RTCEN_Pos     (15U)
#define RCC_BDCR_RTCEN_Msk     (0x1UL << RCC_BDCR_RTCEN_Pos)/*!< 0x00008000 */
#define RCC_BDCR_RTCEN         RCC_BDCR_RTCEN_Msk
#define RCC_BDCR_BDRST_Pos     (16U)
#define RCC_BDCR_BDRST_Msk     (0x1UL << RCC_BDCR_BDRST_Pos)/*!< 0x00010000 */
#define RCC_BDCR_BDRST         RCC_BDCR_BDRST_Msk

/********************  Bit definition for RCC_CSR register  *******************/
#define RCC_CSR_LSION_Pos       (0U)
#define RCC_CSR_LSION_Msk       (0x1UL << RCC_CSR_LSION_Pos)/*!< 0x00000001 */
#define RCC_CSR_LSION           RCC_CSR_LSION_Msk
#define RCC_CSR_LSIRDY_Pos      (1U)
#define RCC_CSR_LSIRDY_Msk      (0x1UL << RCC_CSR_LSIRDY_Pos)	/*!< 0x00000002 */
#define RCC_CSR_LSIRDY          RCC_CSR_LSIRDY_Msk
#define RCC_CSR_RMVF_Pos        (24U)
#define RCC_CSR_RMVF_Msk        (0x1UL << RCC_CSR_RMVF_Pos)	/*!< 0x01000000 */
#define RCC_CSR_RMVF            RCC_CSR_RMVF_Msk
#define RCC_CSR_BORRSTF_Pos     (25U)
#define RCC_CSR_BORRSTF_Msk     (0x1UL << RCC_CSR_BORRSTF_Pos)	/*!< 0x02000000 */
#define RCC_CSR_BORRSTF         RCC_CSR_BORRSTF_Msk
#define RCC_CSR_PINRSTF_Pos     (26U)
#define RCC_CSR_PINRSTF_Msk     (0x1UL << RCC_CSR_PINRSTF_Pos)	/*!< 0x04000000 */
#define RCC_CSR_PINRSTF         RCC_CSR_PINRSTF_Msk
#define RCC_CSR_PORRSTF_Pos     (27U)
#define RCC_CSR_PORRSTF_Msk     (0x1UL << RCC_CSR_PORRSTF_Pos)	/*!< 0x08000000 */
#define RCC_CSR_PORRSTF         RCC_CSR_PORRSTF_Msk
#define RCC_CSR_SFTRSTF_Pos     (28U)
#define RCC_CSR_SFTRSTF_Msk     (0x1UL << RCC_CSR_SFTRSTF_Pos)	/*!< 0x10000000 */
#define RCC_CSR_SFTRSTF         RCC_CSR_SFTRSTF_Msk
#define RCC_CSR_IWDGRSTF_Pos    (29U)
#define RCC_CSR_IWDGRSTF_Msk    (0x1UL << RCC_CSR_IWDGRSTF_Pos)	/*!< 0x20000000 */
#define RCC_CSR_IWDGRSTF        RCC_CSR_IWDGRSTF_Msk
#define RCC_CSR_WWDGRSTF_Pos    (30U)
#define RCC_CSR_WWDGRSTF_Msk    (0x1UL << RCC_CSR_WWDGRSTF_Pos)	/*!< 0x40000000 */
#define RCC_CSR_WWDGRSTF        RCC_CSR_WWDGRSTF_Msk
#define RCC_CSR_LPWRRSTF_Pos    (31U)
#define RCC_CSR_LPWRRSTF_Msk    (0x1UL << RCC_CSR_LPWRRSTF_Pos)	/*!< 0x80000000 */
#define RCC_CSR_LPWRRSTF        RCC_CSR_LPWRRSTF_Msk

/********************  Bit definition for RCC_SSCGR register  *****************/
#define RCC_SSCGR_MODPER_Pos       (0U)
#define RCC_SSCGR_MODPER_Msk       (0x1FFFUL << RCC_SSCGR_MODPER_Pos)	/*!< 0x00001FFF */
#define RCC_SSCGR_MODPER           RCC_SSCGR_MODPER_Msk
#define RCC_SSCGR_INCSTEP_Pos      (13U)
#define RCC_SSCGR_INCSTEP_Msk      (0x7FFFUL << RCC_SSCGR_INCSTEP_Pos)	/*!< 0x0FFFE000 */
#define RCC_SSCGR_INCSTEP          RCC_SSCGR_INCSTEP_Msk
#define RCC_SSCGR_SPREADSEL_Pos    (30U)
#define RCC_SSCGR_SPREADSEL_Msk    (0x1UL << RCC_SSCGR_SPREADSEL_Pos)	/*!< 0x40000000 */
#define RCC_SSCGR_SPREADSEL        RCC_SSCGR_SPREADSEL_Msk
#define RCC_SSCGR_SSCGEN_Pos       (31U)
#define RCC_SSCGR_SSCGEN_Msk       (0x1UL << RCC_SSCGR_SSCGEN_Pos)	/*!< 0x80000000 */
#define RCC_SSCGR_SSCGEN           RCC_SSCGR_SSCGEN_Msk

/********************  Bit definition for RCC_PLLI2SCFGR register  ************/
#define RCC_PLLI2SCFGR_PLLI2SN_Pos    (6U)
#define RCC_PLLI2SCFGR_PLLI2SN_Msk    (0x1FFUL << RCC_PLLI2SCFGR_PLLI2SN_Pos)	/*!< 0x00007FC0 */
#define RCC_PLLI2SCFGR_PLLI2SN        RCC_PLLI2SCFGR_PLLI2SN_Msk
#define RCC_PLLI2SCFGR_PLLI2SN_0      (0x001UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)	/*!< 0x00000040 */
#define RCC_PLLI2SCFGR_PLLI2SN_1      (0x002UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)	/*!< 0x00000080 */
#define RCC_PLLI2SCFGR_PLLI2SN_2      (0x004UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)	/*!< 0x00000100 */
#define RCC_PLLI2SCFGR_PLLI2SN_3      (0x008UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)	/*!< 0x00000200 */
#define RCC_PLLI2SCFGR_PLLI2SN_4      (0x010UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)	/*!< 0x00000400 */
#define RCC_PLLI2SCFGR_PLLI2SN_5      (0x020UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)	/*!< 0x00000800 */
#define RCC_PLLI2SCFGR_PLLI2SN_6      (0x040UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)	/*!< 0x00001000 */
#define RCC_PLLI2SCFGR_PLLI2SN_7      (0x080UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)	/*!< 0x00002000 */
#define RCC_PLLI2SCFGR_PLLI2SN_8      (0x100UL << RCC_PLLI2SCFGR_PLLI2SN_Pos)	/*!< 0x00004000 */
#define RCC_PLLI2SCFGR_PLLI2SQ_Pos    (24U)
#define RCC_PLLI2SCFGR_PLLI2SQ_Msk    (0xFUL << RCC_PLLI2SCFGR_PLLI2SQ_Pos)	/*!< 0x0F000000 */
#define RCC_PLLI2SCFGR_PLLI2SQ        RCC_PLLI2SCFGR_PLLI2SQ_Msk
#define RCC_PLLI2SCFGR_PLLI2SQ_0      (0x1UL << RCC_PLLI2SCFGR_PLLI2SQ_Pos)	/*!< 0x01000000 */
#define RCC_PLLI2SCFGR_PLLI2SQ_1      (0x2UL << RCC_PLLI2SCFGR_PLLI2SQ_Pos)	/*!< 0x02000000 */
#define RCC_PLLI2SCFGR_PLLI2SQ_2      (0x4UL << RCC_PLLI2SCFGR_PLLI2SQ_Pos)	/*!< 0x04000000 */
#define RCC_PLLI2SCFGR_PLLI2SQ_3      (0x8UL << RCC_PLLI2SCFGR_PLLI2SQ_Pos)	/*!< 0x08000000 */
#define RCC_PLLI2SCFGR_PLLI2SR_Pos    (28U)
#define RCC_PLLI2SCFGR_PLLI2SR_Msk    (0x7UL << RCC_PLLI2SCFGR_PLLI2SR_Pos)	/*!< 0x70000000 */
#define RCC_PLLI2SCFGR_PLLI2SR        RCC_PLLI2SCFGR_PLLI2SR_Msk
#define RCC_PLLI2SCFGR_PLLI2SR_0      (0x1UL << RCC_PLLI2SCFGR_PLLI2SR_Pos)	/*!< 0x10000000 */
#define RCC_PLLI2SCFGR_PLLI2SR_1      (0x2UL << RCC_PLLI2SCFGR_PLLI2SR_Pos)	/*!< 0x20000000 */
#define RCC_PLLI2SCFGR_PLLI2SR_2      (0x4UL << RCC_PLLI2SCFGR_PLLI2SR_Pos)	/*!< 0x40000000 */

/********************  Bit definition for RCC_PLLSAICFGR register  ************/
#define RCC_PLLSAICFGR_PLLSAIN_Pos    (6U)
#define RCC_PLLSAICFGR_PLLSAIN_Msk    (0x1FFUL << RCC_PLLSAICFGR_PLLSAIN_Pos)	/*!< 0x00007FC0 */
#define RCC_PLLSAICFGR_PLLSAIN        RCC_PLLSAICFGR_PLLSAIN_Msk
#define RCC_PLLSAICFGR_PLLSAIN_0      (0x001UL << RCC_PLLSAICFGR_PLLSAIN_Pos)	/*!< 0x00000040 */
#define RCC_PLLSAICFGR_PLLSAIN_1      (0x002UL << RCC_PLLSAICFGR_PLLSAIN_Pos)	/*!< 0x00000080 */
#define RCC_PLLSAICFGR_PLLSAIN_2      (0x004UL << RCC_PLLSAICFGR_PLLSAIN_Pos)	/*!< 0x00000100 */
#define RCC_PLLSAICFGR_PLLSAIN_3      (0x008UL << RCC_PLLSAICFGR_PLLSAIN_Pos)	/*!< 0x00000200 */
#define RCC_PLLSAICFGR_PLLSAIN_4      (0x010UL << RCC_PLLSAICFGR_PLLSAIN_Pos)	/*!< 0x00000400 */
#define RCC_PLLSAICFGR_PLLSAIN_5      (0x020UL << RCC_PLLSAICFGR_PLLSAIN_Pos)	/*!< 0x00000800 */
#define RCC_PLLSAICFGR_PLLSAIN_6      (0x040UL << RCC_PLLSAICFGR_PLLSAIN_Pos)	/*!< 0x00001000 */
#define RCC_PLLSAICFGR_PLLSAIN_7      (0x080UL << RCC_PLLSAICFGR_PLLSAIN_Pos)	/*!< 0x00002000 */
#define RCC_PLLSAICFGR_PLLSAIN_8      (0x100UL << RCC_PLLSAICFGR_PLLSAIN_Pos)	/*!< 0x00004000 */
#define RCC_PLLSAICFGR_PLLSAIP_Pos    (16U)
#define RCC_PLLSAICFGR_PLLSAIP_Msk    (0x3UL << RCC_PLLSAICFGR_PLLSAIP_Pos)	/*!< 0x00030000 */
#define RCC_PLLSAICFGR_PLLSAIP        RCC_PLLSAICFGR_PLLSAIP_Msk
#define RCC_PLLSAICFGR_PLLSAIP_0      (0x1UL << RCC_PLLSAICFGR_PLLSAIP_Pos)	/*!< 0x00010000 */
#define RCC_PLLSAICFGR_PLLSAIP_1      (0x2UL << RCC_PLLSAICFGR_PLLSAIP_Pos)	/*!< 0x00020000 */
#define RCC_PLLSAICFGR_PLLSAIQ_Pos    (24U)
#define RCC_PLLSAICFGR_PLLSAIQ_Msk    (0xFUL << RCC_PLLSAICFGR_PLLSAIQ_Pos)	/*!< 0x0F000000 */
#define RCC_PLLSAICFGR_PLLSAIQ        RCC_PLLSAICFGR_PLLSAIQ_Msk
#define RCC_PLLSAICFGR_PLLSAIQ_0      (0x1UL << RCC_PLLSAICFGR_PLLSAIQ_Pos)	/*!< 0x01000000 */
#define RCC_PLLSAICFGR_PLLSAIQ_1      (0x2UL << RCC_PLLSAICFGR_PLLSAIQ_Pos)	/*!< 0x02000000 */
#define RCC_PLLSAICFGR_PLLSAIQ_2      (0x4UL << RCC_PLLSAICFGR_PLLSAIQ_Pos)	/*!< 0x04000000 */
#define RCC_PLLSAICFGR_PLLSAIQ_3      (0x8UL << RCC_PLLSAICFGR_PLLSAIQ_Pos)	/*!< 0x08000000 */

/********************  Bit definition for RCC_DCKCFGR1 register  ***************/
#define RCC_DCKCFGR1_PLLI2SDIVQ_Pos    (0U)
#define RCC_DCKCFGR1_PLLI2SDIVQ_Msk    (0x1FUL << RCC_DCKCFGR1_PLLI2SDIVQ_Pos)	/*!< 0x0000001F */
#define RCC_DCKCFGR1_PLLI2SDIVQ        RCC_DCKCFGR1_PLLI2SDIVQ_Msk
#define RCC_DCKCFGR1_PLLI2SDIVQ_0      (0x01UL << RCC_DCKCFGR1_PLLI2SDIVQ_Pos)	/*!< 0x00000001 */
#define RCC_DCKCFGR1_PLLI2SDIVQ_1      (0x02UL << RCC_DCKCFGR1_PLLI2SDIVQ_Pos)	/*!< 0x00000002 */
#define RCC_DCKCFGR1_PLLI2SDIVQ_2      (0x04UL << RCC_DCKCFGR1_PLLI2SDIVQ_Pos)	/*!< 0x00000004 */
#define RCC_DCKCFGR1_PLLI2SDIVQ_3      (0x08UL << RCC_DCKCFGR1_PLLI2SDIVQ_Pos)	/*!< 0x00000008 */
#define RCC_DCKCFGR1_PLLI2SDIVQ_4      (0x10UL << RCC_DCKCFGR1_PLLI2SDIVQ_Pos)	/*!< 0x00000010 */

#define RCC_DCKCFGR1_PLLSAIDIVQ_Pos    (8U)
#define RCC_DCKCFGR1_PLLSAIDIVQ_Msk    (0x1FUL << RCC_DCKCFGR1_PLLSAIDIVQ_Pos)	/*!< 0x00001F00 */
#define RCC_DCKCFGR1_PLLSAIDIVQ        RCC_DCKCFGR1_PLLSAIDIVQ_Msk
#define RCC_DCKCFGR1_PLLSAIDIVQ_0      (0x01UL << RCC_DCKCFGR1_PLLSAIDIVQ_Pos)	/*!< 0x00000100 */
#define RCC_DCKCFGR1_PLLSAIDIVQ_1      (0x02UL << RCC_DCKCFGR1_PLLSAIDIVQ_Pos)	/*!< 0x00000200 */
#define RCC_DCKCFGR1_PLLSAIDIVQ_2      (0x04UL << RCC_DCKCFGR1_PLLSAIDIVQ_Pos)	/*!< 0x00000400 */
#define RCC_DCKCFGR1_PLLSAIDIVQ_3      (0x08UL << RCC_DCKCFGR1_PLLSAIDIVQ_Pos)	/*!< 0x00000800 */
#define RCC_DCKCFGR1_PLLSAIDIVQ_4      (0x10UL << RCC_DCKCFGR1_PLLSAIDIVQ_Pos)	/*!< 0x00001000 */


#define RCC_DCKCFGR1_SAI1SEL_Pos    (20U)
#define RCC_DCKCFGR1_SAI1SEL_Msk    (0x3UL << RCC_DCKCFGR1_SAI1SEL_Pos)	/*!< 0x00300000 */
#define RCC_DCKCFGR1_SAI1SEL        RCC_DCKCFGR1_SAI1SEL_Msk
#define RCC_DCKCFGR1_SAI1SEL_0      (0x1UL << RCC_DCKCFGR1_SAI1SEL_Pos)	/*!< 0x00100000 */
#define RCC_DCKCFGR1_SAI1SEL_1      (0x2UL << RCC_DCKCFGR1_SAI1SEL_Pos)	/*!< 0x00200000 */

#define RCC_DCKCFGR1_SAI2SEL_Pos    (22U)
#define RCC_DCKCFGR1_SAI2SEL_Msk    (0x3UL << RCC_DCKCFGR1_SAI2SEL_Pos)	/*!< 0x00C00000 */
#define RCC_DCKCFGR1_SAI2SEL        RCC_DCKCFGR1_SAI2SEL_Msk
#define RCC_DCKCFGR1_SAI2SEL_0      (0x1UL << RCC_DCKCFGR1_SAI2SEL_Pos)	/*!< 0x00400000 */
#define RCC_DCKCFGR1_SAI2SEL_1      (0x2UL << RCC_DCKCFGR1_SAI2SEL_Pos)	/*!< 0x00800000 */

#define RCC_DCKCFGR1_TIMPRE_Pos     (24U)
#define RCC_DCKCFGR1_TIMPRE_Msk     (0x1UL << RCC_DCKCFGR1_TIMPRE_Pos)	/*!< 0x01000000 */
#define RCC_DCKCFGR1_TIMPRE         RCC_DCKCFGR1_TIMPRE_Msk

/********************  Bit definition for RCC_DCKCFGR2 register  ***************/
#define RCC_DCKCFGR2_USART1SEL_Pos    (0U)
#define RCC_DCKCFGR2_USART1SEL_Msk    (0x3UL << RCC_DCKCFGR2_USART1SEL_Pos)	/*!< 0x00000003 */
#define RCC_DCKCFGR2_USART1SEL        RCC_DCKCFGR2_USART1SEL_Msk
#define RCC_DCKCFGR2_USART1SEL_0      (0x1UL << RCC_DCKCFGR2_USART1SEL_Pos)	/*!< 0x00000001 */
#define RCC_DCKCFGR2_USART1SEL_1      (0x2UL << RCC_DCKCFGR2_USART1SEL_Pos)	/*!< 0x00000002 */
#define RCC_DCKCFGR2_USART2SEL_Pos    (2U)
#define RCC_DCKCFGR2_USART2SEL_Msk    (0x3UL << RCC_DCKCFGR2_USART2SEL_Pos)	/*!< 0x0000000C */
#define RCC_DCKCFGR2_USART2SEL        RCC_DCKCFGR2_USART2SEL_Msk
#define RCC_DCKCFGR2_USART2SEL_0      (0x1UL << RCC_DCKCFGR2_USART2SEL_Pos)	/*!< 0x00000004 */
#define RCC_DCKCFGR2_USART2SEL_1      (0x2UL << RCC_DCKCFGR2_USART2SEL_Pos)	/*!< 0x00000008 */
#define RCC_DCKCFGR2_USART3SEL_Pos    (4U)
#define RCC_DCKCFGR2_USART3SEL_Msk    (0x3UL << RCC_DCKCFGR2_USART3SEL_Pos)	/*!< 0x00000030 */
#define RCC_DCKCFGR2_USART3SEL        RCC_DCKCFGR2_USART3SEL_Msk
#define RCC_DCKCFGR2_USART3SEL_0      (0x1UL << RCC_DCKCFGR2_USART3SEL_Pos)	/*!< 0x00000010 */
#define RCC_DCKCFGR2_USART3SEL_1      (0x2UL << RCC_DCKCFGR2_USART3SEL_Pos)	/*!< 0x00000020 */
#define RCC_DCKCFGR2_UART4SEL_Pos     (6U)
#define RCC_DCKCFGR2_UART4SEL_Msk     (0x3UL << RCC_DCKCFGR2_UART4SEL_Pos)	/*!< 0x000000C0 */
#define RCC_DCKCFGR2_UART4SEL         RCC_DCKCFGR2_UART4SEL_Msk
#define RCC_DCKCFGR2_UART4SEL_0       (0x1UL << RCC_DCKCFGR2_UART4SEL_Pos)	/*!< 0x00000040 */
#define RCC_DCKCFGR2_UART4SEL_1       (0x2UL << RCC_DCKCFGR2_UART4SEL_Pos)	/*!< 0x00000080 */
#define RCC_DCKCFGR2_UART5SEL_Pos     (8U)
#define RCC_DCKCFGR2_UART5SEL_Msk     (0x3UL << RCC_DCKCFGR2_UART5SEL_Pos)	/*!< 0x00000300 */
#define RCC_DCKCFGR2_UART5SEL         RCC_DCKCFGR2_UART5SEL_Msk
#define RCC_DCKCFGR2_UART5SEL_0       (0x1UL << RCC_DCKCFGR2_UART5SEL_Pos)	/*!< 0x00000100 */
#define RCC_DCKCFGR2_UART5SEL_1       (0x2UL << RCC_DCKCFGR2_UART5SEL_Pos)	/*!< 0x00000200 */
#define RCC_DCKCFGR2_USART6SEL_Pos    (10U)
#define RCC_DCKCFGR2_USART6SEL_Msk    (0x3UL << RCC_DCKCFGR2_USART6SEL_Pos)	/*!< 0x00000C00 */
#define RCC_DCKCFGR2_USART6SEL        RCC_DCKCFGR2_USART6SEL_Msk
#define RCC_DCKCFGR2_USART6SEL_0      (0x1UL << RCC_DCKCFGR2_USART6SEL_Pos)	/*!< 0x00000400 */
#define RCC_DCKCFGR2_USART6SEL_1      (0x2UL << RCC_DCKCFGR2_USART6SEL_Pos)	/*!< 0x00000800 */
#define RCC_DCKCFGR2_UART7SEL_Pos     (12U)
#define RCC_DCKCFGR2_UART7SEL_Msk     (0x3UL << RCC_DCKCFGR2_UART7SEL_Pos)	/*!< 0x00003000 */
#define RCC_DCKCFGR2_UART7SEL         RCC_DCKCFGR2_UART7SEL_Msk
#define RCC_DCKCFGR2_UART7SEL_0       (0x1UL << RCC_DCKCFGR2_UART7SEL_Pos)	/*!< 0x00001000 */
#define RCC_DCKCFGR2_UART7SEL_1       (0x2UL << RCC_DCKCFGR2_UART7SEL_Pos)	/*!< 0x00002000 */
#define RCC_DCKCFGR2_UART8SEL_Pos     (14U)
#define RCC_DCKCFGR2_UART8SEL_Msk     (0x3UL << RCC_DCKCFGR2_UART8SEL_Pos)	/*!< 0x0000C000 */
#define RCC_DCKCFGR2_UART8SEL         RCC_DCKCFGR2_UART8SEL_Msk
#define RCC_DCKCFGR2_UART8SEL_0       (0x1UL << RCC_DCKCFGR2_UART8SEL_Pos)	/*!< 0x00004000 */
#define RCC_DCKCFGR2_UART8SEL_1       (0x2UL << RCC_DCKCFGR2_UART8SEL_Pos)	/*!< 0x00008000 */
#define RCC_DCKCFGR2_I2C1SEL_Pos      (16U)
#define RCC_DCKCFGR2_I2C1SEL_Msk      (0x3UL << RCC_DCKCFGR2_I2C1SEL_Pos)	/*!< 0x00030000 */
#define RCC_DCKCFGR2_I2C1SEL          RCC_DCKCFGR2_I2C1SEL_Msk
#define RCC_DCKCFGR2_I2C1SEL_0        (0x1UL << RCC_DCKCFGR2_I2C1SEL_Pos)	/*!< 0x00010000 */
#define RCC_DCKCFGR2_I2C1SEL_1        (0x2UL << RCC_DCKCFGR2_I2C1SEL_Pos)	/*!< 0x00020000 */
#define RCC_DCKCFGR2_I2C2SEL_Pos      (18U)
#define RCC_DCKCFGR2_I2C2SEL_Msk      (0x3UL << RCC_DCKCFGR2_I2C2SEL_Pos)	/*!< 0x000C0000 */
#define RCC_DCKCFGR2_I2C2SEL          RCC_DCKCFGR2_I2C2SEL_Msk
#define RCC_DCKCFGR2_I2C2SEL_0        (0x1UL << RCC_DCKCFGR2_I2C2SEL_Pos)	/*!< 0x00040000 */
#define RCC_DCKCFGR2_I2C2SEL_1        (0x2UL << RCC_DCKCFGR2_I2C2SEL_Pos)	/*!< 0x00080000 */
#define RCC_DCKCFGR2_I2C3SEL_Pos      (20U)
#define RCC_DCKCFGR2_I2C3SEL_Msk      (0x3UL << RCC_DCKCFGR2_I2C3SEL_Pos)	/*!< 0x00300000 */
#define RCC_DCKCFGR2_I2C3SEL          RCC_DCKCFGR2_I2C3SEL_Msk
#define RCC_DCKCFGR2_I2C3SEL_0        (0x1UL << RCC_DCKCFGR2_I2C3SEL_Pos)	/*!< 0x00100000 */
#define RCC_DCKCFGR2_I2C3SEL_1        (0x2UL << RCC_DCKCFGR2_I2C3SEL_Pos)	/*!< 0x00200000 */
#define RCC_DCKCFGR2_LPTIM1SEL_Pos    (24U)
#define RCC_DCKCFGR2_LPTIM1SEL_Msk    (0x3UL << RCC_DCKCFGR2_LPTIM1SEL_Pos)	/*!< 0x03000000 */
#define RCC_DCKCFGR2_LPTIM1SEL        RCC_DCKCFGR2_LPTIM1SEL_Msk
#define RCC_DCKCFGR2_LPTIM1SEL_0      (0x1UL << RCC_DCKCFGR2_LPTIM1SEL_Pos)	/*!< 0x01000000 */
#define RCC_DCKCFGR2_LPTIM1SEL_1      (0x2UL << RCC_DCKCFGR2_LPTIM1SEL_Pos)	/*!< 0x02000000 */
#define RCC_DCKCFGR2_CK48MSEL_Pos     (27U)
#define RCC_DCKCFGR2_CK48MSEL_Msk     (0x1UL << RCC_DCKCFGR2_CK48MSEL_Pos)	/*!< 0x08000000 */
#define RCC_DCKCFGR2_CK48MSEL         RCC_DCKCFGR2_CK48MSEL_Msk
#define RCC_DCKCFGR2_SDMMC1SEL_Pos    (28U)
#define RCC_DCKCFGR2_SDMMC1SEL_Msk    (0x1UL << RCC_DCKCFGR2_SDMMC1SEL_Pos)	/*!< 0x10000000 */
#define RCC_DCKCFGR2_SDMMC1SEL        RCC_DCKCFGR2_SDMMC1SEL_Msk
#define RCC_DCKCFGR2_SDMMC2SEL_Pos    (29U)
#define RCC_DCKCFGR2_SDMMC2SEL_Msk    (0x1UL << RCC_DCKCFGR2_SDMMC2SEL_Pos)	/*!< 0x20000000 */
#define RCC_DCKCFGR2_SDMMC2SEL        RCC_DCKCFGR2_SDMMC2SEL_Msk

/******************************************************************************/
/*                                                                            */
/*                                    RNG                                     */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for RNG_CR register  *******************/
#define RNG_CR_RNGEN_Pos    (2U)
#define RNG_CR_RNGEN_Msk    (0x1UL << RNG_CR_RNGEN_Pos)	/*!< 0x00000004 */
#define RNG_CR_RNGEN        RNG_CR_RNGEN_Msk
#define RNG_CR_IE_Pos       (3U)
#define RNG_CR_IE_Msk       (0x1UL << RNG_CR_IE_Pos)/*!< 0x00000008 */
#define RNG_CR_IE           RNG_CR_IE_Msk

/********************  Bits definition for RNG_SR register  *******************/
#define RNG_SR_DRDY_Pos    (0U)
#define RNG_SR_DRDY_Msk    (0x1UL << RNG_SR_DRDY_Pos)	/*!< 0x00000001 */
#define RNG_SR_DRDY        RNG_SR_DRDY_Msk
#define RNG_SR_CECS_Pos    (1U)
#define RNG_SR_CECS_Msk    (0x1UL << RNG_SR_CECS_Pos)	/*!< 0x00000002 */
#define RNG_SR_CECS        RNG_SR_CECS_Msk
#define RNG_SR_SECS_Pos    (2U)
#define RNG_SR_SECS_Msk    (0x1UL << RNG_SR_SECS_Pos)	/*!< 0x00000004 */
#define RNG_SR_SECS        RNG_SR_SECS_Msk
#define RNG_SR_CEIS_Pos    (5U)
#define RNG_SR_CEIS_Msk    (0x1UL << RNG_SR_CEIS_Pos)	/*!< 0x00000020 */
#define RNG_SR_CEIS        RNG_SR_CEIS_Msk
#define RNG_SR_SEIS_Pos    (6U)
#define RNG_SR_SEIS_Msk    (0x1UL << RNG_SR_SEIS_Pos)	/*!< 0x00000040 */
#define RNG_SR_SEIS        RNG_SR_SEIS_Msk

/******************************************************************************/
/*                                                                            */
/*                           Real-Time Clock (RTC)                            */
/*                                                                            */
/******************************************************************************/
/********************  Bits definition for RTC_TR register  *******************/
#define RTC_TR_PM_Pos     (22U)
#define RTC_TR_PM_Msk     (0x1UL << RTC_TR_PM_Pos)	/*!< 0x00400000 */
#define RTC_TR_PM         RTC_TR_PM_Msk
#define RTC_TR_HT_Pos     (20U)
#define RTC_TR_HT_Msk     (0x3UL << RTC_TR_HT_Pos)	/*!< 0x00300000 */
#define RTC_TR_HT         RTC_TR_HT_Msk
#define RTC_TR_HT_0       (0x1UL << RTC_TR_HT_Pos)	/*!< 0x00100000 */
#define RTC_TR_HT_1       (0x2UL << RTC_TR_HT_Pos)	/*!< 0x00200000 */
#define RTC_TR_HU_Pos     (16U)
#define RTC_TR_HU_Msk     (0xFUL << RTC_TR_HU_Pos)	/*!< 0x000F0000 */
#define RTC_TR_HU         RTC_TR_HU_Msk
#define RTC_TR_HU_0       (0x1UL << RTC_TR_HU_Pos)	/*!< 0x00010000 */
#define RTC_TR_HU_1       (0x2UL << RTC_TR_HU_Pos)	/*!< 0x00020000 */
#define RTC_TR_HU_2       (0x4UL << RTC_TR_HU_Pos)	/*!< 0x00040000 */
#define RTC_TR_HU_3       (0x8UL << RTC_TR_HU_Pos)	/*!< 0x00080000 */
#define RTC_TR_MNT_Pos    (12U)
#define RTC_TR_MNT_Msk    (0x7UL << RTC_TR_MNT_Pos)	/*!< 0x00007000 */
#define RTC_TR_MNT        RTC_TR_MNT_Msk
#define RTC_TR_MNT_0      (0x1UL << RTC_TR_MNT_Pos)	/*!< 0x00001000 */
#define RTC_TR_MNT_1      (0x2UL << RTC_TR_MNT_Pos)	/*!< 0x00002000 */
#define RTC_TR_MNT_2      (0x4UL << RTC_TR_MNT_Pos)	/*!< 0x00004000 */
#define RTC_TR_MNU_Pos    (8U)
#define RTC_TR_MNU_Msk    (0xFUL << RTC_TR_MNU_Pos)	/*!< 0x00000F00 */
#define RTC_TR_MNU        RTC_TR_MNU_Msk
#define RTC_TR_MNU_0      (0x1UL << RTC_TR_MNU_Pos)	/*!< 0x00000100 */
#define RTC_TR_MNU_1      (0x2UL << RTC_TR_MNU_Pos)	/*!< 0x00000200 */
#define RTC_TR_MNU_2      (0x4UL << RTC_TR_MNU_Pos)	/*!< 0x00000400 */
#define RTC_TR_MNU_3      (0x8UL << RTC_TR_MNU_Pos)	/*!< 0x00000800 */
#define RTC_TR_ST_Pos     (4U)
#define RTC_TR_ST_Msk     (0x7UL << RTC_TR_ST_Pos)	/*!< 0x00000070 */
#define RTC_TR_ST         RTC_TR_ST_Msk
#define RTC_TR_ST_0       (0x1UL << RTC_TR_ST_Pos)	/*!< 0x00000010 */
#define RTC_TR_ST_1       (0x2UL << RTC_TR_ST_Pos)	/*!< 0x00000020 */
#define RTC_TR_ST_2       (0x4UL << RTC_TR_ST_Pos)	/*!< 0x00000040 */
#define RTC_TR_SU_Pos     (0U)
#define RTC_TR_SU_Msk     (0xFUL << RTC_TR_SU_Pos)	/*!< 0x0000000F */
#define RTC_TR_SU         RTC_TR_SU_Msk
#define RTC_TR_SU_0       (0x1UL << RTC_TR_SU_Pos)	/*!< 0x00000001 */
#define RTC_TR_SU_1       (0x2UL << RTC_TR_SU_Pos)	/*!< 0x00000002 */
#define RTC_TR_SU_2       (0x4UL << RTC_TR_SU_Pos)	/*!< 0x00000004 */
#define RTC_TR_SU_3       (0x8UL << RTC_TR_SU_Pos)	/*!< 0x00000008 */

/********************  Bits definition for RTC_DR register  *******************/
#define RTC_DR_YT_Pos     (20U)
#define RTC_DR_YT_Msk     (0xFUL << RTC_DR_YT_Pos)	/*!< 0x00F00000 */
#define RTC_DR_YT         RTC_DR_YT_Msk
#define RTC_DR_YT_0       (0x1UL << RTC_DR_YT_Pos)	/*!< 0x00100000 */
#define RTC_DR_YT_1       (0x2UL << RTC_DR_YT_Pos)	/*!< 0x00200000 */
#define RTC_DR_YT_2       (0x4UL << RTC_DR_YT_Pos)	/*!< 0x00400000 */
#define RTC_DR_YT_3       (0x8UL << RTC_DR_YT_Pos)	/*!< 0x00800000 */
#define RTC_DR_YU_Pos     (16U)
#define RTC_DR_YU_Msk     (0xFUL << RTC_DR_YU_Pos)	/*!< 0x000F0000 */
#define RTC_DR_YU         RTC_DR_YU_Msk
#define RTC_DR_YU_0       (0x1UL << RTC_DR_YU_Pos)	/*!< 0x00010000 */
#define RTC_DR_YU_1       (0x2UL << RTC_DR_YU_Pos)	/*!< 0x00020000 */
#define RTC_DR_YU_2       (0x4UL << RTC_DR_YU_Pos)	/*!< 0x00040000 */
#define RTC_DR_YU_3       (0x8UL << RTC_DR_YU_Pos)	/*!< 0x00080000 */
#define RTC_DR_WDU_Pos    (13U)
#define RTC_DR_WDU_Msk    (0x7UL << RTC_DR_WDU_Pos)	/*!< 0x0000E000 */
#define RTC_DR_WDU        RTC_DR_WDU_Msk
#define RTC_DR_WDU_0      (0x1UL << RTC_DR_WDU_Pos)	/*!< 0x00002000 */
#define RTC_DR_WDU_1      (0x2UL << RTC_DR_WDU_Pos)	/*!< 0x00004000 */
#define RTC_DR_WDU_2      (0x4UL << RTC_DR_WDU_Pos)	/*!< 0x00008000 */
#define RTC_DR_MT_Pos     (12U)
#define RTC_DR_MT_Msk     (0x1UL << RTC_DR_MT_Pos)	/*!< 0x00001000 */
#define RTC_DR_MT         RTC_DR_MT_Msk
#define RTC_DR_MU_Pos     (8U)
#define RTC_DR_MU_Msk     (0xFUL << RTC_DR_MU_Pos)	/*!< 0x00000F00 */
#define RTC_DR_MU         RTC_DR_MU_Msk
#define RTC_DR_MU_0       (0x1UL << RTC_DR_MU_Pos)	/*!< 0x00000100 */
#define RTC_DR_MU_1       (0x2UL << RTC_DR_MU_Pos)	/*!< 0x00000200 */
#define RTC_DR_MU_2       (0x4UL << RTC_DR_MU_Pos)	/*!< 0x00000400 */
#define RTC_DR_MU_3       (0x8UL << RTC_DR_MU_Pos)	/*!< 0x00000800 */
#define RTC_DR_DT_Pos     (4U)
#define RTC_DR_DT_Msk     (0x3UL << RTC_DR_DT_Pos)	/*!< 0x00000030 */
#define RTC_DR_DT         RTC_DR_DT_Msk
#define RTC_DR_DT_0       (0x1UL << RTC_DR_DT_Pos)	/*!< 0x00000010 */
#define RTC_DR_DT_1       (0x2UL << RTC_DR_DT_Pos)	/*!< 0x00000020 */
#define RTC_DR_DU_Pos     (0U)
#define RTC_DR_DU_Msk     (0xFUL << RTC_DR_DU_Pos)	/*!< 0x0000000F */
#define RTC_DR_DU         RTC_DR_DU_Msk
#define RTC_DR_DU_0       (0x1UL << RTC_DR_DU_Pos)	/*!< 0x00000001 */
#define RTC_DR_DU_1       (0x2UL << RTC_DR_DU_Pos)	/*!< 0x00000002 */
#define RTC_DR_DU_2       (0x4UL << RTC_DR_DU_Pos)	/*!< 0x00000004 */
#define RTC_DR_DU_3       (0x8UL << RTC_DR_DU_Pos)	/*!< 0x00000008 */

/********************  Bits definition for RTC_CR register  *******************/
#define RTC_CR_ITSE_Pos       (24U)
#define RTC_CR_ITSE_Msk       (0x1UL << RTC_CR_ITSE_Pos)/*!< 0x01000000 */
#define RTC_CR_ITSE           RTC_CR_ITSE_Msk
#define RTC_CR_COE_Pos        (23U)
#define RTC_CR_COE_Msk        (0x1UL << RTC_CR_COE_Pos)	/*!< 0x00800000 */
#define RTC_CR_COE            RTC_CR_COE_Msk
#define RTC_CR_OSEL_Pos       (21U)
#define RTC_CR_OSEL_Msk       (0x3UL << RTC_CR_OSEL_Pos)/*!< 0x00600000 */
#define RTC_CR_OSEL           RTC_CR_OSEL_Msk
#define RTC_CR_OSEL_0         (0x1UL << RTC_CR_OSEL_Pos)/*!< 0x00200000 */
#define RTC_CR_OSEL_1         (0x2UL << RTC_CR_OSEL_Pos)/*!< 0x00400000 */
#define RTC_CR_POL_Pos        (20U)
#define RTC_CR_POL_Msk        (0x1UL << RTC_CR_POL_Pos)	/*!< 0x00100000 */
#define RTC_CR_POL            RTC_CR_POL_Msk
#define RTC_CR_COSEL_Pos      (19U)
#define RTC_CR_COSEL_Msk      (0x1UL << RTC_CR_COSEL_Pos)	/*!< 0x00080000 */
#define RTC_CR_COSEL          RTC_CR_COSEL_Msk
#define RTC_CR_BKP_Pos        (18U)
#define RTC_CR_BKP_Msk        (0x1UL << RTC_CR_BKP_Pos)	/*!< 0x00040000 */
#define RTC_CR_BKP            RTC_CR_BKP_Msk
#define RTC_CR_SUB1H_Pos      (17U)
#define RTC_CR_SUB1H_Msk      (0x1UL << RTC_CR_SUB1H_Pos)	/*!< 0x00020000 */
#define RTC_CR_SUB1H          RTC_CR_SUB1H_Msk
#define RTC_CR_ADD1H_Pos      (16U)
#define RTC_CR_ADD1H_Msk      (0x1UL << RTC_CR_ADD1H_Pos)	/*!< 0x00010000 */
#define RTC_CR_ADD1H          RTC_CR_ADD1H_Msk
#define RTC_CR_TSIE_Pos       (15U)
#define RTC_CR_TSIE_Msk       (0x1UL << RTC_CR_TSIE_Pos)/*!< 0x00008000 */
#define RTC_CR_TSIE           RTC_CR_TSIE_Msk
#define RTC_CR_WUTIE_Pos      (14U)
#define RTC_CR_WUTIE_Msk      (0x1UL << RTC_CR_WUTIE_Pos)	/*!< 0x00004000 */
#define RTC_CR_WUTIE          RTC_CR_WUTIE_Msk
#define RTC_CR_ALRBIE_Pos     (13U)
#define RTC_CR_ALRBIE_Msk     (0x1UL << RTC_CR_ALRBIE_Pos)	/*!< 0x00002000 */
#define RTC_CR_ALRBIE         RTC_CR_ALRBIE_Msk
#define RTC_CR_ALRAIE_Pos     (12U)
#define RTC_CR_ALRAIE_Msk     (0x1UL << RTC_CR_ALRAIE_Pos)	/*!< 0x00001000 */
#define RTC_CR_ALRAIE         RTC_CR_ALRAIE_Msk
#define RTC_CR_TSE_Pos        (11U)
#define RTC_CR_TSE_Msk        (0x1UL << RTC_CR_TSE_Pos)	/*!< 0x00000800 */
#define RTC_CR_TSE            RTC_CR_TSE_Msk
#define RTC_CR_WUTE_Pos       (10U)
#define RTC_CR_WUTE_Msk       (0x1UL << RTC_CR_WUTE_Pos)/*!< 0x00000400 */
#define RTC_CR_WUTE           RTC_CR_WUTE_Msk
#define RTC_CR_ALRBE_Pos      (9U)
#define RTC_CR_ALRBE_Msk      (0x1UL << RTC_CR_ALRBE_Pos)	/*!< 0x00000200 */
#define RTC_CR_ALRBE          RTC_CR_ALRBE_Msk
#define RTC_CR_ALRAE_Pos      (8U)
#define RTC_CR_ALRAE_Msk      (0x1UL << RTC_CR_ALRAE_Pos)	/*!< 0x00000100 */
#define RTC_CR_ALRAE          RTC_CR_ALRAE_Msk
#define RTC_CR_FMT_Pos        (6U)
#define RTC_CR_FMT_Msk        (0x1UL << RTC_CR_FMT_Pos)	/*!< 0x00000040 */
#define RTC_CR_FMT            RTC_CR_FMT_Msk
#define RTC_CR_BYPSHAD_Pos    (5U)
#define RTC_CR_BYPSHAD_Msk    (0x1UL << RTC_CR_BYPSHAD_Pos)	/*!< 0x00000020 */
#define RTC_CR_BYPSHAD        RTC_CR_BYPSHAD_Msk
#define RTC_CR_REFCKON_Pos    (4U)
#define RTC_CR_REFCKON_Msk    (0x1UL << RTC_CR_REFCKON_Pos)	/*!< 0x00000010 */
#define RTC_CR_REFCKON        RTC_CR_REFCKON_Msk
#define RTC_CR_TSEDGE_Pos     (3U)
#define RTC_CR_TSEDGE_Msk     (0x1UL << RTC_CR_TSEDGE_Pos)	/*!< 0x00000008 */
#define RTC_CR_TSEDGE         RTC_CR_TSEDGE_Msk
#define RTC_CR_WUCKSEL_Pos    (0U)
#define RTC_CR_WUCKSEL_Msk    (0x7UL << RTC_CR_WUCKSEL_Pos)	/*!< 0x00000007 */
#define RTC_CR_WUCKSEL        RTC_CR_WUCKSEL_Msk
#define RTC_CR_WUCKSEL_0      (0x1UL << RTC_CR_WUCKSEL_Pos)	/*!< 0x00000001 */
#define RTC_CR_WUCKSEL_1      (0x2UL << RTC_CR_WUCKSEL_Pos)	/*!< 0x00000002 */
#define RTC_CR_WUCKSEL_2      (0x4UL << RTC_CR_WUCKSEL_Pos)	/*!< 0x00000004 */

/* Legacy define */
#define RTC_CR_BCK    RTC_CR_BKP

/********************  Bits definition for RTC_ISR register  ******************/
#define RTC_ISR_ITSF_Pos       (17U)
#define RTC_ISR_ITSF_Msk       (0x1UL << RTC_ISR_ITSF_Pos)	/*!< 0x00020000 */
#define RTC_ISR_ITSF           RTC_ISR_ITSF_Msk
#define RTC_ISR_RECALPF_Pos    (16U)
#define RTC_ISR_RECALPF_Msk    (0x1UL << RTC_ISR_RECALPF_Pos)	/*!< 0x00010000 */
#define RTC_ISR_RECALPF        RTC_ISR_RECALPF_Msk
#define RTC_ISR_TAMP3F_Pos     (15U)
#define RTC_ISR_TAMP3F_Msk     (0x1UL << RTC_ISR_TAMP3F_Pos)/*!< 0x00008000 */
#define RTC_ISR_TAMP3F         RTC_ISR_TAMP3F_Msk
#define RTC_ISR_TAMP2F_Pos     (14U)
#define RTC_ISR_TAMP2F_Msk     (0x1UL << RTC_ISR_TAMP2F_Pos)/*!< 0x00004000 */
#define RTC_ISR_TAMP2F         RTC_ISR_TAMP2F_Msk
#define RTC_ISR_TAMP1F_Pos     (13U)
#define RTC_ISR_TAMP1F_Msk     (0x1UL << RTC_ISR_TAMP1F_Pos)/*!< 0x00002000 */
#define RTC_ISR_TAMP1F         RTC_ISR_TAMP1F_Msk
#define RTC_ISR_TSOVF_Pos      (12U)
#define RTC_ISR_TSOVF_Msk      (0x1UL << RTC_ISR_TSOVF_Pos)	/*!< 0x00001000 */
#define RTC_ISR_TSOVF          RTC_ISR_TSOVF_Msk
#define RTC_ISR_TSF_Pos        (11U)
#define RTC_ISR_TSF_Msk        (0x1UL << RTC_ISR_TSF_Pos)	/*!< 0x00000800 */
#define RTC_ISR_TSF            RTC_ISR_TSF_Msk
#define RTC_ISR_WUTF_Pos       (10U)
#define RTC_ISR_WUTF_Msk       (0x1UL << RTC_ISR_WUTF_Pos)	/*!< 0x00000400 */
#define RTC_ISR_WUTF           RTC_ISR_WUTF_Msk
#define RTC_ISR_ALRBF_Pos      (9U)
#define RTC_ISR_ALRBF_Msk      (0x1UL << RTC_ISR_ALRBF_Pos)	/*!< 0x00000200 */
#define RTC_ISR_ALRBF          RTC_ISR_ALRBF_Msk
#define RTC_ISR_ALRAF_Pos      (8U)
#define RTC_ISR_ALRAF_Msk      (0x1UL << RTC_ISR_ALRAF_Pos)	/*!< 0x00000100 */
#define RTC_ISR_ALRAF          RTC_ISR_ALRAF_Msk
#define RTC_ISR_INIT_Pos       (7U)
#define RTC_ISR_INIT_Msk       (0x1UL << RTC_ISR_INIT_Pos)	/*!< 0x00000080 */
#define RTC_ISR_INIT           RTC_ISR_INIT_Msk
#define RTC_ISR_INITF_Pos      (6U)
#define RTC_ISR_INITF_Msk      (0x1UL << RTC_ISR_INITF_Pos)	/*!< 0x00000040 */
#define RTC_ISR_INITF          RTC_ISR_INITF_Msk
#define RTC_ISR_RSF_Pos        (5U)
#define RTC_ISR_RSF_Msk        (0x1UL << RTC_ISR_RSF_Pos)	/*!< 0x00000020 */
#define RTC_ISR_RSF            RTC_ISR_RSF_Msk
#define RTC_ISR_INITS_Pos      (4U)
#define RTC_ISR_INITS_Msk      (0x1UL << RTC_ISR_INITS_Pos)	/*!< 0x00000010 */
#define RTC_ISR_INITS          RTC_ISR_INITS_Msk
#define RTC_ISR_SHPF_Pos       (3U)
#define RTC_ISR_SHPF_Msk       (0x1UL << RTC_ISR_SHPF_Pos)	/*!< 0x00000008 */
#define RTC_ISR_SHPF           RTC_ISR_SHPF_Msk
#define RTC_ISR_WUTWF_Pos      (2U)
#define RTC_ISR_WUTWF_Msk      (0x1UL << RTC_ISR_WUTWF_Pos)	/*!< 0x00000004 */
#define RTC_ISR_WUTWF          RTC_ISR_WUTWF_Msk
#define RTC_ISR_ALRBWF_Pos     (1U)
#define RTC_ISR_ALRBWF_Msk     (0x1UL << RTC_ISR_ALRBWF_Pos)/*!< 0x00000002 */
#define RTC_ISR_ALRBWF         RTC_ISR_ALRBWF_Msk
#define RTC_ISR_ALRAWF_Pos     (0U)
#define RTC_ISR_ALRAWF_Msk     (0x1UL << RTC_ISR_ALRAWF_Pos)/*!< 0x00000001 */
#define RTC_ISR_ALRAWF         RTC_ISR_ALRAWF_Msk

/********************  Bits definition for RTC_PRER register  *****************/
#define RTC_PRER_PREDIV_A_Pos    (16U)
#define RTC_PRER_PREDIV_A_Msk    (0x7FUL << RTC_PRER_PREDIV_A_Pos)	/*!< 0x007F0000 */
#define RTC_PRER_PREDIV_A        RTC_PRER_PREDIV_A_Msk
#define RTC_PRER_PREDIV_S_Pos    (0U)
#define RTC_PRER_PREDIV_S_Msk    (0x7FFFUL << RTC_PRER_PREDIV_S_Pos)/*!< 0x00007FFF */
#define RTC_PRER_PREDIV_S        RTC_PRER_PREDIV_S_Msk

/********************  Bits definition for RTC_WUTR register  *****************/
#define RTC_WUTR_WUT_Pos    (0U)
#define RTC_WUTR_WUT_Msk    (0xFFFFUL << RTC_WUTR_WUT_Pos)	/*!< 0x0000FFFF */
#define RTC_WUTR_WUT        RTC_WUTR_WUT_Msk

/********************  Bits definition for RTC_ALRMAR register  ***************/
#define RTC_ALRMAR_MSK4_Pos     (31U)
#define RTC_ALRMAR_MSK4_Msk     (0x1UL << RTC_ALRMAR_MSK4_Pos)	/*!< 0x80000000 */
#define RTC_ALRMAR_MSK4         RTC_ALRMAR_MSK4_Msk
#define RTC_ALRMAR_WDSEL_Pos    (30U)
#define RTC_ALRMAR_WDSEL_Msk    (0x1UL << RTC_ALRMAR_WDSEL_Pos)	/*!< 0x40000000 */
#define RTC_ALRMAR_WDSEL        RTC_ALRMAR_WDSEL_Msk
#define RTC_ALRMAR_DT_Pos       (28U)
#define RTC_ALRMAR_DT_Msk       (0x3UL << RTC_ALRMAR_DT_Pos)/*!< 0x30000000 */
#define RTC_ALRMAR_DT           RTC_ALRMAR_DT_Msk
#define RTC_ALRMAR_DT_0         (0x1UL << RTC_ALRMAR_DT_Pos)/*!< 0x10000000 */
#define RTC_ALRMAR_DT_1         (0x2UL << RTC_ALRMAR_DT_Pos)/*!< 0x20000000 */
#define RTC_ALRMAR_DU_Pos       (24U)
#define RTC_ALRMAR_DU_Msk       (0xFUL << RTC_ALRMAR_DU_Pos)/*!< 0x0F000000 */
#define RTC_ALRMAR_DU           RTC_ALRMAR_DU_Msk
#define RTC_ALRMAR_DU_0         (0x1UL << RTC_ALRMAR_DU_Pos)/*!< 0x01000000 */
#define RTC_ALRMAR_DU_1         (0x2UL << RTC_ALRMAR_DU_Pos)/*!< 0x02000000 */
#define RTC_ALRMAR_DU_2         (0x4UL << RTC_ALRMAR_DU_Pos)/*!< 0x04000000 */
#define RTC_ALRMAR_DU_3         (0x8UL << RTC_ALRMAR_DU_Pos)/*!< 0x08000000 */
#define RTC_ALRMAR_MSK3_Pos     (23U)
#define RTC_ALRMAR_MSK3_Msk     (0x1UL << RTC_ALRMAR_MSK3_Pos)	/*!< 0x00800000 */
#define RTC_ALRMAR_MSK3         RTC_ALRMAR_MSK3_Msk
#define RTC_ALRMAR_PM_Pos       (22U)
#define RTC_ALRMAR_PM_Msk       (0x1UL << RTC_ALRMAR_PM_Pos)/*!< 0x00400000 */
#define RTC_ALRMAR_PM           RTC_ALRMAR_PM_Msk
#define RTC_ALRMAR_HT_Pos       (20U)
#define RTC_ALRMAR_HT_Msk       (0x3UL << RTC_ALRMAR_HT_Pos)/*!< 0x00300000 */
#define RTC_ALRMAR_HT           RTC_ALRMAR_HT_Msk
#define RTC_ALRMAR_HT_0         (0x1UL << RTC_ALRMAR_HT_Pos)/*!< 0x00100000 */
#define RTC_ALRMAR_HT_1         (0x2UL << RTC_ALRMAR_HT_Pos)/*!< 0x00200000 */
#define RTC_ALRMAR_HU_Pos       (16U)
#define RTC_ALRMAR_HU_Msk       (0xFUL << RTC_ALRMAR_HU_Pos)/*!< 0x000F0000 */
#define RTC_ALRMAR_HU           RTC_ALRMAR_HU_Msk
#define RTC_ALRMAR_HU_0         (0x1UL << RTC_ALRMAR_HU_Pos)/*!< 0x00010000 */
#define RTC_ALRMAR_HU_1         (0x2UL << RTC_ALRMAR_HU_Pos)/*!< 0x00020000 */
#define RTC_ALRMAR_HU_2         (0x4UL << RTC_ALRMAR_HU_Pos)/*!< 0x00040000 */
#define RTC_ALRMAR_HU_3         (0x8UL << RTC_ALRMAR_HU_Pos)/*!< 0x00080000 */
#define RTC_ALRMAR_MSK2_Pos     (15U)
#define RTC_ALRMAR_MSK2_Msk     (0x1UL << RTC_ALRMAR_MSK2_Pos)	/*!< 0x00008000 */
#define RTC_ALRMAR_MSK2         RTC_ALRMAR_MSK2_Msk
#define RTC_ALRMAR_MNT_Pos      (12U)
#define RTC_ALRMAR_MNT_Msk      (0x7UL << RTC_ALRMAR_MNT_Pos)	/*!< 0x00007000 */
#define RTC_ALRMAR_MNT          RTC_ALRMAR_MNT_Msk
#define RTC_ALRMAR_MNT_0        (0x1UL << RTC_ALRMAR_MNT_Pos)	/*!< 0x00001000 */
#define RTC_ALRMAR_MNT_1        (0x2UL << RTC_ALRMAR_MNT_Pos)	/*!< 0x00002000 */
#define RTC_ALRMAR_MNT_2        (0x4UL << RTC_ALRMAR_MNT_Pos)	/*!< 0x00004000 */
#define RTC_ALRMAR_MNU_Pos      (8U)
#define RTC_ALRMAR_MNU_Msk      (0xFUL << RTC_ALRMAR_MNU_Pos)	/*!< 0x00000F00 */
#define RTC_ALRMAR_MNU          RTC_ALRMAR_MNU_Msk
#define RTC_ALRMAR_MNU_0        (0x1UL << RTC_ALRMAR_MNU_Pos)	/*!< 0x00000100 */
#define RTC_ALRMAR_MNU_1        (0x2UL << RTC_ALRMAR_MNU_Pos)	/*!< 0x00000200 */
#define RTC_ALRMAR_MNU_2        (0x4UL << RTC_ALRMAR_MNU_Pos)	/*!< 0x00000400 */
#define RTC_ALRMAR_MNU_3        (0x8UL << RTC_ALRMAR_MNU_Pos)	/*!< 0x00000800 */
#define RTC_ALRMAR_MSK1_Pos     (7U)
#define RTC_ALRMAR_MSK1_Msk     (0x1UL << RTC_ALRMAR_MSK1_Pos)	/*!< 0x00000080 */
#define RTC_ALRMAR_MSK1         RTC_ALRMAR_MSK1_Msk
#define RTC_ALRMAR_ST_Pos       (4U)
#define RTC_ALRMAR_ST_Msk       (0x7UL << RTC_ALRMAR_ST_Pos)/*!< 0x00000070 */
#define RTC_ALRMAR_ST           RTC_ALRMAR_ST_Msk
#define RTC_ALRMAR_ST_0         (0x1UL << RTC_ALRMAR_ST_Pos)/*!< 0x00000010 */
#define RTC_ALRMAR_ST_1         (0x2UL << RTC_ALRMAR_ST_Pos)/*!< 0x00000020 */
#define RTC_ALRMAR_ST_2         (0x4UL << RTC_ALRMAR_ST_Pos)/*!< 0x00000040 */
#define RTC_ALRMAR_SU_Pos       (0U)
#define RTC_ALRMAR_SU_Msk       (0xFUL << RTC_ALRMAR_SU_Pos)/*!< 0x0000000F */
#define RTC_ALRMAR_SU           RTC_ALRMAR_SU_Msk
#define RTC_ALRMAR_SU_0         (0x1UL << RTC_ALRMAR_SU_Pos)/*!< 0x00000001 */
#define RTC_ALRMAR_SU_1         (0x2UL << RTC_ALRMAR_SU_Pos)/*!< 0x00000002 */
#define RTC_ALRMAR_SU_2         (0x4UL << RTC_ALRMAR_SU_Pos)/*!< 0x00000004 */
#define RTC_ALRMAR_SU_3         (0x8UL << RTC_ALRMAR_SU_Pos)/*!< 0x00000008 */

/********************  Bits definition for RTC_ALRMBR register  ***************/
#define RTC_ALRMBR_MSK4_Pos     (31U)
#define RTC_ALRMBR_MSK4_Msk     (0x1UL << RTC_ALRMBR_MSK4_Pos)	/*!< 0x80000000 */
#define RTC_ALRMBR_MSK4         RTC_ALRMBR_MSK4_Msk
#define RTC_ALRMBR_WDSEL_Pos    (30U)
#define RTC_ALRMBR_WDSEL_Msk    (0x1UL << RTC_ALRMBR_WDSEL_Pos)	/*!< 0x40000000 */
#define RTC_ALRMBR_WDSEL        RTC_ALRMBR_WDSEL_Msk
#define RTC_ALRMBR_DT_Pos       (28U)
#define RTC_ALRMBR_DT_Msk       (0x3UL << RTC_ALRMBR_DT_Pos)/*!< 0x30000000 */
#define RTC_ALRMBR_DT           RTC_ALRMBR_DT_Msk
#define RTC_ALRMBR_DT_0         (0x1UL << RTC_ALRMBR_DT_Pos)/*!< 0x10000000 */
#define RTC_ALRMBR_DT_1         (0x2UL << RTC_ALRMBR_DT_Pos)/*!< 0x20000000 */
#define RTC_ALRMBR_DU_Pos       (24U)
#define RTC_ALRMBR_DU_Msk       (0xFUL << RTC_ALRMBR_DU_Pos)/*!< 0x0F000000 */
#define RTC_ALRMBR_DU           RTC_ALRMBR_DU_Msk
#define RTC_ALRMBR_DU_0         (0x1UL << RTC_ALRMBR_DU_Pos)/*!< 0x01000000 */
#define RTC_ALRMBR_DU_1         (0x2UL << RTC_ALRMBR_DU_Pos)/*!< 0x02000000 */
#define RTC_ALRMBR_DU_2         (0x4UL << RTC_ALRMBR_DU_Pos)/*!< 0x04000000 */
#define RTC_ALRMBR_DU_3         (0x8UL << RTC_ALRMBR_DU_Pos)/*!< 0x08000000 */
#define RTC_ALRMBR_MSK3_Pos     (23U)
#define RTC_ALRMBR_MSK3_Msk     (0x1UL << RTC_ALRMBR_MSK3_Pos)	/*!< 0x00800000 */
#define RTC_ALRMBR_MSK3         RTC_ALRMBR_MSK3_Msk
#define RTC_ALRMBR_PM_Pos       (22U)
#define RTC_ALRMBR_PM_Msk       (0x1UL << RTC_ALRMBR_PM_Pos)/*!< 0x00400000 */
#define RTC_ALRMBR_PM           RTC_ALRMBR_PM_Msk
#define RTC_ALRMBR_HT_Pos       (20U)
#define RTC_ALRMBR_HT_Msk       (0x3UL << RTC_ALRMBR_HT_Pos)/*!< 0x00300000 */
#define RTC_ALRMBR_HT           RTC_ALRMBR_HT_Msk
#define RTC_ALRMBR_HT_0         (0x1UL << RTC_ALRMBR_HT_Pos)/*!< 0x00100000 */
#define RTC_ALRMBR_HT_1         (0x2UL << RTC_ALRMBR_HT_Pos)/*!< 0x00200000 */
#define RTC_ALRMBR_HU_Pos       (16U)
#define RTC_ALRMBR_HU_Msk       (0xFUL << RTC_ALRMBR_HU_Pos)/*!< 0x000F0000 */
#define RTC_ALRMBR_HU           RTC_ALRMBR_HU_Msk
#define RTC_ALRMBR_HU_0         (0x1UL << RTC_ALRMBR_HU_Pos)/*!< 0x00010000 */
#define RTC_ALRMBR_HU_1         (0x2UL << RTC_ALRMBR_HU_Pos)/*!< 0x00020000 */
#define RTC_ALRMBR_HU_2         (0x4UL << RTC_ALRMBR_HU_Pos)/*!< 0x00040000 */
#define RTC_ALRMBR_HU_3         (0x8UL << RTC_ALRMBR_HU_Pos)/*!< 0x00080000 */
#define RTC_ALRMBR_MSK2_Pos     (15U)
#define RTC_ALRMBR_MSK2_Msk     (0x1UL << RTC_ALRMBR_MSK2_Pos)	/*!< 0x00008000 */
#define RTC_ALRMBR_MSK2         RTC_ALRMBR_MSK2_Msk
#define RTC_ALRMBR_MNT_Pos      (12U)
#define RTC_ALRMBR_MNT_Msk      (0x7UL << RTC_ALRMBR_MNT_Pos)	/*!< 0x00007000 */
#define RTC_ALRMBR_MNT          RTC_ALRMBR_MNT_Msk
#define RTC_ALRMBR_MNT_0        (0x1UL << RTC_ALRMBR_MNT_Pos)	/*!< 0x00001000 */
#define RTC_ALRMBR_MNT_1        (0x2UL << RTC_ALRMBR_MNT_Pos)	/*!< 0x00002000 */
#define RTC_ALRMBR_MNT_2        (0x4UL << RTC_ALRMBR_MNT_Pos)	/*!< 0x00004000 */
#define RTC_ALRMBR_MNU_Pos      (8U)
#define RTC_ALRMBR_MNU_Msk      (0xFUL << RTC_ALRMBR_MNU_Pos)	/*!< 0x00000F00 */
#define RTC_ALRMBR_MNU          RTC_ALRMBR_MNU_Msk
#define RTC_ALRMBR_MNU_0        (0x1UL << RTC_ALRMBR_MNU_Pos)	/*!< 0x00000100 */
#define RTC_ALRMBR_MNU_1        (0x2UL << RTC_ALRMBR_MNU_Pos)	/*!< 0x00000200 */
#define RTC_ALRMBR_MNU_2        (0x4UL << RTC_ALRMBR_MNU_Pos)	/*!< 0x00000400 */
#define RTC_ALRMBR_MNU_3        (0x8UL << RTC_ALRMBR_MNU_Pos)	/*!< 0x00000800 */
#define RTC_ALRMBR_MSK1_Pos     (7U)
#define RTC_ALRMBR_MSK1_Msk     (0x1UL << RTC_ALRMBR_MSK1_Pos)	/*!< 0x00000080 */
#define RTC_ALRMBR_MSK1         RTC_ALRMBR_MSK1_Msk
#define RTC_ALRMBR_ST_Pos       (4U)
#define RTC_ALRMBR_ST_Msk       (0x7UL << RTC_ALRMBR_ST_Pos)/*!< 0x00000070 */
#define RTC_ALRMBR_ST           RTC_ALRMBR_ST_Msk
#define RTC_ALRMBR_ST_0         (0x1UL << RTC_ALRMBR_ST_Pos)/*!< 0x00000010 */
#define RTC_ALRMBR_ST_1         (0x2UL << RTC_ALRMBR_ST_Pos)/*!< 0x00000020 */
#define RTC_ALRMBR_ST_2         (0x4UL << RTC_ALRMBR_ST_Pos)/*!< 0x00000040 */
#define RTC_ALRMBR_SU_Pos       (0U)
#define RTC_ALRMBR_SU_Msk       (0xFUL << RTC_ALRMBR_SU_Pos)/*!< 0x0000000F */
#define RTC_ALRMBR_SU           RTC_ALRMBR_SU_Msk
#define RTC_ALRMBR_SU_0         (0x1UL << RTC_ALRMBR_SU_Pos)/*!< 0x00000001 */
#define RTC_ALRMBR_SU_1         (0x2UL << RTC_ALRMBR_SU_Pos)/*!< 0x00000002 */
#define RTC_ALRMBR_SU_2         (0x4UL << RTC_ALRMBR_SU_Pos)/*!< 0x00000004 */
#define RTC_ALRMBR_SU_3         (0x8UL << RTC_ALRMBR_SU_Pos)/*!< 0x00000008 */

/********************  Bits definition for RTC_WPR register  ******************/
#define RTC_WPR_KEY_Pos    (0U)
#define RTC_WPR_KEY_Msk    (0xFFUL << RTC_WPR_KEY_Pos)	/*!< 0x000000FF */
#define RTC_WPR_KEY        RTC_WPR_KEY_Msk

/********************  Bits definition for RTC_SSR register  ******************/
#define RTC_SSR_SS_Pos    (0U)
#define RTC_SSR_SS_Msk    (0xFFFFUL << RTC_SSR_SS_Pos)	/*!< 0x0000FFFF */
#define RTC_SSR_SS        RTC_SSR_SS_Msk

/********************  Bits definition for RTC_SHIFTR register  ***************/
#define RTC_SHIFTR_SUBFS_Pos    (0U)
#define RTC_SHIFTR_SUBFS_Msk    (0x7FFFUL << RTC_SHIFTR_SUBFS_Pos)	/*!< 0x00007FFF */
#define RTC_SHIFTR_SUBFS        RTC_SHIFTR_SUBFS_Msk
#define RTC_SHIFTR_ADD1S_Pos    (31U)
#define RTC_SHIFTR_ADD1S_Msk    (0x1UL << RTC_SHIFTR_ADD1S_Pos)	/*!< 0x80000000 */
#define RTC_SHIFTR_ADD1S        RTC_SHIFTR_ADD1S_Msk

/********************  Bits definition for RTC_TSTR register  *****************/
#define RTC_TSTR_PM_Pos     (22U)
#define RTC_TSTR_PM_Msk     (0x1UL << RTC_TSTR_PM_Pos)	/*!< 0x00400000 */
#define RTC_TSTR_PM         RTC_TSTR_PM_Msk
#define RTC_TSTR_HT_Pos     (20U)
#define RTC_TSTR_HT_Msk     (0x3UL << RTC_TSTR_HT_Pos)	/*!< 0x00300000 */
#define RTC_TSTR_HT         RTC_TSTR_HT_Msk
#define RTC_TSTR_HT_0       (0x1UL << RTC_TSTR_HT_Pos)	/*!< 0x00100000 */
#define RTC_TSTR_HT_1       (0x2UL << RTC_TSTR_HT_Pos)	/*!< 0x00200000 */
#define RTC_TSTR_HU_Pos     (16U)
#define RTC_TSTR_HU_Msk     (0xFUL << RTC_TSTR_HU_Pos)	/*!< 0x000F0000 */
#define RTC_TSTR_HU         RTC_TSTR_HU_Msk
#define RTC_TSTR_HU_0       (0x1UL << RTC_TSTR_HU_Pos)	/*!< 0x00010000 */
#define RTC_TSTR_HU_1       (0x2UL << RTC_TSTR_HU_Pos)	/*!< 0x00020000 */
#define RTC_TSTR_HU_2       (0x4UL << RTC_TSTR_HU_Pos)	/*!< 0x00040000 */
#define RTC_TSTR_HU_3       (0x8UL << RTC_TSTR_HU_Pos)	/*!< 0x00080000 */
#define RTC_TSTR_MNT_Pos    (12U)
#define RTC_TSTR_MNT_Msk    (0x7UL << RTC_TSTR_MNT_Pos)	/*!< 0x00007000 */
#define RTC_TSTR_MNT        RTC_TSTR_MNT_Msk
#define RTC_TSTR_MNT_0      (0x1UL << RTC_TSTR_MNT_Pos)	/*!< 0x00001000 */
#define RTC_TSTR_MNT_1      (0x2UL << RTC_TSTR_MNT_Pos)	/*!< 0x00002000 */
#define RTC_TSTR_MNT_2      (0x4UL << RTC_TSTR_MNT_Pos)	/*!< 0x00004000 */
#define RTC_TSTR_MNU_Pos    (8U)
#define RTC_TSTR_MNU_Msk    (0xFUL << RTC_TSTR_MNU_Pos)	/*!< 0x00000F00 */
#define RTC_TSTR_MNU        RTC_TSTR_MNU_Msk
#define RTC_TSTR_MNU_0      (0x1UL << RTC_TSTR_MNU_Pos)	/*!< 0x00000100 */
#define RTC_TSTR_MNU_1      (0x2UL << RTC_TSTR_MNU_Pos)	/*!< 0x00000200 */
#define RTC_TSTR_MNU_2      (0x4UL << RTC_TSTR_MNU_Pos)	/*!< 0x00000400 */
#define RTC_TSTR_MNU_3      (0x8UL << RTC_TSTR_MNU_Pos)	/*!< 0x00000800 */
#define RTC_TSTR_ST_Pos     (4U)
#define RTC_TSTR_ST_Msk     (0x7UL << RTC_TSTR_ST_Pos)	/*!< 0x00000070 */
#define RTC_TSTR_ST         RTC_TSTR_ST_Msk
#define RTC_TSTR_ST_0       (0x1UL << RTC_TSTR_ST_Pos)	/*!< 0x00000010 */
#define RTC_TSTR_ST_1       (0x2UL << RTC_TSTR_ST_Pos)	/*!< 0x00000020 */
#define RTC_TSTR_ST_2       (0x4UL << RTC_TSTR_ST_Pos)	/*!< 0x00000040 */
#define RTC_TSTR_SU_Pos     (0U)
#define RTC_TSTR_SU_Msk     (0xFUL << RTC_TSTR_SU_Pos)	/*!< 0x0000000F */
#define RTC_TSTR_SU         RTC_TSTR_SU_Msk
#define RTC_TSTR_SU_0       (0x1UL << RTC_TSTR_SU_Pos)	/*!< 0x00000001 */
#define RTC_TSTR_SU_1       (0x2UL << RTC_TSTR_SU_Pos)	/*!< 0x00000002 */
#define RTC_TSTR_SU_2       (0x4UL << RTC_TSTR_SU_Pos)	/*!< 0x00000004 */
#define RTC_TSTR_SU_3       (0x8UL << RTC_TSTR_SU_Pos)	/*!< 0x00000008 */

/********************  Bits definition for RTC_TSDR register  *****************/
#define RTC_TSDR_WDU_Pos    (13U)
#define RTC_TSDR_WDU_Msk    (0x7UL << RTC_TSDR_WDU_Pos)	/*!< 0x0000E000 */
#define RTC_TSDR_WDU        RTC_TSDR_WDU_Msk
#define RTC_TSDR_WDU_0      (0x1UL << RTC_TSDR_WDU_Pos)	/*!< 0x00002000 */
#define RTC_TSDR_WDU_1      (0x2UL << RTC_TSDR_WDU_Pos)	/*!< 0x00004000 */
#define RTC_TSDR_WDU_2      (0x4UL << RTC_TSDR_WDU_Pos)	/*!< 0x00008000 */
#define RTC_TSDR_MT_Pos     (12U)
#define RTC_TSDR_MT_Msk     (0x1UL << RTC_TSDR_MT_Pos)	/*!< 0x00001000 */
#define RTC_TSDR_MT         RTC_TSDR_MT_Msk
#define RTC_TSDR_MU_Pos     (8U)
#define RTC_TSDR_MU_Msk     (0xFUL << RTC_TSDR_MU_Pos)	/*!< 0x00000F00 */
#define RTC_TSDR_MU         RTC_TSDR_MU_Msk
#define RTC_TSDR_MU_0       (0x1UL << RTC_TSDR_MU_Pos)	/*!< 0x00000100 */
#define RTC_TSDR_MU_1       (0x2UL << RTC_TSDR_MU_Pos)	/*!< 0x00000200 */
#define RTC_TSDR_MU_2       (0x4UL << RTC_TSDR_MU_Pos)	/*!< 0x00000400 */
#define RTC_TSDR_MU_3       (0x8UL << RTC_TSDR_MU_Pos)	/*!< 0x00000800 */
#define RTC_TSDR_DT_Pos     (4U)
#define RTC_TSDR_DT_Msk     (0x3UL << RTC_TSDR_DT_Pos)	/*!< 0x00000030 */
#define RTC_TSDR_DT         RTC_TSDR_DT_Msk
#define RTC_TSDR_DT_0       (0x1UL << RTC_TSDR_DT_Pos)	/*!< 0x00000010 */
#define RTC_TSDR_DT_1       (0x2UL << RTC_TSDR_DT_Pos)	/*!< 0x00000020 */
#define RTC_TSDR_DU_Pos     (0U)
#define RTC_TSDR_DU_Msk     (0xFUL << RTC_TSDR_DU_Pos)	/*!< 0x0000000F */
#define RTC_TSDR_DU         RTC_TSDR_DU_Msk
#define RTC_TSDR_DU_0       (0x1UL << RTC_TSDR_DU_Pos)	/*!< 0x00000001 */
#define RTC_TSDR_DU_1       (0x2UL << RTC_TSDR_DU_Pos)	/*!< 0x00000002 */
#define RTC_TSDR_DU_2       (0x4UL << RTC_TSDR_DU_Pos)	/*!< 0x00000004 */
#define RTC_TSDR_DU_3       (0x8UL << RTC_TSDR_DU_Pos)	/*!< 0x00000008 */

/********************  Bits definition for RTC_TSSSR register  ****************/
#define RTC_TSSSR_SS_Pos    (0U)
#define RTC_TSSSR_SS_Msk    (0xFFFFUL << RTC_TSSSR_SS_Pos)	/*!< 0x0000FFFF */
#define RTC_TSSSR_SS        RTC_TSSSR_SS_Msk

/********************  Bits definition for RTC_CAL register  *****************/
#define RTC_CALR_CALP_Pos      (15U)
#define RTC_CALR_CALP_Msk      (0x1UL << RTC_CALR_CALP_Pos)	/*!< 0x00008000 */
#define RTC_CALR_CALP          RTC_CALR_CALP_Msk
#define RTC_CALR_CALW8_Pos     (14U)
#define RTC_CALR_CALW8_Msk     (0x1UL << RTC_CALR_CALW8_Pos)/*!< 0x00004000 */
#define RTC_CALR_CALW8         RTC_CALR_CALW8_Msk
#define RTC_CALR_CALW16_Pos    (13U)
#define RTC_CALR_CALW16_Msk    (0x1UL << RTC_CALR_CALW16_Pos)	/*!< 0x00002000 */
#define RTC_CALR_CALW16        RTC_CALR_CALW16_Msk
#define RTC_CALR_CALM_Pos      (0U)
#define RTC_CALR_CALM_Msk      (0x1FFUL << RTC_CALR_CALM_Pos)	/*!< 0x000001FF */
#define RTC_CALR_CALM          RTC_CALR_CALM_Msk
#define RTC_CALR_CALM_0        (0x001UL << RTC_CALR_CALM_Pos)	/*!< 0x00000001 */
#define RTC_CALR_CALM_1        (0x002UL << RTC_CALR_CALM_Pos)	/*!< 0x00000002 */
#define RTC_CALR_CALM_2        (0x004UL << RTC_CALR_CALM_Pos)	/*!< 0x00000004 */
#define RTC_CALR_CALM_3        (0x008UL << RTC_CALR_CALM_Pos)	/*!< 0x00000008 */
#define RTC_CALR_CALM_4        (0x010UL << RTC_CALR_CALM_Pos)	/*!< 0x00000010 */
#define RTC_CALR_CALM_5        (0x020UL << RTC_CALR_CALM_Pos)	/*!< 0x00000020 */
#define RTC_CALR_CALM_6        (0x040UL << RTC_CALR_CALM_Pos)	/*!< 0x00000040 */
#define RTC_CALR_CALM_7        (0x080UL << RTC_CALR_CALM_Pos)	/*!< 0x00000080 */
#define RTC_CALR_CALM_8        (0x100UL << RTC_CALR_CALM_Pos)	/*!< 0x00000100 */

/********************  Bits definition for RTC_TAMPCR register  ****************/
#define RTC_TAMPCR_TAMP3MF_Pos         (24U)
#define RTC_TAMPCR_TAMP3MF_Msk         (0x1UL << RTC_TAMPCR_TAMP3MF_Pos)/*!< 0x01000000 */
#define RTC_TAMPCR_TAMP3MF             RTC_TAMPCR_TAMP3MF_Msk
#define RTC_TAMPCR_TAMP3NOERASE_Pos    (23U)
#define RTC_TAMPCR_TAMP3NOERASE_Msk    (0x1UL << RTC_TAMPCR_TAMP3NOERASE_Pos)	/*!< 0x00800000 */
#define RTC_TAMPCR_TAMP3NOERASE        RTC_TAMPCR_TAMP3NOERASE_Msk
#define RTC_TAMPCR_TAMP3IE_Pos         (22U)
#define RTC_TAMPCR_TAMP3IE_Msk         (0x1UL << RTC_TAMPCR_TAMP3IE_Pos)/*!< 0x00400000 */
#define RTC_TAMPCR_TAMP3IE             RTC_TAMPCR_TAMP3IE_Msk
#define RTC_TAMPCR_TAMP2MF_Pos         (21U)
#define RTC_TAMPCR_TAMP2MF_Msk         (0x1UL << RTC_TAMPCR_TAMP2MF_Pos)/*!< 0x00200000 */
#define RTC_TAMPCR_TAMP2MF             RTC_TAMPCR_TAMP2MF_Msk
#define RTC_TAMPCR_TAMP2NOERASE_Pos    (20U)
#define RTC_TAMPCR_TAMP2NOERASE_Msk    (0x1UL << RTC_TAMPCR_TAMP2NOERASE_Pos)	/*!< 0x00100000 */
#define RTC_TAMPCR_TAMP2NOERASE        RTC_TAMPCR_TAMP2NOERASE_Msk
#define RTC_TAMPCR_TAMP2IE_Pos         (19U)
#define RTC_TAMPCR_TAMP2IE_Msk         (0x1UL << RTC_TAMPCR_TAMP2IE_Pos)/*!< 0x00080000 */
#define RTC_TAMPCR_TAMP2IE             RTC_TAMPCR_TAMP2IE_Msk
#define RTC_TAMPCR_TAMP1MF_Pos         (18U)
#define RTC_TAMPCR_TAMP1MF_Msk         (0x1UL << RTC_TAMPCR_TAMP1MF_Pos)/*!< 0x00040000 */
#define RTC_TAMPCR_TAMP1MF             RTC_TAMPCR_TAMP1MF_Msk
#define RTC_TAMPCR_TAMP1NOERASE_Pos    (17U)
#define RTC_TAMPCR_TAMP1NOERASE_Msk    (0x1UL << RTC_TAMPCR_TAMP1NOERASE_Pos)	/*!< 0x00020000 */
#define RTC_TAMPCR_TAMP1NOERASE        RTC_TAMPCR_TAMP1NOERASE_Msk
#define RTC_TAMPCR_TAMP1IE_Pos         (16U)
#define RTC_TAMPCR_TAMP1IE_Msk         (0x1UL << RTC_TAMPCR_TAMP1IE_Pos)/*!< 0x00010000 */
#define RTC_TAMPCR_TAMP1IE             RTC_TAMPCR_TAMP1IE_Msk
#define RTC_TAMPCR_TAMPPUDIS_Pos       (15U)
#define RTC_TAMPCR_TAMPPUDIS_Msk       (0x1UL << RTC_TAMPCR_TAMPPUDIS_Pos)	/*!< 0x00008000 */
#define RTC_TAMPCR_TAMPPUDIS           RTC_TAMPCR_TAMPPUDIS_Msk
#define RTC_TAMPCR_TAMPPRCH_Pos        (13U)
#define RTC_TAMPCR_TAMPPRCH_Msk        (0x3UL << RTC_TAMPCR_TAMPPRCH_Pos)	/*!< 0x00006000 */
#define RTC_TAMPCR_TAMPPRCH            RTC_TAMPCR_TAMPPRCH_Msk
#define RTC_TAMPCR_TAMPPRCH_0          (0x1UL << RTC_TAMPCR_TAMPPRCH_Pos)	/*!< 0x00002000 */
#define RTC_TAMPCR_TAMPPRCH_1          (0x2UL << RTC_TAMPCR_TAMPPRCH_Pos)	/*!< 0x00004000 */
#define RTC_TAMPCR_TAMPFLT_Pos         (11U)
#define RTC_TAMPCR_TAMPFLT_Msk         (0x3UL << RTC_TAMPCR_TAMPFLT_Pos)/*!< 0x00001800 */
#define RTC_TAMPCR_TAMPFLT             RTC_TAMPCR_TAMPFLT_Msk
#define RTC_TAMPCR_TAMPFLT_0           (0x1UL << RTC_TAMPCR_TAMPFLT_Pos)/*!< 0x00000800 */
#define RTC_TAMPCR_TAMPFLT_1           (0x2UL << RTC_TAMPCR_TAMPFLT_Pos)/*!< 0x00001000 */
#define RTC_TAMPCR_TAMPFREQ_Pos        (8U)
#define RTC_TAMPCR_TAMPFREQ_Msk        (0x7UL << RTC_TAMPCR_TAMPFREQ_Pos)	/*!< 0x00000700 */
#define RTC_TAMPCR_TAMPFREQ            RTC_TAMPCR_TAMPFREQ_Msk
#define RTC_TAMPCR_TAMPFREQ_0          (0x1UL << RTC_TAMPCR_TAMPFREQ_Pos)	/*!< 0x00000100 */
#define RTC_TAMPCR_TAMPFREQ_1          (0x2UL << RTC_TAMPCR_TAMPFREQ_Pos)	/*!< 0x00000200 */
#define RTC_TAMPCR_TAMPFREQ_2          (0x4UL << RTC_TAMPCR_TAMPFREQ_Pos)	/*!< 0x00000400 */
#define RTC_TAMPCR_TAMPTS_Pos          (7U)
#define RTC_TAMPCR_TAMPTS_Msk          (0x1UL << RTC_TAMPCR_TAMPTS_Pos)	/*!< 0x00000080 */
#define RTC_TAMPCR_TAMPTS              RTC_TAMPCR_TAMPTS_Msk
#define RTC_TAMPCR_TAMP3TRG_Pos        (6U)
#define RTC_TAMPCR_TAMP3TRG_Msk        (0x1UL << RTC_TAMPCR_TAMP3TRG_Pos)	/*!< 0x00000040 */
#define RTC_TAMPCR_TAMP3TRG            RTC_TAMPCR_TAMP3TRG_Msk
#define RTC_TAMPCR_TAMP3E_Pos          (5U)
#define RTC_TAMPCR_TAMP3E_Msk          (0x1UL << RTC_TAMPCR_TAMP3E_Pos)	/*!< 0x00000020 */
#define RTC_TAMPCR_TAMP3E              RTC_TAMPCR_TAMP3E_Msk
#define RTC_TAMPCR_TAMP2TRG_Pos        (4U)
#define RTC_TAMPCR_TAMP2TRG_Msk        (0x1UL << RTC_TAMPCR_TAMP2TRG_Pos)	/*!< 0x00000010 */
#define RTC_TAMPCR_TAMP2TRG            RTC_TAMPCR_TAMP2TRG_Msk
#define RTC_TAMPCR_TAMP2E_Pos          (3U)
#define RTC_TAMPCR_TAMP2E_Msk          (0x1UL << RTC_TAMPCR_TAMP2E_Pos)	/*!< 0x00000008 */
#define RTC_TAMPCR_TAMP2E              RTC_TAMPCR_TAMP2E_Msk
#define RTC_TAMPCR_TAMPIE_Pos          (2U)
#define RTC_TAMPCR_TAMPIE_Msk          (0x1UL << RTC_TAMPCR_TAMPIE_Pos)	/*!< 0x00000004 */
#define RTC_TAMPCR_TAMPIE              RTC_TAMPCR_TAMPIE_Msk
#define RTC_TAMPCR_TAMP1TRG_Pos        (1U)
#define RTC_TAMPCR_TAMP1TRG_Msk        (0x1UL << RTC_TAMPCR_TAMP1TRG_Pos)	/*!< 0x00000002 */
#define RTC_TAMPCR_TAMP1TRG            RTC_TAMPCR_TAMP1TRG_Msk
#define RTC_TAMPCR_TAMP1E_Pos          (0U)
#define RTC_TAMPCR_TAMP1E_Msk          (0x1UL << RTC_TAMPCR_TAMP1E_Pos)	/*!< 0x00000001 */
#define RTC_TAMPCR_TAMP1E              RTC_TAMPCR_TAMP1E_Msk


/********************  Bits definition for RTC_ALRMASSR register  *************/
#define RTC_ALRMASSR_MASKSS_Pos    (24U)
#define RTC_ALRMASSR_MASKSS_Msk    (0xFUL << RTC_ALRMASSR_MASKSS_Pos)	/*!< 0x0F000000 */
#define RTC_ALRMASSR_MASKSS        RTC_ALRMASSR_MASKSS_Msk
#define RTC_ALRMASSR_MASKSS_0      (0x1UL << RTC_ALRMASSR_MASKSS_Pos)	/*!< 0x01000000 */
#define RTC_ALRMASSR_MASKSS_1      (0x2UL << RTC_ALRMASSR_MASKSS_Pos)	/*!< 0x02000000 */
#define RTC_ALRMASSR_MASKSS_2      (0x4UL << RTC_ALRMASSR_MASKSS_Pos)	/*!< 0x04000000 */
#define RTC_ALRMASSR_MASKSS_3      (0x8UL << RTC_ALRMASSR_MASKSS_Pos)	/*!< 0x08000000 */
#define RTC_ALRMASSR_SS_Pos        (0U)
#define RTC_ALRMASSR_SS_Msk        (0x7FFFUL << RTC_ALRMASSR_SS_Pos)/*!< 0x00007FFF */
#define RTC_ALRMASSR_SS            RTC_ALRMASSR_SS_Msk

/********************  Bits definition for RTC_ALRMBSSR register  *************/
#define RTC_ALRMBSSR_MASKSS_Pos    (24U)
#define RTC_ALRMBSSR_MASKSS_Msk    (0xFUL << RTC_ALRMBSSR_MASKSS_Pos)	/*!< 0x0F000000 */
#define RTC_ALRMBSSR_MASKSS        RTC_ALRMBSSR_MASKSS_Msk
#define RTC_ALRMBSSR_MASKSS_0      (0x1UL << RTC_ALRMBSSR_MASKSS_Pos)	/*!< 0x01000000 */
#define RTC_ALRMBSSR_MASKSS_1      (0x2UL << RTC_ALRMBSSR_MASKSS_Pos)	/*!< 0x02000000 */
#define RTC_ALRMBSSR_MASKSS_2      (0x4UL << RTC_ALRMBSSR_MASKSS_Pos)	/*!< 0x04000000 */
#define RTC_ALRMBSSR_MASKSS_3      (0x8UL << RTC_ALRMBSSR_MASKSS_Pos)	/*!< 0x08000000 */
#define RTC_ALRMBSSR_SS_Pos        (0U)
#define RTC_ALRMBSSR_SS_Msk        (0x7FFFUL << RTC_ALRMBSSR_SS_Pos)/*!< 0x00007FFF */
#define RTC_ALRMBSSR_SS            RTC_ALRMBSSR_SS_Msk

/********************  Bits definition for RTC_OR register  ****************/
#define RTC_OR_TSINSEL_Pos         (1U)
#define RTC_OR_TSINSEL_Msk         (0x3UL << RTC_OR_TSINSEL_Pos)/*!< 0x00000006 */
#define RTC_OR_TSINSEL             RTC_OR_TSINSEL_Msk
#define RTC_OR_TSINSEL_0           (0x1UL << RTC_OR_TSINSEL_Pos)/*!< 0x00000002 */
#define RTC_OR_TSINSEL_1           (0x2UL << RTC_OR_TSINSEL_Pos)/*!< 0x00000004 */
#define RTC_OR_ALARMOUTTYPE_Pos    (3U)
#define RTC_OR_ALARMOUTTYPE_Msk    (0x1UL << RTC_OR_ALARMOUTTYPE_Pos)	/*!< 0x00000008 */
#define RTC_OR_ALARMOUTTYPE        RTC_OR_ALARMOUTTYPE_Msk
/* Legacy defines*/
#define RTC_OR_ALARMTYPE           RTC_OR_ALARMOUTTYPE

/********************  Bits definition for RTC_BKP0R register  ****************/
#define RTC_BKP0R_Pos    (0U)
#define RTC_BKP0R_Msk    (0xFFFFFFFFUL << RTC_BKP0R_Pos)/*!< 0xFFFFFFFF */
#define RTC_BKP0R        RTC_BKP0R_Msk

/********************  Bits definition for RTC_BKP1R register  ****************/
#define RTC_BKP1R_Pos    (0U)
#define RTC_BKP1R_Msk    (0xFFFFFFFFUL << RTC_BKP1R_Pos)/*!< 0xFFFFFFFF */
#define RTC_BKP1R        RTC_BKP1R_Msk

/********************  Bits definition for RTC_BKP2R register  ****************/
#define RTC_BKP2R_Pos    (0U)
#define RTC_BKP2R_Msk    (0xFFFFFFFFUL << RTC_BKP2R_Pos)/*!< 0xFFFFFFFF */
#define RTC_BKP2R        RTC_BKP2R_Msk

/********************  Bits definition for RTC_BKP3R register  ****************/
#define RTC_BKP3R_Pos    (0U)
#define RTC_BKP3R_Msk    (0xFFFFFFFFUL << RTC_BKP3R_Pos)/*!< 0xFFFFFFFF */
#define RTC_BKP3R        RTC_BKP3R_Msk

/********************  Bits definition for RTC_BKP4R register  ****************/
#define RTC_BKP4R_Pos    (0U)
#define RTC_BKP4R_Msk    (0xFFFFFFFFUL << RTC_BKP4R_Pos)/*!< 0xFFFFFFFF */
#define RTC_BKP4R        RTC_BKP4R_Msk

/********************  Bits definition for RTC_BKP5R register  ****************/
#define RTC_BKP5R_Pos    (0U)
#define RTC_BKP5R_Msk    (0xFFFFFFFFUL << RTC_BKP5R_Pos)/*!< 0xFFFFFFFF */
#define RTC_BKP5R        RTC_BKP5R_Msk

/********************  Bits definition for RTC_BKP6R register  ****************/
#define RTC_BKP6R_Pos    (0U)
#define RTC_BKP6R_Msk    (0xFFFFFFFFUL << RTC_BKP6R_Pos)/*!< 0xFFFFFFFF */
#define RTC_BKP6R        RTC_BKP6R_Msk

/********************  Bits definition for RTC_BKP7R register  ****************/
#define RTC_BKP7R_Pos    (0U)
#define RTC_BKP7R_Msk    (0xFFFFFFFFUL << RTC_BKP7R_Pos)/*!< 0xFFFFFFFF */
#define RTC_BKP7R        RTC_BKP7R_Msk

/********************  Bits definition for RTC_BKP8R register  ****************/
#define RTC_BKP8R_Pos    (0U)
#define RTC_BKP8R_Msk    (0xFFFFFFFFUL << RTC_BKP8R_Pos)/*!< 0xFFFFFFFF */
#define RTC_BKP8R        RTC_BKP8R_Msk

/********************  Bits definition for RTC_BKP9R register  ****************/
#define RTC_BKP9R_Pos    (0U)
#define RTC_BKP9R_Msk    (0xFFFFFFFFUL << RTC_BKP9R_Pos)/*!< 0xFFFFFFFF */
#define RTC_BKP9R        RTC_BKP9R_Msk

/********************  Bits definition for RTC_BKP10R register  ***************/
#define RTC_BKP10R_Pos    (0U)
#define RTC_BKP10R_Msk    (0xFFFFFFFFUL << RTC_BKP10R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP10R        RTC_BKP10R_Msk

/********************  Bits definition for RTC_BKP11R register  ***************/
#define RTC_BKP11R_Pos    (0U)
#define RTC_BKP11R_Msk    (0xFFFFFFFFUL << RTC_BKP11R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP11R        RTC_BKP11R_Msk

/********************  Bits definition for RTC_BKP12R register  ***************/
#define RTC_BKP12R_Pos    (0U)
#define RTC_BKP12R_Msk    (0xFFFFFFFFUL << RTC_BKP12R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP12R        RTC_BKP12R_Msk

/********************  Bits definition for RTC_BKP13R register  ***************/
#define RTC_BKP13R_Pos    (0U)
#define RTC_BKP13R_Msk    (0xFFFFFFFFUL << RTC_BKP13R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP13R        RTC_BKP13R_Msk

/********************  Bits definition for RTC_BKP14R register  ***************/
#define RTC_BKP14R_Pos    (0U)
#define RTC_BKP14R_Msk    (0xFFFFFFFFUL << RTC_BKP14R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP14R        RTC_BKP14R_Msk

/********************  Bits definition for RTC_BKP15R register  ***************/
#define RTC_BKP15R_Pos    (0U)
#define RTC_BKP15R_Msk    (0xFFFFFFFFUL << RTC_BKP15R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP15R        RTC_BKP15R_Msk

/********************  Bits definition for RTC_BKP16R register  ***************/
#define RTC_BKP16R_Pos    (0U)
#define RTC_BKP16R_Msk    (0xFFFFFFFFUL << RTC_BKP16R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP16R        RTC_BKP16R_Msk

/********************  Bits definition for RTC_BKP17R register  ***************/
#define RTC_BKP17R_Pos    (0U)
#define RTC_BKP17R_Msk    (0xFFFFFFFFUL << RTC_BKP17R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP17R        RTC_BKP17R_Msk

/********************  Bits definition for RTC_BKP18R register  ***************/
#define RTC_BKP18R_Pos    (0U)
#define RTC_BKP18R_Msk    (0xFFFFFFFFUL << RTC_BKP18R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP18R        RTC_BKP18R_Msk

/********************  Bits definition for RTC_BKP19R register  ***************/
#define RTC_BKP19R_Pos    (0U)
#define RTC_BKP19R_Msk    (0xFFFFFFFFUL << RTC_BKP19R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP19R        RTC_BKP19R_Msk

/********************  Bits definition for RTC_BKP20R register  ***************/
#define RTC_BKP20R_Pos    (0U)
#define RTC_BKP20R_Msk    (0xFFFFFFFFUL << RTC_BKP20R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP20R        RTC_BKP20R_Msk

/********************  Bits definition for RTC_BKP21R register  ***************/
#define RTC_BKP21R_Pos    (0U)
#define RTC_BKP21R_Msk    (0xFFFFFFFFUL << RTC_BKP21R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP21R        RTC_BKP21R_Msk

/********************  Bits definition for RTC_BKP22R register  ***************/
#define RTC_BKP22R_Pos    (0U)
#define RTC_BKP22R_Msk    (0xFFFFFFFFUL << RTC_BKP22R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP22R        RTC_BKP22R_Msk

/********************  Bits definition for RTC_BKP23R register  ***************/
#define RTC_BKP23R_Pos    (0U)
#define RTC_BKP23R_Msk    (0xFFFFFFFFUL << RTC_BKP23R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP23R        RTC_BKP23R_Msk

/********************  Bits definition for RTC_BKP24R register  ***************/
#define RTC_BKP24R_Pos    (0U)
#define RTC_BKP24R_Msk    (0xFFFFFFFFUL << RTC_BKP24R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP24R        RTC_BKP24R_Msk

/********************  Bits definition for RTC_BKP25R register  ***************/
#define RTC_BKP25R_Pos    (0U)
#define RTC_BKP25R_Msk    (0xFFFFFFFFUL << RTC_BKP25R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP25R        RTC_BKP25R_Msk

/********************  Bits definition for RTC_BKP26R register  ***************/
#define RTC_BKP26R_Pos    (0U)
#define RTC_BKP26R_Msk    (0xFFFFFFFFUL << RTC_BKP26R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP26R        RTC_BKP26R_Msk

/********************  Bits definition for RTC_BKP27R register  ***************/
#define RTC_BKP27R_Pos    (0U)
#define RTC_BKP27R_Msk    (0xFFFFFFFFUL << RTC_BKP27R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP27R        RTC_BKP27R_Msk

/********************  Bits definition for RTC_BKP28R register  ***************/
#define RTC_BKP28R_Pos    (0U)
#define RTC_BKP28R_Msk    (0xFFFFFFFFUL << RTC_BKP28R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP28R        RTC_BKP28R_Msk

/********************  Bits definition for RTC_BKP29R register  ***************/
#define RTC_BKP29R_Pos    (0U)
#define RTC_BKP29R_Msk    (0xFFFFFFFFUL << RTC_BKP29R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP29R        RTC_BKP29R_Msk

/********************  Bits definition for RTC_BKP30R register  ***************/
#define RTC_BKP30R_Pos    (0U)
#define RTC_BKP30R_Msk    (0xFFFFFFFFUL << RTC_BKP30R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP30R        RTC_BKP30R_Msk

/********************  Bits definition for RTC_BKP31R register  ***************/
#define RTC_BKP31R_Pos    (0U)
#define RTC_BKP31R_Msk    (0xFFFFFFFFUL << RTC_BKP31R_Pos)	/*!< 0xFFFFFFFF */
#define RTC_BKP31R        RTC_BKP31R_Msk

/******************** Number of backup registers ******************************/
#define RTC_BKP_NUMBER    0x00000020U

/******************************************************************************/
/*                                                                            */
/*                          Serial Audio Interface                            */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for SAI_GCR register  *******************/
#define SAI_GCR_SYNCIN_Pos     (0U)
#define SAI_GCR_SYNCIN_Msk     (0x3UL << SAI_GCR_SYNCIN_Pos)/*!< 0x00000003 */
#define SAI_GCR_SYNCIN         SAI_GCR_SYNCIN_Msk	/*!<SYNCIN[1:0] bits (Synchronization Inputs)   */
#define SAI_GCR_SYNCIN_0       (0x1UL << SAI_GCR_SYNCIN_Pos)/*!< 0x00000001 */
#define SAI_GCR_SYNCIN_1       (0x2UL << SAI_GCR_SYNCIN_Pos)/*!< 0x00000002 */

#define SAI_GCR_SYNCOUT_Pos    (4U)
#define SAI_GCR_SYNCOUT_Msk    (0x3UL << SAI_GCR_SYNCOUT_Pos)	/*!< 0x00000030 */
#define SAI_GCR_SYNCOUT        SAI_GCR_SYNCOUT_Msk				/*!<SYNCOUT[1:0] bits (Synchronization Outputs) */
#define SAI_GCR_SYNCOUT_0      (0x1UL << SAI_GCR_SYNCOUT_Pos)	/*!< 0x00000010 */
#define SAI_GCR_SYNCOUT_1      (0x2UL << SAI_GCR_SYNCOUT_Pos)	/*!< 0x00000020 */

/*******************  Bit definition for SAI_xCR1 register  *******************/
#define SAI_xCR1_MODE_Pos        (0U)
#define SAI_xCR1_MODE_Msk        (0x3UL << SAI_xCR1_MODE_Pos)	/*!< 0x00000003 */
#define SAI_xCR1_MODE            SAI_xCR1_MODE_Msk				/*!<MODE[1:0] bits (Audio Block Mode)           */
#define SAI_xCR1_MODE_0          (0x1UL << SAI_xCR1_MODE_Pos)	/*!< 0x00000001 */
#define SAI_xCR1_MODE_1          (0x2UL << SAI_xCR1_MODE_Pos)	/*!< 0x00000002 */

#define SAI_xCR1_PRTCFG_Pos      (2U)
#define SAI_xCR1_PRTCFG_Msk      (0x3UL << SAI_xCR1_PRTCFG_Pos)	/*!< 0x0000000C */
#define SAI_xCR1_PRTCFG          SAI_xCR1_PRTCFG_Msk/*!<PRTCFG[1:0] bits (Protocol Configuration)   */
#define SAI_xCR1_PRTCFG_0        (0x1UL << SAI_xCR1_PRTCFG_Pos)	/*!< 0x00000004 */
#define SAI_xCR1_PRTCFG_1        (0x2UL << SAI_xCR1_PRTCFG_Pos)	/*!< 0x00000008 */

#define SAI_xCR1_DS_Pos          (5U)
#define SAI_xCR1_DS_Msk          (0x7UL << SAI_xCR1_DS_Pos)	/*!< 0x000000E0 */
#define SAI_xCR1_DS              SAI_xCR1_DS_Msk/*!<DS[1:0] bits (Data Size) */
#define SAI_xCR1_DS_0            (0x1UL << SAI_xCR1_DS_Pos)	/*!< 0x00000020 */
#define SAI_xCR1_DS_1            (0x2UL << SAI_xCR1_DS_Pos)	/*!< 0x00000040 */
#define SAI_xCR1_DS_2            (0x4UL << SAI_xCR1_DS_Pos)	/*!< 0x00000080 */

#define SAI_xCR1_LSBFIRST_Pos    (8U)
#define SAI_xCR1_LSBFIRST_Msk    (0x1UL << SAI_xCR1_LSBFIRST_Pos)	/*!< 0x00000100 */
#define SAI_xCR1_LSBFIRST        SAI_xCR1_LSBFIRST_Msk				/*!<LSB First Configuration  */
#define SAI_xCR1_CKSTR_Pos       (9U)
#define SAI_xCR1_CKSTR_Msk       (0x1UL << SAI_xCR1_CKSTR_Pos)	/*!< 0x00000200 */
#define SAI_xCR1_CKSTR           SAI_xCR1_CKSTR_Msk				/*!<ClocK STRobing edge      */

#define SAI_xCR1_SYNCEN_Pos      (10U)
#define SAI_xCR1_SYNCEN_Msk      (0x3UL << SAI_xCR1_SYNCEN_Pos)	/*!< 0x00000C00 */
#define SAI_xCR1_SYNCEN          SAI_xCR1_SYNCEN_Msk/*!<SYNCEN[1:0](SYNChronization ENable) */
#define SAI_xCR1_SYNCEN_0        (0x1UL << SAI_xCR1_SYNCEN_Pos)	/*!< 0x00000400 */
#define SAI_xCR1_SYNCEN_1        (0x2UL << SAI_xCR1_SYNCEN_Pos)	/*!< 0x00000800 */

#define SAI_xCR1_MONO_Pos        (12U)
#define SAI_xCR1_MONO_Msk        (0x1UL << SAI_xCR1_MONO_Pos)	/*!< 0x00001000 */
#define SAI_xCR1_MONO            SAI_xCR1_MONO_Msk				/*!<Mono mode                  */
#define SAI_xCR1_OUTDRIV_Pos     (13U)
#define SAI_xCR1_OUTDRIV_Msk     (0x1UL << SAI_xCR1_OUTDRIV_Pos)/*!< 0x00002000 */
#define SAI_xCR1_OUTDRIV         SAI_xCR1_OUTDRIV_Msk	/*!<Output Drive               */
#define SAI_xCR1_SAIEN_Pos       (16U)
#define SAI_xCR1_SAIEN_Msk       (0x1UL << SAI_xCR1_SAIEN_Pos)	/*!< 0x00010000 */
#define SAI_xCR1_SAIEN           SAI_xCR1_SAIEN_Msk				/*!<Audio Block enable         */
#define SAI_xCR1_DMAEN_Pos       (17U)
#define SAI_xCR1_DMAEN_Msk       (0x1UL << SAI_xCR1_DMAEN_Pos)	/*!< 0x00020000 */
#define SAI_xCR1_DMAEN           SAI_xCR1_DMAEN_Msk				/*!<DMA enable                 */
#define SAI_xCR1_NODIV_Pos       (19U)
#define SAI_xCR1_NODIV_Msk       (0x1UL << SAI_xCR1_NODIV_Pos)	/*!< 0x00080000 */
#define SAI_xCR1_NODIV           SAI_xCR1_NODIV_Msk				/*!<No Divider Configuration   */

#define SAI_xCR1_MCKDIV_Pos      (20U)
#define SAI_xCR1_MCKDIV_Msk      (0xFUL << SAI_xCR1_MCKDIV_Pos)	/*!< 0x00F00000 */
#define SAI_xCR1_MCKDIV          SAI_xCR1_MCKDIV_Msk/*!<MCKDIV[3:0] (Master ClocK Divider)  */
#define SAI_xCR1_MCKDIV_0        (0x1UL << SAI_xCR1_MCKDIV_Pos)	/*!< 0x00100000 */
#define SAI_xCR1_MCKDIV_1        (0x2UL << SAI_xCR1_MCKDIV_Pos)	/*!< 0x00200000 */
#define SAI_xCR1_MCKDIV_2        (0x4UL << SAI_xCR1_MCKDIV_Pos)	/*!< 0x00400000 */
#define SAI_xCR1_MCKDIV_3        (0x8UL << SAI_xCR1_MCKDIV_Pos)	/*!< 0x00800000 */

/*******************  Bit definition for SAI_xCR2 register  *******************/
#define SAI_xCR2_FTH_Pos        (0U)
#define SAI_xCR2_FTH_Msk        (0x7UL << SAI_xCR2_FTH_Pos)	/*!< 0x00000007 */
#define SAI_xCR2_FTH            SAI_xCR2_FTH_Msk/*!<FTH[2:0](Fifo THreshold)  */
#define SAI_xCR2_FTH_0          (0x1UL << SAI_xCR2_FTH_Pos)	/*!< 0x00000001 */
#define SAI_xCR2_FTH_1          (0x2UL << SAI_xCR2_FTH_Pos)	/*!< 0x00000002 */
#define SAI_xCR2_FTH_2          (0x4UL << SAI_xCR2_FTH_Pos)	/*!< 0x00000004 */

#define SAI_xCR2_FFLUSH_Pos     (3U)
#define SAI_xCR2_FFLUSH_Msk     (0x1UL << SAI_xCR2_FFLUSH_Pos)	/*!< 0x00000008 */
#define SAI_xCR2_FFLUSH         SAI_xCR2_FFLUSH_Msk				/*!<Fifo FLUSH                       */
#define SAI_xCR2_TRIS_Pos       (4U)
#define SAI_xCR2_TRIS_Msk       (0x1UL << SAI_xCR2_TRIS_Pos)/*!< 0x00000010 */
#define SAI_xCR2_TRIS           SAI_xCR2_TRIS_Msk	/*!<TRIState Management on data line */
#define SAI_xCR2_MUTE_Pos       (5U)
#define SAI_xCR2_MUTE_Msk       (0x1UL << SAI_xCR2_MUTE_Pos)/*!< 0x00000020 */
#define SAI_xCR2_MUTE           SAI_xCR2_MUTE_Msk	/*!<Mute mode                        */
#define SAI_xCR2_MUTEVAL_Pos    (6U)
#define SAI_xCR2_MUTEVAL_Msk    (0x1UL << SAI_xCR2_MUTEVAL_Pos)	/*!< 0x00000040 */
#define SAI_xCR2_MUTEVAL        SAI_xCR2_MUTEVAL_Msk/*!<Muate value                      */

#define SAI_xCR2_MUTECNT_Pos    (7U)
#define SAI_xCR2_MUTECNT_Msk    (0x3FUL << SAI_xCR2_MUTECNT_Pos)/*!< 0x00001F80 */
#define SAI_xCR2_MUTECNT        SAI_xCR2_MUTECNT_Msk/*!<MUTECNT[5:0] (MUTE counter) */
#define SAI_xCR2_MUTECNT_0      (0x01UL << SAI_xCR2_MUTECNT_Pos)/*!< 0x00000080 */
#define SAI_xCR2_MUTECNT_1      (0x02UL << SAI_xCR2_MUTECNT_Pos)/*!< 0x00000100 */
#define SAI_xCR2_MUTECNT_2      (0x04UL << SAI_xCR2_MUTECNT_Pos)/*!< 0x00000200 */
#define SAI_xCR2_MUTECNT_3      (0x08UL << SAI_xCR2_MUTECNT_Pos)/*!< 0x00000400 */
#define SAI_xCR2_MUTECNT_4      (0x10UL << SAI_xCR2_MUTECNT_Pos)/*!< 0x00000800 */
#define SAI_xCR2_MUTECNT_5      (0x20UL << SAI_xCR2_MUTECNT_Pos)/*!< 0x00001000 */

#define SAI_xCR2_CPL_Pos        (13U)
#define SAI_xCR2_CPL_Msk        (0x1UL << SAI_xCR2_CPL_Pos)	/*!< 0x00002000 */
#define SAI_xCR2_CPL            SAI_xCR2_CPL_Msk/*!< Complement Bit             */

#define SAI_xCR2_COMP_Pos       (14U)
#define SAI_xCR2_COMP_Msk       (0x3UL << SAI_xCR2_COMP_Pos)/*!< 0x0000C000 */
#define SAI_xCR2_COMP           SAI_xCR2_COMP_Msk	/*!<COMP[1:0] (Companding mode) */
#define SAI_xCR2_COMP_0         (0x1UL << SAI_xCR2_COMP_Pos)/*!< 0x00004000 */
#define SAI_xCR2_COMP_1         (0x2UL << SAI_xCR2_COMP_Pos)/*!< 0x00008000 */

/******************  Bit definition for SAI_xFRCR register  *******************/
#define SAI_xFRCR_FRL_Pos      (0U)
#define SAI_xFRCR_FRL_Msk      (0xFFUL << SAI_xFRCR_FRL_Pos)/*!< 0x000000FF */
#define SAI_xFRCR_FRL          SAI_xFRCR_FRL_Msk/*!<FRL[7:0](Frame length)  */
#define SAI_xFRCR_FRL_0        (0x01UL << SAI_xFRCR_FRL_Pos)/*!< 0x00000001 */
#define SAI_xFRCR_FRL_1        (0x02UL << SAI_xFRCR_FRL_Pos)/*!< 0x00000002 */
#define SAI_xFRCR_FRL_2        (0x04UL << SAI_xFRCR_FRL_Pos)/*!< 0x00000004 */
#define SAI_xFRCR_FRL_3        (0x08UL << SAI_xFRCR_FRL_Pos)/*!< 0x00000008 */
#define SAI_xFRCR_FRL_4        (0x10UL << SAI_xFRCR_FRL_Pos)/*!< 0x00000010 */
#define SAI_xFRCR_FRL_5        (0x20UL << SAI_xFRCR_FRL_Pos)/*!< 0x00000020 */
#define SAI_xFRCR_FRL_6        (0x40UL << SAI_xFRCR_FRL_Pos)/*!< 0x00000040 */
#define SAI_xFRCR_FRL_7        (0x80UL << SAI_xFRCR_FRL_Pos)/*!< 0x00000080 */

#define SAI_xFRCR_FSALL_Pos    (8U)
#define SAI_xFRCR_FSALL_Msk    (0x7FUL << SAI_xFRCR_FSALL_Pos)	/*!< 0x00007F00 */
#define SAI_xFRCR_FSALL        SAI_xFRCR_FSALL_Msk				/*!<FRL[6:0] (Frame synchronization active level length)  */
#define SAI_xFRCR_FSALL_0      (0x01UL << SAI_xFRCR_FSALL_Pos)	/*!< 0x00000100 */
#define SAI_xFRCR_FSALL_1      (0x02UL << SAI_xFRCR_FSALL_Pos)	/*!< 0x00000200 */
#define SAI_xFRCR_FSALL_2      (0x04UL << SAI_xFRCR_FSALL_Pos)	/*!< 0x00000400 */
#define SAI_xFRCR_FSALL_3      (0x08UL << SAI_xFRCR_FSALL_Pos)	/*!< 0x00000800 */
#define SAI_xFRCR_FSALL_4      (0x10UL << SAI_xFRCR_FSALL_Pos)	/*!< 0x00001000 */
#define SAI_xFRCR_FSALL_5      (0x20UL << SAI_xFRCR_FSALL_Pos)	/*!< 0x00002000 */
#define SAI_xFRCR_FSALL_6      (0x40UL << SAI_xFRCR_FSALL_Pos)	/*!< 0x00004000 */

#define SAI_xFRCR_FSDEF_Pos    (16U)
#define SAI_xFRCR_FSDEF_Msk    (0x1UL << SAI_xFRCR_FSDEF_Pos)	/*!< 0x00010000 */
#define SAI_xFRCR_FSDEF        SAI_xFRCR_FSDEF_Msk				/*!<Frame Synchronization Definition  */
#define SAI_xFRCR_FSPOL_Pos    (17U)
#define SAI_xFRCR_FSPOL_Msk    (0x1UL << SAI_xFRCR_FSPOL_Pos)	/*!< 0x00020000 */
#define SAI_xFRCR_FSPOL        SAI_xFRCR_FSPOL_Msk				/*!<Frame Synchronization POLarity    */
#define SAI_xFRCR_FSOFF_Pos    (18U)
#define SAI_xFRCR_FSOFF_Msk    (0x1UL << SAI_xFRCR_FSOFF_Pos)	/*!< 0x00040000 */
#define SAI_xFRCR_FSOFF        SAI_xFRCR_FSOFF_Msk				/*!<Frame Synchronization OFFset      */

/* Legacy define */
#define  SAI_xFRCR_FSPO    SAI_xFRCR_FSPOL

/******************  Bit definition for SAI_xSLOTR register  *******************/
#define SAI_xSLOTR_FBOFF_Pos     (0U)
#define SAI_xSLOTR_FBOFF_Msk     (0x1FUL << SAI_xSLOTR_FBOFF_Pos)	/*!< 0x0000001F */
#define SAI_xSLOTR_FBOFF         SAI_xSLOTR_FBOFF_Msk				/*!<FRL[4:0](First Bit Offset)  */
#define SAI_xSLOTR_FBOFF_0       (0x01UL << SAI_xSLOTR_FBOFF_Pos)	/*!< 0x00000001 */
#define SAI_xSLOTR_FBOFF_1       (0x02UL << SAI_xSLOTR_FBOFF_Pos)	/*!< 0x00000002 */
#define SAI_xSLOTR_FBOFF_2       (0x04UL << SAI_xSLOTR_FBOFF_Pos)	/*!< 0x00000004 */
#define SAI_xSLOTR_FBOFF_3       (0x08UL << SAI_xSLOTR_FBOFF_Pos)	/*!< 0x00000008 */
#define SAI_xSLOTR_FBOFF_4       (0x10UL << SAI_xSLOTR_FBOFF_Pos)	/*!< 0x00000010 */

#define SAI_xSLOTR_SLOTSZ_Pos    (6U)
#define SAI_xSLOTR_SLOTSZ_Msk    (0x3UL << SAI_xSLOTR_SLOTSZ_Pos)	/*!< 0x000000C0 */
#define SAI_xSLOTR_SLOTSZ        SAI_xSLOTR_SLOTSZ_Msk				/*!<SLOTSZ[1:0] (Slot size)  */
#define SAI_xSLOTR_SLOTSZ_0      (0x1UL << SAI_xSLOTR_SLOTSZ_Pos)	/*!< 0x00000040 */
#define SAI_xSLOTR_SLOTSZ_1      (0x2UL << SAI_xSLOTR_SLOTSZ_Pos)	/*!< 0x00000080 */

#define SAI_xSLOTR_NBSLOT_Pos    (8U)
#define SAI_xSLOTR_NBSLOT_Msk    (0xFUL << SAI_xSLOTR_NBSLOT_Pos)	/*!< 0x00000F00 */
#define SAI_xSLOTR_NBSLOT        SAI_xSLOTR_NBSLOT_Msk				/*!<NBSLOT[3:0] (Number of Slot in audio Frame)  */
#define SAI_xSLOTR_NBSLOT_0      (0x1UL << SAI_xSLOTR_NBSLOT_Pos)	/*!< 0x00000100 */
#define SAI_xSLOTR_NBSLOT_1      (0x2UL << SAI_xSLOTR_NBSLOT_Pos)	/*!< 0x00000200 */
#define SAI_xSLOTR_NBSLOT_2      (0x4UL << SAI_xSLOTR_NBSLOT_Pos)	/*!< 0x00000400 */
#define SAI_xSLOTR_NBSLOT_3      (0x8UL << SAI_xSLOTR_NBSLOT_Pos)	/*!< 0x00000800 */

#define SAI_xSLOTR_SLOTEN_Pos    (16U)
#define SAI_xSLOTR_SLOTEN_Msk    (0xFFFFUL << SAI_xSLOTR_SLOTEN_Pos)/*!< 0xFFFF0000 */
#define SAI_xSLOTR_SLOTEN        SAI_xSLOTR_SLOTEN_Msk	/*!<SLOTEN[15:0] (Slot Enable)  */

/*******************  Bit definition for SAI_xIMR register  *******************/
#define SAI_xIMR_OVRUDRIE_Pos     (0U)
#define SAI_xIMR_OVRUDRIE_Msk     (0x1UL << SAI_xIMR_OVRUDRIE_Pos)	/*!< 0x00000001 */
#define SAI_xIMR_OVRUDRIE         SAI_xIMR_OVRUDRIE_Msk				/*!<Overrun underrun interrupt enable                              */
#define SAI_xIMR_MUTEDETIE_Pos    (1U)
#define SAI_xIMR_MUTEDETIE_Msk    (0x1UL << SAI_xIMR_MUTEDETIE_Pos)	/*!< 0x00000002 */
#define SAI_xIMR_MUTEDETIE        SAI_xIMR_MUTEDETIE_Msk/*!<Mute detection interrupt enable                                */
#define SAI_xIMR_WCKCFGIE_Pos     (2U)
#define SAI_xIMR_WCKCFGIE_Msk     (0x1UL << SAI_xIMR_WCKCFGIE_Pos)	/*!< 0x00000004 */
#define SAI_xIMR_WCKCFGIE         SAI_xIMR_WCKCFGIE_Msk				/*!<Wrong Clock Configuration interrupt enable                     */
#define SAI_xIMR_FREQIE_Pos       (3U)
#define SAI_xIMR_FREQIE_Msk       (0x1UL << SAI_xIMR_FREQIE_Pos)/*!< 0x00000008 */
#define SAI_xIMR_FREQIE           SAI_xIMR_FREQIE_Msk	/*!<FIFO request interrupt enable                                  */
#define SAI_xIMR_CNRDYIE_Pos      (4U)
#define SAI_xIMR_CNRDYIE_Msk      (0x1UL << SAI_xIMR_CNRDYIE_Pos)	/*!< 0x00000010 */
#define SAI_xIMR_CNRDYIE          SAI_xIMR_CNRDYIE_Msk				/*!<Codec not ready interrupt enable                               */
#define SAI_xIMR_AFSDETIE_Pos     (5U)
#define SAI_xIMR_AFSDETIE_Msk     (0x1UL << SAI_xIMR_AFSDETIE_Pos)	/*!< 0x00000020 */
#define SAI_xIMR_AFSDETIE         SAI_xIMR_AFSDETIE_Msk				/*!<Anticipated frame synchronization detection interrupt enable   */
#define SAI_xIMR_LFSDETIE_Pos     (6U)
#define SAI_xIMR_LFSDETIE_Msk     (0x1UL << SAI_xIMR_LFSDETIE_Pos)	/*!< 0x00000040 */
#define SAI_xIMR_LFSDETIE         SAI_xIMR_LFSDETIE_Msk				/*!<Late frame synchronization detection interrupt enable          */

/********************  Bit definition for SAI_xSR register  *******************/
#define SAI_xSR_OVRUDR_Pos     (0U)
#define SAI_xSR_OVRUDR_Msk     (0x1UL << SAI_xSR_OVRUDR_Pos)/*!< 0x00000001 */
#define SAI_xSR_OVRUDR         SAI_xSR_OVRUDR_Msk	/*!<Overrun underrun                               */
#define SAI_xSR_MUTEDET_Pos    (1U)
#define SAI_xSR_MUTEDET_Msk    (0x1UL << SAI_xSR_MUTEDET_Pos)	/*!< 0x00000002 */
#define SAI_xSR_MUTEDET        SAI_xSR_MUTEDET_Msk				/*!<Mute detection                                 */
#define SAI_xSR_WCKCFG_Pos     (2U)
#define SAI_xSR_WCKCFG_Msk     (0x1UL << SAI_xSR_WCKCFG_Pos)/*!< 0x00000004 */
#define SAI_xSR_WCKCFG         SAI_xSR_WCKCFG_Msk	/*!<Wrong Clock Configuration                      */
#define SAI_xSR_FREQ_Pos       (3U)
#define SAI_xSR_FREQ_Msk       (0x1UL << SAI_xSR_FREQ_Pos)	/*!< 0x00000008 */
#define SAI_xSR_FREQ           SAI_xSR_FREQ_Msk				/*!<FIFO request                                   */
#define SAI_xSR_CNRDY_Pos      (4U)
#define SAI_xSR_CNRDY_Msk      (0x1UL << SAI_xSR_CNRDY_Pos)	/*!< 0x00000010 */
#define SAI_xSR_CNRDY          SAI_xSR_CNRDY_Msk/*!<Codec not ready                                */
#define SAI_xSR_AFSDET_Pos     (5U)
#define SAI_xSR_AFSDET_Msk     (0x1UL << SAI_xSR_AFSDET_Pos)/*!< 0x00000020 */
#define SAI_xSR_AFSDET         SAI_xSR_AFSDET_Msk	/*!<Anticipated frame synchronization detection    */
#define SAI_xSR_LFSDET_Pos     (6U)
#define SAI_xSR_LFSDET_Msk     (0x1UL << SAI_xSR_LFSDET_Pos)/*!< 0x00000040 */
#define SAI_xSR_LFSDET         SAI_xSR_LFSDET_Msk	/*!<Late frame synchronization detection           */

#define SAI_xSR_FLVL_Pos       (16U)
#define SAI_xSR_FLVL_Msk       (0x7UL << SAI_xSR_FLVL_Pos)	/*!< 0x00070000 */
#define SAI_xSR_FLVL           SAI_xSR_FLVL_Msk				/*!<FLVL[2:0] (FIFO Level Threshold)               */
#define SAI_xSR_FLVL_0         (0x1UL << SAI_xSR_FLVL_Pos)	/*!< 0x00010000 */
#define SAI_xSR_FLVL_1         (0x2UL << SAI_xSR_FLVL_Pos)	/*!< 0x00020000 */
#define SAI_xSR_FLVL_2         (0x4UL << SAI_xSR_FLVL_Pos)	/*!< 0x00040000 */

/******************  Bit definition for SAI_xCLRFR register  ******************/
#define SAI_xCLRFR_COVRUDR_Pos     (0U)
#define SAI_xCLRFR_COVRUDR_Msk     (0x1UL << SAI_xCLRFR_COVRUDR_Pos)/*!< 0x00000001 */
#define SAI_xCLRFR_COVRUDR         SAI_xCLRFR_COVRUDR_Msk	/*!<Clear Overrun underrun                               */
#define SAI_xCLRFR_CMUTEDET_Pos    (1U)
#define SAI_xCLRFR_CMUTEDET_Msk    (0x1UL << SAI_xCLRFR_CMUTEDET_Pos)	/*!< 0x00000002 */
#define SAI_xCLRFR_CMUTEDET        SAI_xCLRFR_CMUTEDET_Msk				/*!<Clear Mute detection                                 */
#define SAI_xCLRFR_CWCKCFG_Pos     (2U)
#define SAI_xCLRFR_CWCKCFG_Msk     (0x1UL << SAI_xCLRFR_CWCKCFG_Pos)/*!< 0x00000004 */
#define SAI_xCLRFR_CWCKCFG         SAI_xCLRFR_CWCKCFG_Msk	/*!<Clear Wrong Clock Configuration                      */
#define SAI_xCLRFR_CFREQ_Pos       (3U)
#define SAI_xCLRFR_CFREQ_Msk       (0x1UL << SAI_xCLRFR_CFREQ_Pos)	/*!< 0x00000008 */
#define SAI_xCLRFR_CFREQ           SAI_xCLRFR_CFREQ_Msk				/*!<Clear FIFO request                                   */
#define SAI_xCLRFR_CCNRDY_Pos      (4U)
#define SAI_xCLRFR_CCNRDY_Msk      (0x1UL << SAI_xCLRFR_CCNRDY_Pos)	/*!< 0x00000010 */
#define SAI_xCLRFR_CCNRDY          SAI_xCLRFR_CCNRDY_Msk/*!<Clear Codec not ready                                */
#define SAI_xCLRFR_CAFSDET_Pos     (5U)
#define SAI_xCLRFR_CAFSDET_Msk     (0x1UL << SAI_xCLRFR_CAFSDET_Pos)/*!< 0x00000020 */
#define SAI_xCLRFR_CAFSDET         SAI_xCLRFR_CAFSDET_Msk	/*!<Clear Anticipated frame synchronization detection    */
#define SAI_xCLRFR_CLFSDET_Pos     (6U)
#define SAI_xCLRFR_CLFSDET_Msk     (0x1UL << SAI_xCLRFR_CLFSDET_Pos)/*!< 0x00000040 */
#define SAI_xCLRFR_CLFSDET         SAI_xCLRFR_CLFSDET_Msk	/*!<Clear Late frame synchronization detection           */

/******************  Bit definition for SAI_xDR register  *********************/
#define SAI_xDR_DATA_Pos    (0U)
#define SAI_xDR_DATA_Msk    (0xFFFFFFFFUL << SAI_xDR_DATA_Pos)	/*!< 0xFFFFFFFF */
#define SAI_xDR_DATA        SAI_xDR_DATA_Msk


/******************************************************************************/
/*                                                                            */
/*                          SD host Interface                                 */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for SDMMC_POWER register  ******************/
#define SDMMC_POWER_PWRCTRL_Pos    (0U)
#define SDMMC_POWER_PWRCTRL_Msk    (0x3UL << SDMMC_POWER_PWRCTRL_Pos)	/*!< 0x00000003 */
#define SDMMC_POWER_PWRCTRL        SDMMC_POWER_PWRCTRL_Msk				/*!<PWRCTRL[1:0] bits (Power supply control bits) */
#define SDMMC_POWER_PWRCTRL_0      (0x1UL << SDMMC_POWER_PWRCTRL_Pos)	/*!< 0x01 */
#define SDMMC_POWER_PWRCTRL_1      (0x2UL << SDMMC_POWER_PWRCTRL_Pos)	/*!< 0x02 */

/******************  Bit definition for SDMMC_CLKCR register  ******************/
#define SDMMC_CLKCR_CLKDIV_Pos     (0U)
#define SDMMC_CLKCR_CLKDIV_Msk     (0xFFUL << SDMMC_CLKCR_CLKDIV_Pos)	/*!< 0x000000FF */
#define SDMMC_CLKCR_CLKDIV         SDMMC_CLKCR_CLKDIV_Msk				/*!<Clock divide factor             */
#define SDMMC_CLKCR_CLKEN_Pos      (8U)
#define SDMMC_CLKCR_CLKEN_Msk      (0x1UL << SDMMC_CLKCR_CLKEN_Pos)	/*!< 0x00000100 */
#define SDMMC_CLKCR_CLKEN          SDMMC_CLKCR_CLKEN_Msk/*!<Clock enable bit                */
#define SDMMC_CLKCR_PWRSAV_Pos     (9U)
#define SDMMC_CLKCR_PWRSAV_Msk     (0x1UL << SDMMC_CLKCR_PWRSAV_Pos)/*!< 0x00000200 */
#define SDMMC_CLKCR_PWRSAV         SDMMC_CLKCR_PWRSAV_Msk	/*!<Power saving configuration bit  */
#define SDMMC_CLKCR_BYPASS_Pos     (10U)
#define SDMMC_CLKCR_BYPASS_Msk     (0x1UL << SDMMC_CLKCR_BYPASS_Pos)/*!< 0x00000400 */
#define SDMMC_CLKCR_BYPASS         SDMMC_CLKCR_BYPASS_Msk	/*!<Clock divider bypass enable bit */

#define SDMMC_CLKCR_WIDBUS_Pos     (11U)
#define SDMMC_CLKCR_WIDBUS_Msk     (0x3UL << SDMMC_CLKCR_WIDBUS_Pos)/*!< 0x00001800 */
#define SDMMC_CLKCR_WIDBUS         SDMMC_CLKCR_WIDBUS_Msk	/*!<WIDBUS[1:0] bits (Wide bus mode enable bit) */
#define SDMMC_CLKCR_WIDBUS_0       (0x1UL << SDMMC_CLKCR_WIDBUS_Pos)/*!< 0x0800 */
#define SDMMC_CLKCR_WIDBUS_1       (0x2UL << SDMMC_CLKCR_WIDBUS_Pos)/*!< 0x1000 */

#define SDMMC_CLKCR_NEGEDGE_Pos    (13U)
#define SDMMC_CLKCR_NEGEDGE_Msk    (0x1UL << SDMMC_CLKCR_NEGEDGE_Pos)	/*!< 0x00002000 */
#define SDMMC_CLKCR_NEGEDGE        SDMMC_CLKCR_NEGEDGE_Msk				/*!<SDMMC_CK dephasing selection bit */
#define SDMMC_CLKCR_HWFC_EN_Pos    (14U)
#define SDMMC_CLKCR_HWFC_EN_Msk    (0x1UL << SDMMC_CLKCR_HWFC_EN_Pos)	/*!< 0x00004000 */
#define SDMMC_CLKCR_HWFC_EN        SDMMC_CLKCR_HWFC_EN_Msk				/*!<HW Flow Control enable          */

/*******************  Bit definition for SDMMC_ARG register  *******************/
#define SDMMC_ARG_CMDARG_Pos    (0U)
#define SDMMC_ARG_CMDARG_Msk    (0xFFFFFFFFUL << SDMMC_ARG_CMDARG_Pos)	/*!< 0xFFFFFFFF */
#define SDMMC_ARG_CMDARG        SDMMC_ARG_CMDARG_Msk					/*!<Command argument */

/*******************  Bit definition for SDMMC_CMD register  *******************/
#define SDMMC_CMD_CMDINDEX_Pos       (0U)
#define SDMMC_CMD_CMDINDEX_Msk       (0x3FUL << SDMMC_CMD_CMDINDEX_Pos)	/*!< 0x0000003F */
#define SDMMC_CMD_CMDINDEX           SDMMC_CMD_CMDINDEX_Msk				/*!<Command Index                               */

#define SDMMC_CMD_WAITRESP_Pos       (6U)
#define SDMMC_CMD_WAITRESP_Msk       (0x3UL << SDMMC_CMD_WAITRESP_Pos)	/*!< 0x000000C0 */
#define SDMMC_CMD_WAITRESP           SDMMC_CMD_WAITRESP_Msk				/*!<WAITRESP[1:0] bits (Wait for response bits) */
#define SDMMC_CMD_WAITRESP_0         (0x1UL << SDMMC_CMD_WAITRESP_Pos)	/*!< 0x0040 */
#define SDMMC_CMD_WAITRESP_1         (0x2UL << SDMMC_CMD_WAITRESP_Pos)	/*!< 0x0080 */

#define SDMMC_CMD_WAITINT_Pos        (8U)
#define SDMMC_CMD_WAITINT_Msk        (0x1UL << SDMMC_CMD_WAITINT_Pos)	/*!< 0x00000100 */
#define SDMMC_CMD_WAITINT            SDMMC_CMD_WAITINT_Msk				/*!<CPSM Waits for Interrupt Request                               */
#define SDMMC_CMD_WAITPEND_Pos       (9U)
#define SDMMC_CMD_WAITPEND_Msk       (0x1UL << SDMMC_CMD_WAITPEND_Pos)	/*!< 0x00000200 */
#define SDMMC_CMD_WAITPEND           SDMMC_CMD_WAITPEND_Msk				/*!<CPSM Waits for ends of data transfer (CmdPend internal signal) */
#define SDMMC_CMD_CPSMEN_Pos         (10U)
#define SDMMC_CMD_CPSMEN_Msk         (0x1UL << SDMMC_CMD_CPSMEN_Pos)/*!< 0x00000400 */
#define SDMMC_CMD_CPSMEN             SDMMC_CMD_CPSMEN_Msk	/*!<Command path state machine (CPSM) Enable bit                   */
#define SDMMC_CMD_SDIOSUSPEND_Pos    (11U)
#define SDMMC_CMD_SDIOSUSPEND_Msk    (0x1UL << SDMMC_CMD_SDIOSUSPEND_Pos)	/*!< 0x00000800 */
#define SDMMC_CMD_SDIOSUSPEND        SDMMC_CMD_SDIOSUSPEND_Msk				/*!<SD I/O suspend command                                         */

/*****************  Bit definition for SDMMC_RESPCMD register  *****************/
#define SDMMC_RESPCMD_RESPCMD_Pos    (0U)
#define SDMMC_RESPCMD_RESPCMD_Msk    (0x3FUL << SDMMC_RESPCMD_RESPCMD_Pos)	/*!< 0x0000003F */
#define SDMMC_RESPCMD_RESPCMD        SDMMC_RESPCMD_RESPCMD_Msk				/*!<Response command index */

/******************  Bit definition for SDMMC_RESP0 register  ******************/
#define SDMMC_RESP0_CARDSTATUS0_Pos    (0U)
#define SDMMC_RESP0_CARDSTATUS0_Msk    (0xFFFFFFFFUL << SDMMC_RESP0_CARDSTATUS0_Pos)/*!< 0xFFFFFFFF */
#define SDMMC_RESP0_CARDSTATUS0        SDMMC_RESP0_CARDSTATUS0_Msk	/*!<Card Status */

/******************  Bit definition for SDMMC_RESP1 register  ******************/
#define SDMMC_RESP1_CARDSTATUS1_Pos    (0U)
#define SDMMC_RESP1_CARDSTATUS1_Msk    (0xFFFFFFFFUL << SDMMC_RESP1_CARDSTATUS1_Pos)/*!< 0xFFFFFFFF */
#define SDMMC_RESP1_CARDSTATUS1        SDMMC_RESP1_CARDSTATUS1_Msk	/*!<Card Status */

/******************  Bit definition for SDMMC_RESP2 register  ******************/
#define SDMMC_RESP2_CARDSTATUS2_Pos    (0U)
#define SDMMC_RESP2_CARDSTATUS2_Msk    (0xFFFFFFFFUL << SDMMC_RESP2_CARDSTATUS2_Pos)/*!< 0xFFFFFFFF */
#define SDMMC_RESP2_CARDSTATUS2        SDMMC_RESP2_CARDSTATUS2_Msk	/*!<Card Status */

/******************  Bit definition for SDMMC_RESP3 register  ******************/
#define SDMMC_RESP3_CARDSTATUS3_Pos    (0U)
#define SDMMC_RESP3_CARDSTATUS3_Msk    (0xFFFFFFFFUL << SDMMC_RESP3_CARDSTATUS3_Pos)/*!< 0xFFFFFFFF */
#define SDMMC_RESP3_CARDSTATUS3        SDMMC_RESP3_CARDSTATUS3_Msk	/*!<Card Status */

/******************  Bit definition for SDMMC_RESP4 register  ******************/
#define SDMMC_RESP4_CARDSTATUS4_Pos    (0U)
#define SDMMC_RESP4_CARDSTATUS4_Msk    (0xFFFFFFFFUL << SDMMC_RESP4_CARDSTATUS4_Pos)/*!< 0xFFFFFFFF */
#define SDMMC_RESP4_CARDSTATUS4        SDMMC_RESP4_CARDSTATUS4_Msk	/*!<Card Status */

/******************  Bit definition for SDMMC_DTIMER register  *****************/
#define SDMMC_DTIMER_DATATIME_Pos    (0U)
#define SDMMC_DTIMER_DATATIME_Msk    (0xFFFFFFFFUL << SDMMC_DTIMER_DATATIME_Pos)/*!< 0xFFFFFFFF */
#define SDMMC_DTIMER_DATATIME        SDMMC_DTIMER_DATATIME_Msk	/*!<Data timeout period. */

/******************  Bit definition for SDMMC_DLEN register  *******************/
#define SDMMC_DLEN_DATALENGTH_Pos    (0U)
#define SDMMC_DLEN_DATALENGTH_Msk    (0x1FFFFFFUL << SDMMC_DLEN_DATALENGTH_Pos)	/*!< 0x01FFFFFF */
#define SDMMC_DLEN_DATALENGTH        SDMMC_DLEN_DATALENGTH_Msk					/*!<Data length value    */

/******************  Bit definition for SDMMC_DCTRL register  ******************/
#define SDMMC_DCTRL_DTEN_Pos          (0U)
#define SDMMC_DCTRL_DTEN_Msk          (0x1UL << SDMMC_DCTRL_DTEN_Pos)	/*!< 0x00000001 */
#define SDMMC_DCTRL_DTEN              SDMMC_DCTRL_DTEN_Msk				/*!<Data transfer enabled bit         */
#define SDMMC_DCTRL_DTDIR_Pos         (1U)
#define SDMMC_DCTRL_DTDIR_Msk         (0x1UL << SDMMC_DCTRL_DTDIR_Pos)	/*!< 0x00000002 */
#define SDMMC_DCTRL_DTDIR             SDMMC_DCTRL_DTDIR_Msk				/*!<Data transfer direction selection */
#define SDMMC_DCTRL_DTMODE_Pos        (2U)
#define SDMMC_DCTRL_DTMODE_Msk        (0x1UL << SDMMC_DCTRL_DTMODE_Pos)	/*!< 0x00000004 */
#define SDMMC_DCTRL_DTMODE            SDMMC_DCTRL_DTMODE_Msk/*!<Data transfer mode selection      */
#define SDMMC_DCTRL_DMAEN_Pos         (3U)
#define SDMMC_DCTRL_DMAEN_Msk         (0x1UL << SDMMC_DCTRL_DMAEN_Pos)	/*!< 0x00000008 */
#define SDMMC_DCTRL_DMAEN             SDMMC_DCTRL_DMAEN_Msk				/*!<DMA enabled bit                   */

#define SDMMC_DCTRL_DBLOCKSIZE_Pos    (4U)
#define SDMMC_DCTRL_DBLOCKSIZE_Msk    (0xFUL << SDMMC_DCTRL_DBLOCKSIZE_Pos)	/*!< 0x000000F0 */
#define SDMMC_DCTRL_DBLOCKSIZE        SDMMC_DCTRL_DBLOCKSIZE_Msk/*!<DBLOCKSIZE[3:0] bits (Data block size) */
#define SDMMC_DCTRL_DBLOCKSIZE_0      (0x1UL << SDMMC_DCTRL_DBLOCKSIZE_Pos)	/*!< 0x0010 */
#define SDMMC_DCTRL_DBLOCKSIZE_1      (0x2UL << SDMMC_DCTRL_DBLOCKSIZE_Pos)	/*!< 0x0020 */
#define SDMMC_DCTRL_DBLOCKSIZE_2      (0x4UL << SDMMC_DCTRL_DBLOCKSIZE_Pos)	/*!< 0x0040 */
#define SDMMC_DCTRL_DBLOCKSIZE_3      (0x8UL << SDMMC_DCTRL_DBLOCKSIZE_Pos)	/*!< 0x0080 */

#define SDMMC_DCTRL_RWSTART_Pos       (8U)
#define SDMMC_DCTRL_RWSTART_Msk       (0x1UL << SDMMC_DCTRL_RWSTART_Pos)/*!< 0x00000100 */
#define SDMMC_DCTRL_RWSTART           SDMMC_DCTRL_RWSTART_Msk	/*!<Read wait start         */
#define SDMMC_DCTRL_RWSTOP_Pos        (9U)
#define SDMMC_DCTRL_RWSTOP_Msk        (0x1UL << SDMMC_DCTRL_RWSTOP_Pos)	/*!< 0x00000200 */
#define SDMMC_DCTRL_RWSTOP            SDMMC_DCTRL_RWSTOP_Msk/*!<Read wait stop          */
#define SDMMC_DCTRL_RWMOD_Pos         (10U)
#define SDMMC_DCTRL_RWMOD_Msk         (0x1UL << SDMMC_DCTRL_RWMOD_Pos)	/*!< 0x00000400 */
#define SDMMC_DCTRL_RWMOD             SDMMC_DCTRL_RWMOD_Msk				/*!<Read wait mode          */
#define SDMMC_DCTRL_SDIOEN_Pos        (11U)
#define SDMMC_DCTRL_SDIOEN_Msk        (0x1UL << SDMMC_DCTRL_SDIOEN_Pos)	/*!< 0x00000800 */
#define SDMMC_DCTRL_SDIOEN            SDMMC_DCTRL_SDIOEN_Msk/*!<SD I/O enable functions */

/******************  Bit definition for SDMMC_DCOUNT register  *****************/
#define SDMMC_DCOUNT_DATACOUNT_Pos    (0U)
#define SDMMC_DCOUNT_DATACOUNT_Msk    (0x1FFFFFFUL << SDMMC_DCOUNT_DATACOUNT_Pos)	/*!< 0x01FFFFFF */
#define SDMMC_DCOUNT_DATACOUNT        SDMMC_DCOUNT_DATACOUNT_Msk					/*!<Data count value */

/******************  Bit definition for SDMMC_STA registe  ********************/
#define SDMMC_STA_CCRCFAIL_Pos    (0U)
#define SDMMC_STA_CCRCFAIL_Msk    (0x1UL << SDMMC_STA_CCRCFAIL_Pos)	/*!< 0x00000001 */
#define SDMMC_STA_CCRCFAIL        SDMMC_STA_CCRCFAIL_Msk/*!<Command response received (CRC check failed)  */
#define SDMMC_STA_DCRCFAIL_Pos    (1U)
#define SDMMC_STA_DCRCFAIL_Msk    (0x1UL << SDMMC_STA_DCRCFAIL_Pos)	/*!< 0x00000002 */
#define SDMMC_STA_DCRCFAIL        SDMMC_STA_DCRCFAIL_Msk/*!<Data block sent/received (CRC check failed)   */
#define SDMMC_STA_CTIMEOUT_Pos    (2U)
#define SDMMC_STA_CTIMEOUT_Msk    (0x1UL << SDMMC_STA_CTIMEOUT_Pos)	/*!< 0x00000004 */
#define SDMMC_STA_CTIMEOUT        SDMMC_STA_CTIMEOUT_Msk/*!<Command response timeout                      */
#define SDMMC_STA_DTIMEOUT_Pos    (3U)
#define SDMMC_STA_DTIMEOUT_Msk    (0x1UL << SDMMC_STA_DTIMEOUT_Pos)	/*!< 0x00000008 */
#define SDMMC_STA_DTIMEOUT        SDMMC_STA_DTIMEOUT_Msk/*!<Data timeout                                  */
#define SDMMC_STA_TXUNDERR_Pos    (4U)
#define SDMMC_STA_TXUNDERR_Msk    (0x1UL << SDMMC_STA_TXUNDERR_Pos)	/*!< 0x00000010 */
#define SDMMC_STA_TXUNDERR        SDMMC_STA_TXUNDERR_Msk/*!<Transmit FIFO underrun error                  */
#define SDMMC_STA_RXOVERR_Pos     (5U)
#define SDMMC_STA_RXOVERR_Msk     (0x1UL << SDMMC_STA_RXOVERR_Pos)	/*!< 0x00000020 */
#define SDMMC_STA_RXOVERR         SDMMC_STA_RXOVERR_Msk				/*!<Received FIFO overrun error                   */
#define SDMMC_STA_CMDREND_Pos     (6U)
#define SDMMC_STA_CMDREND_Msk     (0x1UL << SDMMC_STA_CMDREND_Pos)	/*!< 0x00000040 */
#define SDMMC_STA_CMDREND         SDMMC_STA_CMDREND_Msk				/*!<Command response received (CRC check passed)  */
#define SDMMC_STA_CMDSENT_Pos     (7U)
#define SDMMC_STA_CMDSENT_Msk     (0x1UL << SDMMC_STA_CMDSENT_Pos)	/*!< 0x00000080 */
#define SDMMC_STA_CMDSENT         SDMMC_STA_CMDSENT_Msk				/*!<Command sent (no response required)           */
#define SDMMC_STA_DATAEND_Pos     (8U)
#define SDMMC_STA_DATAEND_Msk     (0x1UL << SDMMC_STA_DATAEND_Pos)	/*!< 0x00000100 */
#define SDMMC_STA_DATAEND         SDMMC_STA_DATAEND_Msk				/*!<Data end (data counter, SDIDCOUNT, is zero)   */
#define SDMMC_STA_DBCKEND_Pos     (10U)
#define SDMMC_STA_DBCKEND_Msk     (0x1UL << SDMMC_STA_DBCKEND_Pos)	/*!< 0x00000400 */
#define SDMMC_STA_DBCKEND         SDMMC_STA_DBCKEND_Msk				/*!<Data block sent/received (CRC check passed)   */
#define SDMMC_STA_CMDACT_Pos      (11U)
#define SDMMC_STA_CMDACT_Msk      (0x1UL << SDMMC_STA_CMDACT_Pos)	/*!< 0x00000800 */
#define SDMMC_STA_CMDACT          SDMMC_STA_CMDACT_Msk				/*!<Command transfer in progress                  */
#define SDMMC_STA_TXACT_Pos       (12U)
#define SDMMC_STA_TXACT_Msk       (0x1UL << SDMMC_STA_TXACT_Pos)/*!< 0x00001000 */
#define SDMMC_STA_TXACT           SDMMC_STA_TXACT_Msk	/*!<Data transmit in progress                     */
#define SDMMC_STA_RXACT_Pos       (13U)
#define SDMMC_STA_RXACT_Msk       (0x1UL << SDMMC_STA_RXACT_Pos)/*!< 0x00002000 */
#define SDMMC_STA_RXACT           SDMMC_STA_RXACT_Msk	/*!<Data receive in progress                      */
#define SDMMC_STA_TXFIFOHE_Pos    (14U)
#define SDMMC_STA_TXFIFOHE_Msk    (0x1UL << SDMMC_STA_TXFIFOHE_Pos)	/*!< 0x00004000 */
#define SDMMC_STA_TXFIFOHE        SDMMC_STA_TXFIFOHE_Msk/*!<Transmit FIFO Half Empty: at least 8 words can be written into the FIFO */
#define SDMMC_STA_RXFIFOHF_Pos    (15U)
#define SDMMC_STA_RXFIFOHF_Msk    (0x1UL << SDMMC_STA_RXFIFOHF_Pos)	/*!< 0x00008000 */
#define SDMMC_STA_RXFIFOHF        SDMMC_STA_RXFIFOHF_Msk/*!<Receive FIFO Half Full: there are at least 8 words in the FIFO */
#define SDMMC_STA_TXFIFOF_Pos     (16U)
#define SDMMC_STA_TXFIFOF_Msk     (0x1UL << SDMMC_STA_TXFIFOF_Pos)	/*!< 0x00010000 */
#define SDMMC_STA_TXFIFOF         SDMMC_STA_TXFIFOF_Msk				/*!<Transmit FIFO full                            */
#define SDMMC_STA_RXFIFOF_Pos     (17U)
#define SDMMC_STA_RXFIFOF_Msk     (0x1UL << SDMMC_STA_RXFIFOF_Pos)	/*!< 0x00020000 */
#define SDMMC_STA_RXFIFOF         SDMMC_STA_RXFIFOF_Msk				/*!<Receive FIFO full                             */
#define SDMMC_STA_TXFIFOE_Pos     (18U)
#define SDMMC_STA_TXFIFOE_Msk     (0x1UL << SDMMC_STA_TXFIFOE_Pos)	/*!< 0x00040000 */
#define SDMMC_STA_TXFIFOE         SDMMC_STA_TXFIFOE_Msk				/*!<Transmit FIFO empty                           */
#define SDMMC_STA_RXFIFOE_Pos     (19U)
#define SDMMC_STA_RXFIFOE_Msk     (0x1UL << SDMMC_STA_RXFIFOE_Pos)	/*!< 0x00080000 */
#define SDMMC_STA_RXFIFOE         SDMMC_STA_RXFIFOE_Msk				/*!<Receive FIFO empty                            */
#define SDMMC_STA_TXDAVL_Pos      (20U)
#define SDMMC_STA_TXDAVL_Msk      (0x1UL << SDMMC_STA_TXDAVL_Pos)	/*!< 0x00100000 */
#define SDMMC_STA_TXDAVL          SDMMC_STA_TXDAVL_Msk				/*!<Data available in transmit FIFO               */
#define SDMMC_STA_RXDAVL_Pos      (21U)
#define SDMMC_STA_RXDAVL_Msk      (0x1UL << SDMMC_STA_RXDAVL_Pos)	/*!< 0x00200000 */
#define SDMMC_STA_RXDAVL          SDMMC_STA_RXDAVL_Msk				/*!<Data available in receive FIFO                */
#define SDMMC_STA_SDIOIT_Pos      (22U)
#define SDMMC_STA_SDIOIT_Msk      (0x1UL << SDMMC_STA_SDIOIT_Pos)	/*!< 0x00400000 */
#define SDMMC_STA_SDIOIT          SDMMC_STA_SDIOIT_Msk				/*!<SDMMC interrupt received                       */

/*******************  Bit definition for SDMMC_ICR register  *******************/
#define SDMMC_ICR_CCRCFAILC_Pos    (0U)
#define SDMMC_ICR_CCRCFAILC_Msk    (0x1UL << SDMMC_ICR_CCRCFAILC_Pos)	/*!< 0x00000001 */
#define SDMMC_ICR_CCRCFAILC        SDMMC_ICR_CCRCFAILC_Msk				/*!<CCRCFAIL flag clear bit */
#define SDMMC_ICR_DCRCFAILC_Pos    (1U)
#define SDMMC_ICR_DCRCFAILC_Msk    (0x1UL << SDMMC_ICR_DCRCFAILC_Pos)	/*!< 0x00000002 */
#define SDMMC_ICR_DCRCFAILC        SDMMC_ICR_DCRCFAILC_Msk				/*!<DCRCFAIL flag clear bit */
#define SDMMC_ICR_CTIMEOUTC_Pos    (2U)
#define SDMMC_ICR_CTIMEOUTC_Msk    (0x1UL << SDMMC_ICR_CTIMEOUTC_Pos)	/*!< 0x00000004 */
#define SDMMC_ICR_CTIMEOUTC        SDMMC_ICR_CTIMEOUTC_Msk				/*!<CTIMEOUT flag clear bit */
#define SDMMC_ICR_DTIMEOUTC_Pos    (3U)
#define SDMMC_ICR_DTIMEOUTC_Msk    (0x1UL << SDMMC_ICR_DTIMEOUTC_Pos)	/*!< 0x00000008 */
#define SDMMC_ICR_DTIMEOUTC        SDMMC_ICR_DTIMEOUTC_Msk				/*!<DTIMEOUT flag clear bit */
#define SDMMC_ICR_TXUNDERRC_Pos    (4U)
#define SDMMC_ICR_TXUNDERRC_Msk    (0x1UL << SDMMC_ICR_TXUNDERRC_Pos)	/*!< 0x00000010 */
#define SDMMC_ICR_TXUNDERRC        SDMMC_ICR_TXUNDERRC_Msk				/*!<TXUNDERR flag clear bit */
#define SDMMC_ICR_RXOVERRC_Pos     (5U)
#define SDMMC_ICR_RXOVERRC_Msk     (0x1UL << SDMMC_ICR_RXOVERRC_Pos)/*!< 0x00000020 */
#define SDMMC_ICR_RXOVERRC         SDMMC_ICR_RXOVERRC_Msk	/*!<RXOVERR flag clear bit  */
#define SDMMC_ICR_CMDRENDC_Pos     (6U)
#define SDMMC_ICR_CMDRENDC_Msk     (0x1UL << SDMMC_ICR_CMDRENDC_Pos)/*!< 0x00000040 */
#define SDMMC_ICR_CMDRENDC         SDMMC_ICR_CMDRENDC_Msk	/*!<CMDREND flag clear bit  */
#define SDMMC_ICR_CMDSENTC_Pos     (7U)
#define SDMMC_ICR_CMDSENTC_Msk     (0x1UL << SDMMC_ICR_CMDSENTC_Pos)/*!< 0x00000080 */
#define SDMMC_ICR_CMDSENTC         SDMMC_ICR_CMDSENTC_Msk	/*!<CMDSENT flag clear bit  */
#define SDMMC_ICR_DATAENDC_Pos     (8U)
#define SDMMC_ICR_DATAENDC_Msk     (0x1UL << SDMMC_ICR_DATAENDC_Pos)/*!< 0x00000100 */
#define SDMMC_ICR_DATAENDC         SDMMC_ICR_DATAENDC_Msk	/*!<DATAEND flag clear bit  */
#define SDMMC_ICR_DBCKENDC_Pos     (10U)
#define SDMMC_ICR_DBCKENDC_Msk     (0x1UL << SDMMC_ICR_DBCKENDC_Pos)/*!< 0x00000400 */
#define SDMMC_ICR_DBCKENDC         SDMMC_ICR_DBCKENDC_Msk	/*!<DBCKEND flag clear bit  */
#define SDMMC_ICR_SDIOITC_Pos      (22U)
#define SDMMC_ICR_SDIOITC_Msk      (0x1UL << SDMMC_ICR_SDIOITC_Pos)	/*!< 0x00400000 */
#define SDMMC_ICR_SDIOITC          SDMMC_ICR_SDIOITC_Msk/*!<SDMMCIT flag clear bit   */

/******************  Bit definition for SDMMC_MASK register  *******************/
#define SDMMC_MASK_CCRCFAILIE_Pos    (0U)
#define SDMMC_MASK_CCRCFAILIE_Msk    (0x1UL << SDMMC_MASK_CCRCFAILIE_Pos)	/*!< 0x00000001 */
#define SDMMC_MASK_CCRCFAILIE        SDMMC_MASK_CCRCFAILIE_Msk				/*!<Command CRC Fail Interrupt Enable          */
#define SDMMC_MASK_DCRCFAILIE_Pos    (1U)
#define SDMMC_MASK_DCRCFAILIE_Msk    (0x1UL << SDMMC_MASK_DCRCFAILIE_Pos)	/*!< 0x00000002 */
#define SDMMC_MASK_DCRCFAILIE        SDMMC_MASK_DCRCFAILIE_Msk				/*!<Data CRC Fail Interrupt Enable             */
#define SDMMC_MASK_CTIMEOUTIE_Pos    (2U)
#define SDMMC_MASK_CTIMEOUTIE_Msk    (0x1UL << SDMMC_MASK_CTIMEOUTIE_Pos)	/*!< 0x00000004 */
#define SDMMC_MASK_CTIMEOUTIE        SDMMC_MASK_CTIMEOUTIE_Msk				/*!<Command TimeOut Interrupt Enable           */
#define SDMMC_MASK_DTIMEOUTIE_Pos    (3U)
#define SDMMC_MASK_DTIMEOUTIE_Msk    (0x1UL << SDMMC_MASK_DTIMEOUTIE_Pos)	/*!< 0x00000008 */
#define SDMMC_MASK_DTIMEOUTIE        SDMMC_MASK_DTIMEOUTIE_Msk				/*!<Data TimeOut Interrupt Enable              */
#define SDMMC_MASK_TXUNDERRIE_Pos    (4U)
#define SDMMC_MASK_TXUNDERRIE_Msk    (0x1UL << SDMMC_MASK_TXUNDERRIE_Pos)	/*!< 0x00000010 */
#define SDMMC_MASK_TXUNDERRIE        SDMMC_MASK_TXUNDERRIE_Msk				/*!<Tx FIFO UnderRun Error Interrupt Enable    */
#define SDMMC_MASK_RXOVERRIE_Pos     (5U)
#define SDMMC_MASK_RXOVERRIE_Msk     (0x1UL << SDMMC_MASK_RXOVERRIE_Pos)/*!< 0x00000020 */
#define SDMMC_MASK_RXOVERRIE         SDMMC_MASK_RXOVERRIE_Msk	/*!<Rx FIFO OverRun Error Interrupt Enable     */
#define SDMMC_MASK_CMDRENDIE_Pos     (6U)
#define SDMMC_MASK_CMDRENDIE_Msk     (0x1UL << SDMMC_MASK_CMDRENDIE_Pos)/*!< 0x00000040 */
#define SDMMC_MASK_CMDRENDIE         SDMMC_MASK_CMDRENDIE_Msk	/*!<Command Response Received Interrupt Enable */
#define SDMMC_MASK_CMDSENTIE_Pos     (7U)
#define SDMMC_MASK_CMDSENTIE_Msk     (0x1UL << SDMMC_MASK_CMDSENTIE_Pos)/*!< 0x00000080 */
#define SDMMC_MASK_CMDSENTIE         SDMMC_MASK_CMDSENTIE_Msk	/*!<Command Sent Interrupt Enable              */
#define SDMMC_MASK_DATAENDIE_Pos     (8U)
#define SDMMC_MASK_DATAENDIE_Msk     (0x1UL << SDMMC_MASK_DATAENDIE_Pos)/*!< 0x00000100 */
#define SDMMC_MASK_DATAENDIE         SDMMC_MASK_DATAENDIE_Msk	/*!<Data End Interrupt Enable                  */
#define SDMMC_MASK_DBCKENDIE_Pos     (10U)
#define SDMMC_MASK_DBCKENDIE_Msk     (0x1UL << SDMMC_MASK_DBCKENDIE_Pos)/*!< 0x00000400 */
#define SDMMC_MASK_DBCKENDIE         SDMMC_MASK_DBCKENDIE_Msk	/*!<Data Block End Interrupt Enable            */
#define SDMMC_MASK_CMDACTIE_Pos      (11U)
#define SDMMC_MASK_CMDACTIE_Msk      (0x1UL << SDMMC_MASK_CMDACTIE_Pos)	/*!< 0x00000800 */
#define SDMMC_MASK_CMDACTIE          SDMMC_MASK_CMDACTIE_Msk/*!<CCommand Acting Interrupt Enable           */
#define SDMMC_MASK_TXACTIE_Pos       (12U)
#define SDMMC_MASK_TXACTIE_Msk       (0x1UL << SDMMC_MASK_TXACTIE_Pos)	/*!< 0x00001000 */
#define SDMMC_MASK_TXACTIE           SDMMC_MASK_TXACTIE_Msk				/*!<Data Transmit Acting Interrupt Enable      */
#define SDMMC_MASK_RXACTIE_Pos       (13U)
#define SDMMC_MASK_RXACTIE_Msk       (0x1UL << SDMMC_MASK_RXACTIE_Pos)	/*!< 0x00002000 */
#define SDMMC_MASK_RXACTIE           SDMMC_MASK_RXACTIE_Msk				/*!<Data receive acting interrupt enabled      */
#define SDMMC_MASK_TXFIFOHEIE_Pos    (14U)
#define SDMMC_MASK_TXFIFOHEIE_Msk    (0x1UL << SDMMC_MASK_TXFIFOHEIE_Pos)	/*!< 0x00004000 */
#define SDMMC_MASK_TXFIFOHEIE        SDMMC_MASK_TXFIFOHEIE_Msk				/*!<Tx FIFO Half Empty interrupt Enable        */
#define SDMMC_MASK_RXFIFOHFIE_Pos    (15U)
#define SDMMC_MASK_RXFIFOHFIE_Msk    (0x1UL << SDMMC_MASK_RXFIFOHFIE_Pos)	/*!< 0x00008000 */
#define SDMMC_MASK_RXFIFOHFIE        SDMMC_MASK_RXFIFOHFIE_Msk				/*!<Rx FIFO Half Full interrupt Enable         */
#define SDMMC_MASK_TXFIFOFIE_Pos     (16U)
#define SDMMC_MASK_TXFIFOFIE_Msk     (0x1UL << SDMMC_MASK_TXFIFOFIE_Pos)/*!< 0x00010000 */
#define SDMMC_MASK_TXFIFOFIE         SDMMC_MASK_TXFIFOFIE_Msk	/*!<Tx FIFO Full interrupt Enable              */
#define SDMMC_MASK_RXFIFOFIE_Pos     (17U)
#define SDMMC_MASK_RXFIFOFIE_Msk     (0x1UL << SDMMC_MASK_RXFIFOFIE_Pos)/*!< 0x00020000 */
#define SDMMC_MASK_RXFIFOFIE         SDMMC_MASK_RXFIFOFIE_Msk	/*!<Rx FIFO Full interrupt Enable              */
#define SDMMC_MASK_TXFIFOEIE_Pos     (18U)
#define SDMMC_MASK_TXFIFOEIE_Msk     (0x1UL << SDMMC_MASK_TXFIFOEIE_Pos)/*!< 0x00040000 */
#define SDMMC_MASK_TXFIFOEIE         SDMMC_MASK_TXFIFOEIE_Msk	/*!<Tx FIFO Empty interrupt Enable             */
#define SDMMC_MASK_RXFIFOEIE_Pos     (19U)
#define SDMMC_MASK_RXFIFOEIE_Msk     (0x1UL << SDMMC_MASK_RXFIFOEIE_Pos)/*!< 0x00080000 */
#define SDMMC_MASK_RXFIFOEIE         SDMMC_MASK_RXFIFOEIE_Msk	/*!<Rx FIFO Empty interrupt Enable             */
#define SDMMC_MASK_TXDAVLIE_Pos      (20U)
#define SDMMC_MASK_TXDAVLIE_Msk      (0x1UL << SDMMC_MASK_TXDAVLIE_Pos)	/*!< 0x00100000 */
#define SDMMC_MASK_TXDAVLIE          SDMMC_MASK_TXDAVLIE_Msk/*!<Data available in Tx FIFO interrupt Enable */
#define SDMMC_MASK_RXDAVLIE_Pos      (21U)
#define SDMMC_MASK_RXDAVLIE_Msk      (0x1UL << SDMMC_MASK_RXDAVLIE_Pos)	/*!< 0x00200000 */
#define SDMMC_MASK_RXDAVLIE          SDMMC_MASK_RXDAVLIE_Msk/*!<Data available in Rx FIFO interrupt Enable */
#define SDMMC_MASK_SDIOITIE_Pos      (22U)
#define SDMMC_MASK_SDIOITIE_Msk      (0x1UL << SDMMC_MASK_SDIOITIE_Pos)	/*!< 0x00400000 */
#define SDMMC_MASK_SDIOITIE          SDMMC_MASK_SDIOITIE_Msk/*!<SDMMC Mode Interrupt Received interrupt Enable */

/*****************  Bit definition for SDMMC_FIFOCNT register  *****************/
#define SDMMC_FIFOCNT_FIFOCOUNT_Pos    (0U)
#define SDMMC_FIFOCNT_FIFOCOUNT_Msk    (0xFFFFFFUL << SDMMC_FIFOCNT_FIFOCOUNT_Pos)	/*!< 0x00FFFFFF */
#define SDMMC_FIFOCNT_FIFOCOUNT        SDMMC_FIFOCNT_FIFOCOUNT_Msk					/*!<Remaining number of words to be written to or read from the FIFO */

/******************  Bit definition for SDMMC_FIFO register  *******************/
#define SDMMC_FIFO_FIFODATA_Pos    (0U)
#define SDMMC_FIFO_FIFODATA_Msk    (0xFFFFFFFFUL << SDMMC_FIFO_FIFODATA_Pos)/*!< 0xFFFFFFFF */
#define SDMMC_FIFO_FIFODATA        SDMMC_FIFO_FIFODATA_Msk	/*!<Receive and transmit FIFO data */

/******************************************************************************/
/*                                                                            */
/*                        Serial Peripheral Interface (SPI)                   */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for SPI_CR1 register  ********************/
#define SPI_CR1_CPHA_Pos        (0U)
#define SPI_CR1_CPHA_Msk        (0x1UL << SPI_CR1_CPHA_Pos)	/*!< 0x00000001 */
#define SPI_CR1_CPHA            SPI_CR1_CPHA_Msk/*!< Clock Phase                        */
#define SPI_CR1_CPOL_Pos        (1U)
#define SPI_CR1_CPOL_Msk        (0x1UL << SPI_CR1_CPOL_Pos)	/*!< 0x00000002 */
#define SPI_CR1_CPOL            SPI_CR1_CPOL_Msk/*!< Clock Polarity                     */
#define SPI_CR1_MSTR_Pos        (2U)
#define SPI_CR1_MSTR_Msk        (0x1UL << SPI_CR1_MSTR_Pos)	/*!< 0x00000004 */
#define SPI_CR1_MSTR            SPI_CR1_MSTR_Msk/*!< Master Selection                   */
#define SPI_CR1_BR_Pos          (3U)
#define SPI_CR1_BR_Msk          (0x7UL << SPI_CR1_BR_Pos)	/*!< 0x00000038 */
#define SPI_CR1_BR              SPI_CR1_BR_Msk				/*!< BR[2:0] bits (Baud Rate Control)   */
#define SPI_CR1_BR_0            (0x1UL << SPI_CR1_BR_Pos)	/*!< 0x00000008 */
#define SPI_CR1_BR_1            (0x2UL << SPI_CR1_BR_Pos)	/*!< 0x00000010 */
#define SPI_CR1_BR_2            (0x4UL << SPI_CR1_BR_Pos)	/*!< 0x00000020 */
#define SPI_CR1_SPE_Pos         (6U)
#define SPI_CR1_SPE_Msk         (0x1UL << SPI_CR1_SPE_Pos)	/*!< 0x00000040 */
#define SPI_CR1_SPE             SPI_CR1_SPE_Msk				/*!< SPI Enable                          */
#define SPI_CR1_LSBFIRST_Pos    (7U)
#define SPI_CR1_LSBFIRST_Msk    (0x1UL << SPI_CR1_LSBFIRST_Pos)	/*!< 0x00000080 */
#define SPI_CR1_LSBFIRST        SPI_CR1_LSBFIRST_Msk/*!< Frame Format                        */
#define SPI_CR1_SSI_Pos         (8U)
#define SPI_CR1_SSI_Msk         (0x1UL << SPI_CR1_SSI_Pos)	/*!< 0x00000100 */
#define SPI_CR1_SSI             SPI_CR1_SSI_Msk				/*!< Internal slave select               */
#define SPI_CR1_SSM_Pos         (9U)
#define SPI_CR1_SSM_Msk         (0x1UL << SPI_CR1_SSM_Pos)	/*!< 0x00000200 */
#define SPI_CR1_SSM             SPI_CR1_SSM_Msk				/*!< Software slave management           */
#define SPI_CR1_RXONLY_Pos      (10U)
#define SPI_CR1_RXONLY_Msk      (0x1UL << SPI_CR1_RXONLY_Pos)	/*!< 0x00000400 */
#define SPI_CR1_RXONLY          SPI_CR1_RXONLY_Msk				/*!< Receive only                        */
#define SPI_CR1_CRCL_Pos        (11U)
#define SPI_CR1_CRCL_Msk        (0x1UL << SPI_CR1_CRCL_Pos)	/*!< 0x00000800 */
#define SPI_CR1_CRCL            SPI_CR1_CRCL_Msk/*!< CRC Length                          */
#define SPI_CR1_CRCNEXT_Pos     (12U)
#define SPI_CR1_CRCNEXT_Msk     (0x1UL << SPI_CR1_CRCNEXT_Pos)	/*!< 0x00001000 */
#define SPI_CR1_CRCNEXT         SPI_CR1_CRCNEXT_Msk				/*!< Transmit CRC next                   */
#define SPI_CR1_CRCEN_Pos       (13U)
#define SPI_CR1_CRCEN_Msk       (0x1UL << SPI_CR1_CRCEN_Pos)/*!< 0x00002000 */
#define SPI_CR1_CRCEN           SPI_CR1_CRCEN_Msk	/*!< Hardware CRC calculation enable     */
#define SPI_CR1_BIDIOE_Pos      (14U)
#define SPI_CR1_BIDIOE_Msk      (0x1UL << SPI_CR1_BIDIOE_Pos)	/*!< 0x00004000 */
#define SPI_CR1_BIDIOE          SPI_CR1_BIDIOE_Msk				/*!< Output enable in bidirectional mode */
#define SPI_CR1_BIDIMODE_Pos    (15U)
#define SPI_CR1_BIDIMODE_Msk    (0x1UL << SPI_CR1_BIDIMODE_Pos)	/*!< 0x00008000 */
#define SPI_CR1_BIDIMODE        SPI_CR1_BIDIMODE_Msk/*!< Bidirectional data mode enable      */

/*******************  Bit definition for SPI_CR2 register  ********************/
#define SPI_CR2_RXDMAEN_Pos    (0U)
#define SPI_CR2_RXDMAEN_Msk    (0x1UL << SPI_CR2_RXDMAEN_Pos)	/*!< 0x00000001 */
#define SPI_CR2_RXDMAEN        SPI_CR2_RXDMAEN_Msk				/*!< Rx Buffer DMA Enable                 */
#define SPI_CR2_TXDMAEN_Pos    (1U)
#define SPI_CR2_TXDMAEN_Msk    (0x1UL << SPI_CR2_TXDMAEN_Pos)	/*!< 0x00000002 */
#define SPI_CR2_TXDMAEN        SPI_CR2_TXDMAEN_Msk				/*!< Tx Buffer DMA Enable                 */
#define SPI_CR2_SSOE_Pos       (2U)
#define SPI_CR2_SSOE_Msk       (0x1UL << SPI_CR2_SSOE_Pos)	/*!< 0x00000004 */
#define SPI_CR2_SSOE           SPI_CR2_SSOE_Msk				/*!< SS Output Enable                     */
#define SPI_CR2_NSSP_Pos       (3U)
#define SPI_CR2_NSSP_Msk       (0x1UL << SPI_CR2_NSSP_Pos)	/*!< 0x00000008 */
#define SPI_CR2_NSSP           SPI_CR2_NSSP_Msk				/*!< NSS pulse management Enable          */
#define SPI_CR2_FRF_Pos        (4U)
#define SPI_CR2_FRF_Msk        (0x1UL << SPI_CR2_FRF_Pos)	/*!< 0x00000010 */
#define SPI_CR2_FRF            SPI_CR2_FRF_Msk				/*!< Frame Format Enable                  */
#define SPI_CR2_ERRIE_Pos      (5U)
#define SPI_CR2_ERRIE_Msk      (0x1UL << SPI_CR2_ERRIE_Pos)	/*!< 0x00000020 */
#define SPI_CR2_ERRIE          SPI_CR2_ERRIE_Msk/*!< Error Interrupt Enable               */
#define SPI_CR2_RXNEIE_Pos     (6U)
#define SPI_CR2_RXNEIE_Msk     (0x1UL << SPI_CR2_RXNEIE_Pos)/*!< 0x00000040 */
#define SPI_CR2_RXNEIE         SPI_CR2_RXNEIE_Msk	/*!< RX buffer Not Empty Interrupt Enable */
#define SPI_CR2_TXEIE_Pos      (7U)
#define SPI_CR2_TXEIE_Msk      (0x1UL << SPI_CR2_TXEIE_Pos)	/*!< 0x00000080 */
#define SPI_CR2_TXEIE          SPI_CR2_TXEIE_Msk/*!< Tx buffer Empty Interrupt Enable     */
#define SPI_CR2_DS_Pos         (8U)
#define SPI_CR2_DS_Msk         (0xFUL << SPI_CR2_DS_Pos)/*!< 0x00000F00 */
#define SPI_CR2_DS             SPI_CR2_DS_Msk	/*!< DS[3:0] Data Size                    */
#define SPI_CR2_DS_0           (0x1UL << SPI_CR2_DS_Pos)/*!< 0x00000100 */
#define SPI_CR2_DS_1           (0x2UL << SPI_CR2_DS_Pos)/*!< 0x00000200 */
#define SPI_CR2_DS_2           (0x4UL << SPI_CR2_DS_Pos)/*!< 0x00000400 */
#define SPI_CR2_DS_3           (0x8UL << SPI_CR2_DS_Pos)/*!< 0x00000800 */
#define SPI_CR2_FRXTH_Pos      (12U)
#define SPI_CR2_FRXTH_Msk      (0x1UL << SPI_CR2_FRXTH_Pos)	/*!< 0x00001000 */
#define SPI_CR2_FRXTH          SPI_CR2_FRXTH_Msk/*!< FIFO reception Threshold           */
#define SPI_CR2_LDMARX_Pos     (13U)
#define SPI_CR2_LDMARX_Msk     (0x1UL << SPI_CR2_LDMARX_Pos)/*!< 0x00002000 */
#define SPI_CR2_LDMARX         SPI_CR2_LDMARX_Msk	/*!< Last DMA transfer for reception    */
#define SPI_CR2_LDMATX_Pos     (14U)
#define SPI_CR2_LDMATX_Msk     (0x1UL << SPI_CR2_LDMATX_Pos)/*!< 0x00004000 */
#define SPI_CR2_LDMATX         SPI_CR2_LDMATX_Msk	/*!< Last DMA transfer for transmission */

/********************  Bit definition for SPI_SR register  ********************/
#define SPI_SR_RXNE_Pos      (0U)
#define SPI_SR_RXNE_Msk      (0x1UL << SPI_SR_RXNE_Pos)	/*!< 0x00000001 */
#define SPI_SR_RXNE          SPI_SR_RXNE_Msk/*!< Receive buffer Not Empty  */
#define SPI_SR_TXE_Pos       (1U)
#define SPI_SR_TXE_Msk       (0x1UL << SPI_SR_TXE_Pos)	/*!< 0x00000002 */
#define SPI_SR_TXE           SPI_SR_TXE_Msk				/*!< Transmit buffer Empty     */
#define SPI_SR_CHSIDE_Pos    (2U)
#define SPI_SR_CHSIDE_Msk    (0x1UL << SPI_SR_CHSIDE_Pos)	/*!< 0x00000004 */
#define SPI_SR_CHSIDE        SPI_SR_CHSIDE_Msk				/*!< Channel side              */
#define SPI_SR_UDR_Pos       (3U)
#define SPI_SR_UDR_Msk       (0x1UL << SPI_SR_UDR_Pos)	/*!< 0x00000008 */
#define SPI_SR_UDR           SPI_SR_UDR_Msk				/*!< Underrun flag             */
#define SPI_SR_CRCERR_Pos    (4U)
#define SPI_SR_CRCERR_Msk    (0x1UL << SPI_SR_CRCERR_Pos)	/*!< 0x00000010 */
#define SPI_SR_CRCERR        SPI_SR_CRCERR_Msk				/*!< CRC Error flag            */
#define SPI_SR_MODF_Pos      (5U)
#define SPI_SR_MODF_Msk      (0x1UL << SPI_SR_MODF_Pos)	/*!< 0x00000020 */
#define SPI_SR_MODF          SPI_SR_MODF_Msk/*!< Mode fault                */
#define SPI_SR_OVR_Pos       (6U)
#define SPI_SR_OVR_Msk       (0x1UL << SPI_SR_OVR_Pos)	/*!< 0x00000040 */
#define SPI_SR_OVR           SPI_SR_OVR_Msk				/*!< Overrun flag              */
#define SPI_SR_BSY_Pos       (7U)
#define SPI_SR_BSY_Msk       (0x1UL << SPI_SR_BSY_Pos)	/*!< 0x00000080 */
#define SPI_SR_BSY           SPI_SR_BSY_Msk				/*!< Busy flag                 */
#define SPI_SR_FRE_Pos       (8U)
#define SPI_SR_FRE_Msk       (0x1UL << SPI_SR_FRE_Pos)	/*!< 0x00000100 */
#define SPI_SR_FRE           SPI_SR_FRE_Msk				/*!< TI frame format error     */
#define SPI_SR_FRLVL_Pos     (9U)
#define SPI_SR_FRLVL_Msk     (0x3UL << SPI_SR_FRLVL_Pos)/*!< 0x00000600 */
#define SPI_SR_FRLVL         SPI_SR_FRLVL_Msk	/*!< FIFO Reception Level      */
#define SPI_SR_FRLVL_0       (0x1UL << SPI_SR_FRLVL_Pos)/*!< 0x00000200 */
#define SPI_SR_FRLVL_1       (0x2UL << SPI_SR_FRLVL_Pos)/*!< 0x00000400 */
#define SPI_SR_FTLVL_Pos     (11U)
#define SPI_SR_FTLVL_Msk     (0x3UL << SPI_SR_FTLVL_Pos)/*!< 0x00001800 */
#define SPI_SR_FTLVL         SPI_SR_FTLVL_Msk	/*!< FIFO Transmission Level   */
#define SPI_SR_FTLVL_0       (0x1UL << SPI_SR_FTLVL_Pos)/*!< 0x00000800 */
#define SPI_SR_FTLVL_1       (0x2UL << SPI_SR_FTLVL_Pos)/*!< 0x00001000 */

/********************  Bit definition for SPI_DR register  ********************/
#define SPI_DR_DR_Pos    (0U)
#define SPI_DR_DR_Msk    (0xFFFFUL << SPI_DR_DR_Pos)/*!< 0x0000FFFF */
#define SPI_DR_DR        SPI_DR_DR_Msk	/*!< Data Register */

/*******************  Bit definition for SPI_CRCPR register  ******************/
#define SPI_CRCPR_CRCPOLY_Pos    (0U)
#define SPI_CRCPR_CRCPOLY_Msk    (0xFFFFUL << SPI_CRCPR_CRCPOLY_Pos)/*!< 0x0000FFFF */
#define SPI_CRCPR_CRCPOLY        SPI_CRCPR_CRCPOLY_Msk	/*!< CRC polynomial register */

/******************  Bit definition for SPI_RXCRCR register  ******************/
#define SPI_RXCRCR_RXCRC_Pos    (0U)
#define SPI_RXCRCR_RXCRC_Msk    (0xFFFFUL << SPI_RXCRCR_RXCRC_Pos)	/*!< 0x0000FFFF */
#define SPI_RXCRCR_RXCRC        SPI_RXCRCR_RXCRC_Msk				/*!< Rx CRC Register */

/******************  Bit definition for SPI_TXCRCR register  ******************/
#define SPI_TXCRCR_TXCRC_Pos    (0U)
#define SPI_TXCRCR_TXCRC_Msk    (0xFFFFUL << SPI_TXCRCR_TXCRC_Pos)	/*!< 0x0000FFFF */
#define SPI_TXCRCR_TXCRC        SPI_TXCRCR_TXCRC_Msk				/*!< Tx CRC Register */

/******************  Bit definition for SPI_I2SCFGR register  *****************/
#define SPI_I2SCFGR_CHLEN_Pos      (0U)
#define SPI_I2SCFGR_CHLEN_Msk      (0x1UL << SPI_I2SCFGR_CHLEN_Pos)	/*!< 0x00000001 */
#define SPI_I2SCFGR_CHLEN          SPI_I2SCFGR_CHLEN_Msk/*!<Channel length (number of bits per audio channel) */
#define SPI_I2SCFGR_DATLEN_Pos     (1U)
#define SPI_I2SCFGR_DATLEN_Msk     (0x3UL << SPI_I2SCFGR_DATLEN_Pos)/*!< 0x00000006 */
#define SPI_I2SCFGR_DATLEN         SPI_I2SCFGR_DATLEN_Msk	/*!<DATLEN[1:0] bits (Data length to be transferred)  */
#define SPI_I2SCFGR_DATLEN_0       (0x1UL << SPI_I2SCFGR_DATLEN_Pos)/*!< 0x00000002 */
#define SPI_I2SCFGR_DATLEN_1       (0x2UL << SPI_I2SCFGR_DATLEN_Pos)/*!< 0x00000004 */
#define SPI_I2SCFGR_CKPOL_Pos      (3U)
#define SPI_I2SCFGR_CKPOL_Msk      (0x1UL << SPI_I2SCFGR_CKPOL_Pos)	/*!< 0x00000008 */
#define SPI_I2SCFGR_CKPOL          SPI_I2SCFGR_CKPOL_Msk/*!<steady state clock polarity                       */
#define SPI_I2SCFGR_I2SSTD_Pos     (4U)
#define SPI_I2SCFGR_I2SSTD_Msk     (0x3UL << SPI_I2SCFGR_I2SSTD_Pos)/*!< 0x00000030 */
#define SPI_I2SCFGR_I2SSTD         SPI_I2SCFGR_I2SSTD_Msk	/*!<I2SSTD[1:0] bits (I2S standard selection)         */
#define SPI_I2SCFGR_I2SSTD_0       (0x1UL << SPI_I2SCFGR_I2SSTD_Pos)/*!< 0x00000010 */
#define SPI_I2SCFGR_I2SSTD_1       (0x2UL << SPI_I2SCFGR_I2SSTD_Pos)/*!< 0x00000020 */
#define SPI_I2SCFGR_PCMSYNC_Pos    (7U)
#define SPI_I2SCFGR_PCMSYNC_Msk    (0x1UL << SPI_I2SCFGR_PCMSYNC_Pos)	/*!< 0x00000080 */
#define SPI_I2SCFGR_PCMSYNC        SPI_I2SCFGR_PCMSYNC_Msk				/*!<PCM frame synchronization                         */
#define SPI_I2SCFGR_I2SCFG_Pos     (8U)
#define SPI_I2SCFGR_I2SCFG_Msk     (0x3UL << SPI_I2SCFGR_I2SCFG_Pos)/*!< 0x00000300 */
#define SPI_I2SCFGR_I2SCFG         SPI_I2SCFGR_I2SCFG_Msk	/*!<I2SCFG[1:0] bits (I2S configuration mode)         */
#define SPI_I2SCFGR_I2SCFG_0       (0x1UL << SPI_I2SCFGR_I2SCFG_Pos)/*!< 0x00000100 */
#define SPI_I2SCFGR_I2SCFG_1       (0x2UL << SPI_I2SCFGR_I2SCFG_Pos)/*!< 0x00000200 */
#define SPI_I2SCFGR_I2SE_Pos       (10U)
#define SPI_I2SCFGR_I2SE_Msk       (0x1UL << SPI_I2SCFGR_I2SE_Pos)	/*!< 0x00000400 */
#define SPI_I2SCFGR_I2SE           SPI_I2SCFGR_I2SE_Msk				/*!<I2S Enable                                        */
#define SPI_I2SCFGR_I2SMOD_Pos     (11U)
#define SPI_I2SCFGR_I2SMOD_Msk     (0x1UL << SPI_I2SCFGR_I2SMOD_Pos)/*!< 0x00000800 */
#define SPI_I2SCFGR_I2SMOD         SPI_I2SCFGR_I2SMOD_Msk	/*!<I2S mode selection                                */
#define SPI_I2SCFGR_ASTRTEN_Pos    (12U)
#define SPI_I2SCFGR_ASTRTEN_Msk    (0x1UL << SPI_I2SCFGR_ASTRTEN_Pos)	/*!< 0x00001000 */
#define SPI_I2SCFGR_ASTRTEN        SPI_I2SCFGR_ASTRTEN_Msk				/*!<Asynchronous start enable                        */

/******************  Bit definition for SPI_I2SPR register  *******************/
#define SPI_I2SPR_I2SDIV_Pos    (0U)
#define SPI_I2SPR_I2SDIV_Msk    (0xFFUL << SPI_I2SPR_I2SDIV_Pos)/*!< 0x000000FF */
#define SPI_I2SPR_I2SDIV        SPI_I2SPR_I2SDIV_Msk/*!<I2S Linear prescaler         */
#define SPI_I2SPR_ODD_Pos       (8U)
#define SPI_I2SPR_ODD_Msk       (0x1UL << SPI_I2SPR_ODD_Pos)/*!< 0x00000100 */
#define SPI_I2SPR_ODD           SPI_I2SPR_ODD_Msk	/*!<Odd factor for the prescaler */
#define SPI_I2SPR_MCKOE_Pos     (9U)
#define SPI_I2SPR_MCKOE_Msk     (0x1UL << SPI_I2SPR_MCKOE_Pos)	/*!< 0x00000200 */
#define SPI_I2SPR_MCKOE         SPI_I2SPR_MCKOE_Msk				/*!<Master Clock Output Enable   */


/******************************************************************************/
/*                                                                            */
/*                                 SYSCFG                                     */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for SYSCFG_MEMRMP register  ***************/
#define SYSCFG_MEMRMP_MEM_BOOT_Pos    (0U)
#define SYSCFG_MEMRMP_MEM_BOOT_Msk    (0x1UL << SYSCFG_MEMRMP_MEM_BOOT_Pos)	/*!< 0x00000001 */
#define SYSCFG_MEMRMP_MEM_BOOT        SYSCFG_MEMRMP_MEM_BOOT_Msk/*!< Boot information after Reset */


#define SYSCFG_MEMRMP_SWP_FMC_Pos    (10U)
#define SYSCFG_MEMRMP_SWP_FMC_Msk    (0x3UL << SYSCFG_MEMRMP_SWP_FMC_Pos)	/*!< 0x00000C00 */
#define SYSCFG_MEMRMP_SWP_FMC        SYSCFG_MEMRMP_SWP_FMC_Msk				/*!< FMC Memory Mapping swapping */
#define SYSCFG_MEMRMP_SWP_FMC_0      (0x1UL << SYSCFG_MEMRMP_SWP_FMC_Pos)	/*!< 0x00000400 */
#define SYSCFG_MEMRMP_SWP_FMC_1      (0x2UL << SYSCFG_MEMRMP_SWP_FMC_Pos)	/*!< 0x00000800 */

/******************  Bit definition for SYSCFG_PMC register  ******************/
#define SYSCFG_PMC_I2C1_FMP_Pos       (0U)
#define SYSCFG_PMC_I2C1_FMP_Msk       (0x1UL << SYSCFG_PMC_I2C1_FMP_Pos)/*!< 0x00000001 */
#define SYSCFG_PMC_I2C1_FMP           SYSCFG_PMC_I2C1_FMP_Msk	/*!< I2C1_FMP I2C1 Fast Mode + Enable */
#define SYSCFG_PMC_I2C2_FMP_Pos       (1U)
#define SYSCFG_PMC_I2C2_FMP_Msk       (0x1UL << SYSCFG_PMC_I2C2_FMP_Pos)/*!< 0x00000002 */
#define SYSCFG_PMC_I2C2_FMP           SYSCFG_PMC_I2C2_FMP_Msk	/*!< I2C2_FMP I2C2 Fast Mode + Enable */
#define SYSCFG_PMC_I2C3_FMP_Pos       (2U)
#define SYSCFG_PMC_I2C3_FMP_Msk       (0x1UL << SYSCFG_PMC_I2C3_FMP_Pos)/*!< 0x00000004 */
#define SYSCFG_PMC_I2C3_FMP           SYSCFG_PMC_I2C3_FMP_Msk	/*!< I2C3_FMP I2C3 Fast Mode + Enable */
#define SYSCFG_PMC_I2C_PB6_FMP_Pos    (4U)
#define SYSCFG_PMC_I2C_PB6_FMP_Msk    (0x1UL << SYSCFG_PMC_I2C_PB6_FMP_Pos)	/*!< 0x00000010 */
#define SYSCFG_PMC_I2C_PB6_FMP        SYSCFG_PMC_I2C_PB6_FMP_Msk/*!< PB6_FMP Fast Mode + Enable */
#define SYSCFG_PMC_I2C_PB7_FMP_Pos    (5U)
#define SYSCFG_PMC_I2C_PB7_FMP_Msk    (0x1UL << SYSCFG_PMC_I2C_PB7_FMP_Pos)	/*!< 0x00000020 */
#define SYSCFG_PMC_I2C_PB7_FMP        SYSCFG_PMC_I2C_PB7_FMP_Msk/*!< PB7_FMP Fast Mode + Enable */
#define SYSCFG_PMC_I2C_PB8_FMP_Pos    (6U)
#define SYSCFG_PMC_I2C_PB8_FMP_Msk    (0x1UL << SYSCFG_PMC_I2C_PB8_FMP_Pos)	/*!< 0x00000040 */
#define SYSCFG_PMC_I2C_PB8_FMP        SYSCFG_PMC_I2C_PB8_FMP_Msk/*!< PB8_FMP Fast Mode + Enable */
#define SYSCFG_PMC_I2C_PB9_FMP_Pos    (7U)
#define SYSCFG_PMC_I2C_PB9_FMP_Msk    (0x1UL << SYSCFG_PMC_I2C_PB9_FMP_Pos)	/*!< 0x00000080 */
#define SYSCFG_PMC_I2C_PB9_FMP        SYSCFG_PMC_I2C_PB9_FMP_Msk/*!< PB9_FMP Fast Mode + Enable */

#define SYSCFG_PMC_ADCxDC2_Pos        (16U)
#define SYSCFG_PMC_ADCxDC2_Msk        (0x7UL << SYSCFG_PMC_ADCxDC2_Pos)	/*!< 0x00070000 */
#define SYSCFG_PMC_ADCxDC2            SYSCFG_PMC_ADCxDC2_Msk/*!< Refer to AN4073 on how to use this bit  */
#define SYSCFG_PMC_ADC1DC2_Pos        (16U)
#define SYSCFG_PMC_ADC1DC2_Msk        (0x1UL << SYSCFG_PMC_ADC1DC2_Pos)	/*!< 0x00010000 */
#define SYSCFG_PMC_ADC1DC2            SYSCFG_PMC_ADC1DC2_Msk/*!< Refer to AN4073 on how to use this bit  */
#define SYSCFG_PMC_ADC2DC2_Pos        (17U)
#define SYSCFG_PMC_ADC2DC2_Msk        (0x1UL << SYSCFG_PMC_ADC2DC2_Pos)	/*!< 0x00020000 */
#define SYSCFG_PMC_ADC2DC2            SYSCFG_PMC_ADC2DC2_Msk/*!< Refer to AN4073 on how to use this bit  */
#define SYSCFG_PMC_ADC3DC2_Pos        (18U)
#define SYSCFG_PMC_ADC3DC2_Msk        (0x1UL << SYSCFG_PMC_ADC3DC2_Pos)	/*!< 0x00040000 */
#define SYSCFG_PMC_ADC3DC2            SYSCFG_PMC_ADC3DC2_Msk/*!< Refer to AN4073 on how to use this bit  */


/*****************  Bit definition for SYSCFG_EXTICR1 register  ***************/
#define SYSCFG_EXTICR1_EXTI0_Pos    (0U)
#define SYSCFG_EXTICR1_EXTI0_Msk    (0xFUL << SYSCFG_EXTICR1_EXTI0_Pos)	/*!< 0x0000000F */
#define SYSCFG_EXTICR1_EXTI0        SYSCFG_EXTICR1_EXTI0_Msk/*!<EXTI 0 configuration */
#define SYSCFG_EXTICR1_EXTI1_Pos    (4U)
#define SYSCFG_EXTICR1_EXTI1_Msk    (0xFUL << SYSCFG_EXTICR1_EXTI1_Pos)	/*!< 0x000000F0 */
#define SYSCFG_EXTICR1_EXTI1        SYSCFG_EXTICR1_EXTI1_Msk/*!<EXTI 1 configuration */
#define SYSCFG_EXTICR1_EXTI2_Pos    (8U)
#define SYSCFG_EXTICR1_EXTI2_Msk    (0xFUL << SYSCFG_EXTICR1_EXTI2_Pos)	/*!< 0x00000F00 */
#define SYSCFG_EXTICR1_EXTI2        SYSCFG_EXTICR1_EXTI2_Msk/*!<EXTI 2 configuration */
#define SYSCFG_EXTICR1_EXTI3_Pos    (12U)
#define SYSCFG_EXTICR1_EXTI3_Msk    (0xFUL << SYSCFG_EXTICR1_EXTI3_Pos)	/*!< 0x0000F000 */
#define SYSCFG_EXTICR1_EXTI3        SYSCFG_EXTICR1_EXTI3_Msk/*!<EXTI 3 configuration */

/**
 * @brief   EXTI0 configuration
 */
#define SYSCFG_EXTICR1_EXTI0_PA    0x0000U	/*!<PA[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PB    0x0001U	/*!<PB[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PC    0x0002U	/*!<PC[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PD    0x0003U	/*!<PD[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PE    0x0004U	/*!<PE[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PF    0x0005U	/*!<PF[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PG    0x0006U	/*!<PG[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PH    0x0007U	/*!<PH[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PI    0x0008U	/*!<PI[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PJ    0x0009U	/*!<PJ[0] pin */
#define SYSCFG_EXTICR1_EXTI0_PK    0x000AU	/*!<PK[0] pin */

/**
 * @brief   EXTI1 configuration
 */
#define SYSCFG_EXTICR1_EXTI1_PA    0x0000U	/*!<PA[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PB    0x0010U	/*!<PB[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PC    0x0020U	/*!<PC[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PD    0x0030U	/*!<PD[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PE    0x0040U	/*!<PE[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PF    0x0050U	/*!<PF[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PG    0x0060U	/*!<PG[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PH    0x0070U	/*!<PH[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PI    0x0080U	/*!<PI[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PJ    0x0090U	/*!<PJ[1] pin */
#define SYSCFG_EXTICR1_EXTI1_PK    0x00A0U	/*!<PK[1] pin */

/**
 * @brief   EXTI2 configuration
 */
#define SYSCFG_EXTICR1_EXTI2_PA    0x0000U	/*!<PA[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PB    0x0100U	/*!<PB[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PC    0x0200U	/*!<PC[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PD    0x0300U	/*!<PD[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PE    0x0400U	/*!<PE[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PF    0x0500U	/*!<PF[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PG    0x0600U	/*!<PG[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PH    0x0700U	/*!<PH[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PI    0x0800U	/*!<PI[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PJ    0x0900U	/*!<PJ[2] pin */
#define SYSCFG_EXTICR1_EXTI2_PK    0x0A00U	/*!<PK[2] pin */

/**
 * @brief   EXTI3 configuration
 */
#define SYSCFG_EXTICR1_EXTI3_PA    0x0000U	/*!<PA[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PB    0x1000U	/*!<PB[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PC    0x2000U	/*!<PC[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PD    0x3000U	/*!<PD[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PE    0x4000U	/*!<PE[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PF    0x5000U	/*!<PF[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PG    0x6000U	/*!<PG[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PH    0x7000U	/*!<PH[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PI    0x8000U	/*!<PI[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PJ    0x9000U	/*!<PJ[3] pin */
#define SYSCFG_EXTICR1_EXTI3_PK    0xA000U	/*!<PK[3] pin */

/*****************  Bit definition for SYSCFG_EXTICR2 register  ***************/
#define SYSCFG_EXTICR2_EXTI4_Pos    (0U)
#define SYSCFG_EXTICR2_EXTI4_Msk    (0xFUL << SYSCFG_EXTICR2_EXTI4_Pos)	/*!< 0x0000000F */
#define SYSCFG_EXTICR2_EXTI4        SYSCFG_EXTICR2_EXTI4_Msk/*!<EXTI 4 configuration */
#define SYSCFG_EXTICR2_EXTI5_Pos    (4U)
#define SYSCFG_EXTICR2_EXTI5_Msk    (0xFUL << SYSCFG_EXTICR2_EXTI5_Pos)	/*!< 0x000000F0 */
#define SYSCFG_EXTICR2_EXTI5        SYSCFG_EXTICR2_EXTI5_Msk/*!<EXTI 5 configuration */
#define SYSCFG_EXTICR2_EXTI6_Pos    (8U)
#define SYSCFG_EXTICR2_EXTI6_Msk    (0xFUL << SYSCFG_EXTICR2_EXTI6_Pos)	/*!< 0x00000F00 */
#define SYSCFG_EXTICR2_EXTI6        SYSCFG_EXTICR2_EXTI6_Msk/*!<EXTI 6 configuration */
#define SYSCFG_EXTICR2_EXTI7_Pos    (12U)
#define SYSCFG_EXTICR2_EXTI7_Msk    (0xFUL << SYSCFG_EXTICR2_EXTI7_Pos)	/*!< 0x0000F000 */
#define SYSCFG_EXTICR2_EXTI7        SYSCFG_EXTICR2_EXTI7_Msk/*!<EXTI 7 configuration */

/**
 * @brief   EXTI4 configuration
 */
#define SYSCFG_EXTICR2_EXTI4_PA    0x0000U	/*!<PA[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PB    0x0001U	/*!<PB[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PC    0x0002U	/*!<PC[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PD    0x0003U	/*!<PD[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PE    0x0004U	/*!<PE[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PF    0x0005U	/*!<PF[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PG    0x0006U	/*!<PG[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PH    0x0007U	/*!<PH[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PI    0x0008U	/*!<PI[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PJ    0x0009U	/*!<PJ[4] pin */
#define SYSCFG_EXTICR2_EXTI4_PK    0x000AU	/*!<PK[4] pin */

/**
 * @brief   EXTI5 configuration
 */
#define SYSCFG_EXTICR2_EXTI5_PA    0x0000U	/*!<PA[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PB    0x0010U	/*!<PB[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PC    0x0020U	/*!<PC[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PD    0x0030U	/*!<PD[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PE    0x0040U	/*!<PE[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PF    0x0050U	/*!<PF[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PG    0x0060U	/*!<PG[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PH    0x0070U	/*!<PH[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PI    0x0080U	/*!<PI[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PJ    0x0090U	/*!<PJ[5] pin */
#define SYSCFG_EXTICR2_EXTI5_PK    0x00A0U	/*!<PK[5] pin */

/**
 * @brief   EXTI6 configuration
 */
#define SYSCFG_EXTICR2_EXTI6_PA    0x0000U	/*!<PA[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PB    0x0100U	/*!<PB[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PC    0x0200U	/*!<PC[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PD    0x0300U	/*!<PD[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PE    0x0400U	/*!<PE[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PF    0x0500U	/*!<PF[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PG    0x0600U	/*!<PG[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PH    0x0700U	/*!<PH[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PI    0x0800U	/*!<PI[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PJ    0x0900U	/*!<PJ[6] pin */
#define SYSCFG_EXTICR2_EXTI6_PK    0x0A00U	/*!<PK[6] pin */

/**
 * @brief   EXTI7 configuration
 */
#define SYSCFG_EXTICR2_EXTI7_PA    0x0000U	/*!<PA[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PB    0x1000U	/*!<PB[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PC    0x2000U	/*!<PC[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PD    0x3000U	/*!<PD[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PE    0x4000U	/*!<PE[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PF    0x5000U	/*!<PF[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PG    0x6000U	/*!<PG[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PH    0x7000U	/*!<PH[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PI    0x8000U	/*!<PI[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PJ    0x9000U	/*!<PJ[7] pin */
#define SYSCFG_EXTICR2_EXTI7_PK    0xA000U	/*!<PK[7] pin */

/*****************  Bit definition for SYSCFG_EXTICR3 register  ***************/
#define SYSCFG_EXTICR3_EXTI8_Pos     (0U)
#define SYSCFG_EXTICR3_EXTI8_Msk     (0xFUL << SYSCFG_EXTICR3_EXTI8_Pos)/*!< 0x0000000F */
#define SYSCFG_EXTICR3_EXTI8         SYSCFG_EXTICR3_EXTI8_Msk	/*!<EXTI 8 configuration */
#define SYSCFG_EXTICR3_EXTI9_Pos     (4U)
#define SYSCFG_EXTICR3_EXTI9_Msk     (0xFUL << SYSCFG_EXTICR3_EXTI9_Pos)/*!< 0x000000F0 */
#define SYSCFG_EXTICR3_EXTI9         SYSCFG_EXTICR3_EXTI9_Msk	/*!<EXTI 9 configuration */
#define SYSCFG_EXTICR3_EXTI10_Pos    (8U)
#define SYSCFG_EXTICR3_EXTI10_Msk    (0xFUL << SYSCFG_EXTICR3_EXTI10_Pos)	/*!< 0x00000F00 */
#define SYSCFG_EXTICR3_EXTI10        SYSCFG_EXTICR3_EXTI10_Msk				/*!<EXTI 10 configuration */
#define SYSCFG_EXTICR3_EXTI11_Pos    (12U)
#define SYSCFG_EXTICR3_EXTI11_Msk    (0xFUL << SYSCFG_EXTICR3_EXTI11_Pos)	/*!< 0x0000F000 */
#define SYSCFG_EXTICR3_EXTI11        SYSCFG_EXTICR3_EXTI11_Msk				/*!<EXTI 11 configuration */

/**
 * @brief   EXTI8 configuration
 */
#define SYSCFG_EXTICR3_EXTI8_PA    0x0000U	/*!<PA[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PB    0x0001U	/*!<PB[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PC    0x0002U	/*!<PC[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PD    0x0003U	/*!<PD[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PE    0x0004U	/*!<PE[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PF    0x0005U	/*!<PF[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PG    0x0006U	/*!<PG[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PH    0x0007U	/*!<PH[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PI    0x0008U	/*!<PI[8] pin */
#define SYSCFG_EXTICR3_EXTI8_PJ    0x0009U	/*!<PJ[8] pin */

/**
 * @brief   EXTI9 configuration
 */
#define SYSCFG_EXTICR3_EXTI9_PA    0x0000U	/*!<PA[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PB    0x0010U	/*!<PB[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PC    0x0020U	/*!<PC[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PD    0x0030U	/*!<PD[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PE    0x0040U	/*!<PE[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PF    0x0050U	/*!<PF[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PG    0x0060U	/*!<PG[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PH    0x0070U	/*!<PH[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PI    0x0080U	/*!<PI[9] pin */
#define SYSCFG_EXTICR3_EXTI9_PJ    0x0090U	/*!<PJ[9] pin */

/**
 * @brief   EXTI10 configuration
 */
#define SYSCFG_EXTICR3_EXTI10_PA    0x0000U	/*!<PA[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PB    0x0100U	/*!<PB[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PC    0x0200U	/*!<PC[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PD    0x0300U	/*!<PD[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PE    0x0400U	/*!<PE[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PF    0x0500U	/*!<PF[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PG    0x0600U	/*!<PG[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PH    0x0700U	/*!<PH[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PI    0x0800U	/*!<PI[10] pin */
#define SYSCFG_EXTICR3_EXTI10_PJ    0x0900U	/*!<PJ[10] pin */

/**
 * @brief   EXTI11 configuration
 */
#define SYSCFG_EXTICR3_EXTI11_PA    0x0000U	/*!<PA[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PB    0x1000U	/*!<PB[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PC    0x2000U	/*!<PC[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PD    0x3000U	/*!<PD[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PE    0x4000U	/*!<PE[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PF    0x5000U	/*!<PF[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PG    0x6000U	/*!<PG[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PH    0x7000U	/*!<PH[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PI    0x8000U	/*!<PI[11] pin */
#define SYSCFG_EXTICR3_EXTI11_PJ    0x9000U	/*!<PJ[11] pin */


/*****************  Bit definition for SYSCFG_EXTICR4 register  ***************/
#define SYSCFG_EXTICR4_EXTI12_Pos    (0U)
#define SYSCFG_EXTICR4_EXTI12_Msk    (0xFUL << SYSCFG_EXTICR4_EXTI12_Pos)	/*!< 0x0000000F */
#define SYSCFG_EXTICR4_EXTI12        SYSCFG_EXTICR4_EXTI12_Msk				/*!<EXTI 12 configuration */
#define SYSCFG_EXTICR4_EXTI13_Pos    (4U)
#define SYSCFG_EXTICR4_EXTI13_Msk    (0xFUL << SYSCFG_EXTICR4_EXTI13_Pos)	/*!< 0x000000F0 */
#define SYSCFG_EXTICR4_EXTI13        SYSCFG_EXTICR4_EXTI13_Msk				/*!<EXTI 13 configuration */
#define SYSCFG_EXTICR4_EXTI14_Pos    (8U)
#define SYSCFG_EXTICR4_EXTI14_Msk    (0xFUL << SYSCFG_EXTICR4_EXTI14_Pos)	/*!< 0x00000F00 */
#define SYSCFG_EXTICR4_EXTI14        SYSCFG_EXTICR4_EXTI14_Msk				/*!<EXTI 14 configuration */
#define SYSCFG_EXTICR4_EXTI15_Pos    (12U)
#define SYSCFG_EXTICR4_EXTI15_Msk    (0xFUL << SYSCFG_EXTICR4_EXTI15_Pos)	/*!< 0x0000F000 */
#define SYSCFG_EXTICR4_EXTI15        SYSCFG_EXTICR4_EXTI15_Msk				/*!<EXTI 15 configuration */

/**
 * @brief   EXTI12 configuration
 */
#define SYSCFG_EXTICR4_EXTI12_PA    0x0000U	/*!<PA[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PB    0x0001U	/*!<PB[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PC    0x0002U	/*!<PC[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PD    0x0003U	/*!<PD[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PE    0x0004U	/*!<PE[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PF    0x0005U	/*!<PF[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PG    0x0006U	/*!<PG[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PH    0x0007U	/*!<PH[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PI    0x0008U	/*!<PI[12] pin */
#define SYSCFG_EXTICR4_EXTI12_PJ    0x0009U	/*!<PJ[12] pin */

/**
 * @brief   EXTI13 configuration
 */
#define SYSCFG_EXTICR4_EXTI13_PA    0x0000U	/*!<PA[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PB    0x0010U	/*!<PB[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PC    0x0020U	/*!<PC[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PD    0x0030U	/*!<PD[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PE    0x0040U	/*!<PE[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PF    0x0050U	/*!<PF[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PG    0x0060U	/*!<PG[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PH    0x0070U	/*!<PH[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PI    0x0080U	/*!<PI[13] pin */
#define SYSCFG_EXTICR4_EXTI13_PJ    0x0090U	/*!<PJ[13] pin */

/**
 * @brief   EXTI14 configuration
 */
#define SYSCFG_EXTICR4_EXTI14_PA    0x0000U	/*!<PA[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PB    0x0100U	/*!<PB[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PC    0x0200U	/*!<PC[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PD    0x0300U	/*!<PD[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PE    0x0400U	/*!<PE[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PF    0x0500U	/*!<PF[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PG    0x0600U	/*!<PG[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PH    0x0700U	/*!<PH[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PI    0x0800U	/*!<PI[14] pin */
#define SYSCFG_EXTICR4_EXTI14_PJ    0x0900U	/*!<PJ[14] pin */

/**
 * @brief   EXTI15 configuration
 */
#define SYSCFG_EXTICR4_EXTI15_PA    0x0000U	/*!<PA[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PB    0x1000U	/*!<PB[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PC    0x2000U	/*!<PC[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PD    0x3000U	/*!<PD[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PE    0x4000U	/*!<PE[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PF    0x5000U	/*!<PF[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PG    0x6000U	/*!<PG[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PH    0x7000U	/*!<PH[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PI    0x8000U	/*!<PI[15] pin */
#define SYSCFG_EXTICR4_EXTI15_PJ    0x9000U	/*!<PJ[15] pin */


/******************  Bit definition for SYSCFG_CMPCR register  ****************/
#define SYSCFG_CMPCR_CMP_PD_Pos    (0U)
#define SYSCFG_CMPCR_CMP_PD_Msk    (0x1UL << SYSCFG_CMPCR_CMP_PD_Pos)	/*!< 0x00000001 */
#define SYSCFG_CMPCR_CMP_PD        SYSCFG_CMPCR_CMP_PD_Msk				/*!<Compensation cell power-down */
#define SYSCFG_CMPCR_READY_Pos     (8U)
#define SYSCFG_CMPCR_READY_Msk     (0x1UL << SYSCFG_CMPCR_READY_Pos)/*!< 0x00000100 */
#define SYSCFG_CMPCR_READY         SYSCFG_CMPCR_READY_Msk	/*!<Compensation cell ready flag */

/******************************************************************************/
/*                                                                            */
/*                                    TIM                                     */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for TIM_CR1 register  ********************/
#define TIM_CR1_CEN_Pos         (0U)
#define TIM_CR1_CEN_Msk         (0x1UL << TIM_CR1_CEN_Pos)	/*!< 0x00000001 */
#define TIM_CR1_CEN             TIM_CR1_CEN_Msk				/*!<Counter enable        */
#define TIM_CR1_UDIS_Pos        (1U)
#define TIM_CR1_UDIS_Msk        (0x1UL << TIM_CR1_UDIS_Pos)	/*!< 0x00000002 */
#define TIM_CR1_UDIS            TIM_CR1_UDIS_Msk/*!<Update disable        */
#define TIM_CR1_URS_Pos         (2U)
#define TIM_CR1_URS_Msk         (0x1UL << TIM_CR1_URS_Pos)	/*!< 0x00000004 */
#define TIM_CR1_URS             TIM_CR1_URS_Msk				/*!<Update request source */
#define TIM_CR1_OPM_Pos         (3U)
#define TIM_CR1_OPM_Msk         (0x1UL << TIM_CR1_OPM_Pos)	/*!< 0x00000008 */
#define TIM_CR1_OPM             TIM_CR1_OPM_Msk				/*!<One pulse mode        */
#define TIM_CR1_DIR_Pos         (4U)
#define TIM_CR1_DIR_Msk         (0x1UL << TIM_CR1_DIR_Pos)	/*!< 0x00000010 */
#define TIM_CR1_DIR             TIM_CR1_DIR_Msk				/*!<Direction             */

#define TIM_CR1_CMS_Pos         (5U)
#define TIM_CR1_CMS_Msk         (0x3UL << TIM_CR1_CMS_Pos)	/*!< 0x00000060 */
#define TIM_CR1_CMS             TIM_CR1_CMS_Msk				/*!<CMS[1:0] bits (Center-aligned mode selection) */
#define TIM_CR1_CMS_0           (0x1UL << TIM_CR1_CMS_Pos)	/*!< 0x0020 */
#define TIM_CR1_CMS_1           (0x2UL << TIM_CR1_CMS_Pos)	/*!< 0x0040 */

#define TIM_CR1_ARPE_Pos        (7U)
#define TIM_CR1_ARPE_Msk        (0x1UL << TIM_CR1_ARPE_Pos)	/*!< 0x00000080 */
#define TIM_CR1_ARPE            TIM_CR1_ARPE_Msk/*!<Auto-reload preload enable     */

#define TIM_CR1_CKD_Pos         (8U)
#define TIM_CR1_CKD_Msk         (0x3UL << TIM_CR1_CKD_Pos)	/*!< 0x00000300 */
#define TIM_CR1_CKD             TIM_CR1_CKD_Msk				/*!<CKD[1:0] bits (clock division) */
#define TIM_CR1_CKD_0           (0x1UL << TIM_CR1_CKD_Pos)	/*!< 0x0100 */
#define TIM_CR1_CKD_1           (0x2UL << TIM_CR1_CKD_Pos)	/*!< 0x0200 */
#define TIM_CR1_UIFREMAP_Pos    (11U)
#define TIM_CR1_UIFREMAP_Msk    (0x1UL << TIM_CR1_UIFREMAP_Pos)	/*!< 0x00000800 */
#define TIM_CR1_UIFREMAP        TIM_CR1_UIFREMAP_Msk/*!<UIF status bit */

/*******************  Bit definition for TIM_CR2 register  ********************/
#define TIM_CR2_CCPC_Pos     (0U)
#define TIM_CR2_CCPC_Msk     (0x1UL << TIM_CR2_CCPC_Pos)/*!< 0x00000001 */
#define TIM_CR2_CCPC         TIM_CR2_CCPC_Msk	/*!<Capture/Compare Preloaded Control        */
#define TIM_CR2_CCUS_Pos     (2U)
#define TIM_CR2_CCUS_Msk     (0x1UL << TIM_CR2_CCUS_Pos)/*!< 0x00000004 */
#define TIM_CR2_CCUS         TIM_CR2_CCUS_Msk	/*!<Capture/Compare Control Update Selection */
#define TIM_CR2_CCDS_Pos     (3U)
#define TIM_CR2_CCDS_Msk     (0x1UL << TIM_CR2_CCDS_Pos)/*!< 0x00000008 */
#define TIM_CR2_CCDS         TIM_CR2_CCDS_Msk	/*!<Capture/Compare DMA Selection            */

#define TIM_CR2_OIS5_Pos     (16U)
#define TIM_CR2_OIS5_Msk     (0x1UL << TIM_CR2_OIS5_Pos)/*!< 0x00010000 */
#define TIM_CR2_OIS5         TIM_CR2_OIS5_Msk	/*!<Output Idle state 4 (OC4 output) */
#define TIM_CR2_OIS6_Pos     (18U)
#define TIM_CR2_OIS6_Msk     (0x1UL << TIM_CR2_OIS6_Pos)/*!< 0x00040000 */
#define TIM_CR2_OIS6         TIM_CR2_OIS6_Msk	/*!<Output Idle state 4 (OC4 output) */

#define TIM_CR2_MMS_Pos      (4U)
#define TIM_CR2_MMS_Msk      (0x7UL << TIM_CR2_MMS_Pos)	/*!< 0x00000070 */
#define TIM_CR2_MMS          TIM_CR2_MMS_Msk/*!<MMS[2:0] bits (Master Mode Selection) */
#define TIM_CR2_MMS_0        (0x1UL << TIM_CR2_MMS_Pos)	/*!< 0x0010 */
#define TIM_CR2_MMS_1        (0x2UL << TIM_CR2_MMS_Pos)	/*!< 0x0020 */
#define TIM_CR2_MMS_2        (0x4UL << TIM_CR2_MMS_Pos)	/*!< 0x0040 */

#define TIM_CR2_MMS2_Pos     (20U)
#define TIM_CR2_MMS2_Msk     (0xFUL << TIM_CR2_MMS2_Pos)/*!< 0x00F00000 */
#define TIM_CR2_MMS2         TIM_CR2_MMS2_Msk	/*!<MMS[2:0] bits (Master Mode Selection) */
#define TIM_CR2_MMS2_0       (0x1UL << TIM_CR2_MMS2_Pos)/*!< 0x00100000 */
#define TIM_CR2_MMS2_1       (0x2UL << TIM_CR2_MMS2_Pos)/*!< 0x00200000 */
#define TIM_CR2_MMS2_2       (0x4UL << TIM_CR2_MMS2_Pos)/*!< 0x00400000 */
#define TIM_CR2_MMS2_3       (0x8UL << TIM_CR2_MMS2_Pos)/*!< 0x00800000 */

#define TIM_CR2_TI1S_Pos     (7U)
#define TIM_CR2_TI1S_Msk     (0x1UL << TIM_CR2_TI1S_Pos)/*!< 0x00000080 */
#define TIM_CR2_TI1S         TIM_CR2_TI1S_Msk	/*!<TI1 Selection */
#define TIM_CR2_OIS1_Pos     (8U)
#define TIM_CR2_OIS1_Msk     (0x1UL << TIM_CR2_OIS1_Pos)/*!< 0x00000100 */
#define TIM_CR2_OIS1         TIM_CR2_OIS1_Msk	/*!<Output Idle state 1 (OC1 output)  */
#define TIM_CR2_OIS1N_Pos    (9U)
#define TIM_CR2_OIS1N_Msk    (0x1UL << TIM_CR2_OIS1N_Pos)	/*!< 0x00000200 */
#define TIM_CR2_OIS1N        TIM_CR2_OIS1N_Msk				/*!<Output Idle state 1 (OC1N output) */
#define TIM_CR2_OIS2_Pos     (10U)
#define TIM_CR2_OIS2_Msk     (0x1UL << TIM_CR2_OIS2_Pos)/*!< 0x00000400 */
#define TIM_CR2_OIS2         TIM_CR2_OIS2_Msk	/*!<Output Idle state 2 (OC2 output)  */
#define TIM_CR2_OIS2N_Pos    (11U)
#define TIM_CR2_OIS2N_Msk    (0x1UL << TIM_CR2_OIS2N_Pos)	/*!< 0x00000800 */
#define TIM_CR2_OIS2N        TIM_CR2_OIS2N_Msk				/*!<Output Idle state 2 (OC2N output) */
#define TIM_CR2_OIS3_Pos     (12U)
#define TIM_CR2_OIS3_Msk     (0x1UL << TIM_CR2_OIS3_Pos)/*!< 0x00001000 */
#define TIM_CR2_OIS3         TIM_CR2_OIS3_Msk	/*!<Output Idle state 3 (OC3 output)  */
#define TIM_CR2_OIS3N_Pos    (13U)
#define TIM_CR2_OIS3N_Msk    (0x1UL << TIM_CR2_OIS3N_Pos)	/*!< 0x00002000 */
#define TIM_CR2_OIS3N        TIM_CR2_OIS3N_Msk				/*!<Output Idle state 3 (OC3N output) */
#define TIM_CR2_OIS4_Pos     (14U)
#define TIM_CR2_OIS4_Msk     (0x1UL << TIM_CR2_OIS4_Pos)/*!< 0x00004000 */
#define TIM_CR2_OIS4         TIM_CR2_OIS4_Msk	/*!<Output Idle state 4 (OC4 output)  */

/*******************  Bit definition for TIM_SMCR register  *******************/
#define TIM_SMCR_SMS_Pos     (0U)
#define TIM_SMCR_SMS_Msk     (0x10007UL << TIM_SMCR_SMS_Pos)/*!< 0x00010007 */
#define TIM_SMCR_SMS         TIM_SMCR_SMS_Msk	/*!<SMS[2:0] bits (Slave mode selection)    */
#define TIM_SMCR_SMS_0       (0x00001UL << TIM_SMCR_SMS_Pos)/*!< 0x00000001 */
#define TIM_SMCR_SMS_1       (0x00002UL << TIM_SMCR_SMS_Pos)/*!< 0x00000002 */
#define TIM_SMCR_SMS_2       (0x00004UL << TIM_SMCR_SMS_Pos)/*!< 0x00000004 */
#define TIM_SMCR_SMS_3       (0x10000UL << TIM_SMCR_SMS_Pos)/*!< 0x00010000 */

#define TIM_SMCR_TS_Pos      (4U)
#define TIM_SMCR_TS_Msk      (0x7UL << TIM_SMCR_TS_Pos)	/*!< 0x00000070 */
#define TIM_SMCR_TS          TIM_SMCR_TS_Msk/*!<TS[2:0] bits (Trigger selection)        */
#define TIM_SMCR_TS_0        (0x1UL << TIM_SMCR_TS_Pos)	/*!< 0x0010 */
#define TIM_SMCR_TS_1        (0x2UL << TIM_SMCR_TS_Pos)	/*!< 0x0020 */
#define TIM_SMCR_TS_2        (0x4UL << TIM_SMCR_TS_Pos)	/*!< 0x0040 */

#define TIM_SMCR_MSM_Pos     (7U)
#define TIM_SMCR_MSM_Msk     (0x1UL << TIM_SMCR_MSM_Pos)/*!< 0x00000080 */
#define TIM_SMCR_MSM         TIM_SMCR_MSM_Msk	/*!<Master/slave mode                       */

#define TIM_SMCR_ETF_Pos     (8U)
#define TIM_SMCR_ETF_Msk     (0xFUL << TIM_SMCR_ETF_Pos)/*!< 0x00000F00 */
#define TIM_SMCR_ETF         TIM_SMCR_ETF_Msk	/*!<ETF[3:0] bits (External trigger filter) */
#define TIM_SMCR_ETF_0       (0x1UL << TIM_SMCR_ETF_Pos)/*!< 0x0100 */
#define TIM_SMCR_ETF_1       (0x2UL << TIM_SMCR_ETF_Pos)/*!< 0x0200 */
#define TIM_SMCR_ETF_2       (0x4UL << TIM_SMCR_ETF_Pos)/*!< 0x0400 */
#define TIM_SMCR_ETF_3       (0x8UL << TIM_SMCR_ETF_Pos)/*!< 0x0800 */

#define TIM_SMCR_ETPS_Pos    (12U)
#define TIM_SMCR_ETPS_Msk    (0x3UL << TIM_SMCR_ETPS_Pos)	/*!< 0x00003000 */
#define TIM_SMCR_ETPS        TIM_SMCR_ETPS_Msk				/*!<ETPS[1:0] bits (External trigger prescaler) */
#define TIM_SMCR_ETPS_0      (0x1UL << TIM_SMCR_ETPS_Pos)	/*!< 0x1000 */
#define TIM_SMCR_ETPS_1      (0x2UL << TIM_SMCR_ETPS_Pos)	/*!< 0x2000 */

#define TIM_SMCR_ECE_Pos     (14U)
#define TIM_SMCR_ECE_Msk     (0x1UL << TIM_SMCR_ECE_Pos)/*!< 0x00004000 */
#define TIM_SMCR_ECE         TIM_SMCR_ECE_Msk	/*!<External clock enable     */
#define TIM_SMCR_ETP_Pos     (15U)
#define TIM_SMCR_ETP_Msk     (0x1UL << TIM_SMCR_ETP_Pos)/*!< 0x00008000 */
#define TIM_SMCR_ETP         TIM_SMCR_ETP_Msk	/*!<External trigger polarity */

/*******************  Bit definition for TIM_DIER register  *******************/
#define TIM_DIER_UIE_Pos      (0U)
#define TIM_DIER_UIE_Msk      (0x1UL << TIM_DIER_UIE_Pos)	/*!< 0x00000001 */
#define TIM_DIER_UIE          TIM_DIER_UIE_Msk				/*!<Update interrupt enable */
#define TIM_DIER_CC1IE_Pos    (1U)
#define TIM_DIER_CC1IE_Msk    (0x1UL << TIM_DIER_CC1IE_Pos)	/*!< 0x00000002 */
#define TIM_DIER_CC1IE        TIM_DIER_CC1IE_Msk/*!<Capture/Compare 1 interrupt enable   */
#define TIM_DIER_CC2IE_Pos    (2U)
#define TIM_DIER_CC2IE_Msk    (0x1UL << TIM_DIER_CC2IE_Pos)	/*!< 0x00000004 */
#define TIM_DIER_CC2IE        TIM_DIER_CC2IE_Msk/*!<Capture/Compare 2 interrupt enable   */
#define TIM_DIER_CC3IE_Pos    (3U)
#define TIM_DIER_CC3IE_Msk    (0x1UL << TIM_DIER_CC3IE_Pos)	/*!< 0x00000008 */
#define TIM_DIER_CC3IE        TIM_DIER_CC3IE_Msk/*!<Capture/Compare 3 interrupt enable   */
#define TIM_DIER_CC4IE_Pos    (4U)
#define TIM_DIER_CC4IE_Msk    (0x1UL << TIM_DIER_CC4IE_Pos)	/*!< 0x00000010 */
#define TIM_DIER_CC4IE        TIM_DIER_CC4IE_Msk/*!<Capture/Compare 4 interrupt enable   */
#define TIM_DIER_COMIE_Pos    (5U)
#define TIM_DIER_COMIE_Msk    (0x1UL << TIM_DIER_COMIE_Pos)	/*!< 0x00000020 */
#define TIM_DIER_COMIE        TIM_DIER_COMIE_Msk/*!<COM interrupt enable                 */
#define TIM_DIER_TIE_Pos      (6U)
#define TIM_DIER_TIE_Msk      (0x1UL << TIM_DIER_TIE_Pos)	/*!< 0x00000040 */
#define TIM_DIER_TIE          TIM_DIER_TIE_Msk				/*!<Trigger interrupt enable             */
#define TIM_DIER_BIE_Pos      (7U)
#define TIM_DIER_BIE_Msk      (0x1UL << TIM_DIER_BIE_Pos)	/*!< 0x00000080 */
#define TIM_DIER_BIE          TIM_DIER_BIE_Msk				/*!<Break interrupt enable               */
#define TIM_DIER_UDE_Pos      (8U)
#define TIM_DIER_UDE_Msk      (0x1UL << TIM_DIER_UDE_Pos)	/*!< 0x00000100 */
#define TIM_DIER_UDE          TIM_DIER_UDE_Msk				/*!<Update DMA request enable            */
#define TIM_DIER_CC1DE_Pos    (9U)
#define TIM_DIER_CC1DE_Msk    (0x1UL << TIM_DIER_CC1DE_Pos)	/*!< 0x00000200 */
#define TIM_DIER_CC1DE        TIM_DIER_CC1DE_Msk/*!<Capture/Compare 1 DMA request enable */
#define TIM_DIER_CC2DE_Pos    (10U)
#define TIM_DIER_CC2DE_Msk    (0x1UL << TIM_DIER_CC2DE_Pos)	/*!< 0x00000400 */
#define TIM_DIER_CC2DE        TIM_DIER_CC2DE_Msk/*!<Capture/Compare 2 DMA request enable */
#define TIM_DIER_CC3DE_Pos    (11U)
#define TIM_DIER_CC3DE_Msk    (0x1UL << TIM_DIER_CC3DE_Pos)	/*!< 0x00000800 */
#define TIM_DIER_CC3DE        TIM_DIER_CC3DE_Msk/*!<Capture/Compare 3 DMA request enable */
#define TIM_DIER_CC4DE_Pos    (12U)
#define TIM_DIER_CC4DE_Msk    (0x1UL << TIM_DIER_CC4DE_Pos)	/*!< 0x00001000 */
#define TIM_DIER_CC4DE        TIM_DIER_CC4DE_Msk/*!<Capture/Compare 4 DMA request enable */
#define TIM_DIER_COMDE_Pos    (13U)
#define TIM_DIER_COMDE_Msk    (0x1UL << TIM_DIER_COMDE_Pos)	/*!< 0x00002000 */
#define TIM_DIER_COMDE        TIM_DIER_COMDE_Msk/*!<COM DMA request enable               */
#define TIM_DIER_TDE_Pos      (14U)
#define TIM_DIER_TDE_Msk      (0x1UL << TIM_DIER_TDE_Pos)	/*!< 0x00004000 */
#define TIM_DIER_TDE          TIM_DIER_TDE_Msk				/*!<Trigger DMA request enable           */

/********************  Bit definition for TIM_SR register  ********************/
#define TIM_SR_UIF_Pos      (0U)
#define TIM_SR_UIF_Msk      (0x1UL << TIM_SR_UIF_Pos)	/*!< 0x00000001 */
#define TIM_SR_UIF          TIM_SR_UIF_Msk				/*!<Update interrupt Flag              */
#define TIM_SR_CC1IF_Pos    (1U)
#define TIM_SR_CC1IF_Msk    (0x1UL << TIM_SR_CC1IF_Pos)	/*!< 0x00000002 */
#define TIM_SR_CC1IF        TIM_SR_CC1IF_Msk/*!<Capture/Compare 1 interrupt Flag   */
#define TIM_SR_CC2IF_Pos    (2U)
#define TIM_SR_CC2IF_Msk    (0x1UL << TIM_SR_CC2IF_Pos)	/*!< 0x00000004 */
#define TIM_SR_CC2IF        TIM_SR_CC2IF_Msk/*!<Capture/Compare 2 interrupt Flag   */
#define TIM_SR_CC3IF_Pos    (3U)
#define TIM_SR_CC3IF_Msk    (0x1UL << TIM_SR_CC3IF_Pos)	/*!< 0x00000008 */
#define TIM_SR_CC3IF        TIM_SR_CC3IF_Msk/*!<Capture/Compare 3 interrupt Flag   */
#define TIM_SR_CC4IF_Pos    (4U)
#define TIM_SR_CC4IF_Msk    (0x1UL << TIM_SR_CC4IF_Pos)	/*!< 0x00000010 */
#define TIM_SR_CC4IF        TIM_SR_CC4IF_Msk/*!<Capture/Compare 4 interrupt Flag   */
#define TIM_SR_COMIF_Pos    (5U)
#define TIM_SR_COMIF_Msk    (0x1UL << TIM_SR_COMIF_Pos)	/*!< 0x00000020 */
#define TIM_SR_COMIF        TIM_SR_COMIF_Msk/*!<COM interrupt Flag                 */
#define TIM_SR_TIF_Pos      (6U)
#define TIM_SR_TIF_Msk      (0x1UL << TIM_SR_TIF_Pos)	/*!< 0x00000040 */
#define TIM_SR_TIF          TIM_SR_TIF_Msk				/*!<Trigger interrupt Flag             */
#define TIM_SR_BIF_Pos      (7U)
#define TIM_SR_BIF_Msk      (0x1UL << TIM_SR_BIF_Pos)	/*!< 0x00000080 */
#define TIM_SR_BIF          TIM_SR_BIF_Msk				/*!<Break interrupt Flag               */
#define TIM_SR_B2IF_Pos     (8U)
#define TIM_SR_B2IF_Msk     (0x1UL << TIM_SR_B2IF_Pos)	/*!< 0x00000100 */
#define TIM_SR_B2IF         TIM_SR_B2IF_Msk				/*!<Break2 interrupt Flag               */
#define TIM_SR_CC1OF_Pos    (9U)
#define TIM_SR_CC1OF_Msk    (0x1UL << TIM_SR_CC1OF_Pos)	/*!< 0x00000200 */
#define TIM_SR_CC1OF        TIM_SR_CC1OF_Msk/*!<Capture/Compare 1 Overcapture Flag */
#define TIM_SR_CC2OF_Pos    (10U)
#define TIM_SR_CC2OF_Msk    (0x1UL << TIM_SR_CC2OF_Pos)	/*!< 0x00000400 */
#define TIM_SR_CC2OF        TIM_SR_CC2OF_Msk/*!<Capture/Compare 2 Overcapture Flag */
#define TIM_SR_CC3OF_Pos    (11U)
#define TIM_SR_CC3OF_Msk    (0x1UL << TIM_SR_CC3OF_Pos)	/*!< 0x00000800 */
#define TIM_SR_CC3OF        TIM_SR_CC3OF_Msk/*!<Capture/Compare 3 Overcapture Flag */
#define TIM_SR_CC4OF_Pos    (12U)
#define TIM_SR_CC4OF_Msk    (0x1UL << TIM_SR_CC4OF_Pos)	/*!< 0x00001000 */
#define TIM_SR_CC4OF        TIM_SR_CC4OF_Msk/*!<Capture/Compare 4 Overcapture Flag */
#define TIM_SR_SBIF_Pos     (13U)
#define TIM_SR_SBIF_Msk     (0x1UL << TIM_SR_SBIF_Pos)	/*!< 0x00002000 */
#define TIM_SR_SBIF         TIM_SR_SBIF_Msk				/*!<System Break interrupt Flag */
#define TIM_SR_CC5IF_Pos    (16U)
#define TIM_SR_CC5IF_Msk    (0x1UL << TIM_SR_CC5IF_Pos)	/*!< 0x00010000 */
#define TIM_SR_CC5IF        TIM_SR_CC5IF_Msk/*!<Capture/Compare 5 interrupt Flag */
#define TIM_SR_CC6IF_Pos    (17U)
#define TIM_SR_CC6IF_Msk    (0x1UL << TIM_SR_CC6IF_Pos)	/*!< 0x00020000 */
#define TIM_SR_CC6IF        TIM_SR_CC6IF_Msk/*!<Capture/Compare 6 interrupt Flag */

/*******************  Bit definition for TIM_EGR register  ********************/
#define TIM_EGR_UG_Pos      (0U)
#define TIM_EGR_UG_Msk      (0x1UL << TIM_EGR_UG_Pos)	/*!< 0x00000001 */
#define TIM_EGR_UG          TIM_EGR_UG_Msk				/*!<Update Generation                         */
#define TIM_EGR_CC1G_Pos    (1U)
#define TIM_EGR_CC1G_Msk    (0x1UL << TIM_EGR_CC1G_Pos)	/*!< 0x00000002 */
#define TIM_EGR_CC1G        TIM_EGR_CC1G_Msk/*!<Capture/Compare 1 Generation              */
#define TIM_EGR_CC2G_Pos    (2U)
#define TIM_EGR_CC2G_Msk    (0x1UL << TIM_EGR_CC2G_Pos)	/*!< 0x00000004 */
#define TIM_EGR_CC2G        TIM_EGR_CC2G_Msk/*!<Capture/Compare 2 Generation              */
#define TIM_EGR_CC3G_Pos    (3U)
#define TIM_EGR_CC3G_Msk    (0x1UL << TIM_EGR_CC3G_Pos)	/*!< 0x00000008 */
#define TIM_EGR_CC3G        TIM_EGR_CC3G_Msk/*!<Capture/Compare 3 Generation              */
#define TIM_EGR_CC4G_Pos    (4U)
#define TIM_EGR_CC4G_Msk    (0x1UL << TIM_EGR_CC4G_Pos)	/*!< 0x00000010 */
#define TIM_EGR_CC4G        TIM_EGR_CC4G_Msk/*!<Capture/Compare 4 Generation              */
#define TIM_EGR_COMG_Pos    (5U)
#define TIM_EGR_COMG_Msk    (0x1UL << TIM_EGR_COMG_Pos)	/*!< 0x00000020 */
#define TIM_EGR_COMG        TIM_EGR_COMG_Msk/*!<Capture/Compare Control Update Generation */
#define TIM_EGR_TG_Pos      (6U)
#define TIM_EGR_TG_Msk      (0x1UL << TIM_EGR_TG_Pos)	/*!< 0x00000040 */
#define TIM_EGR_TG          TIM_EGR_TG_Msk				/*!<Trigger Generation                        */
#define TIM_EGR_BG_Pos      (7U)
#define TIM_EGR_BG_Msk      (0x1UL << TIM_EGR_BG_Pos)	/*!< 0x00000080 */
#define TIM_EGR_BG          TIM_EGR_BG_Msk				/*!<Break Generation                          */
#define TIM_EGR_B2G_Pos     (8U)
#define TIM_EGR_B2G_Msk     (0x1UL << TIM_EGR_B2G_Pos)	/*!< 0x00000100 */
#define TIM_EGR_B2G         TIM_EGR_B2G_Msk				/*!<Break2 Generation                          */

/******************  Bit definition for TIM_CCMR1 register  *******************/
#define TIM_CCMR1_CC1S_Pos     (0U)
#define TIM_CCMR1_CC1S_Msk     (0x3UL << TIM_CCMR1_CC1S_Pos)/*!< 0x00000003 */
#define TIM_CCMR1_CC1S         TIM_CCMR1_CC1S_Msk	/*!<CC1S[1:0] bits (Capture/Compare 1 Selection) */
#define TIM_CCMR1_CC1S_0       (0x1UL << TIM_CCMR1_CC1S_Pos)/*!< 0x00000001 */
#define TIM_CCMR1_CC1S_1       (0x2UL << TIM_CCMR1_CC1S_Pos)/*!< 0x00000002 */

#define TIM_CCMR1_OC1FE_Pos    (2U)
#define TIM_CCMR1_OC1FE_Msk    (0x1UL << TIM_CCMR1_OC1FE_Pos)	/*!< 0x00000004 */
#define TIM_CCMR1_OC1FE        TIM_CCMR1_OC1FE_Msk				/*!<Output Compare 1 Fast enable                 */
#define TIM_CCMR1_OC1PE_Pos    (3U)
#define TIM_CCMR1_OC1PE_Msk    (0x1UL << TIM_CCMR1_OC1PE_Pos)	/*!< 0x00000008 */
#define TIM_CCMR1_OC1PE        TIM_CCMR1_OC1PE_Msk				/*!<Output Compare 1 Preload enable              */

#define TIM_CCMR1_OC1M_Pos     (4U)
#define TIM_CCMR1_OC1M_Msk     (0x1007UL << TIM_CCMR1_OC1M_Pos)	/*!< 0x00010070 */
#define TIM_CCMR1_OC1M         TIM_CCMR1_OC1M_Msk				/*!<OC1M[2:0] bits (Output Compare 1 Mode)       */
#define TIM_CCMR1_OC1M_0       (0x0001UL << TIM_CCMR1_OC1M_Pos)	/*!< 0x00000010 */
#define TIM_CCMR1_OC1M_1       (0x0002UL << TIM_CCMR1_OC1M_Pos)	/*!< 0x00000020 */
#define TIM_CCMR1_OC1M_2       (0x0004UL << TIM_CCMR1_OC1M_Pos)	/*!< 0x00000040 */
#define TIM_CCMR1_OC1M_3       (0x1000UL << TIM_CCMR1_OC1M_Pos)	/*!< 0x00010000 */

#define TIM_CCMR1_OC1CE_Pos    (7U)
#define TIM_CCMR1_OC1CE_Msk    (0x1UL << TIM_CCMR1_OC1CE_Pos)	/*!< 0x00000080 */
#define TIM_CCMR1_OC1CE        TIM_CCMR1_OC1CE_Msk				/*!<Output Compare 1Clear Enable                 */

#define TIM_CCMR1_CC2S_Pos     (8U)
#define TIM_CCMR1_CC2S_Msk     (0x3UL << TIM_CCMR1_CC2S_Pos)/*!< 0x00000300 */
#define TIM_CCMR1_CC2S         TIM_CCMR1_CC2S_Msk	/*!<CC2S[1:0] bits (Capture/Compare 2 Selection) */
#define TIM_CCMR1_CC2S_0       (0x1UL << TIM_CCMR1_CC2S_Pos)/*!< 0x00000100 */
#define TIM_CCMR1_CC2S_1       (0x2UL << TIM_CCMR1_CC2S_Pos)/*!< 0x00000200 */

#define TIM_CCMR1_OC2FE_Pos    (10U)
#define TIM_CCMR1_OC2FE_Msk    (0x1UL << TIM_CCMR1_OC2FE_Pos)	/*!< 0x00000400 */
#define TIM_CCMR1_OC2FE        TIM_CCMR1_OC2FE_Msk				/*!<Output Compare 2 Fast enable                 */
#define TIM_CCMR1_OC2PE_Pos    (11U)
#define TIM_CCMR1_OC2PE_Msk    (0x1UL << TIM_CCMR1_OC2PE_Pos)	/*!< 0x00000800 */
#define TIM_CCMR1_OC2PE        TIM_CCMR1_OC2PE_Msk				/*!<Output Compare 2 Preload enable              */

#define TIM_CCMR1_OC2M_Pos     (12U)
#define TIM_CCMR1_OC2M_Msk     (0x1007UL << TIM_CCMR1_OC2M_Pos)	/*!< 0x01007000 */
#define TIM_CCMR1_OC2M         TIM_CCMR1_OC2M_Msk				/*!<OC2M[2:0] bits (Output Compare 2 Mode)       */
#define TIM_CCMR1_OC2M_0       (0x0001UL << TIM_CCMR1_OC2M_Pos)	/*!< 0x00001000 */
#define TIM_CCMR1_OC2M_1       (0x0002UL << TIM_CCMR1_OC2M_Pos)	/*!< 0x00002000 */
#define TIM_CCMR1_OC2M_2       (0x0004UL << TIM_CCMR1_OC2M_Pos)	/*!< 0x00004000 */
#define TIM_CCMR1_OC2M_3       (0x1000UL << TIM_CCMR1_OC2M_Pos)	/*!< 0x01000000 */

#define TIM_CCMR1_OC2CE_Pos    (15U)
#define TIM_CCMR1_OC2CE_Msk    (0x1UL << TIM_CCMR1_OC2CE_Pos)	/*!< 0x00008000 */
#define TIM_CCMR1_OC2CE        TIM_CCMR1_OC2CE_Msk				/*!<Output Compare 2 Clear Enable */

/*----------------------------------------------------------------------------*/

#define TIM_CCMR1_IC1PSC_Pos    (2U)
#define TIM_CCMR1_IC1PSC_Msk    (0x3UL << TIM_CCMR1_IC1PSC_Pos)	/*!< 0x0000000C */
#define TIM_CCMR1_IC1PSC        TIM_CCMR1_IC1PSC_Msk/*!<IC1PSC[1:0] bits (Input Capture 1 Prescaler) */
#define TIM_CCMR1_IC1PSC_0      (0x1UL << TIM_CCMR1_IC1PSC_Pos)	/*!< 0x0004 */
#define TIM_CCMR1_IC1PSC_1      (0x2UL << TIM_CCMR1_IC1PSC_Pos)	/*!< 0x0008 */

#define TIM_CCMR1_IC1F_Pos      (4U)
#define TIM_CCMR1_IC1F_Msk      (0xFUL << TIM_CCMR1_IC1F_Pos)	/*!< 0x000000F0 */
#define TIM_CCMR1_IC1F          TIM_CCMR1_IC1F_Msk				/*!<IC1F[3:0] bits (Input Capture 1 Filter)      */
#define TIM_CCMR1_IC1F_0        (0x1UL << TIM_CCMR1_IC1F_Pos)	/*!< 0x0010 */
#define TIM_CCMR1_IC1F_1        (0x2UL << TIM_CCMR1_IC1F_Pos)	/*!< 0x0020 */
#define TIM_CCMR1_IC1F_2        (0x4UL << TIM_CCMR1_IC1F_Pos)	/*!< 0x0040 */
#define TIM_CCMR1_IC1F_3        (0x8UL << TIM_CCMR1_IC1F_Pos)	/*!< 0x0080 */

#define TIM_CCMR1_IC2PSC_Pos    (10U)
#define TIM_CCMR1_IC2PSC_Msk    (0x3UL << TIM_CCMR1_IC2PSC_Pos)	/*!< 0x00000C00 */
#define TIM_CCMR1_IC2PSC        TIM_CCMR1_IC2PSC_Msk/*!<IC2PSC[1:0] bits (Input Capture 2 Prescaler)  */
#define TIM_CCMR1_IC2PSC_0      (0x1UL << TIM_CCMR1_IC2PSC_Pos)	/*!< 0x0400 */
#define TIM_CCMR1_IC2PSC_1      (0x2UL << TIM_CCMR1_IC2PSC_Pos)	/*!< 0x0800 */

#define TIM_CCMR1_IC2F_Pos      (12U)
#define TIM_CCMR1_IC2F_Msk      (0xFUL << TIM_CCMR1_IC2F_Pos)	/*!< 0x0000F000 */
#define TIM_CCMR1_IC2F          TIM_CCMR1_IC2F_Msk				/*!<IC2F[3:0] bits (Input Capture 2 Filter)       */
#define TIM_CCMR1_IC2F_0        (0x1UL << TIM_CCMR1_IC2F_Pos)	/*!< 0x1000 */
#define TIM_CCMR1_IC2F_1        (0x2UL << TIM_CCMR1_IC2F_Pos)	/*!< 0x2000 */
#define TIM_CCMR1_IC2F_2        (0x4UL << TIM_CCMR1_IC2F_Pos)	/*!< 0x4000 */
#define TIM_CCMR1_IC2F_3        (0x8UL << TIM_CCMR1_IC2F_Pos)	/*!< 0x8000 */

/******************  Bit definition for TIM_CCMR2 register  *******************/
#define TIM_CCMR2_CC3S_Pos     (0U)
#define TIM_CCMR2_CC3S_Msk     (0x3UL << TIM_CCMR2_CC3S_Pos)/*!< 0x00000003 */
#define TIM_CCMR2_CC3S         TIM_CCMR2_CC3S_Msk	/*!<CC3S[1:0] bits (Capture/Compare 3 Selection)  */
#define TIM_CCMR2_CC3S_0       (0x1UL << TIM_CCMR2_CC3S_Pos)/*!< 0x00000001 */
#define TIM_CCMR2_CC3S_1       (0x2UL << TIM_CCMR2_CC3S_Pos)/*!< 0x00000002 */

#define TIM_CCMR2_OC3FE_Pos    (2U)
#define TIM_CCMR2_OC3FE_Msk    (0x1UL << TIM_CCMR2_OC3FE_Pos)	/*!< 0x00000004 */
#define TIM_CCMR2_OC3FE        TIM_CCMR2_OC3FE_Msk				/*!<Output Compare 3 Fast enable           */
#define TIM_CCMR2_OC3PE_Pos    (3U)
#define TIM_CCMR2_OC3PE_Msk    (0x1UL << TIM_CCMR2_OC3PE_Pos)	/*!< 0x00000008 */
#define TIM_CCMR2_OC3PE        TIM_CCMR2_OC3PE_Msk				/*!<Output Compare 3 Preload enable        */

#define TIM_CCMR2_OC3M_Pos     (4U)
#define TIM_CCMR2_OC3M_Msk     (0x1007UL << TIM_CCMR2_OC3M_Pos)	/*!< 0x00010070 */
#define TIM_CCMR2_OC3M         TIM_CCMR2_OC3M_Msk				/*!<OC3M[2:0] bits (Output Compare 3 Mode) */
#define TIM_CCMR2_OC3M_0       (0x0001UL << TIM_CCMR2_OC3M_Pos)	/*!< 0x00000010 */
#define TIM_CCMR2_OC3M_1       (0x0002UL << TIM_CCMR2_OC3M_Pos)	/*!< 0x00000020 */
#define TIM_CCMR2_OC3M_2       (0x0004UL << TIM_CCMR2_OC3M_Pos)	/*!< 0x00000040 */
#define TIM_CCMR2_OC3M_3       (0x1000UL << TIM_CCMR2_OC3M_Pos)	/*!< 0x00010000 */


#define TIM_CCMR2_OC3CE_Pos    (7U)
#define TIM_CCMR2_OC3CE_Msk    (0x1UL << TIM_CCMR2_OC3CE_Pos)	/*!< 0x00000080 */
#define TIM_CCMR2_OC3CE        TIM_CCMR2_OC3CE_Msk				/*!<Output Compare 3 Clear Enable */

#define TIM_CCMR2_CC4S_Pos     (8U)
#define TIM_CCMR2_CC4S_Msk     (0x3UL << TIM_CCMR2_CC4S_Pos)/*!< 0x00000300 */
#define TIM_CCMR2_CC4S         TIM_CCMR2_CC4S_Msk	/*!<CC4S[1:0] bits (Capture/Compare 4 Selection) */
#define TIM_CCMR2_CC4S_0       (0x1UL << TIM_CCMR2_CC4S_Pos)/*!< 0x00000100 */
#define TIM_CCMR2_CC4S_1       (0x2UL << TIM_CCMR2_CC4S_Pos)/*!< 0x00000200 */

#define TIM_CCMR2_OC4FE_Pos    (10U)
#define TIM_CCMR2_OC4FE_Msk    (0x1UL << TIM_CCMR2_OC4FE_Pos)	/*!< 0x00000400 */
#define TIM_CCMR2_OC4FE        TIM_CCMR2_OC4FE_Msk				/*!<Output Compare 4 Fast enable    */
#define TIM_CCMR2_OC4PE_Pos    (11U)
#define TIM_CCMR2_OC4PE_Msk    (0x1UL << TIM_CCMR2_OC4PE_Pos)	/*!< 0x00000800 */
#define TIM_CCMR2_OC4PE        TIM_CCMR2_OC4PE_Msk				/*!<Output Compare 4 Preload enable */

#define TIM_CCMR2_OC4M_Pos     (12U)
#define TIM_CCMR2_OC4M_Msk     (0x1007UL << TIM_CCMR2_OC4M_Pos)	/*!< 0x01007000 */
#define TIM_CCMR2_OC4M         TIM_CCMR2_OC4M_Msk				/*!<OC4M[2:0] bits (Output Compare 4 Mode) */
#define TIM_CCMR2_OC4M_0       (0x0001UL << TIM_CCMR2_OC4M_Pos)	/*!< 0x00001000 */
#define TIM_CCMR2_OC4M_1       (0x0002UL << TIM_CCMR2_OC4M_Pos)	/*!< 0x00002000 */
#define TIM_CCMR2_OC4M_2       (0x0004UL << TIM_CCMR2_OC4M_Pos)	/*!< 0x00004000 */
#define TIM_CCMR2_OC4M_3       (0x1000UL << TIM_CCMR2_OC4M_Pos)	/*!< 0x01000000 */

#define TIM_CCMR2_OC4CE_Pos    (15U)
#define TIM_CCMR2_OC4CE_Msk    (0x1UL << TIM_CCMR2_OC4CE_Pos)	/*!< 0x00008000 */
#define TIM_CCMR2_OC4CE        TIM_CCMR2_OC4CE_Msk				/*!<Output Compare 4 Clear Enable */

/*----------------------------------------------------------------------------*/

#define TIM_CCMR2_IC3PSC_Pos    (2U)
#define TIM_CCMR2_IC3PSC_Msk    (0x3UL << TIM_CCMR2_IC3PSC_Pos)	/*!< 0x0000000C */
#define TIM_CCMR2_IC3PSC        TIM_CCMR2_IC3PSC_Msk/*!<IC3PSC[1:0] bits (Input Capture 3 Prescaler) */
#define TIM_CCMR2_IC3PSC_0      (0x1UL << TIM_CCMR2_IC3PSC_Pos)	/*!< 0x0004 */
#define TIM_CCMR2_IC3PSC_1      (0x2UL << TIM_CCMR2_IC3PSC_Pos)	/*!< 0x0008 */

#define TIM_CCMR2_IC3F_Pos      (4U)
#define TIM_CCMR2_IC3F_Msk      (0xFUL << TIM_CCMR2_IC3F_Pos)	/*!< 0x000000F0 */
#define TIM_CCMR2_IC3F          TIM_CCMR2_IC3F_Msk				/*!<IC3F[3:0] bits (Input Capture 3 Filter) */
#define TIM_CCMR2_IC3F_0        (0x1UL << TIM_CCMR2_IC3F_Pos)	/*!< 0x0010 */
#define TIM_CCMR2_IC3F_1        (0x2UL << TIM_CCMR2_IC3F_Pos)	/*!< 0x0020 */
#define TIM_CCMR2_IC3F_2        (0x4UL << TIM_CCMR2_IC3F_Pos)	/*!< 0x0040 */
#define TIM_CCMR2_IC3F_3        (0x8UL << TIM_CCMR2_IC3F_Pos)	/*!< 0x0080 */

#define TIM_CCMR2_IC4PSC_Pos    (10U)
#define TIM_CCMR2_IC4PSC_Msk    (0x3UL << TIM_CCMR2_IC4PSC_Pos)	/*!< 0x00000C00 */
#define TIM_CCMR2_IC4PSC        TIM_CCMR2_IC4PSC_Msk/*!<IC4PSC[1:0] bits (Input Capture 4 Prescaler) */
#define TIM_CCMR2_IC4PSC_0      (0x1UL << TIM_CCMR2_IC4PSC_Pos)	/*!< 0x0400 */
#define TIM_CCMR2_IC4PSC_1      (0x2UL << TIM_CCMR2_IC4PSC_Pos)	/*!< 0x0800 */

#define TIM_CCMR2_IC4F_Pos      (12U)
#define TIM_CCMR2_IC4F_Msk      (0xFUL << TIM_CCMR2_IC4F_Pos)	/*!< 0x0000F000 */
#define TIM_CCMR2_IC4F          TIM_CCMR2_IC4F_Msk				/*!<IC4F[3:0] bits (Input Capture 4 Filter) */
#define TIM_CCMR2_IC4F_0        (0x1UL << TIM_CCMR2_IC4F_Pos)	/*!< 0x1000 */
#define TIM_CCMR2_IC4F_1        (0x2UL << TIM_CCMR2_IC4F_Pos)	/*!< 0x2000 */
#define TIM_CCMR2_IC4F_2        (0x4UL << TIM_CCMR2_IC4F_Pos)	/*!< 0x4000 */
#define TIM_CCMR2_IC4F_3        (0x8UL << TIM_CCMR2_IC4F_Pos)	/*!< 0x8000 */

/*******************  Bit definition for TIM_CCER register  *******************/
#define TIM_CCER_CC1E_Pos     (0U)
#define TIM_CCER_CC1E_Msk     (0x1UL << TIM_CCER_CC1E_Pos)	/*!< 0x00000001 */
#define TIM_CCER_CC1E         TIM_CCER_CC1E_Msk				/*!<Capture/Compare 1 output enable */
#define TIM_CCER_CC1P_Pos     (1U)
#define TIM_CCER_CC1P_Msk     (0x1UL << TIM_CCER_CC1P_Pos)	/*!< 0x00000002 */
#define TIM_CCER_CC1P         TIM_CCER_CC1P_Msk				/*!<Capture/Compare 1 output Polarity */
#define TIM_CCER_CC1NE_Pos    (2U)
#define TIM_CCER_CC1NE_Msk    (0x1UL << TIM_CCER_CC1NE_Pos)	/*!< 0x00000004 */
#define TIM_CCER_CC1NE        TIM_CCER_CC1NE_Msk/*!<Capture/Compare 1 Complementary output enable */
#define TIM_CCER_CC1NP_Pos    (3U)
#define TIM_CCER_CC1NP_Msk    (0x1UL << TIM_CCER_CC1NP_Pos)	/*!< 0x00000008 */
#define TIM_CCER_CC1NP        TIM_CCER_CC1NP_Msk/*!<Capture/Compare 1 Complementary output Polarity */
#define TIM_CCER_CC2E_Pos     (4U)
#define TIM_CCER_CC2E_Msk     (0x1UL << TIM_CCER_CC2E_Pos)	/*!< 0x00000010 */
#define TIM_CCER_CC2E         TIM_CCER_CC2E_Msk				/*!<Capture/Compare 2 output enable */
#define TIM_CCER_CC2P_Pos     (5U)
#define TIM_CCER_CC2P_Msk     (0x1UL << TIM_CCER_CC2P_Pos)	/*!< 0x00000020 */
#define TIM_CCER_CC2P         TIM_CCER_CC2P_Msk				/*!<Capture/Compare 2 output Polarity */
#define TIM_CCER_CC2NE_Pos    (6U)
#define TIM_CCER_CC2NE_Msk    (0x1UL << TIM_CCER_CC2NE_Pos)	/*!< 0x00000040 */
#define TIM_CCER_CC2NE        TIM_CCER_CC2NE_Msk/*!<Capture/Compare 2 Complementary output enable */
#define TIM_CCER_CC2NP_Pos    (7U)
#define TIM_CCER_CC2NP_Msk    (0x1UL << TIM_CCER_CC2NP_Pos)	/*!< 0x00000080 */
#define TIM_CCER_CC2NP        TIM_CCER_CC2NP_Msk/*!<Capture/Compare 2 Complementary output Polarity */
#define TIM_CCER_CC3E_Pos     (8U)
#define TIM_CCER_CC3E_Msk     (0x1UL << TIM_CCER_CC3E_Pos)	/*!< 0x00000100 */
#define TIM_CCER_CC3E         TIM_CCER_CC3E_Msk				/*!<Capture/Compare 3 output enable */
#define TIM_CCER_CC3P_Pos     (9U)
#define TIM_CCER_CC3P_Msk     (0x1UL << TIM_CCER_CC3P_Pos)	/*!< 0x00000200 */
#define TIM_CCER_CC3P         TIM_CCER_CC3P_Msk				/*!<Capture/Compare 3 output Polarity */
#define TIM_CCER_CC3NE_Pos    (10U)
#define TIM_CCER_CC3NE_Msk    (0x1UL << TIM_CCER_CC3NE_Pos)	/*!< 0x00000400 */
#define TIM_CCER_CC3NE        TIM_CCER_CC3NE_Msk/*!<Capture/Compare 3 Complementary output enable */
#define TIM_CCER_CC3NP_Pos    (11U)
#define TIM_CCER_CC3NP_Msk    (0x1UL << TIM_CCER_CC3NP_Pos)	/*!< 0x00000800 */
#define TIM_CCER_CC3NP        TIM_CCER_CC3NP_Msk/*!<Capture/Compare 3 Complementary output Polarity */
#define TIM_CCER_CC4E_Pos     (12U)
#define TIM_CCER_CC4E_Msk     (0x1UL << TIM_CCER_CC4E_Pos)	/*!< 0x00001000 */
#define TIM_CCER_CC4E         TIM_CCER_CC4E_Msk				/*!<Capture/Compare 4 output enable */
#define TIM_CCER_CC4P_Pos     (13U)
#define TIM_CCER_CC4P_Msk     (0x1UL << TIM_CCER_CC4P_Pos)	/*!< 0x00002000 */
#define TIM_CCER_CC4P         TIM_CCER_CC4P_Msk				/*!<Capture/Compare 4 output Polarity */
#define TIM_CCER_CC4NP_Pos    (15U)
#define TIM_CCER_CC4NP_Msk    (0x1UL << TIM_CCER_CC4NP_Pos)	/*!< 0x00008000 */
#define TIM_CCER_CC4NP        TIM_CCER_CC4NP_Msk/*!<Capture/Compare 4 Complementary output Polarity */
#define TIM_CCER_CC5E_Pos     (16U)
#define TIM_CCER_CC5E_Msk     (0x1UL << TIM_CCER_CC5E_Pos)	/*!< 0x00010000 */
#define TIM_CCER_CC5E         TIM_CCER_CC5E_Msk				/*!<Capture/Compare 5 output enable */
#define TIM_CCER_CC5P_Pos     (17U)
#define TIM_CCER_CC5P_Msk     (0x1UL << TIM_CCER_CC5P_Pos)	/*!< 0x00020000 */
#define TIM_CCER_CC5P         TIM_CCER_CC5P_Msk				/*!<Capture/Compare 5 output Polarity */
#define TIM_CCER_CC6E_Pos     (20U)
#define TIM_CCER_CC6E_Msk     (0x1UL << TIM_CCER_CC6E_Pos)	/*!< 0x00100000 */
#define TIM_CCER_CC6E         TIM_CCER_CC6E_Msk				/*!<Capture/Compare 6 output enable */
#define TIM_CCER_CC6P_Pos     (21U)
#define TIM_CCER_CC6P_Msk     (0x1UL << TIM_CCER_CC6P_Pos)	/*!< 0x00200000 */
#define TIM_CCER_CC6P         TIM_CCER_CC6P_Msk				/*!<Capture/Compare 6 output Polarity */


/*******************  Bit definition for TIM_CNT register  ********************/
#define TIM_CNT_CNT_Pos       (0U)
#define TIM_CNT_CNT_Msk       (0xFFFFFFFFUL << TIM_CNT_CNT_Pos)	/*!< 0xFFFFFFFF */
#define TIM_CNT_CNT           TIM_CNT_CNT_Msk					/*!<Counter Value            */
#define TIM_CNT_UIFCPY_Pos    (31U)
#define TIM_CNT_UIFCPY_Msk    (0x1UL << TIM_CNT_UIFCPY_Pos)	/*!< 0x80000000 */
#define TIM_CNT_UIFCPY        TIM_CNT_UIFCPY_Msk/*!<Update interrupt flag copy (if UIFREMAP=1) */

/*******************  Bit definition for TIM_PSC register  ********************/
#define TIM_PSC_PSC_Pos    (0U)
#define TIM_PSC_PSC_Msk    (0xFFFFUL << TIM_PSC_PSC_Pos)/*!< 0x0000FFFF */
#define TIM_PSC_PSC        TIM_PSC_PSC_Msk	/*!<Prescaler Value          */

/*******************  Bit definition for TIM_ARR register  ********************/
#define TIM_ARR_ARR_Pos    (0U)
#define TIM_ARR_ARR_Msk    (0xFFFFFFFFUL << TIM_ARR_ARR_Pos)/*!< 0xFFFFFFFF */
#define TIM_ARR_ARR        TIM_ARR_ARR_Msk	/*!<actual auto-reload Value */

/*******************  Bit definition for TIM_RCR register  ********************/
#define TIM_RCR_REP_Pos    (0U)
#define TIM_RCR_REP_Msk    (0xFFFFUL << TIM_RCR_REP_Pos)/*!< 0x0000FFFF */
#define TIM_RCR_REP        TIM_RCR_REP_Msk	/*!<Repetition Counter Value */

/*******************  Bit definition for TIM_CCR1 register  *******************/
#define TIM_CCR1_CCR1_Pos    (0U)
#define TIM_CCR1_CCR1_Msk    (0xFFFFUL << TIM_CCR1_CCR1_Pos)/*!< 0x0000FFFF */
#define TIM_CCR1_CCR1        TIM_CCR1_CCR1_Msk	/*!<Capture/Compare 1 Value  */

/*******************  Bit definition for TIM_CCR2 register  *******************/
#define TIM_CCR2_CCR2_Pos    (0U)
#define TIM_CCR2_CCR2_Msk    (0xFFFFUL << TIM_CCR2_CCR2_Pos)/*!< 0x0000FFFF */
#define TIM_CCR2_CCR2        TIM_CCR2_CCR2_Msk	/*!<Capture/Compare 2 Value  */

/*******************  Bit definition for TIM_CCR3 register  *******************/
#define TIM_CCR3_CCR3_Pos    (0U)
#define TIM_CCR3_CCR3_Msk    (0xFFFFUL << TIM_CCR3_CCR3_Pos)/*!< 0x0000FFFF */
#define TIM_CCR3_CCR3        TIM_CCR3_CCR3_Msk	/*!<Capture/Compare 3 Value  */

/*******************  Bit definition for TIM_CCR4 register  *******************/
#define TIM_CCR4_CCR4_Pos    (0U)
#define TIM_CCR4_CCR4_Msk    (0xFFFFUL << TIM_CCR4_CCR4_Pos)/*!< 0x0000FFFF */
#define TIM_CCR4_CCR4        TIM_CCR4_CCR4_Msk	/*!<Capture/Compare 4 Value  */

/*******************  Bit definition for TIM_BDTR register  *******************/
#define TIM_BDTR_DTG_Pos     (0U)
#define TIM_BDTR_DTG_Msk     (0xFFUL << TIM_BDTR_DTG_Pos)	/*!< 0x000000FF */
#define TIM_BDTR_DTG         TIM_BDTR_DTG_Msk				/*!<DTG[0:7] bits (Dead-Time Generator set-up) */
#define TIM_BDTR_DTG_0       (0x01UL << TIM_BDTR_DTG_Pos)	/*!< 0x00000001 */
#define TIM_BDTR_DTG_1       (0x02UL << TIM_BDTR_DTG_Pos)	/*!< 0x00000002 */
#define TIM_BDTR_DTG_2       (0x04UL << TIM_BDTR_DTG_Pos)	/*!< 0x00000004 */
#define TIM_BDTR_DTG_3       (0x08UL << TIM_BDTR_DTG_Pos)	/*!< 0x00000008 */
#define TIM_BDTR_DTG_4       (0x10UL << TIM_BDTR_DTG_Pos)	/*!< 0x00000010 */
#define TIM_BDTR_DTG_5       (0x20UL << TIM_BDTR_DTG_Pos)	/*!< 0x00000020 */
#define TIM_BDTR_DTG_6       (0x40UL << TIM_BDTR_DTG_Pos)	/*!< 0x00000040 */
#define TIM_BDTR_DTG_7       (0x80UL << TIM_BDTR_DTG_Pos)	/*!< 0x00000080 */

#define TIM_BDTR_LOCK_Pos    (8U)
#define TIM_BDTR_LOCK_Msk    (0x3UL << TIM_BDTR_LOCK_Pos)	/*!< 0x00000300 */
#define TIM_BDTR_LOCK        TIM_BDTR_LOCK_Msk				/*!<LOCK[1:0] bits (Lock Configuration) */
#define TIM_BDTR_LOCK_0      (0x1UL << TIM_BDTR_LOCK_Pos)	/*!< 0x00000100 */
#define TIM_BDTR_LOCK_1      (0x2UL << TIM_BDTR_LOCK_Pos)	/*!< 0x00000200 */

#define TIM_BDTR_OSSI_Pos    (10U)
#define TIM_BDTR_OSSI_Msk    (0x1UL << TIM_BDTR_OSSI_Pos)	/*!< 0x00000400 */
#define TIM_BDTR_OSSI        TIM_BDTR_OSSI_Msk				/*!<Off-State Selection for Idle mode */
#define TIM_BDTR_OSSR_Pos    (11U)
#define TIM_BDTR_OSSR_Msk    (0x1UL << TIM_BDTR_OSSR_Pos)	/*!< 0x00000800 */
#define TIM_BDTR_OSSR        TIM_BDTR_OSSR_Msk				/*!<Off-State Selection for Run mode  */
#define TIM_BDTR_BKE_Pos     (12U)
#define TIM_BDTR_BKE_Msk     (0x1UL << TIM_BDTR_BKE_Pos)/*!< 0x00001000 */
#define TIM_BDTR_BKE         TIM_BDTR_BKE_Msk	/*!<Break enable                      */
#define TIM_BDTR_BKP_Pos     (13U)
#define TIM_BDTR_BKP_Msk     (0x1UL << TIM_BDTR_BKP_Pos)/*!< 0x00002000 */
#define TIM_BDTR_BKP         TIM_BDTR_BKP_Msk	/*!<Break Polarity                    */
#define TIM_BDTR_AOE_Pos     (14U)
#define TIM_BDTR_AOE_Msk     (0x1UL << TIM_BDTR_AOE_Pos)/*!< 0x00004000 */
#define TIM_BDTR_AOE         TIM_BDTR_AOE_Msk	/*!<Automatic Output enable           */
#define TIM_BDTR_MOE_Pos     (15U)
#define TIM_BDTR_MOE_Msk     (0x1UL << TIM_BDTR_MOE_Pos)/*!< 0x00008000 */
#define TIM_BDTR_MOE         TIM_BDTR_MOE_Msk	/*!<Main Output enable                */
#define TIM_BDTR_BKF_Pos     (16U)
#define TIM_BDTR_BKF_Msk     (0xFUL << TIM_BDTR_BKF_Pos)/*!< 0x000F0000 */
#define TIM_BDTR_BKF         TIM_BDTR_BKF_Msk	/*!<Break Filter for Break1 */
#define TIM_BDTR_BK2F_Pos    (20U)
#define TIM_BDTR_BK2F_Msk    (0xFUL << TIM_BDTR_BK2F_Pos)	/*!< 0x00F00000 */
#define TIM_BDTR_BK2F        TIM_BDTR_BK2F_Msk				/*!<Break Filter for Break2 */
#define TIM_BDTR_BK2E_Pos    (24U)
#define TIM_BDTR_BK2E_Msk    (0x1UL << TIM_BDTR_BK2E_Pos)	/*!< 0x01000000 */
#define TIM_BDTR_BK2E        TIM_BDTR_BK2E_Msk				/*!<Break enable for Break2 */
#define TIM_BDTR_BK2P_Pos    (25U)
#define TIM_BDTR_BK2P_Msk    (0x1UL << TIM_BDTR_BK2P_Pos)	/*!< 0x02000000 */
#define TIM_BDTR_BK2P        TIM_BDTR_BK2P_Msk				/*!<Break Polarity for Break2 */

/*******************  Bit definition for TIM_DCR register  ********************/
#define TIM_DCR_DBA_Pos    (0U)
#define TIM_DCR_DBA_Msk    (0x1FUL << TIM_DCR_DBA_Pos)	/*!< 0x0000001F */
#define TIM_DCR_DBA        TIM_DCR_DBA_Msk				/*!<DBA[4:0] bits (DMA Base Address) */
#define TIM_DCR_DBA_0      (0x01UL << TIM_DCR_DBA_Pos)	/*!< 0x0001 */
#define TIM_DCR_DBA_1      (0x02UL << TIM_DCR_DBA_Pos)	/*!< 0x0002 */
#define TIM_DCR_DBA_2      (0x04UL << TIM_DCR_DBA_Pos)	/*!< 0x0004 */
#define TIM_DCR_DBA_3      (0x08UL << TIM_DCR_DBA_Pos)	/*!< 0x0008 */
#define TIM_DCR_DBA_4      (0x10UL << TIM_DCR_DBA_Pos)	/*!< 0x0010 */

#define TIM_DCR_DBL_Pos    (8U)
#define TIM_DCR_DBL_Msk    (0x1FUL << TIM_DCR_DBL_Pos)	/*!< 0x00001F00 */
#define TIM_DCR_DBL        TIM_DCR_DBL_Msk				/*!<DBL[4:0] bits (DMA Burst Length) */
#define TIM_DCR_DBL_0      (0x01UL << TIM_DCR_DBL_Pos)	/*!< 0x0100 */
#define TIM_DCR_DBL_1      (0x02UL << TIM_DCR_DBL_Pos)	/*!< 0x0200 */
#define TIM_DCR_DBL_2      (0x04UL << TIM_DCR_DBL_Pos)	/*!< 0x0400 */
#define TIM_DCR_DBL_3      (0x08UL << TIM_DCR_DBL_Pos)	/*!< 0x0800 */
#define TIM_DCR_DBL_4      (0x10UL << TIM_DCR_DBL_Pos)	/*!< 0x1000 */

/*******************  Bit definition for TIM_DMAR register  *******************/
#define TIM_DMAR_DMAB_Pos    (0U)
#define TIM_DMAR_DMAB_Msk    (0xFFFFUL << TIM_DMAR_DMAB_Pos)/*!< 0x0000FFFF */
#define TIM_DMAR_DMAB        TIM_DMAR_DMAB_Msk	/*!<DMA register for burst accesses                    */

/*******************  Bit definition for TIM_OR regiter  *********************/
#define TIM_OR_TI4_RMP_Pos     (6U)
#define TIM_OR_TI4_RMP_Msk     (0x3UL << TIM_OR_TI4_RMP_Pos)/*!< 0x000000C0 */
#define TIM_OR_TI4_RMP         TIM_OR_TI4_RMP_Msk	/*!<TI4_RMP[1:0] bits (TIM5 Input 4 remap)             */
#define TIM_OR_TI4_RMP_0       (0x1UL << TIM_OR_TI4_RMP_Pos)/*!< 0x0040 */
#define TIM_OR_TI4_RMP_1       (0x2UL << TIM_OR_TI4_RMP_Pos)/*!< 0x0080 */
#define TIM_OR_ITR1_RMP_Pos    (10U)
#define TIM_OR_ITR1_RMP_Msk    (0x3UL << TIM_OR_ITR1_RMP_Pos)	/*!< 0x00000C00 */
#define TIM_OR_ITR1_RMP        TIM_OR_ITR1_RMP_Msk				/*!<ITR1_RMP[1:0] bits (TIM2 Internal trigger 1 remap) */
#define TIM_OR_ITR1_RMP_0      (0x1UL << TIM_OR_ITR1_RMP_Pos)	/*!< 0x0400 */
#define TIM_OR_ITR1_RMP_1      (0x2UL << TIM_OR_ITR1_RMP_Pos)	/*!< 0x0800 */

/*******************  Bit definition for TIM2_OR register  *******************/
#define TIM2_OR_ITR1_RMP_Pos    (10U)
#define TIM2_OR_ITR1_RMP_Msk    (0x3UL << TIM2_OR_ITR1_RMP_Pos)	/*!< 0x00000C00 */
#define TIM2_OR_ITR1_RMP        TIM2_OR_ITR1_RMP_Msk/*!<TIM2 Internal trigger 1 remap */
#define TIM2_OR_ITR1_RMP_0      (0x1UL << TIM2_OR_ITR1_RMP_Pos)	/*!< 0x00000400 */
#define TIM2_OR_ITR1_RMP_1      (0x2UL << TIM2_OR_ITR1_RMP_Pos)	/*!< 0x00000800 */

/*******************  Bit definition for TIM5_OR register  *******************/
#define TIM5_OR_TI4_RMP_Pos    (6U)
#define TIM5_OR_TI4_RMP_Msk    (0x3UL << TIM5_OR_TI4_RMP_Pos)	/*!< 0x000000C0 */
#define TIM5_OR_TI4_RMP        TIM5_OR_TI4_RMP_Msk				/*!<TI4_RMP[1:0] bits (TIM5 Input Capture 4 remap) */
#define TIM5_OR_TI4_RMP_0      (0x1UL << TIM5_OR_TI4_RMP_Pos)	/*!< 0x00000040 */
#define TIM5_OR_TI4_RMP_1      (0x2UL << TIM5_OR_TI4_RMP_Pos)	/*!< 0x00000080 */

/*******************  Bit definition for TIM11_OR register  *******************/
#define TIM11_OR_TI1_RMP_Pos    (0U)
#define TIM11_OR_TI1_RMP_Msk    (0x3UL << TIM11_OR_TI1_RMP_Pos)	/*!< 0x00000003 */
#define TIM11_OR_TI1_RMP        TIM11_OR_TI1_RMP_Msk/*!<TI1_RMP[1:0] bits (TIM11 Input Capture 1 remap) */
#define TIM11_OR_TI1_RMP_0      (0x1UL << TIM11_OR_TI1_RMP_Pos)	/*!< 0x00000001 */
#define TIM11_OR_TI1_RMP_1      (0x2UL << TIM11_OR_TI1_RMP_Pos)	/*!< 0x00000002 */

/******************  Bit definition for TIM_CCMR3 register  *******************/
#define TIM_CCMR3_OC5FE_Pos    (2U)
#define TIM_CCMR3_OC5FE_Msk    (0x1UL << TIM_CCMR3_OC5FE_Pos)	/*!< 0x00000004 */
#define TIM_CCMR3_OC5FE        TIM_CCMR3_OC5FE_Msk				/*!<Output Compare 5 Fast enable */
#define TIM_CCMR3_OC5PE_Pos    (3U)
#define TIM_CCMR3_OC5PE_Msk    (0x1UL << TIM_CCMR3_OC5PE_Pos)	/*!< 0x00000008 */
#define TIM_CCMR3_OC5PE        TIM_CCMR3_OC5PE_Msk				/*!<Output Compare 5 Preload enable */

#define TIM_CCMR3_OC5M_Pos     (4U)
#define TIM_CCMR3_OC5M_Msk     (0x1007UL << TIM_CCMR3_OC5M_Pos)	/*!< 0x00010070 */
#define TIM_CCMR3_OC5M         TIM_CCMR3_OC5M_Msk				/*!<OC5M[2:0] bits (Output Compare 5 Mode) */
#define TIM_CCMR3_OC5M_0       (0x0001UL << TIM_CCMR3_OC5M_Pos)	/*!< 0x00000010 */
#define TIM_CCMR3_OC5M_1       (0x0002UL << TIM_CCMR3_OC5M_Pos)	/*!< 0x00000020 */
#define TIM_CCMR3_OC5M_2       (0x0004UL << TIM_CCMR3_OC5M_Pos)	/*!< 0x00000040 */
#define TIM_CCMR3_OC5M_3       (0x1000UL << TIM_CCMR3_OC5M_Pos)	/*!< 0x00010000 */

#define TIM_CCMR3_OC5CE_Pos    (7U)
#define TIM_CCMR3_OC5CE_Msk    (0x1UL << TIM_CCMR3_OC5CE_Pos)	/*!< 0x00000080 */
#define TIM_CCMR3_OC5CE        TIM_CCMR3_OC5CE_Msk				/*!<Output Compare 5 Clear Enable */

#define TIM_CCMR3_OC6FE_Pos    (10U)
#define TIM_CCMR3_OC6FE_Msk    (0x1UL << TIM_CCMR3_OC6FE_Pos)	/*!< 0x00000400 */
#define TIM_CCMR3_OC6FE        TIM_CCMR3_OC6FE_Msk				/*!<Output Compare 4 Fast enable */
#define TIM_CCMR3_OC6PE_Pos    (11U)
#define TIM_CCMR3_OC6PE_Msk    (0x1UL << TIM_CCMR3_OC6PE_Pos)	/*!< 0x00000800 */
#define TIM_CCMR3_OC6PE        TIM_CCMR3_OC6PE_Msk				/*!<Output Compare 4 Preload enable */

#define TIM_CCMR3_OC6M_Pos     (12U)
#define TIM_CCMR3_OC6M_Msk     (0x1007UL << TIM_CCMR3_OC6M_Pos)	/*!< 0x01007000 */
#define TIM_CCMR3_OC6M         TIM_CCMR3_OC6M_Msk				/*!<OC4M[2:0] bits (Output Compare 4 Mode) */
#define TIM_CCMR3_OC6M_0       (0x0001UL << TIM_CCMR3_OC6M_Pos)	/*!< 0x00001000 */
#define TIM_CCMR3_OC6M_1       (0x0002UL << TIM_CCMR3_OC6M_Pos)	/*!< 0x00002000 */
#define TIM_CCMR3_OC6M_2       (0x0004UL << TIM_CCMR3_OC6M_Pos)	/*!< 0x00004000 */
#define TIM_CCMR3_OC6M_3       (0x1000UL << TIM_CCMR3_OC6M_Pos)	/*!< 0x01000000 */

#define TIM_CCMR3_OC6CE_Pos    (15U)
#define TIM_CCMR3_OC6CE_Msk    (0x1UL << TIM_CCMR3_OC6CE_Pos)	/*!< 0x00008000 */
#define TIM_CCMR3_OC6CE        TIM_CCMR3_OC6CE_Msk				/*!<Output Compare 4 Clear Enable */

/*******************  Bit definition for TIM_CCR5 register  *******************/
#define TIM_CCR5_CCR5_Pos     (0U)
#define TIM_CCR5_CCR5_Msk     (0xFFFFFFFFUL << TIM_CCR5_CCR5_Pos)	/*!< 0xFFFFFFFF */
#define TIM_CCR5_CCR5         TIM_CCR5_CCR5_Msk						/*!<Capture/Compare 5 Value */
#define TIM_CCR5_GC5C1_Pos    (29U)
#define TIM_CCR5_GC5C1_Msk    (0x1UL << TIM_CCR5_GC5C1_Pos)	/*!< 0x20000000 */
#define TIM_CCR5_GC5C1        TIM_CCR5_GC5C1_Msk/*!<Group Channel 5 and Channel 1 */
#define TIM_CCR5_GC5C2_Pos    (30U)
#define TIM_CCR5_GC5C2_Msk    (0x1UL << TIM_CCR5_GC5C2_Pos)	/*!< 0x40000000 */
#define TIM_CCR5_GC5C2        TIM_CCR5_GC5C2_Msk/*!<Group Channel 5 and Channel 2 */
#define TIM_CCR5_GC5C3_Pos    (31U)
#define TIM_CCR5_GC5C3_Msk    (0x1UL << TIM_CCR5_GC5C3_Pos)	/*!< 0x80000000 */
#define TIM_CCR5_GC5C3        TIM_CCR5_GC5C3_Msk/*!<Group Channel 5 and Channel 3 */

/*******************  Bit definition for TIM_CCR6 register  *******************/
#define  TIM_CCR6_CCR6    ((uint16_t) 0xFFFFU)	/*!<Capture/Compare 6 Value */


/******************************************************************************/
/*                                                                            */
/*                         Low Power Timer (LPTIM)                            */
/*                                                                            */
/******************************************************************************/
/******************  Bit definition for LPTIM_ISR register  *******************/
#define LPTIM_ISR_CMPM_Pos       (0U)
#define LPTIM_ISR_CMPM_Msk       (0x1UL << LPTIM_ISR_CMPM_Pos)	/*!< 0x00000001 */
#define LPTIM_ISR_CMPM           LPTIM_ISR_CMPM_Msk				/*!< Compare match                       */
#define LPTIM_ISR_ARRM_Pos       (1U)
#define LPTIM_ISR_ARRM_Msk       (0x1UL << LPTIM_ISR_ARRM_Pos)	/*!< 0x00000002 */
#define LPTIM_ISR_ARRM           LPTIM_ISR_ARRM_Msk				/*!< Autoreload match                    */
#define LPTIM_ISR_EXTTRIG_Pos    (2U)
#define LPTIM_ISR_EXTTRIG_Msk    (0x1UL << LPTIM_ISR_EXTTRIG_Pos)	/*!< 0x00000004 */
#define LPTIM_ISR_EXTTRIG        LPTIM_ISR_EXTTRIG_Msk				/*!< External trigger edge event         */
#define LPTIM_ISR_CMPOK_Pos      (3U)
#define LPTIM_ISR_CMPOK_Msk      (0x1UL << LPTIM_ISR_CMPOK_Pos)	/*!< 0x00000008 */
#define LPTIM_ISR_CMPOK          LPTIM_ISR_CMPOK_Msk/*!< Compare register update OK          */
#define LPTIM_ISR_ARROK_Pos      (4U)
#define LPTIM_ISR_ARROK_Msk      (0x1UL << LPTIM_ISR_ARROK_Pos)	/*!< 0x00000010 */
#define LPTIM_ISR_ARROK          LPTIM_ISR_ARROK_Msk/*!< Autoreload register update OK       */
#define LPTIM_ISR_UP_Pos         (5U)
#define LPTIM_ISR_UP_Msk         (0x1UL << LPTIM_ISR_UP_Pos)/*!< 0x00000020 */
#define LPTIM_ISR_UP             LPTIM_ISR_UP_Msk	/*!< Counter direction change down to up */
#define LPTIM_ISR_DOWN_Pos       (6U)
#define LPTIM_ISR_DOWN_Msk       (0x1UL << LPTIM_ISR_DOWN_Pos)	/*!< 0x00000040 */
#define LPTIM_ISR_DOWN           LPTIM_ISR_DOWN_Msk				/*!< Counter direction change up to down */

/******************  Bit definition for LPTIM_ICR register  *******************/
#define LPTIM_ICR_CMPMCF_Pos       (0U)
#define LPTIM_ICR_CMPMCF_Msk       (0x1UL << LPTIM_ICR_CMPMCF_Pos)	/*!< 0x00000001 */
#define LPTIM_ICR_CMPMCF           LPTIM_ICR_CMPMCF_Msk				/*!< Compare match Clear Flag                       */
#define LPTIM_ICR_ARRMCF_Pos       (1U)
#define LPTIM_ICR_ARRMCF_Msk       (0x1UL << LPTIM_ICR_ARRMCF_Pos)	/*!< 0x00000002 */
#define LPTIM_ICR_ARRMCF           LPTIM_ICR_ARRMCF_Msk				/*!< Autoreload match Clear Flag                    */
#define LPTIM_ICR_EXTTRIGCF_Pos    (2U)
#define LPTIM_ICR_EXTTRIGCF_Msk    (0x1UL << LPTIM_ICR_EXTTRIGCF_Pos)	/*!< 0x00000004 */
#define LPTIM_ICR_EXTTRIGCF        LPTIM_ICR_EXTTRIGCF_Msk				/*!< External trigger edge event Clear Flag         */
#define LPTIM_ICR_CMPOKCF_Pos      (3U)
#define LPTIM_ICR_CMPOKCF_Msk      (0x1UL << LPTIM_ICR_CMPOKCF_Pos)	/*!< 0x00000008 */
#define LPTIM_ICR_CMPOKCF          LPTIM_ICR_CMPOKCF_Msk/*!< Compare register update OK Clear Flag          */
#define LPTIM_ICR_ARROKCF_Pos      (4U)
#define LPTIM_ICR_ARROKCF_Msk      (0x1UL << LPTIM_ICR_ARROKCF_Pos)	/*!< 0x00000010 */
#define LPTIM_ICR_ARROKCF          LPTIM_ICR_ARROKCF_Msk/*!< Autoreload register update OK Clear Flag       */
#define LPTIM_ICR_UPCF_Pos         (5U)
#define LPTIM_ICR_UPCF_Msk         (0x1UL << LPTIM_ICR_UPCF_Pos)/*!< 0x00000020 */
#define LPTIM_ICR_UPCF             LPTIM_ICR_UPCF_Msk	/*!< Counter direction change down to up Clear Flag */
#define LPTIM_ICR_DOWNCF_Pos       (6U)
#define LPTIM_ICR_DOWNCF_Msk       (0x1UL << LPTIM_ICR_DOWNCF_Pos)	/*!< 0x00000040 */
#define LPTIM_ICR_DOWNCF           LPTIM_ICR_DOWNCF_Msk				/*!< Counter direction change up to down Clear Flag */

/******************  Bit definition for LPTIM_IER register *******************/
#define LPTIM_IER_CMPMIE_Pos       (0U)
#define LPTIM_IER_CMPMIE_Msk       (0x1UL << LPTIM_IER_CMPMIE_Pos)	/*!< 0x00000001 */
#define LPTIM_IER_CMPMIE           LPTIM_IER_CMPMIE_Msk				/*!< Compare match Interrupt Enable                       */
#define LPTIM_IER_ARRMIE_Pos       (1U)
#define LPTIM_IER_ARRMIE_Msk       (0x1UL << LPTIM_IER_ARRMIE_Pos)	/*!< 0x00000002 */
#define LPTIM_IER_ARRMIE           LPTIM_IER_ARRMIE_Msk				/*!< Autoreload match Interrupt Enable                    */
#define LPTIM_IER_EXTTRIGIE_Pos    (2U)
#define LPTIM_IER_EXTTRIGIE_Msk    (0x1UL << LPTIM_IER_EXTTRIGIE_Pos)	/*!< 0x00000004 */
#define LPTIM_IER_EXTTRIGIE        LPTIM_IER_EXTTRIGIE_Msk				/*!< External trigger edge event Interrupt Enable         */
#define LPTIM_IER_CMPOKIE_Pos      (3U)
#define LPTIM_IER_CMPOKIE_Msk      (0x1UL << LPTIM_IER_CMPOKIE_Pos)	/*!< 0x00000008 */
#define LPTIM_IER_CMPOKIE          LPTIM_IER_CMPOKIE_Msk/*!< Compare register update OK Interrupt Enable          */
#define LPTIM_IER_ARROKIE_Pos      (4U)
#define LPTIM_IER_ARROKIE_Msk      (0x1UL << LPTIM_IER_ARROKIE_Pos)	/*!< 0x00000010 */
#define LPTIM_IER_ARROKIE          LPTIM_IER_ARROKIE_Msk/*!< Autoreload register update OK Interrupt Enable       */
#define LPTIM_IER_UPIE_Pos         (5U)
#define LPTIM_IER_UPIE_Msk         (0x1UL << LPTIM_IER_UPIE_Pos)/*!< 0x00000020 */
#define LPTIM_IER_UPIE             LPTIM_IER_UPIE_Msk	/*!< Counter direction change down to up Interrupt Enable */
#define LPTIM_IER_DOWNIE_Pos       (6U)
#define LPTIM_IER_DOWNIE_Msk       (0x1UL << LPTIM_IER_DOWNIE_Pos)	/*!< 0x00000040 */
#define LPTIM_IER_DOWNIE           LPTIM_IER_DOWNIE_Msk				/*!< Counter direction change up to down Interrupt Enable */

/******************  Bit definition for LPTIM_CFGR register*******************/
#define LPTIM_CFGR_CKSEL_Pos        (0U)
#define LPTIM_CFGR_CKSEL_Msk        (0x1UL << LPTIM_CFGR_CKSEL_Pos)	/*!< 0x00000001 */
#define LPTIM_CFGR_CKSEL            LPTIM_CFGR_CKSEL_Msk/*!< Clock selector */

#define LPTIM_CFGR_CKPOL_Pos        (1U)
#define LPTIM_CFGR_CKPOL_Msk        (0x3UL << LPTIM_CFGR_CKPOL_Pos)	/*!< 0x00000006 */
#define LPTIM_CFGR_CKPOL            LPTIM_CFGR_CKPOL_Msk/*!< CKPOL[1:0] bits (Clock polarity) */
#define LPTIM_CFGR_CKPOL_0          (0x1UL << LPTIM_CFGR_CKPOL_Pos)	/*!< 0x00000002 */
#define LPTIM_CFGR_CKPOL_1          (0x2UL << LPTIM_CFGR_CKPOL_Pos)	/*!< 0x00000004 */

#define LPTIM_CFGR_CKFLT_Pos        (3U)
#define LPTIM_CFGR_CKFLT_Msk        (0x3UL << LPTIM_CFGR_CKFLT_Pos)	/*!< 0x00000018 */
#define LPTIM_CFGR_CKFLT            LPTIM_CFGR_CKFLT_Msk/*!< CKFLT[1:0] bits (Configurable digital filter for external clock) */
#define LPTIM_CFGR_CKFLT_0          (0x1UL << LPTIM_CFGR_CKFLT_Pos)	/*!< 0x00000008 */
#define LPTIM_CFGR_CKFLT_1          (0x2UL << LPTIM_CFGR_CKFLT_Pos)	/*!< 0x00000010 */

#define LPTIM_CFGR_TRGFLT_Pos       (6U)
#define LPTIM_CFGR_TRGFLT_Msk       (0x3UL << LPTIM_CFGR_TRGFLT_Pos)/*!< 0x000000C0 */
#define LPTIM_CFGR_TRGFLT           LPTIM_CFGR_TRGFLT_Msk	/*!< TRGFLT[1:0] bits (Configurable digital filter for trigger) */
#define LPTIM_CFGR_TRGFLT_0         (0x1UL << LPTIM_CFGR_TRGFLT_Pos)/*!< 0x00000040 */
#define LPTIM_CFGR_TRGFLT_1         (0x2UL << LPTIM_CFGR_TRGFLT_Pos)/*!< 0x00000080 */

#define LPTIM_CFGR_PRESC_Pos        (9U)
#define LPTIM_CFGR_PRESC_Msk        (0x7UL << LPTIM_CFGR_PRESC_Pos)	/*!< 0x00000E00 */
#define LPTIM_CFGR_PRESC            LPTIM_CFGR_PRESC_Msk/*!< PRESC[2:0] bits (Clock prescaler) */
#define LPTIM_CFGR_PRESC_0          (0x1UL << LPTIM_CFGR_PRESC_Pos)	/*!< 0x00000200 */
#define LPTIM_CFGR_PRESC_1          (0x2UL << LPTIM_CFGR_PRESC_Pos)	/*!< 0x00000400 */
#define LPTIM_CFGR_PRESC_2          (0x4UL << LPTIM_CFGR_PRESC_Pos)	/*!< 0x00000800 */

#define LPTIM_CFGR_TRIGSEL_Pos      (13U)
#define LPTIM_CFGR_TRIGSEL_Msk      (0x7UL << LPTIM_CFGR_TRIGSEL_Pos)	/*!< 0x0000E000 */
#define LPTIM_CFGR_TRIGSEL          LPTIM_CFGR_TRIGSEL_Msk				/*!< TRIGSEL[2:0]] bits (Trigger selector) */
#define LPTIM_CFGR_TRIGSEL_0        (0x1UL << LPTIM_CFGR_TRIGSEL_Pos)	/*!< 0x00002000 */
#define LPTIM_CFGR_TRIGSEL_1        (0x2UL << LPTIM_CFGR_TRIGSEL_Pos)	/*!< 0x00004000 */
#define LPTIM_CFGR_TRIGSEL_2        (0x4UL << LPTIM_CFGR_TRIGSEL_Pos)	/*!< 0x00008000 */

#define LPTIM_CFGR_TRIGEN_Pos       (17U)
#define LPTIM_CFGR_TRIGEN_Msk       (0x3UL << LPTIM_CFGR_TRIGEN_Pos)/*!< 0x00060000 */
#define LPTIM_CFGR_TRIGEN           LPTIM_CFGR_TRIGEN_Msk	/*!< TRIGEN[1:0] bits (Trigger enable and polarity) */
#define LPTIM_CFGR_TRIGEN_0         (0x1UL << LPTIM_CFGR_TRIGEN_Pos)/*!< 0x00020000 */
#define LPTIM_CFGR_TRIGEN_1         (0x2UL << LPTIM_CFGR_TRIGEN_Pos)/*!< 0x00040000 */

#define LPTIM_CFGR_TIMOUT_Pos       (19U)
#define LPTIM_CFGR_TIMOUT_Msk       (0x1UL << LPTIM_CFGR_TIMOUT_Pos)/*!< 0x00080000 */
#define LPTIM_CFGR_TIMOUT           LPTIM_CFGR_TIMOUT_Msk	/*!< Timout enable           */
#define LPTIM_CFGR_WAVE_Pos         (20U)
#define LPTIM_CFGR_WAVE_Msk         (0x1UL << LPTIM_CFGR_WAVE_Pos)	/*!< 0x00100000 */
#define LPTIM_CFGR_WAVE             LPTIM_CFGR_WAVE_Msk				/*!< Waveform shape          */
#define LPTIM_CFGR_WAVPOL_Pos       (21U)
#define LPTIM_CFGR_WAVPOL_Msk       (0x1UL << LPTIM_CFGR_WAVPOL_Pos)/*!< 0x00200000 */
#define LPTIM_CFGR_WAVPOL           LPTIM_CFGR_WAVPOL_Msk	/*!< Waveform shape polarity */
#define LPTIM_CFGR_PRELOAD_Pos      (22U)
#define LPTIM_CFGR_PRELOAD_Msk      (0x1UL << LPTIM_CFGR_PRELOAD_Pos)	/*!< 0x00400000 */
#define LPTIM_CFGR_PRELOAD          LPTIM_CFGR_PRELOAD_Msk				/*!< Reg update mode         */
#define LPTIM_CFGR_COUNTMODE_Pos    (23U)
#define LPTIM_CFGR_COUNTMODE_Msk    (0x1UL << LPTIM_CFGR_COUNTMODE_Pos)	/*!< 0x00800000 */
#define LPTIM_CFGR_COUNTMODE        LPTIM_CFGR_COUNTMODE_Msk/*!< Counter mode enable     */
#define LPTIM_CFGR_ENC_Pos          (24U)
#define LPTIM_CFGR_ENC_Msk          (0x1UL << LPTIM_CFGR_ENC_Pos)	/*!< 0x01000000 */
#define LPTIM_CFGR_ENC              LPTIM_CFGR_ENC_Msk				/*!< Encoder mode enable     */

/******************  Bit definition for LPTIM_CR register  ********************/
#define LPTIM_CR_ENABLE_Pos     (0U)
#define LPTIM_CR_ENABLE_Msk     (0x1UL << LPTIM_CR_ENABLE_Pos)	/*!< 0x00000001 */
#define LPTIM_CR_ENABLE         LPTIM_CR_ENABLE_Msk				/*!< LPTIMer enable                 */
#define LPTIM_CR_SNGSTRT_Pos    (1U)
#define LPTIM_CR_SNGSTRT_Msk    (0x1UL << LPTIM_CR_SNGSTRT_Pos)	/*!< 0x00000002 */
#define LPTIM_CR_SNGSTRT        LPTIM_CR_SNGSTRT_Msk/*!< Timer start in single mode     */
#define LPTIM_CR_CNTSTRT_Pos    (2U)
#define LPTIM_CR_CNTSTRT_Msk    (0x1UL << LPTIM_CR_CNTSTRT_Pos)	/*!< 0x00000004 */
#define LPTIM_CR_CNTSTRT        LPTIM_CR_CNTSTRT_Msk/*!< Timer start in continuous mode */

/******************  Bit definition for LPTIM_CMP register *******************/
#define LPTIM_CMP_CMP_Pos    (0U)
#define LPTIM_CMP_CMP_Msk    (0xFFFFUL << LPTIM_CMP_CMP_Pos)/*!< 0x0000FFFF */
#define LPTIM_CMP_CMP        LPTIM_CMP_CMP_Msk	/*!< Compare register     */

/******************  Bit definition for LPTIM_ARR register *******************/
#define LPTIM_ARR_ARR_Pos    (0U)
#define LPTIM_ARR_ARR_Msk    (0xFFFFUL << LPTIM_ARR_ARR_Pos)/*!< 0x0000FFFF */
#define LPTIM_ARR_ARR        LPTIM_ARR_ARR_Msk	/*!< Auto reload register */

/******************  Bit definition for LPTIM_CNT register *******************/
#define LPTIM_CNT_CNT_Pos    (0U)
#define LPTIM_CNT_CNT_Msk    (0xFFFFUL << LPTIM_CNT_CNT_Pos)/*!< 0x0000FFFF */
#define LPTIM_CNT_CNT        LPTIM_CNT_CNT_Msk	/*!< Counter register     */
/******************************************************************************/
/*                                                                            */
/*      Universal Synchronous Asynchronous Receiver Transmitter (USART)       */
/*                                                                            */
/******************************************************************************/

/*
 * @brief Specific device feature definitions (not present on all devices in the STM32F7 serie)
 */
/* Support of TCBGT feature : Supported from USART IP version c7amba_sci3 v1.3 */
#define USART_TCBGT_SUPPORT
/******************  Bit definition for USART_CR1 register  *******************/
#define USART_CR1_UE_Pos        (0U)
#define USART_CR1_UE_Msk        (0x1UL << USART_CR1_UE_Pos)	/*!< 0x00000001 */
#define USART_CR1_UE            USART_CR1_UE_Msk/*!< USART Enable                                    */
#define USART_CR1_RE_Pos        (2U)
#define USART_CR1_RE_Msk        (0x1UL << USART_CR1_RE_Pos)	/*!< 0x00000004 */
#define USART_CR1_RE            USART_CR1_RE_Msk/*!< Receiver Enable                                 */
#define USART_CR1_TE_Pos        (3U)
#define USART_CR1_TE_Msk        (0x1UL << USART_CR1_TE_Pos)	/*!< 0x00000008 */
#define USART_CR1_TE            USART_CR1_TE_Msk/*!< Transmitter Enable                              */
#define USART_CR1_IDLEIE_Pos    (4U)
#define USART_CR1_IDLEIE_Msk    (0x1UL << USART_CR1_IDLEIE_Pos)	/*!< 0x00000010 */
#define USART_CR1_IDLEIE        USART_CR1_IDLEIE_Msk/*!< IDLE Interrupt Enable                           */
#define USART_CR1_RXNEIE_Pos    (5U)
#define USART_CR1_RXNEIE_Msk    (0x1UL << USART_CR1_RXNEIE_Pos)	/*!< 0x00000020 */
#define USART_CR1_RXNEIE        USART_CR1_RXNEIE_Msk/*!< RXNE Interrupt Enable                           */
#define USART_CR1_TCIE_Pos      (6U)
#define USART_CR1_TCIE_Msk      (0x1UL << USART_CR1_TCIE_Pos)	/*!< 0x00000040 */
#define USART_CR1_TCIE          USART_CR1_TCIE_Msk				/*!< Transmission Complete Interrupt Enable          */
#define USART_CR1_TXEIE_Pos     (7U)
#define USART_CR1_TXEIE_Msk     (0x1UL << USART_CR1_TXEIE_Pos)	/*!< 0x00000080 */
#define USART_CR1_TXEIE         USART_CR1_TXEIE_Msk				/*!< TXE Interrupt Enable                            */
#define USART_CR1_PEIE_Pos      (8U)
#define USART_CR1_PEIE_Msk      (0x1UL << USART_CR1_PEIE_Pos)	/*!< 0x00000100 */
#define USART_CR1_PEIE          USART_CR1_PEIE_Msk				/*!< PE Interrupt Enable                             */
#define USART_CR1_PS_Pos        (9U)
#define USART_CR1_PS_Msk        (0x1UL << USART_CR1_PS_Pos)	/*!< 0x00000200 */
#define USART_CR1_PS            USART_CR1_PS_Msk/*!< Parity Selection                                */
#define USART_CR1_PCE_Pos       (10U)
#define USART_CR1_PCE_Msk       (0x1UL << USART_CR1_PCE_Pos)/*!< 0x00000400 */
#define USART_CR1_PCE           USART_CR1_PCE_Msk	/*!< Parity Control Enable                           */
#define USART_CR1_WAKE_Pos      (11U)
#define USART_CR1_WAKE_Msk      (0x1UL << USART_CR1_WAKE_Pos)	/*!< 0x00000800 */
#define USART_CR1_WAKE          USART_CR1_WAKE_Msk				/*!< Receiver Wakeup method                          */
#define USART_CR1_M_Pos         (12U)
#define USART_CR1_M_Msk         (0x10001UL << USART_CR1_M_Pos)	/*!< 0x10001000 */
#define USART_CR1_M             USART_CR1_M_Msk					/*!< Word length                                     */
#define USART_CR1_M0            (0x00001UL << USART_CR1_M_Pos)	/*!< 0x00001000 */
#define USART_CR1_MME_Pos       (13U)
#define USART_CR1_MME_Msk       (0x1UL << USART_CR1_MME_Pos)/*!< 0x00002000 */
#define USART_CR1_MME           USART_CR1_MME_Msk	/*!< Mute Mode Enable                                */
#define USART_CR1_CMIE_Pos      (14U)
#define USART_CR1_CMIE_Msk      (0x1UL << USART_CR1_CMIE_Pos)	/*!< 0x00004000 */
#define USART_CR1_CMIE          USART_CR1_CMIE_Msk				/*!< Character match interrupt enable                */
#define USART_CR1_OVER8_Pos     (15U)
#define USART_CR1_OVER8_Msk     (0x1UL << USART_CR1_OVER8_Pos)	/*!< 0x00008000 */
#define USART_CR1_OVER8         USART_CR1_OVER8_Msk				/*!< Oversampling by 8-bit or 16-bit mode            */
#define USART_CR1_DEDT_Pos      (16U)
#define USART_CR1_DEDT_Msk      (0x1FUL << USART_CR1_DEDT_Pos)	/*!< 0x001F0000 */
#define USART_CR1_DEDT          USART_CR1_DEDT_Msk				/*!< DEDT[4:0] bits (Driver Enable Deassertion Time) */
#define USART_CR1_DEDT_0        (0x01UL << USART_CR1_DEDT_Pos)	/*!< 0x00010000 */
#define USART_CR1_DEDT_1        (0x02UL << USART_CR1_DEDT_Pos)	/*!< 0x00020000 */
#define USART_CR1_DEDT_2        (0x04UL << USART_CR1_DEDT_Pos)	/*!< 0x00040000 */
#define USART_CR1_DEDT_3        (0x08UL << USART_CR1_DEDT_Pos)	/*!< 0x00080000 */
#define USART_CR1_DEDT_4        (0x10UL << USART_CR1_DEDT_Pos)	/*!< 0x00100000 */
#define USART_CR1_DEAT_Pos      (21U)
#define USART_CR1_DEAT_Msk      (0x1FUL << USART_CR1_DEAT_Pos)	/*!< 0x03E00000 */
#define USART_CR1_DEAT          USART_CR1_DEAT_Msk				/*!< DEAT[4:0] bits (Driver Enable Assertion Time)   */
#define USART_CR1_DEAT_0        (0x01UL << USART_CR1_DEAT_Pos)	/*!< 0x00200000 */
#define USART_CR1_DEAT_1        (0x02UL << USART_CR1_DEAT_Pos)	/*!< 0x00400000 */
#define USART_CR1_DEAT_2        (0x04UL << USART_CR1_DEAT_Pos)	/*!< 0x00800000 */
#define USART_CR1_DEAT_3        (0x08UL << USART_CR1_DEAT_Pos)	/*!< 0x01000000 */
#define USART_CR1_DEAT_4        (0x10UL << USART_CR1_DEAT_Pos)	/*!< 0x02000000 */
#define USART_CR1_RTOIE_Pos     (26U)
#define USART_CR1_RTOIE_Msk     (0x1UL << USART_CR1_RTOIE_Pos)	/*!< 0x04000000 */
#define USART_CR1_RTOIE         USART_CR1_RTOIE_Msk				/*!< Receive Time Out interrupt enable */
#define USART_CR1_EOBIE_Pos     (27U)
#define USART_CR1_EOBIE_Msk     (0x1UL << USART_CR1_EOBIE_Pos)	/*!< 0x08000000 */
#define USART_CR1_EOBIE         USART_CR1_EOBIE_Msk				/*!< End of Block interrupt enable     */
#define USART_CR1_M1            0x10000000U						/*!< Word length - Bit 1               */

/* Legacy defines */
#define  USART_CR1_M_0    USART_CR1_M0	/*!< Word length - Bit 0               */
#define  USART_CR1_M_1    USART_CR1_M1	/*!< Word length - Bit 1               */

/******************  Bit definition for USART_CR2 register  *******************/
#define USART_CR2_ADDM7_Pos       (4U)
#define USART_CR2_ADDM7_Msk       (0x1UL << USART_CR2_ADDM7_Pos)/*!< 0x00000010 */
#define USART_CR2_ADDM7           USART_CR2_ADDM7_Msk	/*!< 7-bit or 4-bit Address Detection       */
#define USART_CR2_LBDL_Pos        (5U)
#define USART_CR2_LBDL_Msk        (0x1UL << USART_CR2_LBDL_Pos)	/*!< 0x00000020 */
#define USART_CR2_LBDL            USART_CR2_LBDL_Msk/*!< LIN Break Detection Length             */
#define USART_CR2_LBDIE_Pos       (6U)
#define USART_CR2_LBDIE_Msk       (0x1UL << USART_CR2_LBDIE_Pos)/*!< 0x00000040 */
#define USART_CR2_LBDIE           USART_CR2_LBDIE_Msk	/*!< LIN Break Detection Interrupt Enable   */
#define USART_CR2_LBCL_Pos        (8U)
#define USART_CR2_LBCL_Msk        (0x1UL << USART_CR2_LBCL_Pos)	/*!< 0x00000100 */
#define USART_CR2_LBCL            USART_CR2_LBCL_Msk/*!< Last Bit Clock pulse                   */
#define USART_CR2_CPHA_Pos        (9U)
#define USART_CR2_CPHA_Msk        (0x1UL << USART_CR2_CPHA_Pos)	/*!< 0x00000200 */
#define USART_CR2_CPHA            USART_CR2_CPHA_Msk/*!< Clock Phase                            */
#define USART_CR2_CPOL_Pos        (10U)
#define USART_CR2_CPOL_Msk        (0x1UL << USART_CR2_CPOL_Pos)	/*!< 0x00000400 */
#define USART_CR2_CPOL            USART_CR2_CPOL_Msk/*!< Clock Polarity                         */
#define USART_CR2_CLKEN_Pos       (11U)
#define USART_CR2_CLKEN_Msk       (0x1UL << USART_CR2_CLKEN_Pos)/*!< 0x00000800 */
#define USART_CR2_CLKEN           USART_CR2_CLKEN_Msk	/*!< Clock Enable                           */
#define USART_CR2_STOP_Pos        (12U)
#define USART_CR2_STOP_Msk        (0x3UL << USART_CR2_STOP_Pos)	/*!< 0x00003000 */
#define USART_CR2_STOP            USART_CR2_STOP_Msk/*!< STOP[1:0] bits (STOP bits)             */
#define USART_CR2_STOP_0          (0x1UL << USART_CR2_STOP_Pos)	/*!< 0x00001000 */
#define USART_CR2_STOP_1          (0x2UL << USART_CR2_STOP_Pos)	/*!< 0x00002000 */
#define USART_CR2_LINEN_Pos       (14U)
#define USART_CR2_LINEN_Msk       (0x1UL << USART_CR2_LINEN_Pos)/*!< 0x00004000 */
#define USART_CR2_LINEN           USART_CR2_LINEN_Msk	/*!< LIN mode enable                        */
#define USART_CR2_SWAP_Pos        (15U)
#define USART_CR2_SWAP_Msk        (0x1UL << USART_CR2_SWAP_Pos)	/*!< 0x00008000 */
#define USART_CR2_SWAP            USART_CR2_SWAP_Msk/*!< SWAP TX/RX pins                        */
#define USART_CR2_RXINV_Pos       (16U)
#define USART_CR2_RXINV_Msk       (0x1UL << USART_CR2_RXINV_Pos)/*!< 0x00010000 */
#define USART_CR2_RXINV           USART_CR2_RXINV_Msk	/*!< RX pin active level inversion          */
#define USART_CR2_TXINV_Pos       (17U)
#define USART_CR2_TXINV_Msk       (0x1UL << USART_CR2_TXINV_Pos)/*!< 0x00020000 */
#define USART_CR2_TXINV           USART_CR2_TXINV_Msk	/*!< TX pin active level inversion          */
#define USART_CR2_DATAINV_Pos     (18U)
#define USART_CR2_DATAINV_Msk     (0x1UL << USART_CR2_DATAINV_Pos)	/*!< 0x00040000 */
#define USART_CR2_DATAINV         USART_CR2_DATAINV_Msk				/*!< Binary data inversion                  */
#define USART_CR2_MSBFIRST_Pos    (19U)
#define USART_CR2_MSBFIRST_Msk    (0x1UL << USART_CR2_MSBFIRST_Pos)	/*!< 0x00080000 */
#define USART_CR2_MSBFIRST        USART_CR2_MSBFIRST_Msk/*!< Most Significant Bit First             */
#define USART_CR2_ABREN_Pos       (20U)
#define USART_CR2_ABREN_Msk       (0x1UL << USART_CR2_ABREN_Pos)/*!< 0x00100000 */
#define USART_CR2_ABREN           USART_CR2_ABREN_Msk	/*!< Auto Baud-Rate Enable                  */
#define USART_CR2_ABRMODE_Pos     (21U)
#define USART_CR2_ABRMODE_Msk     (0x3UL << USART_CR2_ABRMODE_Pos)	/*!< 0x00600000 */
#define USART_CR2_ABRMODE         USART_CR2_ABRMODE_Msk				/*!< ABRMOD[1:0] bits (Auto Baud-Rate Mode) */
#define USART_CR2_ABRMODE_0       (0x1UL << USART_CR2_ABRMODE_Pos)	/*!< 0x00200000 */
#define USART_CR2_ABRMODE_1       (0x2UL << USART_CR2_ABRMODE_Pos)	/*!< 0x00400000 */
#define USART_CR2_RTOEN_Pos       (23U)
#define USART_CR2_RTOEN_Msk       (0x1UL << USART_CR2_RTOEN_Pos)/*!< 0x00800000 */
#define USART_CR2_RTOEN           USART_CR2_RTOEN_Msk	/*!< Receiver Time-Out enable  */
#define USART_CR2_ADD_Pos         (24U)
#define USART_CR2_ADD_Msk         (0xFFUL << USART_CR2_ADD_Pos)	/*!< 0xFF000000 */
#define USART_CR2_ADD             USART_CR2_ADD_Msk				/*!< Address of the USART node */

/******************  Bit definition for USART_CR3 register  *******************/
#define USART_CR3_EIE_Pos        (0U)
#define USART_CR3_EIE_Msk        (0x1UL << USART_CR3_EIE_Pos)	/*!< 0x00000001 */
#define USART_CR3_EIE            USART_CR3_EIE_Msk				/*!< Error Interrupt Enable                         */
#define USART_CR3_IREN_Pos       (1U)
#define USART_CR3_IREN_Msk       (0x1UL << USART_CR3_IREN_Pos)	/*!< 0x00000002 */
#define USART_CR3_IREN           USART_CR3_IREN_Msk				/*!< IrDA mode Enable                               */
#define USART_CR3_IRLP_Pos       (2U)
#define USART_CR3_IRLP_Msk       (0x1UL << USART_CR3_IRLP_Pos)	/*!< 0x00000004 */
#define USART_CR3_IRLP           USART_CR3_IRLP_Msk				/*!< IrDA Low-Power                                 */
#define USART_CR3_HDSEL_Pos      (3U)
#define USART_CR3_HDSEL_Msk      (0x1UL << USART_CR3_HDSEL_Pos)	/*!< 0x00000008 */
#define USART_CR3_HDSEL          USART_CR3_HDSEL_Msk/*!< Half-Duplex Selection                          */
#define USART_CR3_NACK_Pos       (4U)
#define USART_CR3_NACK_Msk       (0x1UL << USART_CR3_NACK_Pos)	/*!< 0x00000010 */
#define USART_CR3_NACK           USART_CR3_NACK_Msk				/*!< SmartCard NACK enable                          */
#define USART_CR3_SCEN_Pos       (5U)
#define USART_CR3_SCEN_Msk       (0x1UL << USART_CR3_SCEN_Pos)	/*!< 0x00000020 */
#define USART_CR3_SCEN           USART_CR3_SCEN_Msk				/*!< SmartCard mode enable                          */
#define USART_CR3_DMAR_Pos       (6U)
#define USART_CR3_DMAR_Msk       (0x1UL << USART_CR3_DMAR_Pos)	/*!< 0x00000040 */
#define USART_CR3_DMAR           USART_CR3_DMAR_Msk				/*!< DMA Enable Receiver                            */
#define USART_CR3_DMAT_Pos       (7U)
#define USART_CR3_DMAT_Msk       (0x1UL << USART_CR3_DMAT_Pos)	/*!< 0x00000080 */
#define USART_CR3_DMAT           USART_CR3_DMAT_Msk				/*!< DMA Enable Transmitter                         */
#define USART_CR3_RTSE_Pos       (8U)
#define USART_CR3_RTSE_Msk       (0x1UL << USART_CR3_RTSE_Pos)	/*!< 0x00000100 */
#define USART_CR3_RTSE           USART_CR3_RTSE_Msk				/*!< RTS Enable                                     */
#define USART_CR3_CTSE_Pos       (9U)
#define USART_CR3_CTSE_Msk       (0x1UL << USART_CR3_CTSE_Pos)	/*!< 0x00000200 */
#define USART_CR3_CTSE           USART_CR3_CTSE_Msk				/*!< CTS Enable                                     */
#define USART_CR3_CTSIE_Pos      (10U)
#define USART_CR3_CTSIE_Msk      (0x1UL << USART_CR3_CTSIE_Pos)	/*!< 0x00000400 */
#define USART_CR3_CTSIE          USART_CR3_CTSIE_Msk/*!< CTS Interrupt Enable                           */
#define USART_CR3_ONEBIT_Pos     (11U)
#define USART_CR3_ONEBIT_Msk     (0x1UL << USART_CR3_ONEBIT_Pos)/*!< 0x00000800 */
#define USART_CR3_ONEBIT         USART_CR3_ONEBIT_Msk	/*!< One sample bit method enable                   */
#define USART_CR3_OVRDIS_Pos     (12U)
#define USART_CR3_OVRDIS_Msk     (0x1UL << USART_CR3_OVRDIS_Pos)/*!< 0x00001000 */
#define USART_CR3_OVRDIS         USART_CR3_OVRDIS_Msk	/*!< Overrun Disable                                */
#define USART_CR3_DDRE_Pos       (13U)
#define USART_CR3_DDRE_Msk       (0x1UL << USART_CR3_DDRE_Pos)	/*!< 0x00002000 */
#define USART_CR3_DDRE           USART_CR3_DDRE_Msk				/*!< DMA Disable on Reception Error                 */
#define USART_CR3_DEM_Pos        (14U)
#define USART_CR3_DEM_Msk        (0x1UL << USART_CR3_DEM_Pos)	/*!< 0x00004000 */
#define USART_CR3_DEM            USART_CR3_DEM_Msk				/*!< Driver Enable Mode                             */
#define USART_CR3_DEP_Pos        (15U)
#define USART_CR3_DEP_Msk        (0x1UL << USART_CR3_DEP_Pos)	/*!< 0x00008000 */
#define USART_CR3_DEP            USART_CR3_DEP_Msk				/*!< Driver Enable Polarity Selection               */
#define USART_CR3_SCARCNT_Pos    (17U)
#define USART_CR3_SCARCNT_Msk    (0x7UL << USART_CR3_SCARCNT_Pos)	/*!< 0x000E0000 */
#define USART_CR3_SCARCNT        USART_CR3_SCARCNT_Msk				/*!< SCARCNT[2:0] bits (SmartCard Auto-Retry Count) */
#define USART_CR3_SCARCNT_0      (0x1UL << USART_CR3_SCARCNT_Pos)	/*!< 0x00020000 */
#define USART_CR3_SCARCNT_1      (0x2UL << USART_CR3_SCARCNT_Pos)	/*!< 0x00040000 */
#define USART_CR3_SCARCNT_2      (0x4UL << USART_CR3_SCARCNT_Pos)	/*!< 0x00080000 */
#define USART_CR3_TCBGTIE_Pos    (24U)
#define USART_CR3_TCBGTIE_Msk    (0x1UL << USART_CR3_TCBGTIE_Pos)	/*!< 0x01000000 */
#define USART_CR3_TCBGTIE        USART_CR3_TCBGTIE_Msk				/*!< Transmission complete before guard time interrupt enable */

/******************  Bit definition for USART_BRR register  *******************/
#define USART_BRR_DIV_FRACTION_Pos    (0U)
#define USART_BRR_DIV_FRACTION_Msk    (0xFUL << USART_BRR_DIV_FRACTION_Pos)	/*!< 0x0000000F */
#define USART_BRR_DIV_FRACTION        USART_BRR_DIV_FRACTION_Msk/*!< Fraction of USARTDIV */
#define USART_BRR_DIV_MANTISSA_Pos    (4U)
#define USART_BRR_DIV_MANTISSA_Msk    (0xFFFUL << USART_BRR_DIV_MANTISSA_Pos)	/*!< 0x0000FFF0 */
#define USART_BRR_DIV_MANTISSA        USART_BRR_DIV_MANTISSA_Msk				/*!< Mantissa of USARTDIV */

/******************  Bit definition for USART_GTPR register  ******************/
#define USART_GTPR_PSC_Pos    (0U)
#define USART_GTPR_PSC_Msk    (0xFFUL << USART_GTPR_PSC_Pos)/*!< 0x000000FF */
#define USART_GTPR_PSC        USART_GTPR_PSC_Msk/*!< PSC[7:0] bits (Prescaler value) */
#define USART_GTPR_GT_Pos     (8U)
#define USART_GTPR_GT_Msk     (0xFFUL << USART_GTPR_GT_Pos)	/*!< 0x0000FF00 */
#define USART_GTPR_GT         USART_GTPR_GT_Msk				/*!< GT[7:0] bits (Guard time value) */


/*******************  Bit definition for USART_RTOR register  *****************/
#define USART_RTOR_RTO_Pos     (0U)
#define USART_RTOR_RTO_Msk     (0xFFFFFFUL << USART_RTOR_RTO_Pos)	/*!< 0x00FFFFFF */
#define USART_RTOR_RTO         USART_RTOR_RTO_Msk					/*!< Receiver Time Out Value */
#define USART_RTOR_BLEN_Pos    (24U)
#define USART_RTOR_BLEN_Msk    (0xFFUL << USART_RTOR_BLEN_Pos)	/*!< 0xFF000000 */
#define USART_RTOR_BLEN        USART_RTOR_BLEN_Msk				/*!< Block Length */

/*******************  Bit definition for USART_RQR register  ******************/
#define USART_RQR_ABRRQ_Pos    (0U)
#define USART_RQR_ABRRQ_Msk    (0x1UL << USART_RQR_ABRRQ_Pos)	/*!< 0x00000001 */
#define USART_RQR_ABRRQ        USART_RQR_ABRRQ_Msk				/*!< Auto-Baud Rate Request      */
#define USART_RQR_SBKRQ_Pos    (1U)
#define USART_RQR_SBKRQ_Msk    (0x1UL << USART_RQR_SBKRQ_Pos)	/*!< 0x00000002 */
#define USART_RQR_SBKRQ        USART_RQR_SBKRQ_Msk				/*!< Send Break Request          */
#define USART_RQR_MMRQ_Pos     (2U)
#define USART_RQR_MMRQ_Msk     (0x1UL << USART_RQR_MMRQ_Pos)/*!< 0x00000004 */
#define USART_RQR_MMRQ         USART_RQR_MMRQ_Msk	/*!< Mute Mode Request           */
#define USART_RQR_RXFRQ_Pos    (3U)
#define USART_RQR_RXFRQ_Msk    (0x1UL << USART_RQR_RXFRQ_Pos)	/*!< 0x00000008 */
#define USART_RQR_RXFRQ        USART_RQR_RXFRQ_Msk				/*!< Receive Data flush Request  */
#define USART_RQR_TXFRQ_Pos    (4U)
#define USART_RQR_TXFRQ_Msk    (0x1UL << USART_RQR_TXFRQ_Pos)	/*!< 0x00000010 */
#define USART_RQR_TXFRQ        USART_RQR_TXFRQ_Msk				/*!< Transmit data flush Request */

/*******************  Bit definition for USART_ISR register  ******************/
#define USART_ISR_PE_Pos       (0U)
#define USART_ISR_PE_Msk       (0x1UL << USART_ISR_PE_Pos)	/*!< 0x00000001 */
#define USART_ISR_PE           USART_ISR_PE_Msk				/*!< Parity Error                        */
#define USART_ISR_FE_Pos       (1U)
#define USART_ISR_FE_Msk       (0x1UL << USART_ISR_FE_Pos)	/*!< 0x00000002 */
#define USART_ISR_FE           USART_ISR_FE_Msk				/*!< Framing Error                       */
#define USART_ISR_NE_Pos       (2U)
#define USART_ISR_NE_Msk       (0x1UL << USART_ISR_NE_Pos)	/*!< 0x00000004 */
#define USART_ISR_NE           USART_ISR_NE_Msk				/*!< Noise detected Flag                 */
#define USART_ISR_ORE_Pos      (3U)
#define USART_ISR_ORE_Msk      (0x1UL << USART_ISR_ORE_Pos)	/*!< 0x00000008 */
#define USART_ISR_ORE          USART_ISR_ORE_Msk/*!< OverRun Error                       */
#define USART_ISR_IDLE_Pos     (4U)
#define USART_ISR_IDLE_Msk     (0x1UL << USART_ISR_IDLE_Pos)/*!< 0x00000010 */
#define USART_ISR_IDLE         USART_ISR_IDLE_Msk	/*!< IDLE line detected                  */
#define USART_ISR_RXNE_Pos     (5U)
#define USART_ISR_RXNE_Msk     (0x1UL << USART_ISR_RXNE_Pos)/*!< 0x00000020 */
#define USART_ISR_RXNE         USART_ISR_RXNE_Msk	/*!< Read Data Register Not Empty        */
#define USART_ISR_TC_Pos       (6U)
#define USART_ISR_TC_Msk       (0x1UL << USART_ISR_TC_Pos)	/*!< 0x00000040 */
#define USART_ISR_TC           USART_ISR_TC_Msk				/*!< Transmission Complete               */
#define USART_ISR_TXE_Pos      (7U)
#define USART_ISR_TXE_Msk      (0x1UL << USART_ISR_TXE_Pos)	/*!< 0x00000080 */
#define USART_ISR_TXE          USART_ISR_TXE_Msk/*!< Transmit Data Register Empty        */
#define USART_ISR_LBDF_Pos     (8U)
#define USART_ISR_LBDF_Msk     (0x1UL << USART_ISR_LBDF_Pos)/*!< 0x00000100 */
#define USART_ISR_LBDF         USART_ISR_LBDF_Msk	/*!< LIN Break Detection Flag            */
#define USART_ISR_CTSIF_Pos    (9U)
#define USART_ISR_CTSIF_Msk    (0x1UL << USART_ISR_CTSIF_Pos)	/*!< 0x00000200 */
#define USART_ISR_CTSIF        USART_ISR_CTSIF_Msk				/*!< CTS interrupt flag                  */
#define USART_ISR_CTS_Pos      (10U)
#define USART_ISR_CTS_Msk      (0x1UL << USART_ISR_CTS_Pos)	/*!< 0x00000400 */
#define USART_ISR_CTS          USART_ISR_CTS_Msk/*!< CTS flag                            */
#define USART_ISR_RTOF_Pos     (11U)
#define USART_ISR_RTOF_Msk     (0x1UL << USART_ISR_RTOF_Pos)/*!< 0x00000800 */
#define USART_ISR_RTOF         USART_ISR_RTOF_Msk	/*!< Receiver Time Out                   */
#define USART_ISR_EOBF_Pos     (12U)
#define USART_ISR_EOBF_Msk     (0x1UL << USART_ISR_EOBF_Pos)/*!< 0x00001000 */
#define USART_ISR_EOBF         USART_ISR_EOBF_Msk	/*!< End Of Block Flag                   */
#define USART_ISR_ABRE_Pos     (14U)
#define USART_ISR_ABRE_Msk     (0x1UL << USART_ISR_ABRE_Pos)/*!< 0x00004000 */
#define USART_ISR_ABRE         USART_ISR_ABRE_Msk	/*!< Auto-Baud Rate Error                */
#define USART_ISR_ABRF_Pos     (15U)
#define USART_ISR_ABRF_Msk     (0x1UL << USART_ISR_ABRF_Pos)/*!< 0x00008000 */
#define USART_ISR_ABRF         USART_ISR_ABRF_Msk	/*!< Auto-Baud Rate Flag                 */
#define USART_ISR_BUSY_Pos     (16U)
#define USART_ISR_BUSY_Msk     (0x1UL << USART_ISR_BUSY_Pos)/*!< 0x00010000 */
#define USART_ISR_BUSY         USART_ISR_BUSY_Msk	/*!< Busy Flag                           */
#define USART_ISR_CMF_Pos      (17U)
#define USART_ISR_CMF_Msk      (0x1UL << USART_ISR_CMF_Pos)	/*!< 0x00020000 */
#define USART_ISR_CMF          USART_ISR_CMF_Msk/*!< Character Match Flag                */
#define USART_ISR_SBKF_Pos     (18U)
#define USART_ISR_SBKF_Msk     (0x1UL << USART_ISR_SBKF_Pos)/*!< 0x00040000 */
#define USART_ISR_SBKF         USART_ISR_SBKF_Msk	/*!< Send Break Flag                     */
#define USART_ISR_RWU_Pos      (19U)
#define USART_ISR_RWU_Msk      (0x1UL << USART_ISR_RWU_Pos)	/*!< 0x00080000 */
#define USART_ISR_RWU          USART_ISR_RWU_Msk/*!< Receive Wake Up from mute mode Flag */
#define USART_ISR_TEACK_Pos    (21U)
#define USART_ISR_TEACK_Msk    (0x1UL << USART_ISR_TEACK_Pos)	/*!< 0x00200000 */
#define USART_ISR_TEACK        USART_ISR_TEACK_Msk				/*!< Transmit Enable Acknowledge Flag    */
#define USART_ISR_TCBGT_Pos    (25U)
#define USART_ISR_TCBGT_Msk    (0x1UL << USART_ISR_TCBGT_Pos)	/*!< 0x02000000 */
#define USART_ISR_TCBGT        USART_ISR_TCBGT_Msk				/*!< Transmission complete before guard time flag */

/*******************  Bit definition for USART_ICR register  ******************/
#define USART_ICR_PECF_Pos       (0U)
#define USART_ICR_PECF_Msk       (0x1UL << USART_ICR_PECF_Pos)	/*!< 0x00000001 */
#define USART_ICR_PECF           USART_ICR_PECF_Msk				/*!< Parity Error Clear Flag             */
#define USART_ICR_FECF_Pos       (1U)
#define USART_ICR_FECF_Msk       (0x1UL << USART_ICR_FECF_Pos)	/*!< 0x00000002 */
#define USART_ICR_FECF           USART_ICR_FECF_Msk				/*!< Framing Error Clear Flag            */
#define USART_ICR_NCF_Pos        (2U)
#define USART_ICR_NCF_Msk        (0x1UL << USART_ICR_NCF_Pos)	/*!< 0x00000004 */
#define USART_ICR_NCF            USART_ICR_NCF_Msk				/*!< Noise detected Clear Flag           */
#define USART_ICR_ORECF_Pos      (3U)
#define USART_ICR_ORECF_Msk      (0x1UL << USART_ICR_ORECF_Pos)	/*!< 0x00000008 */
#define USART_ICR_ORECF          USART_ICR_ORECF_Msk/*!< OverRun Error Clear Flag            */
#define USART_ICR_IDLECF_Pos     (4U)
#define USART_ICR_IDLECF_Msk     (0x1UL << USART_ICR_IDLECF_Pos)/*!< 0x00000010 */
#define USART_ICR_IDLECF         USART_ICR_IDLECF_Msk	/*!< IDLE line detected Clear Flag       */
#define USART_ICR_TCCF_Pos       (6U)
#define USART_ICR_TCCF_Msk       (0x1UL << USART_ICR_TCCF_Pos)	/*!< 0x00000040 */
#define USART_ICR_TCCF           USART_ICR_TCCF_Msk				/*!< Transmission Complete Clear Flag    */
#define USART_ICR_TCBGTCF_Pos    (7U)
#define USART_ICR_TCBGTCF_Msk    (0x1UL << USART_ICR_TCBGTCF_Pos)	/*!< 0x00000080 */
#define USART_ICR_TCBGTCF        USART_ICR_TCBGTCF_Msk				/*!< Transmission complete before guard time clear flag */
#define USART_ICR_LBDCF_Pos      (8U)
#define USART_ICR_LBDCF_Msk      (0x1UL << USART_ICR_LBDCF_Pos)	/*!< 0x00000100 */
#define USART_ICR_LBDCF          USART_ICR_LBDCF_Msk/*!< LIN Break Detection Clear Flag      */
#define USART_ICR_CTSCF_Pos      (9U)
#define USART_ICR_CTSCF_Msk      (0x1UL << USART_ICR_CTSCF_Pos)	/*!< 0x00000200 */
#define USART_ICR_CTSCF          USART_ICR_CTSCF_Msk/*!< CTS Interrupt Clear Flag            */
#define USART_ICR_RTOCF_Pos      (11U)
#define USART_ICR_RTOCF_Msk      (0x1UL << USART_ICR_RTOCF_Pos)	/*!< 0x00000800 */
#define USART_ICR_RTOCF          USART_ICR_RTOCF_Msk/*!< Receiver Time Out Clear Flag        */
#define USART_ICR_EOBCF_Pos      (12U)
#define USART_ICR_EOBCF_Msk      (0x1UL << USART_ICR_EOBCF_Pos)	/*!< 0x00001000 */
#define USART_ICR_EOBCF          USART_ICR_EOBCF_Msk/*!< End Of Block Clear Flag             */
#define USART_ICR_CMCF_Pos       (17U)
#define USART_ICR_CMCF_Msk       (0x1UL << USART_ICR_CMCF_Pos)	/*!< 0x00020000 */
#define USART_ICR_CMCF           USART_ICR_CMCF_Msk				/*!< Character Match Clear Flag          */

/*******************  Bit definition for USART_RDR register  ******************/
#define USART_RDR_RDR_Pos    (0U)
#define USART_RDR_RDR_Msk    (0x1FFUL << USART_RDR_RDR_Pos)	/*!< 0x000001FF */
#define USART_RDR_RDR        USART_RDR_RDR_Msk				/*!< RDR[8:0] bits (Receive Data value) */

/*******************  Bit definition for USART_TDR register  ******************/
#define USART_TDR_TDR_Pos    (0U)
#define USART_TDR_TDR_Msk    (0x1FFUL << USART_TDR_TDR_Pos)	/*!< 0x000001FF */
#define USART_TDR_TDR        USART_TDR_TDR_Msk				/*!< TDR[8:0] bits (Transmit Data value) */

/******************************************************************************/
/*                                                                            */
/*                            Window WATCHDOG                                 */
/*                                                                            */
/******************************************************************************/
/*******************  Bit definition for WWDG_CR register  ********************/
#define WWDG_CR_T_Pos    (0U)
#define WWDG_CR_T_Msk    (0x7FUL << WWDG_CR_T_Pos)	/*!< 0x0000007F */
#define WWDG_CR_T        WWDG_CR_T_Msk				/*!<T[6:0] bits (7-Bit counter (MSB to LSB)) */
#define WWDG_CR_T_0      (0x01UL << WWDG_CR_T_Pos)	/*!< 0x01 */
#define WWDG_CR_T_1      (0x02UL << WWDG_CR_T_Pos)	/*!< 0x02 */
#define WWDG_CR_T_2      (0x04UL << WWDG_CR_T_Pos)	/*!< 0x04 */
#define WWDG_CR_T_3      (0x08UL << WWDG_CR_T_Pos)	/*!< 0x08 */
#define WWDG_CR_T_4      (0x10UL << WWDG_CR_T_Pos)	/*!< 0x10 */
#define WWDG_CR_T_5      (0x20UL << WWDG_CR_T_Pos)	/*!< 0x20 */
#define WWDG_CR_T_6      (0x40UL << WWDG_CR_T_Pos)	/*!< 0x40 */


#define WWDG_CR_WDGA_Pos    (7U)
#define WWDG_CR_WDGA_Msk    (0x1UL << WWDG_CR_WDGA_Pos)	/*!< 0x00000080 */
#define WWDG_CR_WDGA        WWDG_CR_WDGA_Msk/*!<Activation bit */

/*******************  Bit definition for WWDG_CFR register  *******************/
#define WWDG_CFR_W_Pos    (0U)
#define WWDG_CFR_W_Msk    (0x7FUL << WWDG_CFR_W_Pos)/*!< 0x0000007F */
#define WWDG_CFR_W        WWDG_CFR_W_Msk/*!<W[6:0] bits (7-bit window value) */
#define WWDG_CFR_W_0      (0x01UL << WWDG_CFR_W_Pos)/*!< 0x0001 */
#define WWDG_CFR_W_1      (0x02UL << WWDG_CFR_W_Pos)/*!< 0x0002 */
#define WWDG_CFR_W_2      (0x04UL << WWDG_CFR_W_Pos)/*!< 0x0004 */
#define WWDG_CFR_W_3      (0x08UL << WWDG_CFR_W_Pos)/*!< 0x0008 */
#define WWDG_CFR_W_4      (0x10UL << WWDG_CFR_W_Pos)/*!< 0x0010 */
#define WWDG_CFR_W_5      (0x20UL << WWDG_CFR_W_Pos)/*!< 0x0020 */
#define WWDG_CFR_W_6      (0x40UL << WWDG_CFR_W_Pos)/*!< 0x0040 */


#define WWDG_CFR_WDGTB_Pos    (7U)
#define WWDG_CFR_WDGTB_Msk    (0x3UL << WWDG_CFR_WDGTB_Pos)	/*!< 0x00000180 */
#define WWDG_CFR_WDGTB        WWDG_CFR_WDGTB_Msk/*!<WDGTB[1:0] bits (Timer Base) */
#define WWDG_CFR_WDGTB_0      (0x1UL << WWDG_CFR_WDGTB_Pos)	/*!< 0x0080 */
#define WWDG_CFR_WDGTB_1      (0x2UL << WWDG_CFR_WDGTB_Pos)	/*!< 0x0100 */


#define WWDG_CFR_EWI_Pos    (9U)
#define WWDG_CFR_EWI_Msk    (0x1UL << WWDG_CFR_EWI_Pos)	/*!< 0x00000200 */
#define WWDG_CFR_EWI        WWDG_CFR_EWI_Msk/*!<Early Wakeup Interrupt */

/*******************  Bit definition for WWDG_SR register  ********************/
#define WWDG_SR_EWIF_Pos    (0U)
#define WWDG_SR_EWIF_Msk    (0x1UL << WWDG_SR_EWIF_Pos)	/*!< 0x00000001 */
#define WWDG_SR_EWIF        WWDG_SR_EWIF_Msk/*!<Early Wakeup Interrupt Flag */

/******************************************************************************/
/*                                                                            */
/*                                DBG                                         */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for DBGMCU_IDCODE register  *************/
#define DBGMCU_IDCODE_DEV_ID_Pos    (0U)
#define DBGMCU_IDCODE_DEV_ID_Msk    (0xFFFUL << DBGMCU_IDCODE_DEV_ID_Pos)	/*!< 0x00000FFF */
#define DBGMCU_IDCODE_DEV_ID        DBGMCU_IDCODE_DEV_ID_Msk
#define DBGMCU_IDCODE_REV_ID_Pos    (16U)
#define DBGMCU_IDCODE_REV_ID_Msk    (0xFFFFUL << DBGMCU_IDCODE_REV_ID_Pos)	/*!< 0xFFFF0000 */
#define DBGMCU_IDCODE_REV_ID        DBGMCU_IDCODE_REV_ID_Msk

/********************  Bit definition for DBGMCU_CR register  *****************/
#define DBGMCU_CR_DBG_SLEEP_Pos      (0U)
#define DBGMCU_CR_DBG_SLEEP_Msk      (0x1UL << DBGMCU_CR_DBG_SLEEP_Pos)	/*!< 0x00000001 */
#define DBGMCU_CR_DBG_SLEEP          DBGMCU_CR_DBG_SLEEP_Msk
#define DBGMCU_CR_DBG_STOP_Pos       (1U)
#define DBGMCU_CR_DBG_STOP_Msk       (0x1UL << DBGMCU_CR_DBG_STOP_Pos)	/*!< 0x00000002 */
#define DBGMCU_CR_DBG_STOP           DBGMCU_CR_DBG_STOP_Msk
#define DBGMCU_CR_DBG_STANDBY_Pos    (2U)
#define DBGMCU_CR_DBG_STANDBY_Msk    (0x1UL << DBGMCU_CR_DBG_STANDBY_Pos)	/*!< 0x00000004 */
#define DBGMCU_CR_DBG_STANDBY        DBGMCU_CR_DBG_STANDBY_Msk
#define DBGMCU_CR_TRACE_IOEN_Pos     (5U)
#define DBGMCU_CR_TRACE_IOEN_Msk     (0x1UL << DBGMCU_CR_TRACE_IOEN_Pos)/*!< 0x00000020 */
#define DBGMCU_CR_TRACE_IOEN         DBGMCU_CR_TRACE_IOEN_Msk

#define DBGMCU_CR_TRACE_MODE_Pos     (6U)
#define DBGMCU_CR_TRACE_MODE_Msk     (0x3UL << DBGMCU_CR_TRACE_MODE_Pos)/*!< 0x000000C0 */
#define DBGMCU_CR_TRACE_MODE         DBGMCU_CR_TRACE_MODE_Msk
#define DBGMCU_CR_TRACE_MODE_0       (0x1UL << DBGMCU_CR_TRACE_MODE_Pos)/*!< 0x00000040 */
#define DBGMCU_CR_TRACE_MODE_1       (0x2UL << DBGMCU_CR_TRACE_MODE_Pos)/*!< 0x00000080 */

/********************  Bit definition for DBGMCU_APB1_FZ register  ************/
#define DBGMCU_APB1_FZ_DBG_TIM2_STOP_Pos             (0U)
#define DBGMCU_APB1_FZ_DBG_TIM2_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_TIM2_STOP_Pos)/*!< 0x00000001 */
#define DBGMCU_APB1_FZ_DBG_TIM2_STOP                 DBGMCU_APB1_FZ_DBG_TIM2_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_TIM3_STOP_Pos             (1U)
#define DBGMCU_APB1_FZ_DBG_TIM3_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_TIM3_STOP_Pos)/*!< 0x00000002 */
#define DBGMCU_APB1_FZ_DBG_TIM3_STOP                 DBGMCU_APB1_FZ_DBG_TIM3_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_TIM4_STOP_Pos             (2U)
#define DBGMCU_APB1_FZ_DBG_TIM4_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_TIM4_STOP_Pos)/*!< 0x00000004 */
#define DBGMCU_APB1_FZ_DBG_TIM4_STOP                 DBGMCU_APB1_FZ_DBG_TIM4_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_TIM5_STOP_Pos             (3U)
#define DBGMCU_APB1_FZ_DBG_TIM5_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_TIM5_STOP_Pos)/*!< 0x00000008 */
#define DBGMCU_APB1_FZ_DBG_TIM5_STOP                 DBGMCU_APB1_FZ_DBG_TIM5_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP_Pos             (4U)
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_TIM6_STOP_Pos)/*!< 0x00000010 */
#define DBGMCU_APB1_FZ_DBG_TIM6_STOP                 DBGMCU_APB1_FZ_DBG_TIM6_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP_Pos             (5U)
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_TIM7_STOP_Pos)/*!< 0x00000020 */
#define DBGMCU_APB1_FZ_DBG_TIM7_STOP                 DBGMCU_APB1_FZ_DBG_TIM7_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_TIM12_STOP_Pos            (6U)
#define DBGMCU_APB1_FZ_DBG_TIM12_STOP_Msk            (0x1UL << DBGMCU_APB1_FZ_DBG_TIM12_STOP_Pos)	/*!< 0x00000040 */
#define DBGMCU_APB1_FZ_DBG_TIM12_STOP                DBGMCU_APB1_FZ_DBG_TIM12_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_TIM13_STOP_Pos            (7U)
#define DBGMCU_APB1_FZ_DBG_TIM13_STOP_Msk            (0x1UL << DBGMCU_APB1_FZ_DBG_TIM13_STOP_Pos)	/*!< 0x00000080 */
#define DBGMCU_APB1_FZ_DBG_TIM13_STOP                DBGMCU_APB1_FZ_DBG_TIM13_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_TIM14_STOP_Pos            (8U)
#define DBGMCU_APB1_FZ_DBG_TIM14_STOP_Msk            (0x1UL << DBGMCU_APB1_FZ_DBG_TIM14_STOP_Pos)	/*!< 0x00000100 */
#define DBGMCU_APB1_FZ_DBG_TIM14_STOP                DBGMCU_APB1_FZ_DBG_TIM14_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_LPTIM1_STOP_Pos           (9U)
#define DBGMCU_APB1_FZ_DBG_LPTIM1_STOP_Msk           (0x1UL << DBGMCU_APB1_FZ_DBG_LPTIM1_STOP_Pos)	/*!< 0x00000200 */
#define DBGMCU_APB1_FZ_DBG_LPTIM1_STOP               DBGMCU_APB1_FZ_DBG_LPTIM1_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_RTC_STOP_Pos              (10U)
#define DBGMCU_APB1_FZ_DBG_RTC_STOP_Msk              (0x1UL << DBGMCU_APB1_FZ_DBG_RTC_STOP_Pos)	/*!< 0x00000400 */
#define DBGMCU_APB1_FZ_DBG_RTC_STOP                  DBGMCU_APB1_FZ_DBG_RTC_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP_Pos             (11U)
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_WWDG_STOP_Pos)/*!< 0x00000800 */
#define DBGMCU_APB1_FZ_DBG_WWDG_STOP                 DBGMCU_APB1_FZ_DBG_WWDG_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP_Pos             (12U)
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_IWDG_STOP_Pos)/*!< 0x00001000 */
#define DBGMCU_APB1_FZ_DBG_IWDG_STOP                 DBGMCU_APB1_FZ_DBG_IWDG_STOP_Msk
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Pos    (21U)
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Msk    (0x1UL << DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Pos)	/*!< 0x00200000 */
#define DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT        DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT_Msk
#define DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT_Pos    (22U)
#define DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT_Msk    (0x1UL << DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT_Pos)	/*!< 0x00400000 */
#define DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT        DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT_Msk
#define DBGMCU_APB1_FZ_DBG_I2C3_SMBUS_TIMEOUT_Pos    (23U)
#define DBGMCU_APB1_FZ_DBG_I2C3_SMBUS_TIMEOUT_Msk    (0x1UL << DBGMCU_APB1_FZ_DBG_I2C3_SMBUS_TIMEOUT_Pos)	/*!< 0x00800000 */
#define DBGMCU_APB1_FZ_DBG_I2C3_SMBUS_TIMEOUT        DBGMCU_APB1_FZ_DBG_I2C3_SMBUS_TIMEOUT_Msk
#define DBGMCU_APB1_FZ_DBG_CAN1_STOP_Pos             (25U)
#define DBGMCU_APB1_FZ_DBG_CAN1_STOP_Msk             (0x1UL << DBGMCU_APB1_FZ_DBG_CAN1_STOP_Pos)/*!< 0x02000000 */
#define DBGMCU_APB1_FZ_DBG_CAN1_STOP                 DBGMCU_APB1_FZ_DBG_CAN1_STOP_Msk

/********************  Bit definition for DBGMCU_APB2_FZ register  ************/
#define DBGMCU_APB2_FZ_DBG_TIM1_STOP_Pos     (0U)
#define DBGMCU_APB2_FZ_DBG_TIM1_STOP_Msk     (0x1UL << DBGMCU_APB2_FZ_DBG_TIM1_STOP_Pos)/*!< 0x00000001 */
#define DBGMCU_APB2_FZ_DBG_TIM1_STOP         DBGMCU_APB2_FZ_DBG_TIM1_STOP_Msk
#define DBGMCU_APB2_FZ_DBG_TIM8_STOP_Pos     (1U)
#define DBGMCU_APB2_FZ_DBG_TIM8_STOP_Msk     (0x1UL << DBGMCU_APB2_FZ_DBG_TIM8_STOP_Pos)/*!< 0x00000002 */
#define DBGMCU_APB2_FZ_DBG_TIM8_STOP         DBGMCU_APB2_FZ_DBG_TIM8_STOP_Msk
#define DBGMCU_APB2_FZ_DBG_TIM9_STOP_Pos     (16U)
#define DBGMCU_APB2_FZ_DBG_TIM9_STOP_Msk     (0x1UL << DBGMCU_APB2_FZ_DBG_TIM9_STOP_Pos)/*!< 0x00010000 */
#define DBGMCU_APB2_FZ_DBG_TIM9_STOP         DBGMCU_APB2_FZ_DBG_TIM9_STOP_Msk
#define DBGMCU_APB2_FZ_DBG_TIM10_STOP_Pos    (17U)
#define DBGMCU_APB2_FZ_DBG_TIM10_STOP_Msk    (0x1UL << DBGMCU_APB2_FZ_DBG_TIM10_STOP_Pos)	/*!< 0x00020000 */
#define DBGMCU_APB2_FZ_DBG_TIM10_STOP        DBGMCU_APB2_FZ_DBG_TIM10_STOP_Msk
#define DBGMCU_APB2_FZ_DBG_TIM11_STOP_Pos    (18U)
#define DBGMCU_APB2_FZ_DBG_TIM11_STOP_Msk    (0x1UL << DBGMCU_APB2_FZ_DBG_TIM11_STOP_Pos)	/*!< 0x00040000 */
#define DBGMCU_APB2_FZ_DBG_TIM11_STOP        DBGMCU_APB2_FZ_DBG_TIM11_STOP_Msk


/******************************************************************************/
/*                                                                            */
/*                                       USB_OTG                              */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for USB_OTG_GOTGCTL register  ********************/
#define USB_OTG_GOTGCTL_SRQSCS_Pos       (0U)
#define USB_OTG_GOTGCTL_SRQSCS_Msk       (0x1UL << USB_OTG_GOTGCTL_SRQSCS_Pos)	/*!< 0x00000001 */
#define USB_OTG_GOTGCTL_SRQSCS           USB_OTG_GOTGCTL_SRQSCS_Msk				/*!< Session request success */
#define USB_OTG_GOTGCTL_SRQ_Pos          (1U)
#define USB_OTG_GOTGCTL_SRQ_Msk          (0x1UL << USB_OTG_GOTGCTL_SRQ_Pos)	/*!< 0x00000002 */
#define USB_OTG_GOTGCTL_SRQ              USB_OTG_GOTGCTL_SRQ_Msk/*!< Session request */
#define USB_OTG_GOTGCTL_VBVALOEN_Pos     (2U)
#define USB_OTG_GOTGCTL_VBVALOEN_Msk     (0x1UL << USB_OTG_GOTGCTL_VBVALOEN_Pos)/*!< 0x00000004 */
#define USB_OTG_GOTGCTL_VBVALOEN         USB_OTG_GOTGCTL_VBVALOEN_Msk	/*!< VBUS valid override enable */
#define USB_OTG_GOTGCTL_VBVALOVAL_Pos    (3U)
#define USB_OTG_GOTGCTL_VBVALOVAL_Msk    (0x1UL << USB_OTG_GOTGCTL_VBVALOVAL_Pos)	/*!< 0x00000008 */
#define USB_OTG_GOTGCTL_VBVALOVAL        USB_OTG_GOTGCTL_VBVALOVAL_Msk				/*!< VBUS valid override value */
#define USB_OTG_GOTGCTL_AVALOEN_Pos      (4U)
#define USB_OTG_GOTGCTL_AVALOEN_Msk      (0x1UL << USB_OTG_GOTGCTL_AVALOEN_Pos)	/*!< 0x00000010 */
#define USB_OTG_GOTGCTL_AVALOEN          USB_OTG_GOTGCTL_AVALOEN_Msk/*!< A-peripheral session valid override enable */
#define USB_OTG_GOTGCTL_AVALOVAL_Pos     (5U)
#define USB_OTG_GOTGCTL_AVALOVAL_Msk     (0x1UL << USB_OTG_GOTGCTL_AVALOVAL_Pos)/*!< 0x00000020 */
#define USB_OTG_GOTGCTL_AVALOVAL         USB_OTG_GOTGCTL_AVALOVAL_Msk	/*!< A-peripheral session valid override value */
#define USB_OTG_GOTGCTL_BVALOEN_Pos      (6U)
#define USB_OTG_GOTGCTL_BVALOEN_Msk      (0x1UL << USB_OTG_GOTGCTL_BVALOEN_Pos)	/*!< 0x00000040 */
#define USB_OTG_GOTGCTL_BVALOEN          USB_OTG_GOTGCTL_BVALOEN_Msk/*!< B-peripheral session valid override enable */
#define USB_OTG_GOTGCTL_BVALOVAL_Pos     (7U)
#define USB_OTG_GOTGCTL_BVALOVAL_Msk     (0x1UL << USB_OTG_GOTGCTL_BVALOVAL_Pos)/*!< 0x00000080 */
#define USB_OTG_GOTGCTL_BVALOVAL         USB_OTG_GOTGCTL_BVALOVAL_Msk	/*!< B-peripheral session valid override value  */
#define USB_OTG_GOTGCTL_HNGSCS_Pos       (8U)
#define USB_OTG_GOTGCTL_HNGSCS_Msk       (0x1UL << USB_OTG_GOTGCTL_HNGSCS_Pos)	/*!< 0x00000100 */
#define USB_OTG_GOTGCTL_HNGSCS           USB_OTG_GOTGCTL_HNGSCS_Msk				/*!< Host set HNP enable */
#define USB_OTG_GOTGCTL_HNPRQ_Pos        (9U)
#define USB_OTG_GOTGCTL_HNPRQ_Msk        (0x1UL << USB_OTG_GOTGCTL_HNPRQ_Pos)	/*!< 0x00000200 */
#define USB_OTG_GOTGCTL_HNPRQ            USB_OTG_GOTGCTL_HNPRQ_Msk				/*!< HNP request */
#define USB_OTG_GOTGCTL_HSHNPEN_Pos      (10U)
#define USB_OTG_GOTGCTL_HSHNPEN_Msk      (0x1UL << USB_OTG_GOTGCTL_HSHNPEN_Pos)	/*!< 0x00000400 */
#define USB_OTG_GOTGCTL_HSHNPEN          USB_OTG_GOTGCTL_HSHNPEN_Msk/*!< Host set HNP enable */
#define USB_OTG_GOTGCTL_DHNPEN_Pos       (11U)
#define USB_OTG_GOTGCTL_DHNPEN_Msk       (0x1UL << USB_OTG_GOTGCTL_DHNPEN_Pos)	/*!< 0x00000800 */
#define USB_OTG_GOTGCTL_DHNPEN           USB_OTG_GOTGCTL_DHNPEN_Msk				/*!< Device HNP enabled */
#define USB_OTG_GOTGCTL_EHEN_Pos         (12U)
#define USB_OTG_GOTGCTL_EHEN_Msk         (0x1UL << USB_OTG_GOTGCTL_EHEN_Pos)/*!< 0x00001000 */
#define USB_OTG_GOTGCTL_EHEN             USB_OTG_GOTGCTL_EHEN_Msk	/*!< Embedded host enable */
#define USB_OTG_GOTGCTL_CIDSTS_Pos       (16U)
#define USB_OTG_GOTGCTL_CIDSTS_Msk       (0x1UL << USB_OTG_GOTGCTL_CIDSTS_Pos)	/*!< 0x00010000 */
#define USB_OTG_GOTGCTL_CIDSTS           USB_OTG_GOTGCTL_CIDSTS_Msk				/*!< Connector ID status */
#define USB_OTG_GOTGCTL_DBCT_Pos         (17U)
#define USB_OTG_GOTGCTL_DBCT_Msk         (0x1UL << USB_OTG_GOTGCTL_DBCT_Pos)/*!< 0x00020000 */
#define USB_OTG_GOTGCTL_DBCT             USB_OTG_GOTGCTL_DBCT_Msk	/*!< Long/short debounce time */
#define USB_OTG_GOTGCTL_ASVLD_Pos        (18U)
#define USB_OTG_GOTGCTL_ASVLD_Msk        (0x1UL << USB_OTG_GOTGCTL_ASVLD_Pos)	/*!< 0x00040000 */
#define USB_OTG_GOTGCTL_ASVLD            USB_OTG_GOTGCTL_ASVLD_Msk				/*!< A-session valid  */
#define USB_OTG_GOTGCTL_BSESVLD_Pos      (19U)
#define USB_OTG_GOTGCTL_BSESVLD_Msk      (0x1UL << USB_OTG_GOTGCTL_BSESVLD_Pos)	/*!< 0x00080000 */
#define USB_OTG_GOTGCTL_BSESVLD          USB_OTG_GOTGCTL_BSESVLD_Msk/*!< B-session valid */
#define USB_OTG_GOTGCTL_OTGVER_Pos       (20U)
#define USB_OTG_GOTGCTL_OTGVER_Msk       (0x1UL << USB_OTG_GOTGCTL_OTGVER_Pos)	/*!< 0x00100000 */
#define USB_OTG_GOTGCTL_OTGVER           USB_OTG_GOTGCTL_OTGVER_Msk				/*!< OTG version  */

/********************  Bit definition for USB_OTG_HCFG register  ********************/
#define USB_OTG_HCFG_FSLSPCS_Pos    (0U)
#define USB_OTG_HCFG_FSLSPCS_Msk    (0x3UL << USB_OTG_HCFG_FSLSPCS_Pos)	/*!< 0x00000003 */
#define USB_OTG_HCFG_FSLSPCS        USB_OTG_HCFG_FSLSPCS_Msk/*!< FS/LS PHY clock select  */
#define USB_OTG_HCFG_FSLSPCS_0      (0x1UL << USB_OTG_HCFG_FSLSPCS_Pos)	/*!< 0x00000001 */
#define USB_OTG_HCFG_FSLSPCS_1      (0x2UL << USB_OTG_HCFG_FSLSPCS_Pos)	/*!< 0x00000002 */
#define USB_OTG_HCFG_FSLSS_Pos      (2U)
#define USB_OTG_HCFG_FSLSS_Msk      (0x1UL << USB_OTG_HCFG_FSLSS_Pos)	/*!< 0x00000004 */
#define USB_OTG_HCFG_FSLSS          USB_OTG_HCFG_FSLSS_Msk				/*!< FS- and LS-only support */

/********************  Bit definition for USB_OTG_DCFG register  ********************/
#define USB_OTG_DCFG_DSPD_Pos         (0U)
#define USB_OTG_DCFG_DSPD_Msk         (0x3UL << USB_OTG_DCFG_DSPD_Pos)	/*!< 0x00000003 */
#define USB_OTG_DCFG_DSPD             USB_OTG_DCFG_DSPD_Msk				/*!< Device speed */
#define USB_OTG_DCFG_DSPD_0           (0x1UL << USB_OTG_DCFG_DSPD_Pos)	/*!< 0x00000001 */
#define USB_OTG_DCFG_DSPD_1           (0x2UL << USB_OTG_DCFG_DSPD_Pos)	/*!< 0x00000002 */
#define USB_OTG_DCFG_NZLSOHSK_Pos     (2U)
#define USB_OTG_DCFG_NZLSOHSK_Msk     (0x1UL << USB_OTG_DCFG_NZLSOHSK_Pos)	/*!< 0x00000004 */
#define USB_OTG_DCFG_NZLSOHSK         USB_OTG_DCFG_NZLSOHSK_Msk				/*!< Nonzero-length status OUT handshake */

#define USB_OTG_DCFG_DAD_Pos          (4U)
#define USB_OTG_DCFG_DAD_Msk          (0x7FUL << USB_OTG_DCFG_DAD_Pos)	/*!< 0x000007F0 */
#define USB_OTG_DCFG_DAD              USB_OTG_DCFG_DAD_Msk				/*!< Device address */
#define USB_OTG_DCFG_DAD_0            (0x01UL << USB_OTG_DCFG_DAD_Pos)	/*!< 0x00000010 */
#define USB_OTG_DCFG_DAD_1            (0x02UL << USB_OTG_DCFG_DAD_Pos)	/*!< 0x00000020 */
#define USB_OTG_DCFG_DAD_2            (0x04UL << USB_OTG_DCFG_DAD_Pos)	/*!< 0x00000040 */
#define USB_OTG_DCFG_DAD_3            (0x08UL << USB_OTG_DCFG_DAD_Pos)	/*!< 0x00000080 */
#define USB_OTG_DCFG_DAD_4            (0x10UL << USB_OTG_DCFG_DAD_Pos)	/*!< 0x00000100 */
#define USB_OTG_DCFG_DAD_5            (0x20UL << USB_OTG_DCFG_DAD_Pos)	/*!< 0x00000200 */
#define USB_OTG_DCFG_DAD_6            (0x40UL << USB_OTG_DCFG_DAD_Pos)	/*!< 0x00000400 */

#define USB_OTG_DCFG_PFIVL_Pos        (11U)
#define USB_OTG_DCFG_PFIVL_Msk        (0x3UL << USB_OTG_DCFG_PFIVL_Pos)	/*!< 0x00001800 */
#define USB_OTG_DCFG_PFIVL            USB_OTG_DCFG_PFIVL_Msk/*!< Periodic (micro)frame interval */
#define USB_OTG_DCFG_PFIVL_0          (0x1UL << USB_OTG_DCFG_PFIVL_Pos)	/*!< 0x00000800 */
#define USB_OTG_DCFG_PFIVL_1          (0x2UL << USB_OTG_DCFG_PFIVL_Pos)	/*!< 0x00001000 */

#define USB_OTG_DCFG_PERSCHIVL_Pos    (24U)
#define USB_OTG_DCFG_PERSCHIVL_Msk    (0x3UL << USB_OTG_DCFG_PERSCHIVL_Pos)	/*!< 0x03000000 */
#define USB_OTG_DCFG_PERSCHIVL        USB_OTG_DCFG_PERSCHIVL_Msk/*!< Periodic scheduling interval */
#define USB_OTG_DCFG_PERSCHIVL_0      (0x1UL << USB_OTG_DCFG_PERSCHIVL_Pos)	/*!< 0x01000000 */
#define USB_OTG_DCFG_PERSCHIVL_1      (0x2UL << USB_OTG_DCFG_PERSCHIVL_Pos)	/*!< 0x02000000 */

/********************  Bit definition for USB_OTG_PCGCR register  ********************/
#define USB_OTG_PCGCR_STPPCLK_Pos     (0U)
#define USB_OTG_PCGCR_STPPCLK_Msk     (0x1UL << USB_OTG_PCGCR_STPPCLK_Pos)	/*!< 0x00000001 */
#define USB_OTG_PCGCR_STPPCLK         USB_OTG_PCGCR_STPPCLK_Msk				/*!< Stop PHY clock */
#define USB_OTG_PCGCR_GATEHCLK_Pos    (1U)
#define USB_OTG_PCGCR_GATEHCLK_Msk    (0x1UL << USB_OTG_PCGCR_GATEHCLK_Pos)	/*!< 0x00000002 */
#define USB_OTG_PCGCR_GATEHCLK        USB_OTG_PCGCR_GATEHCLK_Msk/*!< Gate HCLK */
#define USB_OTG_PCGCR_PHYSUSP_Pos     (4U)
#define USB_OTG_PCGCR_PHYSUSP_Msk     (0x1UL << USB_OTG_PCGCR_PHYSUSP_Pos)	/*!< 0x00000010 */
#define USB_OTG_PCGCR_PHYSUSP         USB_OTG_PCGCR_PHYSUSP_Msk				/*!< PHY suspended */

/********************  Bit definition for USB_OTG_GOTGINT register  ********************/
#define USB_OTG_GOTGINT_SEDET_Pos      (2U)
#define USB_OTG_GOTGINT_SEDET_Msk      (0x1UL << USB_OTG_GOTGINT_SEDET_Pos)	/*!< 0x00000004 */
#define USB_OTG_GOTGINT_SEDET          USB_OTG_GOTGINT_SEDET_Msk/*!< Session end detected                   */
#define USB_OTG_GOTGINT_SRSSCHG_Pos    (8U)
#define USB_OTG_GOTGINT_SRSSCHG_Msk    (0x1UL << USB_OTG_GOTGINT_SRSSCHG_Pos)	/*!< 0x00000100 */
#define USB_OTG_GOTGINT_SRSSCHG        USB_OTG_GOTGINT_SRSSCHG_Msk				/*!< Session request success status change  */
#define USB_OTG_GOTGINT_HNSSCHG_Pos    (9U)
#define USB_OTG_GOTGINT_HNSSCHG_Msk    (0x1UL << USB_OTG_GOTGINT_HNSSCHG_Pos)	/*!< 0x00000200 */
#define USB_OTG_GOTGINT_HNSSCHG        USB_OTG_GOTGINT_HNSSCHG_Msk				/*!< Host negotiation success status change */
#define USB_OTG_GOTGINT_HNGDET_Pos     (17U)
#define USB_OTG_GOTGINT_HNGDET_Msk     (0x1UL << USB_OTG_GOTGINT_HNGDET_Pos)/*!< 0x00020000 */
#define USB_OTG_GOTGINT_HNGDET         USB_OTG_GOTGINT_HNGDET_Msk	/*!< Host negotiation detected              */
#define USB_OTG_GOTGINT_ADTOCHG_Pos    (18U)
#define USB_OTG_GOTGINT_ADTOCHG_Msk    (0x1UL << USB_OTG_GOTGINT_ADTOCHG_Pos)	/*!< 0x00040000 */
#define USB_OTG_GOTGINT_ADTOCHG        USB_OTG_GOTGINT_ADTOCHG_Msk				/*!< A-device timeout change                */
#define USB_OTG_GOTGINT_DBCDNE_Pos     (19U)
#define USB_OTG_GOTGINT_DBCDNE_Msk     (0x1UL << USB_OTG_GOTGINT_DBCDNE_Pos)/*!< 0x00080000 */
#define USB_OTG_GOTGINT_DBCDNE         USB_OTG_GOTGINT_DBCDNE_Msk	/*!< Debounce done                          */
#define USB_OTG_GOTGINT_IDCHNG_Pos     (20U)
#define USB_OTG_GOTGINT_IDCHNG_Msk     (0x1UL << USB_OTG_GOTGINT_IDCHNG_Pos)/*!< 0x00100000 */
#define USB_OTG_GOTGINT_IDCHNG         USB_OTG_GOTGINT_IDCHNG_Msk	/*!< Change in ID pin input value           */

/********************  Bit definition for USB_OTG_DCTL register  ********************/
#define USB_OTG_DCTL_RWUSIG_Pos      (0U)
#define USB_OTG_DCTL_RWUSIG_Msk      (0x1UL << USB_OTG_DCTL_RWUSIG_Pos)	/*!< 0x00000001 */
#define USB_OTG_DCTL_RWUSIG          USB_OTG_DCTL_RWUSIG_Msk/*!< Remote wakeup signaling */
#define USB_OTG_DCTL_SDIS_Pos        (1U)
#define USB_OTG_DCTL_SDIS_Msk        (0x1UL << USB_OTG_DCTL_SDIS_Pos)	/*!< 0x00000002 */
#define USB_OTG_DCTL_SDIS            USB_OTG_DCTL_SDIS_Msk				/*!< Soft disconnect         */
#define USB_OTG_DCTL_GINSTS_Pos      (2U)
#define USB_OTG_DCTL_GINSTS_Msk      (0x1UL << USB_OTG_DCTL_GINSTS_Pos)	/*!< 0x00000004 */
#define USB_OTG_DCTL_GINSTS          USB_OTG_DCTL_GINSTS_Msk/*!< Global IN NAK status    */
#define USB_OTG_DCTL_GONSTS_Pos      (3U)
#define USB_OTG_DCTL_GONSTS_Msk      (0x1UL << USB_OTG_DCTL_GONSTS_Pos)	/*!< 0x00000008 */
#define USB_OTG_DCTL_GONSTS          USB_OTG_DCTL_GONSTS_Msk/*!< Global OUT NAK status   */

#define USB_OTG_DCTL_TCTL_Pos        (4U)
#define USB_OTG_DCTL_TCTL_Msk        (0x7UL << USB_OTG_DCTL_TCTL_Pos)	/*!< 0x00000070 */
#define USB_OTG_DCTL_TCTL            USB_OTG_DCTL_TCTL_Msk				/*!< Test control */
#define USB_OTG_DCTL_TCTL_0          (0x1UL << USB_OTG_DCTL_TCTL_Pos)	/*!< 0x00000010 */
#define USB_OTG_DCTL_TCTL_1          (0x2UL << USB_OTG_DCTL_TCTL_Pos)	/*!< 0x00000020 */
#define USB_OTG_DCTL_TCTL_2          (0x4UL << USB_OTG_DCTL_TCTL_Pos)	/*!< 0x00000040 */
#define USB_OTG_DCTL_SGINAK_Pos      (7U)
#define USB_OTG_DCTL_SGINAK_Msk      (0x1UL << USB_OTG_DCTL_SGINAK_Pos)	/*!< 0x00000080 */
#define USB_OTG_DCTL_SGINAK          USB_OTG_DCTL_SGINAK_Msk/*!< Set global IN NAK         */
#define USB_OTG_DCTL_CGINAK_Pos      (8U)
#define USB_OTG_DCTL_CGINAK_Msk      (0x1UL << USB_OTG_DCTL_CGINAK_Pos)	/*!< 0x00000100 */
#define USB_OTG_DCTL_CGINAK          USB_OTG_DCTL_CGINAK_Msk/*!< Clear global IN NAK       */
#define USB_OTG_DCTL_SGONAK_Pos      (9U)
#define USB_OTG_DCTL_SGONAK_Msk      (0x1UL << USB_OTG_DCTL_SGONAK_Pos)	/*!< 0x00000200 */
#define USB_OTG_DCTL_SGONAK          USB_OTG_DCTL_SGONAK_Msk/*!< Set global OUT NAK        */
#define USB_OTG_DCTL_CGONAK_Pos      (10U)
#define USB_OTG_DCTL_CGONAK_Msk      (0x1UL << USB_OTG_DCTL_CGONAK_Pos)	/*!< 0x00000400 */
#define USB_OTG_DCTL_CGONAK          USB_OTG_DCTL_CGONAK_Msk/*!< Clear global OUT NAK      */
#define USB_OTG_DCTL_POPRGDNE_Pos    (11U)
#define USB_OTG_DCTL_POPRGDNE_Msk    (0x1UL << USB_OTG_DCTL_POPRGDNE_Pos)	/*!< 0x00000800 */
#define USB_OTG_DCTL_POPRGDNE        USB_OTG_DCTL_POPRGDNE_Msk				/*!< Power-on programming done */

/********************  Bit definition for USB_OTG_HFIR register  ********************/
#define USB_OTG_HFIR_FRIVL_Pos    (0U)
#define USB_OTG_HFIR_FRIVL_Msk    (0xFFFFUL << USB_OTG_HFIR_FRIVL_Pos)	/*!< 0x0000FFFF */
#define USB_OTG_HFIR_FRIVL        USB_OTG_HFIR_FRIVL_Msk				/*!< Frame interval */

/********************  Bit definition for USB_OTG_HFNUM register  ********************/
#define USB_OTG_HFNUM_FRNUM_Pos    (0U)
#define USB_OTG_HFNUM_FRNUM_Msk    (0xFFFFUL << USB_OTG_HFNUM_FRNUM_Pos)/*!< 0x0000FFFF */
#define USB_OTG_HFNUM_FRNUM        USB_OTG_HFNUM_FRNUM_Msk	/*!< Frame number         */
#define USB_OTG_HFNUM_FTREM_Pos    (16U)
#define USB_OTG_HFNUM_FTREM_Msk    (0xFFFFUL << USB_OTG_HFNUM_FTREM_Pos)/*!< 0xFFFF0000 */
#define USB_OTG_HFNUM_FTREM        USB_OTG_HFNUM_FTREM_Msk	/*!< Frame time remaining */

/********************  Bit definition for USB_OTG_DSTS register  ********************/
#define USB_OTG_DSTS_SUSPSTS_Pos    (0U)
#define USB_OTG_DSTS_SUSPSTS_Msk    (0x1UL << USB_OTG_DSTS_SUSPSTS_Pos)	/*!< 0x00000001 */
#define USB_OTG_DSTS_SUSPSTS        USB_OTG_DSTS_SUSPSTS_Msk/*!< Suspend status   */

#define USB_OTG_DSTS_ENUMSPD_Pos    (1U)
#define USB_OTG_DSTS_ENUMSPD_Msk    (0x3UL << USB_OTG_DSTS_ENUMSPD_Pos)	/*!< 0x00000006 */
#define USB_OTG_DSTS_ENUMSPD        USB_OTG_DSTS_ENUMSPD_Msk/*!< Enumerated speed */
#define USB_OTG_DSTS_ENUMSPD_0      (0x1UL << USB_OTG_DSTS_ENUMSPD_Pos)	/*!< 0x00000002 */
#define USB_OTG_DSTS_ENUMSPD_1      (0x2UL << USB_OTG_DSTS_ENUMSPD_Pos)	/*!< 0x00000004 */
#define USB_OTG_DSTS_EERR_Pos       (3U)
#define USB_OTG_DSTS_EERR_Msk       (0x1UL << USB_OTG_DSTS_EERR_Pos)/*!< 0x00000008 */
#define USB_OTG_DSTS_EERR           USB_OTG_DSTS_EERR_Msk	/*!< Erratic error     */
#define USB_OTG_DSTS_FNSOF_Pos      (8U)
#define USB_OTG_DSTS_FNSOF_Msk      (0x3FFFUL << USB_OTG_DSTS_FNSOF_Pos)/*!< 0x003FFF00 */
#define USB_OTG_DSTS_FNSOF          USB_OTG_DSTS_FNSOF_Msk	/*!< Frame number of the received SOF */

/********************  Bit definition for USB_OTG_GAHBCFG register  ********************/
#define USB_OTG_GAHBCFG_GINT_Pos        (0U)
#define USB_OTG_GAHBCFG_GINT_Msk        (0x1UL << USB_OTG_GAHBCFG_GINT_Pos)	/*!< 0x00000001 */
#define USB_OTG_GAHBCFG_GINT            USB_OTG_GAHBCFG_GINT_Msk/*!< Global interrupt mask */
#define USB_OTG_GAHBCFG_HBSTLEN_Pos     (1U)
#define USB_OTG_GAHBCFG_HBSTLEN_Msk     (0xFUL << USB_OTG_GAHBCFG_HBSTLEN_Pos)	/*!< 0x0000001E */
#define USB_OTG_GAHBCFG_HBSTLEN         USB_OTG_GAHBCFG_HBSTLEN_Msk				/*!< Burst length/type */
#define USB_OTG_GAHBCFG_HBSTLEN_0       (0x0UL << USB_OTG_GAHBCFG_HBSTLEN_Pos)	/*!< Single */
#define USB_OTG_GAHBCFG_HBSTLEN_1       (0x1UL << USB_OTG_GAHBCFG_HBSTLEN_Pos)	/*!< INCR */
#define USB_OTG_GAHBCFG_HBSTLEN_2       (0x3UL << USB_OTG_GAHBCFG_HBSTLEN_Pos)	/*!< INCR4 */
#define USB_OTG_GAHBCFG_HBSTLEN_3       (0x5UL << USB_OTG_GAHBCFG_HBSTLEN_Pos)	/*!< INCR8 */
#define USB_OTG_GAHBCFG_HBSTLEN_4       (0x7UL << USB_OTG_GAHBCFG_HBSTLEN_Pos)	/*!< INCR16 */
#define USB_OTG_GAHBCFG_DMAEN_Pos       (5U)
#define USB_OTG_GAHBCFG_DMAEN_Msk       (0x1UL << USB_OTG_GAHBCFG_DMAEN_Pos)/*!< 0x00000020 */
#define USB_OTG_GAHBCFG_DMAEN           USB_OTG_GAHBCFG_DMAEN_Msk	/*!< DMA enable */
#define USB_OTG_GAHBCFG_TXFELVL_Pos     (7U)
#define USB_OTG_GAHBCFG_TXFELVL_Msk     (0x1UL << USB_OTG_GAHBCFG_TXFELVL_Pos)	/*!< 0x00000080 */
#define USB_OTG_GAHBCFG_TXFELVL         USB_OTG_GAHBCFG_TXFELVL_Msk				/*!< TxFIFO empty level */
#define USB_OTG_GAHBCFG_PTXFELVL_Pos    (8U)
#define USB_OTG_GAHBCFG_PTXFELVL_Msk    (0x1UL << USB_OTG_GAHBCFG_PTXFELVL_Pos)	/*!< 0x00000100 */
#define USB_OTG_GAHBCFG_PTXFELVL        USB_OTG_GAHBCFG_PTXFELVL_Msk/*!< Periodic TxFIFO empty level */

/********************  Bit definition for USB_OTG_GUSBCFG register  ********************/
#define USB_OTG_GUSBCFG_TOCAL_Pos         (0U)
#define USB_OTG_GUSBCFG_TOCAL_Msk         (0x7UL << USB_OTG_GUSBCFG_TOCAL_Pos)	/*!< 0x00000007 */
#define USB_OTG_GUSBCFG_TOCAL             USB_OTG_GUSBCFG_TOCAL_Msk				/*!< FS timeout calibration */
#define USB_OTG_GUSBCFG_TOCAL_0           (0x1UL << USB_OTG_GUSBCFG_TOCAL_Pos)	/*!< 0x00000001 */
#define USB_OTG_GUSBCFG_TOCAL_1           (0x2UL << USB_OTG_GUSBCFG_TOCAL_Pos)	/*!< 0x00000002 */
#define USB_OTG_GUSBCFG_TOCAL_2           (0x4UL << USB_OTG_GUSBCFG_TOCAL_Pos)	/*!< 0x00000004 */
#define USB_OTG_GUSBCFG_PHYSEL_Pos        (6U)
#define USB_OTG_GUSBCFG_PHYSEL_Msk        (0x1UL << USB_OTG_GUSBCFG_PHYSEL_Pos)	/*!< 0x00000040 */
#define USB_OTG_GUSBCFG_PHYSEL            USB_OTG_GUSBCFG_PHYSEL_Msk/*!< USB 2.0 high-speed ULPI PHY or USB 1.1 full-speed serial transceiver select */
#define USB_OTG_GUSBCFG_SRPCAP_Pos        (8U)
#define USB_OTG_GUSBCFG_SRPCAP_Msk        (0x1UL << USB_OTG_GUSBCFG_SRPCAP_Pos)	/*!< 0x00000100 */
#define USB_OTG_GUSBCFG_SRPCAP            USB_OTG_GUSBCFG_SRPCAP_Msk/*!< SRP-capable */
#define USB_OTG_GUSBCFG_HNPCAP_Pos        (9U)
#define USB_OTG_GUSBCFG_HNPCAP_Msk        (0x1UL << USB_OTG_GUSBCFG_HNPCAP_Pos)	/*!< 0x00000200 */
#define USB_OTG_GUSBCFG_HNPCAP            USB_OTG_GUSBCFG_HNPCAP_Msk/*!< HNP-capable */
#define USB_OTG_GUSBCFG_TRDT_Pos          (10U)
#define USB_OTG_GUSBCFG_TRDT_Msk          (0xFUL << USB_OTG_GUSBCFG_TRDT_Pos)	/*!< 0x00003C00 */
#define USB_OTG_GUSBCFG_TRDT              USB_OTG_GUSBCFG_TRDT_Msk				/*!< USB turnaround time */
#define USB_OTG_GUSBCFG_TRDT_0            (0x1UL << USB_OTG_GUSBCFG_TRDT_Pos)	/*!< 0x00000400 */
#define USB_OTG_GUSBCFG_TRDT_1            (0x2UL << USB_OTG_GUSBCFG_TRDT_Pos)	/*!< 0x00000800 */
#define USB_OTG_GUSBCFG_TRDT_2            (0x4UL << USB_OTG_GUSBCFG_TRDT_Pos)	/*!< 0x00001000 */
#define USB_OTG_GUSBCFG_TRDT_3            (0x8UL << USB_OTG_GUSBCFG_TRDT_Pos)	/*!< 0x00002000 */
#define USB_OTG_GUSBCFG_PHYLPCS_Pos       (15U)
#define USB_OTG_GUSBCFG_PHYLPCS_Msk       (0x1UL << USB_OTG_GUSBCFG_PHYLPCS_Pos)/*!< 0x00008000 */
#define USB_OTG_GUSBCFG_PHYLPCS           USB_OTG_GUSBCFG_PHYLPCS_Msk	/*!< PHY Low-power clock select */
#define USB_OTG_GUSBCFG_ULPIFSLS_Pos      (17U)
#define USB_OTG_GUSBCFG_ULPIFSLS_Msk      (0x1UL << USB_OTG_GUSBCFG_ULPIFSLS_Pos)	/*!< 0x00020000 */
#define USB_OTG_GUSBCFG_ULPIFSLS          USB_OTG_GUSBCFG_ULPIFSLS_Msk				/*!< ULPI FS/LS select               */
#define USB_OTG_GUSBCFG_ULPIAR_Pos        (18U)
#define USB_OTG_GUSBCFG_ULPIAR_Msk        (0x1UL << USB_OTG_GUSBCFG_ULPIAR_Pos)	/*!< 0x00040000 */
#define USB_OTG_GUSBCFG_ULPIAR            USB_OTG_GUSBCFG_ULPIAR_Msk/*!< ULPI Auto-resume                */
#define USB_OTG_GUSBCFG_ULPICSM_Pos       (19U)
#define USB_OTG_GUSBCFG_ULPICSM_Msk       (0x1UL << USB_OTG_GUSBCFG_ULPICSM_Pos)/*!< 0x00080000 */
#define USB_OTG_GUSBCFG_ULPICSM           USB_OTG_GUSBCFG_ULPICSM_Msk	/*!< ULPI Clock SuspendM             */
#define USB_OTG_GUSBCFG_ULPIEVBUSD_Pos    (20U)
#define USB_OTG_GUSBCFG_ULPIEVBUSD_Msk    (0x1UL << USB_OTG_GUSBCFG_ULPIEVBUSD_Pos)	/*!< 0x00100000 */
#define USB_OTG_GUSBCFG_ULPIEVBUSD        USB_OTG_GUSBCFG_ULPIEVBUSD_Msk/*!< ULPI External VBUS Drive        */
#define USB_OTG_GUSBCFG_ULPIEVBUSI_Pos    (21U)
#define USB_OTG_GUSBCFG_ULPIEVBUSI_Msk    (0x1UL << USB_OTG_GUSBCFG_ULPIEVBUSI_Pos)	/*!< 0x00200000 */
#define USB_OTG_GUSBCFG_ULPIEVBUSI        USB_OTG_GUSBCFG_ULPIEVBUSI_Msk/*!< ULPI external VBUS indicator    */
#define USB_OTG_GUSBCFG_TSDPS_Pos         (22U)
#define USB_OTG_GUSBCFG_TSDPS_Msk         (0x1UL << USB_OTG_GUSBCFG_TSDPS_Pos)	/*!< 0x00400000 */
#define USB_OTG_GUSBCFG_TSDPS             USB_OTG_GUSBCFG_TSDPS_Msk				/*!< TermSel DLine pulsing selection */
#define USB_OTG_GUSBCFG_PCCI_Pos          (23U)
#define USB_OTG_GUSBCFG_PCCI_Msk          (0x1UL << USB_OTG_GUSBCFG_PCCI_Pos)	/*!< 0x00800000 */
#define USB_OTG_GUSBCFG_PCCI              USB_OTG_GUSBCFG_PCCI_Msk				/*!< Indicator complement            */
#define USB_OTG_GUSBCFG_PTCI_Pos          (24U)
#define USB_OTG_GUSBCFG_PTCI_Msk          (0x1UL << USB_OTG_GUSBCFG_PTCI_Pos)	/*!< 0x01000000 */
#define USB_OTG_GUSBCFG_PTCI              USB_OTG_GUSBCFG_PTCI_Msk				/*!< Indicator pass through          */
#define USB_OTG_GUSBCFG_ULPIIPD_Pos       (25U)
#define USB_OTG_GUSBCFG_ULPIIPD_Msk       (0x1UL << USB_OTG_GUSBCFG_ULPIIPD_Pos)/*!< 0x02000000 */
#define USB_OTG_GUSBCFG_ULPIIPD           USB_OTG_GUSBCFG_ULPIIPD_Msk	/*!< ULPI interface protect disable  */
#define USB_OTG_GUSBCFG_FHMOD_Pos         (29U)
#define USB_OTG_GUSBCFG_FHMOD_Msk         (0x1UL << USB_OTG_GUSBCFG_FHMOD_Pos)	/*!< 0x20000000 */
#define USB_OTG_GUSBCFG_FHMOD             USB_OTG_GUSBCFG_FHMOD_Msk				/*!< Forced host mode                */
#define USB_OTG_GUSBCFG_FDMOD_Pos         (30U)
#define USB_OTG_GUSBCFG_FDMOD_Msk         (0x1UL << USB_OTG_GUSBCFG_FDMOD_Pos)	/*!< 0x40000000 */
#define USB_OTG_GUSBCFG_FDMOD             USB_OTG_GUSBCFG_FDMOD_Msk				/*!< Forced peripheral mode          */
#define USB_OTG_GUSBCFG_CTXPKT_Pos        (31U)
#define USB_OTG_GUSBCFG_CTXPKT_Msk        (0x1UL << USB_OTG_GUSBCFG_CTXPKT_Pos)	/*!< 0x80000000 */
#define USB_OTG_GUSBCFG_CTXPKT            USB_OTG_GUSBCFG_CTXPKT_Msk/*!< Corrupt Tx packet               */

/********************  Bit definition for USB_OTG_GRSTCTL register  ********************/
#define USB_OTG_GRSTCTL_CSRST_Pos      (0U)
#define USB_OTG_GRSTCTL_CSRST_Msk      (0x1UL << USB_OTG_GRSTCTL_CSRST_Pos)	/*!< 0x00000001 */
#define USB_OTG_GRSTCTL_CSRST          USB_OTG_GRSTCTL_CSRST_Msk/*!< Core soft reset          */
#define USB_OTG_GRSTCTL_HSRST_Pos      (1U)
#define USB_OTG_GRSTCTL_HSRST_Msk      (0x1UL << USB_OTG_GRSTCTL_HSRST_Pos)	/*!< 0x00000002 */
#define USB_OTG_GRSTCTL_HSRST          USB_OTG_GRSTCTL_HSRST_Msk/*!< HCLK soft reset          */
#define USB_OTG_GRSTCTL_FCRST_Pos      (2U)
#define USB_OTG_GRSTCTL_FCRST_Msk      (0x1UL << USB_OTG_GRSTCTL_FCRST_Pos)	/*!< 0x00000004 */
#define USB_OTG_GRSTCTL_FCRST          USB_OTG_GRSTCTL_FCRST_Msk/*!< Host frame counter reset */
#define USB_OTG_GRSTCTL_RXFFLSH_Pos    (4U)
#define USB_OTG_GRSTCTL_RXFFLSH_Msk    (0x1UL << USB_OTG_GRSTCTL_RXFFLSH_Pos)	/*!< 0x00000010 */
#define USB_OTG_GRSTCTL_RXFFLSH        USB_OTG_GRSTCTL_RXFFLSH_Msk				/*!< RxFIFO flush             */
#define USB_OTG_GRSTCTL_TXFFLSH_Pos    (5U)
#define USB_OTG_GRSTCTL_TXFFLSH_Msk    (0x1UL << USB_OTG_GRSTCTL_TXFFLSH_Pos)	/*!< 0x00000020 */
#define USB_OTG_GRSTCTL_TXFFLSH        USB_OTG_GRSTCTL_TXFFLSH_Msk				/*!< TxFIFO flush             */
#define USB_OTG_GRSTCTL_TXFNUM_Pos     (6U)
#define USB_OTG_GRSTCTL_TXFNUM_Msk     (0x1FUL << USB_OTG_GRSTCTL_TXFNUM_Pos)	/*!< 0x000007C0 */
#define USB_OTG_GRSTCTL_TXFNUM         USB_OTG_GRSTCTL_TXFNUM_Msk				/*!< TxFIFO number */
#define USB_OTG_GRSTCTL_TXFNUM_0       (0x01UL << USB_OTG_GRSTCTL_TXFNUM_Pos)	/*!< 0x00000040 */
#define USB_OTG_GRSTCTL_TXFNUM_1       (0x02UL << USB_OTG_GRSTCTL_TXFNUM_Pos)	/*!< 0x00000080 */
#define USB_OTG_GRSTCTL_TXFNUM_2       (0x04UL << USB_OTG_GRSTCTL_TXFNUM_Pos)	/*!< 0x00000100 */
#define USB_OTG_GRSTCTL_TXFNUM_3       (0x08UL << USB_OTG_GRSTCTL_TXFNUM_Pos)	/*!< 0x00000200 */
#define USB_OTG_GRSTCTL_TXFNUM_4       (0x10UL << USB_OTG_GRSTCTL_TXFNUM_Pos)	/*!< 0x00000400 */
#define USB_OTG_GRSTCTL_DMAREQ_Pos     (30U)
#define USB_OTG_GRSTCTL_DMAREQ_Msk     (0x1UL << USB_OTG_GRSTCTL_DMAREQ_Pos)/*!< 0x40000000 */
#define USB_OTG_GRSTCTL_DMAREQ         USB_OTG_GRSTCTL_DMAREQ_Msk	/*!< DMA request signal */
#define USB_OTG_GRSTCTL_AHBIDL_Pos     (31U)
#define USB_OTG_GRSTCTL_AHBIDL_Msk     (0x1UL << USB_OTG_GRSTCTL_AHBIDL_Pos)/*!< 0x80000000 */
#define USB_OTG_GRSTCTL_AHBIDL         USB_OTG_GRSTCTL_AHBIDL_Msk	/*!< AHB master idle */

/********************  Bit definition for USB_OTG_DIEPMSK register  ********************/
#define USB_OTG_DIEPMSK_XFRCM_Pos        (0U)
#define USB_OTG_DIEPMSK_XFRCM_Msk        (0x1UL << USB_OTG_DIEPMSK_XFRCM_Pos)	/*!< 0x00000001 */
#define USB_OTG_DIEPMSK_XFRCM            USB_OTG_DIEPMSK_XFRCM_Msk				/*!< Transfer completed interrupt mask                 */
#define USB_OTG_DIEPMSK_EPDM_Pos         (1U)
#define USB_OTG_DIEPMSK_EPDM_Msk         (0x1UL << USB_OTG_DIEPMSK_EPDM_Pos)/*!< 0x00000002 */
#define USB_OTG_DIEPMSK_EPDM             USB_OTG_DIEPMSK_EPDM_Msk	/*!< Endpoint disabled interrupt mask                  */
#define USB_OTG_DIEPMSK_TOM_Pos          (3U)
#define USB_OTG_DIEPMSK_TOM_Msk          (0x1UL << USB_OTG_DIEPMSK_TOM_Pos)	/*!< 0x00000008 */
#define USB_OTG_DIEPMSK_TOM              USB_OTG_DIEPMSK_TOM_Msk/*!< Timeout condition mask (nonisochronous endpoints) */
#define USB_OTG_DIEPMSK_ITTXFEMSK_Pos    (4U)
#define USB_OTG_DIEPMSK_ITTXFEMSK_Msk    (0x1UL << USB_OTG_DIEPMSK_ITTXFEMSK_Pos)	/*!< 0x00000010 */
#define USB_OTG_DIEPMSK_ITTXFEMSK        USB_OTG_DIEPMSK_ITTXFEMSK_Msk				/*!< IN token received when TxFIFO empty mask          */
#define USB_OTG_DIEPMSK_INEPNMM_Pos      (5U)
#define USB_OTG_DIEPMSK_INEPNMM_Msk      (0x1UL << USB_OTG_DIEPMSK_INEPNMM_Pos)	/*!< 0x00000020 */
#define USB_OTG_DIEPMSK_INEPNMM          USB_OTG_DIEPMSK_INEPNMM_Msk/*!< IN token received with EP mismatch mask           */
#define USB_OTG_DIEPMSK_INEPNEM_Pos      (6U)
#define USB_OTG_DIEPMSK_INEPNEM_Msk      (0x1UL << USB_OTG_DIEPMSK_INEPNEM_Pos)	/*!< 0x00000040 */
#define USB_OTG_DIEPMSK_INEPNEM          USB_OTG_DIEPMSK_INEPNEM_Msk/*!< IN endpoint NAK effective mask                    */
#define USB_OTG_DIEPMSK_TXFURM_Pos       (8U)
#define USB_OTG_DIEPMSK_TXFURM_Msk       (0x1UL << USB_OTG_DIEPMSK_TXFURM_Pos)	/*!< 0x00000100 */
#define USB_OTG_DIEPMSK_TXFURM           USB_OTG_DIEPMSK_TXFURM_Msk				/*!< FIFO underrun mask                                */
#define USB_OTG_DIEPMSK_BIM_Pos          (9U)
#define USB_OTG_DIEPMSK_BIM_Msk          (0x1UL << USB_OTG_DIEPMSK_BIM_Pos)	/*!< 0x00000200 */
#define USB_OTG_DIEPMSK_BIM              USB_OTG_DIEPMSK_BIM_Msk/*!< BNA interrupt mask                                */

/********************  Bit definition for USB_OTG_HPTXSTS register  ********************/
#define USB_OTG_HPTXSTS_PTXFSAVL_Pos    (0U)
#define USB_OTG_HPTXSTS_PTXFSAVL_Msk    (0xFFFFUL << USB_OTG_HPTXSTS_PTXFSAVL_Pos)	/*!< 0x0000FFFF */
#define USB_OTG_HPTXSTS_PTXFSAVL        USB_OTG_HPTXSTS_PTXFSAVL_Msk				/*!< Periodic transmit data FIFO space available     */
#define USB_OTG_HPTXSTS_PTXQSAV_Pos     (16U)
#define USB_OTG_HPTXSTS_PTXQSAV_Msk     (0xFFUL << USB_OTG_HPTXSTS_PTXQSAV_Pos)	/*!< 0x00FF0000 */
#define USB_OTG_HPTXSTS_PTXQSAV         USB_OTG_HPTXSTS_PTXQSAV_Msk				/*!< Periodic transmit request queue space available */
#define USB_OTG_HPTXSTS_PTXQSAV_0       (0x01UL << USB_OTG_HPTXSTS_PTXQSAV_Pos)	/*!< 0x00010000 */
#define USB_OTG_HPTXSTS_PTXQSAV_1       (0x02UL << USB_OTG_HPTXSTS_PTXQSAV_Pos)	/*!< 0x00020000 */
#define USB_OTG_HPTXSTS_PTXQSAV_2       (0x04UL << USB_OTG_HPTXSTS_PTXQSAV_Pos)	/*!< 0x00040000 */
#define USB_OTG_HPTXSTS_PTXQSAV_3       (0x08UL << USB_OTG_HPTXSTS_PTXQSAV_Pos)	/*!< 0x00080000 */
#define USB_OTG_HPTXSTS_PTXQSAV_4       (0x10UL << USB_OTG_HPTXSTS_PTXQSAV_Pos)	/*!< 0x00100000 */
#define USB_OTG_HPTXSTS_PTXQSAV_5       (0x20UL << USB_OTG_HPTXSTS_PTXQSAV_Pos)	/*!< 0x00200000 */
#define USB_OTG_HPTXSTS_PTXQSAV_6       (0x40UL << USB_OTG_HPTXSTS_PTXQSAV_Pos)	/*!< 0x00400000 */
#define USB_OTG_HPTXSTS_PTXQSAV_7       (0x80UL << USB_OTG_HPTXSTS_PTXQSAV_Pos)	/*!< 0x00800000 */

#define USB_OTG_HPTXSTS_PTXQTOP_Pos     (24U)
#define USB_OTG_HPTXSTS_PTXQTOP_Msk     (0xFFUL << USB_OTG_HPTXSTS_PTXQTOP_Pos)	/*!< 0xFF000000 */
#define USB_OTG_HPTXSTS_PTXQTOP         USB_OTG_HPTXSTS_PTXQTOP_Msk				/*!< Top of the periodic transmit request queue */
#define USB_OTG_HPTXSTS_PTXQTOP_0       (0x01UL << USB_OTG_HPTXSTS_PTXQTOP_Pos)	/*!< 0x01000000 */
#define USB_OTG_HPTXSTS_PTXQTOP_1       (0x02UL << USB_OTG_HPTXSTS_PTXQTOP_Pos)	/*!< 0x02000000 */
#define USB_OTG_HPTXSTS_PTXQTOP_2       (0x04UL << USB_OTG_HPTXSTS_PTXQTOP_Pos)	/*!< 0x04000000 */
#define USB_OTG_HPTXSTS_PTXQTOP_3       (0x08UL << USB_OTG_HPTXSTS_PTXQTOP_Pos)	/*!< 0x08000000 */
#define USB_OTG_HPTXSTS_PTXQTOP_4       (0x10UL << USB_OTG_HPTXSTS_PTXQTOP_Pos)	/*!< 0x10000000 */
#define USB_OTG_HPTXSTS_PTXQTOP_5       (0x20UL << USB_OTG_HPTXSTS_PTXQTOP_Pos)	/*!< 0x20000000 */
#define USB_OTG_HPTXSTS_PTXQTOP_6       (0x40UL << USB_OTG_HPTXSTS_PTXQTOP_Pos)	/*!< 0x40000000 */
#define USB_OTG_HPTXSTS_PTXQTOP_7       (0x80UL << USB_OTG_HPTXSTS_PTXQTOP_Pos)	/*!< 0x80000000 */

/********************  Bit definition for USB_OTG_HAINT register  ********************/
#define USB_OTG_HAINT_HAINT_Pos    (0U)
#define USB_OTG_HAINT_HAINT_Msk    (0xFFFFUL << USB_OTG_HAINT_HAINT_Pos)/*!< 0x0000FFFF */
#define USB_OTG_HAINT_HAINT        USB_OTG_HAINT_HAINT_Msk	/*!< Channel interrupts */

/********************  Bit definition for USB_OTG_DOEPMSK register  ********************/
#define USB_OTG_DOEPMSK_XFRCM_Pos       (0U)
#define USB_OTG_DOEPMSK_XFRCM_Msk       (0x1UL << USB_OTG_DOEPMSK_XFRCM_Pos)/*!< 0x00000001 */
#define USB_OTG_DOEPMSK_XFRCM           USB_OTG_DOEPMSK_XFRCM_Msk	/*!< Transfer completed interrupt mask */
#define USB_OTG_DOEPMSK_EPDM_Pos        (1U)
#define USB_OTG_DOEPMSK_EPDM_Msk        (0x1UL << USB_OTG_DOEPMSK_EPDM_Pos)	/*!< 0x00000002 */
#define USB_OTG_DOEPMSK_EPDM            USB_OTG_DOEPMSK_EPDM_Msk/*!< Endpoint disabled interrupt mask               */
#define USB_OTG_DOEPMSK_AHBERRM_Pos     (2U)
#define USB_OTG_DOEPMSK_AHBERRM_Msk     (0x1UL << USB_OTG_DOEPMSK_AHBERRM_Pos)	/*!< 0x00000004 */
#define USB_OTG_DOEPMSK_AHBERRM         USB_OTG_DOEPMSK_AHBERRM_Msk				/*!< OUT transaction AHB Error interrupt mask    */
#define USB_OTG_DOEPMSK_STUPM_Pos       (3U)
#define USB_OTG_DOEPMSK_STUPM_Msk       (0x1UL << USB_OTG_DOEPMSK_STUPM_Pos)/*!< 0x00000008 */
#define USB_OTG_DOEPMSK_STUPM           USB_OTG_DOEPMSK_STUPM_Msk	/*!< SETUP phase done mask                          */
#define USB_OTG_DOEPMSK_OTEPDM_Pos      (4U)
#define USB_OTG_DOEPMSK_OTEPDM_Msk      (0x1UL << USB_OTG_DOEPMSK_OTEPDM_Pos)	/*!< 0x00000010 */
#define USB_OTG_DOEPMSK_OTEPDM          USB_OTG_DOEPMSK_OTEPDM_Msk				/*!< OUT token received when endpoint disabled mask */
#define USB_OTG_DOEPMSK_OTEPSPRM_Pos    (5U)
#define USB_OTG_DOEPMSK_OTEPSPRM_Msk    (0x1UL << USB_OTG_DOEPMSK_OTEPSPRM_Pos)	/*!< 0x00000020 */
#define USB_OTG_DOEPMSK_OTEPSPRM        USB_OTG_DOEPMSK_OTEPSPRM_Msk/*!< Status Phase Received mask                     */
#define USB_OTG_DOEPMSK_B2BSTUP_Pos     (6U)
#define USB_OTG_DOEPMSK_B2BSTUP_Msk     (0x1UL << USB_OTG_DOEPMSK_B2BSTUP_Pos)	/*!< 0x00000040 */
#define USB_OTG_DOEPMSK_B2BSTUP         USB_OTG_DOEPMSK_B2BSTUP_Msk				/*!< Back-to-back SETUP packets received mask       */
#define USB_OTG_DOEPMSK_OPEM_Pos        (8U)
#define USB_OTG_DOEPMSK_OPEM_Msk        (0x1UL << USB_OTG_DOEPMSK_OPEM_Pos)	/*!< 0x00000100 */
#define USB_OTG_DOEPMSK_OPEM            USB_OTG_DOEPMSK_OPEM_Msk/*!< OUT packet error mask                          */
#define USB_OTG_DOEPMSK_BOIM_Pos        (9U)
#define USB_OTG_DOEPMSK_BOIM_Msk        (0x1UL << USB_OTG_DOEPMSK_BOIM_Pos)	/*!< 0x00000200 */
#define USB_OTG_DOEPMSK_BOIM            USB_OTG_DOEPMSK_BOIM_Msk/*!< BNA interrupt mask                             */
#define USB_OTG_DOEPMSK_BERRM_Pos       (12U)
#define USB_OTG_DOEPMSK_BERRM_Msk       (0x1UL << USB_OTG_DOEPMSK_BERRM_Pos)/*!< 0x00001000 */
#define USB_OTG_DOEPMSK_BERRM           USB_OTG_DOEPMSK_BERRM_Msk	/*!< Babble error interrupt mask                   */
#define USB_OTG_DOEPMSK_NAKM_Pos        (13U)
#define USB_OTG_DOEPMSK_NAKM_Msk        (0x1UL << USB_OTG_DOEPMSK_NAKM_Pos)	/*!< 0x00002000 */
#define USB_OTG_DOEPMSK_NAKM            USB_OTG_DOEPMSK_NAKM_Msk/*!< OUT Packet NAK interrupt mask                  */
#define USB_OTG_DOEPMSK_NYETM_Pos       (14U)
#define USB_OTG_DOEPMSK_NYETM_Msk       (0x1UL << USB_OTG_DOEPMSK_NYETM_Pos)/*!< 0x00004000 */
#define USB_OTG_DOEPMSK_NYETM           USB_OTG_DOEPMSK_NYETM_Msk	/*!< NYET interrupt mask                           */

/********************  Bit definition for USB_OTG_GINTSTS register  ********************/
#define USB_OTG_GINTSTS_CMOD_Pos                 (0U)
#define USB_OTG_GINTSTS_CMOD_Msk                 (0x1UL << USB_OTG_GINTSTS_CMOD_Pos)/*!< 0x00000001 */
#define USB_OTG_GINTSTS_CMOD                     USB_OTG_GINTSTS_CMOD_Msk	/*!< Current mode of operation                      */
#define USB_OTG_GINTSTS_MMIS_Pos                 (1U)
#define USB_OTG_GINTSTS_MMIS_Msk                 (0x1UL << USB_OTG_GINTSTS_MMIS_Pos)/*!< 0x00000002 */
#define USB_OTG_GINTSTS_MMIS                     USB_OTG_GINTSTS_MMIS_Msk	/*!< Mode mismatch interrupt                        */
#define USB_OTG_GINTSTS_OTGINT_Pos               (2U)
#define USB_OTG_GINTSTS_OTGINT_Msk               (0x1UL << USB_OTG_GINTSTS_OTGINT_Pos)	/*!< 0x00000004 */
#define USB_OTG_GINTSTS_OTGINT                   USB_OTG_GINTSTS_OTGINT_Msk				/*!< OTG interrupt                                  */
#define USB_OTG_GINTSTS_SOF_Pos                  (3U)
#define USB_OTG_GINTSTS_SOF_Msk                  (0x1UL << USB_OTG_GINTSTS_SOF_Pos)	/*!< 0x00000008 */
#define USB_OTG_GINTSTS_SOF                      USB_OTG_GINTSTS_SOF_Msk/*!< Start of frame                                 */
#define USB_OTG_GINTSTS_RXFLVL_Pos               (4U)
#define USB_OTG_GINTSTS_RXFLVL_Msk               (0x1UL << USB_OTG_GINTSTS_RXFLVL_Pos)	/*!< 0x00000010 */
#define USB_OTG_GINTSTS_RXFLVL                   USB_OTG_GINTSTS_RXFLVL_Msk				/*!< RxFIFO nonempty                                */
#define USB_OTG_GINTSTS_NPTXFE_Pos               (5U)
#define USB_OTG_GINTSTS_NPTXFE_Msk               (0x1UL << USB_OTG_GINTSTS_NPTXFE_Pos)	/*!< 0x00000020 */
#define USB_OTG_GINTSTS_NPTXFE                   USB_OTG_GINTSTS_NPTXFE_Msk				/*!< Nonperiodic TxFIFO empty                       */
#define USB_OTG_GINTSTS_GINAKEFF_Pos             (6U)
#define USB_OTG_GINTSTS_GINAKEFF_Msk             (0x1UL << USB_OTG_GINTSTS_GINAKEFF_Pos)/*!< 0x00000040 */
#define USB_OTG_GINTSTS_GINAKEFF                 USB_OTG_GINTSTS_GINAKEFF_Msk	/*!< Global IN nonperiodic NAK effective            */
#define USB_OTG_GINTSTS_BOUTNAKEFF_Pos           (7U)
#define USB_OTG_GINTSTS_BOUTNAKEFF_Msk           (0x1UL << USB_OTG_GINTSTS_BOUTNAKEFF_Pos)	/*!< 0x00000080 */
#define USB_OTG_GINTSTS_BOUTNAKEFF               USB_OTG_GINTSTS_BOUTNAKEFF_Msk				/*!< Global OUT NAK effective                       */
#define USB_OTG_GINTSTS_ESUSP_Pos                (10U)
#define USB_OTG_GINTSTS_ESUSP_Msk                (0x1UL << USB_OTG_GINTSTS_ESUSP_Pos)	/*!< 0x00000400 */
#define USB_OTG_GINTSTS_ESUSP                    USB_OTG_GINTSTS_ESUSP_Msk				/*!< Early suspend                                  */
#define USB_OTG_GINTSTS_USBSUSP_Pos              (11U)
#define USB_OTG_GINTSTS_USBSUSP_Msk              (0x1UL << USB_OTG_GINTSTS_USBSUSP_Pos)	/*!< 0x00000800 */
#define USB_OTG_GINTSTS_USBSUSP                  USB_OTG_GINTSTS_USBSUSP_Msk/*!< USB suspend                                    */
#define USB_OTG_GINTSTS_USBRST_Pos               (12U)
#define USB_OTG_GINTSTS_USBRST_Msk               (0x1UL << USB_OTG_GINTSTS_USBRST_Pos)	/*!< 0x00001000 */
#define USB_OTG_GINTSTS_USBRST                   USB_OTG_GINTSTS_USBRST_Msk				/*!< USB reset                                      */
#define USB_OTG_GINTSTS_ENUMDNE_Pos              (13U)
#define USB_OTG_GINTSTS_ENUMDNE_Msk              (0x1UL << USB_OTG_GINTSTS_ENUMDNE_Pos)	/*!< 0x00002000 */
#define USB_OTG_GINTSTS_ENUMDNE                  USB_OTG_GINTSTS_ENUMDNE_Msk/*!< Enumeration done                               */
#define USB_OTG_GINTSTS_ISOODRP_Pos              (14U)
#define USB_OTG_GINTSTS_ISOODRP_Msk              (0x1UL << USB_OTG_GINTSTS_ISOODRP_Pos)	/*!< 0x00004000 */
#define USB_OTG_GINTSTS_ISOODRP                  USB_OTG_GINTSTS_ISOODRP_Msk/*!< Isochronous OUT packet dropped interrupt       */
#define USB_OTG_GINTSTS_EOPF_Pos                 (15U)
#define USB_OTG_GINTSTS_EOPF_Msk                 (0x1UL << USB_OTG_GINTSTS_EOPF_Pos)/*!< 0x00008000 */
#define USB_OTG_GINTSTS_EOPF                     USB_OTG_GINTSTS_EOPF_Msk	/*!< End of periodic frame interrupt                */
#define USB_OTG_GINTSTS_IEPINT_Pos               (18U)
#define USB_OTG_GINTSTS_IEPINT_Msk               (0x1UL << USB_OTG_GINTSTS_IEPINT_Pos)	/*!< 0x00040000 */
#define USB_OTG_GINTSTS_IEPINT                   USB_OTG_GINTSTS_IEPINT_Msk				/*!< IN endpoint interrupt                          */
#define USB_OTG_GINTSTS_OEPINT_Pos               (19U)
#define USB_OTG_GINTSTS_OEPINT_Msk               (0x1UL << USB_OTG_GINTSTS_OEPINT_Pos)	/*!< 0x00080000 */
#define USB_OTG_GINTSTS_OEPINT                   USB_OTG_GINTSTS_OEPINT_Msk				/*!< OUT endpoint interrupt                         */
#define USB_OTG_GINTSTS_IISOIXFR_Pos             (20U)
#define USB_OTG_GINTSTS_IISOIXFR_Msk             (0x1UL << USB_OTG_GINTSTS_IISOIXFR_Pos)/*!< 0x00100000 */
#define USB_OTG_GINTSTS_IISOIXFR                 USB_OTG_GINTSTS_IISOIXFR_Msk	/*!< Incomplete isochronous IN transfer             */
#define USB_OTG_GINTSTS_PXFR_INCOMPISOOUT_Pos    (21U)
#define USB_OTG_GINTSTS_PXFR_INCOMPISOOUT_Msk    (0x1UL << USB_OTG_GINTSTS_PXFR_INCOMPISOOUT_Pos)	/*!< 0x00200000 */
#define USB_OTG_GINTSTS_PXFR_INCOMPISOOUT        USB_OTG_GINTSTS_PXFR_INCOMPISOOUT_Msk				/*!< Incomplete periodic transfer                   */
#define USB_OTG_GINTSTS_DATAFSUSP_Pos            (22U)
#define USB_OTG_GINTSTS_DATAFSUSP_Msk            (0x1UL << USB_OTG_GINTSTS_DATAFSUSP_Pos)	/*!< 0x00400000 */
#define USB_OTG_GINTSTS_DATAFSUSP                USB_OTG_GINTSTS_DATAFSUSP_Msk				/*!< Data fetch suspended                           */
#define USB_OTG_GINTSTS_RSTDET_Pos               (23U)
#define USB_OTG_GINTSTS_RSTDET_Msk               (0x1UL << USB_OTG_GINTSTS_RSTDET_Pos)	/*!< 0x00800000 */
#define USB_OTG_GINTSTS_RSTDET                   USB_OTG_GINTSTS_RSTDET_Msk				/*!< Reset detected interrupt                       */
#define USB_OTG_GINTSTS_HPRTINT_Pos              (24U)
#define USB_OTG_GINTSTS_HPRTINT_Msk              (0x1UL << USB_OTG_GINTSTS_HPRTINT_Pos)	/*!< 0x01000000 */
#define USB_OTG_GINTSTS_HPRTINT                  USB_OTG_GINTSTS_HPRTINT_Msk/*!< Host port interrupt                            */
#define USB_OTG_GINTSTS_HCINT_Pos                (25U)
#define USB_OTG_GINTSTS_HCINT_Msk                (0x1UL << USB_OTG_GINTSTS_HCINT_Pos)	/*!< 0x02000000 */
#define USB_OTG_GINTSTS_HCINT                    USB_OTG_GINTSTS_HCINT_Msk				/*!< Host channels interrupt                        */
#define USB_OTG_GINTSTS_PTXFE_Pos                (26U)
#define USB_OTG_GINTSTS_PTXFE_Msk                (0x1UL << USB_OTG_GINTSTS_PTXFE_Pos)	/*!< 0x04000000 */
#define USB_OTG_GINTSTS_PTXFE                    USB_OTG_GINTSTS_PTXFE_Msk				/*!< Periodic TxFIFO empty                          */
#define USB_OTG_GINTSTS_LPMINT_Pos               (27U)
#define USB_OTG_GINTSTS_LPMINT_Msk               (0x1UL << USB_OTG_GINTSTS_LPMINT_Pos)	/*!< 0x08000000 */
#define USB_OTG_GINTSTS_LPMINT                   USB_OTG_GINTSTS_LPMINT_Msk				/*!< LPM interrupt                                  */
#define USB_OTG_GINTSTS_CIDSCHG_Pos              (28U)
#define USB_OTG_GINTSTS_CIDSCHG_Msk              (0x1UL << USB_OTG_GINTSTS_CIDSCHG_Pos)	/*!< 0x10000000 */
#define USB_OTG_GINTSTS_CIDSCHG                  USB_OTG_GINTSTS_CIDSCHG_Msk/*!< Connector ID status change                     */
#define USB_OTG_GINTSTS_DISCINT_Pos              (29U)
#define USB_OTG_GINTSTS_DISCINT_Msk              (0x1UL << USB_OTG_GINTSTS_DISCINT_Pos)	/*!< 0x20000000 */
#define USB_OTG_GINTSTS_DISCINT                  USB_OTG_GINTSTS_DISCINT_Msk/*!< Disconnect detected interrupt                  */
#define USB_OTG_GINTSTS_SRQINT_Pos               (30U)
#define USB_OTG_GINTSTS_SRQINT_Msk               (0x1UL << USB_OTG_GINTSTS_SRQINT_Pos)	/*!< 0x40000000 */
#define USB_OTG_GINTSTS_SRQINT                   USB_OTG_GINTSTS_SRQINT_Msk				/*!< Session request/new session detected interrupt */
#define USB_OTG_GINTSTS_WKUINT_Pos               (31U)
#define USB_OTG_GINTSTS_WKUINT_Msk               (0x1UL << USB_OTG_GINTSTS_WKUINT_Pos)	/*!< 0x80000000 */
#define USB_OTG_GINTSTS_WKUINT                   USB_OTG_GINTSTS_WKUINT_Msk				/*!< Resume/remote wakeup detected interrupt        */

/********************  Bit definition for USB_OTG_GINTMSK register  ********************/
#define USB_OTG_GINTMSK_MMISM_Pos              (1U)
#define USB_OTG_GINTMSK_MMISM_Msk              (0x1UL << USB_OTG_GINTMSK_MMISM_Pos)	/*!< 0x00000002 */
#define USB_OTG_GINTMSK_MMISM                  USB_OTG_GINTMSK_MMISM_Msk/*!< Mode mismatch interrupt mask                        */
#define USB_OTG_GINTMSK_OTGINT_Pos             (2U)
#define USB_OTG_GINTMSK_OTGINT_Msk             (0x1UL << USB_OTG_GINTMSK_OTGINT_Pos)/*!< 0x00000004 */
#define USB_OTG_GINTMSK_OTGINT                 USB_OTG_GINTMSK_OTGINT_Msk	/*!< OTG interrupt mask                                  */
#define USB_OTG_GINTMSK_SOFM_Pos               (3U)
#define USB_OTG_GINTMSK_SOFM_Msk               (0x1UL << USB_OTG_GINTMSK_SOFM_Pos)	/*!< 0x00000008 */
#define USB_OTG_GINTMSK_SOFM                   USB_OTG_GINTMSK_SOFM_Msk				/*!< Start of frame mask                                 */
#define USB_OTG_GINTMSK_RXFLVLM_Pos            (4U)
#define USB_OTG_GINTMSK_RXFLVLM_Msk            (0x1UL << USB_OTG_GINTMSK_RXFLVLM_Pos)	/*!< 0x00000010 */
#define USB_OTG_GINTMSK_RXFLVLM                USB_OTG_GINTMSK_RXFLVLM_Msk				/*!< Receive FIFO nonempty mask                          */
#define USB_OTG_GINTMSK_NPTXFEM_Pos            (5U)
#define USB_OTG_GINTMSK_NPTXFEM_Msk            (0x1UL << USB_OTG_GINTMSK_NPTXFEM_Pos)	/*!< 0x00000020 */
#define USB_OTG_GINTMSK_NPTXFEM                USB_OTG_GINTMSK_NPTXFEM_Msk				/*!< Nonperiodic TxFIFO empty mask                       */
#define USB_OTG_GINTMSK_GINAKEFFM_Pos          (6U)
#define USB_OTG_GINTMSK_GINAKEFFM_Msk          (0x1UL << USB_OTG_GINTMSK_GINAKEFFM_Pos)	/*!< 0x00000040 */
#define USB_OTG_GINTMSK_GINAKEFFM              USB_OTG_GINTMSK_GINAKEFFM_Msk/*!< Global nonperiodic IN NAK effective mask            */
#define USB_OTG_GINTMSK_GONAKEFFM_Pos          (7U)
#define USB_OTG_GINTMSK_GONAKEFFM_Msk          (0x1UL << USB_OTG_GINTMSK_GONAKEFFM_Pos)	/*!< 0x00000080 */
#define USB_OTG_GINTMSK_GONAKEFFM              USB_OTG_GINTMSK_GONAKEFFM_Msk/*!< Global OUT NAK effective mask                       */
#define USB_OTG_GINTMSK_ESUSPM_Pos             (10U)
#define USB_OTG_GINTMSK_ESUSPM_Msk             (0x1UL << USB_OTG_GINTMSK_ESUSPM_Pos)/*!< 0x00000400 */
#define USB_OTG_GINTMSK_ESUSPM                 USB_OTG_GINTMSK_ESUSPM_Msk	/*!< Early suspend mask                                  */
#define USB_OTG_GINTMSK_USBSUSPM_Pos           (11U)
#define USB_OTG_GINTMSK_USBSUSPM_Msk           (0x1UL << USB_OTG_GINTMSK_USBSUSPM_Pos)	/*!< 0x00000800 */
#define USB_OTG_GINTMSK_USBSUSPM               USB_OTG_GINTMSK_USBSUSPM_Msk				/*!< USB suspend mask                                    */
#define USB_OTG_GINTMSK_USBRST_Pos             (12U)
#define USB_OTG_GINTMSK_USBRST_Msk             (0x1UL << USB_OTG_GINTMSK_USBRST_Pos)/*!< 0x00001000 */
#define USB_OTG_GINTMSK_USBRST                 USB_OTG_GINTMSK_USBRST_Msk	/*!< USB reset mask                                      */
#define USB_OTG_GINTMSK_ENUMDNEM_Pos           (13U)
#define USB_OTG_GINTMSK_ENUMDNEM_Msk           (0x1UL << USB_OTG_GINTMSK_ENUMDNEM_Pos)	/*!< 0x00002000 */
#define USB_OTG_GINTMSK_ENUMDNEM               USB_OTG_GINTMSK_ENUMDNEM_Msk				/*!< Enumeration done mask                               */
#define USB_OTG_GINTMSK_ISOODRPM_Pos           (14U)
#define USB_OTG_GINTMSK_ISOODRPM_Msk           (0x1UL << USB_OTG_GINTMSK_ISOODRPM_Pos)	/*!< 0x00004000 */
#define USB_OTG_GINTMSK_ISOODRPM               USB_OTG_GINTMSK_ISOODRPM_Msk				/*!< Isochronous OUT packet dropped interrupt mask       */
#define USB_OTG_GINTMSK_EOPFM_Pos              (15U)
#define USB_OTG_GINTMSK_EOPFM_Msk              (0x1UL << USB_OTG_GINTMSK_EOPFM_Pos)	/*!< 0x00008000 */
#define USB_OTG_GINTMSK_EOPFM                  USB_OTG_GINTMSK_EOPFM_Msk/*!< End of periodic frame interrupt mask                */
#define USB_OTG_GINTMSK_EPMISM_Pos             (17U)
#define USB_OTG_GINTMSK_EPMISM_Msk             (0x1UL << USB_OTG_GINTMSK_EPMISM_Pos)/*!< 0x00020000 */
#define USB_OTG_GINTMSK_EPMISM                 USB_OTG_GINTMSK_EPMISM_Msk	/*!< Endpoint mismatch interrupt mask                    */
#define USB_OTG_GINTMSK_IEPINT_Pos             (18U)
#define USB_OTG_GINTMSK_IEPINT_Msk             (0x1UL << USB_OTG_GINTMSK_IEPINT_Pos)/*!< 0x00040000 */
#define USB_OTG_GINTMSK_IEPINT                 USB_OTG_GINTMSK_IEPINT_Msk	/*!< IN endpoints interrupt mask                         */
#define USB_OTG_GINTMSK_OEPINT_Pos             (19U)
#define USB_OTG_GINTMSK_OEPINT_Msk             (0x1UL << USB_OTG_GINTMSK_OEPINT_Pos)/*!< 0x00080000 */
#define USB_OTG_GINTMSK_OEPINT                 USB_OTG_GINTMSK_OEPINT_Msk	/*!< OUT endpoints interrupt mask                        */
#define USB_OTG_GINTMSK_IISOIXFRM_Pos          (20U)
#define USB_OTG_GINTMSK_IISOIXFRM_Msk          (0x1UL << USB_OTG_GINTMSK_IISOIXFRM_Pos)	/*!< 0x00100000 */
#define USB_OTG_GINTMSK_IISOIXFRM              USB_OTG_GINTMSK_IISOIXFRM_Msk/*!< Incomplete isochronous IN transfer mask             */
#define USB_OTG_GINTMSK_PXFRM_IISOOXFRM_Pos    (21U)
#define USB_OTG_GINTMSK_PXFRM_IISOOXFRM_Msk    (0x1UL << USB_OTG_GINTMSK_PXFRM_IISOOXFRM_Pos)	/*!< 0x00200000 */
#define USB_OTG_GINTMSK_PXFRM_IISOOXFRM        USB_OTG_GINTMSK_PXFRM_IISOOXFRM_Msk				/*!< Incomplete periodic transfer mask                   */
#define USB_OTG_GINTMSK_FSUSPM_Pos             (22U)
#define USB_OTG_GINTMSK_FSUSPM_Msk             (0x1UL << USB_OTG_GINTMSK_FSUSPM_Pos)/*!< 0x00400000 */
#define USB_OTG_GINTMSK_FSUSPM                 USB_OTG_GINTMSK_FSUSPM_Msk	/*!< Data fetch suspended mask                           */
#define USB_OTG_GINTMSK_RSTDEM_Pos             (23U)
#define USB_OTG_GINTMSK_RSTDEM_Msk             (0x1UL << USB_OTG_GINTMSK_RSTDEM_Pos)/*!< 0x00800000 */
#define USB_OTG_GINTMSK_RSTDEM                 USB_OTG_GINTMSK_RSTDEM_Msk	/*!< Reset detected interrupt mask                       */
#define USB_OTG_GINTMSK_PRTIM_Pos              (24U)
#define USB_OTG_GINTMSK_PRTIM_Msk              (0x1UL << USB_OTG_GINTMSK_PRTIM_Pos)	/*!< 0x01000000 */
#define USB_OTG_GINTMSK_PRTIM                  USB_OTG_GINTMSK_PRTIM_Msk/*!< Host port interrupt mask                            */
#define USB_OTG_GINTMSK_HCIM_Pos               (25U)
#define USB_OTG_GINTMSK_HCIM_Msk               (0x1UL << USB_OTG_GINTMSK_HCIM_Pos)	/*!< 0x02000000 */
#define USB_OTG_GINTMSK_HCIM                   USB_OTG_GINTMSK_HCIM_Msk				/*!< Host channels interrupt mask                        */
#define USB_OTG_GINTMSK_PTXFEM_Pos             (26U)
#define USB_OTG_GINTMSK_PTXFEM_Msk             (0x1UL << USB_OTG_GINTMSK_PTXFEM_Pos)/*!< 0x04000000 */
#define USB_OTG_GINTMSK_PTXFEM                 USB_OTG_GINTMSK_PTXFEM_Msk	/*!< Periodic TxFIFO empty mask                          */
#define USB_OTG_GINTMSK_LPMINTM_Pos            (27U)
#define USB_OTG_GINTMSK_LPMINTM_Msk            (0x1UL << USB_OTG_GINTMSK_LPMINTM_Pos)	/*!< 0x08000000 */
#define USB_OTG_GINTMSK_LPMINTM                USB_OTG_GINTMSK_LPMINTM_Msk				/*!< LPM interrupt Mask                                  */
#define USB_OTG_GINTMSK_CIDSCHGM_Pos           (28U)
#define USB_OTG_GINTMSK_CIDSCHGM_Msk           (0x1UL << USB_OTG_GINTMSK_CIDSCHGM_Pos)	/*!< 0x10000000 */
#define USB_OTG_GINTMSK_CIDSCHGM               USB_OTG_GINTMSK_CIDSCHGM_Msk				/*!< Connector ID status change mask                     */
#define USB_OTG_GINTMSK_DISCINT_Pos            (29U)
#define USB_OTG_GINTMSK_DISCINT_Msk            (0x1UL << USB_OTG_GINTMSK_DISCINT_Pos)	/*!< 0x20000000 */
#define USB_OTG_GINTMSK_DISCINT                USB_OTG_GINTMSK_DISCINT_Msk				/*!< Disconnect detected interrupt mask                  */
#define USB_OTG_GINTMSK_SRQIM_Pos              (30U)
#define USB_OTG_GINTMSK_SRQIM_Msk              (0x1UL << USB_OTG_GINTMSK_SRQIM_Pos)	/*!< 0x40000000 */
#define USB_OTG_GINTMSK_SRQIM                  USB_OTG_GINTMSK_SRQIM_Msk/*!< Session request/new session detected interrupt mask */
#define USB_OTG_GINTMSK_WUIM_Pos               (31U)
#define USB_OTG_GINTMSK_WUIM_Msk               (0x1UL << USB_OTG_GINTMSK_WUIM_Pos)	/*!< 0x80000000 */
#define USB_OTG_GINTMSK_WUIM                   USB_OTG_GINTMSK_WUIM_Msk				/*!< Resume/remote wakeup detected interrupt mask        */

/********************  Bit definition for USB_OTG_DAINT register  ********************/
#define USB_OTG_DAINT_IEPINT_Pos    (0U)
#define USB_OTG_DAINT_IEPINT_Msk    (0xFFFFUL << USB_OTG_DAINT_IEPINT_Pos)	/*!< 0x0000FFFF */
#define USB_OTG_DAINT_IEPINT        USB_OTG_DAINT_IEPINT_Msk				/*!< IN endpoint interrupt bits  */
#define USB_OTG_DAINT_OEPINT_Pos    (16U)
#define USB_OTG_DAINT_OEPINT_Msk    (0xFFFFUL << USB_OTG_DAINT_OEPINT_Pos)	/*!< 0xFFFF0000 */
#define USB_OTG_DAINT_OEPINT        USB_OTG_DAINT_OEPINT_Msk				/*!< OUT endpoint interrupt bits */

/********************  Bit definition for USB_OTG_HAINTMSK register  ********************/
#define USB_OTG_HAINTMSK_HAINTM_Pos    (0U)
#define USB_OTG_HAINTMSK_HAINTM_Msk    (0xFFFFUL << USB_OTG_HAINTMSK_HAINTM_Pos)/*!< 0x0000FFFF */
#define USB_OTG_HAINTMSK_HAINTM        USB_OTG_HAINTMSK_HAINTM_Msk	/*!< Channel interrupt mask */

/********************  Bit definition for USB_OTG_GRXSTSP register  ********************/
#define USB_OTG_GRXSTSP_EPNUM_Pos     (0U)
#define USB_OTG_GRXSTSP_EPNUM_Msk     (0xFUL << USB_OTG_GRXSTSP_EPNUM_Pos)	/*!< 0x0000000F */
#define USB_OTG_GRXSTSP_EPNUM         USB_OTG_GRXSTSP_EPNUM_Msk				/*!< IN EP interrupt mask bits  */
#define USB_OTG_GRXSTSP_BCNT_Pos      (4U)
#define USB_OTG_GRXSTSP_BCNT_Msk      (0x7FFUL << USB_OTG_GRXSTSP_BCNT_Pos)	/*!< 0x00007FF0 */
#define USB_OTG_GRXSTSP_BCNT          USB_OTG_GRXSTSP_BCNT_Msk				/*!< OUT EP interrupt mask bits */
#define USB_OTG_GRXSTSP_DPID_Pos      (15U)
#define USB_OTG_GRXSTSP_DPID_Msk      (0x3UL << USB_OTG_GRXSTSP_DPID_Pos)	/*!< 0x00018000 */
#define USB_OTG_GRXSTSP_DPID          USB_OTG_GRXSTSP_DPID_Msk				/*!< OUT EP interrupt mask bits */
#define USB_OTG_GRXSTSP_PKTSTS_Pos    (17U)
#define USB_OTG_GRXSTSP_PKTSTS_Msk    (0xFUL << USB_OTG_GRXSTSP_PKTSTS_Pos)	/*!< 0x001E0000 */
#define USB_OTG_GRXSTSP_PKTSTS        USB_OTG_GRXSTSP_PKTSTS_Msk/*!< OUT EP interrupt mask bits */

/********************  Bit definition for USB_OTG_DAINTMSK register  ********************/
#define USB_OTG_DAINTMSK_IEPM_Pos    (0U)
#define USB_OTG_DAINTMSK_IEPM_Msk    (0xFFFFUL << USB_OTG_DAINTMSK_IEPM_Pos)/*!< 0x0000FFFF */
#define USB_OTG_DAINTMSK_IEPM        USB_OTG_DAINTMSK_IEPM_Msk	/*!< IN EP interrupt mask bits */
#define USB_OTG_DAINTMSK_OEPM_Pos    (16U)
#define USB_OTG_DAINTMSK_OEPM_Msk    (0xFFFFUL << USB_OTG_DAINTMSK_OEPM_Pos)/*!< 0xFFFF0000 */
#define USB_OTG_DAINTMSK_OEPM        USB_OTG_DAINTMSK_OEPM_Msk	/*!< OUT EP interrupt mask bits */

/********************  Bit definition for OTG register  ********************/

#define USB_OTG_CHNUM_Pos     (0U)
#define USB_OTG_CHNUM_Msk     (0xFUL << USB_OTG_CHNUM_Pos)	/*!< 0x0000000F */
#define USB_OTG_CHNUM         USB_OTG_CHNUM_Msk				/*!< Channel number */
#define USB_OTG_CHNUM_0       (0x1UL << USB_OTG_CHNUM_Pos)	/*!< 0x00000001 */
#define USB_OTG_CHNUM_1       (0x2UL << USB_OTG_CHNUM_Pos)	/*!< 0x00000002 */
#define USB_OTG_CHNUM_2       (0x4UL << USB_OTG_CHNUM_Pos)	/*!< 0x00000004 */
#define USB_OTG_CHNUM_3       (0x8UL << USB_OTG_CHNUM_Pos)	/*!< 0x00000008 */
#define USB_OTG_BCNT_Pos      (4U)
#define USB_OTG_BCNT_Msk      (0x7FFUL << USB_OTG_BCNT_Pos)	/*!< 0x00007FF0 */
#define USB_OTG_BCNT          USB_OTG_BCNT_Msk				/*!< Byte count */

#define USB_OTG_DPID_Pos      (15U)
#define USB_OTG_DPID_Msk      (0x3UL << USB_OTG_DPID_Pos)	/*!< 0x00018000 */
#define USB_OTG_DPID          USB_OTG_DPID_Msk				/*!< Data PID */
#define USB_OTG_DPID_0        (0x1UL << USB_OTG_DPID_Pos)	/*!< 0x00008000 */
#define USB_OTG_DPID_1        (0x2UL << USB_OTG_DPID_Pos)	/*!< 0x00010000 */

#define USB_OTG_PKTSTS_Pos    (17U)
#define USB_OTG_PKTSTS_Msk    (0xFUL << USB_OTG_PKTSTS_Pos)	/*!< 0x001E0000 */
#define USB_OTG_PKTSTS        USB_OTG_PKTSTS_Msk/*!< Packet status */
#define USB_OTG_PKTSTS_0      (0x1UL << USB_OTG_PKTSTS_Pos)	/*!< 0x00020000 */
#define USB_OTG_PKTSTS_1      (0x2UL << USB_OTG_PKTSTS_Pos)	/*!< 0x00040000 */
#define USB_OTG_PKTSTS_2      (0x4UL << USB_OTG_PKTSTS_Pos)	/*!< 0x00080000 */
#define USB_OTG_PKTSTS_3      (0x8UL << USB_OTG_PKTSTS_Pos)	/*!< 0x00100000 */

#define USB_OTG_EPNUM_Pos     (0U)
#define USB_OTG_EPNUM_Msk     (0xFUL << USB_OTG_EPNUM_Pos)	/*!< 0x0000000F */
#define USB_OTG_EPNUM         USB_OTG_EPNUM_Msk				/*!< Endpoint number */
#define USB_OTG_EPNUM_0       (0x1UL << USB_OTG_EPNUM_Pos)	/*!< 0x00000001 */
#define USB_OTG_EPNUM_1       (0x2UL << USB_OTG_EPNUM_Pos)	/*!< 0x00000002 */
#define USB_OTG_EPNUM_2       (0x4UL << USB_OTG_EPNUM_Pos)	/*!< 0x00000004 */
#define USB_OTG_EPNUM_3       (0x8UL << USB_OTG_EPNUM_Pos)	/*!< 0x00000008 */

#define USB_OTG_FRMNUM_Pos    (21U)
#define USB_OTG_FRMNUM_Msk    (0xFUL << USB_OTG_FRMNUM_Pos)	/*!< 0x01E00000 */
#define USB_OTG_FRMNUM        USB_OTG_FRMNUM_Msk/*!< Frame number */
#define USB_OTG_FRMNUM_0      (0x1UL << USB_OTG_FRMNUM_Pos)	/*!< 0x00200000 */
#define USB_OTG_FRMNUM_1      (0x2UL << USB_OTG_FRMNUM_Pos)	/*!< 0x00400000 */
#define USB_OTG_FRMNUM_2      (0x4UL << USB_OTG_FRMNUM_Pos)	/*!< 0x00800000 */
#define USB_OTG_FRMNUM_3      (0x8UL << USB_OTG_FRMNUM_Pos)	/*!< 0x01000000 */

/********************  Bit definition for OTG register  ********************/

#define USB_OTG_CHNUM_Pos     (0U)
#define USB_OTG_CHNUM_Msk     (0xFUL << USB_OTG_CHNUM_Pos)	/*!< 0x0000000F */
#define USB_OTG_CHNUM         USB_OTG_CHNUM_Msk				/*!< Channel number */
#define USB_OTG_CHNUM_0       (0x1UL << USB_OTG_CHNUM_Pos)	/*!< 0x00000001 */
#define USB_OTG_CHNUM_1       (0x2UL << USB_OTG_CHNUM_Pos)	/*!< 0x00000002 */
#define USB_OTG_CHNUM_2       (0x4UL << USB_OTG_CHNUM_Pos)	/*!< 0x00000004 */
#define USB_OTG_CHNUM_3       (0x8UL << USB_OTG_CHNUM_Pos)	/*!< 0x00000008 */
#define USB_OTG_BCNT_Pos      (4U)
#define USB_OTG_BCNT_Msk      (0x7FFUL << USB_OTG_BCNT_Pos)	/*!< 0x00007FF0 */
#define USB_OTG_BCNT          USB_OTG_BCNT_Msk				/*!< Byte count */

#define USB_OTG_DPID_Pos      (15U)
#define USB_OTG_DPID_Msk      (0x3UL << USB_OTG_DPID_Pos)	/*!< 0x00018000 */
#define USB_OTG_DPID          USB_OTG_DPID_Msk				/*!< Data PID */
#define USB_OTG_DPID_0        (0x1UL << USB_OTG_DPID_Pos)	/*!< 0x00008000 */
#define USB_OTG_DPID_1        (0x2UL << USB_OTG_DPID_Pos)	/*!< 0x00010000 */

#define USB_OTG_PKTSTS_Pos    (17U)
#define USB_OTG_PKTSTS_Msk    (0xFUL << USB_OTG_PKTSTS_Pos)	/*!< 0x001E0000 */
#define USB_OTG_PKTSTS        USB_OTG_PKTSTS_Msk/*!< Packet status */
#define USB_OTG_PKTSTS_0      (0x1UL << USB_OTG_PKTSTS_Pos)	/*!< 0x00020000 */
#define USB_OTG_PKTSTS_1      (0x2UL << USB_OTG_PKTSTS_Pos)	/*!< 0x00040000 */
#define USB_OTG_PKTSTS_2      (0x4UL << USB_OTG_PKTSTS_Pos)	/*!< 0x00080000 */
#define USB_OTG_PKTSTS_3      (0x8UL << USB_OTG_PKTSTS_Pos)	/*!< 0x00100000 */

#define USB_OTG_EPNUM_Pos     (0U)
#define USB_OTG_EPNUM_Msk     (0xFUL << USB_OTG_EPNUM_Pos)	/*!< 0x0000000F */
#define USB_OTG_EPNUM         USB_OTG_EPNUM_Msk				/*!< Endpoint number */
#define USB_OTG_EPNUM_0       (0x1UL << USB_OTG_EPNUM_Pos)	/*!< 0x00000001 */
#define USB_OTG_EPNUM_1       (0x2UL << USB_OTG_EPNUM_Pos)	/*!< 0x00000002 */
#define USB_OTG_EPNUM_2       (0x4UL << USB_OTG_EPNUM_Pos)	/*!< 0x00000004 */
#define USB_OTG_EPNUM_3       (0x8UL << USB_OTG_EPNUM_Pos)	/*!< 0x00000008 */

#define USB_OTG_FRMNUM_Pos    (21U)
#define USB_OTG_FRMNUM_Msk    (0xFUL << USB_OTG_FRMNUM_Pos)	/*!< 0x01E00000 */
#define USB_OTG_FRMNUM        USB_OTG_FRMNUM_Msk/*!< Frame number */
#define USB_OTG_FRMNUM_0      (0x1UL << USB_OTG_FRMNUM_Pos)	/*!< 0x00200000 */
#define USB_OTG_FRMNUM_1      (0x2UL << USB_OTG_FRMNUM_Pos)	/*!< 0x00400000 */
#define USB_OTG_FRMNUM_2      (0x4UL << USB_OTG_FRMNUM_Pos)	/*!< 0x00800000 */
#define USB_OTG_FRMNUM_3      (0x8UL << USB_OTG_FRMNUM_Pos)	/*!< 0x01000000 */

/********************  Bit definition for USB_OTG_GRXFSIZ register  ********************/
#define USB_OTG_GRXFSIZ_RXFD_Pos    (0U)
#define USB_OTG_GRXFSIZ_RXFD_Msk    (0xFFFFUL << USB_OTG_GRXFSIZ_RXFD_Pos)	/*!< 0x0000FFFF */
#define USB_OTG_GRXFSIZ_RXFD        USB_OTG_GRXFSIZ_RXFD_Msk				/*!< RxFIFO depth */

/********************  Bit definition for USB_OTG_DVBUSDIS register  ********************/
#define USB_OTG_DVBUSDIS_VBUSDT_Pos    (0U)
#define USB_OTG_DVBUSDIS_VBUSDT_Msk    (0xFFFFUL << USB_OTG_DVBUSDIS_VBUSDT_Pos)/*!< 0x0000FFFF */
#define USB_OTG_DVBUSDIS_VBUSDT        USB_OTG_DVBUSDIS_VBUSDT_Msk	/*!< Device VBUS discharge time */

/********************  Bit definition for OTG register  ********************/
#define USB_OTG_NPTXFSA_Pos    (0U)
#define USB_OTG_NPTXFSA_Msk    (0xFFFFUL << USB_OTG_NPTXFSA_Pos)/*!< 0x0000FFFF */
#define USB_OTG_NPTXFSA        USB_OTG_NPTXFSA_Msk	/*!< Nonperiodic transmit RAM start address */
#define USB_OTG_NPTXFD_Pos     (16U)
#define USB_OTG_NPTXFD_Msk     (0xFFFFUL << USB_OTG_NPTXFD_Pos)	/*!< 0xFFFF0000 */
#define USB_OTG_NPTXFD         USB_OTG_NPTXFD_Msk				/*!< Nonperiodic TxFIFO depth               */
#define USB_OTG_TX0FSA_Pos     (0U)
#define USB_OTG_TX0FSA_Msk     (0xFFFFUL << USB_OTG_TX0FSA_Pos)	/*!< 0x0000FFFF */
#define USB_OTG_TX0FSA         USB_OTG_TX0FSA_Msk				/*!< Endpoint 0 transmit RAM start address  */
#define USB_OTG_TX0FD_Pos      (16U)
#define USB_OTG_TX0FD_Msk      (0xFFFFUL << USB_OTG_TX0FD_Pos)	/*!< 0xFFFF0000 */
#define USB_OTG_TX0FD          USB_OTG_TX0FD_Msk				/*!< Endpoint 0 TxFIFO depth                */

/********************  Bit definition for USB_OTG_DVBUSPULSE register  ********************/
#define USB_OTG_DVBUSPULSE_DVBUSP_Pos    (0U)
#define USB_OTG_DVBUSPULSE_DVBUSP_Msk    (0xFFFUL << USB_OTG_DVBUSPULSE_DVBUSP_Pos)	/*!< 0x00000FFF */
#define USB_OTG_DVBUSPULSE_DVBUSP        USB_OTG_DVBUSPULSE_DVBUSP_Msk				/*!< Device VBUS pulsing time */

/********************  Bit definition for USB_OTG_GNPTXSTS register  ********************/
#define USB_OTG_GNPTXSTS_NPTXFSAV_Pos    (0U)
#define USB_OTG_GNPTXSTS_NPTXFSAV_Msk    (0xFFFFUL << USB_OTG_GNPTXSTS_NPTXFSAV_Pos)/*!< 0x0000FFFF */
#define USB_OTG_GNPTXSTS_NPTXFSAV        USB_OTG_GNPTXSTS_NPTXFSAV_Msk	/*!< Nonperiodic TxFIFO space available */

#define USB_OTG_GNPTXSTS_NPTQXSAV_Pos    (16U)
#define USB_OTG_GNPTXSTS_NPTQXSAV_Msk    (0xFFUL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos)	/*!< 0x00FF0000 */
#define USB_OTG_GNPTXSTS_NPTQXSAV        USB_OTG_GNPTXSTS_NPTQXSAV_Msk				/*!< Nonperiodic transmit request queue space available */
#define USB_OTG_GNPTXSTS_NPTQXSAV_0      (0x01UL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos)	/*!< 0x00010000 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_1      (0x02UL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos)	/*!< 0x00020000 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_2      (0x04UL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos)	/*!< 0x00040000 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_3      (0x08UL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos)	/*!< 0x00080000 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_4      (0x10UL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos)	/*!< 0x00100000 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_5      (0x20UL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos)	/*!< 0x00200000 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_6      (0x40UL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos)	/*!< 0x00400000 */
#define USB_OTG_GNPTXSTS_NPTQXSAV_7      (0x80UL << USB_OTG_GNPTXSTS_NPTQXSAV_Pos)	/*!< 0x00800000 */

#define USB_OTG_GNPTXSTS_NPTXQTOP_Pos    (24U)
#define USB_OTG_GNPTXSTS_NPTXQTOP_Msk    (0x7FUL << USB_OTG_GNPTXSTS_NPTXQTOP_Pos)	/*!< 0x7F000000 */
#define USB_OTG_GNPTXSTS_NPTXQTOP        USB_OTG_GNPTXSTS_NPTXQTOP_Msk				/*!< Top of the nonperiodic transmit request queue */
#define USB_OTG_GNPTXSTS_NPTXQTOP_0      (0x01UL << USB_OTG_GNPTXSTS_NPTXQTOP_Pos)	/*!< 0x01000000 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_1      (0x02UL << USB_OTG_GNPTXSTS_NPTXQTOP_Pos)	/*!< 0x02000000 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_2      (0x04UL << USB_OTG_GNPTXSTS_NPTXQTOP_Pos)	/*!< 0x04000000 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_3      (0x08UL << USB_OTG_GNPTXSTS_NPTXQTOP_Pos)	/*!< 0x08000000 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_4      (0x10UL << USB_OTG_GNPTXSTS_NPTXQTOP_Pos)	/*!< 0x10000000 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_5      (0x20UL << USB_OTG_GNPTXSTS_NPTXQTOP_Pos)	/*!< 0x20000000 */
#define USB_OTG_GNPTXSTS_NPTXQTOP_6      (0x40UL << USB_OTG_GNPTXSTS_NPTXQTOP_Pos)	/*!< 0x40000000 */

/********************  Bit definition for USB_OTG_DTHRCTL register  ********************/
#define USB_OTG_DTHRCTL_NONISOTHREN_Pos    (0U)
#define USB_OTG_DTHRCTL_NONISOTHREN_Msk    (0x1UL << USB_OTG_DTHRCTL_NONISOTHREN_Pos)	/*!< 0x00000001 */
#define USB_OTG_DTHRCTL_NONISOTHREN        USB_OTG_DTHRCTL_NONISOTHREN_Msk				/*!< Nonisochronous IN endpoints threshold enable */
#define USB_OTG_DTHRCTL_ISOTHREN_Pos       (1U)
#define USB_OTG_DTHRCTL_ISOTHREN_Msk       (0x1UL << USB_OTG_DTHRCTL_ISOTHREN_Pos)	/*!< 0x00000002 */
#define USB_OTG_DTHRCTL_ISOTHREN           USB_OTG_DTHRCTL_ISOTHREN_Msk				/*!< ISO IN endpoint threshold enable */

#define USB_OTG_DTHRCTL_TXTHRLEN_Pos       (2U)
#define USB_OTG_DTHRCTL_TXTHRLEN_Msk       (0x1FFUL << USB_OTG_DTHRCTL_TXTHRLEN_Pos)/*!< 0x000007FC */
#define USB_OTG_DTHRCTL_TXTHRLEN           USB_OTG_DTHRCTL_TXTHRLEN_Msk	/*!< Transmit threshold length */
#define USB_OTG_DTHRCTL_TXTHRLEN_0         (0x001UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos)/*!< 0x00000004 */
#define USB_OTG_DTHRCTL_TXTHRLEN_1         (0x002UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos)/*!< 0x00000008 */
#define USB_OTG_DTHRCTL_TXTHRLEN_2         (0x004UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos)/*!< 0x00000010 */
#define USB_OTG_DTHRCTL_TXTHRLEN_3         (0x008UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos)/*!< 0x00000020 */
#define USB_OTG_DTHRCTL_TXTHRLEN_4         (0x010UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos)/*!< 0x00000040 */
#define USB_OTG_DTHRCTL_TXTHRLEN_5         (0x020UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos)/*!< 0x00000080 */
#define USB_OTG_DTHRCTL_TXTHRLEN_6         (0x040UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos)/*!< 0x00000100 */
#define USB_OTG_DTHRCTL_TXTHRLEN_7         (0x080UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos)/*!< 0x00000200 */
#define USB_OTG_DTHRCTL_TXTHRLEN_8         (0x100UL << USB_OTG_DTHRCTL_TXTHRLEN_Pos)/*!< 0x00000400 */
#define USB_OTG_DTHRCTL_RXTHREN_Pos        (16U)
#define USB_OTG_DTHRCTL_RXTHREN_Msk        (0x1UL << USB_OTG_DTHRCTL_RXTHREN_Pos)	/*!< 0x00010000 */
#define USB_OTG_DTHRCTL_RXTHREN            USB_OTG_DTHRCTL_RXTHREN_Msk				/*!< Receive threshold enable */

#define USB_OTG_DTHRCTL_RXTHRLEN_Pos       (17U)
#define USB_OTG_DTHRCTL_RXTHRLEN_Msk       (0x1FFUL << USB_OTG_DTHRCTL_RXTHRLEN_Pos)/*!< 0x03FE0000 */
#define USB_OTG_DTHRCTL_RXTHRLEN           USB_OTG_DTHRCTL_RXTHRLEN_Msk	/*!< Receive threshold length */
#define USB_OTG_DTHRCTL_RXTHRLEN_0         (0x001UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos)/*!< 0x00020000 */
#define USB_OTG_DTHRCTL_RXTHRLEN_1         (0x002UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos)/*!< 0x00040000 */
#define USB_OTG_DTHRCTL_RXTHRLEN_2         (0x004UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos)/*!< 0x00080000 */
#define USB_OTG_DTHRCTL_RXTHRLEN_3         (0x008UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos)/*!< 0x00100000 */
#define USB_OTG_DTHRCTL_RXTHRLEN_4         (0x010UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos)/*!< 0x00200000 */
#define USB_OTG_DTHRCTL_RXTHRLEN_5         (0x020UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos)/*!< 0x00400000 */
#define USB_OTG_DTHRCTL_RXTHRLEN_6         (0x040UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos)/*!< 0x00800000 */
#define USB_OTG_DTHRCTL_RXTHRLEN_7         (0x080UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos)/*!< 0x01000000 */
#define USB_OTG_DTHRCTL_RXTHRLEN_8         (0x100UL << USB_OTG_DTHRCTL_RXTHRLEN_Pos)/*!< 0x02000000 */
#define USB_OTG_DTHRCTL_ARPEN_Pos          (27U)
#define USB_OTG_DTHRCTL_ARPEN_Msk          (0x1UL << USB_OTG_DTHRCTL_ARPEN_Pos)	/*!< 0x08000000 */
#define USB_OTG_DTHRCTL_ARPEN              USB_OTG_DTHRCTL_ARPEN_Msk/*!< Arbiter parking enable */

/********************  Bit definition for USB_OTG_DIEPEMPMSK register  ********************/
#define USB_OTG_DIEPEMPMSK_INEPTXFEM_Pos    (0U)
#define USB_OTG_DIEPEMPMSK_INEPTXFEM_Msk    (0xFFFFUL << USB_OTG_DIEPEMPMSK_INEPTXFEM_Pos)	/*!< 0x0000FFFF */
#define USB_OTG_DIEPEMPMSK_INEPTXFEM        USB_OTG_DIEPEMPMSK_INEPTXFEM_Msk				/*!< IN EP Tx FIFO empty interrupt mask bits */

/********************  Bit definition for USB_OTG_DEACHINT register  ********************/
#define USB_OTG_DEACHINT_IEP1INT_Pos    (1U)
#define USB_OTG_DEACHINT_IEP1INT_Msk    (0x1UL << USB_OTG_DEACHINT_IEP1INT_Pos)	/*!< 0x00000002 */
#define USB_OTG_DEACHINT_IEP1INT        USB_OTG_DEACHINT_IEP1INT_Msk/*!< IN endpoint 1interrupt bit   */
#define USB_OTG_DEACHINT_OEP1INT_Pos    (17U)
#define USB_OTG_DEACHINT_OEP1INT_Msk    (0x1UL << USB_OTG_DEACHINT_OEP1INT_Pos)	/*!< 0x00020000 */
#define USB_OTG_DEACHINT_OEP1INT        USB_OTG_DEACHINT_OEP1INT_Msk/*!< OUT endpoint 1 interrupt bit */

/********************  Bit definition for USB_OTG_GCCFG register  ********************/
#define USB_OTG_GCCFG_PWRDWN_Pos    (16U)
#define USB_OTG_GCCFG_PWRDWN_Msk    (0x1UL << USB_OTG_GCCFG_PWRDWN_Pos)	/*!< 0x00010000 */
#define USB_OTG_GCCFG_PWRDWN        USB_OTG_GCCFG_PWRDWN_Msk/*!< Power down */
#define USB_OTG_GCCFG_VBDEN_Pos     (21U)
#define USB_OTG_GCCFG_VBDEN_Msk     (0x1UL << USB_OTG_GCCFG_VBDEN_Pos)	/*!< 0x00200000 */
#define USB_OTG_GCCFG_VBDEN         USB_OTG_GCCFG_VBDEN_Msk				/*!< USB VBUS Detection Enable */

/********************  Bit definition for USB_OTG_DEACHINTMSK register  ********************/
#define USB_OTG_DEACHINTMSK_IEP1INTM_Pos    (1U)
#define USB_OTG_DEACHINTMSK_IEP1INTM_Msk    (0x1UL << USB_OTG_DEACHINTMSK_IEP1INTM_Pos)	/*!< 0x00000002 */
#define USB_OTG_DEACHINTMSK_IEP1INTM        USB_OTG_DEACHINTMSK_IEP1INTM_Msk/*!< IN Endpoint 1 interrupt mask bit  */
#define USB_OTG_DEACHINTMSK_OEP1INTM_Pos    (17U)
#define USB_OTG_DEACHINTMSK_OEP1INTM_Msk    (0x1UL << USB_OTG_DEACHINTMSK_OEP1INTM_Pos)	/*!< 0x00020000 */
#define USB_OTG_DEACHINTMSK_OEP1INTM        USB_OTG_DEACHINTMSK_OEP1INTM_Msk/*!< OUT Endpoint 1 interrupt mask bit */

/********************  Bit definition for USB_OTG_CID register  ********************/
#define USB_OTG_CID_PRODUCT_ID_Pos    (0U)
#define USB_OTG_CID_PRODUCT_ID_Msk    (0xFFFFFFFFUL << USB_OTG_CID_PRODUCT_ID_Pos)	/*!< 0xFFFFFFFF */
#define USB_OTG_CID_PRODUCT_ID        USB_OTG_CID_PRODUCT_ID_Msk					/*!< Product ID field */

/********************  Bit definition for USB_OTG_GLPMCFG register  ********************/
#define USB_OTG_GLPMCFG_LPMEN_Pos         (0U)
#define USB_OTG_GLPMCFG_LPMEN_Msk         (0x1UL << USB_OTG_GLPMCFG_LPMEN_Pos)	/*!< 0x00000001 */
#define USB_OTG_GLPMCFG_LPMEN             USB_OTG_GLPMCFG_LPMEN_Msk				/*!< LPM support enable                                     */
#define USB_OTG_GLPMCFG_LPMACK_Pos        (1U)
#define USB_OTG_GLPMCFG_LPMACK_Msk        (0x1UL << USB_OTG_GLPMCFG_LPMACK_Pos)	/*!< 0x00000002 */
#define USB_OTG_GLPMCFG_LPMACK            USB_OTG_GLPMCFG_LPMACK_Msk/*!< LPM Token acknowledge enable                           */
#define USB_OTG_GLPMCFG_BESL_Pos          (2U)
#define USB_OTG_GLPMCFG_BESL_Msk          (0xFUL << USB_OTG_GLPMCFG_BESL_Pos)	/*!< 0x0000003C */
#define USB_OTG_GLPMCFG_BESL              USB_OTG_GLPMCFG_BESL_Msk				/*!< BESL value received with last ACKed LPM Token          */
#define USB_OTG_GLPMCFG_REMWAKE_Pos       (6U)
#define USB_OTG_GLPMCFG_REMWAKE_Msk       (0x1UL << USB_OTG_GLPMCFG_REMWAKE_Pos)/*!< 0x00000040 */
#define USB_OTG_GLPMCFG_REMWAKE           USB_OTG_GLPMCFG_REMWAKE_Msk	/*!< bRemoteWake value received with last ACKed LPM Token   */
#define USB_OTG_GLPMCFG_L1SSEN_Pos        (7U)
#define USB_OTG_GLPMCFG_L1SSEN_Msk        (0x1UL << USB_OTG_GLPMCFG_L1SSEN_Pos)	/*!< 0x00000080 */
#define USB_OTG_GLPMCFG_L1SSEN            USB_OTG_GLPMCFG_L1SSEN_Msk/*!< L1 shallow sleep enable                                */
#define USB_OTG_GLPMCFG_BESLTHRS_Pos      (8U)
#define USB_OTG_GLPMCFG_BESLTHRS_Msk      (0xFUL << USB_OTG_GLPMCFG_BESLTHRS_Pos)	/*!< 0x00000F00 */
#define USB_OTG_GLPMCFG_BESLTHRS          USB_OTG_GLPMCFG_BESLTHRS_Msk				/*!< BESL threshold                                         */
#define USB_OTG_GLPMCFG_L1DSEN_Pos        (12U)
#define USB_OTG_GLPMCFG_L1DSEN_Msk        (0x1UL << USB_OTG_GLPMCFG_L1DSEN_Pos)	/*!< 0x00001000 */
#define USB_OTG_GLPMCFG_L1DSEN            USB_OTG_GLPMCFG_L1DSEN_Msk/*!< L1 deep sleep enable                                   */
#define USB_OTG_GLPMCFG_LPMRSP_Pos        (13U)
#define USB_OTG_GLPMCFG_LPMRSP_Msk        (0x3UL << USB_OTG_GLPMCFG_LPMRSP_Pos)	/*!< 0x00006000 */
#define USB_OTG_GLPMCFG_LPMRSP            USB_OTG_GLPMCFG_LPMRSP_Msk/*!< LPM response                                           */
#define USB_OTG_GLPMCFG_SLPSTS_Pos        (15U)
#define USB_OTG_GLPMCFG_SLPSTS_Msk        (0x1UL << USB_OTG_GLPMCFG_SLPSTS_Pos)	/*!< 0x00008000 */
#define USB_OTG_GLPMCFG_SLPSTS            USB_OTG_GLPMCFG_SLPSTS_Msk/*!< Port sleep status                                      */
#define USB_OTG_GLPMCFG_L1RSMOK_Pos       (16U)
#define USB_OTG_GLPMCFG_L1RSMOK_Msk       (0x1UL << USB_OTG_GLPMCFG_L1RSMOK_Pos)/*!< 0x00010000 */
#define USB_OTG_GLPMCFG_L1RSMOK           USB_OTG_GLPMCFG_L1RSMOK_Msk	/*!< Sleep State Resume OK                                  */
#define USB_OTG_GLPMCFG_LPMCHIDX_Pos      (17U)
#define USB_OTG_GLPMCFG_LPMCHIDX_Msk      (0xFUL << USB_OTG_GLPMCFG_LPMCHIDX_Pos)	/*!< 0x001E0000 */
#define USB_OTG_GLPMCFG_LPMCHIDX          USB_OTG_GLPMCFG_LPMCHIDX_Msk				/*!< LPM Channel Index                                      */
#define USB_OTG_GLPMCFG_LPMRCNT_Pos       (21U)
#define USB_OTG_GLPMCFG_LPMRCNT_Msk       (0x7UL << USB_OTG_GLPMCFG_LPMRCNT_Pos)/*!< 0x00E00000 */
#define USB_OTG_GLPMCFG_LPMRCNT           USB_OTG_GLPMCFG_LPMRCNT_Msk	/*!< LPM retry count                                        */
#define USB_OTG_GLPMCFG_SNDLPM_Pos        (24U)
#define USB_OTG_GLPMCFG_SNDLPM_Msk        (0x1UL << USB_OTG_GLPMCFG_SNDLPM_Pos)	/*!< 0x01000000 */
#define USB_OTG_GLPMCFG_SNDLPM            USB_OTG_GLPMCFG_SNDLPM_Msk/*!< Send LPM transaction                                   */
#define USB_OTG_GLPMCFG_LPMRCNTSTS_Pos    (25U)
#define USB_OTG_GLPMCFG_LPMRCNTSTS_Msk    (0x7UL << USB_OTG_GLPMCFG_LPMRCNTSTS_Pos)	/*!< 0x0E000000 */
#define USB_OTG_GLPMCFG_LPMRCNTSTS        USB_OTG_GLPMCFG_LPMRCNTSTS_Msk/*!< LPM retry count status                                 */
#define USB_OTG_GLPMCFG_ENBESL_Pos        (28U)
#define USB_OTG_GLPMCFG_ENBESL_Msk        (0x1UL << USB_OTG_GLPMCFG_ENBESL_Pos)	/*!< 0x10000000 */
#define USB_OTG_GLPMCFG_ENBESL            USB_OTG_GLPMCFG_ENBESL_Msk/*!< Enable best effort service latency                     */

/********************  Bit definition for USB_OTG_DIEPEACHMSK1 register  ********************/
#define USB_OTG_DIEPEACHMSK1_XFRCM_Pos        (0U)
#define USB_OTG_DIEPEACHMSK1_XFRCM_Msk        (0x1UL << USB_OTG_DIEPEACHMSK1_XFRCM_Pos)	/*!< 0x00000001 */
#define USB_OTG_DIEPEACHMSK1_XFRCM            USB_OTG_DIEPEACHMSK1_XFRCM_Msk/*!< Transfer completed interrupt mask                 */
#define USB_OTG_DIEPEACHMSK1_EPDM_Pos         (1U)
#define USB_OTG_DIEPEACHMSK1_EPDM_Msk         (0x1UL << USB_OTG_DIEPEACHMSK1_EPDM_Pos)	/*!< 0x00000002 */
#define USB_OTG_DIEPEACHMSK1_EPDM             USB_OTG_DIEPEACHMSK1_EPDM_Msk				/*!< Endpoint disabled interrupt mask                  */
#define USB_OTG_DIEPEACHMSK1_TOM_Pos          (3U)
#define USB_OTG_DIEPEACHMSK1_TOM_Msk          (0x1UL << USB_OTG_DIEPEACHMSK1_TOM_Pos)	/*!< 0x00000008 */
#define USB_OTG_DIEPEACHMSK1_TOM              USB_OTG_DIEPEACHMSK1_TOM_Msk				/*!< Timeout condition mask (nonisochronous endpoints) */
#define USB_OTG_DIEPEACHMSK1_ITTXFEMSK_Pos    (4U)
#define USB_OTG_DIEPEACHMSK1_ITTXFEMSK_Msk    (0x1UL << USB_OTG_DIEPEACHMSK1_ITTXFEMSK_Pos)	/*!< 0x00000010 */
#define USB_OTG_DIEPEACHMSK1_ITTXFEMSK        USB_OTG_DIEPEACHMSK1_ITTXFEMSK_Msk/*!< IN token received when TxFIFO empty mask          */
#define USB_OTG_DIEPEACHMSK1_INEPNMM_Pos      (5U)
#define USB_OTG_DIEPEACHMSK1_INEPNMM_Msk      (0x1UL << USB_OTG_DIEPEACHMSK1_INEPNMM_Pos)	/*!< 0x00000020 */
#define USB_OTG_DIEPEACHMSK1_INEPNMM          USB_OTG_DIEPEACHMSK1_INEPNMM_Msk				/*!< IN token received with EP mismatch mask           */
#define USB_OTG_DIEPEACHMSK1_INEPNEM_Pos      (6U)
#define USB_OTG_DIEPEACHMSK1_INEPNEM_Msk      (0x1UL << USB_OTG_DIEPEACHMSK1_INEPNEM_Pos)	/*!< 0x00000040 */
#define USB_OTG_DIEPEACHMSK1_INEPNEM          USB_OTG_DIEPEACHMSK1_INEPNEM_Msk				/*!< IN endpoint NAK effective mask                    */
#define USB_OTG_DIEPEACHMSK1_TXFURM_Pos       (8U)
#define USB_OTG_DIEPEACHMSK1_TXFURM_Msk       (0x1UL << USB_OTG_DIEPEACHMSK1_TXFURM_Pos)/*!< 0x00000100 */
#define USB_OTG_DIEPEACHMSK1_TXFURM           USB_OTG_DIEPEACHMSK1_TXFURM_Msk	/*!< FIFO underrun mask                                */
#define USB_OTG_DIEPEACHMSK1_BIM_Pos          (9U)
#define USB_OTG_DIEPEACHMSK1_BIM_Msk          (0x1UL << USB_OTG_DIEPEACHMSK1_BIM_Pos)	/*!< 0x00000200 */
#define USB_OTG_DIEPEACHMSK1_BIM              USB_OTG_DIEPEACHMSK1_BIM_Msk				/*!< BNA interrupt mask                                */
#define USB_OTG_DIEPEACHMSK1_NAKM_Pos         (13U)
#define USB_OTG_DIEPEACHMSK1_NAKM_Msk         (0x1UL << USB_OTG_DIEPEACHMSK1_NAKM_Pos)	/*!< 0x00002000 */
#define USB_OTG_DIEPEACHMSK1_NAKM             USB_OTG_DIEPEACHMSK1_NAKM_Msk				/*!< NAK interrupt mask                                */

/********************  Bit definition for USB_OTG_HPRT register  ********************/
#define USB_OTG_HPRT_PCSTS_Pos      (0U)
#define USB_OTG_HPRT_PCSTS_Msk      (0x1UL << USB_OTG_HPRT_PCSTS_Pos)	/*!< 0x00000001 */
#define USB_OTG_HPRT_PCSTS          USB_OTG_HPRT_PCSTS_Msk				/*!< Port connect status        */
#define USB_OTG_HPRT_PCDET_Pos      (1U)
#define USB_OTG_HPRT_PCDET_Msk      (0x1UL << USB_OTG_HPRT_PCDET_Pos)	/*!< 0x00000002 */
#define USB_OTG_HPRT_PCDET          USB_OTG_HPRT_PCDET_Msk				/*!< Port connect detected      */
#define USB_OTG_HPRT_PENA_Pos       (2U)
#define USB_OTG_HPRT_PENA_Msk       (0x1UL << USB_OTG_HPRT_PENA_Pos)/*!< 0x00000004 */
#define USB_OTG_HPRT_PENA           USB_OTG_HPRT_PENA_Msk	/*!< Port enable                */
#define USB_OTG_HPRT_PENCHNG_Pos    (3U)
#define USB_OTG_HPRT_PENCHNG_Msk    (0x1UL << USB_OTG_HPRT_PENCHNG_Pos)	/*!< 0x00000008 */
#define USB_OTG_HPRT_PENCHNG        USB_OTG_HPRT_PENCHNG_Msk/*!< Port enable/disable change */
#define USB_OTG_HPRT_POCA_Pos       (4U)
#define USB_OTG_HPRT_POCA_Msk       (0x1UL << USB_OTG_HPRT_POCA_Pos)/*!< 0x00000010 */
#define USB_OTG_HPRT_POCA           USB_OTG_HPRT_POCA_Msk	/*!< Port overcurrent active    */
#define USB_OTG_HPRT_POCCHNG_Pos    (5U)
#define USB_OTG_HPRT_POCCHNG_Msk    (0x1UL << USB_OTG_HPRT_POCCHNG_Pos)	/*!< 0x00000020 */
#define USB_OTG_HPRT_POCCHNG        USB_OTG_HPRT_POCCHNG_Msk/*!< Port overcurrent change    */
#define USB_OTG_HPRT_PRES_Pos       (6U)
#define USB_OTG_HPRT_PRES_Msk       (0x1UL << USB_OTG_HPRT_PRES_Pos)/*!< 0x00000040 */
#define USB_OTG_HPRT_PRES           USB_OTG_HPRT_PRES_Msk	/*!< Port resume                */
#define USB_OTG_HPRT_PSUSP_Pos      (7U)
#define USB_OTG_HPRT_PSUSP_Msk      (0x1UL << USB_OTG_HPRT_PSUSP_Pos)	/*!< 0x00000080 */
#define USB_OTG_HPRT_PSUSP          USB_OTG_HPRT_PSUSP_Msk				/*!< Port suspend               */
#define USB_OTG_HPRT_PRST_Pos       (8U)
#define USB_OTG_HPRT_PRST_Msk       (0x1UL << USB_OTG_HPRT_PRST_Pos)/*!< 0x00000100 */
#define USB_OTG_HPRT_PRST           USB_OTG_HPRT_PRST_Msk	/*!< Port reset                 */

#define USB_OTG_HPRT_PLSTS_Pos      (10U)
#define USB_OTG_HPRT_PLSTS_Msk      (0x3UL << USB_OTG_HPRT_PLSTS_Pos)	/*!< 0x00000C00 */
#define USB_OTG_HPRT_PLSTS          USB_OTG_HPRT_PLSTS_Msk				/*!< Port line status           */
#define USB_OTG_HPRT_PLSTS_0        (0x1UL << USB_OTG_HPRT_PLSTS_Pos)	/*!< 0x00000400 */
#define USB_OTG_HPRT_PLSTS_1        (0x2UL << USB_OTG_HPRT_PLSTS_Pos)	/*!< 0x00000800 */
#define USB_OTG_HPRT_PPWR_Pos       (12U)
#define USB_OTG_HPRT_PPWR_Msk       (0x1UL << USB_OTG_HPRT_PPWR_Pos)/*!< 0x00001000 */
#define USB_OTG_HPRT_PPWR           USB_OTG_HPRT_PPWR_Msk	/*!< Port power                 */

#define USB_OTG_HPRT_PTCTL_Pos      (13U)
#define USB_OTG_HPRT_PTCTL_Msk      (0xFUL << USB_OTG_HPRT_PTCTL_Pos)	/*!< 0x0001E000 */
#define USB_OTG_HPRT_PTCTL          USB_OTG_HPRT_PTCTL_Msk				/*!< Port test control          */
#define USB_OTG_HPRT_PTCTL_0        (0x1UL << USB_OTG_HPRT_PTCTL_Pos)	/*!< 0x00002000 */
#define USB_OTG_HPRT_PTCTL_1        (0x2UL << USB_OTG_HPRT_PTCTL_Pos)	/*!< 0x00004000 */
#define USB_OTG_HPRT_PTCTL_2        (0x4UL << USB_OTG_HPRT_PTCTL_Pos)	/*!< 0x00008000 */
#define USB_OTG_HPRT_PTCTL_3        (0x8UL << USB_OTG_HPRT_PTCTL_Pos)	/*!< 0x00010000 */

#define USB_OTG_HPRT_PSPD_Pos       (17U)
#define USB_OTG_HPRT_PSPD_Msk       (0x3UL << USB_OTG_HPRT_PSPD_Pos)/*!< 0x00060000 */
#define USB_OTG_HPRT_PSPD           USB_OTG_HPRT_PSPD_Msk	/*!< Port speed                 */
#define USB_OTG_HPRT_PSPD_0         (0x1UL << USB_OTG_HPRT_PSPD_Pos)/*!< 0x00020000 */
#define USB_OTG_HPRT_PSPD_1         (0x2UL << USB_OTG_HPRT_PSPD_Pos)/*!< 0x00040000 */

/********************  Bit definition for USB_OTG_DOEPEACHMSK1 register  ********************/
#define USB_OTG_DOEPEACHMSK1_XFRCM_Pos        (0U)
#define USB_OTG_DOEPEACHMSK1_XFRCM_Msk        (0x1UL << USB_OTG_DOEPEACHMSK1_XFRCM_Pos)	/*!< 0x00000001 */
#define USB_OTG_DOEPEACHMSK1_XFRCM            USB_OTG_DOEPEACHMSK1_XFRCM_Msk/*!< Transfer completed interrupt mask         */
#define USB_OTG_DOEPEACHMSK1_EPDM_Pos         (1U)
#define USB_OTG_DOEPEACHMSK1_EPDM_Msk         (0x1UL << USB_OTG_DOEPEACHMSK1_EPDM_Pos)	/*!< 0x00000002 */
#define USB_OTG_DOEPEACHMSK1_EPDM             USB_OTG_DOEPEACHMSK1_EPDM_Msk				/*!< Endpoint disabled interrupt mask          */
#define USB_OTG_DOEPEACHMSK1_TOM_Pos          (3U)
#define USB_OTG_DOEPEACHMSK1_TOM_Msk          (0x1UL << USB_OTG_DOEPEACHMSK1_TOM_Pos)	/*!< 0x00000008 */
#define USB_OTG_DOEPEACHMSK1_TOM              USB_OTG_DOEPEACHMSK1_TOM_Msk				/*!< Timeout condition mask                    */
#define USB_OTG_DOEPEACHMSK1_ITTXFEMSK_Pos    (4U)
#define USB_OTG_DOEPEACHMSK1_ITTXFEMSK_Msk    (0x1UL << USB_OTG_DOEPEACHMSK1_ITTXFEMSK_Pos)	/*!< 0x00000010 */
#define USB_OTG_DOEPEACHMSK1_ITTXFEMSK        USB_OTG_DOEPEACHMSK1_ITTXFEMSK_Msk/*!< IN token received when TxFIFO empty mask  */
#define USB_OTG_DOEPEACHMSK1_INEPNMM_Pos      (5U)
#define USB_OTG_DOEPEACHMSK1_INEPNMM_Msk      (0x1UL << USB_OTG_DOEPEACHMSK1_INEPNMM_Pos)	/*!< 0x00000020 */
#define USB_OTG_DOEPEACHMSK1_INEPNMM          USB_OTG_DOEPEACHMSK1_INEPNMM_Msk				/*!< IN token received with EP mismatch mask   */
#define USB_OTG_DOEPEACHMSK1_INEPNEM_Pos      (6U)
#define USB_OTG_DOEPEACHMSK1_INEPNEM_Msk      (0x1UL << USB_OTG_DOEPEACHMSK1_INEPNEM_Pos)	/*!< 0x00000040 */
#define USB_OTG_DOEPEACHMSK1_INEPNEM          USB_OTG_DOEPEACHMSK1_INEPNEM_Msk				/*!< IN endpoint NAK effective mask            */
#define USB_OTG_DOEPEACHMSK1_TXFURM_Pos       (8U)
#define USB_OTG_DOEPEACHMSK1_TXFURM_Msk       (0x1UL << USB_OTG_DOEPEACHMSK1_TXFURM_Pos)/*!< 0x00000100 */
#define USB_OTG_DOEPEACHMSK1_TXFURM           USB_OTG_DOEPEACHMSK1_TXFURM_Msk	/*!< OUT packet error mask                     */
#define USB_OTG_DOEPEACHMSK1_BIM_Pos          (9U)
#define USB_OTG_DOEPEACHMSK1_BIM_Msk          (0x1UL << USB_OTG_DOEPEACHMSK1_BIM_Pos)	/*!< 0x00000200 */
#define USB_OTG_DOEPEACHMSK1_BIM              USB_OTG_DOEPEACHMSK1_BIM_Msk				/*!< BNA interrupt mask                        */
#define USB_OTG_DOEPEACHMSK1_BERRM_Pos        (12U)
#define USB_OTG_DOEPEACHMSK1_BERRM_Msk        (0x1UL << USB_OTG_DOEPEACHMSK1_BERRM_Pos)	/*!< 0x00001000 */
#define USB_OTG_DOEPEACHMSK1_BERRM            USB_OTG_DOEPEACHMSK1_BERRM_Msk/*!< Bubble error interrupt mask               */
#define USB_OTG_DOEPEACHMSK1_NAKM_Pos         (13U)
#define USB_OTG_DOEPEACHMSK1_NAKM_Msk         (0x1UL << USB_OTG_DOEPEACHMSK1_NAKM_Pos)	/*!< 0x00002000 */
#define USB_OTG_DOEPEACHMSK1_NAKM             USB_OTG_DOEPEACHMSK1_NAKM_Msk				/*!< NAK interrupt mask                        */
#define USB_OTG_DOEPEACHMSK1_NYETM_Pos        (14U)
#define USB_OTG_DOEPEACHMSK1_NYETM_Msk        (0x1UL << USB_OTG_DOEPEACHMSK1_NYETM_Pos)	/*!< 0x00004000 */
#define USB_OTG_DOEPEACHMSK1_NYETM            USB_OTG_DOEPEACHMSK1_NYETM_Msk/*!< NYET interrupt mask                       */

/********************  Bit definition for USB_OTG_HPTXFSIZ register  ********************/
#define USB_OTG_HPTXFSIZ_PTXSA_Pos    (0U)
#define USB_OTG_HPTXFSIZ_PTXSA_Msk    (0xFFFFUL << USB_OTG_HPTXFSIZ_PTXSA_Pos)	/*!< 0x0000FFFF */
#define USB_OTG_HPTXFSIZ_PTXSA        USB_OTG_HPTXFSIZ_PTXSA_Msk				/*!< Host periodic TxFIFO start address            */
#define USB_OTG_HPTXFSIZ_PTXFD_Pos    (16U)
#define USB_OTG_HPTXFSIZ_PTXFD_Msk    (0xFFFFUL << USB_OTG_HPTXFSIZ_PTXFD_Pos)	/*!< 0xFFFF0000 */
#define USB_OTG_HPTXFSIZ_PTXFD        USB_OTG_HPTXFSIZ_PTXFD_Msk				/*!< Host periodic TxFIFO depth                    */

/********************  Bit definition for USB_OTG_DIEPCTL register  ********************/
#define USB_OTG_DIEPCTL_MPSIZ_Pos             (0U)
#define USB_OTG_DIEPCTL_MPSIZ_Msk             (0x7FFUL << USB_OTG_DIEPCTL_MPSIZ_Pos)/*!< 0x000007FF */
#define USB_OTG_DIEPCTL_MPSIZ                 USB_OTG_DIEPCTL_MPSIZ_Msk	/*!< Maximum packet size              */
#define USB_OTG_DIEPCTL_USBAEP_Pos            (15U)
#define USB_OTG_DIEPCTL_USBAEP_Msk            (0x1UL << USB_OTG_DIEPCTL_USBAEP_Pos)	/*!< 0x00008000 */
#define USB_OTG_DIEPCTL_USBAEP                USB_OTG_DIEPCTL_USBAEP_Msk/*!< USB active endpoint              */
#define USB_OTG_DIEPCTL_EONUM_DPID_Pos        (16U)
#define USB_OTG_DIEPCTL_EONUM_DPID_Msk        (0x1UL << USB_OTG_DIEPCTL_EONUM_DPID_Pos)	/*!< 0x00010000 */
#define USB_OTG_DIEPCTL_EONUM_DPID            USB_OTG_DIEPCTL_EONUM_DPID_Msk/*!< Even/odd frame                   */
#define USB_OTG_DIEPCTL_NAKSTS_Pos            (17U)
#define USB_OTG_DIEPCTL_NAKSTS_Msk            (0x1UL << USB_OTG_DIEPCTL_NAKSTS_Pos)	/*!< 0x00020000 */
#define USB_OTG_DIEPCTL_NAKSTS                USB_OTG_DIEPCTL_NAKSTS_Msk/*!< NAK status                       */

#define USB_OTG_DIEPCTL_EPTYP_Pos             (18U)
#define USB_OTG_DIEPCTL_EPTYP_Msk             (0x3UL << USB_OTG_DIEPCTL_EPTYP_Pos)	/*!< 0x000C0000 */
#define USB_OTG_DIEPCTL_EPTYP                 USB_OTG_DIEPCTL_EPTYP_Msk				/*!< Endpoint type                    */
#define USB_OTG_DIEPCTL_EPTYP_0               (0x1UL << USB_OTG_DIEPCTL_EPTYP_Pos)	/*!< 0x00040000 */
#define USB_OTG_DIEPCTL_EPTYP_1               (0x2UL << USB_OTG_DIEPCTL_EPTYP_Pos)	/*!< 0x00080000 */
#define USB_OTG_DIEPCTL_STALL_Pos             (21U)
#define USB_OTG_DIEPCTL_STALL_Msk             (0x1UL << USB_OTG_DIEPCTL_STALL_Pos)	/*!< 0x00200000 */
#define USB_OTG_DIEPCTL_STALL                 USB_OTG_DIEPCTL_STALL_Msk				/*!< STALL handshake                  */

#define USB_OTG_DIEPCTL_TXFNUM_Pos            (22U)
#define USB_OTG_DIEPCTL_TXFNUM_Msk            (0xFUL << USB_OTG_DIEPCTL_TXFNUM_Pos)	/*!< 0x03C00000 */
#define USB_OTG_DIEPCTL_TXFNUM                USB_OTG_DIEPCTL_TXFNUM_Msk/*!< TxFIFO number                    */
#define USB_OTG_DIEPCTL_TXFNUM_0              (0x1UL << USB_OTG_DIEPCTL_TXFNUM_Pos)	/*!< 0x00400000 */
#define USB_OTG_DIEPCTL_TXFNUM_1              (0x2UL << USB_OTG_DIEPCTL_TXFNUM_Pos)	/*!< 0x00800000 */
#define USB_OTG_DIEPCTL_TXFNUM_2              (0x4UL << USB_OTG_DIEPCTL_TXFNUM_Pos)	/*!< 0x01000000 */
#define USB_OTG_DIEPCTL_TXFNUM_3              (0x8UL << USB_OTG_DIEPCTL_TXFNUM_Pos)	/*!< 0x02000000 */
#define USB_OTG_DIEPCTL_CNAK_Pos              (26U)
#define USB_OTG_DIEPCTL_CNAK_Msk              (0x1UL << USB_OTG_DIEPCTL_CNAK_Pos)	/*!< 0x04000000 */
#define USB_OTG_DIEPCTL_CNAK                  USB_OTG_DIEPCTL_CNAK_Msk				/*!< Clear NAK                        */
#define USB_OTG_DIEPCTL_SNAK_Pos              (27U)
#define USB_OTG_DIEPCTL_SNAK_Msk              (0x1UL << USB_OTG_DIEPCTL_SNAK_Pos)	/*!< 0x08000000 */
#define USB_OTG_DIEPCTL_SNAK                  USB_OTG_DIEPCTL_SNAK_Msk				/*!< Set NAK */
#define USB_OTG_DIEPCTL_SD0PID_SEVNFRM_Pos    (28U)
#define USB_OTG_DIEPCTL_SD0PID_SEVNFRM_Msk    (0x1UL << USB_OTG_DIEPCTL_SD0PID_SEVNFRM_Pos)	/*!< 0x10000000 */
#define USB_OTG_DIEPCTL_SD0PID_SEVNFRM        USB_OTG_DIEPCTL_SD0PID_SEVNFRM_Msk/*!< Set DATA0 PID                    */
#define USB_OTG_DIEPCTL_SODDFRM_Pos           (29U)
#define USB_OTG_DIEPCTL_SODDFRM_Msk           (0x1UL << USB_OTG_DIEPCTL_SODDFRM_Pos)/*!< 0x20000000 */
#define USB_OTG_DIEPCTL_SODDFRM               USB_OTG_DIEPCTL_SODDFRM_Msk	/*!< Set odd frame                    */
#define USB_OTG_DIEPCTL_EPDIS_Pos             (30U)
#define USB_OTG_DIEPCTL_EPDIS_Msk             (0x1UL << USB_OTG_DIEPCTL_EPDIS_Pos)	/*!< 0x40000000 */
#define USB_OTG_DIEPCTL_EPDIS                 USB_OTG_DIEPCTL_EPDIS_Msk				/*!< Endpoint disable                 */
#define USB_OTG_DIEPCTL_EPENA_Pos             (31U)
#define USB_OTG_DIEPCTL_EPENA_Msk             (0x1UL << USB_OTG_DIEPCTL_EPENA_Pos)	/*!< 0x80000000 */
#define USB_OTG_DIEPCTL_EPENA                 USB_OTG_DIEPCTL_EPENA_Msk				/*!< Endpoint enable                  */

/********************  Bit definition for USB_OTG_HCCHAR register  ********************/
#define USB_OTG_HCCHAR_MPSIZ_Pos     (0U)
#define USB_OTG_HCCHAR_MPSIZ_Msk     (0x7FFUL << USB_OTG_HCCHAR_MPSIZ_Pos)	/*!< 0x000007FF */
#define USB_OTG_HCCHAR_MPSIZ         USB_OTG_HCCHAR_MPSIZ_Msk				/*!< Maximum packet size */

#define USB_OTG_HCCHAR_EPNUM_Pos     (11U)
#define USB_OTG_HCCHAR_EPNUM_Msk     (0xFUL << USB_OTG_HCCHAR_EPNUM_Pos)/*!< 0x00007800 */
#define USB_OTG_HCCHAR_EPNUM         USB_OTG_HCCHAR_EPNUM_Msk	/*!< Endpoint number */
#define USB_OTG_HCCHAR_EPNUM_0       (0x1UL << USB_OTG_HCCHAR_EPNUM_Pos)/*!< 0x00000800 */
#define USB_OTG_HCCHAR_EPNUM_1       (0x2UL << USB_OTG_HCCHAR_EPNUM_Pos)/*!< 0x00001000 */
#define USB_OTG_HCCHAR_EPNUM_2       (0x4UL << USB_OTG_HCCHAR_EPNUM_Pos)/*!< 0x00002000 */
#define USB_OTG_HCCHAR_EPNUM_3       (0x8UL << USB_OTG_HCCHAR_EPNUM_Pos)/*!< 0x00004000 */
#define USB_OTG_HCCHAR_EPDIR_Pos     (15U)
#define USB_OTG_HCCHAR_EPDIR_Msk     (0x1UL << USB_OTG_HCCHAR_EPDIR_Pos)/*!< 0x00008000 */
#define USB_OTG_HCCHAR_EPDIR         USB_OTG_HCCHAR_EPDIR_Msk	/*!< Endpoint direction */
#define USB_OTG_HCCHAR_LSDEV_Pos     (17U)
#define USB_OTG_HCCHAR_LSDEV_Msk     (0x1UL << USB_OTG_HCCHAR_LSDEV_Pos)/*!< 0x00020000 */
#define USB_OTG_HCCHAR_LSDEV         USB_OTG_HCCHAR_LSDEV_Msk	/*!< Low-speed device */

#define USB_OTG_HCCHAR_EPTYP_Pos     (18U)
#define USB_OTG_HCCHAR_EPTYP_Msk     (0x3UL << USB_OTG_HCCHAR_EPTYP_Pos)/*!< 0x000C0000 */
#define USB_OTG_HCCHAR_EPTYP         USB_OTG_HCCHAR_EPTYP_Msk	/*!< Endpoint type */
#define USB_OTG_HCCHAR_EPTYP_0       (0x1UL << USB_OTG_HCCHAR_EPTYP_Pos)/*!< 0x00040000 */
#define USB_OTG_HCCHAR_EPTYP_1       (0x2UL << USB_OTG_HCCHAR_EPTYP_Pos)/*!< 0x00080000 */

#define USB_OTG_HCCHAR_MC_Pos        (20U)
#define USB_OTG_HCCHAR_MC_Msk        (0x3UL << USB_OTG_HCCHAR_MC_Pos)	/*!< 0x00300000 */
#define USB_OTG_HCCHAR_MC            USB_OTG_HCCHAR_MC_Msk				/*!< Multi Count (MC) / Error Count (EC) */
#define USB_OTG_HCCHAR_MC_0          (0x1UL << USB_OTG_HCCHAR_MC_Pos)	/*!< 0x00100000 */
#define USB_OTG_HCCHAR_MC_1          (0x2UL << USB_OTG_HCCHAR_MC_Pos)	/*!< 0x00200000 */

#define USB_OTG_HCCHAR_DAD_Pos       (22U)
#define USB_OTG_HCCHAR_DAD_Msk       (0x7FUL << USB_OTG_HCCHAR_DAD_Pos)	/*!< 0x1FC00000 */
#define USB_OTG_HCCHAR_DAD           USB_OTG_HCCHAR_DAD_Msk				/*!< Device address */
#define USB_OTG_HCCHAR_DAD_0         (0x01UL << USB_OTG_HCCHAR_DAD_Pos)	/*!< 0x00400000 */
#define USB_OTG_HCCHAR_DAD_1         (0x02UL << USB_OTG_HCCHAR_DAD_Pos)	/*!< 0x00800000 */
#define USB_OTG_HCCHAR_DAD_2         (0x04UL << USB_OTG_HCCHAR_DAD_Pos)	/*!< 0x01000000 */
#define USB_OTG_HCCHAR_DAD_3         (0x08UL << USB_OTG_HCCHAR_DAD_Pos)	/*!< 0x02000000 */
#define USB_OTG_HCCHAR_DAD_4         (0x10UL << USB_OTG_HCCHAR_DAD_Pos)	/*!< 0x04000000 */
#define USB_OTG_HCCHAR_DAD_5         (0x20UL << USB_OTG_HCCHAR_DAD_Pos)	/*!< 0x08000000 */
#define USB_OTG_HCCHAR_DAD_6         (0x40UL << USB_OTG_HCCHAR_DAD_Pos)	/*!< 0x10000000 */
#define USB_OTG_HCCHAR_ODDFRM_Pos    (29U)
#define USB_OTG_HCCHAR_ODDFRM_Msk    (0x1UL << USB_OTG_HCCHAR_ODDFRM_Pos)	/*!< 0x20000000 */
#define USB_OTG_HCCHAR_ODDFRM        USB_OTG_HCCHAR_ODDFRM_Msk				/*!< Odd frame */
#define USB_OTG_HCCHAR_CHDIS_Pos     (30U)
#define USB_OTG_HCCHAR_CHDIS_Msk     (0x1UL << USB_OTG_HCCHAR_CHDIS_Pos)/*!< 0x40000000 */
#define USB_OTG_HCCHAR_CHDIS         USB_OTG_HCCHAR_CHDIS_Msk	/*!< Channel disable */
#define USB_OTG_HCCHAR_CHENA_Pos     (31U)
#define USB_OTG_HCCHAR_CHENA_Msk     (0x1UL << USB_OTG_HCCHAR_CHENA_Pos)/*!< 0x80000000 */
#define USB_OTG_HCCHAR_CHENA         USB_OTG_HCCHAR_CHENA_Msk	/*!< Channel enable */

/********************  Bit definition for USB_OTG_HCSPLT register  ********************/

#define USB_OTG_HCSPLT_PRTADDR_Pos      (0U)
#define USB_OTG_HCSPLT_PRTADDR_Msk      (0x7FUL << USB_OTG_HCSPLT_PRTADDR_Pos)	/*!< 0x0000007F */
#define USB_OTG_HCSPLT_PRTADDR          USB_OTG_HCSPLT_PRTADDR_Msk				/*!< Port address */
#define USB_OTG_HCSPLT_PRTADDR_0        (0x01UL << USB_OTG_HCSPLT_PRTADDR_Pos)	/*!< 0x00000001 */
#define USB_OTG_HCSPLT_PRTADDR_1        (0x02UL << USB_OTG_HCSPLT_PRTADDR_Pos)	/*!< 0x00000002 */
#define USB_OTG_HCSPLT_PRTADDR_2        (0x04UL << USB_OTG_HCSPLT_PRTADDR_Pos)	/*!< 0x00000004 */
#define USB_OTG_HCSPLT_PRTADDR_3        (0x08UL << USB_OTG_HCSPLT_PRTADDR_Pos)	/*!< 0x00000008 */
#define USB_OTG_HCSPLT_PRTADDR_4        (0x10UL << USB_OTG_HCSPLT_PRTADDR_Pos)	/*!< 0x00000010 */
#define USB_OTG_HCSPLT_PRTADDR_5        (0x20UL << USB_OTG_HCSPLT_PRTADDR_Pos)	/*!< 0x00000020 */
#define USB_OTG_HCSPLT_PRTADDR_6        (0x40UL << USB_OTG_HCSPLT_PRTADDR_Pos)	/*!< 0x00000040 */

#define USB_OTG_HCSPLT_HUBADDR_Pos      (7U)
#define USB_OTG_HCSPLT_HUBADDR_Msk      (0x7FUL << USB_OTG_HCSPLT_HUBADDR_Pos)	/*!< 0x00003F80 */
#define USB_OTG_HCSPLT_HUBADDR          USB_OTG_HCSPLT_HUBADDR_Msk				/*!< Hub address */
#define USB_OTG_HCSPLT_HUBADDR_0        (0x01UL << USB_OTG_HCSPLT_HUBADDR_Pos)	/*!< 0x00000080 */
#define USB_OTG_HCSPLT_HUBADDR_1        (0x02UL << USB_OTG_HCSPLT_HUBADDR_Pos)	/*!< 0x00000100 */
#define USB_OTG_HCSPLT_HUBADDR_2        (0x04UL << USB_OTG_HCSPLT_HUBADDR_Pos)	/*!< 0x00000200 */
#define USB_OTG_HCSPLT_HUBADDR_3        (0x08UL << USB_OTG_HCSPLT_HUBADDR_Pos)	/*!< 0x00000400 */
#define USB_OTG_HCSPLT_HUBADDR_4        (0x10UL << USB_OTG_HCSPLT_HUBADDR_Pos)	/*!< 0x00000800 */
#define USB_OTG_HCSPLT_HUBADDR_5        (0x20UL << USB_OTG_HCSPLT_HUBADDR_Pos)	/*!< 0x00001000 */
#define USB_OTG_HCSPLT_HUBADDR_6        (0x40UL << USB_OTG_HCSPLT_HUBADDR_Pos)	/*!< 0x00002000 */

#define USB_OTG_HCSPLT_XACTPOS_Pos      (14U)
#define USB_OTG_HCSPLT_XACTPOS_Msk      (0x3UL << USB_OTG_HCSPLT_XACTPOS_Pos)	/*!< 0x0000C000 */
#define USB_OTG_HCSPLT_XACTPOS          USB_OTG_HCSPLT_XACTPOS_Msk				/*!< XACTPOS */
#define USB_OTG_HCSPLT_XACTPOS_0        (0x1UL << USB_OTG_HCSPLT_XACTPOS_Pos)	/*!< 0x00004000 */
#define USB_OTG_HCSPLT_XACTPOS_1        (0x2UL << USB_OTG_HCSPLT_XACTPOS_Pos)	/*!< 0x00008000 */
#define USB_OTG_HCSPLT_COMPLSPLT_Pos    (16U)
#define USB_OTG_HCSPLT_COMPLSPLT_Msk    (0x1UL << USB_OTG_HCSPLT_COMPLSPLT_Pos)	/*!< 0x00010000 */
#define USB_OTG_HCSPLT_COMPLSPLT        USB_OTG_HCSPLT_COMPLSPLT_Msk/*!< Do complete split */
#define USB_OTG_HCSPLT_SPLITEN_Pos      (31U)
#define USB_OTG_HCSPLT_SPLITEN_Msk      (0x1UL << USB_OTG_HCSPLT_SPLITEN_Pos)	/*!< 0x80000000 */
#define USB_OTG_HCSPLT_SPLITEN          USB_OTG_HCSPLT_SPLITEN_Msk				/*!< Split enable */

/********************  Bit definition for USB_OTG_HCINT register  ********************/
#define USB_OTG_HCINT_XFRC_Pos      (0U)
#define USB_OTG_HCINT_XFRC_Msk      (0x1UL << USB_OTG_HCINT_XFRC_Pos)	/*!< 0x00000001 */
#define USB_OTG_HCINT_XFRC          USB_OTG_HCINT_XFRC_Msk				/*!< Transfer completed */
#define USB_OTG_HCINT_CHH_Pos       (1U)
#define USB_OTG_HCINT_CHH_Msk       (0x1UL << USB_OTG_HCINT_CHH_Pos)/*!< 0x00000002 */
#define USB_OTG_HCINT_CHH           USB_OTG_HCINT_CHH_Msk	/*!< Channel halted */
#define USB_OTG_HCINT_AHBERR_Pos    (2U)
#define USB_OTG_HCINT_AHBERR_Msk    (0x1UL << USB_OTG_HCINT_AHBERR_Pos)	/*!< 0x00000004 */
#define USB_OTG_HCINT_AHBERR        USB_OTG_HCINT_AHBERR_Msk/*!< AHB error */
#define USB_OTG_HCINT_STALL_Pos     (3U)
#define USB_OTG_HCINT_STALL_Msk     (0x1UL << USB_OTG_HCINT_STALL_Pos)	/*!< 0x00000008 */
#define USB_OTG_HCINT_STALL         USB_OTG_HCINT_STALL_Msk				/*!< STALL response received interrupt */
#define USB_OTG_HCINT_NAK_Pos       (4U)
#define USB_OTG_HCINT_NAK_Msk       (0x1UL << USB_OTG_HCINT_NAK_Pos)/*!< 0x00000010 */
#define USB_OTG_HCINT_NAK           USB_OTG_HCINT_NAK_Msk	/*!< NAK response received interrupt */
#define USB_OTG_HCINT_ACK_Pos       (5U)
#define USB_OTG_HCINT_ACK_Msk       (0x1UL << USB_OTG_HCINT_ACK_Pos)/*!< 0x00000020 */
#define USB_OTG_HCINT_ACK           USB_OTG_HCINT_ACK_Msk	/*!< ACK response received/transmitted interrupt */
#define USB_OTG_HCINT_NYET_Pos      (6U)
#define USB_OTG_HCINT_NYET_Msk      (0x1UL << USB_OTG_HCINT_NYET_Pos)	/*!< 0x00000040 */
#define USB_OTG_HCINT_NYET          USB_OTG_HCINT_NYET_Msk				/*!< Response received interrupt */
#define USB_OTG_HCINT_TXERR_Pos     (7U)
#define USB_OTG_HCINT_TXERR_Msk     (0x1UL << USB_OTG_HCINT_TXERR_Pos)	/*!< 0x00000080 */
#define USB_OTG_HCINT_TXERR         USB_OTG_HCINT_TXERR_Msk				/*!< Transaction error */
#define USB_OTG_HCINT_BBERR_Pos     (8U)
#define USB_OTG_HCINT_BBERR_Msk     (0x1UL << USB_OTG_HCINT_BBERR_Pos)	/*!< 0x00000100 */
#define USB_OTG_HCINT_BBERR         USB_OTG_HCINT_BBERR_Msk				/*!< Babble error */
#define USB_OTG_HCINT_FRMOR_Pos     (9U)
#define USB_OTG_HCINT_FRMOR_Msk     (0x1UL << USB_OTG_HCINT_FRMOR_Pos)	/*!< 0x00000200 */
#define USB_OTG_HCINT_FRMOR         USB_OTG_HCINT_FRMOR_Msk				/*!< Frame overrun */
#define USB_OTG_HCINT_DTERR_Pos     (10U)
#define USB_OTG_HCINT_DTERR_Msk     (0x1UL << USB_OTG_HCINT_DTERR_Pos)	/*!< 0x00000400 */
#define USB_OTG_HCINT_DTERR         USB_OTG_HCINT_DTERR_Msk				/*!< Data toggle error */

/********************  Bit definition for USB_OTG_DIEPINT register  ********************/
#define USB_OTG_DIEPINT_XFRC_Pos          (0U)
#define USB_OTG_DIEPINT_XFRC_Msk          (0x1UL << USB_OTG_DIEPINT_XFRC_Pos)	/*!< 0x00000001 */
#define USB_OTG_DIEPINT_XFRC              USB_OTG_DIEPINT_XFRC_Msk				/*!< Transfer completed interrupt */
#define USB_OTG_DIEPINT_EPDISD_Pos        (1U)
#define USB_OTG_DIEPINT_EPDISD_Msk        (0x1UL << USB_OTG_DIEPINT_EPDISD_Pos)	/*!< 0x00000002 */
#define USB_OTG_DIEPINT_EPDISD            USB_OTG_DIEPINT_EPDISD_Msk/*!< Endpoint disabled interrupt */
#define USB_OTG_DIEPINT_AHBERR_Pos        (2U)
#define USB_OTG_DIEPINT_AHBERR_Msk        (0x1UL << USB_OTG_DIEPINT_AHBERR_Pos)	/*!< 0x00000004 */
#define USB_OTG_DIEPINT_AHBERR            USB_OTG_DIEPINT_AHBERR_Msk/*!< AHB Error (AHBErr) during an IN transaction */
#define USB_OTG_DIEPINT_TOC_Pos           (3U)
#define USB_OTG_DIEPINT_TOC_Msk           (0x1UL << USB_OTG_DIEPINT_TOC_Pos)/*!< 0x00000008 */
#define USB_OTG_DIEPINT_TOC               USB_OTG_DIEPINT_TOC_Msk	/*!< Timeout condition */
#define USB_OTG_DIEPINT_ITTXFE_Pos        (4U)
#define USB_OTG_DIEPINT_ITTXFE_Msk        (0x1UL << USB_OTG_DIEPINT_ITTXFE_Pos)	/*!< 0x00000010 */
#define USB_OTG_DIEPINT_ITTXFE            USB_OTG_DIEPINT_ITTXFE_Msk/*!< IN token received when TxFIFO is empty */
#define USB_OTG_DIEPINT_INEPNM_Pos        (5U)
#define USB_OTG_DIEPINT_INEPNM_Msk        (0x1UL << USB_OTG_DIEPINT_INEPNM_Pos)	/*!< 0x00000020 */
#define USB_OTG_DIEPINT_INEPNM            USB_OTG_DIEPINT_INEPNM_Msk/*!< IN token received with EP mismatch */
#define USB_OTG_DIEPINT_INEPNE_Pos        (6U)
#define USB_OTG_DIEPINT_INEPNE_Msk        (0x1UL << USB_OTG_DIEPINT_INEPNE_Pos)	/*!< 0x00000040 */
#define USB_OTG_DIEPINT_INEPNE            USB_OTG_DIEPINT_INEPNE_Msk/*!< IN endpoint NAK effective */
#define USB_OTG_DIEPINT_TXFE_Pos          (7U)
#define USB_OTG_DIEPINT_TXFE_Msk          (0x1UL << USB_OTG_DIEPINT_TXFE_Pos)	/*!< 0x00000080 */
#define USB_OTG_DIEPINT_TXFE              USB_OTG_DIEPINT_TXFE_Msk				/*!< Transmit FIFO empty */
#define USB_OTG_DIEPINT_TXFIFOUDRN_Pos    (8U)
#define USB_OTG_DIEPINT_TXFIFOUDRN_Msk    (0x1UL << USB_OTG_DIEPINT_TXFIFOUDRN_Pos)	/*!< 0x00000100 */
#define USB_OTG_DIEPINT_TXFIFOUDRN        USB_OTG_DIEPINT_TXFIFOUDRN_Msk/*!< Transmit Fifo Underrun */
#define USB_OTG_DIEPINT_BNA_Pos           (9U)
#define USB_OTG_DIEPINT_BNA_Msk           (0x1UL << USB_OTG_DIEPINT_BNA_Pos)/*!< 0x00000200 */
#define USB_OTG_DIEPINT_BNA               USB_OTG_DIEPINT_BNA_Msk	/*!< Buffer not available interrupt */
#define USB_OTG_DIEPINT_PKTDRPSTS_Pos     (11U)
#define USB_OTG_DIEPINT_PKTDRPSTS_Msk     (0x1UL << USB_OTG_DIEPINT_PKTDRPSTS_Pos)	/*!< 0x00000800 */
#define USB_OTG_DIEPINT_PKTDRPSTS         USB_OTG_DIEPINT_PKTDRPSTS_Msk				/*!< Packet dropped status */
#define USB_OTG_DIEPINT_BERR_Pos          (12U)
#define USB_OTG_DIEPINT_BERR_Msk          (0x1UL << USB_OTG_DIEPINT_BERR_Pos)	/*!< 0x00001000 */
#define USB_OTG_DIEPINT_BERR              USB_OTG_DIEPINT_BERR_Msk				/*!< Babble error interrupt */
#define USB_OTG_DIEPINT_NAK_Pos           (13U)
#define USB_OTG_DIEPINT_NAK_Msk           (0x1UL << USB_OTG_DIEPINT_NAK_Pos)/*!< 0x00002000 */
#define USB_OTG_DIEPINT_NAK               USB_OTG_DIEPINT_NAK_Msk	/*!< NAK interrupt */

/********************  Bit definition for USB_OTG_HCINTMSK register  ********************/
#define USB_OTG_HCINTMSK_XFRCM_Pos     (0U)
#define USB_OTG_HCINTMSK_XFRCM_Msk     (0x1UL << USB_OTG_HCINTMSK_XFRCM_Pos)/*!< 0x00000001 */
#define USB_OTG_HCINTMSK_XFRCM         USB_OTG_HCINTMSK_XFRCM_Msk	/*!< Transfer completed mask */
#define USB_OTG_HCINTMSK_CHHM_Pos      (1U)
#define USB_OTG_HCINTMSK_CHHM_Msk      (0x1UL << USB_OTG_HCINTMSK_CHHM_Pos)	/*!< 0x00000002 */
#define USB_OTG_HCINTMSK_CHHM          USB_OTG_HCINTMSK_CHHM_Msk/*!< Channel halted mask */
#define USB_OTG_HCINTMSK_AHBERR_Pos    (2U)
#define USB_OTG_HCINTMSK_AHBERR_Msk    (0x1UL << USB_OTG_HCINTMSK_AHBERR_Pos)	/*!< 0x00000004 */
#define USB_OTG_HCINTMSK_AHBERR        USB_OTG_HCINTMSK_AHBERR_Msk				/*!< AHB error */
#define USB_OTG_HCINTMSK_STALLM_Pos    (3U)
#define USB_OTG_HCINTMSK_STALLM_Msk    (0x1UL << USB_OTG_HCINTMSK_STALLM_Pos)	/*!< 0x00000008 */
#define USB_OTG_HCINTMSK_STALLM        USB_OTG_HCINTMSK_STALLM_Msk				/*!< STALL response received interrupt mask */
#define USB_OTG_HCINTMSK_NAKM_Pos      (4U)
#define USB_OTG_HCINTMSK_NAKM_Msk      (0x1UL << USB_OTG_HCINTMSK_NAKM_Pos)	/*!< 0x00000010 */
#define USB_OTG_HCINTMSK_NAKM          USB_OTG_HCINTMSK_NAKM_Msk/*!< NAK response received interrupt mask */
#define USB_OTG_HCINTMSK_ACKM_Pos      (5U)
#define USB_OTG_HCINTMSK_ACKM_Msk      (0x1UL << USB_OTG_HCINTMSK_ACKM_Pos)	/*!< 0x00000020 */
#define USB_OTG_HCINTMSK_ACKM          USB_OTG_HCINTMSK_ACKM_Msk/*!< ACK response received/transmitted interrupt mask */
#define USB_OTG_HCINTMSK_NYET_Pos      (6U)
#define USB_OTG_HCINTMSK_NYET_Msk      (0x1UL << USB_OTG_HCINTMSK_NYET_Pos)	/*!< 0x00000040 */
#define USB_OTG_HCINTMSK_NYET          USB_OTG_HCINTMSK_NYET_Msk/*!< response received interrupt mask */
#define USB_OTG_HCINTMSK_TXERRM_Pos    (7U)
#define USB_OTG_HCINTMSK_TXERRM_Msk    (0x1UL << USB_OTG_HCINTMSK_TXERRM_Pos)	/*!< 0x00000080 */
#define USB_OTG_HCINTMSK_TXERRM        USB_OTG_HCINTMSK_TXERRM_Msk				/*!< Transaction error mask */
#define USB_OTG_HCINTMSK_BBERRM_Pos    (8U)
#define USB_OTG_HCINTMSK_BBERRM_Msk    (0x1UL << USB_OTG_HCINTMSK_BBERRM_Pos)	/*!< 0x00000100 */
#define USB_OTG_HCINTMSK_BBERRM        USB_OTG_HCINTMSK_BBERRM_Msk				/*!< Babble error mask */
#define USB_OTG_HCINTMSK_FRMORM_Pos    (9U)
#define USB_OTG_HCINTMSK_FRMORM_Msk    (0x1UL << USB_OTG_HCINTMSK_FRMORM_Pos)	/*!< 0x00000200 */
#define USB_OTG_HCINTMSK_FRMORM        USB_OTG_HCINTMSK_FRMORM_Msk				/*!< Frame overrun mask */
#define USB_OTG_HCINTMSK_DTERRM_Pos    (10U)
#define USB_OTG_HCINTMSK_DTERRM_Msk    (0x1UL << USB_OTG_HCINTMSK_DTERRM_Pos)	/*!< 0x00000400 */
#define USB_OTG_HCINTMSK_DTERRM        USB_OTG_HCINTMSK_DTERRM_Msk				/*!< Data toggle error mask */

/********************  Bit definition for USB_OTG_DIEPTSIZ register  ********************/

#define USB_OTG_DIEPTSIZ_XFRSIZ_Pos    (0U)
#define USB_OTG_DIEPTSIZ_XFRSIZ_Msk    (0x7FFFFUL << USB_OTG_DIEPTSIZ_XFRSIZ_Pos)	/*!< 0x0007FFFF */
#define USB_OTG_DIEPTSIZ_XFRSIZ        USB_OTG_DIEPTSIZ_XFRSIZ_Msk					/*!< Transfer size */
#define USB_OTG_DIEPTSIZ_PKTCNT_Pos    (19U)
#define USB_OTG_DIEPTSIZ_PKTCNT_Msk    (0x3FFUL << USB_OTG_DIEPTSIZ_PKTCNT_Pos)	/*!< 0x1FF80000 */
#define USB_OTG_DIEPTSIZ_PKTCNT        USB_OTG_DIEPTSIZ_PKTCNT_Msk				/*!< Packet count */
#define USB_OTG_DIEPTSIZ_MULCNT_Pos    (29U)
#define USB_OTG_DIEPTSIZ_MULCNT_Msk    (0x3UL << USB_OTG_DIEPTSIZ_MULCNT_Pos)	/*!< 0x60000000 */
#define USB_OTG_DIEPTSIZ_MULCNT        USB_OTG_DIEPTSIZ_MULCNT_Msk				/*!< Packet count */
/********************  Bit definition for USB_OTG_HCTSIZ register  ********************/
#define USB_OTG_HCTSIZ_XFRSIZ_Pos      (0U)
#define USB_OTG_HCTSIZ_XFRSIZ_Msk      (0x7FFFFUL << USB_OTG_HCTSIZ_XFRSIZ_Pos)	/*!< 0x0007FFFF */
#define USB_OTG_HCTSIZ_XFRSIZ          USB_OTG_HCTSIZ_XFRSIZ_Msk/*!< Transfer size */
#define USB_OTG_HCTSIZ_PKTCNT_Pos      (19U)
#define USB_OTG_HCTSIZ_PKTCNT_Msk      (0x3FFUL << USB_OTG_HCTSIZ_PKTCNT_Pos)	/*!< 0x1FF80000 */
#define USB_OTG_HCTSIZ_PKTCNT          USB_OTG_HCTSIZ_PKTCNT_Msk				/*!< Packet count */
#define USB_OTG_HCTSIZ_DOPING_Pos      (31U)
#define USB_OTG_HCTSIZ_DOPING_Msk      (0x1UL << USB_OTG_HCTSIZ_DOPING_Pos)	/*!< 0x80000000 */
#define USB_OTG_HCTSIZ_DOPING          USB_OTG_HCTSIZ_DOPING_Msk/*!< Do PING */
#define USB_OTG_HCTSIZ_DPID_Pos        (29U)
#define USB_OTG_HCTSIZ_DPID_Msk        (0x3UL << USB_OTG_HCTSIZ_DPID_Pos)	/*!< 0x60000000 */
#define USB_OTG_HCTSIZ_DPID            USB_OTG_HCTSIZ_DPID_Msk				/*!< Data PID */
#define USB_OTG_HCTSIZ_DPID_0          (0x1UL << USB_OTG_HCTSIZ_DPID_Pos)	/*!< 0x20000000 */
#define USB_OTG_HCTSIZ_DPID_1          (0x2UL << USB_OTG_HCTSIZ_DPID_Pos)	/*!< 0x40000000 */

/********************  Bit definition for USB_OTG_DIEPDMA register  ********************/
#define USB_OTG_DIEPDMA_DMAADDR_Pos    (0U)
#define USB_OTG_DIEPDMA_DMAADDR_Msk    (0xFFFFFFFFUL << USB_OTG_DIEPDMA_DMAADDR_Pos)/*!< 0xFFFFFFFF */
#define USB_OTG_DIEPDMA_DMAADDR        USB_OTG_DIEPDMA_DMAADDR_Msk	/*!< DMA address */

/********************  Bit definition for USB_OTG_HCDMA register  ********************/
#define USB_OTG_HCDMA_DMAADDR_Pos    (0U)
#define USB_OTG_HCDMA_DMAADDR_Msk    (0xFFFFFFFFUL << USB_OTG_HCDMA_DMAADDR_Pos)/*!< 0xFFFFFFFF */
#define USB_OTG_HCDMA_DMAADDR        USB_OTG_HCDMA_DMAADDR_Msk	/*!< DMA address */

/********************  Bit definition for USB_OTG_DTXFSTS register  ********************/
#define USB_OTG_DTXFSTS_INEPTFSAV_Pos    (0U)
#define USB_OTG_DTXFSTS_INEPTFSAV_Msk    (0xFFFFUL << USB_OTG_DTXFSTS_INEPTFSAV_Pos)/*!< 0x0000FFFF */
#define USB_OTG_DTXFSTS_INEPTFSAV        USB_OTG_DTXFSTS_INEPTFSAV_Msk	/*!< IN endpoint TxFIFO space available */

/********************  Bit definition for USB_OTG_DIEPTXF register  ********************/
#define USB_OTG_DIEPTXF_INEPTXSA_Pos    (0U)
#define USB_OTG_DIEPTXF_INEPTXSA_Msk    (0xFFFFUL << USB_OTG_DIEPTXF_INEPTXSA_Pos)	/*!< 0x0000FFFF */
#define USB_OTG_DIEPTXF_INEPTXSA        USB_OTG_DIEPTXF_INEPTXSA_Msk				/*!< IN endpoint FIFOx transmit RAM start address */
#define USB_OTG_DIEPTXF_INEPTXFD_Pos    (16U)
#define USB_OTG_DIEPTXF_INEPTXFD_Msk    (0xFFFFUL << USB_OTG_DIEPTXF_INEPTXFD_Pos)	/*!< 0xFFFF0000 */
#define USB_OTG_DIEPTXF_INEPTXFD        USB_OTG_DIEPTXF_INEPTXFD_Msk				/*!< IN endpoint TxFIFO depth */

/********************  Bit definition for USB_OTG_DOEPCTL register  ********************/
#define USB_OTG_DOEPCTL_MPSIZ_Pos             (0U)
#define USB_OTG_DOEPCTL_MPSIZ_Msk             (0x7FFUL << USB_OTG_DOEPCTL_MPSIZ_Pos)/*!< 0x000007FF */
#define USB_OTG_DOEPCTL_MPSIZ                 USB_OTG_DOEPCTL_MPSIZ_Msk	/*!< Maximum packet size */          /*!<Bit 1 */
#define USB_OTG_DOEPCTL_USBAEP_Pos            (15U)
#define USB_OTG_DOEPCTL_USBAEP_Msk            (0x1UL << USB_OTG_DOEPCTL_USBAEP_Pos)	/*!< 0x00008000 */
#define USB_OTG_DOEPCTL_USBAEP                USB_OTG_DOEPCTL_USBAEP_Msk/*!< USB active endpoint */
#define USB_OTG_DOEPCTL_NAKSTS_Pos            (17U)
#define USB_OTG_DOEPCTL_NAKSTS_Msk            (0x1UL << USB_OTG_DOEPCTL_NAKSTS_Pos)	/*!< 0x00020000 */
#define USB_OTG_DOEPCTL_NAKSTS                USB_OTG_DOEPCTL_NAKSTS_Msk/*!< NAK status */
#define USB_OTG_DOEPCTL_SD0PID_SEVNFRM_Pos    (28U)
#define USB_OTG_DOEPCTL_SD0PID_SEVNFRM_Msk    (0x1UL << USB_OTG_DOEPCTL_SD0PID_SEVNFRM_Pos)	/*!< 0x10000000 */
#define USB_OTG_DOEPCTL_SD0PID_SEVNFRM        USB_OTG_DOEPCTL_SD0PID_SEVNFRM_Msk/*!< Set DATA0 PID */
#define USB_OTG_DOEPCTL_SODDFRM_Pos           (29U)
#define USB_OTG_DOEPCTL_SODDFRM_Msk           (0x1UL << USB_OTG_DOEPCTL_SODDFRM_Pos)/*!< 0x20000000 */
#define USB_OTG_DOEPCTL_SODDFRM               USB_OTG_DOEPCTL_SODDFRM_Msk	/*!< Set odd frame */
#define USB_OTG_DOEPCTL_EPTYP_Pos             (18U)
#define USB_OTG_DOEPCTL_EPTYP_Msk             (0x3UL << USB_OTG_DOEPCTL_EPTYP_Pos)	/*!< 0x000C0000 */
#define USB_OTG_DOEPCTL_EPTYP                 USB_OTG_DOEPCTL_EPTYP_Msk				/*!< Endpoint type */
#define USB_OTG_DOEPCTL_EPTYP_0               (0x1UL << USB_OTG_DOEPCTL_EPTYP_Pos)	/*!< 0x00040000 */
#define USB_OTG_DOEPCTL_EPTYP_1               (0x2UL << USB_OTG_DOEPCTL_EPTYP_Pos)	/*!< 0x00080000 */
#define USB_OTG_DOEPCTL_SNPM_Pos              (20U)
#define USB_OTG_DOEPCTL_SNPM_Msk              (0x1UL << USB_OTG_DOEPCTL_SNPM_Pos)	/*!< 0x00100000 */
#define USB_OTG_DOEPCTL_SNPM                  USB_OTG_DOEPCTL_SNPM_Msk				/*!< Snoop mode */
#define USB_OTG_DOEPCTL_STALL_Pos             (21U)
#define USB_OTG_DOEPCTL_STALL_Msk             (0x1UL << USB_OTG_DOEPCTL_STALL_Pos)	/*!< 0x00200000 */
#define USB_OTG_DOEPCTL_STALL                 USB_OTG_DOEPCTL_STALL_Msk				/*!< STALL handshake */
#define USB_OTG_DOEPCTL_CNAK_Pos              (26U)
#define USB_OTG_DOEPCTL_CNAK_Msk              (0x1UL << USB_OTG_DOEPCTL_CNAK_Pos)	/*!< 0x04000000 */
#define USB_OTG_DOEPCTL_CNAK                  USB_OTG_DOEPCTL_CNAK_Msk				/*!< Clear NAK */
#define USB_OTG_DOEPCTL_SNAK_Pos              (27U)
#define USB_OTG_DOEPCTL_SNAK_Msk              (0x1UL << USB_OTG_DOEPCTL_SNAK_Pos)	/*!< 0x08000000 */
#define USB_OTG_DOEPCTL_SNAK                  USB_OTG_DOEPCTL_SNAK_Msk				/*!< Set NAK */
#define USB_OTG_DOEPCTL_EPDIS_Pos             (30U)
#define USB_OTG_DOEPCTL_EPDIS_Msk             (0x1UL << USB_OTG_DOEPCTL_EPDIS_Pos)	/*!< 0x40000000 */
#define USB_OTG_DOEPCTL_EPDIS                 USB_OTG_DOEPCTL_EPDIS_Msk				/*!< Endpoint disable */
#define USB_OTG_DOEPCTL_EPENA_Pos             (31U)
#define USB_OTG_DOEPCTL_EPENA_Msk             (0x1UL << USB_OTG_DOEPCTL_EPENA_Pos)	/*!< 0x80000000 */
#define USB_OTG_DOEPCTL_EPENA                 USB_OTG_DOEPCTL_EPENA_Msk				/*!< Endpoint enable */

/********************  Bit definition for USB_OTG_DOEPINT register  ********************/
#define USB_OTG_DOEPINT_XFRC_Pos         (0U)
#define USB_OTG_DOEPINT_XFRC_Msk         (0x1UL << USB_OTG_DOEPINT_XFRC_Pos)/*!< 0x00000001 */
#define USB_OTG_DOEPINT_XFRC             USB_OTG_DOEPINT_XFRC_Msk	/*!< Transfer completed interrupt */
#define USB_OTG_DOEPINT_EPDISD_Pos       (1U)
#define USB_OTG_DOEPINT_EPDISD_Msk       (0x1UL << USB_OTG_DOEPINT_EPDISD_Pos)	/*!< 0x00000002 */
#define USB_OTG_DOEPINT_EPDISD           USB_OTG_DOEPINT_EPDISD_Msk				/*!< Endpoint disabled interrupt */
#define USB_OTG_DOEPINT_AHBERR_Pos       (2U)
#define USB_OTG_DOEPINT_AHBERR_Msk       (0x1UL << USB_OTG_DOEPINT_AHBERR_Pos)	/*!< 0x00000004 */
#define USB_OTG_DOEPINT_AHBERR           USB_OTG_DOEPINT_AHBERR_Msk				/*!< AHB Error (AHBErr) during an OUT transaction */
#define USB_OTG_DOEPINT_STUP_Pos         (3U)
#define USB_OTG_DOEPINT_STUP_Msk         (0x1UL << USB_OTG_DOEPINT_STUP_Pos)/*!< 0x00000008 */
#define USB_OTG_DOEPINT_STUP             USB_OTG_DOEPINT_STUP_Msk	/*!< SETUP phase done */
#define USB_OTG_DOEPINT_OTEPDIS_Pos      (4U)
#define USB_OTG_DOEPINT_OTEPDIS_Msk      (0x1UL << USB_OTG_DOEPINT_OTEPDIS_Pos)	/*!< 0x00000010 */
#define USB_OTG_DOEPINT_OTEPDIS          USB_OTG_DOEPINT_OTEPDIS_Msk/*!< OUT token received when endpoint disabled */
#define USB_OTG_DOEPINT_OTEPSPR_Pos      (5U)
#define USB_OTG_DOEPINT_OTEPSPR_Msk      (0x1UL << USB_OTG_DOEPINT_OTEPSPR_Pos)	/*!< 0x00000020 */
#define USB_OTG_DOEPINT_OTEPSPR          USB_OTG_DOEPINT_OTEPSPR_Msk/*!< Status Phase Received For Control Write */
#define USB_OTG_DOEPINT_B2BSTUP_Pos      (6U)
#define USB_OTG_DOEPINT_B2BSTUP_Msk      (0x1UL << USB_OTG_DOEPINT_B2BSTUP_Pos)	/*!< 0x00000040 */
#define USB_OTG_DOEPINT_B2BSTUP          USB_OTG_DOEPINT_B2BSTUP_Msk/*!< Back-to-back SETUP packets received */
#define USB_OTG_DOEPINT_OUTPKTERR_Pos    (8U)
#define USB_OTG_DOEPINT_OUTPKTERR_Msk    (0x1UL << USB_OTG_DOEPINT_OUTPKTERR_Pos)	/*!< 0x00000100 */
#define USB_OTG_DOEPINT_OUTPKTERR        USB_OTG_DOEPINT_OUTPKTERR_Msk				/*!< OUT packet error */
#define USB_OTG_DOEPINT_NAK_Pos          (13U)
#define USB_OTG_DOEPINT_NAK_Msk          (0x1UL << USB_OTG_DOEPINT_NAK_Pos)	/*!< 0x00002000 */
#define USB_OTG_DOEPINT_NAK              USB_OTG_DOEPINT_NAK_Msk/*!< NAK Packet is transmitted by the device */
#define USB_OTG_DOEPINT_NYET_Pos         (14U)
#define USB_OTG_DOEPINT_NYET_Msk         (0x1UL << USB_OTG_DOEPINT_NYET_Pos)/*!< 0x00004000 */
#define USB_OTG_DOEPINT_NYET             USB_OTG_DOEPINT_NYET_Msk	/*!< NYET interrupt */
#define USB_OTG_DOEPINT_STPKTRX_Pos      (15U)
#define USB_OTG_DOEPINT_STPKTRX_Msk      (0x1UL << USB_OTG_DOEPINT_STPKTRX_Pos)	/*!< 0x00008000 */
#define USB_OTG_DOEPINT_STPKTRX          USB_OTG_DOEPINT_STPKTRX_Msk/*!< Setup Packet Received */

/********************  Bit definition for USB_OTG_DOEPTSIZ register  ********************/
#define USB_OTG_DOEPTSIZ_XFRSIZ_Pos     (0U)
#define USB_OTG_DOEPTSIZ_XFRSIZ_Msk     (0x7FFFFUL << USB_OTG_DOEPTSIZ_XFRSIZ_Pos)	/*!< 0x0007FFFF */
#define USB_OTG_DOEPTSIZ_XFRSIZ         USB_OTG_DOEPTSIZ_XFRSIZ_Msk					/*!< Transfer size */
#define USB_OTG_DOEPTSIZ_PKTCNT_Pos     (19U)
#define USB_OTG_DOEPTSIZ_PKTCNT_Msk     (0x3FFUL << USB_OTG_DOEPTSIZ_PKTCNT_Pos)/*!< 0x1FF80000 */
#define USB_OTG_DOEPTSIZ_PKTCNT         USB_OTG_DOEPTSIZ_PKTCNT_Msk	/*!< Packet count */

#define USB_OTG_DOEPTSIZ_STUPCNT_Pos    (29U)
#define USB_OTG_DOEPTSIZ_STUPCNT_Msk    (0x3UL << USB_OTG_DOEPTSIZ_STUPCNT_Pos)	/*!< 0x60000000 */
#define USB_OTG_DOEPTSIZ_STUPCNT        USB_OTG_DOEPTSIZ_STUPCNT_Msk/*!< SETUP packet count */
#define USB_OTG_DOEPTSIZ_STUPCNT_0      (0x1UL << USB_OTG_DOEPTSIZ_STUPCNT_Pos)	/*!< 0x20000000 */
#define USB_OTG_DOEPTSIZ_STUPCNT_1      (0x2UL << USB_OTG_DOEPTSIZ_STUPCNT_Pos)	/*!< 0x40000000 */

/********************  Bit definition for PCGCCTL register  ********************/
#define USB_OTG_PCGCCTL_STOPCLK_Pos    (0U)
#define USB_OTG_PCGCCTL_STOPCLK_Msk    (0x1UL << USB_OTG_PCGCCTL_STOPCLK_Pos)	/*!< 0x00000001 */
#define USB_OTG_PCGCCTL_STOPCLK        USB_OTG_PCGCCTL_STOPCLK_Msk				/*!< SETUP packet count */
#define USB_OTG_PCGCCTL_GATECLK_Pos    (1U)
#define USB_OTG_PCGCCTL_GATECLK_Msk    (0x1UL << USB_OTG_PCGCCTL_GATECLK_Pos)	/*!< 0x00000002 */
#define USB_OTG_PCGCCTL_GATECLK        USB_OTG_PCGCCTL_GATECLK_Msk				/*!<Bit 0 */
#define USB_OTG_PCGCCTL_PHYSUSP_Pos    (4U)
#define USB_OTG_PCGCCTL_PHYSUSP_Msk    (0x1UL << USB_OTG_PCGCCTL_PHYSUSP_Pos)	/*!< 0x00000010 */
#define USB_OTG_PCGCCTL_PHYSUSP        USB_OTG_PCGCCTL_PHYSUSP_Msk				/*!<Bit 1 */


/**
 * @}
 */

/**
 * @}
 */

/** @addtogroup Exported_macros
 * @{
 */

/******************************* ADC Instances ********************************/
#define IS_ADC_ALL_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == ADC1) || \
	((__INSTANCE__) == ADC2) || \
	((__INSTANCE__) == ADC3))
#define IS_ADC_MULTIMODE_MASTER_INSTANCE(INSTANCE)    ((INSTANCE) == ADC1)

#define IS_ADC_COMMON_INSTANCE(INSTANCE)              ((INSTANCE) == ADC123_COMMON)

/******************************* CAN Instances ********************************/
#define IS_CAN_ALL_INSTANCE(__INSTANCE__)    ((__INSTANCE__) == CAN1)
/******************************* CRC Instances ********************************/
#define IS_CRC_ALL_INSTANCE(__INSTANCE__)    ((__INSTANCE__) == CRC)

/******************************* DAC Instances ********************************/
#define IS_DAC_ALL_INSTANCE(__INSTANCE__)    ((__INSTANCE__) == DAC1)


/******************************** DMA Instances *******************************/
#define IS_DMA_STREAM_ALL_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == DMA1_Stream0) || \
	((__INSTANCE__) == DMA1_Stream1) || \
	((__INSTANCE__) == DMA1_Stream2) || \
	((__INSTANCE__) == DMA1_Stream3) || \
	((__INSTANCE__) == DMA1_Stream4) || \
	((__INSTANCE__) == DMA1_Stream5) || \
	((__INSTANCE__) == DMA1_Stream6) || \
	((__INSTANCE__) == DMA1_Stream7) || \
	((__INSTANCE__) == DMA2_Stream0) || \
	((__INSTANCE__) == DMA2_Stream1) || \
	((__INSTANCE__) == DMA2_Stream2) || \
	((__INSTANCE__) == DMA2_Stream3) || \
	((__INSTANCE__) == DMA2_Stream4) || \
	((__INSTANCE__) == DMA2_Stream5) || \
	((__INSTANCE__) == DMA2_Stream6) || \
	((__INSTANCE__) == DMA2_Stream7))

/******************************* GPIO Instances *******************************/
#define IS_GPIO_ALL_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == GPIOA) || \
	((__INSTANCE__) == GPIOB) || \
	((__INSTANCE__) == GPIOC) || \
	((__INSTANCE__) == GPIOD) || \
	((__INSTANCE__) == GPIOE) || \
	((__INSTANCE__) == GPIOF) || \
	((__INSTANCE__) == GPIOG) || \
	((__INSTANCE__) == GPIOH) || \
	((__INSTANCE__) == GPIOI))

#define IS_GPIO_AF_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == GPIOA) || \
	((__INSTANCE__) == GPIOB) || \
	((__INSTANCE__) == GPIOC) || \
	((__INSTANCE__) == GPIOD) || \
	((__INSTANCE__) == GPIOE) || \
	((__INSTANCE__) == GPIOF) || \
	((__INSTANCE__) == GPIOG) || \
	((__INSTANCE__) == GPIOH) || \
	((__INSTANCE__) == GPIOI))


/****************************** QSPI Instances *********************************/
#define IS_QSPI_ALL_INSTANCE(__INSTANCE__)    ((__INSTANCE__) == QUADSPI)


/******************************** I2C Instances *******************************/
#define IS_I2C_ALL_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == I2C1) || \
	((__INSTANCE__) == I2C2) || \
	((__INSTANCE__) == I2C3))

/****************************** SMBUS Instances *******************************/
#define IS_SMBUS_ALL_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == I2C1) || \
	((__INSTANCE__) == I2C2) || \
	((__INSTANCE__) == I2C3))


/******************************** I2S Instances *******************************/
#define IS_I2S_ALL_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == SPI1) || \
	((__INSTANCE__) == SPI2) || \
	((__INSTANCE__) == SPI3))

/******************************* LPTIM Instances ********************************/
#define IS_LPTIM_INSTANCE(__INSTANCE__)    ((__INSTANCE__) == LPTIM1)


/******************************* RNG Instances ********************************/
#define IS_RNG_ALL_INSTANCE(__INSTANCE__)    ((__INSTANCE__) == RNG)

/****************************** RTC Instances *********************************/
#define IS_RTC_ALL_INSTANCE(__INSTANCE__)    ((__INSTANCE__) == RTC)

/******************************* SAI Instances ********************************/
#define IS_SAI_ALL_INSTANCE(__PERIPH__) \
	(((__PERIPH__) == SAI1_Block_A) || \
	((__PERIPH__) == SAI1_Block_B) || \
	((__PERIPH__) == SAI2_Block_A) || \
	((__PERIPH__) == SAI2_Block_B))
/* Legacy define */
#define IS_SAI_BLOCK_PERIPH    IS_SAI_ALL_INSTANCE

/******************************** SDMMC Instances *******************************/
#define IS_SDMMC_ALL_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == SDMMC1) || \
	((__INSTANCE__) == SDMMC2))


/******************************** SPI Instances *******************************/
#define IS_SPI_ALL_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == SPI1) || \
	((__INSTANCE__) == SPI2) || \
	((__INSTANCE__) == SPI3) || \
	((__INSTANCE__) == SPI4) || \
	((__INSTANCE__) == SPI5))

/****************** TIM Instances : All supported instances *******************/
#define IS_TIM_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM6) || \
	((__INSTANCE__) == TIM7) || \
	((__INSTANCE__) == TIM8) || \
	((__INSTANCE__) == TIM9) || \
	((__INSTANCE__) == TIM10) || \
	((__INSTANCE__) == TIM11) || \
	((__INSTANCE__) == TIM12) || \
	((__INSTANCE__) == TIM13) || \
	((__INSTANCE__) == TIM14))

/****************** TIM Instances : supporting 32 bits counter ****************/
#define IS_TIM_32B_COUNTER_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM5))

/****************** TIM Instances : supporting the break function *************/
#define IS_TIM_BREAK_INSTANCE(INSTANCE) \
	(((INSTANCE) == TIM1) || \
	((INSTANCE) == TIM8))

/************** TIM Instances : supporting Break source selection *************/
#define IS_TIM_BREAKSOURCE_INSTANCE(INSTANCE) \
	(((INSTANCE) == TIM1) || \
	((INSTANCE) == TIM8))

/****************** TIM Instances : supporting 2 break inputs *****************/
#define IS_TIM_BKIN2_INSTANCE(INSTANCE) \
	(((INSTANCE) == TIM1) || \
	((INSTANCE) == TIM8))

/************* TIM Instances : at least 1 capture/compare channel *************/
#define IS_TIM_CC1_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8) || \
	((__INSTANCE__) == TIM9) || \
	((__INSTANCE__) == TIM10) || \
	((__INSTANCE__) == TIM11) || \
	((__INSTANCE__) == TIM12) || \
	((__INSTANCE__) == TIM13) || \
	((__INSTANCE__) == TIM14))

/************ TIM Instances : at least 2 capture/compare channels *************/
#define IS_TIM_CC2_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8) || \
	((__INSTANCE__) == TIM9) || \
	((__INSTANCE__) == TIM12))

/************ TIM Instances : at least 3 capture/compare channels *************/
#define IS_TIM_CC3_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8))

/************ TIM Instances : at least 4 capture/compare channels *************/
#define IS_TIM_CC4_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8))

/****************** TIM Instances : at least 5 capture/compare channels *******/
#define IS_TIM_CC5_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM8))

/****************** TIM Instances : at least 6 capture/compare channels *******/
#define IS_TIM_CC6_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM8))

/************ TIM Instances : DMA requests generation (TIMx_DIER.COMDE) *******/
#define IS_TIM_CCDMA_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM8))

/****************** TIM Instances : DMA requests generation (TIMx_DIER.UDE) ***/
#define IS_TIM_DMA_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM8) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM6) || \
	((__INSTANCE__) == TIM7))

/************ TIM Instances : DMA requests generation (CCxDE) *****************/
#define IS_TIM_DMA_CC_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8))

/******************** TIM Instances : DMA burst feature ***********************/
#define IS_TIM_DMABURST_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8))

/****************** TIM Instances : supporting combined 3-phase PWM mode ******/
#define IS_TIM_COMBINED3PHASEPWM_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM8))

/****************** TIM Instances : supporting counting mode selection ********/
#define IS_TIM_COUNTER_MODE_SELECT_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8))

/****************** TIM Instances : supporting encoder interface **************/
#define IS_TIM_ENCODER_INTERFACE_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8))

/****************** TIM Instances : supporting OCxREF clear *******************/
#define IS_TIM_OCXREF_CLEAR_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5))

/****************** TIM Instances : supporting external clock mode 1 for TIX inputs*/
#define IS_TIM_CLOCKSOURCE_TIX_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8))

/****************** TIM Instances : supporting internal trigger inputs(ITRX) *******/
#define IS_TIM_CLOCKSOURCE_ITRX_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8))

/******************** TIM Instances : Advanced-control timers *****************/
#define IS_TIM_ADVANCED_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM8))

/******************* TIM Instances : Timer input XOR function *****************/
#define IS_TIM_XOR_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8))

/****** TIM Instances : master mode available (TIMx_CR2.MMS available )********/
#define IS_TIM_MASTER_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM6) || \
	((__INSTANCE__) == TIM7) || \
	((__INSTANCE__) == TIM8))

/*********** TIM Instances : Slave mode available (TIMx_SMCR available )*******/
#define IS_TIM_SLAVE_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8) || \
	((__INSTANCE__) == TIM9) || \
	((__INSTANCE__) == TIM12))

/***************** TIM Instances : external trigger input available ************/
#define IS_TIM_ETR_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8))

/****************** TIM Instances : remapping capability **********************/
#define IS_TIM_REMAP_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM11))

/******************* TIM Instances : output(s) available **********************/
#define IS_TIM_CCX_INSTANCE(__INSTANCE__, __CHANNEL__) \
	((((__INSTANCE__) == TIM1) &&                  \
	(((__CHANNEL__) == TIM_CHANNEL_1) ||          \
	((__CHANNEL__) == TIM_CHANNEL_2) ||          \
	((__CHANNEL__) == TIM_CHANNEL_3) ||          \
	((__CHANNEL__) == TIM_CHANNEL_4) ||          \
	((__CHANNEL__) == TIM_CHANNEL_5) ||          \
	((__CHANNEL__) == TIM_CHANNEL_6)))           \
	||                                         \
	(((__INSTANCE__) == TIM2) &&                   \
	(((__CHANNEL__) == TIM_CHANNEL_1) ||          \
	((__CHANNEL__) == TIM_CHANNEL_2) ||          \
	((__CHANNEL__) == TIM_CHANNEL_3) ||          \
	((__CHANNEL__) == TIM_CHANNEL_4)))           \
	||                                         \
	(((__INSTANCE__) == TIM3) &&                   \
	(((__CHANNEL__) == TIM_CHANNEL_1) ||          \
	((__CHANNEL__) == TIM_CHANNEL_2) ||          \
	((__CHANNEL__) == TIM_CHANNEL_3) ||          \
	((__CHANNEL__) == TIM_CHANNEL_4)))           \
	||                                         \
	(((__INSTANCE__) == TIM4) &&                   \
	(((__CHANNEL__) == TIM_CHANNEL_1) ||          \
	((__CHANNEL__) == TIM_CHANNEL_2) ||          \
	((__CHANNEL__) == TIM_CHANNEL_3) ||          \
	((__CHANNEL__) == TIM_CHANNEL_4)))           \
	||                                         \
	(((__INSTANCE__) == TIM5) &&                   \
	(((__CHANNEL__) == TIM_CHANNEL_1) ||          \
	((__CHANNEL__) == TIM_CHANNEL_2) ||          \
	((__CHANNEL__) == TIM_CHANNEL_3) ||          \
	((__CHANNEL__) == TIM_CHANNEL_4)))           \
	||                                         \
	(((__INSTANCE__) == TIM8) &&                   \
	(((__CHANNEL__) == TIM_CHANNEL_1) ||          \
	((__CHANNEL__) == TIM_CHANNEL_2) ||          \
	((__CHANNEL__) == TIM_CHANNEL_3) ||          \
	((__CHANNEL__) == TIM_CHANNEL_4) ||          \
	((__CHANNEL__) == TIM_CHANNEL_5) ||          \
	((__CHANNEL__) == TIM_CHANNEL_6)))           \
	||                                         \
	(((__INSTANCE__) == TIM9) &&                   \
	(((__CHANNEL__) == TIM_CHANNEL_1) ||          \
	((__CHANNEL__) == TIM_CHANNEL_2)))           \
	||                                         \
	(((__INSTANCE__) == TIM10) &&                  \
	(((__CHANNEL__) == TIM_CHANNEL_1)))           \
	||                                         \
	(((__INSTANCE__) == TIM11) &&                  \
	(((__CHANNEL__) == TIM_CHANNEL_1)))           \
	||                                         \
	(((__INSTANCE__) == TIM12) &&                  \
	(((__CHANNEL__) == TIM_CHANNEL_1) ||          \
	((__CHANNEL__) == TIM_CHANNEL_2)))           \
	||                                         \
	(((__INSTANCE__) == TIM13) &&                  \
	(((__CHANNEL__) == TIM_CHANNEL_1)))           \
	||                                         \
	(((__INSTANCE__) == TIM14) &&                  \
	(((__CHANNEL__) == TIM_CHANNEL_1))))

/************ TIM Instances : complementary output(s) available ***************/
#define IS_TIM_CCXN_INSTANCE(__INSTANCE__, __CHANNEL__) \
	((((__INSTANCE__) == TIM1) &&                    \
	(((__CHANNEL__) == TIM_CHANNEL_1) ||           \
	((__CHANNEL__) == TIM_CHANNEL_2) ||           \
	((__CHANNEL__) == TIM_CHANNEL_3)))            \
	||                                          \
	(((__INSTANCE__) == TIM8) &&                    \
	(((__CHANNEL__) == TIM_CHANNEL_1) ||           \
	((__CHANNEL__) == TIM_CHANNEL_2) ||           \
	((__CHANNEL__) == TIM_CHANNEL_3))))

/****************** TIM Instances : supporting ADC triggering through TRGO2 ***/
#define IS_TIM_TRGO2_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM8) )

/****************** TIM Instances : supporting synchronization ****************/
#define IS_TIM_SYNCHRO_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM6) || \
	((__INSTANCE__) == TIM7) || \
	((__INSTANCE__) == TIM8))

/****************** TIM Instances : supporting clock division *****************/
#define IS_TIM_CLOCK_DIVISION_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8) || \
	((__INSTANCE__) == TIM9) || \
	((__INSTANCE__) == TIM10) || \
	((__INSTANCE__) == TIM11) || \
	((__INSTANCE__) == TIM12) || \
	((__INSTANCE__) == TIM13) || \
	((__INSTANCE__) == TIM14))

/****************** TIM Instances : supporting repetition counter *************/
#define IS_TIM_REPETITION_COUNTER_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM8))

/****** TIM Instances : supporting external clock mode 1 for ETRF input *******/
#define IS_TIM_CLOCKSOURCE_ETRMODE1_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8) || \
	((__INSTANCE__) == TIM9) || \
	((__INSTANCE__) == TIM12))

/****** TIM Instances : supporting external clock mode 2 for ETRF input *******/
#define IS_TIM_CLOCKSOURCE_ETRMODE2_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8))

/****************** TIM Instances : supporting Hall sensor interface **********/
#define IS_TIM_HALL_SENSOR_INTERFACE_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM2) || \
	((__INSTANCE__) == TIM3) || \
	((__INSTANCE__) == TIM4) || \
	((__INSTANCE__) == TIM5) || \
	((__INSTANCE__) == TIM8))

/****************** TIM Instances : supporting commutation event generation ***/
#define IS_TIM_COMMUTATION_EVENT_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == TIM1) || \
	((__INSTANCE__) == TIM8))

/******************** USART Instances : Synchronous mode **********************/
#define IS_USART_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == USART1) || \
	((__INSTANCE__) == USART2) || \
	((__INSTANCE__) == USART3) || \
	((__INSTANCE__) == USART6))

/******************** UART Instances : Asynchronous mode **********************/
#define IS_UART_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == USART1) || \
	((__INSTANCE__) == USART2) || \
	((__INSTANCE__) == USART3) || \
	((__INSTANCE__) == UART4) || \
	((__INSTANCE__) == UART5) || \
	((__INSTANCE__) == USART6) || \
	((__INSTANCE__) == UART7) || \
	((__INSTANCE__) == UART8))

/****************** UART Instances : Auto Baud Rate detection ****************/
#define IS_USART_AUTOBAUDRATE_DETECTION_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == USART1) || \
	((__INSTANCE__) == USART2) || \
	((__INSTANCE__) == USART3) || \
	((__INSTANCE__) == USART6))

/****************** UART Instances : Driver Enable *****************/
#define IS_UART_DRIVER_ENABLE_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == USART1) || \
	((__INSTANCE__) == USART2) || \
	((__INSTANCE__) == USART3) || \
	((__INSTANCE__) == UART4) || \
	((__INSTANCE__) == UART5) || \
	((__INSTANCE__) == USART6) || \
	((__INSTANCE__) == UART7) || \
	((__INSTANCE__) == UART8))

/******************** UART Instances : Half-Duplex mode **********************/
#define IS_UART_HALFDUPLEX_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == USART1) || \
	((__INSTANCE__) == USART2) || \
	((__INSTANCE__) == USART3) || \
	((__INSTANCE__) == UART4) || \
	((__INSTANCE__) == UART5) || \
	((__INSTANCE__) == USART6) || \
	((__INSTANCE__) == UART7) || \
	((__INSTANCE__) == UART8))

/****************** UART Instances : Hardware Flow control ********************/
#define IS_UART_HWFLOW_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == USART1) || \
	((__INSTANCE__) == USART2) || \
	((__INSTANCE__) == USART3) || \
	((__INSTANCE__) == UART4) || \
	((__INSTANCE__) == UART5) || \
	((__INSTANCE__) == USART6) || \
	((__INSTANCE__) == UART7) || \
	((__INSTANCE__) == UART8))

/******************** UART Instances : LIN mode **********************/
#define IS_UART_LIN_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == USART1) || \
	((__INSTANCE__) == USART2) || \
	((__INSTANCE__) == USART3) || \
	((__INSTANCE__) == UART4) || \
	((__INSTANCE__) == UART5) || \
	((__INSTANCE__) == USART6) || \
	((__INSTANCE__) == UART7) || \
	((__INSTANCE__) == UART8))

/********************* UART Instances : Smart card mode ***********************/
#define IS_SMARTCARD_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == USART1) || \
	((__INSTANCE__) == USART2) || \
	((__INSTANCE__) == USART3) || \
	((__INSTANCE__) == USART6))

/*********************** UART Instances : IRDA mode ***************************/
#define IS_IRDA_INSTANCE(__INSTANCE__) \
	(((__INSTANCE__) == USART1) || \
	((__INSTANCE__) == USART2) || \
	((__INSTANCE__) == USART3) || \
	((__INSTANCE__) == UART4) || \
	((__INSTANCE__) == UART5) || \
	((__INSTANCE__) == USART6) || \
	((__INSTANCE__) == UART7) || \
	((__INSTANCE__) == UART8))

/****************************** IWDG Instances ********************************/
#define IS_IWDG_ALL_INSTANCE(__INSTANCE__)    ((__INSTANCE__) == IWDG)

/****************************** WWDG Instances ********************************/
#define IS_WWDG_ALL_INSTANCE(__INSTANCE__)    ((__INSTANCE__) == WWDG)

/*********************** PCD Instances ****************************************/
#define IS_PCD_ALL_INSTANCE(INSTANCE) \
	(((INSTANCE) == USB_OTG_FS) || \
	((INSTANCE) == USB_OTG_HS))

/*********************** HCD Instances ****************************************/
#define IS_HCD_ALL_INSTANCE(INSTANCE) \
	(((INSTANCE) == USB_OTG_FS) || \
	((INSTANCE) == USB_OTG_HS))

/******************************************************************************/
/*  For a painless codes migration between the STM32F7xx device product       */
/*  lines, the aliases defined below are put in place to overcome the         */
/*  differences in the interrupt handlers and IRQn definitions.               */
/*  No need to update developed interrupt code when moving across             */
/*  product lines within the same STM32F7 Family                              */
/******************************************************************************/

/* Aliases for __IRQn */
#define HASH_RNG_IRQn    RNG_IRQn

/* Aliases for __IRQHandler */
#define HASH_RNG_IRQHandler    RNG_IRQHandler

/**
 * @}
 */

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif	/* __cplusplus */

#endif	/* __STM32F722xx_H */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
