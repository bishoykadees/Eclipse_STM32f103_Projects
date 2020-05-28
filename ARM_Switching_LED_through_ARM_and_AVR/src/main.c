
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "RCC_interface.h"

void main(void)
{
	/* RCC_Init */
	RCC_Init();

	/* Enable clock on port c */
	RCC_EnablePeripheralClock (2,3);
	RCC_EnablePeripheralClock (2,4);

	/* Set Pin C13 Mode to output 2MHz Push Pull */
	DIO_SetPinMode('B',9,0b0100);

	/* Set Pin C13 Mode to output 2MHz Push Pull */
	DIO_SetPinMode('C',14,0b0010);

	while (1)
	{
		//DIO_SetPinVal('C',13,0);

		if(DIO_GetPinVal('B',9)==1)
		{
			DIO_SetPinVal('C',14,1);
		}
		else
		{
			DIO_SetPinVal('C',14,0);
		}

    }
}
