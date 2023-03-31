 /******************************************************************************
 *
 * Module: Led
 *
 * File Name: led.h
 *
 * Description: Header file for the led driver
 *
 * Author: Tarek Ahmed
 *
 *******************************************************************************/

#ifndef HAL_LED_H_
#define HAL_LED_H_


typedef enum
{
	LED_PORTA,
	LED_PORTB,
	LED_PORTC,
	LED_PORTD,
}LED_PORT;

typedef enum
{
	LED_PIN0,
	LED_PIN1,
	LED_PIN2,
	LED_PIN3,
	LED_PIN4,
	LED_PIN5,
	LED_PIN6,
	LED_PIN7
}LED_PIN;

void LED_init(LED_PORT , LED_PIN);


void LED_on(LED_PORT port, LED_PIN pin);

void LED_off(LED_PORT port, LED_PIN pin);

void LED_toggle(LED_PORT port, LED_PIN pin);

#endif /* HAL_LED_H_ */
