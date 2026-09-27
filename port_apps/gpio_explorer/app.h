#ifndef APP_H
#define APP_H

#include "storage_manager.h"
#include "gpio_explorer_app_struct.h"
#include "gpio_explorer_led_struct.h"
#include "gpio_explorer_rgb_struct.h"
#include "gpio_explorer_gpio_reader_struct.h"
#include "gpio_explorer_submenu_index_enum.h"
#include "gpio_explorer_view_enum.h"

#define TAG "GPIOExplorer"
#define BACKLIGHT_ON 0
#define ON 1
#define OFF 0
#define PIN_R_CONFIG_LABEL   "RGB R Pin"
#define PIN_G_CONFIG_LABEL   "RGB G Pin"
#define PIN_B_CONFIG_LABEL   "RGB B Pin"
#define PIN_LED_CONFIG_LABEL "LED Pin"

/*
 * Cardputer-ADV exposes only the Grove/Qwiic pins as safe user GPIO:
 * GPIO2 = SDA, GPIO1 = SCL.
 * Do not expose the Flipper PA/PB/PC aliases here: on this port several of
 * those aliases are wired to the shared CC1101/SD SPI bus.
 */
#define DEFAULT_LED_PIN   0
#define DEFAULT_RGB_R_PIN 0
#define DEFAULT_RGB_G_PIN 1
#define DEFAULT_RGB_B_PIN 0

static const char* const rgb_setting_pins[] = {"G2 (SDA)", "G1 (SCL)"};
static const char* const rgb_colors[] =
    {"White", "Red", "Green", "Blue", "Purple", "Yellow", "Cyan"};

static const GpioPin* const pins[] = {
    gpio_pins[0].pin,
    gpio_pins[1].pin,
};

int32_t main_gpio_explorer_app(void* _p);

#endif
