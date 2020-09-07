/*
 * DELAY_private.h
 *
 *  Created on: Feb 8, 2019
 *      Author: Ahmed
 */

#ifndef DELAY_PRIVATE_H_
#define DELAY_PRIVATE_H_

/*Time values for milliseconds in floating point representation for accuracy*/
#define T1 					2.376
#define T2 					1.502
#define T3 					911.5
#define one_for_loop_time	4.8795

/*Time values for microseconds in integer representation for minimum T3 starts working from 83 microseconds*/
#define T1_us 					2
#define T2_us 					2
#define T3_us 					78
#define Total_Time_lose			82
#define one_for_loop_time_us	5


static u32 value=0;
static u32 counts=0;

#endif /* DELAY_PRIVATE_H_ */
