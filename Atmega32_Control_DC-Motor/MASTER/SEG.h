/*
 * _7SEG.h
 *
 * Created: 11/25/2022 9:58:55 AM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef SEG_H_
#define SEG_H_

#include "std_macros.h"
#include <avr/io.h>


#define PORT_WRITE PORTC
#define E0 CLRBIT(PORTA, 0)
#define E1 CLRBIT(PORTA, 1)

#define RESET PORTA =0x03;

#define INIT_SS_PIN DDRC |= 0XFF;\
DDRA |=0X03;\
PORTA |= 0X03;


void SEVEN_SEG_write(uint8_t num );



#endif /* 7SEG_H_ */