/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 15 NOV , 2021
/* Version  : v1.0
*******************************************************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

typedef sttruct 
{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}RCC_t;
#define RCC  ((volatile RCC_t*)0x40021000)

#define RCC_HSI 0
#define RCC_HSE_RC 1 
#define RCC_HSE_CRYSTAL 2
#define RCC_PLL 3
#define PLL_HSI_DIV_2 4
#define PLL_HSE_RC 5
#define PLL_HSE_RC_DIV_2 6
#define PLL_HSE_CRY 7
#define PLL_HSE_CRY_DIV_2 8




















#endif