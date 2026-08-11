#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"


#define PROTEUS
#define KEYPAD_PORT 'D'
#define NOT_PRESSED 0xff

void KEYPAD_initialize(void);
unsigned char KEYPAD_read(void);





#endif KEYPAD_H_ 