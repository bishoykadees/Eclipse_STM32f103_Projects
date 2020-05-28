
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H
#include "BIT_MATH.h"
#include "STD_TYPES.h"
extern void RCC_Init(void);
extern void RCC_EnablePeripheralClock (u8 Bus, u8 Peripheral);
extern void RCC_DisablePeripheralClock(u8 Bus, u8 Peripheral);

#endif
