/* Project Description      : testing LCD using my RCC and the DIO implemented with Assaf
 * Made by                  : Bishoy Nabil
 * Testing & Working Status : Tested and Working */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_interface.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"

void main(void)
{
	RCC_EnableAPB2Peripheral(IOPA);

	DIO_SetPinMode('A',0,0b0010);
	DIO_SetPinMode('A',1,0b0010);
	DIO_SetPinMode('A',2,0b0010);
	DIO_SetPinMode('A',3,0b0010);
	DIO_SetPinMode('A',4,0b0010);
	DIO_SetPinMode('A',5,0b0010);
	DIO_SetPinMode('A',6,0b0010);
	DIO_SetPinMode('A',7,0b0010);
	DIO_SetPinMode('A',8,0b0010);
	DIO_SetPinMode('A',9,0b0010);
	DIO_SetPinMode('A',10,0b0010);

	CLCD_voidInitialize();

	CLCD_voidWriteString("JESUS");

	while(1)
	{
	}

}
