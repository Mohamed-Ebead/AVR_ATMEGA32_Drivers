/*
 * STP_Prog.c
 *
 *  Created on: Sep 7, 2019
 *      Author: Mohamed_Ebead
 */

#include "STD_Types.h"
#include<util/delay.h>
#include "DIO_int.h"

#define PORT PORTB


void vid_Stepper(void) {






	 DIO_SetPinValue(PORT, PIN0, HIGH);
	 DIO_SetPinValue(PORT, PIN1, LOW);
	 DIO_SetPinValue(PORT, PIN2, LOW);
	 DIO_SetPinValue(PORT, PIN3, LOW);



	 DIO_SetPinValue(PORT, PIN0, LOW);
	 DIO_SetPinValue(PORT, PIN1, HIGH);
	 DIO_SetPinValue(PORT, PIN2,LOW);
	 DIO_SetPinValue(PORT, PIN3,LOW );

		_delay_ms(20);

	  DIO_SetPinValue(PORT, PIN0, LOW);
	  DIO_SetPinValue(PORT, PIN1, LOW);
	  DIO_SetPinValue(PORT, PIN2,HIGH);
	  DIO_SetPinValue(PORT, PIN3,LOW );

			_delay_ms(20);

	 DIO_SetPinValue(PORT, PIN0, LOW);
	 DIO_SetPinValue(PORT, PIN1, LOW);
	 DIO_SetPinValue(PORT, PIN2, LOW);
	 DIO_SetPinValue(PORT, PIN3, HIGH);

				_delay_ms(20);











}
