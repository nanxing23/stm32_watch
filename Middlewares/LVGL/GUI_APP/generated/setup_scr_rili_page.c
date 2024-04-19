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

static void rili_page_rili_taskdraw_part_begin_event_cb(lv_event_t * e)
{
	lv_obj_t * obj = lv_event_get_target(e);
	lv_obj_draw_part_dsc_t * dsc = lv_event_get_param(e);
	if(dsc->part == LV_PART_ITEMS) {
		if(dsc->id < 7) {
			dsc->label_dsc->color = lv_color_make(0xff, 0xff, 0xff);
			dsc->label_dsc->font = &lv_font_simsun_20;
		}	else if (lv_btnmatrix_has_btn_ctrl(obj, dsc->id, LV_BTNMATRIX_CTRL_DISABLED)) {
			dsc->rect_dsc->bg_color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_grad.stops_count = 2;
			dsc->rect_dsc->bg_grad.dir = LV_GRAD_DIR_NONE;
			dsc->rect_dsc->bg_grad.stops[0].color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_grad.stops[1].color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_opa = 0;
			dsc->label_dsc->color = lv_color_make(0x68, 0x55, 0x55);
			dsc->label_dsc->font = &lv_font_simsun_20;
		}		else if(lv_btnmatrix_has_btn_ctrl(obj, dsc->id, LV_BTNMATRIX_CTRL_CUSTOM_1)) {
			dsc->rect_dsc->bg_color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_grad.stops_count = 2;
			dsc->rect_dsc->bg_grad.dir = LV_GRAD_DIR_NONE;
			dsc->rect_dsc->bg_grad.stops[0].color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_grad.stops[1].color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_opa = 0;
			dsc->rect_dsc->border_color = lv_color_make(0xff, 0xff, 0xff);
			dsc->rect_dsc->border_width = 1;
			dsc->rect_dsc->border_opa = 255;
			dsc->label_dsc->color = lv_color_make(0xff, 0xff, 0xff);
			dsc->label_dsc->font = &lv_font_simsun_20;
		}
		else if(lv_btnmatrix_has_btn_ctrl(obj, dsc->id, LV_BTNMATRIX_CTRL_CUSTOM_2)) {
			dsc->rect_dsc->bg_color = lv_color_make(0x00, 0x1e, 0xff);
			dsc->rect_dsc->bg_grad.stops_count = 2;
			dsc->rect_dsc->bg_grad.dir = LV_GRAD_DIR_NONE;
			dsc->rect_dsc->bg_grad.stops[0].color = lv_color_make(0x00, 0x1e, 0xff);
			dsc->rect_dsc->bg_grad.stops[1].color = lv_color_make(0x21, 0x95, 0xf6);
			dsc->rect_dsc->bg_opa = 255;
			dsc->label_dsc->color = lv_color_make(0xff, 0xff, 0xff);
			dsc->label_dsc->font = &lv_font_simsun_20;
		}	else {
			dsc->rect_dsc->bg_color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_grad.stops_count = 2;
			dsc->rect_dsc->bg_grad.dir = LV_GRAD_DIR_NONE;
			dsc->rect_dsc->bg_grad.stops[0].color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_grad.stops[1].color = lv_color_make(0x01, 0xa2, 0xb1);
			dsc->rect_dsc->bg_opa = 0;
			dsc->rect_dsc->border_color = lv_color_make(0xff, 0xff, 0xff);
			dsc->rect_dsc->border_width = 1;
			dsc->rect_dsc->border_opa = 255;
			dsc->label_dsc->color = lv_color_make(0xff, 0xff, 0xff);
			dsc->label_dsc->font = &lv_font_simsun_20;
		}
	}
}

