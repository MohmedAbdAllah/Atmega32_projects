/*
 * LCD.h
 *
 * Created: 8/12/2022 7:48:55 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "std_macros.h"

#define INIT_LCD_PIN  DDRB|= 0b11111010; //PB2 TO PB7 OUTPUT

#define INITIAL_SHIFTING_PIN DDRA |= 0b00000000;\
							 SETBIT(PORTA,0);\
							 SETBIT(PORTA,1);\
                             SETBIT(PORTA,2);\
							 SETBIT(PORTA,3);

#define EN(x)  if(x == 1) SETBIT(PORTB,1); else CLRBIT(PORTB,1);
#define RS(x)  if(x == 1) SETBIT(PORTB,3); else CLRBIT(PORTB,3);
#define D4(x)  if(x == 1) SETBIT(PORTB,4); else CLRBIT(PORTB,4);
#define D5(x)  if(x == 1) SETBIT(PORTB,5); else CLRBIT(PORTB,5);
#define D6(x)  if(x == 1) SETBIT(PORTB,6); else CLRBIT(PORTB,6);
#define D7(x)  if(x == 1) SETBIT(PORTB,7); else CLRBIT(PORTB,7);

#define SHIFT_RIGHT READBIT(PINA,PINA0)
#define SHIFT_LEFT READBIT(PINA,PINA1)
#define SHIFT_UP READBIT(PINA,PINA2)
#define SHIFT_DOWN READBIT(PINA,PINA3)


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
void LCD_shift_str(uint8_t* ,uint8_t,uint8_t*);

#endif /* LCD_H_ */