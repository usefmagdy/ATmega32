/*
 * DIO.h
 *
 *  Created on: Jan 13, 2018
 *      Author: Lenovo
 */

#ifndef DIO_H_
#define DIO_H_

#include "platform_types.h"

void DIO_vidInit(void);
void DIO_vidSeTPinDir(uint8 U8PinNum,uint8 U8Dir);
void DIO_VidWritePIN(uint8 U8PinNum,uint8 U8value);
uint8 DIO_U8ReadPin(uint8 U8PinNum);
void DIO_vidSeTPortDir(uint8 U8PortNum,uint8 U8PortDir);
void DIO_WritePortvoid(uint8 U8PortNum,uint8 U8Portval);
uint8 DIO_read_port_value_U8(uint8 U8PortNum);

#define DIO_PINA0 0
#define DIO_PINA1 1
#define DIO_PINA2 2
#define DIO_PINA4 4
#define DIO_PINA5 5
#define DIO_PINA6 6
#define DIO_PINA7 7

#define DIO_PINB0 8
#define DIO_PINB1 9
#define DIO_PINB2 10
#define DIO_PINB3 11
#define SS 12
#define MOSI 13
#define MISO 14
#define CLK 15

#define DIO_PINC0 16
#define DIO_PINC1 17
#define DIO_PINC2 18
#define DIO_PINC3 19
#define DIO_PINC4 20
#define DIO_PINC5 21
#define DIO_PINC6 22
#define DIO_PINC7 23

#define DIO_PIND0 24
#define DIO_PIND1 25
#define DIO_PIND2 26
#define DIO_PIND3 27
#define DIO_PIND4 28
#define DIO_PIND5 29
#define DIO_PIND6 30
#define DIO_PIND7 31


#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define OP 1
#define IP 0



#endif /* DIO_H_ */
