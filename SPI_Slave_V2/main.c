/*
 * main.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Mohamed_Ebead
 */


#include "STD_Types.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "DIO_int.h"


#include "SPI_Slave_INT.h"


u8 u8_ReceivedData = 0 ;  // To Save data recieved from master


void main(void)
{
	u8 u8garbage = 0 ;  // when recieving data from master transmit anything


	DIO_SetPinDirection(PORTA_DIO , PIN0 , OUTPUT);




	vid_SPI_vid_SlaveInit();



	while(1)
	{

		vid_SPI_vid_TranceiverChar(u8garbage , &u8_ReceivedData);

		if (u8_ReceivedData == 'a') {
			DIO_SetPinValue(PORTA_DIO , PIN0 , HIGH);
		}

		else if (u8_ReceivedData == 'b') {
			DIO_SetPinValue(PORTA_DIO , PIN0 , LOW);
		}
		else {

		}




	}

}
