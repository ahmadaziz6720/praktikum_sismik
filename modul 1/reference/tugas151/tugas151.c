/*******************************************************
This program was created by the CodeWizardAVR V3.48a
Automatic Program Generator
© Copyright 1998-2022 Pavel Haiduc, HP InfoTech S.R.L.
http://www.hpinfotech.ro
Project : Tugas 1.5.1
Version : TP
Date : 09/02/2023
Author : Amelia Ats Tsaniyah Fajri/13220002
Chip type : ATmega328P
Program type : Application
AVR Core Clock frequency: 16.000000 MHz
Memory model : Small
External RAM size : 0
Data Stack size : 512
*******************************************************/
#include <mega328.h>
#include <delay.h>

int i;
//Kode Program membuat running LED dari LED LSB ke MSB.

void main(void){
    //Set mode PIN DDR D menjadi OUTPUT
    DDRD = 0xFF;
    //Unable Comm Serial untuk RX TX
    UCSR0B = 0x00;
    i = 0x01; //inisiasi led mulai dari 1
    while (1){
        PORTD = i;//Assign nilai LED ke port
        delay_ms(1000); //jeda 1 detik
        //Loop agar kembali ke awal ketika maksimal saat 1000000000 = 0x80
        //Lanjut dan shift kiri sebanyak 1
        if (i >= 0x80){
            i = 0x01;
        }
        else{
            i = i << 1;
        }
    }
}
