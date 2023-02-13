/*******************************************************
This program was created by the CodeWizardAVR V3.48a
Automatic Program Generator
© Copyright 1998-2022 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro
Project : Tugas 1.5.3
Version : TP
Date : 09/02/2023
Author : Amelia Ats Tsaniyah F./13220002
Chip type : ATmega328P
Program type : Application
AVR Core Clock frequency: 16.000000 MHz
Memory model : Small
External RAM size : 0
Data Stack size : 512
*******************************************************/
#include <mega328.h>
#include <avr/io.h>
int i;
void init_timer(void) {
	//mode operasi CTC, sumber clock prescaler 256
	TCCR1A = 0;
	TCCR1B = 0b00001100;
	//Overflow interrupt disable
	TIMSK1 |=(0<<TOIE1);
}
void Delay(void) {
	//Overflow interrupt enable
	TIMSK1 |= (1<<TOIE1);

	//Counter start value
	TCNT1H = 0;
	TCNT1L = 0;
	//Set OCR value for 2 Hz
	OCR1AH = 0x7A;
	OCR1AL = 0x11;

	//Compare Match TCNT1 dan OCR1A
	loop_until_bit_is_set(TIFR1,OCF1A);
	//Reset Flag
	TIFR1 |= (1<<OCF1A);

	//Overflow interrupt disable
	TIMSK1 |= (0<<TOIE1);
}
// Flip flop LED 4bit. Jeda 500ms dengan Delay(). Nyala 4 secara 2 batch zigzag.
void main(void) {
	init_timer();
	DDRD = 0xFF;//Assign DDR PIN D sebagai output
	UCSR0B = 0x00;//Unable Comm Serial untuk RX TX
	PORTD = 0x00;//inisialisasi

	while(1){
		//Buat dua kondisi. Batch kiri, lalu memakai fungsi Delay()
		// Setelah Delay (new cycle, mati), nyalakan batch 2.
		PORTD = 0xF0;//kiri
		Delay();
		PORTD = 0x0F;//kanan
		Delay();
	}
}
