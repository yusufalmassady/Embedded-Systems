/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 18 NOV , 2021
/* Version  : v1.0
*******************************************************************************************************/





#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/GPIO_interface.h"
#include "../include/GPIO_private.h"
#include "../include/GPIO_config.h"
void MGPIO_voidSetPinDirection (u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_u8PinMode)
{
	switch (Copy_u8PortName)
	{
	case PORTA:
	//check the pin number 
	if (Copy_u8PinNumber <= 7)
	{
		//MASKS THE 4 BITS 
		GPIOA->CRL&=~((0b1111)<<(Copy_u8PinNumber*4));
		//SET THE PIN MODE VALUES
		GPIOA->CRL|=((Copy_u8PinMode)<< (Copy_u8PinNumber*4 ));
	}
	else
	{
	Copy_u8PinNumber-=8;	
	GPIOA->CRH&=~((0b1111)<<(Copy_u8PinNumber*4));
	GPIOA->CRH|=((Copy_u8PinMode)<< (Copy_u8PinNumber*4 ));	
	
	}
	break;
	case PORTB:
	//check the pin number 
	if (Copy_u8PinNumber <= 7)
	{
		//MASKS THE 4 BITS 
		GPIOB->CRL&=~((0b1111)<<(Copy_u8PinNumber*4));
		//SET THE PIN MODE VALUES
		GPIOB->CRL|=((Copy_u8PinMode)<< (Copy_u8PinNumber*4 ));
	}
	else
	{
	Copy_u8PinNumber-=8;	
	GPIOB->CRH&=~((0b1111)<<(Copy_u8PinNumber*4));
	GPIOB->CRH|=((Copy_u8PinMode)<< (Copy_u8PinNumber*4 ));	
	
	}
	
	break;
	case PORTC:
	//check the pin number 
	if (Copy_u8PinNumber <= 7)
	{
		//MASKS THE 4 BITS 
		GPIOC->CRL&=~((0b1111)<<(Copy_u8PinNumber*4));
		//SET THE PIN MODE VALUES
		GPIOC->CRL|=((Copy_u8PinMode)<< (Copy_u8PinNumber*4 ));
	}
	else
	{
	Copy_u8PinNumber-=8;	
	GPIOC->CRH&=~((0b1111)<<(Copy_u8PinNumber*4));
	GPIOC->CRH|=((Copy_u8PinMode)<< (Copy_u8PinNumber*4 ));	
	
	}
	
	break;
	
	}
	
	
}

void MGPIO_voidSetPinValue (u8 Copy_u8PortName, u8 Copy_u8PinNumber,u8 Copy_PinValue)
{
	switch (Copy_u8PortName)
	{
		case PORTA:
		if (Copy_PinValue== GPIO_HIGH)
			SET_BIT(GPIOA->ODR,Copy_u8PinNumber);
		else
			CLR_BIT(GPIOA->ODR,Copy_u8PinNumber);

		break;
		case PORTB:
		if (Copy_PinValue== GPIO_HIGH)
			SET_BIT(GPIOB->ODR,Copy_u8PinNumber);
		else
			CLR_BIT(GPIOB->ODR,Copy_u8PinNumber);

		break;
		case PORTC:
		if (Copy_PinValue== GPIO_HIGH)
			SET_BIT(GPIOC->ODR,Copy_u8PinNumber);
		else
			CLR_BIT(GPIOC->ODR,Copy_u8PinNumber);
		break;
		
	}
	
}

