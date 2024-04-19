/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "usart.h"
#include "lcd.h"
#include "lcd_init.h"
#include "lvgl.h"
#include "gui_guider.h"
#include "user_ScrRenewTask.h"
#include "user_MPUCheckTask.h"
#include "user_StopEnterTask.h"

const uint8_t ui_LTimeOptions[6] = {5,10,15,20,25};
const uint8_t ui_TTimeOptions[6] = {10,15,25,30,40};
uint8_t ui_LTimeSelected = 0;
uint8_t ui_TTimeSelected = 0;

void events_init(lv_ui *ui)
{
}

static void home_page_caidan_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.Caidan_page_del == true)
				setup_scr_Caidan_page(&guider_ui);
			lv_scr_load_anim(guider_ui.Caidan_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
            user_Stack_Push(&ScrRenewStack,(long long int)&setup_scr_Caidan_page);
		}
		guider_ui.home_page_del = true;
	}
		break;
	default:
		break;
	}
}

void events_init_home_page(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->home_page_caidan, home_page_caidan_event_handler, LV_EVENT_ALL, NULL);
}

static void Caidan_page_miaobiao_e_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.miaobia_page_del == true)
				setup_scr_miaobia_page(&guider_ui);
			lv_scr_load_anim(guider_ui.miaobia_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
            user_Stack_Push(&ScrRenewStack,(long long int)&setup_scr_miaobia_page);
		}
		guider_ui.Caidan_page_del = true;
	}
		break;
	default:
		break;
	}
}

static void Caidan_page_jisuan_e_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.jisuan_page_del == true)
				setup_scr_jisuan_page(&guider_ui);
			lv_scr_load_anim(guider_ui.jisuan_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
            user_Stack_Push(&ScrRenewStack,(long long int)&setup_scr_jisuan_page);
		}
		guider_ui.Caidan_page_del = true;
	}
		break;
	default:
		break;
	}
}

static void Caidan_page_zhinan_e_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	default:
		break;
	}
}

static void Caidan_page_rili_e_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		lv_disp_t * d = lv_obj_get_disp(lv_scr_act());
		if (d->prev_scr == NULL && d->scr_to_load == NULL)
		{
			if (guider_ui.rili_page_del == true)
				setup_scr_rili_page(&guider_ui);
			lv_scr_load_anim(guider_ui.rili_page, LV_SCR_LOAD_ANIM_OVER_TOP, 0, 0, true);
            user_Stack_Push(&ScrRenewStack,(long long int)&setup_scr_jisuan_page);
		}
		guider_ui.Caidan_page_del = true;
	}
		break;
	default:
		break;
	}
}
static void Caidan_page_LCD_PWM_event_handler(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED)
    {
        ui_LightSliderValue = lv_slider_get_value(guider_ui.Caidan_page_LCD_PWM);
        LCD_Set_Light(ui_LightSliderValue);
    }
}

static void Caidan_page_roller_2_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
      ui_TTimeSelected = lv_roller_get_selected(guider_ui.Caidan_page_roller_2);
	  ui_TTimeSelected = ui_TTimeOptions[ui_TTimeSelected];
      printf("ui_TTimeSelected=%d",ui_TTimeSelected);
    }
}

static void Caidan_page_roller_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED)
    {
      ui_LTimeSelected = lv_roller_get_selected(guider_ui.Caidan_page_roller_1);
	  ui_LTimeValue = ui_LTimeOptions[ui_LTimeSelected];
    }
}

static void Caidan_page_sw_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    
    if(code == LV_EVENT_VALUE_CHANGED)
    {
       if(lv_obj_has_state(guider_ui.Caidan_page_sw_1,LV_STATE_CHECKED))
       {
				 user_MPU_Wrist_EN=1;
       }
       else
       {
				 user_MPU_Wrist_EN=0;
       }
    }
}


void events_init_Caidan_page(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Caidan_page_miaobiao_e, Caidan_page_miaobiao_e_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Caidan_page_jisuan_e, Caidan_page_jisuan_e_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Caidan_page_zhinan_e, Caidan_page_zhinan_e_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Caidan_page_rili_e, Caidan_page_rili_e_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Caidan_page_LCD_PWM, Caidan_page_LCD_PWM_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Caidan_page_roller_2, Caidan_page_roller_2_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Caidan_page_roller_1, Caidan_page_roller_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->Caidan_page_sw_1, Caidan_page_sw_1_event_handler, LV_EVENT_ALL, NULL);
}


