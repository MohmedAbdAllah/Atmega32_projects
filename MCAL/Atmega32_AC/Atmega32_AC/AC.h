/*
 * AC.h
 *
 * Created: 8/27/2022 10:26:35 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef AC_H_
#define AC_H_

#include "std_macros.h"

void AC_init(uint8_t);
extern void (*AC_isr)(void);

#endif /* AC_H_ */