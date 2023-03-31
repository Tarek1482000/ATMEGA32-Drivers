/*
 * Seven_seg.c
 *
 *  Created on: Oct 12, 2022
 *      Author: tarek
 */

#include "Seven_seg_dec.h"
#include "../MCAL/gpio.h"
#include "../mcu_config/private.h"
void SEVEN_seg_dec_init(void)
{

	GPIO_setupPinDirection(PORTC_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID, PIN2_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTC_ID, PIN3_ID, PIN_OUTPUT);

	GPIO_writePin(PORTC_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_writePin(PORTC_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_writePin(PORTC_ID, PIN2_ID, PIN_OUTPUT);
	GPIO_writePin(PORTC_ID, PIN3_ID, PIN_OUTPUT);

}

void SEVEN_seg_dec_display_num(uint8 num)
{
	if(num<10 && num>=0)
		PORTC = (PORTC & 0xf0 ) | (num & 0x0f);
}


