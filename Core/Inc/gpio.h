/*
 * gpio.h
 *
 *  Created on: Mar 11, 2025
 *      Author: Diogo R Roessler
 */

#ifndef INC_GPIO_H_
#define INC_GPIO_H_

#include <stdint.h>

void GPIO_Init(void);
void GPIO_ToggleBlink(void);


/* Tester Component */

void GPIO_TesterComponentWorker(uint32_t GPIO_Pin);
void GPIO_TesterComponentFailure(uint32_t GPIO_Pin);

/* CUSTOM */

void GPIO_CustomInit(void);
void GPIO_CustomToggleBlink(void);

#endif /* INC_GPIO_H_ */
