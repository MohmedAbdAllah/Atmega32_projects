/*
 * KEYPAD.h
 *
 * Created: 8/14/2022 9:52:00 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "std_macros.h"
#define INIT_KEYPAD_PIN   DDRB = 0b11110000;\
				          PORTB = 0b1111;
#define K0 READBIT(PINB,PINB0)
#define K1 READBIT(PINB,PINB1)
#define K2 READBIT(PINB,PINB2)
#define K3 READBIT(PINB,PINB3)

#define K4(x) if(x == 1) SETBIT(PORTB,PINB4); else CLRBIT(PORTB,PINB4);
#define K5(x) if(x == 1) SETBIT(PORTB,PINB5); else CLRBIT(PORTB,PINB5);
#define K6(x) if(x == 1) SETBIT(PORTB,PINB6); else CLRBIT(PORTB,PINB6);
#define K7(x) if(x == 1) SETBIT(PORTB,PINB7); else CLRBIT(PORTB,PINB7);


void KEYPAD_init(void);
uint8_t KEYPAD_read(void);




#endif /* KEYPAD_H_ */