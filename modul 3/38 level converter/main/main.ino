//ADC internal nano adalah 10 bit, nilai maksimal 1024
#define ResADC 1023
#define Vin 4.7 // Voltage Nano di sekitar situ
// pin yang digunakan
#define digitalOutput 7
#define analogPin A0

float Vout;

void setup(){
    Serial.begin(9600);
    pinMode(digitalOutput, OUTPUT);
}

void loop() {
    /* Konversi tegangan HIGH */
    // set pin menjadi HIGH
    // baca nilai input tegangan dari output level converter
    // kirim melalui serial communication

    digitalWrite(digitalOutput, HIGH); // set pin menjadi HIGH
    Vout = analogRead(analogPin) * Vin / ResADC; // baca nilai input tegangan dari output level converter
    Serial.println(Vout); // kirim melalui serial communication

    delay(1000);
    /* Konversi tegangan LOW */
    // set pin menjadi LOW
    // baca nilai input tegangan dari output level converter
    // kirim melalui serial communication

    digitalWrite(digitalOutput, LOW); // set pin menjadi LOW
    Vout = analogRead(analogPin) * Vin / ResADC; // baca nilai input tegangan dari output level converter
    Serial.println(Vout); // kirim melalui serial communication

    delay(1000);
}
