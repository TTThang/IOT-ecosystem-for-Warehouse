#include "driver/rtc_io.h"
//#define BUTTON GPIO_NUM_25

RTC_DATA_ATTR int timesWokenUp = 0;

void deep_sleep_EXT_0(void)
{
    gpio_num_t BUTTON = (gpio_num_t)PIN_NUM_DIO;
    rtc_gpio_deinit(BUTTON);

    rtc_gpio_pullup_en(BUTTON);
    rtc_gpio_pulldown_dis(BUTTON);

    esp_sleep_enable_ext0_wakeup(BUTTON, 1);

    printf("going to sleep. woken up %d\n", timesWokenUp++);

    esp_deep_sleep_start();
}

#define BUTTON_1 GPIO_NUM_25
#define BUTTON_2 GPIO_NUM_26

void deep_sleep_EXT_1(void)
{
    rtc_gpio_deinit(BUTTON_1);
    rtc_gpio_deinit(BUTTON_2);
    
    esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_ON);
    rtc_gpio_pullup_en(BUTTON_1);
    rtc_gpio_pulldown_dis(BUTTON_1);
    rtc_gpio_pullup_en(BUTTON_2);
    rtc_gpio_pulldown_dis(BUTTON_2);

    uint64_t mask = (1ULL << BUTTON_1) | (1ULL << BUTTON_2);
    esp_sleep_enable_ext1_wakeup(mask, ESP_EXT1_WAKEUP_ALL_LOW);
    printf("going to sleep. woken up %d\n", timesWokenUp++);

    esp_deep_sleep_start();
}

#define Time    2

void deep_sleep_timer(void)
{
    esp_sleep_enable_timer_wakeup(Time * 1000000);
    printf("going to sleep. woken up %d\n", timesWokenUp++);

    esp_deep_sleep_start();
}