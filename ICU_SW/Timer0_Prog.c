/*
 * Timer0.c
 *
 *  Created on: Sep 27, 2019
 *      Author: Mohamed_Ebead
 */

#include "STD_Types.h"
#include"TIMER_Private.h"
#include "ADC_int.h"

void Timer0_Initialize(void){

	// Prescalar / 64
	// fast PWM
	TCCR0_REG = 0b01101011 ;

	// 128 duty cycle 50 %
	OCR0_REG = 128 ;

	//OCR0_REG =  ADC_Read (0); ;

}
