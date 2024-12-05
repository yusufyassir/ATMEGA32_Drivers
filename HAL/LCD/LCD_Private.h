/*
 * LCD_Private.h
 *
 *  Created on: Nov 27, 2024
 *      Author: pro
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_


//C instructions
#define CLEAR_DISPALY 0b00000001
#define RETURN_HOME	0b00000010

//entry mode options
#define ENTRY_MODE_INCREMENT	0b00000110
#define ENTRY_MODE_DECREMENT	0b00000100

//cursor options
#define DISPLAY_ON_CURSOR_ON_NOBLINK		0b00001110
#define DISPLAY_ON_CURSOR_ON_BLINK			0b00001111
#define DISPLAY_ON_CURSOR_OFF				0b00001100

//display option
#define FUNCTION_SET_4_BIT_1	0b00100100
#define FUNCTION_SET_4_BIT_2	0b00101000
#define FUNCTION_SET_8_BIT_1	0b00110100
#define FUNCTION_SET_8_BIT_2	0b00111000
//ram line address
#define LINE_1_ADDRESS  128
#define LINE_2_ADDRESS  192





#endif /* HAL_LCD_LCD_PRIVATE_H_ */
