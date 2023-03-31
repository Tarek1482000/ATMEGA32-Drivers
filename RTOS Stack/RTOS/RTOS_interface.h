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

void RTOS_voidCreateTask(uint8 u8Priority , uint16 u16Preodicity , void(*PvTaskFunc)(void));


#endif /* RTOS_INTERFACE_C_ */
