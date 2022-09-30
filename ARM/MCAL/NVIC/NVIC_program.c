/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 29 NOV , 2021
/* Version  : v1.0
*******************************************************************************************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/NVIC_private.h"
#include "../include/NVIC_interface.h"
#include "../include/NVIC_config.h"


void MNVIC_voidInit(void)
{
	#define SCB_AIRCR *((volatile u32*)0x0xE000ED00+0x0C)
	SCB_AIRCR=NVIC_SYSTEM_GROUB_SUB_DISTRIBUTION;
}
void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8InterruptID)
{
	if (Copy_u8InterruptID<=31)
	{
		NVIC->ISER0=(1<<Copy_u8InterruptID);
	}
	else if (Copy_u8InterruptID<=59)
	{
		Copy_u8InterruptID-=32;
		NVIC->ISER1=(1<<Copy_u8InterruptID);
	}	
	else
	{
		  // Do Nothing
	}
		
}
void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8InterruptID)
{
	if (Copy_u8InterruptID<=31)
	{
		NVIC->ICER0=(1<<Copy_u8InterruptID);
	}
	else if (Copy_u8InterruptID<=59)
	{
		Copy_u8InterruptID-=32;
		NVIC->ICER1=(1<<Copy_u8InterruptID);
	}	
	else
	{
		  // Do Nothing
	}
		
}
void MNVIC_voidSetPending(u8 Copy_u8InterruptID)
{
	if (Copy_u8InterruptID<=31)
	{
		NVIC->ISPR0=(1<<Copy_u8InterruptID);
	}
	else if (Copy_u8InterruptID<=59)
	{
		Copy_u8InterruptID-=32;
		NVIC->ISPR1=(1<<Copy_u8InterruptID);
	}	
	else
	{
		  // Do Nothing
	}
		
}
void MNVIC_voidClearPending(u8 Copy_u8InterruptID)
{
	if (Copy_u8InterruptID<=31)
	{
		NVIC->ICPR0=(1<<Copy_u8InterruptID);
	}
	else if (Copy_u8InterruptID<=59)
	{
		Copy_u8InterruptID-=32;
		NVIC->ICPR1=(1<<Copy_u8InterruptID);
	}	
	else
	{
		  // Do Nothing
	}
		
}

u8 MNVIC_u8GetActiveFlag (u8 Copy_u8InterruptID)
{
	u8 Local_u8ActiveFlag; 
	if (Copy_u8InterruptID<=31)
	{
		Local_u8ActiveFlag=GET_BIT(NVIC->IABR0,Copy_u8InterruptID);
	}
	else if (Copy_u8InterruptID<=59)
	{
		Copy_u8InterruptID-=32;
		Local_u8ActiveFlag=GET_BIT(NVIC->IABR1,Copy_u8InterruptID);
	}	
	else
	{
		  // Do Nothing
	}
	return Local_u8ActiveFlag;
}

void MNVIC_voidSetInterruptPriority(u8 Copy_u8InterruptID,u8 Copy_u8Priority)
{
	if (Copy_u8InterruptID<=59)
	{
		NVIC_IPR[Copy_u8InterruptID]=Copy_u8Priority;
	}
	else
	{
		//return error
	}
}