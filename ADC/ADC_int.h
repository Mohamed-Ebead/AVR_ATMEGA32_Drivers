/*
 * ADC_int.h
 *
 *  Created on: Sep 7, 2019
 *      Author: Mohamed_Ebead
 */

#ifndef ADC_INT_H_
#define ADC_INT_H_



/***********************************************/

// ADC Initialization And Enable
void ADC_Init (void);

/***********************************************/

// Read From The ADC Channel
u16 ADC_Read (u8);

/***********************************************/

u8 ADC_GetAdcBlocking (u8 copu_channelNB , u8 * copy_channelNB) ;

/***********************************************/

void vid_SeparateResult(u32 Result , u8 * u8ArrayResult) ;

/***********************************************/




#endif /* ADC_INT_H_ */
