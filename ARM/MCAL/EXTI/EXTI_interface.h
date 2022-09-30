/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 9 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/
#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

void MEXTI_voidInit();

/*
modes 

1- RISING_EDGE 
2- FALLING_EDGE
3- ON_CHANGE

PORTS 

1- PA
2- PB 
3- PC

Pin numbers 
EXTI0 0
EXTI1 1
EXTI2 2
EXTI3 3
EXTI4 4
EXTI5 5
EXTI6 6
EXTI7 7
EXTI8 8
EXTI9 9
EXTI10 10
EXTI11 11
EXTI12 12
EXTI13 13
EXTI14 14
EXTI15 15

*/


void MEXTI_voidSetEXTIPin(u8 Copy_u8Port,u8 Copy_u8PinNumber);
void MEXTI_voidSetMode (u8 Copy_u8PinNumber,u8 Copy_u8Mode);
void MEXTI_voidSetPending (u8 Copy_u8PinNumber);
void MEXTI_voidClearPending (u8 Copy_u8PinNumber)
void METI_voidSetInterruptPin(u8 Copy_u8PinNumber);
void MEXTI_voidSetcallback(u8 Copy_u8PinNumber,(void)(*Copy_CallBackFunction)(void));







#endif