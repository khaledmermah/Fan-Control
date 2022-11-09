/*
 * DC_motor.c
 *
 *  Created on: Oct 6, 2022
 *      Author: kMermah
 */
#include "common_macros.h" /* For GET_BIT Macro */
#include "gpio.h"
#include <avr/io.h>
#include "PWM.h"
#include "DC_motor.h"
void DcMotor_Init(void)
{
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);
	PORTB &= ~(1<<0) & ~(1<<1);

}
void DcMotor_Rotate (DcMotor_State state,uint8 speed){
	if( state ==0){
		PORTB &= ~(1<<0) & ~(1<<1);
	}
	else if( state ==1){
		PORTB &= ~(1<<0);
		PORTB |= (1<<1);
	}
	else if( state ==2){
			PORTB &= ~(1<<1);
			PORTB |= (1<<0);
		}
	PWM_Timer0_Start(speed);

}
