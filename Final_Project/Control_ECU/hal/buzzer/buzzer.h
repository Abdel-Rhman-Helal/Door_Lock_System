/*
 ===================================================
 Author    : Abdel Rhman Helal Saleh
 File Name : buzzer.h
 Data      : Oct 22, 2023
 Time      : 4:45:27 PM
 ===================================================
 */

#ifndef HAL_BUZZER_BUZZER_H_
#define HAL_BUZZER_BUZZER_H_

#include "../../lib/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define BUZZER_PORT PORTC_ID
#define BUZZER_PIN  PIN5_ID
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description
 ⮚ Setup the direction for the buzzer pin as output pin through the
 GPIO driver.
 ⮚ Turn off the buzzer through the GPIO.*/
void Buzzer_init();
/*
 * Description
 ⮚ Function to enable the Buzzer through the GPIO*/
void Buzzer_on();
/*
 * Description
 ⮚ Function to disable the Buzzer through the GPIO.
 */
void Buzzer_off(void);

#endif /* HAL_BUZZER_BUZZER_H_ */
