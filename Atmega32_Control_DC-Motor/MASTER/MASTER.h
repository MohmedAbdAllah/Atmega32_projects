/*
 * MASTER.h
 *
 * Created: 11/25/2022 9:55:41 AM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef MASTER_H_
#define MASTER_H_

#include "std_macros.h"
#include "SPI.h"
#include "SEG.h"

#define INC READBIT(PINA,PINA2)
#define DEC READBIT(PINA,PINA3)
#define STOP READBIT(PINA,PINA4)


#endif /* MASTER_H_ */