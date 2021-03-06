/* Module Name : LIN
 * File Name   : LIN_program.c
 * Author      : Bishoy Nabil
 * Version     : 1.0
 * Date        : 23/05/2020 */

#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "SCHEDULER_interface.h"
#include "HUSART_interface.h"
#include "LIN_interface.h"
#include "LIN_config.h"

#define MASTER_TASK                    0
#define SLAVE_TASK                     1

#define ID0                            0
#define ID1                            1
#define ID2                            2
#define ID3                            3
#define ID4                            4
#define ID5                            5

#define S1                             0
#define S2                             1

/* define break character sent flag */
//static u8 vG_u8BreakSentFlag = 0;
/* define sent flag which is set by LIN_TxCallBack */
//static u8 SentFlag = 0;
/* define sent flag which is set by LIN_ReceiveHeaderCBF */
//static u8 vG_u8ReceivedFlag = 0;
/* index of slots */

#if ROLE == MASTER_TASK
static u8 vG_u8SlotsArrayIndex = 0;
#endif

static u8 a2G_u8RXHeaderBuffer[2];

/* used as buffer to send 0x55 and messgae ID */
u8 MasterBuffer[2];

static u8 vG_u8ResponseReceived = 0;

/* used for setting SBK flag */
void LIN_SetBreakFlagCBF(void);
/* called when sending process complete */
void LIN_TxCallBack(void);
/* called when receiving process complete */
void LIN_ReceiveHeaderCBF(void);
void LIN_ReceiveDataCBF(void);

#if ROLE == MASTER_TASK
void LIN_Master_Task(void);
TaskInterface_t LIN_MasterTask = {LIN_Master_Task,1000};
#endif

void LIN_Slave_Task(void);
TaskInterface_t LIN_SlaveTask = {LIN_Slave_Task,1000};

/*************************************************************** LIN_Init ****************************************************************************/
/* this function calculate and update the parity bits of LIN,
 * call setcallback functions
 * and call initLIN function */
ErrorStatus LIN_Init(void)
{
//	/* used as for loop counter */
//	u8 Local_u8Counter = 0;
//	/* LIN first parity bit */
//	u8 Local_u8P0 = 0x00;
//	/* LIN second parity bit */
//	u8 Local_u8P1 = 0x00;
//	/* for loop to calculate P0 and P1 of each message ID and update it to Message ID*/
//	for(Local_u8Counter = 0;Local_u8Counter < NUMBER_OF_SLOTS; Local_u8Counter ++)
//	{
//		/* calculate P0 */
//		Local_u8P0 = (((SlotsArray[Local_u8Counter].MessageID>>ID0)&0x01)^((SlotsArray[Local_u8Counter].MessageID>>ID1)&0x01))^(((SlotsArray[Local_u8Counter].MessageID>>ID2)&0x01)^((SlotsArray[Local_u8Counter].MessageID>>ID4)&0x01));
//		/* calculate P1 */
//		Local_u8P1 = (((SlotsArray[Local_u8Counter].MessageID>>ID1)&0x01)^((SlotsArray[Local_u8Counter].MessageID>>ID3)&0x01))^(((SlotsArray[Local_u8Counter].MessageID>>ID4)&0x01)^((SlotsArray[Local_u8Counter].MessageID>>ID5)&0x01));
//		/* update message ID */
//		SlotsArray[Local_u8Counter].MessageID = (SlotsArray[Local_u8Counter].MessageID << 2) | (Local_u8P0 << 1) | Local_u8P1;
//		MsgsArray[Local_u8Counter].MessageID = (MsgsArray[Local_u8Counter].MessageID << 2) | (Local_u8P0 << 1) | Local_u8P1;
//	}
	HUSART_SetTxCBF(LIN_OVER_USART_CHANNEL, LIN_TxCallBack);
//	HUSART_SetRxCBF(LIN_OVER_USART_CHANNEL, LIN_ReceiveHeaderCBF);
	HUSART_InitLIN(LIN_OVER_USART_CHANNEL, LIN_SetBreakFlagCBF);
	return OK;
}

