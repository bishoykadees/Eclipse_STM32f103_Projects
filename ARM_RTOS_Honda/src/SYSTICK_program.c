/********************************************************************************/
/* Author  : Bishoy Nabil                                                       */
/* Date    : 4 Feb 2020                                                         */
/* Version : V01                                                                */
/********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*da tarteeb el file el sa7*/
#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"
#include "SYSTICK_register.h"

void (*Systick_CallBack) (void);

void STK_voidInitialize (u8 Copy_u8ControlClock, u8 Copy_u8ControlInterrupt)
{
	if(Copy_u8ControlClock==0)
	{
		CLR_BIT(STK_CTRL,CLKSOURSE);
	}
	else if(Copy_u8ControlClock==1)
	{
		SET_BIT(STK_CTRL,CLKSOURSE);
	}

	if(Copy_u8ControlInterrupt==0)
	{
		CLR_BIT(STK_CTRL,TICKINT);
	}
	else if(Copy_u8ControlInterrupt==1)
	{
		SET_BIT(STK_CTRL,TICKINT);
	}


}
void STK_voidStart (u32 Copy_u32ReloadValue)
{
	/* Load Value into Load Register */
	STK_LOAD = Copy_u32ReloadValue;
	/* Clear Value Register */
	STK_VAL = 0;
	/* Start System Timer */
	SET_BIT(STK_CTRL,ENABLE);
}

void  STK_voidCalculateLoadValue(f64 Copy_f64DesiredFrequency, f64 Copy_f64Prescalar, f64 Copy_f64SystemFrequency, u32 *Copy_u32PtrToCov, f64 *Copy_f64PtrToPreload)
{
	f64 Local_f64Cov=0;
	Local_f64Cov= ( (((f64)1)/Copy_f64DesiredFrequency)/((f64)2) * Copy_f64SystemFrequency )/( (f64)16777216 * Copy_f64Prescalar );
	*Copy_f64PtrToPreload = ((f64)Local_f64Cov - (u32)Local_f64Cov) * (f64)16777216;
	*Copy_u32PtrToCov = (u32)Local_f64Cov + 1;
}

void STK_voidSetCallBack (void (*Copy_Ptr)(void))
{
	Systick_CallBack = Copy_Ptr;
}

void SysTick_Handler(void)
{
	Systick_CallBack();
}
