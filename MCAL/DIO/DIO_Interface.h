/*
 * DIO_Interface.h
 *
 *  Created on: Nov 26, 2024
 *      Author: Lenovo
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_

#include "Types.h"

#define DIO_PORTA	0
#define DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3

#define DIO_PIN0	0
#define DIO_PIN1	1
#define DIO_PIN2	2
#define DIO_PIN3	3
#define DIO_PIN4	4
#define DIO_PIN5	5
#define DIO_PIN6	6
#define DIO_PIN7	7

#define DIO_PIN_INPUT		0
#define DIO_PIN_OUTPUT		1

#define DIO_LOW			0
#define DIO_HIGH		1

#define DIO_NIBBLE_LOW 0
#define DIO_NIBBLE_HIGH 1


void DIO_vidSetPinDirection	(u8 PortNum,u8 PinNum,u8 PinDir);
void DIO_vidSetPinValue		(u8 PortNum,u8 PinNum,u8 PinValue);
void DIO_vidTogPinValue		(u8 PortNum,u8 PinNum);
u8 	 DIO_u8GetPinValue		(u8 PortNum,u8 PinNum);
//ports-op
void DIO_vidSetPortDirection(u8 PortNum,u8 PortDir);
void DIO_vidSetPortValue(u8 PortNum,u8 PortValue);
void DIO_vidTogPortValue(u8 PortNum);
u8 	 DIO_u8GetPortValue			(u8 PortNum);
/****************TASKSSS******************/

/*
void DIO_vidSetPortDirection
void DIO_vidSetPortValue
void DIO_vidTogPortValue
u8 	 DIO_u8GetPortValue
*/
void DIO_vidSetNibble(u8 PortNum,u8 Nibble,u8 Data);

#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
