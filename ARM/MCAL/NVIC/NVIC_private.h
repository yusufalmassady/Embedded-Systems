/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 29 NOV , 2021
/* Version  : v1.0
*******************************************************************************************************/
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_



typedef struct 
{
	volatile u32 ISER0;
	volatile u32 ISER1;
	volatile u32 ISER2;
	volatile u32 ICER0;
	volatile u32 ICER1;
	volatile u32 ICER2;
	volatile u32 ISPR0;
	volatile u32 ISPR1;
	volatile u32 ISPR2;
	volatile u32 ICPR0;
	volatile u32 ICPR1;
	volatile u32 ICPR2;
	volatile u32 IABR0;
	volatile u32 IABR1;
	volatile u32 IABR2;
	
}NVIC_t;
#define NVIC_IPR ((volatile u8*)0xE000E100+0x300)
#define NVIC ((volatile NVIC_t*)0xE000E100)

#define GRP_4_SUB_0   0x05FA0300
#define GRP_3_SUB_1   0x05FA0400
#define GRP_2_SUB_2   0x05FA0500
#define GRP_1_SUB_3   0x05FA0600
#define GRP_0_SUB_4   0x05FA0700








#endif