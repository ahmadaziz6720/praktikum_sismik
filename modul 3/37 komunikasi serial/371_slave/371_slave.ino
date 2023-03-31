#include <SoftwareSerial.h>
String dataSlave;
#define rxPin 7
#define txPin 8

SoftwareSerial mySerial (rxPin, txPin);

void setup() {
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  //Pilih nilai port serial
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  //Baca nilai pada port serial dan definisikan sebagai dataSlave
  while (mySerial.available() == 0){
  }
  dataSlave = mySerial.readString();
  
  //Cetak dataSlave
  Serial.println(dataSlave);
}
