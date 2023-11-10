/*
 ===================================================
 Author    : Abdel Rhman Helal Saleh
 File Name : uart_Reg.h
 Data      : Oct 22, 2023
 Time      : 2:51:09 PM
 ===================================================
 */

#ifndef MCAL_UART_UART_REG_H_
#define MCAL_UART_UART_REG_H_

#include "../../lib/std_types.h"
/*******************************************************************************
 *                                Registers                                    *
 *******************************************************************************/
typedef union {
	uint8 Byte;
	struct {
		uint8 MPCM :1;
		uint8 U2X :1;
		uint8 PE :1;
		uint8 DOR :1;
		uint8 FE :1;
		uint8 UDRE :1;
		uint8 TXC :1;
		uint8 RXC :1;
	} Bits;
} UART_UCSRA_Register;
typedef union {
	uint8 Byte;
	struct {
		uint8 TXB8 :1;
		uint8 RXB8 :1;
		uint8 UCSZ2 :1;
		uint8 TXEN :1;
		uint8 RXEN :1;
		uint8 UDRIE :1;
		uint8 TXCIE :1;
		uint8 RXCIE :1;
	} Bits;
} UART_UCSRB_Register;
typedef union {
	uint8 Byte;
	struct {
		uint8 UCPOL :1;
		uint8 UCSZ01 :2;
		uint8 USBS :1;
		uint8 UPM01 :2;
		uint8 UMSEL :1;
		uint8 URSEL :1;
	} Bits;
} UART_UCSRC_Register;

/*******************************************************************************
 *                             Definitions                                      *
 *******************************************************************************/
#define UDR  (*(volatile   uint8*)0x2C)
#define UCSRA  (*(volatile   UART_UCSRA_Register*)0x2B)
#define UCSRB  (*(volatile   UART_UCSRB_Register*)0x2A)
#define UCSRC  (*(volatile   UART_UCSRC_Register*)0x40)
#define UBRRL  (*(volatile   uint8*) 0x29)
#define UBRRH  (*(volatile   uint8*)0x40)

#endif /* MCAL_UART_UART_REG_H_ */
