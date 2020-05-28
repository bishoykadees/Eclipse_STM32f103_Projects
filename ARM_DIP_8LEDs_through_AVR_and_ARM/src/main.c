
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "RCC_interface.h"

void main(void)
{
	u8 counter=0;
	u8 flag=0;
	u32 timer=0;

	/* RCC_Init */
	RCC_Init();

	/* Enable clock on port C */
	RCC_EnablePeripheralClock (2,2);
	/* Enable clock on port B */
	RCC_EnablePeripheralClock (2,3);
	/* Enable clock on port C */
	//RCC_EnablePeripheralClock (2,4);

	/* Set Pin B9 Mode to input floating */
	DIO_SetPinMode('B',9,0b0100);

	/* Set Pin B11 Mode to output 2MHz Push Pull */
	DIO_SetPinMode('B',11,0b0010);
	/* Set Pin B10 Mode to output 2MHz Push Pull */
	DIO_SetPinMode('B',10,0b0010);
	/* Set Pin B1  Mode to output 2MHz Push Pull */
	DIO_SetPinMode('B',1,0b0010);
	/* Set Pin B0  Mode to output 2MHz Push Pull */
	DIO_SetPinMode('B',0,0b0010);
	/* Set Pin A7  Mode to output 2MHz Push Pull */
	DIO_SetPinMode('A',7,0b0010);
	/* Set Pin A6  Mode to output 2MHz Push Pull */
	DIO_SetPinMode('A',6,0b0010);
	/* Set Pin A5  Mode to output 2MHz Push Pull */
	DIO_SetPinMode('A',5,0b0010);
	/* Set Pin A4  Mode to output 2MHz Push Pull */
	DIO_SetPinMode('A',4,0b0010);

	while(1)
	{
		if(DIO_GetPinVal('B',9)==1)
		{
			flag=1;
			timer=0;
		}
		if(DIO_GetPinVal('B',9)==0)
		{
			timer++;
			if(flag==1)
			{
				counter++;
				flag=0;
			}
			if(timer>50)
			{
				timer=0;
				switch(counter)
				{
				case 1:
					DIO_SetPinVal('B',11,1);
					break;
				case 2:
					DIO_SetPinVal('B',10,1);
					break;
				case 3:
					DIO_SetPinVal('B',1,1);
					break;
				case 4:
					DIO_SetPinVal('B',0,1);
					break;
				case 5:
					DIO_SetPinVal('A',7,1);
					break;
				case 6:
					DIO_SetPinVal('A',6,1);
					break;
				case 7:
					DIO_SetPinVal('A',5,1);
					break;
				case 8:
					DIO_SetPinVal('A',4,1);
					break;
				}
				counter=0;
			}
		}
	}
}
