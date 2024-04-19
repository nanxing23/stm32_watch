/* Private includes -----------------------------------------------------------*/
//includes
#include "user_TasksInit.h"
#include "user_ScrRenewTask.h"
#include "user_StopEnterTask.h"
#include "main.h"
#include "rtc.h"
#include "power.h"
#include "stm32f4xx_it.h"

#include "lvgl.h"
#include "gui_guider.h"
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/


/**
  * @brief  charg page enter task
  * @param  argument: Not used
  * @retval None
  */
void ChargPageEnterTask(void *argument)
{
	while(1)
	{
		if(HardInt_Charg_flag)//Èç¹û³äµç
		{printf("HardInt_Charg_flag");
			IdleTimerCount = 0;
			if(ChargeCheck())
			{
                printf("chong dain");

                if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] != (long long int)&setup_scr_chongdian_page)
                {                
                    setup_scr_chongdian_page(&guider_ui);
                    lv_scr_load_anim(guider_ui.chongdian_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
                    user_Stack_Push(&ScrRenewStack,(long long int)&setup_scr_chongdian_page);}
			}
			else if(!ChargeCheck())
			{
                printf("bu chong dain");
                HardInt_Charg_flag = 0;
                setup_scr_home_page(&guider_ui);
                lv_scr_load_anim(guider_ui.home_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
				user_Stack_Pop(&ScrRenewStack);
				user_Stack_Push(&ScrRenewStack,(long long int)&setup_scr_home_page);
			}
		}
		osDelay(500);
	}
}

