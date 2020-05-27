/* Module Name : SCHEDULER
 * File Name   : SCHEDULER_config.c
 * Author      : Bishoy Nabil
 * Version     : 2.0
 * Date        : 28/3/2020 */

#define NUMBER_OF_TASKS                  2

#include "SCHEDULER_interface.h"

typedef struct
{
	const TaskInterface_t *const AppTask;
	      u32                    FirstDelayTicks;
}TaskInfo_t;

/* Structures of type TaskInterface_t created by users */
TaskInterface_t LIN_MasterTask;
TaskInterface_t LIN_SlaveTask;

const TaskInfo_t TasksInfo[NUMBER_OF_TASKS] = {
		{&LIN_MasterTask   ,0},
		{&LIN_SlaveTask   ,0}
};






