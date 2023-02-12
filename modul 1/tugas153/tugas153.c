#include <mega328.h>
#include <avr/io.h>
void init_timer(void) {
    //mode operasi CTC, sumber clock prescaler 256
    TCCR1A = 0;
    TCCR1B = 0b00001010;

    //overflow interrupt disable
    TIMSK1 |=(0<<TOIE1);
    }
    void Delay(void) {
        //Overflow interrupt enable
        TIMSK1 |= (1<<TOIE1);

        //Counter start value
        TCNT1H = 0;
        TCNT1L = 0;

        //Set OCR value for 1 Hz
        OCR1AH = 0x7C;
        OCR1AL = 0xFF;

        //Compare Match TCNT1 dan OCR1A
        loop_until_bit_is_set(TIFR1,OCF1A);
        //Reset Flag
        TIFR1 |= (1<<OCF1A);
        //overflow interrupt disable
        TIMSK1 |= (0<<TOIE1);
    }
void main(void) {
    DDRD=0xff;
    PORTD=0x00;
    init_timer();
    while (1) {
        PORTD=0x0F;
        Delay();
        PORTD=0xF0;
        Delay();
    }
}