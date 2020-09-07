/*
 * Timer1_prog.c
 *
 *  Created on: Sep 27, 2019
 *      Author: Mohamed_Ebead
 */

#include "STD_Types.h"
#include"Timer_Private.h"


void Timer1_Initialize(void){

	// Normal Mode
	// Prescalar / 8

	TCCR1A_REG = 0;
	TCCR1B_REG = 0x03 ;

}


u16 u16Tim_GetCounterVal(void){

	return TCNT1_REG ;

}

void Timer1_Reset(void){

	TCNT1_REG = 0 ;
}
