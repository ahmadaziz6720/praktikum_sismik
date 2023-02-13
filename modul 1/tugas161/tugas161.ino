// Praktikum EL3116 - Sistem Microprosesor
// Modul : 1
// Percobaan : 1
// Tanggal : 10 Februari 2023
// Kelompok : 10
// Rombongan : B
// Nama (NIM) 1 : Ahmad Aziz (13220034)
// Nama (NIM) 2 : Amelia Ats Tsaniyah Fajri (13220002)
// Nama File : tugas161.ino
// Deskripsi : running led
// Running led

void setup() {
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	pinMode(3, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(7, OUTPUT);

	pinMode(9, INPUT);
}

void loop() {
	for (int i = 0; i < 8; i++) {
        digitalWrite(i,HIGH);
        delay(1000);
        digitalWrite(i,LOW);
    }

}