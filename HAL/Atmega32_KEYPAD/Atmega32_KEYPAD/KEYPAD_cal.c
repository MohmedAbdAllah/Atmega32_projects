/*
 * KEYPAD_move_inputStr.c
 *
 * Created: 8/15/2022 12:13:20 AM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "KEYPAD.h"
#include "LCD.h"


int main(void)
{
	/* Replace with your application code */
	uint8_t LCD_arr[16] = {0};
	int32_t cal_arr[3] = {0}, x = 0;
	uint8_t inc = 0, cursor = 0x80 ;
	uint8_t arg = 0,oper = 0;
	
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
				arg = 0;
				cal_arr[0] = 0;
				cal_arr[1] = 0;
				cal_arr[2] = 0;
				oper = 0;
			}
			LCD_write_command(cursor + inc);
			LCD_write_data(x);
			LCD_arr[inc] = x;
			while(x == KEYPAD_read());
			_delay_ms(1);
			if(x != '\t'){
				inc++;
			
				if(x == '='){
					if(oper == '+'){
						cal_arr[2] = cal_arr[0] + cal_arr[1];
					}else if(oper == '-'){
						cal_arr[2] = cal_arr[0] - cal_arr[1];
						/*if((cal_arr[0] - cal_arr[1]) < 0){
							cal_arr[2] = cal_arr[1] - cal_arr[0];
							LCD_write_data('-');
						}*/
						
					}else if(oper == '*'){
						cal_arr[2] = cal_arr[0]* cal_arr[1];
				    }else if(oper == 47){
						cal_arr[2] = cal_arr[0] / cal_arr[1];
						if(cal_arr[1] == 0){
							LCD_write_string((uint8_t*)"wrong entry");
							cal_arr[2] = 0;
						}
				   }
				   //if(cal_arr[2] == 0) LCD_write_data('0'); 
				   LCD_write_num(cal_arr[2]);

	
				}else if((x > 41)&&(x < 48)){
					oper = x;
					arg = 1;
				}else{
					cal_arr[arg] = (x-48) +(cal_arr[arg]*10);
				}
			}
		}
		
	}
}