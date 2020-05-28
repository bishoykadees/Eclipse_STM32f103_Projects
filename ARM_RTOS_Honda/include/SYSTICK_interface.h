/********************************************************************************/
/* Author  : Bishoy Nabil                                                       */
/* Date    : 4 Feb 2020                                                         */
/* Version : V01                                                                */
/********************************************************************************/

#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

void STK_voidInitialize (u8 Copy_u8ControlClock, u8 Copy_u8ControlInterrupt);
void STK_voidStart (u32 copy_u32Value);
void STK_voidSetCallBack (void (*Copy_Ptr)(void));
void  STK_voidCalculateLoadValue(f64 Copy_f64DesiredFrequency, f64 Copy_f64Prescalar, f64 Copy_f64SystemFrequency, u32 *Copy_u32PtrToCov, f64 *Copy_f64PtrToPreload);

#endif
