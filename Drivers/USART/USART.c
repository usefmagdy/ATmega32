/*
 * USART.c
 *
 *  Created on: Feb 7, 2020
 *      Author: Yousif Magdy
 */
#include "platform_types.h"
#include	"USART_LOCAL.h"
#include	"USART_CFG.h"

void UART_vidInit(void)
{
	uint16 u16Baud 	=((FREQUENCY/16/USART_BAUDRATE)-1);
	USART_UCSRA_R	=(0									<<USART_UCSRA_U2X	)
					|(0									<<USART_UCSRA_MPCM	);

	USART_UCSRB_R 	=(1									<<USART_UCSRB_RXEN	)
					|(1									<<USART_UCSRB_TXEN	)
					|(Get_Bit(USART_CHRACTER_LENGTH,2)	<<USART_UCSRB_UCSZ2	);

	USART_UCSRC_R	=(1<<USART_UCSRC_URSEL)
					|(0<<USART_UCSRC_UMSEL)
					|(USART_PARITY_MODE					<<USART_UCSRC_UPM_S	)
					|(USART_STOP_BITS					<<USART_UCSRC_USBS	)
					|((USART_CHRACTER_LENGTH			<<USART_UCSRC_UCZ_S	)&USART_UCSRC_UCZ_M);

	USART_UBRRL_R 	=(u16Baud&0xff);
	USART_UBRRH_R 	=((u16Baud>>8)&USART_UBRRH_M);
}
void UART_vidSendChar(uint8 u8Data)
{
	while (!(USART_UCSRA_R&(1<<USART_UCSRA_UDRE)));
	USART_UDR_R = u8Data;
}

uint8 UART_u8RecieveChar(void)
{
	while (!(USART_UCSRA_R&(1<<USART_UCSRA_RXC)));
	return USART_UDR_R ;
}

void UART_vidSendString(uint8* u8Data, uint8 length)
{
	for (uint8 i=0;i< length;i++)
		UART_vidSendChar(u8Data[i]);
}

void UART_vidRecieveString(uint8* u8Data, uint8* length)
{
	*length=0;
	do
	{
		u8Data[*length]=UART_u8RecieveChar();
		(*length)++;
	}
	while(u8Data[(*length)-1]);
}
