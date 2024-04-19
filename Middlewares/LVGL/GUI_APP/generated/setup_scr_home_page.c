/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"
#include "rtc.h"

///////////////////// 变量 ////////////////////
#define DROPDOWN_HIDEED 0
#define DROPDOWN_SHOWED 1

uint8_t DropDown_Status = DROPDOWN_HIDEED;

uint8_t ui_TimeHourValue = 11;
uint8_t ui_TimeMinuteValue = 59;
uint8_t ui_TimeMinuteValuec = 59;//充电时
const char * ui_Days[7] = {"Mon.", "Tue.", "Wed.", "Thu.", "Fri.", "Sat.", "Sun."};
uint8_t ui_DateMonthValue = 11;
uint8_t ui_DateDayValue = 8;
uint8_t ui_DataWeekdayValue = 2;

uint8_t ui_BatArcValue = 70;            //电池电量
uint16_t ui_StepNumValue = 0;           //步数
uint8_t ui_LightSliderValue = 50;       //屏幕亮度

int8_t ui_EnvTempValue = 00;            //温度
int8_t ui_EnvHumiValue = 00;            //湿度
int16_t ui_EnvAltitudeValue = 00;       //海拔
int8_t ui_HRValue = 00;                 //心率

//create spans
lv_span_t *home_page_data_riqi_span;        //日期
lv_span_t *home_page_data_week_span;        //week
lv_span_t *home_page_data_wendu_span;       //温度
lv_span_t *home_page_data_shidu_span;       //湿度
lv_span_t *home_page_data_haiba_span;       //海拔
lv_span_t *home_page_data_xinlv_span;       //心率
lv_span_t *home_page_data_bushu_span;       //步数
lv_span_t *home_page_data_dianliang_span;   //电池
///////////////////// 动画 ////////////////////



static const lv_img_dsc_t* home_page_animimg_1_imgs[4] = {
	&home_page_animimg_1taikongren_00,
	&home_page_animimg_1taikongren_08,
	&home_page_animimg_1taikongren_10,
	&home_page_animimg_1taikongren_14
};

