/*
 * Seg_Program.c
 *
 *  Created on: Nov 27, 2024
 *      Author: pro
 */


#include"Seg_Config.h"
#include"Seg_Interface.h"
#include"Seg_Private.h"




void Seg_vidInit(void)
{

	DIO_vidSetPinDirection(SEG_Port, SEG_PinA, DIO_PIN_OUTPUT);
	DIO_vidSetPinDirection(SEG_Port, SEG_PinB, DIO_PIN_OUTPUT);
	DIO_vidSetPinDirection(SEG_Port, SEG_PinC, DIO_PIN_OUTPUT);
	DIO_vidSetPinDirection(SEG_Port, SEG_PinD, DIO_PIN_OUTPUT);
	DIO_vidSetPinDirection(SEG_Port, SEG_PinE, DIO_PIN_OUTPUT);
	DIO_vidSetPinDirection(SEG_Port, SEG_PinF, DIO_PIN_OUTPUT);
	DIO_vidSetPinDirection(SEG_Port, SEG_PinG, DIO_PIN_OUTPUT);

}


void Seg_vidDispaly(u8 Data)
{
	switch(Data)
	{
	case 0:
		DIO_vidSetPinValue(SEG_Port, SEG_PinA, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinB, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinC, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinD, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinE, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinF, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinG, DIO_LOW);
		break;
	case 1:
		DIO_vidSetPinValue(SEG_Port, SEG_PinA, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinB, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinC, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinD, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinE, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinF, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinG, DIO_LOW);
		break;
	case 2:
		DIO_vidSetPinValue(SEG_Port, SEG_PinA, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinB, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinC, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinD, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinE, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinF, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinG, DIO_HIGH);
		break;
	case 3:
		DIO_vidSetPinValue(SEG_Port, SEG_PinA, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinB, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinC, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinD, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinE, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinF, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinG, DIO_HIGH);
		break;
	case 4:
		DIO_vidSetPinValue(SEG_Port, SEG_PinA, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinB, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinC, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinD, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinE, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinF, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinG, DIO_HIGH);
		break;
	case 5:
		DIO_vidSetPinValue(SEG_Port, SEG_PinA, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinB, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinC, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinD, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinE, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinF, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinG, DIO_HIGH);
		break;
	case 6:
		DIO_vidSetPinValue(SEG_Port, SEG_PinA, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinB, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinC, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinD, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinE, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinF, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinG, DIO_HIGH);
		break;
	case 7:
		DIO_vidSetPinValue(SEG_Port, SEG_PinA, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinB, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinC, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinD, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinE, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinF, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinG, DIO_LOW);
		break;
	case 8:
		DIO_vidSetPinValue(SEG_Port, SEG_PinA, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinB, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinC, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinD, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinE, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinF, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinG, DIO_HIGH);
		break;
	case 9:
		DIO_vidSetPinValue(SEG_Port, SEG_PinA, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinB, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinC, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinD, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinE, DIO_LOW);
		DIO_vidSetPinValue(SEG_Port, SEG_PinF, DIO_HIGH);
		DIO_vidSetPinValue(SEG_Port, SEG_PinG, DIO_HIGH);
		break;
	default:
		break;
	}
}
