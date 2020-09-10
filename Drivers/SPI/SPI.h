/*
 * SPI.h
 *
 *  Created on: Feb 8, 2020
 *      Author: yousi
 */

#ifndef SPI_H_
#define SPI_H_
void SPI_masterInit(void);
void SPI_slaveInit(void);
void SPI_Master_Transmit(char data);
char SPI_slave_Recieve(void);

#endif /* SPI_H_ */
