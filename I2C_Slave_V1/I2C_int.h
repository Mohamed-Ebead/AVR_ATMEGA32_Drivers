/*
 * I2C_int.h
 *
 *  Created on: Oct 11, 2019
 *      Author: Mohamed_Ebead
 */

#ifndef I2C_INT_H_
#define I2C_INT_H_


#define DDRA  (*((volatile u8*)0x3A))
#define PORTA (*((volatile u8*)0x3B))

#define DDRC  (*((volatile u8*)0x34))
#define PORTC (*((volatile u8*)0x35))

void TWI_InitSlave (void) ;

void TWI_MatchAdrsRead (void) ;

u8 TWI_SlaveRead (void) ;



#endif /* I2C_INT_H_ */
