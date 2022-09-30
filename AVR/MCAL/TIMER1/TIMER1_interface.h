#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

/****************************************************************
 name           : 	MTIMER0_voidInit                        
 description    : 	Sets Timer 1 mode  		                                         
 parameter      :   None		     
 options        :   Set from config file  
 return         : 	none                             
****************************************************************/
void MTIMER1_voidInit();

/****************************************************************
 name           : 	MTIMER1_voidSetDuty
 description    : 	Sets Duty Cycle 		                                         
 parameter      :   Copy_u8DutyCycle		       
 return         : 	none                             
****************************************************************/
void MTIMER1_voidSetDuty(u16 Copy_u8DutyCycle);

/****************************************************************
 name           : 	MTIMER1_voidTimer0CTCSetCallBack
 description    : 	Sets ISR function for on compare match mode		                                         
 parameter      :   Copy_pvCallBackFunc		       
 return         : 	none                             
****************************************************************/
void MTIMER1_voidTimer1ACTCSetCallBack(void (*Copy_pvCallBackFunc)(void));

/****************************************************************
 name           : 	MTIMER1_voidTimer0OVSetCallBack
 description    : 	Sets ISR function for timer overflow  		                                         
 parameter      :   Copy_pvCallBackFunc		       
 return         : 	none                             
****************************************************************/
void MTIMER1_voidTimer1OVSetCallBack(void (*Copy_pvCallBackFunc)(void));
#endif 
