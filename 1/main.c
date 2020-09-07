/*
 * main.c
 *
 *  Created on: Aug 16, 2019
 *      Author: Mohamed_Ebead
 */


#include<util/delay.h>
#include"STD_types.h"
#include"BIT_MATH.h"

#include "DIO_int.h"
#include "DIO_reg.h"




	/* //making pin A0 as an output

	DDRA=0b00100000 ;

	//making pin A0 as output high
	PORTA=0xff;

	while(1){


	}



	DDRA=0x01 ;

	// low FF High D9

	while(1){



			PORTA=0x01;
			_delay_ms (1000) ;

			PORTA=0x00;
			_delay_ms (1000) ;

	}*/

/*	DDRA=0xff;


	while (1){

	for (i=0;i<8;i++){
	PORTA=(1<<i);
	_delay_ms (1000) ;


	}

	for (i=0;i<8;i++){
		PORTA=(128>>i);
		_delay_ms (1000) ;


		}



	}
*/

/*
void main (void)  {

	u8 i ;
	u8 arr[10]= {0b00111111,0b0000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};

	DDRA=0xff  ;



while(1){

	for(i=0;i<10;i++){

	PORTA=arr[i];

	_delay_ms (1000) ;

}
}

}*/
/*
 *
void main(void){

	// u8 Local_u8SwitchStatus   cannel convension

	u8 x,y,z ;

	DDRC=0xff ;
	DDRA=0x00  ;

	PINA=1<<1 ;


	while (1)	{


	     	=SET_BIT(x,BITNO) ;

		    = GET_BIT(PINA,0x00) ;

	    	= TOG_BIT(PINA,BITNO) ;


	}


 * main.c
 *
 *  Created on: Aug 18, 2019
 *      Author: Mohamed_Ebead


#include <avr/io.h>
#include<util/delay.h>
#include"STD_types.h"
#include"BIT_MATH.h"



void main(void){

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



	u8 i ;

	DDRA=0xFF ;
	DDRB=0XFF ;

	while (1){


			PORTB=0b00100000;

			for(i=9;i>0;i--){


				PORTA=arr[i];

				_delay_ms (1000) ;

			}

			PORTA=0b00111111 ;
			_delay_ms (1000) ;


			PORTB=0b01000000;


			for(i=2;i>0;i--){


			PORTA=arr[i];

			_delay_ms (1000) ;

						}

			PORTA=0b00111111;
			_delay_ms (1000) ;




			PORTB=0b10000000;

			for(i=9;i>0;i--){

			PORTA=arr[i];

			_delay_ms (1000) ;

						}
			PORTA=0X00;
			_delay_ms (1000) ;


	}







}

 */


void main(void){
	 u8 i,j ;


	 	 //Set PORTA as INPUT from switches
	 	 	DIO_SetPortDirection (PORTA, 0X00);

	 	// CONNECT PORTA TO PULL UP RESISTORS
	 	 	DIO_SetPortValue  (PORTA, 0Xff);

	 	//Set PORTC as output to leds
	 	  DIO_SetPortDirection (PORTC, 0XFF);

	 	//Set PORTD as extra output to leds
	 	//used in specific tasks
	 	 DIO_SetPortDirection (PORTD, 0XFF);

	while(1){



if (!(DIO_GetPinValue(PORTA, PIN0))){
			DIO_SetPortValue     (PORTC, 0xff);
			_delay_ms(500);
			DIO_SetPortValue     (PORTC, 0x00);
			_delay_ms(500);
		}

else if (!(DIO_GetPinValue(PORTA, PIN1))){
			// Shift LEDs Left
					for(i=0; i<8;i++)
					{
						DIO_SetPortValue     (PORTC, 1 << i);
						_delay_ms(250);
					}
				}

else if (!(DIO_GetPinValue(PORTA, PIN2))){
			// Shift LEDs Left
							for(i=0; i<8;i++)
							{
								DIO_SetPortValue     (PORTC, 0x80>> i);
								_delay_ms(250);
														}
							}

else{

			DIO_SetPortValue     (PORTC, 0xff);

				}

}



}


