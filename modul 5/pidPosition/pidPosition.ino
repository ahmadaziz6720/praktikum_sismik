// Praktikum EL3116 - Sistem Microprosesor
// Modul : 5
// Percobaan : 3
// Tanggal : 13 April 2023
// Kelompok : 10
// Rombongan : B
// Nama (NIM) 1 : Ahmad Aziz (13220034)
// Nama (NIM) 2 : Emmanuella Pramudita Rumanti (13220031)
// Nama File : pidPosition.ino
// Deskripsi : position control using PID

#include <FastPID.h>

#define PWM 5 // PWM output pin
#define fwd 6 // forward direction pin
#define rev 7 // reverse direction pin

#define ppr 600 // pulse per revolution
#define samplingTime 100 // 1 second

int state=0;
long int posisi=0;
float sudut=0;
float lastPosisi=0;

float kecepatan=0;

unsigned long prevMillis = 0;

float Kp=0.1, Ki=0.5, Kd=0, Hz=10;
int output_bits = 8;
bool output_signed = true;

int setpoint = 60; // rpm

uint8_t output;

FastPID positionPID(Kp, Ki, Kd, Hz, output_bits, output_signed);

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
    analogWrite(PWM, 255);

    prevMillis = millis();
    lastPosisi = posisi;
}
void loop() {
    //Konversikan hasil pengukuran rotary encoder menjadi sudut pergerakan motor

    if(millis() - prevMillis >= samplingTime){
        prevMillis = millis();
        lastPosisi = posisi;
        kecepatan = getSpeed()*60/ppr; //rpm
    }

    output = positionPID.step(setpoint, posisi);
    analogWrite(PWM, output);
    
    sudut = ppr * 360.0 / posisi;
    Serial.print("Posisi: ");
    Serial.print(posisi);
    Serial.print(" Sudut: ");
    Serial.print(sudut);
    Serial.print("Kecepatan: ");
    Serial.println(kecepatan);
}

float getSpeed(){
    float speed = 0;
    speed = ((posisi - lastPosisi) / samplingTime)*(1000/samplingTime); //pulse per detik
    return speed;
}