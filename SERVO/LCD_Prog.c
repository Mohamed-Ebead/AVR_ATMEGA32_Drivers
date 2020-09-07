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


/****************************************************************/
void LCD_vidWriteCommand (u8 u8CmdCpy) {
	  // Set RS = 0
	  DIO_SetPinValue(PORTD_DIO , PIN1, LOW);

	  // Set R/W = 0
	  DIO_SetPinValue(PORTD_DIO , PIN2, LOW);

	  // Set EN = 0
	  DIO_SetPinValue(PORTD_DIO , PIN3, HIGH);

	  DIO_SetPortValue (PORTC_DIO,u8CmdCpy);

	  // set EN to 1 after settting command
	  // pulse
	  DIO_SetPinValue(PORTD_DIO , PIN3, LOW);
	  _delay_ms(10);
	  DIO_SetPinValue(PORTD_DIO , PIN3, HIGH);

  }


/****************************************************************/


void LCD_vidInitialize(void){


	 // set VDD @ A0 to 5 volt
	  DIO_SetPinValue(PORTD_DIO , PIN0, HIGH);

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
		DIO_SetPinValue(PORTD_DIO, 1 , HIGH);

		// Set R/W to LOW
		DIO_SetPinValue(PORTD_DIO, 2 , LOW);

		// Set E to HIGH
		DIO_SetPinValue(PORTD_DIO, 3 , HIGH);

		// Load Command on Data bus
		DIO_SetPortValue(PORTC_DIO, u8DataCpy);

		// Set E to LOW
		DIO_SetPinValue(PORTD_DIO, 3, LOW);

		// Wait for E to settle
		_delay_ms(10);

		// Set E to HIGH
		DIO_SetPinValue(PORTD_DIO, 2, HIGH);

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

void LCDWriteInteger(u16 val , u16 field_length)
{
	/***************************************************************
	This function writes a integer type value to LCD module

	Arguments:
	1)int val	: Value to print

	2)unsigned int field_length :total length of field in which the value is printed
	must be between 1-5 if it is -1 the field length is no of digits in the val

	****************************************************************/

	u16 str[5]={0,0,0,0,0};
	u16 i=4,j=0;

	//Handle negative integers
	if(val<0)
	{
		LCD_vidWriteCharacter('-');   //Write Negative sign
		val=val*(-1);     //convert to positive
	}
	else
	{
		LCD_vidWriteCharacter(' ');
	}

	while(val)
	{
		str[i]=val%10;
		val=val/10;
		i--;
	}

	if(field_length==-1)
		while(str[j]==0) j++;
	else
		j=5-field_length;

	for(i=j;i<5;i++)
	{
		LCD_vidWriteCharacter('0'+str[i]);
	}
}
/********************************************************/

void vid_SeparateResult(u32 u32Result , u8 * u8ArrayResult) {

	u8ArrayResult[0]= ( (u32Result / 10000) % 10 ) + 48 ;
	u8ArrayResult[1]= ( (u32Result / 1000) % 10 ) + 48 ;
	u8ArrayResult[2]= ( (u32Result / 100) % 10 ) + 48 ;
	u8ArrayResult[3]= ( (u32Result / 10) % 10 ) + 48 ;
	u8ArrayResult[4]=   (u32Result  % 10 ) + 48 ;

}
