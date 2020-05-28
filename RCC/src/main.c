/* Project Description      : making a new RCC as required by Turkey not the implemented one with Assaf but
 *                            the DIO is that implemented with Assaf
 * Made by                  : Bishoy Nabil
 * Testing & Working Status : Tested and Working */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DELAY_interface.h"
#include "RCC_interface.h"
#include "RCC_register.h"
#include "DIO_interface.h"
void main(void)
{
	RCC_EnablePeripheralClock(IOPA);
	RCC_EnablePeripheralClock(IOPC);

	DIO_SetPinMode('C',13,0b0010);
	DIO_SetPinMode('A',8,0b1011);

	RCC_EnableHSE();
	RCC_SelectSystemClock(HSE_SYSCLK);

	RCC_EnablePLL(HSE_PLL,HSE_DIVIDED_BY_TWO_DISABLED,PLLx4);
	RCC_SelectSystemClock(PLL_SYSCLK);

	RCC_MCOConfiguration(MCO_SYSCLK_SELECTED);

	while(1)
	{
		DIO_SetPinVal('C',13,1);
		delay_ms(100);
		DIO_SetPinVal('C',13,0);
		delay_ms(100);
	}
}
