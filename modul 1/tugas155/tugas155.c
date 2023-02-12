#include <mega328.h>
#include <delay.h>
#include <avr/io.h>

#define LED_PORT PORTB
#define LED_DDR DDRB
#define LED_MASK 0xFF

#define BUTTON_PORT PIND
#define BUTTON_DDR DDRD
#define BUTTON_MASK (1<<PD2)
#define BUTTON_PIN PD2

#define LED_ON(x) LED_PORT &= ~(x)
#define LED_OFF(x) LED_PORT |= (x)

interrupt [EXT_INT0] void ext_int0_isr(void) {
    // Semua LED mati selama 250ms
    LED_ON(LED_MASK);
    delay_ms(250);
    LED_OFF(LED_MASK);
}

void main(void) {
    // SET MODE PIN B = OUTPUT, PIN D2 = INPUT
    LED_DDR = LED_MASK;
    BUTTON_DDR &= ~BUTTON_MASK;

    // SET FALLING EDGE PADA INT0
    EICRA = (0<<ISC11) | (0<<ISC10) | (1<<ISC01) | (0<<ISC00);

    // ENABLE INT0
    EIMSK = (0<<INT1) | (1<<INT0);

    // SET INT0 FLAG
    EIFR = (0<<INTF1) | (1<<INTF0);

    #asm("sei")

    while (1) {
        LED_PORT = LED_PORT ^ LED_MASK;
        delay_ms(100);
    }
}
