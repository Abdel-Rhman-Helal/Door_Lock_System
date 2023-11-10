/*
 ===================================================
 Author    : Abdel Rhman Helal Saleh
 File Name : dc_motor.h
 Data      : Oct 8, 2023
 Time      : 8:41:11 PM
 ===================================================
 */

#ifndef HAL_DCMOTOR_DC_MOTOR_H_
#define HAL_DCMOTOR_DC_MOTOR_H_

#include "../../lib/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DC_MOTOR_PORT PORTB_ID
#define DC_MOTOR_PIN0 PIN0_ID
#define DC_MOTOR_PIN1 PIN1_ID

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum {
	off, CW, A_CW
} DcMotor_State;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*Function responsible for setup the direction for the two*/
void DcMotor_Init(void);

/*function responsible for rotate the DC Motor CW/ or A-CW or
 stop the motor based on the state input state value
 Send the required duty cycle to the PWM driver based on the
 required speed value*/
void DcMotor_Rotate(DcMotor_State state, uint8 speed);
#endif /* HAL_DCMOTOR_DC_MOTOR_H_ */
