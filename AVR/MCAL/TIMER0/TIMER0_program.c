#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

     /*Define Pointer to TIMER0 ISR functions*/
 void (*Global_pvTimerOverFlowCallBack)(void)= NULL;
 void (*Global_pvTimerCTCCallBack)(void)= NULL;
	 
void MTIMER0_voidInit()
{
	#if       TIMER0_Mode == TIMER0_Normal
	/*Choose Normal Mode*/
	CLR_BIT(TCCR0, TCCR0_WGM00);
	CLR_BIT(TCCR0, TCCR0_WGM01);
	
	/*Timer Over flow flag Enable*/
	SET_BIT(TIMSK, TIMSK_TOIE);
	SET_BIT(SREG,SREG_GIE);                /*ENABLE GLOBAL INTERRUPT*/
	
	/*Set PRESCALAR 8*/
	CLR_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS02);
	
	#elif     TIMER0_Mode == TIMER0_CTC
	/*Choose CTC Mode*/
	CLR_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);
	
	/*OUTPUT COMPARE MATCH INTERRUPT ENABLE*/
	SET_BIT(TIMSK, TIMSK_OCIE);
	SET_BIT(SREG,SREG_GIE);
	/*Set compare match value to 250*/
	OCR0=250;

	/*Set PRESCALAR 1*/
	SET_BIT(TCCR0, TCCR0_CS00);
	CLR_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);
	#elif     TIMER0_Mode == TIMER0_PWM
	
	/*Choose Fast PWM Mode*/
	CLR_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);
	
	/*SET OC0 ON TOP CLEAR OC0 ON COMPARE*/
	CLR_BIT(TCCR0, TCCR0_COM00);
	SET_BIT(TCCR0, TCCR0_COM01);
	
	/*Set PRESCALAR 64*/
	CLR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	SET_BIT(TCCR0, TCCR0_CS02);
	#endif
}

void MTIMER0_voidSetDuty(u8 Copy_u8DutyCycle)
{
	/*Check for mode is PWM*/
	#if TIMER0_MODE == TIMER0_PWM
	OCR0 = Copy_u8DutyCycle;               /*Sets OCR0 value*/
	#endif
}

void MTIMER0_voidTimer0OVSetCallBack(void (*Copy_pvCallBackFunc)(void))
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

void MTIMER0_voidTimer0CTCSetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	if(Copy_pvCallBackFunc != NULL) /*checking if function exists*/
	{
		Global_pvTimerCTCCallBack= Copy_pvCallBackFunc; /*ADDS ISR Function*/
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
void  __vector_10 (void)	__attribute__((signal));
void  __vector_10 (void)
{
	if(Global_pvTimerCTCCallBack != NULL)
	{
		Global_pvTimerCTCCallBack();
	}
	else
	{
		/*Do nothing*/
	}

}
