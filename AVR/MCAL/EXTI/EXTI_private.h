#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define SREG           *((volatile u8*)0x5F)   /*AVR STATUS REGISTER*/
#define SREG_GIE       7                       /*GLOBAL INTERRUPT ENABLE*/

#define MCUCR          *((volatile u8*)0x55)   /*MCU CONTROL REGISTER*/
/*INT0 SENSE CONTROL*/
#define MCUCR_ISC00     0
#define MCUCR_ISC01     1
/*INT1 SENSE CONTROL*/
#define MCUCR_ISC10     2
#define MCUCR_ISC11     3

#define MCUCSR          *((volatile u8*)0x54)   /*MCU CONTROL AND STATUS REGISTER*/
#define MCUCSR_ISC2      6                        /*INT2 SENSE CONTROL*/ 

#define GICR            *((volatile u8*)0x5B)   /*GENERAL INTERRUPT CONTROL REGISTER*/ 
#define GICR_INT0E     6                        /*INT0 INTERRUPT ENABLE*/
#define GICR_INT1E     7                        /*INT1 INTERRUPT ENABLE*/
#define GICR_INT2E     5                        /*INT2 INTERRUPT ENABLE*/

#define GIFR            *((volatile u8*)0x5A)   /*GENERAL INTERRUPT FLAG REGISTER*/ 
#define GIFR_INT0F     6                        /*INT0 INTERRUPT FLAG*/
#define GIFR_INT1F     7                        /*INT1 INTERRUPT FLAG*/
#define GIFR_INT2F     5                        /*INT2 INTERRUPT FLAG*/


#endif 