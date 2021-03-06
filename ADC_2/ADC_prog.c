/*
 * ADC_prog.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Mohamed_Ebead
 */


#include "STD_Types.h"
#include"BIT_MATH.h"


#include "ADC_int.h"
#include "ADC_private.h"


void ADC_Init (void){

	// ADC Enable
	SET_BIT(ADCSRA,ADEN)  ;


	// Prescaler Configuration
	/*These bits determine the division factor between
	 * the XTAL frequency and the input clock to the ADC.*/
	// if clock is fewer , consumed power is fewer

	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);




	// Referance Voltage as AVCC with external capacitor

	CLR_BIT(ADMUX,REFS1)  ;
	SET_BIT(ADMUX,REFS0)  ;


	// ADC Data Right Adjustment

	CLR_BIT(ADMUX,ADLAR)  ;

}


/*********************************************************/

u16 ADC_Read (u8 channel) {


	// ADC Channel Selection

		channel &= 0x07;  // channel from 0 : 7  ,& to neglect any bit more than 7
		ADMUX &= 0xE0;
		ADMUX |= channel;


	// Start Single Convertion

	//	ADCSRA|=(1<<ADSC);
		SET_BIT(ADCSRA,ADSC)  ;


	//wait for the conversion
		while(!(ADCSRA & (1<<4)));


	//ADC Interrupt Flag Clear
		/*This bit is set when an ADC conversion completes
		 *  and the Data Registers are updated*/

		SET_BIT(ADCSRA,ADIF);



		return ADC;

}

/***********************************************************/
