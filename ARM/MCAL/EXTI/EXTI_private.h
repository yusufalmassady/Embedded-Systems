/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 9 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_



typedef struct 
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
	
}EXTI_t;
typedef struct 
{
	volatile u32 EXTICR1;
	volatile u32 EXTICR2;
	volatile u32 EXTICR3;
	volatile u32 EXTICR4;
}AFIO_t;
#define EXTI ((volatile EXTI_t*)0x40010400)
#define AFIO ((volatile AFIO_t*)0x40010000 + 0x08 )

#define RISING_EDGE 1
#define FALLING_EDGE 2
#define ON_CHANGE 3 
#define PA 0b0000
#define PB 0b0001
#define PC 0b0010
#define EXTI0 0
#define EXTI1 1
#define EXTI2 2
#define EXTI3 3
#define EXTI4 4
#define EXTI5 5
#define EXTI6 6
#define EXTI7 7
#define EXTI8 8
#define EXTI9 9
#define EXTI10 10
#define EXTI11 11
#define EXTI12 12
#define EXTI13 13
#define EXTI14 14
#define EXTI15 15






#endif