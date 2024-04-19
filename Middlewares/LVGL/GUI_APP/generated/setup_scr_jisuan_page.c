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


void setup_scr_jisuan_page(lv_ui *ui){

	//Write codes jisuan_page
	ui->jisuan_page = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->jisuan_page, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_jisuan_page_main_main_default
	static lv_style_t style_jisuan_page_main_main_default;
	if (style_jisuan_page_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_jisuan_page_main_main_default);
	else
		lv_style_init(&style_jisuan_page_main_main_default);
	lv_style_set_bg_color(&style_jisuan_page_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_jisuan_page_main_main_default, 255);
	lv_obj_add_style(ui->jisuan_page, &style_jisuan_page_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes jisuan_page_btnm_1
	ui->jisuan_page_btnm_1 = lv_btnmatrix_create(ui->jisuan_page);
	lv_obj_set_pos(ui->jisuan_page_btnm_1, 0, 50);
	lv_obj_set_size(ui->jisuan_page_btnm_1, 240, 240);
	lv_obj_set_scrollbar_mode(ui->jisuan_page_btnm_1, LV_SCROLLBAR_MODE_OFF);
	static const char *jisuan_page_btnm_1_text_map[] = {
	"recip","sq","-","del",
	"\n","7","8","9",
	"/","\n","4","5",
	"6","x","\n","1",
	"2","3","+","\n",
	"C","0",".","=",
	"",};
	lv_btnmatrix_set_map(ui->jisuan_page_btnm_1, jisuan_page_btnm_1_text_map);

	//Write style state: LV_STATE_DEFAULT for style_jisuan_page_btnm_1_main_main_default
	static lv_style_t style_jisuan_page_btnm_1_main_main_default;
	if (style_jisuan_page_btnm_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_jisuan_page_btnm_1_main_main_default);
	else
		lv_style_init(&style_jisuan_page_btnm_1_main_main_default);
	lv_style_set_radius(&style_jisuan_page_btnm_1_main_main_default, 0);
	lv_style_set_bg_color(&style_jisuan_page_btnm_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_jisuan_page_btnm_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_jisuan_page_btnm_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_jisuan_page_btnm_1_main_main_default, 255);
	lv_style_set_border_color(&style_jisuan_page_btnm_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_border_width(&style_jisuan_page_btnm_1_main_main_default, 0);
	lv_style_set_border_opa(&style_jisuan_page_btnm_1_main_main_default, 0);
	lv_style_set_pad_left(&style_jisuan_page_btnm_1_main_main_default, 16);
	lv_style_set_pad_right(&style_jisuan_page_btnm_1_main_main_default, 16);
	lv_style_set_pad_top(&style_jisuan_page_btnm_1_main_main_default, 16);
	lv_style_set_pad_bottom(&style_jisuan_page_btnm_1_main_main_default, 16);
	lv_style_set_pad_row(&style_jisuan_page_btnm_1_main_main_default, 8);
	lv_style_set_pad_column(&style_jisuan_page_btnm_1_main_main_default, 8);
	lv_obj_add_style(ui->jisuan_page_btnm_1, &style_jisuan_page_btnm_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);


//Write codes jisuan_page_label_1
	ui->jisuan_page_label_1 = lv_label_create(ui->jisuan_page);
	lv_obj_set_pos(ui->jisuan_page_label_1, 8, 7);
	lv_obj_set_size(ui->jisuan_page_label_1, 225, 50);
	lv_obj_set_scrollbar_mode(ui->jisuan_page_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->jisuan_page_label_1, "0");
	lv_label_set_long_mode(ui->jisuan_page_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_jisuan_page_label_1_main_main_default
	static lv_style_t style_jisuan_page_label_1_main_main_default;
	if (style_jisuan_page_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_jisuan_page_label_1_main_main_default);
	else
		lv_style_init(&style_jisuan_page_label_1_main_main_default);
	lv_style_set_radius(&style_jisuan_page_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_jisuan_page_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_jisuan_page_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_jisuan_page_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_jisuan_page_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_jisuan_page_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_jisuan_page_label_1_main_main_default, &lv_font_simsun_40);
	lv_style_set_text_letter_space(&style_jisuan_page_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_jisuan_page_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_jisuan_page_label_1_main_main_default, LV_TEXT_ALIGN_RIGHT);
	lv_style_set_pad_left(&style_jisuan_page_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_jisuan_page_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_jisuan_page_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_jisuan_page_label_1_main_main_default, 0);
	lv_obj_add_style(ui->jisuan_page_label_1, &style_jisuan_page_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);


    events_init_jisuan_page(ui);
}