#ifndef TP5_H
#define	TP5_H

#define _XTAL_FREQ 4000000
#define D0 PORTCbits.RC0
#define D1 PORTCbits.RC1
#define D2 PORTCbits.RC2
#define D3 PORTCbits.RC3
#define D4 PORTCbits.RC4
#define D5 PORTCbits.RC5
#define D6 PORTCbits.RC6
#define D7 PORTCbits.RC7

#define RS PORTBbits.RB7
#define RW PORTBbits.RB6
#define E PORTBbits.RB5

//VARIABLES

//FUNCIONES
void InicializarDisplay(void);
void BorrarDisplay(void);
//void Mostrar(char *str, unsigned char pos, unsigned char linea);
void Posicionar(unsigned char pos, unsigned char linea);

#endif	/* TP5_H */
