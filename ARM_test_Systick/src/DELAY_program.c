#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DELAY_interface.h"

void delay_ms(u32 value)
{
/*

*/
	u32 i;
	u32 count =(u32)(((f32)value-(f32)0.00630044444)/(f32)0.00012594444);
	for(i=0;i<count;i++)
	{
		asm("NOP");
	}
}

