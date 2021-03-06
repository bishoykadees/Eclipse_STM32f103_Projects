#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"

void main(void)
{
	RCC_Init();
	NVIC_InitPriority();
	RCC_EnablePeripheralClock(2,4);
	DIO_SetPinMode('C',13,0b0010);

	NVIC_voidEnableExtInt(37);
	NVIC_voidEnableExtInt(38);

	NVIC_voidSetPriority(37,0b01000000);
	NVIC_voidSetPriority(38,0b00100000);

	NVIC_voidSetPendingFlag(37);

	while(1);
}

void USART1_IRQHandler(void)
{
	DIO_SetPinVal('C',13,0);
	NVIC_voidSetPendingFlag(38);
	while(1);
}

void USART2_IRQHandler(void)
{
	DIO_SetPinVal('C',13,1);
}
