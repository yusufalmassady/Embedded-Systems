/*******************************************************************************************************
/* Author   : yusuf almassady
/* Date     : 17 JAN , 2022
/* Version  : v1.0
*******************************************************************************************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/ESP_interface.h"

#include "../include/STK_interface.h"

#include "../include/USART_interface.h"

void HESP_voidESPInit(void)
{
	u8 Local_u8Result=0;


	while (Local_u8Result==0)
	{
		//ECHO DISABLE
	    MUSART1_voidTransmit("ATE0\r\n");
	    //CHECK FOR OK
		Local_u8Result=VoidESP_u8ValidateCommand();
	}
	Local_u8Result=0;
	while (Local_u8Result==0)
	{
	//Set mode
	MUSART1_voidTransmit("AT+CWMODE=1\r\n");
	//CHECK FOR OK
    Local_u8Result=VoidESP_u8ValidateCommand();
	}
}
void HESP_voidConnectToWIFI(void)
{
	u8 Local_u8Result=0;
	while (Local_u8Result==0)
	{
	MUSART1_voidTransmit("AT+CWJAP="HighConict","03october2020"\r\n");
	//check for wifi connected
	Local_u8Response=VESP_u8ValidateCommand();
	}
}
u8 HESP_u8GetData()
{
	u8 Local_u8Result=0;
	while (Local_u8Result==0)
	{
	MUSART1_voidTransmit("AT+CIPSTART="TCP","162.253.155.226",80\r\n");
	//check for connect
	Local_u8Response=VESP_u8ValidateCommand();
	}
	Local_u8Result=0;
	//PREPARE TO SEND
	while (Local_u8Result==0)
	{
	MUSART1_voidTransmit("AT+CIPSEND=46\r\n");
	//check for connect
	Local_u8Response=VESP_u8ValidateCommand();
	}
	MUSART1_voidTransmit("GET http://iotest.freevar.com/LED_status.txt\r\n");
		u8 Local_u8Response[100]={0};
	u8 Local_u8Dummy=0;
	u8 Local_u8Counter=0;
	while (Local_u8Dummy != 255)
	{
		Local_u8Dummy=MUSART1_u8Recieve();
		Local_u8Response[Local_u8Counter]=Local_u8Dummy;
		Local_u8Counter++;
	}
	return Local_u8Response[7];
}
u8 VESP_u8ValidateCommand(void)
{
	u8 Local_u8Response[100]={0};
	u8 Local_u8Dummy=0;
	u8 Local_u8Counter=0;
	while (Local_u8Dummy != 255)
	{
		Local_u8Dummy=MUSART1_u8Recieve();
		Local_u8Response[Local_u8Counter]=Local_u8Dummy;
		Local_u8Counter++;
	}
	//CHECK IF "OK"
	if (Local_u8Response[0]=='O' && Local_u8Response[1]=='K')
		return 1;
	//CHECK FOR CONNECT
	if (Local_u8Response[0]=='C' && Local_u8Response[1]=='O' && Local_u8Response[2]=='N' && Local_u8Response[3]=='N' && Local_u8Response[4]=='E' && Local_u8Response[5]=='C' && Local_u8Response[6]=='T')
	return 1;
	//CHECK IF "WIFI CONNECTED"
	if (Local_u8Response[0]=='W' && Local_u8Response[1]=='I' && Local_u8Response[2]=='F' && Local_u8Response[3]=='I' && Local_u8Response[4]==' ' && Local_u8Response[5]=='C' && Local_u8Response[6]=='O')
		return 1;
	else 
		return 0;
	
}
