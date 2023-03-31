String dataMaster1 = "1";
String dataMaster2 = "0";

void setup() {
  //Pilih nilai port serial
  Serial.begin(9600);
}

void loop() {
  //Tulis dataMaster1 ke port serial
  Serial.println(dataMaster1);
  
  //Berikan delay
  delay(1000);
  
  //Tulis dataMaster2 ke port serial
  Serial.println(dataMaster2);
  
  //Berikan delay
  delay(1000);
}
