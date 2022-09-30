/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 15 NOV , 2021
/* Version  : v1.0
*******************************************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB 0
#define RCC_APB1 1
#define RCC_APB2 2
#define IOPAR 2
void MRCC_voidSystemClockIntit(void);
void MRCC_voidEnablePeripheralClock(u8 Copy_u8BusName , u8 Copy_u8PeripheralId);
void MRCC_voidDisablePeripheralClock(u8 Copy_u8BusName , u8 Copy_u8PeripheralId);




#endif