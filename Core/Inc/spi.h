/*
 * spi.h
 *
 *  Created on: Mar 12, 2025
 *      Author: Diogo R Roessler
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

/* Original functions */

void SPI1_Init(void);
void SPI1_SendCmd(void);
void SPI1_ReceiveCmd(void);

/* Tester */

void SPI1_SendCmd_Tester(void);
void SPI1_ReceiveCmd_Tester(void);


#endif /* INC_SPI_H_ */
