/*
 * SPI_PRG.c
 *
 *  Created on: 12/10/2019
 *      Author: Mohamed Ebead
 */



#include "STD_Types.h"
#include "DIO_int.h"

#include "SPI_conf.h"
#include "SPI_Master_REG.h"







void vid_SPI_vid_MasterInit(void)

{
	DIO_SetPinDirection(SPI_PORT,SS,INPUT) ;    // MASTER : SET SS AS INPUT AND WRITE 1
	DIO_SetPinValue(SPI_PORT,SS,HIGH) ;


	DIO_SetPinDirection(SPI_PORT,SCK,OUTPUT) ;
 	DIO_SetPinDirection(SPI_PORT,MOSI,OUTPUT) ;

 	DIO_SetPinDirection(SPI_PORT,MISO,INPUT) ;





	/* disable SPI interrupt , Enable SPI , LSB is transmitted first ,
	 * Master , Rinsing edge leading , and set up leading , CLK/16 */

	SPCR_REG = 0b01110101 ;

	SPSR_REG &= ~(1<<SPI2X);			// Disable speed doubler

}

void vid_SPI_vid_TranceiverChar(u8 u8_Copy_DataSent, u8 *u8_Copy_DataReceived)
{
	SPDR_REG= u8_Copy_DataSent;                // Start transmission

	while(!SPSR_REG &(1<<SPIF));               //  Wait for transmission complete

	*u8_Copy_DataReceived = SPDR_REG;          // save Received Byte
}

