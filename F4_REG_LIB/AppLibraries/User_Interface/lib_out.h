//#ifndef _SQUARELINE_PROJECT_UI_COMP_H
//#define _SQUARELINE_PROJECT_UI_COMP_H

#ifdef __cplusplus
extern "C"{
#endif

#include "lvgl.h"


extern lv_obj_t * ui_Screen1_Image99;

extern lv_obj_t * chart;
extern lv_chart_series_t * ser;
extern lv_chart_cursor_t * cursor;

extern uint32_t point_one;

//extern lv_chart_series_t * ser_one;

/////////////////////////////////////TAB/////////////////////////////////
extern lv_obj_t * tabview;
extern lv_obj_t * text_label;

extern lv_obj_t * tab1;
extern lv_obj_t * tab2;
extern lv_obj_t * tab3;
extern lv_obj_t * tab4;

extern lv_obj_t * label1;

extern lv_obj_t * ui_TempChartChange_test;
extern lv_obj_t * ui_HumidityChartChange_test;
extern lv_obj_t * label;
void ui_tab1_screen_init(lv_obj_t * tab);


//================================TAB_WIFI_CONFIG==============================
extern lv_obj_t * ui_avaiableLabel;
extern lv_obj_t * ui_avaiableSwitch;
extern lv_obj_t * ui_WiFilabel;


void ui_wifi_config(void);
void init_lib(void);

void Image_Screen(void);
void update_Chart_Node1(float temp, float humi);
void update_Chart_Node2(float temp, float humi);

void Set_ShowNode1(float temp, float humi);
void Set_ShowNode2(float temp, float humi);
void Set_Show_Time(void);
void Set_Control_Switch(int id, char *relay, char *state);

void Set_MQTT(char *URL, char *USER, char *PASS);
// 1045
void Set_ShowWiFi(char *WiFi_Buffer);
void Set_NetWork_State(char *text);

void UI_EnableNode1(void);
void UI_DisableNode1(void);
void UI_EnableNode2(void);
void UI_DisableNode2(void);
//===================================TAB_SETTING================================
extern lv_obj_t * btn_url;
extern lv_obj_t * Screen_conect_wifi_top;
extern lv_obj_t * ui_avaiableLabel;


#ifdef __cplusplus
}
#endif

//#endif
