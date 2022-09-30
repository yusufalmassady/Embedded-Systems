

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

void USART_Init ();

void USART_voidSend(u8 Copy_u8data);

u8 USART_u8Receive(void);

void USART_voidSendString(u8 *Copy_u8CharArr);

void USART_voidRecieveString(u8 *Copy_u8CharArr);

#endif
