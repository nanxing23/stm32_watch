/* Private includes -----------------------------------------------------------*/
//includes
#include "user_TasksInit.h"
#include "user_ScrRenewTask.h"
#include "main.h"
#include "rtc.h"
#include "em70x8.h"

#include "lvgl.h"
#include "gui_guider.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
extern osMessageQueueId_t Key_MessageQueue;
user_Stack_T ScrRenewStack;

/* Private function prototypes -----------------------------------------------*/


/**
  * @brief  Screen renew task
  * @param  argument: Not used
  * @retval None
  */
void ScrRenewTask(void *argument)
{
	uint8_t keystr=0;
	user_Stack_Push(&ScrRenewStack,(long long int)&setup_scr_home_page);
	while(1)
	{
		if(osMessageQueueGet(Key_MessageQueue,&keystr,NULL,0)==osOK)
		{
			//key1 pressed
			if(keystr == 1)
			{
				user_Stack_Pop(&ScrRenewStack);     //移除一个栈
				if(user_Stack_isEmpty(&ScrRenewStack))      //移除后没有栈返回菜单
				{
                    setup_scr_Caidan_page(&guider_ui);
                    lv_scr_load_anim(guider_ui.Caidan_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
					user_Stack_Push(&ScrRenewStack,(long long int)&setup_scr_home_page);
					user_Stack_Push(&ScrRenewStack,(long long int)&setup_scr_Caidan_page);
				}
				else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_home_page)//移除后是桌面返回桌面
				{
                    setup_scr_home_page(&guider_ui);
                    lv_scr_load_anim(guider_ui.home_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
				}
				else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_Caidan_page)//移除后是菜单返回菜单
				{
                    setup_scr_Caidan_page(&guider_ui);
                    lv_scr_load_anim(guider_ui.Caidan_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
				}
				else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_jisuan_page)//移除后是计算器返回菜计算器
				{
                    setup_scr_jisuan_page(&guider_ui);
                    lv_scr_load_anim(guider_ui.jisuan_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
				}
				else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_miaobia_page)//移除后是秒表返回秒表
				{
                    setup_scr_miaobia_page(&guider_ui);
                    lv_scr_load_anim(guider_ui.miaobia_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
				}
				else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_rili_page)//移除后是日历返回日历
				{
                    setup_scr_rili_page(&guider_ui);
                    lv_scr_load_anim(guider_ui.rili_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
				}
				
			}	
			//key2 pressed
			else if(keystr == 2)
			{
				user_Stack_Clear(&ScrRenewStack);//清空栈
                
				setup_scr_home_page(&guider_ui);//回到桌面
                lv_scr_load_anim(guider_ui.home_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
				user_Stack_Push(&ScrRenewStack,(long long int)&setup_scr_home_page);//添加桌面栈
			}
		}	
		osDelay(10);
	}
}
