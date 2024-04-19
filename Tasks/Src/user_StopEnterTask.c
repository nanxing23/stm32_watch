/* Private includes -----------------------------------------------------------*/
//includes
#include "user_TasksInit.h"
#include "user_StopEnterTask.h"
#include "user_MPUCheckTask.h"


#include "lvgl.h"
#include "gui_guider.h"

#include "main.h"
#include "stm32f4xx_it.h"
#include "lcd_init.h"
#include "power.h"
#include "CST816.h"
#include "MPU6050.h"
#include "key.h"
#include "WDOG.h"
#include "em70x8.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
uint16_t IdleTimerCount = 0;
uint8_t ui_LTimeValue = 5;
uint8_t ui_TTimeValue = 15;

/* Private function prototypes -----------------------------------------------*/

/* Tasks ---------------------------------------------------------------------*/

/**
	* @brief  Enter Idle state
  * @param  argument: Not used
  * @retval None
  */
void IdleEnterTask(void *argument)
{
	uint8_t Idlestr=0;
	uint8_t IdleBreakstr=0;
	while(1)
	{
		//熄屏
		if(osMessageQueueGet(Idle_MessageQueue,&Idlestr,NULL,1)==osOK)
		{
			LCD_Set_Light(5);
		}
		//有按键或屏幕按动时调用亮屏
		if(osMessageQueueGet(IdleBreak_MessageQueue,&IdleBreakstr,NULL,1)==osOK)
		{
			IdleTimerCount = 0;
			LCD_Set_Light(ui_LightSliderValue);
		}
		osDelay(10);
	}
}

/**
  * @brief  enter the stop mode and resume
  * @param  argument: Not used
  * @retval None
  */
void StopEnterTask(void *argument)
{
	uint8_t Stopstr;
	uint8_t HomeUpdataStr;
	uint8_t Wrist_Flag=0;
	while(1)
	{
		if(osMessageQueueGet(Stop_MessageQueue,&Stopstr,NULL,0)==osOK)
		{
			
			/***** your sleep operations *****/
			sleep:
			IdleTimerCount = 0;

			//sensors
			
			//lcd
			LCD_RES_Clr();
			LCD_Close_Light();
			CST816_Sleep();
            EM7028_hrs_DisEnable();//关闭心率
			/*********************************/
			vTaskSuspendAll();          //暂停任务调度器
			WDOG_Disnable();			//停止看门狗
			CLEAR_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);//禁用systick中断
			HAL_PWR_EnterSTOPMode(PWR_MAINREGULATOR_ON,PWR_STOPENTRY_WFI);//32进入停止模式
			
			//here is the sleep period

			//resume run mode and reset the sysclk
			SET_BIT(SysTick->CTRL, SysTick_CTRL_TICKINT_Msk);
			HAL_SYSTICK_Config(SystemCoreClock / (1000U / uwTickFreq));
			SystemClock_Config();
			WDOG_Feed();
			xTaskResumeAll();
			
			/***** your wakeup operations *****/
			
			//MPU Check
			if(user_MPU_Wrist_EN)
			{
				uint8_t hor;
				hor = MPU_isHorizontal();
				if(hor && user_MPU_Wrist_State == WRIST_DOWN)//水平且状态为放下
				{
					user_MPU_Wrist_State = WRIST_UP;
					Wrist_Flag = 1;
					//resume, go on
				}
				else if(!hor && user_MPU_Wrist_State == WRIST_UP)
				{
					user_MPU_Wrist_State = WRIST_DOWN;
					IdleTimerCount  = 0;
					goto sleep;
				}
			}
			
			//
			if(!KEY1 || KEY2 || HardInt_Charg_flag || Wrist_Flag)
			{
				Wrist_Flag = 0;
				//resume, go on
			}
			else                                                        //按键没有按下    
			{
				IdleTimerCount  = 0;
				goto sleep;
			}
			
			
			//lcd
			LCD_Init();
			LCD_Set_Light(ui_LightSliderValue);
			CST816_Wakeup();
			//是否在充电，如果电压一直跳把注释掉
			if(ChargeCheck())//如果充电
			{HardInt_Charg_flag = 1;}
			/**********************************/
			
		}
		osDelay(100);
	}
}

void IdleTimerCallback(void *argument)      //100ms
{
	IdleTimerCount+=1;
	//make sure the LightOffTime<TurnOffTime
	if(IdleTimerCount == (ui_LTimeValue*10))
	{
		uint8_t Idlestr=0;
		//send the Light off message
		osMessageQueuePut(Idle_MessageQueue, &Idlestr, 0, 1);
		
	}
	if(IdleTimerCount == (ui_TTimeValue*10))
	{
		uint8_t Stopstr = 1;
		IdleTimerCount  = 0;
		//send the Stop message
		osMessageQueuePut(Stop_MessageQueue, &Stopstr, 0, 1);
	}
}


