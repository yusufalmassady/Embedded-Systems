/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 13 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/
#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_



typedef struct 
{
	
     volatile u32 CTRL;
     volatile u32 LOAD;
	 volatile u32 VAL;
	 volatile u32 CALIB;
	 
}STK_t;

#define STK ((volatile STK_t*)0xE000E010)


#define AHB_DIV_BY_8 0 
#define AHB 1

#defiNE INTERVAL_SINGLE 1
#define INTERVAL_PERIODIC 0
#endif