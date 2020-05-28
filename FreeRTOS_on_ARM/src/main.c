#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "queue.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "CLCD_interface.h"

void LCDTask( void *pvParameters );

void main(void)
{
	PinParam_t Local_GPIOPinStruct;

	RCC_EnableAPB2Peripheral(IOPA);

	Local_GPIOPinStruct.Port = PORTA;
	Local_GPIOPinStruct.Mode = OUTPUT_2MHZ_PUSH_PULL;

	Local_GPIOPinStruct.Pin = PIN0;
	DIO_Init(&Local_GPIOPinStruct);
	Local_GPIOPinStruct.Pin = PIN1;
	DIO_Init(&Local_GPIOPinStruct);
	Local_GPIOPinStruct.Pin = PIN2;
	DIO_Init(&Local_GPIOPinStruct);
	Local_GPIOPinStruct.Pin = PIN3;
	DIO_Init(&Local_GPIOPinStruct);
	Local_GPIOPinStruct.Pin = PIN4;
	DIO_Init(&Local_GPIOPinStruct);
	Local_GPIOPinStruct.Pin = PIN5;
	DIO_Init(&Local_GPIOPinStruct);
	Local_GPIOPinStruct.Pin = PIN6;
	DIO_Init(&Local_GPIOPinStruct);
	Local_GPIOPinStruct.Pin = PIN7;
	DIO_Init(&Local_GPIOPinStruct);
	Local_GPIOPinStruct.Pin = PIN8;
	DIO_Init(&Local_GPIOPinStruct);
	Local_GPIOPinStruct.Pin = PIN9;
	DIO_Init(&Local_GPIOPinStruct);
	Local_GPIOPinStruct.Pin = PIN10;
	DIO_Init(&Local_GPIOPinStruct);

	CLCD_voidInitialize();
	xTaskCreate( LCDTask, "LCD", configMINIMAL_STACK_SIZE, NULL, 1, NULL );
	vTaskStartScheduler();
}

void LCDTask( void *pvParameters )
{
		CLCD_voidWriteCmd(0x01);
		CLCD_voidWriteString("Task 05");
}
