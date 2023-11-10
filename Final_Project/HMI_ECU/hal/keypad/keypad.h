/*
 ===================================================
 Author    : Abdel Rhman Helal Saleh
 File Name : keypad.h
 Data      : Oct 7, 2023
 Time      : 1:40:08 PM
 ===================================================
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

#include "../../lib/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define KEYPAD_NUM_COLS                   4
#define KEYPAD_NUM_ROWS                   4

/* Keypad Port Configurations */
#define KEYPAD_ROW_PORT_ID                PORTB_ID
#define KEYPAD_FIRST_ROW_PIN_ID           PIN4_ID

#define KEYPAD_COL_PORT_ID                PORTD_ID
#define KEYPAD_FIRST_COL_PIN_ID           PIN2_ID

/* Keypad button logic configurations */
#define KEYPAD_BUTTON_PRESSED            LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED           LOGIC_HIGH

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Get the Keypad pressed button
 */
uint8 KEYPAD_getPressedKey(void);

#endif /* HAL_KEYPAD_KEYPAD_H_ */
