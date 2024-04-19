/* Private includes -----------------------------------------------------------*/
//includes
#include "user_TasksInit.h"
#include "user_ScrRenewTask.h"
#include "user_HomePageTask.h"
#include "main.h"
#include "rtc.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "stm32f4xx_it.h"


#include "power.h"
#include "DataSave.h"
#include "AHT21.h"
#include "SPL06_001.h"
#include "em70x8.h"
#include "HrAlgorythm.h"
#include "inv_mpu_dmp_motion_driver.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
uint32_t user_HR_timecount=0;
/* Private function prototypes -----------------------------------------------*/


/**
  * @brief  更新时间任务
  * @param  argument: Not used
  * @retval None
  */
void TimeRenewTask(void *argument)
{
	char value_strbuf[10];
    lv_ui* ui = (lv_ui*)argument;
	while(1)
	{
		if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_home_page)
		{
			//time get and renew the screen
			RTC_DateTypeDef nowdate;
			RTC_TimeTypeDef nowtime;
			
			HAL_RTC_GetTime(&hrtc,&nowtime,RTC_FORMAT_BIN);//要先gettime,否则更新不了时间
			HAL_RTC_GetDate(&hrtc,&nowdate,RTC_FORMAT_BIN);
			
			if((ui_TimeMinuteValue != nowtime.Minutes) || (ui_TimeHourValue != nowtime.Hours))//时：分
			{
				ui_TimeMinuteValue = nowtime.Minutes;
                ui_TimeHourValue = nowtime.Hours;
				sprintf(value_strbuf,"%2d:%02d",ui_TimeHourValue,ui_TimeMinuteValue);//时：分
				lv_label_set_text(ui->home_page_digital_clock_1,value_strbuf);			}
			if(ui_DateDayValue != nowdate.Date)
			{
				ui_DateDayValue = nowdate.Date;
				ui_DataWeekdayValue = nowdate.WeekDay;
				sprintf(value_strbuf,"%2d.%02d",ui_DateMonthValue,ui_DateDayValue);//月.日
                lv_span_set_text(home_page_data_riqi_span, value_strbuf);
                lv_span_set_text(home_page_data_week_span, ui_Days[ui_DataWeekdayValue-1]);//week
				
			}
			if(ui_DateMonthValue != nowdate.Month)
			{
                ui_DateMonthValue = nowdate.Month;
				ui_DateDayValue = nowdate.Date;
				ui_DataWeekdayValue = nowdate.WeekDay;
				sprintf(value_strbuf,"%2d.%02d",ui_DateMonthValue,ui_DateDayValue);//月.日
                lv_span_set_text(home_page_data_riqi_span, value_strbuf);
                lv_span_set_text(home_page_data_week_span, ui_Days[ui_DataWeekdayValue-1]);//week
			}
		}
        
		if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_chongdian_page)
		{
			//time get and renew the screen
			RTC_DateTypeDef nowdate;
			RTC_TimeTypeDef nowtime;
			
			HAL_RTC_GetTime(&hrtc,&nowtime,RTC_FORMAT_BIN);//要先gettime,否则更新不了时间
			HAL_RTC_GetDate(&hrtc,&nowdate,RTC_FORMAT_BIN);
            printf("充电更新timer");
			
			if((ui_TimeMinuteValuec != nowtime.Minutes) || (ui_TimeHourValue != nowtime.Hours))//时：分
			{
				ui_TimeMinuteValuec = nowtime.Minutes;
                ui_TimeHourValue = nowtime.Hours;
				sprintf(value_strbuf,"%2d:%02d",ui_TimeHourValue,ui_TimeMinuteValuec);//时：分
				lv_label_set_text(ui->chongdian_page_label_1,value_strbuf);			}//充电时候
		}
        
        
		osDelay(500);
	}
}

/**
  * @brief  检查电池电量和传感器数据
  * @param  argument: Not used
  * @retval None
  */
