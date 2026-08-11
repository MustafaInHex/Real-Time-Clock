#include "TIMER0.h"

void TIMER0_CTC_initialize(void)
{
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);    //CTC MODE
	
		OCR0=40;
		
		sei();
		SET_BIT(TIMSK,OCIE0);  // ENABLE CTC INTERRUPT
		
		SET_BIT(TCCR0,CS00);
		CLR_BIT(TCCR0,CS01);  //PRESCALAR 1024 AND START TIMER
 		SET_BIT(TCCR0,CS02);
		
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TIMER0_FASTPWM_initialize(void)
{
	// SET OC0 AS OUTPUT PIN
	DIO_pindirection('B',3,1);
	
	// TIMER MODE FAST PWM 
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);   
	
	// USE IT TO CONTROL DUTY CYCLE
	OCR0=128;
	
	// PWM MODE 
    CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
	//PRESCALAR 1024 AND START TIMER
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);  
	SET_BIT(TCCR0,CS02);
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TIMER0_PHASECORRECT_PWM_initialize(void)
{
	// SET OC0 AS OUTPUT PIN
	DIO_pindirection('B',3,1);
	
	// TIMER MODE PHASE CORRECT PWM
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	
	// USE IT TO CONTROL DUTY CYCLE
	OCR0=128;
	
	// PWM MODE 
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	
	//PRESCALAR 1024 AND START TIMER
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	
}