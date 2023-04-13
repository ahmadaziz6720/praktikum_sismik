/*
Mengukur posisi relatif rotary encoder dengan INT0 dan INT1
*/

int state=0;
long int posisi=0;
float radNew, radPrev, t1, t2;
float radLast = 0;

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
	radNew = float(posisi)*2*PI/m; // ganti m dengan konstanta motor
	
	Serial.print("rad: ");
	Serial.println(radA); 
	
	radLast = radNew;
	t2 = millis(); 
	
	Serial.print("rad/s: ");
	Serial.println(((radLast-prevRad)/(t2-t1)) * 1000);
	
	prevRad = radLast;
	t1 = t2;
	
	delay(500);
}
