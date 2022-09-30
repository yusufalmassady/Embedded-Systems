/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 23 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/
#ifndef RTOS_INTERFACE_H_
#define RTOS_INTERFACE_H_

void RTOS_voidInit();

void RTOS_voidCreateTask(u8 Copy_u8Priority,u32 Copy_u32Periodicity, void(*Copy_pvTaskFunc)(void));











#endif