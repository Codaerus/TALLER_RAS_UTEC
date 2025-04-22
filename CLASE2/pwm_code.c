#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <driver/ledc.h>

void app_main() {
  ledc_timer_config_t timer_conf = {
    .speed_mode = LEDC_LOW_SPEED_MODE,
    .duty_resolution = LEDC_TIMER_10_BIT,
    .timer_num = LEDC_TIMER_0,
    .freq_hz = 500
  };
  ledc_timer_config(&timer_conf); //configura timer

  ledc_channel_config_t channel_conf = {
    .gpio_num = 2,
    .speed_mode = LEDC_LOW_SPEED_MODE,
    .channel = LEDC_CHANNEL_0,
    .duty = 0,
    .timer_sel = LEDC_TIMER_0
  };
  ledc_channel_config(&channel_conf); //configura chanal pwm

  while(1){
    for(int duty = 0; duty <= 1023; duty +=10)
      {
      ledc_set_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_0,duty);
      ledc_update_duty(LEDC_LOW_SPEED_MODE,LEDC_CHANNEL_0);
      vTaskDelay(50/portTICK_PERIOD_MS);
      printf("Valor PWM: %d\n",duty);
      }
  }
}
//ledc_update_duty(ledc_mode_t speed_mode, ledc_channel_t channel);
// ledc_set_duty(ledc_mode_t speed_mode, ledc_channel_t channel, uint32_t duty);
//ledc_timer_config(const ledc_timer_config_t *timer_conf);
//ledc_channel_config(const ledc_channel_config_t *ledc_conf);
/*
typedef struct {
    int gpio_num;                   
    ledc_mode_t speed_mode;        
    ledc_channel_t channel;         
    ledc_intr_type_t intr_type;     
    ledc_timer_t timer_sel;         
    uint32_t duty;                  
    int hpoint;                     
    struct {
        unsigned int output_invert: 1;
    } flags;                      
} ledc_channel_config_t;
*/
/*
typedef struct {
    ledc_mode_t speed_mode;                
    union {
        ledc_timer_bit_t duty_resolution;  
        ledc_timer_bit_t bit_num __attribute__((deprecated)); 
            };
    ledc_timer_t  timer_num;               
    uint32_t freq_hz;                      
    ledc_clk_cfg_t clk_cfg; 

    } ledc_timer_config_t;
*/
