/*******************************************************
This program was created by the CodeWizardAVR V3.48a
Automatic Program Generator
� Copyright 1998-2022 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro
Project : Tugas 1.6.4
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
	Timer1.initialize(1000000); //100ms
	//Interrupt
	Timer1.attachInterrupt(TimerCounter);
}
bool LED = LOW; //untuk set semua menyala pada HIGH

//Counter untuk tiap jeda 100ms, siklus flipflop
void TimerCounter(){ //
	timer++; //timer akan nambah tiap 100ms
	//Beri kondisi untuk interrupt yang terjadi tiap 1 detik, LED menyala hold 1 detik. Artinya akan menyala tiap 1000ms --> timer harus count dgnkelipatan 1x if (timer != 0 && timer % 10 == 0){ //mod 10 untuk kelipatan 10
	
	if((timer %2) == 0){
		LED = HIGH;
		for(int i = 0; i < 8; i++){
			digitalWrite(i, HIGH);
		}
	}
	else{
		LED = LOW;
	}

	}

void loop() {
	//Interupsi LED nyala semua
	if (LED == HIGH){

	}
	

	//Output LED yang akan dinyalakan, assignment
	for (int i = 0; i < 8;i++) {
		//pergantian penyalaan

		if(LED){
			if ((i % 2) == 0){
				digitalWrite(i, LOW);
			}
			else{
				digitalWrite(i, HIGH);
			};
		
		}
		else{
			if ((i % 2) == 0){
			digitalWrite(i, HIGH);
			}
			else{
				digitalWrite(i, LOW);
				
			};
		}
	}
}
