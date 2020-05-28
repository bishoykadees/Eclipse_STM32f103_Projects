#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SWITCH_interface.h"
#include "SWITCH_private.h"
#include "SWITCH_config.h"

u8 SWITCH_Port_Arr[8]={SWITCH_ONE_PORT,SWITCH_TWO_PORT,SWITCH_THREE_PORT,SWITCH_FOUR_PORT,SWITCH_FIVE_PORT,SWITCH_SIX_PORT,SWITCH_SEVEN_PORT,SWITCH_EIGHT_PORT};
u8 SWITCH_Pin_Arr[8]={SWITCH_ONE_PIN,SWITCH_TWO_PIN,SWITCH_THREE_PIN,SWITCH_FOUR_PIN,SWITCH_FIVE_PIN,SWITCH_SIX_PIN,SWITCH_SEVEN_PIN,SWITCH_EIGHT_PIN};

u8 getSwitchState(u8 SWITCH_Number)
{
	u8 result;
	result=DIO_GetPinVal(SWITCH_Port_Arr[SWITCH_Number],SWITCH_Pin_Arr[SWITCH_Number]);
	#if RELEASE_STATE==1
	{
		return result;
	}
	#else
	{
		return result^0x01;
	}
	#endif
}
