/***************************************************************/
/************* Author		: Ahmed Mamdouh		****************/
/************* Created on	: Jan 29, 2019		****************/
/**************** Version 		: V01			****************/
/***************************************************************/
/************************** Description ************************/
/***************************----------- ************************/
/********this file contains all macros and prototypes***********/
/******** required by the user to use this component ***********/
/***************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_u8_PIN_HIGH    (u8)19
#define DIO_u8_PIN_LOW     (u8)91

#define DIO_u8_PIN_OUTPUT  (u8)22
#define DIO_u8_PIN_INPUT   (u8)9

#define DIO_u8_PORT_HIGH   (u8)14
#define DIO_u8_PORT_LOW    (u8)22

#define DIO_u8_PORT_OUTPUT (u8)35
#define DIO_u8_PORT_INPUT  (u8)48

/************************Ports Numbers************************/
#define DIO_u8_PORT0       (u8)0
#define DIO_u8_PORT1       (u8)1
#define DIO_u8_PORT2       (u8)2
#define DIO_u8_PORT3       (u8)3
/************************Pins Numbers************************/
#define DIO_u8_PIN_NO_00   (u8)0
#define DIO_u8_PIN_NO_01   (u8)1
#define DIO_u8_PIN_NO_02   (u8)2
#define DIO_u8_PIN_NO_03   (u8)3
#define DIO_u8_PIN_NO_04   (u8)4
#define DIO_u8_PIN_NO_05   (u8)5
#define DIO_u8_PIN_NO_06   (u8)6
#define DIO_u8_PIN_NO_07   (u8)7
#define DIO_u8_PIN_NO_08   (u8)8
#define DIO_u8_PIN_NO_09   (u8)9
#define DIO_u8_PIN_NO_10   (u8)10
#define DIO_u8_PIN_NO_11   (u8)11
#define DIO_u8_PIN_NO_12   (u8)12
#define DIO_u8_PIN_NO_13   (u8)13
#define DIO_u8_PIN_NO_14   (u8)14
#define DIO_u8_PIN_NO_15   (u8)15
#define DIO_u8_PIN_NO_16   (u8)16
#define DIO_u8_PIN_NO_17   (u8)17
#define DIO_u8_PIN_NO_18   (u8)18
#define DIO_u8_PIN_NO_19   (u8)19
#define DIO_u8_PIN_NO_20   (u8)20
#define DIO_u8_PIN_NO_21   (u8)21
#define DIO_u8_PIN_NO_22   (u8)22
#define DIO_u8_PIN_NO_23   (u8)23
#define DIO_u8_PIN_NO_24   (u8)24
#define DIO_u8_PIN_NO_25   (u8)25
#define DIO_u8_PIN_NO_26   (u8)26
#define DIO_u8_PIN_NO_27   (u8)27
#define DIO_u8_PIN_NO_28   (u8)28
#define DIO_u8_PIN_NO_29   (u8)29
#define DIO_u8_PIN_NO_30   (u8)30
#define DIO_u8_PIN_NO_31   (u8)31

/*Description : Set Pin Direction
 * Inputs:
 * Outputs:
 * */
u8 DIO_u8SetPinDirection(u8 Copy_u8PinNB,u8 Copy_u8Direction);
u8 DIO_u8SetPinValue(u8 Copy_u8PinNB,u8 Copy_u8Value);
u8 DIO_u8GetPinValue(u8 Copy_u8PinNB,u8* Copy_Pu8Value);

u8 DIO_u8SetPortDirection(u8 Copy_u8PortNB,u8 Copy_u8Direction);
u8 DIO_u8SetPortValue(u8 Copy_u8PortNB,u8 Copy_u8Value);
u8 DIO_u8GetPortValue(u8 Copy_u8PortNB,u8* Copy_Pu8Value);

void DIO_voidinit(void);



#endif /* DIO_INTERFACE_H_ */
