/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 13 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/STK_private.h"
#include "../include/STK_interface.h"
#include "../include/STK_config.h"


static void (*Global_pvNotificationFunction)(void)=NULL;
static u8 Global_u8SystickOperationMode;

void MTSK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	u8 Local_u8Dummy
	//load ticks to the load register 
	STK->LOAD=Copy_u32Ticks;
	//start the timer
	SET_BIT(STK->CTRL,0);
	//POLLING BUSY ON WAIT OF THE FLAG
	while(GET_BIT(STK->CTRL,16) ==0);
	//clear flag
	Local_u8Dummy=GET_BIT(STK->CTRL,16);
	//stop the timer
	CLR_BIT(STK->CTRL,0);
	//clear load register
	STK->LOAD=0;
	//clear val register 
	STK->VAL=0;
}

void MSTK_void Init(void)
{

		 #if STK_CLK_SOURCE==AHB_DIV_BY_8
		    CLR_BIT(STK->CTRL,2);
			#elif STK_CLK_SOURCE==AHB
			SET_BIT(STK->CTRL,2);
			#else
				#error "STK_CLK_SOURCE configuration Error"

        	#endif
		
}


u32 MSTK_u32 GetElapsedTime(void)
{
	return ((STK->LOAD) - (STK->VAL));
}
u32 MSTK_u32 GetRemainingTime(void)
{
	return (STK->VAL)  ;
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks,void(*Copy_pvNotificationFunction)(void))
{
	//set the mode to be interval periodic
	Global_u8SystickOperationMode=INTERVAL_PERIODIC;
	//load ticks to the load register
	STK->LOAD= Copy_u32Ticks
    //start the timer
	SET_BIT(STK->CTRL, 0);
	//set the callback function
	Global_pvNotificationFunction=Copy_pvNotificationFunction;
	//set the interrupt 
	SET_BIT(STK->CTRL, 1);
}

void MSTK_voidIntervalSingle(u32 Copy_u32Ticks,void(*Copy_pvNotificationFunction)(void))
{
	CLR_BIT(STK->CTRL,0)
	STK->VAL=0;
	//set the mode to be interval single
	Global_u8SystickOperationMode=INTERVAL_SINGLE;
	//load ticks to the load register
	STK->LOAD= Copy_u32Ticks
	//start the timer
	SET_BIT(STK->CTRL, 0);
	//set the callback function
	Global_pvNotificationFunction=Copy_pvNotificationFunction;
	//set the interrupt 
	SET_BIT(STK->CTRL, 1);
}

void SysTick_Handler(void)
{
	u8 Local_u8Dummy;
	if (Global_u8SystickOperationMode==INTERVAL_SINGLE)
	{
		//stop the timer
		CLR_BIT(STK->CTRL,0);
		//clear load register
		STK->LOAD=0;
		//clear val register 
		STK->VAL=0;
		//diable interrupt
		CLR_BIT(STK->CTRL,1);
	}
	if (Global_pvNotificationFunction != NULL)
	{
		Global_pvNotificationFunction();
		Local_u8Dummy=GET_BIT(STK->CTRL,16);
	}
	
}