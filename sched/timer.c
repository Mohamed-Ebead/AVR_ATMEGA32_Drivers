

#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

static void (*TimerCallBack)(void) = '\0';		//not prototype it's variable like int *x; it's declaration of pointer to function to save the address of shc_choose in it and it only reserved 4bytes like any regular pointer

ISR(TIMER0_COMP_vect)
{
	if (TimerCallBack != '\0')
	{
		TimerCallBack();
	}
}

void Timer_Init (void)		//it should take void or take pointer to structure have the timer configuration
{
	TCCR0 = 0b00001011;		//prescaler to achieve the 5ms and choose
	TIMSK |= 0b00000010;
	OCR0 = 78;				//5ms period
}

void Timer_SetOFCallBack(void (*sched)(void))
{
	TimerCallBack = sched;
}
