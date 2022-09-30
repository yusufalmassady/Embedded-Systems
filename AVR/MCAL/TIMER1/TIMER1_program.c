#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"

     /*Define Pointer to TIMER0 ISR functions*/
	  void (*Global_pvTimerOverFlowCallBack)(void)= NULL;
	  void (*Global_pvTimer1ACTCCallBack)(void)= NULL;
	 
void MTIMER1_voidInit()
{
	#if       TIMER1_Mode == TIMER1_Normal
	/*Choose Normal Mode*/
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TCCR1A, TCCR1A_WGM11);
	CLR_BIT(TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TCCR1B, TCCR1B_WGM13);
	
	/*Timer Over flow flag Enable*/
	SET_BIT(TIMSK, TIMSK_TOIE1);
	SET_BIT(SREG,SREG_GIE);                /*ENABLE GLOBAL INTERRUPT*/
	
	/*Set PRESCALAR 8*/
	SET_BIT(TCCR1B, TCCR1B_CS10);
	CLR_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS12);
	
	#elif     TIMER1_Mode == TIMER1_CTC
	/*Choose CTC Mode*/
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	CLR_BIT(TCCR1A, TCCR1A_WGM11);
	SET_BIT(TCCR1B, TCCR1B_WGM12);
	CLR_BIT(TCCR1B, TCCR1B_WGM13);
	
	/*OUTPUT COMPARE MATCH INTERRUPT ENABLE*/
	SET_BIT(TIMSK, TIMSK_OCIE1A);
	SET_BIT(SREG,SREG_GIE);                /*ENABLE GLOBAL INTERRUPT*/
	
	/*Set compare match value to 250*/
	OCR1A=20000;
	
	/*Set PRESCALAR 8*/
	SET_BIT(TCCR1B, TCCR1B_CS10);
	CLR_BIT(TCCR1B, TCCR1B_CS11);
	CLR_BIT(TCCR1B, TCCR1B_CS12);
	#elif     TIMER1_Mode == TIMER1_PWM
	
	/*Choose Fast PWM Mode*/
	CLR_BIT(TCCR1A, TCCR1A_WGM10);
	SET_BIT(TCCR1A, TCCR1A_WGM11);
	SET_BIT(TCCR1B, TCCR1B_WGM12);
	SET_BIT(TCCR1B, TCCR1B_WGM13);
	
	/*SET OCR1 ON TOP CLEAR OCR1 ON COMPARE*/
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	CLR_BIT(TCCR1A,TCCR1A_COM1B0);
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);
	
	/*Set PRESCALAR 1*/
	CLR_BIT(TCCR1B,TCCR1B_CS10);
	SET_BIT(TCCR1B,TCCR1B_CS11);
	CLR_BIT(TCCR1B,TCCR1B_CS12);

	/*SET ICR1*/
	//ICR1=20000;      *for servo motor
	ICR1=625;
	#endif
}

void MTIMER1_voidSetDuty(u16 Copy_u8DutyCycle)
{
	/*Check for mode is PWM*/
	OCR1A = Copy_u8DutyCycle;               /*Sets OCR0 value*/
}

void MTIMER1_voidTimer1OVSetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	if(Copy_pvCallBackFunc != NULL) /*checking if function exists*/
	{
		Global_pvTimerOverFlowCallBack= Copy_pvCallBackFunc; /*ADDS ISR Function*/
	}
	else
	{
		/*do nothing*/
	}

}

void MTIMER1_voidTimer1ACTCSetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	if(Copy_pvCallBackFunc != NULL) /*checking if function exists*/
	{
		Global_pvTimer1ACTCCallBack= Copy_pvCallBackFunc; /*ADDS ISR Function*/
	}
	else
	{
		/*do nothing*/
	}

}

//TIMER OVERFLOW ISR
void  __vector_9 (void)	__attribute__((signal));
void  __vector_9 (void)
{
	if(Global_pvTimerOverFlowCallBack != NULL)
	{
		Global_pvTimerOverFlowCallBack();
	}
	else
	{
		/*Do nothing*/
	}

}

//ON COMPARE ISR
void  __vector_7 (void)	__attribute__((signal));
void  __vector_7 (void)
{
	if(Global_pvTimer1ACTCCallBack != NULL)
	{
		Global_pvTimer1ACTCCallBack();
	}
	else
	{
		/*Do nothing*/
	}

}
