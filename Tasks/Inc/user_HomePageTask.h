#ifndef __USER_HOMEPAGETASK_H__
#define __USER_HOMEPAGETASK_H__

#ifdef __cplusplus
extern "C" {
#endif

void TimeRenewTask(void *argument);
void HomeUpdata_Task(void *argument);
    
extern uint32_t user_HR_timecount;

#ifdef __cplusplus
}
#endif

#endif

