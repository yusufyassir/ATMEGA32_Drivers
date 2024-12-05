/*
 * LCD_Interface.h
 *
 *  Created on: Nov 27, 2024
 *      Author: pro
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#define LCD_LINE1		0
#define LCD_LINE2		1


void LCD_vidInit(void);

void LCD_vidSetPositon(u8 LineNum, u8 ColumnNum);

void LCD_vidSendChar(u8 Data);

void LCD_vidSendNum(u32 Data );

/*Recommended Task*/
void LCD_vidSendFloat(f32 Data , u8 DecimalNum);

/*Recommended Task*/
void LCD_vidSendString(u8* String);

/*** BOUNUS GDNNN***/
// LCD_vidGenerate Char




#endif /* HAL_LCD_LCD_INTERFACE_H_ */
