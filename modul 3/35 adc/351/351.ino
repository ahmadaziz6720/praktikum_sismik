#define pinAnalog A0

int sinyalADC;

void setup() {
  //Pilih nilai port serial
  Serial.begin(9600);
  
  //Pendefinisian mode pinAnalog
  pinMode(pinAnalog, INPUT);
}

void loop() {
  //Baca nilai sinyal analog
  bacaAnalog = analogRead(pinAnalog);
  
  //Print nilai sinyal 
  Serial.println(bacaAnalog);
}
