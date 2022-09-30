/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 23 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/
#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_

typedef struct 
{
	volatile u32 CCR;
	volatile u32 CNDTR;
	volatile u32 CPAR;
	volatile u32 CMAR;
	volatile u32 RESERVED;
}DMA_CHANNEL_T;

typedef struct 
{
	volatile u32 ISR;
	volatile u32 IFCR;
    DMA_CHANNEL_T Channel[7];
	
}DMA_t;

#define DMA ((volatile DMA_t*)0x400200000)


#endif