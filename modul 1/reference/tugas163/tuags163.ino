/*******************************************************
This program was created by the CodeWizardAVR V3.48a
Automatic Program Generator
� Copyright 1998-2022 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro
Project : Tugas 1.6.3
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
int timer = 0;
bool kiri = HIGH;
bool kanan = LOW;
void setup() {
//assignment secara PIN untuk output LED, memakai pin 2-9
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);

	//Waktu pergantian
	//Penentuan periode clock
	Timer1.initialize(500000);
	//Interrupt
	Timer1.attachInterrupt(TimerCounter);
}
//Counter untuk tiap jeda 500ms, siklus flipflop
void TimerCounter(){ //
 timer++;
}
void loop() {
 if ((timer % 2) == 0){
	 kiri = HIGH; //pertama kali harus pola kiri ON, kanan OFF
	 kanan = LOW;
 }
 else {
	 kiri = LOW; //satunya lagi, pola kanan ON, kiri OFF
	 kanan = HIGH;
 }

 //Output LED yang akan dinyalakan, assignment
 for (int i = 0; i < 4; i++) { //pola kiri
	digitalWrite(i, kiri);
 }
 for (int i = 4; i < 8; i++) { //pola kanan
	digitalWrite(i, kanan);
 }
}