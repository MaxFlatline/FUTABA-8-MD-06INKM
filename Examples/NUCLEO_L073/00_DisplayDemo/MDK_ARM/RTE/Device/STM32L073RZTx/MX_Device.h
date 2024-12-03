/******************************************************************************
 * File Name   : MX_Device.h
 * Date        : 03/12/2024 20:40:04
 * Description : STM32Cube MX parameter definitions
 * Note        : This file is generated by STM32CubeMX (DO NOT EDIT!)
 ******************************************************************************/

#ifndef __MX_DEVICE_H
#define __MX_DEVICE_H

/*---------------------------- Clock Configuration ---------------------------*/

#define MX_LSI_VALUE                            37000
#define MX_LSE_VALUE                            32768
#define MX_HSI_VALUE                            16000000
#define MX_HSE_VALUE                            8000000
#define MX_HSI48_VALUE                          48000000
#define MX_MSI_VALUE                            2097000
#define MX_PLLCLKFreq_Value                     32000000
#define MX_SYSCLKFreq_VALUE                     32000000
#define MX_HCLKFreq_Value                       32000000
#define MX_FCLKCortexFreq_Value                 32000000
#define MX_AHBFreq_Value                        32000000
#define MX_APB1Freq_Value                       32000000
#define MX_APB2Freq_Value                       32000000
#define MX_48CLKFreq_Value                      32000000
#define MX_48RNGFreq_Value                      32000000
#define MX_48USBFreq_Value                      32000000
#define MX_ADCFreq_Value                        16000000
#define MX_I2C1Freq_Value                       32000000
#define MX_LCDFreq_Value                        37000
#define MX_LPUARTFreq_Value                     32000000
#define MX_LPTIMFreq_Value                      32000000
#define MX_USART1Freq_Value                     32000000
#define MX_USART2Freq_Value                     32000000
#define MX_RTCFreq_Value                        37000
#define MX_RTCHSEDivFreq_Value                  4000000
#define MX_TimerFreq_Value                      32000000
#define MX_VCOOutputFreq_Value                  64000000
#define MX_WatchDogFreq_Value                   37000

/*-------------------------------- SPI1       --------------------------------*/

#define MX_SPI1                                 1

/* GPIO Configuration */

/* Pin PB5 */
#define MX_SPI1_MOSI_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SPI1_MOSI_Pin                        PB5
#define MX_SPI1_MOSI_GPIOx                      GPIOB
#define MX_SPI1_MOSI_GPIO_PuPd                  GPIO_NOPULL
#define MX_SPI1_MOSI_GPIO_Pin                   GPIO_PIN_5
#define MX_SPI1_MOSI_GPIO_AF                    GPIO_AF0_SPI1
#define MX_SPI1_MOSI_GPIO_Mode                  GPIO_MODE_AF_PP

/* Pin PB3 */
#define MX_SPI1_SCK_GPIO_Speed                  GPIO_SPEED_FREQ_VERY_HIGH
#define MX_SPI1_SCK_Pin                         PB3
#define MX_SPI1_SCK_GPIOx                       GPIOB
#define MX_SPI1_SCK_GPIO_PuPd                   GPIO_NOPULL
#define MX_SPI1_SCK_GPIO_Pin                    GPIO_PIN_3
#define MX_SPI1_SCK_GPIO_AF                     GPIO_AF0_SPI1
#define MX_SPI1_SCK_GPIO_Mode                   GPIO_MODE_AF_PP

/* NVIC Configuration */

/* NVIC SPI1_IRQn */
#define MX_SPI1_IRQn_interruptPremptionPriority 0
#define MX_SPI1_IRQn_Subriority                 0

/*-------------------------------- SYS        --------------------------------*/

#define MX_SYS                                  1

/* GPIO Configuration */

/* Pin PA13 */
#define MX_SYS_SWDIO_Pin                        PA13

/* Pin PA14 */
#define MX_SYS_SWCLK_Pin                        PA14

/*-------------------------------- USART2     --------------------------------*/

#define MX_USART2                               1

#define MX_USART2_VM                            VM_ASYNC

/* GPIO Configuration */

