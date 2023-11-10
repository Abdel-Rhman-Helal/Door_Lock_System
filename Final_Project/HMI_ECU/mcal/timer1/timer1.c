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
		TCCR1A_REG.Bits.FOC1A_BIT = 1;
		TCCR1A_REG.Bits.FOC1B_BIT = 1;
		TIMSK_REG.Bits.TOIE1_BIT = 1;
		break;
	case Timer1_Mode_1_PWM_Phase_Correct_8bit:
		TCCR1A_REG.Bits.WGM10_BIT = 1;
		break;
	case Timer1_Mode_2_PWM_Phase_Correct_9bit:
		TCCR1A_REG.Bits.WGM11_BIT = 1;
		break;
	case Timer1_Mode_3_PWM_Phase_Correct_10bit:
		TCCR1A_REG.Bits.WGM10_BIT = 1;
		TCCR1A_REG.Bits.WGM11_BIT = 1;
		break;
	case Timer1_Mode_4_CTC:
		TCCR1A_REG.Bits.FOC1A_BIT = 1;
		TCCR1A_REG.Bits.FOC1B_BIT = 1;
		TCCR1B_REG.Bits.WGM12_BIT = 1;
		TIMSK_REG.Bits.OCIE1A_BIT = 1;

		OCR1A_REG = Config_Ptr->compare_value;
		break;
	case Timer1_Mode_5_Fast_PWM_8bit:
		TCCR1A_REG.Bits.WGM10_BIT = 1;
		TCCR1B_REG.Bits.WGM12_BIT = 1;
		break;
	case Timer1_Mode_6_Fast_PWM_9bit:
		TCCR1A_REG.Bits.WGM11_BIT = 1;
		TCCR1B_REG.Bits.WGM12_BIT = 1;
		break;
	case Timer1_Mode_7_Fast_PWM_10bit:
		TCCR1A_REG.Bits.WGM10_BIT = 1;
		TCCR1A_REG.Bits.WGM11_BIT = 1;
		TCCR1B_REG.Bits.WGM12_BIT = 1;
		break;
	case Timer1_Mode_8_PWM_Phase_and_Frequency:
		TCCR1B_REG.Bits.WGM13_BIT = 1;
		ICR1_REG = Config_Ptr->compare_value;
		break;
	case Timer1_Mode_9_PWM_Phase_and_Frequency:
		TCCR1A_REG.Bits.WGM10_BIT = 1;
		TCCR1B_REG.Bits.WGM13_BIT = 1;
		OCR1A_REG = Config_Ptr->compare_value;
		break;
	case Timer1_Mode_10_PWM_Phase_Correct:
		TCCR1A_REG.Bits.WGM11_BIT = 1;
		TCCR1B_REG.Bits.WGM13_BIT = 1;
		ICR1_REG = Config_Ptr->compare_value;
		break;
	case Timer1_Mode_11_PWM_Phase_Correct:
		TCCR1A_REG.Bits.WGM10_BIT = 1;
		TCCR1A_REG.Bits.WGM11_BIT = 1;
		TCCR1B_REG.Bits.WGM13_BIT = 1;
		OCR1A_REG = Config_Ptr->compare_value;
		break;
	case Timer1_Mode_12_CTC:
		TCCR1B_REG.Bits.WGM12_BIT = 1;
		TCCR1B_REG.Bits.WGM13_BIT = 1;
		ICR1_REG = Config_Ptr->compare_value;
		break;
	case Timer1_Mode_13_Reserved:
		TCCR1A_REG.Bits.WGM10_BIT = 1;
		TCCR1B_REG.Bits.WGM12_BIT = 1;
		TCCR1B_REG.Bits.WGM13_BIT = 1;
		break;
	case Timer1_Mode_14_Fast_PWM:
		TCCR1A_REG.Bits.WGM11_BIT = 1;
		TCCR1B_REG.Bits.WGM12_BIT = 1;
		TCCR1B_REG.Bits.WGM13_BIT = 1;
		ICR1_REG = Config_Ptr->compare_value;
		break;
	case Timer1_Mode_15_Fast_PWM:
		TCCR1A_REG.Bits.WGM10_BIT = 1;
		TCCR1A_REG.Bits.WGM11_BIT = 1;
		TCCR1B_REG.Bits.WGM12_BIT = 1;
		TCCR1B_REG.Bits.WGM13_BIT = 1;
		OCR1A_REG = Config_Ptr->compare_value;
		break;
	default:
		break;
	}
	TIMSK_REG.Bits.OCIE1A_BIT = 1; /* Enable compare interrupt for channel A */

	/*Clock*/
	TCCR1B_REG.Bits.CS10_11_12_BITS = (Config_Ptr->prescaler);
}
/*Description
 Function to disable the Timer1.*/
void Timer1_deInit(void) {
	TCNT1_REG = 0;
	TCCR1A_REG.Byte = 0x00;
	TCCR1B_REG.Byte = 0x00;
	TIMSK_REG.Byte = 0x00;
	OCR1A_REG = 0;
	OCR1B_REG = 0;
	ICR1_REG = 0;
}
/*Description
 Function to set the Call Back function address.*/
void Timer1_setCallBack(void (*a_ptr)(void)) {
	g_callBackPtr = a_ptr;
}
