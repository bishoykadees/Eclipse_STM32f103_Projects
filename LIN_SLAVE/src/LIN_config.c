/* Module Name : LIN
 * File Name   : LIN_config.c
 * Author      : Bishoy Nabil
 * Version     : 1.0
 * Date        : 24/05/2020 */

#include "LIN_config.h"

SlotStruct_t SlotsArray[NUMBER_OF_SLOTS] = {
		{0x01, 20}
};

MsgStruct_t MsgsArray[NUMBER_OF_MESSAGES] = {
		{
				.MessageID     = 0x01,
				.Author        = MESSAGE_LISTENER
		}
};
