 /*==================================================================================*/
 /**
 * @file         HLCD_CONFIG.h
 *
 * \b Description : 
 * This file includes LCD Driver Configurations	  
 *
 * @author      Embedded C TEAM					 								*
 * @date        20/6/2022 																	*
 * @version     V_1	
 * @copyright   IMT_SCHOOL 2022
 */
 /*==================================================================================*/
#ifndef HLCD_CONFIG_H
#define HLCD_CONFIG_H

/**==========================================*
* SELECT LCD MODE oPTION  :					*
*						1)_4_BIT_MODE		*
*						2)_8_BIT_MODE		*
*===========================================*/
#define LCD_MODE         _4_BIT_MODE

/**==========================================*
* SELECT LCD DATA PORT oPTION  :			*
*						1)DIO_u8_PORTA		*
*						2)DIO_u8_PORTB		*
*						1)DIO_u8_PORTC		*
*						2)DIO_u8_PORTD		*
*===========================================*/
#define LCD_DATA_PORT    DIO_u8_PORTD

/**==========================================*
* SELECT LCD DATA PIN oPTION  :				*
*						== > DIO_u8_PINx	*
*===========================================*/
#define LCD_DATA_PIN_4   DIO_u8_PIN2
#define LCD_DATA_PIN_5	 DIO_u8_PIN3
#define LCD_DATA_PIN_6	 DIO_u8_PIN4
#define LCD_DATA_PIN_7	 DIO_u8_PIN5

/**==========================================*
* SELECT LCD CONTROL PINS oPTION  :			*
*						== > DIO_u8_PINx	*
*===========================================*/
#define LCD_RS_PIN       DIO_u8_PIN6
#define LCD_EN_PIN       DIO_u8_PIN7


#endif
