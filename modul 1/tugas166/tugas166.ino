// Praktikum EL3116 - Sistem Microprosesor
// Modul : 1
// Percobaan : 1
// Tanggal : 10 Februari 2023
// Kelompok : 10
// Rombongan : B
// Nama (NIM) 1 : Ahmad Aziz (13220034)
// Nama (NIM) 2 : Amelia Ats Tsaniyah Fajri (13220002)
// Nama File : tugas165.ino
// Deskripsi : 7 segment
// 7 segment

#include <TimerOne.h>

const int segA = 2;
const int segB = 3;
const int segC = 4;
const int segD = 5;
const int segE = 6;
const int segF = 7;
const int segG = 8;
const int segDP = 9;

const int digit1 = 10;
const int digit2 = 11;
const int digit3 = 12;

int counter = 0;

int digit1Value = 0;
int digit2Value = 0;
int digit3Value = 0;

const int numArray[10][7]={
{1,1,1,0,1,1,1}, //0
{0,0,1,0,0,1,0}, //1
{1,0,1,1,1,0,1}, //2
{1,0,1,1,0,1,1}, //3
{0,1,1,1,0,1,0}, //4
{1,1,0,1,0,1,1}, //5
{1,1,0,1,1,1,1}, //6
{1,0,1,0,0,1,0}, //7
{1,1,1,1,1,1,1}, //8
{1,1,1,1,0,1,1} //9
};

void setup() {
    pinMode(segA, OUTPUT);
    pinMode(segB, OUTPUT);
    pinMode(segC, OUTPUT);
    pinMode(segD, OUTPUT);
    pinMode(segE, OUTPUT);
    pinMode(segF, OUTPUT);
    pinMode(segG, OUTPUT);
    pinMode(segDP, OUTPUT);

    pinMode(digit1, OUTPUT);
    pinMode(digit2, OUTPUT);
    pinMode(digit3, OUTPUT);

    Timer1.initialize(1000);
    Timer1.attachInterrupt(updateCounter);
}

void loop() {
    digitalWrite(digit1, LOW);
    showDigit(digit1Value);
    delay(1);
    digitalWrite(digit1, HIGH);

    digitalWrite(digit2, LOW);
    showDigit(digit2Value);
    delay(1);
    digitalWrite(digit2, HIGH);

    digitalWrite(digit3, LOW);
    showDigit(digit3Value);
    delay(1);
}

void updateCounter() {
    // Increment counter
    counter++;

    if (counter >= 1000) {
    counter = 0;
    }

    digit1Value = counter / 100;
    digit2Value = (counter / 10) % 10;
    digit3Value = counter % 10;
}

void showDigit(int digit) {
    digitalWrite(segA, numArray[digit][0]);
    digitalWrite(segB, numArray[digit][1]);
    digitalWrite(segC, numArray[digit][2]);
    digitalWrite(segD, numArray[digit][3]);
    digitalWrite(segE, numArray[digit][4]);
    digitalWrite(segF, numArray[digit][5]);
    digitalWrite(segG, numArray[digit][6]);
    digitalWrite(segDP, LOW);
}

