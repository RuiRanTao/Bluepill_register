//stm32f10x.h
#ifndef __STM32F10X_H
#define __STM32F10X_H
/**
 * @brief STM32F10x Interrupt Number Definition, according to the selected device 
 *        in @ref Library_configuration_section 
 */
typedef enum IRQn
{
/******  Cortex-M3 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable Interrupt                             */
  MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M3 Memory Management Interrupt              */
  BusFault_IRQn               = -11,    /*!< 5 Cortex-M3 Bus Fault Interrupt                      */
  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M3 Usage Fault Interrupt                    */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M3 SV Call Interrupt                       */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M3 Debug Monitor Interrupt                 */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M3 Pend SV Interrupt                       */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M3 System Tick Interrupt                   */

/******  STM32 specific Interrupt Numbers *********************************************************/
  WWDG_IRQn                   = 0,      /*!< Window WatchDog Interrupt                            */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection Interrupt            */
  TAMPER_IRQn                 = 2,      /*!< Tamper Interrupt                                     */
  RTC_IRQn                    = 3,      /*!< RTC global Interrupt                                 */
  FLASH_IRQn                  = 4,      /*!< FLASH global Interrupt                               */
  RCC_IRQn                    = 5,      /*!< RCC global Interrupt                                 */
  EXTI0_IRQn                  = 6,      /*!< EXTI Line0 Interrupt                                 */
  EXTI1_IRQn                  = 7,      /*!< EXTI Line1 Interrupt                                 */
  EXTI2_IRQn                  = 8,      /*!< EXTI Line2 Interrupt                                 */
  EXTI3_IRQn                  = 9,      /*!< EXTI Line3 Interrupt                                 */
  EXTI4_IRQn                  = 10,     /*!< EXTI Line4 Interrupt                                 */
  DMA1_Channel1_IRQn          = 11,     /*!< DMA1 Channel 1 global Interrupt                      */
  DMA1_Channel2_IRQn          = 12,     /*!< DMA1 Channel 2 global Interrupt                      */
  DMA1_Channel3_IRQn          = 13,     /*!< DMA1 Channel 3 global Interrupt                      */
  DMA1_Channel4_IRQn          = 14,     /*!< DMA1 Channel 4 global Interrupt                      */
  DMA1_Channel5_IRQn          = 15,     /*!< DMA1 Channel 5 global Interrupt                      */
  DMA1_Channel6_IRQn          = 16,     /*!< DMA1 Channel 6 global Interrupt                      */
  DMA1_Channel7_IRQn          = 17,     /*!< DMA1 Channel 7 global Interrupt                      */



  ADC1_2_IRQn                 = 18,     /*!< ADC1 and ADC2 global Interrupt                       */
  USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB Device High Priority or CAN1 TX Interrupts       */
  USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB Device Low Priority or CAN1 RX0 Interrupts       */
  CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1 Interrupt                                   */
  CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE Interrupt                                   */
  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5] Interrupts                        */
  TIM1_BRK_IRQn               = 24,     /*!< TIM1 Break Interrupt                                 */
  TIM1_UP_IRQn                = 25,     /*!< TIM1 Update Interrupt                                */
  TIM1_TRG_COM_IRQn           = 26,     /*!< TIM1 Trigger and Commutation Interrupt               */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare Interrupt                       */
  TIM2_IRQn                   = 28,     /*!< TIM2 global Interrupt                                */
  TIM3_IRQn                   = 29,     /*!< TIM3 global Interrupt                                */
  TIM4_IRQn                   = 30,     /*!< TIM4 global Interrupt                                */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event Interrupt                                 */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error Interrupt                                 */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event Interrupt                                 */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error Interrupt                                 */
  SPI1_IRQn                   = 35,     /*!< SPI1 global Interrupt                                */
  SPI2_IRQn                   = 36,     /*!< SPI2 global Interrupt                                */
  USART1_IRQn                 = 37,     /*!< USART1 global Interrupt                              */
  USART2_IRQn                 = 38,     /*!< USART2 global Interrupt                              */
  USART3_IRQn                 = 39,     /*!< USART3 global Interrupt                              */
  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10] Interrupts                      */
  RTCAlarm_IRQn               = 41,     /*!< RTC Alarm through EXTI Line Interrupt                */
  USBWakeUp_IRQn              = 42      /*!< USB Device WakeUp from suspend through EXTI Line Interrupt */  
/* STM32F10X_MD */


} IRQn_Type; 

