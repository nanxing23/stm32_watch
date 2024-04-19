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

	lv_span_t *chongdian_page_spangroup_1_span;//充电动画

void setup_scr_chongdian_page(lv_ui *ui){

    char value_strbuf[10];
	//Write codes chongdian_page
	ui->chongdian_page = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->chongdian_page, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_chongdian_page_main_main_default
	static lv_style_t style_chongdian_page_main_main_default;
	if (style_chongdian_page_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_chongdian_page_main_main_default);
	else
		lv_style_init(&style_chongdian_page_main_main_default);
	lv_style_set_bg_color(&style_chongdian_page_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_chongdian_page_main_main_default, 255);
	lv_obj_add_style(ui->chongdian_page, &style_chongdian_page_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes chongdian_page_label_1
	ui->chongdian_page_label_1 = lv_label_create(ui->chongdian_page);
	lv_obj_set_pos(ui->chongdian_page_label_1, 40, 55);
	lv_obj_set_size(ui->chongdian_page_label_1, 160, 50);
	lv_obj_set_scrollbar_mode(ui->chongdian_page_label_1, LV_SCROLLBAR_MODE_OFF);
    sprintf(value_strbuf,"%2d:%02d",ui_TimeHourValue,ui_TimeMinuteValuec);//时：分
    lv_label_set_text(ui->chongdian_page_label_1,value_strbuf);
	lv_label_set_long_mode(ui->chongdian_page_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_chongdian_page_label_1_main_main_default
	static lv_style_t style_chongdian_page_label_1_main_main_default;
	if (style_chongdian_page_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_chongdian_page_label_1_main_main_default);
	else
		lv_style_init(&style_chongdian_page_label_1_main_main_default);
	lv_style_set_radius(&style_chongdian_page_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_chongdian_page_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_chongdian_page_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_chongdian_page_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_chongdian_page_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_chongdian_page_label_1_main_main_default, lv_color_make(0x00, 0xff, 0x11));
	lv_style_set_text_font(&style_chongdian_page_label_1_main_main_default, &lv_font_simsun_40);
	lv_style_set_text_letter_space(&style_chongdian_page_label_1_main_main_default, 10);
	lv_style_set_text_line_space(&style_chongdian_page_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_chongdian_page_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_chongdian_page_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_chongdian_page_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_chongdian_page_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_chongdian_page_label_1_main_main_default, 0);
	lv_obj_add_style(ui->chongdian_page_label_1, &style_chongdian_page_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes chongdian_page_spangroup_1
	ui->chongdian_page_spangroup_1 = lv_spangroup_create(ui->chongdian_page);
	lv_obj_set_pos(ui->chongdian_page_spangroup_1, 100, 200);
	lv_obj_set_size(ui->chongdian_page_spangroup_1, 80, 50);
	lv_obj_set_scrollbar_mode(ui->chongdian_page_spangroup_1, LV_SCROLLBAR_MODE_OFF);
	lv_spangroup_set_align(ui->chongdian_page_spangroup_1, LV_TEXT_ALIGN_LEFT);
	lv_spangroup_set_overflow(ui->chongdian_page_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
	lv_spangroup_set_mode(ui->chongdian_page_spangroup_1, LV_SPAN_MODE_BREAK);

	//Write style state: LV_STATE_DEFAULT for style_chongdian_page_spangroup_1_main_main_default
	static lv_style_t style_chongdian_page_spangroup_1_main_main_default;
	if (style_chongdian_page_spangroup_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_chongdian_page_spangroup_1_main_main_default);
	else
		lv_style_init(&style_chongdian_page_spangroup_1_main_main_default);
	lv_style_set_radius(&style_chongdian_page_spangroup_1_main_main_default, 0);
	lv_style_set_bg_color(&style_chongdian_page_spangroup_1_main_main_default, lv_color_make(0x00, 0xff, 0x11));
	lv_style_set_bg_grad_color(&style_chongdian_page_spangroup_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_chongdian_page_spangroup_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_chongdian_page_spangroup_1_main_main_default, 0);
	lv_style_set_border_color(&style_chongdian_page_spangroup_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_chongdian_page_spangroup_1_main_main_default, 0);
	lv_style_set_border_opa(&style_chongdian_page_spangroup_1_main_main_default, 255);
	lv_style_set_pad_left(&style_chongdian_page_spangroup_1_main_main_default, 0);
	lv_style_set_pad_right(&style_chongdian_page_spangroup_1_main_main_default, 0);
	lv_style_set_pad_top(&style_chongdian_page_spangroup_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_chongdian_page_spangroup_1_main_main_default, 0);
	lv_obj_add_style(ui->chongdian_page_spangroup_1, &style_chongdian_page_spangroup_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);



	//create a new span
	chongdian_page_spangroup_1_span = lv_spangroup_new_span(ui->chongdian_page_spangroup_1);
	lv_span_set_text(chongdian_page_spangroup_1_span, "...");
	lv_style_set_text_color(&chongdian_page_spangroup_1_span->style, lv_color_make(0x00, 0xff, 0x11));
	lv_style_set_text_decor(&chongdian_page_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
	lv_style_set_text_font(&chongdian_page_spangroup_1_span->style, &lv_font_simsun_40);
	lv_spangroup_refr_mode(ui->chongdian_page_spangroup_1);

	//Write codes chongdian_page_label_2
	ui->chongdian_page_label_2 = lv_label_create(ui->chongdian_page);
	lv_obj_set_pos(ui->chongdian_page_label_2, 60, 150);
	lv_obj_set_size(ui->chongdian_page_label_2, 120, 50);
	lv_obj_set_scrollbar_mode(ui->chongdian_page_label_2, LV_SCROLLBAR_MODE_OFF);
    if(ui_BatArcValue>0 && ui_BatArcValue<=100)
    {
        sprintf(value_strbuf,"%2d%%",ui_BatArcValue);
        lv_label_set_text(guider_ui.chongdian_page_label_2, value_strbuf);
    }
	lv_label_set_long_mode(ui->chongdian_page_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_chongdian_page_label_2_main_main_default
	static lv_style_t style_chongdian_page_label_2_main_main_default;
	if (style_chongdian_page_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_chongdian_page_label_2_main_main_default);
	else
		lv_style_init(&style_chongdian_page_label_2_main_main_default);
	lv_style_set_radius(&style_chongdian_page_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_chongdian_page_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_chongdian_page_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_chongdian_page_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_chongdian_page_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_chongdian_page_label_2_main_main_default, lv_color_make(0x00, 0xff, 0x11));
	lv_style_set_text_font(&style_chongdian_page_label_2_main_main_default, &lv_font_simsun_40);
	lv_style_set_text_letter_space(&style_chongdian_page_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_chongdian_page_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_chongdian_page_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_chongdian_page_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_chongdian_page_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_chongdian_page_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_chongdian_page_label_2_main_main_default, 0);
	lv_obj_add_style(ui->chongdian_page_label_2, &style_chongdian_page_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
}