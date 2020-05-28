#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DELAY_interface.h"
#include "DIO_interface.h"
#include "RCC_interface.h"

void main(void)
{
	RCC_EnablePeripheralClock(2,2);
	RCC_EnablePeripheralClock(2,3);
	RCC_EnablePeripheralClock(2,4);


	DIO_SetPinMode('B',12,0b0010);
	DIO_SetPinMode('B',13,0b0010);
	DIO_SetPinMode('B',14,0b0010);
	DIO_SetPinMode('B',15,0b0010);
	DIO_SetPinMode('A',11,0b0010);
	DIO_SetPinMode('A',12,0b0010);
	DIO_SetPinMode('A',15,0b0010);
	DIO_SetPinMode('B',5,0b0010);

	DIO_SetPinMode('B',6,0b0010);
	DIO_SetPinMode('B',7,0b0010);
	DIO_SetPinMode('B',8,0b0010);
	DIO_SetPinMode('B',9,0b0010);
	DIO_SetPinMode('B',11,0b0010);
	DIO_SetPinMode('B',10,0b0010);
	DIO_SetPinMode('B',1,0b0010);
	DIO_SetPinMode('B',0,0b0010);

	DIO_SetPinVal('B',12,1);
	DIO_SetPinVal('B',13,1);
	DIO_SetPinVal('B',14,1);
	DIO_SetPinVal('B',15,1);
	DIO_SetPinVal('A',11,1);
	DIO_SetPinVal('A',12,1);
	DIO_SetPinVal('A',15,1);
	DIO_SetPinVal('B',5,1);



	while(1)
	{

		DIO_SetPinVal('B',7,1);
		DIO_SetPinVal('B',13,0);
		DIO_SetPinVal('B',14,0);
		DIO_SetPinVal('B',15,0);
		DIO_SetPinVal('A',11,0);
		delay_ms(2);
		DIO_SetPinVal('B',7,0);
		DIO_SetPinVal('B',13,1);
		DIO_SetPinVal('B',14,1);
		DIO_SetPinVal('B',15,1);
		DIO_SetPinVal('A',11,1);


		DIO_SetPinVal('B',8,1);
		DIO_SetPinVal('B',13,0);
		DIO_SetPinVal('A',12,0);
		delay_ms(2);
		DIO_SetPinVal('B',8,0);
		DIO_SetPinVal('B',13,1);
		DIO_SetPinVal('A',12,1);


		DIO_SetPinVal('B',9,1);
		DIO_SetPinVal('B',13,0);
		DIO_SetPinVal('A',12,0);
		delay_ms(2);
		DIO_SetPinVal('B',9,0);
		DIO_SetPinVal('B',13,1);
		DIO_SetPinVal('A',12,1);


		DIO_SetPinVal('B',11,1);
		DIO_SetPinVal('B',13,0);
		DIO_SetPinVal('B',14,0);
		DIO_SetPinVal('B',15,0);
		DIO_SetPinVal('A',11,0);
		delay_ms(2);
		DIO_SetPinVal('B',11,0);
		DIO_SetPinVal('B',13,1);
		DIO_SetPinVal('B',14,1);
		DIO_SetPinVal('B',15,1);
		DIO_SetPinVal('A',11,1);

		DIO_SetPinVal('B',8,1);
		DIO_SetPinVal('B',13,0);
		DIO_SetPinVal('A',12,0);
		delay_ms(2);
		DIO_SetPinVal('B',8,0);
		DIO_SetPinVal('B',13,1);
		DIO_SetPinVal('A',12,1);

		DIO_SetPinVal('B',10,1);
		DIO_SetPinVal('B',13,0);
		DIO_SetPinVal('A',12,0);
		delay_ms(2);
		DIO_SetPinVal('B',10,0);
		DIO_SetPinVal('B',13,1);
		DIO_SetPinVal('A',12,1);


		DIO_SetPinVal('B',1,1);
		DIO_SetPinVal('B',13,0);
		DIO_SetPinVal('B',14,0);
		DIO_SetPinVal('B',15,0);
		DIO_SetPinVal('A',11,0);
		delay_ms(2);
		DIO_SetPinVal('B',1,0);
		DIO_SetPinVal('B',13,1);
		DIO_SetPinVal('B',14,1);
		DIO_SetPinVal('B',15,1);
		DIO_SetPinVal('A',11,1);

	}
}
