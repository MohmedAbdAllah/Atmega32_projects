/*
 * USART.c
 *
 * Created: 8/29/2022 8:30:11 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "USART.h"
/*****************************************************************************
* Function Name: USART_init
* Purpose      : init usart with one stop bit, no parity, baud rate 9600 and 8 bit data
* Parameters   : void
* Return value : void
*****************************************************************************/
void USART_init(){
	CLRBIT(UCSRA,U2X);
	UBRRL = 103;
	
	SETBIT(UCSRB,TXEN);
	SETBIT(UCSRB,RXEN);
	
	UCSRC |= (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
}
/*****************************************************************************
* Function Name: Uart_tx
* Purpose      : Send 8-bit data and make sure the data is out
* Parameters   : uint8_t  data to send
* Return value : void
*****************************************************************************/
void USART_tx(uint8_t data){
	UDR = data;
	while(READBIT(UCSRA,TXC) == 0);
}
/*****************************************************************************
* Function Name: Uart_rx
* Purpose      : wait until receiving 1 byte (sync function)
* Parameters   : void
* Return value : data recieved
*****************************************************************************/
uint8_t USART_rx(void){
	while(READBIT(UCSRA,RXC) == 0);
	return UDR;
}

