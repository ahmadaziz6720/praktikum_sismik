int ledList[8] = {2, 4, 5, 18, 19, 21, 22, 23};

int i = 0;

//led shift when button pressed
void ledShift(){
    delay(200);
    digitalWrite(ledList[i], !digitalRead(ledList[i]));
    i++;
    if(i == 8){
        i = 0;
    }
}


void setup() {
    // put your setup code here, to run once:
    for (int i = 0; i < 8; i++){
        pinMode(ledList[i], OUTPUT);
    }

    pinMode(15, INPUT_PULLUP);
    attachInterrupt(15, ledShift, RISING);
}

void loop() {
    // put your main code here, to run repeatedly:
}

