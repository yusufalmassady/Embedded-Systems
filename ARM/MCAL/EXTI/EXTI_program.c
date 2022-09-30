/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 9 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/EXTI_private.h"
#include "../include/EXTI_interface.h"
#include "../include/EXTI_config.h"

void *Global_PVEXTI0NotificationFunc=NULL;
void MEXTI_voidSetEXTIPin(u8 Copy_u8Port,u8 Copy_u8PinNumber)
{
	switch (Copyu8PinNum)
	{
	case 0:
	AFIO->EXTICR1 &=~((0b1111)<<(Copy_u8PinNumber*4));
	AFIO->EXTICR1 |=~((Copy_u8Port)<<(Copy_u8PinNumber*4));
	break;
	case 1:
	AFIO->EXTICR1 &=~((0b1111)<<(Copy_u8PinNumber*4));
	AFIO->EXTICR1 |=~((Copy_u8Port)<<(Copy_u8PinNumber*4));
	case 2:
	AFIO->EXTICR1 &=~((0b1111)<<(Copy_u8PinNumber*4));
	AFIO->EXTICR1 |=~((Copy_u8Port)<<(Copy_u8PinNumber*4));
	break;
	case 3:
	AFIO->EXTICR1 &=~((0b1111)<<(Copy_u8PinNumber*4));
	AFIO->EXTICR1 |=~((Copy_u8Port)<<(Copy_u8PinNumber*4));
	break;
	case 4:
	Copy_u8PinNumber-=4;
	AFIO->EXTICR2 &=~((0b1111)<<(Copy_u8PinNumber*4));
	AFIO->EXTICR2 |=~((Copy_u8Port)<<(Copy_u8PinNumber*4));
	break;
	case 5:
	Copy_u8PinNumber-=4;
	AFIO->EXTICR2 &=~((0b1111)<<(Copy_u8PinNumber*4));
	AFIO->EXTICR2 |=~((Copy_u8Port)<<(Copy_u8PinNumber*4));
	break;
	case 6:
	Copy_u8PinNumber-=4;
	AFIO->EXTICR2 &=~((0b1111)<<(Copy_u8PinNumber*4));
	AFIO->EXTICR2 |=~((Copy_u8Port)<<(Copy_u8PinNumber*4));
	break;
	case 7:
	Copy_u8PinNumber-=4;
	AFIO->EXTICR2 &=~((0b1111)<<(Copy_u8PinNumber*4));
	AFIO->EXTICR2 |=~((Copy_u8Port)<<(Copy_u8PinNumber*4));
	break;
	case 8:
	Copy_u8PinNumber-=8;
	AFIO->EXTICR3 &=~((0b1111)<<(Copy_u8PinNumber*4));
	AFIO->EXTICR3 |=~((Copy_u8Port)<<(Copy_u8PinNumber*4));
	break;
	case 9:
	Copy_u8PinNumber-=8;
	AFIO->EXTICR3 &=~((0b1111)<<(Copy_u8PinNumber*4));
	AFIO->EXTICR3 |=~((Copy_u8Port)<<(Copy_u8PinNumber*4));
	break;
	case 10:
	Copy_u8PinNumber-=8;
	AFIO->EXTICR3 &=~((0b1111)<<(Copy_u8PinNumber*4));
	AFIO->EXTICR3 |=~((Copy_u8Port)<<(Copy_u8PinNumber*4));
	break;
	case 11:
	Copy_u8PinNumber-=8;
	AFIO->EXTICR3 &=~((0b1111)<<(Copy_u8PinNumber*4));
	AFIO->EXTICR3 |=~((Copy_u8Port)<<(Copy_u8PinNumber*4));
	break;
	case 12:
	Copy_u8PinNumber-=12;
	AFIO->EXTICR4 &=~((0b1111)<<(Copy_u8PinNumber*4));
	AFIO->EXTICR4 |=~((Copy_u8Port)<<(Copy_u8PinNumber*4));
	break;
	case 13:
	Copy_u8PinNumber-=12;
	AFIO->EXTICR4 &=~((0b1111)<<(Copy_u8PinNumber*4));
	AFIO->EXTICR4 |=~((Copy_u8Port)<<(Copy_u8PinNumber*4));
	break;
	case 14:
	Copy_u8PinNumber-=12;
	AFIO->EXTICR4 &=~((0b1111)<<(Copy_u8PinNumber*4));
	AFIO->EXTICR4 |=~((Copy_u8Port)<<(Copy_u8PinNumber*4));
	break;
	case 15:
	Copy_u8PinNumber-=12;
	AFIO->EXTICR4 &=~((0b1111)<<(Copy_u8PinNumber*4));
	AFIO->EXTICR4 |=~((Copy_u8Port)<<(Copy_u8PinNumber*4));
	break;
	}
}
void MEXTI_voidSetMode (u8 Copy_u8PinNumber,u8 Copy_u8Mode)
{
	switch (Copy_u8Mode)
	{
	case RISING_EDGE :
	SET_BIT(EXTI->RTSR,Copy_u8PinNumber);
	break;
	case FALLING_EDGE :
	SET_BIT(EXTI->FTSR,Copy_u8PinNumber);
	break;
	case ON_CHANGE :
	SET_BIT(EXTI->RTSR,Copy_u8PinNumber);
	SET_BIT(EXTI->FTSR,Copy_u8PinNumber);
	break;
	}
}
void MEXTI_voidSetPending (u8 Copy_u8PinNumber)
{
	SET_BIT(EXTI->PR,Copy_u8PinNumber);
}
void MEXTI_voidClearPending (u8 Copy_u8PinNumber)
{
	CLR_BIT(EXTI->PR,Copy_u8PinNumber);
}
void METI_voidSetInterruptPin(u8 Copy_u8PinNumber)
{
	SET_BIT(EXTI->IMR,Copy_u8PinNumber);
}
void MEXTI_voidSetcallback(u8 Copy_u8PinNumber,(void)(*Copy_CallBackFunction)(void))
{
	switch (Copy_u8PinNumber)
	{
		Case EXTI0 :
		Global_PVEXTI0NotificationFunc=Copy_CallBackFunction;
		break;
		
	}
}
void EXTI0_IRQHANDLER(void)
{
	if (Global_PVEXTI0NotificationFunc!=NULL)
	{
		Global_PVEXTI0NotificationFunc();
		MEXTI_voidClearPending(EXTI0);
	}
	//clear pending flag;
	
}