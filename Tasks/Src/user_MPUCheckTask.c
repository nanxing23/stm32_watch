/* Private includes -----------------------------------------------------------*/
//includes
#include "user_MPUCheckTask.h"
#include "user_ScrRenewTask.h"

#include "main.h"
#include "stm32f4xx_it.h"
#include "MPU6050.h"

#include "../../lvgl.h"
#include "gui_guider.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
uint8_t user_MPU_Wrist_State = WRIST_UP;//手表当前状态，抬起放下
uint8_t user_MPU_Wrist_EN = 1;          //是否使能抬腕亮屏

/* Private function prototypes -----------------------------------------------*/

/* Tasks ---------------------------------------------------------------------*/

/**
  * @brief  检查 MPU6050 状态
  * @param  argument: Not used
  * @retval None
  */
void MPUCheckTask(void *argument)
{
	while(1)
	{
		if(user_MPU_Wrist_EN)//是否开启抬腕亮屏
		{
			if(MPU_isHorizontal())//如果水平
			{
				user_MPU_Wrist_State = WRIST_UP;//状态设为抬起
//                printf("user_MPU_Wrist_State = WRIST_UP\r\n");
			}
			else
			{
                
				if(user_MPU_Wrist_State == WRIST_UP)//不水平，且上个状态是抬起
				{
					user_MPU_Wrist_State = WRIST_DOWN;//在状态设置为放下
                    
					if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_home_page || 
						ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_Caidan_page)
					{
						uint8_t Stopstr;
						osMessageQueuePut(Stop_MessageQueue, &Stopstr, 0, 1);//抬起到放下是息屏
					}
				}
				user_MPU_Wrist_State = WRIST_DOWN;
			}
		}
		osDelay(300);
	}
}


