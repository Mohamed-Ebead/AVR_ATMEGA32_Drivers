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

	 u8 ch = 'M';
    u8 s[8]= "Mohamed" ;

	     _delay_ms(50);

		// SET VDD TO A0   5 Volt (A0 >> VDD)
		  DIO_SetPinDirection (PORTA, PIN0, HIGH);

		  //  RS >> A1
		  DIO_SetPinDirection (PORTA, PIN1, HIGH);

		  //  R/W >> A2
		  DIO_SetPinDirection (PORTA, PIN2, HIGH);

		  //  Enable >> A3
		   DIO_SetPinDirection (PORTA, PIN3, HIGH);


		  //SET PORTC AS OUTPUT (PORTC >> DB0...DB7)
		  DIO_SetPortDirection (PORTC, 0XFF);


			LCD_vidInitialize();

			// LCD_vidWriteCharacter(ch) ;

		//	 LCD_vidWriteString (&s,8) ;

			// Gotoxy (3,1) ;

		 // LCD_vidWriteExtraChar(1,1) ;



		//	LCD_vidWriteExtraChar (1,1) ;
			// LCD_SinusoidalExtraChar(1,1);
			/*
u8 x = 0 ;
while (1){
	Gotoxy (x,1) ;
	LCD_vidWriteString (&s,8) ;
	_delay_ms(100);
	 LCD_vidWriteCommand (0b00000100);
	 _delay_ms(100);
	 LCD_vidWriteCommand (0b00000001);
	 _delay_ms(100);

	x+=7;


		Gotoxy (x,2) ;
		LCD_vidWriteString (&s,8) ;
		_delay_ms(100);

		LCD_vidWriteCommand (0b00000100);
		_delay_ms(100);
		LCD_vidWriteCommand (0b00000001);
		_delay_ms(100);
		x+=7;


}
}*/

while(1){
/*
for(u8 i =1 ; i<=16;i++){

LCD_vidWriteExtraCharacter (i,1);
_delay_ms(100);
LCD_vidWriteCommand (0b00000001);
LCD_vidWriteCommand (0b00000100);
i++;

LCD_vidWriteExtraCharacter (i,2);
_delay_ms(100);
LCD_vidWriteCommand (0b00000001);
LCD_vidWriteCommand (0b00000100);
}
}


LCD_vidWriteCommand (0b00000010);
*/
/*
	LCD_SinOneExtraChar(1,1);
		LCD_vidWriteCommand (0b00000011);*/

	/* LCD_SinExtraChar1 (1,1);
	LCD_vidWriteCommand (0b00000011);*/
/*
	LCD_SinExtraChar2(1,1);
	LCD_vidWriteCommand (0b00000011);
	//_delay_ms(100);
*/
}
}

/*
for(u8 i =1 ; i<=16;i++){

	LCD_vidWriteExtraCharacter (i,1) ;
	i++;
	_delay_ms(100);

	LCD_vidWriteExtraCharacter (i,2) ;
_delay_ms(100);
i++ ;

}*/

 // LCD_SinExtraChar(1,1) ;
/*
			u8 i = 1 ;
			for(u8 j =1 ;j<4;j++){


					Gotoxy (i,1) ;
					LCD_vidWriteString (&s,8) ;

					_delay_ms(100);
					i+=7 ;

					Gotoxy(i,2);
					LCD_vidWriteString (&s,8) ;
					_delay_ms(100);
					i+=7 ;

					}

	while(1)
	{
		//LCD_vidWriteExtraCharacter (1,1) ;
		for(u8 j =1 ;;j++){
		u8 i = 1 ;

		Gotoxy (i,1) ;
		LCD_vidWriteString (&s,8) ;

		_delay_ms(100);
		i+=7 ;

		Gotoxy(i,2);
		LCD_vidWriteString (&s,8) ;
		_delay_ms(100);

		}
	}*/


