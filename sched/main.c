#include <avr/io.h>
#include "scheduler.h"
#include "common.h"

void Task1(void);
void Task2(void);
void Task3(void);
void Task4(void);

void main (void)
{
	TaskControlBlock_T t1 =	{
		5,
		Task1,
		25,
		0,
	};

	TaskControlBlock_T t2 =	{
		6,
		Task2,
		50,
		0,
	};

	TaskControlBlock_T t3 =	{
		7,
		Task3,
		100,
		0,
	};
	TaskControlBlock_T t4 =	{
		8,
		Task4,
		200,
		0,
	};

	DDRA = 0xFF;
	DDRB = 0xFF;
	DDRC = 0xFF;
	DDRD = 0xFF;

	Scheduler_Init();

	Scheduler_AddTask(&t1);
	Scheduler_AddTask(&t2);
	Scheduler_AddTask(&t3);
	Scheduler_AddTask(&t4);

	Scheduler_Engine();
	while(1)
	{
		
	}
}

void Task1(void)
{
	PORTA++;
}

void Task2(void)
{
	PORTB++;
}

void Task3(void)
{
	PORTC++;
}

void Task4(void)
{
	PORTD++;
}



