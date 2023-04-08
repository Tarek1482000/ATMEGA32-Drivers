/******************************************************************************
 *
 * Module: RTOS Interface
 *
 * File Name: RTOS_interfce.h
 *
 * Description: header file for the RTOS Interface driver
 *
 * Author: Tarek Ahmed
 *
 *******************************************************************************/

#ifndef RTOS_INTERFACE_C_
#define RTOS_INTERFACE_C_

#include "../../mcu_config/std_types.h"

void RTOS_voidStarts(void);

uint8 RTOS_voidCreateTask(uint8 u8Priority , uint16 u16Preodicity , void(*PvTaskFunc)(void) , uint16 u16FirstDelay);


void RTOS_voidSuspendTask(uint8 u8Priority);

void RTOS_voidResumeTask(uint8 u8Priority);

void RTOS_voidDeleteTask(uint8 u8Priority);


#endif /* RTOS_INTERFACE_C_ */
