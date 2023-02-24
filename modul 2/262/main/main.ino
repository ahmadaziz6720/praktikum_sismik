#define A 2
#define B 4
#define C 5
#define D 18
#define E 19
#define F 21
#define G 22
#define H 23
#define BUTTON 15

void setup() {
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(H, OUTPUT);

    digitalWrite(A, 1);
    pinMode(BUTTON, INPUT_PULLDOWN);
}

int counter = 0;
int buttonArr[8] = {2, 4, 5, 18, 19, 21, 22, 23};

void loop() {
  if (counter > 7) {
    counter = 0;
  }
  
  if (digitalRead(BUTTON) == 1) {
    delay(100);
    digitalWrite(buttonArr[counter], 0);
    counter++;
    digitalWrite(buttonArr[counter], 1);
  }
}
