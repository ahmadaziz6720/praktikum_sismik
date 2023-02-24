#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define GPIO_OUTPUT_A 2
#define GPIO_OUTPUT_B 4
#define GPIO_OUTPUT_C 5
#define GPIO_OUTPUT_D 18
#define GPIO_OUTPUT_E 19
#define GPIO_OUTPUT_F 21
#define GPIO_OUTPUT_G 22
#define GPIO_OUTPUT_H 23
#define GPIO_OUTPUT_PIN_SEL ((1ULL<<GPIO_OUTPUT_A) | (1ULL<<GPIO_OUTPUT_B) | (1ULL<<GPIO_OUTPUT_C)| (1ULL<<GPIO_OUTPUT_D)| (1ULL<<GPIO_OUTPUT_E)| (1ULL<<GPIO_OUTPUT_F)| (1ULL<<GPIO_OUTPUT_G)| (1ULL<<GPIO_OUTPUT_H))

#define GPIO_INPUT_PB 15
#define GPIO_INPUT_PIN_SEL (1ULL<<GPIO_INPUT_PB)

#define DELAY_MS 200

const TickType_t xDelay = DELAY_MS / portTICK_PERIOD_MS;

void app_main() {
	gpio_config_t io_conf;
	io_conf.intr_type = GPIO_INTR_DISABLE;
	io_conf.mode = GPIO_MODE_OUTPUT;
	io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
	io_conf.pull_down_en = 0;
	io_conf.pull_up_en = 0;
	gpio_config(&io_conf);
	io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
	io_conf.mode = GPIO_MODE_INPUT; // mode input
	io_conf.pull_up_en = 0; // menggunakan pull up
	io_conf.pull_down_en = 1; // menggunakan pull down
	gpio_config(&io_conf);
	
	int counter = 0;
	
	while (1) {
		if (gpio_get_level(GPIO_INPUT_PB) == 0) {
			
			counter++;
			
			if (counter > 7) {
				counter = 0;
			}
			
			vTaskDelay(xDelay);
			
		}
		
		if (counter == 0) {
			gpio_set_level(GPIO_OUTPUT_A, 1);
		} else {
			gpio_set_level(GPIO_OUTPUT_A, 0);
		}
		
		if (counter == 1) {
			gpio_set_level(GPIO_OUTPUT_B, 1);
		} else {
			gpio_set_level(GPIO_OUTPUT_B, 0);
		}
		
		if (counter == 2) {
			gpio_set_level(GPIO_OUTPUT_C, 1);
		} else {
			gpio_set_level(GPIO_OUTPUT_C, 0);
		}
		
		if (counter == 3) {
			gpio_set_level(GPIO_OUTPUT_D, 1);
		} else {
			gpio_set_level(GPIO_OUTPUT_D, 0);
		}
		
		if (counter == 4) {
			gpio_set_level(GPIO_OUTPUT_E, 1);
		} else {
			gpio_set_level(GPIO_OUTPUT_E, 0);
		}
		
		if (counter == 5) {
			gpio_set_level(GPIO_OUTPUT_F, 1);
		} else {
			gpio_set_level(GPIO_OUTPUT_F, 0);
		}
		
		if (counter == 6) {
			gpio_set_level(GPIO_OUTPUT_G, 1);
		} else {
			gpio_set_level(GPIO_OUTPUT_G, 0);
		}
		
		if (counter == 7) {
			gpio_set_level(GPIO_OUTPUT_H, 1);
		} else {
			gpio_set_level(GPIO_OUTPUT_H, 0);
		}
	}
}