// Praktikum EL3116 - Sistem Microprosesor
// Modul : 1
// Percobaan : 1
// Tanggal : 10 Februari 2023
// Kelompok : 10
// Rombongan : B
// Nama (NIM) 1 : Ahmad Aziz (13220034)
// Nama (NIM) 2 : Amelia Ats Tsaniyah Fajri (13220002)
// Nama File : tugas151.c
// Deskripsi : running led
// Running led

#include <mega328.h>
#include <delay.h>
int i;
void main(void) {
	//Set mode PIN D menjadi OUTPUT
	DDRD=0xff;
	while (1) {
	    for (i = 0; i < 8; i++) {
			//geser bit 1 ke kiri sebanyak i kali
			PORTD = (1 << i);
			delay_ms(1000);
	    }
	}
}