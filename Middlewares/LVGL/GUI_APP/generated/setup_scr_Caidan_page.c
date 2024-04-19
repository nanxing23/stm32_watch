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
#include "user_MPUCheckTask.h"

uint8_t user_APPSy_EN=1;                        //app同步时间


void setup_scr_Caidan_page(lv_ui *ui){

	//Write codes Caidan_page
	ui->Caidan_page = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->Caidan_page, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_main_main_default
	static lv_style_t style_caidan_page_main_main_default;
	if (style_caidan_page_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_main_main_default);
	else
		lv_style_init(&style_caidan_page_main_main_default);
	lv_style_set_bg_color(&style_caidan_page_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_opa(&style_caidan_page_main_main_default, 0);
	lv_obj_add_style(ui->Caidan_page, &style_caidan_page_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Caidan_page_tileview_1
	ui->Caidan_page_tileview_1 = lv_tileview_create(ui->Caidan_page);
	lv_obj_set_pos(ui->Caidan_page_tileview_1, 0, 0);
	lv_obj_set_size(ui->Caidan_page_tileview_1, 240, 280);
	lv_obj_set_scrollbar_mode(ui->Caidan_page_tileview_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_tileview_1_main_main_default
	static lv_style_t style_caidan_page_tileview_1_main_main_default;
	if (style_caidan_page_tileview_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_tileview_1_main_main_default);
	else
		lv_style_init(&style_caidan_page_tileview_1_main_main_default);
	lv_style_set_radius(&style_caidan_page_tileview_1_main_main_default, 0);
	lv_style_set_bg_color(&style_caidan_page_tileview_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_caidan_page_tileview_1_main_main_default, lv_color_make(0xf6, 0xf6, 0xf6));
	lv_style_set_bg_grad_dir(&style_caidan_page_tileview_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_caidan_page_tileview_1_main_main_default, 255);
	lv_obj_add_style(ui->Caidan_page_tileview_1, &style_caidan_page_tileview_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_tileview_1_main_scrollbar_default
	static lv_style_t style_caidan_page_tileview_1_main_scrollbar_default;
	if (style_caidan_page_tileview_1_main_scrollbar_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_tileview_1_main_scrollbar_default);
	else
		lv_style_init(&style_caidan_page_tileview_1_main_scrollbar_default);
	lv_style_set_radius(&style_caidan_page_tileview_1_main_scrollbar_default, 0);
	lv_style_set_bg_color(&style_caidan_page_tileview_1_main_scrollbar_default, lv_color_make(0xea, 0xef, 0xf3));
	lv_style_set_bg_opa(&style_caidan_page_tileview_1_main_scrollbar_default, 255);
	lv_obj_add_style(ui->Caidan_page_tileview_1, &style_caidan_page_tileview_1_main_scrollbar_default, LV_PART_SCROLLBAR|LV_STATE_DEFAULT);

	//add new tile tileview_1_name_1
	ui->tileview_1_name_1 = lv_tileview_add_tile(ui->Caidan_page_tileview_1, 0, 0, LV_DIR_BOTTOM);

	//Write codes Caidan_page_miaobiao_e
	ui->Caidan_page_miaobiao_e = lv_imgbtn_create(ui->tileview_1_name_1);
	lv_obj_set_pos(ui->Caidan_page_miaobiao_e, 5, 210);
	lv_obj_set_size(ui->Caidan_page_miaobiao_e, 140, 65);
	lv_obj_set_scrollbar_mode(ui->Caidan_page_miaobiao_e, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_miaobiao_e_main_main_default
	static lv_style_t style_caidan_page_miaobiao_e_main_main_default;
	if (style_caidan_page_miaobiao_e_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_miaobiao_e_main_main_default);
	else
		lv_style_init(&style_caidan_page_miaobiao_e_main_main_default);
	lv_style_set_text_color(&style_caidan_page_miaobiao_e_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_caidan_page_miaobiao_e_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_align(&style_caidan_page_miaobiao_e_main_main_default, LV_TEXT_ALIGN_RIGHT);
	lv_style_set_img_recolor(&style_caidan_page_miaobiao_e_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_caidan_page_miaobiao_e_main_main_default, 0);
	lv_style_set_img_opa(&style_caidan_page_miaobiao_e_main_main_default, 0);
	lv_obj_add_style(ui->Caidan_page_miaobiao_e, &style_caidan_page_miaobiao_e_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_caidan_page_miaobiao_e_main_main_pressed
	static lv_style_t style_caidan_page_miaobiao_e_main_main_pressed;
	if (style_caidan_page_miaobiao_e_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_miaobiao_e_main_main_pressed);
	else
		lv_style_init(&style_caidan_page_miaobiao_e_main_main_pressed);
	lv_style_set_text_color(&style_caidan_page_miaobiao_e_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_font(&style_caidan_page_miaobiao_e_main_main_pressed, &lv_font_simsun_12);
	lv_style_set_text_align(&style_caidan_page_miaobiao_e_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_miaobiao_e_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_caidan_page_miaobiao_e_main_main_pressed, 0);
	lv_style_set_img_opa(&style_caidan_page_miaobiao_e_main_main_pressed, 255);
	lv_obj_add_style(ui->Caidan_page_miaobiao_e, &style_caidan_page_miaobiao_e_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_caidan_page_miaobiao_e_main_main_checked
	static lv_style_t style_caidan_page_miaobiao_e_main_main_checked;
	if (style_caidan_page_miaobiao_e_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_miaobiao_e_main_main_checked);
	else
		lv_style_init(&style_caidan_page_miaobiao_e_main_main_checked);
	lv_style_set_text_color(&style_caidan_page_miaobiao_e_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_font(&style_caidan_page_miaobiao_e_main_main_checked, &lv_font_simsun_12);
	lv_style_set_text_align(&style_caidan_page_miaobiao_e_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_miaobiao_e_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_caidan_page_miaobiao_e_main_main_checked, 0);
	lv_style_set_img_opa(&style_caidan_page_miaobiao_e_main_main_checked, 255);
	lv_obj_add_style(ui->Caidan_page_miaobiao_e, &style_caidan_page_miaobiao_e_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	ui->Caidan_page_miaobiao_e_label = lv_label_create(ui->Caidan_page_miaobiao_e);
	lv_label_set_text(ui->Caidan_page_miaobiao_e_label, "秒表");
	lv_obj_set_style_pad_all(ui->Caidan_page_miaobiao_e, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Caidan_page_miaobiao_e_label, LV_ALIGN_RIGHT_MID, 0, 0);

	//Write codes Caidan_page_jisuan_e
	ui->Caidan_page_jisuan_e = lv_imgbtn_create(ui->tileview_1_name_1);
	lv_obj_set_pos(ui->Caidan_page_jisuan_e, 5, 75);
	lv_obj_set_size(ui->Caidan_page_jisuan_e, 150, 65);
	lv_obj_set_scrollbar_mode(ui->Caidan_page_jisuan_e, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_jisuan_e_main_main_default
	static lv_style_t style_caidan_page_jisuan_e_main_main_default;
	if (style_caidan_page_jisuan_e_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_jisuan_e_main_main_default);
	else
		lv_style_init(&style_caidan_page_jisuan_e_main_main_default);
	lv_style_set_text_color(&style_caidan_page_jisuan_e_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_caidan_page_jisuan_e_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_align(&style_caidan_page_jisuan_e_main_main_default, LV_TEXT_ALIGN_RIGHT);
	lv_style_set_img_recolor(&style_caidan_page_jisuan_e_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_caidan_page_jisuan_e_main_main_default, 0);
	lv_style_set_img_opa(&style_caidan_page_jisuan_e_main_main_default, 0);
	lv_obj_add_style(ui->Caidan_page_jisuan_e, &style_caidan_page_jisuan_e_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_caidan_page_jisuan_e_main_main_pressed
	static lv_style_t style_caidan_page_jisuan_e_main_main_pressed;
	if (style_caidan_page_jisuan_e_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_jisuan_e_main_main_pressed);
	else
		lv_style_init(&style_caidan_page_jisuan_e_main_main_pressed);
	lv_style_set_text_color(&style_caidan_page_jisuan_e_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_font(&style_caidan_page_jisuan_e_main_main_pressed, &lv_font_simsun_12);
	lv_style_set_text_align(&style_caidan_page_jisuan_e_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_jisuan_e_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_caidan_page_jisuan_e_main_main_pressed, 0);
	lv_style_set_img_opa(&style_caidan_page_jisuan_e_main_main_pressed, 255);
	lv_obj_add_style(ui->Caidan_page_jisuan_e, &style_caidan_page_jisuan_e_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_caidan_page_jisuan_e_main_main_checked
	static lv_style_t style_caidan_page_jisuan_e_main_main_checked;
	if (style_caidan_page_jisuan_e_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_jisuan_e_main_main_checked);
	else
		lv_style_init(&style_caidan_page_jisuan_e_main_main_checked);
	lv_style_set_text_color(&style_caidan_page_jisuan_e_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_font(&style_caidan_page_jisuan_e_main_main_checked, &lv_font_simsun_12);
	lv_style_set_text_align(&style_caidan_page_jisuan_e_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_jisuan_e_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_caidan_page_jisuan_e_main_main_checked, 0);
	lv_style_set_img_opa(&style_caidan_page_jisuan_e_main_main_checked, 255);
	lv_obj_add_style(ui->Caidan_page_jisuan_e, &style_caidan_page_jisuan_e_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	ui->Caidan_page_jisuan_e_label = lv_label_create(ui->Caidan_page_jisuan_e);
	lv_label_set_text(ui->Caidan_page_jisuan_e_label, "计算器");
	lv_obj_set_style_pad_all(ui->Caidan_page_jisuan_e, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Caidan_page_jisuan_e_label, LV_ALIGN_RIGHT_MID, 0, 0);

	//Write codes Caidan_page_zhinan_e
	ui->Caidan_page_zhinan_e = lv_imgbtn_create(ui->tileview_1_name_1);
	lv_obj_set_pos(ui->Caidan_page_zhinan_e, 5, 145);
	lv_obj_set_size(ui->Caidan_page_zhinan_e, 150, 65);
	lv_obj_set_scrollbar_mode(ui->Caidan_page_zhinan_e, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_zhinan_e_main_main_default
	static lv_style_t style_caidan_page_zhinan_e_main_main_default;
	if (style_caidan_page_zhinan_e_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_zhinan_e_main_main_default);
	else
		lv_style_init(&style_caidan_page_zhinan_e_main_main_default);
	lv_style_set_text_color(&style_caidan_page_zhinan_e_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_caidan_page_zhinan_e_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_align(&style_caidan_page_zhinan_e_main_main_default, LV_TEXT_ALIGN_RIGHT);
	lv_style_set_img_recolor(&style_caidan_page_zhinan_e_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_caidan_page_zhinan_e_main_main_default, 0);
	lv_style_set_img_opa(&style_caidan_page_zhinan_e_main_main_default, 0);
	lv_obj_add_style(ui->Caidan_page_zhinan_e, &style_caidan_page_zhinan_e_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_caidan_page_zhinan_e_main_main_pressed
	static lv_style_t style_caidan_page_zhinan_e_main_main_pressed;
	if (style_caidan_page_zhinan_e_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_zhinan_e_main_main_pressed);
	else
		lv_style_init(&style_caidan_page_zhinan_e_main_main_pressed);
	lv_style_set_text_color(&style_caidan_page_zhinan_e_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_font(&style_caidan_page_zhinan_e_main_main_pressed, &lv_font_simsun_12);
	lv_style_set_text_align(&style_caidan_page_zhinan_e_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_zhinan_e_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_caidan_page_zhinan_e_main_main_pressed, 0);
	lv_style_set_img_opa(&style_caidan_page_zhinan_e_main_main_pressed, 255);
	lv_obj_add_style(ui->Caidan_page_zhinan_e, &style_caidan_page_zhinan_e_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_caidan_page_zhinan_e_main_main_checked
	static lv_style_t style_caidan_page_zhinan_e_main_main_checked;
	if (style_caidan_page_zhinan_e_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_zhinan_e_main_main_checked);
	else
		lv_style_init(&style_caidan_page_zhinan_e_main_main_checked);
	lv_style_set_text_color(&style_caidan_page_zhinan_e_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_font(&style_caidan_page_zhinan_e_main_main_checked, &lv_font_simsun_12);
	lv_style_set_text_align(&style_caidan_page_zhinan_e_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_zhinan_e_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_caidan_page_zhinan_e_main_main_checked, 0);
	lv_style_set_img_opa(&style_caidan_page_zhinan_e_main_main_checked, 255);
	lv_obj_add_style(ui->Caidan_page_zhinan_e, &style_caidan_page_zhinan_e_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	ui->Caidan_page_zhinan_e_label = lv_label_create(ui->Caidan_page_zhinan_e);
	lv_label_set_text(ui->Caidan_page_zhinan_e_label, "指南针");
	lv_obj_set_style_pad_all(ui->Caidan_page_zhinan_e, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Caidan_page_zhinan_e_label, LV_ALIGN_RIGHT_MID, 0, 0);

	//Write codes Caidan_page_rili_e
	ui->Caidan_page_rili_e = lv_imgbtn_create(ui->tileview_1_name_1);
	lv_obj_set_pos(ui->Caidan_page_rili_e, 5, 5);
	lv_obj_set_size(ui->Caidan_page_rili_e, 140, 65);
	lv_obj_set_scrollbar_mode(ui->Caidan_page_rili_e, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_rili_e_main_main_default
	static lv_style_t style_caidan_page_rili_e_main_main_default;
	if (style_caidan_page_rili_e_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_rili_e_main_main_default);
	else
		lv_style_init(&style_caidan_page_rili_e_main_main_default);
	lv_style_set_text_color(&style_caidan_page_rili_e_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_caidan_page_rili_e_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_align(&style_caidan_page_rili_e_main_main_default, LV_TEXT_ALIGN_RIGHT);
	lv_style_set_img_recolor(&style_caidan_page_rili_e_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_caidan_page_rili_e_main_main_default, 0);
	lv_style_set_img_opa(&style_caidan_page_rili_e_main_main_default, 0);
	lv_obj_add_style(ui->Caidan_page_rili_e, &style_caidan_page_rili_e_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_caidan_page_rili_e_main_main_pressed
	static lv_style_t style_caidan_page_rili_e_main_main_pressed;
	if (style_caidan_page_rili_e_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_rili_e_main_main_pressed);
	else
		lv_style_init(&style_caidan_page_rili_e_main_main_pressed);
	lv_style_set_text_color(&style_caidan_page_rili_e_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_font(&style_caidan_page_rili_e_main_main_pressed, &lv_font_simsun_12);
	lv_style_set_text_align(&style_caidan_page_rili_e_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_rili_e_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_caidan_page_rili_e_main_main_pressed, 0);
	lv_style_set_img_opa(&style_caidan_page_rili_e_main_main_pressed, 255);
	lv_obj_add_style(ui->Caidan_page_rili_e, &style_caidan_page_rili_e_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_caidan_page_rili_e_main_main_checked
	static lv_style_t style_caidan_page_rili_e_main_main_checked;
	if (style_caidan_page_rili_e_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_rili_e_main_main_checked);
	else
		lv_style_init(&style_caidan_page_rili_e_main_main_checked);
	lv_style_set_text_color(&style_caidan_page_rili_e_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_font(&style_caidan_page_rili_e_main_main_checked, &lv_font_simsun_12);
	lv_style_set_text_align(&style_caidan_page_rili_e_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_rili_e_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_caidan_page_rili_e_main_main_checked, 0);
	lv_style_set_img_opa(&style_caidan_page_rili_e_main_main_checked, 255);
	lv_obj_add_style(ui->Caidan_page_rili_e, &style_caidan_page_rili_e_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	ui->Caidan_page_rili_e_label = lv_label_create(ui->Caidan_page_rili_e);
	lv_label_set_text(ui->Caidan_page_rili_e_label, "日历");
	lv_obj_set_style_pad_all(ui->Caidan_page_rili_e, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Caidan_page_rili_e_label, LV_ALIGN_RIGHT_MID, 0, 0);

	//add new tile tileview_1_name_2
	ui->tileview_1_name_2 = lv_tileview_add_tile(ui->Caidan_page_tileview_1, 0 , 1, LV_DIR_TOP);
    
    //Write codes Caidan_page_LCD_PWM
	ui->Caidan_page_LCD_PWM = lv_slider_create(ui->tileview_1_name_2);
	lv_obj_set_pos(ui->Caidan_page_LCD_PWM, 5, 225);
	lv_obj_set_size(ui->Caidan_page_LCD_PWM, 230, 30);
	lv_obj_set_scrollbar_mode(ui->Caidan_page_LCD_PWM, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_lcd_pwm_main_main_default
	static lv_style_t style_caidan_page_lcd_pwm_main_main_default;
	if (style_caidan_page_lcd_pwm_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_lcd_pwm_main_main_default);
	else
		lv_style_init(&style_caidan_page_lcd_pwm_main_main_default);
	lv_style_set_radius(&style_caidan_page_lcd_pwm_main_main_default, 50);
	lv_style_set_bg_color(&style_caidan_page_lcd_pwm_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_caidan_page_lcd_pwm_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_caidan_page_lcd_pwm_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_caidan_page_lcd_pwm_main_main_default, 60);
	lv_style_set_outline_color(&style_caidan_page_lcd_pwm_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_outline_width(&style_caidan_page_lcd_pwm_main_main_default, 0);
	lv_style_set_outline_opa(&style_caidan_page_lcd_pwm_main_main_default, 0);
	lv_obj_add_style(ui->Caidan_page_LCD_PWM, &style_caidan_page_lcd_pwm_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_lcd_pwm_main_indicator_default
	static lv_style_t style_caidan_page_lcd_pwm_main_indicator_default;
	if (style_caidan_page_lcd_pwm_main_indicator_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_lcd_pwm_main_indicator_default);
	else
		lv_style_init(&style_caidan_page_lcd_pwm_main_indicator_default);
	lv_style_set_radius(&style_caidan_page_lcd_pwm_main_indicator_default, 50);
	lv_style_set_bg_color(&style_caidan_page_lcd_pwm_main_indicator_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_caidan_page_lcd_pwm_main_indicator_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_caidan_page_lcd_pwm_main_indicator_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_caidan_page_lcd_pwm_main_indicator_default, 255);
	lv_obj_add_style(ui->Caidan_page_LCD_PWM, &style_caidan_page_lcd_pwm_main_indicator_default, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_lcd_pwm_main_knob_default
	static lv_style_t style_caidan_page_lcd_pwm_main_knob_default;
	if (style_caidan_page_lcd_pwm_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_lcd_pwm_main_knob_default);
	else
		lv_style_init(&style_caidan_page_lcd_pwm_main_knob_default);
	lv_style_set_radius(&style_caidan_page_lcd_pwm_main_knob_default, 50);
	lv_style_set_bg_color(&style_caidan_page_lcd_pwm_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_caidan_page_lcd_pwm_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_caidan_page_lcd_pwm_main_knob_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_caidan_page_lcd_pwm_main_knob_default, 0);
	lv_obj_add_style(ui->Caidan_page_LCD_PWM, &style_caidan_page_lcd_pwm_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_slider_set_range(ui->Caidan_page_LCD_PWM,0, 100);
	lv_slider_set_value(ui->Caidan_page_LCD_PWM,50,false);
    

	//Write codes Caidan_page_imgbtn_3
	ui->Caidan_page_imgbtn_3 = lv_imgbtn_create(ui->tileview_1_name_2);
	lv_obj_set_pos(ui->Caidan_page_imgbtn_3, 5, 145);
	lv_obj_set_size(ui->Caidan_page_imgbtn_3, 230, 65);
	lv_obj_set_scrollbar_mode(ui->Caidan_page_imgbtn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_imgbtn_3_main_main_default
	static lv_style_t style_caidan_page_imgbtn_3_main_main_default;
	if (style_caidan_page_imgbtn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_imgbtn_3_main_main_default);
	else
		lv_style_init(&style_caidan_page_imgbtn_3_main_main_default);
	lv_style_set_text_color(&style_caidan_page_imgbtn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_caidan_page_imgbtn_3_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_align(&style_caidan_page_imgbtn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_imgbtn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_caidan_page_imgbtn_3_main_main_default, 0);
	lv_style_set_img_opa(&style_caidan_page_imgbtn_3_main_main_default, 255);
	lv_obj_add_style(ui->Caidan_page_imgbtn_3, &style_caidan_page_imgbtn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_caidan_page_imgbtn_3_main_main_pressed
	static lv_style_t style_caidan_page_imgbtn_3_main_main_pressed;
	if (style_caidan_page_imgbtn_3_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_imgbtn_3_main_main_pressed);
	else
		lv_style_init(&style_caidan_page_imgbtn_3_main_main_pressed);
	lv_style_set_text_color(&style_caidan_page_imgbtn_3_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_font(&style_caidan_page_imgbtn_3_main_main_pressed, &lv_font_simsun_12);
	lv_style_set_text_align(&style_caidan_page_imgbtn_3_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_imgbtn_3_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_caidan_page_imgbtn_3_main_main_pressed, 0);
	lv_style_set_img_opa(&style_caidan_page_imgbtn_3_main_main_pressed, 255);
	lv_obj_add_style(ui->Caidan_page_imgbtn_3, &style_caidan_page_imgbtn_3_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_caidan_page_imgbtn_3_main_main_checked
	static lv_style_t style_caidan_page_imgbtn_3_main_main_checked;
	if (style_caidan_page_imgbtn_3_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_imgbtn_3_main_main_checked);
	else
		lv_style_init(&style_caidan_page_imgbtn_3_main_main_checked);
	lv_style_set_text_color(&style_caidan_page_imgbtn_3_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_font(&style_caidan_page_imgbtn_3_main_main_checked, &lv_font_simsun_12);
	lv_style_set_text_align(&style_caidan_page_imgbtn_3_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_imgbtn_3_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_caidan_page_imgbtn_3_main_main_checked, 0);
	lv_style_set_img_opa(&style_caidan_page_imgbtn_3_main_main_checked, 255);
	lv_obj_add_style(ui->Caidan_page_imgbtn_3, &style_caidan_page_imgbtn_3_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	ui->Caidan_page_imgbtn_3_label = lv_label_create(ui->Caidan_page_imgbtn_3);
	lv_label_set_text(ui->Caidan_page_imgbtn_3_label, "常量时间");
	lv_obj_set_style_pad_all(ui->Caidan_page_imgbtn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Caidan_page_imgbtn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes Caidan_page_imgbtn_2
	ui->Caidan_page_imgbtn_2 = lv_imgbtn_create(ui->tileview_1_name_2);
	lv_obj_set_pos(ui->Caidan_page_imgbtn_2, 5, 75);
	lv_obj_set_size(ui->Caidan_page_imgbtn_2, 230, 65);
	lv_obj_set_scrollbar_mode(ui->Caidan_page_imgbtn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_imgbtn_2_main_main_default
	static lv_style_t style_caidan_page_imgbtn_2_main_main_default;
	if (style_caidan_page_imgbtn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_imgbtn_2_main_main_default);
	else
		lv_style_init(&style_caidan_page_imgbtn_2_main_main_default);
	lv_style_set_text_color(&style_caidan_page_imgbtn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_caidan_page_imgbtn_2_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_align(&style_caidan_page_imgbtn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_imgbtn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_caidan_page_imgbtn_2_main_main_default, 0);
	lv_style_set_img_opa(&style_caidan_page_imgbtn_2_main_main_default, 255);
	lv_obj_add_style(ui->Caidan_page_imgbtn_2, &style_caidan_page_imgbtn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_caidan_page_imgbtn_2_main_main_pressed
	static lv_style_t style_caidan_page_imgbtn_2_main_main_pressed;
	if (style_caidan_page_imgbtn_2_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_imgbtn_2_main_main_pressed);
	else
		lv_style_init(&style_caidan_page_imgbtn_2_main_main_pressed);
	lv_style_set_text_color(&style_caidan_page_imgbtn_2_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_font(&style_caidan_page_imgbtn_2_main_main_pressed, &lv_font_simsun_12);
	lv_style_set_text_align(&style_caidan_page_imgbtn_2_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_imgbtn_2_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_caidan_page_imgbtn_2_main_main_pressed, 0);
	lv_style_set_img_opa(&style_caidan_page_imgbtn_2_main_main_pressed, 255);
	lv_obj_add_style(ui->Caidan_page_imgbtn_2, &style_caidan_page_imgbtn_2_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_caidan_page_imgbtn_2_main_main_checked
	static lv_style_t style_caidan_page_imgbtn_2_main_main_checked;
	if (style_caidan_page_imgbtn_2_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_imgbtn_2_main_main_checked);
	else
		lv_style_init(&style_caidan_page_imgbtn_2_main_main_checked);
	lv_style_set_text_color(&style_caidan_page_imgbtn_2_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_font(&style_caidan_page_imgbtn_2_main_main_checked, &lv_font_simsun_12);
	lv_style_set_text_align(&style_caidan_page_imgbtn_2_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_imgbtn_2_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_caidan_page_imgbtn_2_main_main_checked, 0);
	lv_style_set_img_opa(&style_caidan_page_imgbtn_2_main_main_checked, 255);
	lv_obj_add_style(ui->Caidan_page_imgbtn_2, &style_caidan_page_imgbtn_2_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	ui->Caidan_page_imgbtn_2_label = lv_label_create(ui->Caidan_page_imgbtn_2);
	lv_label_set_text(ui->Caidan_page_imgbtn_2_label, "息屏时间");
	lv_obj_set_style_pad_all(ui->Caidan_page_imgbtn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Caidan_page_imgbtn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes Caidan_page_imgbtn_1
	ui->Caidan_page_imgbtn_1 = lv_imgbtn_create(ui->tileview_1_name_2);
	lv_obj_set_pos(ui->Caidan_page_imgbtn_1, 5, 5);
	lv_obj_set_size(ui->Caidan_page_imgbtn_1, 230, 65);
	lv_obj_set_scrollbar_mode(ui->Caidan_page_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_imgbtn_1_main_main_default
	static lv_style_t style_caidan_page_imgbtn_1_main_main_default;
	if (style_caidan_page_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_caidan_page_imgbtn_1_main_main_default);
	lv_style_set_text_color(&style_caidan_page_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_caidan_page_imgbtn_1_main_main_default, &lv_font_simsun_20);
	lv_style_set_text_align(&style_caidan_page_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_caidan_page_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_caidan_page_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->Caidan_page_imgbtn_1, &style_caidan_page_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_caidan_page_imgbtn_1_main_main_pressed
	static lv_style_t style_caidan_page_imgbtn_1_main_main_pressed;
	if (style_caidan_page_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_caidan_page_imgbtn_1_main_main_pressed);
	lv_style_set_text_color(&style_caidan_page_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_font(&style_caidan_page_imgbtn_1_main_main_pressed, &lv_font_simsun_12);
	lv_style_set_text_align(&style_caidan_page_imgbtn_1_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_caidan_page_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_caidan_page_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->Caidan_page_imgbtn_1, &style_caidan_page_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_caidan_page_imgbtn_1_main_main_checked
	static lv_style_t style_caidan_page_imgbtn_1_main_main_checked;
	if (style_caidan_page_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_caidan_page_imgbtn_1_main_main_checked);
	lv_style_set_text_color(&style_caidan_page_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_font(&style_caidan_page_imgbtn_1_main_main_checked, &lv_font_simsun_12);
	lv_style_set_text_align(&style_caidan_page_imgbtn_1_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_caidan_page_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_caidan_page_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_caidan_page_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->Caidan_page_imgbtn_1, &style_caidan_page_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	ui->Caidan_page_imgbtn_1_label = lv_label_create(ui->Caidan_page_imgbtn_1);
	lv_label_set_text(ui->Caidan_page_imgbtn_1_label, "抬腕亮屏");
	lv_obj_set_style_pad_all(ui->Caidan_page_imgbtn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Caidan_page_imgbtn_1_label, LV_ALIGN_CENTER, 0, 0);

//Write codes Caidan_page_roller_2
	ui->Caidan_page_roller_2 = lv_roller_create(ui->tileview_1_name_2);
	lv_obj_set_pos(ui->Caidan_page_roller_2, 175, 157);
	lv_obj_set_scrollbar_mode(ui->Caidan_page_roller_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_roller_2_main_main_default
	static lv_style_t style_caidan_page_roller_2_main_main_default;
	if (style_caidan_page_roller_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_roller_2_main_main_default);
	else
		lv_style_init(&style_caidan_page_roller_2_main_main_default);
	lv_style_set_radius(&style_caidan_page_roller_2_main_main_default, 5);
	lv_style_set_bg_color(&style_caidan_page_roller_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_caidan_page_roller_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_caidan_page_roller_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_caidan_page_roller_2_main_main_default, 255);
	lv_style_set_border_color(&style_caidan_page_roller_2_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_border_width(&style_caidan_page_roller_2_main_main_default, 2);
	lv_style_set_border_opa(&style_caidan_page_roller_2_main_main_default, 255);
	lv_style_set_text_color(&style_caidan_page_roller_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_caidan_page_roller_2_main_main_default, &lv_font_simsun_20);
	lv_obj_add_style(ui->Caidan_page_roller_2, &style_caidan_page_roller_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_roller_2_main_selected_default
	static lv_style_t style_caidan_page_roller_2_main_selected_default;
	if (style_caidan_page_roller_2_main_selected_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_roller_2_main_selected_default);
	else
		lv_style_init(&style_caidan_page_roller_2_main_selected_default);
	lv_style_set_bg_color(&style_caidan_page_roller_2_main_selected_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_caidan_page_roller_2_main_selected_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_caidan_page_roller_2_main_selected_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_caidan_page_roller_2_main_selected_default, 255);
	lv_style_set_text_color(&style_caidan_page_roller_2_main_selected_default, lv_color_make(0xFF, 0xFF, 0xFF));
	lv_style_set_text_font(&style_caidan_page_roller_2_main_selected_default, &lv_font_simsun_20);
	lv_obj_add_style(ui->Caidan_page_roller_2, &style_caidan_page_roller_2_main_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_options(ui->Caidan_page_roller_2,"10\n15\n25\n30\n40",LV_ROLLER_MODE_INFINITE);
	lv_roller_set_visible_row_count(ui->Caidan_page_roller_2,1);

	//Write codes Caidan_page_roller_1
	ui->Caidan_page_roller_1 = lv_roller_create(ui->tileview_1_name_2);
	lv_obj_set_pos(ui->Caidan_page_roller_1, 175, 86);
	lv_obj_set_scrollbar_mode(ui->Caidan_page_roller_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_roller_1_main_main_default
	static lv_style_t style_caidan_page_roller_1_main_main_default;
	if (style_caidan_page_roller_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_roller_1_main_main_default);
	else
		lv_style_init(&style_caidan_page_roller_1_main_main_default);
	lv_style_set_radius(&style_caidan_page_roller_1_main_main_default, 5);
	lv_style_set_bg_color(&style_caidan_page_roller_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_caidan_page_roller_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_caidan_page_roller_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_caidan_page_roller_1_main_main_default, 255);
	lv_style_set_border_color(&style_caidan_page_roller_1_main_main_default, lv_color_make(0xe6, 0xe6, 0xe6));
	lv_style_set_border_width(&style_caidan_page_roller_1_main_main_default, 2);
	lv_style_set_border_opa(&style_caidan_page_roller_1_main_main_default, 255);
	lv_style_set_text_color(&style_caidan_page_roller_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_caidan_page_roller_1_main_main_default, &lv_font_simsun_20);
	lv_obj_add_style(ui->Caidan_page_roller_1, &style_caidan_page_roller_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_roller_1_main_selected_default
	static lv_style_t style_caidan_page_roller_1_main_selected_default;
	if (style_caidan_page_roller_1_main_selected_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_roller_1_main_selected_default);
	else
		lv_style_init(&style_caidan_page_roller_1_main_selected_default);
	lv_style_set_bg_color(&style_caidan_page_roller_1_main_selected_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_caidan_page_roller_1_main_selected_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_caidan_page_roller_1_main_selected_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_caidan_page_roller_1_main_selected_default, 255);
	lv_style_set_text_color(&style_caidan_page_roller_1_main_selected_default, lv_color_make(0xFF, 0xFF, 0xFF));
	lv_style_set_text_font(&style_caidan_page_roller_1_main_selected_default, &lv_font_simsun_20);
	lv_obj_add_style(ui->Caidan_page_roller_1, &style_caidan_page_roller_1_main_selected_default, LV_PART_SELECTED|LV_STATE_DEFAULT);
	lv_roller_set_options(ui->Caidan_page_roller_1,"5\n10\n15\n20\n25",LV_ROLLER_MODE_INFINITE);
	lv_roller_set_visible_row_count(ui->Caidan_page_roller_1,1);

	//Write codes Caidan_page_sw_1
	ui->Caidan_page_sw_1 = lv_switch_create(ui->tileview_1_name_2);
	lv_obj_set_pos(ui->Caidan_page_sw_1, 165, 22);
	lv_obj_set_size(ui->Caidan_page_sw_1, 66, 31);
	lv_obj_set_scrollbar_mode(ui->Caidan_page_sw_1, LV_SCROLLBAR_MODE_OFF);
    if(user_MPU_Wrist_EN)
	{lv_obj_add_state(ui->Caidan_page_sw_1, LV_STATE_CHECKED);}

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_sw_1_main_main_default
	static lv_style_t style_caidan_page_sw_1_main_main_default;
	if (style_caidan_page_sw_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_sw_1_main_main_default);
	else
		lv_style_init(&style_caidan_page_sw_1_main_main_default);
	lv_style_set_radius(&style_caidan_page_sw_1_main_main_default, 100);
	lv_style_set_bg_color(&style_caidan_page_sw_1_main_main_default, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_color(&style_caidan_page_sw_1_main_main_default, lv_color_make(0xe6, 0xe2, 0xe6));
	lv_style_set_bg_grad_dir(&style_caidan_page_sw_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_caidan_page_sw_1_main_main_default, 255);
	lv_style_set_border_color(&style_caidan_page_sw_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_caidan_page_sw_1_main_main_default, 0);
	lv_style_set_border_opa(&style_caidan_page_sw_1_main_main_default, 255);
	lv_obj_add_style(ui->Caidan_page_sw_1, &style_caidan_page_sw_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_CHECKED for style_caidan_page_sw_1_main_indicator_checked
	static lv_style_t style_caidan_page_sw_1_main_indicator_checked;
	if (style_caidan_page_sw_1_main_indicator_checked.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_sw_1_main_indicator_checked);
	else
		lv_style_init(&style_caidan_page_sw_1_main_indicator_checked);
	lv_style_set_bg_color(&style_caidan_page_sw_1_main_indicator_checked, lv_color_make(0x2f, 0xe4, 0x87));
	lv_style_set_bg_grad_color(&style_caidan_page_sw_1_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_caidan_page_sw_1_main_indicator_checked, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_caidan_page_sw_1_main_indicator_checked, 255);
	lv_style_set_border_color(&style_caidan_page_sw_1_main_indicator_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_caidan_page_sw_1_main_indicator_checked, 0);
	lv_style_set_border_opa(&style_caidan_page_sw_1_main_indicator_checked, 255);
	lv_obj_add_style(ui->Caidan_page_sw_1, &style_caidan_page_sw_1_main_indicator_checked, LV_PART_INDICATOR|LV_STATE_CHECKED);

	//Write style state: LV_STATE_DEFAULT for style_caidan_page_sw_1_main_knob_default
	static lv_style_t style_caidan_page_sw_1_main_knob_default;
	if (style_caidan_page_sw_1_main_knob_default.prop_cnt > 1)
		lv_style_reset(&style_caidan_page_sw_1_main_knob_default);
	else
		lv_style_init(&style_caidan_page_sw_1_main_knob_default);
	lv_style_set_radius(&style_caidan_page_sw_1_main_knob_default, 100);
	lv_style_set_bg_color(&style_caidan_page_sw_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_caidan_page_sw_1_main_knob_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_caidan_page_sw_1_main_knob_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_caidan_page_sw_1_main_knob_default, 255);
	lv_style_set_border_color(&style_caidan_page_sw_1_main_knob_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_caidan_page_sw_1_main_knob_default, 0);
	lv_style_set_border_opa(&style_caidan_page_sw_1_main_knob_default, 255);
	lv_obj_add_style(ui->Caidan_page_sw_1, &style_caidan_page_sw_1_main_knob_default, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_Caidan_page(ui);
}