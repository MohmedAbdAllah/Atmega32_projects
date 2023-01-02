/*
 * Atmega32_USART.c
 *
 * Created: 8/29/2022 8:29:05 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "USART.h"
#include "LCD.h"

int main(void)
{
    USART_init();
	LCD_init();
    while (1) 
    {
		LCD_write_command(0x80);
		LCD_write_num(USART_rx());
    }
}

