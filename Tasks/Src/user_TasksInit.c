/* Private includes -----------------------------------------------------------*/
//includes
#include "user_TasksInit.h"
//sys
#include "sys.h"
#include "stdio.h"
#include "lcd.h"
#include "WDOG.h"
//gui
#include "../../lvgl.h"
#include "gui_guider.h"

//tasks
#include "user_ScrRenewTask.h"
#include "user_HomePageTask.h"
#include "user_MessageSendTask.h"
#include "user_StopEnterTask.h"
#include "user_MPUCheckTask.h"
#include "user_DataSaveTask.h"
#include "user_ChargPageTask.h"
//tasks


/* Private typedef -----------------------------------------------------------*/


/* Private define ------------------------------------------------------------*/


/**************私有变量******************/
extern lv_ui guider_ui;

/* Timers --------------------------------------------------------------------*/
osTimerId_t IdleTimerHandle;


/* Tasks ---------------------------------------------------------------------*/

//WDOG Feed task
osThreadId_t WDOGFeedTaskHandle;
const osThreadAttr_t WDOGFeedTask_attributes = {
  .name = "WDOGFeedTask",
  .stack_size = 128 * 1,
  .priority = (osPriority_t) osPriorityHigh2,
};

//ScrRenew task，按键返回、home
osThreadId_t ScrRenewTaskHandle;
const osThreadAttr_t ScrRenewTask_attributes = {
  .name = "ScrRenewTask",
  .stack_size = 128 * 10,
  .priority = (osPriority_t) osPriorityLow1,
};
//TimeRenew task，更新时间
osThreadId_t TimeRenewTaskHandle;
const osThreadAttr_t TimeRenewTask_attributes = {
  .name = "TimeRenewTask",
  .stack_size = 128 * 5,
  .priority = (osPriority_t) osPriorityLow1,
};
//messagesendtask，蓝牙发送
osThreadId_t MessageSendTaskHandle;
const osThreadAttr_t MessageSendTask_attributes = {
  .name = "MessageSendTask",
  .stack_size = 128 * 5,
  .priority = (osPriority_t) osPriorityLow1,
};
//Stop Enter Task，锁屏
osThreadId_t StopEnterTaskHandle;
const osThreadAttr_t StopEnterTask_attributes = {
  .name = "StopEnterTask",
  .stack_size = 128 * 16,
  .priority = (osPriority_t) osPriorityHigh1,
};
//Idle Enter Task，息屏
osThreadId_t IdleEnterTaskHandle;
const osThreadAttr_t IdleEnterTask_attributes = {
  .name = "IdleEnterTask",
  .stack_size = 128 * 1,
  .priority = (osPriority_t) osPriorityHigh,
};
//HomeUpdata task，主页传感器更新
osThreadId_t HomeUpdataTaskHandle;
const osThreadAttr_t HomeUpdataTask_attributes = {
  .name = "HomeUpdataTask",
  .stack_size = 128 * 5,
  .priority = (osPriority_t) osPriorityLow1,
};
//MPUCheckTask ,检查MPU的状态
osThreadId_t MPUCheckTaskHandle;
const osThreadAttr_t MPUCheckTask_attributes = {
  .name = "MPUCheckTask",
  .stack_size = 128 * 3,
  .priority = (osPriority_t) osPriorityLow2,
};
//DataSaveTask，eeprom保存数据
osThreadId_t DataSaveTaskHandle;
const osThreadAttr_t DataSaveTask_attributes = {
  .name = "DataSaveTask",
  .stack_size = 128 * 5,
  .priority = (osPriority_t) osPriorityLow2,
};
//ChargPageEnterTask,充电标志
osThreadId_t ChargPageEnterTaskHandle;
const osThreadAttr_t ChargPageEnterTask_attributes = {
  .name = "ChargPageEnterTask",
  .stack_size = 128 * 10,
  .priority = (osPriority_t) osPriorityLow1,
};


/* Message queues ------------------------------------------------------------*/
//Key message
osMessageQueueId_t Key_MessageQueue;
osMessageQueueId_t Idle_MessageQueue;
osMessageQueueId_t Stop_MessageQueue;
osMessageQueueId_t IdleBreak_MessageQueue;
osMessageQueueId_t DataSave_MessageQueue;

