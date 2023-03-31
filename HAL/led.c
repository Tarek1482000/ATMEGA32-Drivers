 /******************************************************************************
 *
 * Module: Led
 *
 * File Name: led.c
 *
 * Description: Source file for the led driver
 *
 * Author: Tarek Ahmed
 *
 *******************************************************************************/
#include "../MCAL/gpio.h"
#include "led.h"

void LED_init(LED_PORT port, LED_PIN pin)
{
	GPIO_setupPinDirection(port, pin, PIN_OUTPUT);
}


void LED_on(LED_PORT port, LED_PIN pin)
{
	GPIO_writePin(port, pin, LOGIC_HIGH);
}

void LED_off(LED_PORT port, LED_PIN pin)
{
	GPIO_writePin(port, pin, LOGIC_LOW);
}

void LED_toggle(LED_PORT port, LED_PIN pin)
{
	GPIO_togglePin(port, pin);
}