#define u16 unsigned short
#define u8 unsigned char
#define u32 unsigned int
	
#ifdef __cplusplus
  #define     __I     volatile                /*!< defines 'read only' permissions      */
#else
  #define     __I     volatile const          /*!< defines 'read only' permissions      */
#endif
#define     __O     volatile                  /*!< defines 'write only' permissions     */
#define     __IO    volatile                  /*!< defines 'read / write' permissions   */

#define SysTick             ((SysTick_Type *)       SysTick_BASE)     /*!< SysTick configuration struct      */
#define NVIC                	((NVIC_Type *)          NVIC_BASE)        /*!< NVIC configuration struct         */
#define SCB                 	((SCB_Type *)           SCB_BASE)         /*!< SCB configuration struct          */
#define SCS_BASE            	(0xE000E000)                              /*!< System Control Space Base Address */
#define SCB_BASE            	(SCS_BASE +  0x0D00)                      /*!< System Control Block Base Address */
#define SysTick_BASE        (SCS_BASE +  0x0010)                      /*!< SysTick Base Address              */
#define NVIC_BASE           	(SCS_BASE +  0x0100)                      /*!< NVIC Base Address                 */
#define PERIPH_BASE						((unsigned int)0x40000000)
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)
#define GPIOA_BASE            (APB2PERIPH_BASE + 0x800)
#define RCC_BASE     					(AHBPERIPH_BASE + 0x1000)
#define USART1_BASE           (APB2PERIPH_BASE + 0x3800)
#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x2000) /*!< Flash registers base address */

typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
//typedef unsigned int uint32_t;

/** 
  * @brief Universal Synchronous Asynchronous Receiver Transmitter
  */
typedef struct
{
  __IO u32 CTRL;                         /*!< Offset: 0x00  SysTick Control and Status Register */
  __IO u32 LOAD;                         /*!< Offset: 0x04  SysTick Reload Value Register       */
  __IO u32 VAL;                          /*!< Offset: 0x08  SysTick Current Value Register      */
  __I  u32 CALIB;                        /*!< Offset: 0x0C  SysTick Calibration Register        */
} SysTick_Type;
typedef struct
{
  __IO u32 ACR;
  __IO u32 KEYR;
  __IO u32 OPTKEYR;
  __IO u32 SR;
  __IO u32 CR;
  __IO u32 AR;
  __IO u32 RESERVED;
  __IO u32 OBR;
  __IO u32 WRPR;
#ifdef STM32F10X_XL
  uint32_t RESERVED1[8]; 
  __IO uint32_t KEYR2;
  uint32_t RESERVED2;   
  __IO uint32_t SR2;
  __IO uint32_t CR2;
  __IO uint32_t AR2; 
#endif /* STM32F10X_XL */  
} FLASH_TypeDef;
typedef struct
{
	u32 CRL;
    u32 CRH;
    u32 IDR;
    u32 ODR;
    u32 BSRR;
    u32 BRR;
    u32 LCKR;
}GPIO_TypeDef;

typedef struct 
{
	u32 CR;
	u32 CFGR;
	u32 CIR;
	u32 APB2RSTR;
	u32 APB1RSTR;
	u32 AHBENR;
    u32 APB2ENR;
    u32 APB1ENR;
		u32 BDCR;
		u32 CSR;
}RCC_TypeDef;

typedef struct
{
  __IO uint16_t SR;
  uint16_t  RESERVED0;
  __IO uint16_t DR;
  uint16_t  RESERVED1;
  __IO uint16_t BRR;
  uint16_t  RESERVED2;
  __IO uint16_t CR1;
  uint16_t  RESERVED3;
  __IO uint16_t CR2;
  uint16_t  RESERVED4;
  __IO uint16_t CR3;
  uint16_t  RESERVED5;
  __IO uint16_t GTPR;
  uint16_t  RESERVED6;
} USART_TypeDef;

typedef struct
{
  __IO u32 ISER[8];                      /*!< Offset: 0x000  Interrupt Set Enable Register           */
  u32 RESERVED0[24];
  __IO u32 ICER[8];                      /*!< Offset: 0x080  Interrupt Clear Enable Register         */
  u32 RSERVED1[24];
  __IO u32 ISPR[8];                      /*!< Offset: 0x100  Interrupt Set Pending Register          */
  u32 RESERVED2[24];
  __IO u32 ICPR[8];                      /*!< Offset: 0x180  Interrupt Clear Pending Register        */
  u32 RESERVED3[24];
  __IO u32 IABR[8];                      /*!< Offset: 0x200  Interrupt Active bit Register           */
  u32 RESERVED4[56];
  __IO uint8_t  IP[240];                      /*!< Offset: 0x300  Interrupt Priority Register (8Bit wide) */
  u32 RESERVED5[644];
  __O  u32 STIR;                         /*!< Offset: 0xE00  Software Trigger Interrupt Register     */
}  NVIC_Type;  

