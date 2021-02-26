// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = ON        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include "tp5.h"
#include <string.h>

void main(){
    //Configura entradas y salidas
    ANSEL=0;
    ANSELH=0;
    OPTION_REG=0x04;
    TRISA=0x03;
    TRISB=0x10;
    TRISC=0x00;
    
    //Configura puerto AD
    ANSELH=0;
    ANSELHbits.ANS1=1; 
    ADCON1bits.ADFM=1;
    ADCON1bits.VCFG0=0; ADCON1bits.VCFG1=0;
    ADCON0bits.ADON=1;
    ADCON0bits.CHS0=1; ADCON0bits.CHS1=0; ADCON0bits.CHS2=0; ADCON0bits.CHS3=1;

    InicializarDisplay();
    while(1){
        //MIDE TEMPERATURA
        GO_DONE=1; // empieza la conversión
        __delay_ms(1); // espera el fin de la conversión
        resultado=ADRESH<<8;
        resultado=resultado+ADRESL; //0-1024
        while(resultado>9){
            cosa[3]=resultado%10;
            cosa[2]=cosa[3]%10;
            cosa[1]=cosa[2]%10;
            cosa[0]=cosa[1]%10;
        }
        Mostrar(cosa2,0,0);
        Mostrar(cosa,0,1);
    }
}
