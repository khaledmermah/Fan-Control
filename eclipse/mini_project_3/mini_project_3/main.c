/*
 ======================================================================================
 Name        : mini_project_3.c.c
 Author      : Khaled Mermah
 Description : the fan is turned ON or OFF with different levels depending on the temperature
 Date        : 18/6/2017
 ======================================================================================
 */
#include "LM35.h"
#include "lcd.h"
#include <avr/io.h>
#include "adc.h"
#include "PWM.h"
#include "DC_motor.h"
#include "gpio.h"
#include "common_macros.h"
#include "std_types.h"

int main(void)
{
	ADC_ConfigType confi = { 2.56 ,8 };
	uint8 temp ;
	LCD_init(); /* initialize LCD driver */
	ADC_init(&confi); /* initialize ADC driver */
	DcMotor_Init(); /* initialize DC MOTOR driver */
	SREG |= (1<<7);/* Enable Global Interrupts */

	LCD_moveCursor(1,2);  //move cursor to sec row and third column to  write the below at this position
	LCD_displayString("Temp =     C "); //display this on lcd
	while(1)
	{
		temp = LM35_GetTemperature(); //get temperature from this fun and store it at temp variable
		LCD_moveCursor(1,9); //move cursor to sec row and  column number 9 to start write the temperature value at this position
		LCD_intgerToString(temp);
		if(temp<100)
		{
			/* In case the digital value is three or two or one digits print space in the next digit place */
			LCD_moveCursor(1,11);
			LCD_displayCharacter(' ');
		}

		if(temp<30){
			LCD_moveCursor(0,0); //move cursor to first row and  first column start write from the begainning
			LCD_displayString("  FAN IS OFF "); //displayed at lcd
			DcMotor_Rotate(stop,0); //stop the dc motor and give it power = 0%
		}

		else if(temp<60){
			LCD_moveCursor(0,0);//move cursor to first row and  first column start write from the begainning
			LCD_displayString("  FAN IS ON ");//displayed at lcd
			DcMotor_Rotate(CW,25);//stop the dc motor and give it power = 25%
		}

		else if(temp<90){
			LCD_moveCursor(0,0);//move cursor to first row and  first column start write from the begainning
			LCD_displayString("  FAN IS ON ");//displayed at lcd
			DcMotor_Rotate(CW,50);//stop the dc motor and give it power = 50%
		}

		else if(temp<120){
			LCD_moveCursor(0,0);//move cursor to first row and  first column start write from the begainning
			LCD_displayString("  FAN IS ON ");//displayed at lcd
			DcMotor_Rotate(CW,75);//stop the dc motor and give it power = 75%
		}

		else if(temp>=120){
			LCD_moveCursor(0,0);//move cursor to first row and  first column start write from the begainning
			LCD_displayString("  FAN IS ON ");//displayed at lcd
			DcMotor_Rotate(CW,100);//stop the dc motor and give it power = 100%
		}
	}

}
