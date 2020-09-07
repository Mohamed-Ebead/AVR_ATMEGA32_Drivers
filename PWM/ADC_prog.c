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
	SET_BIT(ADCSRA_REG,ADEN)  ;


	// Prescaler Configuration
	/*These bits determine the division factor between
	 * the XTAL frequency and the input clock to the ADC.*/
	// if clock is fewer , consumed power is fewer

	SET_BIT(ADCSRA_REG,ADPS0);
	SET_BIT(ADCSRA_REG,ADPS1);
	SET_BIT(ADCSRA_REG,ADPS2);




	// Referance Voltage as AVCC with external capacitor

	CLR_BIT(ADMUX_REG,REFS1)  ;
	SET_BIT(ADMUX_REG,REFS0)  ;


	// ADC Data Right Adjustment

	CLR_BIT(ADMUX_REG,ADLAR)  ;

}


/*********************************************************/

u16 ADC_Read (u8 channel) {


	// ADC Channel Selection

		channel &= 0x07;     // channel from 0 : 7  ,& to neglect any bit more than 7
		ADMUX_REG &= 0xE0;   // to save higher 3 bits as they are and set the rest to 0
		ADMUX_REG |= channel;


	// Start Single Convertion

	//	ADCSRA_REG |=(1<<ADSC);
		SET_BIT(ADCSRA_REG,ADSC)  ;


	//wait for the conversion
		while(!(ADCSRA_REG & (1<<4)));


	//ADC Interrupt Flag Clear
		/*This bit is set when an ADC conversion completes
		 *  and the Data Registers are updated*/

		SET_BIT(ADCSRA_REG,ADIF);

		return ADC_REG;

}

/***********************************************************/
/*
 u8 ADC_GetAdcBlocking (u8 copy_channelNB , u8 * copy_channelNB) {






 }*/
