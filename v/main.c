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



void main(void){

  _delay_ms(30000);

  // SET VDD TO 5 Volt (A0 >> VDD)
  DIO_SetPinDirection (PORTA, PIN0, HIGH);
  DIO_SetPinValue(PORTA , PIN0, HIGH);

  //  RS >> PORTA , PIN1
  DIO_SetPinDirection (PORTA, PIN1, HIGH);

  //  R/W >> PORTA , PIN2

  DIO_SetPinDirection (PORTA, PIN2, HIGH);

  //  enable pin >> PORTA , PIN3

   DIO_SetPinDirection (PORTA, PIN3, HIGH);


  //SET PORTB AS OUTPUT (PORTB >> DB0..DB7)
  DIO_SetPortDirection (PORTB, HIGH);


  Initialize_LCD();


	while(1)
	{


	}

}
