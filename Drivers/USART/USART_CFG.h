/*
 * USART_CFG
 *
 *  Created on: Feb 7, 2020
 *      Author: Yousif Magdy
 */

#ifndef USART_CFG_H_
#define USART_CFG_H_


#define	USART_PARITY_NON		0
#define	USART_PARITY_EVEN		2
#define	USART_PARITY_ODD		3

#define USART_STOP_BITS_ONE		0
#define USART_STOP_BITS_TWO		1

#define USART_5BIT				0
#define USART_6BIT				1
#define USART_7BIT				2
#define USART_8BIT				3
#define USART_9BIT				8


#ifndef FREQUENCY
#define FREQUENCY				16000000UL
#endif

#define USART_BAUDRATE			9600
#define USART_STOP_BITS 		USART_STOP_BITS_ONE
#define USART_CHRACTER_LENGTH	USART_8BIT
#define USART_PARITY_MODE		USART_PARITY_NON

#define RXD						PORTD_0
#define TXD						PORTD_1

#endif /* USART_CFG_H_ */
