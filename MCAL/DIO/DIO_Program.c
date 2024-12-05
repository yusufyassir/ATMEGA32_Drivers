/*
 * DIO_Program.c
 *
 *  Created on: Nov 26, 2024
 *      Author: Lenovo
 */


#include "Types.h"
#include "Bitmath.h"
#include "DIO_Private.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"


void DIO_vidSetPinDirection	(u8 PortNum,u8 PinNum,u8 PinDir)
{
	if(PortNum<=DIO_PORTD && PinNum<=DIO_PIN7)
	{
	switch(PortNum){
	case DIO_PORTA:
		if(PinDir==DIO_PIN_INPUT){
			CLR_BIT(DDRA,PinNum);
		}
		else
		{
			SET_BIT(DDRA,PinNum);
		}
		break;
	case DIO_PORTB:
		if(PinDir==DIO_PIN_INPUT){
			CLR_BIT(DDRB,PinNum);
		}
		else
		{
			SET_BIT(DDRB,PinNum);
		}
		break;
	case DIO_PORTC:
		if(PinDir==DIO_PIN_INPUT){
			CLR_BIT(DDRC,PinNum);
		}
		else
		{
			SET_BIT(DDRC,PinNum);
		}
		break;

	case DIO_PORTD:
		if(PinDir==DIO_PIN_INPUT){
			CLR_BIT(DDRD,PinNum);
		}
		else
		{
			SET_BIT(DDRD,PinNum);
		}
		break;

	default:
		//Nothing
		break;



	}
	}
}
void DIO_vidSetPinValue		(u8 PortNum,u8 PinNum,u8 PinValue)
{
	if(PortNum<=DIO_PORTD && PinNum<=DIO_PIN7)
		{
		switch(PortNum){
		case DIO_PORTA:
			if(PinValue==DIO_LOW){
				CLR_BIT(PORTA,PinNum);
			}
			else
			{
				SET_BIT(PORTA,PinNum);
			}
			break;
		case DIO_PORTB:
			if(PinValue==DIO_LOW){
				CLR_BIT(PORTB,PinNum);
			}
			else
			{
				SET_BIT(PORTB,PinNum);
			}
			break;
		case DIO_PORTC:
			if(PinValue==DIO_LOW){
				CLR_BIT(PORTC,PinNum);
			}
			else
			{
				SET_BIT(PORTC,PinNum);
			}
			break;

		case DIO_PORTD:
			if(PinValue==DIO_LOW){
				CLR_BIT(PORTD,PinNum);
			}
			else
			{
				SET_BIT(PORTD,PinNum);
			}
			break;

		default:
			//Nothing
			break;



		}
		}

}
void DIO_vidTogPinValue		(u8 PortNum,u8 PinNum){
	if(PortNum<=DIO_PORTD && PinNum<=DIO_PIN7)
		{
		switch(PortNum){
		case DIO_PORTA:
			TOG_BIT(PORTA,PinNum);
			break;
		case DIO_PORTB:
			TOG_BIT(PORTB,PinNum);
			break;
		case DIO_PORTC:
			TOG_BIT(PORTC,PinNum);
			break;
		case DIO_PORTD:
			TOG_BIT(PORTD,PinNum);
			break;

		default:
			//Nothing
			break;
		}
		}

}
u8 	 DIO_u8GetPinValue		(u8 PortNum,u8 PinNum){
	u8 Data=255;
	if(PortNum<=DIO_PORTD && PinNum<=DIO_PIN7)
		{
		switch(PortNum){
		case DIO_PORTA:
			Data=GET_BIT(PINA,PinNum);
			break;
		case DIO_PORTB:
			Data=GET_BIT(PINB,PinNum);
			break;
		case DIO_PORTC:
			Data=GET_BIT(PINC,PinNum);
			break;
		case DIO_PORTD:
			Data=GET_BIT(PIND,PinNum);
			break;

		default:
			//Nothing
			break;
		}
		}

	return Data;
}

