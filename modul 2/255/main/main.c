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

#define GPIO_OUTPUT_PIN_SEL ((1ULL<<GPIO_OUTPUT_A) | (1ULL<<GPIO_OUTPUT_B) | (1ULL<<GPIO_OUTPUT_C)| (1ULL<<GPIO_OUTPUT_D)| (1ULL<<GPIO_OUTPUT_E)| (1ULL<<GPIO_OUTPUT_F)| (1ULL<<GPIO_OUTPUT_G)| (1ULL<<GPIO_OUTPUT_H));
#define GPIO_INPUT_PB 15
#define GPIO_INPUT_PIN_SEL (1ULL<<GPIO_INPUT_PB)
#define ESP_INTR_FLAG_DEFAULT 0
int on_led_count = 0;
// isi dengan attribut yang membuat interrupt hanya dapat dipanggil pada IRAM/ROM dan juga isi nama fungsi interruptnya.

static void IRAM_ATTR button_isr_handler(void* arg) {
    int gpio_num = (int) arg;
    printf("Button pressed at GPIO %d\n", gpio_num);
}

void app_main() {
    int i=0;
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_INTR_POSEDGE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&io_conf);
    io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
    io_conf.mode = GPIO_MODE_INPUT;
    io_conf.intr_type = GPIO_INTR_POSEDGE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&io_conf);
 
    // Tambahkan potongan kode gpio_install_isr_service() dengan ESP_INTR_FLAG_DEFAULT dan gpio_isr_handler_add(), jangan lupa untuk mengisi parameter kedua fungsi/API tersebut
    gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
    gpio_isr_handler_add(GPIO_INPUT_PB, button_isr_handler, (void*) GPIO_INPUT_PB);
    
    while (1) {
        if(gpio_get_level(GPIO_INPUT_PB) == 0) {
            gpio_set_level(GPIO_OUTPUT_A, 1);
        }
        vTaskDelay(1);
    }
}