/******************************************************************************
 *
 * Module: RTOS Timer0
 *
 * File Name: RTOS_Timer0.c
 *
 * Description: Source file for the RTOS Timer0 driver
 *
 * Author: Tarek Ahmed
 *
 *******************************************************************************/

#include "../../MCAL/gpio.h"
#include "../../mcu_config/common_macros.h"
#include "../../mcu_config/private.h"
#include <avr/interrupt.h>
#include "RTOS_timer0.h"

static volatile void (*g_callBackPtr0)(void) = NULL_PTR;



ISR(TIMER0_COMP_vect)
{
	if(g_callBackPtr0 != NULL_PTR)
	{
		(*g_callBackPtr0)();
	}
}





void Timer0_init(void)
{
	TCNT0 = 0;
	OCR0  = COMP_VALUE;

	/* Compare Mode */
	SET_BIT(TCCR0,WGM01);
	CLEAR_BIT(TCCR0,WGM00);

	/* Non PWM Mode */
	SET_BIT(TCCR0,FOC0);

	/* Enable Interrupt  */
	SET_BIT(TIMSK,OCIE0);

	/* Choose Prescaler */
	TCCR0 =(TCCR0 & 0xF8) | ((PRESCALER) & 0x07);
}





void Timer0_setCallBack(void(*a_ptr)(void))
{

	g_callBackPtr0=a_ptr;
}
