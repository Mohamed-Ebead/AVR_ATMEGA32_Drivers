/*
 * I2C_private.h
 *
 *  Created on: Oct 11, 2019
 *      Author: Mohamed_Ebead
 */

#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_


#define TWAR_REG (*((volatile u8*)0x22))
#define TWBR_REG (*((volatile u8*)0x20))
#define TWCR_REG (*((volatile u8*)0x56))
#define TWDR_REG (*((volatile u8*)0x23))
#define TWSR_REG (*((volatile u8*)0x21))


#define TWPS0 0
#define TWPS1 1

#define TWIE 0
#define TWEN 2
#define TWWC 3
#define TWSTO 4
#define TWSTA 5
#define TWSEA 6
#define TWINT 7





















#endif /* I2C_PRIVATE_H_ */
