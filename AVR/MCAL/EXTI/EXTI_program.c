#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"


/*Define Global array of 3 pointers to functions to carry ISR application addresses*/
static void (*Global_pvINTCallBackFunc[3])(void)={NULL};

void MEXTI_voidEXTIEnalbe(u8 Copy_u8INTNum,u8 Copy_u8SenseControl)
{
	SET_BIT(SREG,SREG_GIE);                /*ENABLE GLOBAL INTERRUPT*/
	switch (Copy_u8INTNum)                 /*CHOOSE INTERRUPT PIN*/
	{
		case EXTI_INT0: 
		     SET_BIT(GICR,GICR_INT0E);     /*SET INT0 INTERRUPT ENABLE*/
			 switch (Copy_u8SenseControl)  /*CHOOSE INTERRUPT SENSE CONTROL*/
			 {
				 case Low_Level    :  CLR_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
				 case On_Change    :  SET_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
				 case Rising_Edge  :  SET_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
				 case Falling_Edge :  CLR_BIT(MCUCR,MCUCR_ISC00); SET_BIT(MCUCR,MCUCR_ISC01); break;
				 default           : break;
			 } break;
		case EXTI_INT1:
		     SET_BIT(GICR,GICR_INT1E);     /*SET INT1 INTERRUPT ENABLE*/
			 switch (Copy_u8SenseControl)  /*CHOOSE INTERRUPT SENSE CONTROL*/
			 {
				 case Low_Level    :  CLR_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
				 case On_Change    :  SET_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
				 case Rising_Edge  :  SET_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
				 case Falling_Edge :  CLR_BIT(MCUCR,MCUCR_ISC10); SET_BIT(MCUCR,MCUCR_ISC11); break;
				 default           : break;
			 } break;
		case EXTI_INT2:		
		     SET_BIT(GICR,GICR_INT2E);     /*SET INT2 INTERRUPT ENABLE*/
			 switch (Copy_u8SenseControl)
			 {
				 case Rising_Edge  :  SET_BIT(MCUCSR,MCUCSR_ISC2); break;
				 case Falling_Edge :  CLR_BIT(MCUCSR,MCUCSR_ISC2); break;
				 default           : break;
			 } break;
		default        :
               break;		
	}
}

void MEXTI_voidDisableInterrupt(u8 Copy_u8INTNum)
{
	switch (Copy_u8INTNum)
	{
		case EXTI_INT0: 
		     CLR_BIT(GICR,GICR_INT0E);     /*CLEAR INT0 INTERRUPT ENABLE*/
			 break;
		case EXTI_INT1:
             CLR_BIT(GICR,GICR_INT1E);     /*CLEAR INT1 INTERRUPT ENABLE*/
			 break;
		case EXTI_INT2:
             CLR_BIT(GICR,GICR_INT2E);     /*CLEAR INT2 INTERRUPT ENABLE*/
			 break;
		default       :
             break;		
	}
}

void MEXTI_voidINTSetCallBack(void (*Copy_pvCallBackFunc)(void), u8 Copy_u8INTNum)
{
	if(Copy_pvCallBackFunc != NULL) /*checking if function exists*/
	{
		Global_pvINTCallBackFunc[Copy_u8INTNum]= Copy_pvCallBackFunc; /*ADDS ISR For chosen interrupt pin*/
	}
	else
	{
		/*do nothing*/
	}

}



/*ISR of INT0*/
void  __vector_1 (void)	__attribute__((signal));
void  __vector_1 (void)
{
	if(Global_pvINTCallBackFunc[0]!=NULL)
	{
		Global_pvINTCallBackFunc[0]();
	}
	else
	{
		/*do nothing*/
	}
}

/*ISR of INT1*/
void  __vector_2 (void)	__attribute__((signal));
void  __vector_2 (void)
{
	if(Global_pvINTCallBackFunc[EXTI_INT1] != NULL)
	{
		Global_pvINTCallBackFunc[EXTI_INT1]();
	}
	else
	{
		/*Do nothing*/
	}

}

/*ISR of INT2*/
void  __vector_3 (void)	__attribute__((signal));
void  __vector_3 (void)
{
	if(Global_pvINTCallBackFunc[EXTI_INT2] != NULL)
	{
		Global_pvINTCallBackFunc[EXTI_INT2]();
	}
	else
	{
		/*Do nothing*/
	}

}
