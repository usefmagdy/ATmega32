#include <avr/io.h>
#include "platform_types.h"
#include "utils.h"
#include "ADC.h"
void ADC_init(uint8 channel)
 {
	 CLRBIT(ADMUX,0);
	 CLRBIT(ADMUX,1);
	 CLRBIT(ADMUX,2);
	 CLRBIT(ADMUX,3);
	 CLRBIT(ADMUX,4);
	 SETBIT(ADMUX,5);
	 SETBIT(ADMUX,6);
	 CLRBIT(ADMUX,7);
	 SETBIT(ADCSRA,7);
	 SETBIT(ADCSRA,0);
	 SETBIT(ADCSRA,1);
	 SETBIT(ADCSRA,2);
 }
 uint16 ADC_GET_result(void)
 {
	 SETBIT(ADCSRA,6);
	 while (GETBIT(ADCSRA,4)==0);
	 SETBIT(ADCSRA,4);
	 return ADCH;
 }
/*void ADC_init(void)
{
	ADMUX|=(1<<REFS0)|(1<<ADLAR);
	ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}

int ADC_GetResult(char channel)
{
	int value;
	ADMUX|= (channel & (0b00000111));
	ADCSRA|= (1<<ADSC);
	while((ADCSRA & (1<<ADSC))!=0);
	value=ADCH;
	ADCSRA|= 0x10;
	return value;
}
*/
