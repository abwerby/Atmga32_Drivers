/*
 * UART_reg.h
 *
 *  Created on: Nov 24, 2018
 *      Author: WERBY
 */

#ifndef UART_REG_H_
#define UART_REG_H_

#define UCSRA (*(volatile u8*)0x2B)
#define UCSRB (*(volatile u8*)0x2A)
#define UDR   (*(volatile u8*)0x2C)
#define UCSRC (*(volatile u8*)0x40)
#define UBRRH (*(volatile u8*)0x40)
#define UBRRL (*(volatile u8*)0x29)

#define RXC   7
#define UDRE  5
#define RXEN  4
#define TXEN  3
#define UCSZ2 2

/* UCSRC Register PINS */
#define UMSEL 6
#define UPM0  4
#define UPM1  5
#define USBS  3
#define UCSZ0 1
#define UCSZ1 2










#endif /* UART_REG_H_ */
