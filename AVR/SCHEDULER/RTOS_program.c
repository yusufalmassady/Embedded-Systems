#include "LIB/STD_TYPES.h"

#include "GIE.h"
#include "TIMER0_interface.h"

#include "RTOS_private.h"
#include "RTOS_interface.h"
#include "RTOS_config.h"


Task_Create  System_Tasks[Task_Num]={{NULL}};

void RTOS_voidStartRTOS()
{
	GIE_voidEnableGlobalInterrupt();
	MTIMER0_voidTimer0CTCSetCallBack(voidScheduler);
	MTIMER0_voidInit();
}

u8 RTOS_u8CreateTask(u16 Copy_u16Periodicity,u16 Copy_u16TaskDelay,u8 Copy_u8Priority,void (*Copy_pvTaskFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	if(System_Tasks[Copy_u8Priority].priority==NULL)
	{

			if(Copy_pvTaskFunc!=NULL)
				{
					System_Tasks[Copy_u8Priority].priority=Copy_u8Priority;
					System_Tasks[Copy_u8Priority].Periodicity=Copy_u16Periodicity;
					System_Tasks[Copy_u8Priority].pvTaskFunction=Copy_pvTaskFunc;
					System_Tasks[Copy_u8Priority].Task_State=TASK_RESUMED;
					System_Tasks[Copy_u8Priority].Task_Delay=Copy_u16TaskDelay;
				}
			else
				{
					/*do nothing */
					Local_u8ErrorState=NOK;
				}
	}
	  else
	{
		/*Do nothing*/
		  Local_u8ErrorState=NOK;
	}
 return Local_u8ErrorState;
}

void RTOS_voidSuspendTask(u8 Copy_u8Priority)
{
	System_Tasks[Copy_u8Priority].Task_State=TASK_SUSPENDED;
}

void RTOS_voidResumeTask(u8 Copy_u8Priority)
{
	System_Tasks[Copy_u8Priority].Task_State=TASK_RESUMED;
}

void RTOS_voidDeleteTask(u8 Copy_u8Priority)
{
						System_Tasks[Copy_u8Priority].priority=NULL;
						System_Tasks[Copy_u8Priority].Periodicity=NULL;
						System_Tasks[Copy_u8Priority].pvTaskFunction=NULL;
						System_Tasks[Copy_u8Priority].Task_State=NULL;
}

void voidScheduler()
{
	u8 Local_u8Priority;
	
	for(Local_u8Priority=0;Local_u8Priority<Task_Num;Local_u8Priority++)
	{
		
		if(System_Tasks[Local_u8Priority].Task_State==TASK_RESUMED)
		{
			if(System_Tasks[Local_u8Priority].Task_Delay==0)
				{
				if(System_Tasks[Local_u8Priority].pvTaskFunction!=NULL)
					{
						System_Tasks[Local_u8Priority].pvTaskFunction();
						System_Tasks[Local_u8Priority].Task_Delay=System_Tasks[Local_u8Priority].Periodicity-1;
					}
				else 
					{
					/*do nothing */
					}
				}
			else 
			{
				/*do nothing*/
				System_Tasks[Local_u8Priority].Task_Delay--;
			}

		}
		else if(System_Tasks[Local_u8Priority].Task_State==TASK_SUSPENDED)
		{
			/*Do nothing*/
		}
	
	}
}
