/********************************
*Author: Mohanad Fawzy Sallam   *
*Version: v01                   *
*Date: 10/02/2020               *
*********************************/
#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H
#include "STD_TYPES.h"
#include "BIT_MATH.h"
typedef struct
{
  void (* TaskHandler)(void);
  u32 periodicity;
  u8 Priority;
}Task;

void RTOS_voidStartOS(void);
void RTOS_voidCreateTask(u8 Copy_u32Priority ,u32 Copy_u32Periodicity,void (* ptr2Func)(void));

#endif
