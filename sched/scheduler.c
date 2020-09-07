

#include "timer.h"
#include "scheduler.h"

static TaskControlBlock_T TCB [MAX_NUM_OF_TASKS];
static uint8 num_of_runs [MAX_NUM_OF_TASKS];
static uint32 num_of_ticks = 0;

static void Scheduler_Choose (void);

void Scheduler_Init (void)
{
	TaskId_T i;
	for(i=0;i<MAX_NUM_OF_TASKS;i++)
	{
		TCB[i].TaskHandler = '\0';
		TCB[i].id = 0;
		TCB[i].period = 0;
		TCB[i].offset = 0;
		//TCB[i].priority = 0;
		num_of_runs[i] = 0;
	}
	Timer_Init();
	Timer_SetOFCallBack(Scheduler_Choose);
}

void Scheduler_AddTask(TaskControlBlock_T *tcb) 		//can return boolean to say if success in adding or it's full
{
	TaskId_T i;
	for (i=0;i<MAX_NUM_OF_TASKS;i++)
	{
		if(TCB[i].id == 0)
		{
			TCB[i].TaskHandler = tcb->TaskHandler;
			TCB[i].id = tcb->id;
			TCB[i].period = tcb->period;
			TCB[i].offset = tcb->offset;
			//TCB[i].priority = tcb->priority;
			break;								//to NOT add same tasks to all empty spaces
		}
	}
}

void Scheduler_DeleteTask(TaskId_T tid)
{
	TaskId_T i;
	for (i=0;i<MAX_NUM_OF_TASKS;i++)
	{
		if (TCB[i].id == tid)
		{
			TCB[i].TaskHandler = '\0';
			TCB[i].id = 0;
			TCB[i].period = 0;
			TCB[i].offset = 0;
			//TCB[i].priority = 0;
			num_of_runs[i] = 0;
			break;
		}
	}
}

static void Scheduler_Choose (void)		//it must finish under 5 ms
{
	TaskId_T i;
	num_of_ticks ++;  //its unit is tick which = 5ms
	for (i=0;i<MAX_NUM_OF_TASKS;i++)
	{
		if ( ((num_of_ticks/*-TCB[i].offset*/) % TCB[i].period) == 0 )
		{
			if (num_of_runs[i] != 255)
			{
				num_of_runs[i]++;
			}
		}
	}
}

void Scheduler_Engine (void)			//work to the end if time :D
{
	TaskId_T i;
	asm("sei");
	while (1)
	{
		for (i=0;i<MAX_NUM_OF_TASKS;i++)
		{
			if (num_of_runs[i] > 0)
			{
				num_of_runs[i]--;
				if (TCB[i].TaskHandler != '\0')
				{
					TCB[i].TaskHandler();
				}
			}
		}
	}
}
