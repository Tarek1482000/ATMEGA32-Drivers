/******************************************************************************
 *
 * Module: RTOS Private
 *
 * File Name: RTOS_private.h
 *
 * Description: Header file for the RTOS Private driver
 *
 * Author: Tarek Ahmed
 *
 *******************************************************************************/

#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

typedef struct
{
	uint16 periodicity;
	void(*TaskFunc)(void);
}Task_t;

static void voidScheduler(void);


#endif /* RTOS_PRIVATE_H_ */
