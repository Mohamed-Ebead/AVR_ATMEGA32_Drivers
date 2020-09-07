/*
 * main.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Mohamed_Ebead
 */

#include "STD_Types.h"
#include"BIT_MATH.h"
#include <util/delay.h>


#include "DIO_int.h"

#include"STP_int.h"




void main(void){



	 DIO_SetPortDirection (PORTB,0xff);


while(1) {



	vid_Stepper();






}




}
