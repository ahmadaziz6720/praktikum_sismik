#include <stdio.h>
#include "driver/gpio.h"
#include "driver/timer.h"
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

#define TIMER_DIVIDER 16
#define TIMER_SCALE (TIMER_BASE_CLK / TIMER_DIVIDER)
#define DELAY_S 0.25
#define NUMBER_OF_LED 8
#define TIMER1_INTERVAL_SEC (DELAY_S * NUMBER_OF_LED)

void app_main(void) {
	
	gpio_config_t io_conf;
	io_conf.intr_type = GPIO_INTR_POSEDGE;
	io_conf.mode = GPIO_MODE_OUTPUT;
	io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
	io_conf.pull_down_en = 0;
	io_conf.pull_up_en = 1;
	gpio_config(&io_conf);
	
	// Timer menghitung ke atas, nanti baru di start, pakai alarm, namun tanpa reload counter value setelah alarm event.
	timer_config_t config = {
        .divider = TIMER_DIVIDER,
        .counter_dir = TIMER_COUNT_UP,
        .counter_en = TIMER_PAUSE,
        .alarm_en = TIMER_ALARM_EN,
        .auto_reload = TIMER_AUTORELOAD_EN
    };
	
	// gunakan timer group dan hardware timer yang valid
	timer_init(TIMER_GROUP_0, TIMER_0, &config);
    timer_set_counter_value(TIMER_GROUP_0, TIMER_0, 0);
    timer_set_alarm_value(TIMER_GROUP_0, TIMER_0, (80000000 / TIMER_DIVIDER));
    timer_enable_intr(TIMER_GROUP_0, TIMER_0);
    timer_start(TIMER_GROUP_0, TIMER_0);
	
	// Silahkan melengkapi potongan kode berikut ini untuk membuat program LED menyala bergeser setiap 250ms dan berulang mulai dari LED paling awal.
	
	// Jika ingin membuat potongan kode sendiri sangat dipersilahkan (sekaligus dapat mengubah konfigurasi timer di atas)
	int count = -1;
	double current_time_sec = 0, last_time_sec = 0,
	last_reset_time = 0;
	
	while (1) {
		timer_get_counter_time_sec(TIMER_GROUP_0, TIMER_0, &current_time_sec);
		
		if (current_time_sec - last_time_sec > DELAY_S) {
			count++;
			last_time_sec = current_time_sec;
		
		} else if (current_time_sec - last_reset_time > TIMER1_INTERVAL_SEC) {
			count = -1;
			last_reset_time = current_time_sec;
		}
		
		
		gpio_set_level(count, 1);
		vTaskDelay(1);
	}
}