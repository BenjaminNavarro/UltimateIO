/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : stm32f10x_map.h
* Author             : MCD Application Team
* Version            : V2.0.2
* Date               : 07/11/2008
* Description        : This file contains all the peripheral register's definitions
*                      and memory mapping.
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F10x_MAP_H
#define __STM32F10x_MAP_H

#ifndef EXT
  #define EXT extern
#endif /* EXT */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_conf.h"
#include "stm32f10x_type.h"
#include "cortexm3_macro.h"

/* Exported types ------------------------------------------------------------*/
/******************************************************************************/
/*                         Peripheral registers structures                    */
/******************************************************************************/

/*------------------------ Nested Vectored Interrupt Controller --------------*/
typedef struct
{
  vu32 ISER[2];
  u32  RESERVED0[30];
  vu32 ICER[2];
  u32  RSERVED1[30];
  vu32 ISPR[2];
  u32  RESERVED2[30];
  vu32 ICPR[2];
  u32  RESERVED3[30];
  vu32 IABR[2];
  u32  RESERVED4[62];
  vu32 IPR[15];
} NVIC_TypeDef;

typedef struct
{
  vuc32 CPUID;
  vu32 ICSR;
  vu32 VTOR;
  vu32 AIRCR;
  vu32 SCR;
  vu32 CCR;
  vu32 SHPR[3];
  vu32 SHCSR;
  vu32 CFSR;
  vu32 HFSR;
  vu32 DFSR;
  vu32 MMFAR;
  vu32 BFAR;
  vu32 AFSR;
} SCB_TypeDef;

/*------------------------ SystemTick ----------------------------------------*/
typedef struct
{
  vu32 CTRL;
  vu32 LOAD;
  vu32 VAL;
  vuc32 CALIB;
} SysTick_TypeDef;

/* Peripheral memory map */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)

#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400)
#define RTC_BASE              (APB1PERIPH_BASE + 0x2800)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x2C00)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x3000)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00)
//#define USART2_BASE           (APB1PERIPH_BASE + 0x4400)
//#define USART3_BASE           (APB1PERIPH_BASE + 0x4800)
#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00)
#define UART5_BASE            (APB1PERIPH_BASE + 0x5000)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800)
#define CAN_BASE              (APB1PERIPH_BASE + 0x6400)
#define BKP_BASE              (APB1PERIPH_BASE + 0x6C00)
#define PWR_BASE              (APB1PERIPH_BASE + 0x7000)
#define DAC_BASE              (APB1PERIPH_BASE + 0x7400)

#define AFIO_BASE             (APB2PERIPH_BASE + 0x0000)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x0400)
//#define GPIOA_BASE            (APB2PERIPH_BASE + 0x0800)
//#define GPIOB_BASE            (APB2PERIPH_BASE + 0x0C00)
//#define GPIOC_BASE            (APB2PERIPH_BASE + 0x1000)
//#define GPIOD_BASE            (APB2PERIPH_BASE + 0x1400)
//#define GPIOE_BASE            (APB2PERIPH_BASE + 0x1800)
//#define GPIOF_BASE            (APB2PERIPH_BASE + 0x1C00)
//#define GPIOG_BASE            (APB2PERIPH_BASE + 0x2000)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x2400)
#define ADC2_BASE             (APB2PERIPH_BASE + 0x2800)
#define TIM1_BASE             (APB2PERIPH_BASE + 0x2C00)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x3400)
//#define USART1_BASE           (APB2PERIPH_BASE + 0x3800)
#define ADC3_BASE             (APB2PERIPH_BASE + 0x3C00)

#define SDIO_BASE             (PERIPH_BASE + 0x18000)

#define DMA1_BASE             (AHBPERIPH_BASE + 0x0000)
#define DMA1_Channel1_BASE    (AHBPERIPH_BASE + 0x0008)
#define DMA1_Channel2_BASE    (AHBPERIPH_BASE + 0x001C)
#define DMA1_Channel3_BASE    (AHBPERIPH_BASE + 0x0030)
#define DMA1_Channel4_BASE    (AHBPERIPH_BASE + 0x0044)
#define DMA1_Channel5_BASE    (AHBPERIPH_BASE + 0x0058)
#define DMA1_Channel6_BASE    (AHBPERIPH_BASE + 0x006C)
#define DMA1_Channel7_BASE    (AHBPERIPH_BASE + 0x0080)
#define DMA2_BASE             (AHBPERIPH_BASE + 0x0400)
#define DMA2_Channel1_BASE    (AHBPERIPH_BASE + 0x0408)
#define DMA2_Channel2_BASE    (AHBPERIPH_BASE + 0x041C)
#define DMA2_Channel3_BASE    (AHBPERIPH_BASE + 0x0430)
#define DMA2_Channel4_BASE    (AHBPERIPH_BASE + 0x0444)
#define DMA2_Channel5_BASE    (AHBPERIPH_BASE + 0x0458)
#define RCC_BASE              (AHBPERIPH_BASE + 0x1000)
#define CRC_BASE              (AHBPERIPH_BASE + 0x3000)

