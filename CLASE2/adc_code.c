#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <driver/adc.h>

void app_main() {
  adc1_config_width(ADC_WIDTH_BIT_12); // 0.0v a 3.3v | 0 - 4095
  adc1_config_channel_atten(ADC1_CHANNEL_6,ADC_ATTEN_DB_11); // 34 input| rango 0.0v - 3.3v
  while(1){
    uint16_t pot1 = adc1_get_raw(ADC1_CHANNEL_6);
    printf("Valor ADC: %u\n",pot1);
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

//esp_err_t adc1_config_channel_atten(adc1_channel_t channel, adc_atten_t atten)
//esp_err_t adc1_config_width(adc_bits_width_t width_bit);
//int adc1_get_raw(adc1_channel_t channel);
