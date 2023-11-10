/*
 ===================================================
 Author    : Abdel Rhman Helal Saleh
 File Name : dc_motor.c
 Data      : Oct 8, 2023
 Time      : 8:41:00 PM
 ===================================================
 */
#include "dc_motor.h"

#include "../../mcal/gpio/gpio.h"
#include "../../mcal/pwm/pwm.h"
#include "../../lib/common_macros.h"

/*
 * Description
 ➢ The Function responsible for setup the direction for the two
 motor pins through the GPIO driver.
 ➢ Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void) {
	/*out pin*/
	GPIO_setupPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN0, PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_PORT, DC_MOTOR_PIN1, PIN_OUTPUT);
	/*Stop*/
	GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN0, LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOGIC_LOW);
}

/*
 * Description:
 ➢ The function responsible for rotate the DC Motor CW/ or A-CW or
 stop the motor based on the state input state value.
 ➢ Send the required duty cycle to the PWM driver based on the
 required speed value.
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed) {
	uint8 duty_cycle;
	/*to get state*/
	switch (state) {
	case off:
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN0, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOGIC_LOW);
		break;
	case CW:
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN0, LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOGIC_LOW);
		break;
	case A_CW:
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN0, LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_PORT, DC_MOTOR_PIN1, LOGIC_HIGH);
		break;
	default:
		break;
	}
	/*Speed*/
	if (speed > 100) {
		speed = 100;
	}
	if (speed < 0) {
		speed = 0;
	}
	duty_cycle = ((float32) speed / 100) * REG_TIMER_0_SIZE;
	PWM_Timer0_Start(duty_cycle);

}
