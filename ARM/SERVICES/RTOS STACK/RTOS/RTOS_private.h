/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 23 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/
#ifndef RTOS_PRIVATE_H_
#define RTOS_PRIVATE_H_

typedef struct
{
	u8 Priority;
	u32 Periodicity;
	void (*TaskFunc)(void);
}Task_t;

void voidSchedular(void);













#endif