// Praktikum EL3116 - Sistem Microprosesor
// Modul : 1
// Percobaan : 3
// Tanggal : 10 Februari 2023
// Kelompok : 10
// Rombongan : B
// Nama (NIM) 1 : Ahmad Aziz (13220034)
// Nama (NIM) 2 : Amelia Ats Tsaniyah Fajri (13220002)
// Nama File : tugas155.c
// Deskripsi : Timer interupt
// Timer interupt

#include <mega328.h>
#include <delay.h>
interrupt [EXT_INT0] void ext_int0_isr(void) {
	PORTD = 0x00;
	delay_ms(250);
}
void main(void) {
	//SET MODE PIN D, PIN D2 = INPUT, SISANYA OUTPUT
	DDRD = 0xFB;

	#asm("sei")

	//SET FALLING EDGE PADA INT0
	EICRA=(0<<ISC11)|(0<<ISC10)|(1<<ISC01)|(0<<ISC00);

	//ENABLE INT0
	EIMSK=(0<<INT1) | (1<<INT0);

	//SET INT0 FLAG
	EIFR=(0<<INTF1) | (1<<INTF0);

	while (1) {
		PORTD = 0b11110000;
		delay_ms(500);
		PORTD = 0x00001111;
		delay_ms(500);
	}
}
