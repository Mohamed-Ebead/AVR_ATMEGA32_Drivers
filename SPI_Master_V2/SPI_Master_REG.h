/*
 * SOI_REG.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: layla
 */

#ifndef SPI_MASTER_REG_H_
#define SPI_MASTER_REG_H_


#define SPCR_REG    *((volatile u8*) 0x2D)
#define SPSR_REG    *((volatile u8*) 0x2E)
#define SPDR_REG    *((volatile u8*) 0x2F)


#define DDRB  (*((volatile u8*)0x37))
#define PORTB  (*((volatile u8*)0x38))


#endif /* SPI_MASTER_REG_H_ */
