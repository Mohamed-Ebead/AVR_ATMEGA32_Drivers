/*
 * main.c
 *
 *   Created on: 12/10/2019
 *      Author: Mhamed Ebead
 */


#include "STD_Types.h"

#include<util/delay.h>

#include "SPI_Master_INT.h"



u8 u8_ReceivedData = 0 ;  // To Save data recieved from master



void main(void)
{

u8 u8_Garbage = 0   ; // Recieve

		vid_SPI_vid_MasterInit();


	while(1)
	{
		vid_SPI_vid_TranceiverChar('a' , &u8_Garbage);
	   _delay_ms(1000);
	   vid_SPI_vid_TranceiverChar('b' , &u8_Garbage);
	  _delay_ms(1000);


	}

}
