#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <esp_log.h>
#include "driver/gpio.h"
#include "driver/i2c.h"
#include "esp_sleep.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define PIN_NUM_MISO    19
#define PIN_NUM_MOSI    23
#define PIN_NUM_CLK     18
#define PIN_NUM_CS      22
#define PIN_NUM_DIO     25
#define RESET_PIN       21
#define TIME            10

const char* TAG = "Node";

char ID[2] = { '\0' }, msg[25] = { '\0' }, data1[8] = { '\0' }, data2[2] = { '\0' }, data3[6] = { '\0' }, data4[3] = { '\0' };

#include "lora.h"
#include "sht31.h"
#include "pcf8574.h"
#include "modun.h"

extern "C" void app_main() {
    lora.initialize(PIN_NUM_MOSI, PIN_NUM_MISO, PIN_NUM_CLK, PIN_NUM_CS, RESET_PIN, PIN_NUM_DIO, 10);
    pcf8574_init();
    sht31_init();

    while (ID[0] == '\0') {
        task_tx((char*)"NEW: *");
        int64_t start = esp_timer_get_time();
        while ((esp_timer_get_time() - start) <= (TIME * 1000000)) {
            if (lora.getDataReceived()) {
                lora.handleDataReceived(ID);
                lora.setDataReceived(false);
                ESP_LOGI(TAG, "%s", ID);  
                if (ID[0] != '\0') {
                    if (check_id(ID) == 1) {
                        char data[8];
                        sprintf(data, "NEW: %s", ID);
                        task_tx(data);
                        break;
                    }
                    else
                        ID[0] = '\0';
                }
            }
        delay(10);
        }
    }
 
    //xTaskCreate(&free_heap_task, " ", 2048, NULL, 0, NULL);

    while (1) {    
        task_rx();
        if (msg[0] != '\0') {
            split_string();
            ESP_LOGE(TAG, "ID: %s", ID);
            if (data2[0] == '\0' || (strcmp((const char*)data2, (const char*)ID) != 0 && strcmp((const char*)data2, "*") != 0))
                ESP_LOGE(TAG, "ID from Gateway ERROR!");
            else
                job();
            msg[0] = '\0'; data1[0] = '\0'; data2[0] = '\0'; data3[0] = '\0'; data4[0] = '\0';
        }
        else
            ESP_LOGW(TAG, "Deo co con cac gi!!!!!!");
        delay(10);
    }
}