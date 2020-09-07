

#ifndef TIMER_H_
#define TIMER_H_

//typedef void (*TimerCallBack)(void);
void Timer_Init (void);
void Timer_SetOFCallBack(void (*sched)(void));

#endif /* TIMER_H_ */
