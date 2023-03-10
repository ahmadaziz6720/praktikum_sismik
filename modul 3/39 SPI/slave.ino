#include <SPI.h>
#define interruptPin 2 //INT0
bool pushed = 0;
int dataSend;
int dataRx;

void setup(){
    pinMode(interruptPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(interruptPin),
    ButtonPushed, FALLING);
    Serial.begin(9600);


}

void loop(){
    
}