#include "bh1750.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

//
esp_err_t bh1750_init(bh1750_t *sensor, i2c_master_bus_handle_t bus, uint8_t addr)
{
    i2c_device_config_t cfg = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = addr,
        .scl_speed_hz = 100000,
    };
    esp_err_t err = i2c_master_bus_add_device(bus, &cfg, &sensor->dev);
    if (err != ESP_OK) return err;

    uint8_t cmd = 0x10;  // continuous high-res mode
    err = i2c_master_transmit(sensor->dev, &cmd, 1, 100);
    vTaskDelay(pdMS_TO_TICKS(180));
    return err;
}

esp_err_t bh1750_read_lux(bh1750_t *sensor, float *lux)
{
    uint8_t buf[2];
    esp_err_t err = i2c_master_receive(sensor->dev, buf, 2, 100);
    if (err == ESP_OK) {
        *lux = ((buf[0] << 8) | buf[1]) / 1.2f;
    }
    return err;
}