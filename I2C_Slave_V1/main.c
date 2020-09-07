/*
 * main.c
 *
 *  Created on: Sep 25, 2019
 *      Author: Mohamed_Ebead
 */


#include "STD_Types.h"
#include "BIT_MATH.h"

#include "I2C_int.h"





void main(void){

	u8 Read = 0 ;

	DDRA = 0x01 ;


	TWI_InitSlave () ;




	while(1){

		TWI_MatchAdrsRead () ;

		Read = TWI_SlaveRead() ;

		if ( Read == 't') {

			 TOG_BIT(PORTA , 0 ) ;
		}


	}

}
