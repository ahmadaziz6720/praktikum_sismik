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

    /*
    digitalWrite(A, !digitalRead(A));
    digitalWrite(B, !digitalRead(B));
    digitalWrite(C, !digitalRead(C));
    digitalWrite(D, !digitalRead(D));
    digitalWrite(E, !digitalRead(E));
    digitalWrite(F, !digitalRead(F));
    digitalWrite(G, !digitalRead(G));
    digitalWrite(H, !digitalRead(H));
    
    delay(500);
    */
    digitalWrite(A, 1);
    delay(500);
    digitalWrite(A, 0);

    digitalWrite(B, 1);
    delay(500);
    digitalWrite(B, 0);

    digitalWrite(C, 1);
    delay(500);
    digitalWrite(C, 0);

    digitalWrite(D, 1);
    delay(500);
    digitalWrite(D, 0);

    digitalWrite(E, 1);
    delay(500);
    digitalWrite(E, 0);

    digitalWrite(F, 1);
    delay(500);
    digitalWrite(F, 0);

    digitalWrite(G, 1);
    delay(500);
    digitalWrite(G, 0);

    digitalWrite(H, 1);
    delay(500);
    digitalWrite(H, 0);

    
    
  }
