#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

void blink_led2(void *p){
    gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT);
    while(1){
      gpio_set_level(GPIO_NUM_2,1);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      gpio_set_level(GPIO_NUM_2,0);
      vTaskDelay(1000 / portTICK_PERIOD_MS);
      }
  }
void blink_led4(void *p){
    gpio_set_direction(GPIO_NUM_4, GPIO_MODE_OUTPUT);
    while(1){
      gpio_set_level(GPIO_NUM_4,1);
      vTaskDelay(2000 / portTICK_PERIOD_MS);
      gpio_set_level(GPIO_NUM_4,0);
      vTaskDelay(2000 / portTICK_PERIOD_MS);
      }
  }
  
void app_main() {
  xTaskCreate(&blink_led2,"blink2",2048,NULL,1,NULL);
  xTaskCreate(&blink_led4,"blink4",2048,NULL,1,NULL);
}
