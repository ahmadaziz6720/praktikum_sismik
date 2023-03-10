//ADC internal nano adalah 10 bit, nilai maksimal 1024
#define ResADC 1023
#define Vin 4.68 // Voltage Nano di sekitar situ
// pin yang digunakan
#define digitalOutput 7
#define analogPin A0

void loop() {
    /* Konversi tegangan HIGH */
    // set pin menjadi HIGH
    // baca nilai input tegangan dari output level converter
    // kirim melalui serial communication
    delay(1000);
    /* Konversi tegangan LOW */
    // set pin menjadi LOW
    // baca nilai input tegangan dari output level converter
    // kirim melalui serial communication
    delay(1000);
}
