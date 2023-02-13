/*******************************************************
This program was created by the CodeWizardAVR V3.48a
Automatic Program Generator
© Copyright 1998-2022 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro
Project : Tugas 1.5.4
Version : TP
Date : 09/02/2023
Author : Amelia Ats Tsaniyah F./13220002
Chip type : ATmega328P
Program type : Application
AVR Core Clock frequency: 16.000000 MHz
Memory model : Small
External RAM size : 0
Data Stack size : 512
*******************************************************/
#include <mega328.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <delay.h>
//SET COUNT VALUE FOR 1 HZ
#define TCNT_HIGH 0xC2
#define TCNT_LOW 0xF7
void init_int(void) {
	//set prescaler 1024
	TIMSK1=0b000001;
	TCCR1B=0b00000101;

	TCNT1H=TCNT_HIGH;
	TCNT1L=TCNT_LOW;

	//Enable Interrupt
	#asm("sei")
}
interrupt [TIM1_OVF] void timer1_ovf_isr(void) {
	//LED ON, jeda 1 detik
	PORTD = 0xFF;
	delay_ms(1000);

	//Set time TCNT1, untuk batas overflow
	TCNT1H=TCNT_HIGH;
	TCNT1L=TCNT_LOW;
}

void main(void) {
	init_int();
	DDRD = 0xFF;//Assign DDR PIN D sebagai output
	UCSR0B = 0x00;//Unable Comm Serial untuk RX TX

	PORTD = 0x00;//inisialisasi
	while (1) {
		//Register Assignment ke port, arduino nano D--> b
		PORTD = 0b10101010;//1 adalah on, 0 adalah off
		delay_ms(100);// jeda 100ms
		PORTD = 0b01010101;
		delay_ms(100);
	}
}
