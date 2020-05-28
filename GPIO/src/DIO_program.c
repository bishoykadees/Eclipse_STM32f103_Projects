#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"

ErrorStatus DIO_SetPinMode (u8 Copy_u8Port, u8 Copy_u8Pin, u32 Copy_u8Mode)
{
	u8 Local_u8ErrorStatus=OK;
	switch(Copy_u8Port)
	{
		case PORTA:
		{
			switch(Copy_u8Pin)
			{
				case PIN0:
				{
					PORTA_CRL &= CNFMODE0_CLEAR;
					PORTA_CRL |= Copy_u8Mode;
					break;
				}
				case PIN1:
				{
					PORTA_CRL &= CNFMODE1_CLEAR;
					PORTA_CRL |= Copy_u8Mode;
					break;
				}
				case PIN2:
				{
					PORTA_CRL &= CNFMODE2_CLEAR;
					PORTA_CRL |= Copy_u8Mode;
					break;
				}
				case PIN3:
				{
					PORTA_CRL &= CNFMODE3_CLEAR;
					PORTA_CRL |= Copy_u8Mode;
					break;
				}
				case PIN4:
				{
					PORTA_CRL &= CNFMODE4_CLEAR;
					PORTA_CRL |= Copy_u8Mode;
					break;
				}
				case PIN5:
				{
					PORTA_CRL &= CNFMODE5_CLEAR;
					PORTA_CRL |= Copy_u8Mode;
					break;
				}
				case PIN6:
				{
					PORTA_CRL &= CNFMODE6_CLEAR;
					PORTA_CRL |= Copy_u8Mode;
					break;
				}
				case PIN7:
				{
					PORTA_CRL &= CNFMODE7_CLEAR;
					PORTA_CRL |= Copy_u8Mode;
					break;
				}
				case PIN8:
				{
					PORTA_CRH &= CNFMODE8_CLEAR;
					PORTA_CRH |= Copy_u8Mode;
					break;
				}
				case PIN9:
				{
					PORTA_CRH &= CNFMODE9_CLEAR;
					PORTA_CRH |= Copy_u8Mode;
					break;
				}
				case PIN10:
				{
					PORTA_CRH &= CNFMODE10_CLEAR;
					PORTA_CRH |= Copy_u8Mode;
					break;
				}
				case PIN11:
				{
					PORTA_CRH &= CNFMODE11_CLEAR;
					PORTA_CRH |= Copy_u8Mode;
					break;
				}
				case PIN12:
				{
					PORTA_CRH &= CNFMODE12_CLEAR;
					PORTA_CRH |= Copy_u8Mode;
					break;
				}
				case PIN13:
				{
					PORTA_CRH &= CNFMODE13_CLEAR;
					PORTA_CRH |= Copy_u8Mode;
					break;
				}
				case PIN14:
				{
					PORTA_CRH &= CNFMODE14_CLEAR;
					PORTA_CRH |= Copy_u8Mode;
					break;
				}
				case PIN15:
				{
					PORTA_CRH &= CNFMODE15_CLEAR;
					PORTA_CRH |= Copy_u8Mode;
					break;
				}
				default:
				{
					Local_u8ErrorStatus = NOK;
				}
			}
			break;
		}
		case PORTB:
		{
			switch(Copy_u8Pin)
			{
				case PIN0:
				{
					PORTB_CRL &= CNFMODE0_CLEAR;
					PORTB_CRL |= Copy_u8Mode;
					break;
				}
				case PIN1:
				{
					PORTB_CRL &= CNFMODE1_CLEAR;
					PORTB_CRL |= Copy_u8Mode;
					break;
				}
				case PIN2:
				{
					PORTB_CRL &= CNFMODE2_CLEAR;
					PORTB_CRL |= Copy_u8Mode;
					break;
				}
				case PIN3:
				{
					PORTB_CRL &= CNFMODE3_CLEAR;
					PORTB_CRL |= Copy_u8Mode;
					break;
				}
				case PIN4:
				{
					PORTB_CRL &= CNFMODE4_CLEAR;
					PORTB_CRL |= Copy_u8Mode;
					break;
				}
				case PIN5:
				{
					PORTB_CRL &= CNFMODE5_CLEAR;
					PORTB_CRL |= Copy_u8Mode;
					break;
				}
				case PIN6:
				{
					PORTB_CRL &= CNFMODE6_CLEAR;
					PORTB_CRL |= Copy_u8Mode;
					break;
				}
				case PIN7:
				{
					PORTB_CRL &= CNFMODE7_CLEAR;
					PORTB_CRL |= Copy_u8Mode;
					break;
				}
				case PIN8:
				{
					PORTB_CRH &= CNFMODE8_CLEAR;
					PORTB_CRH |= Copy_u8Mode;
					break;
				}
				case PIN9:
				{
					PORTB_CRH &= CNFMODE9_CLEAR;
					PORTB_CRH |= Copy_u8Mode;
					break;
				}
				case PIN10:
				{
					PORTB_CRH &= CNFMODE10_CLEAR;
					PORTB_CRH |= Copy_u8Mode;
					break;
				}
				case PIN11:
				{
					PORTB_CRH &= CNFMODE11_CLEAR;
					PORTB_CRH |= Copy_u8Mode;
					break;
				}
				case PIN12:
				{
					PORTB_CRH &= CNFMODE12_CLEAR;
					PORTB_CRH |= Copy_u8Mode;
					break;
				}
				case PIN13:
				{
					PORTB_CRH &= CNFMODE13_CLEAR;
					PORTB_CRH |= Copy_u8Mode;
					break;
				}
				case PIN14:
				{
					PORTB_CRH &= CNFMODE14_CLEAR;
					PORTB_CRH |= Copy_u8Mode;
					break;
				}
				case PIN15:
				{
					PORTB_CRH &= CNFMODE15_CLEAR;
					PORTB_CRH |= Copy_u8Mode;
					break;
				}
				default:
				{
					Local_u8ErrorStatus = NOK;
				}
			}
			break;
		}
		case PORTC:
		{
			switch(Copy_u8Pin)
			{
				case PIN0:
				{
					PORTC_CRL &= CNFMODE0_CLEAR;
					PORTC_CRL |= Copy_u8Mode;
					break;
				}
				case PIN1:
				{
					PORTC_CRL &= CNFMODE1_CLEAR;
					PORTC_CRL |= Copy_u8Mode;
					break;
				}
				case PIN2:
				{
					PORTC_CRL &= CNFMODE2_CLEAR;
					PORTC_CRL |= Copy_u8Mode;
					break;
				}
				case PIN3:
				{
					PORTC_CRL &= CNFMODE3_CLEAR;
					PORTC_CRL |= Copy_u8Mode;
					break;
				}
				case PIN4:
				{
					PORTC_CRL &= CNFMODE4_CLEAR;
					PORTC_CRL |= Copy_u8Mode;
					break;
				}
				case PIN5:
				{
					PORTC_CRL &= CNFMODE5_CLEAR;
					PORTC_CRL |= Copy_u8Mode;
					break;
				}
				case PIN6:
				{
					PORTC_CRL &= CNFMODE6_CLEAR;
					PORTC_CRL |= Copy_u8Mode;
					break;
				}
				case PIN7:
				{
					PORTC_CRL &= CNFMODE7_CLEAR;
					PORTC_CRL |= Copy_u8Mode;
					break;
				}
				case PIN8:
				{
					PORTC_CRH &= CNFMODE8_CLEAR;
					PORTC_CRH |= Copy_u8Mode;
					break;
				}
				case PIN9:
				{
					PORTC_CRH &= CNFMODE9_CLEAR;
					PORTC_CRH |= Copy_u8Mode;
					break;
				}
				case PIN10:
				{
					PORTC_CRH &= CNFMODE10_CLEAR;
					PORTC_CRH |= Copy_u8Mode;
					break;
				}
				case PIN11:
				{
					PORTC_CRH &= CNFMODE11_CLEAR;
					PORTC_CRH |= Copy_u8Mode;
					break;
				}
				case PIN12:
				{
					PORTC_CRH &= CNFMODE12_CLEAR;
					PORTC_CRH |= Copy_u8Mode;
					break;
				}
				case PIN13:
				{
					PORTC_CRH &= CNFMODE13_CLEAR;
					PORTC_CRH |= Copy_u8Mode;
					break;
				}
				case PIN14:
				{
					PORTC_CRH &= CNFMODE14_CLEAR;
					PORTC_CRH |= Copy_u8Mode;
					break;
				}
				case PIN15:
				{
					PORTC_CRH &= CNFMODE15_CLEAR;
					PORTC_CRH |= Copy_u8Mode;
					break;
				}
				default:
				{
					Local_u8ErrorStatus = NOK;
				}
			}
			break;
			default:
			{
				Local_u8ErrorStatus = NOK;
			}
		}
	}
	return Local_u8ErrorStatus;
}

