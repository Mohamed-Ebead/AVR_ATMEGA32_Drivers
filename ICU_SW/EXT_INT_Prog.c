/*
 * EXT_INT_Prog.c

 *
 *  Created on: Sep 27, 2019
 *      Author: Mohamed_Ebead
 */

#include <avr/interrupt.h>
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "EXT_INT_Private.h"
#include "TIMER_Private.h"
#include "Timer1_int.h"

/**************************************************/


void EXT_INT_Initialize(void) {

	// falling edge generates an interrupt request
	MCUCR_REG = 2 ;

	// INT0 Enable
	SET_BIT(GICR_REG,6) ;

	// Global Interrupt Enable
	SET_BIT(SREG_REG,7) ;

}

/**************************************************/

static u16 u16_Time ;
static u16 u16_TOn ;
static u16 u16_TOff ;
static u8 u8_Flag = 0 ;

/**************************************************/

ISR(INT0_vect){

	//u16_Time = TCNT1_REG ;

	u16_Time = u16Tim_GetCounterVal() ;
	TCNT1_REG = 0 ;

	if(u8_Flag==0){

		u16_TOn = u16_Time ;
		MCUCR_REG = 3 ;
		u8_Flag = 1 ;

	}
	else if (u8_Flag==1){

		u16_TOff = u16_Time ;
		MCUCR_REG = 2 ;
		u8_Flag = 0 ;

	}
	else{

	}

}

/**************************************************/

void vid_EXTINT_GetIcu(u16 * u16_F , u16 * u16_D){

	if ( (u16_TOn+u16_TOff) > 0 )
	{
		* u16_D = (u16_TOn * (u16)100) / (u16_TOn+u16_TOff) ;
		* u16_F = (u16)( (u32)1000000 /( (u32)(u16_TOn+u16_TOff)*(u8)8) ) ;
	}
	else{

	}

}

/**************************************************/
