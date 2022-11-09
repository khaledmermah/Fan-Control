/*
 * ADC.c
 *
 *  Created on: Oct 1, 2022
 *      Author: kMermah
 */
#include "adc.h"

#include <util/delay.h> /* For the delay functions */
#include "common_macros.h" /* For GET_BIT Macro */
#include "lcd.h"
#include "gpio.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#if(!(polling))

volatile uint16 g_adcResult = 0;

ISR(ADC_vect)
{
	/* Read ADC Data after conversion complete */
	g_adcResult = ADC;
}
#endif
void ADC_init(const ADC_ConfigType * Config_Ptr){
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADCSRA,ADEN);
	ADCSRA= (ADCSRA | 0x03);
#if(!polling)
	SET_BIT(ADCSRA,ADIE);
#endif
}
#if(polling)
uint16 ADC_readChannel(uint8 ch_num){
	ch_num &= 0x07;
	ADMUX = ((ADMUX & 0xE0) | (ch_num));   //ch_num is 3 bits number "choosing channel num by send it as argument
		SET_BIT(ADCSRA,ADSC);

		while(BIT_IS_CLEAR(ADCSRA,ADIF));
		SET_BIT(ADCSRA,ADIF);
		return ADC;
}
#endif

#if(!polling)
void ADC_readChannel(uint8 ch_num){
	ch_num &= 0x07;
	ADMUX = ((ADMUX & 0xE0) | (ch_num));   //ch_num is 3 bits number "choosing channel num by send it as argument
		SET_BIT(ADCSRA,ADSC);

}
#endif




