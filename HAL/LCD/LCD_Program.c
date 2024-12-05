/*
 * LCD_Program.c
 *
 *  Created on: Nov 27, 2024
 *      Author: pro
 */



#include "Types.h"
#include "Bitmath.h"

#include "util/delay.h"

#include "DIO_Interface.h"

#include "LCD_Private.h"
#include "LCD_Config.h"
#include "LCD_Interface.h"

static void LCD_vidSendCommand(u8 Command){

	//Select Command Register
	DIO_vidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_LOW);

	//Write Mode
	DIO_vidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

	//Send 4MSB In data
	DIO_vidSetNibble(LCD_DATA_PORT,DIO_NIBBLE_HIGH,Command);

	//Pulse
	DIO_vidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_vidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);

	//The rest of the data
	Command<<=4;
	DIO_vidSetNibble(LCD_DATA_PORT,DIO_NIBBLE_HIGH,Command);

	//Pulse
	DIO_vidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_vidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);

}

void LCD_vidInit(void){
	DIO_vidSetPinDirection(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);
	DIO_vidSetPinDirection(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_vidSetPinDirection(LCD_CONTROL_PORT,LCD_E_PIN,DIO_PIN_OUTPUT);

	DIO_vidSetPinDirection(LCD_CONTROL_PORT,LCD_D4_PIN,DIO_PIN_OUTPUT);
	DIO_vidSetPinDirection(LCD_CONTROL_PORT,LCD_D5_PIN,DIO_PIN_OUTPUT);
	DIO_vidSetPinDirection(LCD_CONTROL_PORT,LCD_D6_PIN,DIO_PIN_OUTPUT);
	DIO_vidSetPinDirection(LCD_CONTROL_PORT,LCD_D7_PIN,DIO_PIN_OUTPUT);

	_delay_ms(30);
	LCD_vidSendCommand(RETURN_HOME);
	_delay_ms(10);
	LCD_vidSendCommand(FUNCTION_SET);
	_delay_ms(2);
	LCD_vidSendCommand(DISPLAY_CURSOR);
	_delay_ms(2);
	LCD_vidSendCommand(ENTRY_MODE);
	_delay_ms(2);
	LCD_vidSendCommand(CLEAR_DISPALY);
	_delay_ms(3);

}

void LCD_vidSendChar(u8 Data){
	//Select Address Register
	DIO_vidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,DIO_HIGH);

	//Write Mode
	DIO_vidSetPinValue(LCD_CONTROL_PORT,LCD_RW_PIN,DIO_LOW);

	//Data Send MSB of Data
	DIO_vidSetNibble(LCD_DATA_PORT,DIO_NIBBLE_HIGH,Data);
	_delay_ms(2);

	//Pulse
	DIO_vidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_vidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);

	//Send LSB of Data
	Data<<=4;
	//Data Send
	DIO_vidSetNibble(LCD_DATA_PORT,DIO_NIBBLE_HIGH,Data);
	_delay_ms(2);

	//Pulse
	DIO_vidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_vidSetPinValue(LCD_CONTROL_PORT,LCD_E_PIN,DIO_LOW);

}

void LCD_vidSendNum(u32 Data ){
	u8 ArrOfDigit[10];
	u8 i=0;
	while(Data!=0)
	{
		//Save Digits from least in the array
		ArrOfDigit[i]=Data%10;
		//Throw the smallest digit away
		Data/=10;
		i++;
	}
	for(s8 j=i-1;j>=0 ;j--)
	{
		//Send The data +48 --> Refer to the ascii table
		LCD_vidSendChar(ArrOfDigit[j]+48);
	}
}

void LCD_vidSetPositon(u8 LineNum, u8 ColumnNum)
{
	if(LineNum == LCD_LINE1){
		LCD_vidSendCommand( LINE_1_ADDRESS + ColumnNum );//Address  1 000 0000
	}
	else //if(LineNum == LCD_LINE2)
	{
		LCD_vidSendCommand( LINE_2_ADDRESS + ColumnNum - 1 ) ;
	}


}

void LCD_vidSendString(u8* String)
{
	for(u8 i = 0; *(String+i) != 0 ;i++)
	{
		LCD_vidSendChar(*(String+i));
//		if (*(String+i) == '\0')
//			break;
	}


}