void DIO_vidSetPortDirection(u8 PortNum,u8 PortDir){
	switch(PortNum){
	case DIO_PORTA:
		DDRA = PortDir;
		break;
	case DIO_PORTB:
		DDRB = PortDir;
		break;
	case DIO_PORTC:
		DDRC = PortDir;
		break;
	case DIO_PORTD:
		DDRD = PortDir;
		break;
		default:
			//Nothing
			break;
		}

}
void DIO_vidSetPortValue(u8 PortNum,u8 PortValue)
{
	switch(PortNum){
	case DIO_PORTA:
		PORTA = PortValue;
		break;
	case DIO_PORTB:
		PORTB = PortValue;
		break;
	case DIO_PORTC:
		PORTC = PortValue;
		break;
	case DIO_PORTD:
		PORTD = PortValue;
		break;
		default:
			//Nothing
			break;
		}

}
void DIO_vidTogPortValue(u8 PortNum)
{
	switch(PortNum){
		case DIO_PORTA:
			PORTA = !PORTA;
			break;
		case DIO_PORTB:
			PORTB = !PORTB;
			break;
		case DIO_PORTC:
			PORTC = !PORTD;
			break;
		case DIO_PORTD:
			PORTD = !PORTD;
			break;
			default:
				//Nothing
				break;
			}
}
u8 	 DIO_u8GetPortValue			(u8 PortNum){
	u8 Data;
	switch(PortNum)
	{
	case DIO_PORTA:
		Data=PINA;
	break;
	case DIO_PORTB:
		Data=PINB;
	break;
	case DIO_PORTC:
		Data=PINC;
	break;
	case DIO_PORTD:
		Data=PIND;
	break;
	default:
		//Nothing
		break;
	}
	return Data;
}


void DIO_vidSetNibble(u8 PortNum,u8 Nibble,u8 Data)
{
	switch(PortNum)
	{
	case DIO_PORTA:
			if(Nibble == DIO_NIBBLE_LOW)
			{
				PORTA&=DIO_NIP_LOW_MASK;
				Data&=DIO_DATA_HIGH_MASK;
				PORTA|=Data;
			}
			else//DIO_NIBBLE_HIGH
			{
				PORTA&=DIO_NIP_HIGH_MASK;
				Data&=DIO_DATA_LOW_MASK;
				PORTA|=Data;
			}
		break;
		case DIO_PORTB:
			if(Nibble == DIO_NIBBLE_LOW)
			{
				PORTB&=DIO_NIP_LOW_MASK;
				Data&=DIO_DATA_HIGH_MASK;
				PORTB|=Data;
			}
			else//DIO_NIBBLE_HIGH
			{
				PORTB&=DIO_NIP_HIGH_MASK;
				Data&=DIO_DATA_LOW_MASK;
				PORTB|=Data;
			}

		break;
		case DIO_PORTC:
			if(Nibble == DIO_NIBBLE_LOW)
			{
				PORTC&=DIO_NIP_LOW_MASK;
				Data&=DIO_DATA_HIGH_MASK;
				PORTC|=Data;
			}
			else//DIO_NIBBLE_HIGH
			{
				PORTC&=DIO_NIP_HIGH_MASK;
				Data&=DIO_DATA_LOW_MASK;
				PORTC|=Data;
			}

		break;
		case DIO_PORTD:
			if(Nibble == DIO_NIBBLE_LOW)
			{
				PORTD&=DIO_NIP_LOW_MASK;
				Data&=DIO_DATA_HIGH_MASK;
				PORTD|=Data;
			}
			else//DIO_NIBBLE_HIGH
			{
				PORTD&=DIO_NIP_HIGH_MASK;
				Data&=DIO_DATA_LOW_MASK;
				PORTD|=Data;
			}

		break;
		default:
			//Nothing
			break;
	}
}
