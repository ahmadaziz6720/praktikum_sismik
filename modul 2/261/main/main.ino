#define A 2
#define B 4
#define C 5
#define D 18
#define E 19
#define F 21
#define G 22
#define H 23

void setup() {
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(H, OUTPUT);
  
}

void loop() {
    // Buatlah kondisi dimana 8 buah LED tersebut (GPIO_OUTPUT_A hingga GPIO_OUTPUT_H) menyala bergantian (menggunakanan gpio_set_level())setiap 0,5 detik dengan menggunakan vTaskDelay dan variabel xDelay di atas.
    
    digitalWrite(A, !digitalRead(A));
    digitalWrite(B, !digitalRead(B));
    digitalWrite(C, !digitalRead(C));
    digitalWrite(D, !digitalRead(D));
    digitalWrite(E, !digitalRead(E));
    digitalWrite(F, !digitalRead(F));
    digitalWrite(G, !digitalRead(G));
    digitalWrite(H, !digitalRead(H));
    
    delay(500);
  }
