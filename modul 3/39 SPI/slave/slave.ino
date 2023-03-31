#include <SPI.h>
#define interruptPin 2 //INT0
bool pushed = 0;
int dataSend;
int dataRx;

//MISO (D12), MOSI(D11), SCK(D13), SS(D10).
#define MISO 12
#define MOSI 11
#define SCK 13
#define SS 10

void ButtonPushed(){
    //Saat button pada slave ditekan, LED yang terkoneksi pada server akan menyala. Saat button pada master ditekan, Slave akan merespon dengan mengirimkan data serial ke monitor berupa “Tombol Master ditekan!”
    digitalWrite(SS,LOW);
    dataSend = 1;
    dataRx = SPI.transfer(dataSend);
    digitalWrite(SS,HIGH);
    if(dataRx == 1){
        Serial.println("Tombol Master ditekan!");
    }
    pushed = 0;
}

void setup(){
    pinMode(interruptPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(interruptPin), ButtonPushed, FALLING);
    Serial.begin(9600);

    //SPI Init
    //Lakukan proses inisiasi SPI
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV4);
    SPI.setDataMode(SPI_MODE0);
    SPI.setBitOrder(MSBFIRST);

    SPCR |= _BV(SPE); 

    SPI.attachInterrupt(); 
}

void loop(){
    //komunikasi SPI dengan master
}
