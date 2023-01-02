/*
 * KEYPAD.h
 *
 * Created: 8/14/2022 9:52:00 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_macros.h"
#define INIT_KEYPAD_PIN   DDRD = 0b11110000;\
				          PORTD = 0b1111;
#define K0 READBIT(PIND,PIND0)
#define K1 READBIT(PIND,PIND1)
#define K2 READBIT(PIND,PIND2)
#define K3 READBIT(PIND,PIND3)

#define K4(x) if(x == 1) SETBIT(PORTD,PIND4); else CLRBIT(PORTD,PIND4);
#define K5(x) if(x == 1) SETBIT(PORTD,PIND5); else CLRBIT(PORTD,PIND5);
#define K6(x) if(x == 1) SETBIT(PORTD,PIND6); else CLRBIT(PORTD,PIND6);
#define K7(x) if(x == 1) SETBIT(PORTD,PIND7); else CLRBIT(PORTD,PIND7);


void KEYPAD_init(void);
uint8_t KEYPAD_read(void);




#endif /* KEYPAD_H_ */