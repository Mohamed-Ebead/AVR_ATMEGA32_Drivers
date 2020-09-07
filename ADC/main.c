/*
 * main.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Mohamed_Ebead
 */

#include "STD_Types.h"
#include <util/delay.h>
#include "DIO_int.h"

#include "LCD_int.h"
#include "ADC_int.h"


void main (void) {

	u8 s[9] ="ADC_VAL=";
	u8 x[8] ="TEMP = ";
	u8 m[2] ="C";
	u16 local_u16_Read ;
	u32 volt ;
	u8 arr[5] ;

	/****************  LCD Configuration  *****************/

		     _delay_ms(50);

			  // SET VDD TO D0   5 Volt (D0 >> VDD)
			  DIO_SetPinDirection (PORTD, PIN0, HIGH);

			  //  RS >> D1
			  DIO_SetPinDirection (PORTD, PIN1, HIGH);

			  //  R/W >> D2
			  DIO_SetPinDirection (PORTD, PIN2, HIGH);

			  //  Enable >> D3
			   DIO_SetPinDirection (PORTD, PIN3, HIGH);


			  //SET PORTC AS OUTPUT (PORTC >> DB0...DB7)
			  DIO_SetPortDirection (PORTC, 0XFF);


	/****************  ADC Configuration  *****************/

	DIO_SetPortDirection (PORTA, 0x00);
	DIO_SetPortValue     (PORTA, 0X01);

	/******************************************************/


	ADC_Init ();
	LCD_vidInitialize();



	while (1){


		 local_u16_Read = ADC_Read (0) ;


		volt =(  ( (u32)local_u16_Read *  5000UL)/10UL ) / 1024UL  ;


		 Gotoxy (1,1) ;
		LCD_vidWriteString (s, 9) ;

		Gotoxy (10,1) ;
		LCDWriteInteger( local_u16_Read,4) ;

		 Gotoxy (1,2) ;
		LCD_vidWriteString (x, 8) ;

		Gotoxy (9,2) ;

		LCDWriteInteger( volt,4) ;


		Gotoxy (15,2) ;
		LCD_vidWriteString (m, 2) ;

		LCD_vidWriteCommand (0x02) ;

	}

	}


/*
		local_u16_Read	= ADC_Read (PIN0) ;

	if ( (local_u16_Read > 0) && (local_u16_Read < 300) ){

		// Turn Red LED on

		DIO_SetPinValue(PORTC , PIN0, HIGH );
		DIO_SetPinValue(PORTC , PIN1, LOW );
		DIO_SetPinValue(PORTC , PIN2, LOW );

	}

	else if ( (local_u16_Read > 300) && (local_u16_Read < 700) ) {

		// Turn Yellow LED on

			DIO_SetPinValue(PORTC , PIN0, LOW );
			DIO_SetPinValue(PORTC , PIN1, HIGH );
			DIO_SetPinValue(PORTC , PIN2, LOW );

	}

	else if ( (local_u16_Read > 700) && (local_u16_Read < 1000) ) {

		 // Turn Geen LED on

			DIO_SetPinValue(PORTC , PIN0, LOW );
			DIO_SetPinValue(PORTC , PIN1, LOW );
			DIO_SetPinValue(PORTC , PIN2, HIGH );
			_delay_ms(1000);
	}

		else {

				DIO_SetPinValue(PORTC , PIN0, HIGH );
				DIO_SetPinValue(PORTC , PIN1, HIGH );
				DIO_SetPinValue(PORTC , PIN2, HIGH );

	}

	*/

