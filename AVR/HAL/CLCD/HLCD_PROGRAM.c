 /*==================================================================================*/
 /**
 * @file         HLCD_PROGRAM.c	
 *
 * \b Description : 
 * This file includes LCD Driver implementations 
 *
 * @author      Embedded C TEAM					 								*
 * @date        20/6/2022 																	*
 * @version     V_1	
 * @copyright   IMT_SCHOOL 2022
 */
 /*==================================================================================*/

/************ LIB  **********/
#include "../../00-LIB/STD_TYPES.h"
#include "../../00-LIB/BIT_MATH.h"
#include "../../WMCAL/WMDIO/DIO_interface.h"
#include <util/delay.h>

/************ WMCAL **********/
//#include "../../03-MCAL/01-DIO/DIO_INTERFACE.h"

/************ HAL **********/
#include "HLCD_CONFIG.h"
#include "HLCD_INTERFACE.h"
#include "HLCD_PRIVATE.h"

/*********** FREE_RTOS   **********/
#include "../06-RTOS/FreeRTOSConfig.h"
#include "../06-RTOS/FreeRTOS.h"
#include "../06-RTOS/task.h"

/*==============================================================================*
 * Prototype   : void HLCD_voidInit(void);										*
 * Description : Set initialization direction of LCD							*
 * Arguments   : void			 												*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidInit(void)
{
	MDIO_u8SetPinDirection(LCD_DATA_PORT,LCD_EN_PIN,DIO_u8_OUTPUT);
	MDIO_u8SetPinDirection(LCD_DATA_PORT,LCD_RS_PIN,DIO_u8_OUTPUT);

	#if (LCD_MODE == _8_BIT_MODE)
	MDIO_voidSetPortDirection(LCD_DATA_PORT,0xFF);
	vTaskDelay(100);
	HLCD_voidSendCommand(0x38);			/*select 8-bit Mode*/
	#elif (LCD_MODE == _4_BIT_MODE)
	MDIO_u8SetPinDirection(DIO_u8_PORTD,LCD_DATA_PIN_4,DIO_u8_OUTPUT);
	MDIO_u8SetPinDirection(DIO_u8_PORTD,LCD_DATA_PIN_5,DIO_u8_OUTPUT);
	MDIO_u8SetPinDirection(DIO_u8_PORTD,LCD_DATA_PIN_6,DIO_u8_OUTPUT);
	MDIO_u8SetPinDirection(DIO_u8_PORTD,LCD_DATA_PIN_7,DIO_u8_OUTPUT);
	vTaskDelay(100);
	HLCD_voidSendCommand(0x33);		   /*select 4-bit Mode*/
	HLCD_voidSendCommand(0x32);
	HLCD_voidSendCommand(0x28);
	#endif

	HLCD_voidSendCommand(0x0C);		/*TURN LCD DISPLAY		  */
	HLCD_voidSendCommand(0x02);		/*RETURN HOME			  */
	HLCD_voidSendCommand(0x01);		/*CLEAR	LCD DISPLAY		  */
	HLCD_voidSendCommand(0x06);		/*MOVE FROM LEFT TO RIGHT */
}

