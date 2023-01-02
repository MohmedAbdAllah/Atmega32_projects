/*
 * TIMER0.h
 *
 * Created: 8/19/2022 6:02:02 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#include "std_macros.h"

void (*timer0_ovf_isr)(void);
void (*timer0_comp_isr)(void);


void TIME0_OVF_init(void);
void TIME0_COMP_init(uint8_t);
void TIME0_freqGen_init(uint8_t);
void TIME0_PWM_init(void);
void TIME0_PWM_duty(uint8_t);


#endif /* INCFILE1_H_ */