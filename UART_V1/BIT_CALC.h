/*
 * BIT_MATH.h
 *
 *  Created on: Aug 17, 2019
 *      Author: Ahmed
 */

#ifndef BIT_CALC_H_
#define BIT_CALC_H_


#define SET_BIT(VAR,BIT_NB) (VAR) |=  (1 << (BIT_NB))
#define CLR_BIT(VAR,BIT_NB) (VAR) &= ~(1 << (BIT_NB))
#define TOG_BIT(VAR,BIT_NB) (VAR) ^=  (1 << (BIT_NB))
#define GET_BIT(VAR,BIT_NB) (((VAR) >> (BIT_NB)) & 0x01)


#endif /* BIT_CALC_H_ */
