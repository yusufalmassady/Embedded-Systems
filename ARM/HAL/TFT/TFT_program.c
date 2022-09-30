/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 30 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/GPIO_interface.h"
#include "../include/STK_interface.h"
#include "../include/SPI_interface.h"

#include "../include/TFT_interface.h"
#include "../include/TFT_private.h"
#include "../include/TFT_config.h"


void HTFT_voidInit(void)
{
	//SEND RESET PULSES
	MGPIO_voidSetPinValue(HTFT_RESET_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(HTFT_RESET_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(HTFT_RESET_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(HTFT_RESET_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(HTFT_RESET_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(120000);
	
	//SEND SLEEP OUT COMMAND 
	HTFT_voidSendCommand(0x11);
	
	//COLOR MODE COMMAND
	HTFT_voidSendCommand(0x3A);
	HTFT_voidSendData(0x05);
	
	//DISPLAY ON COMMAND
	HTFT_voidSendCommand(0x29);

}

void HTFT_voidDisplayImage (u16 * Copy_pu16Image)
{
	u16 Local_u16LoopCounter;
    //SEND SET X ADDRESS
    HTFT_voidSendCommand(0x2A);
    HTFT_voidSendData(0); //HIGH BYTE OF START 
    HTFT_voidSendData(0); //LOW BYTE OF START	
	HTFT_voidSendData(0); //HIGH BYTE OF END
    HTFT_voidSendData(127); //LOW BYTE OF END	
	//SEND SET Y ADDRESS
	HTFT_voidSendCommand(0x2B);
    HTFT_voidSendData(0); //HIGH BYTE OF START 
    HTFT_voidSendData(0); //LOW BYTE OF START	
	HTFT_voidSendData(0); //HIGH BYTE OF END
    HTFT_voidSendData(159); //LOW BYTE OF END	
	
	u8 Local_u8Data;
	//SEND WRITE RAM COMMAND
	HTFT_voidSendCommand(0x2C);
	for (Local_u16LoopCounter;Local_u16LoopCounter<20480;Local_u16LoopCounter++)
	{
		//EXTRACT HIGH BYTE
	     Local_u8Data= Copy_pu16Image[Local_u16LoopCounter]>>8;
		//SEND HIGH BYTE
		HTFT_voidSendData(Local_u8Data);
		//EXTRACT LOW BYTE 
		Local_u8Data=Copy_pu16Image[Local_u16LoopCounter] & 0x00FF;
		//SEND LOW BYTE 
		HTFT_voidSendData(Local_u8Data);
	}
}

void HTFT_voidSendData(u8 Copy_u8Data)
{
	u8 Local_u8Dummy;
	//SET A0 PIN TO BE HIGH 
	MGPIO_voidSetPinValue(HTFT_A0_PIN,GPIO_HIGH);
	//SEND THE DATA
	MSPI1_voidExchangeData(Copy_u8Data,Local_u8Dummy);
}
static void voidSendCommand(u8 Copy_u8Command)
{
	u8 Local_u8Dummy;
	//SET A0 PIN TO BE HIGH 
	MGPIO_voidSetPinValue(HTFT_A0_PIN,GPIO_LOW);
	//SEND THE COMMAND
	MSPI1_voidExchangeData(Copy_u8Command,Local_u8Dummy);
	
	
}