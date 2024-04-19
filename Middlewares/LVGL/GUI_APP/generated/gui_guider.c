/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"


void init_scr_del_flag(lv_ui *ui){
	ui->home_page_del = true;
	ui->Caidan_page_del = true;
    ui->chongdian_page_del = true;
	ui->rili_page_del = true;
	ui->miaobia_page_del = true;
	ui->jisuan_page_del = true;
}

void setup_ui(lv_ui *ui){
	init_scr_del_flag(ui);
	setup_scr_home_page(ui);
	lv_scr_load(ui->home_page);
}
