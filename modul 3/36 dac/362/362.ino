#include <Wire.h>
#include <math.h>
#define ResTable 512 //Membuat sinusoid 1kHz dengan look up table 9 bit
#define freq 1000 //Definisikan Frekuensi Sinusoid
#define DAC1 25 // DAC

int i;
int DACInput;

float delayVal = ... //Masukan nilai delayVal agar frekuensi yang diterima nano receiver benar-benar 1kHz;

const PROGMEM uint16_t DAC_LookUpTable[512] = {
  // isi dengan sinyal digital sinusoidal dalam format 8-bit
};

void setup(void){
  Serial.begin(9600);
}

void loop(void){
  for(i = 0; i < ResTable; i++) {
    DACInput = pgm_read_word(&(DAC_LookUpTable[i]));
    dacWrite(DAC1, DACInput);
    delayMicroseconds(round(delayVal*1000000));
  }
}
