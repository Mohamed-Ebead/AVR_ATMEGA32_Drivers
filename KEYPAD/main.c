/*
 * main.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Mohamed_Ebead
 */


#include "STD_Types.h"

#include "DIO_int.h"


#include "KEYPAD_int.h"



void main(void){

// u8 x ;
		// lower 4 bits for input (ROWS) & higher 4 bits for output (COLOUMNS)
		  DIO_SetPortDirection (PORTD, 0b00001111);

	  DIO_SetPortValue     (PORTD,0b11111111);

		  DIO_SetPinValue(PORTD, PIN4, HIGH);
		  DIO_SetPinValue(PORTD, PIN5, HIGH);
		  DIO_SetPinValue(PORTD, PIN6, HIGH);
		  DIO_SetPinValue(PORTD, PIN7, HIGH);

		  DIO_SetPinDirection (PORTB, PIN0, OUTPUT);

		 KPD_u8GetPressedKey();
/*
if(x == 4){

	DIO_SetPinValue(PORTB , PIN0 , HIGH);

}
else {

}
*/
	while(1)
	{




	}

}
