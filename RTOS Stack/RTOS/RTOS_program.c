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
	Timer0_setCallBack(voidScheduler);
	sei()
	Timer0_init();
}

void RTOS_voidCreateTask(uint8 u8Priority , uint16 u16Preodicity , void(*PvTaskFunc)(void))
{
	SystemTasks[u8Priority].periodicity = u16Preodicity;

	SystemTasks[u8Priority].TaskFunc = PvTaskFunc;
}


void voidScheduler(void)
{
	static uint16 Local_u16TickCounter = 0;

	uint8 Local_u8TaskCounter;

	Local_u16TickCounter++;


	/* Loop on all tasks to check their Preodicity*/
	for(Local_u8TaskCounter=0 ;Local_u8TaskCounter < TASK_NUM ;Local_u8TaskCounter++)
	{
		if((Local_u16TickCounter % SystemTasks[Local_u8TaskCounter].periodicity) == 0)
		{
			if(SystemTasks[Local_u8TaskCounter].TaskFunc != NULL)
			{
				SystemTasks[Local_u8TaskCounter].TaskFunc();
			}
			else
			{
				/* Do Nothing*/
			}
		}
	}

}




