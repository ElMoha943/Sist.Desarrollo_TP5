#ifndef TP5_H
#define	TP5_H

#define _XTAL_FREQ 4000000

#define RS PORTBbits.RB7
#define E PORTBbits.RB5

//VARIABLES

//FUNCIONES
void InicializarDisplay(void);
void BorrarDisplay(void);
void Posicionar(unsigned char pos, unsigned char linea);

#endif	/* TP5_H */