void setup_scr_rili_page(lv_ui *ui){

    
    RTC_DateTypeDef nowdate;
    RTC_TimeTypeDef nowtime;

    HAL_RTC_GetTime(&hrtc,&nowtime,RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc,&nowdate,RTC_FORMAT_BIN);
	//Write codes rili_page
	ui->rili_page = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->rili_page, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_rili_page_main_main_default
	static lv_style_t style_rili_page_main_main_default;
	if (style_rili_page_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rili_page_main_main_default);
	else
		lv_style_init(&style_rili_page_main_main_default);
	lv_style_set_bg_color(&style_rili_page_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_opa(&style_rili_page_main_main_default, 0);
	lv_obj_add_style(ui->rili_page, &style_rili_page_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes rili_page_rili_task
	ui->rili_page_rili_task = lv_calendar_create(ui->rili_page);
	lv_obj_set_pos(ui->rili_page_rili_task, 0, 0);
	lv_obj_set_size(ui->rili_page_rili_task, 240, 280);
	lv_obj_set_scrollbar_mode(ui->rili_page_rili_task, LV_SCROLLBAR_MODE_OFF);
	today.year = 2000+nowdate.Year;
	today.month = nowdate.Month;
	today.day = 15;
	lv_calendar_set_today_date(ui->rili_page_rili_task, today.year, today.month, today.day);
	lv_calendar_set_showed_date(ui->rili_page_rili_task, today.year, today.month);
	highlihted_days[0].year = 2000+nowdate.Year;
	highlihted_days[0].month = nowdate.Month;
	highlihted_days[0].day = nowdate.Date;
	lv_calendar_set_highlighted_dates(ui->rili_page_rili_task, highlihted_days, 1);
	lv_obj_t *rili_page_rili_task_header = lv_calendar_header_arrow_create(ui->rili_page_rili_task);
	lv_calendar_t * rili_page_rili_task = (lv_calendar_t *)ui->rili_page_rili_task;
	lv_obj_add_event_cb(rili_page_rili_task->btnm, rili_page_rili_taskdraw_part_begin_event_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);

	//Write style state: LV_STATE_DEFAULT for style_rili_page_rili_task_main_main_default
	static lv_style_t style_rili_page_rili_task_main_main_default;
	if (style_rili_page_rili_task_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_rili_page_rili_task_main_main_default);
	else
		lv_style_init(&style_rili_page_rili_task_main_main_default);
	lv_style_set_radius(&style_rili_page_rili_task_main_main_default, 0);
	lv_style_set_bg_color(&style_rili_page_rili_task_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_rili_page_rili_task_main_main_default, lv_color_make(0xcb, 0xc8, 0xc8));
	lv_style_set_bg_grad_dir(&style_rili_page_rili_task_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_rili_page_rili_task_main_main_default, 255);
	lv_style_set_border_color(&style_rili_page_rili_task_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_border_width(&style_rili_page_rili_task_main_main_default, 0);
	lv_style_set_border_opa(&style_rili_page_rili_task_main_main_default, 255);
	lv_obj_add_style(ui->rili_page_rili_task, &style_rili_page_rili_task_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_FOCUSED for style_rili_page_rili_task_main_main_focused
	static lv_style_t style_rili_page_rili_task_main_main_focused;
	if (style_rili_page_rili_task_main_main_focused.prop_cnt > 1)
		lv_style_reset(&style_rili_page_rili_task_main_main_focused);
	else
		lv_style_init(&style_rili_page_rili_task_main_main_focused);
	lv_style_set_radius(&style_rili_page_rili_task_main_main_focused, 0);
	lv_style_set_bg_color(&style_rili_page_rili_task_main_main_focused, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_rili_page_rili_task_main_main_focused, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_rili_page_rili_task_main_main_focused, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_rili_page_rili_task_main_main_focused, 255);
	lv_style_set_border_color(&style_rili_page_rili_task_main_main_focused, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_rili_page_rili_task_main_main_focused, 1);
	lv_style_set_border_opa(&style_rili_page_rili_task_main_main_focused, 255);
	lv_obj_add_style(ui->rili_page_rili_task, &style_rili_page_rili_task_main_main_focused, LV_PART_MAIN|LV_STATE_FOCUSED);

	//Write style state: LV_STATE_DISABLED for style_rili_page_rili_task_main_main_disabled
	static lv_style_t style_rili_page_rili_task_main_main_disabled;
	if (style_rili_page_rili_task_main_main_disabled.prop_cnt > 1)
		lv_style_reset(&style_rili_page_rili_task_main_main_disabled);
	else
		lv_style_init(&style_rili_page_rili_task_main_main_disabled);
	lv_style_set_radius(&style_rili_page_rili_task_main_main_disabled, 0);
	lv_style_set_bg_color(&style_rili_page_rili_task_main_main_disabled, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_rili_page_rili_task_main_main_disabled, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_rili_page_rili_task_main_main_disabled, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_rili_page_rili_task_main_main_disabled, 255);
	lv_style_set_border_color(&style_rili_page_rili_task_main_main_disabled, lv_color_make(0xc0, 0xc0, 0xc0));
	lv_style_set_border_width(&style_rili_page_rili_task_main_main_disabled, 1);
	lv_style_set_border_opa(&style_rili_page_rili_task_main_main_disabled, 255);
	lv_obj_add_style(ui->rili_page_rili_task, &style_rili_page_rili_task_main_main_disabled, LV_PART_MAIN|LV_STATE_DISABLED);

	//Write style state: LV_STATE_DEFAULT for style_rili_page_rili_task_extra_header_main_default
	static lv_style_t style_rili_page_rili_task_extra_header_main_default;
	if (style_rili_page_rili_task_extra_header_main_default.prop_cnt > 1)
		lv_style_reset(&style_rili_page_rili_task_extra_header_main_default);
	else
		lv_style_init(&style_rili_page_rili_task_extra_header_main_default);
	lv_style_set_bg_color(&style_rili_page_rili_task_extra_header_main_default, lv_color_make(0x01, 0x23, 0x5b));
	lv_style_set_bg_grad_color(&style_rili_page_rili_task_extra_header_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_rili_page_rili_task_extra_header_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_rili_page_rili_task_extra_header_main_default, 255);
	lv_style_set_text_color(&style_rili_page_rili_task_extra_header_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_rili_page_rili_task_extra_header_main_default, &lv_font_simsun_20);
	lv_obj_add_style(rili_page_rili_task_header, &style_rili_page_rili_task_extra_header_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
}