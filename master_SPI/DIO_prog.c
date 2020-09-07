/***************************************************************/
/************* Author		: Ahmed Mamdouh		****************/
/************* Created on	: Jan 29, 2019		****************/
/**************** Version 		: V01			****************/
/***************************************************************/
/************************** Description ************************/
/***************************----------- ************************/
/* This file have the implementation of the DIO functionalities*/
/***************************************************************/
#include "Std_Types.h"
#include "Bit_Calc.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


/****************************************************************/
/* Description : Set Pin Direction to OUT or IN 				*/
/* Inputs:	u8PinNB		:	Pin Number							*/
/* 			u8Direction :	Pin DIO_u8_PIN_OUTPUT or DIO_u8_PIN_INPUT		*/
/* Outputs: Error State											*/
/****************************************************************/
u8 DIO_u8SetPinDirection(u8 Copy_u8PinNB,u8 Copy_u8Direction)
{
	/*Logical Variable*/
	u8 Local_u8Error=STD_u8_ERROR_OK;

	if((Copy_u8PinNB < DIO_MAXPINNB) &&
					((Copy_u8Direction == DIO_u8_PIN_OUTPUT)||
					 (Copy_u8Direction == DIO_u8_PIN_INPUT)))
	{
		switch (Copy_u8Direction)
		{
			case DIO_u8_PIN_OUTPUT:
				if( (Copy_u8PinNB >= DIO_u8_PIN_NO_00) && (Copy_u8PinNB < DIO_u8_PIN_NO_08) )
				{
					BITCALC_SET_BIT(DIO_DDRA_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_00));
				}
				else if ( (Copy_u8PinNB >= DIO_u8_PIN_NO_08) && (Copy_u8PinNB < DIO_u8_PIN_NO_16) )
				{
					BITCALC_SET_BIT(DIO_DDRB_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_08));
				}
				else if ( (Copy_u8PinNB >= DIO_u8_PIN_NO_16) && (Copy_u8PinNB < DIO_u8_PIN_NO_24) )
				{
					BITCALC_SET_BIT(DIO_DDRC_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_16));
				}
				else if ( (Copy_u8PinNB >= DIO_u8_PIN_NO_24) && (Copy_u8PinNB <= DIO_u8_PIN_NO_31) )
				{
					BITCALC_SET_BIT(DIO_DDRD_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_24));
				}
				break;

			case DIO_u8_PIN_INPUT:
				if( (Copy_u8PinNB >= DIO_u8_PIN_NO_00) && (Copy_u8PinNB < DIO_u8_PIN_NO_08) )
				{
					BITCALC_CLR_BIT(DIO_DDRA_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_00));
				}
				else if ( (Copy_u8PinNB >= DIO_u8_PIN_NO_08) && (Copy_u8PinNB < DIO_u8_PIN_NO_16) )
				{
					BITCALC_CLR_BIT(DIO_DDRB_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_08));
				}
				else if ( (Copy_u8PinNB >= DIO_u8_PIN_NO_16) && (Copy_u8PinNB < DIO_u8_PIN_NO_24) )
				{
					BITCALC_CLR_BIT(DIO_DDRC_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_16));
				}
				else if ( (Copy_u8PinNB >= DIO_u8_PIN_NO_24) && (Copy_u8PinNB <= DIO_u8_PIN_NO_31) )
				{
					BITCALC_CLR_BIT(DIO_DDRD_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_24));
				}
				break;

			default:
				break;
		}


	}
	else
	{
		Local_u8Error = STD_u8_ERROR_NOK;
	}

	/*Function Return*/
	return Local_u8Error;
}

