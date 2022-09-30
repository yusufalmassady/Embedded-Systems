/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 15 NOV , 2021
/* Version  : v1.0
*******************************************************************************************************/
#ifndef RCC_PROGRAM_C
#define RCC_PROGRAM_C


#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RCC_interface.h"
#include "../include/RCC_private.h"
#include "../include/RCC_config.h"


void MRCC_voidSystemClockIntit(void)
{
	//HSI AS SYSTEM CLOCK SOURCE 
	#if RCC_CPU_CLK_SOURCE == RCC_HSI
	RCC->CR=0x00000081;
	RCC->CFGR=0x00000000;
	#endif
	//HSE WITH AN EXTERNAL RC CLOCK AS A SYSTEM CLOCK SOURCE
	#if RCC_CPU_CLK_SOURCE == RCC_HSE_RC
	RCC->CR=0x00050000;
	RCC->CFGR=0x00000001;
	#endif
	//HSE WITH CRYSTAL AS A SYSTEM CLOCK SOURCE
	#if RCC_CPU_CLK_SOURCE == RCC_HSE_CRYSTAL
	RCC->CR=0x00010000;
	RCC->CFGR=0x00000001;
	#endif
	//PLL AS A SYSTEM CLOCK

	#if RCC_CPU_CLK_SOURCE == RCC_PLL 
	//HSI DIVIDED BY 2 AS PLL INPUT 
	#if RCC_PLL_IN == PLL_HSI_DIV_2
	RCC->CR=0x01000081;
	RCC->CFGR=0X001C0002;
	//HSE_RC DIVIDED BY 2 AS PLL INPUT 
	#elif RCC_PLL_IN == PLL_HSE_RC_DIV_2
	RCC->CR=0X01050000;
	RCC->CFGR=0X001F0002;
	//HSE_RC AS PLL INPUT 
	#elif RCC_PLL_IN == PLL_HSE_RC
	RCC->CR=0X01050000;
	RCC->CFGR=0X001D0002;
	//HSE_CRY DIVIDED BY 2 AS PLL INPUT 
	#elif RCC_PLL_IN == PLL_HSE_RC_DIV_2
	RCC->CR=0X01010000;
	RCC->CFGR=0X001F0002;
	//HSE_CRY AS PLL INPUT 
	#elif RCC_PLL_IN == PLL_HSE_RC
	RCC->CR=0X01010000;
	RCC->CFGR=0X001D0002;
	#endif
	#endif

	
}
/*
void MRCC_voidSystemClockManIntit(u8 Clock_Source,u8 PLL_Div_Factor)     //if not using pll set the factor to zero
{
	//HSI AS SYSTEM CLOCK SOURCE 
	#if Clock_Source == RCC_HSI
	RCC->CR=0x00000081;
	RCC->CFGR=0x00000000;
	#endif
	//HSE WITH AN EXTERNAL RC CLOCK AS A SYSTEM CLOCK SOURCE
	#if Clock_Source == RCC_HSE_RC
	RCC->CR=0x00050000;
	RCC->CFGR=0x00000001;
	#endif
	//HSE WITH CRYSTAL AS A SYSTEM CLOCK SOURCE
	#if Clock_Source == RCC_HSE_CRYSTAL
	RCC->CR=0x00010000;
	RCC->CFGR=0x00000001;
	#endif
	//PLL AS A SYSTEM CLOCK
	#if Clock_Source == RCC_PLL 
	RCC->CR=0x01000000;
	//HSI DIVIDED BY 2 AS PLL INPUT 
	#if PLL_Div_Factor == PLL_HSI_DIV_2
	RCC->CFGR=0X001C0002;
	#endif
	//HSE DIVIDED BY 2 AS PLL INPUT 
	#if PLL_Div_Factor == PLL_HSE_DIV_2
	RCC->CFGR=0X001F0002;
	#endif
	#endif
	//HSE AS PLL INPUT
	#if PLL_Div_Factor == PLL_HSE
	RCC->CFGR=0X001D0002;
	#endif
	#endif
	
	
}
*/
void MRCC_voidEnablePeripheralClock(u8 Copy_u8BusName , u8 Copy_u8PeripheralId)
{
	switch (Copy_u8BusName)
	{
		case RCC_AHB:
		SET_BIT(RCC->AHBENR,Copy_u8PeripheralId);
		
		break;
		case RCC_APB1:
		SET_BIT(RCC->APB1ENR,Copy_u8PeripheralId);

		
		break;
		case RCC_APB2 :
		SET_BIT(RCC->APB2ENR,Copy_u8PeripheralId);

		
		break;
	}
}
	
void MRCC_voidDisablePeripheralClock(u8 Copy_u8BusName , u8 Copy_u8PeripheralId)
    {
	switch (Copy_u8BusName)
	{
		case RCC_AHB:
		CLR_BIT(RCC->AHBENR,Copy_u8PeripheralId);
		
		break;
		case RCC_APB1:
		CLR_BIT(RCC->APB1ENR,Copy_u8PeripheralId);

		
		break;
		case RCC_APB2 :
		CLR_BIT(RCC->APB2ENR,Copy_u8PeripheralId);

		
		break;
	}
	
	
	
	
	
}









#endif