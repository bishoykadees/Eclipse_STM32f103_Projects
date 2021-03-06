#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "SYSTICK_interface.h"

#include "CLCD_interface.h"

static u32 SYSTICK_u32Cov=0;
static f64 SYSTICK_f64Preload=0;
static u32 FREQUENCY=100;

void LED_ON(void)
{
	DIO_SetPinVal('C',13,0);
}

void LED_OFF(void)
{
	DIO_SetPinVal('C',13,1);
}

void LED_TOGGLE(void)
{
	static u8 flag=0;
	static u32 counter=0;
	counter++;
	if(counter==SYSTICK_u32Cov)
	{
		STK_voidStart(SYSTICK_f64Preload);
		if(flag==0)
		{
			LED_ON();
			flag=1;
		}
		else if(flag==1)
		{
			LED_OFF();
			flag=0;
		}
		counter=0;
	}
	else
	{
		STK_voidStart(16777215);
	}


}



void main(void)
{
	//RCC_Init();
	CLCD_voidInitialize();
	STK_voidInitialize(0,1);

	RCC_EnablePeripheralClock(2,2);
	RCC_EnablePeripheralClock(2,3);
	RCC_EnablePeripheralClock(2,4);

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

	DIO_SetPinMode('B',11,0b1000);
	DIO_SetPinMode('B',10,0b1000);
	DIO_SetPinVal('B',10,1);
	DIO_SetPinVal('B',11,1);


	CLCD_voidWriteCmd(0x01);
	CLCD_voidWriteData(FREQUENCY);
	//CLCD_voidWriteString((const char *)&FREQUENCY);

	DIO_SetPinVal('C',13,1);
	DIO_SetPinMode('C',13,0b0010);
	STK_voidSetCallBack(&LED_TOGGLE);
	STK_voidCalculateLoadValue(100,8,72000000,&SYSTICK_u32Cov,&SYSTICK_f64Preload);
	STK_voidStart(SYSTICK_f64Preload);

	while(1)
	{
		if(DIO_GetPinVal('B',10)==0)
		{
			STK_voidCalculateLoadValue(FREQUENCY=FREQUENCY+10,8,72000000,&SYSTICK_u32Cov,&SYSTICK_f64Preload);
			STK_voidStart(SYSTICK_f64Preload);
		}
		else if(DIO_GetPinVal('B',11)==0)
		{
			STK_voidCalculateLoadValue(FREQUENCY=FREQUENCY-10,8,72000000,&SYSTICK_u32Cov,&SYSTICK_f64Preload);
			STK_voidStart(SYSTICK_f64Preload);
		}
		while((DIO_GetPinVal('B',10)&&DIO_GetPinVal('B',11))==0);



	}
}
