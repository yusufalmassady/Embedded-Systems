#ifndef _RTOS_private_H
#define _RTOS_private_H


typedef struct
{
	u16 Periodicity;
	u8  priority;
	u8 Task_State;
	u16 Task_Delay;
	void (*pvTaskFunction)(void);
}Task_Create;


#define TASK_SUSPENDED  1

#define TASK_RESUMED    2





void voidScheduler();

#endif
