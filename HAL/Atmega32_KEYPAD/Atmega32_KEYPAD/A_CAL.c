/*
 * A_CAL.c
 *
 * Created: 10/7/2022 3:53:56 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "A_CAL.h"
int16_t cal_arr[3] = {0};
int32_t out = 0;
uint8_t oper_arr[2] = {'+'},oper=0, arg=0;

/**************************************************************************
* Function Name: input_specifier
* Purpose      : Specify if the user input is argument or operant
* Parameters   : uint8_t -> keypad input
				 uint8_t -> negative flag
* Return value :void
**************************************************************************/
void CAL_input(uint8_t x,uint8_t neg_flag){
	if((x > 41)&&(x < 48)){
		if(oper < 2){
			oper_arr[oper] = x;
			oper++;
		}
		if(arg < 3) arg++;
	}else{
		if(arg < 3){
			if(neg_flag == 1) x = ((x-'0')* -1);
			else x = x - '0';
			cal_arr[arg] = x +(cal_arr[arg]*10);
		}
	}
}
/**************************************************************************
* Function Name: CAL_output
* Purpose      : calculate the output of the arithmetic operation
* Parameters   : void
* Return value :int32: out
**************************************************************************/
void CAL_output(){
	/*LCD_write_command(0xc0);
	LCD_write_num(cal_arr[0]);
	//LCD_write_data('k');
	LCD_write_data(oper_arr[0]);
	//LCD_write_data('k');
	LCD_write_num(cal_arr[1]);
	//LCD_write_data('k');
	LCD_write_data(oper_arr[1]);
	//LCD_write_data('k');
	LCD_write_num(cal_arr[2]);*/
	
	if((oper_arr[0] == '*')||(oper_arr[0] == '/')){
		switch(oper_arr[0]){
			case '*': out = cal_arr[0] * cal_arr[1];
					  break;
			case '/': out = cal_arr[0] / cal_arr[1];
					 break;
		}
		switch(oper_arr[1]){
			case '*' : out *= cal_arr[2];
			break;
			case  '/': out /= cal_arr[2];
			break;
			case  '+': out += cal_arr[2];
			break;
			case  '-': out -= cal_arr[2];
			break;
		}
		
	}else{
		switch(oper_arr[1]){
			case '*': out = cal_arr[1] * cal_arr[2];
			break;								 
			case '/': out = cal_arr[1] / cal_arr[2];
			break;								 
			case '+': out = cal_arr[1] + cal_arr[2];
			break;								 
			case '-': out = cal_arr[1] - cal_arr[2];
			break;
		}
		switch(oper_arr[0]){
			case  '+': out += cal_arr[0];
			break;
			case  '-': out = cal_arr[0] - out;
			break;
		}
	}
	//out = cal_arr[0] * cal_arr[1] - cal_arr[2];
	LCD_write_command(0xc9);
	LCD_write_num(out);
}
/**************************************************************************
* Function Name: reset_cal
* Purpose      : used to reset the calculator
* Parameters   :void
* Return value :void
**************************************************************************/
void CAL_reset(){
	arg = 0;
	oper = 0;

	cal_arr[0] = 0;
	cal_arr[1] = 0;
	cal_arr[2] = 0;
	oper_arr[0]= 0;
	oper_arr[1]= 0;

}