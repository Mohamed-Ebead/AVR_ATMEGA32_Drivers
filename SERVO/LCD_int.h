/*
 * private.h
 *
 *  Created on: Aug 24, 2019
 *      Author: Mohamed_Ebead
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_


/****************************************************************/

/*description : Write a command to LCD module
 * input : u8 u8 u8CmdCpy
 * output : void
*/
/****************************************************************/

void LCD_vidWriteCommand (u8 u8CmdCpy) ;

/*description : Initialize LCD Module
 * input :  void
 * output : void
*/

void LCD_vidInitialize(void);
/****************************************************************/

/*description : write a character on LCD module
 * input : u8 u8DataCpy
 * output :  void
*/

void LCD_vidWriteCharacter(u8 u8DataCpy);
/****************************************************************/
/* Description :  Interface to write string on LCD screen
* Input      : Pointer to the string
* Output  :void
*/

void LCD_vidWriteString (u8* pu8StringCpy, u8 u8Index);
/****************************************************************/

/* Description :  go to specific coordinates point on LCD screen
* Input      : coordinates point : u8 Y,u8 X
* Output  :void
*/

void Gotoxy (u8 X,u8 Y);
/****************************************************************/

void LCDWriteInteger(u16 val,u16 field_length) ;

/****************************************************************/
void vid_SeparateResult(u32 u32Result , u8 * u8ArrayResult) ;



#endif /* LCD_INT_H_ */
