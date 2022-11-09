/*
 * icu.c
 *
 *  Created on: Oct 6, 2022
 *      Author: kMermah
 */
#include "icu.h"
#include "common_macros.h" /* For GET_BIT Macro */
#include <avr/io.h>
#include <avr/interrupt.h>
static volatile void (*g_callBackPtr)(void) = NULL_PTR;

ISR(TIMER1_CAPT_vect)
{
	if(g_callBackPtr != NULL_PTR)
	{
		/* Call the Call Back function in the application after the edge is detected */
		(*g_callBackPtr)(); /* another method to call the function using pointer to function g_callBackPtr(); */
	}
}
void Icu_init(const Icu_ConfigType * Config_Ptr){
	DDRD &=~(1<<6);
	TCCR1A = (1<<FOC1A) | (1<<FOC1B);
	TCCR1B = (( TCCR1B & 0xF8 ) |( Config_Ptr->clock));
	TCCR1B = (TCCR1B & 0xBF) | ((Config_Ptr->edge)<<6);
	TCNT1 = 0;
	ICR1 = 0;
	TIMSK |=(1<<TICIE1);

}
void Icu_setCallBack(void(*a_ptr)(void)){
	g_callBackPtr = a_ptr;
}
void Icu_setEdgeDetectionType(const Icu_EdgeType a_edgeType){
	TCCR1B = (( TCCR1B & 0XBF ) | (a_edgeType<<6));
}
uint16 Icu_getInputCaptureValue(void){
	return ICR1;
}
void Icu_clearTimerValue(void){
	TCNT1 = 0;
}
void Icu_DeInit(void)
{
	/* Clear All Timer1 Registers */
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
	ICR1 = 0;

	/* Disable the Input Capture interrupt */
	TIMSK &= ~(1<<TICIE1);
}




