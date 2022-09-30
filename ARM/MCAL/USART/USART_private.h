/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 17 JAN , 2022
/* Version  : v1.0
*******************************************************************************************************/

#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H
typedef struct 
{
	
     volatile u32 SR;
     volatile u32 DR;
	 volatile u32 BRR;
	 volatile u32 CR1;
	 volatile u32 CR2;
	 volatile u32 CR3;
	 volatile u32 GRPR;
	 
}USART_t;

#define USART1 ((volatile *USART_T)0x40013800)


#endif
