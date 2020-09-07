/*
 * I2C_int.h
 *
 *  Created on: Oct 11, 2019
 *      Author: Mohamed_Ebead
 */

#ifndef I2C_INT_H_
#define I2C_INT_H_

#define DDRC  (*((volatile u8*)0x34))
#define PORTC (*((volatile u8*)0x35))

void TWI_InitMaster (void) ;

void TWI_Start (void) ;

void TWI_WriteAddress (u8 u8_Address) ;

void TWI_WriteData (u8 u8_Data) ;

void TWI_Stop (void) ;


#endif /* I2C_INT_H_ */
