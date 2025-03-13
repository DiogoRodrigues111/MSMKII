/*
 * spi.c
 *
 *  Created on: Mar 12, 2025
 *      Author: Diogo R Roessler
 */

#include "spi.h"
#include "serialize.h"


/**
  * @brief SPI1 Initialize
  * @param None
  * @retval None
  */
void SPI1_Init(void)
{
	CUSTOM_RCC_APB2ENR |= CUSTOM_RCC_APB2ENR_SPI1EN | CUSTOM_RCC_APB2ENR_IOPAEN;

	/* NSS (Chip Select): PA4 (opcional, dependendo da configuração) */
	GPIOA_CRL &= ~CUSTOM_GPIO_CRL_CNF4;
	GPIOA_CRL |= (CUSTOM_GPIO_CRL_MODE5_0 | CUSTOM_GPIO_CRL_MODE5_1);
	GPIOA_ODR |= CUSTOM_GPIO_ODR_ODR4;

	/* SCK (Serial Clock): PA5 */
	GPIOA_CRL &= ~CUSTOM_GPIO_CRL_CNF5;
	GPIOA_CRL |= (CUSTOM_GPIO_CRL_MODE5_0 | CUSTOM_GPIO_CRL_MODE5_1);
	GPIOA_ODR |= CUSTOM_GPIO_ODR_ODR5;

	/* MISO (Master In Slave Out): PA6 */
	GPIOA_CRL &= ~CUSTOM_GPIO_CRL_CNF6;
	GPIOA_CRL |= (CUSTOM_GPIO_CRL_MODE5_0 | CUSTOM_GPIO_CRL_MODE5_1);
	GPIOA_ODR |= CUSTOM_GPIO_ODR_ODR6;

	/* MOSI (Master Out Slave In): PA7 */
	GPIOA_CRL &= ~CUSTOM_GPIO_CRL_CNF7;
	GPIOA_CRL |= (CUSTOM_GPIO_CRL_MODE5_0 | CUSTOM_GPIO_CRL_MODE5_1);
	GPIOA_ODR |= CUSTOM_GPIO_ODR_ODR7;
}

/**
  * @brief SPI1 Send Command to next
  * @param None
  * @retval None
  */
void SPI1_SendCmd(void)
{

}

/**
  * @brief SPI1 Receive Command from another
  * @param None
  * @retval None
  */
void SPI1_ReceiveCmd(void)
{

}

/**
  * @brief SPI1 Send Command Test
  * @param None
  * @retval None
  */
void SPI1_SendCmd_Tester(void)
{

}

/**
  * @brief SPI1 Receive Command Test
  * @param None
  * @retval None
  */
void SPI1_ReceiveCmd_Tester(void)
{

}
