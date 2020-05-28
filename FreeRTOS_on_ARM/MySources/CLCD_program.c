/**************************************************************/
/* Author  : Bishoy Nabil                                     */
/* Version : V01                                              */
/* Date    : 14 Jan 2020                                      */
/**************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_interface.h"
#include "GPIO_interface.h"


#include "CLCD_private.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"


/* Description: This API shall intialize LCD */
void CLCD_voidInitialize(void)
{
	delay_ms(50);
	/* 8-bit interface, 2 lines, 5x7 dots */
	CLCD_voidWriteCmd(0b00111000);
	/* Display ON, Cursor OFF, Blinking OFF */
	CLCD_voidWriteCmd(0b00001100);
	/* clears display and returns cursor to home position */
	CLCD_voidWriteCmd(0b00000001);
}

/* Description: This API shall display data on LCD */
void CLCD_voidWriteData(u8 Copy_u8Data)
{
	PinParam_t Local_GPIOPinStruct;

	/* Set RS = 1 */
	Local_GPIOPinStruct.Port = PORTA;
	Local_GPIOPinStruct.Pin = SET_PIN8;
	DIO_SetPinValue(&Local_GPIOPinStruct,SET);
	/* Set RW = 0 */
	Local_GPIOPinStruct.Pin = SET_PIN9;
	DIO_SetPinValue(&Local_GPIOPinStruct,RESET);
	
	/* Set Data on Data Port */
	CLCD_voidSetDataPort(Copy_u8Data);
	
	/* Enable Pulse */
	CLCD_voidSetEnablePulse();
}

/* Description: This API shall execute command on LCD */
void CLCD_voidWriteCmd(u8 Copy_u8Cmd)
{
	PinParam_t Local_GPIOPinStruct;
	/* Set RS = 0 */
	Local_GPIOPinStruct.Port = PORTA;
	Local_GPIOPinStruct.Pin = SET_PIN8;
	DIO_SetPinValue(&Local_GPIOPinStruct,RESET);
	/* Set RW = 0 */
	Local_GPIOPinStruct.Pin = SET_PIN9;
	DIO_SetPinValue(&Local_GPIOPinStruct,RESET);

	/* Set Data on Data Port */
	CLCD_voidSetDataPort(Copy_u8Cmd);
	
	/* Enable Pulse */
	CLCD_voidSetEnablePulse();

}

static void CLCD_voidSetEnablePulse(void)
{
	PinParam_t Local_GPIOPinStruct;
	Local_GPIOPinStruct.Port = PORTA;
	Local_GPIOPinStruct.Pin = SET_PIN10;
	DIO_SetPinValue(&Local_GPIOPinStruct,SET);
	delay_ms(5);
	DIO_SetPinValue(&Local_GPIOPinStruct,RESET);
	delay_ms(5);
}


static void CLCD_voidSetDataPort(u8 Copy_u8Data)
{
	u8 Local_u8BitVal;
	PinParam_t Local_GPIOPinStruct;

	Local_GPIOPinStruct.Port = PORTA;
	
	Local_u8BitVal=GET_BIT(Copy_u8Data,0);
	Local_GPIOPinStruct.Pin = SET_PIN0;
	DIO_SetPinValue(&Local_GPIOPinStruct,Local_u8BitVal);
	
	Local_u8BitVal=GET_BIT(Copy_u8Data,1);
	Local_GPIOPinStruct.Pin = SET_PIN1;
	DIO_SetPinValue(&Local_GPIOPinStruct,Local_u8BitVal);
	
	Local_u8BitVal=GET_BIT(Copy_u8Data,2);
	Local_GPIOPinStruct.Pin = SET_PIN2;
	DIO_SetPinValue(&Local_GPIOPinStruct,Local_u8BitVal);
	
	Local_u8BitVal=GET_BIT(Copy_u8Data,3);
	Local_GPIOPinStruct.Pin = SET_PIN3;
	DIO_SetPinValue(&Local_GPIOPinStruct,Local_u8BitVal);
	
	Local_u8BitVal=GET_BIT(Copy_u8Data,4);
	Local_GPIOPinStruct.Pin = SET_PIN4;
	DIO_SetPinValue(&Local_GPIOPinStruct,Local_u8BitVal);
	
	Local_u8BitVal=GET_BIT(Copy_u8Data,5);
	Local_GPIOPinStruct.Pin = SET_PIN5;
	DIO_SetPinValue(&Local_GPIOPinStruct,Local_u8BitVal);
	
	Local_u8BitVal=GET_BIT(Copy_u8Data,6);
	Local_GPIOPinStruct.Pin = SET_PIN6;
	DIO_SetPinValue(&Local_GPIOPinStruct,Local_u8BitVal);
	
	Local_u8BitVal=GET_BIT(Copy_u8Data,7);
	Local_GPIOPinStruct.Pin = SET_PIN7;
	DIO_SetPinValue(&Local_GPIOPinStruct,Local_u8BitVal);
}

void CLCD_voidGoToXYPos(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 Local_DDRamAdd;
	if(Copy_u8XPos==CLCD_U8_LINE_ONE)
	{
		Local_DDRamAdd=Copy_u8XPos;
	}
	else if(Copy_u8YPos==CLCD_U8_LINE_TWO)
	{
		Local_DDRamAdd=Copy_u8XPos+CLCD_U8_LINE_TWO_ADD_OFFSET;
	}
	else
	{
		
	}
	CLCD_voidWriteCmd(Local_DDRamAdd|CLCD_U8_SET_DDRAM_ADDRESS_CMD);
}

void CLCD_voidWriteString(const char *Copy_pchString)
{
	while(*Copy_pchString!='\0')
	{
		CLCD_voidWriteData(*Copy_pchString);
		Copy_pchString++;
	}
}
