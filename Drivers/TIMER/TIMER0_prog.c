/****************************************************************/
/*	Author :	Hassan Omar										*/
/*	Date   :	23 Match 2018									*/
/*	Version:	3.0												*/
/****************************************************************/


#include <avr/io.h>
#include "std_types.h"
#include "BIT_MATH.h"
#include "TIMER_priv.h"
#include "TIMER_config.h"
#include "TIMER_int.h"


void TIM0_voidInitialize(void)
{
#if TIM0_u8_MODE  == TIM0_u8_OV
	/*	Disable OverFlow interrupt	*/
	CLRBIT(TIMSK, TOIE0);
	/*	Clear OverFlow Flag			*/
	SETBIT(TIFR, TOV0);
#elif TIM0_u8_MODE  == TIM0_u8_CTC
	/* 	Enable CTC for Waveform Generator	*/
	TCCR0 |= (1 << FOC0) | (1 << WGM01);
	/*	Disable CTC interrupt				*/
	CLRBIT(TIMSK, OCIE0);
	/*	Clear CTC Flag					    */
	SETBIT(TIFR, OCF0);
	/*	Set the Compare Value 				*/
	OCR0   = TIM0_COMPARE_VALUE;
#elif TIM0_u8_MODE  == TIM0_u8_FastPWD
	/*	Disable Compare Match interrupt		*/
	CLRBIT(TIMSK, OCIE0);

	/*	Clear CTC Flag					    */
	SETBIT(TIFR, OCF0);

	/*	Set Compare Value					*/
	OCR0 = TIM0_COMPARE_VALUE;

	/*	Enable Fast PWD Mode				*/
	TCCR0 |= (1 << WGM01) | (1 << WGM00);

	#if TIM0_PWD_MODE == TIM0_PWD_NORMAL
		TCCR0 |= (1 << COM01);
	#elif TIM0_PWD_MODE == TIM0_PWD_INVERTED
		TCCR0 |= (1 << COM00) | (1 << COM01);
	#else
		#error "PWM Mode is not found"
	#endif

#elif TIM0_u8_MODE == TIM0_u8_PhasePWD
	/*	Disable Compare Match interrupt		*/
	CLRBIT(TIMSK, OCIE0);
	/*	Clear CTC Flag					    */
	SETBIT(TIFR, OCF0);
	/*	Set Compare Value					*/
	OCR0 = TIM0_COMPARE_VALUE;
	/*	Enable Phase Correct PWD Mode		*/
	TCCR0 |= (1 << WGM00);
	#if TIM0_PWD_MODE == TIM0_PWD_NORMAL
		TCCR0 |= (1 << COM01);
	#elif TIM0_PWD_MODE == TIM0_PWD_INVERTED
		TCCR0 |= (1 << COM00) | (1 << COM01);
	#else
		#error "PWM Mode is not found"
	#endif
#else
	#error "Timer Mode is Fault"
#endif

/******************************************************************/
/*	Set Mode and Prescaller	*/
#if	TIM0_u16_PRESCALLER   ==	TIM0_u16_DIV_1
	TCCR0 |= 0b00000001;
#elif TIM0_u16_PRESCALLER ==	TIM0_u16_DIV_8
	TCCR0 |= 0b00000010;
#elif TIM0_u16_PRESCALLER ==	TIM0_u16_DIV_64
	TCCR0 |= 0b00000011;
#elif TIM0_u16_PRESCALLER ==	TIM0_u16_DIV_256
	TCCR0 |= 0b00000100;
#elif TIM0_u16_PRESCALLER ==	TIM0_u16_DIV_1024
	TCCR0 |= 0b00000101;
#else
	#error "Prescaller you chose is fault or not available"
#endif
/******************************************************************/
}


#if TIM0_u8_MODE  == TIM0_u8_OV
	void TIM0_NORMAL_En_INT(void)
	{
		SETBIT(TIMSK,TOIE0);
	}

	void TIM0_NORMAL_Dis_INT(void)
	{
		CLRBIT(TIMSK, TOIE0);
	}

	void TIM0_voidSetTimerRegister(u8 Copy_u8Value)
	{
		TCNT0 = Copy_u8Value;
	}

#elif TIM0_u8_MODE  == TIM0_u8_CTC
	void TIM0_CTC_En_INT(void)
	{
		SETBIT(TIMSK, OCIE0);
	}

	void TIM0_CTC_Dis_INT(void)
	{
		CLRBIT(TIMSK, OCIE0);
	}

	void TIM0_CTC_CompareValue(u8 u8Compare_Value)
	{
		OCR0   = u8Compare_Value;
	}

	void TIM0_CTC_OC0_Disable(void)
	{
		CLRBIT(TCCR0, COM00);
		CLRBIT(TCCR0, COM01);
	}

	void TIM0_CTC_OC0_TOGGLE(void)
	{
		SETBIT(TCCR0, COM00);
		CLRBIT(TCCR0, COM01);
	}

	void TIM0_CTC_OC0_CLEAR(void)
	{
		SETBIT(TCCR0, COM01);
		CLRBIT(TCCR0, COM00);
	}

	void TIM0_CTC_OC0_SET(void)
	{
		TCCR0 |= (1 << COM00) | (1 << COM01);
	}

#elif TIM0_u8_MODE  == TIM0_u8_FastPWD || TIM0_u8_MODE  == TIM0_u8_PhasePWD

	void TIM0_En_INT_CompMatch(void)
	{
		SETBIT(TIMSK, OCIE0);
	}

	void TIM0_Dis_INT_CompMatch(void)
	{
		CLRBIT(TIMSK, OCIE0);
	}

	void TIM0_Set_CompareValue(u8 u8Compare_Value)
	{
		OCR0   = u8Compare_Value;
	}

	void TIM0_PWM_OC0_Norm(void)
	{
		CLRBIT(TCCR0, COM00);
		TCCR0 |= (1 << COM01);
	}

	void TIM0_PWM_OC0_Invert(void)
	{
		TCCR0 |= (1 << COM01) | (1 << COM00);
	}

#endif
