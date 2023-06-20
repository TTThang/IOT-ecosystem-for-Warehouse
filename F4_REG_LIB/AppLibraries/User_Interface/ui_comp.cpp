// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.3.3
// PROJECT: SquareLine_Project


#include "ui.h"
#include "ui_helpers.h"
#include "ui_comp.h"

uint32_t LV_EVENT_GET_COMP_CHILD;

typedef struct {
    uint32_t child_idx;
    lv_obj_t *child;
} ui_comp_get_child_t;

lv_obj_t * ui_comp_get_child(lv_obj_t * comp, uint32_t child_idx)
{
    ui_comp_get_child_t info;
    info.child = NULL;
    info.child_idx = child_idx;
    lv_event_send(comp, (lv_event_code_t)LV_EVENT_GET_COMP_CHILD, &info);
    return info.child;
}

void get_component_child_event_cb(lv_event_t * e)
{
	lv_obj_t *tmp = (lv_obj_t *)lv_event_get_user_data(e);
    ui_comp_get_child_t *info = (ui_comp_get_child_t *)lv_event_get_param(e);

    info->child = (lv_obj_t *)&tmp[info->child_idx];
}

void del_component_child_event_cb(lv_event_t * e)
{
	void *c = lv_event_get_user_data(e);
    lv_mem_free(c);
}


// COMPONENT Screen1 ImgButton2

lv_obj_t * ui_Screen1_ImgButton2_create(lv_obj_t * comp_parent)
{

    lv_obj_t *cui_Screen1_ImgButton2;
    cui_Screen1_ImgButton2 = lv_imgbtn_create(comp_parent);
    lv_obj_set_height(cui_Screen1_ImgButton2, 64);
    lv_obj_set_width(cui_Screen1_ImgButton2, LV_SIZE_CONTENT);   /// 100
    lv_obj_set_x(cui_Screen1_ImgButton2, -151);
    lv_obj_set_y(cui_Screen1_ImgButton2, -14);
    lv_obj_set_align(cui_Screen1_ImgButton2, LV_ALIGN_CENTER);

    lv_obj_t *children = (lv_obj_t *)lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_SCREEN1_IMGBUTTON2_NUM);
    children = cui_Screen1_ImgButton2;
    lv_obj_add_event_cb(cui_Screen1_ImgButton2, get_component_child_event_cb, (lv_event_code_t)LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_Screen1_ImgButton2, del_component_child_event_cb, LV_EVENT_DELETE, children);
    return cui_Screen1_ImgButton2;
}

