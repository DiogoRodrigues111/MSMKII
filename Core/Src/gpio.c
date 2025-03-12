/*
 * gpio.c
 *
 *  Created on: Mar 11, 2025
 *      Author: Diogo R Roessler
 */

#include "gpio.h"
#include "serialize.h"
#include <stm32f1xx.h>
#include <stdint.h>

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
void GPIO_Init(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	GPIOB->CRL &= ~GPIO_CRL_CNF5;
	GPIOB->CRL |= (GPIO_CRL_MODE5_0 | GPIO_CRL_MODE5_1);
	GPIOB->ODR |= GPIO_ODR_ODR5;
}

/**
  * @brief GPIO Toggle Blink Function
  * @param None
  * @retval None
  */
void GPIO_ToggleBlink(void)
{
	GPIOB->ODR ^= GPIO_ODR_ODR5;
	HAL_Delay(1000);
	GPIOB->ODR &= GPIO_ODR_ODR5;
	HAL_Delay(1000);
}

/**
  * @brief Only GPIO Tester Component Worker Status Function
  * @param None
  * @retval None
  */
void GPIO_TesterComponentWorker(uint32_t GPIO_Pin)
{
	GPIOB->ODR ^= GPIO_Pin;
}

/**
  * @brief Only GPIO Tester Component Failure Function
  * @param None
  * @retval None
  */
void GPIO_TesterComponentFailure(uint32_t GPIO_Pin)
{
	GPIOB->ODR &= GPIO_Pin;
}

/**
  * @brief Custom GPIO Initialization Function
  * @param None
  * @retval None
  */
void GPIO_CustomInit(void)
{
	CUSTOM_RCC_APB2ENR |= CUSTOM_RCC_APB2ENR_IOPBEN;
	GPIOB_CRL &= ~CUSTOM_GPIO_CRL_CNF5;
	GPIOB_CRL |= (CUSTOM_GPIO_CRL_MODE5_0 | CUSTOM_GPIO_CRL_MODE5_1);
	GPIOB_ODR |= CUSTOM_GPIO_ODR_ODR5;
}

/**
  * @brief Custom GPIO Toggle Blink Function
  * @param None
  * @retval None
  */
void GPIO_CustomToggleBlink(void)
{
	GPIOB_ODR ^= CUSTOM_GPIO_ODR_ODR5;
	HAL_Delay(1000);
	GPIOB_ODR &= CUSTOM_GPIO_ODR_ODR5;
	HAL_Delay(1000);
}
