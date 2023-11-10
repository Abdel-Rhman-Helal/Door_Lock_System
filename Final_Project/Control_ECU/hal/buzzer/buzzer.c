/*
 ===================================================
 Author    : Abdel Rhman Helal Saleh
 File Name : buzzer.c
 Data      : Oct 22, 2023
 Time      : 4:45:16 PM
 ===================================================
 */
#include "buzzer.h"

#include <util/delay.h>

#include "../../mcal/gpio/gpio.h"
/*
 * Description
 ⮚ Setup the direction for the buzzer pin as output pin through the
 GPIO driver.
 ⮚ Turn off the buzzer through the GPIO.*/
void Buzzer_init() {
	GPIO_setupPinDirection(BUZZER_PORT, BUZZER_PIN, PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_LOW);
}
/*
 * Description
 ⮚ Function to enable the Buzzer through the GPIO*/
void Buzzer_on() {
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_HIGH);
}
/*
 * Description
 ⮚ Function to disable the Buzzer through the GPIO.
 */
void Buzzer_off(void) {
	GPIO_writePin(BUZZER_PORT, BUZZER_PIN, LOGIC_LOW);

}

