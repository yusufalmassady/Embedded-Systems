/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 17 JAN , 2022
/* Version  : v1.0
*******************************************************************************************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/STK_interface.h"

#include "../include/USART_interface.h"
#include "../include/USART_private.h"
#include "../include/USART_config.h"


void MUSART1_voidInit(void)
{
	/*9600 BRR=0x341 */
	/*115200 BRR=0x45 */
	USART1->BRR=0x45;
	/*
	1- enable RX
	2- enable TX
	3- enable USART
	*/
	SET_BIT(USART1->CR1,13);
	SET_BIT(USART1->CR1,2);
	SET_BIT(USART1->CR1,3);
	//CLEAR STATUS REGISTER 
	USART1->SR=0;
}

void MUSART1_voidTransmit(u8 Copy_u8Arr[])
{
    u8 Local_u8LoopDummy=0;
	while(Copy_u8Arr[Local_u8LoopDummy]!='/0')
	{
		USART1->DR=Copy_u8Arr[Local_u8LoopDummy];
		//"also works"  while (((USART1->SR) & 0x40)==0);
		//wait till transmission complete
		while(GET_BIT(USART1->SR,6)!=1);
		Local_u8LoopDummy++;
	}
}

u8 MUSART1_u8Recieve(void)
{
	u16 Local_u16Timeout=0;
	while (((USART1->SR) & 1<<5)==0)
	{
		Local_u16Timeout++;
		if (Local_u16Timeout>=10000)
			break;
	}
	
	return (0xFF & (USART1->DR));
}