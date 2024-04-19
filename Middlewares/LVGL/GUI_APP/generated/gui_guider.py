# Copyright 2022 NXP
# SPDX-License-Identifier: MIT
# The auto-generated can only be used on NXP devices

import SDL
import utime as time
import usys as sys
import lvgl as lv
import lodepng as png
import ustruct

lv.init()
SDL.init(w=240,h=280)

# Register SDL display driver.
disp_buf1 = lv.disp_draw_buf_t()
buf1_1 = bytearray(240*10)
disp_buf1.init(buf1_1, None, len(buf1_1)//4)
disp_drv = lv.disp_drv_t()
disp_drv.init()
disp_drv.draw_buf = disp_buf1
disp_drv.flush_cb = SDL.monitor_flush
disp_drv.hor_res = 240
disp_drv.ver_res = 280
disp_drv.register()

# Regsiter SDL mouse driver
indev_drv = lv.indev_drv_t()
indev_drv.init() 
indev_drv.type = lv.INDEV_TYPE.POINTER
indev_drv.read_cb = SDL.mouse_read
indev_drv.register()

# Below: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

COLOR_SIZE = lv.color_t.__SIZE__
COLOR_IS_SWAPPED = hasattr(lv.color_t().ch,'green_h')

class lodepng_error(RuntimeError):
    def __init__(self, err):
        if type(err) is int:
            super().__init__(png.error_text(err))
        else:
            super().__init__(err)

# Parse PNG file header
# Taken from https://github.com/shibukawa/imagesize_py/blob/ffef30c1a4715c5acf90e8945ceb77f4a2ed2d45/imagesize.py#L63-L85

def get_png_info(decoder, src, header):
    # Only handle variable image types

    if lv.img.src_get_type(src) != lv.img.SRC.VARIABLE:
        return lv.RES.INV

    data = lv.img_dsc_t.__cast__(src).data
    if data == None:
        return lv.RES.INV

    png_header = bytes(data.__dereference__(24))

    if png_header.startswith(b'\211PNG\r\n\032\n'):
        if png_header[12:16] == b'IHDR':
            start = 16
        # Maybe this is for an older PNG version.
        else:
            start = 8
        try:
            width, height = ustruct.unpack(">LL", png_header[start:start+8])
        except ustruct.error:
            return lv.RES.INV
    else:
        return lv.RES.INV

    header.always_zero = 0
    header.w = width
    header.h = height
    header.cf = lv.img.CF.TRUE_COLOR_ALPHA

    return lv.RES.OK

def convert_rgba8888_to_bgra8888(img_view):
    for i in range(0, len(img_view), lv.color_t.__SIZE__):
        ch = lv.color_t.__cast__(img_view[i:i]).ch
        ch.red, ch.blue = ch.blue, ch.red

# Read and parse PNG file

def open_png(decoder, dsc):
    img_dsc = lv.img_dsc_t.__cast__(dsc.src)
    png_data = img_dsc.data
    png_size = img_dsc.data_size
    png_decoded = png.C_Pointer()
    png_width = png.C_Pointer()
    png_height = png.C_Pointer()
    error = png.decode32(png_decoded, png_width, png_height, png_data, png_size)
    if error:
        raise lodepng_error(error)
    img_size = png_width.int_val * png_height.int_val * 4
    img_data = png_decoded.ptr_val
    img_view = img_data.__dereference__(img_size)

    if COLOR_SIZE == 4:
        convert_rgba8888_to_bgra8888(img_view)
    else:
        raise lodepng_error("Error: Color mode not supported yet!")

    dsc.img_data = img_data
    return lv.RES.OK

# Above: Taken from https://github.com/lvgl/lv_binding_micropython/blob/master/driver/js/imagetools.py#L22-L94

decoder = lv.img.decoder_create()
decoder.info_cb = get_png_info
decoder.open_cb = open_png

def anim_x_cb(obj, v):
    obj.set_x(v)

def anim_y_cb(obj, v):
    obj.set_y(v)

def ta_event_cb(e,kb):
    code = e.get_code()
    ta = e.get_target()
    if code == lv.EVENT.FOCUSED:
        kb.set_textarea(ta)
        kb.move_foreground()
        kb.clear_flag(lv.obj.FLAG.HIDDEN)

    if code == lv.EVENT.DEFOCUSED:
        kb.set_textarea(None)
        kb.move_background()
        kb.add_flag(lv.obj.FLAG.HIDDEN)


home_page = lv.obj()
home_page.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_home_page_main_main_default
style_home_page_main_main_default = lv.style_t()
style_home_page_main_main_default.init()
style_home_page_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_home_page_main_main_default.set_bg_opa(255)

# add style for home_page
home_page.add_style(style_home_page_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_animimg_1 = lv.animimg(home_page)
home_page_animimg_1.set_pos(int(65),int(117))
home_page_animimg_1.set_size(70,70)
home_page_animimg_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_animimg_1_animimgs = [None]*4
try:
    with open('D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp124397884.png','rb') as f:
        home_page_animimg_1_animimg_data_0 = f.read()
except:
    print('Could not open D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp124397884.png')
    sys.exit()

home_page_animimg_1_animimgs[0] = lv.img_dsc_t({
  'data_size': len(home_page_animimg_1_animimg_data_0),
  'header': {'always_zero': 0, 'w': 70, 'h': 70, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_page_animimg_1_animimg_data_0
})
try:
    with open('D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp2072141124.png','rb') as f:
        home_page_animimg_1_animimg_data_1 = f.read()
except:
    print('Could not open D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp2072141124.png')
    sys.exit()

home_page_animimg_1_animimgs[1] = lv.img_dsc_t({
  'data_size': len(home_page_animimg_1_animimg_data_1),
  'header': {'always_zero': 0, 'w': 70, 'h': 70, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_page_animimg_1_animimg_data_1
})
try:
    with open('D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp-381160741.png','rb') as f:
        home_page_animimg_1_animimg_data_2 = f.read()
except:
    print('Could not open D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp-381160741.png')
    sys.exit()

home_page_animimg_1_animimgs[2] = lv.img_dsc_t({
  'data_size': len(home_page_animimg_1_animimg_data_2),
  'header': {'always_zero': 0, 'w': 70, 'h': 70, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_page_animimg_1_animimg_data_2
})
try:
    with open('D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp-1554772769.png','rb') as f:
        home_page_animimg_1_animimg_data_3 = f.read()
except:
    print('Could not open D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp-1554772769.png')
    sys.exit()

home_page_animimg_1_animimgs[3] = lv.img_dsc_t({
  'data_size': len(home_page_animimg_1_animimg_data_3),
  'header': {'always_zero': 0, 'w': 70, 'h': 70, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_page_animimg_1_animimg_data_3
})

home_page_animimg_1.set_src(home_page_animimg_1_animimgs, 4)
home_page_animimg_1.set_duration(120 * 4)
home_page_animimg_1.set_repeat_count(3000)
home_page_animimg_1.start()

home_page_digital_clock_1 = lv.dclock(home_page, "11:25")
home_page_digital_clock_1.set_text("11:25")



class home_page_digital_clock_1_timerClass():
    def __init__(self):
        self.hour = 11
        self.minute = 25
        self.second = 0
  
    def count_24(self, timer):
        self.second += 1
        if self.second == 60:
            self.second = 0
            self.minute += 1
	
        if self.minute == 60:
            self.minute = 0
            self.hour +=1
            
        if self.hour == 24:
            self.hour = 0

        home_page_digital_clock_1.set_text("%02d:%02d" %(self.hour, self.minute))

    def count_12(self, timer):
        self.second += 1
        if self.second == 60:
            self.second = 0
            self.minute += 1
        if self.minute == 60:
            self.minute = 0
            if self.hour < 12:
                self.hour += 1
            else:
                self.hour += 1
                self.hour = self.hour % 12
        if (self.hour == 12 and self.second == 0 and self.minute == 0):
            if(self.meridiem == "PM"):
                self.meridiem = "AM"
            else:
                self.meridiem = "PM"
		
        home_page_digital_clock_1.set_text("%02d:%02d %s" %(self.hour, self.minute, self.meridiem))

home_page_digital_clock_1_timerInstance = home_page_digital_clock_1_timerClass()

home_page_digital_clock_1_timer = lv.timer_create_basic()
home_page_digital_clock_1_timer.set_period(1000)

home_page_digital_clock_1_timer.set_cb(lambda src: home_page_digital_clock_1_timerInstance.count_24(home_page_digital_clock_1_timer))
lv.dclock.set_style_text_align(home_page_digital_clock_1, lv.TEXT_ALIGN.CENTER, 0);

home_page_digital_clock_1.set_pos(int(40),int(65))
home_page_digital_clock_1.set_size(160,80)
home_page_digital_clock_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_home_page_digital_clock_1_main_main_default
style_home_page_digital_clock_1_main_main_default = lv.style_t()
style_home_page_digital_clock_1_main_main_default.init()
style_home_page_digital_clock_1_main_main_default.set_radius(0)
style_home_page_digital_clock_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_home_page_digital_clock_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_digital_clock_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_page_digital_clock_1_main_main_default.set_bg_opa(0)
style_home_page_digital_clock_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_home_page_digital_clock_1_main_main_default.set_text_font(lv.font_simsun_40)
except AttributeError:
    try:
        style_home_page_digital_clock_1_main_main_default.set_text_font(lv.font_montserrat_40)
    except AttributeError:
        style_home_page_digital_clock_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_page_digital_clock_1_main_main_default.set_text_letter_space(10)
style_home_page_digital_clock_1_main_main_default.set_pad_left(0)
style_home_page_digital_clock_1_main_main_default.set_pad_right(0)
style_home_page_digital_clock_1_main_main_default.set_pad_top(0)
style_home_page_digital_clock_1_main_main_default.set_pad_bottom(0)

# add style for home_page_digital_clock_1
home_page_digital_clock_1.add_style(style_home_page_digital_clock_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_dian_liang = lv.img(home_page)
home_page_dian_liang.set_pos(int(164),int(21))
home_page_dian_liang.set_size(20,20)
home_page_dian_liang.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_dian_liang.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp352261394.png','rb') as f:
        home_page_dian_liang_img_data = f.read()
except:
    print('Could not open D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp352261394.png')
    sys.exit()

home_page_dian_liang_img = lv.img_dsc_t({
  'data_size': len(home_page_dian_liang_img_data),
  'header': {'always_zero': 0, 'w': 20, 'h': 20, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_page_dian_liang_img_data
})

home_page_dian_liang.set_src(home_page_dian_liang_img)
home_page_dian_liang.set_pivot(0,0)
home_page_dian_liang.set_angle(0)
# create style style_home_page_dian_liang_main_main_default
style_home_page_dian_liang_main_main_default = lv.style_t()
style_home_page_dian_liang_main_main_default.init()
style_home_page_dian_liang_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_page_dian_liang_main_main_default.set_img_recolor_opa(0)
style_home_page_dian_liang_main_main_default.set_img_opa(255)

# add style for home_page_dian_liang
home_page_dian_liang.add_style(style_home_page_dian_liang_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_line_1 = lv.line(home_page)
home_page_line_1.set_pos(int(0),int(56))
home_page_line_1.set_size(240,3)
home_page_line_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":242, "y":0}, 
			  ]
home_page_line_1.set_points(line_points, 2)
# create style style_home_page_line_1_main_main_default
style_home_page_line_1_main_main_default = lv.style_t()
style_home_page_line_1_main_main_default.init()
style_home_page_line_1_main_main_default.set_line_color(lv.color_make(0xff,0xff,0xff))
style_home_page_line_1_main_main_default.set_line_width(2)
style_home_page_line_1_main_main_default.set_line_rounded(True)

# add style for home_page_line_1
home_page_line_1.add_style(style_home_page_line_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_data_dianliang = lv.spangroup(home_page)
home_page_data_dianliang.set_pos(int(186),int(20))
home_page_data_dianliang.set_size(54,22)
home_page_data_dianliang.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_data_dianliang.set_align(lv.TEXT_ALIGN.LEFT)
home_page_data_dianliang.set_overflow(lv.SPAN_OVERFLOW.CLIP)
home_page_data_dianliang.set_mode(lv.SPAN_MODE.BREAK)
home_page_data_dianliang_span = home_page_data_dianliang.new_span()
home_page_data_dianliang_span.set_text("100%")
home_page_data_dianliang_span.style.set_text_color(lv.color_make(0xff,0xff,0xff))
home_page_data_dianliang_span.style.set_text_decor(lv.TEXT_DECOR.NONE)
try:
    home_page_data_dianliang_span.style.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        home_page_data_dianliang_span.style.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        home_page_data_dianliang_span.style.set_text_font(lv.font_montserrat_16)
home_page_data_dianliang.refr_mode()
# create style style_home_page_data_dianliang_main_main_default
style_home_page_data_dianliang_main_main_default = lv.style_t()
style_home_page_data_dianliang_main_main_default.init()
style_home_page_data_dianliang_main_main_default.set_radius(0)
style_home_page_data_dianliang_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_dianliang_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_dianliang_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_page_data_dianliang_main_main_default.set_bg_opa(0)
style_home_page_data_dianliang_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_home_page_data_dianliang_main_main_default.set_border_width(0)
style_home_page_data_dianliang_main_main_default.set_border_opa(255)
style_home_page_data_dianliang_main_main_default.set_pad_left(0)
style_home_page_data_dianliang_main_main_default.set_pad_right(0)
style_home_page_data_dianliang_main_main_default.set_pad_top(0)
style_home_page_data_dianliang_main_main_default.set_pad_bottom(0)

# add style for home_page_data_dianliang
home_page_data_dianliang.add_style(style_home_page_data_dianliang_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_line_2 = lv.line(home_page)
home_page_line_2.set_pos(int(0),int(229))
home_page_line_2.set_size(240,5)
home_page_line_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":242, "y":0}, 
			  ]
home_page_line_2.set_points(line_points, 2)
# create style style_home_page_line_2_main_main_default
style_home_page_line_2_main_main_default = lv.style_t()
style_home_page_line_2_main_main_default.init()
style_home_page_line_2_main_main_default.set_line_color(lv.color_make(0xff,0xff,0xff))
style_home_page_line_2_main_main_default.set_line_width(2)
style_home_page_line_2_main_main_default.set_line_rounded(True)

# add style for home_page_line_2
home_page_line_2.add_style(style_home_page_line_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_huo_jian = lv.img(home_page)
home_page_huo_jian.set_pos(int(15),int(21))
home_page_huo_jian.set_size(20,20)
home_page_huo_jian.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_huo_jian.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp-1233361547.png','rb') as f:
        home_page_huo_jian_img_data = f.read()
except:
    print('Could not open D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp-1233361547.png')
    sys.exit()

home_page_huo_jian_img = lv.img_dsc_t({
  'data_size': len(home_page_huo_jian_img_data),
  'header': {'always_zero': 0, 'w': 20, 'h': 20, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_page_huo_jian_img_data
})

home_page_huo_jian.set_src(home_page_huo_jian_img)
home_page_huo_jian.set_pivot(0,0)
home_page_huo_jian.set_angle(0)
# create style style_home_page_huo_jian_main_main_default
style_home_page_huo_jian_main_main_default = lv.style_t()
style_home_page_huo_jian_main_main_default.init()
style_home_page_huo_jian_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_page_huo_jian_main_main_default.set_img_recolor_opa(0)
style_home_page_huo_jian_main_main_default.set_img_opa(255)

# add style for home_page_huo_jian
home_page_huo_jian.add_style(style_home_page_huo_jian_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_data_riqi = lv.spangroup(home_page)
home_page_data_riqi.set_pos(int(42),int(20))
home_page_data_riqi.set_size(57,21)
home_page_data_riqi.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_data_riqi.set_align(lv.TEXT_ALIGN.LEFT)
home_page_data_riqi.set_overflow(lv.SPAN_OVERFLOW.CLIP)
home_page_data_riqi.set_mode(lv.SPAN_MODE.BREAK)
home_page_data_riqi_span = home_page_data_riqi.new_span()
home_page_data_riqi_span.set_text("9.15")
home_page_data_riqi_span.style.set_text_color(lv.color_make(0xff,0xff,0xff))
home_page_data_riqi_span.style.set_text_decor(lv.TEXT_DECOR.NONE)
try:
    home_page_data_riqi_span.style.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        home_page_data_riqi_span.style.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        home_page_data_riqi_span.style.set_text_font(lv.font_montserrat_16)
home_page_data_riqi.refr_mode()
# create style style_home_page_data_riqi_main_main_default
style_home_page_data_riqi_main_main_default = lv.style_t()
style_home_page_data_riqi_main_main_default.init()
style_home_page_data_riqi_main_main_default.set_radius(0)
style_home_page_data_riqi_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_riqi_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_riqi_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_page_data_riqi_main_main_default.set_bg_opa(0)
style_home_page_data_riqi_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_home_page_data_riqi_main_main_default.set_border_width(0)
style_home_page_data_riqi_main_main_default.set_border_opa(255)
style_home_page_data_riqi_main_main_default.set_pad_left(0)
style_home_page_data_riqi_main_main_default.set_pad_right(0)
style_home_page_data_riqi_main_main_default.set_pad_top(0)
style_home_page_data_riqi_main_main_default.set_pad_bottom(0)

# add style for home_page_data_riqi
home_page_data_riqi.add_style(style_home_page_data_riqi_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_data_week = lv.spangroup(home_page)
home_page_data_week.set_pos(int(105),int(21))
home_page_data_week.set_size(46,20)
home_page_data_week.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_data_week.set_align(lv.TEXT_ALIGN.LEFT)
home_page_data_week.set_overflow(lv.SPAN_OVERFLOW.CLIP)
home_page_data_week.set_mode(lv.SPAN_MODE.BREAK)
home_page_data_week_span = home_page_data_week.new_span()
home_page_data_week_span.set_text("周五")
home_page_data_week_span.style.set_text_color(lv.color_make(0xff,0xff,0xff))
home_page_data_week_span.style.set_text_decor(lv.TEXT_DECOR.NONE)
try:
    home_page_data_week_span.style.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        home_page_data_week_span.style.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        home_page_data_week_span.style.set_text_font(lv.font_montserrat_16)
home_page_data_week.refr_mode()
# create style style_home_page_data_week_main_main_default
style_home_page_data_week_main_main_default = lv.style_t()
style_home_page_data_week_main_main_default.init()
style_home_page_data_week_main_main_default.set_radius(0)
style_home_page_data_week_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_week_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_week_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_page_data_week_main_main_default.set_bg_opa(0)
style_home_page_data_week_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_home_page_data_week_main_main_default.set_border_width(0)
style_home_page_data_week_main_main_default.set_border_opa(255)
style_home_page_data_week_main_main_default.set_pad_left(0)
style_home_page_data_week_main_main_default.set_pad_right(0)
style_home_page_data_week_main_main_default.set_pad_top(0)
style_home_page_data_week_main_main_default.set_pad_bottom(0)

# add style for home_page_data_week
home_page_data_week.add_style(style_home_page_data_week_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_line_3 = lv.line(home_page)
home_page_line_3.set_pos(int(155),int(10))
home_page_line_3.set_size(4,44)
home_page_line_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":0, "y":50}, 
			  ]
home_page_line_3.set_points(line_points, 2)
# create style style_home_page_line_3_main_main_default
style_home_page_line_3_main_main_default = lv.style_t()
style_home_page_line_3_main_main_default.init()
style_home_page_line_3_main_main_default.set_line_color(lv.color_make(0xff,0xff,0xff))
style_home_page_line_3_main_main_default.set_line_width(2)
style_home_page_line_3_main_main_default.set_line_rounded(True)

# add style for home_page_line_3
home_page_line_3.add_style(style_home_page_line_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_line_5 = lv.line(home_page)
home_page_line_5.set_pos(int(80),int(229))
home_page_line_5.set_size(5,32)
home_page_line_5.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":0, "y":50}, 
			  ]
home_page_line_5.set_points(line_points, 2)
# create style style_home_page_line_5_main_main_default
style_home_page_line_5_main_main_default = lv.style_t()
style_home_page_line_5_main_main_default.init()
style_home_page_line_5_main_main_default.set_line_color(lv.color_make(0xff,0xff,0xff))
style_home_page_line_5_main_main_default.set_line_width(2)
style_home_page_line_5_main_main_default.set_line_rounded(True)

# add style for home_page_line_5
home_page_line_5.add_style(style_home_page_line_5_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_line_6 = lv.line(home_page)
home_page_line_6.set_pos(int(160),int(229))
home_page_line_6.set_size(5,32)
home_page_line_6.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
line_points = [
                   {"x":0, "y":0}, 
                   {"x":0, "y":50}, 
			  ]
home_page_line_6.set_points(line_points, 2)
# create style style_home_page_line_6_main_main_default
style_home_page_line_6_main_main_default = lv.style_t()
style_home_page_line_6_main_main_default.init()
style_home_page_line_6_main_main_default.set_line_color(lv.color_make(0xff,0xff,0xff))
style_home_page_line_6_main_main_default.set_line_width(2)
style_home_page_line_6_main_main_default.set_line_rounded(True)

# add style for home_page_line_6
home_page_line_6.add_style(style_home_page_line_6_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_xin_lv = lv.img(home_page)
home_page_xin_lv.set_pos(int(160),int(194))
home_page_xin_lv.set_size(20,20)
home_page_xin_lv.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_xin_lv.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp-184728210.png','rb') as f:
        home_page_xin_lv_img_data = f.read()
except:
    print('Could not open D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp-184728210.png')
    sys.exit()

home_page_xin_lv_img = lv.img_dsc_t({
  'data_size': len(home_page_xin_lv_img_data),
  'header': {'always_zero': 0, 'w': 20, 'h': 20, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_page_xin_lv_img_data
})

home_page_xin_lv.set_src(home_page_xin_lv_img)
home_page_xin_lv.set_pivot(0,0)
home_page_xin_lv.set_angle(0)
# create style style_home_page_xin_lv_main_main_default
style_home_page_xin_lv_main_main_default = lv.style_t()
style_home_page_xin_lv_main_main_default.init()
style_home_page_xin_lv_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_page_xin_lv_main_main_default.set_img_recolor_opa(0)
style_home_page_xin_lv_main_main_default.set_img_opa(255)

# add style for home_page_xin_lv
home_page_xin_lv.add_style(style_home_page_xin_lv_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_data_xinlv = lv.spangroup(home_page)
home_page_data_xinlv.set_pos(int(194),int(194))
home_page_data_xinlv.set_size(46,20)
home_page_data_xinlv.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_data_xinlv.set_align(lv.TEXT_ALIGN.LEFT)
home_page_data_xinlv.set_overflow(lv.SPAN_OVERFLOW.CLIP)
home_page_data_xinlv.set_mode(lv.SPAN_MODE.BREAK)
home_page_data_xinlv_span = home_page_data_xinlv.new_span()
home_page_data_xinlv_span.set_text("80")
home_page_data_xinlv_span.style.set_text_color(lv.color_make(0xff,0xff,0xff))
home_page_data_xinlv_span.style.set_text_decor(lv.TEXT_DECOR.NONE)
try:
    home_page_data_xinlv_span.style.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        home_page_data_xinlv_span.style.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        home_page_data_xinlv_span.style.set_text_font(lv.font_montserrat_16)
home_page_data_xinlv.refr_mode()
# create style style_home_page_data_xinlv_main_main_default
style_home_page_data_xinlv_main_main_default = lv.style_t()
style_home_page_data_xinlv_main_main_default.init()
style_home_page_data_xinlv_main_main_default.set_radius(0)
style_home_page_data_xinlv_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_xinlv_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_xinlv_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_page_data_xinlv_main_main_default.set_bg_opa(0)
style_home_page_data_xinlv_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_home_page_data_xinlv_main_main_default.set_border_width(0)
style_home_page_data_xinlv_main_main_default.set_border_opa(255)
style_home_page_data_xinlv_main_main_default.set_pad_left(0)
style_home_page_data_xinlv_main_main_default.set_pad_right(0)
style_home_page_data_xinlv_main_main_default.set_pad_top(0)
style_home_page_data_xinlv_main_main_default.set_pad_bottom(0)

# add style for home_page_data_xinlv
home_page_data_xinlv.add_style(style_home_page_data_xinlv_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_wen_du = lv.img(home_page)
home_page_wen_du.set_pos(int(10),int(236))
home_page_wen_du.set_size(20,20)
home_page_wen_du.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_wen_du.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp825768977.png','rb') as f:
        home_page_wen_du_img_data = f.read()
except:
    print('Could not open D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp825768977.png')
    sys.exit()

home_page_wen_du_img = lv.img_dsc_t({
  'data_size': len(home_page_wen_du_img_data),
  'header': {'always_zero': 0, 'w': 20, 'h': 20, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_page_wen_du_img_data
})

home_page_wen_du.set_src(home_page_wen_du_img)
home_page_wen_du.set_pivot(0,0)
home_page_wen_du.set_angle(0)
# create style style_home_page_wen_du_main_main_default
style_home_page_wen_du_main_main_default = lv.style_t()
style_home_page_wen_du_main_main_default.init()
style_home_page_wen_du_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_page_wen_du_main_main_default.set_img_recolor_opa(0)
style_home_page_wen_du_main_main_default.set_img_opa(255)

# add style for home_page_wen_du
home_page_wen_du.add_style(style_home_page_wen_du_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_data_wendu = lv.spangroup(home_page)
home_page_data_wendu.set_pos(int(30),int(236))
home_page_data_wendu.set_size(59,22)
home_page_data_wendu.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_data_wendu.set_align(lv.TEXT_ALIGN.LEFT)
home_page_data_wendu.set_overflow(lv.SPAN_OVERFLOW.CLIP)
home_page_data_wendu.set_mode(lv.SPAN_MODE.BREAK)
home_page_data_wendu_span = home_page_data_wendu.new_span()
home_page_data_wendu_span.set_text("25")
home_page_data_wendu_span.style.set_text_color(lv.color_make(0xff,0xff,0xff))
home_page_data_wendu_span.style.set_text_decor(lv.TEXT_DECOR.NONE)
try:
    home_page_data_wendu_span.style.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        home_page_data_wendu_span.style.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        home_page_data_wendu_span.style.set_text_font(lv.font_montserrat_16)
home_page_data_wendu.refr_mode()
# create style style_home_page_data_wendu_main_main_default
style_home_page_data_wendu_main_main_default = lv.style_t()
style_home_page_data_wendu_main_main_default.init()
style_home_page_data_wendu_main_main_default.set_radius(0)
style_home_page_data_wendu_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_wendu_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_wendu_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_page_data_wendu_main_main_default.set_bg_opa(0)
style_home_page_data_wendu_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_home_page_data_wendu_main_main_default.set_border_width(0)
style_home_page_data_wendu_main_main_default.set_border_opa(255)
style_home_page_data_wendu_main_main_default.set_pad_left(0)
style_home_page_data_wendu_main_main_default.set_pad_right(0)
style_home_page_data_wendu_main_main_default.set_pad_top(0)
style_home_page_data_wendu_main_main_default.set_pad_bottom(0)

# add style for home_page_data_wendu
home_page_data_wendu.add_style(style_home_page_data_wendu_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_sheshidu = lv.spangroup(home_page)
home_page_sheshidu.set_pos(int(53),int(236))
home_page_sheshidu.set_size(59,22)
home_page_sheshidu.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_sheshidu.set_align(lv.TEXT_ALIGN.LEFT)
home_page_sheshidu.set_overflow(lv.SPAN_OVERFLOW.CLIP)
home_page_sheshidu.set_mode(lv.SPAN_MODE.BREAK)
home_page_sheshidu_span = home_page_sheshidu.new_span()
home_page_sheshidu_span.set_text("℃")
home_page_sheshidu_span.style.set_text_color(lv.color_make(0xff,0xff,0xff))
home_page_sheshidu_span.style.set_text_decor(lv.TEXT_DECOR.NONE)
try:
    home_page_sheshidu_span.style.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        home_page_sheshidu_span.style.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        home_page_sheshidu_span.style.set_text_font(lv.font_montserrat_16)
home_page_sheshidu.refr_mode()
# create style style_home_page_sheshidu_main_main_default
style_home_page_sheshidu_main_main_default = lv.style_t()
style_home_page_sheshidu_main_main_default.init()
style_home_page_sheshidu_main_main_default.set_radius(0)
style_home_page_sheshidu_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_sheshidu_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_sheshidu_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_page_sheshidu_main_main_default.set_bg_opa(0)
style_home_page_sheshidu_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_home_page_sheshidu_main_main_default.set_border_width(0)
style_home_page_sheshidu_main_main_default.set_border_opa(255)
style_home_page_sheshidu_main_main_default.set_pad_left(0)
style_home_page_sheshidu_main_main_default.set_pad_right(0)
style_home_page_sheshidu_main_main_default.set_pad_top(0)
style_home_page_sheshidu_main_main_default.set_pad_bottom(0)

# add style for home_page_sheshidu
home_page_sheshidu.add_style(style_home_page_sheshidu_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_data_shidu = lv.spangroup(home_page)
home_page_data_shidu.set_pos(int(110),int(236))
home_page_data_shidu.set_size(59,22)
home_page_data_shidu.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_data_shidu.set_align(lv.TEXT_ALIGN.LEFT)
home_page_data_shidu.set_overflow(lv.SPAN_OVERFLOW.CLIP)
home_page_data_shidu.set_mode(lv.SPAN_MODE.BREAK)
home_page_data_shidu_span = home_page_data_shidu.new_span()
home_page_data_shidu_span.set_text("60%")
home_page_data_shidu_span.style.set_text_color(lv.color_make(0xff,0xff,0xff))
home_page_data_shidu_span.style.set_text_decor(lv.TEXT_DECOR.NONE)
try:
    home_page_data_shidu_span.style.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        home_page_data_shidu_span.style.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        home_page_data_shidu_span.style.set_text_font(lv.font_montserrat_16)
home_page_data_shidu.refr_mode()
# create style style_home_page_data_shidu_main_main_default
style_home_page_data_shidu_main_main_default = lv.style_t()
style_home_page_data_shidu_main_main_default.init()
style_home_page_data_shidu_main_main_default.set_radius(0)
style_home_page_data_shidu_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_shidu_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_shidu_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_page_data_shidu_main_main_default.set_bg_opa(0)
style_home_page_data_shidu_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_home_page_data_shidu_main_main_default.set_border_width(0)
style_home_page_data_shidu_main_main_default.set_border_opa(255)
style_home_page_data_shidu_main_main_default.set_pad_left(0)
style_home_page_data_shidu_main_main_default.set_pad_right(0)
style_home_page_data_shidu_main_main_default.set_pad_top(0)
style_home_page_data_shidu_main_main_default.set_pad_bottom(0)

# add style for home_page_data_shidu
home_page_data_shidu.add_style(style_home_page_data_shidu_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_shidu = lv.img(home_page)
home_page_shidu.set_pos(int(90),int(236))
home_page_shidu.set_size(20,20)
home_page_shidu.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_shidu.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp-2079552052.png','rb') as f:
        home_page_shidu_img_data = f.read()
except:
    print('Could not open D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp-2079552052.png')
    sys.exit()

home_page_shidu_img = lv.img_dsc_t({
  'data_size': len(home_page_shidu_img_data),
  'header': {'always_zero': 0, 'w': 20, 'h': 20, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_page_shidu_img_data
})

home_page_shidu.set_src(home_page_shidu_img)
home_page_shidu.set_pivot(0,0)
home_page_shidu.set_angle(0)
# create style style_home_page_shidu_main_main_default
style_home_page_shidu_main_main_default = lv.style_t()
style_home_page_shidu_main_main_default.init()
style_home_page_shidu_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_page_shidu_main_main_default.set_img_recolor_opa(0)
style_home_page_shidu_main_main_default.set_img_opa(255)

# add style for home_page_shidu
home_page_shidu.add_style(style_home_page_shidu_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_bushu = lv.img(home_page)
home_page_bushu.set_pos(int(10),int(194))
home_page_bushu.set_size(20,20)
home_page_bushu.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_bushu.add_flag(lv.obj.FLAG.CLICKABLE)
try:
    with open('D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp-490303714.png','rb') as f:
        home_page_bushu_img_data = f.read()
except:
    print('Could not open D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp-490303714.png')
    sys.exit()

home_page_bushu_img = lv.img_dsc_t({
  'data_size': len(home_page_bushu_img_data),
  'header': {'always_zero': 0, 'w': 20, 'h': 20, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': home_page_bushu_img_data
})

home_page_bushu.set_src(home_page_bushu_img)
home_page_bushu.set_pivot(0,0)
home_page_bushu.set_angle(0)
# create style style_home_page_bushu_main_main_default
style_home_page_bushu_main_main_default = lv.style_t()
style_home_page_bushu_main_main_default.init()
style_home_page_bushu_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_home_page_bushu_main_main_default.set_img_recolor_opa(0)
style_home_page_bushu_main_main_default.set_img_opa(255)

# add style for home_page_bushu
home_page_bushu.add_style(style_home_page_bushu_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_data_bushu = lv.spangroup(home_page)
home_page_data_bushu.set_pos(int(41),int(193))
home_page_data_bushu.set_size(82,21)
home_page_data_bushu.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_data_bushu.set_align(lv.TEXT_ALIGN.LEFT)
home_page_data_bushu.set_overflow(lv.SPAN_OVERFLOW.CLIP)
home_page_data_bushu.set_mode(lv.SPAN_MODE.BREAK)
home_page_data_bushu_span = home_page_data_bushu.new_span()
home_page_data_bushu_span.set_text("15000")
home_page_data_bushu_span.style.set_text_color(lv.color_make(0xff,0xff,0xff))
home_page_data_bushu_span.style.set_text_decor(lv.TEXT_DECOR.NONE)
try:
    home_page_data_bushu_span.style.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        home_page_data_bushu_span.style.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        home_page_data_bushu_span.style.set_text_font(lv.font_montserrat_16)
home_page_data_bushu.refr_mode()
# create style style_home_page_data_bushu_main_main_default
style_home_page_data_bushu_main_main_default = lv.style_t()
style_home_page_data_bushu_main_main_default.init()
style_home_page_data_bushu_main_main_default.set_radius(0)
style_home_page_data_bushu_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_bushu_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_bushu_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_page_data_bushu_main_main_default.set_bg_opa(0)
style_home_page_data_bushu_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_home_page_data_bushu_main_main_default.set_border_width(0)
style_home_page_data_bushu_main_main_default.set_border_opa(0)
style_home_page_data_bushu_main_main_default.set_pad_left(0)
style_home_page_data_bushu_main_main_default.set_pad_right(0)
style_home_page_data_bushu_main_main_default.set_pad_top(0)
style_home_page_data_bushu_main_main_default.set_pad_bottom(0)

# add style for home_page_data_bushu
home_page_data_bushu.add_style(style_home_page_data_bushu_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_caidan = lv.imgbtn(home_page)
home_page_caidan.set_pos(int(163),int(206))
home_page_caidan.set_size(75,85)
home_page_caidan.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)





home_page_caidan.add_flag(lv.obj.FLAG.CHECKABLE)
home_page_caidan_label = lv.label(home_page_caidan)
home_page_caidan_label.set_text("菜单")
home_page_caidan.set_style_pad_all(0, lv.STATE.ANY)
home_page_caidan_label.align(lv.ALIGN.CENTER,0,0)
# create style style_home_page_caidan_main_main_default
style_home_page_caidan_main_main_default = lv.style_t()
style_home_page_caidan_main_main_default.init()
style_home_page_caidan_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_home_page_caidan_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_home_page_caidan_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_home_page_caidan_main_main_default.set_text_font(lv.font_montserrat_16)
style_home_page_caidan_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_page_caidan_main_main_default.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_page_caidan_main_main_default.set_img_recolor_opa(0)
style_home_page_caidan_main_main_default.set_img_opa(255)

# add style for home_page_caidan
home_page_caidan.add_style(style_home_page_caidan_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_home_page_caidan_main_main_pressed
style_home_page_caidan_main_main_pressed = lv.style_t()
style_home_page_caidan_main_main_pressed.init()
style_home_page_caidan_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_home_page_caidan_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_page_caidan_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_page_caidan_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_home_page_caidan_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_page_caidan_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_page_caidan_main_main_pressed.set_img_recolor_opa(0)
style_home_page_caidan_main_main_pressed.set_img_opa(255)

# add style for home_page_caidan
home_page_caidan.add_style(style_home_page_caidan_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_home_page_caidan_main_main_checked
style_home_page_caidan_main_main_checked = lv.style_t()
style_home_page_caidan_main_main_checked.init()
style_home_page_caidan_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_home_page_caidan_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_home_page_caidan_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_home_page_caidan_main_main_checked.set_text_font(lv.font_montserrat_16)
style_home_page_caidan_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_home_page_caidan_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_home_page_caidan_main_main_checked.set_img_recolor_opa(0)
style_home_page_caidan_main_main_checked.set_img_opa(255)

# add style for home_page_caidan
home_page_caidan.add_style(style_home_page_caidan_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

home_page_data_miao = lv.spangroup(home_page)
home_page_data_miao.set_pos(int(194),int(86))
home_page_data_miao.set_size(30,20)
home_page_data_miao.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_data_miao.set_align(lv.TEXT_ALIGN.LEFT)
home_page_data_miao.set_overflow(lv.SPAN_OVERFLOW.CLIP)
home_page_data_miao.set_mode(lv.SPAN_MODE.BREAK)
home_page_data_miao_span = home_page_data_miao.new_span()
home_page_data_miao_span.set_text("20")
home_page_data_miao_span.style.set_text_color(lv.color_make(0xff,0xff,0xff))
home_page_data_miao_span.style.set_text_decor(lv.TEXT_DECOR.NONE)
try:
    home_page_data_miao_span.style.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        home_page_data_miao_span.style.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        home_page_data_miao_span.style.set_text_font(lv.font_montserrat_16)
home_page_data_miao.refr_mode()
# create style style_home_page_data_miao_main_main_default
style_home_page_data_miao_main_main_default = lv.style_t()
style_home_page_data_miao_main_main_default.init()
style_home_page_data_miao_main_main_default.set_radius(0)
style_home_page_data_miao_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_miao_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_miao_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_page_data_miao_main_main_default.set_bg_opa(0)
style_home_page_data_miao_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_home_page_data_miao_main_main_default.set_border_width(0)
style_home_page_data_miao_main_main_default.set_border_opa(255)
style_home_page_data_miao_main_main_default.set_pad_left(0)
style_home_page_data_miao_main_main_default.set_pad_right(0)
style_home_page_data_miao_main_main_default.set_pad_top(0)
style_home_page_data_miao_main_main_default.set_pad_bottom(0)

# add style for home_page_data_miao
home_page_data_miao.add_style(style_home_page_data_miao_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_data_haiba = lv.spangroup(home_page)
home_page_data_haiba.set_pos(int(173),int(161))
home_page_data_haiba.set_size(66,18)
home_page_data_haiba.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_data_haiba.set_align(lv.TEXT_ALIGN.LEFT)
home_page_data_haiba.set_overflow(lv.SPAN_OVERFLOW.CLIP)
home_page_data_haiba.set_mode(lv.SPAN_MODE.BREAK)
home_page_data_haiba_span = home_page_data_haiba.new_span()
home_page_data_haiba_span.set_text("100m")
home_page_data_haiba_span.style.set_text_color(lv.color_make(0xff,0xff,0xff))
home_page_data_haiba_span.style.set_text_decor(lv.TEXT_DECOR.NONE)
try:
    home_page_data_haiba_span.style.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        home_page_data_haiba_span.style.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        home_page_data_haiba_span.style.set_text_font(lv.font_montserrat_16)
home_page_data_haiba.refr_mode()
# create style style_home_page_data_haiba_main_main_default
style_home_page_data_haiba_main_main_default = lv.style_t()
style_home_page_data_haiba_main_main_default.init()
style_home_page_data_haiba_main_main_default.set_radius(0)
style_home_page_data_haiba_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_haiba_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_data_haiba_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_page_data_haiba_main_main_default.set_bg_opa(0)
style_home_page_data_haiba_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_home_page_data_haiba_main_main_default.set_border_width(0)
style_home_page_data_haiba_main_main_default.set_border_opa(255)
style_home_page_data_haiba_main_main_default.set_pad_left(0)
style_home_page_data_haiba_main_main_default.set_pad_right(0)
style_home_page_data_haiba_main_main_default.set_pad_top(0)
style_home_page_data_haiba_main_main_default.set_pad_bottom(0)

# add style for home_page_data_haiba
home_page_data_haiba.add_style(style_home_page_data_haiba_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

home_page_spangroup_1 = lv.spangroup(home_page)
home_page_spangroup_1.set_pos(int(150),int(135))
home_page_spangroup_1.set_size(69,20)
home_page_spangroup_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
home_page_spangroup_1.set_align(lv.TEXT_ALIGN.LEFT)
home_page_spangroup_1.set_overflow(lv.SPAN_OVERFLOW.CLIP)
home_page_spangroup_1.set_mode(lv.SPAN_MODE.BREAK)
home_page_spangroup_1_span = home_page_spangroup_1.new_span()
home_page_spangroup_1_span.set_text("海 拔")
home_page_spangroup_1_span.style.set_text_color(lv.color_make(0xff,0xff,0xff))
home_page_spangroup_1_span.style.set_text_decor(lv.TEXT_DECOR.NONE)
try:
    home_page_spangroup_1_span.style.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        home_page_spangroup_1_span.style.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        home_page_spangroup_1_span.style.set_text_font(lv.font_montserrat_16)
home_page_spangroup_1.refr_mode()
# create style style_home_page_spangroup_1_main_main_default
style_home_page_spangroup_1_main_main_default = lv.style_t()
style_home_page_spangroup_1_main_main_default.init()
style_home_page_spangroup_1_main_main_default.set_radius(0)
style_home_page_spangroup_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_spangroup_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_home_page_spangroup_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_home_page_spangroup_1_main_main_default.set_bg_opa(0)
style_home_page_spangroup_1_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_home_page_spangroup_1_main_main_default.set_border_width(0)
style_home_page_spangroup_1_main_main_default.set_border_opa(255)
style_home_page_spangroup_1_main_main_default.set_pad_left(0)
style_home_page_spangroup_1_main_main_default.set_pad_right(0)
style_home_page_spangroup_1_main_main_default.set_pad_top(0)
style_home_page_spangroup_1_main_main_default.set_pad_bottom(0)

# add style for home_page_spangroup_1
home_page_spangroup_1.add_style(style_home_page_spangroup_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Caidan_page = lv.obj()
Caidan_page.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_caidan_page_main_main_default
style_caidan_page_main_main_default = lv.style_t()
style_caidan_page_main_main_default.init()
style_caidan_page_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_caidan_page_main_main_default.set_bg_opa(0)

# add style for Caidan_page
Caidan_page.add_style(style_caidan_page_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

Caidan_page_tileview_1 = lv.tileview(Caidan_page)
Caidan_page_tileview_1.set_pos(int(0),int(0))
Caidan_page_tileview_1.set_size(240,280)
Caidan_page_tileview_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
tileview_1_name_1 = Caidan_page_tileview_1.add_tile(0, 0, lv.DIR.BOTTOM)
Caidan_page_miaobiao_e = lv.imgbtn(tileview_1_name_1)
Caidan_page_miaobiao_e.set_pos(int(5),int(210))
Caidan_page_miaobiao_e.set_size(140,65)
Caidan_page_miaobiao_e.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)





Caidan_page_miaobiao_e_label = lv.label(Caidan_page_miaobiao_e)
Caidan_page_miaobiao_e_label.set_text("秒表")
Caidan_page_miaobiao_e.set_style_pad_all(0, lv.STATE.ANY)
Caidan_page_miaobiao_e_label.align(lv.ALIGN.RIGHT_MID,0,0)
# create style style_caidan_page_miaobiao_e_main_main_default
style_caidan_page_miaobiao_e_main_main_default = lv.style_t()
style_caidan_page_miaobiao_e_main_main_default.init()
style_caidan_page_miaobiao_e_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_caidan_page_miaobiao_e_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_caidan_page_miaobiao_e_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_caidan_page_miaobiao_e_main_main_default.set_text_font(lv.font_montserrat_16)
style_caidan_page_miaobiao_e_main_main_default.set_text_align(lv.TEXT_ALIGN.RIGHT)
style_caidan_page_miaobiao_e_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_caidan_page_miaobiao_e_main_main_default.set_img_recolor_opa(0)
style_caidan_page_miaobiao_e_main_main_default.set_img_opa(0)

# add style for Caidan_page_miaobiao_e
Caidan_page_miaobiao_e.add_style(style_caidan_page_miaobiao_e_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_caidan_page_miaobiao_e_main_main_pressed
style_caidan_page_miaobiao_e_main_main_pressed = lv.style_t()
style_caidan_page_miaobiao_e_main_main_pressed.init()
style_caidan_page_miaobiao_e_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_caidan_page_miaobiao_e_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_caidan_page_miaobiao_e_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_caidan_page_miaobiao_e_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_caidan_page_miaobiao_e_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_miaobiao_e_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_caidan_page_miaobiao_e_main_main_pressed.set_img_recolor_opa(0)
style_caidan_page_miaobiao_e_main_main_pressed.set_img_opa(255)

# add style for Caidan_page_miaobiao_e
Caidan_page_miaobiao_e.add_style(style_caidan_page_miaobiao_e_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_caidan_page_miaobiao_e_main_main_checked
style_caidan_page_miaobiao_e_main_main_checked = lv.style_t()
style_caidan_page_miaobiao_e_main_main_checked.init()
style_caidan_page_miaobiao_e_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_caidan_page_miaobiao_e_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_caidan_page_miaobiao_e_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_caidan_page_miaobiao_e_main_main_checked.set_text_font(lv.font_montserrat_16)
style_caidan_page_miaobiao_e_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_miaobiao_e_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_caidan_page_miaobiao_e_main_main_checked.set_img_recolor_opa(0)
style_caidan_page_miaobiao_e_main_main_checked.set_img_opa(255)

# add style for Caidan_page_miaobiao_e
Caidan_page_miaobiao_e.add_style(style_caidan_page_miaobiao_e_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

Caidan_page_jisuan_e = lv.imgbtn(tileview_1_name_1)
Caidan_page_jisuan_e.set_pos(int(5),int(75))
Caidan_page_jisuan_e.set_size(150,65)
Caidan_page_jisuan_e.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)





Caidan_page_jisuan_e_label = lv.label(Caidan_page_jisuan_e)
Caidan_page_jisuan_e_label.set_text("计算器")
Caidan_page_jisuan_e.set_style_pad_all(0, lv.STATE.ANY)
Caidan_page_jisuan_e_label.align(lv.ALIGN.RIGHT_MID,0,0)
# create style style_caidan_page_jisuan_e_main_main_default
style_caidan_page_jisuan_e_main_main_default = lv.style_t()
style_caidan_page_jisuan_e_main_main_default.init()
style_caidan_page_jisuan_e_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_caidan_page_jisuan_e_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_caidan_page_jisuan_e_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_caidan_page_jisuan_e_main_main_default.set_text_font(lv.font_montserrat_16)
style_caidan_page_jisuan_e_main_main_default.set_text_align(lv.TEXT_ALIGN.RIGHT)
style_caidan_page_jisuan_e_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_caidan_page_jisuan_e_main_main_default.set_img_recolor_opa(0)
style_caidan_page_jisuan_e_main_main_default.set_img_opa(0)

# add style for Caidan_page_jisuan_e
Caidan_page_jisuan_e.add_style(style_caidan_page_jisuan_e_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_caidan_page_jisuan_e_main_main_pressed
style_caidan_page_jisuan_e_main_main_pressed = lv.style_t()
style_caidan_page_jisuan_e_main_main_pressed.init()
style_caidan_page_jisuan_e_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_caidan_page_jisuan_e_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_caidan_page_jisuan_e_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_caidan_page_jisuan_e_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_caidan_page_jisuan_e_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_jisuan_e_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_caidan_page_jisuan_e_main_main_pressed.set_img_recolor_opa(0)
style_caidan_page_jisuan_e_main_main_pressed.set_img_opa(255)

# add style for Caidan_page_jisuan_e
Caidan_page_jisuan_e.add_style(style_caidan_page_jisuan_e_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_caidan_page_jisuan_e_main_main_checked
style_caidan_page_jisuan_e_main_main_checked = lv.style_t()
style_caidan_page_jisuan_e_main_main_checked.init()
style_caidan_page_jisuan_e_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_caidan_page_jisuan_e_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_caidan_page_jisuan_e_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_caidan_page_jisuan_e_main_main_checked.set_text_font(lv.font_montserrat_16)
style_caidan_page_jisuan_e_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_jisuan_e_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_caidan_page_jisuan_e_main_main_checked.set_img_recolor_opa(0)
style_caidan_page_jisuan_e_main_main_checked.set_img_opa(255)

# add style for Caidan_page_jisuan_e
Caidan_page_jisuan_e.add_style(style_caidan_page_jisuan_e_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

Caidan_page_zhinan_e = lv.imgbtn(tileview_1_name_1)
Caidan_page_zhinan_e.set_pos(int(5),int(145))
Caidan_page_zhinan_e.set_size(150,65)
Caidan_page_zhinan_e.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)





Caidan_page_zhinan_e_label = lv.label(Caidan_page_zhinan_e)
Caidan_page_zhinan_e_label.set_text("指南针")
Caidan_page_zhinan_e.set_style_pad_all(0, lv.STATE.ANY)
Caidan_page_zhinan_e_label.align(lv.ALIGN.RIGHT_MID,0,0)
# create style style_caidan_page_zhinan_e_main_main_default
style_caidan_page_zhinan_e_main_main_default = lv.style_t()
style_caidan_page_zhinan_e_main_main_default.init()
style_caidan_page_zhinan_e_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_caidan_page_zhinan_e_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_caidan_page_zhinan_e_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_caidan_page_zhinan_e_main_main_default.set_text_font(lv.font_montserrat_16)
style_caidan_page_zhinan_e_main_main_default.set_text_align(lv.TEXT_ALIGN.RIGHT)
style_caidan_page_zhinan_e_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_caidan_page_zhinan_e_main_main_default.set_img_recolor_opa(0)
style_caidan_page_zhinan_e_main_main_default.set_img_opa(0)

# add style for Caidan_page_zhinan_e
Caidan_page_zhinan_e.add_style(style_caidan_page_zhinan_e_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_caidan_page_zhinan_e_main_main_pressed
style_caidan_page_zhinan_e_main_main_pressed = lv.style_t()
style_caidan_page_zhinan_e_main_main_pressed.init()
style_caidan_page_zhinan_e_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_caidan_page_zhinan_e_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_caidan_page_zhinan_e_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_caidan_page_zhinan_e_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_caidan_page_zhinan_e_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_zhinan_e_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_caidan_page_zhinan_e_main_main_pressed.set_img_recolor_opa(0)
style_caidan_page_zhinan_e_main_main_pressed.set_img_opa(255)

# add style for Caidan_page_zhinan_e
Caidan_page_zhinan_e.add_style(style_caidan_page_zhinan_e_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_caidan_page_zhinan_e_main_main_checked
style_caidan_page_zhinan_e_main_main_checked = lv.style_t()
style_caidan_page_zhinan_e_main_main_checked.init()
style_caidan_page_zhinan_e_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_caidan_page_zhinan_e_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_caidan_page_zhinan_e_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_caidan_page_zhinan_e_main_main_checked.set_text_font(lv.font_montserrat_16)
style_caidan_page_zhinan_e_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_zhinan_e_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_caidan_page_zhinan_e_main_main_checked.set_img_recolor_opa(0)
style_caidan_page_zhinan_e_main_main_checked.set_img_opa(255)

# add style for Caidan_page_zhinan_e
Caidan_page_zhinan_e.add_style(style_caidan_page_zhinan_e_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

Caidan_page_rili_e = lv.imgbtn(tileview_1_name_1)
Caidan_page_rili_e.set_pos(int(5),int(5))
Caidan_page_rili_e.set_size(140,65)
Caidan_page_rili_e.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)





Caidan_page_rili_e_label = lv.label(Caidan_page_rili_e)
Caidan_page_rili_e_label.set_text("日历")
Caidan_page_rili_e.set_style_pad_all(0, lv.STATE.ANY)
Caidan_page_rili_e_label.align(lv.ALIGN.RIGHT_MID,0,0)
# create style style_caidan_page_rili_e_main_main_default
style_caidan_page_rili_e_main_main_default = lv.style_t()
style_caidan_page_rili_e_main_main_default.init()
style_caidan_page_rili_e_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_caidan_page_rili_e_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_caidan_page_rili_e_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_caidan_page_rili_e_main_main_default.set_text_font(lv.font_montserrat_16)
style_caidan_page_rili_e_main_main_default.set_text_align(lv.TEXT_ALIGN.RIGHT)
style_caidan_page_rili_e_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_caidan_page_rili_e_main_main_default.set_img_recolor_opa(0)
style_caidan_page_rili_e_main_main_default.set_img_opa(0)

# add style for Caidan_page_rili_e
Caidan_page_rili_e.add_style(style_caidan_page_rili_e_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_caidan_page_rili_e_main_main_pressed
style_caidan_page_rili_e_main_main_pressed = lv.style_t()
style_caidan_page_rili_e_main_main_pressed.init()
style_caidan_page_rili_e_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_caidan_page_rili_e_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_caidan_page_rili_e_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_caidan_page_rili_e_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_caidan_page_rili_e_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_rili_e_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_caidan_page_rili_e_main_main_pressed.set_img_recolor_opa(0)
style_caidan_page_rili_e_main_main_pressed.set_img_opa(255)

# add style for Caidan_page_rili_e
Caidan_page_rili_e.add_style(style_caidan_page_rili_e_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_caidan_page_rili_e_main_main_checked
style_caidan_page_rili_e_main_main_checked = lv.style_t()
style_caidan_page_rili_e_main_main_checked.init()
style_caidan_page_rili_e_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_caidan_page_rili_e_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_caidan_page_rili_e_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_caidan_page_rili_e_main_main_checked.set_text_font(lv.font_montserrat_16)
style_caidan_page_rili_e_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_rili_e_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_caidan_page_rili_e_main_main_checked.set_img_recolor_opa(0)
style_caidan_page_rili_e_main_main_checked.set_img_opa(255)

# add style for Caidan_page_rili_e
Caidan_page_rili_e.add_style(style_caidan_page_rili_e_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

tileview_1_name_2 = Caidan_page_tileview_1.add_tile(0 , 1, lv.DIR.TOP)
Caidan_page_imgbtn_3 = lv.imgbtn(tileview_1_name_2)
Caidan_page_imgbtn_3.set_pos(int(5),int(145))
Caidan_page_imgbtn_3.set_size(230,65)
Caidan_page_imgbtn_3.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)





Caidan_page_imgbtn_3_label = lv.label(Caidan_page_imgbtn_3)
Caidan_page_imgbtn_3_label.set_text("常量时间")
Caidan_page_imgbtn_3.set_style_pad_all(0, lv.STATE.ANY)
Caidan_page_imgbtn_3_label.align(lv.ALIGN.CENTER,0,0)
# create style style_caidan_page_imgbtn_3_main_main_default
style_caidan_page_imgbtn_3_main_main_default = lv.style_t()
style_caidan_page_imgbtn_3_main_main_default.init()
style_caidan_page_imgbtn_3_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_caidan_page_imgbtn_3_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_caidan_page_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_caidan_page_imgbtn_3_main_main_default.set_text_font(lv.font_montserrat_16)
style_caidan_page_imgbtn_3_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_imgbtn_3_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_caidan_page_imgbtn_3_main_main_default.set_img_recolor_opa(0)
style_caidan_page_imgbtn_3_main_main_default.set_img_opa(255)

# add style for Caidan_page_imgbtn_3
Caidan_page_imgbtn_3.add_style(style_caidan_page_imgbtn_3_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_caidan_page_imgbtn_3_main_main_pressed
style_caidan_page_imgbtn_3_main_main_pressed = lv.style_t()
style_caidan_page_imgbtn_3_main_main_pressed.init()
style_caidan_page_imgbtn_3_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_caidan_page_imgbtn_3_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_caidan_page_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_caidan_page_imgbtn_3_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_caidan_page_imgbtn_3_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_imgbtn_3_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_caidan_page_imgbtn_3_main_main_pressed.set_img_recolor_opa(0)
style_caidan_page_imgbtn_3_main_main_pressed.set_img_opa(255)

# add style for Caidan_page_imgbtn_3
Caidan_page_imgbtn_3.add_style(style_caidan_page_imgbtn_3_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_caidan_page_imgbtn_3_main_main_checked
style_caidan_page_imgbtn_3_main_main_checked = lv.style_t()
style_caidan_page_imgbtn_3_main_main_checked.init()
style_caidan_page_imgbtn_3_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_caidan_page_imgbtn_3_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_caidan_page_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_caidan_page_imgbtn_3_main_main_checked.set_text_font(lv.font_montserrat_16)
style_caidan_page_imgbtn_3_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_imgbtn_3_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_caidan_page_imgbtn_3_main_main_checked.set_img_recolor_opa(0)
style_caidan_page_imgbtn_3_main_main_checked.set_img_opa(255)

# add style for Caidan_page_imgbtn_3
Caidan_page_imgbtn_3.add_style(style_caidan_page_imgbtn_3_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

Caidan_page_imgbtn_2 = lv.imgbtn(tileview_1_name_2)
Caidan_page_imgbtn_2.set_pos(int(5),int(75))
Caidan_page_imgbtn_2.set_size(230,65)
Caidan_page_imgbtn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)





Caidan_page_imgbtn_2_label = lv.label(Caidan_page_imgbtn_2)
Caidan_page_imgbtn_2_label.set_text("息屏时间")
Caidan_page_imgbtn_2.set_style_pad_all(0, lv.STATE.ANY)
Caidan_page_imgbtn_2_label.align(lv.ALIGN.CENTER,0,0)
# create style style_caidan_page_imgbtn_2_main_main_default
style_caidan_page_imgbtn_2_main_main_default = lv.style_t()
style_caidan_page_imgbtn_2_main_main_default.init()
style_caidan_page_imgbtn_2_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_caidan_page_imgbtn_2_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_caidan_page_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_caidan_page_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_caidan_page_imgbtn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_imgbtn_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_caidan_page_imgbtn_2_main_main_default.set_img_recolor_opa(0)
style_caidan_page_imgbtn_2_main_main_default.set_img_opa(255)

# add style for Caidan_page_imgbtn_2
Caidan_page_imgbtn_2.add_style(style_caidan_page_imgbtn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_caidan_page_imgbtn_2_main_main_pressed
style_caidan_page_imgbtn_2_main_main_pressed = lv.style_t()
style_caidan_page_imgbtn_2_main_main_pressed.init()
style_caidan_page_imgbtn_2_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_caidan_page_imgbtn_2_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_caidan_page_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_caidan_page_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_caidan_page_imgbtn_2_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_imgbtn_2_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_caidan_page_imgbtn_2_main_main_pressed.set_img_recolor_opa(0)
style_caidan_page_imgbtn_2_main_main_pressed.set_img_opa(255)

# add style for Caidan_page_imgbtn_2
Caidan_page_imgbtn_2.add_style(style_caidan_page_imgbtn_2_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_caidan_page_imgbtn_2_main_main_checked
style_caidan_page_imgbtn_2_main_main_checked = lv.style_t()
style_caidan_page_imgbtn_2_main_main_checked.init()
style_caidan_page_imgbtn_2_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_caidan_page_imgbtn_2_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_caidan_page_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_caidan_page_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_16)
style_caidan_page_imgbtn_2_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_imgbtn_2_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_caidan_page_imgbtn_2_main_main_checked.set_img_recolor_opa(0)
style_caidan_page_imgbtn_2_main_main_checked.set_img_opa(255)

# add style for Caidan_page_imgbtn_2
Caidan_page_imgbtn_2.add_style(style_caidan_page_imgbtn_2_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

Caidan_page_imgbtn_1 = lv.imgbtn(tileview_1_name_2)
Caidan_page_imgbtn_1.set_pos(int(5),int(5))
Caidan_page_imgbtn_1.set_size(230,65)
Caidan_page_imgbtn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)





Caidan_page_imgbtn_1_label = lv.label(Caidan_page_imgbtn_1)
Caidan_page_imgbtn_1_label.set_text("抬腕亮屏")
Caidan_page_imgbtn_1.set_style_pad_all(0, lv.STATE.ANY)
Caidan_page_imgbtn_1_label.align(lv.ALIGN.CENTER,0,0)
# create style style_caidan_page_imgbtn_1_main_main_default
style_caidan_page_imgbtn_1_main_main_default = lv.style_t()
style_caidan_page_imgbtn_1_main_main_default.init()
style_caidan_page_imgbtn_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_caidan_page_imgbtn_1_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_caidan_page_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_caidan_page_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_caidan_page_imgbtn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_imgbtn_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_caidan_page_imgbtn_1_main_main_default.set_img_recolor_opa(0)
style_caidan_page_imgbtn_1_main_main_default.set_img_opa(255)

# add style for Caidan_page_imgbtn_1
Caidan_page_imgbtn_1.add_style(style_caidan_page_imgbtn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_caidan_page_imgbtn_1_main_main_pressed
style_caidan_page_imgbtn_1_main_main_pressed = lv.style_t()
style_caidan_page_imgbtn_1_main_main_pressed.init()
style_caidan_page_imgbtn_1_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_caidan_page_imgbtn_1_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_caidan_page_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_caidan_page_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_caidan_page_imgbtn_1_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_imgbtn_1_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_caidan_page_imgbtn_1_main_main_pressed.set_img_recolor_opa(0)
style_caidan_page_imgbtn_1_main_main_pressed.set_img_opa(255)

# add style for Caidan_page_imgbtn_1
Caidan_page_imgbtn_1.add_style(style_caidan_page_imgbtn_1_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_caidan_page_imgbtn_1_main_main_checked
style_caidan_page_imgbtn_1_main_main_checked = lv.style_t()
style_caidan_page_imgbtn_1_main_main_checked.init()
style_caidan_page_imgbtn_1_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_caidan_page_imgbtn_1_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_caidan_page_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_caidan_page_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_16)
style_caidan_page_imgbtn_1_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_caidan_page_imgbtn_1_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_caidan_page_imgbtn_1_main_main_checked.set_img_recolor_opa(0)
style_caidan_page_imgbtn_1_main_main_checked.set_img_opa(255)

# add style for Caidan_page_imgbtn_1
Caidan_page_imgbtn_1.add_style(style_caidan_page_imgbtn_1_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

Caidan_page_roller_2 = lv.roller(tileview_1_name_2)
Caidan_page_roller_2.set_pos(int(175),int(157))
Caidan_page_roller_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Caidan_page_roller_2.set_options("5\n10\n15\n20\n25", lv.roller.MODE.INFINITE)
Caidan_page_roller_2.set_visible_row_count(1)
# create style style_caidan_page_roller_2_main_main_default
style_caidan_page_roller_2_main_main_default = lv.style_t()
style_caidan_page_roller_2_main_main_default.init()
style_caidan_page_roller_2_main_main_default.set_radius(5)
style_caidan_page_roller_2_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_caidan_page_roller_2_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_caidan_page_roller_2_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_caidan_page_roller_2_main_main_default.set_bg_opa(255)
style_caidan_page_roller_2_main_main_default.set_border_color(lv.color_make(0xe6,0xe6,0xe6))
style_caidan_page_roller_2_main_main_default.set_border_width(2)
style_caidan_page_roller_2_main_main_default.set_border_opa(255)
style_caidan_page_roller_2_main_main_default.set_text_color(lv.color_make(0x33,0x33,0x33))
try:
    style_caidan_page_roller_2_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_caidan_page_roller_2_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_caidan_page_roller_2_main_main_default.set_text_font(lv.font_montserrat_16)

# add style for Caidan_page_roller_2
Caidan_page_roller_2.add_style(style_caidan_page_roller_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_caidan_page_roller_2_main_selected_default
style_caidan_page_roller_2_main_selected_default = lv.style_t()
style_caidan_page_roller_2_main_selected_default.init()
style_caidan_page_roller_2_main_selected_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_caidan_page_roller_2_main_selected_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_caidan_page_roller_2_main_selected_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_caidan_page_roller_2_main_selected_default.set_bg_opa(255)
style_caidan_page_roller_2_main_selected_default.set_text_color(lv.color_make(0xFF,0xFF,0xFF))
try:
    style_caidan_page_roller_2_main_selected_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_caidan_page_roller_2_main_selected_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_caidan_page_roller_2_main_selected_default.set_text_font(lv.font_montserrat_16)

# add style for Caidan_page_roller_2
Caidan_page_roller_2.add_style(style_caidan_page_roller_2_main_selected_default, lv.PART.SELECTED|lv.STATE.DEFAULT)

Caidan_page_roller_1 = lv.roller(tileview_1_name_2)
Caidan_page_roller_1.set_pos(int(175),int(86))
Caidan_page_roller_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
Caidan_page_roller_1.set_options("5\n10\n15\n20\n25", lv.roller.MODE.INFINITE)
Caidan_page_roller_1.set_visible_row_count(1)
# create style style_caidan_page_roller_1_main_main_default
style_caidan_page_roller_1_main_main_default = lv.style_t()
style_caidan_page_roller_1_main_main_default.init()
style_caidan_page_roller_1_main_main_default.set_radius(5)
style_caidan_page_roller_1_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_caidan_page_roller_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_caidan_page_roller_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_caidan_page_roller_1_main_main_default.set_bg_opa(255)
style_caidan_page_roller_1_main_main_default.set_border_color(lv.color_make(0xe6,0xe6,0xe6))
style_caidan_page_roller_1_main_main_default.set_border_width(2)
style_caidan_page_roller_1_main_main_default.set_border_opa(255)
style_caidan_page_roller_1_main_main_default.set_text_color(lv.color_make(0x33,0x33,0x33))
try:
    style_caidan_page_roller_1_main_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_caidan_page_roller_1_main_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_caidan_page_roller_1_main_main_default.set_text_font(lv.font_montserrat_16)

# add style for Caidan_page_roller_1
Caidan_page_roller_1.add_style(style_caidan_page_roller_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_caidan_page_roller_1_main_selected_default
style_caidan_page_roller_1_main_selected_default = lv.style_t()
style_caidan_page_roller_1_main_selected_default.init()
style_caidan_page_roller_1_main_selected_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_caidan_page_roller_1_main_selected_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_caidan_page_roller_1_main_selected_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_caidan_page_roller_1_main_selected_default.set_bg_opa(255)
style_caidan_page_roller_1_main_selected_default.set_text_color(lv.color_make(0xFF,0xFF,0xFF))
try:
    style_caidan_page_roller_1_main_selected_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_caidan_page_roller_1_main_selected_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_caidan_page_roller_1_main_selected_default.set_text_font(lv.font_montserrat_16)

# add style for Caidan_page_roller_1
Caidan_page_roller_1.add_style(style_caidan_page_roller_1_main_selected_default, lv.PART.SELECTED|lv.STATE.DEFAULT)

Caidan_page_sw_1 = lv.switch(tileview_1_name_2)
Caidan_page_sw_1.set_pos(int(165),int(22))
Caidan_page_sw_1.set_size(66,31)
Caidan_page_sw_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_caidan_page_sw_1_main_main_default
style_caidan_page_sw_1_main_main_default = lv.style_t()
style_caidan_page_sw_1_main_main_default.init()
style_caidan_page_sw_1_main_main_default.set_radius(100)
style_caidan_page_sw_1_main_main_default.set_bg_color(lv.color_make(0xe6,0xe2,0xe6))
style_caidan_page_sw_1_main_main_default.set_bg_grad_color(lv.color_make(0xe6,0xe2,0xe6))
style_caidan_page_sw_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_caidan_page_sw_1_main_main_default.set_bg_opa(255)
style_caidan_page_sw_1_main_main_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_caidan_page_sw_1_main_main_default.set_border_width(0)
style_caidan_page_sw_1_main_main_default.set_border_opa(255)

# add style for Caidan_page_sw_1
Caidan_page_sw_1.add_style(style_caidan_page_sw_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_caidan_page_sw_1_main_indicator_checked
style_caidan_page_sw_1_main_indicator_checked = lv.style_t()
style_caidan_page_sw_1_main_indicator_checked.init()
style_caidan_page_sw_1_main_indicator_checked.set_bg_color(lv.color_make(0x2f,0xe4,0x87))
style_caidan_page_sw_1_main_indicator_checked.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_caidan_page_sw_1_main_indicator_checked.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_caidan_page_sw_1_main_indicator_checked.set_bg_opa(255)
style_caidan_page_sw_1_main_indicator_checked.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_caidan_page_sw_1_main_indicator_checked.set_border_width(0)
style_caidan_page_sw_1_main_indicator_checked.set_border_opa(255)

# add style for Caidan_page_sw_1
Caidan_page_sw_1.add_style(style_caidan_page_sw_1_main_indicator_checked, lv.PART.INDICATOR|lv.STATE.CHECKED)

# create style style_caidan_page_sw_1_main_knob_default
style_caidan_page_sw_1_main_knob_default = lv.style_t()
style_caidan_page_sw_1_main_knob_default.init()
style_caidan_page_sw_1_main_knob_default.set_radius(100)
style_caidan_page_sw_1_main_knob_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_caidan_page_sw_1_main_knob_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_caidan_page_sw_1_main_knob_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_caidan_page_sw_1_main_knob_default.set_bg_opa(255)
style_caidan_page_sw_1_main_knob_default.set_border_color(lv.color_make(0x21,0x95,0xf6))
style_caidan_page_sw_1_main_knob_default.set_border_width(0)
style_caidan_page_sw_1_main_knob_default.set_border_opa(255)

# add style for Caidan_page_sw_1
Caidan_page_sw_1.add_style(style_caidan_page_sw_1_main_knob_default, lv.PART.KNOB|lv.STATE.DEFAULT)

# create style style_caidan_page_tileview_1_main_main_default
style_caidan_page_tileview_1_main_main_default = lv.style_t()
style_caidan_page_tileview_1_main_main_default.init()
style_caidan_page_tileview_1_main_main_default.set_radius(0)
style_caidan_page_tileview_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_caidan_page_tileview_1_main_main_default.set_bg_grad_color(lv.color_make(0xf6,0xf6,0xf6))
style_caidan_page_tileview_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_caidan_page_tileview_1_main_main_default.set_bg_opa(255)

# add style for Caidan_page_tileview_1
Caidan_page_tileview_1.add_style(style_caidan_page_tileview_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_caidan_page_tileview_1_main_scrollbar_default
style_caidan_page_tileview_1_main_scrollbar_default = lv.style_t()
style_caidan_page_tileview_1_main_scrollbar_default.init()
style_caidan_page_tileview_1_main_scrollbar_default.set_radius(0)
style_caidan_page_tileview_1_main_scrollbar_default.set_bg_color(lv.color_make(0xea,0xef,0xf3))
style_caidan_page_tileview_1_main_scrollbar_default.set_bg_opa(255)

# add style for Caidan_page_tileview_1
Caidan_page_tileview_1.add_style(style_caidan_page_tileview_1_main_scrollbar_default, lv.PART.SCROLLBAR|lv.STATE.DEFAULT)

rili_page = lv.obj()
rili_page.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_rili_page_main_main_default
style_rili_page_main_main_default = lv.style_t()
style_rili_page_main_main_default.init()
style_rili_page_main_main_default.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_rili_page_main_main_default.set_bg_opa(0)

# add style for rili_page
rili_page.add_style(style_rili_page_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

rili_page_rili_task = lv.calendar(rili_page)
rili_page_rili_task.set_pos(int(0),int(0))
rili_page_rili_task.set_size(240,280)
rili_page_rili_task.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
rili_page_rili_task.set_today_date(time.localtime()[0], time.localtime()[1], time.localtime()[2])
rili_page_rili_task.set_showed_date(time.localtime()[0], time.localtime()[1])
highlighted_days=[
    lv.calendar_date_t({'year':2020, 'month':5, 'day':14})
]
rili_page_rili_task.set_highlighted_dates(highlighted_days, len(highlighted_days))
rili_page_rili_task_header = lv.calendar_header_arrow(rili_page_rili_task)
def style_rili_page_rili_task_extra_ctrl_day_names_items_default_event_cb(e):
    obj = lv.btnmatrix.__cast__(e.get_target())
    dsc = lv.obj_draw_part_dsc_t.__cast__(e.get_param())
    if dsc.id < 7:

        if dsc.label_dsc:
            dsc.label_dsc.color = lv.color_make(0xff,0xff,0xff)
            try:
                lv.font_montserrat_20
                dsc.label_dsc.font = lv.font_montserrat_20
            except AttributeError:
                try:
                    lv.font_montserrat_21
                    dsc.label_dsc.font = lv.font_montserrat_21
                except AttributeError:
                    dsc.label_dsc.font = lv.font_montserrat_16

rili_page_rili_task.get_btnmatrix().add_event_cb(style_rili_page_rili_task_extra_ctrl_day_names_items_default_event_cb, lv.EVENT.DRAW_PART_BEGIN, None)

def style_rili_page_rili_task_extra_ctrl_days_of_current_month_items_default_event_cb(e):
    obj = lv.btnmatrix.__cast__(e.get_target())
    dsc = lv.obj_draw_part_dsc_t.__cast__(e.get_param())
    if (dsc.id >= 7
        and not obj.has_btn_ctrl(dsc.id, lv.btnmatrix.CTRL.CUSTOM_1)
        and not obj.has_btn_ctrl(dsc.id, lv.btnmatrix.CTRL.CUSTOM_2)
        and not obj.has_btn_ctrl(dsc.id, lv.btnmatrix.CTRL.DISABLED)):
        dsc.rect_dsc.bg_color = lv.color_make(0x01,0xa2,0xb1)

        dsc.rect_dsc.bg_opa = 0
        dsc.rect_dsc.border_color = lv.color_make(0xff,0xff,0xff)
        dsc.rect_dsc.border_width = 1
        dsc.rect_dsc.border_opa = 255
        if dsc.label_dsc:
            dsc.label_dsc.color = lv.color_make(0xff,0xff,0xff)
            try:
                lv.font_montserrat_20
                dsc.label_dsc.font = lv.font_montserrat_20
            except AttributeError:
                try:
                    lv.font_montserrat_21
                    dsc.label_dsc.font = lv.font_montserrat_21
                except AttributeError:
                    dsc.label_dsc.font = lv.font_montserrat_16

rili_page_rili_task.get_btnmatrix().add_event_cb(style_rili_page_rili_task_extra_ctrl_days_of_current_month_items_default_event_cb, lv.EVENT.DRAW_PART_BEGIN, None)

def style_rili_page_rili_task_extra_ctrl_highlight_items_default_event_cb(e):
    obj = lv.btnmatrix.__cast__(e.get_target())
    dsc = lv.obj_draw_part_dsc_t.__cast__(e.get_param())
    if dsc.id >= 7 and obj.has_btn_ctrl(dsc.id, lv.btnmatrix.CTRL.CUSTOM_2):
        dsc.rect_dsc.bg_color = lv.color_make(0x00,0x1e,0xff)

        dsc.rect_dsc.bg_opa = 255
        if dsc.label_dsc:
            dsc.label_dsc.color = lv.color_make(0xff,0xff,0xff)
            try:
                lv.font_montserrat_20
                dsc.label_dsc.font = lv.font_montserrat_20
            except AttributeError:
                try:
                    lv.font_montserrat_21
                    dsc.label_dsc.font = lv.font_montserrat_21
                except AttributeError:
                    dsc.label_dsc.font = lv.font_montserrat_16

rili_page_rili_task.get_btnmatrix().add_event_cb(style_rili_page_rili_task_extra_ctrl_highlight_items_default_event_cb, lv.EVENT.DRAW_PART_BEGIN, None)

def style_rili_page_rili_task_extra_ctrl_today_items_default_event_cb(e):
    obj = lv.btnmatrix.__cast__(e.get_target())
    dsc = lv.obj_draw_part_dsc_t.__cast__(e.get_param())
    if dsc.id >= 7 and obj.has_btn_ctrl(dsc.id, lv.btnmatrix.CTRL.CUSTOM_1):
        dsc.rect_dsc.bg_color = lv.color_make(0x01,0xa2,0xb1)

        dsc.rect_dsc.bg_opa = 0
        dsc.rect_dsc.border_color = lv.color_make(0xff,0xff,0xff)
        dsc.rect_dsc.border_width = 1
        dsc.rect_dsc.border_opa = 255
        if dsc.label_dsc:
            dsc.label_dsc.color = lv.color_make(0xff,0xff,0xff)
            try:
                lv.font_montserrat_20
                dsc.label_dsc.font = lv.font_montserrat_20
            except AttributeError:
                try:
                    lv.font_montserrat_21
                    dsc.label_dsc.font = lv.font_montserrat_21
                except AttributeError:
                    dsc.label_dsc.font = lv.font_montserrat_16

rili_page_rili_task.get_btnmatrix().add_event_cb(style_rili_page_rili_task_extra_ctrl_today_items_default_event_cb, lv.EVENT.DRAW_PART_BEGIN, None)

def style_rili_page_rili_task_extra_ctrl_other_month_items_default_event_cb(e):
    obj = lv.btnmatrix.__cast__(e.get_target())
    dsc = lv.obj_draw_part_dsc_t.__cast__(e.get_param())
    if dsc.id >= 7 and obj.has_btn_ctrl(dsc.id, lv.btnmatrix.CTRL.DISABLED):
        dsc.rect_dsc.bg_color = lv.color_make(0x01,0xa2,0xb1)

        dsc.rect_dsc.bg_opa = 0
        if dsc.label_dsc:
            dsc.label_dsc.color = lv.color_make(0x68,0x55,0x55)
            try:
                lv.font_montserrat_20
                dsc.label_dsc.font = lv.font_montserrat_20
            except AttributeError:
                try:
                    lv.font_montserrat_21
                    dsc.label_dsc.font = lv.font_montserrat_21
                except AttributeError:
                    dsc.label_dsc.font = lv.font_montserrat_16

rili_page_rili_task.get_btnmatrix().add_event_cb(style_rili_page_rili_task_extra_ctrl_other_month_items_default_event_cb, lv.EVENT.DRAW_PART_BEGIN, None)

# create style style_rili_page_rili_task_extra_header_main_default
style_rili_page_rili_task_extra_header_main_default = lv.style_t()
style_rili_page_rili_task_extra_header_main_default.init()
style_rili_page_rili_task_extra_header_main_default.set_bg_color(lv.color_make(0x01,0x23,0x5b))
style_rili_page_rili_task_extra_header_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_rili_page_rili_task_extra_header_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_rili_page_rili_task_extra_header_main_default.set_bg_opa(255)
style_rili_page_rili_task_extra_header_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_rili_page_rili_task_extra_header_main_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_rili_page_rili_task_extra_header_main_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_rili_page_rili_task_extra_header_main_default.set_text_font(lv.font_montserrat_16)

# add style for rili_page_rili_task_header
rili_page_rili_task_header.add_style(style_rili_page_rili_task_extra_header_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_rili_page_rili_task_main_main_default
style_rili_page_rili_task_main_main_default = lv.style_t()
style_rili_page_rili_task_main_main_default.init()
style_rili_page_rili_task_main_main_default.set_radius(0)
style_rili_page_rili_task_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_rili_page_rili_task_main_main_default.set_bg_grad_color(lv.color_make(0xcb,0xc8,0xc8))
style_rili_page_rili_task_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_rili_page_rili_task_main_main_default.set_bg_opa(255)
style_rili_page_rili_task_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_rili_page_rili_task_main_main_default.set_border_width(0)
style_rili_page_rili_task_main_main_default.set_border_opa(255)

# add style for rili_page_rili_task
rili_page_rili_task.add_style(style_rili_page_rili_task_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_rili_page_rili_task_main_main_focused
style_rili_page_rili_task_main_main_focused = lv.style_t()
style_rili_page_rili_task_main_main_focused.init()
style_rili_page_rili_task_main_main_focused.set_radius(0)
style_rili_page_rili_task_main_main_focused.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_rili_page_rili_task_main_main_focused.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_rili_page_rili_task_main_main_focused.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_rili_page_rili_task_main_main_focused.set_bg_opa(255)
style_rili_page_rili_task_main_main_focused.set_border_color(lv.color_make(0xc0,0xc0,0xc0))
style_rili_page_rili_task_main_main_focused.set_border_width(1)
style_rili_page_rili_task_main_main_focused.set_border_opa(255)

# add style for rili_page_rili_task
rili_page_rili_task.add_style(style_rili_page_rili_task_main_main_focused, lv.PART.MAIN|lv.STATE.FOCUSED)

# create style style_rili_page_rili_task_main_main_disabled
style_rili_page_rili_task_main_main_disabled = lv.style_t()
style_rili_page_rili_task_main_main_disabled.init()
style_rili_page_rili_task_main_main_disabled.set_radius(0)
style_rili_page_rili_task_main_main_disabled.set_bg_color(lv.color_make(0xff,0xff,0xff))
style_rili_page_rili_task_main_main_disabled.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_rili_page_rili_task_main_main_disabled.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_rili_page_rili_task_main_main_disabled.set_bg_opa(255)
style_rili_page_rili_task_main_main_disabled.set_border_color(lv.color_make(0xc0,0xc0,0xc0))
style_rili_page_rili_task_main_main_disabled.set_border_width(1)
style_rili_page_rili_task_main_main_disabled.set_border_opa(255)

# add style for rili_page_rili_task
rili_page_rili_task.add_style(style_rili_page_rili_task_main_main_disabled, lv.PART.MAIN|lv.STATE.DISABLED)

miaobia_page = lv.obj()
miaobia_page.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_miaobia_page_main_main_default
style_miaobia_page_main_main_default = lv.style_t()
style_miaobia_page_main_main_default.init()
style_miaobia_page_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_miaobia_page_main_main_default.set_bg_opa(255)

# add style for miaobia_page
miaobia_page.add_style(style_miaobia_page_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

miaobia_page_imgbtn_1 = lv.imgbtn(miaobia_page)
miaobia_page_imgbtn_1.set_pos(int(140),int(180))
miaobia_page_imgbtn_1.set_size(40,40)
miaobia_page_imgbtn_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp1450870190.png','rb') as f:
        miaobia_page_imgbtn_1_imgReleased_data = f.read()
except:
    print('Could not open D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp1450870190.png')
    sys.exit()

miaobia_page_imgbtn_1_imgReleased = lv.img_dsc_t({
  'data_size': len(miaobia_page_imgbtn_1_imgReleased_data),
  'header': {'always_zero': 0, 'w': 40, 'h': 40, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': miaobia_page_imgbtn_1_imgReleased_data
})
miaobia_page_imgbtn_1.set_src(lv.imgbtn.STATE.RELEASED, miaobia_page_imgbtn_1_imgReleased, None, None)



try:
    with open('D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp520100900.png','rb') as f:
        miaobia_page_imgbtn_1_imgCheckedReleased_data = f.read()
except:
    print('Could not open D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp520100900.png')
    sys.exit()

miaobia_page_imgbtn_1_imgCheckedReleased = lv.img_dsc_t({
  'data_size': len(miaobia_page_imgbtn_1_imgCheckedReleased_data),
  'header': {'always_zero': 0, 'w': 40, 'h': 40, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': miaobia_page_imgbtn_1_imgCheckedReleased_data
})
miaobia_page_imgbtn_1.set_src(lv.imgbtn.STATE.CHECKED_RELEASED, miaobia_page_imgbtn_1_imgCheckedReleased, None, None)


miaobia_page_imgbtn_1.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_miaobia_page_imgbtn_1_main_main_default
style_miaobia_page_imgbtn_1_main_main_default = lv.style_t()
style_miaobia_page_imgbtn_1_main_main_default.init()
style_miaobia_page_imgbtn_1_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_miaobia_page_imgbtn_1_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_miaobia_page_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_miaobia_page_imgbtn_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_miaobia_page_imgbtn_1_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_miaobia_page_imgbtn_1_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_miaobia_page_imgbtn_1_main_main_default.set_img_recolor_opa(0)
style_miaobia_page_imgbtn_1_main_main_default.set_img_opa(255)

# add style for miaobia_page_imgbtn_1
miaobia_page_imgbtn_1.add_style(style_miaobia_page_imgbtn_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_miaobia_page_imgbtn_1_main_main_pressed
style_miaobia_page_imgbtn_1_main_main_pressed = lv.style_t()
style_miaobia_page_imgbtn_1_main_main_pressed.init()
style_miaobia_page_imgbtn_1_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_miaobia_page_imgbtn_1_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_miaobia_page_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_miaobia_page_imgbtn_1_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_miaobia_page_imgbtn_1_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_miaobia_page_imgbtn_1_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_miaobia_page_imgbtn_1_main_main_pressed.set_img_recolor_opa(0)
style_miaobia_page_imgbtn_1_main_main_pressed.set_img_opa(255)

# add style for miaobia_page_imgbtn_1
miaobia_page_imgbtn_1.add_style(style_miaobia_page_imgbtn_1_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_miaobia_page_imgbtn_1_main_main_checked
style_miaobia_page_imgbtn_1_main_main_checked = lv.style_t()
style_miaobia_page_imgbtn_1_main_main_checked.init()
style_miaobia_page_imgbtn_1_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_miaobia_page_imgbtn_1_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_miaobia_page_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_miaobia_page_imgbtn_1_main_main_checked.set_text_font(lv.font_montserrat_16)
style_miaobia_page_imgbtn_1_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_miaobia_page_imgbtn_1_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_miaobia_page_imgbtn_1_main_main_checked.set_img_recolor_opa(0)
style_miaobia_page_imgbtn_1_main_main_checked.set_img_opa(255)

# add style for miaobia_page_imgbtn_1
miaobia_page_imgbtn_1.add_style(style_miaobia_page_imgbtn_1_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

miaobia_page_data_miaobiao = lv.spangroup(miaobia_page)
miaobia_page_data_miaobiao.set_pos(int(38),int(102))
miaobia_page_data_miaobiao.set_size(165,36)
miaobia_page_data_miaobiao.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
miaobia_page_data_miaobiao.set_align(lv.TEXT_ALIGN.LEFT)
miaobia_page_data_miaobiao.set_overflow(lv.SPAN_OVERFLOW.CLIP)
miaobia_page_data_miaobiao.set_mode(lv.SPAN_MODE.BREAK)
miaobia_page_data_miaobiao_span = miaobia_page_data_miaobiao.new_span()
miaobia_page_data_miaobiao_span.set_text("00:00:00")
miaobia_page_data_miaobiao_span.style.set_text_color(lv.color_make(0xff,0xff,0xff))
miaobia_page_data_miaobiao_span.style.set_text_decor(lv.TEXT_DECOR.NONE)
try:
    miaobia_page_data_miaobiao_span.style.set_text_font(lv.font_simsun_40)
except AttributeError:
    try:
        miaobia_page_data_miaobiao_span.style.set_text_font(lv.font_montserrat_40)
    except AttributeError:
        miaobia_page_data_miaobiao_span.style.set_text_font(lv.font_montserrat_16)
miaobia_page_data_miaobiao.refr_mode()
# create style style_miaobia_page_data_miaobiao_main_main_default
style_miaobia_page_data_miaobiao_main_main_default = lv.style_t()
style_miaobia_page_data_miaobiao_main_main_default.init()
style_miaobia_page_data_miaobiao_main_main_default.set_radius(0)
style_miaobia_page_data_miaobiao_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_miaobia_page_data_miaobiao_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_miaobia_page_data_miaobiao_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_miaobia_page_data_miaobiao_main_main_default.set_bg_opa(0)
style_miaobia_page_data_miaobiao_main_main_default.set_border_color(lv.color_make(0x00,0x00,0x00))
style_miaobia_page_data_miaobiao_main_main_default.set_border_width(0)
style_miaobia_page_data_miaobiao_main_main_default.set_border_opa(255)
style_miaobia_page_data_miaobiao_main_main_default.set_pad_left(0)
style_miaobia_page_data_miaobiao_main_main_default.set_pad_right(0)
style_miaobia_page_data_miaobiao_main_main_default.set_pad_top(0)
style_miaobia_page_data_miaobiao_main_main_default.set_pad_bottom(0)

# add style for miaobia_page_data_miaobiao
miaobia_page_data_miaobiao.add_style(style_miaobia_page_data_miaobiao_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

miaobia_page_imgbtn_2 = lv.imgbtn(miaobia_page)
miaobia_page_imgbtn_2.set_pos(int(60),int(182))
miaobia_page_imgbtn_2.set_size(35,35)
miaobia_page_imgbtn_2.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
try:
    with open('D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp1592820265.png','rb') as f:
        miaobia_page_imgbtn_2_imgReleased_data = f.read()
except:
    print('Could not open D:\\aa\\f407UI\\home\\aaaa\\aaa\\aaa\\generated\\mPythonImages\\mp1592820265.png')
    sys.exit()

miaobia_page_imgbtn_2_imgReleased = lv.img_dsc_t({
  'data_size': len(miaobia_page_imgbtn_2_imgReleased_data),
  'header': {'always_zero': 0, 'w': 35, 'h': 35, 'cf': lv.img.CF.TRUE_COLOR_ALPHA},
  'data': miaobia_page_imgbtn_2_imgReleased_data
})
miaobia_page_imgbtn_2.set_src(lv.imgbtn.STATE.RELEASED, miaobia_page_imgbtn_2_imgReleased, None, None)





miaobia_page_imgbtn_2.add_flag(lv.obj.FLAG.CHECKABLE)
# create style style_miaobia_page_imgbtn_2_main_main_default
style_miaobia_page_imgbtn_2_main_main_default = lv.style_t()
style_miaobia_page_imgbtn_2_main_main_default.init()
style_miaobia_page_imgbtn_2_main_main_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_miaobia_page_imgbtn_2_main_main_default.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_miaobia_page_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_miaobia_page_imgbtn_2_main_main_default.set_text_font(lv.font_montserrat_16)
style_miaobia_page_imgbtn_2_main_main_default.set_text_align(lv.TEXT_ALIGN.CENTER)
style_miaobia_page_imgbtn_2_main_main_default.set_img_recolor(lv.color_make(0xff,0xff,0xff))
style_miaobia_page_imgbtn_2_main_main_default.set_img_recolor_opa(0)
style_miaobia_page_imgbtn_2_main_main_default.set_img_opa(255)

# add style for miaobia_page_imgbtn_2
miaobia_page_imgbtn_2.add_style(style_miaobia_page_imgbtn_2_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_miaobia_page_imgbtn_2_main_main_pressed
style_miaobia_page_imgbtn_2_main_main_pressed = lv.style_t()
style_miaobia_page_imgbtn_2_main_main_pressed.init()
style_miaobia_page_imgbtn_2_main_main_pressed.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_miaobia_page_imgbtn_2_main_main_pressed.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_miaobia_page_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_miaobia_page_imgbtn_2_main_main_pressed.set_text_font(lv.font_montserrat_16)
style_miaobia_page_imgbtn_2_main_main_pressed.set_text_align(lv.TEXT_ALIGN.CENTER)
style_miaobia_page_imgbtn_2_main_main_pressed.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_miaobia_page_imgbtn_2_main_main_pressed.set_img_recolor_opa(0)
style_miaobia_page_imgbtn_2_main_main_pressed.set_img_opa(255)

# add style for miaobia_page_imgbtn_2
miaobia_page_imgbtn_2.add_style(style_miaobia_page_imgbtn_2_main_main_pressed, lv.PART.MAIN|lv.STATE.PRESSED)

# create style style_miaobia_page_imgbtn_2_main_main_checked
style_miaobia_page_imgbtn_2_main_main_checked = lv.style_t()
style_miaobia_page_imgbtn_2_main_main_checked.init()
style_miaobia_page_imgbtn_2_main_main_checked.set_text_color(lv.color_make(0xFF,0x33,0xFF))
try:
    style_miaobia_page_imgbtn_2_main_main_checked.set_text_font(lv.font_simsun_12)
except AttributeError:
    try:
        style_miaobia_page_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_12)
    except AttributeError:
        style_miaobia_page_imgbtn_2_main_main_checked.set_text_font(lv.font_montserrat_16)
style_miaobia_page_imgbtn_2_main_main_checked.set_text_align(lv.TEXT_ALIGN.CENTER)
style_miaobia_page_imgbtn_2_main_main_checked.set_img_recolor(lv.color_make(0x00,0x00,0x00))
style_miaobia_page_imgbtn_2_main_main_checked.set_img_recolor_opa(0)
style_miaobia_page_imgbtn_2_main_main_checked.set_img_opa(255)

# add style for miaobia_page_imgbtn_2
miaobia_page_imgbtn_2.add_style(style_miaobia_page_imgbtn_2_main_main_checked, lv.PART.MAIN|lv.STATE.CHECKED)

jisuan_page = lv.obj()
jisuan_page.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
# create style style_jisuan_page_main_main_default
style_jisuan_page_main_main_default = lv.style_t()
style_jisuan_page_main_main_default.init()
style_jisuan_page_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_jisuan_page_main_main_default.set_bg_opa(255)

# add style for jisuan_page
jisuan_page.add_style(style_jisuan_page_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

jisuan_page_btnm_1 = lv.btnmatrix(jisuan_page)
jisuan_page_btnm_1.set_pos(int(0),int(60))
jisuan_page_btnm_1.set_size(240,220)
jisuan_page_btnm_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
btnm_map = [
"7",
"8",
"9",
"+",
"\n",
"4",
"5",
"6",
"-",
"\n",
"1",
"2",
"3",
"×",
"\n",
".",
"0",
"=",
"÷",
"",
""]
jisuan_page_btnm_1.set_map(btnm_map)
# create style style_jisuan_page_btnm_1_main_main_default
style_jisuan_page_btnm_1_main_main_default = lv.style_t()
style_jisuan_page_btnm_1_main_main_default.init()
style_jisuan_page_btnm_1_main_main_default.set_radius(0)
style_jisuan_page_btnm_1_main_main_default.set_bg_color(lv.color_make(0x00,0x00,0x00))
style_jisuan_page_btnm_1_main_main_default.set_bg_grad_color(lv.color_make(0xff,0xff,0xff))
style_jisuan_page_btnm_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_jisuan_page_btnm_1_main_main_default.set_bg_opa(255)
style_jisuan_page_btnm_1_main_main_default.set_border_color(lv.color_make(0xff,0xff,0xff))
style_jisuan_page_btnm_1_main_main_default.set_border_width(0)
style_jisuan_page_btnm_1_main_main_default.set_border_opa(0)
style_jisuan_page_btnm_1_main_main_default.set_pad_left(16)
style_jisuan_page_btnm_1_main_main_default.set_pad_right(16)
style_jisuan_page_btnm_1_main_main_default.set_pad_top(16)
style_jisuan_page_btnm_1_main_main_default.set_pad_bottom(16)
style_jisuan_page_btnm_1_main_main_default.set_pad_row(8)
style_jisuan_page_btnm_1_main_main_default.set_pad_column(8)

# add style for jisuan_page_btnm_1
jisuan_page_btnm_1.add_style(style_jisuan_page_btnm_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)

# create style style_jisuan_page_btnm_1_main_items_default
style_jisuan_page_btnm_1_main_items_default = lv.style_t()
style_jisuan_page_btnm_1_main_items_default.init()
style_jisuan_page_btnm_1_main_items_default.set_radius(4)
style_jisuan_page_btnm_1_main_items_default.set_bg_color(lv.color_make(0xdb,0xc7,0xc7))
style_jisuan_page_btnm_1_main_items_default.set_bg_grad_color(lv.color_make(0xe6,0xe6,0xe6))
style_jisuan_page_btnm_1_main_items_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_jisuan_page_btnm_1_main_items_default.set_bg_opa(255)
style_jisuan_page_btnm_1_main_items_default.set_border_color(lv.color_make(0xd6,0xdd,0xe3))
style_jisuan_page_btnm_1_main_items_default.set_border_width(1)
style_jisuan_page_btnm_1_main_items_default.set_border_opa(255)
style_jisuan_page_btnm_1_main_items_default.set_text_color(lv.color_make(0x00,0x00,0x00))
try:
    style_jisuan_page_btnm_1_main_items_default.set_text_font(lv.font_simsun_20)
except AttributeError:
    try:
        style_jisuan_page_btnm_1_main_items_default.set_text_font(lv.font_montserrat_20)
    except AttributeError:
        style_jisuan_page_btnm_1_main_items_default.set_text_font(lv.font_montserrat_16)

# add style for jisuan_page_btnm_1
jisuan_page_btnm_1.add_style(style_jisuan_page_btnm_1_main_items_default, lv.PART.ITEMS|lv.STATE.DEFAULT)

jisuan_page_label_1 = lv.label(jisuan_page)
jisuan_page_label_1.set_pos(int(0),int(0))
jisuan_page_label_1.set_size(240,50)
jisuan_page_label_1.set_scrollbar_mode(lv.SCROLLBAR_MODE.OFF)
jisuan_page_label_1.set_text("0")
jisuan_page_label_1.set_long_mode(lv.label.LONG.WRAP)
# create style style_jisuan_page_label_1_main_main_default
style_jisuan_page_label_1_main_main_default = lv.style_t()
style_jisuan_page_label_1_main_main_default.init()
style_jisuan_page_label_1_main_main_default.set_radius(0)
style_jisuan_page_label_1_main_main_default.set_bg_color(lv.color_make(0x21,0x95,0xf6))
style_jisuan_page_label_1_main_main_default.set_bg_grad_color(lv.color_make(0x21,0x95,0xf6))
style_jisuan_page_label_1_main_main_default.set_bg_grad_dir(lv.GRAD_DIR.NONE)
style_jisuan_page_label_1_main_main_default.set_bg_opa(0)
style_jisuan_page_label_1_main_main_default.set_text_color(lv.color_make(0xff,0xff,0xff))
try:
    style_jisuan_page_label_1_main_main_default.set_text_font(lv.font_simsun_40)
except AttributeError:
    try:
        style_jisuan_page_label_1_main_main_default.set_text_font(lv.font_montserrat_40)
    except AttributeError:
        style_jisuan_page_label_1_main_main_default.set_text_font(lv.font_montserrat_16)
style_jisuan_page_label_1_main_main_default.set_text_letter_space(2)
style_jisuan_page_label_1_main_main_default.set_text_line_space(0)
style_jisuan_page_label_1_main_main_default.set_text_align(lv.TEXT_ALIGN.RIGHT)
style_jisuan_page_label_1_main_main_default.set_pad_left(0)
style_jisuan_page_label_1_main_main_default.set_pad_right(0)
style_jisuan_page_label_1_main_main_default.set_pad_top(0)
style_jisuan_page_label_1_main_main_default.set_pad_bottom(0)

# add style for jisuan_page_label_1
jisuan_page_label_1.add_style(style_jisuan_page_label_1_main_main_default, lv.PART.MAIN|lv.STATE.DEFAULT)



def Caidan_page_miaobiao_e_released_1_event_cb(e,miaobia_page):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(miaobia_page, lv.SCR_LOAD_ANIM.OVER_TOP, 0, 0, False)
Caidan_page_miaobiao_e.add_event_cb(lambda e: Caidan_page_miaobiao_e_released_1_event_cb(e,miaobia_page), lv.EVENT.RELEASED, None)


def Caidan_page_jisuan_e_released_1_event_cb(e,jisuan_page):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(jisuan_page, lv.SCR_LOAD_ANIM.OVER_TOP, 0, 0, False)
Caidan_page_jisuan_e.add_event_cb(lambda e: Caidan_page_jisuan_e_released_1_event_cb(e,jisuan_page), lv.EVENT.RELEASED, None)


def Caidan_page_rili_e_released_1_event_cb(e,rili_page):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(rili_page, lv.SCR_LOAD_ANIM.OVER_TOP, 0, 0, False)
Caidan_page_rili_e.add_event_cb(lambda e: Caidan_page_rili_e_released_1_event_cb(e,rili_page), lv.EVENT.RELEASED, None)


def home_page_caidan_pressed_1_event_cb(e,Caidan_page):
    src = e.get_target()
    code = e.get_code()
    lv.scr_load_anim(Caidan_page, lv.SCR_LOAD_ANIM.OVER_TOP, 0, 0, False)
home_page_caidan.add_event_cb(lambda e: home_page_caidan_pressed_1_event_cb(e,Caidan_page), lv.EVENT.PRESSED, None)



# content from custom.py

# Load the default screen
lv.scr_load(home_page)

while SDL.check():
    time.sleep_ms(5)
