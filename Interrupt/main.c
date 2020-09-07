/*
 * main.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Mohamed_Ebead
 */





#include<avr/interrupt.h>
#include<avr/io.h>

#include "STD_Types.h"
#include"BIT_MATH.h"
#include <util/delay.h>


ISR(INT0_vect)
{
	// PORTA ISR 5 , 10

	static  u8 flag = 0 ;
	if (flag == 0) {

		PORTA = 5 ;
		flag= 1 ;

	}

	else {
		PORTA=10;
		flag=0;

	}


}

void main(void){

// PORTA & PORTB OUTPUT
DDRA= 0xff ;
DDRB= 0xff ;

PORTA= 00;
PORTB = 00;

// PULL UP RES
// INT0 at D2
CLR_BIT(DDRD,2) ;
SET_BIT(PORTD,2) ;


// The falling edge of INT0 generates an interrupt req
CLR_BIT(MCUCR,ISC00) ;
SET_BIT(MCUCR,ISC01);



SET_BIT(GICR,INT0);

SET_BIT(GIFR,INTF0);

SET_BIT(SREG,7);


while(1) {


	PORTB = 0XFF;
	_delay_ms(1000);
	PORTB = 0x00;
	_delay_ms(1000);


}


}


