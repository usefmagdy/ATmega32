/*
 * DIO.c

 *
 *  Created on: Jan 13, 2018
 *      Author: Yousif Magdy
 */

#include"platform_types.h"
#include"utils.h"
#include "DIO_Local.h"
#include"DIO.h"

void DIO_vidInit(void)
{

}
void DIO_vidSeTPinDir(uint8 U8PinNum,uint8 U8Dir)
{
if (U8PinNum%8<=7&&U8PinNum/8==0)

{
	ASSIGNBIT(DDRA,U8PinNum%8,U8Dir);
}

	else if(U8PinNum>=8 && U8PinNum/8==1)
	{

		ASSIGNBIT(DDRB,U8PinNum%8,U8Dir);
	}

	else if(U8PinNum>16 && U8PinNum <=23)
	{

		 ASSIGNBIT(DDRC,U8PinNum%8,U8Dir);
	}

	else if(U8PinNum>=DIO_PIND0 && U8PinNum <=DIO_PIND7)
	{

		ASSIGNBIT(DDRD,U8PinNum%8,U8Dir);
	}
}


void DIO_VidWritePIN(uint8 U8PinNum,uint8 U8value)
{
	if (U8PinNum >= DIO_PINA0 && U8PinNum<=DIO_PINA7)
	{

		ASSIGNBIT(PORTA,U8PinNum%8,U8value);

	}


	else if (U8PinNum >= DIO_PINB0 && U8PinNum<=CLK)
	{

		ASSIGNBIT(PORTB,U8PinNum%8,U8value);

	}

	else if (U8PinNum>= DIO_PINC0 && U8PinNum<=DIO_PINC7)
	{

		ASSIGNBIT(PORTC,U8PinNum%8,U8value);

	}
	else if (U8PinNum>= DIO_PIND0 && U8PinNum<=DIO_PIND7)
	{

		ASSIGNBIT(PORTD,U8PinNum%8,U8value);

	}
}
uint8 DIO_U8ReadPin(uint8 U8PinNum)
{

uint8 value;
if (U8PinNum>= DIO_PINA0 && U8PinNum<= DIO_PINA7)
{

value = GETBIT(PINA,U8PinNum%8);

}

else if (U8PinNum >= DIO_PINB0 && U8PinNum <= CLK)
{

value = GETBIT(PINB,U8PinNum%8);

}

else if (U8PinNum >= DIO_PINC0 && U8PinNum <= DIO_PINC7)
{

value = GETBIT(PINC,U8PinNum%8);

}

else if (U8PinNum>= DIO_PIND0 && U8PinNum <= DIO_PIND7)
{

value = GETBIT(PIND,U8PinNum%8);

}

return value;
}
void DIO_vidSeTPortDir(uint8 U8PortNum,uint8 U8PortDir)
{
	if (U8PortNum == DIO_PORTA)
	{
		DDRA = U8PortDir;
	}
	else if (U8PortNum== DIO_PORTB)
	{
		DDRB = U8PortDir;
	}
	else if (U8PortNum == DIO_PORTC)
	{
		DDRC = U8PortDir;
	}
	else if (U8PortNum== DIO_PORTD)
	{
		DDRD = U8PortDir;
	}
}


void DIO_WritePortvoid(uint8 U8PortNum,uint8 U8Portval)
{

     if (U8PortNum == DIO_PORTA)
     {
    	 PORTA = U8Portval;
     }
     else if (U8PortNum == DIO_PORTB)
     {
    	 PORTB = U8Portval;
     }
     else if (U8PortNum == DIO_PORTC)
     {
    	 PORTC = U8Portval;
     }
     else if (U8PortNum == DIO_PORTD)
     {
    	 PORTD = U8Portval;
     }
}

uint8 DIO_read_port_value_U8(uint8 U8PortNum)
{
	uint8 U8Portval;
    if (U8PortNum == DIO_PORTA)
    {
    	U8Portval= PINA;
    }
    else if (U8PortNum == DIO_PORTB)
    {
    	U8Portval = PINB;
    }
    else if (U8PortNum == DIO_PORTC)
    {
    	U8Portval = PINC;
    }
    else if (U8PortNum == DIO_PORTD)
    {
    	U8Portval = PIND;
    }
return U8Portval;
}
