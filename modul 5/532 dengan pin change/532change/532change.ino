/*
Mengukur posisi relatif rotary encoder dengan INT0 dan INT1
*/

// D7 dan D8

int state = 0;
long int posisi = 0;

void changePin(byte pin) {
  *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin)); 
  PCIFR |= bit (digitalPinToPCICRbit(pin)); 
  PCICR |= bit (digitalPinToPCICRbit(pin)); 
}

ISR (PCINT0_vect) { 
  int pinA, pinB; 
  pinA = digitalRead(7);
  pinB = digitalRead(8);
  if (pinA==LOW && pinB==LOW){
    posisi--; //CCW }
  }
  if(pinA==LOW && pinB==HIGH){
    posisi++; //CW
  }
  if(pinA==HIGH&& pinB==LOW){
    posisi++; //CW
  }
  if(pinA==HIGH && pinB==HIGH){
    posisi--; //CCW
  }
}

ISR (PCINT2_vect){ 
  int pinA,pinB;
  pinA=digitalRead(7);
  pinB=digitalRead(8);
  
  if(pinA==LOW && pinB==LOW){
    posisi++; //CW
  }
  if(pinA==LOW && pinB==HIGH){
    posisi--; //CCW
  }
  if(pinA==HIGH && pinB==LOW){
    posisi--; //CCW
  }
  if(pinA==HIGH && pinB==HIGH){
    posisi++; //CW
  }
}

void setup(){
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(7,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  changePin(7);
  changePin(8);
}

void loop() {
  //Konversikan hasil pengukuran rotary encoder menjadi sudut pergerakan motor dalam satuan radian dan kirimkan ke serial monitor
  Serial.print("rad: ");
  Serial.println(float (posisi/1570.0)*2*PI); // ganti m dengan konstanta motor
  delay(500);
}
