/*
 * LCD_Private.h
 *
 *  Created on: Aug 29, 2019
 *      Author: Mohamed_Ebead
 */

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define No_Of_Chars 6

const u8  Sine_Wave[]=
{
		0x00, 0x00, 0x00, 0x01, 0x02, 0x04, 0x08, 0x10, //Char0
		0x0E, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Char1
		0x00, 0x00, 0x00, 0x10, 0x08, 0x04, 0x02, 0x01, //Char2
		0x10, 0x08, 0x04, 0x02, 0x01, 0x00, 0x00, 0x00, //Char3
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x0E, //Char4
		0x01, 0x02, 0x04, 0x08, 0x10, 0x00, 0x00, 0x00, //Char5


};



 const u8  Hamoksha[]=
{
		0x0E, 0x0E, 0x04, 0x0E, 0x15, 0x04, 0x0A, 0x0A, //Char0
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Char1
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Char2
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Char3
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Char4
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //Char5
};


 u8 Array ;

#endif /* LCD_PRIVATE_H_ */

