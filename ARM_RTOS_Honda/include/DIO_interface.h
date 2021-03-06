#ifndef DIO_INTERFACE
#define DIO_INTERFACE
#include "BIT_MATH.h"
#include "STD_TYPES.h"
void DIO_SetPinMode (u8 Port, u8 Pin, u8 Mode);
void DIO_SetPinVal (u8 Port, u8 Pin, u8 Val);
u8 DIO_GetPinVal (u8 Port, u8 Pin);

#endif
