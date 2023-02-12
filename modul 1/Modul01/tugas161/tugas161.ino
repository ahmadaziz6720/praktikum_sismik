/*******************************************************
This program was created by the CodeWizardAVR V3.48a
Automatic Program Generator
� Copyright 1998-2022 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro
Project : Tugas 1.6.1
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
void setup() {
//assignment secara PIN untuk output LED 0-7
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);

	pinMode(9, INPUT);
}
int i =0; //kondisi awal
void loop() {
	while (i <8) {
		//Turn ON LED satu per satu
		digitalWrite(i,HIGH);
		//jeda 1 detik
		delay(1000);
		//TURN OFF
		digitalWrite(i,LOW);

		i++;//increment
	}
	//buat kondisi untuk overflow -> ulang dari awal

	if(i ==8) {
		i =0;
	}
}

