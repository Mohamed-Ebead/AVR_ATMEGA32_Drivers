/*
 * SPI_Prog.c
 *
 *  Created on: May 14, 2019
 *      Author: Ahmed
 */


#include "Std_Types.h"
#include "Bit_Calc.h"

#include "SPI_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"

void SPI_Init (void)
{
	SPCR_REG = (SPI_INT_Status<<7)|(SPI_Status<<6)|(SPI_DATA_ORDER<<5)|(SPI_MODE<<4)
			|(SPI_Clock_Polarity<<3)|(SPI_Clock_Phase<<2)|(SPI_PRESCALER<<0);
	/* Enable SPI, Master, set clock rate fck/16 , CPHA setupthen sample */
	//SPCR_REG = (1<<6)|(1<<4)|(1<<0)|(1<<2);


#if (SPI_MODE == SPI_MASTER)
	set_bit(SPCR_REG,4);
#else
	clr_bit(SPCR_REG,4);
#endif
}

void SPI_SynchTransceiver(u8 Copy_DataSent, u8 *Copy_DataReceived)
{
	/* Start transmission */
	SPDR_REG = Copy_DataSent;
	/* Wait for transmission complete */
	while(!(SPSR_REG & (1<<7)));
	/*save Received Byte*/
	*Copy_DataReceived = SPDR_REG;
}
