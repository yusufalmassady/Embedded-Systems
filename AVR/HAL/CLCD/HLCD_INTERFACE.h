 /*==================================================================================*/
 /**
 * @file         HLCD_INTERFACE.h 
 *
 * \b Description : 
 * This file includes LCD Driver prototypes and macros	  
 *
 * @author      Embedded C TEAM					 								*
 * @date        20/6/2022 																	*
 * @version     V_1	
 * @copyright   IMT_SCHOOL 2022
 */
 /*==================================================================================*/

#ifndef HLCD_INTERFACE_H
#define HLCD_INTERFACE_H

/**************  LIB ********************/
#include "../../00-LIB/STD_TYPES.h"

/************** LCD Modes macros ***************/
#define _4_BIT_MODE  4
#define _8_BIT_MODE  8


/************ Prototypes LCD DRIVERS ***************/
/*==============================================================================*/
/**
 * Prototype   : void HLCD_voidInit(void);
 *
 * \b Description : 
 * Set initialization direction of LCD												
 * @param   void		 										
 * @return  void	
 */ 
/*==============================================================================*/
void HLCD_voidInit(void);


/*==============================================================================*/
/**
 * Prototype   : void HLCD_voidSendCommand(u8 Copy_u8Cmd);
 *
 * \b Description : 
 * Send Command to LCD												
 * @param   Copy_u8Cmd  takes Command		 										
 * @return  void	
 */ 
/*==============================================================================*/
void HLCD_voidSendCommand(u8 Copy_u8Cmd);


/*==============================================================================*/
/**
 * Prototype   : void HLCD_voidDisplayCharacter(u8 Copy_u8Data);
 *
 * \b Description : 
 * Send Char to LCD												
 * @param   Copy_u8Data takes Char		 										
 * @return  void	
 */ 
/*==============================================================================*/
void HLCD_voidDisplayCharacter(u8 Copy_u8Data);

/*==============================================================================*/
/**
 * Prototype   : HLCD_voidClearDisplay(void);
 *
 * \b Description : 
 * Clear LCD Display												
 * @param   void		 										
 * @return  void	
 */ 
/*==============================================================================*/
void HLCD_voidClearDisplay(void);

/*==============================================================================*/
/**
 * Prototype   : HLCD_voidWriteString(u8 *Ptr_u8PtrString);
 *
 * \b Description : 
 * Send String to LCD												
 * @param   *Ptr_u8PtrString  takes String		 										
 * @return  void	
 */ 
/*==============================================================================*/
void HLCD_voidWriteString(u8 *Ptr_u8PtrString);

/*==============================================================================*/
/**
 * Prototype   : HLCD_voidGoToPosition(u8 Copy_u8Row,u8 Copy_u8Col)
 *
 * \b Description : 
 * Send Position to LCD												
 * @param   Copy_u8Row  N.OF ROW	
 * @param   Copy_u8Col  N.OF COL
 * @return  void	
 */ 
/*==============================================================================*/
void HLCD_voidGoToPosition(u8 Copy_u8Row,u8 Copy_u8Col);

/*==============================================================================*/
/**
 * Prototype   : HLCD_voidDisplayNum(s32 Copy_s32Num);
 *
 * \b Description : 
 * Send NUMBER to LCD													
 * @param   Copy_s32Number  Number to be send to LCD	
 * @return  void	
 */ 
/*==============================================================================*/
void HLCD_voidDisplayNum(s32 Copy_s32Num);

/*==============================================================================*/
/**
 * Prototype   : HLCD_voidDisplayFloat(f64 Copy_f64Num)
 *
 * \b Description : 
 * Send Float to LCD													
 * @param   Copy_f64Num  Number to be send to LCD	
 * @return  void	
 */ 
/*==============================================================================*/
void HLCD_voidDisplayFloat(f64 Copy_f64Num)

#endif
