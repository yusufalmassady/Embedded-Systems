/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 15 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/
#include "../include/STD_TYPES.h";
#include "../include/BIT_MATH.h"

#include "../include/IR_interface.h"
#include "../include/STK_interface.h"

volatile u8 Global_u8StartFrame = 0;
volatile u32 Global_u32FrameData[50]={0};
volatile u8 Global_u8EdgeCounter = 0;
volatile u8 Global_u8Data = 0;

void HIR_voidPlay(void)
{
	switch Global_u8Data:
	{
		
	}
}

void HIR_voidGetFrame()
{
	if (Global_u8StartFrame==0)
	{
		void MSTK_voidIntervalSingle(1000000,HAL_voidTakeAction)
		Global_u8StartFrame=1;
	}
	else 
	{
		Global_u32FrameData[Global_u8EdgeCounter] = MSTK_u32 GetElapsedTime();
		void MSTK_voidIntervalSingle(1000000,HAL_voidTakeAction)
		Global_u8EdgeCounter++;
	}
}

void HIR_voidTakeAction()
{
	Global_u8Data=0;
	u8 Copy_u8Dummy=0;
	for (Copy_u8Dummy=0;Copy_u8Dummy<=8;Copy_u8Dummy++)
	{
		if ((Global_u32FrameData[Copy_u8Dummy+17]>=2000) && (Global_u32FrameData[Copy_u8Dummy+17]<=2300))
		{
			SET_BIT(Global_u8Data,Copy_u8Dummy);
		}
		else
			CLR_BIT(Global_u8Data,Copy_u8Dummy);
	}
	asm("NOP");

	Global_u8StartFrame = 0;
	Global_u32FrameData[0]={0};
	Global_u8EdgeCounter = 0;
}