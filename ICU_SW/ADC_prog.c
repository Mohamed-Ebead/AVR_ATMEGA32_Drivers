/*
 * ADC_prog.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Mohamed_Ebead
 */


#include "STD_Types.h"
#include"BIT_MATH.h"

#include "DIO_int.h"
#include "ADC_int.h"
#include "ADC_private.h"


void ADC_Init (void){

	DIO_SetPinDirection (PORTA_DIO, PIN0, INPUT);
	DIO_SetPinValue (PORTA_DIO , PIN0 , HIGH );

	// ADC Enable
	// Prescalar I/P CLK   / 8
	ADCSRA= 0b10000011 ;

	// Referance Voltage as AVCC with external capacitor
	// ADC Data Right Adjustment
	// ADC 0 sellected

	ADMUX = 0b01000000 ;

}


/*********************************************************/

u8 ADC_Read (u8 channel) {

	// ADC Channel Selection

		channel &= 0x07;  // channel from 0 : 7  ,& to neglect any bit more than 7
		ADMUX &= 0xE0;   // to save higher 3 bits as they are and set the rest to 0
		ADMUX |= channel;


	// Start Single Convertion
		SET_BIT(ADCSRA,ADSC)  ;


	//wait for the conversion (ADIF bit is set when conversion is done )
		while(!GET_BIT(ADCSRA,4));


		return ADCL;

}

/***********************************************************/
