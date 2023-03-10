#include <SPI.h>
#define interruptPin 2 //INT0
#define LED 3
bool pushed = 0;
int dataSend;
int dataRx;

void SPITransmit(){

}

void setup(){
    pinMode(interruptPin, INPUT);
    pinMode(LED,OUTPUT);
    attachInterrupt(digitalPinToInterrupt(interruptPin),SPITransmit, FALLING);
    Serial.begin(9600);

    //SPI Init
    //Lakukan proses inisiasi SPI
}

void loop(){
    // Memulai Komunikasi dengan Slave
    //Mengirim data ke slave, dan di saat bersamaan, menerima data dari slave. Data dari slave tersebut kemudian dianalisis. Jika data bernilai 1,hidupkan LED selama 1 detik. 
}