ErrorStatus DIO_SetPin (u8 Copy_u8Port, u32 Copy_u8Pin)
{
	u8 Local_u8ErrorStatus = OK;
	switch(Copy_u8Port)
	{
		case PORTA:
		{
			PORTA_BSRR |= Copy_u8Pin;
		}
		break;
		case PORTB:
		{
			PORTB_BSRR |= Copy_u8Pin;
		}
		break;
		case PORTC:
		{
			PORTC_BSRR |= Copy_u8Pin;
		}
		break;
		default:
		{
			Local_u8ErrorStatus = NOK;
		}
	}
	return Local_u8ErrorStatus;
}
ErrorStatus DIO_ResetPin (u8 Copy_u8Port, u32 Copy_u8Pin)
{
	u8 Local_u8ErrorStatus = OK;
	switch(Copy_u8Port)
	{
		case PORTA:
		{
			PORTA_BRR |= Copy_u8Pin;
		}
		break;
		case PORTB:
		{
			PORTA_BRR |= Copy_u8Pin;
		}
		break;
		case PORTC:
		{
			PORTA_BRR |= Copy_u8Pin;
		}
		break;
		default:
		{
			Local_u8ErrorStatus = NOK;
		}
	}
	return Local_u8ErrorStatus;
}
ErrorStatus DIO_GetPinValue (u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_u8ValuePtr)
{
	u8 Local_u8ErrorStatus = OK;
	switch(Copy_u8Port)
	{
		case PORTA:
		{
			*Copy_u8ValuePtr = (PORTA_IDR >> Copy_u8Pin)&(0x00000001);
		}
		break;
		case PORTB:
		{
			*Copy_u8ValuePtr = (PORTB_IDR >> Copy_u8Pin)&(0x00000001);
		}
		break;
		case PORTC:
		{
			*Copy_u8ValuePtr = (PORTC_IDR >> Copy_u8Pin)&(0x00000001);
		}
		break;
		default:
		{
			Local_u8ErrorStatus = NOK;
		}
	}
	return Local_u8ErrorStatus;
}
