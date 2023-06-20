#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"
#include "lib_out.h"

#include "STM_LOG.h"
#include "LoRa_API.h"
#include "ESP32_API.h"
#include "DS3231.h"
#include "Config.h"

//extern uint32_t Node_ID[LORA_NUM_NODE+1];
extern DS3231_Time_t time;

#define label_sw_x 3
#define label_sw_y -170
#define sw_x 48
#define sw_y -79

uint32_t point_one;
//lv_chart_series_t * ser_one;

lv_obj_t * ui_Screen1_Image99;
//=========================	INIT=============================

//==========================TOP_VIEW=========================

//==========================================


/////////////////////////////TAB////////////////////////////
lv_obj_t * cover_node_control_2;
lv_obj_t * cover_node_control;

lv_obj_t * tabview;


lv_obj_t * text_label;
lv_obj_t * img_button;

lv_obj_t * tab1;
lv_obj_t * tab2;
lv_obj_t * tab3;
lv_obj_t * tab4;

lv_obj_t * label1;

//=========================================================TOP_UI=============================================================================
static lv_obj_t * label_time;
static lv_obj_t * label_date;
static lv_obj_t * label_v2;

//=========================================================TAB_Chart_LIB======================================================================
lv_obj_t * label_chart_N1;
lv_obj_t * label_chart_N2;

lv_obj_t * chart;
lv_obj_t * chart_N2;

lv_chart_series_t * ser;
lv_chart_series_t * ser_humi;
lv_chart_cursor_t * cursor;

lv_chart_series_t * ser_N2;
lv_chart_series_t * ser_humi_N2;
lv_chart_cursor_t * cursor_humi;


extern lv_style_t * style;
lv_obj_t * ui_TempChartChange_test;
lv_obj_t * ui_HumidityChartChange_test;
lv_obj_t * label;
void tab_left(void);
void update_data(lv_timer_t * timer);
void update_data2(lv_timer_t * timer);
lv_timer_t * time_1;
int tem;


//=========================================================TAB_Control_LIB====================================================================

lv_obj_t * View_1;
lv_obj_t * View_2;
lv_obj_t * View_3;

lv_obj_t * View_4;
lv_obj_t * View_2_n2;
lv_obj_t * arc_n2;
lv_obj_t * Switch_1_n2;
lv_obj_t * Switch_2_n2;
lv_obj_t * Switch_3_n2;
lv_obj_t * Switch_4_n2;


lv_obj_t * btn_n1;
lv_obj_t * label_n1;
lv_obj_t * btn_n2;
lv_obj_t * label_n2;

lv_obj_t * arc_temp;
lv_obj_t * Switch_1;
lv_obj_t * Switch_2;
lv_obj_t * Switch_3;
lv_obj_t * Switch_4;

lv_obj_t * lb_1;
lv_obj_t * lb_2;
lv_obj_t * lb_3;
lv_obj_t * lb_4;

lv_obj_t * lb_1_N2;
lv_obj_t * lb_2_N2;
lv_obj_t * lb_3_N2;
lv_obj_t * lb_4_N2;

lv_obj_t * label_arc;
lv_obj_t * label_temp;

//==========================================================TAB_SETTING=====================================================================
static lv_obj_t * animation_1;
lv_obj_t * btn_url;
static lv_obj_t * mbox;
static lv_obj_t * mbox_of_pass;

static lv_anim_t animation_template;
static lv_style_t label_style;
//lv_obj_t * mbox_bot;
static lv_obj_t * btn_set_url;
static lv_obj_t * mbox_btn_password;
static lv_obj_t * pwd_ta;
static lv_obj_t * kb;
static lv_obj_t * mbox_btn_user;
lv_obj_t * Done;
lv_obj_t * label_Done;
lv_obj_t * label_user;
lv_obj_t * label_pass;
lv_obj_t * label2;
lv_obj_t * label3;

static lv_obj_t * mboxConnectBtn;
static lv_obj_t * pwd_ta_Pass;
static lv_obj_t * pwd_ta_User;
static lv_obj_t * kb_User;
static lv_obj_t * kb_Pass;

//static char ssidPW[20];
static bool switch_chek[8] = {0,0,0,0,0,0};
lv_coord_t text_value_c[20] = {20,19,1,1,1,1,1,1,1,1,1,11,1,1,1,1,1,1,1,1};

static int btn_hight_url = 0;

//==========================================================TAB_wifi_config=================================================================
lv_obj_t * ui_avaiableLabel;
static char *Get_wifi;
lv_obj_t * ui_avaiableSwitch;
lv_obj_t * ui_WiFilabel;
lv_obj_t * label_const;
lv_obj_t * label_get_value_now;

static lv_obj_t * Screen_conect_wifi;
lv_obj_t * Screen_conect_wifi_top;
lv_obj_t * pwd_Pass_wifi;
lv_obj_t * OK;
lv_obj_t * cancel;
lv_obj_t * label_wifi;

static lv_obj_t * kb_set_pass_wifi;

static lv_obj_t * list;
static int btn_cnt = 0;
lv_obj_t * add_wifi_btn;

static lv_timer_t * timer;

static lv_obj_t * list_btn;

static const char *TAG = "STM32_LOG";


//========================================================Event cover============================================================================
//void btn_cover_event (lv_event_t *e){
//	lv_event_code_t code = lv_event_get_code(e);
//	lv_obj_t * obj = lv_event_get_target(e);
//	lv_obj_add_flag(cover_node_control, LV_OBJ_FLAG_HIDDEN);
//	lv_obj_clear_flag(cover_node_control, LV_OBJ_FLAG_HIDDEN);
//Z
//}

//void UI_EnableNode1(void){
//	lv_obj_add_flag(cover_node_control, LV_OBJ_FLAG_HIDDEN);
//	STM_LOG(BOLD_GREEN, "STM32_LOG", "Enable node 1");
//	delay_ms(2);
//}
//void UI_DisableNode1(void){
//	lv_obj_clear_flag(cover_node_control, LV_OBJ_FLAG_HIDDEN);
//	lv_obj_add_flag(View_3, LV_OBJ_FLAG_HIDDEN);
//}
//
//void UI_EnableNode2(void){
//	lv_obj_add_flag(cover_node_control, LV_OBJ_FLAG_HIDDEN);
//}
//void UI_DisableNode2(void){
//	lv_obj_clear_flag(cover_node_control, LV_OBJ_FLAG_HIDDEN);
//	lv_obj_add_flag(View_4, LV_OBJ_FLAG_HIDDEN);
//}

