/*
 * serialize.h
 *
 *  Created on: Mar 11, 2025
 *      Author: Diogo R Roessler
 */

#ifndef INC_SERIALIZE_H_
#define INC_SERIALIZE_H_

#include <stdint.h>

#define CUSTOM_RCC_BASE		0x40021000
#define CUSTOM_GPIOA_BASE	0x40010800
#define CUSTOM_GPIOB_BASE	0x40010C00
#define CUSTOM_GPIOC_BASE	0x40011000
#define CUSTOM_SPI1_BASE	0x40013000
#define CUSTOM_USART1_BASE	0x40013800
#define CUSTOM_USART2_BASE	0x40004400
#define CUSTOM_WWDG_BASE	0x40002C00
#define CUSTOM_IWDG_BASE	0x40003000
#define CUSTOM_DAC_BASE		0x40007400
#define CUSTOM_ADC1_BASE	0x40012400
#define CUSTOM_I2C1_BASE	0x40005400
#define CUSTOM_I2C2_BASE	0x40005800
#define CUSTOM_AFIO_BASE	0x40010000
#define CUSTOM_EXTI_BASE	0x40010400

/* USART1EN, SPI1EN, TIM1EN, ADC2EN, ADC1EN, IOPxEN, AFIOEN */
#define CUSTOM_RCC_APB2ENR	(*(volatile uint32_t *)(CUSTOM_RCC_BASE + 0x18))

/* DACEN, PWREN, BKPEN,
 * CAN2EN, CAN1EN,
 * I2C2EN, I2C1EN,
 * UART5EN, UART4EN, USART3EN, USART2EN,
 * SPI3EN, SPI2EN, WWDGEN,
 * TIM7EN, TIM6EN, TIM5EN, TIM4EN, TIM3EN, TIM2EN */
#define CUSTOM_RCC_APB1ENR	(*(volatile uint32_t *)(CUSTOM_RCC_BASE + 0x1C))

#define CUSTOM_RCC_APB2ENR_IOPBEN	(1 << 3)
#define CUSTOM_RCC_APB2ENR_IOPAEN	(1 << 2)
#define CUSTOM_RCC_APB2ENR_AFIOEN	(1 << 0)
#define CUSTOM_RCC_APB2ENR_USART1EN	(1 << 14)
#define CUSTOM_RCC_APB2ENR_SPI1EN	(1 << 12)
#define CUSTOM_RCC_APB2ENR_TIM1EN	(1 << 11)
#define CUSTOM_RCC_APB2ENR_ADC2EN	(1 << 10)
#define CUSTOM_RCC_APB2ENR_ADC1EN	(1 << 9)

/* GPIO Flags */

#define GPIOB_CRL	(*(volatile uint32_t *)(CUSTOM_GPIOB_BASE + 0x00))
#define GPIOB_ODR	(*(volatile uint32_t *)(CUSTOM_GPIOB_BASE + 0x0C))
#define GPIOB_BSRR	(*(volatile uint32_t *)(CUSTOM_GPIOB_BASE + 0x10))
#define GPIOB_BRR	(*(volatile uint32_t *)(CUSTOM_GPIOB_BASE + 0x14))

#define GPIOA_CRL	(*(volatile uint32_t *)(CUSTOM_GPIOA_BASE + 0x00))
#define GPIOA_ODR	(*(volatile uint32_t *)(CUSTOM_GPIOA_BASE + 0x0C))
#define GPIOA_BSRR	(*(volatile uint32_t *)(CUSTOM_GPIOA_BASE + 0x10))
#define GPIOA_BRR	(*(volatile uint32_t *)(CUSTOM_GPIOA_BASE + 0x14))
#define GPIOA_IDR	(*(volatile uint32_t *)(CUSTOM_GPIOA_BASE + 0x08))
#define GPIOA_CRH	(*(volatile uint32_t *)(CUSTOM_GPIOA_BASE + 0x04))

/* CNF and MODE */

#define Analog_mode	0x0
#define Floating_input_RESETSTATE 0x1
#define Input_pull_up_down 0x2
#define __INPUT_MODE_RESERVED__ 0x3

#define General_purpose_output_push_pull 0x0UL
#define General_purpose_output_open_drain 0x1UL
#define Alternate_function_output_push_pull 0x2UL
#define Alternate_function_output_open_drain 0x3UL

#define Input_mode_RESETSTATE	0x0UL
#define Output_mode_10MHz	0x1UL
#define Output_mode_2MHz	0x2UL
#define Output_mode_50MHz	0x3UL

/* GPIO Pin */

#define CUSTOM_GPIO_CRL_MODE4_0		(Output_mode_10MHz << (16U)) // (0x1UL = representa SPEED) - (MODE5_0 | MODE5_1) = 0b11 = 50Mhz
#define CUSTOM_GPIO_CRL_MODE4_1		(Output_mode_10MHz << (17U))
#define CUSTOM_GPIO_CRL_CNF4		(Alternate_function_output_open_drain << (18U)) // (0x3UL = MODE_PIN [PushPull, OpenDrain, etc..]) [SEMPRE É MELHOR (22U), pois é menor que (23U)] sempre prefira menor
#define CUSTOM_GPIO_ODR_ODR4		(0x1UL << (4U)) 			// ENABLE

#define CUSTOM_GPIO_CRL_MODE5_0		(Output_mode_10MHz << (20U)) // (0x1UL = representa SPEED) - (MODE5_0 | MODE5_1) = 0b11 = 50Mhz
#define CUSTOM_GPIO_CRL_MODE5_1		(Output_mode_10MHz << (21U)) // (0x1UL << (21)) | (0x2UL << (20U)) //21 (0x1UL = SPEED)
#define CUSTOM_GPIO_CRL_CNF5		(Alternate_function_output_open_drain << (22U)) // (0x3UL = MODE_PIN [PushPull, OpenDrain, etc..]) [SEMPRE É MELHOR (22U), pois é menor que (23U)] sempre prefira menor
#define CUSTOM_GPIO_ODR_ODR5		(0x1UL << (5U)) 			// ENABLE

#define CUSTOM_GPIO_CRL_MODE6_0		(Output_mode_10MHz << (24U)) // (0x1UL = representa SPEED) - (MODE5_0 | MODE5_1) = 0b11 = 50Mhz
#define CUSTOM_GPIO_CRL_MODE6_1		(Output_mode_10MHz << (25U))
#define CUSTOM_GPIO_CRL_CNF6		(Alternate_function_output_open_drain << (26U)) // (0x3UL = MODE_PIN [PushPull, OpenDrain, etc..]) [SEMPRE É MELHOR (22U), pois é menor que (23U)] sempre prefira menor
#define CUSTOM_GPIO_ODR_ODR6		(0x1UL << (6U)) 			// ENABLE

#define CUSTOM_GPIO_CRL_MODE7_0		(Output_mode_10MHz << (28U)) // (0x1UL = representa SPEED) - (MODE5_0 | MODE5_1) = 0b11 = 50Mhz
#define CUSTOM_GPIO_CRL_MODE7_1		(Output_mode_10MHz << (29U))
#define CUSTOM_GPIO_CRL_CNF7		(Alternate_function_output_open_drain << (30U)) // (0x3UL = MODE_PIN [PushPull, OpenDrain, etc..]) [SEMPRE É MELHOR (22U), pois é menor que (23U)] sempre prefira menor
#define CUSTOM_GPIO_ODR_ODR7		(0x1UL << (7U)) 			// ENABLE

#endif /* INC_SERIALIZE_H_ */
