/*
 * SHEDULAR_config.c
 *
 *  Created on: Mar 28, 2020
 *      Author: Bishoy Nabil
 */

#define MAX                                                100

#include "SCHEDULAR_interface.h"

typedef struct
{
	const TaskInterface_t *const AppTask;
	      u32                    FirstDelayTicks;
}TaskInfo_t;

/* Structures of type TaskInterface_t created by users */
extern TaskInterface_t HLED_Task;
extern TaskInterface_t HSWITCH_Task;
extern TaskInterface_t HLCD_Task;
extern TaskInterface_t AppTask01;
extern TaskInterface_t AppTask02;

extern const TaskInfo_t TasksInfo[MAX] = {
		{&HLED_Task   ,0},
		{&HSWITCH_Task,1},
		{&HLCD_Task   ,2},
		{&AppTask01   ,3},
		{&AppTask02   ,4}
};