void setup_scr_home_page(lv_ui *ui){

    RTC_DateTypeDef nowdate;
    RTC_TimeTypeDef nowtime;
    char value_strbuf[10];
    char baifenhao = '%';
	//Write codes home_page
	ui->home_page = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->home_page, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_page_main_main_default
	static lv_style_t style_home_page_main_main_default;
	if (style_home_page_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_main_main_default);
	else
		lv_style_init(&style_home_page_main_main_default);
	lv_style_set_bg_color(&style_home_page_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_home_page_main_main_default, 255);
	lv_obj_add_style(ui->home_page, &style_home_page_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_page_animimg_1
	ui->home_page_animimg_1 = lv_animimg_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_animimg_1, 65, 117);
	lv_obj_set_size(ui->home_page_animimg_1, 70, 70);
	lv_obj_set_scrollbar_mode(ui->home_page_animimg_1, LV_SCROLLBAR_MODE_OFF);
	lv_animimg_set_src(ui->home_page_animimg_1, (lv_img_dsc_t**) home_page_animimg_1_imgs, 4);
	lv_animimg_set_duration(ui->home_page_animimg_1, 480);
	lv_animimg_set_repeat_count(ui->home_page_animimg_1, 3000);
	lv_animimg_start(ui->home_page_animimg_1);
	static bool home_page_digital_clock_1_timer_enabled = false;

	//Write codes home_page_digital_clock_1
	ui->home_page_digital_clock_1 = lv_label_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_digital_clock_1, 40, 65);
	lv_obj_set_size(ui->home_page_digital_clock_1, 160, 80);
	lv_obj_set_scrollbar_mode(ui->home_page_digital_clock_1, LV_SCROLLBAR_MODE_OFF);
    ui_TimeMinuteValue = nowtime.Minutes;
    ui_TimeHourValue = nowtime.Hours;
    sprintf(value_strbuf,"%2d:%02d",ui_TimeHourValue,ui_TimeMinuteValue);//时：分
    lv_label_set_text(ui->home_page_digital_clock_1,value_strbuf);			
	lv_label_set_long_mode(ui->home_page_digital_clock_1, LV_LABEL_LONG_WRAP);
	
	//Write style state: LV_STATE_DEFAULT for style_home_page_digital_clock_1_main_main_default
	static lv_style_t style_home_page_digital_clock_1_main_main_default;
	if (style_home_page_digital_clock_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_digital_clock_1_main_main_default);
	else
	lv_style_init(&style_home_page_digital_clock_1_main_main_default);
	lv_style_set_radius(&style_home_page_digital_clock_1_main_main_default, 0);
	lv_style_set_bg_color(&style_home_page_digital_clock_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_home_page_digital_clock_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_page_digital_clock_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_page_digital_clock_1_main_main_default, 0);
	lv_style_set_text_color(&style_home_page_digital_clock_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_page_digital_clock_1_main_main_default, &lv_font_simsun_40);
	lv_style_set_text_letter_space(&style_home_page_digital_clock_1_main_main_default, 10);
	lv_style_set_pad_left(&style_home_page_digital_clock_1_main_main_default, 0);
	lv_style_set_pad_right(&style_home_page_digital_clock_1_main_main_default, 0);
	lv_style_set_pad_top(&style_home_page_digital_clock_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_page_digital_clock_1_main_main_default, 0);
	lv_obj_add_style(ui->home_page_digital_clock_1, &style_home_page_digital_clock_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_page_dian_liang
	ui->home_page_dian_liang = lv_img_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_dian_liang, 164, 21);
	lv_obj_set_size(ui->home_page_dian_liang, 20, 20);
	lv_obj_set_scrollbar_mode(ui->home_page_dian_liang, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_page_dian_liang_main_main_default
	static lv_style_t style_home_page_dian_liang_main_main_default;
	if (style_home_page_dian_liang_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_dian_liang_main_main_default);
	else
		lv_style_init(&style_home_page_dian_liang_main_main_default);
	lv_style_set_img_recolor(&style_home_page_dian_liang_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_page_dian_liang_main_main_default, 0);
	lv_style_set_img_opa(&style_home_page_dian_liang_main_main_default, 255);
	lv_obj_add_style(ui->home_page_dian_liang, &style_home_page_dian_liang_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->home_page_dian_liang, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->home_page_dian_liang,&_dianliang_20x20);
	lv_img_set_pivot(ui->home_page_dian_liang, 0,0);
	lv_img_set_angle(ui->home_page_dian_liang, 0);

	//Write codes home_page_line_1
	ui->home_page_line_1 = lv_line_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_line_1, 0, 56);
	lv_obj_set_size(ui->home_page_line_1, 240, 3);
	lv_obj_set_scrollbar_mode(ui->home_page_line_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_page_line_1_main_main_default
	static lv_style_t style_home_page_line_1_main_main_default;
	if (style_home_page_line_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_line_1_main_main_default);
	else
		lv_style_init(&style_home_page_line_1_main_main_default);
	lv_style_set_line_color(&style_home_page_line_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_home_page_line_1_main_main_default, 2);
	lv_style_set_line_rounded(&style_home_page_line_1_main_main_default, true);
	lv_obj_add_style(ui->home_page_line_1, &style_home_page_line_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t home_page_line_1[] ={{0, 0},{242, 0},};
	lv_line_set_points(ui->home_page_line_1,home_page_line_1,2);

	//Write codes home_page_data_dianliang
	ui->home_page_data_dianliang = lv_spangroup_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_data_dianliang, 186, 20);
	lv_obj_set_size(ui->home_page_data_dianliang, 54, 22);
	lv_obj_set_scrollbar_mode(ui->home_page_data_dianliang, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->home_page_data_dianliang, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->home_page_data_dianliang, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->home_page_data_dianliang, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_home_page_data_dianliang_main_main_default
	static lv_style_t style_home_page_data_dianliang_main_main_default;
	if (style_home_page_data_dianliang_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_data_dianliang_main_main_default);
	else
		lv_style_init(&style_home_page_data_dianliang_main_main_default);
	lv_style_set_radius(&style_home_page_data_dianliang_main_main_default, 0);
	lv_style_set_bg_color(&style_home_page_data_dianliang_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_page_data_dianliang_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_page_data_dianliang_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_page_data_dianliang_main_main_default, 0);
	lv_style_set_border_color(&style_home_page_data_dianliang_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_home_page_data_dianliang_main_main_default, 0);
	lv_style_set_border_opa(&style_home_page_data_dianliang_main_main_default, 255);
	lv_style_set_pad_left(&style_home_page_data_dianliang_main_main_default, 0);
	lv_style_set_pad_right(&style_home_page_data_dianliang_main_main_default, 0);
	lv_style_set_pad_top(&style_home_page_data_dianliang_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_page_data_dianliang_main_main_default, 0);
	lv_obj_add_style(ui->home_page_data_dianliang, &style_home_page_data_dianliang_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);


	//create a new span
	home_page_data_dianliang_span = lv_spangroup_new_span(ui->home_page_data_dianliang);
    sprintf(value_strbuf,"%2d%%",ui_BatArcValue);
    lv_span_set_text(home_page_data_dianliang_span, value_strbuf);//电量显示
	lv_style_set_text_color(&home_page_data_dianliang_span->style, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_decor(&home_page_data_dianliang_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&home_page_data_dianliang_span->style, &lv_font_simsun_20);
	lv_spangroup_refr_mode(ui->home_page_data_dianliang);

	//Write codes home_page_line_2
	ui->home_page_line_2 = lv_line_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_line_2, 0, 229);
	lv_obj_set_size(ui->home_page_line_2, 240, 5);
	lv_obj_set_scrollbar_mode(ui->home_page_line_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_page_line_2_main_main_default
	static lv_style_t style_home_page_line_2_main_main_default;
	if (style_home_page_line_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_line_2_main_main_default);
	else
		lv_style_init(&style_home_page_line_2_main_main_default);
	lv_style_set_line_color(&style_home_page_line_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_home_page_line_2_main_main_default, 2);
	lv_style_set_line_rounded(&style_home_page_line_2_main_main_default, true);
	lv_obj_add_style(ui->home_page_line_2, &style_home_page_line_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t home_page_line_2[] ={{0, 0},{242, 0},};
	lv_line_set_points(ui->home_page_line_2,home_page_line_2,2);

	//Write codes home_page_huo_jian
	ui->home_page_huo_jian = lv_img_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_huo_jian, 15, 21);
	lv_obj_set_size(ui->home_page_huo_jian, 20, 20);
	lv_obj_set_scrollbar_mode(ui->home_page_huo_jian, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_page_huo_jian_main_main_default
	static lv_style_t style_home_page_huo_jian_main_main_default;
	if (style_home_page_huo_jian_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_huo_jian_main_main_default);
	else
		lv_style_init(&style_home_page_huo_jian_main_main_default);
	lv_style_set_img_recolor(&style_home_page_huo_jian_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_page_huo_jian_main_main_default, 0);
	lv_style_set_img_opa(&style_home_page_huo_jian_main_main_default, 255);
	lv_obj_add_style(ui->home_page_huo_jian, &style_home_page_huo_jian_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->home_page_huo_jian, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->home_page_huo_jian,&_huojian_20x20);
	lv_img_set_pivot(ui->home_page_huo_jian, 0,0);
	lv_img_set_angle(ui->home_page_huo_jian, 0);

	//Write codes home_page_data_riqi
	ui->home_page_data_riqi = lv_spangroup_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_data_riqi, 42, 20);
	lv_obj_set_size(ui->home_page_data_riqi, 57, 21);
	lv_obj_set_scrollbar_mode(ui->home_page_data_riqi, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->home_page_data_riqi, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->home_page_data_riqi, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->home_page_data_riqi, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_home_page_data_riqi_main_main_default
	static lv_style_t style_home_page_data_riqi_main_main_default;
	if (style_home_page_data_riqi_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_data_riqi_main_main_default);
	else
		lv_style_init(&style_home_page_data_riqi_main_main_default);
	lv_style_set_radius(&style_home_page_data_riqi_main_main_default, 0);
	lv_style_set_bg_color(&style_home_page_data_riqi_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_page_data_riqi_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_page_data_riqi_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_page_data_riqi_main_main_default, 0);
	lv_style_set_border_color(&style_home_page_data_riqi_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_home_page_data_riqi_main_main_default, 0);
	lv_style_set_border_opa(&style_home_page_data_riqi_main_main_default, 255);
	lv_style_set_pad_left(&style_home_page_data_riqi_main_main_default, 0);
	lv_style_set_pad_right(&style_home_page_data_riqi_main_main_default, 0);
	lv_style_set_pad_top(&style_home_page_data_riqi_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_page_data_riqi_main_main_default, 0);
	lv_obj_add_style(ui->home_page_data_riqi, &style_home_page_data_riqi_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);



	//create a new span
	home_page_data_riqi_span = lv_spangroup_new_span(ui->home_page_data_riqi);
    sprintf(value_strbuf,"%2d.%02d",ui_DateMonthValue,ui_DateDayValue);//月.日
    lv_span_set_text(home_page_data_riqi_span, value_strbuf);
	lv_style_set_text_color(&home_page_data_riqi_span->style, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_decor(&home_page_data_riqi_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&home_page_data_riqi_span->style, &lv_font_simsun_20);
	lv_spangroup_refr_mode(ui->home_page_data_riqi);

	//Write codes home_page_data_week
	ui->home_page_data_week = lv_spangroup_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_data_week, 105, 21);
	lv_obj_set_size(ui->home_page_data_week, 46, 20);
	lv_obj_set_scrollbar_mode(ui->home_page_data_week, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->home_page_data_week, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->home_page_data_week, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->home_page_data_week, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_home_page_data_week_main_main_default
	static lv_style_t style_home_page_data_week_main_main_default;
	if (style_home_page_data_week_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_data_week_main_main_default);
	else
		lv_style_init(&style_home_page_data_week_main_main_default);
	lv_style_set_radius(&style_home_page_data_week_main_main_default, 0);
	lv_style_set_bg_color(&style_home_page_data_week_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_page_data_week_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_page_data_week_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_page_data_week_main_main_default, 0);
	lv_style_set_border_color(&style_home_page_data_week_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_home_page_data_week_main_main_default, 0);
	lv_style_set_border_opa(&style_home_page_data_week_main_main_default, 255);
	lv_style_set_pad_left(&style_home_page_data_week_main_main_default, 0);
	lv_style_set_pad_right(&style_home_page_data_week_main_main_default, 0);
	lv_style_set_pad_top(&style_home_page_data_week_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_page_data_week_main_main_default, 0);
	lv_obj_add_style(ui->home_page_data_week, &style_home_page_data_week_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);



	//create a new span
	home_page_data_week_span = lv_spangroup_new_span(ui->home_page_data_week);
    lv_span_set_text(home_page_data_week_span, ui_Days[ui_DataWeekdayValue-1]);//week
	lv_style_set_text_color(&home_page_data_week_span->style, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_decor(&home_page_data_week_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&home_page_data_week_span->style, &lv_font_simsun_20);
	lv_spangroup_refr_mode(ui->home_page_data_week);

	//Write codes home_page_line_3
	ui->home_page_line_3 = lv_line_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_line_3, 155, 10);
	lv_obj_set_size(ui->home_page_line_3, 4, 44);
	lv_obj_set_scrollbar_mode(ui->home_page_line_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_page_line_3_main_main_default
	static lv_style_t style_home_page_line_3_main_main_default;
	if (style_home_page_line_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_line_3_main_main_default);
	else
		lv_style_init(&style_home_page_line_3_main_main_default);
	lv_style_set_line_color(&style_home_page_line_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_home_page_line_3_main_main_default, 2);
	lv_style_set_line_rounded(&style_home_page_line_3_main_main_default, true);
	lv_obj_add_style(ui->home_page_line_3, &style_home_page_line_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t home_page_line_3[] ={{0, 0},{0, 50},};
	lv_line_set_points(ui->home_page_line_3,home_page_line_3,2);

	//Write codes home_page_line_5
	ui->home_page_line_5 = lv_line_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_line_5, 80, 229);
	lv_obj_set_size(ui->home_page_line_5, 5, 32);
	lv_obj_set_scrollbar_mode(ui->home_page_line_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_page_line_5_main_main_default
	static lv_style_t style_home_page_line_5_main_main_default;
	if (style_home_page_line_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_line_5_main_main_default);
	else
		lv_style_init(&style_home_page_line_5_main_main_default);
	lv_style_set_line_color(&style_home_page_line_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_home_page_line_5_main_main_default, 2);
	lv_style_set_line_rounded(&style_home_page_line_5_main_main_default, true);
	lv_obj_add_style(ui->home_page_line_5, &style_home_page_line_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t home_page_line_5[] ={{0, 0},{0, 50},};
	lv_line_set_points(ui->home_page_line_5,home_page_line_5,2);

	//Write codes home_page_line_6
	ui->home_page_line_6 = lv_line_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_line_6, 160, 229);
	lv_obj_set_size(ui->home_page_line_6, 5, 32);
	lv_obj_set_scrollbar_mode(ui->home_page_line_6, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_page_line_6_main_main_default
	static lv_style_t style_home_page_line_6_main_main_default;
	if (style_home_page_line_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_line_6_main_main_default);
	else
		lv_style_init(&style_home_page_line_6_main_main_default);
	lv_style_set_line_color(&style_home_page_line_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_line_width(&style_home_page_line_6_main_main_default, 2);
	lv_style_set_line_rounded(&style_home_page_line_6_main_main_default, true);
	lv_obj_add_style(ui->home_page_line_6, &style_home_page_line_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	static lv_point_t home_page_line_6[] ={{0, 0},{0, 50},};
	lv_line_set_points(ui->home_page_line_6,home_page_line_6,2);

	//Write codes home_page_xin_lv
	ui->home_page_xin_lv = lv_img_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_xin_lv, 160, 194);
	lv_obj_set_size(ui->home_page_xin_lv, 20, 20);
	lv_obj_set_scrollbar_mode(ui->home_page_xin_lv, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_page_xin_lv_main_main_default
	static lv_style_t style_home_page_xin_lv_main_main_default;
	if (style_home_page_xin_lv_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_xin_lv_main_main_default);
	else
		lv_style_init(&style_home_page_xin_lv_main_main_default);
	lv_style_set_img_recolor(&style_home_page_xin_lv_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_page_xin_lv_main_main_default, 0);
	lv_style_set_img_opa(&style_home_page_xin_lv_main_main_default, 255);
	lv_obj_add_style(ui->home_page_xin_lv, &style_home_page_xin_lv_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->home_page_xin_lv, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->home_page_xin_lv,&_xinlv_20x20);
	lv_img_set_pivot(ui->home_page_xin_lv, 0,0);
	lv_img_set_angle(ui->home_page_xin_lv, 0);

	//Write codes home_page_data_xinlv
	ui->home_page_data_xinlv = lv_spangroup_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_data_xinlv, 194, 194);
	lv_obj_set_size(ui->home_page_data_xinlv, 46, 20);
	lv_obj_set_scrollbar_mode(ui->home_page_data_xinlv, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->home_page_data_xinlv, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->home_page_data_xinlv, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->home_page_data_xinlv, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_home_page_data_xinlv_main_main_default
	static lv_style_t style_home_page_data_xinlv_main_main_default;
	if (style_home_page_data_xinlv_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_data_xinlv_main_main_default);
	else
		lv_style_init(&style_home_page_data_xinlv_main_main_default);
	lv_style_set_radius(&style_home_page_data_xinlv_main_main_default, 0);
	lv_style_set_bg_color(&style_home_page_data_xinlv_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_page_data_xinlv_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_page_data_xinlv_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_page_data_xinlv_main_main_default, 0);
	lv_style_set_border_color(&style_home_page_data_xinlv_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_home_page_data_xinlv_main_main_default, 0);
	lv_style_set_border_opa(&style_home_page_data_xinlv_main_main_default, 255);
	lv_style_set_pad_left(&style_home_page_data_xinlv_main_main_default, 0);
	lv_style_set_pad_right(&style_home_page_data_xinlv_main_main_default, 0);
	lv_style_set_pad_top(&style_home_page_data_xinlv_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_page_data_xinlv_main_main_default, 0);
	lv_obj_add_style(ui->home_page_data_xinlv, &style_home_page_data_xinlv_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);



	//create a new span
	home_page_data_xinlv_span = lv_spangroup_new_span(ui->home_page_data_xinlv);
    sprintf(value_strbuf, "%d", ui_HRValue);
    lv_span_set_text(home_page_data_xinlv_span,value_strbuf);                         //心率
	lv_style_set_text_color(&home_page_data_xinlv_span->style, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_decor(&home_page_data_xinlv_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&home_page_data_xinlv_span->style, &lv_font_simsun_20);
	lv_spangroup_refr_mode(ui->home_page_data_xinlv);

	//Write codes home_page_wen_du
	ui->home_page_wen_du = lv_img_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_wen_du, 10, 236);
	lv_obj_set_size(ui->home_page_wen_du, 20, 20);
	lv_obj_set_scrollbar_mode(ui->home_page_wen_du, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_page_wen_du_main_main_default
	static lv_style_t style_home_page_wen_du_main_main_default;
	if (style_home_page_wen_du_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_wen_du_main_main_default);
	else
		lv_style_init(&style_home_page_wen_du_main_main_default);
	lv_style_set_img_recolor(&style_home_page_wen_du_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_page_wen_du_main_main_default, 0);
	lv_style_set_img_opa(&style_home_page_wen_du_main_main_default, 255);
	lv_obj_add_style(ui->home_page_wen_du, &style_home_page_wen_du_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->home_page_wen_du, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->home_page_wen_du,&_wendu1_20x20);
	lv_img_set_pivot(ui->home_page_wen_du, 0,0);
	lv_img_set_angle(ui->home_page_wen_du, 0);

	//Write codes home_page_data_wendu
	ui->home_page_data_wendu = lv_spangroup_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_data_wendu, 30, 236);
	lv_obj_set_size(ui->home_page_data_wendu, 59, 22);
	lv_obj_set_scrollbar_mode(ui->home_page_data_wendu, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->home_page_data_wendu, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->home_page_data_wendu, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->home_page_data_wendu, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_home_page_data_wendu_main_main_default
	static lv_style_t style_home_page_data_wendu_main_main_default;
	if (style_home_page_data_wendu_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_data_wendu_main_main_default);
	else
		lv_style_init(&style_home_page_data_wendu_main_main_default);
	lv_style_set_radius(&style_home_page_data_wendu_main_main_default, 0);
	lv_style_set_bg_color(&style_home_page_data_wendu_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_page_data_wendu_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_page_data_wendu_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_page_data_wendu_main_main_default, 0);
	lv_style_set_border_color(&style_home_page_data_wendu_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_home_page_data_wendu_main_main_default, 0);
	lv_style_set_border_opa(&style_home_page_data_wendu_main_main_default, 255);
	lv_style_set_pad_left(&style_home_page_data_wendu_main_main_default, 0);
	lv_style_set_pad_right(&style_home_page_data_wendu_main_main_default, 0);
	lv_style_set_pad_top(&style_home_page_data_wendu_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_page_data_wendu_main_main_default, 0);
	lv_obj_add_style(ui->home_page_data_wendu, &style_home_page_data_wendu_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);



	//create a new span
	home_page_data_wendu_span = lv_spangroup_new_span(ui->home_page_data_wendu);
    sprintf(value_strbuf,"%d",ui_EnvTempValue);
    lv_span_set_text(home_page_data_wendu_span,value_strbuf);               //温度
	lv_style_set_text_color(&home_page_data_wendu_span->style, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_decor(&home_page_data_wendu_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&home_page_data_wendu_span->style, &lv_font_simsun_20);
	lv_spangroup_refr_mode(ui->home_page_data_wendu);

	//Write codes home_page_sheshidu
	ui->home_page_sheshidu = lv_spangroup_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_sheshidu, 53, 236);
	lv_obj_set_size(ui->home_page_sheshidu, 59, 22);
	lv_obj_set_scrollbar_mode(ui->home_page_sheshidu, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->home_page_sheshidu, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->home_page_sheshidu, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->home_page_sheshidu, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_home_page_sheshidu_main_main_default
	static lv_style_t style_home_page_sheshidu_main_main_default;
	if (style_home_page_sheshidu_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_sheshidu_main_main_default);
	else
		lv_style_init(&style_home_page_sheshidu_main_main_default);
	lv_style_set_radius(&style_home_page_sheshidu_main_main_default, 0);
	lv_style_set_bg_color(&style_home_page_sheshidu_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_page_sheshidu_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_page_sheshidu_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_page_sheshidu_main_main_default, 0);
	lv_style_set_border_color(&style_home_page_sheshidu_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_home_page_sheshidu_main_main_default, 0);
	lv_style_set_border_opa(&style_home_page_sheshidu_main_main_default, 255);
	lv_style_set_pad_left(&style_home_page_sheshidu_main_main_default, 0);
	lv_style_set_pad_right(&style_home_page_sheshidu_main_main_default, 0);
	lv_style_set_pad_top(&style_home_page_sheshidu_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_page_sheshidu_main_main_default, 0);
	lv_obj_add_style(ui->home_page_sheshidu, &style_home_page_sheshidu_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//create spans
	lv_span_t *home_page_sheshidu_span;

	//create a new span
	home_page_sheshidu_span = lv_spangroup_new_span(ui->home_page_sheshidu);
	lv_span_set_text(home_page_sheshidu_span, "℃");
	lv_style_set_text_color(&home_page_sheshidu_span->style, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_decor(&home_page_sheshidu_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&home_page_sheshidu_span->style, &lv_font_simsun_20);
	lv_spangroup_refr_mode(ui->home_page_sheshidu);

	//Write codes home_page_data_shidu
	ui->home_page_data_shidu = lv_spangroup_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_data_shidu, 110, 236);
	lv_obj_set_size(ui->home_page_data_shidu, 59, 22);
	lv_obj_set_scrollbar_mode(ui->home_page_data_shidu, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->home_page_data_shidu, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->home_page_data_shidu, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->home_page_data_shidu, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_home_page_data_shidu_main_main_default
	static lv_style_t style_home_page_data_shidu_main_main_default;
	if (style_home_page_data_shidu_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_data_shidu_main_main_default);
	else
		lv_style_init(&style_home_page_data_shidu_main_main_default);
	lv_style_set_radius(&style_home_page_data_shidu_main_main_default, 0);
	lv_style_set_bg_color(&style_home_page_data_shidu_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_page_data_shidu_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_page_data_shidu_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_page_data_shidu_main_main_default, 0);
	lv_style_set_border_color(&style_home_page_data_shidu_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_home_page_data_shidu_main_main_default, 0);
	lv_style_set_border_opa(&style_home_page_data_shidu_main_main_default, 255);
	lv_style_set_pad_left(&style_home_page_data_shidu_main_main_default, 0);
	lv_style_set_pad_right(&style_home_page_data_shidu_main_main_default, 0);
	lv_style_set_pad_top(&style_home_page_data_shidu_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_page_data_shidu_main_main_default, 0);
	lv_obj_add_style(ui->home_page_data_shidu, &style_home_page_data_shidu_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);


	//create a new span
	home_page_data_shidu_span = lv_spangroup_new_span(ui->home_page_data_shidu);
    sprintf(value_strbuf,"%d%c",ui_EnvHumiValue,baifenhao);
    lv_span_set_text(home_page_data_shidu_span,value_strbuf);//湿度
	lv_style_set_text_color(&home_page_data_shidu_span->style, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_decor(&home_page_data_shidu_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&home_page_data_shidu_span->style, &lv_font_simsun_20);
	lv_spangroup_refr_mode(ui->home_page_data_shidu);

	//Write codes home_page_shidu
	ui->home_page_shidu = lv_img_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_shidu, 90, 236);
	lv_obj_set_size(ui->home_page_shidu, 20, 20);
	lv_obj_set_scrollbar_mode(ui->home_page_shidu, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_page_shidu_main_main_default
	static lv_style_t style_home_page_shidu_main_main_default;
	if (style_home_page_shidu_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_shidu_main_main_default);
	else
		lv_style_init(&style_home_page_shidu_main_main_default);
	lv_style_set_img_recolor(&style_home_page_shidu_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_page_shidu_main_main_default, 0);
	lv_style_set_img_opa(&style_home_page_shidu_main_main_default, 255);
	lv_obj_add_style(ui->home_page_shidu, &style_home_page_shidu_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->home_page_shidu, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->home_page_shidu,&_shidu_20x20);
	lv_img_set_pivot(ui->home_page_shidu, 0,0);
	lv_img_set_angle(ui->home_page_shidu, 0);

	//Write codes home_page_bushu
	ui->home_page_bushu = lv_img_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_bushu, 10, 194);
	lv_obj_set_size(ui->home_page_bushu, 20, 20);
	lv_obj_set_scrollbar_mode(ui->home_page_bushu, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_page_bushu_main_main_default
	static lv_style_t style_home_page_bushu_main_main_default;
	if (style_home_page_bushu_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_bushu_main_main_default);
	else
		lv_style_init(&style_home_page_bushu_main_main_default);
	lv_style_set_img_recolor(&style_home_page_bushu_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_page_bushu_main_main_default, 0);
	lv_style_set_img_opa(&style_home_page_bushu_main_main_default, 255);
	lv_obj_add_style(ui->home_page_bushu, &style_home_page_bushu_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->home_page_bushu, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->home_page_bushu,&_buhsu_20x20);
	lv_img_set_pivot(ui->home_page_bushu, 0,0);
	lv_img_set_angle(ui->home_page_bushu, 0);

	//Write codes home_page_data_bushu
	ui->home_page_data_bushu = lv_spangroup_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_data_bushu, 41, 193);
	lv_obj_set_size(ui->home_page_data_bushu, 82, 21);
	lv_obj_set_scrollbar_mode(ui->home_page_data_bushu, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->home_page_data_bushu, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->home_page_data_bushu, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->home_page_data_bushu, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_home_page_data_bushu_main_main_default
	static lv_style_t style_home_page_data_bushu_main_main_default;
	if (style_home_page_data_bushu_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_data_bushu_main_main_default);
	else
		lv_style_init(&style_home_page_data_bushu_main_main_default);
	lv_style_set_radius(&style_home_page_data_bushu_main_main_default, 0);
	lv_style_set_bg_color(&style_home_page_data_bushu_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_page_data_bushu_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_page_data_bushu_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_page_data_bushu_main_main_default, 0);
	lv_style_set_border_color(&style_home_page_data_bushu_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_home_page_data_bushu_main_main_default, 0);
	lv_style_set_border_opa(&style_home_page_data_bushu_main_main_default, 0);
	lv_style_set_pad_left(&style_home_page_data_bushu_main_main_default, 0);
	lv_style_set_pad_right(&style_home_page_data_bushu_main_main_default, 0);
	lv_style_set_pad_top(&style_home_page_data_bushu_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_page_data_bushu_main_main_default, 0);
	lv_obj_add_style(ui->home_page_data_bushu, &style_home_page_data_bushu_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);



	//create a new span
	home_page_data_bushu_span = lv_spangroup_new_span(ui->home_page_data_bushu);
    sprintf(value_strbuf,"%d",ui_StepNumValue);
    lv_span_set_text(home_page_data_bushu_span, value_strbuf);       //步数
	lv_style_set_text_color(&home_page_data_bushu_span->style, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_decor(&home_page_data_bushu_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&home_page_data_bushu_span->style, &lv_font_simsun_20);
	lv_spangroup_refr_mode(ui->home_page_data_bushu);

	//Write codes home_page_caidan
	ui->home_page_caidan = lv_imgbtn_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_caidan, 163, 206);
	lv_obj_set_size(ui->home_page_caidan, 75, 85);
	lv_obj_set_scrollbar_mode(ui->home_page_caidan, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_page_caidan_main_main_default
	static lv_style_t style_home_page_caidan_main_main_default;
	if (style_home_page_caidan_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_caidan_main_main_default);
	else
		lv_style_init(&style_home_page_caidan_main_main_default);
	lv_style_set_text_color(&style_home_page_caidan_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_page_caidan_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_align(&style_home_page_caidan_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_home_page_caidan_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_page_caidan_main_main_default, 0);
	lv_style_set_img_opa(&style_home_page_caidan_main_main_default, 255);
	lv_obj_add_style(ui->home_page_caidan, &style_home_page_caidan_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_home_page_caidan_main_main_pressed
	static lv_style_t style_home_page_caidan_main_main_pressed;
	if (style_home_page_caidan_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_home_page_caidan_main_main_pressed);
	else
		lv_style_init(&style_home_page_caidan_main_main_pressed);
	lv_style_set_text_color(&style_home_page_caidan_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_font(&style_home_page_caidan_main_main_pressed, &lv_font_simsun_12);
	lv_style_set_text_align(&style_home_page_caidan_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_home_page_caidan_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_page_caidan_main_main_pressed, 0);
	lv_style_set_img_opa(&style_home_page_caidan_main_main_pressed, 255);
	lv_obj_add_style(ui->home_page_caidan, &style_home_page_caidan_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_home_page_caidan_main_main_checked
	static lv_style_t style_home_page_caidan_main_main_checked;
	if (style_home_page_caidan_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_home_page_caidan_main_main_checked);
	else
		lv_style_init(&style_home_page_caidan_main_main_checked);
	lv_style_set_text_color(&style_home_page_caidan_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_font(&style_home_page_caidan_main_main_checked, &lv_font_simsun_12);
	lv_style_set_text_align(&style_home_page_caidan_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_home_page_caidan_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_page_caidan_main_main_checked, 0);
	lv_style_set_img_opa(&style_home_page_caidan_main_main_checked, 255);
	lv_obj_add_style(ui->home_page_caidan, &style_home_page_caidan_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_obj_add_flag(ui->home_page_caidan, LV_OBJ_FLAG_CHECKABLE);
	ui->home_page_caidan_label = lv_label_create(ui->home_page_caidan);
	lv_label_set_text(ui->home_page_caidan_label, "菜单");
	lv_obj_set_style_pad_all(ui->home_page_caidan, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->home_page_caidan_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes home_page_data_miao
	ui->home_page_data_miao = lv_spangroup_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_data_miao, 194, 86);
	lv_obj_set_size(ui->home_page_data_miao, 30, 20);
	lv_obj_set_scrollbar_mode(ui->home_page_data_miao, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->home_page_data_miao, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->home_page_data_miao, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->home_page_data_miao, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_home_page_data_miao_main_main_default
	static lv_style_t style_home_page_data_miao_main_main_default;
	if (style_home_page_data_miao_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_data_miao_main_main_default);
	else
		lv_style_init(&style_home_page_data_miao_main_main_default);
	lv_style_set_radius(&style_home_page_data_miao_main_main_default, 0);
	lv_style_set_bg_color(&style_home_page_data_miao_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_page_data_miao_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_page_data_miao_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_page_data_miao_main_main_default, 0);
	lv_style_set_border_color(&style_home_page_data_miao_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_home_page_data_miao_main_main_default, 0);
	lv_style_set_border_opa(&style_home_page_data_miao_main_main_default, 255);
	lv_style_set_pad_left(&style_home_page_data_miao_main_main_default, 0);
	lv_style_set_pad_right(&style_home_page_data_miao_main_main_default, 0);
	lv_style_set_pad_top(&style_home_page_data_miao_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_page_data_miao_main_main_default, 0);
	lv_obj_add_style(ui->home_page_data_miao, &style_home_page_data_miao_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//create spans
	lv_span_t *home_page_data_miao_span;

	//create a new span
	home_page_data_miao_span = lv_spangroup_new_span(ui->home_page_data_miao);
//	lv_span_set_text(home_page_data_miao_span, "20");
	lv_style_set_text_color(&home_page_data_miao_span->style, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_decor(&home_page_data_miao_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&home_page_data_miao_span->style, &lv_font_simsun_20);
	lv_spangroup_refr_mode(ui->home_page_data_miao);

	//Write codes home_page_data_haiba
	ui->home_page_data_haiba = lv_spangroup_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_data_haiba, 173, 161);
	lv_obj_set_size(ui->home_page_data_haiba, 66, 18);
	lv_obj_set_scrollbar_mode(ui->home_page_data_haiba, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->home_page_data_haiba, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->home_page_data_haiba, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->home_page_data_haiba, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_home_page_data_haiba_main_main_default
	static lv_style_t style_home_page_data_haiba_main_main_default;
	if (style_home_page_data_haiba_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_data_haiba_main_main_default);
	else
		lv_style_init(&style_home_page_data_haiba_main_main_default);
	lv_style_set_radius(&style_home_page_data_haiba_main_main_default, 0);
	lv_style_set_bg_color(&style_home_page_data_haiba_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_page_data_haiba_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_page_data_haiba_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_page_data_haiba_main_main_default, 0);
	lv_style_set_border_color(&style_home_page_data_haiba_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_home_page_data_haiba_main_main_default, 0);
	lv_style_set_border_opa(&style_home_page_data_haiba_main_main_default, 255);
	lv_style_set_pad_left(&style_home_page_data_haiba_main_main_default, 0);
	lv_style_set_pad_right(&style_home_page_data_haiba_main_main_default, 0);
	lv_style_set_pad_top(&style_home_page_data_haiba_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_page_data_haiba_main_main_default, 0);
	lv_obj_add_style(ui->home_page_data_haiba, &style_home_page_data_haiba_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);



	//create a new span
	home_page_data_haiba_span = lv_spangroup_new_span(ui->home_page_data_haiba);
    sprintf(value_strbuf,":%dm", ui_EnvAltitudeValue);
    lv_span_set_text(home_page_data_haiba_span, value_strbuf);                        //海拔
	lv_style_set_text_color(&home_page_data_haiba_span->style, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_decor(&home_page_data_haiba_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&home_page_data_haiba_span->style, &lv_font_simsun_20);
	lv_spangroup_refr_mode(ui->home_page_data_haiba);

	//Write codes home_page_spangroup_1
	ui->home_page_spangroup_1 = lv_spangroup_create(ui->home_page);
	lv_obj_set_pos(ui->home_page_spangroup_1, 150, 135);
	lv_obj_set_size(ui->home_page_spangroup_1, 69, 20);
	lv_obj_set_scrollbar_mode(ui->home_page_spangroup_1, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->home_page_spangroup_1, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->home_page_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->home_page_spangroup_1, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_home_page_spangroup_1_main_main_default
	static lv_style_t style_home_page_spangroup_1_main_main_default;
	if (style_home_page_spangroup_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_page_spangroup_1_main_main_default);
	else
		lv_style_init(&style_home_page_spangroup_1_main_main_default);
	lv_style_set_radius(&style_home_page_spangroup_1_main_main_default, 0);
	lv_style_set_bg_color(&style_home_page_spangroup_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_page_spangroup_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_page_spangroup_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_page_spangroup_1_main_main_default, 0);
	lv_style_set_border_color(&style_home_page_spangroup_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_home_page_spangroup_1_main_main_default, 0);
	lv_style_set_border_opa(&style_home_page_spangroup_1_main_main_default, 255);
	lv_style_set_pad_left(&style_home_page_spangroup_1_main_main_default, 0);
	lv_style_set_pad_right(&style_home_page_spangroup_1_main_main_default, 0);
	lv_style_set_pad_top(&style_home_page_spangroup_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_page_spangroup_1_main_main_default, 0);
	lv_obj_add_style(ui->home_page_spangroup_1, &style_home_page_spangroup_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//create spans
	lv_span_t *home_page_spangroup_1_span;

	//create a new span
	home_page_spangroup_1_span = lv_spangroup_new_span(ui->home_page_spangroup_1);
	lv_span_set_text(home_page_spangroup_1_span, "海 拔");
	lv_style_set_text_color(&home_page_spangroup_1_span->style, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_decor(&home_page_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&home_page_spangroup_1_span->style, &lv_font_simsun_20);
	lv_spangroup_refr_mode(ui->home_page_spangroup_1);

	//Init events for screen
	events_init_home_page(ui);
}



