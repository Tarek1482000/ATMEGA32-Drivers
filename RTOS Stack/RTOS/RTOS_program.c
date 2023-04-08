/******************************************************************************
 *
 * Module: RTOS Program
 *
 * File Name: RTOS_program.c
 *
 * Description: Source file for the RTOS driver
 *
 * Author: Tarek Ahmed
 *
 *******************************************************************************/

#include "../../mcu_config/private.h"
#include "../Timer0/RTOS_timer0.h"
#include "RTOS_config.h"
#include "RTOS_private.h"
#include "RTOS_interface.h"


Task_t SystemTasks[TASK_NUM] = {{NULL}};


void RTOS_voidStarts(void)
{
	Timer0_setCallBack(&voidScheduler);
	sei()
	Timer0_init();
}

uint8 RTOS_voidCreateTask(uint8 u8Priority , uint16 u16Preodicity , void(*PvTaskFunc)(void) , uint16 u16FirstDelay)
{
	uint8 Local_u8ErorrState = OK ;

	/* Check if the required priority is empty or used before for another task*/

	if(SystemTasks[u8Priority].TaskFunc != NULL)
	{
		SystemTasks[u8Priority].periodicity = u16Preodicity;

		SystemTasks[u8Priority].TaskFunc = PvTaskFunc;

		SystemTasks[u8Priority].state = TASK_RESUMED;

		SystemTasks[u8Priority].FirstDelay = u16FirstDelay;
	}
	else
	{
		Local_u8ErorrState = NOK;
	}
	return Local_u8ErorrState;
}


void RTOS_voidSuspendTask(uint8 u8Priority)
{
	SystemTasks[u8Priority].state = TASK_SUSPENDED;
}

void RTOS_voidResumeTask(uint8 u8Priority)
{
	SystemTasks[u8Priority].state = TASK_RESUMED;
}

void RTOS_voidDeleteTask(uint8 u8Priority)
{
	SystemTasks[u8Priority].TaskFunc = NULL;
}

void voidScheduler(void)
{

	uint8 Local_u8TaskCounter;

	/* Loop on all tasks to check their Preodicity*/
	for(Local_u8TaskCounter=0 ;Local_u8TaskCounter < TASK_NUM ;Local_u8TaskCounter++)
	{
		/* Check if Task Suspended or not */
		if(SystemTasks[Local_u8TaskCounter].state == TASK_RESUMED)
		{
			if(SystemTasks[Local_u8TaskCounter].FirstDelay == 0)
			{
				if(SystemTasks[Local_u8TaskCounter].TaskFunc != NULL)
				{
					SystemTasks[Local_u8TaskCounter].TaskFunc();

					/* Assign the first delay parameter to the periodicity minus 1*/
					SystemTasks[Local_u8TaskCounter].FirstDelay = SystemTasks[Local_u8TaskCounter].periodicity-1;
				}
				else
				{
					/* Do Nothing*/
				}
			}
			else
			{
				/* Decrement the first delay*/
				SystemTasks[Local_u8TaskCounter].FirstDelay--;
			}
		}
		else
		{
			/* Task Suspended */
		}
	}

}




