#ifndef TIMER0_H_
#define TIMER0_H_
#include <avr/interrupt.h>
#include "std_macros.h"

void TIMER0_CTC_initialize(void);
void TIMER0_FASTPWM_initialize(void);
void TIMER0_PHASECORRECT_PWM_initialize(void);


#endif /* TIMER0_H_ */