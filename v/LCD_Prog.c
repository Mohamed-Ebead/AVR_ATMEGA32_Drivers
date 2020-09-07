/*
 * LCD_Prog.c
 *
 *  Created on: Aug 24, 2019
 *      Author: Mohamed_Ebead
 */


#include "STD_Types.h"
#include<util/delay.h>
#include "DIO_int.h"

#include "LCD_int.h"


void   Initialize_LCD(void){

	//FUNCTION SET
	  LCD_Write_Command(0b00001100);
	  _delay_ms (1000);


	  // DISPLAY ON/OFF CONTROL
	  LCD_Write_Command(0b00001111);
	  _delay_ms (1000);



	  //DISPLAY CLEAR
	  LCD_Write_Command(0b00000001);
	  _delay_ms (2000);



	  // Entry mode set
	  LCD_Write_Command(0b00000111);
	  _delay_ms (2000);






}



/**************************************************/
 void LCD_Write_Command(u8 a) {
	  // Set RS = 0
	  DIO_SetPinValue(PORTA , PIN1, LOW);

	  // Set R/W = 0
	  DIO_SetPinValue(PORTA , PIN2, LOW);

	  // Set EN = 0
	  DIO_SetPinValue(PORTA , PIN3, LOW);

	  DIO_SetPortValue     (PORTB,a);

	  DIO_SetPinValue(PORTA , PIN3, HIGH);
	  _delay_ms(10000);
	  DIO_SetPinValue(PORTA , PIN3, LOW);

  }