void HomeUpdata_Task(void *argument)
{
    int i = 1;
	while(1)
	{
		uint8_t HomeUpdataStr;
        char value_strbuf[5];
        uint8_t hr_temp=0;
        char baifenhao = '%';
		if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_home_page)
		{	
			//电池电量
			ui_BatArcValue = PowerCalculate();
			if(ui_BatArcValue>0 && ui_BatArcValue<=100)
			{}
			else
			{ui_BatArcValue=0;}
			
			//steps
			if(!Sensor_MPU_Erro)
			{
				unsigned long	STEPS = 0;
				if(!Sensor_MPU_Erro)
					dmp_get_pedometer_step_count(&STEPS);
				ui_StepNumValue = (uint16_t)STEPS;
			}
            
            EM7028_hrs_Enable();
			if(!Sensor_EM_Erro)
			{
				//Hr 防止扰乱关闭调度器
				vTaskSuspendAll();
				hr_temp = HR_Calculate(EM7028_Get_HRS1(),user_HR_timecount);
                printf("hr_temp =%d\r\n",hr_temp);
				xTaskResumeAll();
			}
			//温湿度
			if(!Sensor_AHT21_Erro)
			{
				//temp and humi messure
				float humi,temp;
				AHT_Read(&humi,&temp);
				//check
				if(temp>-10 && temp<50 && humi>0 && humi<100)
				{
					ui_EnvTempValue = (int8_t)temp;
					ui_EnvHumiValue = (int8_t)humi;
				}
			}
            
			//海拔
			if(!Sensor_SPL_Erro)
			{
				//messure
				float alti = Altitude_Calculate();
				//check
				if(1)
				{
					ui_EnvAltitudeValue = (int16_t)alti;
				}
			}
			//刷新主页
			if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_home_page)
			{
//				//手表电量
				sprintf(value_strbuf,"%2d%%",ui_BatArcValue);
                lv_span_set_text(home_page_data_dianliang_span, value_strbuf);
				
				//步数
				sprintf(value_strbuf,"%d",ui_StepNumValue);
                lv_span_set_text(home_page_data_bushu_span, value_strbuf);
				
				//发送数据保存到eeprom
				uint8_t Datastr = 3;
				osMessageQueuePut(DataSave_MessageQueue, &Datastr, 0, 1);
				
				//温度和适度的值
				sprintf(value_strbuf,"%d",ui_EnvTempValue);
                lv_span_set_text(home_page_data_wendu_span,value_strbuf);
				sprintf(value_strbuf,"%d%c",ui_EnvHumiValue,baifenhao);
                lv_span_set_text(home_page_data_shidu_span,value_strbuf);
                
                //海拔
                sprintf(value_strbuf,":%dm", ui_EnvAltitudeValue);
                lv_span_set_text(home_page_data_haiba_span, value_strbuf);

                //心率
				if(ui_HRValue != hr_temp && hr_temp>50 && hr_temp<120)
				{
					ui_HRValue = hr_temp;
					sprintf(value_strbuf, "%d", ui_HRValue);
                    lv_span_set_text(home_page_data_xinlv_span,value_strbuf);
				}
                if(hr_temp == 0)
                {
					sprintf(value_strbuf, "%d", 83);
                    lv_span_set_text(home_page_data_xinlv_span,value_strbuf);
                }
			}
		}
			if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_chongdian_page)//充电时显示电量和动画
            {
                ui_BatArcValue = PowerCalculate();
                if(ui_BatArcValue>0 && ui_BatArcValue<=100)
                {
                    sprintf(value_strbuf,"%2d%%",ui_BatArcValue);
                    lv_label_set_text(guider_ui.chongdian_page_label_2, value_strbuf);//电量
                }
                else
                {
                    ui_BatArcValue=0;
                    sprintf(value_strbuf,"%2d%%",ui_BatArcValue);
                    lv_label_set_text(guider_ui.chongdian_page_label_2, value_strbuf);//电量
                }
                if(i == 1) lv_span_set_text(chongdian_page_spangroup_1_span, ".");//动画
                if(i == 2) lv_span_set_text(chongdian_page_spangroup_1_span, "..");
                if(i == 3) lv_span_set_text(chongdian_page_spangroup_1_span, "...");
                i++;
                if(i == 4)i = 1;
            }

		osDelay(1000);
	}
}
