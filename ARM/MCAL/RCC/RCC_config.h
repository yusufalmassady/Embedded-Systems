/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 15 NOV , 2021
/* Version  : v1.0
*******************************************************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H
/*OPTIONS
 1- RCC-HSI FOR HSI AS CLOCK SOURCE 
 2- RCC_HSE_RC FOR HSE RC AS CLOCK SOURCE
 3- RCC_HSE_CRYSTAL FOR HSE RC AS CLOCK SOURCE 
 4 RC_PLL FOR PLL AS CLOCK SOURCE 
 EXTRA NEEDED OPTIONS FOR PLL 
 PLL_HSI_DIV_2 PLL SCALER
 PLL_HSE PLL SCALER 
 PLL_HSE_DIV_2 SCALER 
 */
#define RCC_CPU_CLK_SOURCE     RCC_HSI
#define RCC_PLL_IN    HSE_DIV_2
#endif