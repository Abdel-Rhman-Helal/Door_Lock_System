/*
 ===================================================
 Author    : Abdel Rhman Helal Saleh
 File Name : external_eeprom.h
 Data      : Oct 22, 2023
 Time      : 9:57:19 PM
 ===================================================
 */

#ifndef HAL_EEPROM_EXTERNAL_EEPROM_H_
#define HAL_EEPROM_EXTERNAL_EEPROM_H_

#include "../../lib/std_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 0
#define SUCCESS 1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

uint8 EEPROM_writeByte(uint16 u16addr, uint8 u8data);
uint8 EEPROM_readByte(uint16 u16addr, uint8 *u8data);

#endif /* HAL_EEPROM_EXTERNAL_EEPROM_H_ */
