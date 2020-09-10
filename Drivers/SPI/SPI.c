/*
 * SPI.c
 *
 *  Created on: Feb 8, 2020
 *      Author: yousi
 */
#include <avr/io.h>
#include "utils.h"
#include "platform_types.h"
#include "DIO.h"
#include "DIO_Local.h"
#include "SPI.h"
#include "SPI_Config.h"
#include "SPI_local.h"


void SPI_masterInit(void)
{
	 // Set MOSI, SCK as Output
	    DDRB=(1<<5)|(1<<3);

	    // Enable SPI, Set as Master
	    // Prescaler: Fosc/16, Enable Interrupts
	    //The MOSI, SCK pins are as per ATMega8
	    SPCR=(1<<SPE)|(1<<MSTR)|(1<<SPR0)|(1<<SPIE);

	    // Enable Global Interrupts

}
void SPI_slaveInit(void)
{

	SPCR = (1<<6);   //Enable SPI
}
void SPI_Master_Transmit(char data)
{

	SPDR=data;
	while(!(SPSR & (1<<SPIF)));
}

char SPI_slave_Recieve(void)
{
	while(!(SPSR & (1<<SPIF)));	/* Wait till reception complete */
	return SPDR;
}
