/*
 * EXT_INT_Private.h
 *
 *  Created on: Sep 27, 2019
 *      Author: Mohamed_Ebead
 */


#ifndef EXT_INT_PRIVATE_H_
#define EXT_INT_PRIVATE_H_

//INTERRUPT REGISTERS

/**********************************************/

// Microcontroller Control Register
#define MCUCR_REG           (*((volatile u8*)0x55))

//General Interrupt Flag Register GICR
#define GIFR_REG            (*((volatile u8*)0x5A))

//General Interrupt Control Register GICR
#define GICR_REG            (*((volatile u8*)0x5B))

//Status Register
#define SREG_REG            (*((volatile u8*)0x5F))

/**********************************************/


#endif /* EXT_INT_PRIVATE_H_ */
