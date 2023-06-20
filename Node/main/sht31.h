
static esp_err_t sht31_init(void) {
    i2c_config_t conf;
        conf.mode = I2C_MODE_MASTER;
        conf.scl_io_num = GPIO_NUM_4;
        conf.sda_io_num = GPIO_NUM_5;
        conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
        conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
        conf.master.clk_speed = 100000;
        conf.clk_flags = 0;
    i2c_param_config(I2C_NUM_1, &conf);
    return i2c_driver_install(I2C_NUM_1, conf.mode, 0, 0, 0);
}

static uint8_t sht31_crc(uint8_t* data) {
    uint8_t crc = 0xff;
    for (int i = 0; i < 2; i++) {
        crc ^= data[i];
        for (int j = 0; j < 8; j++) {
            if (crc & 0x80) {
                crc <<= 1;
                crc ^= 0x131;
            }
            else
                crc <<= 1;
        }
    }
    return crc;
}

static esp_err_t sht31_read_temp_humi(float* temp, float* humi){
    unsigned char data_wr[] = { 0x24, 0x00 };
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (0x44 << 1) | I2C_MASTER_WRITE, 0x1);
    i2c_master_write(cmd, data_wr, sizeof(data_wr), 0x1);
    i2c_master_stop(cmd);
    esp_err_t ret = i2c_master_cmd_begin(I2C_NUM_1, cmd, 1000 / portTICK_RATE_MS);

    if (ret != ESP_OK) 
        return ret; 
    i2c_cmd_link_delete(cmd);

    vTaskDelay(2);
    // Read 6 bytes
    cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (0x44 << 1) | I2C_MASTER_READ, 0x1);
    size_t size = 6;
    uint8_t* data_rd = (uint8_t*) malloc(size);
    if (size > 1) 
        i2c_master_read(cmd, data_rd, size - 1, I2C_MASTER_ACK);
    i2c_master_read_byte(cmd, data_rd + size - 1, I2C_MASTER_NACK);
    i2c_master_stop(cmd);
    ret = i2c_master_cmd_begin(I2C_NUM_1, cmd, 1000 / portTICK_RATE_MS);
    
    if (ret != ESP_OK)
        return ret;
    i2c_cmd_link_delete(cmd);

    // check error
    if (data_rd[2] != sht31_crc(data_rd) || data_rd[5] != sht31_crc(data_rd + 3))
        return ESP_ERR_INVALID_CRC;

    *temp = -45 + (175 * (float)(data_rd[0] * 256 + data_rd[1]) / 65535);
    *humi = 100 * (float)(data_rd[3] * 256 + data_rd[4]) / 65535;

    if (data_rd != NULL)
        free(data_rd);

    return ESP_OK;
}
