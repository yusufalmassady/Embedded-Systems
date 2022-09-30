/*************************************************************************
/*
/*Author  : Abdulla
/*Date    : 15/11/2021
/*Version : 1.0
**************************************************************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/GPIO_interface.h"
#include "../include/STK_interface.h"

#include "../include/S2P_interface.h"
#include "../include/S2P_private.h"
#include "../include/S2P_config.h"


void HS2P_voidSendData(u8 Copy_u8Data)
{
	s8 Local_s8LoopCounter;
	u8 Local_u8Bit;
	for(Local_s8LoopCounter = 7; Local_s8LoopCounter>=0;Local_s8LoopCounter--)
	{
		Local_u8Bit = GET_BIT(Copy_u8Data,Local_s8LoopCounter);
		MGPIO_voidSetPinValue(DATA_SERIAL_PIN,Local_u8Bit);
		MGPIO_voidSetPinValue(SHIFT_CLK_PIN,HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(SHIFT_CLK_PIN,LOW);
		MSTK_voidSetBusyWait(1);		
	}
	MGPIO_voidSetPinValue(STORE_CLK_PIN,HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(STORE_CLK_PIN,LOW);
	MSTK_voidSetBusyWait(1);		
}

