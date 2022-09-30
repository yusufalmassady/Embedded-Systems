#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
/****************************************************************
 name           : 	MEXTI_voidEXTIEnalbe                        
 description    : 	init EXTERNAL INTERRUPT PIN AND CONTROL  		                                         
 parameter      :   Copy_u8INTNum,Copy_u8SenseControl		     
 options        :   EXTI_INT0,EXTI_INT1,EXTI_INT2  :::  
 ****************   Rising_Edge,Falling_Edge,On_Change,Low_Level 
 return         : 	none                             
 notes          :   External Interrupt Pin 2 only have 2 sense
*****************   options *rising/falling* 
****************************************************************/
void MEXTI_voidEXTIEnalbe(u8 Copy_u8INTNum,u8 Copy_u8SenseControl);
/****************************************************************
 name           : 	MEXTI_voidDisableInterrupt                        
 description    : 	Disable EXTERNAL INTERRUPT PIN  		                                         
 parameter      :   Copy_u8INTNum		     
 options        :   EXTI_INT0,EXTI_INT1,EXTI_INT2  
 return         : 	none                             
****************************************************************/
void MEXTI_voidDisableInterrupt(u8 Copy_u8INTNum);
/****************************************************************
 name           : 	MEXTI_voidINTSetCallBack                       
 description    : 	init User ISR Function   		                                         
 parameter      :   Copy_u8INTNum, *Copy_pvCallBackFunc		
 options        :   EXTI_INT0,EXTI_INT1,EXTI_INT2 
 return         : 	none                             
****************************************************************/
void MEXTI_voidINTSetCallBack(void (*Copy_pvCallBackFunc)(void), u8 Copy_u8INTNum);

/****************************************************************
 define Interrupt Sense Control options 
****************************************************************/
#define Low_Level      1
#define On_Change      2
#define Rising_Edge    3
#define Falling_Edge   4

/****************************************************************
 define Interrupt PINS options 
****************************************************************/
#define EXTI_INT0      0
#define EXTI_INT1      1
#define EXTI_INT2      2

#endif 
