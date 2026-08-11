#include "TIMER2.h"

void TIMER2_OVERFLOW_initialize(void)
{
	//OVERFLOW MODE
	CLR_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);    
	
	//ALLOW EXTERNAL CLOCK
	SET_BIT(ASSR,AS2);
	
	// ENABLE OVERFLOW INTERRUPT
	sei();
	SET_BIT(TIMSK,TOIE2);  
	
	//PRESCALAR 128 AND START TIMER
	SET_BIT(TCCR2,CS20);
	CLR_BIT(TCCR2,CS21); 
	SET_BIT(TCCR2,CS22);
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TIMER2_CTC_initialize(void)
{
	CLR_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);    //CTC MODE
	
	OCR0=80;
	
	sei();
	SET_BIT(TIMSK,OCIE2);  // ENABLE CTC INTERRUPT
	
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);  //PRESCALAR 1024 AND START TIMER
	SET_BIT(TCCR2,CS22);
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TIMER2_FASTPWM_initialize(void)
{
	// SET OC0 AS OUTPUT PIN
	DIO_pindirection('D',7,1);
	
	// TIMER MODE FAST PWM
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	
	// USE IT TO CONTROL DUTY CYCLE
	OCR2=128;
	
	// PWM MODE
	CLR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	
	//PRESCALAR 1024 AND START TIMER
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TIMER2_PHASECORRECT_PWM_initialize(void)
{
	// SET OC0 AS OUTPUT PIN
	DIO_pindirection('B',3,1);
	
	// TIMER MODE PHASE CORRECT PWM
	SET_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
	
	// USE IT TO CONTROL DUTY CYCLE
	OCR2=128;
	
	// PWM MODE
	CLR_BIT(TCCR2,COM20);
	SET_BIT(TCCR2,COM21);
	
	//PRESCALAR 1024 AND START TIMER
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS22);
	
}