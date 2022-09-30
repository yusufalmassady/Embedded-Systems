/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 30 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

#define HTFT_RESET_PIN PORTA,3
#define HTFT_A0_PIN PORTA,2

void HTFT_voidInit(void);
void HTFT_voidSendData(u8 Copy_u8Data);
void HTFT_voidDisplayImage (u16 * Copy_pu16Image);
#endif