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
uint8_t user_MPU_Wrist_State = WRIST_UP;//�ֱ�ǰ״̬��̧�����
uint8_t user_MPU_Wrist_EN = 1;          //�Ƿ�ʹ��̧������

/* Private function prototypes -----------------------------------------------*/

/* Tasks ---------------------------------------------------------------------*/

/**
  * @brief  ��� MPU6050 ״̬
  * @param  argument: Not used
  * @retval None
  */
void MPUCheckTask(void *argument)
{
	while(1)
	{
		if(user_MPU_Wrist_EN)//�Ƿ���̧������
		{
			if(MPU_isHorizontal())//���ˮƽ
			{
				user_MPU_Wrist_State = WRIST_UP;//״̬��Ϊ̧��
//                printf("user_MPU_Wrist_State = WRIST_UP\r\n");
			}
			else
			{
                
				if(user_MPU_Wrist_State == WRIST_UP)//��ˮƽ�����ϸ�״̬��̧��
				{
					user_MPU_Wrist_State = WRIST_DOWN;//��״̬����Ϊ����
                    
					if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_home_page || 
						ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&setup_scr_Caidan_page)
					{
						uint8_t Stopstr;
						osMessageQueuePut(Stop_MessageQueue, &Stopstr, 0, 1);//̧�𵽷�����Ϣ��
					}
				}
				user_MPU_Wrist_State = WRIST_DOWN;
			}
		}
		osDelay(300);
	}
}


