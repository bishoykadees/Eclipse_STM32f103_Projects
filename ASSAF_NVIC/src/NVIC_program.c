#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*da tarteeb el file el sa7*/
#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
#include "NVIC_register.h"

void NVIC_InitPriority(void)
{
	#define SCB_AIRCR *((volatile u32*) 0xE000ED0C)
	/* bit 6,7 for group, bit 4,5 for sub */
	SCB_AIRCR = 0x05FA0500;
}

void NVIC_voidSetPriority(u8 Copy_u8Idx, u8 Copy_u8Priority)
{
	NVIC_IPR[Copy_u8Idx]=Copy_u8Priority;
}

void NVIC_voidEnableExtInt (u8 copy_u8Idx)
{
	if(copy_u8Idx <= 31)
	{
		SET_BIT(NVIC_ISER0,copy_u8Idx);
	}
	else if(copy_u8Idx <= 59)
	{
		copy_u8Idx -= 32;
		SET_BIT(NVIC_ISER1,copy_u8Idx);
	}
}
void NVIC_voidDisableExtInt (u8 copy_u8Idx)
{
	if(copy_u8Idx <= 31)
	{
		SET_BIT(NVIC_ICER0,copy_u8Idx);
	}
	else if(copy_u8Idx <= 59)
	{
		copy_u8Idx -= 32;
		SET_BIT(NVIC_ICER1,copy_u8Idx);
	}
}

void NVIC_voidSetPendingFlag (u8 copy_u8Idx)
{
	if(copy_u8Idx <= 31)
	{
		SET_BIT(NVIC_ISPR0,copy_u8Idx);
	}
	else if(copy_u8Idx <= 59)
	{
		copy_u8Idx -= 32;
		SET_BIT(NVIC_ISPR1,copy_u8Idx);
	}
}
void NVIC_voidClrPendingFlag (u8 copy_u8Idx)
{
	if(copy_u8Idx <= 31)
	{
		SET_BIT(NVIC_ICPR0,copy_u8Idx);
	}
	else if(copy_u8Idx <= 59)
	{
		copy_u8Idx -= 32;
		SET_BIT(NVIC_ICPR1,copy_u8Idx);
	}
}

u8 NVIC_u8GetActiveFlag (u8 copy_u8Idx)
{
	u8 Local_u8Result;
	if(copy_u8Idx <= 31)
	{
		SET_BIT(NVIC_IABR0,copy_u8Idx);
	}
	else if(copy_u8Idx <= 59)
	{
		copy_u8Idx -= 32;
		SET_BIT(NVIC_IABR1,copy_u8Idx);
	}
	return Local_u8Result;
}
