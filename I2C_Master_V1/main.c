/*
 * main.c
 *
 *  Created on: Sep 25, 2019
 *      Author: Mohamed_Ebead
 */


#include "STD_Types.h"
#include <util/delay.h>
#include "I2C_int.h"



void main(void){

	u8 Address = 0x20 ;
	u8 Data = 't' ;


	TWI_InitMaster () ;



	while(1){

		TWI_Start () ;

			TWI_WriteAddress (Address+0) ;


			TWI_WriteData (Data) ;

			_delay_ms(1000) ;
	}

	TWI_Stop () ;



}