//========================================================TAB_1===================================================================================
void button_ev(lv_event_t *e){
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t * obj = lv_event_get_target(e);

	if(code == LV_EVENT_CLICKED && obj == ui_TempChartChange_test) {
		lv_obj_clear_flag(chart,LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(label_chart_N1,LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(label_chart_N2,LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(chart_N2,LV_OBJ_FLAG_HIDDEN);
	    lv_obj_set_style_bg_color(ui_TempChartChange_test, lv_color_hex(0X33CCFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	    lv_obj_set_style_bg_opa(ui_TempChartChange_test, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	    lv_obj_set_style_bg_color(ui_HumidityChartChange_test, lv_color_hex(0XFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	    lv_obj_set_style_bg_opa(ui_HumidityChartChange_test, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	}
	if(code == LV_EVENT_CLICKED && obj == ui_HumidityChartChange_test) {
		lv_obj_add_flag(chart,LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(label_chart_N1,LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(label_chart_N2,LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(chart_N2,LV_OBJ_FLAG_HIDDEN);
	    lv_obj_set_style_bg_color(ui_TempChartChange_test, lv_color_hex(0XFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	    lv_obj_set_style_bg_opa(ui_TempChartChange_test, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	    lv_obj_set_style_bg_color(ui_HumidityChartChange_test, lv_color_hex(0X33CCFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	    lv_obj_set_style_bg_opa(ui_HumidityChartChange_test, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	}
}

void ui_tab1_screen_init(lv_obj_t * tab){

    ui_TempChartChange_test = lv_btn_create(tab);
    lv_obj_set_width(ui_TempChartChange_test, 100);
    lv_obj_set_height(ui_TempChartChange_test, 25);
    lv_obj_set_x(ui_TempChartChange_test, -117);
    lv_obj_set_y(ui_TempChartChange_test, -117);
    lv_obj_set_align(ui_TempChartChange_test, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_TempChartChange_test, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_TempChartChange_test, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

//    lv_obj_add_style(ui_TempChartChange_test, &tyle, LV_GAUGE_PART_MAIN);
    lv_obj_set_style_bg_color(ui_TempChartChange_test, lv_color_hex(0X33CCFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TempChartChange_test, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_TempChartChange_test, lv_color_hex(0x777777), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_TempChartChange_test, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_TempChartChange_test, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    label = lv_label_create(ui_TempChartChange_test);
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    lv_label_set_text(label, "Node1");
    lv_obj_set_style_text_color(label, lv_color_hex(0x444444), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_HumidityChartChange_test = lv_btn_create(tab);
    lv_obj_set_width(ui_HumidityChartChange_test, 100);
    lv_obj_set_height(ui_HumidityChartChange_test, 25);
    lv_obj_set_x(ui_HumidityChartChange_test, 0);
    lv_obj_set_y(ui_HumidityChartChange_test, -117);
    lv_obj_set_align(ui_HumidityChartChange_test, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_HumidityChartChange_test, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_HumidityChartChange_test, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_HumidityChartChange_test, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_HumidityChartChange_test, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(ui_HumidityChartChange_test, lv_color_hex(0x777777), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_HumidityChartChange_test, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_HumidityChartChange_test, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    label = lv_label_create(ui_HumidityChartChange_test);
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    lv_label_set_text(label, "Node2");
    lv_obj_set_style_text_color(label, lv_color_hex(0x444444), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(label, 255, LV_PART_MAIN | LV_STATE_DEFAULT);




    lv_obj_add_event_cb(ui_TempChartChange_test, button_ev,  LV_EVENT_ALL, NULL); //@F@r
    lv_obj_add_event_cb(ui_HumidityChartChange_test, button_ev,  LV_EVENT_ALL, NULL); //HF@r

    label_get_value_now = lv_obj_create(tab);
    lv_obj_set_width(label_get_value_now, 130);
    lv_obj_set_height(label_get_value_now, 25);
    lv_obj_set_x(label_get_value_now, 120);
    lv_obj_set_y(label_get_value_now, -117);
    lv_obj_set_align(label_get_value_now, LV_ALIGN_CENTER);
    lv_obj_add_flag(label_get_value_now, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(label_get_value_now, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(label_get_value_now, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(label_get_value_now, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_border_color(label_get_value_now, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(label_get_value_now, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(label_get_value_now, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    label_chart_N1 = lv_label_create(label_get_value_now);
    lv_obj_set_align(label_chart_N1, LV_ALIGN_CENTER);
    lv_label_set_text(label_chart_N1, "00.0°C-00.0%");
    lv_obj_set_style_text_color(label_chart_N1, lv_color_hex(0x444444), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(label_chart_N1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(label_chart_N1, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    label_chart_N2 = lv_label_create(label_get_value_now);
    lv_obj_set_align(label_chart_N2, LV_ALIGN_CENTER);
    lv_label_set_text(label_chart_N2, "00.0°C-00.0%");
    lv_obj_set_style_text_color(label_chart_N2, lv_color_hex(0x444444), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(label_chart_N2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(label_chart_N2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(label_chart_N2, LV_OBJ_FLAG_HIDDEN);
}

void Set_ShowNode1(float temp, float humi){
	char buf[13];
	sprintf(buf, "%.01f°C-%.01f%%", temp, humi);
    lv_label_set_text(label_chart_N1, buf);
}

void Set_ShowNode2(float temp, float humi){
	char buf[13];
	sprintf(buf, "%.01f°C-%.01f%%", temp, humi);
    lv_label_set_text(label_chart_N2, buf);
}

void update_Chart_Node1(float temp, float humi){
	lv_chart_set_next_value(chart, ser_humi, (int16_t)humi);
    lv_chart_set_next_value(chart, ser, (int16_t)temp);
    lv_chart_refresh(chart);
}

void update_Chart_Node2(float temp, float humi){
    lv_chart_set_next_value(chart_N2, ser_humi_N2, (int16_t)humi);
    lv_chart_set_next_value(chart_N2, ser_N2, (int16_t)temp);
    lv_chart_refresh(chart_N2);
}



static void draw_event_cb_chart(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);

    /*Add the faded area before the lines are drawn*/
    lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
    if(dsc->part == LV_PART_ITEMS) {
        if(!dsc->p1 || !dsc->p2) return;

        /*Add a line mask that keeps the area below the line*/
        lv_draw_mask_line_param_t line_mask_param;
        lv_draw_mask_line_points_init(&line_mask_param, dsc->p1->x, dsc->p1->y, dsc->p2->x, dsc->p2->y,
                                      LV_DRAW_MASK_LINE_SIDE_BOTTOM);
        int16_t line_mask_id = lv_draw_mask_add(&line_mask_param, NULL);

        /*Add a fade effect: transparent bottom covering top*/
        lv_coord_t h = lv_obj_get_height(obj);
        lv_draw_mask_fade_param_t fade_mask_param;
        lv_draw_mask_fade_init(&fade_mask_param, &obj->coords, LV_OPA_COVER, obj->coords.y1 + h / 8, LV_OPA_TRANSP,
                               obj->coords.y2);
        int16_t fade_mask_id = lv_draw_mask_add(&fade_mask_param, NULL);

        /*Draw a rectangle that will be affected by the mask*/
        lv_draw_rect_dsc_t draw_rect_dsc;
        lv_draw_rect_dsc_init(&draw_rect_dsc);
        draw_rect_dsc.bg_opa = LV_OPA_100;
        draw_rect_dsc.bg_color = dsc->line_dsc->color;

        lv_area_t a;
        a.x1 = dsc->p1->x;
        a.x2 = dsc->p2->x - 1;
        a.y1 = LV_MIN(dsc->p1->y, dsc->p2->y);
        a.y2 = obj->coords.y2;
        lv_draw_rect(dsc->draw_ctx, &draw_rect_dsc, &a);

        /*Remove the masks*/
        lv_draw_mask_free_param(&line_mask_param);
        lv_draw_mask_free_param(&fade_mask_param);
        lv_draw_mask_remove_id(line_mask_id);
        lv_draw_mask_remove_id(fade_mask_id);
    }
}

void Chart_ui_tab_1(void)
{
    chart = lv_chart_create(tab1);
    lv_obj_set_x(chart, 13);
    lv_obj_set_y(chart, 0);
    lv_obj_set_align(chart, LV_ALIGN_CENTER);
    lv_obj_set_size(chart, 342, 190);
    lv_chart_set_axis_tick(chart, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 11 , 5, true, 40); //Ä‘iá»u chá»‰nh khoáº£n cĂ¡ch cĂ¡c giĂ¡ trá»‹ trĂªn trá»¥c y
    lv_chart_set_axis_tick(chart, LV_CHART_AXIS_PRIMARY_X, 10, 5, 20, 5, true, 40);
    lv_obj_add_event_cb(chart, draw_event_cb_chart, LV_EVENT_DRAW_PART_BEGIN, NULL);
    lv_chart_set_point_count(chart, 20);
    lv_obj_refresh_ext_draw_size(chart);
    cursor = lv_chart_add_cursor(chart, lv_palette_main(LV_PALETTE_BLUE), LV_DIR_RIGHT);//váº½ con trá» vá»›i má»™t mĂ u nháº¥t Ä‘á»‹nh
    ser_humi = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_BLUE), LV_CHART_AXIS_PRIMARY_Y);
	ser = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);//Äáº·c quy Ä‘á»‹nh cĂ¡c chuá»—i trong lvgl
	lv_chart_set_div_line_count(chart, 20, 101);

    lv_chart_set_series_color(chart, ser, lv_color_hex(0xFF3300));
    lv_chart_set_series_color(chart, ser_humi, lv_color_hex(0x3333FF));
    uint32_t i;
    for(i = 0; i < 10; i++) {
        lv_chart_set_next_value(chart, ser, 0);
    }
    lv_chart_set_zoom_x(chart, 512);

    chart_N2 = lv_chart_create(tab1);
    lv_obj_set_x(chart_N2, 13);
    lv_obj_set_y(chart_N2, 0);
    lv_obj_set_align(chart_N2, LV_ALIGN_CENTER);
    lv_obj_set_size(chart_N2, 342, 190);
    lv_chart_set_axis_tick(chart_N2, LV_CHART_AXIS_PRIMARY_Y, 10, 5, 11 , 5, true, 40); //Ä‘iá»u chá»‰nh khoáº£n cĂ¡ch cĂ¡c giĂ¡ trá»‹ trĂªn trá»¥c y
    lv_chart_set_axis_tick(chart_N2, LV_CHART_AXIS_PRIMARY_X, 10, 5, 20, 5, true, 40);
    lv_obj_add_event_cb(chart_N2, draw_event_cb_chart, LV_EVENT_DRAW_PART_BEGIN, NULL);
    lv_chart_set_point_count(chart_N2, 10);
    lv_obj_refresh_ext_draw_size(chart_N2);
    cursor_humi = lv_chart_add_cursor(chart_N2, lv_palette_main(LV_PALETTE_BLUE), LV_DIR_LEFT );//váº½ con trá» vá»›i má»™t mĂ u nháº¥t Ä‘á»‹nh
    ser_humi_N2 = lv_chart_add_series(chart_N2, lv_palette_main(LV_PALETTE_BLUE), LV_CHART_AXIS_PRIMARY_Y);//Äáº·c quy Ä‘á»‹nh cĂ¡c chuá»—i trong lvgl
    ser_N2 = lv_chart_add_series(chart_N2, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_PRIMARY_Y);//Äáº·c quy Ä‘á»‹nh cĂ¡c chuá»—i trong lvgl
    lv_chart_set_div_line_count(chart_N2, 10, 101);
    lv_chart_set_series_color(chart_N2, ser_humi_N2, lv_color_hex(0x3333FF));
    lv_chart_set_series_color(chart_N2, ser_N2, lv_color_hex(0xFF3300));
    for(i = 0; i < 10; i++) {
        lv_chart_set_next_value(chart_N2, ser_humi_N2, 0);
    }
    lv_chart_set_zoom_x(chart_N2, 512);
    lv_obj_add_flag(chart_N2, LV_OBJ_FLAG_HIDDEN);

//    time_1 = lv_timer_create(foo, 2000, chart);
}




////////////////////////////////////////// TABVIEW //////////////////////////////////////////////////////////////////////////////////
void tab_left(void){
	tabview = lv_tabview_create(ui_Screen1, LV_DIR_LEFT, 80);
	lv_obj_set_align(tabview, LV_ALIGN_CENTER);
    lv_obj_set_x(tabview, -2);
    lv_obj_set_y(tabview, 30);

    lv_obj_set_width(tabview, 480);
    lv_obj_set_height(tabview, 275);

//	lv_obj_add_event_cb(lv_tabview_get_content(tabview), scroll_begin_event, LV_EVENT_SCROLL_BEGIN, NULL);
    lv_obj_set_style_bg_color(tabview, lv_color_hex(0xFFFFFF), 0);// mĂ u cá»§a mĂ ng áº£nh

    lv_obj_t * tab_btns = lv_tabview_get_tab_btns(tabview);

    lv_obj_set_style_bg_color(tab_btns, lv_palette_darken(LV_PALETTE_RED, 5), 0);
    lv_obj_set_style_text_color(tab_btns, lv_color_hex(0xFFFFFF), 0); //mĂ u nĂºt chá»n tab
    lv_obj_set_style_border_side(tab_btns, LV_BORDER_SIDE_RIGHT, LV_PART_ITEMS | LV_STATE_CHECKED);


    /*Add 3 tabs (the tabs are page (lv_page) and can be scrolled*/
    tab1 = lv_tabview_add_tab(tabview, "Data view");
    tab2 = lv_tabview_add_tab(tabview, "Control");
    tab3 = lv_tabview_add_tab(tabview, "Setting");
    tab4 = lv_tabview_add_tab(tabview, "Network");

//    lv_obj_t * label ;

    ui_tab1_screen_init(tab1);

    lv_obj_clear_flag(lv_tabview_get_content(tabview), LV_OBJ_FLAG_SCROLLABLE);

}

//================================================================TAB_2============================================================
void control_event (lv_event_t * e){
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t * obj = lv_event_get_target(e);

	if(code == LV_EVENT_CLICKED && obj == btn_n2){
		lv_obj_add_flag(View_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(View_4, LV_OBJ_FLAG_HIDDEN);
	    lv_obj_clear_flag(View_2_n2, LV_OBJ_FLAG_HIDDEN);
	    if(Node_ID[2] == 0){
	    	lv_obj_clear_flag(cover_node_control, LV_OBJ_FLAG_HIDDEN);
	    	lv_obj_add_flag(View_4, LV_OBJ_FLAG_HIDDEN);
	    }

	    else if(Node_ID[2] != 0){
	    	lv_obj_add_flag(cover_node_control, LV_OBJ_FLAG_HIDDEN);
	    	lv_obj_clear_flag(View_4, LV_OBJ_FLAG_HIDDEN);
	    }
	    lv_obj_set_style_bg_color(btn_n1, lv_color_hex(0XFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	    lv_obj_set_style_bg_opa(btn_n1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	    lv_obj_set_style_bg_color(btn_n2, lv_color_hex(0X33CCFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	    lv_obj_set_style_bg_opa(btn_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	}

	else if(code == LV_EVENT_CLICKED && obj == btn_n1  ){

		lv_obj_clear_flag(View_3, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(View_4, LV_OBJ_FLAG_HIDDEN);
	    lv_obj_add_flag(View_2_n2, LV_OBJ_FLAG_HIDDEN);
	    if(Node_ID[1] == 0){
	    	lv_obj_clear_flag(cover_node_control, LV_OBJ_FLAG_HIDDEN);
	    	lv_obj_add_flag(View_3, LV_OBJ_FLAG_HIDDEN);
	    }

	    else if(Node_ID[1] != 0){
	    	lv_obj_add_flag(cover_node_control, LV_OBJ_FLAG_HIDDEN);
	    	lv_obj_clear_flag(View_3, LV_OBJ_FLAG_HIDDEN);
	    }
	    lv_obj_set_style_bg_color(btn_n2, lv_color_hex(0XFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	    lv_obj_set_style_bg_opa(btn_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	    lv_obj_set_style_bg_color(btn_n1, lv_color_hex(0X33CCFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	    lv_obj_set_style_bg_opa(btn_n1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	}
	else if(code == LV_EVENT_CLICKED && obj == Switch_1){
		switch_chek[0] = !switch_chek[0];
		if(switch_chek[0]){
		    lv_obj_set_style_bg_color(Switch_1, lv_color_hex(0X33CFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
		    lv_obj_set_style_bg_opa(Switch_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
		    LoRa_SendCommand(CMD_CONTROL, "1,RELAY3,ON");
			ESP32_SendCommand(CMD_CONTROL, "1,RELAY3,ON");
			lv_label_set_text(lb_1, "ON");
		}
		else{
		    lv_obj_set_style_bg_color(Switch_1, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
		    lv_obj_set_style_bg_opa(Switch_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
		    LoRa_SendCommand(CMD_CONTROL, "1,RELAY3,OFF");
			ESP32_SendCommand(CMD_CONTROL, "1,RELAY3,OFF");
			lv_label_set_text(lb_1, "OFF");
		}
	}
	else if(code == LV_EVENT_CLICKED && obj == Switch_2){
		switch_chek[1] = !switch_chek[1];
		if(switch_chek[1]){
			lv_obj_set_style_bg_color(Switch_2, lv_color_hex(0X33CFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_obj_set_style_bg_opa(Switch_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			LoRa_SendCommand(CMD_CONTROL, "1,RELAY2,ON");
			ESP32_SendCommand(CMD_CONTROL, "1,RELAY2,ON");
			lv_label_set_text(lb_2, "ON");
		}
		else{
			lv_obj_set_style_bg_color(Switch_2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_obj_set_style_bg_opa(Switch_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			LoRa_SendCommand(CMD_CONTROL, "1,RELAY2,OFF");
			ESP32_SendCommand(CMD_CONTROL, "1,RELAY2,OFF");
			lv_label_set_text(lb_2, "OFF");
		}
	}
	else if(code == LV_EVENT_CLICKED && obj == Switch_3){
		switch_chek[2] = !switch_chek[2];
		if(switch_chek[2]){
			lv_obj_set_style_bg_color(Switch_3, lv_color_hex(0X33CFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_obj_set_style_bg_opa(Switch_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			LoRa_SendCommand(CMD_CONTROL, "1,RELAY1,ON");
			ESP32_SendCommand(CMD_CONTROL, "1,RELAY1,ON");
			lv_label_set_text(lb_3, "ON");
		}
		else{
			lv_obj_set_style_bg_color(Switch_3, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_obj_set_style_bg_opa(Switch_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			LoRa_SendCommand(CMD_CONTROL, "1,RELAY1,OFF");
			ESP32_SendCommand(CMD_CONTROL, "1,RELAY1,OFF");
			lv_label_set_text(lb_3, "OFF");
		}
	}
	else if(code == LV_EVENT_CLICKED && obj == Switch_4){
		switch_chek[7] = !switch_chek[7];
		if(switch_chek[7]){
			lv_obj_set_style_bg_color(Switch_4, lv_color_hex(0X33CFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_obj_set_style_bg_opa(Switch_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			LoRa_SendCommand(CMD_CONTROL, "1,AUTO,ON");
			ESP32_SendCommand(CMD_CONTROL, "1,AUTO,ON");
			lv_label_set_text(lb_4, "ON");
		}
		else{
			lv_obj_set_style_bg_color(Switch_4, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_obj_set_style_bg_opa(Switch_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			LoRa_SendCommand(CMD_CONTROL, "1,AUTO,OFF");
			ESP32_SendCommand(CMD_CONTROL, "1,AUTO,OFF");
			lv_label_set_text(lb_4, "OFF");
		}
	}
	else if(code == LV_EVENT_CLICKED && obj == Switch_1_n2){
		switch_chek[3] = !switch_chek[3];
		if(switch_chek[3]){
			lv_obj_set_style_bg_color(Switch_1_n2, lv_color_hex(0X33CFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_obj_set_style_bg_opa(Switch_1_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			LoRa_SendCommand(CMD_CONTROL, "2,RELAY3,ON");
			ESP32_SendCommand(CMD_CONTROL, "2,RELAY3,ON");
			lv_label_set_text(lb_1_N2, "ON");
		}
		else{
			lv_obj_set_style_bg_color(Switch_1_n2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_obj_set_style_bg_opa(Switch_1_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			LoRa_SendCommand(CMD_CONTROL, "2,RELAY3,OFF");
			ESP32_SendCommand(CMD_CONTROL, "2,RELAY3,OFF");
			lv_label_set_text(lb_1_N2, "OFF");
		}
	}
	else if(code == LV_EVENT_CLICKED && obj == Switch_2_n2){
		switch_chek[4] = !switch_chek[4];
		if(switch_chek[4]){
			lv_obj_set_style_bg_color(Switch_2_n2, lv_color_hex(0X33CFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_obj_set_style_bg_opa(Switch_2_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			LoRa_SendCommand(CMD_CONTROL, "2,RELAY2,ON");
			ESP32_SendCommand(CMD_CONTROL, "2,RELAY2,ON");
			lv_label_set_text(lb_2_N2, "ON");
		}
		else{
			lv_obj_set_style_bg_color(Switch_2_n2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
	  		lv_obj_set_style_bg_opa(Switch_2_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	  		LoRa_SendCommand(CMD_CONTROL, "2,RELAY2,OFF");
			ESP32_SendCommand(CMD_CONTROL, "2,RELAY2,OFF");
			lv_label_set_text(lb_2_N2, "OFF");

		}
	}
	else if(code == LV_EVENT_CLICKED && obj == Switch_3_n2){
		switch_chek[5]  = !switch_chek[5];
		if(switch_chek[5]){
			lv_obj_set_style_bg_color(Switch_3_n2, lv_color_hex(0X33CFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_obj_set_style_bg_opa(Switch_3_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			LoRa_SendCommand(CMD_CONTROL, "2,RELAY1,ON");
			ESP32_SendCommand(CMD_CONTROL, "2,RELAY1,ON");
			lv_label_set_text(lb_3_N2, "ON");
		}
		else{
			lv_obj_set_style_bg_color(Switch_3_n2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_obj_set_style_bg_opa(Switch_3_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			LoRa_SendCommand(CMD_CONTROL, "2,RELAY1,OFF");
			ESP32_SendCommand(CMD_CONTROL, "2,RELAY1,OFF");
			lv_label_set_text(lb_3_N2, "OFF");
		}
	}

	else if(code == LV_EVENT_CLICKED && obj == Switch_4_n2){
		switch_chek[6]  = !switch_chek[6];
		if(switch_chek[6]){
			lv_obj_set_style_bg_color(Switch_4_n2, lv_color_hex(0X33CFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_obj_set_style_bg_opa(Switch_4_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			LoRa_SendCommand(CMD_CONTROL, "2,AUTO,ON");
			ESP32_SendCommand(CMD_CONTROL, "2,AUTO,ON");
			lv_label_set_text(lb_4_N2, "ON");
		}
		else{
			lv_obj_set_style_bg_color(Switch_4_n2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
			lv_obj_set_style_bg_opa(Switch_4_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			LoRa_SendCommand(CMD_CONTROL, "2,AUTO,OFF");
			ESP32_SendCommand(CMD_CONTROL, "2,AUTO,OFF");
			lv_label_set_text(lb_4_N2, "OFF");
		}
	}
}

void Set_Control_Switch(int id, char *relay, char *state){
	if(id == 1){
		if(!strcmp(state, "ON")){
			if(!strcmp(relay, "RELAY1")){
			    lv_obj_set_style_bg_color(Switch_3, lv_color_hex(0X33CFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_obj_set_style_bg_opa(Switch_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_label_set_text(lb_3, "ON");
			    switch_chek[2] = 1;
			}
			else if(!strcmp(relay, "RELAY2")){
			    lv_obj_set_style_bg_color(Switch_2, lv_color_hex(0X33CFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_obj_set_style_bg_opa(Switch_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_label_set_text(lb_2, "ON");
			    switch_chek[1] = 1;
			}
			else if(!strcmp(relay, "RELAY3")){
			    lv_obj_set_style_bg_color(Switch_1, lv_color_hex(0X33CFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_obj_set_style_bg_opa(Switch_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_label_set_text(lb_1, "ON");
			    switch_chek[0] = 1;
			}
			else if(!strcmp(relay, "AUTO")){
			    lv_obj_set_style_bg_color(Switch_4, lv_color_hex(0X33CFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_obj_set_style_bg_opa(Switch_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_label_set_text(lb_4, "ON");
			    switch_chek[7] = 1;
			}
		}
		else{
			if(!strcmp(relay, "RELAY1")){
			    lv_obj_set_style_bg_color(Switch_3, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_obj_set_style_bg_opa(Switch_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_label_set_text(lb_3, "OFF");
			    switch_chek[2] = 0;
			}
			else if(!strcmp(relay, "RELAY2")){
			    lv_obj_set_style_bg_color(Switch_2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_obj_set_style_bg_opa(Switch_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_label_set_text(lb_2, "OFF");
			    switch_chek[1] = 0;
			}
			else if(!strcmp(relay, "RELAY3")){
			    lv_obj_set_style_bg_color(Switch_1, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_obj_set_style_bg_opa(Switch_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_label_set_text(lb_1, "OFF");
			    switch_chek[2] = 0;
			}
			else if(!strcmp(relay, "AUTO")){
			    lv_obj_set_style_bg_color(Switch_4, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_obj_set_style_bg_opa(Switch_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_label_set_text(lb_4, "OFF");
			    switch_chek[7] = 0;
			}
		}
	}
	else if(id == 2){
		if(!strcmp(state, "ON")){
			if(!strcmp(relay, "RELAY1")){
			    lv_obj_set_style_bg_color(Switch_3_n2, lv_color_hex(0X33CFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_obj_set_style_bg_opa(Switch_3_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_label_set_text(lb_3_N2, "ON");
			    switch_chek[5] = 1;
			}
			else if(!strcmp(relay, "RELAY2")){
			    lv_obj_set_style_bg_color(Switch_2_n2, lv_color_hex(0X33CFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_obj_set_style_bg_opa(Switch_2_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_label_set_text(lb_2_N2, "ON");
			    switch_chek[4] = 1;
			}
			else if(!strcmp(relay, "RELAY3")){
			    lv_obj_set_style_bg_color(Switch_1_n2, lv_color_hex(0X33CFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_obj_set_style_bg_opa(Switch_1_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_label_set_text(lb_1_N2, "ON");
			    switch_chek[3] = 1;
			}
			else if(!strcmp(relay, "AUTO")){
			    lv_obj_set_style_bg_color(Switch_4_n2, lv_color_hex(0X33CFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_obj_set_style_bg_opa(Switch_4_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_label_set_text(lb_4_N2, "ON");
			    switch_chek[6] = 1;
			}
		}
		else{
			if(!strcmp(relay, "RELAY1")){
			    lv_obj_set_style_bg_color(Switch_3_n2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_obj_set_style_bg_opa(Switch_3_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_label_set_text(lb_3_N2, "OFF");
			    switch_chek[5] = 0;
			}
			else if(!strcmp(relay, "RELAY2")){
			    lv_obj_set_style_bg_color(Switch_2_n2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_obj_set_style_bg_opa(Switch_2_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_label_set_text(lb_2_N2, "OFF");
			    switch_chek[4] = 0;
			}
			else if(!strcmp(relay, "RELAY3")){
			    lv_obj_set_style_bg_color(Switch_1_n2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_obj_set_style_bg_opa(Switch_1_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_label_set_text(lb_1_N2, "OFF");
			    switch_chek[3] = 0;
			}
			else if(!strcmp(relay, "AUTO")){
			    lv_obj_set_style_bg_color(Switch_4_n2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_obj_set_style_bg_opa(Switch_4_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			    lv_label_set_text(lb_4_N2, "OFF");
			    switch_chek[6] = 0;
			}
		}
	}
}


void ui_tab_control(void){
	//============================View_1==================================
	View_1 = lv_obj_create(tab2);
    lv_obj_set_width(View_1, 166);
    lv_obj_set_height(View_1, 78);
    lv_obj_set_x(View_1, -107);
    lv_obj_set_y(View_1, -87);
    lv_obj_set_align(View_1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(View_1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(View_1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(View_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    btn_n1 = lv_btn_create(View_1);
    lv_obj_set_width(btn_n1, 69);
    lv_obj_set_height(btn_n1, 50);
    lv_obj_set_x(btn_n1, -39);
    lv_obj_set_y(btn_n1, 0);
    lv_obj_set_align(btn_n1, LV_ALIGN_CENTER);
    lv_obj_add_flag(btn_n1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(btn_n1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(btn_n1, lv_color_hex(0X33CCFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(btn_n1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    label_n1 = lv_label_create(btn_n1);
    lv_obj_set_width(label_n1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(label_n1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(label_n1, LV_ALIGN_CENTER);
    lv_label_set_text(label_n1, "Node1");
    lv_obj_set_style_text_color(label_n1, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(label_n1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);



    btn_n2 = lv_btn_create(View_1);
    lv_obj_set_width(btn_n2, 69);
    lv_obj_set_height(btn_n2, 50);
    lv_obj_set_x(btn_n2, 36);
    lv_obj_set_y(btn_n2, 0);
    lv_obj_set_align(btn_n2, LV_ALIGN_CENTER);
    lv_obj_add_flag(btn_n2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(btn_n2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(btn_n2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(btn_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    label_n2 = lv_label_create(btn_n2);
    lv_obj_set_width(label_n2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(label_n2, LV_SIZE_CONTENT);    /// 1
    lv_label_set_text(label_n2, "Node2");
    lv_obj_set_align(label_n2, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(label_n2, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(label_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    //===========================View_2=====================================
    View_2 = lv_obj_create(tab2);
    lv_obj_set_width(View_2, 164);
    lv_obj_set_height(View_2, 150);
    lv_obj_set_x(View_2, -107);
    lv_obj_set_y(View_2, 36);
    lv_obj_set_align(View_2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(View_2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(View_2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(View_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(View_2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

    arc_temp = lv_arc_create(View_2);
    lv_obj_set_width(arc_temp, 125);
    lv_obj_set_height(arc_temp, 125);
   	lv_obj_set_x(arc_temp, 0);
   	lv_obj_set_y(arc_temp, 1);
  	lv_obj_set_align(arc_temp, LV_ALIGN_CENTER);
   	lv_arc_set_value(arc_temp, 50);

    lv_obj_set_style_bg_color(arc_temp, lv_color_hex(0x00FF00), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(arc_temp, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(arc_temp, lv_color_hex(0x00FFA0), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(arc_temp, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

    label_arc = lv_label_create(View_2);
    lv_obj_set_width(label_arc, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(label_arc, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(label_arc, 0);
    lv_obj_set_y(label_arc, 62);
    lv_obj_set_align(label_arc, LV_ALIGN_CENTER);
    lv_label_set_text(label_arc, "Auto Temperature");

    label_temp = lv_label_create(View_2);
    lv_obj_set_width(label_temp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(label_temp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(label_temp, 0);
    lv_obj_set_y(label_temp, 0);
    lv_obj_set_align(label_temp, LV_ALIGN_CENTER);
    lv_label_set_text(label_temp, "0°C");
    lv_obj_set_style_text_font(label_temp, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);


	//===========================View_3=======================================

    View_3 = lv_obj_create(tab2);
	lv_obj_set_width(View_3, 201);
	lv_obj_set_height(View_3, 234);
	lv_obj_set_x(View_3, 89);
	lv_obj_set_y(View_3, -5);
	lv_obj_set_align(View_3, LV_ALIGN_CENTER);
	lv_obj_clear_flag(View_3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
	lv_obj_set_style_border_color(View_3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(View_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(View_3, 2, LV_PART_MAIN | LV_STATE_DEFAULT);

	label1 = lv_label_create(View_3);
	lv_obj_set_width(label1, LV_SIZE_CONTENT);
	lv_obj_set_height(label1, LV_SIZE_CONTENT);
	lv_obj_set_x(label1, label_sw_x);
	lv_obj_set_y(label1, label_sw_y+50);
	lv_obj_set_align(label1, LV_ALIGN_BOTTOM_LEFT);
	lv_label_set_text(label1, "Light");

	Switch_2 = lv_btn_create(View_3);
	lv_obj_set_width(Switch_2, 77);
	lv_obj_set_height(Switch_2, 33);
	lv_obj_set_x(Switch_2, sw_x);
	lv_obj_set_y(Switch_2, sw_y+50);
	lv_obj_set_align(Switch_2, LV_ALIGN_CENTER);
	lv_obj_add_flag(Switch_2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
	lv_obj_clear_flag(Switch_2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
	lv_obj_set_style_bg_color(Switch_2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(Switch_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	lb_2 = lv_label_create(Switch_2);
	lv_obj_set_align(lb_2, LV_ALIGN_CENTER);
	lv_label_set_text(lb_2, "OFF");
	lv_obj_set_style_text_color(lb_2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(lb_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	label1 = lv_label_create(View_3);
	lv_obj_set_width(label1, LV_SIZE_CONTENT);
	lv_obj_set_height(label1, LV_SIZE_CONTENT);
	lv_obj_set_x(label1, label_sw_x);
	lv_obj_set_y(label1, label_sw_y+50+50);
	lv_obj_set_align(label1, LV_ALIGN_BOTTOM_LEFT);
	lv_label_set_text(label1, "Fan");

	Switch_3 = lv_btn_create(View_3);
	lv_obj_set_width(Switch_3, 77);
	lv_obj_set_height(Switch_3, 33);
	lv_obj_set_x(Switch_3, sw_x);
	lv_obj_set_y(Switch_3, sw_y+50+50);
	lv_obj_set_align(Switch_3, LV_ALIGN_CENTER);
	lv_obj_add_flag(Switch_3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
	lv_obj_clear_flag(Switch_3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
	lv_obj_set_style_bg_color(Switch_3, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(Switch_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	lb_3 = lv_label_create(Switch_3);
	lv_obj_set_align(lb_3, LV_ALIGN_CENTER);
	lv_label_set_text(lb_3, "OFF");
	lv_obj_set_style_text_color(lb_3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(lb_3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	label1 = lv_label_create(View_3);
	lv_obj_set_width(label1, LV_SIZE_CONTENT);
	lv_obj_set_height(label1, LV_SIZE_CONTENT);
	lv_obj_set_x(label1, label_sw_x);
	lv_obj_set_y(label1, label_sw_y+50+50+50);
	lv_obj_set_align(label1, LV_ALIGN_BOTTOM_LEFT);
	lv_label_set_text(label1, "Auto");

	Switch_4 = lv_btn_create(View_3);
	lv_obj_set_width(Switch_4, 77);
	lv_obj_set_height(Switch_4, 33);
	lv_obj_set_x(Switch_4, sw_x);
	lv_obj_set_y(Switch_4, sw_y+50+50+50);
	lv_obj_set_align(Switch_4, LV_ALIGN_CENTER);
	lv_obj_add_flag(Switch_4, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
	lv_obj_clear_flag(Switch_4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
	lv_obj_set_style_bg_color(Switch_4, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(Switch_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	lb_4 = lv_label_create(Switch_4);
	lv_obj_set_align(lb_4, LV_ALIGN_CENTER);
	lv_label_set_text(lb_4, "OFF");
	lv_obj_set_style_text_color(lb_4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(lb_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	label1 = lv_label_create(View_3);
	lv_obj_set_width(label1, LV_SIZE_CONTENT);
	lv_obj_set_height(label1, LV_SIZE_CONTENT);
	lv_obj_set_x(label1, label_sw_x);
	lv_obj_set_y(label1, label_sw_y);
	lv_obj_set_align(label1, LV_ALIGN_BOTTOM_LEFT);
	lv_label_set_text(label1, "Door");

	Switch_1 = lv_btn_create(View_3);
	lv_obj_set_width(Switch_1, 77);
	lv_obj_set_height(Switch_1, 33);
	lv_obj_set_x(Switch_1, sw_x);
	lv_obj_set_y(Switch_1, sw_y);
	lv_obj_set_align(Switch_1, LV_ALIGN_CENTER);
	lv_obj_add_flag(Switch_1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
	lv_obj_clear_flag(Switch_1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
	lv_obj_set_style_bg_color(Switch_1, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(Switch_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	lb_1 = lv_label_create(Switch_1);
	lv_obj_set_align(lb_1, LV_ALIGN_CENTER);
	lv_label_set_text(lb_1, "OFF");
	lv_obj_set_style_text_color(lb_1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(lb_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	View_4 = lv_obj_create(tab2);
	lv_obj_set_width(View_4, 201);
	lv_obj_set_height(View_4, 234);
	lv_obj_set_x(View_4, 89);
	lv_obj_set_y(View_4, -5);
	lv_obj_set_align(View_4, LV_ALIGN_CENTER);
	lv_obj_clear_flag(View_4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
	lv_obj_set_style_border_color(View_4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(View_4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(View_4, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_flag(View_4, LV_OBJ_FLAG_HIDDEN);

//    cover_node_control_2 = lv_obj_create(tab2);
//	lv_obj_set_width(cover_node_control_2, 201);
//	lv_obj_set_height(cover_node_control_2, 234);
//	lv_obj_set_x(cover_node_control_2, 89);
//	lv_obj_set_y(cover_node_control_2, -5);
//	lv_obj_set_align(cover_node_control_2, LV_ALIGN_CENTER);
//	lv_obj_clear_flag(cover_node_control_2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//	lv_obj_set_style_border_color(cover_node_control_2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//	lv_obj_set_style_border_opa(cover_node_control_2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//	lv_obj_set_style_border_width(cover_node_control_2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
//	lv_obj_add_flag(cover_node_control_2 , LV_OBJ_FLAG_HIDDEN);

	View_2_n2 = lv_obj_create(tab2);
	lv_obj_set_width(View_2_n2, 164);
	lv_obj_set_height(View_2_n2, 150);
	lv_obj_set_x(View_2_n2, -107);
	lv_obj_set_y(View_2_n2, 36);
	lv_obj_set_align(View_2_n2, LV_ALIGN_CENTER);
	lv_obj_clear_flag(View_2_n2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
	lv_obj_set_style_border_color(View_2_n2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(View_2_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(View_2_n2, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_add_flag(View_2_n2, LV_OBJ_FLAG_HIDDEN);

    label_arc = lv_label_create(View_2_n2);
    lv_obj_set_width(label_arc, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(label_arc, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(label_arc, 0);
    lv_obj_set_y(label_arc, 62);
    lv_obj_set_align(label_arc, LV_ALIGN_CENTER);
    lv_label_set_text(label_arc, "Auto Temperature");

    label_temp = lv_label_create(View_2_n2);
    lv_obj_set_width(label_temp, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(label_temp, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(label_temp, 0);
    lv_obj_set_y(label_temp, 0);
    lv_obj_set_align(label_temp, LV_ALIGN_CENTER);
    lv_label_set_text(label_temp, "0°C");
    lv_obj_set_style_text_font(label_temp, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);


	arc_n2 = lv_arc_create(View_2_n2);
	lv_obj_set_width(arc_n2, 125);
	lv_obj_set_height(arc_n2, 125);
	lv_obj_set_x(arc_n2, 0);
	lv_obj_set_y(arc_n2, 1);
	lv_obj_set_align(arc_n2, LV_ALIGN_CENTER);
	lv_arc_set_value(arc_n2, 70);

	lv_obj_set_style_bg_color(arc_n2, lv_color_hex(0x000000), LV_PART_INDICATOR | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(arc_n2, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

	lv_obj_set_style_bg_color(arc_n2, lv_color_hex(0xFF0000), LV_PART_KNOB | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(arc_n2, 255, LV_PART_KNOB | LV_STATE_DEFAULT);

	label1 = lv_label_create(View_4);
	lv_obj_set_width(label1, LV_SIZE_CONTENT);
	lv_obj_set_height(label1, LV_SIZE_CONTENT);
	lv_obj_set_x(label1, label_sw_x);
	lv_obj_set_y(label1, label_sw_y+50);
	lv_obj_set_align(label1, LV_ALIGN_BOTTOM_LEFT);
	lv_label_set_text(label1, "Light");

	Switch_2_n2 = lv_btn_create(View_4);
	lv_obj_set_width(Switch_2_n2, 77);
	lv_obj_set_height(Switch_2_n2, 33);
	lv_obj_set_x(Switch_2_n2, sw_x);
	lv_obj_set_y(Switch_2_n2, sw_y+50);
	lv_obj_set_align(Switch_2_n2, LV_ALIGN_CENTER);
	lv_obj_add_flag(Switch_2_n2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
	lv_obj_clear_flag(Switch_2_n2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
	lv_obj_set_style_bg_color(Switch_2_n2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(Switch_2_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	lb_2_N2 = lv_label_create(Switch_2_n2);
	lv_obj_set_align(lb_2_N2, LV_ALIGN_CENTER);
	lv_label_set_text(lb_2_N2, "OFF");
	lv_obj_set_style_text_color(lb_2_N2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(lb_2_N2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	label1 = lv_label_create(View_4);
	lv_obj_set_width(label1, LV_SIZE_CONTENT);
	lv_obj_set_height(label1, LV_SIZE_CONTENT);
	lv_obj_set_x(label1, label_sw_x);
	lv_obj_set_y(label1, label_sw_y+50+50);
	lv_obj_set_align(label1, LV_ALIGN_BOTTOM_LEFT);
	lv_label_set_text(label1, "Fan");

	Switch_3_n2 = lv_btn_create(View_4);
	lv_obj_set_width(Switch_3_n2, 77);
	lv_obj_set_height(Switch_3_n2, 33);
	lv_obj_set_x(Switch_3_n2, sw_x);
	lv_obj_set_y(Switch_3_n2, sw_y+50+50);
	lv_obj_set_align(Switch_3_n2, LV_ALIGN_CENTER);
	lv_obj_add_flag(Switch_3_n2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
	lv_obj_clear_flag(Switch_3_n2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
	lv_obj_set_style_bg_color(Switch_3_n2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(Switch_3_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	lb_3_N2 = lv_label_create(Switch_3_n2);
	lv_obj_set_align(lb_3_N2, LV_ALIGN_CENTER);
	lv_label_set_text(lb_3_N2, "OFF");
	lv_obj_set_style_text_color(lb_3_N2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(lb_3_N2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	label1 = lv_label_create(View_4);
	lv_obj_set_width(label1, LV_SIZE_CONTENT);
	lv_obj_set_height(label1, LV_SIZE_CONTENT);
	lv_obj_set_x(label1, label_sw_x);
	lv_obj_set_y(label1, label_sw_y+50+50+50);
	lv_obj_set_align(label1, LV_ALIGN_BOTTOM_LEFT);
	lv_label_set_text(label1, "Auto");

	Switch_4_n2 = lv_btn_create(View_4);
	lv_obj_set_width(Switch_4_n2, 77);
	lv_obj_set_height(Switch_4_n2, 33);
	lv_obj_set_x(Switch_4_n2, sw_x);
	lv_obj_set_y(Switch_4_n2, sw_y+50+50+50);
	lv_obj_set_align(Switch_4_n2, LV_ALIGN_CENTER);
	lv_obj_add_flag(Switch_4_n2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
	lv_obj_clear_flag(Switch_4_n2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
	lv_obj_set_style_bg_color(Switch_4_n2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(Switch_4_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	lb_4_N2 = lv_label_create(Switch_4_n2);
	lv_obj_set_align(lb_4_N2, LV_ALIGN_CENTER);
	lv_label_set_text(lb_4_N2, "OFF");
	lv_obj_set_style_text_color(lb_4_N2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(lb_4_N2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	label1 = lv_label_create(View_4);
	lv_obj_set_width(label1, LV_SIZE_CONTENT);
	lv_obj_set_height(label1, LV_SIZE_CONTENT);
	lv_obj_set_x(label1, label_sw_x);
	lv_obj_set_y(label1, label_sw_y);
	lv_obj_set_align(label1, LV_ALIGN_BOTTOM_LEFT);
	lv_label_set_text(label1, "Door");

	Switch_1_n2 = lv_btn_create(View_4);
	lv_obj_set_width(Switch_1_n2, 77);
	lv_obj_set_height(Switch_1_n2, 33);
	lv_obj_set_x(Switch_1_n2, sw_x);
	lv_obj_set_y(Switch_1_n2, sw_y);
	lv_obj_set_align(Switch_1_n2, LV_ALIGN_CENTER);
	lv_obj_add_flag(Switch_1_n2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
	lv_obj_clear_flag(Switch_1_n2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
	lv_obj_set_style_bg_color(Switch_1_n2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(Switch_1_n2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	lb_1_N2 = lv_label_create(Switch_1_n2);
	lv_obj_set_align(lb_1_N2, LV_ALIGN_CENTER);
	lv_label_set_text(lb_1_N2, "OFF");
	lv_obj_set_style_text_color(lb_1_N2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(lb_1_N2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	lv_obj_add_event_cb(btn_n2, control_event, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(btn_n1, control_event, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(Switch_1, control_event, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(Switch_2, control_event, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(Switch_3, control_event, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(Switch_4, control_event, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(Switch_1_n2, control_event, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(Switch_2_n2, control_event, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(Switch_3_n2, control_event, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(Switch_4_n2, control_event, LV_EVENT_CLICKED, NULL);

    cover_node_control = lv_obj_create(tab2);
	lv_obj_set_width(cover_node_control, 201);
	lv_obj_set_height(cover_node_control, 234);
	lv_obj_set_x(cover_node_control, 89);
	lv_obj_set_y(cover_node_control, -5);
	lv_obj_set_align(cover_node_control, LV_ALIGN_CENTER);
	lv_obj_clear_flag(cover_node_control, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
	lv_obj_set_style_border_color(cover_node_control, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(cover_node_control, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(cover_node_control, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_clear_flag(cover_node_control, LV_OBJ_FLAG_HIDDEN);
}

//========================================================TAB3=========================================================================
void event_btn_wifi(lv_event_t * e){
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t * obj = lv_event_get_target(e);

	if(code == LV_EVENT_CLICKED && obj == pwd_Pass_wifi ){
		lv_obj_clear_flag(kb_set_pass_wifi, LV_OBJ_FLAG_HIDDEN);
	}
	else if ((code == LV_EVENT_CLICKED) && (obj == Screen_conect_wifi || obj == Screen_conect_wifi_top)){
		lv_obj_add_flag(kb_set_pass_wifi, LV_OBJ_FLAG_HIDDEN);
	}
	else if (code == LV_EVENT_CLICKED && obj == OK){
		timer->paused;
		lv_obj_add_flag(Screen_conect_wifi, LV_OBJ_FLAG_HIDDEN);
		lv_obj_clear_flag(list, LV_OBJ_FLAG_HIDDEN);

		char buf[50];
		sprintf(buf, "Connected to %s.", Get_wifi);
		lv_label_set_text(ui_avaiableLabel, buf);

		WF_SSID = Get_wifi;
		WF_PASS = (char *)lv_textarea_get_text(pwd_Pass_wifi);

		STM_LOG(BOLD_WHITE, TAG, "Connecting to %s, pass = %s", WF_SSID, WF_PASS);
		delay_ms(2);
		ESP32_WiFi_On(WF_SSID, WF_PASS);
		delay_ms(500);
	}
	else if(code == LV_EVENT_CLICKED && obj == cancel){
		lv_obj_add_flag(Screen_conect_wifi, LV_OBJ_FLAG_HIDDEN);
		lv_textarea_set_text(pwd_Pass_wifi, "");
		lv_obj_clear_flag(list, LV_OBJ_FLAG_HIDDEN);
	}
}

void list_event_handler(lv_event_t * e){
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *obj = lv_event_get_target(e);

	if(code == LV_EVENT_CLICKED){
		Get_wifi = (char *)lv_list_get_btn_text(list, obj);
		lv_obj_clear_flag(Screen_conect_wifi, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(list, LV_OBJ_FLAG_HIDDEN);
		lv_textarea_set_text(pwd_Pass_wifi, "");
		char buf[50];
		sprintf(buf, "%s", Get_wifi);
		lv_label_set_text(label_wifi, buf);
	}
}


void Set_ShowWiFi(char *WiFi_Buffer){
	lv_obj_clean(list);
	char buf[50];

	char *num_str = GetData(WiFi_Buffer, 0, ',');
	int num_wifi = atoi(num_str);
	STM_LOG(BOLD_CYAN, TAG, "SCAN RESULT %d WiFi", num_wifi);
	delay_ms(2);

	for(int i=1; i<=num_wifi; ++i){
		char *ssidi = GetData(WiFi_Buffer, i, ',');
		sprintf(buf, "%s", ssidi);
		STM_LOG(BOLD_CYAN, TAG, " WiFi: %s", ssidi);
		delay_ms(2);
		list_btn = lv_list_add_btn(list, LV_SYMBOL_WIFI, buf);
		lv_obj_add_event_cb(list_btn, list_event_handler, LV_EVENT_CLICKED, NULL);
	}

	lv_timer_del(timer);
}


void Set_NetWork_State(char *text){
	if(strcmp(text, "No Internet") == 0){
		lv_obj_del(label_v2);
		label_v2 = lv_label_create(ui_Screen1);
		lv_obj_set_width(label_v2, 38);
		lv_obj_set_height(label_v2, 28);
		lv_obj_set_x(label_v2, -4);
		lv_obj_set_y(label_v2, -287);
		lv_obj_set_align(label_v2, LV_ALIGN_BOTTOM_RIGHT);
		lv_label_set_text(label_v2, LV_SYMBOL_WIFI);
		lv_obj_set_style_text_font(label_v2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
		lv_obj_set_style_text_color(label_v2, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);

		label_v2 = lv_label_create(ui_Screen1);
		lv_obj_set_width(label_v2, 38);
		lv_obj_set_height(label_v2, 28);
		lv_obj_set_x(label_v2, 1);
		lv_obj_set_y(label_v2, -287);
		lv_obj_set_align(label_v2, LV_ALIGN_BOTTOM_RIGHT);
		lv_label_set_text(label_v2, "X");
		lv_obj_set_style_text_font(label_v2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
		lv_obj_set_style_text_color(label_v2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
	}

	else if(strcmp(text,LV_SYMBOL_WIFI) == 0){
		lv_obj_del(label_v2);
		label_v2 = lv_label_create(ui_Screen1);
		lv_obj_set_width(label_v2, 38);
		lv_obj_set_height(label_v2, 28);
		lv_obj_set_x(label_v2, -4);
		lv_obj_set_y(label_v2, -287);
		lv_obj_set_align(label_v2, LV_ALIGN_BOTTOM_RIGHT);
		lv_label_set_text(label_v2, text);
		lv_obj_set_style_text_font(label_v2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
		lv_obj_set_style_text_color(label_v2, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
	}

	else if(strcmp(text, "Eth") == 0){
		lv_obj_del(label_v2);
		label_v2 = lv_label_create(ui_Screen1);
		lv_obj_set_width(label_v2, 148);
		lv_obj_set_height(label_v2, 28);
		lv_obj_set_x(label_v2, -4);
		lv_obj_set_y(label_v2, -287);
		lv_obj_set_align(label_v2, LV_ALIGN_BOTTOM_RIGHT);
		lv_label_set_text(label_v2, text);
		lv_obj_set_style_text_font(label_v2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
		lv_obj_set_style_text_color(label_v2, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
	}
}


void sw_event_cb(lv_event_t * e){
	lv_event_code_t code = lv_event_get_code(e);
	btn_cnt ++;
	if(code == LV_EVENT_VALUE_CHANGED && btn_cnt%2==0){
		lv_obj_clean(list);

		lv_obj_add_flag(list, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(Screen_conect_wifi, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(label,LV_OBJ_FLAG_HIDDEN );
		lv_obj_add_flag(kb_set_pass_wifi, LV_OBJ_FLAG_HIDDEN);

	    lv_obj_clear_flag(ui_avaiableLabel, LV_OBJ_FLAG_HIDDEN);
	    lv_label_set_text(ui_avaiableLabel, "Turn on WiFi to connect.");

		if(!WiFi_Connected && !ETH_Connected) Set_NetWork_State((char *)"No Internet");
		else if(WiFi_Connected && !ETH_Connected) Set_NetWork_State((char *)LV_SYMBOL_WIFI);
		else Set_NetWork_State((char *)"Eth");

	    lv_obj_set_style_text_font(label_v2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
	    lv_obj_set_style_text_color(label_v2, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);

	    ESP32_WiFi_Off();
	}

	else if(code == LV_EVENT_VALUE_CHANGED && btn_cnt%2!=0){
		lv_obj_clear_flag(list, LV_OBJ_FLAG_HIDDEN);
	    lv_label_set_text(ui_avaiableLabel, "Select WiFi to connect to internet.");

//	    lv_label_set_text(label_v2, LV_SYMBOL_WIFI);
		if(!WiFi_Connected && !ETH_Connected) Set_NetWork_State((char *)"No Internet");
		else if(WiFi_Connected && !ETH_Connected) Set_NetWork_State((char *)LV_SYMBOL_WIFI);
		else Set_NetWork_State((char *)"Eth");


	    ESP32_WiFi_Scan();
	    delay_ms(200);
	}
}

void ui_wifi_config(void){
    ui_avaiableLabel = lv_label_create(tab4);
    lv_obj_set_width(ui_avaiableLabel, 295);
    lv_obj_set_height(ui_avaiableLabel, 17);
    lv_obj_set_x(ui_avaiableLabel, -40);
    lv_obj_set_y(ui_avaiableLabel, -90);
    lv_obj_set_align(ui_avaiableLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_avaiableLabel, "To see available networks, turn on wifi");
    lv_obj_set_style_text_color(ui_avaiableLabel, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_avaiableLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);


    ui_avaiableSwitch = lv_switch_create(tab4);
    lv_obj_set_width(ui_avaiableSwitch, 50);
    lv_obj_set_height(ui_avaiableSwitch, 25);
    lv_obj_set_x(ui_avaiableSwitch, 161);
    lv_obj_set_y(ui_avaiableSwitch, -111);
    lv_obj_set_align(ui_avaiableSwitch, LV_ALIGN_CENTER);
    lv_obj_add_event_cb(ui_avaiableSwitch, sw_event_cb, LV_EVENT_VALUE_CHANGED, tab4);

    ui_WiFilabel = lv_label_create(tab4);
    lv_obj_set_width(ui_WiFilabel, 67);
    lv_obj_set_height(ui_WiFilabel, lv_pct(8));
    lv_obj_set_x(ui_WiFilabel, -156);
    lv_obj_set_y(ui_WiFilabel, -117);
    lv_obj_set_align(ui_WiFilabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WiFilabel, "WiFi Setting");
    lv_obj_set_style_text_color(ui_WiFilabel, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_WiFilabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_WiFilabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);


    Screen_conect_wifi = lv_obj_create(tab4);
    lv_obj_set_width(Screen_conect_wifi, 283);
    lv_obj_set_height(Screen_conect_wifi, 124);
    lv_obj_set_x(Screen_conect_wifi, -47);
    lv_obj_set_y(Screen_conect_wifi, -66);
    lv_obj_set_align(Screen_conect_wifi, LV_ALIGN_CENTER);
    lv_obj_clear_flag(Screen_conect_wifi, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(Screen_conect_wifi, lv_color_hex(0x0033FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(Screen_conect_wifi, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(Screen_conect_wifi, LV_OBJ_FLAG_HIDDEN);

    Screen_conect_wifi_top = lv_obj_create(Screen_conect_wifi);
    lv_obj_set_width(Screen_conect_wifi_top, 283);
    lv_obj_set_height(Screen_conect_wifi_top, 30);
    lv_obj_set_x(Screen_conect_wifi_top, 0);
    lv_obj_set_y(Screen_conect_wifi_top, -47);
    lv_obj_set_align(Screen_conect_wifi_top, LV_ALIGN_CENTER);
    lv_obj_clear_flag(Screen_conect_wifi_top, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(Screen_conect_wifi_top, lv_color_hex(0x0033FF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(Screen_conect_wifi_top, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    label_wifi = lv_label_create(Screen_conect_wifi_top);
    lv_label_set_text(label_wifi, "");
    lv_obj_set_style_text_color(label_wifi, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_align(label_wifi, LV_ALIGN_CENTER);

    pwd_Pass_wifi = lv_textarea_create(Screen_conect_wifi);
    lv_obj_set_width(pwd_Pass_wifi, 283);
    lv_obj_set_height(pwd_Pass_wifi, 30);
    lv_obj_set_x(pwd_Pass_wifi, 0);
    lv_obj_set_y(pwd_Pass_wifi, -10);
    lv_obj_set_align(pwd_Pass_wifi, LV_ALIGN_CENTER);
    lv_obj_clear_flag(pwd_Pass_wifi, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_textarea_set_one_line(pwd_Pass_wifi, true);
    lv_textarea_set_placeholder_text(pwd_Pass_wifi, "Pass");

    kb_set_pass_wifi = lv_keyboard_create(tab4);
    lv_obj_set_size(kb_set_pass_wifi,  400, 168);
    lv_keyboard_set_textarea(kb_set_pass_wifi, pwd_Pass_wifi); /*Focus it on one of the text areas to start*/
    lv_obj_add_flag(kb_set_pass_wifi, LV_OBJ_FLAG_HIDDEN);

    OK = lv_btn_create(Screen_conect_wifi);
    lv_obj_set_width(OK, 100);
    lv_obj_set_height(OK, 37);
    lv_obj_set_x(OK, -76);
    lv_obj_set_y(OK, 33);
    lv_obj_set_align(OK, LV_ALIGN_CENTER);
    lv_obj_clear_flag(OK, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    label = lv_label_create(OK);
    lv_label_set_text(label, "OK");
    lv_obj_set_align(label, LV_ALIGN_CENTER);


    cancel = lv_btn_create(Screen_conect_wifi);
    lv_obj_set_width(cancel, 100);
    lv_obj_set_height(cancel, 37);
    lv_obj_set_x(cancel, 77);
    lv_obj_set_y(cancel, 33);
    lv_obj_set_align(cancel, LV_ALIGN_CENTER);
    lv_obj_clear_flag(cancel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(cancel, lv_color_hex(0xFFFFFF),LV_PART_MAIN | LV_STATE_DEFAULT );
    label = lv_label_create(cancel);
    lv_label_set_text(label, "cancel");
    lv_obj_set_style_text_color(label, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
    lv_obj_set_align(label, LV_ALIGN_CENTER);


    list = lv_list_create(tab4);
    lv_obj_set_size(list, 360, 190);
    lv_obj_center(list);
    lv_obj_set_x(list, 3);
    lv_obj_set_y(list, 20);
    lv_obj_add_flag(list, LV_OBJ_FLAG_HIDDEN);

	lv_obj_add_event_cb(pwd_Pass_wifi, event_btn_wifi, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(Screen_conect_wifi, event_btn_wifi, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(Screen_conect_wifi_top, event_btn_wifi, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(OK, event_btn_wifi, LV_EVENT_CLICKED, NULL);
	lv_obj_add_event_cb(cancel, event_btn_wifi, LV_EVENT_CLICKED, NULL);

}


void Top_ui(){
	label_time = lv_label_create(ui_Screen1);
    lv_obj_set_width(label_time, 200);
    lv_obj_set_height(label_time, 28);
    lv_obj_set_x(label_time, -130);
    lv_obj_set_y(label_time, -142);
    lv_obj_set_align(label_time, LV_ALIGN_CENTER);
    lv_label_set_text(label_time, "00:00:00");
    lv_obj_set_style_text_color(label_time, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(label_time, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(label_time, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
//    lv_obj_add_event_cb(label_v2, event_update, LV_EVENT_ALL, NULL);
//    lv_timer_create(update_data, 30, label_time);


    label_date = lv_label_create(ui_Screen1);
    lv_obj_set_width(label_date, 233);
    lv_obj_set_height(label_date, 16);
    lv_obj_set_x(label_date, -115);
    lv_obj_set_y(label_date, -118);
    lv_obj_set_align(label_date, LV_ALIGN_CENTER);
    lv_label_set_text(label_date, "Th2, 21/12/2022");
    lv_obj_set_style_text_color(label_date, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(label_date, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    label_v2 = lv_label_create(ui_Screen1);
    lv_obj_set_width(label_v2, 38);
    lv_obj_set_height(label_v2, 28);
    lv_obj_set_x(label_v2, -4);
    lv_obj_set_y(label_v2, -287);
    lv_obj_set_align(label_v2, LV_ALIGN_BOTTOM_RIGHT);
    lv_label_set_text(label_v2, LV_SYMBOL_WIFI);
    lv_obj_set_style_text_font(label_v2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label_v2, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);

    label_v2 = lv_label_create(ui_Screen1);
    lv_obj_set_width(label_v2, 38);
    lv_obj_set_height(label_v2, 28);
    lv_obj_set_x(label_v2, 2);
    lv_obj_set_y(label_v2, -287);
    lv_obj_set_align(label_v2, LV_ALIGN_BOTTOM_RIGHT);
    lv_label_set_text(label_v2, "X");
    lv_obj_set_style_text_font(label_v2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(label_v2, lv_color_hex(0xFF3300), LV_PART_MAIN | LV_STATE_DEFAULT);
}


void Set_Show_Time(void){
	char buf[15];
	DS3231_GetTime(&time);
	sprintf(buf, "Th%1d, %02d/%02d/20%02d", time.dayofweek, time.dayofmonth, time.month, time.year);
	lv_label_set_text(label_date, buf);
	sprintf(buf, "%02d:%02d:%02d", time.hour, time.minutes, time.seconds);
	lv_label_set_text(label_time, buf);
}

//================================================================UI_setting===========================================================================
void Set_MQTT(char *URL, char *USER, char *PASS){
	ESP32_MQTT_Stop();
	delay_ms(500);
	ESP32_MQTT_Config(URL, USER, PASS);
	delay_ms(500);
	ESP32_MQTT_Start();
	delay_ms(500);
}

void mbox_event(lv_event_t * e){
	lv_event_code_t code = lv_event_get_code(e);
	lv_obj_t *btn = lv_event_get_target(e);
	if(btn == mboxConnectBtn && code == LV_EVENT_CLICKED){
		MQTT_URL = (char *)lv_textarea_get_text(pwd_ta);
	    lv_label_set_text(animation_1, MQTT_URL);
	    Set_MQTT(MQTT_URL, MQTT_USER, MQTT_PASS);
	}
	else if((btn == mbox_btn_password || btn == mbox_btn_user) && (code == LV_EVENT_CLICKED)){
		lv_obj_clear_flag(mbox_of_pass, LV_OBJ_FLAG_HIDDEN);
	}
	else if(btn == pwd_ta && code == LV_EVENT_CLICKED){
		lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(kb_User, LV_OBJ_FLAG_HIDDEN);
	}
	else if(btn == pwd_ta_Pass && code == LV_EVENT_CLICKED){
		lv_obj_clear_flag(kb_Pass, LV_OBJ_FLAG_HIDDEN);
	}
	else if(btn == pwd_ta_User && code == LV_EVENT_CLICKED){
		lv_obj_clear_flag(kb_User, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(kb_Pass, LV_OBJ_FLAG_HIDDEN);
	}
	else if(btn == mbox_of_pass && code == LV_EVENT_CLICKED){
		lv_obj_add_flag(kb_User, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(kb_Pass, LV_OBJ_FLAG_HIDDEN);
	}

	else if(btn == Done && code == LV_EVENT_CLICKED){
		lv_obj_add_flag(kb_User, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(kb_Pass, LV_OBJ_FLAG_HIDDEN);
		lv_obj_add_flag(mbox_of_pass, LV_OBJ_FLAG_HIDDEN);

		MQTT_USER = (char *)lv_textarea_get_text(pwd_ta_User);
		MQTT_PASS = (char *)lv_textarea_get_text(pwd_ta_Pass);

		lv_label_set_text(label_user, MQTT_USER);
		lv_label_set_text(label_pass, MQTT_PASS);
	}
}

void KB_CLEAR_HIDDEN(void){
	lv_obj_clear_flag(kb, LV_OBJ_FLAG_HIDDEN);
}

void hight_url_event_cb_label (lv_event_cb_t * e){
	lv_event_code_t code = lv_event_get_code((lv_event_t *)e);
	if(code == LV_EVENT_CLICKED){
		lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
	}
}

void hight_url_event_cb (lv_event_t * e){
	lv_obj_add_flag(mbox_of_pass, LV_OBJ_FLAG_HIDDEN);
	lv_event_code_t code = lv_event_get_code(e);
	btn_hight_url++;
	if(code == LV_EVENT_CLICKED &&  btn_hight_url%2==0){
		lv_obj_del(animation_1);

//	    lv_obj_add_flag(pwd_ta, LV_OBJ_FLAG_HIDDEN);
	    lv_obj_add_flag(mbox, LV_OBJ_FLAG_HIDDEN);
	    lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);

	    animation_1 = lv_label_create(btn_url);
	    lv_label_set_long_mode(animation_1, LV_LABEL_LONG_SCROLL_CIRCULAR);
	    lv_obj_align(animation_1, LV_ALIGN_CENTER, 0, 0);
	    lv_obj_set_width(animation_1, 190);
	    lv_label_set_text(animation_1,lv_textarea_get_text(pwd_ta));
	    lv_obj_add_style(animation_1, &label_style, LV_STATE_DEFAULT);
	    lv_obj_set_style_text_color(animation_1, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
	    lv_obj_set_style_text_opa(animation_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

	}

	else if(code == LV_EVENT_CLICKED &&  btn_hight_url%2!=0){
		lv_obj_del(animation_1);
//	    lv_obj_clear_flag(pwd_ta, LV_OBJ_FLAG_HIDDEN);
	    lv_obj_clear_flag(mbox, LV_OBJ_FLAG_HIDDEN);
//	    KB_CLEAR_HIDDEN();

	    animation_1 = lv_label_create(btn_url);
	    lv_label_set_long_mode(animation_1, LV_LABEL_LONG_SCROLL_CIRCULAR);
	    lv_obj_align(animation_1, LV_ALIGN_CENTER, 0, 0);
	    lv_obj_set_width(animation_1, 190);
	    lv_label_set_text(animation_1,lv_textarea_get_text(pwd_ta));
	    lv_obj_add_style(animation_1, &label_style, LV_STATE_DEFAULT);
	    lv_obj_set_style_text_color(animation_1, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
	    lv_obj_set_style_text_opa(animation_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	}

}




void ui_setting(void){
    lv_anim_init(&animation_template);
    lv_style_init(&label_style);
    lv_style_set_anim(&label_style, &animation_template);


    label1 = lv_obj_create(tab3);
    lv_obj_set_width(label1, 374);
    lv_obj_set_height(label1, 33);
    lv_obj_set_x(label1, 1);
    lv_obj_set_y(label1, -113);
    lv_obj_set_align(label1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(label1, LV_OBJ_FLAG_SCROLLABLE);

    label2 = lv_obj_create(tab3);
    lv_obj_set_width(label2, 191);
    lv_obj_set_height(label2, 195);
    lv_obj_set_x(label2, -94);
    lv_obj_set_y(label2, 11);
    lv_obj_set_align(label2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(label2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    label3 = lv_obj_create(tab3);
    lv_obj_set_width(label3, 171);
    lv_obj_set_height(label3, 194);
    lv_obj_set_x(label3, 100);
    lv_obj_set_y(label3, 12);
    lv_obj_set_align(label3, LV_ALIGN_CENTER);
    lv_obj_clear_flag(label3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags


	btn_url = lv_btn_create(label1);
    lv_obj_set_width(btn_url, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(btn_url, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(btn_url, 110);
    lv_obj_set_y(btn_url, 2);
    lv_obj_set_align(btn_url, LV_ALIGN_CENTER);
    lv_obj_add_flag(btn_url, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(btn_url, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
	lv_obj_set_style_bg_color(btn_url, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(btn_url, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(btn_url, lv_color_hex(0x7D7D7D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(btn_url, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(btn_url, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(btn_url, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    animation_1 = lv_label_create(btn_url);
    lv_label_set_long_mode(animation_1, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_align(animation_1, LV_ALIGN_CENTER, -30, 0);
    lv_obj_set_width(animation_1, 230);
    lv_label_set_text(animation_1, "mqtt://homethang.duckdns.org");
    lv_obj_add_style(animation_1, &label_style, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(animation_1, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(animation_1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(btn_url, hight_url_event_cb, LV_EVENT_CLICKED, NULL);

    mbox = lv_obj_create(tab3);
    lv_obj_set_width(mbox, 387);
    lv_obj_set_height(mbox, 211);
    lv_obj_set_x(mbox, 2);
    lv_obj_set_y(mbox, 14);
    lv_obj_set_align(mbox, LV_ALIGN_CENTER);
    lv_obj_clear_flag(mbox, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(mbox, lv_color_hex(0x7D7D7D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(mbox, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(mbox, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(mbox, LV_OBJ_FLAG_HIDDEN);
//    lv_obj_add_event_cb(mbox, hight_url_event_cb_labe, LV_EVENT_CLICKED, NULL);

    label = lv_label_create(label1);
    lv_obj_set_width(label, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(label, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(label, -110);
    lv_obj_set_y(label, 0);
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    lv_obj_set_style_text_color(animation_1, lv_color_hex(0x808080), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_text(label, "MQTT Server URL: ");


    btn_set_url = lv_btn_create(mbox);
    lv_obj_set_width(btn_set_url, 211);
    lv_obj_set_height(btn_set_url, 50);
    lv_obj_set_x(btn_set_url, 1);
    lv_obj_set_y(btn_set_url, -93);
    lv_obj_set_align(btn_set_url, LV_ALIGN_CENTER);
    lv_obj_add_flag(btn_set_url, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(btn_set_url, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_style_bg_color(btn_set_url, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(btn_set_url, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(btn_set_url, lv_color_hex(0x444444), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(btn_set_url, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(btn_set_url, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(btn_set_url, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    mbox_btn_user = lv_obj_create(mbox);
//    lv_textarea_set_text(mbox_btn_user, "");
    lv_obj_set_x(mbox_btn_user, -78);
    lv_obj_set_y(mbox_btn_user, -1);
    lv_obj_set_width(mbox_btn_user, 165);
    lv_obj_set_height(mbox_btn_user, 50);
//    lv_textarea_set_password_mode(mbox_btn_user, false);
//    lv_textarea_set_one_line(mbox_btn_user, true);
    lv_obj_set_align(mbox_btn_user, LV_ALIGN_CENTER);
//    lv_label_set_text(mbox_btn_user,"User");

	label_user = lv_label_create(mbox_btn_user);
    lv_obj_set_align(label_user, LV_ALIGN_CENTER);
    lv_label_set_text(label_user, "User");

    mbox_btn_password = lv_obj_create(mbox);
    lv_obj_set_x(mbox_btn_password, -78);
    lv_obj_set_y(mbox_btn_password, 64);
    lv_obj_set_width(mbox_btn_password, 165);
    lv_obj_set_height(mbox_btn_password, 45);
    lv_obj_set_align(mbox_btn_password, LV_ALIGN_CENTER);
    lv_obj_clear_flag(mbox_btn_password, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
//    lv_label_set_text(mbox_btn_password,"Pass");
	label_pass = lv_label_create(mbox_btn_password);
    lv_obj_set_align(label_pass, LV_ALIGN_CENTER);
    lv_label_set_text(label_pass, "Pass");

    pwd_ta = lv_textarea_create(mbox);
    lv_textarea_set_text(pwd_ta, "");
    lv_obj_set_x(pwd_ta, 3);
    lv_obj_set_y(pwd_ta, -68);
    lv_obj_set_width(pwd_ta, 324);
    lv_obj_set_height(pwd_ta, 50);
    lv_textarea_set_password_mode(pwd_ta, false);
    lv_textarea_set_one_line(pwd_ta, true);
    lv_obj_set_align(pwd_ta, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(pwd_ta, "MQTT server url...");

    kb = lv_keyboard_create(tab3);
    lv_obj_set_size(kb,  387, 149);
    lv_keyboard_set_textarea(kb, pwd_ta); /*Focus it on one of the text areas to start*/
    lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);

	mboxConnectBtn = lv_btn_create(mbox);
    lv_obj_set_width(mboxConnectBtn, 123);
    lv_obj_set_height(mboxConnectBtn, 40);
    lv_obj_set_x(mboxConnectBtn, 115);
    lv_obj_set_y(mboxConnectBtn, 64);
    lv_obj_set_align(mboxConnectBtn, LV_ALIGN_CENTER);
//	lv_obj_set_style_bg_color(mboxConnectBtn, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
//    lv_obj_set_style_bg_opa(mboxConnectBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
//    lv_obj_set_style_border_color(mboxConnectBtn, lv_color_hex(0x777777), LV_PART_MAIN | LV_STATE_DEFAULT);
//    lv_obj_set_style_border_opa(mboxConnectBtn, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
//    lv_obj_set_style_shadow_color(mboxConnectBtn, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
//    lv_obj_set_style_shadow_opa(mboxConnectBtn, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

	mbox_of_pass = lv_obj_create(tab3);
    lv_obj_set_width(mbox_of_pass, 387);
    lv_obj_set_height(mbox_of_pass, 211);
    lv_obj_set_x(mbox_of_pass, 2);
    lv_obj_set_y(mbox_of_pass, 14);
    lv_obj_set_align(mbox_of_pass, LV_ALIGN_CENTER);
    lv_obj_clear_flag(mbox_of_pass, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(mbox_of_pass, lv_color_hex(0x7D7D7D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(mbox_of_pass, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(mbox_of_pass, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_flag(mbox_of_pass, LV_OBJ_FLAG_HIDDEN);

    Done = lv_obj_create(mbox_of_pass);
    lv_obj_set_x(Done, 100);
    lv_obj_set_y(Done, 70);
    lv_obj_set_width(Done, 165);
    lv_obj_set_height(Done, 45);
    lv_obj_set_align(Done, LV_ALIGN_CENTER);
    lv_obj_clear_flag(Done, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_add_event_cb(Done, mbox_event, LV_EVENT_CLICKED, NULL);


    label_Done = lv_label_create(Done);
    lv_label_set_text(label_Done,"Done");
    lv_obj_set_width(label_Done, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(label_Done, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(label_Done, LV_ALIGN_CENTER);


    pwd_ta_User = lv_textarea_create(mbox_of_pass);
    lv_textarea_set_text(pwd_ta_User, "");
    lv_obj_set_x(pwd_ta_User, -100);
    lv_obj_set_y(pwd_ta_User, -70);
    lv_obj_set_width(pwd_ta_User, 165);
    lv_obj_set_height(pwd_ta_User, 40);
    lv_textarea_set_password_mode(pwd_ta_User, false);
    lv_textarea_set_one_line(pwd_ta_User, true);
    lv_obj_set_align(pwd_ta_User, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(pwd_ta_User, "User");

    kb_User = lv_keyboard_create(mbox_of_pass);
    lv_obj_set_size(kb_User,  387, 149);
    lv_obj_set_y(kb_User, 20);
    lv_keyboard_set_textarea(kb_User, pwd_ta_User); /*Focus it on one of the text areas to start*/
    lv_obj_add_flag(kb_User, LV_OBJ_FLAG_HIDDEN);

    pwd_ta_Pass = lv_textarea_create(mbox_of_pass);
    lv_textarea_set_text(pwd_ta_Pass, "");
    lv_obj_set_x(pwd_ta_Pass, 100);
    lv_obj_set_y(pwd_ta_Pass, -70);
    lv_obj_set_width(pwd_ta_Pass, 165);
    lv_obj_set_height(pwd_ta_Pass, 50);
    lv_textarea_set_password_mode(pwd_ta_Pass, true);
    lv_textarea_set_one_line(pwd_ta_Pass, true);
    lv_obj_set_align(pwd_ta_Pass, LV_ALIGN_CENTER);
    lv_textarea_set_placeholder_text(pwd_ta_Pass, "Pass");

    kb_Pass = lv_keyboard_create(mbox_of_pass);
    lv_obj_set_size(kb_Pass,  387, 149);
    lv_obj_set_y(kb_Pass, 20);
    lv_keyboard_set_textarea(kb_Pass, pwd_ta_Pass); /*Focus it on one of the text areas to start*/
    lv_obj_add_flag(kb_Pass, LV_OBJ_FLAG_HIDDEN);




	lv_obj_t *btnLabel = lv_label_create(mboxConnectBtn);
    lv_obj_set_style_text_color(btnLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(btnLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
	lv_label_set_text(btnLabel, "Connect");
	lv_obj_center(btnLabel);

	lv_obj_add_event_cb(mboxConnectBtn, mbox_event, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(mbox, (lv_event_cb_t)hight_url_event_cb_label, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(pwd_ta, (lv_event_cb_t)mbox_event, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(mbox_of_pass, (lv_event_cb_t)mbox_event, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(pwd_ta_Pass,(lv_event_cb_t)mbox_event, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(pwd_ta_User, (lv_event_cb_t)mbox_event, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(mbox_btn_password, (lv_event_cb_t)mbox_event, LV_EVENT_CLICKED, NULL);
    lv_obj_add_event_cb(mbox_btn_user, (lv_event_cb_t)mbox_event, LV_EVENT_CLICKED, NULL);

}

void init_lib(void)
{
	tab_left();
	Chart_ui_tab_1();
	ui_tab_control();
	ui_wifi_config();
	Top_ui();
	ui_setting();
}
