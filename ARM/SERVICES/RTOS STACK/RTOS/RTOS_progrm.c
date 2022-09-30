/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 23 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RTOS_private.h"
#include "../include/RTOS_interface.h"
#include "../include/RTOS_config.h"

#include "../include/STK_interface.h"


Task_t SystemTasks[NUM_OF_SYSTEM_TASKS]={{0}};

void RTOS_voidInit()
{
	//initialize systick
	MSTK_voidInit();
	//set the callback for the systick
	MSTK_voidSetIntervalPeriodic(1000,&voidSchedular);
}

void RTOS_voidCreateTask(u8 Copy_u8Priority,u32 Copy_u32Periodicity, void(*Copy_pvTaskFunc)(void))
{
	SystemTasks[Copy_u8Priority].Periodicity=Copy_u32Periodicity;
	SystemTasks[Copy_u8Priority].TaskFunc=Copy_pvTaskFunc;
}

void voidSchedular(void)
{
	static u32 Local_u32TickCounter = 0;
	Local_u32TickCounter++;
	u8 Local_u8Loopcounter=0;
	for(Local_u8Loopcounter=0;Local_u8Loopcounter<NUM_OF_SYSTEM_TASKS;Local_u8Loopcounter++)
	{
		if(Local_u32TickCounter% SystemTasks[Local_u8Loopcounter].Periodicity==0)
		{
			if(SystemTasks[Local_u8Loopcounter].TaskFunc != NULL)
			{
				SystemTasks[Local_u8Loopcounter].TaskFunc();
			}
		}
	}
}