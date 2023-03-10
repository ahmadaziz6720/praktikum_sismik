char dataSlave;

void setup() {
  //Pilih nilai port serial
  Serial.begin(9600);
}

void loop() {
  //Baca nilai pada port serial dan definisikan sebagai dataSlave
  Serial.readBytes(dataSlave, 1);
  
  //Cetak dataSlave
  Serial.println(dataSlave);
}
