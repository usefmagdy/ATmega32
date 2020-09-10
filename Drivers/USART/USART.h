/*
 * USART.h
 *
 *  Created on: Feb 7, 2020
 *      Author: Yousif Magdy
 */

#ifndef USART_H_
#define USART_H_

void UART_vidInit(void);
void UART_vidSendChar(uint8 u8Data);
uint8 UART_u8RecieveChar(void);
void UART_vidSendString(uint8* u8Data, uint8 length);
void UART_vidRecieveString(uint8* u8Data, uint8* length);

#endif /* USART_H_ */
