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

 
 ///////////////////// 变量 ////////////////////
lv_timer_t * ui_TimerPageTimer;//定时器标志

uint8_t ui_TimerPageFlag=0;
uint8_t ui_TimerPage_min=0;
uint8_t ui_TimerPage_sec=0;
uint8_t ui_TimerPage_10ms=0;
uint8_t ui_TimerPage_ms=0;


lv_span_t *miaobia_page_data_miaobiao_span;//秒表显示


///////////////////// 动画 ////////////////////
void setup_scr_miaobia_page(lv_ui *ui){
    
    ui_TimerPageFlag=0;
    ui_TimerPage_min=0;
    ui_TimerPage_sec=0;
	ui_TimerPage_10ms=0;
    ui_TimerPage_ms=0;
    
	//Write codes miaobia_page
	ui->miaobia_page = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->miaobia_page, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_miaobia_page_main_main_default
	static lv_style_t style_miaobia_page_main_main_default;
	if (style_miaobia_page_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_miaobia_page_main_main_default);
	else
		lv_style_init(&style_miaobia_page_main_main_default);
	lv_style_set_bg_color(&style_miaobia_page_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_miaobia_page_main_main_default, 255);
	lv_obj_add_style(ui->miaobia_page, &style_miaobia_page_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes miaobia_page_imgbtn_1
	ui->miaobia_page_imgbtn_1 = lv_imgbtn_create(ui->miaobia_page);
	lv_obj_set_pos(ui->miaobia_page_imgbtn_1, 140, 180);
	lv_obj_set_size(ui->miaobia_page_imgbtn_1, 40, 40);
	lv_obj_set_scrollbar_mode(ui->miaobia_page_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_miaobia_page_imgbtn_1_main_main_default
	static lv_style_t style_miaobia_page_imgbtn_1_main_main_default;
	if (style_miaobia_page_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_miaobia_page_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_miaobia_page_imgbtn_1_main_main_default);
	lv_style_set_text_color(&style_miaobia_page_imgbtn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_miaobia_page_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_miaobia_page_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_miaobia_page_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_miaobia_page_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->miaobia_page_imgbtn_1, &style_miaobia_page_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_miaobia_page_imgbtn_1_main_main_pressed
	static lv_style_t style_miaobia_page_imgbtn_1_main_main_pressed;
	if (style_miaobia_page_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_miaobia_page_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_miaobia_page_imgbtn_1_main_main_pressed);
	lv_style_set_text_color(&style_miaobia_page_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_miaobia_page_imgbtn_1_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_miaobia_page_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_miaobia_page_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_miaobia_page_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->miaobia_page_imgbtn_1, &style_miaobia_page_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_miaobia_page_imgbtn_1_main_main_checked
	static lv_style_t style_miaobia_page_imgbtn_1_main_main_checked;
	if (style_miaobia_page_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_miaobia_page_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_miaobia_page_imgbtn_1_main_main_checked);
	lv_style_set_text_color(&style_miaobia_page_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_miaobia_page_imgbtn_1_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_miaobia_page_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_miaobia_page_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_miaobia_page_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->miaobia_page_imgbtn_1, &style_miaobia_page_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->miaobia_page_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_kaishi_alpha_40x40, NULL);
	lv_imgbtn_set_src(ui->miaobia_page_imgbtn_1, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_zhating_alpha_40x40, NULL);
	lv_obj_add_flag(ui->miaobia_page_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);

	//Write codes miaobia_page_data_miaobiao
	ui->miaobia_page_data_miaobiao = lv_spangroup_create(ui->miaobia_page);
	lv_obj_set_pos(ui->miaobia_page_data_miaobiao, 38, 102);
	lv_obj_set_size(ui->miaobia_page_data_miaobiao, 165, 36);
	lv_obj_set_scrollbar_mode(ui->miaobia_page_data_miaobiao, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->miaobia_page_data_miaobiao, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->miaobia_page_data_miaobiao, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->miaobia_page_data_miaobiao, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_miaobia_page_data_miaobiao_main_main_default
	static lv_style_t style_miaobia_page_data_miaobiao_main_main_default;
	if (style_miaobia_page_data_miaobiao_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_miaobia_page_data_miaobiao_main_main_default);
	else
		lv_style_init(&style_miaobia_page_data_miaobiao_main_main_default);
	lv_style_set_radius(&style_miaobia_page_data_miaobiao_main_main_default, 0);
	lv_style_set_bg_color(&style_miaobia_page_data_miaobiao_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_miaobia_page_data_miaobiao_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_miaobia_page_data_miaobiao_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_miaobia_page_data_miaobiao_main_main_default, 0);
	lv_style_set_border_color(&style_miaobia_page_data_miaobiao_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_miaobia_page_data_miaobiao_main_main_default, 0);
	lv_style_set_border_opa(&style_miaobia_page_data_miaobiao_main_main_default, 255);
	lv_style_set_pad_left(&style_miaobia_page_data_miaobiao_main_main_default, 0);
	lv_style_set_pad_right(&style_miaobia_page_data_miaobiao_main_main_default, 0);
	lv_style_set_pad_top(&style_miaobia_page_data_miaobiao_main_main_default, 0);
	lv_style_set_pad_bottom(&style_miaobia_page_data_miaobiao_main_main_default, 0);
	lv_obj_add_style(ui->miaobia_page_data_miaobiao, &style_miaobia_page_data_miaobiao_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);


	//create a new span
	miaobia_page_data_miaobiao_span = lv_spangroup_new_span(ui->miaobia_page_data_miaobiao);
	lv_span_set_text(miaobia_page_data_miaobiao_span, "00:00:00");//显示
	lv_style_set_text_color(&miaobia_page_data_miaobiao_span->style, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_decor(&miaobia_page_data_miaobiao_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&miaobia_page_data_miaobiao_span->style, &lv_font_simsun_40);
	lv_spangroup_refr_mode(ui->miaobia_page_data_miaobiao);

	//Write codes miaobia_page_imgbtn_2
	ui->miaobia_page_imgbtn_2 = lv_imgbtn_create(ui->miaobia_page);
	lv_obj_set_pos(ui->miaobia_page_imgbtn_2, 60, 182);
	lv_obj_set_size(ui->miaobia_page_imgbtn_2, 35, 35);
	lv_obj_set_scrollbar_mode(ui->miaobia_page_imgbtn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_miaobia_page_imgbtn_2_main_main_default
	static lv_style_t style_miaobia_page_imgbtn_2_main_main_default;
	if (style_miaobia_page_imgbtn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_miaobia_page_imgbtn_2_main_main_default);
	else
		lv_style_init(&style_miaobia_page_imgbtn_2_main_main_default);
	lv_style_set_text_color(&style_miaobia_page_imgbtn_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_miaobia_page_imgbtn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_miaobia_page_imgbtn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_miaobia_page_imgbtn_2_main_main_default, 0);
	lv_style_set_img_opa(&style_miaobia_page_imgbtn_2_main_main_default, 255);
	lv_obj_add_style(ui->miaobia_page_imgbtn_2, &style_miaobia_page_imgbtn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_miaobia_page_imgbtn_2_main_main_pressed
	static lv_style_t style_miaobia_page_imgbtn_2_main_main_pressed;
	if (style_miaobia_page_imgbtn_2_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_miaobia_page_imgbtn_2_main_main_pressed);
	else
		lv_style_init(&style_miaobia_page_imgbtn_2_main_main_pressed);
	lv_style_set_text_color(&style_miaobia_page_imgbtn_2_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_miaobia_page_imgbtn_2_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_miaobia_page_imgbtn_2_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_miaobia_page_imgbtn_2_main_main_pressed, 0);
	lv_style_set_img_opa(&style_miaobia_page_imgbtn_2_main_main_pressed, 255);
	lv_obj_add_style(ui->miaobia_page_imgbtn_2, &style_miaobia_page_imgbtn_2_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_miaobia_page_imgbtn_2_main_main_checked
	static lv_style_t style_miaobia_page_imgbtn_2_main_main_checked;
	if (style_miaobia_page_imgbtn_2_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_miaobia_page_imgbtn_2_main_main_checked);
	else
		lv_style_init(&style_miaobia_page_imgbtn_2_main_main_checked);
	lv_style_set_text_color(&style_miaobia_page_imgbtn_2_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_miaobia_page_imgbtn_2_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_miaobia_page_imgbtn_2_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_miaobia_page_imgbtn_2_main_main_checked, 0);
	lv_style_set_img_opa(&style_miaobia_page_imgbtn_2_main_main_checked, 255);
	lv_obj_add_style(ui->miaobia_page_imgbtn_2, &style_miaobia_page_imgbtn_2_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->miaobia_page_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &_return_alpha_35x35, NULL);
	lv_obj_add_flag(ui->miaobia_page_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);
    
	events_init_miaobia_page(ui);
}