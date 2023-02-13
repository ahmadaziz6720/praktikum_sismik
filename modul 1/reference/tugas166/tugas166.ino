/*******************************************************
This program was created by the CodeWizardAVR V3.48a
Automatic Program Generator
� Copyright 1998-2022 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro
Project : Tugas 1.6.6
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
#include "TimerOne.h"
//inisialisasi
int count = 0;
int d_1;
int d_2;
int d_3;
#define digit1 9
#define digit2 10
#define digit3 11
void setup() {
	//assignment secara PIN untuk tiap LED 7S, memakai pin mulai dari 2-8, 9-11
	untuk digit
	pinMode(2, OUTPUT); //LED a
	pinMode(3, OUTPUT); //LED b
	pinMode(4, OUTPUT); //LED c
	pinMode(5, OUTPUT); //LED d
	pinMode(6, OUTPUT); //LED e
	pinMode(7, OUTPUT); //LED f
	pinMode(8, OUTPUT); //LED g
	pinMode(digit1, OUTPUT); //untuk digit 1
	pinMode(digit2, OUTPUT); //untuk digit 2
	pinMode(digit3, OUTPUT); //untuk digit 3

	//interrupts
	noInterrupts();
	Timer1.initialize(1000000); // timer 1 detik
	Timer1.attachInterrupt(counter);
	interrupts();
}
void counter(void) {
	count = (count + 1) % 1000;
	d_1 = count % 10;
	d_2 = (count % 100)/10;
	d_3 = count/100;
}
//ASUMSI : 7Segment common ANODE
void seven_segment(byte number){
	switch (number){
		case 0: //for display 0 0000001
		digitalWrite(2,LOW);
		digitalWrite(3,LOW);
		digitalWrite(4,LOW);
		digitalWrite(5,LOW);
		digitalWrite(6,LOW);
		digitalWrite(7,LOW);
		digitalWrite(8,HIGH);
		break;
		case 1: //for display 1 1001111
		digitalWrite(2,HIGH);
		digitalWrite(3,LOW);
		digitalWrite(4,LOW);
		digitalWrite(5,HIGH);
		digitalWrite(6,HIGH);
		digitalWrite(7,HIGH);
		digitalWrite(8,HIGH);
		break;

		case 2: //for display 2 0010010
		digitalWrite(2,LOW);
		digitalWrite(3,LOW);
		digitalWrite(4,HIGH);
		digitalWrite(5,LOW);
		digitalWrite(6,LOW);
		digitalWrite(7,HIGH);
		digitalWrite(8,LOW);
		break;

		case 3: //for display 3 000110
		digitalWrite(2,LOW);
		digitalWrite(3,LOW);
		digitalWrite(4,LOW);
		digitalWrite(5,LOW);
		digitalWrite(6,HIGH);
		digitalWrite(7,HIGH);
		digitalWrite(8,LOW);
		break;

		case 4: //for display 4 1001100
		digitalWrite(2,HIGH);
		digitalWrite(3,LOW);
		digitalWrite(4,LOW);
		digitalWrite(5,HIGH);
		digitalWrite(6,HIGH);
		digitalWrite(7,LOW);
		digitalWrite(8,LOW);
		break;

		case 5: //for display 5 0100100
		digitalWrite(2,LOW);
		digitalWrite(3,HIGH);
		digitalWrite(4,LOW);
		digitalWrite(5,LOW);
		digitalWrite(6,HIGH);
		digitalWrite(7,LOW);
		digitalWrite(8,LOW);
		break;

		case 6: //for display 6 0100000
		digitalWrite(2,LOW);
		digitalWrite(3,HIGH);
		digitalWrite(4,LOW);
		digitalWrite(5,LOW);
		digitalWrite(6,LOW);
		digitalWrite(7,LOW);
		digitalWrite(8,LOW);
		break;

		case 7: //for display 7 0001111
		digitalWrite(2,LOW);
		digitalWrite(3,LOW);
		digitalWrite(4,LOW);
		digitalWrite(5,HIGH);
		digitalWrite(6,HIGH);
		digitalWrite(7,HIGH);
		digitalWrite(8,HIGH);
		break;

		case 8: //for display 8 0000000
		digitalWrite(2,LOW);
		digitalWrite(3,LOW);
		digitalWrite(4,LOW);
		digitalWrite(5,LOW);
		digitalWrite(6,LOW);
		digitalWrite(7,LOW);
		digitalWrite(8,LOW);
		break;

		case 9: //for display 9 0000110
		digitalWrite(2,LOW);
		digitalWrite(3,LOW);
		digitalWrite(4,LOW);
		digitalWrite(5,LOW);
		digitalWrite(6,HIGH);
		digitalWrite(7,LOW);
		digitalWrite(8,LOW);
		break;
	}
}
void loop() {
	digitalWrite(digit1, HIGH);
	digitalWrite(digit2, LOW);
	digitalWrite(digit3, LOW);
	even_segment(d_1);
	delay(1);

	digitalWrite(digit1, LOW);
	digitalWrite(digit2, LOW);
	digitalWrite(digit3, LOW);
	seven_segment(10);
	delay(1);

	digitalWrite(digit1, LOW);
	digitalWrite(digit2, HIGH);
	digitalWrite(digit3, LOW);
	seven_segment(d_2);
	delay(1);

	digitalWrite(digit1, LOW);
	digitalWrite(digit2, LOW);
	digitalWrite(digit3, LOW);
	seven_segment(10);
	delay(1);

	digitalWrite(digit1, LOW);
	digitalWrite(digit2, LOW);
	digitalWrite(digit3, HIGH);
	seven_segment(d_3);
	delay(1);

	digitalWrite(digit1, LOW);
	digitalWrite(digit2, LOW);
	digitalWrite(digit3, LOW);
	seven_segment(10);
	delay(1);
}