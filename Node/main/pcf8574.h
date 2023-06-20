
uint8_t relay[1] = { 0x00 };

static esp_err_t pcf8574_init() {
    i2c_config_t conf;
        conf.mode = I2C_MODE_MASTER,
        conf.scl_io_num = GPIO_NUM_26;
        conf.sda_io_num = GPIO_NUM_27;
        conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
        conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
        conf.master.clk_speed = 100000;
        conf.clk_flags = 0;

    i2c_param_config(I2C_NUM_0, &conf);
    
    esp_err_t err =  i2c_driver_install(I2C_NUM_0, conf.mode, 0, 0, 0);
    i2c_master_write_to_device(I2C_NUM_0, 0x20, relay, 1, 1000);
    return err;
}
static void write_pcf8574(const char* item, const char* status) {
    uint8_t  save[1] = { relay[0] };
    if (strcmp(status, "ON") == 0) {
        if (strcmp(item, "RELAY1") == 0)
            relay[0] = 0x01;
        else if (strcmp(item, "RELAY2") == 0)
            relay[0] = 0x02;
        else if (strcmp(item, "RELAY3") == 0)
            relay[0] = 0x04;
        /*else if (strcmp(item, "all") == 0)
            relay[0] = 0x07;*/
        relay[0] = relay[0] | save[0];
    }
    else if (strcmp(status, "OFF") == 0) { 
        if (strcmp(item, "RELAY1") == 0)
            relay[0] = 0x06;
        else if (strcmp(item, "RELAY2") == 0)
            relay[0] = 0x05;
            else if (strcmp(item, "RELAY3") == 0)
            relay[0] = 0x03;
        /*else if (strcmp(item, "all") == 0)
            relay[0] = 0x00;*/
        relay[0] = relay[0] & save[0];
    }
    i2c_master_write_to_device(I2C_NUM_0, 0x20, relay, 1, 1000);
}