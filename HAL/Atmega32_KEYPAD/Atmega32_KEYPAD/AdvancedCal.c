/*
 * KEYPAD.c
 *
 * Created: 10/7/2022 3:49:11 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 

#include "A_CAL.h"

int main(void)
{
	/* Replace with your application code */
	uint8_t LCD_arr[16] = {0};
	uint8_t inc = 0, cursor = 0x80 ;
	uint8_t x = 0,neg_flag = 0;
	
	LCD_init();
	KEYPAD_init();
	
	while (1)
	{
		//take input from user
		x = KEYPAD_read();
		//check if the user input anything or not
		if(x > 0){
			_delay_ms(1);
			//check if user want to clear screen
			if(x == '\t'){
				LCD_write_command(0x01);
				inc = 0;
				CAL_reset();
			}
			else if(x == '='){
				CAL_output();
			}
			else{
				LCD_arr[inc] = x;
				if((LCD_arr[inc-1] > 41)&&(LCD_arr[inc-1] < 48)&&(x == '-')){
					neg_flag = 1;
				}else{
					if((x > 41)&&(x < 48)&&(neg_flag == 1)){
						neg_flag = 0;
					}
					CAL_input(x,neg_flag);
				}
			}
			LCD_write_command(cursor + inc);
			LCD_write_data(x);
			inc++;
			while(x == KEYPAD_read());
			_delay_ms(1);
		
		}
		
	}
}