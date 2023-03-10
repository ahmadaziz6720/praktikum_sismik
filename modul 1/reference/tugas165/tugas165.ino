/*******************************************************
This program was created by the CodeWizardAVR V3.48a
Automatic Program Generator
� Copyright 1998-2022 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro
Project : Tugas 1.6.5
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

#define button 2
void setup() {
//assignment secara PIN untuk output LED, memakai pin 2-9
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(4, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);
	
	pinMode(button,INPUT);
	attachInterrupt(digitalPinToInterrupt(button),LEDOff,FALLING);
}

void LEDOff(){
	for (int i = 0; i < 8; i++) {
		digitalWrite(i, LOW);
	}
	delay(250);
}

void loop() {
	for (int i = 0; i < 5; i++) {
		digitalWrite(i, HIGH);
		if(i == 2){
			i++;
		}
	}
	for (int i = 4; i < 9; i++) {
		digitalWrite(i, LOW);
		if(i == 2){
			i++;
		}
	}
	delay(500);
	for (int i = 0; i < 5; i++) {
		digitalWrite(i, LOW);
		if(i == 2){
			i++;
		}
	}
	for (int i = 4; i < 9; i++) {
		digitalWrite(i, HIGH);
		if(i == 2){
			i++;
		}
	}
	delay(500);
}
