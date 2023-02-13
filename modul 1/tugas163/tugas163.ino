// Praktikum EL3116 - Sistem Microprosesor
// Modul : 1
// Percobaan : 1
// Tanggal : 10 Februari 2023
// Kelompok : 10
// Rombongan : B
// Nama (NIM) 1 : Ahmad Aziz (13220034)
// Nama (NIM) 2 : Amelia Ats Tsaniyah Fajri (13220002)
// Nama File : tugas162.ino
// Deskripsi : timer
// timer

#include <TimerOne.h>
int LED[8] = {0,1,2,3,4,5,6,7};
int state = 0;

void setup() {
    for (int i = 0; i < 8; i++) {
        pinMode(LED[i], OUTPUT);
    }
    Timer1.initialize(500000);
    Timer1.attachInterrupt(updateLEDs);
}

void updateLEDs() {
    if (state == 0) {
        digitalWrite(LED[0], LOW);
        digitalWrite(LED[1], LOW);
        digitalWrite(LED[2], LOW);
        digitalWrite(LED[3], LOW);
        digitalWrite(LED[4], HIGH);
        digitalWrite(LED[5], HIGH);
        digitalWrite(LED[6], HIGH);
        digitalWrite(LED[7], HIGH);
        state = 1;
    }
    else if (state == 1) {
        digitalWrite(LED[0], HIGH);
        digitalWrite(LED[1], HIGH);
        digitalWrite(LED[2], HIGH);
        digitalWrite(LED[3], HIGH);
        digitalWrite(LED[4], LOW);
        digitalWrite(LED[5], LOW);
        digitalWrite(LED[6], LOW);
        digitalWrite(LED[7], LOW);
        state = 0;
    }
}