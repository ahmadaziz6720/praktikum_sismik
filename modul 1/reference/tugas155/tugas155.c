/*******************************************************
This program was created by the CodeWizardAVR V3.48a
Automatic Program Generator
© Copyright 1998-2022 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro
Project : Tugas 1.5.5
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
#include <delay.h>
interrupt [EXT_INT0] void ext_int0_isr(void) {
//Diminta semua LED mati dengan hold 250 ms
	PORTD = 0x00;
	delay_ms(250);
}
void main(void) {
	//SET MODE PIN D, PIN D2 = INPUT, SISANYA OUTPUT
	DDRD = 0xFB;
	//Unable Comm Serial RX TX
	UCSR0B = 0x00;

	#asm("sei")

	//SET FALLING EDGE PADA INT0
	EICRA=(0<<ISC11)|(0<<ISC10)|(1<<ISC01)|(0<<ISC00);

	//ENABLE INT0
	EIMSK=(0<<INT1) | (1<<INT0);

	//SET INT0 FLAG
	EIFR=(0<<INTF1) | (1<<INTF0);

	while (1) {
		PORTD = 0xF0; //pola 11110000
		delay_ms(500); //delay 500ms
		PORTD = 0x0F; //pola 00001111
		delay_ms(500); //delay 500ms
	}
}

