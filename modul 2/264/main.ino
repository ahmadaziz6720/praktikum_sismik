#define A 2
#define B 4
#define C 5
#define D 18
#define E 19
#define F 21
#define G 22
#define H 23

// setup timer interupt timer 0 esp32
hw_timer_t * My_timer = NULL;

void IRAM_ATTR onTimer(){
    digitalWrite(A, !digitalRead(A));
    digitalWrite(B, !digitalRead(B));
    digitalWrite(C, !digitalRead(C));
    digitalWrite(D, !digitalRead(D));
    digitalWrite(E, !digitalRead(E));
    digitalWrite(F, !digitalRead(F));
    digitalWrite(G, !digitalRead(G));
    digitalWrite(H, !digitalRead(H));
}

void setup() {
    // put your setup code here, to run once:
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(H, OUTPUT);

    // setup timer interupt timer 0 esp32
    My_timer = timerBegin(0, 80, true);
    timerAttachInterrupt(My_timer, &onTimer, true);
    timerAlarmWrite(My_timer, 1000000, true);
    timerAlarmEnable(My_timer);
}

void loop() {
    // put your main code here, to run repeatedly:
}