/*
 * main.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Mohamed_Ebead
 */

#include "STD_Types.h"
#include"BIT_MATH.h"

#include "DIO_int.h"

#include"STP_int.h"




void main(void){







	 DIO_SetPortDirection (PORTB,0xff);



/*
       // CONNECT transistor base at B0
         DIO_SetPinDirection (PORTB, PIN0, HIGH);

         // SET transistor base to HIGH
         DIO_SetPinValue(PORTB , PIN0, HIGH);

  		_delay_ms(1000);

  		 // SET transistor base to LOW
  		DIO_SetPinValue(PORTB , PIN0, LOW);
  		_delay_ms(1000);
  		*/

//H-BRIDGE  : MOTOR in two directions
/*
	DIO_SetPinDirection (PORTB, PIN0, HIGH);
	DIO_SetPinDirection (PORTB, PIN1, HIGH);
	DIO_SetPinDirection (PORTB, PIN2, HIGH);
	DIO_SetPinDirection (PORTB, PIN3, HIGH);

	       	DIO_SetPinValue(PORTB , PIN0, LOW);
	       	DIO_SetPinValue(PORTB , PIN3, LOW);
	        DIO_SetPinValue(PORTB , PIN1, HIGH);
	        DIO_SetPinValue(PORTB , PIN2, HIGH);

 		_delay_ms(5000);

 		   DIO_SetPinValue(PORTB, PIN0, LOW);
           DIO_SetPinValue(PORTB, PIN3, LOW);
 		   DIO_SetPinValue(PORTB, PIN1, LOW);
 		   DIO_SetPinValue(PORTB, PIN2, LOW);

 		 		_delay_ms(1000);

 	       DIO_SetPinValue(PORTB, PIN1, LOW);
 		   DIO_SetPinValue(PORTB, PIN2, LOW);
 		   DIO_SetPinValue(PORTB, PIN0, HIGH);
 		   DIO_SetPinValue(PORTB, PIN3, HIGH);

 	 		_delay_ms(5000);

 	 	   DIO_SetPinValue(PORTB, PIN0, LOW);
 	 	   DIO_SetPinValue(PORTB, PIN3, LOW);
 	 	   DIO_SetPinValue(PORTB, PIN1, LOW);
 	 	   DIO_SetPinValue(PORTB, PIN2, LOW);
*/

//OPTOCOUPLER

	/* CONNECT OPTOCOUPLER anode at B0


	         DIO_SetPinDirection (PORTB, PIN0, HIGH);

	    	 DIO_SetPinValue(PORTB , PIN0, HIGH);
*/

	//RELAY

	// DIO_SetPinDirection (PORTB, PIN2, HIGH);
	// DIO_SetPinDirection (PORTB, PIN3, HIGH);

	// stepper motor


	while(1)

	{

		vid_Stepper() ;


/*
			  DIO_SetPinValue(PORTB , PIN0, HIGH);
			  DIO_SetPinValue(PORTB , PIN1, HIGH);
			  _delay_ms(2500);



			  DIO_SetPinValue(PORTB , PIN1,LOW);
			  	 _delay_ms(100);

			  	 DIO_SetPinValue(PORTB , PIN0, LOW);
			  	DIO_SetPinValue(PORTB , PIN1, LOW);
			    _delay_ms(2500);*/


/*
		 DIO_SetPinValue(PORTB , PIN0, HIGH);
        // SET transistor base to HIGH

	  	_delay_ms(5000);

	  		 // SET transistor base to LOW
	  		DIO_SetPinValue(PORTB , PIN0, LOW);
			_delay_ms(5000);*/

	}

}
