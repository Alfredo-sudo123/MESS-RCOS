#pragma once
#include "driver/i2c_master.h"
#include "esp_err.h"

#define BH1750_ADDR_LOW  0x23
#define BH1750_ADDR_HIGH 0x5C

typedef struct 
{
    i2c_master_dev_handle_t dev;
} 
bh1750_t;

esp_err_t bh1750_init(bh1750_t *sensor, i2c_master_bus_handle_t bus, uint8_t addr);
esp_err_t bh1750_read_lux(bh1750_t *sensor, float *lux);