/* Flash registers base address */
#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x2000)

/* FSMC Bankx registers base address */
#define FSMC_Bank1_R_BASE     (FSMC_R_BASE + 0x0000)
#define FSMC_Bank1E_R_BASE    (FSMC_R_BASE + 0x0104)
#define FSMC_Bank2_R_BASE     (FSMC_R_BASE + 0x0060)
#define FSMC_Bank3_R_BASE     (FSMC_R_BASE + 0x0080)
#define FSMC_Bank4_R_BASE     (FSMC_R_BASE + 0x00A0)

#define SysTick_BASE          (SCS_BASE + 0x0010)
#define NVIC_BASE             (SCS_BASE + 0x0100)
#define SCB_BASE              (SCS_BASE + 0x0D00)

/******************************************************************************/
/*                         Peripheral declaration                             */
/******************************************************************************/

/*------------------------ Non Debug Mode ------------------------------------*/
#ifndef DEBUG
#ifdef _TIM2
  #define TIM2                ((TIM_TypeDef *) TIM2_BASE)
#endif /*_TIM2 */

#ifdef _TIM3
  #define TIM3                ((TIM_TypeDef *) TIM3_BASE)
#endif /*_TIM3 */

#ifdef _TIM4
  #define TIM4                ((TIM_TypeDef *) TIM4_BASE)
#endif /*_TIM4 */

#ifdef _TIM5
  #define TIM5                ((TIM_TypeDef *) TIM5_BASE)
#endif /*_TIM5 */

#ifdef _TIM6
  #define TIM6                ((TIM_TypeDef *) TIM6_BASE)
#endif /*_TIM6 */

#ifdef _TIM7
  #define TIM7                ((TIM_TypeDef *) TIM7_BASE)
#endif /*_TIM7 */

#ifdef _RTC
  #define RTC                 ((RTC_TypeDef *) RTC_BASE)
#endif /*_RTC */

#ifdef _WWDG
  #define WWDG                ((WWDG_TypeDef *) WWDG_BASE)
#endif /*_WWDG */

#ifdef _IWDG
  #define IWDG                ((IWDG_TypeDef *) IWDG_BASE)
#endif /*_IWDG */

#ifdef _SPI2
  #define SPI2                ((SPI_TypeDef *) SPI2_BASE)
#endif /*_SPI2 */

#ifdef _SPI3
  #define SPI3                ((SPI_TypeDef *) SPI3_BASE)
#endif /*_SPI3 */

#ifdef _USART2
  #define USART2              ((USART_TypeDef *) USART2_BASE)
#endif /*_USART2 */

#ifdef _USART3
  #define USART3              ((USART_TypeDef *) USART3_BASE)
#endif /*_USART3 */

#ifdef _UART4
  #define UART4              ((USART_TypeDef *) UART4_BASE)
#endif /*_UART4 */

#ifdef _UART5
  #define UART5              ((USART_TypeDef *) UART5_BASE)
#endif /*_USART5 */

#ifdef _I2C1
  #define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#endif /*_I2C1 */

#ifdef _I2C2
  #define I2C2                ((I2C_TypeDef *) I2C2_BASE)
#endif /*_I2C2 */

#ifdef _CAN
  #define CAN                 ((CAN_TypeDef *) CAN_BASE)
#endif /*_CAN */

#ifdef _BKP
  #define BKP                 ((BKP_TypeDef *) BKP_BASE)
#endif /*_BKP */

#ifdef _PWR
  #define PWR                 ((PWR_TypeDef *) PWR_BASE)
#endif /*_PWR */

#ifdef _DAC
  #define DAC                 ((DAC_TypeDef *) DAC_BASE)
#endif /*_DAC */

#ifdef _AFIO
  #define AFIO                ((AFIO_TypeDef *) AFIO_BASE)
#endif /*_AFIO */

#ifdef _EXTI
  #define EXTI                ((EXTI_TypeDef *) EXTI_BASE)
