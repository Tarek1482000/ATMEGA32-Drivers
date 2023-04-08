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
	uint16 FirstDelay;
	void(*TaskFunc)(void);
	uint8 state;
}Task_t;

static void voidScheduler(void);

#define TASK_RESUMED    (0u)
#define TASK_SUSPENDED  (1u)

#endif /* RTOS_PRIVATE_H_ */
