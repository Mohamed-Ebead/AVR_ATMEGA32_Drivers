/*
 * main.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Mohamed_Ebead
 */


#include "STD_Types.h"
#include"BIT_MATH.h"
#include<util/delay.h>

#include "DIO_int.h"
#include "DIO_reg.h"

#include "LCD_int.h"
#include "KEYPAD_int.h"


void main(void){

	u8 C[10]= "Clockwise" ;
    u8 CC[12]= "C.Clockwise" ;
    u8 S[5]= "Stop" ;

	     _delay_ms(50);

		// SET VDD TO A0   5 Volt (A0 >> VDD)
		  DIO_SetPinDirection (PORTA, PIN0, HIGH);

		  //  RS >> A1
		  DIO_SetPinDirection (PORTA, PIN1, HIGH);

		  //  R/W >> A2
		  DIO_SetPinDirection (PORTA, PIN2, HIGH);

		  //  Enable >> A3
		   DIO_SetPinDirection (PORTA, PIN3, HIGH);


		  //SET PORTC AS OUTPUT (PORTC >> DB0...DB7)
		  DIO_SetPortDirection (PORTC, 0XFF);



		  // lower 4 bits for input (ROWS) & higher 4 bits for output (COLOUMNS)
		  DIO_SetPortDirection (PORTD, 0b00001111);

		 DIO_SetPortValue (PORTD,0xff);


		   DIO_SetPinDirection (PORTB, PIN0, HIGH);



			LCD_vidInitialize();

u8 x ;
while(1){


	x= KPD_u8GetPressedKey();

	switch (x){
	case 1 :  // clockwise
		LCD_vidInitialize();
		DIO_SetPinValue(PORTB , PIN0, HIGH);
	    DIO_SetPinValue(PORTB , PIN1, HIGH);

		LCD_vidWriteString (&C,10) ;
      _delay_ms(2500);

       break ;
	case 2 : //counter clockwise
		LCD_vidInitialize();
		DIO_SetPinValue(PORTB , PIN0, LOW);
	    DIO_SetPinValue(PORTB , PIN1, LOW);

		LCD_vidWriteString (&CC,12) ;
		_delay_ms(2500);

		break ;

	default : // stop
		LCD_vidInitialize();
		DIO_SetPinValue(PORTB , PIN0, HIGH);
		DIO_SetPinValue(PORTB , PIN1, LOW);

		LCD_vidWriteString (&S,5) ;
	//	_delay_ms(2500);

		 break ;
	}











}

}
