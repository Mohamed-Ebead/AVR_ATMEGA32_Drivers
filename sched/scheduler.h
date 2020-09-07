

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "Std_Types.h"

#define MAX_NUM_OF_TASKS  10
typedef uint8 TaskId_T;

typedef struct
{
	TaskId_T id;				//mean systems can only have 255 task
	void (*TaskHandler)(void);	//task address at the memory
	//uint8 priority;
	uint16 period;		//its unit is tick which = 5ms so this number user enters should be in ticks which is number of seconds multiple from 5 milliseconds
	uint16 offset;
}TaskControlBlock_T;

void Scheduler_Init (void);
void Scheduler_AddTask(TaskControlBlock_T *tcb) ;
void Scheduler_DeleteTask(TaskId_T tid);
void Scheduler_Engine (void);

#endif /* SCHEDULER_H_ */
