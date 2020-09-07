/*
 * DELAY_prog.c
 *
 *  Created on: Feb 8, 2019
 *      Author: Ahmed
 */
#include "Std_Types.h"

#include "DELAY_interface.h"
#include "DELAY_private.h"
#include "DELAY_config.h"


void delay_millisecond (u32 valua_0)
{
	value=(valua_0*1000)-T1-T2-T3;
	counts=(value/one_for_loop_time);

	for(;counts>0;counts--)
	{
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
	}
}


void delay_microsecond (u32 valua_0)
{
	value=(valua_0)-T1_us-T2_us-T3_us;
	counts=(value/one_for_loop_time_us);


	for(;counts>0;counts--)
	{
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
		asm("nop");
	}
}

