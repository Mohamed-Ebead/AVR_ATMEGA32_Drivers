/*
 * DIO_interface.h
 *
 *  Created on: Aug 17, 2019
 *      Author: Ahmed
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*ports*/
#define	PORTA	0
#define	PORTB	1
#define	PORTC	2
#define	PORTD	3


/*pins*/
#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7


#define DIO_HIGH	1
#define DIO_LOW		0


#define DIO_OUTPUT	1
#define DIO_INPUT	0

/*prototyps*/
/*Desc: set direction of any pin  */
/*inputs : Copy_u8PortId  : porta, port ......
 * 			Copy_u8PinId : pin0 ,....
 * 			Copy_u8Direction : input,output*/
/*return : void */
void DIO_vidSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Direction);

void DIO_vidSetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Value);

u8 DIO_u8GetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId);

void DIO_VidSetPortDirection (u8 Copy_u8PortId , u8 Copy_u8PortDirection);
void DIO_VidSetPortValue (u8 Copy_u8PortId , u8 Copy_u8PortValue);





#endif /* DIO_INTERFACE_H_ */