/******************************************************************/
/* Description : Set Pin Value to HIGH or LOW	    			  */
/* Inputs:	u8PinNB		:	Pin Number					  		  */
/* 			u8Value :	Pin DIO_u8_PIN_HIGH or DIO_u8_PIN_LOW 	  */
/* Outputs: Error State								     		  */
/******************************************************************/
u8 DIO_u8SetPinValue(u8 Copy_u8PinNB,u8 Copy_u8Value)
{
	/*Logical Variable*/
	u8 Local_u8Error=STD_u8_ERROR_OK;

	if((Copy_u8PinNB < DIO_MAXPINNB) &&
					((Copy_u8Value == DIO_u8_PIN_HIGH)||
					 (Copy_u8Value == DIO_u8_PIN_LOW)))
	{
		switch (Copy_u8Value)
		{
			case DIO_u8_PIN_HIGH:
				if( (Copy_u8PinNB >= DIO_u8_PIN_NO_00) && (Copy_u8PinNB < DIO_u8_PIN_NO_08) )
				{
					BITCALC_SET_BIT(DIO_PORTA_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_00));
				}
				else if ( (Copy_u8PinNB >= DIO_u8_PIN_NO_08) && (Copy_u8PinNB < DIO_u8_PIN_NO_16) )
				{
					BITCALC_SET_BIT(DIO_PORTB_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_08));
				}
				else if ( (Copy_u8PinNB >= DIO_u8_PIN_NO_16) && (Copy_u8PinNB < DIO_u8_PIN_NO_24) )
				{
					BITCALC_SET_BIT(DIO_PORTC_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_16));
				}
				else if ( (Copy_u8PinNB >= DIO_u8_PIN_NO_24) && (Copy_u8PinNB <= DIO_u8_PIN_NO_31) )
				{
					BITCALC_SET_BIT(DIO_PORTD_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_24));
				}
				break;

			case DIO_u8_PIN_LOW:
				if( (Copy_u8PinNB >= DIO_u8_PIN_NO_00) && (Copy_u8PinNB < DIO_u8_PIN_NO_08) )
				{
					BITCALC_CLR_BIT(DIO_PORTA_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_00));
				}
				else if ( (Copy_u8PinNB >= DIO_u8_PIN_NO_08) && (Copy_u8PinNB < DIO_u8_PIN_NO_16) )
				{
					BITCALC_CLR_BIT(DIO_PORTB_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_08));
				}
				else if ( (Copy_u8PinNB >= DIO_u8_PIN_NO_16) && (Copy_u8PinNB < DIO_u8_PIN_NO_24) )
				{
					BITCALC_CLR_BIT(DIO_PORTC_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_16));
				}
				else if ( (Copy_u8PinNB >= DIO_u8_PIN_NO_24) && (Copy_u8PinNB <= DIO_u8_PIN_NO_31) )
				{
					BITCALC_CLR_BIT(DIO_PORTD_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_24));
				}
				break;

			default:
				break;
		}
	}
	else
	{
		Local_u8Error = STD_u8_ERROR_NOK;
	}

	/*Function Return*/
	return Local_u8Error;
}

/******************************************************************/
/* Description : Get Pin Value to HIGH or LOW	    			  */
/* Inputs:	u8PinNB		:	Pin Number					  		  */
/* 			Pu8Value :	pointer to save pin_value inside it &	  */
/* 						return it to the caller					  */
/* Outputs: Error State								     		  */
/******************************************************************/
u8 DIO_u8GetPinValue(u8 Copy_u8PinNB,u8* Copy_Pu8Value)
{
	/*Logical Variable*/
	u8 Local_u8Error=STD_u8_ERROR_OK;

	if((Copy_u8PinNB < DIO_MAXPINNB) && (Copy_Pu8Value != Null))
	{
		if( (Copy_u8PinNB >= DIO_u8_PIN_NO_00) && (Copy_u8PinNB < DIO_u8_PIN_NO_08) )
		{
			*Copy_Pu8Value=BITCALC_GET_BIT(DIO_PINA_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_00));
		}
		else if ( (Copy_u8PinNB >= DIO_u8_PIN_NO_08) && (Copy_u8PinNB < DIO_u8_PIN_NO_16) )
		{
			*Copy_Pu8Value=BITCALC_GET_BIT(DIO_PINB_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_08));
		}
		else if ( (Copy_u8PinNB >= DIO_u8_PIN_NO_16) && (Copy_u8PinNB < DIO_u8_PIN_NO_24) )
		{
			*Copy_Pu8Value=BITCALC_GET_BIT(DIO_PINC_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_16));
		}
		else if ( (Copy_u8PinNB >= DIO_u8_PIN_NO_24) && (Copy_u8PinNB <= DIO_u8_PIN_NO_31) )
		{
			*Copy_Pu8Value=BITCALC_GET_BIT(DIO_PIND_REG,(Copy_u8PinNB-DIO_u8_PIN_NO_24));
		}
	}
	else
	{
		Local_u8Error = STD_u8_ERROR_NOK;
	}

	/*Function Return*/
	return Local_u8Error;
}



