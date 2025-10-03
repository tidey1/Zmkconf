#include <zmk/display/widgets/layer_status.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/display/widgets/output_status.h>
#include <zmk/display/status_screen.h>
#include <lvgl.h>

LV_IMG_DECLARE(zmk_logo); /* optional, if you want a logo */

static struct zmk_widget_layer_status layer_status_widget;
static struct zmk_widget_battery_status battery_status_widget;
static struct zmk_widget_output_status output_status_widget;

lv_obj_t *zmk_display_status_screen(void) {
    lv_obj_t *screen = lv_obj_create(NULL);

    lv_obj_t *layer = zmk_widget_layer_status_create(screen);
    lv_obj_align(layer, LV_ALIGN_TOP_MID, 0, 0);

    lv_obj_t *battery = zmk_widget_battery_status_create(screen);
    lv_obj_align(battery, LV_ALIGN_BOTTOM_LEFT, 0, 0);

    lv_obj_t *output = zmk_widget_output_status_create(screen);
    lv_obj_align(output, LV_ALIGN_BOTTOM_RIGHT, 0, 0);

    return screen;
}