static void miaobia_page_imgbtn_1_event_handler(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED &&  lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        //��ʼ
        ui_TimerPageFlag = 1;
//        printf("ui_TimerPageFlag=%d\r\n",ui_TimerPageFlag);

    }
    if(event_code == LV_EVENT_VALUE_CHANGED &&  !lv_obj_has_state(target, LV_STATE_CHECKED))
    {
        //��ͣ
        ui_TimerPageFlag = 0;
//        printf("ui_TimerPageFlag=%d\r\n",ui_TimerPageFlag);

    }
}

static void miaobia_page_imgbtn_2_event_handler(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED)
    {

        ui_TimerPage_min = 0;
        ui_TimerPage_sec = 0;
		ui_TimerPage_10ms = 0;
        ui_TimerPage_ms = 0;
        ui_TimerPageFlag = 0;
        lv_span_set_text(miaobia_page_data_miaobiao_span, "00:00:00");

    }
}

void events_init_miaobia_page(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->miaobia_page_imgbtn_1, miaobia_page_imgbtn_1_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->miaobia_page_imgbtn_2, miaobia_page_imgbtn_2_event_handler, LV_EVENT_ALL, NULL);
}

static int get_result(int old,int oper,int value)
{
    int result = 0;
    switch(oper)
    {
        case 2:
            result = old - value;
        break;
        case 7:
            result = old / value;
        break;
        case 11:
            result = old * value;
        break;
        case 15:
            result = old + value;
        break;
        
    }
}
static void jisuan_page_btnm_1_event_handler(lv_event_t *e)
{
    int value = 0;//现在显示的数字
    static char num[10] = {0};
    static int old = 0;
    static int oper = 0;    //运算符
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    
    if(code == LV_EVENT_VALUE_CHANGED)
    {
        uint16_t btn_id = lv_btnmatrix_get_selected_btn(obj); // 获取当前选中的按键的id
        const char * txt = lv_btnmatrix_get_btn_text(obj, btn_id); // 获取当前按键的文本
        if (txt != NULL)
        {printf("1");
            if (guider_ui.jisuan_page_label_1 != NULL)
            {printf("2");
                if(strlen(num)<sizeof(num)-1){
                    switch (btn_id)
                    {
                    case 0:
                        strcat(num,txt);//不要直接出
                        printf("倒数\r\n");
                        break;
                    case 1:             //不要直接出
                        strcat(num,"²");
                        printf("平方\r\n");
                        break;
                    case 2:
                        strcat(num,"-");
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf("-\r\n");
                        break;
                    case 3:
                        strcat(num,txt);//需要改
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf("删\r\n");
                        break;
                    case 4:
                        strcat(num,txt);
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf("7\r\n");
                        break;
                    case 5:
                        strcat(num,txt);
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf("8\r\n");
                        break;
                    case 6:
                        strcat(num,txt);
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf("9\r\n");
                        break;
                    case 7:
                        strcat(num,"/");
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf("÷\r\n");
                        break;
                    case 8:
                        strcat(num,txt);
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf("4\r\n");
                        break;
                    case 9:
                        strcat(num,txt);    
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf("5\r\n");
                        break;
                    case 10:
                        strcat(num,txt);
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf("6\r\n");
                        break;
                    case 11:
                        strcat(num,"x");
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf("x\r\n");
                        break;
                    case 12:
                        strcat(num,txt);
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf("1\r\n");
                        break;
                    case 13:
                        strcat(num,txt);
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf("2\r\n");
                        break;
                    case 14:
                        strcat(num,txt);
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf("3\r\n");
                        break;
                    case 15:
                        strcat(num,"+");
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf("+\r\n");
                        break;
                    case 16:
//                        strcat(num,txt);//归零
                        memset(num, 0, sizeof(num));
                        lv_label_set_text(guider_ui.jisuan_page_label_1,"0");
                        printf("C\r\n");
                        break;
                    case 17:
                        strcat(num,txt);
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf("0\r\n");
                        break;
                    case 18:
                        strcat(num,".");
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf(".\r\n");
                        break;
                    case 19:
                        strcat(num,txt);
                        lv_label_set_text(guider_ui.jisuan_page_label_1,num);
                        printf("=\r\n");
                        break;
                    }
                }
                else{
                    if(btn_id == 16) {memset(num, 0, sizeof(num));lv_label_set_text(guider_ui.jisuan_page_label_1,"0");}
                }
            }
        }
    }
}

void events_init_jisuan_page(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->jisuan_page_btnm_1, jisuan_page_btnm_1_event_handler, LV_EVENT_ALL, NULL);
}

