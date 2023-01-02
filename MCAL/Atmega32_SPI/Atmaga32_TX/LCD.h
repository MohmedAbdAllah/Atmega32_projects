/*
 * LCD.h
 *
 * Created: 8/12/2022 7:48:55 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "std_macros.h"

#define INIT_LCD_PIN  DDRA|= 0b11111100; //PB2 TO PB7 OUTPUT

#define INITIAL_SHIFTING_PIN DDRB |= 0x00000000;\
							 SETBIT(PORTB,0);\
							 SETBIT(PORTB,1);\
							 SETBIT(PORTB,2);\
							 SETBIT(PORTB,3);

#define EN(x)  if(x == 1) SETBIT(PORTA,2); else CLRBIT(PORTA,2);
#define RS(x)  if(x == 1) SETBIT(PORTA,3); else CLRBIT(PORTA,3);
#define D4(x)  if(x == 1) SETBIT(PORTA,4); else CLRBIT(PORTA,4);
#define D5(x)  if(x == 1) SETBIT(PORTA,5); else CLRBIT(PORTA,5);
#define D6(x)  if(x == 1) SETBIT(PORTA,6); else CLRBIT(PORTA,6);
#define D7(x)  if(x == 1) SETBIT(PORTA,7); else CLRBIT(PORTA,7);

#define SHIFT_RIGHT READBIT(PINB,PINB0)
#define SHIFT_LEFT READBIT(PINB,PINB1)
#define SHIFT_UP READBIT(PINB,PINB2)
#define SHIFT_DOWN READBIT(PINB,PINB3)


//* Purpose      : Configure LCD port
void LCD_init(void);

//* Purpose      : Send command to LCD
void LCD_write_command(uint8_t com);

//* Purpose      : Send data to LCD
void LCD_write_data(uint8_t data);

//* Purpose      : write complex TXT
void LCD_write_string(uint8_t* string);

//* Purpose      : write number
void LCD_write_num(uint32_t);

//* Purpose      : shift string
void LCD_shift_str(uint8_t* ,uint8_t*);

#endif /* LCD_H_ */