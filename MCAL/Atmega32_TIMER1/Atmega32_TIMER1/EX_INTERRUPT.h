/*
 * EX_INTERRUPT.h
 *
 * Created: 8/26/2022 6:30:33 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_

#include "std_macros.h"


void EI_INT0_init(uint8_t);
void EI_INT1_init(uint8_t);

extern void (*INT0_vect_isr)(void);
extern void (*INT1_vect_isr)(void);


#endif /* EX_INTERRUPT_H_ */