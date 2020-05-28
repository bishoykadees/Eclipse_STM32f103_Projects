
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RTOS_config.h"
#include "RTOS_interface.h"
#include "SYSTICK_interface.h"
Task SysTasks [ NUM_OF_TASKS ];
void RTOS_voidSchedular (void)
{
  u8 i=0;
  static u32 Local_u32TickCounter=0;
  Local_u32TickCounter++;
  for (i=0;i<NUM_OF_TASKS;i++)
  {
    if (!(Local_u32TickCounter %SysTasks[i].periodicity))
    {
      (SysTasks[i].TaskHandler)();
    }
  }
  if (Local_u32TickCounter == TICK_OVF_LIMIT )
  {
    Local_u32TickCounter=0;
  }
}
void RTOS_voidStartOS(void)
{
  STK_voidInitialize(1,0);
  STK_voidSetCallBack (RTOS_voidSchedular);
  STK_voidStart(TICK_TIME);
}
void RTOS_voidCreateTask(u8 Copy_u32Priority ,u32 Copy_u32Periodicity,void (* ptr2Func)(void))
{
  SysTasks[Copy_u32Priority].periodicity=Copy_u32Periodicity;
  SysTasks[Copy_u32Priority].TaskHandler=ptr2Func;
}
