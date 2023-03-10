#define pinAnalog A0

int sinyalADC;
float nilaiTegangan;

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

  //Modifikasi program sebelumnya untuk mengkonversikan nilai sinyal analog
  //yang terbaca ke nilai tegangan yang terukur di Arduino IDE
  nilaiTegangan = (sinyalADC / 5) / 1023; // tegangan max 5V resolusi 1024
  
}
