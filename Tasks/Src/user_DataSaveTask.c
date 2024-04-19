/* Private includes -----------------------------------------------------------*/
//includes
#include "user_DataSaveTask.h"
#include "user_MPUCheckTask.h"
//LVGL
#include "../../lvgl.h"
#include "gui_guider.h"

#include "main.h"
#include "rtc.h"
#include "DataSave.h"
#include "inv_mpu_dmp_motion_driver.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/******************************************
EEPROM Data description:
[0x00]:0x55 检查
[0x01]:0xAA 检查

[0x10]:user_MPU_Wrist_EN
[0x11]:user_APPSy_EN

[0x20]:当前日期
[0x21]:步数

*******************************************/


/* Private function prototypes -----------------------------------------------*/

/* Tasks ---------------------------------------------------------------------*/

/**
  * @brief  Data Save in the EEPROM
  * @param  argument: Not used
  * @retval None
  */
void DataSaveTask(void *argument)
{
	
	while(1)
	{
		uint8_t Datastr=0;
		if(osMessageQueueGet(DataSave_MessageQueue,&Datastr,NULL,1)==osOK)
		{
			/****************
			设置抬手蓝牙
			日期更改
			步数更改
			****************/
			uint8_t dat[3];
			dat[0] = user_MPU_Wrist_EN;
//			dat[1] = user_APPSy_EN;
			SettingSave(dat,0x10,2);
			
			RTC_DateTypeDef nowdate;
			HAL_RTC_GetDate(&hrtc,&nowdate,RTC_FORMAT_BIN);
			
			SettingGet(dat,0x20,3);
			if(dat[0] != nowdate.Date)
			{
				if(!Sensor_MPU_Erro)
					dmp_set_pedometer_step_count(0);
				dat[0] = nowdate.Date;
				dat[2] = 0;
				dat[1] = 0;
				SettingSave(dat,0x20,3);
			}
			else
			{
				unsigned long	STEPS = 0;
				if(!Sensor_MPU_Erro)
					dmp_get_pedometer_step_count(&STEPS);
				uint16_t temp = (uint16_t)STEPS;
				dat[0] = nowdate.Date;
				dat[2] = temp & 0xff;
				dat[1] = temp>>8 & 0xff;
				SettingSave(dat,0x20,3);
			}
			
		}
		osDelay(100);
	}
}


