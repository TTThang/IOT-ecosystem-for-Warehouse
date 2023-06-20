
LoRa lora;

void delay(int msec) {
    vTaskDelay(msec / portTICK_PERIOD_MS);
}

void task_tx(char* send){
    lora.setSyncWord(0xDF);
    lora.beginPacket(false);
    lora.write((uint8_t*)send, (size_t)strlen(send));
    lora.endPacket(false);
    lora.setSyncWord(0xFF);
    lora.receive(0);
    ESP_LOGE(TAG, "Sended: %s",send);
    delay(10);
}

void task_rx() {
    if (lora.getDataReceived()) {
        if (msg[0] == '\0') {
            lora.handleDataReceived(msg);
            lora.setDataReceived(false);
            ESP_LOGI(TAG, "%s", msg);
        }
    }
    delay(10);
}

void free_heap_task(void* cc) {
    while (1) {
        ESP_LOGW(TAG, "Free heap: %u", esp_get_free_heap_size());
        delay(1000);
    }
}

void copy_data(char* data, char* dt) {
    for ( int i = 0; i < strlen(data); i++)
        *dt++ = data[i];
    *dt = '\0';
}

void split_string() {
    char *data = strtok(msg, " ");
    copy_data(data, data1);
    while (data != NULL) {
        data = strtok(NULL, ",");
        if (data != NULL) {
            if (data2[0] == '\0')
                copy_data(data, data2);
            else if (data3[0] == '\0')
                copy_data(data, data3);
            else if (data4[0] == '\0')
                copy_data(data, data4);
        }
    }
}

void job() {
    char data[25];
    if (strcmp((const char*)data1, "CONTROL:") == 0) {
        write_pcf8574((const char*)data3, (const char*)data4);
        sprintf(data, "%s %s,%s,%s",data1, ID, data3 , data4);
        task_tx(data);
    }
    else if (strcmp((const char*)data1, "DATA:") == 0) {
        float temp, humi;
        sht31_read_temp_humi(&temp, &humi);
        sprintf(data, "%s %s,%0.2f,%0.2f",data1, ID, temp , humi);
        task_tx(data);
    }
}

int check_id(char* id) {
    int ind = 0;
    for (int i = 0; i < strlen(id); i++) {
        if (id[i] < '0' || id[i] > '9')
            return 0;
        ind = ind * 10 + id[i] - 48;
    }
    if (ind < 1 || ind > 2)
        return 0;
    return 1;
}