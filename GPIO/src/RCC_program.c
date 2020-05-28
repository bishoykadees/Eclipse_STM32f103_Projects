
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "RCC_register.h"
#include "RCC_config.h"
#include "RCC_private.h"

static ErrorStatus RCC_CheckSystemClock(u8 Copy_u8Clock)
{
	if(((u32)(Copy_u8Clock<<SWS))==(RCC_CFGR & (u32)(11<<SWS)))
	{
		return OK;
	}
	return NOK;
}

extern ErrorStatus RCC_EnablePLL(u8 Copy_u8PLLClockSelected, u8 Copy_u8HSEDivision, u8 Copy_u8PLLMUL)
{
	/* disable PLL */
	RCC_CR &= (~(1<<PLLON));

	/* switching on HSE is divided by 2 or not */
	switch(Copy_u8HSEDivision)
	{
		case HSE_DIVIDED_BY_TWO_ENABLED:
		{
			RCC_CFGR |= (1<<PLLXTPRE);
		}
		break;
		case HSE_DIVIDED_BY_TWO_DISABLED:
		{
			RCC_CFGR &= (~(1<<PLLXTPRE));
		}
		break;
	}
	
	/* switching on HSE or HSI selected as input to PLL*/
	switch(Copy_u8PLLClockSelected)
	{
		case HSI_PLL:
		{
			RCC_CFGR &= (~(1<<PLLSRC));
		}
		break;
		case HSE_PLL:
		{
			RCC_CFGR |= (1<<PLLSRC);
		}
		break;
	}
	
	/* setting PLL Multiplier */
	RCC_CFGR &= (~(0b1111<<PLLMUL));
	RCC_CFGR |= (Copy_u8PLLMUL<<PLLMUL);

	/* enable PLL */
	RCC_CR |= (0b1<<PLLON);
	
	/* checking that PLL is ready */
	while((0b1<<PLLRDY)&&(RCC_CR)==0);
	return OK;
}
extern ErrorStatus RCC_EnableHSE(void)
{
	RCC_CR |= (0b1<<HSEON);
	while(((0b1<<HSERDY)&(RCC_CR))==0);
	return OK;
}
extern ErrorStatus RCC_EnableHSI(void)
{
	RCC_CR|=(0b1<<HSION);
	while((0b1<<HSIRDY)&&(RCC_CR)==0);
	return OK;
}
extern ErrorStatus RCC_MCOConfiguration(u8 Copy_u8MCOCLockSelected)
{
	RCC_CFGR &= (~(0b111<<MCO));
	RCC_CFGR |= (Copy_u8MCOCLockSelected<<MCO);
	return OK;
}

extern ErrorStatus RCC_DisablePLL(void)
{
	/* disable PLL */
	RCC_CR &= (~(1<<PLLON));
	return OK;
}
extern ErrorStatus RCC_DisableHSE(void)
{
	RCC_CR &= (~(1<<HSEON));
	return OK;
}
extern ErrorStatus RCC_DisableHSI(void)
{
	RCC_CR &= (~(1<<HSION));
	return OK;
}
extern ErrorStatus RCC_EnablePeripheralClock(u8 Copy_u8PeripheralName)
{
	RCC_APB2ENR |= (1<<Copy_u8PeripheralName);
	return OK;
}
extern ErrorStatus RCC_DisablePeripheralClock(u8 Copy_u8PeripheralName)
{
	RCC_APB2ENR &= (~(1<<Copy_u8PeripheralName));
	return OK;
}
extern ErrorStatus RCC_SelectSystemClock(u8 Copy_u8SelectSystemClock)
{
	u32 Local_u8Temp = 0xFFFFFFFC & RCC_CFGR;
	Local_u8Temp |= (Copy_u8SelectSystemClock<<SW);
	RCC_CFGR = Local_u8Temp;
	return RCC_CheckSystemClock(Copy_u8SelectSystemClock);
}