/*==============================================================================*
 * Prototype   : void HLCD_voidSendCommand(u8 Copy_u8Cmd);						*
 * Description : Send Command to LCD											*
 * Arguments   : Command : takes Command 										*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidSendCommand(u8 Copy_u8Cmd)
{
	#if (LCD_MODE == _8_BIT_MODE)
	MDIO_u8SetPinValue (LCD_DATA_PORT,LCD_RS_PIN,DIO_u8_LOW);
	MDIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Cmd);
	MDIO_u8SetPinValue (LCD_DATA_PORT,LCD_EN_PIN,DIO_u8_HIGH);
	_vTaskDelay(1);
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_u8_LOW);
	vTaskDelay(5);

	#elif (LCD_MODE == _4_BIT_MODE)
	//to select command register
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_RS_PIN,DIO_u8_LOW);
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_4, GET_BIT(Copy_u8Cmd,4));
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_5, GET_BIT(Copy_u8Cmd,5));
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_6, GET_BIT(Copy_u8Cmd,6));
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_7, GET_BIT(Copy_u8Cmd,7));

	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_u8_HIGH); //EN
	vTaskDelay(1);
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_u8_LOW);

	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_4, GET_BIT(Copy_u8Cmd,0));
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_5, GET_BIT(Copy_u8Cmd,1));
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_6, GET_BIT(Copy_u8Cmd,2));
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_7, GET_BIT(Copy_u8Cmd,3));

	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_u8_HIGH); //EN
	vTaskDelay(1);
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_u8_LOW);
	vTaskDelay(5);
	#endif
}

/*==============================================================================*
 * Prototype   : void HLCD_voidDisplayCharacter(u8 Copy_u8Data);				*
 * Description : Send Char to LCD												*
 * Arguments   : Char : takes Char		 										*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidDisplayCharacter(u8 Copy_u8Data)
{
	#if (LCD_MODE == _8_BIT_MODE)
	MDIO_u8SetPinValue (LCD_DATA_PORT,LCD_RS_PIN,DIO_u8_HIGH);
	MDIO_u8SetPortValue(LCD_DATA_PORT,Copy_u8Data);
	MDIO_u8SetPinValue (LCD_DATA_PORT,LCD_EN_PIN,DIO_u8_HIGH);
	vTaskDelay(1);
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_u8_LOW);
	vTaskDelay(5);

	#elif (LCD_MODE == _4_BIT_MODE)
	//to select command register
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_RS_PIN,DIO_u8_HIGH);
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_4, GET_BIT(Copy_u8Data,4));
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_5, GET_BIT(Copy_u8Data,5));
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_6, GET_BIT(Copy_u8Data,6));
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_7, GET_BIT(Copy_u8Data,7));

	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_u8_HIGH); //EN
	vTaskDelay(1);
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_u8_LOW);

	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_4, GET_BIT(Copy_u8Data,0));
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_5, GET_BIT(Copy_u8Data,1));
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_6, GET_BIT(Copy_u8Data,2));
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_DATA_PIN_7, GET_BIT(Copy_u8Data,3));

	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_u8_HIGH); //EN
	vTaskDelay(1);
	MDIO_u8SetPinValue(LCD_DATA_PORT,LCD_EN_PIN,DIO_u8_LOW);
	vTaskDelay(5);
	#endif
}

/*==============================================================================*
 * Prototype   : void HLCD_voidClearDisplay(void);								*
 * Description : Clear LCD Display												*
 * Arguments   : void						 									*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidClearDisplay(void)
{
	HLCD_voidSendCommand(0x01);
}

/*==============================================================================*
 * Prototype   : void HLCD_voidWriteString(u8 *Ptr_u8PtrString);				*
 * Description : Send String to LCD												*
 * Arguments   : String : takes String		 									*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidWriteString(u8 *Ptr_u8PtrString)
{
	while(*Ptr_u8PtrString != 0)
	{
		HLCD_voidDisplayCharacter(*Ptr_u8PtrString);
		Ptr_u8PtrString++;
	}
}

/*==============================================================================*
 * Prototype   : void HLCD_voidGoToPosition(u8 Copy_u8Row,u8 Copy_u8Col);		*
 * Description : Send Position to LCD											*
 * Arguments   : N.OF ROW AND N.OF COL											*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidGoToPosition(u8 Copy_u8Row,u8 Copy_u8Col)
{
	u8 arr[4] ={0x80,0xC0,0x90,0xD0};
	HLCD_voidSendCommand(arr[Copy_u8Row] + Copy_u8Col);
}

/*==============================================================================*
 * Prototype   : void HLCD_voidDisplayNum(s32 Copy_s32Num);				*
 * Description : Send NUMBER to LCD												*
 * Arguments   : NUMBER															*
 * return      : void															*
 *==============================================================================*/
void HLCD_voidDisplayNum(s32 Copy_s32Num)
{
	if(Copy_s32Num == 0)
	{
		HLCD_voidDisplayCharacter('0');
	}
	else if(Copy_s32Num > 0  )
	{
		s8 i=0;
	    u8 Copy_u8Remander = 0;
	    u8 arr[10] = {0};
	    while(Copy_s32Num != 0)
	    {
	    	Copy_u8Remander = Copy_s32Num % 10;
	    	arr[i] = Copy_u8Remander;
	    	i++;
	    	Copy_s32Num /= 10;
	    }
	    i--;
	    while(i >= 0)
	    {
	    	HLCD_voidDisplayCharacter(arr[i] + 48);
	    	i--;
	    }

	}
}

/*==============================================================================*
 * Prototype   : void HLCD_voidDisplayFloat(f64 Copy_f64Num);				    *
 * Description : Send FLOAT to LCD												*
 * Arguments   : Num															*
 * return      : void															*
 *==============================================================================*/

 void HLCD_voidDisplayFloat(f64 Copy_f64Num)
 {
	 s32 Local_s32Num,Local_s32CastFNum;
	 f64 Local_f64FloatNum;
	 Local_s32Num = (s32)Copy_f64Num; 
	 HLCD_voidDisplayNum(Local_s32Num);
	 HLCD_voidDisplayCharacter('.');
	 Local_f64FloatNum=Copy_f64Num - (f64)Local_s32Num;
	 Local_f64FloatNum=Local_f64FloatNum*100;
	 Local_s32CastFNum=(s32)Local_f64FloatNum;
	 HLCD_voidDisplayNum(Local_s32CastFNum);
 }