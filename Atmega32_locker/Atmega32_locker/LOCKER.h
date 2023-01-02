/*
 * LOCKER.h
 *
 * Created: 8/23/2022 11:32:44 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef LOCKER_H_
#define LOCKER_H_

#include "std_macros.h"
#include "EEPROM.h"
#include "KEYPAD.h"
#include "LCD.h"

#define NEW_PASS 47
#define ENTER '='
#define ERASE '\t'
#define LOCK '*'

void ERASE_fun(void);
void CHECK_INPUT_fun(uint16_t);
void BUZZER_TOGGLE_fun(uint16_t);

void NEW_PASS_fun(void);
void RESET_PASS_fun(void);
void CHECK_PASS_fun(uint16_t);

extern volatile uint8_t  inc, cursor, key_input;

#endif /* LOCKER_H_ */