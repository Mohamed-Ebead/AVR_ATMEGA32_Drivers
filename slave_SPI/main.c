/*
 * main.c
 *
 *  Created on: Jan 29, 2019
 *      Author: Ahmed
 */
#include "Std_Types.h"
#include "DELAY_interface.h"
#include "DIO_interface.h"

#include "SPI_Interface.h"

/*Master Program*/
//void main(void)
//{
//	//u8 temp[]={'A','h','m','e','d','\0'};
//	u8 recdata =0;
//	DIO_voidinit();
//	SPI_Init();
//	while(1)
//	{
//		SPI_SynchTransceiver('A',&recdata);
//		//for (int i = 0; i < 5; ++i)
//		//{
//		//	SPI_SynchTransceiver(temp[i]);
//		//}
//		delay_millisecond(1000);
//	}
//}

/*Master Program*/
void main(void)
{
	//u8 temp[]={'A','h','m','e','d','\0'};
	u8 recdata =0;
	DIO_voidinit();
	SPI_Init();
	while(1)
	{
		SPI_SynchTransceiver(3,&recdata);
		if(recdata == 'A')
		{
			DIO_u8SetPinValue(DIO_u8_PIN_NO_31,DIO_u8_PIN_HIGH);
		}
		else if (recdata == 'B')
		{
			DIO_u8SetPinValue(DIO_u8_PIN_NO_31,DIO_u8_PIN_LOW);
		}
	}
}
