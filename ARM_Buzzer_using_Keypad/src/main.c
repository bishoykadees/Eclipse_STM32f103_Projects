
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "RCC_interface.h"

#include "SWITCH_interface.h"

void main(void)
{
	u32 i=0;

	/* RCC_Init */
	RCC_Init();

	/* Enable clock on port A */
	RCC_EnablePeripheralClock (2,2);

	/* Enable clock on port B */
	RCC_EnablePeripheralClock (2,3);

	/* Enable clock on port C */
	//RCC_EnablePeripheralClock (2,4);

	/* Set Pin B9 Mode to input floating */
	//DIO_SetPinMode('B',9,0b0100);

	/* Set Pin B11 Mode to output 2MHz Push Pull */
	DIO_SetPinMode('B',11,0b0010);

	/* Set Pin B12 Mode to input pull up */
	DIO_SetPinMode('B',12,0b1000);
	DIO_SetPinVal('B',12,1);

	/* Set Pin B13 Mode to input pull up */
	DIO_SetPinMode('B',13,0b1000);
	DIO_SetPinVal('B',13,1);

	/* Set Pin B14 Mode to input pull up */
	DIO_SetPinMode('B',14,0b1000);
	DIO_SetPinVal('B',14,1);

	/* Set Pin B15 Mode to input pull up */
	DIO_SetPinMode('B',15,0b1000);
	DIO_SetPinVal('B',15,1);

	/* Set Pin A8 Mode to input pull up */
	DIO_SetPinMode('A',8,0b1000);
	DIO_SetPinVal('A',8,1);

	/* Set Pin A9 Mode to input pull up */
	DIO_SetPinMode('A',9,0b1000);
	DIO_SetPinVal('A',9,1);

	/* Set Pin A10 Mode to input pull up */
	DIO_SetPinMode('A',10,0b1000);
	DIO_SetPinVal('A',10,1);

	/* Set Pin A11 Mode to input pull up */
	DIO_SetPinMode('A',11,0b1000);
	DIO_SetPinVal('A',11,1);

	while(1)
	{
		if(getSwitchState(0)==1)
		{
			for(i=0;i<100;i++)
			{
				DIO_SetPinVal('B',11,1);
				for(i=0;i<150;i++);
				DIO_SetPinVal('B',11,0);
				for(i=0;i<150;i++);
			}
		}
		else if(getSwitchState(1)==1)
		{
			for(i=0;i<100;i++)
			{
				DIO_SetPinVal('B',11,1);
				for(i=0;i<200;i++);
				DIO_SetPinVal('B',11,0);
				for(i=0;i<200;i++);
			}
		}
		else if(getSwitchState(2)==1)
		{
			for(i=0;i<100;i++)
			{
				DIO_SetPinVal('B',11,1);
				for(i=0;i<250;i++);
				DIO_SetPinVal('B',11,0);
				for(i=0;i<250;i++);
			}
		}
		else if(getSwitchState(3)==1)
		{
			for(i=0;i<100;i++)
			{
				DIO_SetPinVal('B',11,1);
				for(i=0;i<300;i++);
				DIO_SetPinVal('B',11,0);
				for(i=0;i<300;i++);
			}
		}
		else if(getSwitchState(4)==1)
		{
			for(i=0;i<100;i++)
			{
				DIO_SetPinVal('B',11,1);
				for(i=0;i<350;i++);
				DIO_SetPinVal('B',11,0);
				for(i=0;i<350;i++);
			}
		}
		else if(getSwitchState(5)==1)
		{
			for(i=0;i<100;i++)
			{
				DIO_SetPinVal('B',11,1);
				for(i=0;i<400;i++);
				DIO_SetPinVal('B',11,0);
				for(i=0;i<400;i++);
			}
		}
		else if(getSwitchState(6)==1)
		{
			for(i=0;i<100;i++)
			{
				DIO_SetPinVal('B',11,1);
				for(i=0;i<450;i++);
				DIO_SetPinVal('B',11,0);
				for(i=0;i<450;i++);
			}
		}
		else if(getSwitchState(7)==1)
		{
			for(i=0;i<100;i++)
			{
				DIO_SetPinVal('B',11,1);
				for(i=0;i<100;i++);
				DIO_SetPinVal('B',11,0);
				for(i=0;i<100;i++);
			}
		}

	}
}
