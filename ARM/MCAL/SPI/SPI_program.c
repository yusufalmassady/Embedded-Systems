/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 30 DEC , 2021
/* Version  : v1.0
*******************************************************************************************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/GPIO_interface.h"

#include "../include/SPI_private.h"
#include "../include/SPI_interface.h"
#include "../include/SPI_config.h"


void MSPI1_voidInit(void)
{
	//idle high
	//write @ leading
	//clock 8 MHZ
	//full duplex
	//2 line unidirectional 
	//8 bit data size 
	//MSB First 
	SPI1->CR1=0x0347
}

void MSPI1_voidExchangeData(u8 Copy_u8Data, u8 *Copy_pu8RecievedData)
{
	//clear negative slave select pin 
	MGPIO_voidSetPinValue (Slave_Select_Pin ,GPIO_LOW);
	//send data
	SPI1 -> DR=Copy_u8Data;
	//wait for the flag to return to zero
	while (GET_BIT(SPI->SR,7)==1);
	//GET THE RECIEVED DATA 
	*Copy_pu8RecievedData = SPI-> DR;
	//deselect the slave by setting negative select slave to 1
	MGPIO_voidSetPinValue(Slave_Select_Pin,GPIO_HIGH);
}