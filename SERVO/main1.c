/*
 * main.c
 *
 *  Created on: Sep 14, 2019
 *      Author: Mohamed_Ebead
 */

#include <avr/interrupt.h>
#include <Util/delay.h>
#include "STD_Types.h"
#include"BIT_MATH.h"
#include "DIO_int.h"

#include "ADC_int.h"
#include "ADC_private.h"
#include "Timer_int.h"
#include "TIMER_Private.h"
#include "LCD_int.h"
#include "ADC_int.h"




ISR(TIMER1_COMPA_vect)
{
	static u8 flag = 0 ;

	if (flag == 0) {
		SET_BIT(PORTB,0);
		OCR1A_REG = u32OnTime ;
		flag = 1 ;

	}
	else if(flag==1){
		CLR_BIT(PORTB,0);
		OCR1A_REG =(u32)20000 - u32OnTime  ;
		flag = 0 ;

	}
	else{

	}

}




	void main (void){

			u8 s[11] ="ADC_VAL = ";
			u8 x[11] ="ON_TIME = ";
			//u8 m[3] ="mV";
			u16 local_u16_Read ;
			u32 volt ;
			u8 arr[5] ;


			u32 u32Angle ;


			/****************  LCD Configuration  *****************/

				     _delay_ms(50);

					  // SET VDD TO D0   5 Volt (D0 >> VDD)
					  DIO_SetPinDirection (PORTD_DIO, PIN0, HIGH);

					  //  RS >> D1
					  DIO_SetPinDirection (PORTD_DIO, PIN1, HIGH);

					  //  R/W >> D2
					  DIO_SetPinDirection (PORTD_DIO, PIN2, HIGH);

					  //  Enable >> D3
					   DIO_SetPinDirection (PORTD_DIO, PIN3, HIGH);


					  //SET PORTC AS OUTPUT (PORTC >> DB0...DB7)
					  DIO_SetPortDirection (PORTC_DIO, 0XFF);


			/****************  ADC Configuration  *****************/

			DIO_SetPortDirection (PORTA_DIO, 0x00);
			DIO_SetPortValue     (PORTA_DIO, 0X01);

			/******************************************************/


			ADC_Init ();
			LCD_vidInitialize();


		/******************************************/



		// OUT TO SERVO
		DDRB=0x01;


	/* 16-bit timer
	 * Normal port operation , OC1A disconnected
	 */
		TCCR1A_REG = 0b10000000 ;

		//OCR1A_REG=1500;

		/* CTC Mode
		 * ClK input / 8
		 */
		TCCR1B_REG = 0b00001010 ;

		// ENABLE INTERRUPT
		SET_BIT(TIMSK_REG,4);

		// ENABLE GLOBAL INTERRUPT
		SET_BIT(SREG_REG,7);

		while(1){

			 local_u16_Read = ADC_Read (0) ;

			 u32Angle = ( (u32)( ( (u32)local_u16_Read ) * 1000UL ) / 255UL ) + 1000UL  ;
			 u32OnTime =u32Angle ;


			 Gotoxy (1,1) ;
			LCD_vidWriteString (s, 11) ;

			 Gotoxy (10,1) ;
			LCDWriteInteger(local_u16_Read,4) ;

			 Gotoxy (1,2) ;
			LCD_vidWriteString (x,11) ;

			Gotoxy (10,2) ;

			LCDWriteInteger(u32OnTime,4) ;


			LCD_vidWriteCommand (0x02) ;


			_delay_ms(100) ;

		        }
	}




