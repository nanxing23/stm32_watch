#ifndef __USER_STOPENTERTASK_H__
#define __USER_STOPENTERTASK_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "user_TasksInit.h"

void IdleEnterTask(void *argument);
void StopEnterTask(void *argument);
void IdleTimerCallback(void *argument);

extern uint16_t IdleTimerCount;
extern uint8_t ui_LTimeValue;
extern uint8_t ui_TTimeValue;

#ifdef __cplusplus
}
#endif

#endif