/****************************************************************/
/* Description : Set Port Direction to OUT or IN 				*/
/* Inputs:	Copy_u8PortNB		:	Port Number							*/
/* 			Copy_u8Direction	:	DIO_u8_PORT_OUTPUT or DIO_u8_PORT_INPUT or any 8bit direction*/
/* Outputs: Error State											*/
/****************************************************************/
u8 DIO_u8SetPortDirection(u8 Copy_u8PortNB,u8 Copy_u8Direction)
{
	/*Logical Variable*/
	u8 Local_u8Error=STD_u8_ERROR_OK;

	if(Copy_u8PortNB < DIO_MAXPPORTNB)
	{
				if( Copy_u8PortNB == DIO_u8_PORT0)
				{
					BITCALC_ASS_PORT(DIO_DDRA_REG,Copy_u8Direction);
				}
				else if ( Copy_u8PortNB == DIO_u8_PORT1 )
				{
					BITCALC_ASS_PORT(DIO_DDRB_REG,Copy_u8Direction);
				}
				else if ( Copy_u8PortNB == DIO_u8_PORT2 )
				{
					BITCALC_ASS_PORT(DIO_DDRC_REG,Copy_u8Direction);
				}
				else if ( Copy_u8PortNB == DIO_u8_PORT3 )
				{
					BITCALC_ASS_PORT(DIO_DDRD_REG,Copy_u8Direction);
				}
	}
	else
	{
		Local_u8Error = STD_u8_ERROR_NOK;
	}

	/*Function Return*/
	return Local_u8Error;
}





/****************************************************************/
/* Description : Set Port Value  				*/
/* Inputs:	Copy_u8PortNB		:	Port Number							*/
/* 			Copy_u8Value	:	DIO_u8_PORT_HIGH or DIO_u8_PORT_LOW or any 8bit VALUE*/
/* Outputs: Error State											*/
/****************************************************************/
u8 DIO_u8SetPortValue(u8 Copy_u8PortNB,u8 Copy_u8Value)
{
	/*Logical Variable*/
	u8 Local_u8Error=STD_u8_ERROR_OK;

	if(Copy_u8PortNB < DIO_MAXPPORTNB)
	{
				if( Copy_u8PortNB == DIO_u8_PORT0)
				{
					BITCALC_ASS_PORT(DIO_PORTA_REG,Copy_u8Value);
				}
				else if ( Copy_u8PortNB == DIO_u8_PORT1 )
				{
					BITCALC_ASS_PORT(DIO_PORTB_REG,Copy_u8Value);
				}
				else if ( Copy_u8PortNB == DIO_u8_PORT2 )
				{
					BITCALC_ASS_PORT(DIO_PORTC_REG,Copy_u8Value);
				}
				else if ( Copy_u8PortNB == DIO_u8_PORT3 )
				{
					BITCALC_ASS_PORT(DIO_PORTD_REG,Copy_u8Value);
				}
	}
	else
	{
		Local_u8Error = STD_u8_ERROR_NOK;
	}

	/*Function Return*/
	return Local_u8Error;
}




/****************************************************************/
/* Description : get Port value 				*/
/* Inputs:	Copy_u8PortNB		:	Port Number							*/
/* 			Copy_u8Value	:	DIO_u8_PORT_HIGH or DIO_u8_PORT_LOW or any 8bit VALUE*/
/* Outputs: Error State											*/
/****************************************************************/
u8 DIO_u8GetPortValue(u8 Copy_u8PortNB,u8* Copy_Pu8Value)
{
	/*Logical Variable*/
	u8 Local_u8Error=STD_u8_ERROR_OK;

	if(Copy_u8PortNB < DIO_MAXPPORTNB)
	{
				if( Copy_u8PortNB == DIO_u8_PORT0)
				{
					BITCALC_GET_PORT(DIO_PINA_REG,*Copy_Pu8Value);
				}
				else if ( Copy_u8PortNB == DIO_u8_PORT1 )
				{
					BITCALC_GET_PORT(DIO_PINB_REG,*Copy_Pu8Value);
				}
				else if ( Copy_u8PortNB == DIO_u8_PORT2 )
				{
					BITCALC_GET_PORT(DIO_PINC_REG,*Copy_Pu8Value);
				}
				else if ( Copy_u8PortNB == DIO_u8_PORT3 )
				{
					BITCALC_GET_PORT(DIO_PIND_REG,*Copy_Pu8Value);
				}
	}
	else
	{
		Local_u8Error = STD_u8_ERROR_NOK;
	}

	/*Function Return*/
	return Local_u8Error;
}




