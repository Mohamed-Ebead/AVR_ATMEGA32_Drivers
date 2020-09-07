/*
 * KEYPAD_int.h
 *
 *  Created on: Aug 30, 2019
 *      Author: Mohamed_Ebead
 */

#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

/*description : get pressed key on key pad
 * input : void
 * output : u8 u8Pressed_Key
*/

u8 KPD_u8GetPressedKey(void) ;

/***************************************** Macros **************************************/
#define PORT DIO_PORTD

#define COL_INIT   0

#define COL_FIN    4

#define ROW_INIT   4

#define ROW_FIN    8

#define NOT_PRESSED    0

#endif /* KEYPAD_INT_H_ */
