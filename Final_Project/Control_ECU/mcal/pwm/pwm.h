/*
 ===================================================
 Author    : Abdel Rhman Helal Saleh
 File Name : pwm.h
 Data      : Oct 8, 2023
 Time      : 9:08:38 PM
 ===================================================
 */

#ifndef MCAL_PWM_PWM_H_
#define MCAL_PWM_PWM_H_
#include "../../lib/std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define REG_TIMER_0_SIZE 255
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description:
 ➢ The function responsible for trigger the Timer0 with the PWM Mode.
 ➢ Setup the PWM mode with Non-Inverting.
 ➢ Setup the prescaler with F_CPU/8.
 ➢ Setup the compare value based on the required input duty cycle
 ➢ Setup the direction for OC0 as output pin through the GPIO driver.
 ➢ The generated PWM signal frequency will be 500Hz to control the DC
 Motor speed*/
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* MCAL_PWM_PWM_H_ */
