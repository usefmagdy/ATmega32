
#ifndef _TIMER_INT_H
#define _TIMER_INT_H

void TIM0_voidInitialize(void);

#if TIM0_u8_MODE  == TIM0_u8_OV
	void TIM0_NORMAL_En_INT(void);
	void TIM0_NORMAL_Dis_INT(void);
	void TIM0_voidSetTimerRegister(u8 Copy_u8Value);
#endif
#if TIM0_u8_MODE  == TIM0_u8_CTC
	void TIM0_CTC_En_INT(void);
	void TIM0_CTC_Dis_INT(void);
	void TIM0_CTC_CompareValue(u8 u8Compare_Value);
	void TIM0_CTC_OC0_Disable(void);
	void TIM0_CTC_OC0_TOGGLE(void);
	void TIM0_CTC_OC0_CLEAR(void);
	void TIM0_CTC_OC0_SET(void);
#endif
#if TIM0_u8_MODE  == TIM0_u8_FastPWD || TIM0_u8_MODE  == TIM0_u8_PhasePWD
	void TIM0_PWM_OC0_Norm(void);
	void TIM0_PWM_OC0_Invert(void);
	void TIM0_En_INT_CompMatch(void);
	void TIM0_Dis_INT_CompMatch(void);
	void TIM0_Set_CompareValue(u8 u8Compare_Value);
#endif


void TIM0_voidSetCallBack(void (*Copy_ptr) (void));



#endif /* TIMER_INT_H_ */
