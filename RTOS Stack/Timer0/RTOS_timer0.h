/******************************************************************************
 *
 * Module: RTOS Timer0
 *
 * File Name: RTOS_timer0.h
 *
 * Description: header file for the RTOS Timer0 driver
 *
 * Author: Tarek Ahmed
 *
 *******************************************************************************/

#ifndef RTOS_TIMER0_H_
#define RTOS_TIMER0_H_

#include "../../mcu_config/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define COMP_VALUE        125

#define NO_CLOCK          0
#define NO_PRESCALER      1
#define PRESCALER_8       2
#define PRESCALER_64      3
#define PRESCALER_256     4
#define PRESCALER_1024    5


#define PRESCALER        PRESCALER_64

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/




/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/


/*
 * Setup Timer configuration
 */
void Timer0_init(void);




/*
 * Timer call back function
 */
void Timer0_setCallBack(void(*a_ptr)(void));


#endif /* RTOS_TIMER0_H_ */
