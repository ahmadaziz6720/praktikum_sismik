// Praktikum EL3116 - Sistem Microprosesor
// Modul : 1
// Percobaan : 3
// Tanggal : 10 Februari 2023
// Kelompok : 10
// Rombongan : B
// Nama (NIM) 1 : Ahmad Aziz (13220034)
// Nama (NIM) 2 : Amelia Ats Tsaniyah Fajri (13220002)
// Nama File : tugas154.c
// Deskripsi : Timer interupt
// Timer interupt

#include <mega328.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <delay.h>

//SET COUNT VALUE FOR 1 HZ
#define TCNT_HIGH 0xC2
#define TCNT_LOW 0xF7

void init_int(void) {
    //set prescaler 1024
    TIMSK1=0b000001;
    TCCR1B=0b00000101;

    TCNT1H=TCNT_HIGH;
    TCNT1L=TCNT_LOW;

    //Enable Interrupt
    #asm("sei")
}

interrupt [TIM1_OVF] void timer1_ovf_isr(void) {
    //LED ON, jeda 1 detik
    PORTD = 0xFF;
    delay_ms(1000);
}

void main(void) {
    init_int();
    DDRD = 0xFF;

	PORTD = 0x00;
	while (1) {
		PORTD = 0b10101010;
		delay_ms(100);
		PORTD = 0b01010101;
		delay_ms(100);
	}
}