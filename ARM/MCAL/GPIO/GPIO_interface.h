/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 18 NOV , 2021
/* Version  : v1.0
*******************************************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/**********************OUTPUT SPEED 2MHZ***************************/
#define OUTPUT_2MHZ_PP 0b0010
#define OUTPUT_2MHZ_OD 0b0110
#define OUTPUT_2MHZ_AFPP 0b1010
#define OUTPUT_2MHZ_AFOD 0b1110

/**********************OUTPUT SPEED 10MHZ***************************/
#define OUTPUT_10MHZ_PP 0b0001
#define OUTPUT_10MHZ_OD 0b0101
#define OUTPUT_10MHZ_AFPP 0b1001
#define OUTPUT_10MHZ_AFOD 0b1101

/**********************OUTPUT SPEED 50MHZ***************************/
#define OUTPUT_50MHZ_PP 0b0011
#define OUTPUT_50MHZ_OD 0b0111
#define OUTPUT_50MHZ_AFPP 0b1011
#define OUTPUT_50MHZ_AFOD 0b1111

/**********************INPUT **************************************/
#define INPUT_ANALOG 0b0000
#define INPUT_FLOAT 0b0100
#define INPUT_PULL_UP_DOWN 0b1000



#define PORTA 0
#define PORTB 1 
#define PORTC 2 
#define GPIO_HIGH 1  
#define GPIO_LOW 0  
void MGPIO_voidSetPinDirection (u8 Copy_u8PortName,u8 Copy_u8PinNumber,u8 Copy_u8PinMode);
void MGPIO_voidSetPinValue (u8 Copy_u8PortName, u8 Copy_u8PinNumber,u8 Copy_PinValue);










#endif
