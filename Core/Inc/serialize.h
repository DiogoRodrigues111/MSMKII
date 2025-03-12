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
#define CUSTOM_GPIOB_BASE	0x40010C00

#define CUSTOM_RCC_APB2ENR	(*(volatile uint32_t *)(CUSTOM_RCC_BASE + 0x18))
#define CUSTOM_RCC_APB1ENR	(*(volatile uint32_t *)(CUSTOM_RCC_BASE + 0x1C))

#define CUSTOM_RCC_APB2ENR_IOPBEN	(1 << 3)
#define CUSTOM_RCC_APB2ENR_IOPAEN	(1 << 2)

#define GPIOB_CRL	(*(volatile uint32_t *)(CUSTOM_GPIOB_BASE + 0x00))
#define GPIOB_ODR	(*(volatile uint32_t *)(CUSTOM_GPIOB_BASE + 0x0C))
#define GPIOB_BSRR	(*(volatile uint32_t *)(CUSTOM_GPIOB_BASE + 0x10))
#define GPIOB_BRR	(*(volatile uint32_t *)(CUSTOM_GPIOB_BASE + 0x14))

#define CUSTOM_GPIO_CRL_MODE5_0		(0x1UL << (20U)) // (0x1UL = representa SPEED) - (MODE5_0 | MODE5_1) = 0b11 = 50Mhz
#define CUSTOM_GPIO_CRL_MODE5_1		(0x1UL << (21U)) // (0x1UL << (21)) | (0x2UL << (20U)) //21 (0x1UL = SPEED)
#define CUSTOM_GPIO_CRL_CNF5		(0x3UL << (22U)) // (0x3UL = MODE_PIN PushPull, OpenDrain, etc..) [SEMPRE EH MELHOR 22U Que eh melhor que 23] sempre prefira menor
#define CUSTOM_GPIO_ODR_ODR5		(0x1UL << (5U)) // ENABLE

#endif /* INC_SERIALIZE_H_ */
