/*
 * main.c
 *
 *  Created on: Aug 16, 2019
 *      Author: Ahmed
 */

#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include <util/delay.h>

#include "DIO_interface.h"
#include "UART_interface.h"
#include "DIO_regs.h"

void main (void)
{
	u8 res=0;
	vid_UART_vid_Initialize();
	DIO_VidSetPortDirection(PORTA,0xFF);

	while(1)
	{
		res=u8_UART_u8_GetChar();
		if (res == 'a')
		{
			DIO_VidSetPortValue(PORTA,DIO_HIGH);
		}
		else if (res == 'b')
		{
			DIO_VidSetPortValue(PORTA,DIO_LOW);

		}
}
}


/*
 *
		UART_SendChar('a');
		_delay_ms(2000);

*/
