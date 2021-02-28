// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = ON
#pragma config CP = OFF
#pragma config CPD = OFF
#pragma config BOREN = OFF
#pragma config IESO = ON
#pragma config FCMEN = ON
#pragma config LVP = OFF
#pragma config BOR4V = BOR40V
#pragma config WRT = OFF

// CONFIG2
#pragma config BOR4V = BOR40V // Brown-out Reset Selection bit(Brown-out Reset set to 4.0V)
#pragma config WRT = OFF // Flash Program Memory Self Write Enablebits (Write protection off)

#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include "tp5.h"
#include <string.h>

void main(){
    //Configura entradas y salidas
//    OPTION_REG=0x04;
    TRISA=0xFF;
    TRISB=0x00;
    TRISC=0x00;
    
    //Configura puerto AD
    ANSEL=0;
    ANSELbits.ANS1=1;
    ADCON1bits.ADFM=1;
    ADCON1bits.VCFG0=0;
    ADCON1bits.VCFG1=0;
    ADCON0bits.ADON=1;
    ADCON0bits.CHS=1;

    float valor;
    unsigned int caca;
    InicializarDisplay();
    BorrarDisplay();
    while (1)
    {
        ADCON0bits.GO=1;
        while (ADCON0bits.GO==1)
        {
        }
        caca= (ADRESH<<8)+ADRESL;
        __delay_ms(2);
        valor= (((float)caca)*5/1023)*100;
        Posicionar(0, 1);
        printf (" Temperatura : ");    
        Posicionar(3, 2);
        printf ("  %.1f", valor);
    }
}

void Putch(char c){
    RS=1;RW=0;E=1;
    if(c<200) PORTC=c;
    else PORTC=c-200;
    E=0;
    __delay_ms(1);
}
