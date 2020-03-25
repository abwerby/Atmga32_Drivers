/*
 * UART_prog.c
 *
 *  Created on: Nov 24, 2018
 *      Author: WERBY
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "UART_reg.h"
#include "UART_int.h"


void UART_vidInit(u16 UBRR)
{


	/* DOUBLE SPEED */
	//SET_BIT(UCSRA,U2X);

	/* ENABLE RECEVIER */
	SET_BIT(UCSRB,RXEN);

	/* ENABLE TRANSMITER */
	SET_BIT(UCSRB,TXEN);

	/* CLEAR BIT UCSZ2 TO SET 8 BIT */
	CLR_BIT(UCSRB,UCSZ2);

	/* Asynchronous MODE */
	CLR_BIT(UCSRC,UMSEL);

	/* Parity Disabled */
	CLR_BIT(UCSRC,UPM0);
	CLR_BIT(UCSRC,UPM1);

	/* ONE BIT STOP */
	CLR_BIT(UCSRC,USBS);

	/* SET BIT UCSZ0 , UCSZ1  TO SET 8 BIT */
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);

	/* BUAD RATE SET*/
	UBRRH = (u8)(UBRR>>8);
	UBRRL = (u8)UBRR;


}


void UART_vidSendChar(u8 u8DataSend)
{
	/* WAIT TELL TX BUFFER IS EMPTY */
	while(GET_BIT(UCSRA,UDRE) == 0);

	/* SET DATA REGSITER WITH DATA TO SEND */
	UDR = u8DataSend ;
}


u8 UART_u8GetChar(void)
{
	/* WAIT TILL A VAILD BYTE AVALIBLE INSIDE RX BUFFER  */
	while(GET_BIT(UCSRA,RXC) == 0 );
	/* RETURN BYTE RECIVED */
	return UDR ;
}


void UART_vidSendString(u8 *str)
{
	while(*str != '\0')
	{
		UART_vidSendChar(*str);
		str++;
	}
}

void UART_vidSendNumber(long long Number)
{
	long long Temp =1;

	if (Number == 0)
	{
		UART_vidSendChar('0');
	}
	else
	{
		while (Number!=0)
		{
			u8 Reminder = Number % 10;
			Number = Number / 10 ;
			Temp = Temp * 10 + Reminder ;
		}
		while (Temp != 1)
		{
			u8 Reminder2 = Temp % 10 ;
			UART_vidSendChar(Reminder2+48);
			Temp = Temp / 10 ;
		}
	}
}


void UART_VidReceiveString(u8 *str)
{
	u8 i = 0;
	str[i] = UART_u8GetChar();
	while(str[i] != '#')
	{
		i++;
		str[i] = UART_u8GetChar();
	}
	str[i] = '\0';
}
