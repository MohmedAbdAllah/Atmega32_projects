/*
 * USART.c
 *
 * Created: 8/29/2022 8:30:11 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "USART.h"
extern void (*USART_rxc_vect)(void);
/*****************************************************************************
* Function Name: USART_init
* Purpose      : init usart with two stop bit, no parity, baud rate 9600 and 8 bit data
* Parameters   : void
* Return value : void
*****************************************************************************/
void USART_init(){
	//Baud_rate setting (normal mode ,baud = 9600)
	//CLRBIT(UCSRA,U2X);
	
	UBRRL = UBRR_reg;
	UBRRH = (UBRR_reg >> 8);
	// Set frame format: 8data, 2stop bit
	UCSRC = (1<<URSEL)|(3<<UCSZ0);
	//Enable receiver and transmitter
	SETBIT(UCSRB,TXEN);
	SETBIT(UCSRB,RXEN);
	
	//Enable interrupt
	SETBIT(UCSRB,RXCIE);
	SETBIT(SREG,7);
}
/*****************************************************************************
* Function Name: Uart_tx
* Purpose      : Send 8-bit data and make sure the data is out
* Parameters   : uint8_t  data to send
* Return value : void
*****************************************************************************/
void USART_tx(uint8_t data){
	// Wait for empty transmit buffer 
	while(READBIT(UCSRA,UDRE) == 0);
	//write the data in the buffer
	UDR = data;
	//wait transmit shift register has been shifted out
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

ISR(USART_RXC_vect){
	USART_rxc_vect();
}