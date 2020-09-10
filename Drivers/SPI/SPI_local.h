/*
 * SPI_local.h
 *
 *  Created on: Feb 8, 2020
 *      Author: yousi
 */

#ifndef SPI_LOCAL_H_
#define SPI_LOCAL_H_

#define SPCR *((volatile uint8*)(0x2D))
#define SPSR *((volatile uint8*)(0x2E))
#define SPIF 7
#define SPDR *((volatile uint8*)(0x2F))


#endif /* SPI_LOCAL_H_ */
