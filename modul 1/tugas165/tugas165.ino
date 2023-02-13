// Praktikum EL3116 - Sistem Microprosesor
// Modul : 1
// Percobaan : 1
// Tanggal : 10 Februari 2023
// Kelompok : 10
// Rombongan : B
// Nama (NIM) 1 : Ahmad Aziz (13220034)
// Nama (NIM) 2 : Amelia Ats Tsaniyah Fajri (13220002)
// Nama File : tugas165.ino
// Deskripsi : button interupt
// button interupt

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