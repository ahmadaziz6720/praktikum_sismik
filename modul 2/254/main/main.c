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
//gunakan timer 0 esp32
#define TIMER_USED TIMER_0
#define TIMER_DIVIDER 16
#define TIMER_SCALE (TIMER_BASE_CLK / TIMER_DIVIDER) 
#define DELAY_S (1.0)
#define NUMBER_OF_LED 8

int led_state= 0;
// isi dengan attribut yang membuat interrupt hanya dapat dipanggil pada IRAM/ROM dan juga isi nama fungsi interruptnya.
void IRAM_ATTR timer_group0_isr(void* para) {
    // semua timer group pada interrupt harus sama dengan app_main
    timer_spinlock_take(TIMER_GROUP_0);
    int timer_idx = (int)para;
    uint32_t timer_intr = timer_group_get_intr_status_in_isr(TIMER_GROUP_0);
    if (timer_intr & TIMER_INTR_T0) {
        timer_group_clr_intr_status_in_isr(TIMER_GROUP_0, TIMER_0);
    } else if (timer_intr & TIMER_INTR_T1) {
        timer_group_clr_intr_status_in_isr(TIMER_GROUP_0, TIMER_1);
    }
    // merubah kondisi LED (menyala menjadi mati, mati menjadi menyala) setiap kali interrupt ini dipanggil.
    led_state = !led_state;
    gpio_set_level(GPIO_OUTPUT_A, led_state);
    gpio_set_level(GPIO_OUTPUT_B, led_state);
    gpio_set_level(GPIO_OUTPUT_C, led_state);
    gpio_set_level(GPIO_OUTPUT_D, led_state);
    gpio_set_level(GPIO_OUTPUT_E, led_state);
    gpio_set_level(GPIO_OUTPUT_F, led_state);
    gpio_set_level(GPIO_OUTPUT_G, led_state);
    gpio_set_level(GPIO_OUTPUT_H, led_state);
    timer_group_enable_alarm_in_isr(TIMER_GROUP_0, timer_idx);
    timer_spinlock_give(TIMER_GROUP_0);
}

void app_main(void) {
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);
 
    timer_config_t config = {
    .divider = TIMER_DIVIDER,
    .counter_dir = TIMER_COUNT_UP,
    .counter_en = TIMER_PAUSE,
    .alarm_en = TIMER_ALARM_EN,
    .auto_reload = true,
    };

    timer_init(TIMER_GROUP_0, TIMER_USED, &config);
    timer_set_counter_value(TIMER_GROUP_0, TIMER_USED, 0x00000000ULL);
    timer_set_alarm_value(TIMER_GROUP_0, TIMER_USED, DELAY_S * TIMER_SCALE);
    timer_enable_intr(TIMER_GROUP_0, TIMER_USED);
    // Buat interrupt yang dapat dipanggil hanya pada IRAM/ROM
    int intr_alloc_flags = ESP_INTR_FLAG_IRAM | ESP_INTR_FLAG_LEVEL1;

    // jangan lupa isi dengan nama fungsi interrupt dan isi intr_alloc_flags agar interrupt hanya dapat dipanggil pada IRAM/ROM
    timer_isr_register(TIMER_GROUP_0, TIMER_USED, timer_group0_isr, (void*)TIMER_USED, intr_alloc_flags, NULL);
    timer_start(TIMER_GROUP_0, TIMER_USED);
    while (1) {
        vTaskDelay(1);
    };
}
