#ifndef _RTOS_INTERFACE_H
#define _RTOS_INTERFACE_H

void RTOS_voidStartRTOS();

u8 RTOS_u8CreateTask(u16 Copy_u16Periodicity,u16 Copy_u16TaskDelay,u8 Copy_u8Priority,void (*Copy_pvTaskFunc)(void));


void RTOS_voidSuspendTask(u8 Copy_u8Priority);

void RTOS_voidResumeTask(u8 Copy_u8Priority);

void RTOS_voidDeleteTask(u8 Copy_u8Priority);

#define Task_Num   3









#endif
