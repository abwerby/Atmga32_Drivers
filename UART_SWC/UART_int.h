/*
 * UART_int.h
 *
 *  Created on: Nov 24, 2018
 *      Author: WERBY
 */

#ifndef UART_INT_H_
#define UART_INT_H_

void UART_vidInit(u16 UBRR);
void UART_vidSendChar(u8 u8DataSend);
void UART_vidSendString(u8 *str);
void UART_vidSendNumber(long long Number);
void UART_VidReceiveString(u8 *str);
u8 UART_u8GetChar(void);



#endif /* UART_INT_H_ */
