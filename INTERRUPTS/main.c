/*
 *      main.c
 *
 *  	Created on: Sep 24, 2019
 *      Author: Mohamed_Ebead
 */

#include<avr/interrupt.h>

#include<util/delay.h>
#include "STD_Types.h"
#include"BIT_MATH.h"

#include "INTERRUPT_private.h"




/*************  INTERRUPT SERVICE ROUTINE   ***************/
/******************  INTERRUPT BODY   *********************/

ISR(INT2_vect){

static u8 flag = 0;

if (flag==0){

			PORTA= 0xAA;
			flag=1;
}
else{
			PORTA= 0x55;
			flag=0;
}

}

/**********************************************************/

void main (void){

/****************  PORT CONFIGURATION  ********************/
	// OUTPUT : PORTA
	DDRA=0xff;

	// INT0 PIN PB2
	DDRB=0x00 ;
	PORTB=0xff ;

/***********************************************************/

/***************  REGISTERS CONFIGURATION  *****************/

	MCUCR_REG = 0b00000011 ;		// Rising edge request an interrupt
	GICR_REG  = 0b00100000 ;		// INT2 is activated
	SREG_REG  = 0b10000000 ;		// Global INTERRUPT Enable

/***********************************************************/


	while(1){

		PORTA= 0xff;
		_delay_ms(500);

		PORTA= 0x00;
		_delay_ms(500);

	}



}
