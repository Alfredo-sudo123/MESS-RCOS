#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/i2c_master.h"
#include "bh1750.h"

static const char *TAG = "main";

void app_main(void)
{
    //creating bus
    i2c_master_bus_config_t bus_cfg = 
    {
        .i2c_port = I2C_NUM_0,
        .sda_io_num = 21,
        .scl_io_num = 22,
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };

    i2c_master_bus_handle_t bus;
    ESP_ERROR_CHECK(i2c_new_master_bus(&bus_cfg, &bus));
    
    //setting up bh1750 sensor light
    bh1750_t light;
    ESP_ERROR_CHECK(bh1750_init(&light, bus, BH1750_ADDR_LOW));

    while (1) {
        float lux;
        if (bh1750_read_lux(&light, &lux) == ESP_OK) {
            ESP_LOGI(TAG, "Light: %.1f lx", lux);
        } else {
            ESP_LOGE(TAG, "BH1750 read failed");
        }
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}