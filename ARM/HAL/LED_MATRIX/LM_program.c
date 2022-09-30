/*************************************************************************
/*
/*Author  : YUSUF
/*Date    : 16/2/2022
/*Version : 1.0
**************************************************************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/GPIO_interface.h"
#include "../include/STK_interface.h"

#include "../include/LM_interface.h"
#include "../include/LM_private.h"
#include "../include/LM_config.h"

void HLM_voidLMInit()
{
	//SETTING THE PIN DIRECTION AND SPEED FOR PINS USED IN LED MATRIX ROWS 
	MGPIO_voidSetPinDirection(LM_ROW0_PIN,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(LM_ROW1_PIN,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(LM_ROW2_PIN,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(LM_ROW3_PIN,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(LM_ROW4_PIN,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(LM_ROW5_PIN,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(LM_ROW6_PIN,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(LM_ROW7_PIN,OUTPUT_2MHZ_PP);
	
	//SETTING THE PIN DIRECTION AND SPEED FOR PINS USED IN LED MATRIX COLUMNS
	MGPIO_voidSetPinDirection(LM_COL0_PIN,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(LM_COL1_PIN,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(LM_COL2_PIN,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(LM_COL3_PIN,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(LM_COL4_PIN,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(LM_COL5_PIN,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(LM_COL6_PIN,OUTPUT_2MHZ_PP);
	MGPIO_voidSetPinDirection(LM_COL7_PIN,OUTPUT_2MHZ_PP);

}

void HLM_voidLMDisableColumns()
{
	//SETTING COLUMN VALUE TO 1 TO DISABLE ALL THE COLUMNS 
	MGPIO_voidSetPinValue(LM_COL0_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LM_COL1_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LM_COL2_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LM_COL3_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LM_COL4_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LM_COL5_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LM_COL6_PIN,GPIO_HIGH);
	MGPIO_voidSetPinValue(LM_COL7_PIN,GPIO_HIGH);
}

void HLM_u8SetRowValue (u8 copy_u8Value)
{
	MGPIO_voidSetPinValue(LM_ROW0_PIN,GET_BIT(copy_u8Value,0));
	MGPIO_voidSetPinValue(LM_ROW1_PIN,GET_BIT(copy_u8Value,1));
	MGPIO_voidSetPinValue(LM_ROW2_PIN,GET_BIT(copy_u8Value,2));
	MGPIO_voidSetPinValue(LM_ROW3_PIN,GET_BIT(copy_u8Value,3));
	MGPIO_voidSetPinValue(LM_ROW4_PIN,GET_BIT(copy_u8Value,4));
	MGPIO_voidSetPinValue(LM_ROW5_PIN,GET_BIT(copy_u8Value,5));
	MGPIO_voidSetPinValue(LM_ROW6_PIN,GET_BIT(copy_u8Value,6));
	MGPIO_voidSetPinValue(LM_ROW7_PIN,GET_BIT(copy_u8Value,7));
}

void HLM_u8Display(u8 *copy_pu8Data)
{
	//APPLYING DATA IN ROWS FOR FIRST COLUMN
	HLM_voidLMDisableColumns;
	HLM_u8SetRowValue(copy_pu8Data[0]);
	MGPIO_voidSetPinValue(LM_COL0_PIN,GPIO_LOW);
    MTSK_voidSetBusyWait(2500);	
	
	//APPLYING DATA IN ROWS FOR FIRST COLUMN
    HLM_voidLMDisableColumns();
	HLM_u8SetRowValue(copy_pu8Data[1]);
	MGPIO_voidSetPinValue(LM_COL1_PIN,GPIO_LOW);
    MTSK_voidSetBusyWait(2500);
	
	HLM_voidLMDisableColumns();
	HLM_u8SetRowValue(copy_pu8Data[2]);
	MGPIO_voidSetPinValue(LM_COL2_PIN,GPIO_LOW);
    MTSK_voidSetBusyWait(2500);
	
	HLM_voidLMDisableColumns();
	HLM_u8SetRowValue(copy_pu8Data[3]);
	MGPIO_voidSetPinValue(LM_COL3_PIN,GPIO_LOW);
    MTSK_voidSetBusyWait(2500);
	
	HLM_voidLMDisableColumns();
	HLM_u8SetRowValue(copy_pu8Data[4]);
	MGPIO_voidSetPinValue(LM_COL4_PIN,GPIO_LOW);
    MTSK_voidSetBusyWait(2500);
	
	HLM_voidLMDisableColumns();
	HLM_u8SetRowValue(copy_pu8Data[5]);
	MGPIO_voidSetPinValue(LM_COL5_PIN,GPIO_LOW);
    MTSK_voidSetBusyWait(2500);
	
	HLM_voidLMDisableColumns();
	HLM_u8SetRowValue(copy_pu8Data[6]);
	MGPIO_voidSetPinValue(LM_COL6_PIN,GPIO_LOW);
    MTSK_voidSetBusyWait(2500);
	
	HLM_voidLMDisableColumns();
	HLM_u8SetRowValue(copy_pu8Data[7]);
	MGPIO_voidSetPinValue(LM_COL7_PIN,GPIO_LOW);
    MTSK_voidSetBusyWait(2500);
}
