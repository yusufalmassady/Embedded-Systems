/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 18 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/
#include "../include/STD_TYPES.h";
#include "../include/BIT_MATH.h"

#include "../include/DAC_interface.h"
#include "../include/GPIO_interface.h"


void HDAC_voidDACInit()
{
void MGPIO_voidSetPortSectionDirection(PORTA,0,OUTPUT_50MHZ_PP);
}


void HDAC_voidDisplaySong(u8 Copy_u8ArrayHead,u16 Copy_u16ArraySize)
{
	u8 Local_u8Dummy=0;
	for (Local_u8Dummy=0;Local_u8Dummy<=Copy_u16ArraySize;Local_u8Dummy++)
	{
		void MGPIO_voidSetPortSectionValue(PORTA,0,Copy_u8ArrayHead[Local_u8Dummy]);
	}
}