#endif /*_EXTI */

#ifdef _GPIOA
  #define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#endif /*_GPIOA */

#ifdef _GPIOB
  #define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#endif /*_GPIOB */

#ifdef _GPIOC
  #define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#endif /*_GPIOC */

#ifdef _GPIOD
  #define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#endif /*_GPIOD */

#ifdef _GPIOE
  #define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#endif /*_GPIOE */

#ifdef _GPIOF
  #define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#endif /*_GPIOF */

#ifdef _GPIOG
  #define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#endif /*_GPIOG */

#ifdef _ADC1
  #define ADC1                ((ADC_TypeDef *) ADC1_BASE)
#endif /*_ADC1 */

#ifdef _ADC2
  #define ADC2                ((ADC_TypeDef *) ADC2_BASE)
#endif /*_ADC2 */

#ifdef _TIM1
  #define TIM1                ((TIM_TypeDef *) TIM1_BASE)
#endif /*_TIM1 */

#ifdef _SPI1
  #define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#endif /*_SPI1 */

#ifdef _TIM8
  #define TIM8                ((TIM_TypeDef *) TIM8_BASE)
#endif /*_TIM8 */

#ifdef _USART1
  #define USART1              ((USART_TypeDef *) USART1_BASE)
#endif /*_USART1 */

#ifdef _ADC3
  #define ADC3                ((ADC_TypeDef *) ADC3_BASE)
#endif /*_ADC3 */

#ifdef _SDIO
  #define SDIO                ((SDIO_TypeDef *) SDIO_BASE)
#endif /*_SDIO */

#ifdef _DMA
  #define DMA1                ((DMA_TypeDef *) DMA1_BASE)
  #define DMA2                ((DMA_TypeDef *) DMA2_BASE)
#endif /*_DMA */

#ifdef _DMA1_Channel1
  #define DMA1_Channel1       ((DMA_Channel_TypeDef *) DMA1_Channel1_BASE)
#endif /*_DMA1_Channel1 */

#ifdef _DMA1_Channel2
  #define DMA1_Channel2       ((DMA_Channel_TypeDef *) DMA1_Channel2_BASE)
#endif /*_DMA1_Channel2 */

#ifdef _DMA1_Channel3
  #define DMA1_Channel3       ((DMA_Channel_TypeDef *) DMA1_Channel3_BASE)
#endif /*_DMA1_Channel3 */

#ifdef _DMA1_Channel4
  #define DMA1_Channel4       ((DMA_Channel_TypeDef *) DMA1_Channel4_BASE)
#endif /*_DMA1_Channel4 */

#ifdef _DMA1_Channel5
  #define DMA1_Channel5       ((DMA_Channel_TypeDef *) DMA1_Channel5_BASE)
#endif /*_DMA1_Channel5 */

#ifdef _DMA1_Channel6
  #define DMA1_Channel6       ((DMA_Channel_TypeDef *) DMA1_Channel6_BASE)
#endif /*_DMA1_Channel6 */

#ifdef _DMA1_Channel7
  #define DMA1_Channel7       ((DMA_Channel_TypeDef *) DMA1_Channel7_BASE)
#endif /*_DMA1_Channel7 */

#ifdef _DMA2_Channel1
  #define DMA2_Channel1       ((DMA_Channel_TypeDef *) DMA2_Channel1_BASE)
#endif /*_DMA2_Channel1 */

#ifdef _DMA2_Channel2
  #define DMA2_Channel2       ((DMA_Channel_TypeDef *) DMA2_Channel2_BASE)
#endif /*_DMA2_Channel2 */

#ifdef _DMA2_Channel3
  #define DMA2_Channel3       ((DMA_Channel_TypeDef *) DMA2_Channel3_BASE)
#endif /*_DMA2_Channel3 */

#ifdef _DMA2_Channel4
  #define DMA2_Channel4       ((DMA_Channel_TypeDef *) DMA2_Channel4_BASE)
#endif /*_DMA2_Channel4 */

#ifdef _DMA2_Channel5
  #define DMA2_Channel5       ((DMA_Channel_TypeDef *) DMA2_Channel5_BASE)
#endif /*_DMA2_Channel5 */

#ifdef _RCC
  #define RCC                 ((RCC_TypeDef *) RCC_BASE)
#endif /*_RCC */

#ifdef _CRC
  #define CRC                 ((CRC_TypeDef *) CRC_BASE)
#endif /*_CRC */

#ifdef _FLASH
  #define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)
  #define OB                  ((OB_TypeDef *) OB_BASE) 