#if ROLE == MASTER_TASK
/************************************************************** LIN_MasterSlaveTask ******************************************************************/
void LIN_Master_Task(void)
{
	/* used to change th slot state as master or slave */
//	static u8 Local_u8SlotState = MASTER_TASK;
	/* used to check if function set flag is called or not */
	static u8 Local_u8SBKFlagisSet = 0;
	/* used to count ticks and note here we depend on ticktime = 1ms */
	static u8 Local_u8TickCounter = 0;


	/* to check if the current slot time is ended move to the next one */
	if(Local_u8TickCounter == SlotsArray[vG_u8SlotsArrayIndex].SlotTime)
	{
//		Local_u8SlotState = MASTER_TASK;
		vG_u8SlotsArrayIndex ++;
		Local_u8SBKFlagisSet = 0;
	}
	/* increase tick counter by one */
	Local_u8TickCounter ++;

	/* if all slots are finished loop on them again */
	if(vG_u8SlotsArrayIndex == NUMBER_OF_SLOTS)
	{
		vG_u8SlotsArrayIndex = 0;
	}

	/* state machine on master task and slave task */
//	switch(Local_u8SlotState)
//	{
//	case MASTER_TASK:
//	{
		/* setting SBK flag for the first time only in each slot */
		if(Local_u8SBKFlagisSet == 0)
		{
//			HUSART_SetFlag(LIN_OVER_USART_CHANNEL,HUSART_TE_FLAG);
//			HUSART_SetFlag(LIN_OVER_USART_CHANNEL,HUSART_RE_FLAG);
			HUSART_SetFlag(LIN_OVER_USART_CHANNEL,HUSART_SBK_FLAG);
			Local_u8SBKFlagisSet = 1;                                  //need to be reset at end of slot
		}
//		else if(vG_u8BreakSentFlag != 0)
//		{
//			vG_u8BreakSentFlag = 0;
//			MasterBuffer[0] = 0x55;
//			MasterBuffer[1] = SlotsArray[vG_u8SlotsArrayIndex].MessageID;
//			HUSART_Send(LIN_OVER_USART_CHANNEL, MasterBuffer, 2);
//			Local_u8SlotState = SLAVE_TASK;
//		}
//	}break;
//	case SLAVE_TASK:
//		break;
//	}

//	if(vG_u8ReceivedFlag == 1)
//	{
//		static u8 Local_u8Idx = 0;
//		vG_u8ReceivedFlag = 0;
//		static u8 Local_u8RxState = S1;
//		if((Local_u8RxState == S1)&&(a2G_u8RXHeaderBuffer[0] == 0x55))
//		{
//			for(Local_u8Idx = 0;Local_u8Idx < NUMBER_OF_MESSAGES;Local_u8Idx ++)
//			{
//				if(a2G_u8RXHeaderBuffer[1] == MsgsArray[Local_u8Idx].MessageID)
//				{
//					if(MsgsArray[Local_u8Idx].Author == MESSAGE_OWNER)
//					{
//						//MsgsArray[Local_u8Idx].MsgBuffer[0] = 'b';
//						//MsgsArray[Local_u8Idx].MsgBufferSize = 1;
//						HUSART_Send(LIN_OVER_USART_CHANNEL, MsgsArray[Local_u8Idx].MsgBuffer, MsgsArray[Local_u8Idx].MsgBufferSize);
//					}
//					else if(MsgsArray[Local_u8Idx].Author == MESSAGE_LISTENER)
//					{
//						MsgsArray[Local_u8Idx].MsgBufferSize = 1;
//						HUSART_Receive(LIN_OVER_USART_CHANNEL, MsgsArray[Local_u8Idx].MsgBuffer, MsgsArray[Local_u8Idx].MsgBufferSize);
//						Local_u8RxState = S2;
//					}
//					break;
//				}
//			}
//		}
//		else if(Local_u8RxState == S2)
//		{
//			/*
//			if(MsgsArray[1].MsgBuffer[0] == 'b')
//			{
//				PinParam_t GPIOStr;
//				GPIOStr.Port = PORTC;
//				GPIOStr.Pin = PIN13;
//				GPIOStr.Mode = OUTPUT_2MHZ_PUSH_PULL;
//
//				DIO_Init(&GPIOStr);
//			}
//			*/
//			Local_u8RxState = S1;
//		}
//	}
}
#endif

