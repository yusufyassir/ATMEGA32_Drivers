/*
 * ADC_Program.c
 *
 *  Created on: Dec 1, 2024
 *      Author: pro
 */


#ifndef MCAL_ADC_ADC_PROGRAM_C_
#define MCAL_ADC_ADC_PROGRAM_C_

#include "Bitmath.h"
#include "Types.h"

#include"ADC_Config.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"

#include "util/delay.h"

void ADCvidinit(void)
{
	ADMUX &= 0x00;
	ADCSRA = 0;
	//set internal voltage ref
	ADMUX |= ADC_INTERNAL;
	// set prescaller
	ADCSRA |= ADC_PRESCALER;
	//turn on adc
	ADCSRA |= ADC_ENABLE;
	//start conversion
	ADCSRA |= ADC_START;
}


u16 ADCu16read(u8 channel)
{
	ADMUX &= 0xF0;
	ADMUX |= channel;
	ADCSRA |= ADC_START;
	while(GET_BIT(ADCSRA, 6));
	return ADCDATA;

}

#endif /* MCAL_ADC_ADC_PROGRAM_C_ */
