/*
 * DIO_prog.c
 *
 *  Created on: Aug 17, 2019
 *      Author: Ahmed
 */


/*Author : ahmed*/
/*date : 17/8/2018*/
/*Description : dio driver for avr atmegaa32 ......*/

#include "STD_TYPES.h"
#include "BIT_CALC.h"

#include "DIO_interface.h"
#include "DIO_regs.h"





/*Desc: ....... */
/*inputs : */
/*output : */
void DIO_vidSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Direction)
{
	if( (Copy_u8PortId <= PORTD) && (Copy_u8PinId <= PIN7) )
	{
		/*parameter checked status ok*/
		if(Copy_u8Direction == DIO_OUTPUT)
		{
			switch (Copy_u8PortId)
			{
				case PORTA: SET_BIT(DDRA_Register,Copy_u8PinId); break;
				case PORTB: SET_BIT(DDRB_Register,Copy_u8PinId); break;
				case PORTC: SET_BIT(DDRC_Register,Copy_u8PinId); break;
				case PORTD: SET_BIT(DDRD_Register,Copy_u8PinId); break;
			}
		}
		else if (Copy_u8Direction == DIO_INPUT)
		{
			switch (Copy_u8PortId)
			{
				case PORTA: CLR_BIT(DDRA_Register,Copy_u8PinId); break;
				case PORTB: CLR_BIT(DDRB_Register,Copy_u8PinId); break;
				case PORTC: CLR_BIT(DDRC_Register,Copy_u8PinId); break;
				case PORTD: CLR_BIT(DDRD_Register,Copy_u8PinId); break;
			}
		}
		else
		{
			/*error ....*/
		}

	}
	else
	{
		/*error ....*/
	}
}


void DIO_vidSetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Value)
{
	if( (Copy_u8PortId <= PORTD) && (Copy_u8PinId <= PIN7) )
	{
		if(Copy_u8Value == DIO_HIGH)
		{
			switch (Copy_u8PortId)
			{
				case PORTA: SET_BIT(PORTA_Register,Copy_u8PinId); break;
				case PORTB: SET_BIT(PORTB_Register,Copy_u8PinId); break;
				case PORTC: SET_BIT(PORTC_Register,Copy_u8PinId); break;
				case PORTD: SET_BIT(PORTD_Register,Copy_u8PinId); break;
			}
		}
		else if (Copy_u8Value == DIO_LOW)
		{
			switch (Copy_u8PortId)
			{
				case PORTA: CLR_BIT(PORTA_Register,Copy_u8PinId); break;
				case PORTB: CLR_BIT(PORTB_Register,Copy_u8PinId); break;
				case PORTC: CLR_BIT(PORTC_Register,Copy_u8PinId); break;
				case PORTD: CLR_BIT(PORTD_Register,Copy_u8PinId); break;
			}
		}
		else
		{
			//error
		}
	}
	else
	{
		//error
	}
}

u8 DIO_u8GetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId)
{
	u8 Local_u8Result;
	if( (Copy_u8PortId <= PORTD) && (Copy_u8PinId <= PIN7) )
	{
		switch (Copy_u8PortId)
		{
			case PORTA: Local_u8Result=GET_BIT(PINA_Register,Copy_u8PinId); break;
			case PORTB: Local_u8Result=GET_BIT(PINB_Register,Copy_u8PinId); break;
			case PORTC: Local_u8Result=GET_BIT(PINC_Register,Copy_u8PinId); break;
			case PORTD: Local_u8Result=GET_BIT(PIND_Register,Copy_u8PinId); break;
		}
	}
	else
	{
		//error
		Local_u8Result  = 0xFF;
	}

	return Local_u8Result;
}


void DIO_VidSetPortDirection (u8 Copy_u8PortId , u8 Copy_u8PortDirection)
{
	switch (Copy_u8PortId)
	{
		case PORTA :  DDRA_Register = Copy_u8PortDirection; break;
		case PORTB :  DDRB_Register = Copy_u8PortDirection; break;
		case PORTC :  DDRC_Register = Copy_u8PortDirection; break;
		case PORTD :  DDRD_Register = Copy_u8PortDirection; break;

		default : /*error*/	break;
	}
}


void DIO_VidSetPortValue (u8 Copy_u8PortId , u8 Copy_u8PortValue)
{
	switch (Copy_u8PortId)
	{
		case PORTA :  PORTA_Register = Copy_u8PortValue; break;
		case PORTB :  PORTB_Register = Copy_u8PortValue; break;
		case PORTC :  PORTC_Register = Copy_u8PortValue; break;
		case PORTD :  PORTD_Register = Copy_u8PortValue; break;

		default : /*error*/	break;
	}

}
