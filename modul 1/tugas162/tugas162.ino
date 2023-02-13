// Praktikum EL3116 - Sistem Microprosesor
// Modul : 1
// Percobaan : 1
// Tanggal : 10 Februari 2023
// Kelompok : 10
// Rombongan : B
// Nama (NIM) 1 : Ahmad Aziz (13220034)
// Nama (NIM) 2 : Amelia Ats Tsaniyah Fajri (13220002)
// Nama File : tugas162.ino
// Deskripsi : running led
// Running led

bool state = 0;
void setup() {
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);

	pinMode(9, INPUT);
}
int i=1;
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
		} 
        else {
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