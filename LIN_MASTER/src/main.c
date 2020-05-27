/* Author      : Bishoy Nabil
 * Description : this main is used to test each newly implemented module */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "SCHEDULER_interface.h"
#include "HUSART_interface.h"
#include "LIN_interface.h"


u8 TxBuffer[1000];
u8 RxBuffer[1000];

//void TxCallBack(void);
//void RxCallBack(void);

void main(void)
{
	RCC_EnableAPB2Peripheral(IOPC);
	LIN_Init();

	/*
	PinParam_t GPIOStr;
	TxBuffer[0] = 'B';
	TxBuffer[1] = 'i';
	TxBuffer[2] = 's';
	TxBuffer[3] = 'h';
	TxBuffer[4] = 'o';
	TxBuffer[5] = 'y';


	GPIOStr.Port = PORTC;
	GPIOStr.Pin = PIN13;
	GPIOStr.Mode = OUTPUT_2MHZ_PUSH_PULL;

	DIO_Init(&GPIOStr);

	GPIOStr.Pin = SET_PIN13;

	DIO_SetPinValue(&GPIOStr,SET);
	HUSART_Init(USART1);
	HUSART_SetTxCBF(USART1,&TxCallBack);
	HUSART_SetRxCBF(USART1,&RxCallBack);
	HUSART_Receive(USART1,RxBuffer,6);
	HUSART_Send(USART1,TxBuffer,6);
	 */
	SCHEDULAR_Init();
	SCHEDULAR_Start();


/*
	STKStr.TimeUS = 500000;
	STKStr.CallBackPtr = &LED;
	STKStr.InterruptControl = INTERRUPT_ENABLED;
	STKStr.Prescaler = AHB_DIVIDED_BY_EIGHT;
	STKStr.Cov = &Cov;

	STK_Init(&STKStr);
	STK_SetCallBack(&STKStr);
	STK_SetTime(&STKStr);
	STK_Start();

	RCC_EnableAPB2Peripheral(IOPC);
	GPIOStr.Port = PORTC;
	GPIOStr.Pin = PIN13;
	GPIOStr.Mode = OUTPUT_2MHZ_PUSH_PULL;
	DIO_Init(&GPIOStr);
	GPIOStr.Pin = SET_PIN13;
	DIO_SetPinValue(&GPIOStr , 1);
	*/


	while(1);
}
/*
void TxCallBack(void)
{

}
void RxCallBack(void)
{
	if(TxBuffer[6] == RxBuffer[6])
	{
		PinParam_t GPIOStr;
		GPIOStr.Port = PORTC;
		GPIOStr.Pin = SET_PIN13;
		DIO_SetPinValue(&GPIOStr,RESET);
	}
}
*/
/*
void LED(void)
{
	static u8 i = 0;
	static u8 counter = 0;

	counter ++;

	if(counter < Cov)
	{
		STK_SetMaxPreload();
		STK_Start();
	}
	else
	{
		if(i == 0)
		{
			DIO_SetPinValue(&GPIOStr , 1);
			i=1;
		}
		else if(i == 1)
		{
			DIO_SetPinValue(&GPIOStr , 0);
			i=0;
		}
		STKStr.TimeUS = 500000;
		STK_SetTime(&STKStr);
		counter = 0;
		STK_Start();
	}
}
*/
