#include <SPI.h>
#define interruptPin 2 //INT0
#define LED 3
bool pushed = 0;
int dataSend;
int dataRx;

//MISO (D12), MOSI(D11), SCK(D13), SS(D10).
#define MISO 12
#define MOSI 11
#define SCK 13
#define SS 10

void SPITransmit(){
    //Mengirim data ke slave, dan di saat bersamaan, menerima data dari slave. Data dari slave tersebut kemudian dianalisis. Jika data bernilai 1,hidupkan LED selama 1 detik. 
    //Jika data bernilai 0, matikan LED selama 1 detik.
    digitalWrite(SS,LOW);
    dataSend = 1;
    dataRx = SPI.transfer(dataSend);
    digitalWrite(SS,HIGH);
    if(dataRx == 1){
        digitalWrite(LED,HIGH);
    }else{
        digitalWrite(LED,LOW);
    }
}

void setup(){
    pinMode(interruptPin, INPUT);
    pinMode(LED,OUTPUT);

    attachInterrupt(digitalPinToInterrupt(interruptPin),SPITransmit, FALLING);
    Serial.begin(9600);

    //SPI Init
    //Lakukan proses inisiasi SPI
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV4);
    SPI.setDataMode(SPI_MODE0);
    SPI.setBitOrder(MSBFIRST);
}

void loop(){
    // Memulai Komunikasi dengan Slave
}
