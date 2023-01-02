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

#define RESET PORTA =0x03;

#define INIT_SS_PIN DDRC |= 0XFF;\
                    DDRA |=0X03;\
                    PORTA |= 0X03;


void SEVEN_SEG_write(uint8_t num );

	
#endif /* CLOCK_H_ */
