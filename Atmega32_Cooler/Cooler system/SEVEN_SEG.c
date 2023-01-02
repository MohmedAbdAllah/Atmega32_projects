/*
 * CFile1.c
 *
 * Created: 8/16/2022 8:08:52 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "SEVEN_SEG.h"

/**************************************************************************
* Function Name: SEVEN_SEG_init
* Purpose      : Configure seven segment port
* Parameters   : void
* Return value :void
**************************************************************************/
void SEVEN_SEG_init(void){
	INIT_SEVEN_SEG_PINS;	
}

/**************************************************************************
* Function Name: SEVEN_SEG_write
* Purpose      : write number in seven segment can be from 0 to 9
* Parameters   : data = number fro 0 to 9
* Return value :void
**************************************************************************/
void SEVEN_SEG_write(uint8_t data){
	EN1(1);
	A(READBIT(data,0));
	B(READBIT(data,1));
	C(READBIT(data,2));
	D(READBIT(data,3));
}

/**************************************************************************
* Function Name: SEVEN_SEG_write_on2
* Purpose      : write number in two seven segment can be from 0 to 9
* Parameters   : data = number fro 0 to 9
* Return value :void
**************************************************************************/
void SEVEN_SEG_write_on2(uint8_t data){
	uint8_t x = data % 10;
	EN1(1);
	EN2(0);
	A(READBIT(x,0));
	B(READBIT(x,1));
	C(READBIT(x,2));
	D(READBIT(x,3));
	_delay_ms(5);
	
	x = data / 10;
	EN1(0);
	EN2(1);
	A(READBIT(x,0));
	B(READBIT(x,1));
	C(READBIT(x,2));
	D(READBIT(x,3));
	_delay_ms(5);
}