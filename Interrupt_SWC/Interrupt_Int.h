/*
 * Interrupt_Int.h
 *
 *  Created on: Nov 19, 2018
 *      Author: werby
 */

#ifndef INTERRUPT_INT_H_
#define INTERRUPT_INT_H_


#define low_level 0
#define logical_Change 1
#define Falling_Edge 2
#define Rising_Edge 3

void INT0_init( u8 INT_MODE , void (*func)(void) );
void INT1_init( u8 INT_MODE , void (*func)(void) );
void INT2_init( u8 INT_MODE , void (*func)(void) );

#endif /* INTERRUPT_INT_H_ */
