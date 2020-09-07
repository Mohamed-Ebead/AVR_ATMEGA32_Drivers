
/*
 * main.c
 *
 *  Created on: Aug 18, 2019
 *      Author: Mohamed_Ebead
 */


#include<util/delay.h>
#include"STD_types.h"
#include"BIT_MATH.h"

#include "DIO_int.h"
#include "DIO_reg.h"


void main(void){

	u8 i ; // iteration

	//  7-segment array

	u8 arr[10]= {0b00111111,
				 0b00000110,
				 0b01011011,
				 0b01001111,
				 0b01100110,
				 0b01101101,
				 0b01111101,
				 0b00000111,
				 0b01111111,
				 0b01101111};


	// set PORTA as output to 7-segment 1
	DIO_SetPortDirection (PORTA, 0XFF);

	// set PORTD as output to 7-segment 2
	DIO_SetPortDirection (PORTD, 0XFF);

	// set PORTC as output to Leds
	DIO_SetPortDirection (PORTC, 0XFF);


	while (1){

		//turn on green led
		DIO_SetPortValue     (PORTC, 0b00000100);

		// set left  segment to 1
		DIO_SetPortValue     (PORTD, 0b00000110);

		// set right  segment to 0
		DIO_SetPortValue     (PORTA, 0b00111111);
		_delay_ms (1000) ;

		// set left  segment to 0
				DIO_SetPortValue     (PORTD, 0b00111111);


		// count down from 9 >> 1 on right segment
			for(i=9;i>0;i--){


				DIO_SetPortValue     (PORTA, arr[i]);

				_delay_ms (1000) ;

			}


			// turn on yellow led
			DIO_SetPortValue     (PORTC, 0b00000010);

			// set left  segment to 0
			DIO_SetPortValue  (PORTD, 0b00111111);

			// count down from 3 >> 1 on right segment
			for(i=3;i>0;i--){

				DIO_SetPortValue     (PORTA, arr[i]);

			_delay_ms (1000) ;

						}


			//turn on red led
					DIO_SetPortValue     (PORTC, 0b00000001);

					// set left  segment to 1
					DIO_SetPortValue     (PORTD, 0b00000110);
					// set right  segment to 0
					DIO_SetPortValue     (PORTA, 0b00111111);
					_delay_ms (1000) ;

					// set left  segment to 0
								DIO_SetPortValue  (PORTD, 0b00111111);


					// count down from 9 >> 1 on right segment
						for(i=9;i>0;i--){


							DIO_SetPortValue     (PORTA, arr[i]);

							_delay_ms (1000) ;

						}



	}







}
