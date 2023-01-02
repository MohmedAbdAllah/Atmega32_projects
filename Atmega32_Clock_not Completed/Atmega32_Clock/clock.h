/*
 * clock.h
 *
 * Created: 9/16/2022 12:44:17 PM
 *  Author: mo
 */ 


#ifndef CLOCK_H_
#define CLOCK_H_
#include "std_macros.h"
#include <avr/io.h>


#define PORT_WRITE PORTC
#define E0 CLRBIT(PORTA, 0)
#define E1 CLRBIT(PORTA, 1)
#define E2 CLRBIT(PORTA, 2)
#define E3 CLRBIT(PORTA, 3)
#define E4 CLRBIT(PORTA, 4)
#define E5 CLRBIT(PORTA, 5)
#define E6 CLRBIT(PORTA, 6)
#define E7 CLRBIT(PORTA, 7)
#define RESET PORTA =0xFF;

#define INIT_SS_PIN DDRC |= 0XFF;\
                    DDRA |=0XFF;\
                    PORTA |= 0XFF;


void SEVEN_SEG_write(uint8_t num , uint8_t h_m_s);

	
#endif /* CLOCK_H_ */
