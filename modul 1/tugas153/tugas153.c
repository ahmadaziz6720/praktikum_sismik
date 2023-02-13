// Praktikum EL3116 - Sistem Microprosesor
// Modul : 1
// Percobaan : 3
// Tanggal : 10 Februari 2023
// Kelompok : 10
// Rombongan : B
// Nama (NIM) 1 : Ahmad Aziz (13220034)
// Nama (NIM) 2 : Amelia Ats Tsaniyah Fajri (13220002)
// Nama File : tugas153.c
// Deskripsi : Timer
// Timer

#include <mega328.h>
#include <avr/io.h>
void init_timer(void) {
    //mode operasi CTC, sumber clock prescaler 256
    TCCR1A = 0;
    TCCR1B = 0b00000100;

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
	OCR1AH = 0x3D;
	OCR1AL = 0x09;

	//Compare Match TCNT1 dan OCR1A
	loop_until_bit_is_set(TIFR1,OCF1A);
	//Reset Flag
	TIFR1 |= (1<<OCF1A);

	//Overflow interrupt disable
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