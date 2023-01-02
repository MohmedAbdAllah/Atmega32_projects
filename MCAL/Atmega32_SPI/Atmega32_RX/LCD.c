/*
 * LCD.c
 *
 * Created: 8/12/2022 7:48:26 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "LCD.h"

/**************************************************************************
* Function Name: LCD_init
* Purpose      : Configure LCD port
* Parameters   : void
* Return value :void
**************************************************************************/

void LCD_init(void){
	INIT_LCD_PIN;
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x3);
	_delay_ms(4);
	LCD_write_command(0x2);
	LCD_write_command(0x28);
	LCD_write_command(0x08);
	LCD_write_command(0x1);
	LCD_write_command(0x6);
	LCD_write_command(0x3);
	LCD_write_command(0xc);
	_delay_ms(20);
	
	
}


/**************************************************************************
* Function Name: LCD_write_command
* Purpose      : Send command to LCD
* Parameters   : com : one of LCD command
* Return value :void
**************************************************************************/

void LCD_write_command(uint8_t com){
	
	RS(0);
	D7(READBIT(com,7)); //com bit 7 --> D7
	D6(READBIT(com,6)); //com bit 6 --> D6
	D5(READBIT(com,5)); //com bit 5 --> D5
	D4(READBIT(com,4)); //com bit 4 --> D4
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
	
	D7(READBIT(com,3)); //com bit 3 --> D7
	D6(READBIT(com,2)); //com bit 2 --> D6
	D5(READBIT(com,1)); //com bit 1 --> D5
	D4(READBIT(com,0)); //com bit 0 --> D4
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
	
	
}

/**************************************************************************
* Function Name: LCD_write_data
* Purpose      : Send data to LCD
* Parameters   : data :ASCII value specific input
* Return value : void
**************************************************************************/

void LCD_write_data(uint8_t data){
	
	RS(1);
	D7(READBIT(data,7)); //com bit 7 --> D7
	D6(READBIT(data,6)); //com bit 6 --> D6
	D5(READBIT(data,5)); //com bit 5 --> D5
	D4(READBIT(data,4)); //com bit 4 --> D4
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);
	
	D7(READBIT(data,3)); //com bit 3 --> D7
	D6(READBIT(data,2)); //com bit 2 --> D6
	D5(READBIT(data,1)); //com bit 1 --> D5
	D4(READBIT(data,0)); //com bit 0 --> D4
	EN(1);
	_delay_ms(1);
	EN(0);
	_delay_ms(1);

}
/**************************************************************************
* Function Name: LCD_write_string
* Purpose      : write complex TXT
* Parameters   : string: Array of character
* Return value : void
**************************************************************************/

void LCD_write_string(uint8_t *string){
	int8_t i = 0;
	while(string[i] != '\0'){
		LCD_write_data(string[i]);
		i++;
	}
	
}

/**************************************************************************
* Function Name: LCD_shift_str
* Purpose      : shift string
* Parameters   : pos: pointer point to the value of pos, 
				 arr: string
* Return value : void
**************************************************************************/
void LCD_shift_str(uint8_t*arr ,uint8_t*pos){
	INITIAL_SHIFTING_PIN
	uint8_t x = 0;
	
	LCD_write_command(0x80);
	LCD_write_num(sizeof(arr[0]));
	LCD_init();
	LCD_write_command(*pos);
	LCD_write_string(arr);
	// Shift right
	if(SHIFT_RIGHT == 0){
		if(((*pos) == 0x8f)||((*pos) == 0xcf)){
		}else{
			(*pos)++;
		}
	    while (x == SHIFT_RIGHT); 	
	}
	//Shift left
	if(SHIFT_LEFT == 0){
		if(((*pos) == 0x80)||((*pos) == 0xc0)){
		}else{
			(*pos)--;
		}
	    while (x == SHIFT_LEFT);
	}
	// Shift up
	if(SHIFT_UP == 0){
		if((*pos) < 0x8f){
		}else{
			(*pos) -= 0x40;
		}
	    while (x == SHIFT_UP);
	}
	//Shift down
	if(SHIFT_DOWN == 0){
		if((*pos) > 0x8f){
		}else{
			(*pos) += 0x40;
		}
	    while (x == SHIFT_DOWN);
	}
}

/**************************************************************************
* Function Name: LCD_write_num
* Purpose      : write number
* Parameters   : num: decimal number 0 -->255
* Return value : void
**************************************************************************/

void LCD_write_num(uint32_t num){
	int8_t i = 0, arr_num[10];
	
	for(i = 0 ;num != 0 ; i++){
		arr_num[i] = num % 10 + 48;
		num /= 10;
	}
	i--;
	while(i >= 0){
		LCD_write_data(arr_num[i]);
		i--;
	}
}

/*
void LCD_write_num(uint8_t num){
	int8_t i = 0, n[] = {48,48,48};
	
	while(num != 0){
		// Count the number of hundred
		if(num >= 100){
			n[0]++;
			num -= 100;
		}
		// Count the number of hundred
		else if(num >= 10){
			n[1]++;
			num -= 10;
		}else{
			n[2] += num;
			num-=num;
		}
	}
	
	while(i <= 2){
		LCD_write_data(n[i]);
		i++;
	}
	
}*/


	