/** @addtogroup CMSIS_CM3_SCB CMSIS CM3 SCB
  memory mapped structure for System Control Block (SCB)
  @{
 */
typedef struct
{
  __I  u32 CPUID;                        /*!< Offset: 0x00  CPU ID Base Register                                  */
  __IO u32 ICSR;                         /*!< Offset: 0x04  Interrupt Control State Register                      */
  __IO u32 VTOR;                         /*!< Offset: 0x08  Vector Table Offset Register                          */
  __IO u32 AIRCR;                        /*!< Offset: 0x0C  Application Interrupt / Reset Control Register        */
  __IO u32 SCR;                          /*!< Offset: 0x10  System Control Register                               */
  __IO u32 CCR;                          /*!< Offset: 0x14  Configuration Control Register                        */
  __IO uint8_t  SHP[12];                      /*!< Offset: 0x18  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  __IO u32 SHCSR;                        /*!< Offset: 0x24  System Handler Control and State Register             */
  __IO u32 CFSR;                         /*!< Offset: 0x28  Configurable Fault Status Register                    */
  __IO u32 HFSR;                         /*!< Offset: 0x2C  Hard Fault Status Register                            */
  __IO u32 DFSR;                         /*!< Offset: 0x30  Debug Fault Status Register                           */
  __IO u32 MMFAR;                        /*!< Offset: 0x34  Mem Manage Address Register                           */
  __IO u32 BFAR;                         /*!< Offset: 0x38  Bus Fault Address Register                            */
  __IO u32 AFSR;                         /*!< Offset: 0x3C  Auxiliary Fault Status Register                       */
  __I  u32 PFR[2];                       /*!< Offset: 0x40  Processor Feature Register                            */
  __I  u32 DFR;                          /*!< Offset: 0x48  Debug Feature Register                                */
  __I  u32 ADR;                          /*!< Offset: 0x4C  Auxiliary Feature Register                            */
  __I  u32 MMFR[4];                      /*!< Offset: 0x50  Memory Model Feature Register                         */
  __I  u32 ISAR[5];                      /*!< Offset: 0x60  ISA Feature Register                                  */
} SCB_Type; 

/** @addtogroup Peripheral_declaration
  * @{
  */  
#define GPIOA								((GPIO_TypeDef*)GPIOA_BASE)
#define RCC									((RCC_TypeDef*)RCC_BASE)
#define USART1              ((USART_TypeDef *) USART1_BASE)
#define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)

/*
#define GPIOA_CRL			*(unsigned int*)(GPIOA_BASE+0x00)
#define GPIOA_CRH			*(unsigned int*)(GPIOA_BASE+0x04)
#define GPIOA_IDR			*(unsigned int*)(GPIOA_BASE+0x08)
#define GPIOA_ODR			*(unsigned int*)(GPIOA_BASE+0x0C)
#define GPIOA_BSRR	  *(unsigned int*)(GPIOA_BASE+0x10)
#define GPIOA_BRR			*(unsigned int*)(GPIOA_BASE+0x14)
#define GPIOA_LCKR		*(unsigned int*)(GPIOA_BASE+0x18)


#define GPIOC_BASE            (APB2PERIPH_BASE + 0x1000)

#define GPIOC_CRL			*(unsigned int*)(GPIOC_BASE+0x00)
#define GPIOC_CRH			*(unsigned int*)(GPIOC_BASE+0x04)
#define GPIOC_IDR			*(unsigned int*)(GPIOC_BASE+0x08)
#define GPIOC_ODR			*(unsigned int*)(GPIOC_BASE+0x0C)
#define GPIOC_BSRR	  *(unsigned int*)(GPIOC_BASE+0x10)
#define GPIOC_BRR			*(unsigned int*)(GPIOC_BASE+0x14)
#define GPIOC_LCKR		*(unsigned int*)(GPIOC_BASE+0x18)


#define RCC_BASE      (AHBPERIPH_BASE + 0x1000)

#define RCC_APB2ENR		 *(unsigned int*)(RCC_BASE+0x18)
	
*/

#endif

