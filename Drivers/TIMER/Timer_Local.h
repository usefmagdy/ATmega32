/*
 * Timer_Local.h
 *
 *  Created on: Dec 10, 2019
 *      Author: yousi
 */

#ifndef TIMER_LOCAL_H_
#define TIMER_LOCAL_H_

#define SREG *((volatile uint8*)0x5f)
#define OCR0 *((volatile uint8*)0x5c)
#define TIMSK *((volatile uint8*)0x59)
#define TIFR *((volatile uint8*)0x58)
#define TCCR0 *((volatile uint8*)0x53)
#define TCNT0 *((volatile uint8*)0x52)
#define MCUCR *((volatile uint8*)(0x55))
#define GICR *((volatile uint8*)(0x5B))


#define TCCR1A *((volatile uint8*)(0x4F)
#define TCCR1B *((volatile uint8*)(0x4E)
#define OCR1AL  *((volatile uint8*)(0x4A)
#define OCR1AH  *((volatile uint8*)(0x4B)
#define OCR1BH  *((volatile uint8*)(0x49)
#define OCR1BL  *((volatile uint8*)(0x48)


#define TCNT1H *((volatile uint8*)(0x4D)
#define TCNT1L *((volatile uint8*)(0x4C)



#define TCCR2 *((volatile uint8*)0x45)
#define OCR2 *((volatile uint8*)0x43)
#define TCNT2 *((volatile uint8*)0x44)




#endif /* TIMER_LOCAL_H_ */
