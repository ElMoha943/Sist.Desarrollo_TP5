#ifndef TP5_H
#define	TP5_H

#define _XTAL_FREQ 4000000
#define D0 PORTBbits.RB7
#define D1 PORTBbits.RB6
#define D2 PORTBbits.RB5
#define D3 PORTCbits.RB4
#define D4 PORTBbits.RB3
#define D5 PORTBbits.RB2
#define D6 PORTBbits.RB1
#define D7 PORTBbits.RB0

#define RS PORTCbits.RC7
#define RW PORTCbits.RC6
#define E PORTCbits.RC5

//VARIABLES
int resultado;
char cosa[10], cosa2[]="TEMPERATURA:";

//FUNCIONES
void InicializarDisplay(void);
void Mostrar(char *str, unsigned char pos, unsigned char linea);
void BorrarDisplay(void);

#endif	/* TP5_H */
