/********************************************************************************/
/* Author  : Bishoy Nabil                                                       */
/* Date    : 2 Feb 2020                                                         */
/* Version : V01                                                                */
/********************************************************************************/

#ifndef NCIC_INTERFACE_H
#define NCIC_INTERFACE_H

void NVIC_InitPriority(void);
void NVIC_voidSetPriority(u8 Copy_u8Idx, u8 Copy_u8Priority);

void NVIC_voidEnableExtInt (u8 copy_u8Idx);
void NVIC_voidDisableExtInt (u8 copy_u8Idx);

void NVIC_voidSetPendingFlag (u8 copy_u8Idx);
void NVIC_voidClrPendingFlag (u8 copy_u8Idx);

u8 NVIC_u8GetActiveFlag (u8 copy_u8Idx);

#endif

/*tarteeb el inclusion:
el libraries
el layers ely ta7tya
el files bt3ty
*/
