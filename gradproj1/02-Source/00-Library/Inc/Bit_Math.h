/*
 * Bit_Math.h
 *
 *  Created on: 12þ/11þ/2021
 *      Author: Reem
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT_NO)    REG|=(1<<BIT_NO)
#define CLR_BIT(REG,BIT_NO)    REG&=~(1<<BIT_NO)
#define CHK_BIT(REG,BIT_NO)    ((REG>>BIT_NO)&0x01)
#define TOGGLE_BIT(REG,BIT_NO) REG^=(1<<BIT_NO)

long map(long x, long in_min, long in_max, long out_min, long out_max);


#endif /* BIT_MATH_H_ */
