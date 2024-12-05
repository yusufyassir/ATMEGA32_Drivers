/*
 * DIO_Private.h
 *
 *  Created on: Nov 26, 2024
 *      Author: Lenovo
 */

#ifndef MCAL_DIO_DIO_PRIVATE_H_
#define MCAL_DIO_DIO_PRIVATE_H_
#include "Types.h"

#define PORTA		*((volatile u8*)0x3B)
#define DDRA		*((volatile u8*)0x3A)
#define PINA		*((volatile u8*)0x39)

#define PORTB		*((volatile u8*)0x38)
#define DDRB		*((volatile u8*)0x37)
#define PINB		*((volatile u8*)0x36)

#define PORTC		*((volatile u8*)0x35)
#define DDRC		*((volatile u8*)0x34)
#define PINC		*((volatile u8*)0x33)

#define PORTD		*((volatile u8*)0x32)
#define DDRD		*((volatile u8*)0x31)
#define PIND		*((volatile u8*)0x30)

#define DIO_NIP_LOW_MASK	0xf0
#define DIO_NIP_HIGH_MASK	0x0f

#define DIO_DATA_LOW_MASK	0xf0
#define DIO_DATA_HIGH_MASK	0x0f
#endif /* MCAL_DIO_DIO_PRIVATE_H_ */
