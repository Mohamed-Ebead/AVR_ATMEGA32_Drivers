/*
 * KEYPAD_Prog.c
 *
 *  Created on: Aug 30, 2019
 *      Author: Mohamed_Ebead
 */
#include "STD_Types.h"


#include "DIO_int.h"


#include<util/delay.h>
#include "KEYPAD_int.h"

u8 KPD_u8GetPressedKey(void){


	u8 NB =0 	;  //  returned pressed button number
	u8 iteration1 , iteration2 ;


	const u8 arr[4][4]= {{1,5,9,13},{2,6,10,14},{3,7,11,15},{4,8,12,16}};


//  input Rows loop
	for(iteration1 = 0 ;iteration1 <4 ;iteration1 ++){

		DIO_SetPinValue(PORTD , iteration1 , LOW);

// Output coulomns loop
		for(iteration2 =4 ;iteration2 <8 ;iteration2 ++){

			if(!(DIO_GetPinValue(PORTD, iteration2 ))){

				NB=arr[iteration1][iteration2 - 4 ] ;

				 while (!(DIO_GetPinValue(PORTD, iteration2))) ;
				 _delay_ms(20);
			}
			else {

			}

		}

		DIO_SetPinValue(PORTD , iteration1 , HIGH);

	}

	return NB ;

}
