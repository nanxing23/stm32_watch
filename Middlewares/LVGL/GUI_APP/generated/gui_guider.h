/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts.h"
#include "stdio.h"
#include "StrCalculate.h"
    
#define TEXT_FULL 10        //��������ݳ���

typedef struct
{
	lv_obj_t *home_page;
	bool home_page_del;
	lv_obj_t *home_page_animimg_1;
	lv_obj_t *home_page_digital_clock_1;
	lv_obj_t *home_page_dian_liang;
	lv_obj_t *home_page_line_1;
	lv_obj_t *home_page_data_dianliang;
	lv_obj_t *home_page_line_2;
	lv_obj_t *home_page_huo_jian;
	lv_obj_t *home_page_data_riqi;
	lv_obj_t *home_page_data_week;
	lv_obj_t *home_page_line_3;
	lv_obj_t *home_page_line_5;
	lv_obj_t *home_page_line_6;
	lv_obj_t *home_page_xin_lv;
	lv_obj_t *home_page_data_xinlv;
	lv_obj_t *home_page_wen_du;
	lv_obj_t *home_page_data_wendu;
	lv_obj_t *home_page_sheshidu;
	lv_obj_t *home_page_data_shidu;
	lv_obj_t *home_page_shidu;
	lv_obj_t *home_page_bushu;
	lv_obj_t *home_page_data_bushu;
	lv_obj_t *home_page_caidan;
	lv_obj_t *home_page_caidan_label;
	lv_obj_t *home_page_data_miao;
	lv_obj_t *home_page_data_haiba;
	lv_obj_t *home_page_spangroup_1;
	lv_obj_t *Caidan_page;
	bool Caidan_page_del;
	lv_obj_t *Caidan_page_tileview_1;
	lv_obj_t *tileview_1_name_1;
	lv_obj_t *Caidan_page_miaobiao_e;
	lv_obj_t *Caidan_page_miaobiao_e_label;
	lv_obj_t *Caidan_page_jisuan_e;
	lv_obj_t *Caidan_page_jisuan_e_label;
	lv_obj_t *Caidan_page_zhinan_e;
	lv_obj_t *Caidan_page_zhinan_e_label;
	lv_obj_t *Caidan_page_rili_e;
	lv_obj_t *Caidan_page_rili_e_label;
	lv_obj_t *tileview_1_name_2;
	lv_obj_t *Caidan_page_LCD_PWM;
	lv_obj_t *Caidan_page_imgbtn_3;
	lv_obj_t *Caidan_page_imgbtn_3_label;
	lv_obj_t *Caidan_page_imgbtn_2;
	lv_obj_t *Caidan_page_imgbtn_2_label;
	lv_obj_t *Caidan_page_imgbtn_1;
	lv_obj_t *Caidan_page_imgbtn_1_label;
	lv_obj_t *Caidan_page_roller_2;
	lv_obj_t *Caidan_page_roller_1;
	lv_obj_t *Caidan_page_sw_1;
	lv_obj_t *chongdian_page;
	bool chongdian_page_del;
	lv_obj_t *chongdian_page_label_1;
	lv_obj_t *chongdian_page_spangroup_1;
	lv_obj_t *chongdian_page_label_2;
	lv_obj_t *rili_page;
	bool rili_page_del;
	lv_obj_t *rili_page_rili_task;
	lv_obj_t *miaobia_page;
	bool miaobia_page_del;
	lv_obj_t *miaobia_page_imgbtn_1;
	lv_obj_t *miaobia_page_imgbtn_1_label;
	lv_obj_t *miaobia_page_data_miaobiao;
	lv_obj_t *miaobia_page_imgbtn_2;
	lv_obj_t *miaobia_page_imgbtn_2_label;
	lv_obj_t *jisuan_page;
	bool jisuan_page_del;
	lv_obj_t *jisuan_page_btnm_1;
	lv_obj_t *jisuan_page_label_1;
}lv_ui;

/****************miaobia*******************/
extern lv_obj_t * ui_TimerPage;
extern uint8_t ui_TimerPageFlag;
extern uint8_t ui_TimerPage_min;
extern uint8_t ui_TimerPage_sec;
extern uint8_t ui_TimerPage_10ms;
extern uint8_t ui_TimerPage_ms;
/****************************************/

/****************home********************/
extern uint8_t ui_TimeHourValue;
extern uint8_t ui_TimeMinuteValue;
extern uint8_t ui_TimeMinuteValuec;//���ʱ
extern uint8_t ui_DateMonthValue;
extern uint8_t ui_DateDayValue;
extern uint8_t ui_DataWeekdayValue;
extern const char * ui_Days[7];

extern uint8_t ui_BatArcValue;
extern uint16_t ui_StepNumValue;
extern uint8_t ui_LightSliderValue;

extern lv_span_t *home_page_data_riqi_span;         //����
extern lv_span_t *home_page_data_week_span;         //week
extern lv_span_t *home_page_data_wendu_span;        //�¶�
extern lv_span_t *home_page_data_shidu_span;        //ʪ��
extern lv_span_t *home_page_data_haiba_span;        //����
extern lv_span_t *home_page_data_xinlv_span;        //����
extern lv_span_t *home_page_data_dianliang_span;    //���
extern lv_span_t *home_page_data_bushu_span;        //����
extern lv_span_t *chongdian_page_spangroup_1_span;  //��綯��

extern int8_t ui_EnvTempValue;            //�¶�
extern int8_t ui_EnvHumiValue;            //ʪ��
extern int16_t ui_EnvAltitudeValue;       //����
extern int8_t ui_HRValue;                 //����
/****************************************/

/***************�˵�********************/
extern uint8_t user_APPSy_EN;           //appͬ��ʱ��


/****************************************/
/***************���**********************/
extern lv_timer_t * ui_TimerPageTimer;//��ʱ����־
extern lv_span_t *miaobia_page_data_miaobiao_span;//�����ʾ
/****************************************/
void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_home_page(lv_ui *ui);

#include "extra/widgets/animimg/lv_animimg.h"
LV_IMG_DECLARE(home_page_animimg_1taikongren_00)
LV_IMG_DECLARE(home_page_animimg_1taikongren_08)
LV_IMG_DECLARE(home_page_animimg_1taikongren_10)
LV_IMG_DECLARE(home_page_animimg_1taikongren_14)
void setup_scr_Caidan_page(lv_ui *ui);
void setup_scr_chongdian_page(lv_ui *ui);
void setup_scr_rili_page(lv_ui *ui);
static lv_calendar_date_t today;
static lv_calendar_date_t highlihted_days[1];
void setup_scr_miaobia_page(lv_ui *ui);
void setup_scr_jisuan_page(lv_ui *ui);
LV_IMG_DECLARE(_return_alpha_35x35);
LV_IMG_DECLARE(_huojian_20x20);
LV_IMG_DECLARE(_buhsu_20x20);
LV_IMG_DECLARE(_xinlv_20x20);
LV_IMG_DECLARE(_dianliang_20x20);
LV_IMG_DECLARE(_shidu_20x20);
LV_IMG_DECLARE(_kaishi_alpha_40x40);
LV_IMG_DECLARE(_wendu1_20x20);
LV_IMG_DECLARE(_zhating_alpha_40x40);

#ifdef __cplusplus
}
#endif
#endif

