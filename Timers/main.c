/*
 * main.c
 *
 *  Created on: Sep 14, 2019
 *      Author: Mohamed_Ebead
 */



#include<avr/interrupt.h>


#include "STD_Types.h"
#include"BIT_MATH.h"
#include "Timer_int.h"


// NORMAL MODE
/*
ISR(TIMER0_OVF_vect)
{
	static  u16 counter = 0 ;
		counter ++ ;

	if (counter == (FullOVF+1)) {
		counter=0 ;

		TCNT0 = PreloadVal ;

		TOG_BIT(PORTA,PIN0);

	}*/

// CTC MODE

ISR(TIMER0_COMP_vect)
{
	static  u16 counter = 0 ;
		counter ++ ;

	if (counter == 5000) {
		counter=0 ;

		TOG_BIT(PORTA,PIN0);

	}

}



	void main (void){


		DDRA=0XFF;

		// CTC MODE

		CLR_BIT(TCCR0,WGM00) ;
		SET_BIT (TCCR0,WGM01);


		//Normal port operation , OC0 disconnected

		CLR_BIT(TCCR0,COM00) ;
		CLR_BIT(TCCR0,COM01) ;

		OCR0 = 200 ;

		// clk I/O/8 (From prescaler)
		CLR_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS01);
		CLR_BIT(TCCR0,CS02);


		// ENABLE INTERRUPT
		SET_BIT(TIMSK,OCIE0);

		// ENABLE GLOBAL INTERRUPT
		SET_BIT(SREG,7);

		while(1){



		}

	}