#endif /*_FLASH */

#ifdef _FSMC
  #define FSMC_Bank1          ((FSMC_Bank1_TypeDef *) FSMC_Bank1_R_BASE)
  #define FSMC_Bank1E         ((FSMC_Bank1E_TypeDef *) FSMC_Bank1E_R_BASE)
  #define FSMC_Bank2          ((FSMC_Bank2_TypeDef *) FSMC_Bank2_R_BASE)
  #define FSMC_Bank3          ((FSMC_Bank3_TypeDef *) FSMC_Bank3_R_BASE)
  #define FSMC_Bank4          ((FSMC_Bank4_TypeDef *) FSMC_Bank4_R_BASE)
#endif /*_FSMC */

#ifdef _DBGMCU
  #define DBGMCU              ((DBGMCU_TypeDef *) DBGMCU_BASE)
#endif /*_DBGMCU */

#ifdef _SysTick
  #define SysTick             ((SysTick_TypeDef *) SysTick_BASE)
#endif /*_SysTick */

#ifdef _NVIC
  #define NVIC                ((NVIC_TypeDef *) NVIC_BASE)
  #define SCB                 ((SCB_TypeDef *) SCB_BASE)  
#endif /*_NVIC */

/*------------------------ Debug Mode ----------------------------------------*/
#else   /* DEBUG */
#ifdef _TIM2
  EXT TIM_TypeDef             *TIM2;
#endif /*_TIM2 */

#ifdef _TIM3
  EXT TIM_TypeDef             *TIM3;
#endif /*_TIM3 */

#ifdef _TIM4
  EXT TIM_TypeDef             *TIM4;
#endif /*_TIM4 */

#ifdef _TIM5
  EXT TIM_TypeDef             *TIM5;
#endif /*_TIM5 */

#ifdef _TIM6
  EXT TIM_TypeDef             *TIM6;
#endif /*_TIM6 */

#ifdef _TIM7
  EXT TIM_TypeDef             *TIM7;
#endif /*_TIM7 */

#ifdef _RTC
  EXT RTC_TypeDef             *RTC;
#endif /*_RTC */

#ifdef _WWDG
  EXT WWDG_TypeDef            *WWDG;
#endif /*_WWDG */

#ifdef _IWDG
  EXT IWDG_TypeDef            *IWDG;
#endif /*_IWDG */

#ifdef _SPI2
  EXT SPI_TypeDef             *SPI2;
#endif /*_SPI2 */

#ifdef _SPI3
  EXT SPI_TypeDef             *SPI3;
#endif /*_SPI3 */

#ifdef _USART2
  EXT USART_TypeDef           *USART2;
#endif /*_USART2 */

#ifdef _USART3
  EXT USART_TypeDef           *USART3;
#endif /*_USART3 */

#ifdef _UART4
  EXT USART_TypeDef           *UART4;
#endif /*_UART4 */

#ifdef _UART5
  EXT USART_TypeDef           *UART5;
#endif /*_UART5 */

#ifdef _I2C1
  EXT I2C_TypeDef             *I2C1;
#endif /*_I2C1 */

#ifdef _I2C2
  EXT I2C_TypeDef             *I2C2;
#endif /*_I2C2 */

#ifdef _CAN
  EXT CAN_TypeDef             *CAN;
#endif /*_CAN */

#ifdef _BKP
  EXT BKP_TypeDef             *BKP;
#endif /*_BKP */

#ifdef _PWR
  EXT PWR_TypeDef             *PWR;
#endif /*_PWR */

#ifdef _DAC
  EXT DAC_TypeDef             *DAC;
#endif /*_DAC */

#ifdef _AFIO
  EXT AFIO_TypeDef            *AFIO;
#endif /*_AFIO */

#ifdef _EXTI
  EXT EXTI_TypeDef            *EXTI;
#endif /*_EXTI */

#ifdef _GPIOA
  EXT GPIO_TypeDef            *GPIOA;
#endif /*_GPIOA */

#ifdef _GPIOB
  EXT GPIO_TypeDef            *GPIOB;
#endif /*_GPIOB */

#ifdef _GPIOC
  EXT GPIO_TypeDef            *GPIOC;
#endif /*_GPIOC */

#ifdef _GPIOD
  EXT GPIO_TypeDef            *GPIOD;
#endif /*_GPIOD */

#ifdef _GPIOE
  EXT GPIO_TypeDef            *GPIOE;
#endif /*_GPIOE */

#ifdef _GPIOF
  EXT GPIO_TypeDef            *GPIOF;
