/*
 * CFile1.c
 *
 * Created: 9/16/2022 1:06:13 PM
 *  Author: Amro
 */ 

#include "clock.h"


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

void SEVEN_SEG_write(uint8_t num , uint8_t h_m_s){
	INIT_SS_PIN
	uint8_t digit_1= num/10;
	uint8_t digit_2= num%10;
	uint8_t seg1 = 0,seg2 = 0;
	
	
	if(h_m_s == 'h') {seg1 = 1;seg2 = 2;}
	else if(h_m_s == 'm') {seg1 = 3;seg2 = 4;}
	else if(h_m_s == 's') {seg1 = 5;seg2 = 6;}
	
	
	PORT_WRITE = ss_arr[digit_1];
	switch (seg1){
		case 1: E0;break;
		case 2: E1;break;
		case 3: E2;break;
		case 4: E3;break;
		case 5: E4;break;
		case 6: E5;break;
		default:;break;
	}
	
	_delay_us(5);
	RESET;
	PORT_WRITE = ss_arr[digit_2];
	switch (seg2){
		case 1: E0;break;
		case 2: E1;break;
		case 3: E2;break;
		case 4: E3;break;
		case 5: E4;break;
		case 6: E5;break;
		default:;break;
	}
	_delay_us(5);
	RESET;
}
	


// 
// mySS.seven_segment_element = ss_arr[0];
// myPort.port = PORTA;
// *myPort.port = ss_arr[0];