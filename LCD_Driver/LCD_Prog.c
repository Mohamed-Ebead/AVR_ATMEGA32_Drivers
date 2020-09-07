/*
 * LCD_Prog.c
 *
 *  Created on: Aug 24, 2019
 *      Author: Mohamed_Ebead
 */


#include "STD_Types.h"
#include<util/delay.h>
#include "DIO_int.h"

#include "LCD_int.h"
#include "LCD_Private.h"

/****************************************************************/
void LCD_vidWriteCommand (u8 u8CmdCpy) {
	  // Set RS = 0
	  DIO_SetPinValue(PORTA , PIN1, LOW);

	  // Set R/W = 0
	  DIO_SetPinValue(PORTA , PIN2, LOW);

	  // Set EN = 0
	  DIO_SetPinValue(PORTA , PIN3, HIGH);

	  DIO_SetPortValue (PORTC,u8CmdCpy);

	  // set EN to 1 after settting command
	  // pulse
	  DIO_SetPinValue(PORTA , PIN3, LOW);
	  _delay_ms(10);
	  DIO_SetPinValue(PORTA , PIN3, HIGH);

  }


/****************************************************************/


void LCD_vidInitialize(void){


	 // set VDD @ A0 to 5 volt
	  DIO_SetPinValue(PORTA , PIN0, HIGH);

	  _delay_ms(50);

	  //Return Home
	  	// LCD_vidWriteCommand (0b00000010);//0X02
	  	// _delay_ms (10000);

	//FUNCTION SET
	  LCD_vidWriteCommand (0b00111000);//0X38  // N=0 1 line 0b00110000
	  _delay_ms (10);


	  // DISPLAY ON/OFF CONTROL
	  LCD_vidWriteCommand (0b00001111);
	//  LCD_vidWriteCommand (0b00001100); //0X0C
	  _delay_ms (10);

	  // DISPLAY CLEAR
	 	  LCD_vidWriteCommand (0b00000001);
	 	  _delay_ms (10);


	  // Entry mode set
	  LCD_vidWriteCommand (0b00000110);//0X06
	  _delay_ms (20);

}



/****************************************************************/

void LCD_vidWriteCharacter(u8 u8DataCpy){
	 // Set RS to HIGH
		DIO_SetPinValue(PORTA, 1 , HIGH);

		// Set R/W to LOW
		DIO_SetPinValue(PORTA, 2 , LOW);

		// Set E to HIGH
		DIO_SetPinValue(PORTA, 3 , HIGH);

		// Load Command on Data bus
		DIO_SetPortValue(PORTC, u8DataCpy);

		// Set E to LOW
		DIO_SetPinValue(PORTA, 3, LOW);

		// Wait for E to settle
		_delay_ms(10);

		// Set E to HIGH
		DIO_SetPinValue(PORTA, 2, HIGH);

		// Delay to let the LCD Display the character
		_delay_ms(10);

}


/****************************************************************/

void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index){


	//	/* Local loop index */
	//	u8 u8Index = 0;
		u8 iteration=0;
	//	while (pu8StringCpy[u8Index] != '\0')
		for (iteration=0; ((iteration<u8Index)&&(pu8StringCpy[iteration] != '\0')) ; iteration++)
		{

			/* Write Character on LCD */
			LCD_vidWriteCharacter(pu8StringCpy[iteration]);

	//		/* Increment local loop index */
	//		u8Index++;

			/* Delay to let the LCD show the character */
			_delay_ms(10);
		}


}

/****************************************************************/

void Gotoxy (u8 X,u8 Y){
	if (X>0 && X<=16)
		{
		    switch(Y)
		    {
			    case 1:
			    	LCD_vidWriteCommand(X+127);
			    break;
			    case 2:
			    	LCD_vidWriteCommand(X+191);
			    break;
			    default:
			    break;
		    }
		}

}

/****************************************************************/

