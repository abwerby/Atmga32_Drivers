/*
 * Interrupt_Prog.c
 *
 *  Created on: Nov 19, 2018
 *      Author: werby
 */

#include "avr/io.h"
#include "avr/interrupt.h"
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "Interrupt_Int.h"



void (*func_INT0)();
void (*func_INT1)();
void (*func_INT2)();



void INT0_init( u8 INT_MODE , void (*func)(void) )
{
	SET_BIT(SREG,7);

	func_INT0 = func ;

	SET_BIT(GICR,6);

	if(INT_MODE == low_level)
	{
		CLR_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
	}
	else if(INT_MODE == logical_Change)
	{
		SET_BIT(MCUCR,0);
		CLR_BIT(MCUCR,1);
	}
	else if(INT_MODE == Falling_Edge)
	{
		CLR_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
	}
	else if(INT_MODE == Rising_Edge)
	{
		SET_BIT(MCUCR,0);
		SET_BIT(MCUCR,1);
	}
	else
	{
		/* DO NOTHING */
	}
}

void INT1_init( u8 INT_MODE , void (*func)(void) )
{
	SET_BIT(SREG,7);

	func_INT1 = func ;

	SET_BIT(GICR,7);

	if(INT_MODE == low_level)
	{
		CLR_BIT(MCUCR,2);
		CLR_BIT(MCUCR,3);
	}
	else if(INT_MODE == logical_Change)
	{
		SET_BIT(MCUCR,2);
		CLR_BIT(MCUCR,3);
	}
	else if(INT_MODE == Falling_Edge)
	{
		CLR_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
	}
	else if(INT_MODE == Rising_Edge)
	{
		SET_BIT(MCUCR,2);
		SET_BIT(MCUCR,3);
	}
	else
	{
		/* DO NOTHING */
	}
}

void INT2_init( u8 INT_MODE , void (*func)(void) )
{
	SET_BIT(SREG,7);

	func_INT2 = func ;

	SET_BIT(GICR,5);

	if(INT_MODE == Falling_Edge)
	{
		CLR_BIT(MCUCSR,6);
	}
	else if(INT_MODE == Rising_Edge)
	{
		SET_BIT(MCUCSR,6);
	}

	else
	{
		/* DO NOTHING */
	}
}



ISR(INT0_vect)
{
	func_INT0();
}

ISR(INT1_vect)
{
	func_INT1();
}

ISR(INT2_vect)
{
	func_INT2();
}
