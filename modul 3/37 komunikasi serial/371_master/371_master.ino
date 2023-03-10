char dataMaster1 = '1';
char dataMaster2 = '0';

void setup() {
  //Pilih nilai port serial
  Serial.begin(9600);
}

void loop() {
  //Tulis dataMaster1 ke port serial
  Serial.write(dataMaster1);
  
  //Berikan delay
  delay(250);
  
  //Tulis dataMaster2 ke port serial
  Serial.write(dataMaster2);
  
  //Berikan delay
  delay(250);
}
