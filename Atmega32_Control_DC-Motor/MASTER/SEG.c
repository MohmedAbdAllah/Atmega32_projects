/*
 * CFile1.c
 *
 * Created: 9/16/2022 1:06:13 PM
 *  Author: Amro
 */ 

#include "SEG.h"


uint8_t ss_arr[10] = {
	0b0111111,
	0b0000110,
	0b1011011,
	0b1001111,
	0b1100110,
	0b1101101,
	0b1111101,
	0b0000111,
	0b1111111,
	0b1101111
};

void SEVEN_SEG_write(uint8_t num){
	INIT_SS_PIN
	uint8_t digit_1= num/10;
	uint8_t digit_2= num%10;
	
	PORT_WRITE = ss_arr[digit_1];
	E0;
	_delay_us(5);
	RESET;
	PORT_WRITE = ss_arr[digit_2];
	E1;
	_delay_us(5);
	RESET;
}
	


// 
// mySS.seven_segment_element = ss_arr[0];
// myPort.port = PORTA;
// *myPort.port = ss_arr[0];