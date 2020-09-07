/*
 * main.c

 *
 *  Created on: Sep 25, 2019
 *      Author: Mohamed_Ebead
 */

#include <avr/interrupt.h>
#include <util/delay.h>
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "LCD_int.h"
#include "Timer0_int.h"
#include "Timer1_int.h"
#include "EXT_INT.h"
#include "ADC_int.h"


u16 u16_Freq = 0 ;
u16 u16_Duty = 0 ;

void main(void) {

	u8 F[11] = "Frequency=" ;
	u8 D[11] = "DutyCycle=" ;


	/*****************************************************************/

	// SET  OCO >> PORTB , PIN 3 OUT_PUT
	DIO_SetPinDirection (PORTB_DIO , PIN3 , OUTPUT );

 	// External Interrupt INT0 >> PORTD , PIN 2
	DIO_SetPinDirection (PORTD_DIO , PIN2 , INPUT );
	DIO_SetPinValue (PORTD_DIO , PIN2 , HIGH );

	// ADC >> A0
	DIO_SetPinDirection (PORTA_DIO , PIN0 , INPUT );
	DIO_SetPinValue (PORTA_DIO , PIN0 , HIGH );

	/****************************************************************/

	/******************  Preipherals Initialization *****************/

 	LCD_vidInitialize();

	ADC_Init () ;

	Timer0_Initialize();

	Timer1_Initialize();

	EXT_INT_Initialize();

	/***************************************************************/



	while(1){

		//OCR0_REG =  ADC_Read (0); ;

		vid_EXTINT_GetIcu(& u16_Freq ,& u16_Duty) ;

		 Gotoxy (1,1) ;
		 LCD_vidWriteString (F,11) ;
		 Gotoxy (12,1) ;
		LCDWriteInteger( u16_Freq,4) ;

		 Gotoxy (1,2) ;
	     LCD_vidWriteString (D,11) ;
	     Gotoxy (12,2) ;
	     LCDWriteInteger( u16_Duty,4) ;


		_delay_ms(1000);
	}

}
