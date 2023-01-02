/*
 * Atmega32_ADC.c
 *
 * Created: 8/22/2022 7:22:19 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "ADC.h"
#include "LCD.h"


int main(void)
{
    LCD_init();
	ADC_init();
	
    while (1) 
    {
		LCD_write_command(0x80);
		LCD_write_command(0x01);
		LCD_write_num((ADC_read()*100/206)+1);
		_delay_ms(100);
    }
}

