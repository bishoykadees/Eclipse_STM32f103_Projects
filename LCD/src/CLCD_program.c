/**************************************************************/
/* Author  : Bishoy Nabil                                     */
/* Version : V01                                              */
/* Date    : 14 Jan 2020                                      */
/**************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY_interface.h"
#include "DIO_interface.h"


#include "CLCD_private.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"


/* Description: This API shall intialize LCD */
void CLCD_voidInitialize(void)
{
	delay_ms(50);
	CLCD_voidWriteCmd(0b00111000);
	CLCD_voidWriteCmd(0b00001100);
	CLCD_voidWriteCmd(0b00000001);

}

/* Description: This API shall display data on LCD */
void CLCD_voidWriteData(u8 Copy_u8Data)
{
	/* Set RS = 1 */
	DIO_SetPinVal(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,1);
	/* Set RW = 0 */
	DIO_SetPinVal(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);
	

	/* Set Data on Data Port */
	CLCD_voidSetDataPort(Copy_u8Data);
	
	/* Enable Pulse */
	CLCD_voidSetEnablePulse();
	/*
	DIO_SetPinVal(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	delay_ms(5);
	DIO_SetPinVal(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	delay_ms(5);
	*/
}

/* Description: This API shall execute command on LCD */
void CLCD_voidWriteCmd(u8 Copy_u8Cmd)
{
	/* Set RS = 0 */
	DIO_SetPinVal(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);
	/* Set RW = 0 */
	DIO_SetPinVal(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);

	/* Set Data on Data Port */
	CLCD_voidSetDataPort(Copy_u8Cmd);
	
	/* Enable Pulse */
	CLCD_voidSetEnablePulse();
	/*
	DIO_SetPinVal(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	delay_ms(5);
	DIO_SetPinVal(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	delay_ms(5);
	 */
}

static void CLCD_voidSetEnablePulse(void)
{
	/* Enable Pulse : set the enable pin to high for a period of time then it set 's*/
	DIO_SetPinVal(CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
	delay_ms(5);
	DIO_SetPinVal(CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
	delay_ms(5);
}


static void CLCD_voidSetDataPort(u8 Copy_u8Data)
{
	u8 Local_u8BitVal;
	
	Local_u8BitVal=GET_BIT(Copy_u8Data,0);
	DIO_SetPinVal(CLCD_u8_DATA_PORT,CLCD_u8_D0,Local_u8BitVal);
	
	Local_u8BitVal=GET_BIT(Copy_u8Data,1);
	DIO_SetPinVal(CLCD_u8_DATA_PORT,CLCD_u8_D1,Local_u8BitVal);
	
	Local_u8BitVal=GET_BIT(Copy_u8Data,2);
	DIO_SetPinVal(CLCD_u8_DATA_PORT,CLCD_u8_D2,Local_u8BitVal);
	
	Local_u8BitVal=GET_BIT(Copy_u8Data,3);
	DIO_SetPinVal(CLCD_u8_DATA_PORT,CLCD_u8_D3,Local_u8BitVal);
	
	Local_u8BitVal=GET_BIT(Copy_u8Data,4);
	DIO_SetPinVal(CLCD_u8_DATA_PORT,CLCD_u8_D4,Local_u8BitVal);
	
	Local_u8BitVal=GET_BIT(Copy_u8Data,5);
	DIO_SetPinVal(CLCD_u8_DATA_PORT,CLCD_u8_D5,Local_u8BitVal);
	
	Local_u8BitVal=GET_BIT(Copy_u8Data,6);
	DIO_SetPinVal(CLCD_u8_DATA_PORT,CLCD_u8_D6,Local_u8BitVal);
	
	Local_u8BitVal=GET_BIT(Copy_u8Data,7);
	DIO_SetPinVal(CLCD_u8_DATA_PORT,CLCD_u8_D7,Local_u8BitVal);
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
