/*
 * I2C_master.c
 *
 *  Created on: Oct 11, 2019
 *      Author: Mohamed_Ebead
 */


#include "STD_Types.h"
#include "I2C_private.h"

/********************************************************/

void TWI_InitMaster (void) {
	TWBR_REG = 0X72 ;     // FROM BIT RATE EQUATION
	TWSR_REG |= (1<<TWPS1) | (1<<TWPS0) ;   //PRESCALER / 64
}

/********************************************************/

void TWI_Start (void) {

	/* clear TWINT Flag , write TWSTA to 1 to become a master, TWI Enable */

	TWCR_REG = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN) ;

	/*wait until TWI finishes its current job */
	while (!(TWCR_REG & (1<<TWINT))) ;

	while ( ( TWSR_REG & 0xF8 ) != 0x08 ) ;
}

/********************************************************/

void TWI_WriteAddress (u8 u8_Address) {

	TWCR_REG |= (1<<TWINT)  ;  //clear TWINT Flag
	TWDR_REG = u8_Address ;

	while (!TWCR_REG & (1<<TWINT)) ;
	while ( ( TWSR_REG & 0xF8 ) != 0x18 ) ;
}

/********************************************************/

void TWI_WriteData (u8 u8_Data) {

	TWCR_REG |= (1<<TWINT)  ;
	TWDR_REG = u8_Data ;

	while (!TWCR_REG & (1<<TWINT)) ;
	while ( ( TWSR_REG & 0xF8 ) != 0x28 ) ;
}

/********************************************************/

void TWI_Stop (void) {
	TWCR_REG |= (1<<TWSTO) ;      //generate stop condition

}

/********************************************************/
