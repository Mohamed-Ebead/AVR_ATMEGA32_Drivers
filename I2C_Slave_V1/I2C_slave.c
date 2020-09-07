/*
 * I2C_master.c
 *
 *  Created on: Oct 11, 2019
 *      Author: Mohamed_Ebead
 */


#include "STD_Types.h"
#include "I2C_private.h"

/********************************************************/

void TWI_InitSlave (void) {
	TWAR_REG = u8_SlaveAddress ;     // set slave address
	TWCR_REG |= (1<<TWEA) | (1<<TWEN) | (0<<TWSTA) | (0<<TWST0) ;
}

/********************************************************/

void TWI_MatchAdrsRead (void) {
	while ( ( TWSR_REG & 0xF8 ) != 0x60 ) ;
	TWCR_REG |= (1<<TWEA) | (1<<TWEN) | (1<<TWINT)   ;
	while (!TWCR_REG & (1<<TWINT)) ;

}

/********************************************************/

u8 TWI_SlaveRead (void) {

	TWCR_REG |= (1<<TWINT) | (1<<TWEA) | (1<<TWEN) ;
	while (!(TWCR_REG & (1<<TWINT))) ;
	while ( ( TWSR_REG & 0xF8 ) != 0x80 ) ;
	return TWDR_REG ;
}

/********************************************************/

