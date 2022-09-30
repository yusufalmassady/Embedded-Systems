#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

#define SREG           *((volatile u8*)0x5F)         /*AVR STATUS REGISTER*/
#define SREG_GIE       7                             /*GLOBAL INTERRUPT ENABLE*/

#define TCCR1A         *((volatile u8*)0x4F)
#define TCCR1B         *((volatile u8*)0x4E)         /*Timer1 control registers*/
#define TCCR1A_COM1A1  7                             /*COMPARE OUTPUT MODE FOR OCRA bit1*/
#define TCCR1A_COM1A0  6                             /*COMPARE OUTPUT MODE FOR OCRA bit0*/
#define TCCR1A_COM1B1  5                             /*COMPARE OUTPUT MODE FOR OCRB bit1*/
#define TCCR1A_COM1B0  4                             /*COMPARE OUTPUT MODE FOR OCRB bit0*/
#define TCCR1A_WGM10   0                             /*Waveform generation Mode bit0*/
#define TCCR1A_WGM11   1                             /*Waveform generation Mode bit1*/
#define TCCR1B_WGM12   3                             /*Waveform generation Mode bit3*/
#define TCCR1B_WGM13   4                             /*Waveform generation Mode bit4*/
#define TCCR1B_ICNC1   7                             /*Input Capture Noise cancelor bit*/
#define TCCR1B_ICES    6                             /*Input Capture Enable*/
#define TCCR1B_WGM12   3                             /*Waveform generation Mode bit3*/
#define TCCR1B_WGM13   4                             /*Waveform generation Mode bit4*/
#define TCCR1B_CS10    0                             /*Prescalar select bit0*/
#define TCCR1B_CS11    1                             /*Prescalar select bit1*/
#define TCCR1B_CS12    2                             /*Prescalar select bit2*/

#define TCNT1H *((volatile u8*)0x4D)             
#define TCNT1L *((volatile u8*)0x4C)                 /*Contains Timer Counter Value*/
#define TCNT1 *((volatile u16*)0x4C)


#define OCR1AH *((volatile u8*)0x4B)
#define OCR1AL *((volatile u8*)0x4A)                 /*Output Compare Register A*/
#define OCR1A *((volatile u16*)0x4A)  

#define OCR1BH *((volatile u8*)0x49)
#define OCR1BL *((volatile u8*)0x48)  
#define OCR1B  *((volatile u16*)0x48)                /*Output Compare Register B*/

#define TIMSK         *((volatile u8*)0X59)          /*Timer mask*/
#define TIMSK_OCIE         1                         /*Output Compare 0 interrupt enable*/
#define TIMSK_TOIE         0                         /*OVERFLOW 0 interrupt enable*/
#define TIMSK_OCIE1A       4                         /*Output Compare A 1 interrupt enable*/
#define TIMSK_TOIE1        2

#define ICR1  *((volatile u16*)0x46)


/*Define TIMER1 Mode options*/
#define TIMER1_Normal     1
#define TIMER1_CTC        2
#define TIMER1_PWM        3

#endif 
