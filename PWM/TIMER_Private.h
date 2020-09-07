/*
 * TIMER_Private.h
 *
 *  Created on: Sep 20, 2019
 *      Author: Mohamed_Ebead
 */

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_



#define TCCR0_REG     (*((volatile u8*)0x53))

#define TCCR1A_REG     (*((volatile u8*)0x4F))

#define TCCR1B_REG     (*((volatile u8*)0x4E))

#define OCR1A_REG    (*((volatile u16*)0x4A))

#define OCR1B_REG    (*((volatile u16*)0x48))



#define SREG_REG (*((volatile u8*)0x5F))

#define SREG_REG (*((volatile u8*)0x5F))

#define TIMSK_REG (*((volatile u8*)0x59))

#define SREG_REG (*((volatile u8*)0x5F))


#endif /* TIMER_PRIVATE_H_ */
