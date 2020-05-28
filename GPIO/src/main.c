/* Project Description      : building my first GPIO driver and using my own RCC driver
 * Made by                  : Bishoy Nabil
 * Testing & Working Status : Tested and Working */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"

void main(void)
{
	RCC_EnableHSE();
	RCC_SelectSystemClock(HSE_SYSCLK);
	RCC_EnablePeripheralClock(IOPC);
	DIO_SetPinMode(PORTC,PIN13,PIN13_OUTPUT_2MHZ_PUSH_PULL);
}
