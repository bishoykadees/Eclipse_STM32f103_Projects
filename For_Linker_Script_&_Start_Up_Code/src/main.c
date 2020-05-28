
#include "stm32f10x.h"
extern u32* __vectors_start__;


void main (void)
{
	volatile u32* x = __vectors_start__;
	x++;
	while(1);
}
