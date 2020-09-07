/*
 * SPI_PRG.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: layla
 */

#include "BIT_MATH.h"
#include "STD_Types.h"

#include "DIO_int.h"
#include "SPI_conf.h"
#include "SPI_Slave_privet.h"



extern u8 u8_ReceivedData  ;



void vid_SPI_vid_SlaveInit(void)

{
	DIO_SetPinDirection(SPI_PORT,SS,INPUT) ;    // SLAVE : SET SS AS INPUT
	DIO_SetPinValue(SPI_PORT,SS,LOW) ;          //AND WRITE 0 TO ACTIVATE SLAVE


	DIO_SetPinDirection(SPI_PORT,SCK,INPUT) ;
	DIO_SetPinDirection(SPI_PORT,MOSI,INPUT) ;

	DIO_SetPinDirection(SPI_PORT,MISO,OUTPUT) ;





	/* disable SPI interrupt , Enable SPI , LSB is transmitted first ,
	 * Slave , Rinsing edge leading , and set up leading , CLK/16 */

	SPCR_REG = 0b01100101 ;

	SPSR_REG &= ~(1<<SPI2X);			// Disable speed doubler

}



void vid_SPI_vid_TranceiverChar(u8 u8_Copy_DataSent, u8 *u8_Copy_DataReceived)
{
	SPDR_REG= u8_Copy_DataSent;                // Start transmission

	while(!SPSR_REG &(1<<SPIF));               //  Wait for transmission complete

	*u8_Copy_DataReceived = SPDR_REG;          // save Received Byte

}






