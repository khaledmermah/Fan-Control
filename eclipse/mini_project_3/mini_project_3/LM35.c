#include "LM35.h"
#include <util/delay.h> /* For the delay functions */
#include "common_macros.h" /* For GET_BIT Macro */
#include "lcd.h"
#include "gpio.h"
#include <avr/io.h>
#include "adc.h"

uint8 LM35_GetTemperature(){
	uint8 temp_value = 0;

	uint16 adc_value = 0;
#if(!(polling))
	ADC_readChannel(SENSOR_CHANNEL_ID);
#endif
	/* Read ADC channel where the temperature sensor is connected */
#if (polling)
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);
#endif
#if(!(polling))
	adc_value = g_adcResult;
#endif
	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}
