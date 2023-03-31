/*
 * Seven_seg.c
 *
 *  Created on: Oct 12, 2022
 *      Author: tarek
 */

#include "Seven_seg.h"
#include "../MCAL/gpio.h"
#include "../mcu_config/private.h"
void SEVEN_seg_init(void)
{

	GPIO_setupPinDirection(PORTC_ID, PIN6_ID, PIN_OUTPUT);

	GPIO_setupPinDirection(PORTA_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID, PIN2_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID, PIN3_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID, PIN4_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID, PIN5_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID, PIN6_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTA_ID, PIN7_ID, PIN_OUTPUT);

	GPIO_writePin(PORTC_ID, PIN6_ID, LOGIC_HIGH);

	GPIO_writePin(PORTA_ID, PIN1_ID, LOGIC_LOW);
	GPIO_writePin(PORTA_ID, PIN2_ID, LOGIC_LOW);
	GPIO_writePin(PORTA_ID, PIN3_ID, LOGIC_LOW);
	GPIO_writePin(PORTA_ID, PIN4_ID, LOGIC_LOW);
	GPIO_writePin(PORTA_ID, PIN5_ID, LOGIC_LOW);
	GPIO_writePin(PORTA_ID, PIN6_ID, LOGIC_LOW);
}

void SEVEN_seg_display_num(uint8 num)
{
	uint8 arr_num[10]={0x7E,0x0C,0xb6,0x9E,0xcc,0xda,0xfa,0x0e,0xFE,0xdE};

	PORTA = (PORTA & 0x01 ) | (arr_num[num]);
}


