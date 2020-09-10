
#include "I2C.h"

void TWI_Init(void)
{
    /* Bit Rate: 400.000 kbps using zero pre-scaler TWPS=00 and F_CPU=8Mhz */
    TWBR = 0x02;
	TWSR = 0x00;
	
    /* Two Wire Bus address my address if any master device want to call me: 0x1 
	   (used in case this MC is a slave device) and General Call Recognition: Off */
    TWAR = 0b00000010; /* my address = 0x01 :) */
	
    TWCR = (1<<TWEN); /* enable TWI */
}

void TWI_Start(void)
{
    /* 
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    
    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
    while (!(TWCR & (1 << TWINT)));
}

void TWI_Stop(void)
{
    /* 
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void TWI_Write(unsigned char data)
{
    /* Put data On TWI data Register */
    TWDR = data;
    /* 
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */ 
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
    while (!(TWCR & (1 << TWINT)));
}

unsigned char TWI_Read_With_ACK(void)
{
	/* 
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1 
	 */ 
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while (!(TWCR & (1 << TWINT)));
    /* Read Data */
    return TWDR;
}

unsigned char TWI_Read_With_NACK(void)
{
	/* 
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1 
	 */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while (!(TWCR & (1 << TWINT)));
    /* Read Data */
    return TWDR;
}

unsigned char TWI_Get_Status(void)
{
    unsigned char status;
    status = TWSR & 0xF8; /* masking to eliminate first 3 bits */ 
    return status;
}
