/*
 * ADC_Private.h
 *
 *  Created on: Dec 1, 2024
 *      Author: pro
 */

#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_



#define ADMUX	*((volatile u8*)0x27)
#define ADCSRA	*((volatile u8*)0x26)
#define ADCDATA	*((volatile u16*)0x24)


#define ADC_INTERNAL	0b11000000

#define ADC_ENABLE 0b10000000

#define ADC_START	0b01000000

#define ADC_PRESCALER	0b00000111


#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
