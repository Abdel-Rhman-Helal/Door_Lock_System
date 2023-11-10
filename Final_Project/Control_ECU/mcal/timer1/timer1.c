/*
 ===================================================
 Author    : Abdel Rhman Helal Saleh
 File Name : timer1.c
 Data      : Oct 23, 2023
 Time      : 12:51:28 PM
 ===================================================
 */
#include "timer1.h"

#include <avr/interrupt.h> /* For ICU ISR */

#include "timer1_Reg.h"
/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
/* Global variables to hold the address of the call back function in the application */
static volatile void (*g_callBackPtr)(void) = NULL_PTR;
/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/
/* Normal mode ISR */
ISR(TIMER1_OVF_vect) {
	if (g_callBackPtr != NULL_PTR) {
		(*g_callBackPtr)();
	}
}

/* Compare mode ISR */
ISR(TIMER1_COMPA_vect) {
	if (g_callBackPtr != NULL_PTR) {
		(*g_callBackPtr)();
	}
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
/* Description
 Function to initialize the Timer driver */
void Timer1_init(const Timer1_ConfigType *Config_Ptr) {
	TCNT1_REG = (Config_Ptr->initial_value);
	switch ((Config_Ptr->mode)) {
	case Timer1_Mode_0_Normal:
		/*NO PWM*/
		TCCR1A_REG.Bits.FOC1A_BIT = 1;
		TCCR1A_REG.Bits.FOC1B_BIT = 1;
		/*TOIE1 Interput enable*/
		TIMSK_REG.Bits.TOIE1_BIT = 1;
		break;
	case Timer1_Mode_4_CTC:
		/*NO PWM*/
		TCCR1A_REG.Bits.FOC1A_BIT = 1;
		TCCR1A_REG.Bits.FOC1B_BIT = 1;
		/*CTC MODE*/
		TCCR1B_REG.Bits.WGM12_BIT = 1;
		/*OCIE1A Interput enable*/
		TIMSK_REG.Bits.OCIE1A_BIT = 1;
		/*Set the compere value*/
		OCR1A_REG = Config_Ptr->compare_value;
		break;
	default:
		break;
	}
	/*Clock*/
	TCCR1B_REG.Bits.CS10_11_12_BITS = (Config_Ptr->prescaler);
}
/*Description
 Function to disable the Timer1.*/
void Timer1_deInit(void) {
	/*Set all values*/
	TCNT1_REG = 0;
	TCCR1A_REG.Byte = 0x00;
	TCCR1B_REG.Byte = 0x00;
	TIMSK_REG.Byte = 0x00;
	OCR1A_REG = 0;
	OCR1B_REG = 0;
	ICR1_REG = 0;
	g_callBackPtr = NULL_PTR;

}
/*Description
 Function to set the Call Back function address.*/
void Timer1_setCallBack(void (*a_ptr)(void)) {
	g_callBackPtr = a_ptr;
}
