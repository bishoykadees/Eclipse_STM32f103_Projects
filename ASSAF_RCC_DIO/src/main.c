/* Project Description      : RCC and DIO drivers implemented with Assaf
 * Made by                  : Bishoy Nabil
 * Testing & Working Status : Tested and Working */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "RCC_interface.h"

void main(void)
{
	u32 counter = 0;

	/* RCC_Init */
	RCC_Init();

	/* Enable clock on port c */
	RCC_EnablePeripheralClock (2,4);

	/* Set Pin C13 Mode to output 2MHz Push Pull */
	DIO_SetPinMode('C',13,0b0010);

	while (1)
	{
		/* Set pin c13 value to low */
		DIO_SetPinVal('C',13,1);
		for(counter = 0;counter < 1000000;counter++);
		DIO_SetPinVal('C',13,0);
		for(counter = 0;counter < 1000000;counter++);
    }
}
