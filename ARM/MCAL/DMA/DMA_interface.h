/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 23 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/
#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

void MDMA_voidChannelInit();
void MDMA_voidChannelStart(u32 *Copy_u32SourceAdress,u32 *Copy_u32DestinationAdress,u16 Copy_u16BlockSize);

#endif