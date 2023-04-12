// Praktikum EL3116 - Sistem Microprosesor
// Modul : 4
// Percobaan : 1
// Tanggal : 31 Maret 2023
// Kelompok : 10
// Rombongan : B
// Nama (NIM) 1 : Ahmad Aziz (13220034)
// Nama (NIM) 2 : Emmanuella Pramudita Rumanti (13220031)
// Nama File : main.ino
// Deskripsi : code for reading MPU6050 sensors

#include "Wire.h"
#define MPU_ADDR 0x68

int16_t accX, accY, accZ;
float rangePerDigit = .000061f;
float NormAccX,NormAccY,NormAccZ;
int pitch, roll;

void setup() {
  	Serial.begin(9600);
  	Wire.begin();
  	Wire.beginTransmission(MPU_ADDR);
  	Wire.write(0x6B);
  	Wire.write(0);
  	Wire.endTransmission(true);
}

void loop() {
	Wire.beginTransmission(MPU_ADDR);
  	Wire.write(0x3B);
  	Wire.endTransmission(false);
  	Wire.requestFrom(MPU_ADDR, 14, true);

	//Pembacaan urut dari alamat accX
  	accX = Wire.read() << 8 | Wire.read();
  	accY = Wire.read() << 8 | Wire.read();
  	accZ = Wire.read() << 8 | Wire.read();

	//Normalisasi Raw Data tersebut
  	NormAccX = accX * rangePerDigit * 9.80665f;
  	NormAccY = accY * rangePerDigit * 9.80665f;
  	NormAccZ = accZ * rangePerDigit * 9.80665f;

	//Mengkalkulasi pitch dan roll
	pitch = -(atan2(NormAccX, sqrt(NormAccY*NormAccY + NormAccZ* NormAccZ)) * 180.0) / M_PI;
	roll = (atan2(NormAccY, NormAccZ)*180.0)/M_PI;

	//Output Serial
  	Serial.print("Pitch: ");
  	Serial.print(pitch);
  	Serial.print(" Roll: ");
  	Serial.println(roll);
  	delay(100);
}
