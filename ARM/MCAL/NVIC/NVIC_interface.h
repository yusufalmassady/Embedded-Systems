/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 29 NOV , 2021
/* Version  : v1.0
*******************************************************************************************************/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_


void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8InterruptID);
void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8InterruptID);
void MNVIC_voidSetPending(u8 Copy_u8InterruptID);
void MNVIC_voidClearPending(u8 Copy_u8InterruptID);
u8 MNVIC_u8GetActiveFlag (u8 Copy_u8InterruptID);
void MNVIC_voidSetInterruptPriority(u8 Copy_u8InterruptID,u8 Copy_u8Priority);











#endif