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
				user_Stack_Pop(&ScrRenewStack);     //�Ƴ�һ��ջ
				if(user_Stack_isEmpty(&ScrRenewStack))      //�Ƴ���û��ջ���ز˵�
				{
                    setup_scr_Caidan_page(&guider_ui);
                    lv_scr_load_anim(guider_ui.Caidan_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
					user_Stack_Push(&ScrRenewStack,(long long int)&setup_scr_home_page);
					user_Stack_Push(&ScrRenewStack,(long long int)&setup_scr_Caidan_page);
				}
				else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_home_page)//�Ƴ��������淵������
				{
                    setup_scr_home_page(&guider_ui);
                    lv_scr_load_anim(guider_ui.home_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
				}
				else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_Caidan_page)//�Ƴ����ǲ˵����ز˵�
				{
                    setup_scr_Caidan_page(&guider_ui);
                    lv_scr_load_anim(guider_ui.Caidan_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
				}
				else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_jisuan_page)//�Ƴ����Ǽ��������ز˼�����
				{
                    setup_scr_jisuan_page(&guider_ui);
                    lv_scr_load_anim(guider_ui.jisuan_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
				}
				else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_miaobia_page)//�Ƴ�������������
				{
                    setup_scr_miaobia_page(&guider_ui);
                    lv_scr_load_anim(guider_ui.miaobia_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
				}
				else if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_rili_page)//�Ƴ�����������������
				{
                    setup_scr_rili_page(&guider_ui);
                    lv_scr_load_anim(guider_ui.rili_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
				}
				
			}	
			//key2 pressed
			else if(keystr == 2)
			{
				user_Stack_Clear(&ScrRenewStack);//���ջ
                
				setup_scr_home_page(&guider_ui);//�ص�����
                lv_scr_load_anim(guider_ui.home_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
				user_Stack_Push(&ScrRenewStack,(long long int)&setup_scr_home_page);//�������ջ
			}
		}	
		osDelay(10);
	}
}
