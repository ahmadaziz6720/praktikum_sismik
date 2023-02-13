/*******************************************************
This program was created by the CodeWizardAVR V3.48a
Automatic Program Generator
� Copyright 1998-2022 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro
Project : Tugas 1.6.2
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

bool state = 0;
void setup() {

//assignment secara PIN untuk output LED, memakai pin 2-9
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);

	pinMode(9, INPUT);
}
int i=1; //kondisi awal, karena pin dari 2 supaya lebih mudah saja
void loop() {

	if(digitalRead(9) == HIGH) {
		delay(100);
		if(state == 0) {
			i++;
			digitalWrite(i,HIGH);
			if (i==7) {
				state = 1;
				for(int j=0; j<8; j++) {
					digitalWrite(j,LOW);
				}
			}
		} else {
			i--;
			digitalWrite(i,HIGH);
			if(i==0) {
				state = 0;
				for(int j=0; j<8; j++) {
					digitalWrite(j,LOW);
				}
			}
		}
		
	}

	
}