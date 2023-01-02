/*
 * SEVEN_SEG.h
 *
 * Created: 8/16/2022 8:08:44 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "std_macros.h"

#define INIT_SEVEN_SEG_PINS DDRC |= 0b11111100
#define EN1(x) if(x == 1) SETBIT(PORTC,2); else CLRBIT(PORTC,2);
#define EN2(x) if(x == 1) SETBIT(PORTC,7); else CLRBIT(PORTC,7);
#define A(x) if(x == 1) SETBIT(PORTC,3); else CLRBIT(PORTC,3);
#define B(x) if(x == 1) SETBIT(PORTC,4); else CLRBIT(PORTC,4);
#define C(x) if(x == 1) SETBIT(PORTC,5); else CLRBIT(PORTC,5);
#define D(x) if(x == 1) SETBIT(PORTC,6); else CLRBIT(PORTC,6);

void SEVEN_SEG_init(void);
void SEVEN_SEG_write(uint8_t);
void SEVEN_SEG_write_on2(uint8_t data);


#endif /* SEVEN_SEG_H_ */