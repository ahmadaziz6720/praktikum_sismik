#include <PCF8574.h>

PCF8574 pcf8574(0x20);

void setup(){
    pcf8574.pinMode(P1,INPUT); // untuk INPUT
    pcf8574.pinMode(P0,OUTPUT); // untuk OUTPUT
    pcf8574.begin();
}

void loop(){
    pcf8574.digitalWrite(P0, HIGH); // untuk HIGH
    delay(1000);
    pcf8574.digitalWrite(P0, LOW); // untuk LOW
    delay(1000);
}