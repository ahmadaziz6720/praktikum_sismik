/*******************************************************
This program was created by the CodeWizardAVR V3.48a
Automatic Program Generator
� Copyright 1998-2022 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro
Project : Tugas 1.5.2
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
int i;
int PVPINB;
//Kode running LED sama seperti pada tugas151 tetapi dengan pergantian dari input push button
void main(void){
	DDRD = 0xFF; //Assign DDR mode PIN D menjadi OUTPUT
	DDRB = 0x00; //Assign DDR mode PIN B untuk button
	UCSR0B = 0x00; //Unable Comm Serial untuk RX TX
	i = 0x01; //inisilasasi led mulai dari 1
	PVPINB= PINB.1; //untuk melihat status button sebelumnya

//Kondisi : push button low ke high (on), tugas151, button harus ditahan, meskipun sudah tidak dipush,
//harus tetap menyala sampai tidak sesuai dengan previous button
	while (1) {

		if (!(PINB.1)) {
			delay_ms(100);
			PORTD = (1 << i);
			i++;
			if (i > 7) {
				i = 0;
			}
		while (!(PINB.1)) {};
	}

	}
}