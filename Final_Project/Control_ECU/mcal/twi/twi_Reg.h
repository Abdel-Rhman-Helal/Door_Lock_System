/*
 ===================================================
 Author    : Abdel Rhman Helal Saleh
 File Name : twi_Reg.h
 Data      : Oct 22, 2023
 Time      : 8:57:19 PM
 ===================================================
 */

#ifndef MCAL_TWI_TWI_REG_H_
#define MCAL_TWI_TWI_REG_H_

#include "../../lib/std_types.h"
/*******************************************************************************
 *                                Registers                                    *
 *******************************************************************************/
typedef union {
	uint8 Byte;
	struct {
		uint8 TWIE :1;
		uint8 :1;
		uint8 TWEN :1;
		uint8 TWWC :1;
		uint8 TWSTO :1;
		uint8 TWSTA :1;
		uint8 TWEA :1;
		uint8 TWINT :1;
	} Bits;
} TWI_TWCR_Register;
typedef union {
	uint8 Byte;
	struct {
		uint8 TWPS01 :2;
		uint8 :1;
		uint8 TWS3_7 :5;
	} Bits;
} TWI_TWSR_Register;
typedef union {
	uint8 Byte;
	struct {
		uint8 TWGCE :1;
		uint8 TWA0_6 :7;
	} Bits;
} TWI_TWAR_Register;

/*******************************************************************************
 *                             Definitions                                      *
 *******************************************************************************/
#define TWBR  (*(volatile   uint8*)0x20)
#define TWCR  (*(volatile   TWI_TWCR_Register*)0x56)
#define TWDR  (*(volatile   uint8*)0x23)
#define TWSR  (*(volatile   uint8*)0x21)
#define TWAR  (*(volatile   TWI_TWAR_Register*) 0x22)

#endif /* MCAL_TWI_TWI_REG_H_ */
