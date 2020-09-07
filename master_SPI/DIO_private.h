/***************************************************************/
/************* Author		: Ahmed Mamdouh		****************/
/************* Created on	: Jan 29, 2019		****************/
/**************** Version 		: V01			****************/
/***************************************************************/
/************************** Description ************************/
/***************************----------- ************************/
/***********file contains all Macros to be used by
 * the developer of this component only ************************/
/***************************************************************/

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/*****************Ports & Pins Maximum Numbers****************/
#define DIO_MAXPINNB 	(u8)32
#define DIO_MAXPPORTNB	(u8)4
/****************Number of Pins in each Port *****************/
#define NUMBER_PIN_IN_PORT (u8)8

/********************************/
#define DIO_u8_PIN_INIT_HIGH    1
#define DIO_u8_PIN_INIT_LOW     0
#define DIO_u8_PIN_INIT_DEF     0

#define DIO_u8_PIN_INIT_OUTPUT  1
#define DIO_u8_PIN_INIT_INPUT   0

#define DIO_u8_PORT_INIT_HIGH   0xFF
#define DIO_u8_PORT_INIT_LOW    0x00

#define DIO_u8_PORT_INIT_OUTPUT 0xFF
#define DIO_u8_PORT_INIT_INPUT  0x00

/*****************Dio Registers Addresses********************/

#define DDRA	((volatile Register *)(0x3A))
#define PINA	((volatile Register *)(0x39))
#define PORTA	((volatile Register *)(0x3B))

#define DDRB	((volatile Register *)(0x37))
#define PINB	((volatile Register *)(0x36))
#define PORTB	((volatile Register *)(0x38))

#define DDRC	((volatile Register *)(0x34))
#define PINC	((volatile Register *)(0x33))
#define PORTC	((volatile Register *)(0x35))

#define DDRD	((volatile Register *)(0x31))
#define PIND	((volatile Register *)(0x30))
#define PORTD	((volatile Register *)(0x32))



#define DIO_DDRA_REG	(DDRA->ByteAccess)
#define DIO_PINA_REG	(PINA->ByteAccess)
#define DIO_PORTA_REG	(PORTA->ByteAccess)

#define DIO_DDRB_REG	(DDRB->ByteAccess)
#define DIO_PINB_REG	(PINB->ByteAccess)
#define DIO_PORTB_REG	(PORTB->ByteAccess)

#define DIO_DDRC_REG	(DDRC->ByteAccess)
#define DIO_PINC_REG	(PINC->ByteAccess)
#define DIO_PORTC_REG	(PORTC->ByteAccess)

#define DIO_DDRD_REG	(DDRD->ByteAccess)
#define DIO_PIND_REG	(PIND->ByteAccess)
#define DIO_PORTD_REG	(PORTD->ByteAccess)

#endif /* DIO_PRIVATE_H_ */
