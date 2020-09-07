

/********************************** Header Files INCLUSIONS ****************************/
#include "Std_Types.h"


#include "util/delay.h"

#include "DIO_int.h"
#include "KEYPAD_int.h"




/*************************************** Constants *************************************/
/* Values of the Key Pad switches                                                      */
/* Matrix is not standard it depends on the connection between the Micro and KeyPad    */
const u8 KPD_au8SwitchVal[4][4] =
{
  {
    0x04,
    0x08,
    0x0C,
    0x10 },
  {
    0x03,
    0x07,
    0x0B,
    0x0F },
  {
    0x02,
    0x06,
    0x0A,
    0x0E },
  {
    0x01,
    0x05,
    0x09,
    0x0D }
};

/***************************************************************************************/



/***************************************************************************************/
/* Description! Interface to get the ID of the pressed key, return 0 incase no key     */
/*              is pressed, this function doesn't handle the sitaution if 2 keys are   */
/*              pressed at the same time                               	     		   */
/* Input      ! Nothing                                                                */
/* Output     ! Nothing                                                                */
/***************************************************************************************/
u8 KPD_u8GetPressedKey(void)
{

  u8 LOC_u8Column;

  u8 LOC_u8Row;

  /* Initialize the switch status to NOT Pressed                                                                     */
  u8 LOC_u8Retrun = NOT_PRESSED;

  /* Looping on columns of the Key Pad                                                                               */
  for (LOC_u8Column = 0 + COL_INIT; LOC_u8Column < COL_FIN; LOC_u8Column++)
  {
    /* Activate the Column                                                                                           */
    Dio_vidSetPinValue(PORT, LOC_u8Column, STD_LOW);

    /* Loop on the rows of the Key Pad                                                                               */
    for (LOC_u8Row = 0 + ROW_INIT; LOC_u8Row < ROW_FIN; LOC_u8Row++)
    {
      /* Check the status of the switch                                                                              */
      if (!Dio_u8GetPinValue(PORT, LOC_u8Row))
      {
        /* Get the value of the currently pressed switch                                                             */
        LOC_u8Retrun = KPD_au8SwitchVal[LOC_u8Column - COL_INIT][LOC_u8Row - ROW_INIT];

		DIO_SetPinValue(PORTB , PIN0 , HIGH);

        /* Wait until the switch is released (Single Press)                                                          */
        while (!Dio_u8GetPinValue(PORT, LOC_u8Row))
          ;

        /* Delay to avoid bouncing                                                                                   */
        _delay_ms(10);

      }
    }

    /* Deactivate the Column                                                                                         */
    Dio_vidSetPinValue(PORT, LOC_u8Column, STD_HIGH);
  }

  return LOC_u8Retrun;
}