/* Pin PA2 */
#define MX_USART2_TX_GPIO_ModeDefaultPP         GPIO_MODE_AF_PP
#define MX_USART2_TX_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_USART2_TX_Pin                        PA2
#define MX_USART2_TX_GPIOx                      GPIOA
#define MX_USART2_TX_GPIO_PuPd                  GPIO_NOPULL
#define MX_USART2_TX_GPIO_Pin                   GPIO_PIN_2
#define MX_USART2_TX_GPIO_AF                    GPIO_AF4_USART2

/* Pin PA3 */
#define MX_USART2_RX_GPIO_ModeDefaultPP         GPIO_MODE_AF_PP
#define MX_USART2_RX_GPIO_Speed                 GPIO_SPEED_FREQ_VERY_HIGH
#define MX_USART2_RX_Pin                        PA3
#define MX_USART2_RX_GPIOx                      GPIOA
#define MX_USART2_RX_GPIO_PuPd                  GPIO_NOPULL
#define MX_USART2_RX_GPIO_Pin                   GPIO_PIN_3
#define MX_USART2_RX_GPIO_AF                    GPIO_AF4_USART2

/* NVIC Configuration */

/* NVIC USART2_IRQn */
#define MX_USART2_IRQn_interruptPremptionPriority 0
#define MX_USART2_IRQn_Subriority               0

/*-------------------------------- NVIC       --------------------------------*/

#define MX_NVIC                                 1

/*-------------------------------- GPIO       --------------------------------*/

#define MX_GPIO                                 1

/* GPIO Configuration */

/* Pin PC13 */
#define MX_PC13_Pin                             PC13
#define MX_PC13_GPIOx                           GPIOC
#define MX_PC13_GPIO_PuPd                       GPIO_NOPULL
#define MX_USER_BUTTON                          PC13
#define MX_PC13_GPIO_Pin                        GPIO_PIN_13
#define MX_PC13_GPIO_ModeDefaultEXTI            GPIO_MODE_IT_RISING

/* Pin PB4 */
#define MX_PB4_GPIO_Speed                       GPIO_SPEED_FREQ_LOW
#define MX_PB4_Pin                              PB4
#define MX_PB4_GPIOx                            GPIOB
#define MX_PB4_PinState                         GPIO_PIN_RESET
#define MX_PB4_GPIO_PuPd                        GPIO_NOPULL
#define MX_DISPLAY_RESET                        PB4
#define MX_PB4_GPIO_Pin                         GPIO_PIN_4
#define MX_PB4_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

/* Pin PB10 */
#define MX_PB10_GPIO_Speed                      GPIO_SPEED_FREQ_LOW
#define MX_PB10_Pin                             PB10
#define MX_PB10_GPIOx                           GPIOB
#define MX_PB10_PinState                        GPIO_PIN_RESET
#define MX_PB10_GPIO_PuPd                       GPIO_NOPULL
#define MX_DISPLAY_EN                           PB10
#define MX_PB10_GPIO_Pin                        GPIO_PIN_10
#define MX_PB10_GPIO_ModeDefaultOutputPP        GPIO_MODE_OUTPUT_PP

/* Pin PA5 */
#define MX_PA5_GPIO_Speed                       GPIO_SPEED_FREQ_LOW
#define MX_PA5_Pin                              PA5
#define MX_PA5_GPIOx                            GPIOA
#define MX_PA5_PinState                         GPIO_PIN_RESET
#define MX_PA5_GPIO_PuPd                        GPIO_NOPULL
#define MX_USER_LED                             PA5
#define MX_PA5_GPIO_Pin                         GPIO_PIN_5
#define MX_PA5_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

/* Pin PA8 */
#define MX_PA8_GPIO_Speed                       GPIO_SPEED_FREQ_LOW
#define MX_PA8_Pin                              PA8
#define MX_PA8_GPIOx                            GPIOA
#define MX_PA8_PinState                         GPIO_PIN_RESET
#define MX_PA8_GPIO_PuPd                        GPIO_NOPULL
#define MX_DISPLAY_CS                           PA8
#define MX_PA8_GPIO_Pin                         GPIO_PIN_8
#define MX_PA8_GPIO_ModeDefaultOutputPP         GPIO_MODE_OUTPUT_PP

#endif  /* __MX_DEVICE_H */
