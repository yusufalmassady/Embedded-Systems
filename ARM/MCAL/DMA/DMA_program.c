/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 23 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/DMA_private.h"
#include "../include/DMA_interface.h"
#include "../include/DMA_config.h"

void MDMA_voidChannelInit()
{
	//memory to memory 
	//priority very high 
	//source and destination size element = 32 bit 
	//PINC and DINC enabled 
	//no circular mode 
	// direction peripheral to memory 
	//transfer complete interrupt enable 
	//channel disable 
	DMA->Channel[0].CCR=0x00007AC2;
}

void MDMA_voidChannelStart(u32 *Copy_u32SourceAdress,u32 *Copy_u32DestinationAdress,u16 Copy_u16BlockSize)
{
	//make sure channel is disabled 
	CLR_BIT(DMA->Channel[0].CCR,0);
	//load source adress
	DMA->Channel[0].CPAR=Copy_u32SourceAdress;
	//load destination adress	
	DMA->Channel[0].CMAR=Copy_u32DestinationAdress;
	//load block size 
	DMA->Channel[0].CNDTR=Copy_u16BlockSize;
	SET_BIT(DMA->Channel[0].CCR,0);
	
}

