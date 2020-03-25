/*
 * PWM_int.h
 *
 *  Created on: Nov 23, 2018
 *      Author: werby
 */

#ifndef PWM_INT_H_
#define PWM_INT_H_

#define OC1A 0
#define OC1B 1


#define TIMER_PRESCALER_1 1
#define TIMER_PRESCALER_8 2
#define TIMER_PRESCALER_64 3
#define TIMER_PRESCALER_256 4
#define TIMER_PRESCALER_1024 5


void Fast_PWM0_init(u8 prescaler , u8 value);
void Fast_PWM1_init(u8 prescaler , u16 value , u8 pin);



#endif /* PWM_INT_H_ */
