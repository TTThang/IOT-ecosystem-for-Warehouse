#include "esp_event.h"
#include "mqtt_client.h"
#include "driver/gpio.h"
#include "hal/gpio_types.h"

#include "esp_log.h"

#define MAX_NUM_NODE 3

extern bool Node_Id[MAX_NUM_NODE+1];

extern QueueHandle_t MQTT_Data_Queue_Handle;
extern esp_mqtt_client_handle_t Client;
extern esp_mqtt_client_config_t mqtt_cfg;

bool InitWarehouse(char* index);
bool DenitWarehouse(char* index);

void mqtt_start(void *arg);
bool publish_data_sensor(char* id, char* temp, char* humi);
bool publish_data_switch(char* id, char* device, char* payload);
void mqtt_stop(void *arg);
