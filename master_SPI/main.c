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

u8 recdata =0;

/*Master Program*/
void main(void)
{

	SPI_Init();
	while(1)
	{
		SPI_SynchTransceiver('A',&recdata);

		delay_millisecond(1000);
		SPI_SynchTransceiver('B',&recdata);
		delay_millisecond(1000);
	}
}
