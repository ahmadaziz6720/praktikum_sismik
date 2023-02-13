// Praktikum EL3116 - Sistem Microprosesor
// Modul : 1
// Percobaan : 1
// Tanggal : 10 Februari 2023
// Kelompok : 10
// Rombongan : B
// Nama (NIM) 1 : Ahmad Aziz (13220034)
// Nama (NIM) 2 : Amelia Ats Tsaniyah Fajri (13220002)
// Nama File : tugas164.ino
// Deskripsi : timer interupt
// timer interupt

#include "TimerOne.h"
int timer = 0;
bool kiri = HIGH;
bool kanan = LOW;
void setup() {
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);

	Timer1.initialize(1000000); 
	//Interrupt
	Timer1.attachInterrupt(TimerCounter);
}
bool LED = LOW;

//Counter untuk tiap jeda 100ms, siklus flipflop
void TimerCounter(){ 
	timer++;
    //setiap siklus interupt
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
	for (int i = 0; i < 8;i++) {
		//flip flop
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