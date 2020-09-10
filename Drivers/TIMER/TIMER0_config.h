/****************************************************************/
/*	Author :	Yousif Magdy				*/
/*	Date   :	23 June 2019				*/
/*	Version:	1.0					*/
/****************************************************************/

#ifndef _TIMER_CONFIG_H
#define _TIMER_CONFIG_H


/********************************/
/*	Range: TIM0_u16_DIV_1		*/
/*	       TIM0_u16_DIV_8		*/
/*	       TIM0_u16_DIV_64		*/
/*	       TIM0_u16_DIV_256		*/
/*	       TIM0_u16_DIV_1024	*/
/********************************/
#define TIM0_u16_PRESCALLER		TIM0_u16_DIV_8

/********************************/
/*	Modes:	TIM0_u8_CTC			*/
/*			TIM0_u8_OV			*/
/*			TIM0_u8_FastPWD	  	*/
/*			TIM0_u8_PhasePWD    */
/********************************/
#define TIM0_u8_MODE	TIM0_u8_CTC

#if TIM0_u8_MODE == TIM0_u8_CTC
	/*	Set the Compare Value        */
#define TIM0_COMPARE_VALUE			250


#elif TIM0_u8_MODE == TIM0_u8_FastPWD || TIM0_u8_MODE == TIM0_u8_PhasePWD
	/*	PWD MODES:	TIM0_PWD_NORMAL		*/
	/* 	 	 	 	TIM0_PWD_INVERTED	*/
	#define TIM0_PWD_MODE		TIM0_PWD_INVERTED
	#define TIM0_COMPARE_VALUE			200



#endif

#endif /* TIMER_CONFIG_H_ */
