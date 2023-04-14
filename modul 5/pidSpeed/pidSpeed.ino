// Praktikum EL3116 - Sistem Microprosesor
// Modul : 5
// Percobaan : 2
// Tanggal : 13 April 2023
// Kelompok : 10
// Rombongan : B
// Nama (NIM) 1 : Ahmad Aziz (13220034)
// Nama (NIM) 2 : Emmanuella Pramudita Rumanti (13220031)
// Nama File : pidSpeed.ino
// Deskripsi : speed control using PID

#include <FastPID.h>

#define PWM 5 // PWM output pin
#define fwd 6 // forward direction pin
#define rev 7 // reverse direction pin

float ppr = 1570.0; // pulse per revolution
float samplingTime = 100.0; // 1 second

int state=0;
long int posisi=0;
float sudut=0;
float lastPosisi=0;

float kecepatan=0;

unsigned long prevMillis = 0;

float Kp=6.0, Ki=6.0, Kd=0.30, Hz=10;
int output_bits = 8;
bool output_signed = true;

int setpoint = 60; // rpm

uint8_t output;

FastPID speedPID(Kp, Ki, Kd, Hz, output_bits, output_signed);

void ISR_INT0(){
    int pinA,pinB;
    pinA=digitalRead(2);
    pinB=digitalRead(3);
    if(pinA==LOW && pinB==LOW){
        posisi--; // CCW
    }
    if(pinA==LOW && pinB==HIGH){
        posisi++; 
    }
    if(pinA==HIGH&& pinB==LOW){
        posisi++; // CCW
    }
    if(pinA==HIGH && pinB==HIGH){
        posisi--; // CCW
    }
}
void ISR_INT1(){
    int pinA,pinB;
    pinA=digitalRead(2);
    pinB=digitalRead(3);
    if(pinA==LOW && pinB==LOW){
        posisi++; // CCW
    }
    if(pinA==LOW && pinB==HIGH){
        posisi--; 
    }
    
    if(pinA==HIGH&& pinB==LOW){
        posisi--; // CCW
    }
    if(pinA==HIGH && pinB==HIGH){
        posisi++; // CCW
    }
}
void setup() {
    // initialize serial communications at 9600 bps:
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT); // untuk indikator
    pinMode(2,INPUT_PULLUP);
    pinMode(3,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(2), ISR_INT0, CHANGE);
    attachInterrupt(digitalPinToInterrupt(3), ISR_INT1, CHANGE);

    pinMode(PWM, OUTPUT);
    pinMode(fwd, OUTPUT);
    pinMode(rev, OUTPUT);

    digitalWrite(fwd, HIGH);
    digitalWrite(rev, LOW);
    analogWrite(PWM, 0);

    prevMillis = millis();
    lastPosisi = posisi;
}
void loop() {
    //Konversikan hasil pengukuran rotary encoder menjadi sudut pergerakan motor

    if(millis() - prevMillis >= samplingTime){
        float kecepatan = ((posisi - lastPosisi) / samplingTime)*(1000.0/samplingTime);
        prevMillis = millis();
        lastPosisi = posisi;
        output = speedPID.step(setpoint, kecepatan);
        analogWrite(PWM, map(output, 0,255, 0, 100));
        Serial.print("Posisi: ");
        Serial.print(map(output, 0,255, 0, 100));
        Serial.print("Kecepatan: ");
        Serial.println(float (kecepatan));
    }
    
//    if(millis() - prevMillis >= samplingTime){
//      
//    }
    

    
    
//    sudut = ppr * 360.0 / posisi;
    
}
