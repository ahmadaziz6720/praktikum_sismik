/*
Mengukur posisi relatif rotary encoder dengan INT0 dan INT1
*/

int state=0;
long int posisi=0;

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
}
void loop() {
	//Konversikan hasil pengukuran rotary encoder menjadi sudut pergerakan motor dalam satuan radian dan kirimkan ke serial monitor
	Serial.print("rad: ");
	Serial.println(float(posisi)*2*PI/m); // ganti m dengan konstanta motor
	delay(500);
}
