#include <xc.h>
#include "tp5.h"
#include <stdlib.h>
#include <stdio.h>

void InicializarDisplay(void){
    //Display on/off
    E = 1;
    RS = 0;
    PORTC = 0b00001111;
    E = 0;
    __delay_ms(1);
    //Fuction set
    E = 1;
    RS = 0;
    PORTC = 0b00111000;
    E = 0;
    __delay_ms(1);
    //Entry Mode Set
    E = 1;
    RS = 0;
    PORTC = 0b00000110;
    E = 0;
    __delay_ms(1);
    //Return Home
    E = 1;
    RS = 0;
    PORTC = 0b00000010;
    E = 0;
    __delay_ms(2);
}

void BorrarDisplay(void){
    //Display Clear
    RS=0; E=1;
    PORTB=0b00000001;
    E=0;
    __delay_ms(10);
}

void Posicionar(unsigned char pos, unsigned char linea){
    unsigned char cosa, i=0;
    if(linea==1) pos = pos | 0x80;
    else pos = pos | 0x40 | 0x80;
    RS=0; E=1;
    PORTC=pos;
    E=0;
    __delay_ms(1);
}

void putch(char c) {
    RS = 1;
    E = 1;
    __delay_ms(1);
    if (c < 200) PORTC = c;
    else PORTC = c - 200;
    E = 0;
    __delay_ms(1);
}
