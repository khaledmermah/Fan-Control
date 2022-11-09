/*
 * ADC.h
 *
 *  Created on: Oct 1, 2022
 *      Author: kMermah
 */

#ifndef ADC_H_
#define ADC_H_
#include  "std_types.h"
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56
#define polling 1
#define ADC_ReferenceVolatge uint8

#define ADC_Prescaler uint8

typedef struct{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;
extern volatile uint16 g_adcResult;

void ADC_init(const ADC_ConfigType * Config_Ptr);
#if(polling)
uint16 ADC_readChannel(uint8 ch_num);
#endif
#if(!polling)
void ADC_readChannel(uint8 ch_num);
#endif
#endif /* ADC_H_ */
