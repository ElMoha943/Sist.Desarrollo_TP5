#include <xc.h>
#include "tp5.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void InicializarDisplay(void) {
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
    RS=0; RW=0; E=1;
    D7=0; D6=0; D5=0; D4=0;
    D3=0; D2=0; D1=0; D0=1;
    E=0;
    __delay_ms(10);
}

void Posicionar(unsigned char pos, unsigned char linea){
    if(linea==2)
    {
        pos=pos+0x40;
    }
    RS=0;RW=0;E=1;
    PORTC=pos|0x80;
    E=0;
}
