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
  148, 168, 186, 204, 219, 232, 242, 250, 254, 255, 253, 248, 240, 229, 215, 199, 
  181, 162, 142, 122, 102, 82, 64, 47, 32, 20, 10, 4, 0, 0, 3, 9, 18, 30, 44, 61, 
  79, 98, 118, 139, 159, 178, 196, 212, 226, 238, 247, 253, 255, 255, 251, 244, 234, 
  222, 207, 190, 171, 152, 131, 111, 91, 72, 54, 39, 25, 14, 6, 1, 0, 1, 6, 13, 24, 
  37, 53, 70, 89, 109, 129, 149, 169, 188, 205, 220, 233, 243, 250, 255, 255, 253, 
  248, 239, 228, 214, 198, 180, 161, 141, 120, 100, 81, 62, 46, 31, 19, 10, 3, 0, 
  0, 3, 9, 19, 31, 45, 62, 80, 100, 120, 140, 160, 179, 197, 213, 227, 239, 247, 
  253, 255, 255, 251, 243, 233, 220, 205, 188, 170, 150, 130, 109, 89, 71, 53, 38, 
  24, 14, 6, 1, 0, 1, 6, 14, 25, 38, 54, 72, 91, 111, 131, 151, 171, 189, 206, 221, 
  234, 244, 251, 255, 255, 253, 247, 238, 227, 213, 196, 178, 159, 139, 119, 98, 
  79, 61, 44, 30, 18, 9, 3, 0, 0, 3, 10, 20, 32, 47, 63, 82, 101, 122, 142, 162, 
  181, 199, 215, 228, 240, 248, 253, 255, 254, 250, 243, 232, 219, 204, 187, 168, 
  148, 128, 108, 88, 69, 52, 36, 23, 13, 5, 1, 0, 2, 7, 15, 26, 40, 56, 73, 92, 
  112, 133, 153, 172, 191, 208, 222, 235, 245, 251, 255, 255, 252, 246, 237, 226, 
  211, 195, 177, 157, 137, 117, 97, 77, 59, 43, 29, 17, 8, 2, 0, 0, 4, 11, 21, 33, 
  48, 65, 83, 103, 123, 144, 164, 183, 200, 216, 230, 240, 249, 254, 255, 254, 250, 
  242, 231, 218, 203, 185, 166, 147, 126, 106, 86, 68, 50, 35, 22, 12, 5, 1, 0, 2, 7, 
  16, 27, 41, 57, 75, 94, 114, 134, 154, 174, 192, 209, 224, 236, 245, 252, 255, 255, 
  252, 246, 236, 224, 210, 193, 175, 156, 136, 115, 95, 76, 58, 42, 28, 16, 8, 2, 0, 
  0, 4, 11, 22, 34, 49, 66, 85, 105, 125, 145, 165, 184, 202, 217, 231, 241, 249, 254, 
  255, 254, 249, 241, 230, 217, 201, 184, 165, 145, 125, 104, 85, 66, 49, 34, 21, 11, 
  4, 0, 0, 2, 8, 17, 28, 42, 58, 76, 96, 116, 136, 156, 176, 194, 210, 225, 237, 246, 
  252, 255, 255, 252, 245, 236, 223, 209, 192, 174, 154, 134, 114, 94, 74, 57, 41, 27, 
  16, 7, 2, 0, 1, 5, 12, 22, 35, 51, 68, 87, 106, 127, 147, 167, 186, 203, 218, 232, 
  242, 250, 254, 255, 254, 248, 240, 229, 216, 200, 182, 163, 143, 123, 103, 83, 65, 
  48, 33, 20, 11, 4, 0, 0, 3, 8, 17, 29, 43, 60, 78, 97, 117, 138, 158, 177, 195, 212, 
  226, 238, 247, 252, 255, 255, 251, 244, 235, 222, 207, 190, 172, 152, 132, 112, 92, 73, 
  55, 39, 26, 15, 7, 1, 0, 1, 5, 13, 23, 37, 52, 69, 88
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
