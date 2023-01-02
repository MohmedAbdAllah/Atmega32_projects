/*
 * Communication_Slave.c
 *
 * Created: 12/3/2022 7:05:59 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "SLAVE.h"
static void usart_rxc_vect(void);
static void spi_stc_vect(void);
static uint8_t SPI_data = 0;
static uint8_t UART_data = 0;
int main(void)
{
    //initialize LCD and SPI peripherals
	SPI_stc_vect = spi_stc_vect;
	USART_rxc_vect = usart_rxc_vect;
	LCD_init();
	SPI_init_slave();
	USART_init();
    while (1) 
    {
		//get the slave read and print it in the LCD
		LCD_write_command(0x80);
		LCD_write_num(SPI_data);
		LCD_write_command(0x85);
		LCD_write_num(UART_data);
		USART_tx(UART_data);
    }
}
static void spi_stc_vect(){
	SPI_data = SPDR;
}

static void usart_rxc_vect(){
	UART_data = UDR;
	
}