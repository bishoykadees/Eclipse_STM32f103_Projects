/********************************************************************************/
/* Author  : Bishoy Nabil                                                       */
/* Date    : 4 Feb 2020                                                         */
/* Version : V01                                                                */
/********************************************************************************/


#ifndef SYSTICK_REGISTER_H
#define SYSTICK_REGISTER_H

#define STK_CTRL *((volatile u32*)0xE000E010)
#define STK_LOAD *((volatile u32*)0xE000E014)
#define STK_VAL  *((volatile u32*)0xE000E018)

#endif
