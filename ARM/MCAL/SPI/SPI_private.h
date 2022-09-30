/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 30 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_



typedef struct 
{
	
     volatile u32 CR1;
     volatile u32 CR2;
	 volatile u32 SR;
	 volatile u32 DR;
	 volatile u32 CRCPR;
	 volatile u32 RXCRCR;
	 volatile u32 TXCRCR;
	 
}SPI_t;

#define SPI1 ((volatile SPI_t*)0x40013000 )



#endif