#endif /*_GPIOF */

#ifdef _GPIOG
  EXT GPIO_TypeDef            *GPIOG;
#endif /*_GPIOG */

#ifdef _ADC1
  EXT ADC_TypeDef             *ADC1;
#endif /*_ADC1 */

#ifdef _ADC2
  EXT ADC_TypeDef             *ADC2;
#endif /*_ADC2 */

#ifdef _TIM1
  EXT TIM_TypeDef             *TIM1;
#endif /*_TIM1 */

#ifdef _SPI1
  EXT SPI_TypeDef             *SPI1;
#endif /*_SPI1 */

#ifdef _TIM8
  EXT TIM_TypeDef             *TIM8;
#endif /*_TIM8 */

#ifdef _USART1
  EXT USART_TypeDef           *USART1;
#endif /*_USART1 */

#ifdef _ADC3
  EXT ADC_TypeDef             *ADC3;
#endif /*_ADC3 */

#ifdef _SDIO
  EXT SDIO_TypeDef            *SDIO;
#endif /*_SDIO */

#ifdef _DMA
  EXT DMA_TypeDef             *DMA1;
  EXT DMA_TypeDef             *DMA2;
#endif /*_DMA */

#ifdef _DMA1_Channel1
  EXT DMA_Channel_TypeDef     *DMA1_Channel1;
#endif /*_DMA1_Channel1 */

#ifdef _DMA1_Channel2
  EXT DMA_Channel_TypeDef     *DMA1_Channel2;
#endif /*_DMA1_Channel2 */

#ifdef _DMA1_Channel3
  EXT DMA_Channel_TypeDef     *DMA1_Channel3;
#endif /*_DMA1_Channel3 */

#ifdef _DMA1_Channel4
  EXT DMA_Channel_TypeDef     *DMA1_Channel4;
#endif /*_DMA1_Channel4 */

#ifdef _DMA1_Channel5
  EXT DMA_Channel_TypeDef     *DMA1_Channel5;
#endif /*_DMA1_Channel5 */

#ifdef _DMA1_Channel6
  EXT DMA_Channel_TypeDef     *DMA1_Channel6;
#endif /*_DMA1_Channel6 */

#ifdef _DMA1_Channel7
  EXT DMA_Channel_TypeDef     *DMA1_Channel7;
#endif /*_DMA1_Channel7 */

#ifdef _DMA2_Channel1
  EXT DMA_Channel_TypeDef     *DMA2_Channel1;
#endif /*_DMA2_Channel1 */

#ifdef _DMA2_Channel2
  EXT DMA_Channel_TypeDef     *DMA2_Channel2;
#endif /*_DMA2_Channel2 */

#ifdef _DMA2_Channel3
  EXT DMA_Channel_TypeDef     *DMA2_Channel3;
#endif /*_DMA2_Channel3 */

#ifdef _DMA2_Channel4
  EXT DMA_Channel_TypeDef     *DMA2_Channel4;
#endif /*_DMA2_Channel4 */

#ifdef _DMA2_Channel5
  EXT DMA_Channel_TypeDef     *DMA2_Channel5;
#endif /*_DMA2_Channel5 */

#ifdef _RCC
  EXT RCC_TypeDef             *RCC;
#endif /*_RCC */

#ifdef _CRC
  EXT CRC_TypeDef             *CRC;
#endif /*_CRC */

#ifdef _FLASH
  EXT FLASH_TypeDef            *FLASH;
  EXT OB_TypeDef               *OB;  
#endif /*_FLASH */

#ifdef _FSMC
  EXT FSMC_Bank1_TypeDef      *FSMC_Bank1;
  EXT FSMC_Bank1E_TypeDef     *FSMC_Bank1E;
  EXT FSMC_Bank2_TypeDef      *FSMC_Bank2;
  EXT FSMC_Bank3_TypeDef      *FSMC_Bank3;
  EXT FSMC_Bank4_TypeDef      *FSMC_Bank4;
#endif /*_FSMC */

#ifdef _DBGMCU
  EXT DBGMCU_TypeDef          *DBGMCU;
#endif /*_DBGMCU */

#ifdef _SysTick
  EXT SysTick_TypeDef         *SysTick;
#endif /*_SysTick */

#ifdef _NVIC
  EXT NVIC_TypeDef            *NVIC;
  EXT SCB_TypeDef             *SCB;
#endif /*_NVIC */

#endif  /* DEBUG */

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __STM32F10x_MAP_H */

/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
