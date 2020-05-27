/* Module Name : LIN
 * File Name   : LIN_config.h
 * Author      : Bishoy Nabil
 * Version     : 1.0
 * Date        : 24/4/2020 */

#ifndef LIN_CONFIG_H_
#define LIN_CONFIG_H_

#include "STD_TYPES.h"

#define NUMBER_OF_SLOTS                            1
#define NUMBER_OF_MESSAGES                         1
#define LIN_OVER_USART_CHANNEL                     USART1

#define MESSAGE_OWNER                              0
#define MESSAGE_LISTENER                           1
#define MAX_RESPONSE_FRAME                         8

#define ROLE                                       SLAVE_TASK

typedef struct
{
	u8 MessageID;
	u8 SlotTime;
}SlotStruct_t;

typedef struct
{
	u8 MessageID;
	u8 Author;
	u8 MsgBuffer[MAX_RESPONSE_FRAME];
	u8 MsgBufferSize;
}MsgStruct_t;

extern SlotStruct_t SlotsArray[NUMBER_OF_SLOTS];
extern MsgStruct_t MsgsArray[NUMBER_OF_MESSAGES];

#endif /* LIN_CONFIG_H_ */
