#ifndef TIMER2_H_
#define TIMER2_H_
#include <avr/interrupt.h>
#include "std_macros.h"

void TIMER2_CTC_initialize(void);
void TIMER2_FASTPWM_initialize(void);
void TIMER2_PHASECORRECT_PWM_initialize(void);


#endif /* TIMER2_H_ */