/****************************************************************/
/* Description : Set Direction & Port Values to specific value	*/
/****************************************************************/
void DIO_voidinit(void)
{
	DDRA->ByteAccess=BITCALC_CONC_8BIT(DIO_PIN00_INIT_DIR,DIO_PIN01_INIT_DIR,DIO_PIN02_INIT_DIR,DIO_PIN03_INIT_DIR,
								DIO_PIN04_INIT_DIR,DIO_PIN05_INIT_DIR,DIO_PIN06_INIT_DIR,DIO_PIN07_INIT_DIR);

	DDRB->ByteAccess=BITCALC_CONC_8BIT(DIO_PIN08_INIT_DIR,DIO_PIN09_INIT_DIR,DIO_PIN10_INIT_DIR,DIO_PIN11_INIT_DIR,
								DIO_PIN12_INIT_DIR,DIO_PIN13_INIT_DIR,DIO_PIN14_INIT_DIR,DIO_PIN15_INIT_DIR);

	DDRC->ByteAccess=BITCALC_CONC_8BIT(DIO_PIN16_INIT_DIR,DIO_PIN17_INIT_DIR,DIO_PIN18_INIT_DIR,DIO_PIN19_INIT_DIR,
								DIO_PIN20_INIT_DIR,DIO_PIN21_INIT_DIR,DIO_PIN22_INIT_DIR,DIO_PIN23_INIT_DIR);

	DDRD->ByteAccess=BITCALC_CONC_8BIT(DIO_PIN24_INIT_DIR,DIO_PIN25_INIT_DIR,DIO_PIN26_INIT_DIR,DIO_PIN27_INIT_DIR,
								DIO_PIN28_INIT_DIR,DIO_PIN29_INIT_DIR,DIO_PIN30_INIT_DIR,DIO_PIN31_INIT_DIR);


	PORTA->ByteAccess=BITCALC_CONC_8BIT(DIO_PIN00_INIT_VALUE,DIO_PIN01_INIT_VALUE,DIO_PIN02_INIT_VALUE,DIO_PIN03_INIT_VALUE,
								DIO_PIN04_INIT_VALUE,DIO_PIN05_INIT_VALUE,DIO_PIN06_INIT_VALUE,DIO_PIN07_INIT_VALUE);

	PORTB->ByteAccess=BITCALC_CONC_8BIT(DIO_PIN08_INIT_VALUE,DIO_PIN09_INIT_VALUE,DIO_PIN10_INIT_VALUE,DIO_PIN11_INIT_VALUE,
								DIO_PIN12_INIT_VALUE,DIO_PIN13_INIT_VALUE,DIO_PIN14_INIT_VALUE,DIO_PIN15_INIT_VALUE);

	PORTC->ByteAccess=BITCALC_CONC_8BIT(DIO_PIN16_INIT_VALUE,DIO_PIN17_INIT_VALUE,DIO_PIN18_INIT_VALUE,DIO_PIN19_INIT_VALUE,
								DIO_PIN20_INIT_VALUE,DIO_PIN21_INIT_VALUE,DIO_PIN22_INIT_VALUE,DIO_PIN23_INIT_VALUE);

	PORTD->ByteAccess=BITCALC_CONC_8BIT(DIO_PIN24_INIT_VALUE,DIO_PIN25_INIT_VALUE,DIO_PIN26_INIT_VALUE,DIO_PIN27_INIT_VALUE,
								DIO_PIN28_INIT_VALUE,DIO_PIN29_INIT_VALUE,DIO_PIN30_INIT_VALUE,DIO_PIN31_INIT_VALUE);



	/* validate the initialization values of all PINs when set its direction as input */

	  #if (( DIO_PIN00_INIT_DIR == DIO_u8_PIN_INIT_INPUT)&&( DIO_PIN00_INIT_VALUE == DIO_u8_PIN_INIT_HIGH))
	    #warning "this pin direction is INPUT & you set it as HIGH so it will automatically be set as LOW"
	    #undef  DIO_PIN00_INIT_VALUE
	    #define DIO_PIN00_INIT_VALUE  DIO_u8_PIN_INIT_DEF
	  #endif
}
