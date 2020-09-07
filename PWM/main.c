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

#include "ADC_int.h"
#include "ADC_private.h"
#include "Timer_int.h"
#include "TIMER_Private.h"



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

/*
ISR(TIMER1_COMPA_vect)
{
	static u8 flag = 0 ;

	if (flag == 0) {
		SET_BIT(PORTB,0);
		OCR1A_REG =1000 ;
		flag = 1 ;
	}
	else if(flag==1){
		CLR_BIT(PORTB,0);
		OCR1A_REG =19600  ;
		flag = 0 ;
	}
	else{

	}

}
*/

	void main (void){

		u32 u32ADCValue ;
		u32 u32Angle ;

		ADC_Init () ;

		// OUT TO SERVO
		DDRB=0x01;

		// INPUT ADC
		DDRA=0X00;
	//	PORTA=0x01;

		// SET  OC1A ( PORTD PIN 5 ) output
		// DDRD=0b00100000 ;


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

		     u32ADCValue = ADC_Read (0) ;
			 u32Angle = ( (u32)( ( (u32)u32ADCValue ) * 1000UL ) / 255UL ) + 1000UL  ;
			 u32OnTime =u32Angle ;

			_delay_ms(100) ;

		        }
	}