/* Private function prototypes -----------------------------------------------*/
void WDOGFeedTask(void *argument);

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void User_Tasks_Init(void) 
{
  /* 添加time中断 */
/*
    用于计算当前亮屏时间，到达时间后息屏
*/
	IdleTimerHandle = osTimerNew(IdleTimerCallback, osTimerPeriodic, NULL, NULL);
	osTimerStart(IdleTimerHandle,100);//100ms
	
  /* 添加队列 */
	Key_MessageQueue  = osMessageQueueNew(1, 1, NULL);//按键的队列用于传递
	Idle_MessageQueue = osMessageQueueNew(1, 1, NULL);//一段时间未操作调低亮度
	Stop_MessageQueue = osMessageQueueNew(1, 1, NULL);//长时间未操作息屏
	IdleBreak_MessageQueue = osMessageQueueNew(1, 1, NULL);//有按键或屏幕按动
	DataSave_MessageQueue = osMessageQueueNew(2, 1, NULL);
	
	/* 添加线程任务 */
    WDOGFeedTaskHandle   = osThreadNew(WDOGFeedTask, NULL, &WDOGFeedTask_attributes);
	IdleEnterTaskHandle  = osThreadNew(IdleEnterTask, NULL, &IdleEnterTask_attributes);
	StopEnterTaskHandle  = osThreadNew(StopEnterTask, NULL, &StopEnterTask_attributes);
    ScrRenewTaskHandle   = osThreadNew(ScrRenewTask, NULL, &ScrRenewTask_attributes);
	TimeRenewTaskHandle  = osThreadNew(TimeRenewTask, (void*)&guider_ui, &TimeRenewTask_attributes);
	HomeUpdataTaskHandle = osThreadNew(HomeUpdata_Task, NULL, &HomeUpdataTask_attributes);
	ChargPageEnterTaskHandle = osThreadNew(ChargPageEnterTask, NULL, &ChargPageEnterTask_attributes);
    MessageSendTaskHandle = osThreadNew(MessageSendTask, NULL, &MessageSendTask_attributes);
	MPUCheckTaskHandle		= osThreadNew(MPUCheckTask, NULL, &MPUCheckTask_attributes);
	DataSaveTaskHandle		= osThreadNew(DataSaveTask, NULL, &DataSaveTask_attributes);

  /* 添加中断 */
	
	
	/* 其他函数 */
    
	
}


/**
  * @brief  FreeRTOS Tick Hook, to increase the LVGL tick
  * @param  None
  * @retval None
  */
void TaskTickHook(void)
{
    char strbuf[10];
	//to increase the LVGL tick
	lv_tick_inc(1);
	//秒表
	if(ui_TimerPageFlag)
	{
			ui_TimerPage_ms+=1;
			if(ui_TimerPage_ms>=10)
			{
				ui_TimerPage_ms=0;
				ui_TimerPage_10ms+=1;
			}
			if(ui_TimerPage_10ms>=100)
			{
					ui_TimerPage_10ms=0;
					ui_TimerPage_sec+=1;
					uint8_t IdleBreakstr = 0;

                osMessageQueuePut(IdleBreak_MessageQueue, &IdleBreakstr, 0, 0);
			}
			if(ui_TimerPage_sec>=60)
			{
					ui_TimerPage_sec=0;
					ui_TimerPage_min+=1;
			}
			if(ui_TimerPage_min>=60)
			{
					ui_TimerPage_min=0;
			}
        if(ui_TimerPage_ms == 3 || ui_TimerPage_ms == 6 || ui_TimerPage_ms == 9)
        {
            sprintf(strbuf,"%02d:%02d:%02d",ui_TimerPage_min,ui_TimerPage_sec,ui_TimerPage_10ms);
            lv_span_set_text(miaobia_page_data_miaobiao_span, strbuf);
        }
	}
	user_HR_timecount+=1;
}
/**
  * @brief  Watch Dog Feed task
  * @param  argument: Not used
  * @retval None
  */
void WDOGFeedTask(void *argument)
{
	//owdg
	WDOG_Port_Init();
  while(1)
  {
		WDOG_Feed();
		WDOG_Enable();
    osDelay(100);
  }
}


