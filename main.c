/*
 * main.c
 *
 *  Created on: Nov 25, 2024
 *      Author: pro
 */

//COMMON
#include "Bitmath.h"
#include "Types.h"
#include"util/delay.h"
//MCAL
#include "DIO_Interface.h"
#include "ADC_Interface.h"
//HAL
#include"Seg_Interface.h"
#include "LCD_Interface.h"
//APP
#include "ADC_Private.h"

int main()
{


	ADCvidinit();
	LCD_vidInit();
	LCD_vidSendString("thanks Sector B5");
	LCD_vidSetPositon(1,1);
	LCD_vidSendString("and ENG.Omar...");
	_delay_ms(1500);
	LCD_vidInit();
	LCD_vidSendString("Temperature : ");

	while(1)
	{
		LCD_vidSetPositon(0,14);
		u16 adc = ADCu16read(0);
		u16 temp = (adc*2.56)/1023*100;
		LCD_vidSendNum(temp);
		_delay_ms(300);



	}



	return 0;
}

