/*
 * USART_LOCAL.h
 *
 *  Created on: Feb 7, 2020
 *      Author: Yousif Magdy
 */

#ifndef USART_LOCAL_H_
#define USART_LOCAL_H_

#include "Std_Types.h"
#include "Utils.h"

#define USART_UDR_R			*((volatile uint8 *)(0x2C))

#define USART_UCSRA_R		*((volatile uint8 *)(0x2B))
#define USART_UCSRA_RXC		(7)
#define USART_UCSRA_TXC		(6)
#define USART_UCSRA_UDRE	(5)
#define USART_UCSRA_FE		(4)
#define USART_UCSRA_DOR		(3)
#define USART_UCSRA_PE		(2)
#define USART_UCSRA_U2X		(1)
#define USART_UCSRA_MPCM	(0)

#define USART_UCSRB_R		*((volatile uint8 *)(0x2A))
#define USART_UCSRB_RXCIE	(7)
#define USART_UCSRB_TXCIE	(6)
#define USART_UCSRB_UDRIE	(5)
#define USART_UCSRB_RXEN	(4)
#define USART_UCSRB_TXEN	(3)
#define USART_UCSRB_UCSZ2	(2)
#define USART_UCSRB_RXB8	(1)
#define USART_UCSRB_TXB8	(0)

#define USART_UCSRC_R		*((volatile uint8 *)(0x40))
#define USART_UCSRC_URSEL	(7)
#define USART_UCSRC_UMSEL	(6)
#define USART_UCSRC_UPM1	(5)
#define USART_UCSRC_UPM0	(4)
#define USART_UCSRC_UPM_S	(4)
#define USART_UCSRC_UPM_M	(0X30)
#define USART_UCSRC_USBS	(3)
#define USART_UCSRC_UCZ1	(2)
#define USART_UCSRC_UCZ0	(1)
#define USART_UCSRC_UCZ_S	(1)
#define USART_UCSRC_UCZ_M	(0X06)
#define USART_UCSRC_UCPOL	(0)

#define USART_UBRRL_R		*((volatile uint8 *)(0x29))

#define USART_UBRRH_R		*((volatile uint8 *)(0x40))
#define USART_UBRRH_M		(0x0f)

#endif /* USART_LOCAL_H_ */