/************************************************************** LIN_SlaveTask ************************************************************************/
void LIN_Slave_Task(void)
{
	if(vG_u8ResponseReceived == 1)
	{
		vG_u8ResponseReceived = 0;
		if(MsgsArray[1].MsgBuffer[0] == 'b')
		{
			PinParam_t GPIOStr;
			GPIOStr.Port = PORTC;
			GPIOStr.Pin = PIN13;
			GPIOStr.Mode = OUTPUT_2MHZ_PUSH_PULL;

			DIO_Init(&GPIOStr);
		}
	}
}

/************************************************************** LIN_SetBreakFlagCBF ******************************************************************/
void LIN_SetBreakFlagCBF(void)
{
	HUSART_SetRxCBF(LIN_OVER_USART_CHANNEL, LIN_ReceiveHeaderCBF);
	HUSART_Receive(LIN_OVER_USART_CHANNEL, a2G_u8RXHeaderBuffer, 2);
	//vG_u8BreakSentFlag = 1;
#if ROLE == MASTER
	MasterBuffer[0] = 0x55;
	MasterBuffer[1] = SlotsArray[vG_u8SlotsArrayIndex].MessageID;
	HUSART_Send(LIN_OVER_USART_CHANNEL, MasterBuffer, 2);
#endif
}

/************************************************************** LIN_TxCallBack ***************************************************************************/
void LIN_TxCallBack(void)
{
	//SentFlag = 1;
}

/************************************************************* LIN_ReceiveHeaderCBF *****************************************************************************/
void LIN_ReceiveHeaderCBF(void)
{
	// for loop index
	static u8 Local_u8Idx = 0;
//	vG_u8ReceivedFlag = 0;
//	static u8 Local_u8RxState = S1;

//	HUSART_Receive(LIN_OVER_USART_CHANNEL, a2G_u8RXHeaderBuffer, 2);
	if(a2G_u8RXHeaderBuffer[0] == 0x55)
	{
		for(Local_u8Idx = 0;Local_u8Idx < NUMBER_OF_MESSAGES;Local_u8Idx ++)
		{
			if(a2G_u8RXHeaderBuffer[1] == MsgsArray[Local_u8Idx].MessageID)
			{
				if(MsgsArray[Local_u8Idx].Author == MESSAGE_OWNER)
				{
					//MsgsArray[Local_u8Idx].MsgBuffer[0] = 'b';
					//MsgsArray[Local_u8Idx].MsgBufferSize = 1;
					HUSART_Send(LIN_OVER_USART_CHANNEL, MsgsArray[Local_u8Idx].MsgBuffer, MsgsArray[Local_u8Idx].MsgBufferSize);
				}
				else if(MsgsArray[Local_u8Idx].Author == MESSAGE_LISTENER)
				{
					HUSART_SetRxCBF(LIN_OVER_USART_CHANNEL, LIN_ReceiveDataCBF);
					MsgsArray[Local_u8Idx].MsgBufferSize = 1;
					HUSART_Receive(LIN_OVER_USART_CHANNEL, MsgsArray[Local_u8Idx].MsgBuffer, MsgsArray[Local_u8Idx].MsgBufferSize);
//					Local_u8RxState = S2;
				}
				break;
			}
		}
	}
}

void LIN_ReceiveDataCBF(void)
{
	vG_u8ResponseReceived = 1;
}
