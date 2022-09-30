/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 30 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/
#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
//please select the slave to be used by adjusting this 
#define Slave_Select_Pin  PORTA,0

void MSPI1_voidInit(void);
void MSPI1_voidExchangeData(u8 Copy_u8Data, u8 *Copy_pu8RecievedData);

#endif