void LCD_vidWriteExtraChar (u8 X,u8 Y){

	u8 iteration1,iteration2;

	    //DDRAM-->CGRAM
		LCD_vidWriteCommand(0x40);

		for(iteration1=0 ; iteration1<64 ; iteration1++)
		{
			LCD_vidWriteCharacter(ExtraCharacter[iteration1]);
		}

		//CGRAM-->DDRAM
		LCD_vidWriteCommand(0x80);
		Gotoxy(X,Y);


	//    Gotoxy(X+2,Y-1);
	//	LCD_vidWriteCharacter(0); // display first char

	//	Gotoxy(X,Y+1);
	//First # characterS which saved at CGRAM
	//for (iteration2=1; iteration2<2; iteration2++)
	//{
		// Write bytes of DDRAM
		LCD_vidWriteCharacter(0);

	//_delay_ms(10);
	//}


}

/****************************************************************/
void LCD_Sinusoidalstring(u8 u8sincpy,u8 u8Index)
{

	 s8 i , j ;
for(j=1 ; j<16 ; j++)
	{
		for(i=1 ; i<3 ;i++)
		{
			Gotoxy (i,j);
			_delay_ms(5);
			LCD_vidWriteString (u8sincpy ,u8Index );
	    	_delay_ms(1000);
	    	LCD_vidWriteCommand(0x01);
	    	_delay_ms(10);
	    	if(i==1)
	    	{
	    	j++ ;

	    	}
	    	else
	    	{

	    	}
		}
		}

for(j=16 ; j>=0 ; j--)
	{
		for(i=2 ; i>0 ;i--)
		{
			Gotoxy (i,j);
			_delay_ms(5);
			LCD_vidWriteString (u8sincpy,u8Index);
	    	_delay_ms(1000);
	    	LCD_vidWriteCommand(0x01);
	    	_delay_ms(10);
	    	if(i==2)
	    	{
	    	j-- ;

	    	}
	    	else
	    	{

	    	}
		}
	}
}

/****************************************************************/

void LCD_SinusoidalChar(u8 u8sincharcpy)
{
s8 i , j ;
for(j=1 ; j<16 ; j++)
	{
		for(i=1 ; i<3 ;i++)
		{
			Gotoxy (i,j);
			_delay_ms(5);
			LCD_vidWriteCharacter(u8sincharcpy);
	    	_delay_ms(1000);
	    	LCD_vidWriteCommand(0x01);
	    	_delay_ms(10);

	    	if(i==1)
	    	{
				j++ ;

	    	}
	    	else
	    	{

	    	}
		}
	}

for(j=16 ; j>=0 ; j--)
	{
		for(i=2 ; i>0 ;i--)
		{
			Gotoxy (i,j);
			_delay_ms(5);
			LCD_vidWriteCharacter(u8sincharcpy);
	    	_delay_ms(1000);
	    	LCD_vidWriteCommand(0x01);
	    	_delay_ms(10);
	    	if(i==2)
	      	{
	    		j-- ;

	      	}
	      	else
	      	{

	      	}
		}
	}
}

/*******************************************************/
/*
void LCD_SinusoidalExtraChar(void)
{
s8 i , j  ;
for(j=1 ; j<16 ; j++)
	{
		for(i=1 ; i<3 ;i++)
		{
			Gotoxy (i,j);
			_delay_ms(5);
			LCD_vidWriteExtraChar (i,j);
	    	_delay_ms(1000);
	    	LCD_vidWriteCommand(0x01);
	    	_delay_ms(10);
	    	if(i==1)
	    	{
	    	j++ ;

	    	}
	    	else
	    	{

	    	}
		}
	}

for(j=16 ; j>0 ; j--)
	{
		for(i=2 ; i>0 ;i--)
		{
			Gotoxy (i,j);
			_delay_ms(5);
			LCD_vidWriteExtraChar (i,j);
	    	_delay_ms(1000);
	    	LCD_vidWriteCommand(0x01);
	    	_delay_ms(10);
	    	if(i==2)
	    	{
	    	j-- ;

	    	}
	    	else
	    	{

	    	}
		}
	}
}
*/
