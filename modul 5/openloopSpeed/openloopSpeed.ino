// Praktikum EL3116 - Sistem Microprosesor
// Modul : 5
// Percobaan : 1
// Tanggal : 13 April 2023
// Kelompok : 10
// Rombongan : B
// Nama (NIM) 1 : Ahmad Aziz (13220034)
// Nama (NIM) 2 : Emmanuella Pramudita Rumanti (13220031)
// Nama File : openloopSpeed.ino
// Deskripsi : speed control using PWM and read speed using encoder

#define PWM 5 // PWM output pin
#define fwd 6 // forward direction pin
#define rev 7 // reverse direction pin


float samplingTime = 50.0; // 1 second

float ppr = 1570.0; // pulse per revolution
int state=0;
long int posisi=0;
float sudut=0;
float lastPosisi=0;

float kecepatan=0;
float speed;

unsigned long prevMillis = 0;

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

    digitalWrite(fwd, LOW);
    digitalWrite(rev, HIGH);
    analogWrite(PWM, 40);

    prevMillis = millis();
    lastPosisi = posisi;
}
void loop() {
    //Konversikan hasil pengukuran rotary encoder menjadi sudut pergerakan motor

    if(millis() - prevMillis >= samplingTime){
        prevMillis = millis();
        lastPosisi = posisi;
        
    }
    float kecepatan = ((posisi - lastPosisi) / samplingTime)*(1000.0/samplingTime);
    if(millis() - prevMillis >= samplingTime){
      Serial.print("Posisi: ");
      Serial.print(sudut);
      Serial.print("Kecepatan: ");
      Serial.println(float (kecepatan));
    }
    
    
    sudut = ppr * 360.0 / posisi;
    
}
