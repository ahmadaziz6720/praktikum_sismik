#include <PCF8574.h>

PCF8574 pcf8574(/* alamat PCF8574 */);


void setup(){
    pcf8574.pinMode(/* PIN */,INPUT); // untuk INPUT
    pcf8574.pinMode(/* PIN */,OUTPUT); // untuk OUTPUT
    pcf8574.begin();

}

void loop(){
    pcf8574.digitalWrite(/* PIN */, HIGH); // untuk HIGH
    pcf8574.digitalWrite(/* PIN */, LOW); // untuk LOW
    
}