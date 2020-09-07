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
	u8 i,j ;


	 //Set PORTA as INPUT from switches
	 	DIO_SetPortDirection (PORTA, 0X00);

	 	// CONNECT PORTA TO PULL UP RESISTORS
	 	DIO_SetPortValue     (PORTA, 0XFF);

	//Set PORTC as output to leds
	 	 DIO_SetPortDirection (PORTC, 0XFF);

	 	//Set PORTD as extra output to leds
	 	//used in specific tasks
	 	 DIO_SetPortDirection (PORTD, 0XFF);

	while (1){


		// Flashing every 500 ms
		if (!(DIO_GetPinValue(PORTA,PIN0)))
		{
			DIO_SetPortValue (PORTC, 0xff);
			_delay_ms(500);
			DIO_SetPortValue     (PORTC, 0x00);
			_delay_ms(500);
		}


		//Shifting Left every 250 ms
		else if (!(DIO_GetPinValue(PORTA, PIN1))){
			// Shift LEDs Left
					for(i=0; i<8;i++)
					{
						DIO_SetPortValue     (PORTC, 1 << i);
						_delay_ms(250);
					}
				}

		//Shifting Right every 250 ms
		else if (!(DIO_GetPinValue(PORTA, pin2))){
							// Shift LEDs Left
				for(i=0; i<8;i++)
				{
					DIO_SetPortValue     (PORTC, 0x80>> i);
					_delay_ms(250);
											}
				}


		//2-LEDs Converging every 300 ms
		else if (!DIO_GetPinValue(PORTA, PIN3))){

			for(i=0; i<4;i++){

				DIO_SetPortValue     (PORTC, 1 << i);
				DIO_SetPortValue     (PORTD, 0x80>> i);
					_delay_ms(300);

									}
		}

		//2-LEDs Diverging every 300 ms
		else if (!(DIO_GetPinValue(PORTA,PIN4))){

				for(i=0; i<4;i++){
					DIO_SetPortValue     (PORTC, 0b00010000 << i);
					DIO_SetPortValue     (PORTD, 0b00001000>> i);

						_delay_ms(300);

										}
			}

		//Ping Pong effect every 250 ms
		else if (!(DIO_GetPinValue(PORTA,PIN5))){

					for(i=0; i<8;i++){
					DIO_SetPortValue     (PORTC, 1<< i);
							_delay_ms(250);
				}

					for(j=0; j<8;j++){
						DIO_SetPortValue     (PORTC, 0x80 >> j);
								_delay_ms(250);
					}



				}

// Incrementing (Snake effect) every 300 ms
		else if (!(DIO_GetPinValue(PORTA,PIN6))){
				for(i=0; i<8;i++)
				DIO_SetPortValue     (PORTC, 0xFF);
				DIO_SetPinValue(PORTC , i, LOW);{
				_delay_ms(300);

				}
		}



		//2-LEDs Converging/Diverging every 300 ms
		else if (!(DIO_GetPinValue(PORTA,PIN7))){

				for(i=0; i<4;i++){
					DIO_SetPortValue     (PORTC, 0b00010000 << i);
					DIO_SetPortValue     (PORTD, 0b00001000>> i);

						_delay_ms(300);

				}

					for(i=0; i<4;i++){
						DIO_SetPortValue     (PORTC, 0b10000000 >>i);
						DIO_SetPortValue     (PORTD, 0b00000001<< i);

							_delay_ms(300);

												}


				}


		else{

			DIO_SetPortValue     (PORTC, 0xff);

				}

	}


}
