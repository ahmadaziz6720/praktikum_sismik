#include <mega328.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <delay.h>

#define LED_PORT PORTB
#define LED_DDR DDRB
#define LED_MASK 0b00000001
#define LED_INIT LED_DDR = 0xff
#define LED_ON LED_PORT = LED_MASK
#define LED_OFF LED_PORT = 0x00

#define TCNT_HIGH 0xFD
#define TCNT_LOW 0x3F

unsigned char LED_state = 0;

void init_int(void) {
    //set prescaler 1024
    TCCR1B |= (1<<CS12) | (1<<CS10);
    TIMSK1 |= (1<<TOIE1);

    TCNT1H = TCNT_HIGH;
    TCNT1L = TCNT_LOW;

    // Enable Interrupt
    #asm("sei")
}

interrupt [TIM1_OVF] void timer1_ovf_isr(void) {
    TCNT1H = TCNT_HIGH;
    TCNT1L = TCNT_LOW;
}

void Delay(void) {
    unsigned char i;
    for (i=0; i<100; i++) {
        delay_ms(1);
    }
}

void main(void) {
    LED_INIT;
    init_int();
    while (1) {
        LED_state = !LED_state;
        if (LED_state) {
            LED_ON;
        } else {
            LED_OFF;
        }
        Delay();
    }
}